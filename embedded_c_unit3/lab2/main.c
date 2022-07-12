#include <stdio.h>
#include <stdint.h>

#define Rcc_base 0x40021000
#define GPIO_Base 0x40010800
#define Rcc_R *(volatile unsigned int *) (Rcc_base+0x18)
#define CHR_R *(volatile volatile unsigned int *) 	 (GPIO_Base+0x04)
#define ODR_R *(volatile volatile unsigned int *) 	 (GPIO_Base+0x0C)
#define RCC_IOPAEN (1<<2)
#define GPIOA13 (1UL<<13)

typedef union {
	volatile unsigned int allfield;
	struct{
		volatile unsigned int reserved:13;
		volatile unsigned int p_13:1;
	}pin;
}ODR_R_P13;
volatile ODR_R_P13* R_ODR = (volatile ODR_R_P13*) (GPIO_Base+0x0C);

void main(void){

	Rcc_R |= RCC_IOPAEN;
	CHR_R &= 0xff0fffff;
	CHR_R |= 0x00200000;
	while(1){
		R_ODR->pin.p_13 =1;
		for(int i=0; i<5000;i++)
		R_ODR->pin.p_13=0;
		for(int i=0;i<5000;i++);
	}


}