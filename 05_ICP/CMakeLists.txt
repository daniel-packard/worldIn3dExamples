cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (05_ICP main.cpp)
target_link_libraries (05_ICP ${PCL_LIBRARIES})