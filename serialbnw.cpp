#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "time.h"
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    //CommandLineParser parser( argc, argv, "{@input | lena.jpg | input image}" );
     clock_t starttime = clock();
   
    
    Mat src = imread(argv[1], IMREAD_COLOR );
    if( src.empty() )
    {
        cout << "Could not open or find the image!\n" << endl;
        cout << "Usage: " << argv[0] << " <Input image>" << endl;
        return -1;
    }
    cvtColor( src, src, COLOR_BGR2GRAY );
    Mat dst;
    equalizeHist( src, dst );
    imwrite( "/content/output.PNG", dst );
    //imshow( "Source image", src );
    //imshow( "Equalized Image", dst );
    //waitKey();
    clock_t stoptime = clock();
    float total_time = ((float)(stoptime - starttime))/(CLOCKS_PER_SEC/1000);
    
    printf("Black and white serial processing time: %f (ms)\n", total_time);
    return 0;
}
