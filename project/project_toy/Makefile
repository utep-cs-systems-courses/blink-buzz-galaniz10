# makfile configuration
COMMON_OBJECTS  = switches.o led.o p1_interrupt_handler.o buttonMain.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf modular_s.elf modular_c.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} buttonMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

modular_s.elf: ${COMMON_OBJECTS} assembly.s
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *.c~ *.h~ *.s~

load_s: modular_s.elf
	msp430loader.sh $^

buttonMain.o: led.h

led.o: led.h

switches.o: led.h

assembly_s.o: assembly_s.c led.h

p1_interrupt_handler.o: p1_interrupt_handler.c

