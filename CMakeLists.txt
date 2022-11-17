cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(libraries/catch2)

add_executable(dynamic-programming

    problems/fib/main.h
    problems/fib/main.cpp

#    problems/002-gridTraveler/main.h
#    problems/002-gridTraveler/main.cpp

#    problems/003-canSum/main.h
#    problems/003-canSum/main.cpp

#    problems/004-howSum/main.h
#    problems/004-howSum/main.cpp

#    problems/005-bestSum/main.h
#    problems/005-bestSum/main.cpp

#    problems/maximal-square/problem.h
#    problems/maximal-square/problem.cpp
#    tests/maximal-square.h

#    problems/jumping-stones/problem.h
#    problems/jumping-stones/problem.cpp
#    tests/jumping-stones.h

    tests/fib.h
#    tests/002-grid-traveler.h
#    tests/003-can-sum.h
#    tests/004-how-sum.h
#    tests/005-best-sum.h

    source/main.cpp
)

target_link_libraries(dynamic-programming PRIVATE Catch2::Catch2WithMain)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000000")
