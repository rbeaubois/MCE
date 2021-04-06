/* *******************************
* Exercise 1.6.1b : Illustrate PWM operation
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define LED1_PIN    13
#define LED2_PIN    12
#define LED3_PIN    11
#define LED4_PIN    10
#define LED_ON      LOW
#define LED_OFF     HIGH

// A table can be used to ease led handling (go to ex_1_1_1 for alternative declarations)
  int leds[]        = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  int nb_leds       = (sizeof(leds)/sizeof(leds[0])); // nb of elements = size of the table / size of 1 element
  int j = 0;

// Declare useful variables
  float duty_cycle[]      = {1, 10, 50, 100};
  unsigned long period    = 10; // µs
  unsigned long counter   = 0;

// Executed once to set pins, variables, ...
void setup() {

  // Set outputs
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);

  // Initialize all leds
    for (int i = 0; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding*/
  // Light up all leds
  for (int i = 0; i < nb_leds; i++)
    digitalWrite(leds[i], LED_ON);
  
  counter = 0;

  // Light off leds depending on duty cycle
  for (int i = 0; i < nb_leds; i++)
  {
    counter = period*(duty_cycle[i]/100) - counter; // calculate time to wait depending on duty cycle and previous delay
    delay(counter);
    digitalWrite(leds[i], LED_OFF);
  }

}