int pin = 13;
void setup()
{
	pinMode(pin,OUTPUT);
}

void loop()
{
	parpadeo(true,100);
    parpadeo(false, 100);
}

void parpadeo(bool estado, int seg){
    digitalWrite(pin, estado);
    delay(seg);
}