CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
AsOBJ= $(AS:.s=.o)

all: learn-in-depth.bin
	@echo "==================Build is Done==================="

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	arm-none-eabi-ld.exe -T   liker_script.ld  $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	cp learn-in-depth.elf learn-in-depth.axf

learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm -rf *.o .hex *~
	@echo "============CLEAN============"
