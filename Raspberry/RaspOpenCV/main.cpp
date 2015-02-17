#include <iostream>
#include "opencv.h"
#include "capture.h"
#include <pthread.h>
#include <time.h>

using namespace std;

bool canCapture;
Mat frame;
int num;

void *processing_image(void* param)
{
    OpenCV *openCV = (OpenCV*)param;
    openCV->detectFace(canCapture, frame, num);
}

void chamaOpenCV(OpenCV openCV){
    printf("Vai chamar Thread de deteccao\n");
    pthread_t processingImg;
    pthread_create(&processingImg, NULL, &processing_image, &openCV);
    pthread_join(processingImg,NULL);    
    printf("Chamou Thread de deteccao\n");
}
/*
void *init_capture(void* param)
{
    Capture *cap = (Capture*)param;
    cap->capture(canCapture, frame, capture);
}

void chamaCaptura(Capture cap){
    printf("Vai chamar Captura\n");
    pthread_t initCapture;
    pthread_create(&initCapture, NULL, &init_capture, &cap);
    pthread_join(initCapture,NULL);    
    printf("Chamou Thread de captura\n");
}*/

void printBuild(){
    time_t rawtime;
    struct tm * timeinfo();
    time (&rawtime);
    printf("Tempo: %s", ctime(&rawtime));
}

int main()
{
    canCapture = true;
    num = 0;
    
    //Capture cap;
    //cap.init(canCapture, frame);

    OpenCV openCV;
    //openCV.init(canCapture, frame);
    printf("Iniciou Aplicacao\n"); 

    cv::VideoCapture capture(0);
    if( capture.isOpened() )
    {
 	printf("Captura rodando!\n");
    }

    while(true){	

        if(canCapture){
           printBuild();
           capture >> frame;
           //chamaCaptura(cap); 
	   chamaOpenCV(openCV);
        }
        else{
           printf("Aguardando deteccao");
        }
    }

    return 0;
}
