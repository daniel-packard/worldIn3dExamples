#include <iostream>
#include <string>

#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/time.h>

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

int main (int argc, char* argv[]) 
{
  PointCloudT::Ptr cloud_in (new PointCloudT);  // Original point cloud

  if (argc < 2)
  {
    printf ("Usage :\n");
    printf ("\t\t%s file.ply\n", argv[0]);
    PCL_ERROR ("Provide one ply file.\n");
    return (-1);
  }

  if (pcl::io::loadPLYFile (argv[1], *cloud_in) < 0)
  {
    PCL_ERROR ("Error loading cloud %s.\n", argv[1]);
    return (-1);
  }

  pcl::visualization::PCLVisualizer viewer ("ICP demo");
  viewer.addPointCloud (cloud_in, "cloud_in_v1");

  while (!viewer.wasStopped ())
  {
    viewer.spinOnce ();
  }
  return (0);
}
