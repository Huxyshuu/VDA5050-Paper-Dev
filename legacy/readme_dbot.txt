Point A - for Dbot:
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
"{pose: {header: {frame_id: 'map'}, pose: {position: {x: -2.7704, y: -5.23018, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.00673695, w: 0.999996}}}}"

Point B - for Dbot:
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
"{pose: {header: {frame_id: 'map'}, pose: {position: {x: -0.0521810, y: -5.32476640, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.5331910, w: 00.8459948}}}}"

Poiny C - for Dbot:
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
"{pose: {header: {frame_id: 'map'}, pose: {position: {x: -0.8227, y: -1.3880, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: -0.71209, w: 0.70207}}}}"
-------------------------------------------------------------------------
To view all topics sub's at the same time:
mosquitto_sub -h 192.168.1.115 -p 1883 -t 'uagv/v2/OSRF/TB3_1/#' -v
-------------------------------------------------------------------------
!!! Important check the nano .bashrc file to make sure the yours is sourced properly and also make sure the systemctl services
are not interferring with your lanuching files...
  
# Build workspace packages

cd dbot_vda5050_ilmatar/
colcon build && source install/setup.bash
  
ros2 launch dbot_nav_slam auto_nav_dbot_launch.py 
ros2 run rviz2 rviz2 -d $(ros2 pkg prefix nav2_bringup)/share/nav2_bringup/rviz/nav2_default_view.rviz


# Launch the TB3 VDA5050 connector

ros2 launch vda5050_tb3_adapter connector_tb3.launch.py


Initial Pose or Point A - for Dbot:
ros2 topic pub -1 --qos-reliability reliable /initialpose geometry_msgs/PoseWithCovarianceStamped \
"{header: {frame_id: map}, pose: {pose: {position: {x: -2.7704, y: -5.23018, z: 0.0}, orientation: {x: 0.0, y: 0.0, z: 0.00673695, w: 0.999996}}, covariance: [0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.25, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06853891945200942]}}"
  
-------------------------------------------
initPose InstantAction (Automatic Button on UI is for Dbot initPosition) 
-------------------------------------------
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/OSRF/TB3_1/instantActions -m '
  {
      "version": "2.0.0",
      "manufacturer": "OSRF",
      "serialNumber": "TB3_1",
      "actions": [
          {
              "actionType": "initPosition",
              "actionId": "'$(cat /proc/sys/kernel/random/uuid)'",
              "blockingType": "NONE",
              "actionParameters": [
                  {
                      "key": "x",
                      "value": "-2.7704"
                  },
                  {
                      "key": "y",
                      "value": "-5.23018"
                  },
                  {
                      "key": "theta",
                      "value": "0.0"
                  },
                  {
                      "key": "mapId",
                      "value": "map"
                  }
              ]
          }
      ]
  }'
----------------------------------------------------------------------
4 Nodes -- A to B to C to again A (WithOut Actions[])
----------------------------------------------------------------------
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/OSRF/TB3_1/order -m '
    {
        "orderId": "'$(cat /proc/sys/kernel/random/uuid)'",
        "orderUpdateId": 0,
        "version": "2.0.0",
        "manufacturer": "OSRF",
        "serialNumber": "TB3_1",
        "nodes": [
            {
                "nodeId": "node1",
                "released": true,
                "sequenceId": 0,
                "nodePosition": {
                    "x": -2.7704,
                    "y": -5.23018,
                    "theta": 0.0135,
                    "mapId": "map"
                },
                "actions": []
            },
            {
                "nodeId": "node2",
                "released": true,
                "sequenceId": 2,
                "nodePosition": {
                    "x": -0.0521810,
                    "y": -5.32476640,
                    "theta": 1.125,
                    "mapId": "map"
                },
                "actions": []
            },
            {
                "nodeId": "node3",
                "released": true,
                "sequenceId": 4,
                "nodePosition": {
                    "x": -0.8227,
                    "y": -1.3880,
                    "theta": -1.584,
                    "mapId": "map"
                },
                "actions": []
            },
            {
                "nodeId": "node1",
                "released": true,
                "sequenceId": 6,
                "nodePosition": {
                    "x": -2.7704,
                    "y": -5.23018,
                    "theta": 0.0135,
                    "mapId": "map"
                },
                "actions": []
            }
        ],
        "edges": [
            {
                "edgeId": "edge1",
                "released": true,
                "sequenceId": 1,
                "startNodeId": "node1",
                "endNodeId": "node2",
                "actions": []
            },
            {
                "edgeId": "edge2",
                "released": true,
                "sequenceId": 3,
                "startNodeId": "node2",
                "endNodeId": "node3",
                "actions": []
            },
            {
                "edgeId": "edge3",
                "released": true,
                "sequenceId": 5,
                "startNodeId": "node3",
                "endNodeId": "node1",
                "actions": []
            }
        ]
    }'
----------------------------------------------------------------------
Single Node testing
----------------------------------------------------------------------
mosquitto_pub -h 192.168.1.115 -p 1883 -t uagv/v2/OSRF/TB3_1/order -m '{
        "orderId": "'$(cat /proc/sys/kernel/random/uuid)'",
        "orderUpdateId": 0,
        "version": "2.0.0",
        "manufacturer": "OSRF",
        "serialNumber": "TB3_1",
        "nodes": [
            {
                "nodeId": "node1",
                "released": true,
                "sequenceId": 0,
                "nodePosition": {
                    "x": -2.778,
                    "y": -1.604,
                    "theta": 0.0,
                    "mapId": "map"
                },
                "actions": []
            },
            {
                "nodeId": "node2",
                "released": true,
                "sequenceId": 2,
                "nodePosition": {
                    "x": 3.973,
                    "y": -8.366,
                    "theta": 0.0,
                    "mapId": "map"
                },
                "actions": []
            }
        ],
        "edges": [
            {
                "edgeId": "edge1",
                "released": true,
                "sequenceId": 1,
                "startNodeId": "node1",
                "endNodeId": "node2",
                "actions": []
            }
        ]
    }'

----------------------------------------------------------

{
  "orderId": "'$(cat /proc/sys/kernel/random/uuid)'",
  "orderUpdateId": 0,
  "version": "2.0.0",
  "manufacturer": "OSRF",
  "serialNumber": "TB3_1",
  "nodes": [
    {
      "nodeId": "node1",
      "released": true,
      "sequenceId": 0,
      "nodePosition": {
        "x": -2.7,
        "y": -1.6,
        "theta": 0.0,
        "mapId": "map"
      },
      "actions": []
    },
    {
      "nodeId": "node2",
      "released": true,
      "sequenceId": 2,
      "nodePosition": {
        "x": 3.9,
        "y": -8.4,
        "theta": 0.0,
        "mapId": "map"
      },
      "actions": []
    }
  ],
  "edges": [
    {
      "edgeId": "edge1",
      "released": true,
      "sequenceId": 1,
      "startNodeId": "node1",
      "endNodeId": "node2",
      "actions": []
    }
  ]
}

------------------------------------------