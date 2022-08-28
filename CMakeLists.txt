cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/catch2)

add_executable(tests

    001-fib/main.h
    001-fib/main.cpp

    002-gridTraveler/main.h
    002-gridTraveler/main.cpp

    003-canSum/main.h
    003-canSum/main.cpp

    tests/001-fib-tests.h
    tests/002-grid-traveler-tests.h
    tests/003-can-sum-tests.h

    tests/main.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10000000000")
