CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
AsOBJ= $(AS:.s=.o)

all: learn-in-depth.bin

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 2> log
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	arm-none-eabi-ld.exe -T   linkerScript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm -rf *.o .hex *~
	@echo "============CLEAN============"
