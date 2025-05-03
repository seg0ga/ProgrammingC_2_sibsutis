cmake_minimum_required(VERSION 3.10)
project(triangular_project LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

enable_testing()

add_executable(main main.c functions.c)

find_package(cmocka REQUIRED)

add_executable(test_triangle test_triangle.c functions.c)

target_link_libraries(test_triangle PRIVATE cmocka)
add_test(NAME run_tests COMMAND test_triangle)