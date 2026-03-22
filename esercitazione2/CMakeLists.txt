cmake_minimum_required(VERSION 3.20)
project(code_es2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


set(SOURCES code_es2.cpp)

add_executable(proges2 ${SOURCES})