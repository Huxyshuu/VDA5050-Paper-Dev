
#! /usr/bin/env python3
# Copyright 2021 Samsung Research America
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from rclpy.duration import Duration

"""
Basic navigation demo to go to poses.
"""


def main():
    rclpy.init()

    navigator = BasicNavigator()

    # Set our demo's initial pose
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = -2.43
    initial_pose.pose.position.y = 11.98
    initial_pose.pose.orientation.z = -0.5609755243567902
    initial_pose.pose.orientation.w = 0.8278323870643285
    navigator.setInitialPose(initial_pose)

    navigator.waitUntilNav2Active()

    # set our demo's goal poses
    goal_poses = []
    goal_pose1 = PoseStamped()
    goal_pose1.header.frame_id = 'map'
    goal_pose1.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose1.pose.position.x = -7.60
    goal_pose1.pose.position.y = -0.97
    goal_pose1.pose.orientation.w = 0.9943775184377706
    goal_pose1.pose.orientation.z = 0.10589311037806598
    goal_poses.append(goal_pose1)

    goal_pose2 = PoseStamped()
    goal_pose2.header.frame_id = 'map'
    goal_pose2.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose2.pose.position.x = -8.44
    goal_pose2.pose.position.y = -1.80
    goal_pose2.pose.orientation.w = 0.07434361039232239
    goal_pose2.pose.orientation.z = 0.9972326847801543
    goal_poses.append(goal_pose2)

    #goal_pose3 = PoseStamped()
    #goal_pose3.header.frame_id = 'map'
    #goal_pose3.header.stamp = navigator.get_clock().now().to_msg()
    #goal_pose3.pose.position.x = 16.692912439231986
    #goal_pose3.pose.position.y = -1.0993501787312698
    #goal_pose3.pose.orientation.w = 0.07434361039232239
    #goal_pose3.pose.orientation.z = 0.9972326847801543
    #goal_poses.append(goal_pose3)

    #goal_pose4 = PoseStamped()
    #goal_pose4.header.frame_id = 'map'
    #goal_pose4.header.stamp = navigator.get_clock().now().to_msg()
    #goal_pose4.pose.position.x = 17.040161857746327
    #goal_pose4.pose.position.y = 6.21275441467242
    #goal_pose4.pose.orientation.w = 0.554653723736308
    #goal_pose4.pose.orientation.z = 0.8320812741225748
    #goal_poses.append(goal_pose4)

    # sanity check a valid path exists
    # path = navigator.getPathThroughPoses(initial_pose, goal_poses)

    print(list)
    navigator.goThroughPoses(goal_poses)

    i = 0
    while not navigator.isTaskComplete():
        ################################################
        #
        # Implement some code here for your application!
        #
        ################################################

        # Do something with the feedback
        i = i + 1
        feedback = navigator.getFeedback()
        if feedback and i % 5 == 0:
            print('Estimated time of arrival: ' + '{0:.0f}'.format(
                  Duration.from_msg(feedback.estimated_time_remaining).nanoseconds / 1e9)
                  + ' seconds.')

            # Some navigation timeout to demo cancellation
            if Duration.from_msg(feedback.navigation_time) > Duration(seconds=600.0):
                navigator.cancelTask()

            # Some navigation request change to demo preemption
            #if Duration.from_msg(feedback.navigation_time) > Duration(seconds=35.0):
               # goal_pose4 = PoseStamped()
               # goal_pose4.header.frame_id = 'map'
               # goal_pose4.header.stamp = navigator.get_clock().now().to_msg()
               # goal_pose4.pose.position.x = -2.0
               # goal_pose4.pose.position.y = -4.0
               # goal_pose4.pose.orientation.w = 0.8
               # goal_pose4.pose.orientation.z = 0.6
               # navigator.goThroughPoses([goal_pose4])

    # Do something depending on the return code
    result = navigator.getResult()
    if result == TaskResult.SUCCEEDED:
        print('Goal succeeded!')
        print('Returning to home position')
        navigator.goToPose(initial_pose)

    elif result == TaskResult.CANCELED:
        print('Goal was canceled!')
        print('Returning to home position')
        navigator.goToPose(initial_pose)

    elif result == TaskResult.FAILED:
        print('Goal failed!')
        print('Returning to home position')
        navigator.goToPose(initial_pose)

    else:
        print('Goal has an invalid return status!')
        print('Returning to home position')
        navigator.goToPose(initial_pose)

    if navigator.isTaskComplete():
        navigator.lifecycleShutdown()  

    exit(0)


if __name__ == '__main__':
    main()
