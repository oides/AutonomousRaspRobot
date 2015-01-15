/*
 Modulo para controle de motores.
 Recebe como entrada sinais vindos do raspberry.
*/
// Entredas digitais...
int inFrentePin = 2;
int inRePin = 4;
int inEsquerdaPin = 7;
int inDireitaPin = 8;

// Saidas PWM...
int outFrente = 3;
int outEsquerda = 5;

// Variaveis locais para leitura dos comandos...
int irFrente;
int irRe;
int irEsquerda;
int irDireita;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(inFrentePin, INPUT);
  pinMode(inRePin, INPUT);
  pinMode(inEsquerdaPin, INPUT);
  pinMode(inDireitaPin, INPUT);
  
  pinMode(outFrente, OUTPUT);
  pinMode(outEsquerda, OUTPUT);
}

void loop()
{
  irFrente = digitalRead(inFrentePin);
  irRe = digitalRead(inRePin);
  irEsquerda = digitalRead(inEsquerdaPin);
  irDireita = digitalRead(inDireitaPin);
  
  Serial.print("Frente: ");
  Serial.print(irFrente);
  Serial.print("\n");
  
  Serial.print("Re: ");
  Serial.print(irRe);
  Serial.print("\n");
  
  Serial.print("Esquerda: ");
  Serial.print(irEsquerda);
  Serial.print("\n");
  
  Serial.print("Direita: ");
  Serial.print(irDireita);
  Serial.print("\n");
  
}
