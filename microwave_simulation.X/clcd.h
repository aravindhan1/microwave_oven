#ifndef CLCD_H
#define CLCD_H

#include <xc.h>
#define _XTAL_FREQ 20000000

/* LCD Data Port */
#define CLCD_DATA_PORT      PORTB
#define CLCD_DATA_DDR       TRISB

/* Control Pins */
#define CLCD_RS             RC0
#define CLCD_RW             RC1
#define CLCD_EN             RC2

#define CLCD_RS_DDR         TRISC0
#define CLCD_RW_DDR         TRISC1
#define CLCD_EN_DDR         TRISC2

/* Modes */
#define INST_MODE   0
#define DATA_MODE   1

#define HI  1
#define LOW 0

/* LCD Commands */
#define TWO_LINE_LCD        0x38
#define CLEAR_DISP_SCREEN   0x01
#define DISP_ON_CURSOR_OFF  0x0C

/* Line addresses */
#define LINE1(x) (0x80 + (x))
#define LINE2(x) (0xC0 + (x))
#define LINE3(x) (0x94 + (x))
#define LINE4(x) (0xD4 + (x))

void init_clcd(void);
void clcd_write(unsigned char byte, unsigned char mode);
void clcd_putch(char data, unsigned char addr);
void clcd_print(const char *str, unsigned char addr);

#endif
