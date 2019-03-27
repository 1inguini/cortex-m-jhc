#ifndef MYLIB_H  //二重でincludeされることを防ぐ
#define MYLIB_H

typedef unsigned int uint;

void main(void);

// call this
void gpio_setup(void);
void led_toggle(void);
void wait(uint);
void led_on(void);
void led_off(void);

#endif
