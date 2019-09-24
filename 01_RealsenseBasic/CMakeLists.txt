add_executable(01_RealsenseBasic main.cpp)

# Link librealsense2 to the target
target_link_libraries(01_RealsenseBasic ${realsense2_LIBRARY})
