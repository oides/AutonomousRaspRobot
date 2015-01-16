#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include "messagequeue.h"
#include <string.h>
#include <wiringPi.h>
#include <thread>
#include <mutex>

#define PIN_FRENTE_11 0
#define PIN_RE_13 2
#define PIN_ESQUERDA_15 3
#define PIN_DIREITA_16 4

using namespace std;

class Server
{
private:
    MessageQueue messageQueue;
    void init();
    void turnOn(int, int*);
    void turnOnPins(int, int*);
    int pinCount11, pinCount13, pinCount15, pinCount16;
    std::mutex lockMotor;

public:
    void start();
    Server();
};

#endif // SERVER_H
