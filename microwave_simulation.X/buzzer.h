#ifndef BUZZER_H
#define BUZZER_H

#include <xc.h>
#define _XTAL_FREQ 20000000

#define BUZZER RC5
#define BUZZER_DDR TRISC5

void init_buzzer(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_beep(unsigned int ms);

#endif
