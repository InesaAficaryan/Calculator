cmake_minimum_required(VERSION 3.5)

project(calculator)

add_executable(calculator main.cpp calculator.cpp)

target_include_directories(calculator PRIVATE "./include")


