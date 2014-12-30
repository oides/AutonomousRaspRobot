#include "server.h"

Server::Server()
{
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        cout << "Could not create socket" << endl;
    }
    cout << "Socket created" << endl;

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        cout << "bind failed" << endl;
    }
    else
    {
        cout << "bind done" << endl;
    }
}

void Server::listening()
{
    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    cout << "Waiting for incoming connections..." << endl;
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        cout << "accept failed" << endl;
        return;
    }
    else
    {
        cout << "Connection accepted" << endl;
    }

    //Receive a message from client
    while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
    {
        cout << "[" << client_message << "][" << read_size << "]" <<endl;
    }

    if(read_size == 0)
    {
        cout << "Client disconnected" << endl;
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        cout << "recv failed" << endl;
    }
}
