cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

add_executable (06_Viewer main.cpp)
target_link_libraries (06_Viewer ${PCL_LIBRARIES})
set_target_properties(06_Viewer PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "${PROJECT_SOURCE_DIR}/test_data/monkey.ply")
