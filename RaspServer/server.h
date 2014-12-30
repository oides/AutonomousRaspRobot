#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class Server
{
private:
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[100];

public:
    Server();
    void listening();
};

#endif // SERVER_H
