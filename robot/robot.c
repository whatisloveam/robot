// 192.168.31.15:7070

void setup()
{
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	
	moveForTime(150, 2000);
	motorBForTime(150, 1000);
	moveForTime(150, 2000);
	motorBForTime(150, 1000);
	moveForTime(150, 2000);
	motorBForTime(150, 1000);
	moveForTime(150, 2000);
	motorBForTime(150, 1000);
}

void loop()
{	
}