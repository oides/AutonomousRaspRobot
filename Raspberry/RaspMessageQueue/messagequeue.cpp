#include "messagequeue.h"

MessageQueue::MessageQueue()
{
    attr.mq_flags = 0;
    attr.mq_maxmsg = MQ_MAX_NUM_OF_MESSAGES;
    attr.mq_msgsize = MQ_MESSAGE_LENGTH;
    attr.mq_curmsgs = 0;

    mqd = mq_open(MQ_NAME, flags, MQ_MODE, &attr);

    if(mqd != (mqd_t)-1)
    {
        cout << "Message Queue Opened" << endl;
    }
    else
    {
        cout << "Message queue open failed" << endl;
    }
}

MessageQueue::~MessageQueue()
{
    mq_close(mqd);
    mq_unlink(MQ_NAME);
    cout << "Message Queue Closed" << endl;
}

void MessageQueue::sendMessage(char* message)
{
    cout << "Sending message..." << endl;

    int ret = mq_send(mqd, message, MQ_MESSAGE_LENGTH, MQ_MESSAGE_PRIORITY);

    if(ret)
    {
        cout << "Failed" << endl;
    }
    else
    {
        cout << "Message: " << message << endl;
        cout << "Done\n" << endl;
    }
}

char* MessageQueue::receiveMessage()
{
    cout << "Receiving message..." << endl;

    int msg_len = mq_receive(mqd, msg_buff, MQ_MESSAGE_LENGTH, NULL);

    if(msg_len < 0)
    {
        cout << "Failed" << endl;
    }
    else
    {
        msg_buff[MQ_MESSAGE_LENGTH-1] = '\0';
        cout << "Successfully received " << msg_len << " bytes" << endl;
        cout << "Message: " << msg_buff << endl;
    }

    return msg_buff;
}
