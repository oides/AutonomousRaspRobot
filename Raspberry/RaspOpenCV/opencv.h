#ifndef OPENCV_H
#define OPENCV_H

#include <iostream>
#include <messagequeue.h>

#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;
using namespace cv;

#define SLEEP_CAMERA 200

/** Function Headers */
void detectAndDisplay( Mat frame );
void saveImage (Mat mat);

class OpenCV
{
private:
     String face_cascade_name;
     String eyes_cascade_name;
     String dirFace;
     CascadeClassifier face_cascade;
     CascadeClassifier eyes_cascade;
     RNG rng;
     int num;
     bool canCapture;
     Mat frame;

     void saveImage (Mat mat);
public:
    void initRecog();	
    void capture();
    void detectAndDisplay( Mat frame );
    void detect();
};

#endif // OPENCV_H
