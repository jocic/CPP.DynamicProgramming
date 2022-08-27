cmake_minimum_required(VERSION 3.5)

project(002-gridTraveler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(002-gridTraveler main.h main.cpp)

install(TARGETS 002-gridTraveler
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
