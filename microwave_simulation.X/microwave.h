#ifndef MICROWAVE_H
#define MICROWAVE_H

void power_on_screen(void);
void cooking_mode_screen(void);

void micro_power_screen(void);
void grill_power_screen(void);
void convection_power_screen(void);

void set_time_screen(void);
void enter_time(void);
void run_timer(void);

void set_temp_screen(void);
void enter_temperature(void);

extern unsigned int minutes;
extern unsigned int seconds;
extern unsigned int temperature;

#endif
