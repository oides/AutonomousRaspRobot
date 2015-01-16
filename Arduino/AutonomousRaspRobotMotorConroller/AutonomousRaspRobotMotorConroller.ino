/*
 Modulo para controle de motores.
 Recebe como entrada sinais vindos do raspberry.
*/
// Entradas digitais...
int inFrentePin = 2;
int inRePin = 4;
int inEsquerdaPin = 7;
int inDireitaPin = 8;

// Saidas PWM...
int outMotorAceleracao = 3;
int outFrente = 5;
int outRe = 6;

int outMotorCurva = 11;
int outEsquerda = 10;
int outDireita = 9;

// Variaveis locais para leitura dos comandos...
int irFrente;
int irRe;
int irEsquerda;
int irDireita;
int existeMovimento;

void setup()
{
  Serial.begin(9600); 
  
  pinMode(inFrentePin, INPUT);
  pinMode(inRePin, INPUT);
  pinMode(inEsquerdaPin, INPUT);
  pinMode(inDireitaPin, INPUT);
  
  pinMode(outMotorAceleracao, OUTPUT);
  pinMode(outFrente, OUTPUT);
  pinMode(outRe, OUTPUT);
  
  pinMode(outMotorCurva, OUTPUT);
  pinMode(outEsquerda, OUTPUT);
  pinMode(outDireita, OUTPUT);
}

void loop()
{
  irFrente = digitalRead(inFrentePin);
  irRe = digitalRead(inRePin);
  irEsquerda = digitalRead(inEsquerdaPin);
  irDireita = digitalRead(inDireitaPin);

  existeMovimento = irFrente + irRe + irEsquerda + irDireita;
  if (existeMovimento != 0 && existeMovimento != 4)
  {
    if (irFrente != 0)
    {
      Serial.print("[FRENTE]\n");
      digitalWrite(outMotorAceleracao, HIGH);
      digitalWrite(outFrente, HIGH);
      digitalWrite(outRe, LOW);
    }
    if (irRe != 0)
    {
      Serial.print("[RE]\n");
      digitalWrite(outMotorAceleracao, HIGH);
      digitalWrite(outFrente, LOW);
      digitalWrite(outRe, HIGH);
    }
    if (irEsquerda != 0)
    {
      Serial.print("[RE]\n");
      digitalWrite(outMotorCurva, HIGH);
      digitalWrite(outEsquerda, HIGH);
      digitalWrite(outDireita, LOW);
    }
    if (irDireita != 0)
    {
      Serial.print("[RE]\n");
      digitalWrite(outMotorCurva, HIGH);
      digitalWrite(outEsquerda, LOW);
      digitalWrite(outDireita, HIGH);
    }
  }
  delay(50);

  analogWrite(outMotorAceleracao, LOW);
  analogWrite(outFrente, LOW);
  analogWrite(outRe, LOW);
  
  analogWrite(outMotorCurva, LOW);
  analogWrite(outEsquerda, LOW);
  analogWrite(outDireita, LOW);
  
/*  Serial.print("Frente: ");
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
  Serial.print("\n\n");*/
  
  
}
