//*******************************************************************************
//VMA209 RUNNING LED EXAMPLE
//Written on : Arduino IDE
//Compatible with ：Arduino Leonardo, Arduino UNO, Mega
//*******************************************************************************/
int BASE = 10 ;  //Digital Pin Base = 10, 10 = corresponding with D10
int NUM = 4;   // 4 Digital lines are used for 4 LEDs

void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   //declare digital pins 10 to 13 as output
   }
}

void loop()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, LOW);    //Switch OFF Digital lines 10 to 13 one by one
     delay(200);        // wait 0,2 seconds
   }
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, HIGH);    //Switch ON Digital lines 10 to 13 one by one
     delay(200);        //wait 0,2 seconds
   }  
}

