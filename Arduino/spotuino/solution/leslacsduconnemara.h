/*************************************************
 * Les lacs du connemara
 * Michel Sardou - 1981
 * 
 * R. Beaubois
 *************************************************/

#ifndef __LESLACSDUCONNEMARA__H__

#include "pitches.h"  // Correspondance between PWM values and notes tuned in 12-ET
#include "rhythm.h"   // Correspondance between rhythm notations and time

#define SONG_BPM 120

// PWM values corresponding to notes thx to library pitches.h
const unsigned int pitch[] = {
  NOTE_G4,NOTE_DS4,   NOTE_G4,NOTE_DS4,   NOTE_G4,NOTE_DS4,   NOTE_GS4,NOTE_G4,NOTE_F4,
  NOTE_G4,NOTE_DS4,   NOTE_G4,NOTE_DS4,   NOTE_G4,NOTE_DS4,   NOTE_GS4,NOTE_G4,NOTE_F4,
  NOTE_DS4,NOTE_C4,   NOTE_DS4,NOTE_C4,   NOTE_DS4,NOTE_C4,   NOTE_DS4,NOTE_D4,NOTE_DS4,
  NOTE_F4,
  NOTE_GS4,NOTE_F4,NOTE_GS4,NOTE_F4,    NOTE_GS4,NOTE_F4,NOTE_AS4,NOTE_GS4,NOTE_G4,
  NOTE_GS4,NOTE_F4,NOTE_GS4,NOTE_F4,    NOTE_GS4,NOTE_F4,NOTE_AS4,NOTE_GS4,NOTE_G4,
  NOTE_GS4,NOTE_F4,NOTE_GS4,NOTE_F4,    NOTE_GS4,NOTE_F4,NOTE_GS4,NOTE_G4,NOTE_GS4,
  NOTE_AS4
};

// Rhythm of the melody
const float rhythm[] = {
  BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   NOIRE,NOIRE,NOIRE,
  BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   NOIRE,NOIRE,NOIRE,
  BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   BLANCHE_P,NOIRE,   NOIRE,NOIRE,NOIRE,
  RONDE,
  NOIRE_P,CROCHE,NOIRE_P,CROCHE,    NOIRE_P,CROCHE,CROCHE_P,DBL_CROCHE+CROCHE,CROCHE,
  NOIRE_P,CROCHE,NOIRE_P,CROCHE,    NOIRE_P,CROCHE,CROCHE_P,DBL_CROCHE+CROCHE,CROCHE,
  NOIRE_P,CROCHE,NOIRE_P,CROCHE,    NOIRE_P,CROCHE,CROCHE_P,DBL_CROCHE+CROCHE,CROCHE,
  RONDE_P
};

#endif