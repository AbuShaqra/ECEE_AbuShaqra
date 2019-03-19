#******************************************************************************
# Copyright (C) 2019 by Albara Abu Shaqra
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Albara Abu Shaqra is not liable for any misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <FILE>.o - Builds <FILE>.o object file
#       <FILE>.i - Builds <FILE>.i preprocessed file
#       <FILE>.asm - Builds <FILE>.asm assembly file
#       compile-all - compile all object files without linking
#       build - Builds and links all source files
#       clean - removes all generated files
#
# Platform Overrides:
#       PLATFORM - the target platform (MSP432 or HOST)
#
#------------------------------------------------------------------------------
include sources.mk
-include $(OBJS:.o=.d)

# Platform Overrides

PLATFORM = MSP432
TARGET= final.out
VERBOSE = DISABLE
COURSE  = COURSE 

ifeq ($(VERBOSE),ENABLE)
  CPPFLAGS += -DVERBOSE
endif

ifeq ($(COURSE),COURSE1)
  CPPFLAGS += -DCOURSE1
endif

ifeq ($(PLATFORM),MSP432)
	# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU = cortex-m4
	ARCH = -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS = nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=main.map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) $(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DMSP432
        SIZE = arm-none-eabi-size
        OBJS = $(MSP_SOURCES:.c=.o)
        INCLUDES = $(MSP_INCLUDES)


else ifeq ($(PLATFORM),HOST)

	# Compiler Flags and Defines
	CC = gcc
	LD = ld
	LDFLAGS = -Wl,-Map=main.map -T $(LINKER_FILE)
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST
        SIZE = arm-none-eabi-size
        OBJS = $(HOST_SOURCES:.c=.o)
        INCLUDES = $(HOST_INCLUDES)
else 

@echo "Platform not supported!"

endif 



%.i : %.c
	$(CC) -E $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

%.asm : %.c
	$(CC) -S $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@

%.o : %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $< -o $@
	$(CC) -MM $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $*.c > $*.d

.PHONY: compile-all
compile-all: $(CC) -c $(OBJS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -o $@

.PHONY: build
build: $(TARGET)

final.out: $(OBJS)
	  $(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LDFLAGS)  -o  $@
	  $(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *.map *.i *.asm *.d

