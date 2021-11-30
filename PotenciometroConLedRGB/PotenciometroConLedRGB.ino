

const int PRojo = A0;   //Potenciometro que controla el color Rojo
const int PVerde = A1;  //Potenciometro que controla el color Verde
const int PAzul = A2;   //Potenciometro que controla el color Azul

int valorPRojo = 0; //Valor actual del potenciometro de color Rojo
int valorPVerde = 0;    //Valor actual del potenciometro de color Verde
int valorPAzul = 0; //Valor actual del potenciometro de color Azul

int ledR = 3;   //led rojo
int ledV = 6;   //led Verde
int ledA = 5;   //led Azul

void setup()
{
    pinMode(ledR, OUTPUT);
    pinMode(ledV, OUTPUT);
    pinMode(ledA, OUTPUT);
}

void loop()
{
    pRojo();
    pVerde();
    pAzul();
    colorActual();
    delay(100);
}

void pRojo(){
    valorPRojo = analogRead(PRojo)/4;
    //analogWrite(PRojo, valorPRojo);
}

void pVerde(){
    valorPVerde = analogRead(PVerde)/4;
    //analogWrite(PVerde, valorPVerde);
}

void pAzul(){
    valorPAzul = analogRead(PAzul)/4;
    //analogWrite(PAzul, valorPAzul);
}

void colorActual(){
    analogWrite(ledR, valorPRojo);
    analogWrite(ledV, valorPVerde);
    analogWrite(ledA, valorPAzul);
}
