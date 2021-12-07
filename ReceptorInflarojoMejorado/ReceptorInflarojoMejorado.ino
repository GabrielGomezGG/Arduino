#include <IRremote.h>
#include "Led.h"

// #define B0 0xFD30CF //Boton 0 
// #define B1 0xFD08F7 //Boton 1 
// #define B2 0xFD8877 //Boton 2
// #define B3 0xFD48B7 //Boton 3
// #define B4 0xFD28D7 //Boton 4
// #define B5 0xFDA857 //Boton 5
// #define B6 0xFDA857 //Boton 6
// #define B7 0xFD08F7 //Boton 7
// #define B8 0xFD8877 //Boton 8
// #define B9 0xFD48B7 //Boton 9
// #define B0 0xFD30CF //Boton 0
// #define B100 0xFDB04F //Boton 100
// #define B200 0xFD708F //Boton 200
// #define BCHu 0xFD00FF //Boton off
// #define BCH 0xFD807F  //Boton guardar
// #define BCHd 0xFD40BF //Boton borrar
const float b1 = 16582903;
const float b2 = 16615543;
const float b3 = 16599223;
const float b4 = 16591063;
const float b5 = 16623703;
const float b6 = 16607383; 
const float b7 = 16586983; 
const float b8 = 16619623;
const float b9 = 16603303;

Led ledR = Led(3,b1,b2,b3,"Rojo");
Led ledV = Led(6,b4,b5,b6,"Verde");
Led ledA = Led(5,b7,b8,b9,"Azul");

int SENSOR = 11;    //sensor inflarojo en el pin11
IRrecv irrecv(SENSOR);  //objeto de la clase IRrecv (resive las señales del sensor)
decode_results codigo;

void setup()    
{    
	Serial.begin(9600);
    irrecv.enableIRIn();

    //leds output
    pinMode(ledR.getNumeroDePin(),OUTPUT);
    pinMode(ledV.getNumeroDePin(),OUTPUT);
    pinMode(ledA.getNumeroDePin(), OUTPUT);

}

void loop()
{
	if(irrecv.decode(&codigo)){
        Serial.println(codigo.value,HEX);

        accionLed(ledR);
        accionLed(ledV);
        accionLed(ledA);

        irrecv.resume();
    }
    delay(100);
}

//dependiendo el boton que toques en el control, se hara la siguiente opcion:
//-bajar el brillo del led
//-apaga o enciden el led 
//-sube el brillo del led 
void accionLed(Led led){

    if(codigo.value == led.getBajar()){
        led.bajarBrillo();
    }

    if(codigo.value == led.getEncenderApagar()){
        led.offOn();
    }

    if(codigo.value == led.getEncenderApagar()){
        led.subirBrillo();
    }
}