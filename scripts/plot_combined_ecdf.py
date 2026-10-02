#!/usr/bin/env python3
"""Compact ROX/crane ECDFs from existing analysis/derive_latency.py CSVs.

Example (from repository root):
  python3 scripts/plot_combined_ecdf.py \
    --rox runs/rox50-pairs/trials.csv \
    --crane runs/crane-final-03/trials.csv --output-dir figures/combined

Requires numpy and matplotlib. Reads files only; no ROS/MQTT or device commands.
Default produces two layouts in PNG, PDF and SVG:
  ecdf_combined_log: two device panels, ACK + completion overlaid, all times ms.
  ecdf_combined_detail: device columns, metric rows, independent linear x axes.
Both use all successful complete measured rows, NOT complete-pair filtering.
Setup and failed/incomplete trials are excluded, with counts printed to stdout.
These are conditional successful-trial distributions, not reliability estimates.
"""
from __future__ import annotations
import argparse
import csv
import math
from pathlib import Path
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D
from matplotlib.ticker import FuncFormatter, LogLocator, NullFormatter

MODES = ('native', 'vda')
COLORS = {'native': '#0072B2', 'vda': '#D55E00'}
METRICS = ('ack_round_trip_ms', 'completion_round_trip_ms')


def truth(value):
    return str(value).strip().lower() in ('true', '1')


def load_campaign(path, device):
    with Path(path).open(newline='', encoding='utf-8-sig') as f:
        reader = csv.DictReader(f)
        required = {'trial_id', 'architecture', 'device', 'measure',
                    'complete', 'success', 'config_id', *METRICS}
        missing = required - set(reader.fieldnames or [])
        if missing:
            raise ValueError(f'{path}: missing columns: {sorted(missing)}')
        rows = list(reader)
    if not rows:
        raise ValueError(f'{path}: empty campaign')
    ids = [r['trial_id'] for r in rows]
    if any(not x for x in ids) or len(set(ids)) != len(ids):
        raise ValueError(f'{path}: missing/duplicate trial IDs; do not merge retries silently')
    if {r['device'].strip().lower() for r in rows} != {device}:
        raise ValueError(f'{path}: expected only device={device}')
    configs = {r['config_id'].strip() for r in rows}
    if len(configs) != 1 or '' in configs:
        raise ValueError(f'{path}: expected one nonempty frozen config_id')
    measured = [r for r in rows if truth(r['measure'])]
    if any(r['architecture'] not in MODES for r in measured):
        raise ValueError(f'{path}: measured row has unexpected architecture')
    groups = {}
    for mode in MODES:
        attempts = [r for r in measured if r['architecture'] == mode]
        accepted = [r for r in attempts if truth(r['complete']) and truth(r['success'])]
        if not accepted:
            raise ValueError(f'{path}: no successful measured {mode} rows')
        vals = {key: [] for key in METRICS}
        for row in accepted:
            for key in METRICS:
                try:
                    v = float(row[key])
                except (TypeError, ValueError):
                    raise ValueError(f"{row['trial_id']}: invalid {key}") from None
                if not math.isfinite(v) or v < 0:
                    raise ValueError(f"{row['trial_id']}: invalid {key}={v}")
                vals[key].append(v)
            if vals[METRICS[1]][-1] < vals[METRICS[0]][-1]:
                raise ValueError(f"{row['trial_id']}: completion precedes acknowledgement")
        groups[mode] = {key: np.asarray(v) for key, v in vals.items()}
        print(f'{device.upper()} {mode}: included {len(accepted)}/{len(attempts)} measured rows; '
              f'excluded {len(attempts)-len(accepted)} unsuccessful/incomplete')
    print(f'{device.upper()}: excluded {len(rows)-len(measured)} non-measured/setup rows')
    return groups


def ecdf_points(values, lower, upper):
    # Unique values create one vertical jump for tied observations.
    x, counts = np.unique(values, return_counts=True)
    return np.r_[lower, x, upper], np.r_[0., 100*np.cumsum(counts)/counts.sum(), 100.]


def decorate(ax):
    ax.set_ylim(0, 102)
    ax.set_yticks([0, 25, 50, 75, 100])
    ax.grid(axis='x', alpha=.16, lw=.7)
    for y in [50, 95]:
        ax.axhline(y, color='#8C8C8C', ls=':', lw=.8, zorder=0)
    ax.spines[['top', 'right']].set_visible(False)
    ax.tick_params(labelsize=8)


def count_label(groups):
    return 'Native n={}; VDA n={}'.format(*(len(groups[m][METRICS[0]]) for m in MODES))


def save(fig, output, name):
    for ext in ('png', 'pdf', 'svg'):
        fig.savefig(output / f'{name}.{ext}', dpi=300, facecolor='white')
    plt.close(fig)
    print(f'Saved {output / name}.{{png,pdf,svg}}')


def compact(campaigns, output):
    all_values = np.concatenate([g[m][k] for g in campaigns.values() for m in MODES for k in METRICS])
    if np.any(all_values <= 0):
        raise ValueError('Log layout requires positive times; use --layout detail for zero observations')
    lo, hi = float(all_values.min())/1.25, float(all_values.max())*1.25
    fig, axes = plt.subplots(1, 2, figsize=(7.15, 3.05), sharey=True)
    fig.subplots_adjust(left=.085, right=.985, bottom=.29, top=.84, wspace=.13)
    for ax, (device, groups) in zip(axes, campaigns.items()):
        decorate(ax)
        ax.set_xscale('log'); ax.set_xlim(lo, hi)
        ax.xaxis.set_major_locator(LogLocator(base=10))
        ax.xaxis.set_major_formatter(FuncFormatter(lambda x, _: f'{x:g}'))
        ax.xaxis.set_minor_formatter(NullFormatter())
        for k, style in zip(METRICS, ['-', '--']):
            for mode in MODES:
                x, y = ecdf_points(groups[mode][k], lo, hi)
                ax.step(x, y, where='post', color=COLORS[mode], ls=style, lw=1.65)
        ax.set_title(f'{device}\n{count_label(groups)}', fontsize=9, pad=7)
        ax.set_xlabel('Response time (ms; logarithmic)', fontsize=9)
    axes[0].set_ylabel('Cumulative observations (%)', fontsize=9)
    handles = [Line2D([], [], color=COLORS[m], ls=style, lw=1.7,
                      label=f"{'VDA' if m == 'vda' else 'Native'} {label}")
               for label, style in [('acknowledgement', '-'), ('completion', '--')] for m in MODES]
    fig.legend(handles=handles, loc='lower center', bbox_to_anchor=(.5,.015),
               ncol=2, frameon=False, fontsize=8, columnspacing=2)
    save(fig, output, 'ecdf_combined_log')


def detail(campaigns, output):
    fig, axes = plt.subplots(2, 2, figsize=(7.15, 4.5), sharey=True)
    fig.subplots_adjust(left=.085, right=.985, bottom=.14, top=.86, hspace=.55, wspace=.20)
    for col, (device, groups) in enumerate(campaigns.items()):
        axes[0,col].set_title(f'{device}\n{count_label(groups)}', fontsize=10, pad=8)
        for row, (k, divisor, label) in enumerate(zip(METRICS,[1,1000],
                    ['Acknowledgement (ms)', 'Completion (s; zoomed axis)'])):
            ax=axes[row,col]; decorate(ax)
            data=np.concatenate([groups[m][k]/divisor for m in MODES])
            spread=max(float(np.ptp(data)), float(data.max())*.02, .001)
            lo=0. if row==0 else max(0.,float(data.min())-.07*spread)
            hi=float(data.max())+.07*spread
            ax.set_xlim(lo,hi)
            for mode, style in zip(MODES,['-','--']):
                x,y=ecdf_points(groups[mode][k]/divisor,lo,hi)
                ax.step(x,y,where='post',color=COLORS[mode],ls=style,lw=1.65)
            ax.set_xlabel(label,fontsize=9)
    for ax in axes[:,0]: ax.set_ylabel('Cumulative observations (%)',fontsize=9)
    handles=[Line2D([],[],color=COLORS[m],ls=s,lw=1.7,label=('VDA' if m == 'vda' else 'Native'))
             for m,s in zip(MODES,['-','--'])]
    fig.legend(handles=handles,loc='lower center',bbox_to_anchor=(.5,.005),ncol=2,frameon=False,fontsize=9)
    save(fig,output,'ecdf_combined_detail')


def main():
    p=argparse.ArgumentParser(description=__doc__,formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--rox',type=Path,required=True)
    p.add_argument('--crane',type=Path,required=True)
    p.add_argument('--output-dir',type=Path,default=Path('figures/combined'))
    p.add_argument('--layout',choices=['both','compact','detail'],default='both')
    a=p.parse_args()
    try:
        campaigns={'ROX':load_campaign(a.rox,'rox'),'Crane':load_campaign(a.crane,'crane')}
        if a.layout in ('both','compact') and any(np.any(g[m][k]<=0) for g in campaigns.values() for m in MODES for k in METRICS):
            raise ValueError('Log layout requires positive times; use --layout detail for zero observations')
        a.output_dir.mkdir(parents=True,exist_ok=True)
        plt.rcParams.update({'font.family':'DejaVu Sans','font.size':9,'pdf.fonttype':42,'ps.fonttype':42})
        if a.layout in ('both','compact'): compact(campaigns,a.output_dir)
        if a.layout in ('both','detail'): detail(campaigns,a.output_dir)
        print('ECDFs condition on successful measured trials. Dotted guides: 50% and 95%.')
        print('Compact: solid=ack, dashed=completion. Detail: solid=native, dashed=VDA.')
    except ValueError as exc:
        p.error(str(exc))

if __name__=='__main__': main()
