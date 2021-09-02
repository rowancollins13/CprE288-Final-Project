/*
*
*   uart.c
*
*
*
*   @author
*   @date
*/

#include <inc/tm4c123gh6pm.h>
#include <stdint.h>
#include "uart.h"

// UART1 device initialization for CyBot to PuTTY
void uart_init(void){
	//TODO
  //enable clock to GPIO port B
  SYSCTL_RCGCGPIO_R |= 0b10;

  //enable clock to UART1
  SYSCTL_RCGCUART_R |= 0b10;

  //wait for GPIOB and UART1 peripherals to be ready
  long delay = SYSCTL_PRGPIO_R;

  //enable alternate functions on port B pins
  GPIO_PORTB_AFSEL_R |= 0x3;

  //enable digital functionality on port B pins
  GPIO_PORTB_DEN_R |= 0x3;

  //enable UART1 Rx and Tx on port B pins
  GPIO_PORTB_PCTL_R = 0x11;
  GPIO_PORTB_PCTL_R &= 0xFFFFFF11;

  //calculate baud rate
  uint16_t iBRD = 8; //use equations
  uint16_t fBRD = 44; //use equations

  //turn off UART1 while setting it up
  UART1_CTL_R &= ~0x1;

  //set baud rate
  //note: to take effect, there must be a write to LCRH after these assignments
  UART1_IBRD_R = iBRD;
  UART1_FBRD_R = fBRD;

  //set frame, 8 data bits, 1 stop bit, no parity, no FIFO
  //note: this write to LCRH must be after the BRD assignments
  UART1_LCRH_R = 0x60;

  //use system clock as source
  //note from the datasheet UARTCCC register description:
  //field is 0 (system clock) by default on reset
  //Good to be explicit in your code
  UART1_CC_R = 0x0;

  //re-enable UART1 and also enable RX, TX (three bits)
  //note from the datasheet UARTCTL register description:
  //RX and TX are enabled by default on reset
  //Good to be explicit in your code
  //Be careful to not clear RX and TX enable bits
  //(either preserve if already set or set them)
  UART1_CTL_R = 0x301;

}

// Send a byte over UART1 from CyBot to PuTTY
void uart_sendChar(char data){
	while (UART1_FR_R & 0x20)
	{

	}
	UART1_DR_R = data;
}

// CyBot waits (i.e. blocks) to receive a byte from PuTTY
// returns byte that was received by UART1
char uart_receive(void){
	char data;
	while (((UART1_FR_R & 0x10) >> 4) == 1)
	{

	}
	data = (char)(UART1_DR_R & 0xFF);
	return data;
}

// CyBot recieves a byte from PuTTY
// returns byte that was received by UART1 or a null character
char uart_receive_nonblocking(void){
    char data;
    if (((UART1_FR_R & 0x10) >> 4) == 1)
        data = (char)0;
    else
        data = (char)(UART1_DR_R & 0xFF);
    return data;
}

// Send a string over UART1
// Sends each char in the string one at a time
void uart_sendStr_A(const char *data){
	int i = 0;
	while (data[i] != '\0')
	{
	    uart_sendChar(data[i]);
	    i++;
	}
}
