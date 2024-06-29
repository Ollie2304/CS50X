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

add_executable(contacts ${PROJECT_SOURCE_DIR}/src/Week-1/Section/contacts.c)
add_executable(pyramid ${PROJECT_SOURCE_DIR}/src/Week-1/Section/pyramid.c)

add_executable(helloworld ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/helloworld.c)
add_executable(helloitsme ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/helloitsme.c)
add_executable(mario-less ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/mario-less.c)
add_executable(mario-more ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/mario-more.c)
add_executable(cash ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/cash.c)
add_executable(credit ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/credit.c)

add_executable(scores ${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/scores.c)
add_executable(length ${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/length.c)
add_executable(string ${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/string.c)
add_executable(uppercase ${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/uppercase.c)

add_executable(double ${PROJECT_SOURCE_DIR}/src/Week-2/Section/double.c)
add_executable(alphabetical ${PROJECT_SOURCE_DIR}/src/Week-2/Section/alphabetical.c)

target_link_libraries(name cs50)
target_link_libraries(compare cs50)
target_link_libraries(agree cs50)
target_link_libraries(calculator cs50)
target_link_libraries(mario cs50)

target_link_libraries(contacts cs50)
target_link_libraries(pyramid cs50)

target_link_libraries(helloitsme cs50)
target_link_libraries(mario-less cs50)
target_link_libraries(mario-more cs50)
target_link_libraries(cash cs50)
target_link_libraries(credit cs50)

target_link_libraries(scores cs50)
target_link_libraries(length cs50)
target_link_libraries(string cs50)
target_link_libraries(uppercase cs50)

target_link_libraries(double cs50)
target_link_libraries(alphabetical cs50)