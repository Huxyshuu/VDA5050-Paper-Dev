#ifndef ODOMETRY_ESTIMATION_NODE_H
#define ODOMETRY_ESTIMATION_NODE_H

#include <chrono>
#include <nav_msgs/msg/odometry.hpp>
#include <std_msgs/msg/int64.hpp>
#include <std_msgs/msg/float64.hpp>
#include <vector>

#include "vehicle_models.h"
#include "rclcpp/rclcpp.hpp"
#include "dbot_custom_msgs/msg/wheel_encoder.hpp"

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class OdometryEstimator : public rclcpp::Node {
 public:
  OdometryEstimator();

 private:
  void handleWheelEncoderInput(const dbot_custom_msgs::msg::WheelEncoder::SharedPtr rpm_wheel);
  void publish();
  VehicleModelPtr vehicle_model_{nullptr};
  VehicleState state_{0.0, 0.0, 0.0};
  std::vector<double> rpms_left_;
  std::vector<double> rpms_right_;
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
  rclcpp::Subscription<dbot_custom_msgs::msg::WheelEncoder>::SharedPtr wheel_encoder_subscriber_;
  rclcpp::TimerBase::SharedPtr timer_;
  TimePoint previous_time_{};
};

#endif  // ODOMETRY_ESTIMATION_NODE_H
