cmake_minimum_required(VERSION 3.10)

if(POLICY CMP0074)
  # TODO: update *_ROOT variables to be PCL_*_ROOT or equivalent.
  # CMP0074 directly affects how Find* modules work and *_ROOT variables.  Since
  # this is a config file that will be consumed by parent projects with (likely)
  # NEW behavior, we need to push a policy stack.
  cmake_policy(PUSH)
  cmake_policy(SET CMP0074 OLD)
endif()

project(worldIn3dExamples VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(glfw3_DIR $ENV{REALSENSE_ROOT}lib/cmake/glfw3)
set(FLANN_DIR $ENV{PCL_ROOT}share/flann)
set(g2o_DIR $ENV{G2O_ROOT}lib/cmake)
set(lz4_DIR $ENV{PCL_ROOT}share/lz4)
set(PCL_DIR $ENV{PCL_ROOT}share/pcl)
set(realsense2_DIR $ENV{REALSENSE_ROOT}lib/cmake/realsense2)

find_package(realsense2 REQUIRED)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
set(GLFW glfw ${OPENGL_LIBRARIES})

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS} include)
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

FIND_PACKAGE( G2O REQUIRED )
include_directories(${G2O_INCLUDE_DIR})
include_directories($ENV{G2O_ROOT}include/g2o/EXTERNAL/csparse/)
link_directories($ENV{G2O_ROOT}lib)

SET(G2O_LIBRARIES 
  g2o_cli.lib
  g2o_core.lib
  g2o_stuff.lib
  g2o_types_data.lib
  g2o_types_icp.lib
  g2o_types_sba.lib
  g2o_types_sclam2d.lib
  g2o_types_sim3.lib
  g2o_types_slam2d.lib
  g2o_types_slam3d.lib
  g2o_solver_csparse.lib
  g2o_csparse_extension.lib
  g2o_ext_csparse.lib
  g2o_solver_csparse.lib
)
  
add_subdirectory(01_HelloRealSense)
add_subdirectory(02_Distance)
add_subdirectory(03_PointCloud)
add_subdirectory(04_RenderPointCloud)
add_subdirectory(05_ICP)
add_subdirectory(06_PclViewer)
add_subdirectory(07_g2o_circle_fit)
add_subdirectory(08_g2o_test)

if(POLICY CMP0074)
  cmake_policy(POP)
endif()