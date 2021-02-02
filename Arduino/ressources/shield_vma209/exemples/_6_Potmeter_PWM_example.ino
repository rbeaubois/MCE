//*******************************************************************************
//  VMA209 - Pot meter + PWM example
//  The VMA209 contains a blue potmeter (trimmer) which is connected to Analog 0
//  In this example we show You how to measure the voltage between 0 and 5V,how to visualise it by the serial monitor, and how to adjust the intensity of 2 LED's by using PWM
//  Programmed :Arduino IDE
//  Board ：Arduino Leonardo, UNO,  
//*******************************************************************************/

int potpin=A0; //Initialize integer potpin as Analog 0
int ledpin1=11;//Define digital interface 11 (PWM output）
int ledpin2=10;//Define digital interface 10 (PWM output）


int val=0;// initialize val as a integer with value 0
void setup()
{
Serial.begin(9600);//Set the communications baudrate to 9600 Baud

}
void loop()
{
val=analogRead(potpin);// Read the sensor's analog value and assign it to val
Serial.println(val);// Print this value to the serial monitor
analogWrite(ledpin1,val/4);// write this value to the LED and set its brightness by PWM (value between 0 and 255, that's why devide by 4)
analogWrite(ledpin2,val/4);// write this value to the LED and set its brightness by PWM (value between 0 and 255, that's why devide by 4)


delay(100);//wait for 0,1 second for the next measurement
}

