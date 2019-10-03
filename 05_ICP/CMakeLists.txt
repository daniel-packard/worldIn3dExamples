cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

add_executable (05_ICP main.cpp)
target_link_libraries (05_ICP ${PCL_LIBRARIES})
set_target_properties(05_ICP PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "${PROJECT_SOURCE_DIR}/test_data/monkey.ply")