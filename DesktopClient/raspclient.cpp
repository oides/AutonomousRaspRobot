#include "raspclient.h"

RaspClient::RaspClient()
{
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        cout << "Could not create socket" << endl;
    }
    cout << "Socket created" << endl;

    server.sin_addr.s_addr = inet_addr("192.168.1.5");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        cout << "connect failed" << endl;
        cout << strerror(errno) << endl;
    }
    else
    {
        cout << "Connected\n" << endl;
    }
}

RaspClient::~RaspClient()
{
    close(sock);
    cout << "Disconnected\n" << endl;
}

void RaspClient::sendMessage(const char *message)
{
    cout << "Sent Message [" << message << "][" << strlen(message) << "]" << endl;

    //Send some data
    if(send(sock , message, strlen(message) + 1, 0) < 0)
    {
        cout << "Send failed" << endl;
    }
}
