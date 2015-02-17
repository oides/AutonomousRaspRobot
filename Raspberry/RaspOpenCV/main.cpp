#include <iostream>
#include "opencv.h"
#include "capture.h"
#include <pthread.h>

using namespace std;

void *processing_image(void* param)
{
    OpenCV *openCV = (OpenCV*)param;
    openCV->detect();
}

void chamaOpenCV(OpenCV openCV){
    printf("Vai chamar Thread de deteccao\n");
    pthread_t processingImg;
    pthread_create(&processingImg, NULL, &processing_image, &openCV);
    pthread_join(processingImg,NULL);    
    printf("Chamou Thread de deteccao\n");
}

void *init_capture(void* param)
{
    Capture *cap = (Capture*)param;
    cap->capture();
}

void chamaCaptura(Capture cap){
    printf("Vai chamar Captura\n");
    pthread_t initCapture;
    pthread_create(&initCapture, NULL, &init_capture, &cap);
    pthread_join(initCapture,NULL);    
    printf("Chamou Thread de captura\n");
}

int main()
{
    bool canCapture = true;

    Capture cap;
    cap.init(canCapture);

    OpenCV openCV;
    openCV.init(canCapture);
    printf("Iniciou Aplicacao\n");

    chamaCaptura(cap);

    chamaOpenCV(openCV);

    return 0;
}
