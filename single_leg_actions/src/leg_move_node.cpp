#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include "single_leg_actions/action/leg_move_actions.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <champ_msgs/msg/foot_pos_deltas.hpp>
#include "std_msgs/msg/float32_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"



class leg_move_node : public rclcpp::Node {
public:
    using Leg_move_actions = single_leg_actions::action::LegMoveActions;
    using GoalHandle_Leg_move_actions = rclcpp_action::ServerGoalHandle<Leg_move_actions>;

    leg_move_node() : Node("leg_move_node") {
        // Publisher
        //publisher_ = this->create_publisher<my_package::msg::MyMessage>("custom_topic", 10);
        foot_pos_deltas_publisher_ = this->create_publisher<champ_msgs::msg::FootPosDeltas>("foot_pos_deltas", 10);
        CG_offset_publisher_ = this->create_publisher<std_msgs::msg::Float32MultiArray>("CG_offset", 10);
        
        roll_subscriber_ = this->create_subscription<std_msgs::msg::Float32>(
        "roll", 10, std::bind(&leg_move_node::rollCallback_, this,  std::placeholders::_1));
        pitch_subscriber_ = this->create_subscription<std_msgs::msg::Float32>(
        "pitch", 10, std::bind(&leg_move_node::pitchCallback_, this,  std::placeholders::_1));
        foot_force_subscriber_ = this->create_subscription<std_msgs::msg::Float64MultiArray>(
        "measured_footForce", 10, std::bind(&leg_move_node::footForceCallback_, this,  std::placeholders::_1));

         
        
        
        
        balance_offset_server_ = rclcpp_action::create_server<Leg_move_actions>(
            this,
            "balance_offset_action",
            std::bind(&leg_move_node::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&leg_move_node::handle_cancel, this, std::placeholders::_1),
            std::bind(&leg_move_node::handle_accepted_balance_offset, this, std::placeholders::_1)
        );
        
        leg_move_server_ = rclcpp_action::create_server<Leg_move_actions>(
            this,
            "leg_move_action",
            std::bind(&leg_move_node::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&leg_move_node::handle_cancel, this, std::placeholders::_1),
            std::bind(&leg_move_node::handle_accepted_leg_move, this, std::placeholders::_1)
        );
        
    }


private:
    //rclcpp::Publisher<my_package::msg::MyMessage>::SharedPtr publisher_;
    rclcpp::Publisher<champ_msgs::msg::FootPosDeltas>::SharedPtr foot_pos_deltas_publisher_;
    rclcpp::Publisher<std_msgs::msg::Float32MultiArray>::SharedPtr CG_offset_publisher_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr roll_subscriber_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr pitch_subscriber_;
    rclcpp::Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr foot_force_subscriber_;


    float imu_roll=0.0;
    float imu_pitch=0.0;
    double measured_foot_force[4]={0.0, 0.0, 0.0, 0.0};

    
    rclcpp_action::Server<Leg_move_actions>::SharedPtr balance_offset_server_;
    rclcpp_action::Server<Leg_move_actions>::SharedPtr leg_move_server_;
    
    


    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const Leg_move_actions::Goal> goal) {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal request with target %f", goal->z_target);
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandle_Leg_move_actions> goal_handle) {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Cancel request received");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted_balance_offset(
        const std::shared_ptr<GoalHandle_Leg_move_actions> goal_handle) {
        std::thread([this, goal_handle]() {
            auto goal = goal_handle->get_goal();
            RCLCPP_INFO(this->get_logger(), "Executing goal with target %f", goal->z_target);

            
            std_msgs::msg::Float32MultiArray CG_offset;
            switch (goal->leg) {
                case 0:
                   CG_offset.data={-goal->z_target,-goal->z_target};
                   break;
                case 1:
                   CG_offset.data={-goal->z_target,goal->z_target};
                   break;
                case 2: 
                   CG_offset.data={goal->z_target,-goal->z_target};
                   break;
                case 3:
                   CG_offset.data={goal->z_target,goal->z_target};
                   break;
                default:
                   CG_offset.data={0.0f, 0.0f};
            }       

            //CG_offset.data={.2,-.2};
            CG_offset_publisher_->publish(CG_offset);
/*
            champ_msgs::msg::FootPosDeltas foot_pos_deltas;
            for (int i = 0; i < 4; ++i) {
              champ_msgs::msg::Transformation transform;
              transform.translation.x = 0;
              transform.translation.y = 0;
              transform.translation.z = 0.0;

              transform.rotation.x = 0;
              transform.rotation.y = 0;
              transform.rotation.w = 0;
              // Assign the transform to the array
              foot_pos_deltas.foot_pos_deltas[i] = transform;
            }
*/                    
            //foot_pos_deltas_publisher_->publish(foot_pos_deltas);

            auto result = std::make_shared<Leg_move_actions::Result>();
            result->success = true;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal execution completed");
        }).detach();
    }
    
    void handle_accepted_leg_move(const std::shared_ptr<GoalHandle_Leg_move_actions> goal_handle) {
        std::thread([this, goal_handle]() {
            auto goal = goal_handle->get_goal();
            RCLCPP_INFO(this->get_logger(), "Executing goal with target %f", goal->z_target);
 
            champ_msgs::msg::FootPosDeltas foot_pos_deltas;
            for (int i = 0; i < 4; ++i) {
              champ_msgs::msg::Transformation transform;
              transform.translation.x = 0;
              transform.translation.y = 0;
              transform.translation.z = 0;

              transform.rotation.x = 0;
              transform.rotation.y = 0;
              transform.rotation.w = 0;
              // Assign the transform to the array
              foot_pos_deltas.foot_pos_deltas[i] = transform;
            }
            foot_pos_deltas.foot_pos_deltas[goal->leg].translation.x = goal->x_target;
            foot_pos_deltas.foot_pos_deltas[goal->leg].translation.y = goal->y_target;
            foot_pos_deltas.foot_pos_deltas[goal->leg].translation.z = goal->z_target;       
            foot_pos_deltas_publisher_->publish(foot_pos_deltas);

            auto result = std::make_shared<Leg_move_actions::Result>();
            result->success = true;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal execution completed");
        }).detach();
    }

    void rollCallback_(const std_msgs::msg::Float32 msg) {   
       imu_roll=msg.data;          
    }
    void pitchCallback_(const std_msgs::msg::Float32 msg) {   
       imu_pitch=msg.data;          
    }
    void footForceCallback_(const std_msgs::msg::Float64MultiArray msg) { 
       for (int i=0; i<4; i++) {
        measured_foot_force[i]=msg.data[i]; 
       }
    }

};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    //rclcpp::spin(std::make_shared<leg_move_node>());
    // Create an instance of the node using `make_shared`
    auto node = std::make_shared<leg_move_node>();

    // Run the node with the rclcpp spinning loop
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
