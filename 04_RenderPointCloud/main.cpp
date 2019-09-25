#include <iostream>
#include <iomanip>

#include <librealsense2/rs.hpp>

#include "helpers.hpp"

using namespace rs2;
using namespace std;

void register_glfw_callbacks ( window &app, glfw_state &app_state );

int main()
{
  window app ( 1280, 720, "RealSense Pointcloud Example" );
  glfw_state app_state;
  register_glfw_callbacks ( app, app_state );

  rs2::pointcloud pc;
  rs2::points points;
  rs2::pipeline pipe;
  pipe.start ();

  while ( app ) // Application still alive?
  {
    // Wait for the next set of frames from the camera
    auto frames = pipe.wait_for_frames ();
    auto color = frames.get_color_frame ();

    if ( !color )
      color = frames.get_infrared_frame ();

    pc.map_to ( color );
    auto depth = frames.get_depth_frame ();
    points = pc.calculate ( depth );
    app_state.tex.upload ( color );
    draw_pointcloud ( app.width (), app.height (), app_state, points );
  }

  return 0;
}


