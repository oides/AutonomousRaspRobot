#include "opencv.h"

void OpenCV::initRecog()
{
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     dirFace = "/home/pi/Dados/Fotos/";
     rng = 12345;
     num = 0;
 	
     recognition();
 }

void OpenCV::recognition()
{
    printf("Iniciou Aplicacao\n");
    CvCapture* capture;
    Mat frame;

    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading1\n"); };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading2\n"); };

    //-- 2. Read the video stream
    capture = cvCaptureFromCAM( -1 );
    cvSetCaptureProperty(capture, CV_CAP_PROP_FPS, 10);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);

    if( capture )
    {
      //thread.Start();
      printf("Iniciada Captura\n");

      while( true )
      {	
        frame = cvQueryFrame( capture );
        printf("Executar deteccao do Frame\n");

    	//-- 3. Apply the classifier to the frame
        if( !frame.empty() )
        {
            detectAndDisplay( frame ); 
	}
        else
        { 
	    printf(" --(!) No captured frame -- Break!");  
	    break;
	}

        int c = waitKey(10);
        if( (char)c == 'c' ) 
	{
	    break;
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
    printf("Detectar face\n");
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
