include sources.mk
-include $(OBJS:.o=.d)

TARGET= c1m2.out
PLATFORM = MSP432

        LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS = nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=main.map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) $(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DMSP432

        OBJS = $(SOURCES:.c=.o)
        INCLUDES = $(MSP_INCLUDES)

.PHONY: build
build: $(TARGET) $(size)
size= arm-none-eabi-size -Atd c1m2.out

c1m2.out: $(OBJS)
	  $(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS)  -o  $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *.map *.i *.asm *.d

