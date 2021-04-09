/* *******************************
* Exercise 1.6.3 : Buzzer
********************************** */

// Define pin mapping
//  - no memory used for defines (C preprocessor)
//  - always useful since we only check pinout once
#define BUZZER_PIN  3
#define BTN1_PIN    A1

// Declare used elements
int buzzer = BUZZER_PIN;
int button = BTN1_PIN;

// Executed once to set pins, variables, ...
void setup() {
  // Set pins
    pinMode(button, INPUT);   // Set button pin
    pinMode(buzzer, OUTPUT);  // Set buzzer pin

  // Initialize
    digitalWrite(buzzer, HIGH);   // Turn off buzzer (inverted because driven by PNP transistor)
}

// Executed over and over (infinite loop)
void loop() {
  /* Standard coding */
  if (digitalRead(button))
  {
    digitalWrite(buzzer, HIGH);   // Turn off buzzer (inverted because driven by PNP transistor)
  }
  else
  {
    analogWrite(buzzer, 127);
    delay(500);
    analogWrite(buzzer, 255); // PWM completly high so buzzer off
    delay(500);
  }
}