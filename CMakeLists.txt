cmake_minimum_required(VERSION 3.10)
project(hero_chassis_controller)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
## enforcing cleaner code.
add_definitions(-Wall -Werror)

## Find catkin macros and libraries
find_package(catkin REQUIRED
    COMPONENTS
    geometry_msgs
    roscpp
    roslint
    controller_interface
    hardware_interface
    forward_command_controller
    pluginlib
    )



roslint_cpp()
include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)
add_library(hero_chassis_controller
        src/hero_chassis_controller.cpp
)
target_link_libraries(hero_chassis_controller
        ${catkin_LIBRARIES}
)
catkin_package(
        INCLUDE_DIRS include
        LIBRARIES hero_chassis_controller
        CATKIN_DEPENDS geometry_msgs roscpp controller_interface hardware_interface
)