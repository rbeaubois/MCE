//*******************************************************************************
//  VMA209 - Pot meter example
//  The VMA209 contains a blue potmeter (trimmer) which is connected to Analog 0
//  In this example we show You how to measure the voltage between 0 and 5V, and how to visualise it by the serial monitor
//  Programmed :Arduino IDE
//  Board ：Arduino Leonardo, UNO, MEGA 
//*******************************************************************************/
#define Pot A0			//declare Analog line 0 as Pot

int PotBuffer = 0;		//initialize variable PotBuffer as integer

void setup()
{
  Serial.begin(9600);			//Set serial port to 9600 Baud
}

void loop()
{
  PotBuffer = analogRead(Pot);	// Read the value of Pot (A0) and store it into PotBuffer
  Serial.print("Pot = ");// Write "Pot = " to the serial monitor
  Serial.println(PotBuffer);    // Now print the actual value measured by A0 (Pot or PotBuffer), TURN the small screw on top of the blue trimmer and You will see a value between 0 and about 1000
                                //
                                // This means that You have to devide PotBuffer by 200 to have the actual voltage on A0 (Serial.println(PotBuffer/200)), the variable Potbuffer , which is declared as Integer (int) should 
                                // then be declared as Floating point variable or : float PotBuffer = 0;
                                
  delay(500);										// wait 0,5 sec. between each measuring cycle
}
