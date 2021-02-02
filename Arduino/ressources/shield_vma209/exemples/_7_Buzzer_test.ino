//*******************************************************************************
// VMA209 Buzzer example
// The buzzer on the VMA209 is connected to digital pin 3
// with this small example, we show You how to create a siren
// compatible with ：Arduino Leonardo or Arduino UNO R3
//*******************************************************************************/

int buzzer=3;     //Set variable buzzer as integer and assign the value 3 
void setup() 
{ 
pinMode(buzzer,OUTPUT);// Initialize Pin3 (buzzer) as output 
} 
void loop() 
{ 
unsigned char i,j;// Define variables
while(1) 
{ 
for(i=0;i<80;i++)
{ 
digitalWrite(buzzer,HIGH);//Sound On
delay(1);// Wait 1ms 
digitalWrite(buzzer,LOW);//Sound Off
delay(1);//Wait 1ms 
} 
for(i=0;i<100;i++)//second sound  
{ 
digitalWrite(buzzer,HIGH);//Sound On
delay(2);//Wait 2ms 
digitalWrite(buzzer,LOW);//Sound Off
delay(2);//Wait 2ms 
} 
} 
}

