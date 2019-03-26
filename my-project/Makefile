# put your *.o targets here, make should handle the rest!
SRCS = main.c errno.c hs_main.c alloc.c dummy4jhc.c

# all the files will be generated with this name (main.elf, main.bin, main.hex, etc)
PROJ_NAME=main

JHCRTS=jhc_custom
JHCRTS_LIB=$(JHCRTS)/rts
JHCRTS_SRC=$(JHCRTS)/rts/src

# TODO - you will need to edit these two lines!
DEVICE= stm32f401re
CHIP = STM32F4

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=./libopencm3

# that's it, no need to change anything below this line!

###################################################

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump
SIZE=arm-none-eabi-size
GDB=arm-none-eabi-gdb
AR=arm-none-eabi-ar

CFLAGS  = -Wall -g -std=gnu99 -O
CFLAGS += -mlittle-endian -mcpu=cortex-m4  -march=armv7e-m -mthumb
CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Wl,--gc-sections -Wl,-Map=$(PROJ_NAME).map
CFLAGS += -Wl,--defsym,jhc_zeroAddress=0

CFLAGS += -ffreestanding -nostdlib
CFLAGS += -D_LITTLE_ENDIAN
CFLAGS += -D_JHC_ARM_STAY_IN_THUMB_MODE
CFLAGS += -D_JHC_JGC_STACKGROW=16 -D_JHC_JGC_LIMITED_NUM_MEGABLOCK=3
CFLAGS += -D_JHC_JGC_BLOCK_SHIFT=8 -D_JHC_JGC_MEGABLOCK_SHIFT=13
CFLAGS += -D_JHC_JGC_GC_STACK_SHIFT=8 -D_JHC_JGC_LIMITED_NUM_GC_STACK=2
CFLAGS += -D_JHC_JGC_NAIVEGC -D_JHC_JGC_SAVING_MALLOC_HEAP
CFLAGS += -D_JHC_CONC=_JHC_CONC_CUSTOM

vpath %.c src
vpath %.a $(OPENCM3_DIR)

ROOT=$(shell pwd)

CFLAGS += -I inc 
CFLAGS += -I $(OPENCM3_DIR)
CFLAGS += -I . -I $(JHCRTS)
CFLAGS += -DNDEBUG -D_JHC_GC=_JHC_GC_JGC -D_JHC_STANDALONE=0

# SRCS += Device/startup_stm32f30x.s # add startup file to build

# need if you want to build with -DUSE_CMSIS 
#SRCS += stm32f0_discovery.c
#SRCS += stm32f0_discovery.c stm32f0xx_it.c

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: all clean proj

all: jhcrts proj

jhcrts: hs_main.c
	$(MAKE) -C $(JHCRTS_LIB)

hs_main.c: hs_src/Main.hs
	jhc -v -fffi --tdir=$(JHCRTS) -C --include=hs_src -o $@ $<

proj: 	$(PROJ_NAME).elf

$(PROJ_NAME).elf: $(OBJS) $(LDSCRIPT)
	$(CC) $(CFLAGS) $^ -o $@ -L$(OPENCM3_DIR) -L$(JHCRTS_LIB) -ljhcrts -T$(LDSCRIPT) -D$(CHIP)
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin
	$(OBJDUMP) -St $(PROJ_NAME).elf >$(PROJ_NAME).lst
	$(SIZE) $(PROJ_NAME).elf

clean:
	find ./ -name '*~' | xargs rm -f	
	rm -f *.o hs_main.c *.symlist
	rm -f $(PROJ_NAME).elf
	rm -f $(PROJ_NAME).hex
	rm -f $(PROJ_NAME).bin
	rm -f $(PROJ_NAME).map
	rm -f $(PROJ_NAME).lst
	rm -f $(LDSCRIPT)
	$(MAKE) -C $(JHCRTS_LIB) clean

include $(OPENCM3_DIR)/mk/genlink-config.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
