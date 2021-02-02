//*******************************************************************************
//----------------VMA209 UP-DOWN counter example-----------
//*******************************************************************************/
int latchPin = 4;
int clockPin =7;
int dataPin = 8; //Define latch, clock and data pins for the display
int KEY_ADD =A1;  //Define Switch 1 as count UP
int KEY_DEC=A2;  //Define Switch 2 as count DOWN
unsigned char Dis_table[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};	//LED status display variables
unsigned char Dis_buf[]   = {0xF1,0xF2,0xF4,0xF8};
unsigned char disbuff[]  =  {0, 0, 0, 0};  
int SUM = 0;
int Flag_up = 1;
int Flag_up1 = 1;

void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //define pins 4,7,8 as OUTPUT
}

void display()
{
  for(char i=0; i<=3; i++)
  {
    digitalWrite(latchPin,LOW); 
    shiftOut(dataPin,clockPin,MSBFIRST,Dis_table[disbuff[i]]); //Send value to the 4 displays
    shiftOut(dataPin,clockPin,MSBFIRST,Dis_buf[i] );  
    digitalWrite(latchPin,HIGH); 
    delay(2);				//wait 2ms before accesing the next display, please try another value (for example 100 ) to see how the multiplexing works 
  }
  
}
unsigned char ScanKey()			//Scan push button 1 (S1)
{
  if(Flag_up  && digitalRead(KEY_ADD) == LOW)		
  {
    Flag_up = 0;										
    display();
    display();											
    if(digitalRead(KEY_ADD) == LOW)			
    {
      return 1;											
    }
  }
  if(digitalRead(KEY_ADD) == HIGH)			
  {
    Flag_up = 1;										
  }
  return 0;													
}

unsigned char ScanKey1()			//Scan push button 2 (S2)
{
  if(Flag_up1  && digitalRead(KEY_DEC) == LOW)		
  {
    Flag_up1 = 0;										
    display();
    display();											
    if(digitalRead(KEY_DEC) == LOW)			
    {
      return 1;											
    }
  }
  if(digitalRead(KEY_DEC) == HIGH)			
  {
    Flag_up1 = 1;										
  }
  return 0;													
}

void loop()
{
  
   display();
   if( ScanKey() == 1)				// if a push button is pressed 
  {
    SUM++;								//Add 1
    if(SUM>9999)					//Maximum counter value is 9999 (try another value !! )
    {
      SUM = 9999;  // remains at 9999
    }
    disbuff[0]=SUM/1000;		//Fill the 4 display buffers with the new value
    disbuff[1]=SUM%1000/100;	
    disbuff[2]=SUM%100/10;		
    disbuff[3]=SUM%10;				
   }
   
   if( ScanKey1() == 1)				//Button 2 pushed ?
  {
    SUM--;								//Count down one value
    if(SUM<=0)					//Value is zero ? than remain at 0
    {
      SUM = 0;
    }
    disbuff[0]=SUM/1000;		//Fill the 4 display buffers with the new value
    disbuff[1]=SUM%1000/100;	
    disbuff[2]=SUM%100/10;		
    disbuff[3]=SUM%10;			
   }
  
  }
  
  

