cmake_minimum_required(VERSION 3.0)
project(YARoG)

find_package(glfw3 REQUIRED)

add_executable(YARoG main.cpp)

target_link_libraries(YARoG glfw)
