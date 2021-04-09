/* *******************************
* Exercise 1.5.1 : Digital input
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define LED1_PIN  13
#define BTN1_PIN  A1
#define LED_ON    LOW
#define LED_OFF   HIGH

// Declare components used
int led     = LED1_PIN;
int button  = BTN1_PIN;

// Executed once to set pins, variables, ...
void setup() {
  // Set inputs
    pinMode(button, INPUT);

  // Set outputs
    pinMode(led, OUTPUT);

  // Initiatilze led
    digitalWrite(led, LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding */
  digitalWrite(led, digitalRead(button));
  // Plug/Unplug J2 to enable/disable on-board pull-up resistance
}