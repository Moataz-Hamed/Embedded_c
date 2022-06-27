#include <stdio.h>
#include "uart.h"
unsigned char stringBuffer[100]="learn-in-depth:<Moataz>";

void main(void){

	Uart_send_string(stringBuffer);
}