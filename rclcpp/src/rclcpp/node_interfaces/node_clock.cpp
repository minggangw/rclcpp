// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "rclcpp/node_interfaces/node_clock.hpp"

#include <string>

using rclcpp::node_interfaces::NodeClock;

NodeClock::NodeClock(
  rclcpp::node_interfaces::NodeBaseInterface * node_base,
  rclcpp::node_interfaces::NodeTopicsInterface * node_topics,
  rclcpp::node_interfaces::NodeParametersInterface * node_parameters)
: node_base_(node_base),
  node_topics_(node_topics),
  node_parameters_(node_parameters)
{
  // TODO(tfoote) initialize time source and attach clock and node
}

NodeClock::~NodeClock()
{}

std::shared_ptr<rclcpp::Clock>
NodeClock::get_clock(rcl_clock_type_t clock_type)
{
  switch(clock_type) {
    case RCL_SYSTEM_TIME:
      return system_clock_;
    case RCL_STEADY_TIME:
      return steady_clock_;
    default:
      return ros_clock_;
  }
}
