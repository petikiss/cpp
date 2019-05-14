#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

int main(int argc, char* argv[])
{

   cv::Mat image = cv::imread("../hun.jpg", cv::IMREAD_GRAYSCALE);

   if (image.data == NULL)
   {
      std::cout << "Image reading error!";
   }




   cv::imshow("Marci", image);

   cv::waitKey(0);
   return 0;
}
