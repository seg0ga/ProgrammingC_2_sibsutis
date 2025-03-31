cmake_minimum_required(VERSION 3.10)
project(qwerty)


add_library(bibl ${TYPE} main.c ishod.c)

add_executable(main123 main.c)
target_link_libraries(main123 bibl)
