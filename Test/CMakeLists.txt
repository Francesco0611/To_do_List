cmake_minimum_required(VERSION 3.30)
project(Test)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(testTask testTask.cpp)
add_executable(testTo_do_List testTo_do_List.cpp)

target_link_libraries(testTask core gtest gtest_main)
target_link_libraries(testTo_do_List core gtest gtest_main)