#ifndef KEYPAD_H
#define KEYPAD_H
#include "stm32f1xx_hal.h"

/* Rows - Outputs */
#define R1_PIN GPIO_PIN_7
#define R1_PORT GPIOB

#define R2_PIN GPIO_PIN_10
#define R2_PORT GPIOB

#define R3_PIN GPIO_PIN_11
#define R3_PORT GPIOA

#define R4_PIN GPIO_PIN_12
#define R4_PORT GPIOA

/* Columns - Inputs */
#define C1_PIN GPIO_PIN_6
#define C1_PORT GPIOB

#define C2_PIN GPIO_PIN_5
#define C2_PORT GPIOB

#define C3_PIN GPIO_PIN_2
#define C3_PORT GPIOA

#define C4_PIN GPIO_PIN_3
#define C4_PORT GPIOA

/* key mapping */
extern const char keymap[4][4];

char get_keypad_key(void);

#endif
