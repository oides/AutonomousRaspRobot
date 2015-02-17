#ifndef MOVIMENT_H
#define MOVIMENT_H

#include <stdio.h>
#include "messagequeue.h"
#include <unistd.h>
#include <string.h>

using namespace std;

#define SLEEP_MOVIMENT 1

class Moviment
{
private:
    MessageQueue messageQueue;
    char* client_message;
public:
    void startMoviment(bool &walk);
    void executeFrente(bool &walk);
    void executeRe(bool &walk);
    void executeDireita(bool &walk);
    void executeEsquerda(bool &walk);
    void interromperExecucao(bool &walk);
};

#endif // MOVIMENT_H
