cmake_minimum_required(VERSION 3.1.0)
project(quad_simulation)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs tf roscpp roslib)

################################################
## Declare ROS messages, services and actions ##
################################################

## Add specific stuff for linking the C libraries in the crazyflie-firmware package

set(C_FIRMWARE_DIRECTORY crazyflie-firmware/src/)
include_directories(include ${catkin_INCLUDE_DIRS} ${C_FIRMWARE_DIRECTORY}/modules/interface ${C_FIRMWARE_DIRECTORY}/hal/interface)
add_definitions(-DCOMPILE_AS_SIM_)


## Generate services in the 'srv' folder
#add_service_files(
#   FILES
#   quadsim_call.srv
#)

#add_message_files(
#   FILES
#)

## Generate added messages and services with any dependencies listed here
#generate_messages(
#  DEPENDENCIES
#  geometry_msgs
#)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(CATKIN_DEPENDS geometry_msgs tf roscpp roslib LIBRARIES quad_simulation_LIBRARY INCLUDE_DIRS include ${C_FIRMWARE_DIRECTORY}/modules/interface ${C_FIRMWARE_DIRECTORY}/hal/interface)

## Declare a C++ executable
add_executable(simulation src/simulation.cpp)

## Export c code as a library
add_library(quad_simulation_LIBRARY ${C_FIRMWARE_DIRECTORY}/modules/src/ekf.c ${C_FIRMWARE_DIRECTORY}/modules/src/position_controller_mellinger.c)

set_property(TARGET quad_simulation_LIBRARY PROPERTY C_STANDARD 11)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(simulation ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(simulation
   ${catkin_LIBRARIES}
)

 install(DIRECTORY ${C_FIRMWARE_DIRECTORY}/modules/interface/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
 )

