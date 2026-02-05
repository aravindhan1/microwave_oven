#include "matrix_keypad.h"

void init_matrix_keypad(void)
{
    TRISD = 0x78;   // RD3-6 input, RD0-2 output
    PORTD = 0x07;   // columns high
}

static unsigned char scan_keypad(void)
{
    COL1=0; COL2=1; COL3=1;
    if(ROW1) return '1';
    if(ROW2) return '4';
    if(ROW3) return '7';
    if(ROW4) return '*';

    COL1=1; COL2=0; COL3=1;
    if(ROW1) return '2';
    if(ROW2) return '5';
    if(ROW3) return '8';
    if(ROW4) return '0';

    COL1=1; COL2=1; COL3=0;
    if(ROW1) return '3';
    if(ROW2) return '6';
    if(ROW3) return '9';
    if(ROW4) return '#';

    return ALL_RELEASED;
}

unsigned char read_matrix_keypad(unsigned char mode)
{
    static unsigned char once = 1;
    unsigned char key = scan_keypad();

    if (mode == LEVEL)
        return key;

    if (key != ALL_RELEASED && once)
    {
        once = 0;
        return key;
    }
    else if (key == ALL_RELEASED)
    {
        once = 1;
    }

    return ALL_RELEASED;
}
