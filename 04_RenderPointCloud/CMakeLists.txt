add_executable(04_RenderPointCloud main.cpp helpers.hpp)
target_link_libraries(04_RenderPointCloud ${realsense2_LIBRARY} ${GLFW})