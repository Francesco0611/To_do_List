cmake_minimum_required(VERSION 4.0)
project(To_do_List)

set(CMAKE_CXX_STANDARD 11)

add_executable(To_do_List
        main.cpp
        Task.cpp
        Task.h
        To_do_List.cpp
        To_do_List.h)
