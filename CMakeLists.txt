cmake_minimum_required(VERSION 2.8.3)
project(quad_simulation)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS message_generation geometry_msgs tf roscpp)

################################################
## Declare ROS messages, services and actions ##
################################################


## Generate services in the 'srv' folder
add_service_files(
   FILES
   register_quads.srv
)

add_message_files(
   FILES
)


## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(CATKIN_DEPENDS geometry_msgs tf roscpp)


## Declare a C++ executable
add_executable(simulation src/simulation.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(simulation ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


## Specify libraries to link a library or executable target against
target_link_libraries(simulation
   ${catkin_LIBRARIES}
)
