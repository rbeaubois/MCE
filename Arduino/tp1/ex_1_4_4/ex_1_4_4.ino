/* *******************************
* Exercise 1.4.4 : Conversion
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

// Declare adc to read
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
        int val_mV = map(pot, 0, 1023, 0, 5000);

        if(val_mV<500)
        {
            for (int i = 0; i < nb_leds; i++)
            digitalWrite(leds[i], LED_OFF); 
        }
        else
        {
            if(val_mV>2000)
            digitalWrite(leds[0], LED_ON);

            if(val_mV>1500)
            digitalWrite(leds[1], LED_ON);

            if(val_mV>1000)
            digitalWrite(leds[2], LED_ON);

            if(val_mV>500)
            digitalWrite(leds[3], LED_ON);
        }

    /* Spicy coding */
        // int val_mV = map(analogRead(adc), 0, 1023, 0, 5000);

        // digitalWrite(leds[0], !(val_mV>2000));  // '!' because inverted logic for LEDs
        // digitalWrite(leds[1], !(val_mV>1500));
        // digitalWrite(leds[2], !(val_mV>1000));
        // digitalWrite(leds[3], !(val_mV>500));
    

    /* Meaty coding */
        // const int threhsolds[4] = {2000, 1500, 1000, 500};
        // int val_mV = map(analogRead(adc), 0, 1023, 0, 5000);

        // for (int i = 0; i < nb_leds; i++)
        // digitalWrite(leds[i], !(val_mV>threhsolds[i]));
  

}