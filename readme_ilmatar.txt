----------- CLI Commands -------------------
Make sure opcua-env is sourced and activated
--------------------------------------------
cd ~/masters_thesis/ilmatar/vda5050_adapter/ON-GOING_TEST
python3 crane_vda5050_adapter_TEST.py 
python3 master_control_panel_TEST.py 
mosquitto_pub -h 192.168.1.115 -p 1883 -t 'uagv/v2/konecranes/ilmatar_1/order' -f order_TEST.json 
--------------------------------------------

Automatic button in UI is for reseting Crane to homing position.

---  _sub List of VDA5050 Topics --- 
mosquitto_sub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/order' -v
mosquitto_sub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/instantActions' -v
mosquitto_sub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/connection' -v
mosquitto_sub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/state' -v
mosquitto_sub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/visualization' -v
-------------------------------

---  _pub List of VDA5050 Topics --- 

--- If sending from same device i.e. Rpi Broker --- 
mosquitto_pub -h localhost -t 'uagv/v2/konecranes/ilmatar_1/order' -f order.json
---  OR If sending from same network i.e. DTLabStatic --- 
mosquitto_pub -h 192.168.1.115 -p 1883 -t 'uagv/v2/konecranes/ilmatar_1/order' -f order.json
----------------------------------------------------

--- Release IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "release", "blockingType": "NONE", "actionParameters": []}]}'
--- Cancel Order IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "cancelOrder", "blockingType": "HARD", "actionParameters": []}]}'
--- Pause IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "pause", "blockingType": "NONE", "actionParameters": []}]}'
--- Resume IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "resume", "blockingType": "NONE", "actionParameters": []}]}'
--- Reset All IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "resetAllHome", "blockingType": "HARD", "actionParameters": []}]}'
--- Reset Hoist IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "resetHoist", "blockingType": "SOFT", "actionParameters": []}]}'
--- Reset Bridge and Trolley IA ---
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/instantActions -m '{"headerId": 1, "timestamp": "2025-09-08T13:22:10.499Z", "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "actions": [{"actionId": "2cb50d8d53564d4dbe8405c8a7e745fb", "actionType": "resetBridgeTrolley", "blockingType": "HARD", "actionParameters": []}]}'

--------------------

----------- Route A'B'A' ----------
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/konecranes/ilmatar_1/order -m '{"headerId": 1, "timestamp": "2025-09-08T13:52:13.346Z", "orderId": "4d4dd05d-087b-429a-ac34-e1844166bb2b", "orderUpdateId": 0, "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "nodes": [{"nodeId": "n1", "released": true, "sequenceId": 0, "nodePosition": {"x": 17.534, "y": 6.664, "mapId": "map"}, "actions": [{"actionId": "a1", "actionType": "lowerHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zd", "value": 0.445}]}, {"actionId": "a2", "actionType": "buttonPress", "blockingType": "HARD", "actionParameters": []}, {"actionId": "a3", "actionType": "raiseHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zu", "value": 2.071}]}]}, {"nodeId": "n2", "released": true, "sequenceId": 2, "nodePosition": {"x": 19.501, "y": 5.302, "mapId": "map"}, "actions": [{"actionId": "a4", "actionType": "lowerHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zd", "value": 0.445}]}, {"actionId": "a5", "actionType": "buttonPress", "blockingType": "HARD", "actionParameters": []}, {"actionId": "a6", "actionType": "raiseHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zu", "value": 3.071}]}]}, {"nodeId": "n3", "released": true, "sequenceId": 4, "nodePosition": {"x": 17.534, "y": 6.664, "mapId": "map"}, "actions": []}], "edges": [{ "edgeId": "edge1", "released": true, "sequenceId": 1, "startNodeId": "node1", "endNodeId": "node2", "actions": [] }, { "edgeId": "edge1", "released": true, "sequenceId": 3, "startNodeId": "node2", "endNodeId": "node1", "actions": [] }]}'
------------ Direct to Point B' -----------------------
{"headerId": 2, "timestamp": "2025-09-08T13:52:13.346Z", "orderId": "4d4dd05d-087b-429a-ac34-e1844166bb2b", "orderUpdateId": 0, "version": "2.1.0", "manufacturer": "konecranes", "serialNumber": "ilmatar_1", "nodes": [{"nodeId": "n1", "released": true, "sequenceId": 0, "nodePosition": {"x": 19.501, "y": 5.302, "mapId": "DT-Lab"}, "actions": [{"actionId": "a4", "actionType": "lowerHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zd", "value": 0.445}]}, {"actionId": "a5", "actionType": "buttonPress", "blockingType": "HARD"}, {"actionId": "a6", "actionType": "raiseHoist", "blockingType": "SOFT", "actionParameters": [{"key": "zu", "value": 3.071}]}]}], "edges": []}

-----------------------------------


(opcua-env) ilmatarlogs@raspberrypi:~/masters_thesis/ilmatar/vda5050_adapter $ python3 crane_vda5050_adapter.py 
