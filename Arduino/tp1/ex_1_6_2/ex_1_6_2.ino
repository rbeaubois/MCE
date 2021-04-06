/* *******************************
* Exercise 1.6.2 : PWM stands for Pulse Width Modulation !
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define BUZZER_PIN  3
#define POT_PIN     A0
#define LED1_PIN    13
#define LED2_PIN    12
#define LED3_PIN    11
#define LED4_PIN    10
#define LED_ON      LOW
#define LED_OFF     HIGH

int leds[]    = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN}; // Array for led pins
int nb_leds   = (sizeof(leds)/sizeof(leds[0]));           // nb of elements = size of the table / size of 1 element
int pot       = POT_PIN;                                  // Declare potentiometer to use

// Executed once to set pins, variables, ...
void setup() {
  // Set pins
    pinMode(pot, INPUT);
    for (int i = 0; i < nb_leds; i++)
      pinMode(leds[i], OUTPUT);

  // Initialize
    for (int i = 0; i < nb_leds; i++)
      digitalWrite(leds[i], LED_OFF);

  // Prevent ear damages
    digitalWrite(BUZZER_PIN, HIGH);
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding */
    // int led_brightness = map(analogRead(pot), 0, 1023, 0, 10000);
    
    // for (int i = 0; i < nb_leds; i++)
    //   analogWrite(leds[i], led_brightness);
    
    // // Now find the impostor led that is assumed to be PWM compatible but actually isn't !
    // // You may experience fast blinking, it's due to the high flucutation on the value read on the pot
    // // a slight delay will improve it


  /* Spicy coding*/
  // A fancier use of the PWM signal could be a hearbeat led so here we go
  // Heartbeat by 2PWM
    static int lval = 0;  // led brightness
    static int sd   = 1;  // Shift direction
    static int cnt  = 0;  // Counter of microseconds

    for (int i = 0; i < nb_leds; i++)
      analogWrite(leds[i], lval);
    
    if (cnt == 10){
      cnt = 0;

      if(lval==255)
        sd = -1;
      else if(lval==0)
        sd = 1;
      
      lval += sd;
    }
    else{
      cnt++;
    }

    delay(1);
    
    // Linear increment doesn't seem to be the most appealing choice for brightness evolution
    // but since the naked eye render isn't perceived linear, it looks fine
    // The use of "static" directive is used to initialize variable only once so as I can
    // declare the variables here instead of flooding the upper part

}
