set(main 01_HelloRealSense)
add_executable(${main} ${main}.cpp)
target_link_libraries(${main} ${realsense2_LIBRARY})