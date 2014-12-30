#ifndef RASPCLIENT_H
#define RASPCLIENT_H

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>

using namespace std;

class RaspClient
{
private:
    int sock;
    struct sockaddr_in server;
    char message[1000] , server_reply[2000];

public:
    RaspClient();
    ~RaspClient();

    void sendMessage(const char *message);
};

#endif // RASPCLIENT_H
