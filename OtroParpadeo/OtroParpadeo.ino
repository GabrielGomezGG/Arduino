int pin = 13;
void setup()
{
	pinMode(pin,OUTPUT);
}

void loop()
{
	parpadeo(true,10000);
    parpadeo(false, 10000);
}

void parpadeo(bool estado, int seg){
    digitalWrite(pin, estado);
    delay(seg);
}