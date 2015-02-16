#include "opencv.h"

void OpenCV::initRecog()
{
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     dirFace = "/home/novais/Dados/Fotos/"; 
     rng = 12345;
     num = 0;  
     canCapture = true;
 }

void OpenCV::capture()
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
	   if(canCapture){
		frame = cvQueryFrame( capture );

	    	//-- 3. Apply the classifier to the frame
		if( !frame.empty() )
		{
		    printf("Frame\n");
		    canCapture = false;
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

void OpenCV::detect()
{
      /*for (int i = 0; i < 10000; i++)
      {
          printf("Detect");
      }*/
      printf("Detect\n");
      while(true){
         if(!canCapture){
 	    canCapture = false;
            printf("Entrou1\n");
	    if (!frame.empty()){	 
               printf("Entrou2\n");
  	       detectAndDisplay( frame ); 
            }
         }
      }
}

void OpenCV::detectAndDisplay( Mat frame )
{
  std::vector<Rect> faces;
  Mat frame_gray;

  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );
    printf("Detectar face\n\n");
  //-- Detect faces
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

  for( size_t i = 0; i < faces.size(); i++ )
  {
    printf("Identificou um formato de face\n");
    //moviment.interromperExecucao();    

    //Mat faceROI = frame_gray( faces[i] );
    //std::vector<Rect> eyes;

    //-- In each face, detect eyes
    //eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    //if(eyes.size() == 2){
	printf("Identificou e tirou uma foto!\n");
    	saveImage(frame);
	printf("Guardou!\n");	
    //}
    
    //moviment.executeFrente();
  }
   canCapture = true;
   printf("canCapture = true\n");
 }

void OpenCV::saveImage (Mat mat) 
{
	string store_path;
	
	std::stringstream sstm;
	sstm << dirFace << "img" << num << ".png";
	store_path = sstm.str();

	num = num + 1;

	bool write_success = imwrite(store_path, mat);
	if (write_success == true ) {
		printf("Sucesso ao armanezar imagem!");
	}
	else{
		printf("Falha ao armazenar imagem!");
	}
}
