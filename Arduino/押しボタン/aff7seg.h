/***************************************************************************
* Author   : R. Beaubois
* Created  : 29/01/2021
* Edited   : 11/03/2021
*
* >>> aff7seg.h : header contenant les déclarations (prototypes) des fonctions
*
* Comments :
*****************************************************************************/

/* *** 7 segments utilies **************************************************************** */
void display7seg_1digit(const unsigned char sel_digit, const int data);
void display7seg(const int data1, const int data2, const int data3, const int data4);
void display7seg_int(int data,  unsigned long it_time);
unsigned char trans7seg(const int data);