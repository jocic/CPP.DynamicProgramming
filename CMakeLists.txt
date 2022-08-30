cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(libraries/catch2)

add_executable(dynamic-programming

    problems/001-fib/main.h
    problems/001-fib/main.cpp

    problems/002-gridTraveler/main.h
    problems/002-gridTraveler/main.cpp

    problems/003-canSum/main.h
    problems/003-canSum/main.cpp

    problems/004-howSum/main.h
    problems/004-howSum/main.cpp

    tests/001-fib.h
    tests/002-grid-traveler.h
    tests/003-can-sum.h
    tests/004-how-sum.h

    source/main.cpp
)

target_link_libraries(dynamic-programming PRIVATE Catch2::Catch2WithMain)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000000")
