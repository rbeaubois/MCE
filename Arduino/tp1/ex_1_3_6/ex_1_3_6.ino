/* *******************************
* Exercise 1.3.6 : Improved bidirectionnal led chaser 
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define BTN1_PIN    A1
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
  int sd, i;

// Executed once to set pins, variables, ...
void setup() {
  // Set push button
    pinMode(BTN1_PIN, INPUT); // Pull-up is already on shield (enable/disable with J2 jumper)

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
    int sw = digitalRead(BTN1_PIN);    // sw stands for switch but this latter is an Arduino keyword

    if (sw == HIGH)
    {
      if (i!=(nb_leds-1))
        i++;
      else
        i=0;
    }
    else
    {
      if (i!=0)
        i--;
      else
        i=nb_leds-1;
    }
      
    digitalWrite(leds[i], LED_ON);  // LED at index i lights up
    delay(500);                     // Wait 500ms
    digitalWrite(leds[i], LED_OFF); // LED at index i lights off


  /* Spicy coding */
    // bool sw = digitalRead(TO_READ_PIN);
    // for (int i = (sw)?(0):(nb_leds-1) ; (sw)?(i<nb_leds):(i>-1) ; i+=(sw)?(1):(-1))
    // {
    //   digitalWrite(leds[i], LED_ON);  // LED at index i lights up
    //   delay(500);                     // Wait 500ms
    //   digitalWrite(leds[i], LED_OFF);  // LED at index i lights off
    // }

}