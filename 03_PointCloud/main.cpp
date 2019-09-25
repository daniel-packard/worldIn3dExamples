#include <iostream>
#include <iomanip>

#include <librealsense2/rs.hpp>

using namespace rs2;
using namespace std;

int main()
{
    pipeline pipe;
    auto profile = pipe.start ( );

    pointcloud pc;

    while ( true )
    {
      frameset frameset = pipe.wait_for_frames ();
      auto depth_frame = frameset.get_depth_frame ();

      auto points = pc.calculate ( depth_frame );

      auto w = depth_frame.get_width ();
      auto h = depth_frame.get_height ();
      auto center = w * h / 2 + w / 2;
      auto pt = points.get_vertices ()[center];

      cout << "number of points: " << points.size () << "\n"
        << "center point: ("
        << pt.x << ", "
        << pt.y << ", "
        << pt.z << ")\n\n";

    }

    return 0;
}


