// Copyright 2017 Open Source Robotics Foundation, Inc.
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

#include <gtest/gtest.h>

#include <chrono>
#include <string>
#include <memory>

#include "rclcpp/exceptions.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/steady_time.hpp"

using namespace std::chrono_literals;

class TestMultiThreadedExecutor : public ::testing::Test
{
protected:
  static void SetUpTestCase()
  {
    rclcpp::init(0, nullptr);
  }
};

/*
   Test that timers are not taken multiple times when using reentrant callback groups.
 */
TEST_F(TestMultiThreadedExecutor, timer_over_take) {
  std::shared_ptr<rclcpp::Node> node =
    std::make_shared<rclcpp::Node>("test_multi_threaded_executor_timer_over_take");
  auto cbg = node->create_callback_group(rclcpp::callback_group::CallbackGroupType::Reentrant);
  auto start = rclcpp::SteadyTime::now();
  size_t count = 1;
  auto timer = node->create_wall_timer(100ms, [&start, &count]() {
    auto time_since_start = rclcpp::SteadyTime::now() - start;
  });
}
