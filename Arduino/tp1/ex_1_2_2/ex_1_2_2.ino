/* *******************************
* Exercise 1.2.2 : Led chaser
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define LED1_PIN  13
#define LED2_PIN  12
#define LED3_PIN  11
#define LED4_PIN  10
#define LED_ON    LOW
#define LED_OFF   HIGH

// A table can be used to ease led handling
  int leds[]  = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  int nb_leds = (sizeof(leds)/sizeof(leds[0])); // nb of elements = size of the table / size of 1 element

// Declaration for spicy version
  int led_id = 0;

// Executed once to set pins, variables, ...
void setup() {
  // Set pins as output
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);

  // Initialize all leds
    digitalWrite(leds[0], LED_ON);
    for (int i = 1; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding 1 */
  // Simple and efficient led chaser from top to down (from A2a group)
    for (int i = 0; i < nb_leds; i++)
    {
      digitalWrite(leds[i], LED_ON);  // LED at index i lights up
      delay(500);                     // Wait 500ms
      digitalWrite(leds[i], LED_OFF);  // LED at index i lights off
    }

  /* Standard coding 2 */
  // Simple led chaser from top to down (from A2a group)
    // for (int i = 0; i < nb_leds; i++)
    // {
    //   if(i==0)
    //     digitalWrite(leds[nb_leds-1], LED_OFF);   // Previous LED lights off (last led)
    //   else
    //     digitalWrite(leds[i-1], LED_OFF);         // Previous LED lights off (last led)

    //   digitalWrite(leds[i], LED_ON);  // LED at index i lights up
    //   delay(500);                     // Wait 500ms
    // }

  /* Spicy coding */
  // Simple led chaser from top to down
    // (led_id<(nb_leds-1))?(led_id++):(led_id=0);
    // digitalWrite(leds[led_id], LED_ON);   // LED at index led_id lights up
    // delay(500);                           // Wait 500ms
    // digitalWrite(leds[led_id], LED_OFF);  // LED at index led_id lights off    

}