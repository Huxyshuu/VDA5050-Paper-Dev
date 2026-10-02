#!/usr/bin/env python3
"""Plot a single laptop-timing campaign without changing its data or runner.

Usage: python3 scripts/plot_benchmark_results.py runs/NAME/trials.csv
Optional: --output-dir PATH --recoveries PATH --bootstrap 10000 --seed 5050
Requires numpy and matplotlib (already in benchmark/requirements.txt).
Timing plots use complete successful measured trials; setup and unsuccessful
rows remain in accounting.csv and the timeline. CIs resample matched differences
and describe the mean, not equivalence. Recovery markers are descriptive only.
"""
from __future__ import annotations
import argparse
import csv
import json
import math
from pathlib import Path
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

MODES = ('native', 'vda')
COLORS = {'native': '#0072B2', 'vda': '#D55E00'}
METRICS = (('ack_round_trip_ms', 'Acknowledgement', 'ms', 1),
           ('completion_round_trip_ms', 'Completion', 's', 1000))


def truth(value):
    return str(value).lower() in ('true', '1')


def good(row):
    return truth(row.get('complete')) and truth(row.get('success'))


def measured(row):
    return truth(row.get('measure')) and row.get('architecture') in MODES


def value(row, key):
    try:
        number = float(row.get(key, ''))
        return number if math.isfinite(number) and number >= 0 else None
    except (ValueError, TypeError):
        return None


def load_rows(path):
    with path.open(newline='', encoding='utf-8-sig') as stream:
        reader = csv.DictReader(stream)
        required = {'trial_id', 'pair_id', 'architecture', 'device', 'measure',
                    'complete', 'success', 'start', 'target', 'config_id',
                    *(m[0] for m in METRICS)}
        if not required.issubset(reader.fieldnames or []):
            raise ValueError('Use trials.csv produced by analysis/derive_latency.py; missing: '
                             + ', '.join(sorted(required - set(reader.fieldnames or []))))
        rows = list(reader)
    if not rows or len({r['trial_id'] for r in rows}) != len(rows):
        raise ValueError('Empty CSV or duplicate trial IDs; do not merge repeated attempts silently')
    for field in ('device', 'config_id'):
        if len({r[field] for r in rows if r[field]}) != 1:
            raise ValueError(f'Expected one non-empty {field} per campaign')
    for row in rows:
        if good(row) and any(value(row, m[0]) is None for m in METRICS):
            raise ValueError(f"Successful trial has missing/invalid timings: {row['trial_id']}")
    return rows


def paired_rows(rows):
    groups = {}
    for row in rows:
        if not measured(row):
            continue
        pair = groups.setdefault(row['pair_id'], {})
        if row['architecture'] in pair:
            raise ValueError(f"Duplicate mode in pair {row['pair_id']}")
        pair[row['architecture']] = row
    pairs = []
    for name, group in groups.items():
        if set(group) != set(MODES):
            continue
        a, b = group['native'], group['vda']
        if any(a[k] != b[k] for k in ('start', 'target', 'config_id')):
            raise ValueError(f'Unmatched endpoints/configuration in pair {name}')
        if good(a) and good(b):
            pairs.append((name, a, b))
    return pairs


def mean_ci(values, samples, seed):
    data = np.asarray(values, dtype=float)
    if len(data) < 2:
        return (math.nan, math.nan)
    rng = np.random.default_rng(seed)
    means = np.concatenate([rng.choice(data, size=(min(500, samples-i), len(data))).mean(axis=1)
                            for i in range(0, samples, 500)])
    return tuple(np.percentile(means, [2.5, 97.5]))


def describe(values):
    x = np.asarray(values, dtype=float)
    if not len(x):
        return {'n': 0}
    q1, median, q3, p95 = np.percentile(x, [25, 50, 75, 95])
    return dict(n=len(x), mean=x.mean(), median=median,
                std=x.std(ddof=1) if len(x)>1 else math.nan,
                q1=q1, q3=q3, iqr=q3-q1, p95=p95, min=x.min(), max=x.max())


def write_csv(path, rows):
    fields = list(dict.fromkeys(k for row in rows for k in row))
    with path.open('w', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields or ['n'])
        writer.writeheader()
        writer.writerows(rows)


def recovery_info(path, rows):
    marked, affected = [], set()
    if path is None:
        return marked, affected
    lookup = {r['trial_id']: (i+1, r['pair_id']) for i, r in enumerate(rows)}
    for line in path.read_text().splitlines():
        if not line.strip():
            continue
        item = json.loads(line)
        if item.get('event') != 'RECOVERY_VERIFIED':
            continue
        for key in ('failed_trial_id', 'next_trial_id'):
            if item.get(key) in lookup:
                affected.add(lookup[item[key]][1])
        if item.get('next_trial_id') in lookup:
            marked.append(lookup[item['next_trial_id']][0])
    return marked, affected


def finish(fig, output, name, note):
    fig.text(.02, .015, note, fontsize=9, color='#444444', va='bottom')
    fig.savefig(output / (name+'.png'), dpi=220)
    fig.savefig(output / (name+'.pdf'))
    plt.close(fig)


def make_plots(rows, output, samples=10000, seed=5050, recoveries=None):
    output.mkdir(parents=True, exist_ok=True)
    passed = [r for r in rows if measured(r) and good(r)]
    pairs = paired_rows(rows)
    recovery_marks, affected = recovery_info(recoveries, rows)
    device = next(r['device'] for r in rows if r['device']).upper()
    count = sum(measured(r) for r in rows)
    note = (f'Successful measured trials: {len(passed)}/{count} CSV rows; '
            f'{len(pairs)} complete matched pairs. Setups excluded from timing summaries.')
    plt.rcParams.update({'font.size': 11, 'axes.spines.top': False,
                         'axes.spines.right': False, 'pdf.fonttype': 42,
                         'axes.titleweight': 'bold', 'figure.facecolor': 'white'})
    summaries, differences = [], []
    fig, axes = plt.subplots(1, 2, figsize=(12, 5.5))
    fig.subplots_adjust(bottom=.27, top=.8, wspace=.3)
    fig.suptitle(f'{device} | Every successful measurement', fontsize=17)
    rng = np.random.default_rng(seed)
    for ax, (key, title, unit, scale) in zip(axes, METRICS):
        texts = []
        for y, mode in enumerate(MODES):
            x = np.array([value(r, key)/scale for r in passed if r['architecture']==mode])
            stats = describe(x)
            summaries.append(dict(metric=key, unit=unit, architecture=mode, **stats))
            if len(x):
                ax.boxplot([x], positions=[y], vert=False, widths=.34, showfliers=False,
                           patch_artist=True, boxprops=dict(facecolor=COLORS[mode], alpha=.16),
                           medianprops=dict(color=COLORS[mode], linewidth=2),
                           whiskerprops=dict(color=COLORS[mode]), capprops=dict(color=COLORS[mode]))
                ax.scatter(x, y+rng.uniform(-.11,.11,len(x)), color=COLORS[mode],
                           s=20, alpha=.65, zorder=3)
                ax.scatter([x.mean()], [y], marker='D', s=65, color='black', zorder=4)
                texts.append(f"{mode.upper()} n={len(x)}: median {stats['median']:.2f}; "
                             f"mean {stats['mean']:.2f}; p95 {stats['p95']:.2f} {unit}")
            else:
                texts.append(f'{mode.upper()}: no successful measurements')
        ax.set(yticks=[0,1], yticklabels=['Native','VDA 5050'], ylim=(1.5,-.5),
               xlabel=f'Laptop-observed response time ({unit})',
               title=title + (' (zoomed axis)' if scale==1000 else ''))
        if scale==1:
            ax.set_xlim(left=0)
        ax.grid(axis='x', alpha=.2)
        ax.text(0,-.25,'\n'.join(texts), transform=ax.transAxes, fontsize=9)
    finish(fig, output, '01_distributions', note+'\nDots = trials; box = middle 50%; line = median; diamond = mean; whiskers = within 1.5 IQR.')

    fig, axes = plt.subplots(1,2,figsize=(12,5.3))
    fig.subplots_adjust(bottom=.2, top=.8, wspace=.26)
    fig.suptitle(f'{device} | How often is a response this fast?', fontsize=17)
    for ax, (key,title,unit,scale) in zip(axes,METRICS):
        for mode in MODES:
            x = np.sort([value(r,key)/scale for r in passed if r['architecture']==mode])
            if len(x):
                ax.step(np.r_[0,x],np.r_[0,100*np.arange(1,len(x)+1)/len(x)],where='post',
                        color=COLORS[mode], linestyle='-' if mode=='native' else '--',
                        linewidth=2,label=f'{mode.upper()} (n={len(x)})')
        for p in (50,95):
            ax.axhline(p,color='#999999',ls=':',lw=1)
        if scale==1000:
            all_x=[value(r,key)/scale for r in passed]
            if all_x:
                ax.set_xlim(max(0,min(all_x)-max(.02,np.ptp(all_x)*.07)),max(all_x)+max(.02,np.ptp(all_x)*.07))
        else:
            ax.set_xlim(left=0)
        ax.set(ylim=(0,102),title=title + (' (zoomed axis)' if scale==1000 else ''),
               xlabel=f'Response time ({unit})',ylabel='Responses at or below this time (%)')
        if ax.get_legend_handles_labels()[0]:
            ax.legend(loc='lower right',fontsize=9)
        ax.grid(alpha=.15)
    finish(fig,output,'02_cumulative_distribution',note+'\nHigher/leftward curve = faster responses. Dotted guides: 50% and 95%.')

    fig,axes=plt.subplots(1,2,figsize=(12,6))
    fig.subplots_adjust(left=.14,bottom=.29,top=.8,wspace=.4)
    fig.suptitle(f'{device} | Extra time from VDA, within each pair',fontsize=17)
    for ax,(key,title,unit,scale) in zip(axes,METRICS):
        groups=[('All pairs',pairs)]+[(f'{a} → {b}',[p for p in pairs if p[1]['start']==a and p[1]['target']==b])
                                    for a,b in sorted({(p[1]['start'],p[1]['target']) for p in pairs})]
        labels=[]
        for y,(label,subset) in enumerate(groups):
            x=np.array([(value(b,key)-value(a,key))/scale for _,a,b in subset])
            labels.append(f'{label}\nn={len(x)}')
            if not len(x):
                continue
            lo,hi=mean_ci(x,samples,seed+y)
            summaries.append(dict(metric=key,unit=unit,architecture='vda-minus-native',
                                  group=label,ci_method='paired percentile bootstrap of mean, 95%',
                                  mean_ci_low=lo,mean_ci_high=hi,**describe(x)))
            ax.scatter(x,y+rng.uniform(-.1,.1,len(x)),s=22,color='#666666',alpha=.45)
            ax.plot([lo,hi],[y,y],color='#009E73',lw=4,zorder=4)
            ax.scatter([x.mean()],[y],marker='D',s=60,color='#00785B',zorder=5)
            if y==0:
                ax.text(0,-.30,f'Mean extra time: {x.mean():+.3f} {unit}\n95% CI [{lo:+.3f}, {hi:+.3f}] {unit}',
                        transform=ax.transAxes,fontsize=10)
        ax.axvline(0,color='black',ls='--',lw=1)
        ax.set(yticks=range(len(labels)),yticklabels=labels,ylim=(len(labels)-.5,-.5),
               xlabel=f'VDA − native ({unit})',title=title)
        ax.grid(axis='x',alpha=.2)
        for name,a,b in pairs:
            differences.append(dict(pair_id=name,start=a['start'],target=a['target'],metric=key,
                                    unit=unit,native=value(a,key)/scale,vda=value(b,key)/scale,
                                    difference=(value(b,key)-value(a,key))/scale,
                                    recovery_adjacent=name in affected))
    finish(fig,output,'03_paired_overhead','Positive = VDA slower; negative = VDA faster. Dots = pairs; diamond/bar = mean and bootstrap 95% CI.\n'
           'Directional groups are descriptive; CIs assume independent pairs. No equivalence margin is inferred.')

    fig,axes=plt.subplots(3,1,figsize=(12,8),sharex=True,gridspec_kw={'height_ratios':[2,2,1]})
    fig.subplots_adjust(left=.12,bottom=.17,top=.86,hspace=.34)
    fig.suptitle(f'{device} | Trial order and interruptions',fontsize=17)
    for ax,(key,title,unit,scale) in zip(axes[:2],METRICS):
        for mode,marker in zip(MODES,('o','^')):
            indices=[i for i,r in enumerate(rows,1) if measured(r) and good(r) and r['architecture']==mode]
            ax.scatter(indices,[value(rows[i-1],key)/scale for i in indices],s=28,
                       color=COLORS[mode],marker=marker,label=mode.upper())
        ax.set(ylabel=f'{title} ({unit})' + ('\nzoomed axis' if scale==1000 else ''))
        if scale==1:
            ax.set_ylim(bottom=0)
        ax.grid(alpha=.2)
    axes[0].legend(loc='lower right',ncol=2,fontsize=9)
    accounting=[]
    for i,row in enumerate(rows,1):
        status='success' if good(row) else ('missing' if row.get('outcome')=='missing' else 'unsuccessful')
        group=row['architecture'] if measured(row) else 'setup'
        accounting.append(dict(csv_row=i,trial_id=row['trial_id'],pair_id=row['pair_id'],
                               group=group,status=status,outcome=row.get('outcome',''),
                               reason=row.get('reason',''),recovery_adjacent=row['pair_id'] in affected))
        y={'native':0,'vda':1,'setup':2}[group]
        axes[2].scatter(i,y,marker='|' if status=='success' else 'x',s=65,
                        color='#999999' if status=='success' else '#CC3311')
    for ax in axes:
        for pos in recovery_marks:
            ax.axvline(pos-.5,color='#AA4499',ls=':',lw=1.3)
    axes[2].set(yticks=[0,1,2],yticklabels=['Native','VDA','Setup'],ylim=(2.5,-.5),
                xlabel='Row in input CSV (schedule order when generated with --schedule)',xlim=(.5,len(rows)+.5))
    finish(fig,output,'04_trial_order',note+'\nOutcome strip: grey tick = successful; red × = failed/incomplete/missing. Purple line = verified recovery (if supplied).')
    write_csv(output/'plot_summary.csv',summaries)
    write_csv(output/'paired_plot_data.csv',differences)
    write_csv(output/'accounting.csv',accounting)
    print(note)
    print(f'Recovery-adjacent pairs: {len(affected)}. Plots retain them; inspect accounting.csv for sensitivity analysis.')
    print(f'Wrote four PNG/PDF figures and three CSVs to {output}')


def main():
    parser=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('trials',type=Path)
    parser.add_argument('--output-dir',type=Path)
    parser.add_argument('--recoveries',type=Path,help='Optional recovery audit JSONL; otherwise auto-detect beside trials.csv')
    parser.add_argument('--bootstrap',type=int,default=10000)
    parser.add_argument('--seed',type=int,default=5050)
    args=parser.parse_args()
    if args.bootstrap<1000:
        parser.error('--bootstrap must be at least 1000')
    recovery=args.recoveries or (args.trials.parent/'recoveries.jsonl')
    if args.recoveries and not recovery.is_file():
        parser.error('Recovery file does not exist')
    make_plots(load_rows(args.trials),args.output_dir or args.trials.parent/'results'/'clear_plots',
               args.bootstrap,args.seed,recovery if recovery.is_file() else None)


if __name__=='__main__':
    main()
