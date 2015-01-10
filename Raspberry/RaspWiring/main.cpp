#include <iostream>
#include "messagequeue.h"
#include <string.h>
#include <wiringPi.h>

#define PIN_11 0

using namespace std;

int
main()
{
    MessageQueue messageQueue;

    wiringPiSetup();
    pinMode (PIN_11, OUTPUT) ;

    while(1)
    {
      	char* msg_buff = messageQueue.receiveMessage();

        if (!strcmp(FRENTE, msg_buff))
	{
                cout << "Wiring Message Reicived: FRENTE" << endl;
		digitalWrite (PIN_11, HIGH);
		delay (3000);
		digitalWrite (0, LOW);
	}
        else if (!strcmp(RE, msg_buff))
                cout << "Wiring Message Reicived: RE" << endl;
        else if (!strcmp(ESQUERDA, msg_buff))
                cout << "Wiring Message Reicived: ESQUERDA" << endl;
        else if (!strcmp(DIREITA, msg_buff))
		cout << "Wiring Message Reicived: DIREITA" << endl;
	else	cout << "Wiring Message Reicived: " << msg_buff << endl;

    }

    return 0;
}

