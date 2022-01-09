#include <opencv2/opencv.hpp>
#include <iostream>
#include "time.h"
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Read the image file
    Mat image = imread(argv[1]);
 clock_t starttime = clock();
    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return -1;
    }

    //Convert the image from BGR to YCrCb color space
    Mat hist_equalized_image;
    cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

    //Split the image into 3 channels; Y, Cr and Cb channels respectively and store it in a std::vector
    vector<Mat> vec_channels;
    split(hist_equalized_image, vec_channels); 

    //Equalize the histogram of only the Y channel 
    equalizeHist(vec_channels[0], vec_channels[0]);

    //Merge 3 channels in the vector to form the color image in YCrCB color space.
    merge(vec_channels, hist_equalized_image); 
        
    //Convert the histogram equalized image from YCrCb to BGR color space again
    cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

  
imwrite( "/content/outputcolor.PNG", hist_equalized_image );
   clock_t stoptime = clock();
    float total_time = ((float)(stoptime - starttime))/(CLOCKS_PER_SEC/1000);
    
    printf("Color Image serial processing time: %f (ms)\n", total_time);
  return 0;
}
