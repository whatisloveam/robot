// 192.168.31.15:7070
// github.com/whatisloveam/robot

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
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
void log() {
	display.clearDisplay();
	display.setCursor(10, 10);
	display.print(analogRead(A0));
	display.setCursor(50, 10);
	display.print(analogRead(A1));
	display.fillRect(10, 25, 20, 30, SSD1306_WHITE);
	display.fillRect(60, 25, 20, 30, SSD1306_WHITE);
	int fill1 = map(analogRead(A0), 31, 1000, 0, 30);
	int fill2 = map(analogRead(A1), 31, 1000, 0, 30);
	display.fillRect(10, 25, 20, fill1, SSD1306_BLACK);	
	display.fillRect(60, 25, 20, fill2, SSD1306_BLACK);
	display.display();
}
void setup()
{
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    	Serial.println(F("SSD1306 allocation failed"));
    	for(;;); // Don't proceed, loop forever
  	}
  	display.display();
	display.setTextColor(SSD1306_WHITE);
	display.setTextSize(1);
	
	//line();
}



void loop()
{	
	display.clearDisplay();
	log();
	display.display();
	delay(10);
}