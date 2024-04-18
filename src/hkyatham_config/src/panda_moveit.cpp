#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.h>


int main(int argc, char * argv[])
{
  // Initialize ROS and create the Node
  rclcpp::init(argc, argv);
  auto const node = std::make_shared<rclcpp::Node>(
      "panda_moveit", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

  // Create a ROS logger
  auto const logger = rclcpp::get_logger("panda_moveit");

  // Create the MoveIt MoveGroup Interface
  using moveit::planning_interface::MoveGroupInterface;
  auto move_group_interface = MoveGroupInterface(node, "panda_arm");
  auto move_hand_interface = MoveGroupInterface(node, "panda_hand");

move_hand_interface.setNamedTarget("open");
auto const [success3, plan3] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success3)
  {
    move_group_interface.execute(plan3);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }
  move_group_interface.setNamedTarget("home");

  // Create a plan to that target pose
  auto const [success, plan] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success)
  {
    move_group_interface.execute(plan);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }
  move_group_interface.setNamedTarget("pick");

  // Create a plan to that target pose
  auto const [success2, plan2] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success2)
  {
    move_group_interface.execute(plan2);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }
  move_hand_interface.setNamedTarget("close");
auto const [success4, plan4] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success4)
  {
    move_group_interface.execute(plan4);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }
  move_group_interface.setNamedTarget("place");

  // Create a plan to that target pose
  auto const [success1, plan1] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success1)
  {
    move_group_interface.execute(plan1);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }
  move_group_interface.setNamedTarget("home");

  // Create a plan to that target pose
  auto const [success5, plan5] = [&move_group_interface] {
    moveit::planning_interface::MoveGroupInterface::Plan msg;
    auto const ok = static_cast<bool>(move_group_interface.plan(msg));
    return std::make_pair(ok, msg);
  }();

  // Execute the plan
  if (success5)
  {
    move_group_interface.execute(plan5);
  }
  else
  {
    RCLCPP_ERROR(logger, "Planning failed!");
  }

  // Shutdown ROS
  rclcpp::shutdown();
  return 0;
}