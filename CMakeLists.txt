cmake_minimum_required(VERSION 3.28)
project(CS50X C)

set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(hello ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/hello.c)
add_executable(name ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/name.c)
add_executable(compare ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/compare.c)
add_executable(agree ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/agree.c)
add_executable(meow ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/meow.c)
add_executable(calculator ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/calculator.c)
add_executable(mario ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/mario.c)

target_link_libraries(name cs50)
target_link_libraries(compare cs50)
target_link_libraries(agree cs50)
target_link_libraries(calculator cs50)
target_link_libraries(mario cs50)
