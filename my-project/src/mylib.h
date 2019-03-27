#ifndef MYLIB_H  //二重でincludeされることを防ぐ
#define MYLIB_H

typedef unsigned int uint32;
typedef unsigned short uint16;

void main(void);

uint32 gpioB(void);
uint16 gpio12(void);

// call this
void gpio_setup(void);
void led_toggle(void);
void wait(uint32);
void led_on(void);
void led_off(void);

#endif
