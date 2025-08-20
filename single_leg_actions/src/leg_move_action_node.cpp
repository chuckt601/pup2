#include "behaviortree_cpp_v3/action_node.h"
#include "rclcpp/rclcpp.hpp"
#include "single_leg_actions/action/leg_move_actions.hpp"
#include "rclcpp_action/rclcpp_action.hpp"


using LegMoveActions = single_leg_actions::action::LegMoveActions;

class LegMoveActionNode : public BT::AsyncActionNode {
public:
    LegMoveActionNode(const std::string &name, const BT::NodeConfiguration &config)
        : BT::AsyncActionNode(name, config),
          node_(rclcpp::Node::make_shared("leg_move_action_bt")) {
        client_ = rclcpp_action::create_client<LegMoveActions>(node_, "leg_move_action");
    }

    static BT::PortsList providedPorts() {
        return {
            BT::InputPort<float>("z_target"),
            BT::InputPort<float>("x_target"),
            BT::InputPort<int>("leg")
        };
    }

    BT::NodeStatus tick() override {
        if (!client_->wait_for_action_server(std::chrono::seconds(2))) {
            RCLCPP_ERROR(node_->get_logger(), "Action server not available");
            return BT::NodeStatus::FAILURE;
        }

        // Create goal message
        auto goal = LegMoveActions::Goal();
        if (!getInput("z_target", goal.z_target) ||
            !getInput("x_target", goal.x_target) ||
            !getInput("leg", goal.leg)) {
            RCLCPP_ERROR(node_->get_logger(), "Missing input");
            return BT::NodeStatus::FAILURE;
        }

        // Send goal and wait for result
        auto future_goal_handle = client_->async_send_goal(goal);
        if (rclcpp::spin_until_future_complete(node_, future_goal_handle) !=
            rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(node_->get_logger(), "Failed to send goal");
            return BT::NodeStatus::FAILURE;
        }

        auto goal_handle = future_goal_handle.get();
        if (!goal_handle) {
            RCLCPP_ERROR(node_->get_logger(), "Goal was rejected by server");
            return BT::NodeStatus::FAILURE;
        }

        auto future_result = client_->async_get_result(goal_handle);
        if (rclcpp::spin_until_future_complete(node_, future_result) !=
            rclcpp::FutureReturnCode::SUCCESS) {
            RCLCPP_ERROR(node_->get_logger(), "Failed to get result");
            return BT::NodeStatus::FAILURE;
        }

        auto result = future_result.get();
        //if (result.code == rclcpp::FutureReturnCode::SUCCESS) {
        //if (result->result_code == result->SUCCESS) {    
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {  
            RCLCPP_INFO(node_->get_logger(), "Action succeeded");
            return BT::NodeStatus::SUCCESS;
        } else {
            RCLCPP_ERROR(node_->get_logger(), "Action failed");
            return BT::NodeStatus::FAILURE;
        }
    }

private:
    rclcpp::Node::SharedPtr node_;
    rclcpp_action::Client<LegMoveActions>::SharedPtr client_;
};
