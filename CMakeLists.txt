cmake_minimum_required(VERSION 3.3)
project(TreeMas)

set(SOURCE_FILES main.cpp Tree.cpp Tree.h ChildTree.cpp ChildTree.h Root.cpp Root.h)
add_executable(TreeMas ${SOURCE_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lboost_unit_test_framework -lboost_program_options -lboost_system -pg")

FIND_PACKAGE(Boost COMPONENTS unit_test_framework system REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

set(SOURCE_FILES Tests.cpp)
add_executable(Tests ${SOURCE_FILES} Tests.cpp)

TARGET_LINK_LIBRARIES(Tests ${Boost_LIBRARIES})
