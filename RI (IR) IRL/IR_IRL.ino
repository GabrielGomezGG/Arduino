#include <IRremote.h>

int SENSOR = 11;

IRrecv ir(SENSOR);
decode_results codigo;

void setup()
{
    Serial.begin(9600);
    ir.enableIRIn();
}

void loop()
{
    if(ir.decode(&codigo)){
        Serial.println(codigo.value);
        Serial.println(codigo.value,HEX);
        ir.resume();
    }
    delay(100);
}

