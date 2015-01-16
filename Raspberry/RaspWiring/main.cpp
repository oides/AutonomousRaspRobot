#include <iostream>
#include "messagequeue.h"
#include <string.h>
#include <wiringPi.h>

#define PIN_FRENTE_11 0
#define PIN_RE_13 2
#define PIN_ESQUERDA_15 3
#define PIN_DIREITA_16 4

using namespace std;

void turnOn(int);
void init();

int
main()
{
    MessageQueue messageQueue;

    wiringPiSetup();
    pinMode (PIN_FRENTE_11, OUTPUT);
    pinMode (PIN_RE_13, OUTPUT);
    pinMode (PIN_ESQUERDA_15, OUTPUT);
    pinMode (PIN_DIREITA_16, OUTPUT);

    init();

    while(1)
    {
      	char* msg_buff = messageQueue.receiveMessage();

        if (!strcmp(FRENTE, msg_buff))
	{
                cout << "Wiring Message Reicived: FRENTE" << endl;
		turnOn(PIN_FRENTE_11);
	}
        else if (!strcmp(RE, msg_buff))
	{
                cout << "Wiring Message Reicived: RE" << endl;
		turnOn(PIN_RE_13);
	}
        else if (!strcmp(ESQUERDA, msg_buff))
	{
                cout << "Wiring Message Reicived: ESQUERDA" << endl;
		turnOn(PIN_ESQUERDA_15);
	}
        else if (!strcmp(DIREITA, msg_buff))
	{
		cout << "Wiring Message Reicived: DIREITA" << endl;
		turnOn(PIN_DIREITA_16);
	}
	else	cout << "Wiring Message Reicived: " << msg_buff << endl;

    }

    return 0;
}

void
turnOn(int motor)
{
	std::thread t1(turnOnPins, this, motor);
        t1.detach();
}

void
turnOnPins(int motor)
{
        digitalWrite (motor, HIGH);
        delay (330);
        digitalWrite (motor, LOW);
}

void
init()
{
	digitalWrite (PIN_FRENTE_11, LOW);
        digitalWrite (PIN_RE_13, LOW);
        digitalWrite (PIN_ESQUERDA_15, LOW);
        digitalWrite (PIN_DIREITA_16, LOW);
}
