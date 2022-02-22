// 192.168.31.15:7070
// github.com/whatisloveam/robot

#include <SPI.h>
#include <Wire.h>
int s1, s2;

void PAction() {
	upd();
	log();
	int u = -0.3 *(analogRead(A0) - analogRead(A1));
	motorB(150 + u);
	motorC(150 - u);
	delay(10);
}
void line() {
	while(true) PAction();
}
void lineForCross() {
	upd();
	while(!(s1 < 30 && s2 < 30)) PAction();
}
void upd() {
	s1 = map(analogRead(A0), 1000, 30, 0, 100);
	s2 = map(analogRead(A1), 1000, 30, 0, 100);
}
void setup()
{
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	//line();
}



void loop()
{	
}
