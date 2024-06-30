cmake_minimum_required(VERSION 3.28)
project(CS50X C)
set(CMAKE_C_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(
        SOURCES
        hello
        name
        compare
        agree
        meow
        calculator
        mario
        contacts
        pyramid
        helloworld
        helloitsme
        mario-less
        mario-more
        cash
        credit
        scores
        length
        string
        uppercase
        double
        alphabetical
        triangle
)

foreach (source IN LISTS SOURCES)
    if (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-1/Lecture/${source}.c)
    elseif (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-1/Section/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-1/Section/${source}.c)
    elseif (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-1/ProblemSet-1/${source}.c)
    elseif (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-2/Lecture/${source}.c)
    elseif (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-2/Section/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-2/Section/${source}.c)
    elseif (EXISTS "${PROJECT_SOURCE_DIR}/src/Week-2/Shorts/${source}.c")
        add_executable(${source} ${PROJECT_SOURCE_DIR}/src/Week-2/Shorts/${source}.c)
    endif ()

    if (TARGET ${source})
        target_link_libraries(${source} cs50)
    endif ()
endforeach ()