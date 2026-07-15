# VDA 5050 v2/DBot to v3/ROX Migration Notes

## Replaced architecture

The old robot side combined VDA v2 MQTT bridging, custom ROS VDA messages, a controller node, TurtleBot/DBot adapter code, DBot hardware packages and DBot maps. The new robot side validates official v3 JSON directly and calls native Nav2.

## VDA v3 behavior reflected in the implementation

- topic root uses `vda5050/v3/...`;
- message header version is `3.0.0`;
- state uses `mobileRobotPosition` and `localized`;
- battery is reported under `powerSupply`;
- normal and instant action states are separate arrays;
- action statuses include `PAUSED` and `RETRIABLE`;
- blocking schema supports `SINGLE` in addition to `NONE`, `SOFT` and `HARD`;
- `startPause`, `stopPause`, `cancelOrder`, `initializePosition`, `factsheetRequest`, `retry` and `skipRetry` are handled;
- cancellation includes the active order ID when the master knows it;
- connection uses retained ONLINE/OFFLINE and broker last will;
- order edges do not use old `startNodeId`/`endNodeId` fields;
- new orders require `orderUpdateId: 0` in the first implementation;
- the first order node must be trivially reachable and is removed from remaining `nodeStates` when accepted;
- node/edge sequence IDs are checked as continuous even/odd values;
- outgoing/incoming key messages are validated against official schemas.

## Project-specific actions

The initial case study retains custom actions because the standard does not define the specific AMR–crane handover semantics:

```text
holdPose / releaseHold
waitForTrigger / trigger
```

They must be documented in the factsheet/usage profile and should not be mistaken for predefined standard actions.

## Implemented retry limitation

`retry` and `skipRetry` are implemented only for the current blocked node action in `RETRIABLE`. The adapter does not yet persist arbitrary action recovery across restarts or support a general retry queue.

## Deliberately deferred v3 features

- same-order update and base/horizon merging;
- edge actions;
- planned/intermediate path publication;
- zone sets and interactive zone responses;
- zone action states;
- visualization topic;
- full restart persistence/recovery.

These should be added after basic physical ROX–crane handover is repeatable.
