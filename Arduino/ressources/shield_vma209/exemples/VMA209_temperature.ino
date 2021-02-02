//************************************************************************************************************/
//---------------- VMA209 measuring temperature by using input A4 --------------------------------------------/
//--- ATTENTION -- The symbol on the PCB is for sensor 18B20 !! If using LM35 it has to be upside down !! ----/ 
//---------------- CHECK THE POLARITY FIRST !!! --------------------------------------------------------------/
//************************************************************************************************************/
#define LM35 A4

int val = 0;				// initialising variable val with value 0
float temp = 0;			// initialising variable temp as floating point

void setup()
{
  Serial.begin(9600);	// set the baudrate to 9600
}

void loop()
{
  val = analogRead(LM35);			// read the value of A4
  temp = val * 0.48876;				// eventual correction factor 
  Serial.print("LM35 = ");		
  Serial.println(temp);				// print the value to the serial  monitor
  delay(1000);   // wait one second for the next measurement 
}
