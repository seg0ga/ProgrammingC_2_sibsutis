cmake_minimum_required(VERSION 3.10)
project(SortTests)

enable_testing()
find_package(cmocka REQUIRED)

add_executable(sort_tests test_sorts.c sort.c)

target_link_libraries(sort_tests cmocka)
add_test(NAME SortTests COMMAND sort_tests)
set(CTEST_OUTPUT_ON_FAILURE ON)
