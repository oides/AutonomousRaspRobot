#include <iostream>
#include "messagequeue.h"

using namespace std;

int
main()
{
    MessageQueue messageQueue;

    while(1)
    {
        messageQueue.receiveMessage();
    }

    return 0;
}

