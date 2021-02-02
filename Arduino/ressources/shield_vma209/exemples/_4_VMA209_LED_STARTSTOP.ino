//*******************************************************************************
//  VMA209 - LED START-STOP BY PUSH BUTTON EXAMPLE
//  function : press S1, LED D1 will light -- press S1 again, LED D1 will switch off
//  programmed on:Arduino IDE-----------------------------------------
//  compatible with Arduino UNO, MEGA 
//*******************************************************************************

#define LED 13  // LED is on digital 13, another value between line 10 and 13 can be chosen ! Just give it a try !
#define KEY A1  // we choose one of the available push buttons which are on A1, A2 or A3. In this case we choose A1 but You can try another one

int KEY_NUM = 0;	

void setup()
{
  pinMode(LED,OUTPUT);			// initialize LED (D13) as output
  pinMode(KEY,INPUT_PULLUP);		//initialize KEY (analog pin A1) as an input with the internal pull-up resistor enabled
}

void loop()
{
  ScanKey();		// check if there is a key pressed (see void ScanKey)
  if(KEY_NUM == 1)	// key 1 pressed
  {   
    digitalWrite(LED,!digitalRead(LED));// Inverte the LED status
  }
}

void ScanKey()	// ScanKey routine
{
  KEY_NUM = 0;	
  if(digitalRead(KEY) == LOW)	
  {
    delay(20);						// anti-bounce delay , this is the minimuum time You have to press the button
    if(digitalRead(KEY) == LOW)		
    {
      KEY_NUM = 1;				
      while(digitalRead(KEY) == LOW);
    }
  }
}
