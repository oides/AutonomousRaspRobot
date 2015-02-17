#include "capture.h"

void Capture::init(bool &canCapture, Mat &frame)
{
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     //tempCanCapture = &canCapture;
     //tempFrame = &frame;
     //printf("canCapture2 = %s\n", &canCapture ? "true":"false");
     //printf("tempCanCapture2 = %s\n", *tempCanCapture ? "true":"false

     
     if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading1\n"); };
     if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading2\n"); };
}

void Capture::capture(Mat &frame)
{
    /* //cv::VideoCapture capture(0);

    //-- 1. Load the cascades


    //-- 2. Read the video stream
    //capture = cvCaptureFromCAM( 0 );
   // cvSetCaptureProperty(capture, CV_CAP_PROP_FPS, 1);
    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);
    //cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 320);
    
    //if( capture.isOpened() )
    //{
 	   // printf("Captura rodando!\n");

	    //if(canCapture){
		//frame = cvQueryFrame( capture );	
                 capture >> frame;	
		// *tempFrame = frame;

	    	//-- 3. Apply the classifier to the frame
		if( !frame.empty() )
		{
		     //printf("Frame\n");
		     // *tempCanCapture = false;
		     //printf("tempCanCapture3 = %s\n", *tempCanCapture ? "true":"false");
		     //break;
		}
		else
		{ 
		     printf(" --(!) No captured frame -- Break!");  
		     //break;
		}
	     //}
	     //else{
		//printf("Sem Frame");
	     //}
    //}
 	
    //printf("Clean Camera\n");
   // cvReleaseCapture(&capture);
   //capture.release();*/
}
