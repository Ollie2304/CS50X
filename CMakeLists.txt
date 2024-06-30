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

set(
        WEEKS
        "Week-1/Lecture"
        "Week-1/Section"
        "Week-1/ProblemSet-1"
        "Week-2/Lecture"
        "Week-2/Section"
        "Week-2/Shorts"
)

foreach (source IN LISTS SOURCES)
    foreach (week IN LISTS WEEKS)
        if (EXISTS "${PROJECT_SOURCE_DIR}/src/${week}/${source}.c")
            add_executable(${source} ${PROJECT_SOURCE_DIR}/src/${week}/${source}.c)
            if (TARGET ${source})
                target_link_libraries(${source} cs50)
            endif ()
            break()
        endif ()
    endforeach ()
endforeach ()