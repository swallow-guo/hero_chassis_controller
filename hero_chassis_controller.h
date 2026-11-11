//
// Created by qiayuan on 2/6/21.
//

#ifndef hero_chassis_controller_hero_chassis_controller_H
#define hero_chassis_controller_hero_chassis_controller_H

#include <controller_interface/controller.h>
#include <hardware_interface/joint_command_interface.h>
#include <geometry_msgs/Twist.h>

namespace hero_chassis_controller {

class HeroChassisController : public controller_interface::Controller<hardware_interface::EffortJointInterface> {
 public:
  HeroChassisController() = default;
  ~HeroChassisController() override = default;

  bool init(hardware_interface::EffortJointInterface *effort_joint_interface,
            ros::NodeHandle &root_nh, ros::NodeHandle &controller_nh) override;

  void update(const ros::Time &time, const ros::Duration &period) override;

  hardware_interface::JointHandle front_left_joint_, front_right_joint_, back_left_joint_, back_right_joint_;
 private:
    ros::Subscriber cmd_vel_sub_;
    geometry_msgs::Twist cmd_vel_;
    void cmdVelCallback(const geometry_msgs::Twist& msg);
  int state_{};
  ros::Time last_change_;
};
}// namespace hero_chassis_controller

#endif //hero_chassis_controller_hero_chassis_controller_H
