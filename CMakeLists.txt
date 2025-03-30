cmake_minimum_required(VERSION 3.26.1)
project(cinema)
include_directories(include)
add_executable(app main.cpp src/city.cpp src/theater.cpp)