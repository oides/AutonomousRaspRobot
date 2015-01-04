#include <iostream>
#include "messagequeue.h"

using namespace std;

int
main()
{
    MessageQueue messageQueue;
    messageQueue.sendMessage("B");
    messageQueue.receiveMessage();

    return 0;
}

