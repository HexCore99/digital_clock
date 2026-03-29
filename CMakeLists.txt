cmake_minimum_required(VERSION 3.16)
project(digital_clock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(digital_clock digital_clock.cpp)
target_link_libraries(digital_clock PRIVATE raylib)
