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
import math

def generate_circle(x, y, z, w, r, points, direction):
    coord_list = []
    angle_increment = direction * math.pi / points  #change to -2 for reverse direction

    for i in range(points):
        theta = i * angle_increment

        x_point = x + r * math.cos(theta)
        y_point = y + r * math.sin(theta)
        z_point = math.sin(theta / 2)
        w_point = math.cos(theta / 2)

        value_list = [round(x_point, 2), round(y_point, 2), round(z_point, 5), round(w_point, 5)]
        coord_list.append(value_list)

    return coord_list


def get_circle(x, y, z, w, radius, points_to_generate, navigator, goal_poses, direction):

    points = generate_circle(x, y, z, w, radius, points_to_generate, direction)

    for i, item in enumerate(points):
        x_point = item[0]
        y_point = item[1]
        z_point = item[2]
        w_point = item[3]

        goal_pose = PoseStamped()
        goal_pose.header.frame_id = 'map'
        goal_pose.header.stamp = navigator.get_clock().now().to_msg()
        goal_pose.pose.position.x = x_point
        goal_pose.pose.position.y = y_point
        goal_pose.pose.orientation.w = z_point
        goal_pose.pose.orientation.z = w_point
        goal_poses.append(goal_pose)


def main():
    rclpy.init()

    navigator = BasicNavigator()

    # Set initial pose
    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = 0.06915
    initial_pose.pose.position.y = 0.00875
    initial_pose.pose.orientation.z = -0.01012096346046257
    initial_pose.pose.orientation.w = 0.9999487817376608
    navigator.setInitialPose(initial_pose)

    navigator.waitUntilNav2Active()

    # set goal poses
    goal_poses = []

    #Generate a circle
    #center point for circle and paramaters

    #x = -6.968
    #y = -1.022
    #z = -0.984
    #w = 0.177
    #radius = 1
    #points_to_generate = 9
    #direction = -2 #should always be 2, - for clockwise and + for counter-clockwise
    #get_circle(x, y, z, w, radius, points_to_generate, navigator, goal_poses, direction)

    #x = 4.82
    #y = -2.96
    #w = -0.99092
    #z = 0.13443
    #radius = 0.5
    #points_to_generate = 7
    #direction = 2 #should always be 2, - for clockwise and + for counter-clockwise
    #get_circle(x, y, z, w, radius, points_to_generate, navigator, goal_poses, direction)

    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose.pose.position.x = -0.07
    goal_pose.pose.position.y = -4.12
    goal_pose.pose.orientation.w = -0.74264
    goal_pose.pose.orientation.z = 0.66969
    goal_poses.append(goal_pose)

    goal_pose2 = PoseStamped()
    goal_pose2.header.frame_id = 'map'
    goal_pose2.header.stamp = navigator.get_clock().now().to_msg()
    goal_pose2.pose.position.x = -1.89
    goal_pose2.pose.position.y = -3.82
    goal_pose2.pose.orientation.w = 0.99630
    goal_pose2.pose.orientation.z = 0.08593
    goal_poses.append(goal_pose2)


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
