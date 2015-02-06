#ifndef MOVIMENT_H
#define MOVIMENT_H

#include <stdio.h>
#include "messagequeue.h"
#include <unistd.h>
#include <string.h>

using namespace std;

#define SLEEP_MOVIMENT 300

class Moviment
{
private:
    MessageQueue messageQueue;
    char* client_message;
    pthread_t thread;
    int thread_arg;
    bool walk;
public:
    Moviment();
    ~Moviment();

    void executeFrente();
    void executeRe();
    void executeDireita();
    void executeEsquerda();
    void interromperExecucao();
};

#endif // MOVIMENT_H
