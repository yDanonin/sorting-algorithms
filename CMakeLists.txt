cmake_minimum_required(VERSION 3.24)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms main.c algs/sorting_algorithms.h algs/quick_sort.c algs/binary_insertion_sort.c algs/radix_sort.c)
