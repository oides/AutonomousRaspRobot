#include "capture.h"

void Capture::init(bool &canCapture)
{
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     tempCanCapture = canCapture;
 }

void Capture::capture()
{
    CvCapture* capture;

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading1\n"); };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading2\n"); };

    //-- 2. Read the video stream
    capture = cvCaptureFromCAM( -1 );
//    cvSetCaptureProperty(capture, CV_CAP_PROP_FPS, 1);
//    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 800);
//    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 600);

    if( capture )
    {
 	printf("Iniciada Captura\n");
	while( true )
        {	
	   if(tempCanCapture){
		frame = cvQueryFrame( capture );

	    	//-- 3. Apply the classifier to the frame
		if( !frame.empty() )
		{
		    printf("Frame\n");
		    tempCanCapture = false;
		    //detectAndDisplay( frame ); 
		}
		else
		{ 
		    printf(" --(!) No captured frame -- Break!");  
		    break;
		}
	    }
	 }
    }
}