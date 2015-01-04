#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "messagequeue.h"


using namespace std;

class Server
{
private:
    int socket_desc;
    struct sockaddr_in server , client;
    char client_message[100];
    void listeningMessages(int socket);
    MessageQueue messageQueue;

public:
    Server();
    void start();
};

#endif // SERVER_H
