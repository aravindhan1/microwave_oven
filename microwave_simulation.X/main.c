#include <xc.h>
#include "clcd.h"
#include "matrix_keypad.h"
#include "microwave.h"
#include "fan.h"
#include "buzzer.h"

#define _XTAL_FREQ 20000000
#pragma config WDTE = OFF

void init_config(void)
{
    init_clcd();
    init_matrix_keypad();
    init_fan();
    init_buzzer();
}

void main(void)
{
    unsigned char key;
    init_config();

    power_on_screen();
    cooking_mode_screen();

    while(1)
    {
        key = read_matrix_keypad(STATE);

        if(key=='1') micro_power_screen();
        else if(key=='2') grill_power_screen();
        else if(key=='3') convection_power_screen();

        cooking_mode_screen();
    }
}
