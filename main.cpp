#include <iostream>
#include <opencv2/opencv.hpp>
#include "xiApiPlusOcv.hpp" 

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
    try
 {
   xiAPIplusCameraOcv cam;
   cam.OpenFirst();
   cam.SetExposureTime(10000); //10000 us = 10 ms
   float FR = 10.0;
   cam.SetAcquisitionTimingMode(XI_ACQ_TIMING_MODE_FRAME_RATE);
   cam.SetFrameRate(FR);
   cam.StartAcquisition();

   // Read and convert a frame from the camera
   Mat cv_mat_image = cam.GetNextImageOcvMat();
   // Show image on display
   cv::imshow("Image from camera",cv_mat_image);
   cv::waitKey(0);

   cam.StopAcquisition();
   cam.Close();
 }
 catch(xiAPIplus_Exception& exp)
 {
   exp.PrintError(); // report error if some call fails
 }
}