/* Layout and display projections only. Commands use the existing dashboard handlers. */
(function (host) {
  'use strict';
  const BUSY = new Set(['RUNNING', 'PAUSED', 'WAITING_OPERATOR', 'CANCELLING']);
  const TERMINAL = new Set(['FINISHED', 'FAILED', 'REJECTED', 'CANCELLED']);
  const PHASES = [
    ['Home the cell', ['crane_home_start', 'rox_home_start']],
    ['Pick up item', ['rox_to_handover', 'crane_to_source', 'crane_lower_source', 'confirm_source_pickup', 'crane_raise_source']],
    ['Transfer to ROX', ['crane_to_handover', 'crane_lower_handover', 'confirm_handover_release', 'crane_raise_handover']],
    ['Deliver item', ['rox_to_warehouse', 'confirm_human_unload']],
    ['Return home', ['rox_home_finish', 'crane_home_finish']]
  ];
  function deriveGuidance(data) {
    const chain = data.command_chain || {}, run = data.active_scenario || {};
    const status = String(chain.status || 'IDLE'), steps = Array.isArray(chain.steps) ? chain.steps : [];
    const currentIndex = steps.findIndex(s => s.phase === 'active' || s.phase === 'failed');
    const current = steps[currentIndex] || null, prompt = run.operator_prompt || {};
    const scenario = chain.kind === 'scenario', busy = scenario && BUSY.has(status);
    const waiting = busy && status === 'WAITING_OPERATOR';
    // Confirmation remains bound to the same run and physical gate as the existing API.
    const canConfirm = Boolean(waiting && data.server?.mqtt_connected &&
      run.run_id && run.active_step_id && prompt.step_id === run.active_step_id);
    const completed = steps.filter(s => s.phase === 'completed').length;
    const terminal = TERMINAL.has(status);
    let title = current?.label || chain.title || 'Operation in progress';
    let instruction = current?.description || chain.description || 'Follow the live sequence below.';
    if (chain.kind === 'idle' || !chain.kind) {
      title = 'Choose the operation.';
      instruction = 'Start with a repeatable scenario, or open the robot and crane controls.';
    } else if (waiting) {
      title = prompt.label || current?.label || 'Operator confirmation required';
      instruction = prompt.prompt || 'Verify that the current physical task is complete and the cell is clear.';
    } else if (status === 'PAUSED') {
      title = 'Operation paused.';
      instruction = 'Review the current device state before resuming from its control page.';
    } else if (status === 'CANCELLING') {
      title = 'Stopping the operation…';
      instruction = 'Waiting for the current motion and cancelable actions to stop.';
    } else if (terminal) {
      title = status === 'FINISHED' ? 'Operation complete.' : status === 'CANCELLED' ? 'Operation cancelled.' : 'Operation needs attention.';
      instruction = status === 'FINISHED' ? 'Review the result or choose the next operation.' :
        'Review diagnostics and the final device state before starting another operation.';
    }
    const policy = run.operator_confirmation_mode || prompt.mode;
    const deadline = Number(prompt.auto_confirm_deadline_epoch), now = Date.parse(data.generated_at) / 1000;
    const timed = waiting && prompt.mode === 'timeout';
    const remaining = timed && prompt.auto_confirm_deadline_epoch != null && Number.isFinite(deadline) && Number.isFinite(now)
      ? Math.max(0, Math.ceil(deadline - now)) : null;
    let phases;
    const grouped = run.target === 'sequential_cell' && steps.length &&
      steps.every(s => PHASES.some(([, ids]) => ids.includes(s.id)));
    if (grouped) {
      phases = PHASES.map(([label, ids]) => {
        const members = steps.filter(s => ids.includes(s.id));
        const phase = members.some(s => s.phase === 'failed') ? 'failed' :
          members.some(s => s.phase === 'active') ? 'active' :
            members.length && members.every(s => s.phase === 'completed') ? 'completed' : 'upcoming';
        return { label, phase, present: members.length > 0 };
      }).filter(p => p.present);
    } else {
      // A compact window also supports configured scenarios with different lengths and IDs.
      const first = Math.max(0, Math.min(currentIndex < 0 ? Math.max(0, completed - 2) : currentIndex - 1, steps.length - 5));
      phases = steps.slice(first, first + 5).map((s, i) => ({ label: s.label || s.waypoint || s.id || 'Step', phase: s.phase || 'upcoming', index: first + i + 1 }));
    }
    const progress = Number(chain.progress_percent);
    return {
      title, instruction, status, scenario, busy, waiting, canConfirm, timed, remaining,
      policy, current, currentIndex, completed, total: steps.length, phases,
      progress: chain.progress_percent != null && Number.isFinite(progress) ? Math.max(0, Math.min(100, progress)) : null,
      next: terminal ? null : steps.slice(currentIndex < 0 ? 0 : currentIndex + 1).find(s => s.phase === 'upcoming') || null,
      error: String(chain.error || (scenario ? run.error : data.mission?.terminal_reason) || ''),
      canChoose: !busy && (terminal || chain.kind === 'idle' || !chain.kind)
    };
  }
  if (typeof module !== 'undefined' && module.exports) module.exports = { deriveGuidance };
  if (typeof document === 'undefined') return;
  const el = id => document.getElementById(id);
  const text = (id, value) => { const node = el(id); if (node.textContent !== value) node.textContent = value; };
  const safe = value => String(value ?? '').replace(/[&<>"']/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;', "'": '&#39;' }[c]));

  // Avoid replacing focused buttons on every 0.5 s refresh when content is unchanged.
  host.updateDashboardHTML = function (node, markup) {
    if (node.dataset.lastMarkup === markup) return;
    const active = document.activeElement, restore = active && node.contains(active);
    const key = restore && (active.dataset.name || active.dataset.id), attr = restore && (active.dataset.name ? 'name' : 'id');
    node.innerHTML = markup; node.dataset.lastMarkup = markup;
    if (key) {
      const next = [...node.querySelectorAll(`[data-${attr}]`)].find(b => b.dataset[attr] === key);
      if (next && !next.disabled) next.focus({ preventScroll: true });
    }
  };
  const views = ['operations', 'robot', 'crane', 'diagnostics', 'research', 'history'];
  const sidebarViewport = window.matchMedia('(min-width: 1025px)');
  const availableViews = () => views.filter(view => view !== 'diagnostics' || !sidebarViewport.matches);
  let activeView = 'operations';
  host.guidedSelectView = function (name, focus = false) {
    if (!views.includes(name)) return;
    if (sidebarViewport.matches && name === 'diagnostics') name = 'operations';
    activeView = name;
    for (const view of views) {
      const selected = view === name;
      el(`view-${view}`).hidden = !(selected || (view === 'diagnostics' && sidebarViewport.matches));
      el(`tab-${view}`).hidden = view === 'diagnostics' && sidebarViewport.matches;
      el(`tab-${view}`).setAttribute('aria-selected', String(selected));
      el(`tab-${view}`).tabIndex = selected ? 0 : -1;
    }
    el('view-diagnostics').setAttribute('role', sidebarViewport.matches ? 'complementary' : 'tabpanel');
    el('view-diagnostics').setAttribute('aria-labelledby', sidebarViewport.matches ? 'systemSidebarTitle' : 'tab-diagnostics');
    el('mobileView').value = name;
    try { localStorage.setItem('vda5050-view', name); } catch {}
    if (focus && window.matchMedia('(min-width: 761px)').matches) el(`tab-${name}`).focus();
    if (typeof scheduleMapRender === 'function') scheduleMapRender();
  };
  function syncTheme() {
    const dark = document.documentElement.dataset.theme === 'dark';
    text('themeToggle', dark ? 'Light theme' : 'Dark theme');
    el('themeToggle').setAttribute('aria-label', `Switch to ${dark ? 'light' : 'dark'} theme`);
    el('themeToggle').setAttribute('aria-pressed', String(dark));
    if (typeof scheduleMapRender === 'function') scheduleMapRender();
  }
  el('themeToggle').onclick = () => {
    const theme = document.documentElement.dataset.theme === 'dark' ? 'light' : 'dark';
    document.documentElement.dataset.theme = theme;
    try { localStorage.setItem('vda5050-theme', theme); } catch {}
    syncTheme();
  };
  document.querySelectorAll('[data-view]').forEach(button => button.onclick = () => host.guidedSelectView(button.dataset.view));
  document.querySelectorAll('[data-open-view]').forEach(button => button.onclick = () => host.guidedSelectView(button.dataset.openView, true));
  el('mobileView').onchange = e => host.guidedSelectView(e.target.value);
  document.querySelector('.view-nav').onkeydown = e => {
    if (!['ArrowLeft', 'ArrowRight', 'Home', 'End'].includes(e.key)) return;
    e.preventDefault();
    const pages = availableViews(), i = pages.indexOf(activeView);
    const next = e.key === 'Home' ? 0 : e.key === 'End' ? pages.length - 1 : (i + (e.key === 'ArrowRight' ? 1 : -1) + pages.length) % pages.length;
    host.guidedSelectView(pages[next], true);
  };
  el('guideSelectScenario').onclick = () => {
    host.guidedSelectView('operations');
    el('scenarioLibrary').scrollIntoView({ behavior: window.matchMedia('(prefers-reduced-motion: reduce)').matches ? 'auto' : 'smooth', block: 'start' });
    const start = el('scenarioList').querySelector('button:not(:disabled)');
    if (start) start.focus({ preventScroll: true });
  };
  host.renderGuidedOperations = function (data) {
    const g = deriveGuidance(data), chain = data.command_chain || {};
    el('connectionAlert').hidden = true;
    el('view-diagnostics').dataset.stale = 'false';
    text('sidebarFreshness', 'Live system state');
    text('guideRunKind', g.scenario ? 'SEQUENTIAL OPERATIONS / RESEARCH CELL' : 'OPERATIONS / RESEARCH CELL');
    text('guideRunMeta', g.total ? `${g.completed} of ${g.total} sequence steps complete${g.policy ? ` · ${g.policy === 'timeout' ? 'Timed' : 'Manual'} confirmations` : ''}` : 'Choose a scenario or a named destination to begin.');
    text('guideTaskKind', g.waiting ? 'OPERATOR CONFIRMATION' : g.current?.target ? `${g.current.target.toUpperCase()} / CURRENT STEP` : 'CURRENT TASK');
    text('guideStepTitle', g.title); text('guideInstruction', g.instruction);
    text('guideStepCount', g.total ? g.currentIndex >= 0 ? `STEP ${g.currentIndex + 1} / ${g.total}` : `${g.completed} / ${g.total} COMPLETE` : 'No active run');
    text('guideConfirmationPolicy', g.timed ? g.remaining == null ? 'Timed gate · countdown unavailable' : `Automatic continuation in ${g.remaining} s` : g.policy === 'manual' ? 'Manual gate · no countdown' : g.policy === 'timeout' ? 'Timed confirmation gates' : 'Live device state');
    el('guideProgress').hidden = g.progress == null;
    if (g.progress != null) el('guideProgress').setAttribute('aria-valuenow', String(g.progress));
    el('confirmScenarioStepBtn').hidden = !g.waiting;
    el('confirmScenarioStepBtn').disabled = !g.canConfirm;
    el('stopScenarioBtn').hidden = !g.busy;
    el('stopScenarioBtn').disabled = !g.busy || !data.server?.mqtt_connected;
    el('guideSelectScenario').hidden = !g.canChoose;
    // Collapse the chooser only once the server confirms a scenario has started.
    el('scenarioLibrary').hidden = g.busy;
    const target = g.current?.target || (chain.kind === 'order' ? 'rox' : null);
    el('guideDeviceControl').hidden = !['rox', 'crane'].includes(target);
    el('guideDeviceControl').dataset.openView = target === 'crane' ? 'crane' : 'robot';
    text('guideDeviceControl', target === 'crane' ? 'Open crane controls' : 'Open robot controls');
    el('guideNext').hidden = !g.next;
    text('guideNextLabel', g.next?.label || '—');
    el('guideFailure').hidden = !g.error;
    text('guideFailure', g.error);
    const markup = g.phases.map((p, i) => `<li class="phase-item ${safe(p.phase)}" ${p.phase === 'active' ? 'aria-current="step"' : ''}><span>${String(p.index || i + 1).padStart(2, '0')} / ${p.phase === 'completed' ? 'COMPLETE' : p.phase === 'active' ? g.waiting ? 'YOUR TURN' : 'ACTIVE' : p.phase === 'failed' ? 'STOPPED' : 'UP NEXT'}</span>${safe(p.label)}</li>`).join('');
    host.updateDashboardHTML(el('guidePhases'), markup);
    el('guidePhases').hidden = !g.phases.length;
    el('guideAttention').hidden = !g.waiting || activeView === 'operations';
    el('guideMobileAttention').hidden = !g.waiting || activeView === 'operations';
    el('experimentToggle').setAttribute('aria-pressed', String(Boolean(data.experiment?.enabled)));
    // Existing API availability remains authoritative. Losing the broker never leaves motion buttons enabled.
    if (!data.server?.mqtt_connected) host.guidedOffline('Master is responding, but the MQTT broker is disconnected.');
  };
  host.renderGuidedCrane = function (data) {
    const height = data?.position?.hoist_m;
    text('guideHookHeight', height != null && Number.isFinite(Number(height)) ? `${Number(height).toFixed(3)} m` : '—');
    text('guideCraneReadiness', [data?.connection || 'UNKNOWN', data?.operating_mode || 'UNKNOWN', ...(data?.reasons || [])].join(' · '));
    if (!el('connectionAlert').hidden) host.guidedDisableCommands();
  };
  host.guidedDisableCommands = function () {
    document.querySelectorAll('#view-robot button, #view-crane button, .scenario-btn, #confirmScenarioStepBtn, #stopScenarioBtn, #experimentToggle').forEach(b => { b.disabled = true; });
  };
  host.guidedOffline = function (message) {
    host.guidedDisableCommands();
    el('connectionAlert').hidden = false;
    el('view-diagnostics').dataset.stale = 'true';
    text('sidebarFreshness', 'Telemetry stale · reconnecting');
    text('connectionAlert', `Live control unavailable. ${message} Controls will recover after a fresh snapshot.`);
    text('guideStepTitle', 'Waiting for live state.');
    text('guideInstruction', 'Previous telemetry may be stale. Reconnect before sending commands.');
    el('cellChip').classList.remove('online');
    el('cellChip').querySelector('strong').textContent = 'Control unavailable';
    if (el('modalBackdrop').classList.contains('open') && typeof closeModal === 'function') closeModal();
  };
  let savedView;
  try { savedView = localStorage.getItem('vda5050-view'); } catch {}
  host.guidedSelectView(views.includes(savedView) ? savedView : 'operations');
  const syncSidebar = () => host.guidedSelectView(activeView);
  if (sidebarViewport.addEventListener) sidebarViewport.addEventListener('change', syncSidebar);
  else if (sidebarViewport.addListener) sidebarViewport.addListener(syncSidebar);
  syncTheme();
})(typeof window !== 'undefined' ? window : globalThis);
