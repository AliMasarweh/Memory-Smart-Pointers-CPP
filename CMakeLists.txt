cmake_minimum_required(VERSION 3.15)
project(SmartPointerExercise)

set(CMAKE_CXX_STANDARD 98)

add_executable(SmartPointerExercise main.cpp auto_pointer.h unique_pointer.h shared_pointer.h person.h person.cpp)