/***************************************************************************
* Author   : R. Beaubois
* Created  : 29/01/2021
* Edited   : 11/03/2021
*
* >>> spotuino.cpp : définitions des fonctions du projet
*
* Comments :
*****************************************************************************/

#include "VMA209.h"     // Mapping defines for vma209 shield
#include "spotuino.h"   // Functions headers

/* *** Music utilities **************************************************************** */

// Play all notes of a song
void music(int sound_out, unsigned int tempo, const unsigned int* pitch, const float* rhythm, const unsigned int nb_notes) {
  static unsigned long note_duration;
  static unsigned int note;


  note_duration = (rhythm[note]*1000) / tempo;         // Calculate note duration in ms depending on tempo

  if(!play_note(sound_out, pitch[note], note_duration)){
    if(note<(nb_notes-1))
      note++;
    else
      note = 0;
  }

}

// Play one note of a given pitch and duration on a a given sound output
bool play_note(int sound_out, const unsigned int pitch, const unsigned long duration){
  const unsigned long note_change_delay = 30; // ms, average human can hear down to about 20 ms changes
  static unsigned long last;

  if ((millis()-last) < (duration - note_change_delay))
  {
    if(pitch != 0)
      tone(sound_out, pitch, duration);
    else
      mute(sound_out);
    
    return true;
  }
  else if (((millis()-last) < duration))
  {
    mute(sound_out);
    return true;
  }
  else
  {
    last = millis();
    return false;
  }

}

// Mute sound output
void mute(int sound_out){
  if(sound_out == BUZZER_PIN)
    digitalWrite(sound_out,HIGH);  // buzzer driven by PNP so it's inverted, high voltage turns it off
  else
    noTone(sound_out);
}

/* *** 7 segments utilities **************************************************************** */
void display7seg_1digit(const unsigned char sel_digit, const int data){
  digitalWrite(SEG_WDATA_PIN, SEG_WDATA_EN);
  shiftOut(SEG_DATA_PIN, SEG_CLK_PIN, MSBFIRST, trans7seg(data));
  shiftOut(SEG_DATA_PIN, SEG_CLK_PIN, MSBFIRST, sel_digit);
  digitalWrite(SEG_WDATA_PIN, !SEG_WDATA_EN);
}

void display7seg(const int data1, const int data2, const int data3, const int data4){
  const unsigned char sel_digit[4] = {SEL_DIGIT1, SEL_DIGIT2, SEL_DIGIT3, SEL_DIGIT4};
  const int data_digit[4]   = {data1, data2, data3, data4};
  const int blank_digit[4]  = {' ', ' ', ' ', ' '};
  for(int i = 0 ; i < 4 ; i++)
    display7seg_1digit(sel_digit[i],data_digit[i]);
  for(int i = 0 ; i < 4 ; i++)
    display7seg_1digit(sel_digit[i],blank_digit[i]);
}

unsigned char trans7seg(const int data){
  switch(data){
  case 0        :  return 0xC0;
  case 1        :  return 0xF9;
  case 2        :  return 0xA4;
  case 3        :  return 0xB0;
  case 4        :  return 0x99;
  case 5        :  return 0x92;
  case 6        :  return 0x82;
  case 7        :  return 0xF8;
  case 8        :  return 0x80;
  case 9        :  return 0x90;
  case int('a') :  return 0x88;
  case int('b') :  return 0x83;
  case int('c') :  return 0xA7;
  case int('d') :  return 0xA1;
  case int('e') :  return 0x86;
  case int('f') :  return 0x8E;
  case int('u') :  return 0xC1;
  case int(' ') :  return 0xFF;
  case int('-') :  return 0xBF;
  case int('.') :  return 0x7F;
  case int('_') :  return 0xF7;
  default       :  return 0xFF;
  }
}

void display7seg_int(int data){
  display7seg(' ', data/100, (data/10)%10, (data%10));
}

/* *** LED utilities **************************************************************** */
void led_chaser(char shift){
    const int leds[]    = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};
    const int nb_leds   = sizeof(leds)/sizeof(leds[0]);
    static int i;
    static bool sd;

    if (shift=='d') // down
      (i<(nb_leds-1))?(i++):(i=0);
    else if (shift=='u')  //up
      (i>0)?(i--):(i=nb_leds-1);
    else if (shift=='r') // round trip
    {
      if (i==(nb_leds-1) || i==0)
        sd = !sd;
      
      (sd)?(led_chaser('d')):(led_chaser('u'));
    }

    for (int led_n = 0; led_n < nb_leds; led_n++)
      digitalWrite(leds[led_n], !(led_n==i));
}