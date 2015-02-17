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
     int num;
     void saveImage (Mat &frame);
     void printBuild();
public:
    //void init(bool &canCapture, Mat &frame);
    void detectFace(bool &canCapture, Mat &frame);
    void startNum();
    //void detect(Mat &frame);
};

#endif // OPENCV_H
