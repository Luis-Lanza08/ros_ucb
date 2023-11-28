# ros_ucb
Problemas a la hora de subir el archivo CMakelists.txt general de la direccion: ros_ucb/src/CMakeLists.txt
![image](https://github.com/Luis-Lanza08/ros_ucb/assets/129080944/bccfbd14-d0e4-49ee-9aba-30a7a1ecb121)

# Solucion de ejericios:

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
