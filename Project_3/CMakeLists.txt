cmake_minimum_required(VERSION 3.12)
project(Project_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_3
               main.cpp
               PlayList.cpp PlayList.h
               Song.cpp Song.h)
