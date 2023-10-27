cmake_minimum_required(VERSION 3.24)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms main.c quick_sort.h quick_sort.c)
