#include <stdio.h>
#include <stdint.h>

#define SYSCTL_BASE 0x20000000
#define GPIO_BASE 0x40025000

#define SYSCTL_RCGC2_R    *(volatile unsigned long *)(SYSCTL_BASE+0x108)	//enable the gpio port
#define GPIO_PORTF_DIR_R  *(volatile unsigned long *)(GPIO_BASE+0x3FC)	//diection inpu or output 
#define GPIO_PORTF_DEN_R  *(volatile unsigned long *)(GPIO_BASE+0x400) 	//enable gpio pin
#define GPIO_PORTF_DATA_R *(volatile unsigned long *)(GPIO_BASE+0x51C)	//the data to be written on pin

int main(void){

	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x00000020;
		for(delay_count=0;delay_count<200;delay_count++);
	GPIO_PORTF_DIR_R |= 1<<3;
	GPIO_PORTF_DEN_R |= 1<<3;
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_count=0;delay_count<200000;delay_count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_count=0;delay_count<200000;delay_count++);
	}
return 0;
}