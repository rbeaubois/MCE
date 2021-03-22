/* *******************************
* Exercise 1.4.3 : Variable speed led chaser
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define ADC0_PIN    A0
#define LED1_PIN    13
#define LED2_PIN    12
#define LED3_PIN    11
#define LED4_PIN    10
#define LED_ON      LOW
#define LED_OFF     HIGH

// A table can be used to ease led handling (go to ex_1_1_1 for alternative declarations)
  int leds[]  = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  int nb_leds = (sizeof(leds)/sizeof(leds[0])); // nb of elements = size of the table / size of 1 element

// Shift direction variable
  int sd = 1, i;

// Global variable
  int adc = ADC0_PIN;

// Executed once to set pins, variables, ...
void setup() {
  // Set ADC pin as input
    pinMode(adc, INPUT);

  // Set leds pin as output
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);

  // Initialize all leds
    for (int i = 0; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding */
    int pot = analogRead(adc);

    if (i!=(nb_leds-1))
      i++;
    else
      i=0;
      
    digitalWrite(leds[i], LED_ON);  // LED at index i lights up
    delay(pot);                     // Variable delay depending on pot's value
    digitalWrite(leds[i], LED_OFF); // LED at index i lights off

}