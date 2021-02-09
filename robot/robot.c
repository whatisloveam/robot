// 192.168.31.15:7070
// github.com/whatisloveam/robot

void line() {
	while(true) 
	{
		int u = -0.3 *(analogRead(A0) - analogRead(A1));
		motorB(150 + u);
		motorC(150 - u);
		delay(10);
	}
}

void setup()
{
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	line();
}



void loop()
{	
}