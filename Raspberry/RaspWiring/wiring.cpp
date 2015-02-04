#include "wiring.h"

Server::Server()
{
    wiringPiSetup();
    pinMode (PIN_FRENTE_11, OUTPUT);
    pinMode (PIN_RE_13, OUTPUT);
    pinMode (PIN_ESQUERDA_15, OUTPUT);
    pinMode (PIN_DIREITA_16, OUTPUT);
    pinMode (PIN_TRACAO_7, OUTPUT);
    pinMode (PIN_CURVA_12, OUTPUT);

    init();

    pinCount11 = 0;
    pinCount13 = 0;
    pinCount15 = 0;
    pinCount16 = 0;
}

void
Server::start()
{
    while(1)
    {
        char* msg_buff = messageQueue.receiveMessage();

        if (!strcmp(FRENTE, msg_buff))
        {
                cout << "Wiring Message Reicived: FRENTE" << endl;
                turnOn(PIN_TRACAO_7, PIN_FRENTE_11, &pinCount11);
        }
        else if (!strcmp(RE, msg_buff))
        {
                cout << "Wiring Message Reicived: RE" << endl;
                turnOn(PIN_TRACAO_7, PIN_RE_13, &pinCount13);
        }
        else if (!strcmp(ESQUERDA, msg_buff))
        {
                cout << "Wiring Message Reicived: ESQUERDA" << endl;
                turnOn(PIN_CURVA_12, PIN_ESQUERDA_15, &pinCount15);
        }
        else if (!strcmp(DIREITA, msg_buff))
        {
                cout << "Wiring Message Reicived: DIREITA" << endl;
                turnOn(PIN_CURVA_12, PIN_DIREITA_16, &pinCount16);
        }
        else    cout << "Wiring Message Reicived: " << msg_buff << endl;

    }
}

void
Server::init()
{
        digitalWrite (PIN_FRENTE_11, LOW);
        digitalWrite (PIN_RE_13, LOW);
        digitalWrite (PIN_ESQUERDA_15, LOW);
        digitalWrite (PIN_DIREITA_16, LOW);
	digitalWrite (PIN_TRACAO_7, LOW);
	digitalWrite (PIN_CURVA_12, LOW);
}

void
Server::turnOn(int motor, int sentido, int* pinCount)
{
        std::thread t1(&Server::turnOnPins, this, motor, sentido, pinCount);
        t1.detach();
}

void
Server::turnOnPins(int motor, int sentido, int* pinCount)
{
	lockMotor.lock();
	if(*pinCount == 0)
	{
		cout << "Ligando Motor [" << motor << "][" << *pinCount << "]" << endl;
	        digitalWrite (motor, HIGH);
		digitalWrite (sentido, HIGH);
	}
	else
	{
		cout << "Tentando Ligar Motor[" << motor << "][" << *pinCount << "]" << endl;
	}
	(*pinCount)++;
	lockMotor.unlock();

        delay (315);	

	lockMotor.lock();
	(*pinCount)--;
	if(*pinCount == 0)
	{
	        digitalWrite (motor, LOW);
		digitalWrite (sentido, LOW);
		cout << "Desligando Motor [" << motor << "][" << *pinCount << "]" << endl;
	}
	else
	{
		cout << "Tentando desligar Motor[" << motor << "][" << *pinCount << "]" << endl;
	}
	lockMotor.unlock();
}

