/***************************************************************************
* Author   : 
* Created  : 
* Edited   : 
*
* >>> oshibotan.ino : sketch principal du projet
*
* Comments :
* 
*
*****************************************************************************/

// Utilities libraries
#include "VMA209.h"         // Mapping defines for VMA209 shield
#include "aff7seg.h"        // Functions 7 segments display

// User functions
void mute(int sound_out);

// Global variables
unsigned long it_time = 0; // Keep track on time elasped since program start up

// Setting pins mode and init
void setup() {
  // 7 segments display
  pinMode(SEG_CLK_PIN,    OUTPUT);
  pinMode(SEG_DATA_PIN,   OUTPUT);
  pinMode(SEG_WDATA_PIN,  OUTPUT);
}

/* ************************************* MAIN LOOP ******************************************* */
void loop() {
  it_time = millis();

  // Refresh 7 segments  
  display7seg_int(120, it_time);  // Display 120 on 7 seg every LCD_REFRESH_TIME ms
}
/* ********************************* END MAIN LOOP *******************************************  */

// Mute sound output
void mute(int sound_out){
  if(sound_out == BUZZER_PIN)
    digitalWrite(sound_out,HIGH);  // buzzer driven by PNP so it's inverted, high voltage turns it off
  else
    noTone(sound_out);
}
