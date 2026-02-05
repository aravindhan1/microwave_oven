#include "buzzer.h"

void init_buzzer(void)
{
    BUZZER_DDR = 0;
    BUZZER = 0;
}

void buzzer_on(void)
{
    BUZZER = 1;
}

void buzzer_off(void)
{
    BUZZER = 0;
}

void buzzer_beep(unsigned int ms)
{
    unsigned int i;
    BUZZER = 1;
    for(i=0;i<ms;i++)
        __delay_ms(1);
    BUZZER = 0;
}
