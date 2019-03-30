char jhc_c_compile[] = "gcc /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/profile.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/rts_support.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/gc_none.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/jhc_rts.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/lib/lib_cbits.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/gc_jgc.c /home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/rts/stableptr.c -I/home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom/cbits -I/home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom /home/linguini/Desktop/Haskell/jhc-blackpill/hs_main.c -o /home/linguini/Desktop/Haskell/jhc-blackpill/hs_main.c '-std=gnu99' -D_GNU_SOURCE '-falign-functions=4' -ffast-math -Wextra -Wall -Wno-unused-parameter -fno-strict-aliasing -DNDEBUG -O3 '-D_JHC_GC=_JHC_GC_JGC'";
char jhc_command[] = "jhc -v -fffi --tdir=/home/linguini/Desktop/Haskell/jhc-blackpill/jhc_custom -C --include=/home/linguini/Desktop/Haskell/jhc-blackpill --include=/home/linguini/Desktop/Haskell/jhc-blackpill/Lib -o /home/linguini/Desktop/Haskell/jhc-blackpill/hs_main.c /home/linguini/Desktop/Haskell/jhc-blackpill/Main.hs";
char jhc_version[] = "jhc 0.8.2 (mydniquipepo-32)";

#include "jhc_rts_header.h"
#include <libopencm3/stm32/gpio.h>
#include <mylib.h>


void jhc_hs_init(void) ;
void _amain(void) ;
static void b__main(gc_t gc) A_STD;
static void ftheMain(gc_t gc) A_STD;
/* CAFS */

const void * const nh_stuff[] = {
NULL
};


void 
jhc_hs_init(void)
{
}

void 
_amain(void)
{
        return (void)b__main(saved_gc);
}

static void A_STD
b__main(gc_t gc)
{
        return ftheMain(gc);
}

static void A_STD
ftheMain(gc_t gc)
{
        saved_gc = gc;
        uint32_t v24 = ((uint32_t)gpioB());
        saved_gc = gc;
        uint16_t v168 = ((uint16_t)gpio12());
        saved_gc = gc;
        (void)gpio_setup();
        fx59774543__2:;
        {   saved_gc = gc;
            (void)wait((unsigned)200000);
            saved_gc = gc;
            (void)gpio_clear((uint32_t)v24,(uint16_t)v168);
            saved_gc = gc;
            (void)wait((unsigned)200000);
            saved_gc = gc;
            (void)gpio_set((uint32_t)v24,(uint16_t)v168);
            goto fx59774543__2;
        }
        return;
}
