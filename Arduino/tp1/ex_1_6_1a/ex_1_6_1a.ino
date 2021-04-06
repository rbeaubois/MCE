/* *******************************
* Exercise 1.6.1a : Illustrate PWM operation
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define POT_PIN     A0
#define LED1_PIN    13
#define LED2_PIN    12
#define LED3_PIN    11
#define LED4_PIN    10
#define LED_ON      LOW
#define LED_OFF     HIGH

// A table can be used to ease led handling (go to ex_1_1_1 for alternative declarations)
  int leds[]  = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  int nb_leds = (sizeof(leds)/sizeof(leds[0])); // nb of elements = size of the table / size of 1 element
  bool state;

// Executed once to set pins, variables, ...
void setup() {
  // Set inputs
    pinMode(POT_PIN, INPUT);

  // Set outputs
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);

  // Initialize all leds
    for (int i = 0; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);

    digitalWrite(leds[1], LED_ON);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding*/
  int pot = map(analogRead(POT_PIN), 0, 1023, 2, 2000); // 2 ms -> 500 Hz | 2000 ms -> 0.5 Hz

  state = !state;
  digitalWrite(leds[0], state);
  delay(pot);

}