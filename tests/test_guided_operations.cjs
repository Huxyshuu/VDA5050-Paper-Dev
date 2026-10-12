'use strict';
// Offline UI checks: no browser, broker, Flask process or hardware is required.
const { test } = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const root = path.resolve(__dirname, '..');
const { deriveGuidance } = require('../fleet_control/static/guided_operations.js');
const template = fs.readFileSync(path.join(root, 'fleet_control/templates/index.html'), 'utf8');
const layout = fs.readFileSync(path.join(root, 'fleet_control/static/guided_operations.js'), 'utf8');
const inline = [...template.matchAll(/<script>([\s\S]*?)<\/script>/g)].at(-1)[1];

function waitingFixture() {
  return {
    generated_at: '2026-10-12T09:00:00Z', server: { mqtt_connected: true, protocol: '3.0.0', map_id: 'df_map' },
    command_chain: { kind: 'scenario', title: 'Pickup & delivery', status: 'WAITING_OPERATOR', progress_percent: 50,
      steps: [{ id: 'crane_lower_handover', label: 'Lower item', phase: 'completed', target: 'crane' },
        { id: 'confirm_handover_release', label: 'Confirm release', phase: 'active', target: 'operator' },
        { id: 'crane_raise_handover', label: 'Raise hook', phase: 'upcoming', target: 'crane' }] },
    active_scenario: { target: 'sequential_cell', run_id: 'run-a', active_step_id: 'confirm_handover_release',
      status: 'WAITING_OPERATOR', operator_confirmation_mode: 'manual',
      operator_prompt: { step_id: 'confirm_handover_release', label: 'Confirm release', prompt: 'Clear the hook and robot.', confirm_label: 'Item released — continue', mode: 'manual' } },
    control_availability: { factsheet: true, pause: false, resume: false, cancel: false },
    devices: { rox: { enabled: true, online: true, safety: { active_emergency_stop: 'NONE' }, position: {} } },
    waypoints: [], scenarios: [], events: [], missions: [], experiment: {}, benchmark: {}, execution_monitor: {}, map: {}
  };
}

test('manual gate uses live run binding, prompt, next step and dynamic counts', () => {
  const g = deriveGuidance(waitingFixture());
  assert.equal(g.canConfirm, true); assert.equal(g.title, 'Confirm release');
  assert.equal(g.instruction, 'Clear the hook and robot.'); assert.equal(g.next.label, 'Raise hook');
  assert.equal(g.total, 3); assert.equal(g.currentIndex, 1); assert.equal(g.phases.length, 1);
});
test('missing or mismatched gate IDs and disconnected broker block confirmation', () => {
  for (const mutate of [x => { x.active_scenario.run_id = ''; }, x => { x.active_scenario.operator_prompt.step_id = 'old-gate'; }, x => { x.server.mqtt_connected = false; }]) {
    const data = waitingFixture(); mutate(data); assert.equal(deriveGuidance(data).canConfirm, false);
  }
});
test('timed confirmation uses the server snapshot time and never triggers a client-side motion', () => {
  const data = waitingFixture(); data.active_scenario.operator_prompt.mode = 'timeout';
  data.active_scenario.operator_prompt.auto_confirm_deadline_epoch = Date.parse(data.generated_at) / 1000 + 5;
  assert.equal(deriveGuidance(data).remaining, 5);
  data.generated_at = '2026-10-12T09:00:06Z'; assert.equal(deriveGuidance(data).remaining, 0);
});
test('terminal scenario has no active confirmation or next-step prompt', () => {
  const data = waitingFixture(); data.command_chain.status = 'FINISHED';
  const g = deriveGuidance(data);
  assert.equal(g.canConfirm, false); assert.equal(g.next, null); assert.equal(g.canChoose, true);
});
test('custom sequences keep the current step visible after the first five steps', () => {
  const data = waitingFixture(); data.active_scenario.target = 'rox';
  data.command_chain.status = 'RUNNING';
  data.command_chain.steps = Array.from({ length: 12 }, (_, i) => ({ id: `custom-${i}`, label: `Step ${i}`, phase: i < 9 ? 'completed' : i === 9 ? 'active' : 'upcoming' }));
  const g = deriveGuidance(data); assert.equal(g.total, 12);
  assert.ok(g.phases.some(p => p.phase === 'active')); assert.equal(g.next.label, 'Step 10');
});
test('HTML keeps every original control ID exactly once and routes tabs to real panels', () => {
  const ids = [...template.matchAll(/\sid="([^"]+)"/g)].map(m => m[1]);
  assert.equal(new Set(ids).size, ids.length);
  for (const name of ['mapCanvas', 'pauseBtn', 'resumeBtn', 'cancelBtn', 'retryBtn', 'skipRetryBtn', 'factsheetBtn',
    'craneReleaseHandoverBtn', 'craneHomeAllBtn', 'craneHomeXYBtn', 'craneHomeHoistBtn', 'cranePauseBtn',
    'craneResumeBtn', 'craneCancelBtn', 'confirmScenarioStepBtn', 'stopScenarioBtn', 'experimentToggle',
    'benchmarkTimeline', 'missionHistory', 'eventLog']) assert.ok(ids.includes(name), name);
  for (const m of template.matchAll(/aria-controls="([^"]+)"/g)) assert.ok(ids.includes(m[1]));
});

// Minimal DOM adapter exercises the real rendering and handlers, not a second UI implementation.
function harness({ desktop = false } = {}) {
  class Element {
    constructor(id = '') {
      this.id = id; this.dataset = {}; this.style = {}; this.attributes = {}; this.disabled = false;
      this.hidden = false; this.textContent = ''; this.innerHTML = ''; this.value = ''; this.isConnected = true;
      const classes = new Set(); this.classList = { add: x => classes.add(x), remove: x => classes.delete(x),
        contains: x => classes.has(x), toggle: (x, on) => { if (on ?? !classes.has(x)) classes.add(x); else classes.delete(x); } };
      this.strong = { textContent: '' };
    }
    setAttribute(k, v) { this.attributes[k] = String(v); }
    getAttribute(k) { return this.attributes[k]; }
    querySelector(q) { return q === 'strong' ? this.strong : null; }
    querySelectorAll() { return []; }
    contains(other) { return other === this; }
    focus() { document.activeElement = this; }
    addEventListener() {}
    scrollIntoView() {}
    getBoundingClientRect() { return { width: 480, height: 330, left: 0, top: 0 }; }
    getContext() { return new Proxy({}, { get: () => () => {} }); }
    closest(q) { return q === '.map-wrap' ? new Element() : null; }
    appendChild() {}
    remove() {}
  }
  const elements = new Map();
  for (const m of template.matchAll(/<[^>]*\sid="([^"]+)"[^>]*>/g)) {
    const node = new Element(m[1]); node.hidden = /\bhidden\b/.test(m[0]); node.disabled = /\bdisabled\b/.test(m[0]); elements.set(m[1], node);
  }
  elements.get('eventLevel').value = 'ALL';
  const document = { documentElement: new Element(), activeElement: null,
    getElementById: id => { assert.ok(elements.has(id), `Missing DOM ID ${id}`); return elements.get(id); },
    querySelector: q => q === '.view-nav' ? new Element() : null,
    querySelectorAll: q => q.includes('#view-robot button') ? [...elements.values()].filter(e => /Btn$|experimentToggle/.test(e.id)) : [],
    addEventListener() {}, createElement: () => new Element() };
  document.documentElement.dataset.theme = 'light';
  const posts = [];
  let mediaChange;
  const sidebarMedia = { matches: desktop, addEventListener: (_event, callback) => { mediaChange = callback; } };
  const context = { document, console, AbortController, URL, Map, Set, Date, Math, JSON,
    localStorage: { getItem: () => null, setItem() {} }, requestAnimationFrame: () => 1,
    setTimeout: () => 1, clearTimeout() {}, ResizeObserver: class { observe() {} },
    getComputedStyle: () => ({ getPropertyValue: () => '#222222' }),
    matchMedia: query => query.includes('1025px') ? sidebarMedia : { matches: query.includes('761px') && sidebarMedia.matches }, addEventListener() {}, devicePixelRatio: 1,
    fetch: async (url, options = {}) => { if (options.method === 'POST') posts.push({ url, payload: JSON.parse(options.body) });
      return { ok: true, json: async () => url === '/api/dashboard' ? context.fixture : url === '/api/crane/manual' ? context.crane : {} }; }
  };
  context.window = context; context.globalThis = context;
  vm.createContext(context); vm.runInContext(layout, context);
  // Suppress only the background polling loop; all real render and command functions remain.
  vm.runInContext(inline.replace(/pollLoop\(\);\s*$/, ''), context);
  context.fixture = waitingFixture(); context.crane = { ready: true, connection: 'ONLINE', operating_mode: 'AUTOMATIC',
    position: { bridge_m: 0, trolley_m: 0, hoist_m: 0 }, controls: { home_all: true }, waypoints: [], hoist_positions: [] };
  function render() { vm.runInContext('render(fixture);renderCraneManual(crane)', context); }
  return { context, elements, posts, render, resize: value => { sidebarMedia.matches = value; mediaChange(); } };
}
test('real dashboard renders live guidance without commanding hardware at startup', () => {
  const h = harness(); h.render();
  assert.equal(h.elements.get('guideStepTitle').textContent, 'Confirm release');
  assert.equal(h.elements.get('confirmScenarioStepBtn').hidden, false);
  assert.equal(h.elements.get('confirmScenarioStepBtn').disabled, false);
  assert.equal(h.elements.get('guideHookHeight').textContent, '0.000 m');
  assert.equal(h.posts.length, 0);
});
test('offline lock disables commands; fresh state recovers controls and recorder', () => {
  const h = harness(); h.render(); h.context.guidedOffline('Lost connection');
  assert.equal(h.elements.get('confirmScenarioStepBtn').disabled, true);
  assert.equal(h.elements.get('craneHomeAllBtn').disabled, true);
  assert.equal(h.elements.get('experimentToggle').disabled, true);
  h.render(); assert.equal(h.elements.get('confirmScenarioStepBtn').disabled, false);
  assert.equal(h.elements.get('craneHomeAllBtn').disabled, false);
  assert.equal(h.elements.get('experimentToggle').disabled, false);
});
test('theme and mobile navigation work independently of live commands', () => {
  const h = harness(); h.elements.get('themeToggle').onclick();
  assert.equal(h.context.document.documentElement.dataset.theme, 'dark');
  h.context.guidedSelectView('crane'); assert.equal(h.elements.get('view-crane').hidden, false);
  assert.equal(h.elements.get('view-operations').hidden, true); assert.equal(h.elements.get('mobileView').value, 'crane');
  assert.equal(h.posts.length, 0);
});
test('confirmation posts the original bound run and step; stale gate closes the dialog', async () => {
  const h = harness(); h.render(); h.elements.get('confirmScenarioStepBtn').onclick();
  await h.elements.get('modalConfirm').onclick();
  assert.equal(h.posts[0].url, '/api/scenarios/active/confirm');
  assert.deepEqual(h.posts[0].payload, { run_id: 'run-a', step_id: 'confirm_handover_release' });
  h.elements.get('confirmScenarioStepBtn').onclick();
  h.context.fixture.active_scenario.active_step_id = 'another-gate'; h.render();
  assert.equal(h.elements.get('modalBackdrop').classList.contains('open'), false);
  assert.equal(h.elements.get('confirmScenarioStepBtn').disabled, true);
});

test('desktop health sidebar remains visible across all workspace pages', () => {
  const h = harness({ desktop: true });
  for (const page of ['operations', 'robot', 'crane', 'research', 'history']) {
    h.context.guidedSelectView(page);
    assert.equal(h.elements.get('view-diagnostics').hidden, false);
    assert.equal(h.elements.get('tab-diagnostics').hidden, true);
    assert.equal(h.elements.get('view-diagnostics').getAttribute('role'), 'complementary');
    assert.equal(h.elements.get(`view-${page}`).hidden, false);
  }
  assert.equal(h.posts.length, 0);
});
test('mobile Diagnostics contains participants and health without a duplicate sidebar', () => {
  const h = harness(); h.context.guidedSelectView('robot');
  assert.equal(h.elements.get('view-diagnostics').hidden, true);
  h.context.guidedSelectView('diagnostics');
  assert.equal(h.elements.get('view-diagnostics').hidden, false);
  assert.equal(h.elements.get('view-robot').hidden, true);
  assert.equal(h.elements.get('view-diagnostics').getAttribute('role'), 'tabpanel');
  const sidebar = template.slice(template.indexOf('<aside id="view-diagnostics"'), template.indexOf('</aside>'));
  assert.ok(sidebar.indexOf('id="deviceList"') < sidebar.indexOf('id="diagScenarioCard"'));
});
test('resizing from mobile Diagnostics to desktop switches main view and keeps health visible', () => {
  const h = harness(); h.context.guidedSelectView('diagnostics'); h.resize(true);
  assert.equal(h.elements.get('view-diagnostics').hidden, false);
  assert.equal(h.elements.get('view-operations').hidden, false);
  assert.equal(h.elements.get('mobileView').value, 'operations');
  h.resize(false);
  assert.equal(h.elements.get('view-diagnostics').hidden, true);
  assert.equal(h.elements.get('tab-diagnostics').hidden, false);
});
test('mission library hides for active, paused and cancelling runs; returns on completion', () => {
  const h = harness();
  for (const status of ['RUNNING', 'WAITING_OPERATOR', 'PAUSED', 'CANCELLING']) {
    h.context.fixture.command_chain.status = status;
    h.context.fixture.active_scenario.status = status; h.render();
    assert.equal(h.elements.get('scenarioLibrary').hidden, true, status);
  }
  for (const status of ['FINISHED', 'CANCELLED', 'FAILED', 'REJECTED']) {
    h.context.fixture.command_chain.status = status;
    h.context.fixture.active_scenario.status = status; h.render();
    assert.equal(h.elements.get('scenarioLibrary').hidden, false, status);
  }
});
test('scenario rows retain start binding, escaped content and expandable stage information', () => {
  const h = harness();
  h.context.fixture.command_chain = { kind: 'idle', status: 'IDLE', steps: [] };
  h.context.fixture.active_scenario = null;
  h.context.fixture.scenarios = [{ id: 'short_loop', label: 'Short <test>', enabled: true, target: 'rox', risk: 'low', description: 'A & B', display_steps: ['Home', 'Short test', 'Home'] }];
  h.render();
  const markup = h.elements.get('scenarioList').innerHTML;
  assert.ok(markup.includes('class="scenario scenario-row"'));
  assert.ok(markup.includes('data-id="short_loop"'));
  assert.ok(markup.includes('<details class="scenario-details"'));
  assert.ok(markup.includes('<ol class="scenario-stages">'));
  assert.ok(markup.includes('Short &lt;test&gt;'));
  assert.ok(markup.includes('3 stages'));
  assert.equal(h.elements.get('scenarioLibrary').hidden, false);
  assert.equal(h.posts.length, 0);
});
