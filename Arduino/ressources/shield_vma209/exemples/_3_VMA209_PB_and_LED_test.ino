//*****************************************************
//  VMA209 Push button and LED test
//  written by Patrick De Coninck / Velleman NV.
//  VMA209 contains 3 Push buttons, they are connected to the Arduino Analog inputs A1, A2, A3
//  in this example we will switch ON LED1 when pushing Push button 3 - please feel free to choose different buttons or LEDS
//****************************************************


int ledpin=13; //Define integer ledpin with a value of 13
int inpin=A3;  //Define integer inpin = analog line A3
int val;  // define variable VAL
void setup()
{
pinMode(ledpin,OUTPUT);//Declare ledpin (which has a value of 13) as OUTPUT
pinMode(inpin,INPUT);//Declare inpin (which is analog input A3) as INPUT
}
void loop()
{
val=digitalRead(inpin);//Read the value of Analog line 13 (push button)
if(val==LOW)           //If this value is LOW: 
{ digitalWrite(ledpin,LOW);} // then ledpin (the led on digital line 13) is also LOW (off)
else
{ digitalWrite(ledpin,HIGH);} // in the other case (ledpin is not low) switch ON the LED on D13
}

