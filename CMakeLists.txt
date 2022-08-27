cmake_minimum_required(VERSION 3.5)

project(dynamic-programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_library(001-fib 001-fib/main.h 001-fib/main.cpp)
add_library(002-gridTraveler 002-gridTraveler/main.h 002-gridTraveler/main.cpp)

add_executable(tests tests/main.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE 001-fib)

