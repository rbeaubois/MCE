/* *******************************
* Exercise 1.4.2 : LED threshold lighting
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define ADC0_PIN    A0
#define LED1_PIN    13
#define LED_ON      LOW
#define LED_OFF     HIGH

// Global variables
  const int threshold = 500;
  int adc = ADC0_PIN;
  int led = LED1_PIN;

// Executed once to set pins, variables, ...
void setup() {
  // Set ADC
    pinMode(adc, INPUT);

  // Set led pin as output
    pinMode(led, OUTPUT);

  // Initialize led
    digitalWrite(led, LED_OFF);

}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding */
    int pot = analogRead(adc);
      
    if (pot>=threshold)
        digitalWrite(led, LED_ON);
    else
        digitalWrite(led, LED_OFF);

  /* Spicy coding */
//     digitalWrite(led, !(analogRead(adc)>=threshold));

}
