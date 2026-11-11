//
// Created by qiayuan on 2/6/21.
//#include "hero_chassis_controller/hero_chassis_controlle
#include <geometry_msgs/Twist.h>
#include <controller_interface/controller.h>
#include <hardware_interface/joint_command_interface.h>
#include "hero_chassis_controller/hero_chassis_controller.h"
#include <pluginlib/class_list_macros.hpp>


namespace hero_chassis_controller {
    bool HeroChassisController::init(hardware_interface::EffortJointInterface *effort_joint_interface,
                                       ros::NodeHandle &root_nh, ros::NodeHandle &controller_nh) {
        front_left_joint_ =
            effort_joint_interface->getHandle("left_front_wheel_joint");
        front_right_joint_ =
            effort_joint_interface->getHandle("right_front_wheel_joint");
        back_left_joint_ = effort_joint_interface->getHandle("left_back_wheel_joint");
        back_right_joint_ =
            effort_joint_interface->getHandle("right_back_wheel_joint");
        cmd_vel_sub_ = controller_nh.subscribe("/cmd_vel", 10, &HeroChassisController::cmdVelCallback, this);

        return true;
    }
    void HeroChassisController::cmdVelCallback(const geometry_msgs::Twist& msg) {
        cmd_vel_ = msg;
    }
    void HeroChassisController::update(const ros::Time &time, const ros::Duration &period) {
        double vx = cmd_vel_.linear.x;
        double vy = cmd_vel_.linear.y;
        double wz = cmd_vel_.angular.z;


        double r = 0.07;
        double lx = 0.2;
        double ly = 0.2;


        double target_v_fl = (vx - vy - (lx + ly) * wz) / r;
        double target_v_fr = (vx + vy + (lx + ly) * wz) / r;
        double target_v_bl = (vx + vy - (lx + ly) * wz) / r;
        double target_v_br = (vx - vy + (lx + ly) * wz) / r;


        double current_v_fl = front_left_joint_.getVelocity();
        double current_v_fr = front_right_joint_.getVelocity();
        double current_v_bl = back_left_joint_.getVelocity();
        double current_v_br = back_right_joint_.getVelocity();


        double kp = 10.0;

        front_left_joint_.setCommand(kp * (target_v_fl - current_v_fl));
        front_right_joint_.setCommand(kp * (target_v_fr - current_v_fr));
        back_left_joint_.setCommand(kp * (target_v_bl - current_v_bl));
        back_right_joint_.setCommand(kp * (target_v_br - current_v_br));
    }


    PLUGINLIB_EXPORT_CLASS(hero_chassis_controller::HeroChassisController, controller_interface::ControllerBase);
}

