#include "clcd.h"

void clcd_write(unsigned char byte, unsigned char mode)
{
    CLCD_RS = (mode == DATA_MODE);
    CLCD_RW = 0;
    CLCD_DATA_PORT = byte;

    CLCD_EN = HI;
    __delay_us(100);
    CLCD_EN = LOW;
    __delay_ms(2);
}

void init_clcd(void)
{
    CLCD_DATA_DDR = 0x00;
    CLCD_RS_DDR = 0;
    CLCD_RW_DDR = 0;
    CLCD_EN_DDR = 0;

    __delay_ms(20);

    clcd_write(TWO_LINE_LCD, INST_MODE);
    clcd_write(DISP_ON_CURSOR_OFF, INST_MODE);
    clcd_write(CLEAR_DISP_SCREEN, INST_MODE);
}

void clcd_putch(char data, unsigned char addr)
{
    clcd_write(addr, INST_MODE);
    clcd_write(data, DATA_MODE);
}

void clcd_print(const char *str, unsigned char addr)
{
    clcd_write(addr, INST_MODE);
    while (*str)
    {
        clcd_write(*str++, DATA_MODE);
    }
}
