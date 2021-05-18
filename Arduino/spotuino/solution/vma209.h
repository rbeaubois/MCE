/***************************************************************************
* Author   : R. Beaubois
* Created  : 28/01/2021
* Edited   : 11/03/2021
*
* >>> vma209.h : définitions des pins du shield vma209
*
* Comments :
*****************************************************************************/

#ifndef __VMA209_H__

// Buttons
#define BTN1_PIN        A1
#define BTN2_PIN        A2
#define BTN3_PIN        A3
#define DEBOUNCE_TIME   200

// Potentiometer
#define POT_PIN         A0

// LED
#define LED1_PIN        13
#define LED2_PIN        12
#define LED3_PIN        11
#define LED4_PIN        10

// Buzzer
#define BUZZER_PIN      3

// Socket infrared receiver
#define IR_RX_PIN       2   // Infrared receiver

// Socket temperature sensor LM35
#define TS_PIN          A4  // Temperature sensor

// 4 digits 7 segments display
#define SEG_CLK_PIN     7               // Clock
#define SEG_DATA_PIN    8               // Data
#define SEG_WDATA_PIN   4               // Write data enable pin
#define SEG_WDATA_EN    LOW             // Write data enable
#define SEL_DIGIT1      0xF1            // Multiplexing command for digit 1
#define SEL_DIGIT2      0xF2            // Multiplexing command for digit 2
#define SEL_DIGIT3      0xF4            // Multiplexing command for digit 3
#define SEL_DIGIT4      0xF8            // Multiplexing command for digit 4

// PWM
#define PWM1_PIN        5
#define PWM2_PIN        6
#define PWM3_PIN        9
#define PWM4_PIN        A5

#endif