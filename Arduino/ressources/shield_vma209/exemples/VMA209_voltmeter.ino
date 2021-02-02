//**********************************************************************************************
//-- VMA209 Voltmeter example 
//-- This example reads the value of the blue potmeter on the VMA209 and shows it on the display
//**********************************************************************************************/

int  potpin=A0;//declare variable potpin as connected to analog input A0
int latchPin = 4;
int clockPin =7;
int dataPin = 8; //declare latchPin, clockpin and datapin for the display (data pins 4,7 and 8)

unsigned char Dis_table[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};	// This table defines the 7 segments of the display , 0x is not used here.00 = all segments ON, FF = all segments OFF, 0x7F is used for the decimal point
unsigned char Dis_buf[]   = {0xF1,0xF2,0xF4,0xF8}; // this table sets a "selector" for what digit is selected 
unsigned char disbuff[]  =  {0, 0, 0, 0}; // set display buffer to 0
int SUM = 0;


void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //set the 3 data pins as output
}

void display()
{
  for(char i=0; i<=3; i++)// This routine will write information to the 4 display digits, variable i will count from 0 to 3
  {
    digitalWrite(latchPin,LOW); //Activate the Latch Pin , the Latch Pin allows data to be written to the shift registers of the VMA209
    shiftOut(dataPin,clockPin,MSBFIRST,Dis_table[disbuff[i]]); //output Dis_table depending on the value of i , 
    shiftOut(dataPin,clockPin,MSBFIRST,Dis_buf[i] );  //output Dis_buf depending on the value of i
    digitalWrite(latchPin,HIGH); //De-activate the latch pin, the information for digit(i) has been written
    delay(2);				// take a break for 2mS 
  }
  
}

void loop()
{
  
    SUM=analogRead(potpin)*(4.97 / 1.0230); // read the analog value of A0, this is the analog input connected to the blue trimmer on the VMA209 
    disbuff[0]=SUM/1000;		//Store this analog value into the 4 display buffers , each digit has his own display buffer disbuff(i) where i range from 0 to 3
    disbuff[1]=SUM%1000/100;	
    disbuff[2]=SUM%100/10;	
    disbuff[3]=SUM%10;

      for(char time=0;time<10;time++)

    {
    display();
    }
  }
  
  

