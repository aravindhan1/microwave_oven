#include "fan.h"

void init_fan(void)
{
    FAN_DDR = 0;
    FAN = 0;
}

void fan_on(void)
{
    FAN = 1;
}

void fan_off(void)
{
    FAN = 0;
}
