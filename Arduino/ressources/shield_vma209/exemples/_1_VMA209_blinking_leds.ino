//*******************************************************************************
//Flashing LEDS on the Velleman VMA209
//Programmed by : Arduino IDE
//Compatible with ：Arduino Leonardo, Arduino UNO, MEGA
//*******************************************************************************

char ledPin =  10; //digital pin 10 -> LED1 (D4)
char ledPin1 = 11; //digital pin 11 -> LED2 (D3)
char ledPin2 = 12; //digital pin 12 -> LED2 (D2)
char ledPin3 = 13; //digital pin 13 -> LED2 (D1)
void setup()
{
pinMode(ledPin, OUTPUT);//declare LedPin as output
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
}
void loop()
{
digitalWrite(ledPin, HIGH); //Switch ON this LED
digitalWrite(ledPin1, HIGH);
digitalWrite(ledPin2, HIGH);
digitalWrite(ledPin3, HIGH);
delay(1000); //Wait for 1 second
digitalWrite(ledPin, LOW); //Switch OFF this LED
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);
delay(1000); // Wait for 1 second
}

