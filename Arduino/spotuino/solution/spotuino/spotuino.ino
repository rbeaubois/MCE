/***************************************************************************
* Author   : R. Beaubois
* Created  : 28/01/2021
* Edited   : 11/03/2021
*
* >>> spotuino.ino : sketch principal du projet
*
* Comments :
* V1.11
*   - Add mute functions to handle differents peripherals as sound output
* V1.12
*   - Allows multiple sound output in the same time
* V1.2
*   - Songs handled in header files rather than in main file
* V1.21
*   - Add 7 segments display
* V2.0
*   - All delay replaced by timers
* V2.01
*   - Push buttons keep value and debounce filter
* V2.11
*   - Add led chaser
* V2.12
*   - Add tunable BPM using potentiometer toggled by button 2
*   - Display BPM on segments
*
*****************************************************************************/

// Utilities libraries
#include "VMA209.h"         // Mapping defines for VMA209 shield
#include "spotuino.h"       // Functions for spotuino project

// Song to play (only one at a time for now since tables are named the same)
// #include "leslacsduconnemara.h"   // pitch and rhythm array for "les lacs du connemara"
#include "narcotic.h"             // pitch and rhythm array for "narcotic"

// Sound output
#define SOUND_OUT_PIN   BUZZER_PIN    // PWM1_PIN as signal for aux output (headphones/speaker) | BUZZER_PIN for embedded buzzer

// Musics parameters
unsigned int tempo            = SONG_BPM;  // Tunable BPM
const unsigned int nb_notes   = (sizeof(pitch)/sizeof(pitch[0]));

// Push buttons
unsigned long btn1_rf         = 0;
unsigned long btn2_rf         = 0;
bool btn1                     = false;
bool btn2                     = false;

// 7 Segments
unsigned long t_last_disp     = 0;
unsigned int disp_state       = 0;
int disp_test[] = {0,1,2,3,4,5,6,7,8,9,'a','b','c','d','e','f','_','-','u', '.', '.', ' ', ' ', '.'};

// LEDs
unsigned long t_last_led      = 0;

// Time
unsigned long it_time         = 0;

// Pot
unsigned long pot_rf          = 0;

// Setting pins mode and init
void setup() {
  Serial.begin(115200);
  pinMode(BTN1_PIN,       INPUT);
  pinMode(BTN2_PIN,       INPUT);
  pinMode(POT_PIN,        INPUT);

  pinMode(SOUND_OUT_PIN,  OUTPUT);
  pinMode(SEG_CLK_PIN,    OUTPUT);
  pinMode(SEG_DATA_PIN,   OUTPUT);
  pinMode(SEG_WDATA_PIN,  OUTPUT);
  pinMode(LED1_PIN,       OUTPUT);
  pinMode(LED2_PIN,       OUTPUT);
  pinMode(LED3_PIN,       OUTPUT);
  pinMode(LED4_PIN,       OUTPUT);
}

/* ************************************* MAIN LOOP ******************************************* */
void loop() {
  it_time = millis();

  // Change state of 7 segments for test
  if ((it_time-t_last_disp)>1000)
  {
    (disp_state!=20)?disp_state+=4:disp_state=0; 
    t_last_disp = it_time;
  }

  // Push button as toggle with debounce filter
  if(!digitalRead(BTN1_PIN) && (it_time-btn1_rf)>DEBOUNCE_TIME)
  {
    btn1    = !btn1;
    btn1_rf = it_time;
  }
  if(!digitalRead(BTN2_PIN) && (it_time-btn2_rf)>DEBOUNCE_TIME)
  {
    btn2    = !btn2;
    btn2_rf = it_time;
  }

  // Actions related to button 1
  if(btn1)
  {
    // LED chaser to tempo
    if ((it_time-t_last_led)>(1000*(float)NOIRE/(float)tempo))
    {
      led_chaser('d');
      t_last_led = it_time;
    }

    // Play music 
    music(SOUND_OUT_PIN, tempo, pitch, rhythm, nb_notes);
  }
  else
    mute(SOUND_OUT_PIN);

  // Actions related to button 2
  if(btn2){
    // Tune BPM with averaging (pot's value is highly fluctuating)
    if((it_time-pot_rf)>DEBOUNCE_TIME)
    {
      tempo = SONG_BPM*analogRead(POT_PIN)/100;
      pot_rf = it_time;
    }
  }
  else
    tempo = SONG_BPM;

  // Refresh 7 segments  
  display7seg_int(tempo);
  // display7seg(disp_test[disp_state],disp_test[disp_state+1],disp_test[disp_state+2],disp_test[disp_state+3]);
}
/* ********************************* END MAIN LOOP *******************************************  */
