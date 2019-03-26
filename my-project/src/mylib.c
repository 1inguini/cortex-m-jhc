// #include "api.h"
// #include "api-asm.h"

// int main(void) {
// 	/* add your own code */
// 	uint32_t rev = 0xaabbccdd;
// 	rev = rev_bytes(rev);
// 	return my_func(rev);
// }
#include "mylib.h"
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

void main() { _amain(); }

void gpio_setup(void) {
    /* Enable GPIOA clock. */
    /* Manually: */
    /*RCC_AHB1ENR |= RCC_AHB1ENR_IOPAEN; */
    /* Using API functions: */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);

    /* Set GPIO5 (in GPIO port A) to 'output push-pull'. */
    /* Manually: */
    /*GPIOA_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2)); */
    /*GPIOA_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4)); */
    /* Using API functions: */
    // gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
    // gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL,
                  GPIO12);
}

// call this
void led_toggle() {
    gpio_toggle(GPIOB, GPIO12);
    // gpio_toggle(GPIOB, GPIO5);
    // gpio_toggle(GPIOA, GPIO5); /* LED on */
}

void led_on() {
    gpio_clear(GPIOB, GPIO12);
    // gpio_clear(GPIOA, GPIO5);
    // gpio_clear(GPIOB, GPIO5);
}
void led_off() {
    gpio_set(GPIOB, GPIO12);
    // gpio_set(GPIOA, GPIO5);
    // gpio_set(GPIOB, GPIO5);
}

void wait() {
    int i;
    for (i = 0; i < 100000; i++) { /* Wait a bit. */
        __asm__("nop");
    }
}

// int main(void) {
//   int i;

//   gpio_setup();

//   /* Blink the LED (PC8) on the board. */
//   while (1) {
//     /* Manually: */
//     /* GPIOA_BSRR = GPIO5; */           /* LED off */
//     /* for (i = 0; i < 1000000; i++) */ /* Wait a bit. */
//     /*	__asm__("nop"); */
//     /* GPIOA_BRR = GPIO5; */            /* LED on */
//     /* for (i = 0; i < 1000000; i++) */ /* Wait a bit. */
//     /*	__asm__("nop"); */

//     /* Using API functions gpio_set()/gpio_clear(): */
//     /* gpio_set(GPIOA, GPIO5); */       /* LED off */
//     /* for (i = 0; i < 1000000; i++) */ /* Wait a bit. */
//     /*	__asm__("nop"); */
//     /* gpio_clear(GPIOA, GPIO5); */     /* LED on */
//     /* for (i = 0; i < 1000000; i++) */ /* Wait a bit. */
//     /*	__asm__("nop"); */

//     /* Using API function gpio_toggle(): */
//     gpio_toggle(GPIOA, GPIO5);      /* LED on/off */
//     gpio_toggle(GPIOB, GPIO5);      /* LED on/off */
//     for (i = 0; i < 1000000; i++) { /* Wait a bit. */
//       __asm__("nop");
//     }
//   }

//   return 0;
// }
