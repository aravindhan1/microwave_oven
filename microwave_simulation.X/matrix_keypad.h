#ifndef MATRIX_KEYPAD_H
#define MATRIX_KEYPAD_H

#include <xc.h>

#define ROW1 RD3
#define ROW2 RD4
#define ROW3 RD5
#define ROW4 RD6

#define COL1 RD0
#define COL2 RD1
#define COL3 RD2

#define ROW_DDR TRISD
#define COL_DDR TRISD

#define HI 1
#define LOW 0

#define STATE 1
#define LEVEL 0
#define ALL_RELEASED 0xFF

void init_matrix_keypad(void);
unsigned char read_matrix_keypad(unsigned char mode);

#endif
