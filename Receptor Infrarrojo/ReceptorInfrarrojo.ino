#include<IRremote.h>

#define B1 0xFD08F7 //Rojo
#define B2 0xFD8877 //Verde
#define B3 0xFD48B7 //Azul
#define B0 0xFD30CF //Blanco
#define BApagado 0xFD00FF //apagar
#define B4 0xFD28D7 //Rosa
#define B5 0xFDA857 //Naranja 
#define B6 0xFDA857 //

int ledR = 3;   //rojo
int ledV = 6;   //Verde
int ledA = 5;   //Azul

int SENSOR = 11;
IRrecv irrecv(SENSOR);
decode_results codigo;

void setup()
{
	Serial.begin(9600);
    irrecv.enableIRIn();

    //leds output
    pinMode(ledR,OUTPUT);
    pinMode(ledV,OUTPUT);
    pinMode(ledA, OUTPUT);
}

void loop()
{
	if(irrecv.decode(&codigo)){
        Serial.println(codigo.value,HEX);

        //leer los botones y darles una accion
        //rojo
        if(codigo.value == B1){
            digitalWrite(ledR, !digitalRead(ledR));
        }

        //verde
        if(codigo.value == B2){
            digitalWrite(ledV, !digitalRead(ledV));
        }

        //azul
        if(codigo.value == B3){
            digitalWrite(ledA, !digitalRead(ledA));
        }

        //blanco
        if(codigo.value == B0){
            digitalWrite(ledR, 0);
            digitalWrite(ledV, 0);
            digitalWrite(ledA, 0);
            digitalWrite(ledR, !digitalRead(ledR));
            digitalWrite(ledV, !digitalRead(ledV));
            digitalWrite(ledA, !digitalRead(ledA));
        }

        //off
        if(codigo.value == BApagado){
            digitalWrite(ledR, 0);
            digitalWrite(ledV, 0);
            digitalWrite(ledA, 0);
        }

        //Rosa
        if(codigo.value == B4){
            analogWrite(ledR, 255);
            analogWrite(ledV, 51);
            analogWrite(ledA, 246);
        }

        irrecv.resume();
    }
    delay(100);
}

