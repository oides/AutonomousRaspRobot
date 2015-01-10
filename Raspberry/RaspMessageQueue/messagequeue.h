#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include<iostream>
#include <mqueue.h>

using namespace std;

#define MQ_NAME "/carcommand_queue"
#define MQ_MAX_NUM_OF_MESSAGES 10
#define MQ_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

// Default send message configuration
#define MQ_MESSAGE_LENGTH 100
#define MQ_MESSAGE_PRIORITY 0

#define FRENTE		"FRENTE"
#define RE		"RE"
#define ESQUERDA	"ESQUERDA"
#define	DIREITA		"DIREITA"

class MessageQueue
{
private:
    int flags = O_RDWR | O_CREAT;
    struct mq_attr attr;
    mqd_t mqd;
    char msg_buff[MQ_MESSAGE_LENGTH];

public:
    void sendMessage(char* message);
    char* receiveMessage();

    MessageQueue();
    ~MessageQueue();
};

#endif // MESSAGEQUEUE_H
