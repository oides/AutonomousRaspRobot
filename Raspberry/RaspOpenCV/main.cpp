#include <iostream>
#include "opencv.h"
#include <pthread.h>

using namespace std;

void *processing_image(void* param)
{
    OpenCV *openCV = (OpenCV*)param;
    openCV->detect();
}

void chamaThread(OpenCV openCV){
    printf("Vai chamar Thread de deteccao\n");
    pthread_t processingImg;

    pthread_create(&processingImg, NULL, &processing_image, &openCV);

    void* result;
    pthread_join(processingImg,NULL);    
    printf("Chamou Thread\n");
}

void chamaCaptura(OpenCV openCV){
    printf("Vai chamar Captura\n");
    openCV.capture();
    printf("Chamou Captura\n");
}

int main()
{
    OpenCV openCV;
    openCV.initRecog();
    printf("Iniciou Aplicacao\n");

    chamaCaptura(openCV);

    chamaThread(openCV);
 
    return 0;
}
