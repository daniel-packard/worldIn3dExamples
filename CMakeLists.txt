cmake_minimum_required(VERSION 3.10)

project(worldIn3dExamples VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(realsense2 REQUIRED)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(GLFW glfw ${OPENGL_LIBRARIES})

# Adding PCL library
# set(PCL_DIR "/home/sai/workspace/pcl-pcl-1.7.2/build/")
find_package(PCL REQUIRED)

include_directories(${PCL_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_subdirectory(01_HelloRealSense)
add_subdirectory(02_Distance)
add_subdirectory(03_PointCloud)
add_subdirectory(04_RenderPointCloud)
add_subdirectory(05_ICP)
add_subdirectory(06_Viewer)