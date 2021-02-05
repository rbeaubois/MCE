/* *******************************
* Exercise 1.2.1 : Blinking leds
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
//
/*Table with size automatically udpated */
  int leds[]  = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  int nb_leds = (sizeof(leds)/sizeof(leds[0])); // nb of elements = size of the table / size of 1 element
/* Table with given size */
  // int leds[4]  = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
  // int nb_leds  = 4;

// Declaration for spicy version
  unsigned char led_state = 0x00;

// Executed once to set pins, variables, ...
void setup() {
  // Set pins as output
  //
  /* All pins using for loop*/
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);
  /* Without using table*/
    // pinMode(LED1_PIN, OUTPUT);
    // pinMode(LED2_PIN, OUTPUT);
    // pinMode(LED3_PIN, OUTPUT);
    // pinMode(LED4_PIN, OUTPUT);

  // Initialize all leds
  //
  /* All pins using for loop*/
    for (int i = 0; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);
  /* Without using table*/
    // digitalWrite(LED1_PIN, LED_OFF);
    // digitalWrite(LED2_PIN, LED_OFF);
    // digitalWrite(LED3_PIN, LED_OFF);
    // digitalWrite(LED4_PIN, LED_OFF);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding 1 */
    digitalWrite(leds[0],LOW);
    digitalWrite(leds[1],HIGH);
    delay(1000);
    digitalWrite(leds[0],HIGH);
    digitalWrite(leds[1],LOW);
    delay(1000);  // Don't forget this one otherwise it's almost instantly going back at the beginning of the loop

  /* Standard coding 2 */
    // digitalWrite(leds[0],LED_ON);
    // digitalWrite(leds[1],LED_OFF);
    // delay(1000);
    // digitalWrite(leds[0],LED_OFF);
    // digitalWrite(leds[1],LED_ON);
    // delay(1000);  // Don't forget this one otherwise it's almost instantly going back at the beginning of the loop

  /* Spicy coding */
    // digitalWrite(leds[0],led_state);
    // digitalWrite(leds[1],!led_state);
    // delay(1000);
    // led_state = !led_state;

}