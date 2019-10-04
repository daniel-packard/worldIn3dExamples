set(main 03_PointCloud)
add_executable(${main} ${main}.cpp)
target_link_libraries(${main} ${realsense2_LIBRARY})