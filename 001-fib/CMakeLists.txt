cmake_minimum_required(VERSION 3.5)

project(001-fib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(001-fib main.cpp)

install(TARGETS 001-fib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
