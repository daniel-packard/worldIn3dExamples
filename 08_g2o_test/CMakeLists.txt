#cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

set(main 08_g2o_test)
add_executable(${main} ${main}.cpp)
target_link_libraries(${main} ${G2O_LIBRARIES})
set_target_properties(${main} PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "${PROJECT_SOURCE_DIR}/test_data/monkey.ply")
