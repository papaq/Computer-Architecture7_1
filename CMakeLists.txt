cmake_minimum_required(VERSION 3.3)
project(TreeMas)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Tree.cpp Tree.h ChildTree.cpp ChildTree.h Root.cpp Root.h)
add_executable(TreeMas ${SOURCE_FILES})