set(main 02_Distance)
add_executable(${main} ${main}.cpp)
target_link_libraries(${main} ${realsense2_LIBRARY})