/*************************************************
 * Narcotic
 * Liquido - 1998
 * 
 * R. Beaubois
 *************************************************/

#ifndef __NARCOTIC__H__

#include "pitches.h"  // Correspondance between PWM values and notes tuned in 12-ET
#include "rhythm.h"   // Correspondance between rhythm notations and time

#define SONG_BPM 102

// PWM values corresponding to notes thx to library pitches.h
const unsigned int pitch[] = {
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,//NOTE_F4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,//NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,//NOTE_E4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,0,NOTE_F4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,//NOTE_F4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,//NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,//NOTE_E4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,//NOTE_F4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,//NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,//NOTE_E4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,0,NOTE_F4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,//NOTE_F4,
  NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,//NOTE_A4,
  NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_G4,//NOTE_E4,
  NOTE_E4,NOTE_D4,NOTE_E4,NOTE_D4,NOTE_E4,NOTE_F4,
  NOTE_E4
};

// Rhythm of the melody
const float rhythm[] = {
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,NOIRE,
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,NOIRE,NOIRE,
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,NOIRE,
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,CROCHE,DBL_CROCHE,DBL_CROCHE+
  CROCHE,CROCHE,CROCHE,CROCHE,NOIRE,NOIRE,
  RONDE
};

#endif