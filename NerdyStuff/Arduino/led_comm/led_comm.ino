const int LED1 = 4;
const int LED2 = 7;
unsigned long prev_millis;
unsigned long const Timeout = 1000;
int counter = 0;
void setup()
{
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	Serial.begin(9600);
	prev_millis = millis();
}

void loop()
{
	if (Serial.available() > 0)
	{
		char c = Serial.read();
		if (c == '1')
			digitalWrite(LED1,HIGH);
		else if (c == '2')
			digitalWrite(LED2,HIGH);
		else if (c == '0')
		{
			digitalWrite(LED1,LOW);
			digitalWrite(LED2,LOW);
		}
	}

	if (millis() - prev_millis > Timeout)
	{
		char c = (counter++)%10 + '0';
		Serial.write((char*)&c,1);
		prev_millis = millis();
	}

	delay(10);
}