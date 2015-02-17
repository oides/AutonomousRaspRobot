#ifndef CAPTURE_H
#define CAPTURE_H

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

class Capture
{
private:
     String face_cascade_name;
     String eyes_cascade_name;
     CascadeClassifier face_cascade;
     CascadeClassifier eyes_cascade;
     bool *tempCanCapture;
     Mat *tempFrame;

public:
    void init(bool &canCapture, Mat &frame);	
    void capture();
};

#endif // OPENCV_H
