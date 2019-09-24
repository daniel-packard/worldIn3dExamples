cmake_minimum_required(VERSION 3.15)

project(worldIn3dExamples VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find librealsense2 installed package
find_package(realsense2 REQUIRED)

add_subdirectory(01_RealsenseBasic)
