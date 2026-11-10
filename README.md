# Hero Chassis Controller\nThis is my custom controller.
# Hero Chassis Controller

## Overview
This is a custom ROS controller for the RoboMaster hero chassis, developed as part of the assignment. It is based on the `ros_control` framework and dynamically loaded via `pluginlib`.

**Keywords:** RoboMaster, ROS, ros_control, PID, Kinematics

### License
The source code is released under a [BSD 3-Clause license](LICENSE).

## Installation

### Dependencies
- [Robot Operating System (ROS)](http://wiki.ros.org) (middleware for robotics)
- controller_interface
- hardware_interface
- pluginlib
- control_toolbox

### Building from Source
To build from source, clone the latest version from this repository into your catkin workspace and compile the package using:

    cd ~/your_ros2_ws/src
    git clone https://github.com/swallow-guo/hero_chassis_controller.git
    cd ~/your_ros2_ws
    rosdep install --from-paths src --ignore-src -r -y
    catkin build hero_chassis_controller

## Features
- [x] Basic pluginlib framework
- [x] Inverse Kinematics (Subscribe to `/cmd_vel` and calculate 4-wheel speeds)
- [x] Basic P Control (for wheel velocity tracking)
- [ ] PID Control (using `control_toolbox`)
- [ ] Odometry (Forward Kinematics & TF Broadcast)

*(Note: Update the checklist above as you complete more optional tasks.)*

## Usage
Run the simulation and controller with:

    roslaunch hero_chassis_controller run_simulation_and_controller.launch

## Config files
* **controllers.yaml**: Params of `hero_chassis_controller` and `joint_state_controller`.

## Launch files
* **run_simulation_and_controller.launch**: Hero chassis only simulation and hero chassis controller.
