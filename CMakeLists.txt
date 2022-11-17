cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(libraries/catch2)

add_executable(dynamic-programming

    problems/fib/main.h
    problems/fib/main.cpp

    problems/grid-traveler/main.h
    problems/grid-traveler/main.cpp

    problems/can-sum/main.h
    problems/can-sum/main.cpp

    problems/how-sum/main.h
    problems/how-sum/main.cpp

#    problems/005-bestSum/main.h
#    problems/005-bestSum/main.cpp

#    problems/maximal-square/problem.h
#    problems/maximal-square/problem.cpp
#    tests/maximal-square.h

#    problems/jumping-stones/problem.h
#    problems/jumping-stones/problem.cpp
#    tests/jumping-stones.h

    tests/fib.h
    tests/grid-traveler.h
    tests/can-sum.h
    tests/how-sum.h
#    tests/005-best-sum.h

    source/main.cpp
)

target_link_libraries(dynamic-programming PRIVATE Catch2::Catch2WithMain)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000000")
