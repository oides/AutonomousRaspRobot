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
#include <time.h>

using namespace std;
using namespace cv;

class OpenCV
{
private:
     String face_cascade_name;
     String eyes_cascade_name;
     String dirFace;
     CascadeClassifier face_cascade;
     CascadeClassifier eyes_cascade;
     RNG rng;
     void saveImage (Mat &frame, int &num);
     void printBuild();
public:
    void detectFace(bool &canCapture, Mat &frame, int &num);
};

#endif // OPENCV_H
