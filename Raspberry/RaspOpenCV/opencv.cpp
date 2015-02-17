#include "opencv.h"

//const string dirFace = "/home/novais/Dados/Fotos/";

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
    printf("Detectar face\n");
    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

    for( size_t i = 0; i < faces.size(); i++ )
    {
        printf("Identificou um formato de face\n");
     
        //Mat faceROI = frame_gray( faces[i] );
        //std::vector<Rect> eyes;

        //-- In each face, detect eyes
        //eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
        //if(eyes.size() == 2){
	printf("Identificou e tirou uma foto!\n");
    	saveImage(frame, "face", num);
	printf("Guardou!\n");	
        //}
    }
     
    canCapture = true;
    printf("canCapture = %s\n", canCapture ? "true":"false");
     
    printBuild();
}

void OpenCV::detectColor(bool &canCapture, Mat &frame, int &num)
{
    canCapture = false;
    printf("canCapture = %s\n", canCapture ? "true":"false");
    dirFace = "/home/novais/Dados/Fotos/";

    int iLowH = 170;
    int iHighH = 179;

    int iLowS = 150; 
    int iHighS = 255;

    int iLowV = 60;
    int iHighV = 255;

    int iLastX = -1; 
    int iLastY = -1;

    Mat imgTmp;

    //Create a black image with the size as the camera output
    Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );

    Mat frame_HSV;
    cvtColor(frame, frame_HSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
    Mat imgThresholded;
    inRange(frame_HSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
 
    Moments oMoments = moments(imgThresholded);

    double dM01 = oMoments.m01;
    double dM10 = oMoments.m10;
    double dArea = oMoments.m00;

    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 

    //morphological closing (fill small holes in the foreground)
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) ); 
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

    // if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
    if (dArea > 10000)
    {
        //calculate the position of the ball
        int posX = dM10 / dArea;
        int posY = dM01 / dArea;        
        
        printf("Area\n");        
        //saveImage(frame, "color", num);
        saveImage(imgThresholded, "color", num);

        iLastX = posX;
        iLastY = posY;
    }

    //sleep(3);

    canCapture = true;
    printf("canCapture = %s\n", canCapture ? "true":"false");
}

void OpenCV::printBuild(){
    time_t rawtime;
    struct tm * timeinfo();
    time (&rawtime);
    printf("Tempo: %s", ctime(&rawtime));
}

void OpenCV::saveImage (Mat &frame, string prefixo, int &num) 
{
    string store_path;
	
    std::stringstream sstm;
    sstm << dirFace << prefixo << num << ".png";
    store_path = sstm.str();
    num = num + 1;
        
    bool write_success = imwrite(store_path, frame);
    if (write_success == true ) {
        printf("Sucesso ao armanezar imagem!\n");
    }
    else{
        printf("Falha ao armazenar imagem!\n");
    }
}
