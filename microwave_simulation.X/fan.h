#ifndef FAN_H
#define FAN_H

#include <xc.h>

#define FAN RC4
#define FAN_DDR TRISC4

void init_fan(void);
void fan_on(void);
void fan_off(void);

#endif
