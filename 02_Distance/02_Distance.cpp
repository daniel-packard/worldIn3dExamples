#include <iostream>
#include <iomanip>

#include <librealsense2/rs.hpp>

using namespace rs2;
using namespace std;

int main()
{
    pipeline pipe;
    auto profile = pipe.start ( );

    while ( true )
    {
      frameset frameset = pipe.wait_for_frames ();
      auto depth_frame = frameset.get_depth_frame ();

      auto midX = depth_frame.get_width () / 2;
      auto midY = depth_frame.get_height () / 2;

      std::cout << "Depth is " 
        << setprecision(2) << setw(3)
        << (int) (100.0f*depth_frame.get_distance (midX, midY))
        << "cm at pixel (" << midX << ", " << midY << ")\r"; 
    }

    return 0;
}


