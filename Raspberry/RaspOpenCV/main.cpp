#include <iostream>
#include "opencv.h"
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
    printf("Finalizou Thread de deteccao\n");
}

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

    OpenCV openCV;
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
	   chamaOpenCV(openCV);
        }
        else{
           printf("Aguardando deteccao");
        }
    }

    return 0;
}
