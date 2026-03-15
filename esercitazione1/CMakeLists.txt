cmake_minimum_required(VERSION 3.20)
project(media_temp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES media_temp.cpp)

add_executable(medie_prog ${SOURCES})