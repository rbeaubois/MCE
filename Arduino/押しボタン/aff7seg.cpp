/***************************************************************************
* Author   : R. Beaubois
* Created  : 29/01/2021
* Edited   : 11/03/2021
*
* >>> aff7seg.cpp : définitions des fonctions de l'afficheur 7 segments
*
* Comments :
*****************************************************************************/

#include "VMA209.h"     // Mapping defines for vma209 shield
#include "aff7seg.h"   // Functions headers

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

void display7seg_int(int data, unsigned long it_time){
  static unsigned long last_it_time = 0;
  if ((it_time-last_it_time)> LCD_REFRESH_TIME)
  {
    display7seg(' ', data/100, (data/10)%10, (data%10));
  }
}