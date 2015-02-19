#include "moviment.h"

void Moviment::startMoviment(bool &walk)
{
    walk = true;
    while(1)
    {
        if(walk) executeFrente(walk);
	sleep(SLEEP_MOVIMENT);
    }
}

void Moviment::executeFrente(bool &walk)
{
    printf("executeFrente\n");
    walk = true;
    strncpy(client_message, FRENTE, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
    sleep(2);
}

void Moviment::executeDireita(bool &walk)
{
    printf("executeDireita\n");
    walk = true;
    strncpy(client_message, DIREITA, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}

void Moviment::interromperExecucao(bool &walk)
{
    printf("interromperExecucao\n");
    walk = false;
}

void Moviment::executeRe(bool &walk)
{
    printf("executeRe\n");
    walk = false;
    strncpy(client_message, RE, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}

void Moviment::executeEsquerda(bool &walk)
{
    printf("executeEsquerda\n");
    walk = true;
    strncpy(client_message, ESQUERDA, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}
