cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(libs/catch2)

add_executable(dynamic-programming

    problems/001-fib/main.h
    problems/001-fib/main.cpp

    problems/002-gridTraveler/main.h
    problems/002-gridTraveler/main.cpp

    problems/003-canSum/main.h
    problems/003-canSum/main.cpp

    tests/001-fib-tests.h
    tests/002-grid-traveler-tests.h
    tests/003-can-sum-tests.h

    src/main.cpp
)

target_link_libraries(dynamic-programming PRIVATE Catch2::Catch2WithMain)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000000")
