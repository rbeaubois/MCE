/***************************************************************************
* Author   : R. Beaubois
* Created  : 29/01/2021
* Edited   : 11/03/2021
*
* >>> spotuino.h : header contenant les déclarations (prototypes) des fonctions
*
* Comments :
*****************************************************************************/

/* *** Music utilities **************************************************************** */
void music(int sound_out, unsigned int tempo, const unsigned int* pitch, const float* rhythm, const unsigned int nb_notes);
bool play_note(int sound_out, const unsigned int pitch, const unsigned long duration);
void mute(int sound_out);

/* *** 7 segments utilies **************************************************************** */
void display7seg_1digit(const unsigned char sel_digit, const int data);
void display7seg(const int data1, const int data2, const int data3, const int data4);
void display7seg_int(int data);
unsigned char trans7seg(const int data);

/* *** LED utilies **************************************************************** */
void led_chaser(char shift);