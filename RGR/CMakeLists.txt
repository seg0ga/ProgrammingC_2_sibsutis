cmake_minimum_required(VERSION 3.10)
project(triangular_project)

enable_testing()

add_library(triangular_lib SHARED functions.c)

add_executable(main main.c)
target_link_libraries(main triangular_lib)

find_package(cmocka REQUIRED)

add_executable(test_triangle test_triangle.c)
target_link_libraries(test_triangle triangular_lib cmocka)

add_test(NAME tests_of_code COMMAND test_triangle)
