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

void Server::start()
{
    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    cout << "Waiting for incoming connections..." << endl;
    int c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    while(1)
    {
        int client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
        if (client_sock < 0)
        {
            cout << "accept failed" << endl;
        }
        else
        {
            cout << "Connection accepted [" << client_sock << "]" << endl;
            std::thread t1(&Server::listeningMessages, this, client_sock);
            t1.detach();
            cout << "Thread created" << endl;
        }
    }
}

void Server::listeningMessages(int socket)
{
    //Receive a message from client
    int read_size;
    while( (read_size = recv(socket , client_message , 2000 , 0)) > 0 )
    {
        cout << "[" << client_message << "][" << strlen(client_message) << "]" <<endl;

	if (!strcmp("w", client_message) || !strcmp("W", client_message))
		strncpy(client_message, FRENTE, MQ_MESSAGE_LENGTH);
	else if (!strcmp("a", client_message) || !strcmp("A", client_message))
		strncpy(client_message, ESQUERDA, MQ_MESSAGE_LENGTH);
        else if (!strcmp("s", client_message) || !strcmp("S", client_message))
                strncpy(client_message, RE, MQ_MESSAGE_LENGTH);
        else if (!strcmp("d", client_message) || !strcmp("D", client_message))
                strncpy(client_message, DIREITA, MQ_MESSAGE_LENGTH);

        messageQueue.sendMessage(client_message);
    }

    if(read_size == 0)
    {
        cout << "Client disconnected [" << socket << "]" << endl;
        fflush(stdout);
    }
    else if(read_size == -1)
    {
        cout << "recv failed" << endl;
    }
}
