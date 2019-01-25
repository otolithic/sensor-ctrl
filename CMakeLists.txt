cmake_minimum_required(VERSION 2.8.3)
project(kate_tests)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  robotiq_ft_sensor
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS message_runtime
)

###########
## Build ##
###########

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

# make the executables
add_executable(kate_tests src/listener.cpp)
add_dependencies(kate_tests ${catkin_EXPORTED_TARGETS})
target_link_libraries(kate_tests ${catkin_LIBRARIES})

add_executable(listener src/listener.cpp)
add_dependencies(listener ${catkin_EXPORTED_TARGETS})
target_link_libraries(listener ${catkin_LIBRARIES})
