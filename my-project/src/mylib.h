#ifndef MYLIB_H  //二重でincludeされることを防ぐ
#define MYLIB_H

void main(void);

// call this
void gpio_setup(void);
void led_toggle(void);
void wait(void);
void led_on(void);
void led_off(void);

#endif
