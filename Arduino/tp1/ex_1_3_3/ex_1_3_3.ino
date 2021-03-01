/* *******************************
* Exercise 1.3.3 : Pull-up resistor
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
    pinMode(TO_READ_PIN,  INPUT_PULLUP); // Enable intern pull-up resistor of Arduino
    pinMode(led,          OUTPUT);

  // Initiatilze led
    digitalWrite(led,     LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding 1 */
    int button  = digitalRead(TO_READ_PIN);

    if(bouton == HIGH)
      digitalWrite(led, LED_OFF);
    else
      digitalWrite(led, LED_ON);

  /* Spicy coding */
    // (!digitalRead(TO_READ_PIN))?(digitalWrite(led, LED_ON)):(digitalWrite(led, LED_OFF));

  /* Meaty coding */
    // digitalWrite(led, digitalRead(TO_READ_PIN));
}