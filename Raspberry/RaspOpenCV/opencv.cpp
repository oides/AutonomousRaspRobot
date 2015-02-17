#include "opencv.h"
/*
void OpenCV::init(bool &canCapture, Mat &frame)
{
     
     tempCanCapture = &canCapture;
     tempFrame = &frame;
     //printf("canCapture = %s\n", &canCapture ? "true":"false");
     //printf("tempCanCapture = %s\n", *tempCanCapture ? "true":"false");
 }*/
/*void OpenCV::detect(bool &canCapture, Mat &frame)
{
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     dirFace = "/home/novais/Dados/Fotos/"; 
     rng = 12345;
     num = 0;  


      printf("Detect\n");
      //while(true){

   	 *tempCanCapture = false;

            printf("Entrou detect\n");
        sleep(5);
            printf("Entrou2 detect\n");
   	 //*tempCanCapture = true;

//         printf("tempCanCapture5 = %s\n", *tempCanCapture ? "true":"false");
         //if(!*tempCanCapture){


	    if (!*tempFrame->empty()){	 
               printf("Entrou2\n");
  	       detectFace( *tempFrame ); 
            }
  	       //detectFace( tempFrame ); 
  // 	    *tempCanCapture = true;
         //}
      //}
}*/

void OpenCV::detectFace(bool &canCapture, Mat &frame, int &num)
{
     canCapture = false;
     printBuild();
     printf("canCapture = %s\n", canCapture ? "true":"false");

     dirFace = "/home/novais/Dados/Fotos/"; 
     face_cascade_name = "haarcascade_frontalface_alt.xml";
     eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
     rng = 12345; 

     if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading1\n"); };
     if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading2\n"); };

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
    	  saveImage(frame, num);
	  printf("Guardou!\n");	
      //}
    
      //moviment.executeFrente();
  }
   canCapture = true;
   printf("canCapture = %s\n", canCapture ? "true":"false");
     printBuild();
 }

void OpenCV::printBuild(){
    time_t rawtime;
    struct tm * timeinfo();
    time (&rawtime);
    printf("Tempo: %s", ctime(&rawtime));
}

void OpenCV::saveImage (Mat &frame, int &num) 
{
	string store_path;
	
	std::stringstream sstm;
	sstm << dirFace << "img" << num << ".png";
	store_path = sstm.str();

	num = num + 1;
        
	bool write_success = imwrite(store_path, frame);
	if (write_success == true ) {
		printf("Sucesso ao armanezar imagem!");
	}
	else{
		printf("Falha ao armazenar imagem!");
	}
}
