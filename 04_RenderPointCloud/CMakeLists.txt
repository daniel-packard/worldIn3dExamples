set(main 04_RenderPointCloud)
add_executable(${main} ${main}.cpp)
target_link_libraries(${main} ${realsense2_LIBRARY} ${GLFW})