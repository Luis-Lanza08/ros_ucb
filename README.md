# ros_ucb
Problemas a la hora de subir el archivo CMakelists.txt general de la direccion: ros_ucb/src/CMakeLists.txt
![image](https://github.com/Luis-Lanza08/ros_ucb/assets/129080944/bccfbd14-d0e4-49ee-9aba-30a7a1ecb121)

este es el codigo que tiene ese archivo CMakeLists.txt

```
# toplevel CMakeLists.txt for a catkin workspace
# catkin/cmake/toplevel.cmake

cmake_minimum_required(VERSION 3.0.2)

project(Project)

set(CATKIN_TOPLEVEL TRUE)

# search for catkin within the workspace
set(_cmd "catkin_find_pkg" "catkin" "${CMAKE_SOURCE_DIR}")
execute_process(COMMAND ${_cmd}
  RESULT_VARIABLE _res
  OUTPUT_VARIABLE _out
  ERROR_VARIABLE _err
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_STRIP_TRAILING_WHITESPACE
)
if(NOT _res EQUAL 0 AND NOT _res EQUAL 2)
  # searching fot catkin resulted in an error
  string(REPLACE ";" " " _cmd_str "${_cmd}")
  message(FATAL_ERROR "Search for 'catkin' in workspace failed (${_>endif()

# include catkin from workspace or via find_package()
if(_res EQUAL 0)
  set(catkin_EXTRAS_DIR "${CMAKE_SOURCE_DIR}/${_out}/cmake")        
  # include all.cmake without add_subdirectory to let it operate in>  include(${catkin_EXTRAS_DIR}/all.cmake NO_POLICY_SCOPE)
  add_subdirectory("${_out}")

else()
  # use either CMAKE_PREFIX_PATH explicitly passed to CMake as a co>  # or CMAKE_PREFIX_PATH from the environment
  if(NOT DEFINED CMAKE_PREFIX_PATH)
    if(NOT "$ENV{CMAKE_PREFIX_PATH}" STREQUAL "")
      if(NOT WIN32)
        string(REPLACE ":" ";" CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_>      else()
        set(CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH})
      endif()
    endif()
  endif()

  # list of catkin workspaces
  set(catkin_search_path "")
  foreach(path ${CMAKE_PREFIX_PATH})
    if(EXISTS "${path}/.catkin")
      list(FIND catkin_search_path ${path} _index)
      if(_index EQUAL -1)
        list(APPEND catkin_search_path ${path})
      endif()
    endif()
  endforeach()

  # search for catkin in all workspaces
  set(CATKIN_TOPLEVEL_FIND_PACKAGE TRUE)
  find_package(catkin QUIET
    NO_POLICY_SCOPE
    PATHS ${catkin_search_path}
    NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  unset(CATKIN_TOPLEVEL_FIND_PACKAGE)

  if(NOT catkin_FOUND)
    message(FATAL_ERROR "find_package(catkin) failed. catkin was ne>  endif()
endif()

catkin_workspace()

```


# Solucion de ejercicios:

source /home/ros_ucb/devel/setup.bash


ejercicio 1.

roslaunch beginner_tutorials exercise1.launch run_node_A:=True run_node_B:=True

roslaunch beginner_tutorials exercise1.launch run_node_A:=True

roslaunch beginner_tutorials exercise1.launch run_node_B:=True

ejercicio 2.

a.
roslaunch beginner_tutorials rand_vel_turtle.launch

b.
roslaunch beginner_tutorials rand_vels.launch

c.
roslaunch beginner_tutorials teleopturtle_rand_vel.launch use_random_vel:=false   // or true

ejercicio 3.


a.
rosrun turtlesim turtlesim_node

rosrun message_tests improved_pubvel_toggle

rosservice call /toogle_stop_run

rosservice call /change_speed 5

b.
roscore

rosrun turtlesim turtlesim_node

rosrun message_tests improved_pubvel_toggle

rosrun message_tests spawn_turtle_plus

rosservice call /toogle_stop_run

rosservice call /toggle_forward

rosservice call /change_rate 10

rosservice call /change_speed 5

