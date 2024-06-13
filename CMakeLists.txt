cmake_minimum_required(VERSION 3.28)
project(CS50X C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

link_directories(lib)

add_executable(CS50X
        src/Week-1/Lecture/hello.c)

target_link_libraries(CS50X cs50)
