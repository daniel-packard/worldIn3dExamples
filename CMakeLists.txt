cmake_minimum_required(VERSION 3.15)

project(worldIn3dExamples VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(realsense2 REQUIRED)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(GLFW glfw ${OPENGL_LIBRARIES})

add_subdirectory(01_HelloRealSense)
add_subdirectory(02_Distance)
add_subdirectory(03_PointCloud)
add_subdirectory(04_RenderPointCloud)
add_subdirectory(05_ICP)