/* *******************************
* Exercise 1.3.4 : 1 second lighten up led
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define PULSE_PIN     9
#define LED1_PIN      13
#define LED2_PIN      12
#define LED3_PIN      11
#define LED4_PIN      10
#define LED_ON        LOW
#define LED_OFF       HIGH

// Declare the only led used
  int led = LED4_PIN; // LED connected to pin 10

// Executed once to set pins, variables, ...
void setup() {
  // Set pins mode
    pinMode(PULSE_PIN,    INPUT_PULLUP); // Enable intern pull-up resistor of Arduino
    pinMode(led,          OUTPUT);

  // Initiatilze led
    digitalWrite(led,     LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding 1 */
    // int button  = digitalRead(PULSE_PIN);

    // if(bouton == LOW){
    //   digitalWrite(led, LED_ON);
    //   delay(3000);
    //   digitalWrite(led, LED_OFF);
    // }
    // else
    // {
    //   digitalWrite(led, LED_OFF);
    // }

  /* Spicy coding */
  // Input is a pulse so we can expect it to last less than 3 seconds
    if(!digitalRead(PULSE_PIN)){
      digitalWrite(led, LED_ON);
      delay(3000);
    }
    else
    {
      digitalWrite(led, LED_OFF);
    }

}