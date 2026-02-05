#include "microwave.h"
#include "clcd.h"
#include "matrix_keypad.h"
#include "fan.h"
#include "buzzer.h"

#define _XTAL_FREQ 20000000

unsigned int minutes=0, seconds=0, temperature=0;

void power_on_screen(void)
{
    clcd_print("Powering ON", LINE2(0));
    __delay_ms(2000);
}

void cooking_mode_screen(void)
{
    clcd_print("1.Micro", LINE1(0));
    clcd_print("2.Grill", LINE2(0));
    clcd_print("3.Convection", LINE3(0));
}

void micro_power_screen(void)
{
    clcd_print("Power=900W", LINE2(0));
    __delay_ms(2000);
    enter_time();
}

void grill_power_screen(void)
{
    clcd_print("Power=700W", LINE2(0));
    __delay_ms(2000);
    enter_time();
}

void convection_power_screen(void)
{
    clcd_print("Set Temp", LINE2(0));
    __delay_ms(2000);
    enter_temperature();
}

void set_temp_screen(void)
{
    clcd_print("SET TEMP", LINE1(0));
    clcd_print("Temp=000C", LINE2(0));
}

void enter_temperature(void)
{
    unsigned char key;
    char t[3]={'0','0','0'};
    unsigned char pos=0;

    set_temp_screen();

    while(1)
    {
        key=read_matrix_keypad(STATE);
        if(key>='0' && key<='9' && pos<3)
        {
            t[pos++]=key;
            clcd_putch(t[0],LINE2(5));
            clcd_putch(t[1],LINE2(6));
            clcd_putch(t[2],LINE2(7));
        }
        else if(key=='#')
        {
            enter_time();
            break;
        }
    }
}

void set_time_screen(void)
{
    clcd_print("SET TIME", LINE1(0));
    clcd_print("00:00", LINE2(5));
}

void enter_time(void)
{
    unsigned char key;
    char time[4]={'0','0','0','0'};
    unsigned char pos=0;

    set_time_screen();

    while(1)
    {
        key=read_matrix_keypad(STATE);
        if(key>='0' && key<='9' && pos<4)
        {
            time[pos++]=key;
            minutes=(time[0]-'0')*10+(time[1]-'0');
            seconds=(time[2]-'0')*10+(time[3]-'0');

            clcd_putch(time[0],LINE2(5));
            clcd_putch(time[1],LINE2(6));
            clcd_putch(':',LINE2(7));
            clcd_putch(time[2],LINE2(8));
            clcd_putch(time[3],LINE2(9));
        }
        else if(key=='#')
        {
            run_timer();
            break;
        }
    }
}

void run_timer(void)
{
    unsigned char key;
    fan_on();

    while(minutes||seconds)
    {
        clcd_putch((minutes/10)+'0',LINE1(7));
        clcd_putch((minutes%10)+'0',LINE1(8));
        clcd_putch(':',LINE1(9));
        clcd_putch((seconds/10)+'0',LINE1(10));
        clcd_putch((seconds%10)+'0',LINE1(11));

        __delay_ms(1000);

        if(seconds==0)
        {
            seconds=59;
            minutes--;
        }
        else seconds--;

        key=read_matrix_keypad(LEVEL);
        if(key=='6') break;
    }

    fan_off();
    buzzer_beep(5000);
}
