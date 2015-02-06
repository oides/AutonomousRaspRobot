#include "moviment.h"

Moviment::Moviment()
{ 
    walk = true;
    while(1)
    {
        if(walk) executeFrente();
	sleep(SLEEP_MOVIMENT);
    }
}

Moviment::~Moviment()
{

}

void Moviment::executeFrente()
{
    printf("executeFrente\n");
    walk = true;
    strncpy(client_message, FRENTE, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}

void Moviment::executeDireita()
{
    printf("executeDireita\n");
    strncpy(client_message, DIREITA, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}

void Moviment::interromperExecucao()
{
    printf("interromperExecucao\n");
    walk = false;
}

/*
void Moviment::executeRe()
{
    printf("executeRe\n");
    strncpy(client_message, RE, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}

void Moviment::executeEsquerda()
{
    printf("executeEsquerda\n");
    strncpy(client_message, ESQUERDA, MQ_MESSAGE_LENGTH);
    messageQueue.sendMessage(client_message);
}*/
