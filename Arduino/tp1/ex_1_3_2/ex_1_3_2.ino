/* *******************************
* Exercise 1.3.2 : Conditionnal lighting
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define TO_READ_PIN   5
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
    pinMode(TO_READ_PIN,  INPUT);
    pinMode(led,          OUTPUT);

  // Initiatilze led
    digitalWrite(led,     LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding 1 */
    int bouton  = digitalRead(TO_READ_PIN);

    if(bouton == HIGH)
      digitalWrite(led, LED_ON);
    else
      digitalWrite(led, LED_OFF);

  /* Spicy coding */
    // (digitalRead(TO_READ_PIN))?(digitalWrite(led, LED_ON)):(digitalWrite(led, LED_OFF));

  /* Meaty coding */
    // digitalWrite(led, !digitalRead(TO_READ_PIN));
}

// You may have experienced random changes of the led status when the cable isn't plugged in.
// The reason is the lack of pull-up resistor on pin 5 that is left "open" when connection isn't established
// betwenn either the power supply (VCC) or the ground.
// Without pull-up resistor, the value read on the pin is fluctuating because of the ambient electromagnetic noise
// amplified by the cable acting like an antenna.