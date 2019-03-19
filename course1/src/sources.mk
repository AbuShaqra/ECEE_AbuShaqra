#******************************************************************************
# Copyright (C) 2019 by Albara Abu Shaqra
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Albara Abu Shaqra is not liable for any misuse of this material. 
#
#*****************************************************************************

# Add your Source files to this variable

MSP_SOURCES = main.c                       \
          memory.c                         \
          course1.c                        \
          data.c                           \
	  stats.c                          \
          interrupts_msp432p401r_gcc.c     \
          startup_msp432p401r_gcc.c        \
          system_msp432p401r.c

HOST_SOURCES = main.c                       \
          memory.c                         \
          course1.c                        \
          data.c                           \
	  stats.c                                               

         

# Add your include paths to this variable

MSP_INCLUDES = -I../include/common -I../include/msp432 -I../include/CMSIS



HOST_INCLUDES = -I../include/common -I../include/CMSIS



