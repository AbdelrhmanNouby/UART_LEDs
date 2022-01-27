/*
 * UART_LEDs.c
 *
 * Created: 1/27/2022  
 * Author : Abdelrhman Elsawy
 */

#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/UART/UART.h"
#include "../ECUAL/LED/LED.h"
#include "../LIB/STRING.h"

LED_t led1 = {PORTB,PIN4};					// Green LED configuration 
LED_t led2 = {PORTB,PIN6};					// Red LED configuration
LED_t led3 = {PORTB,PIN5};					// Yellow LED configuration
	
int main (void)
{
	UART_u8Init();						// initialize UART comm
	TIMER0_u8Init();					// initialize TIMER0 to  use delay 
	LED_u8Init(led1);					// initialize Green LED
	LED_u8Init(led2);					// initialize Red LED
	LED_u8Init(led3);					// initialize Yellow LED
	uint8_t R_Str [256] ;						// array to contain Received string 
	uint8_t WAIT_Str [] = {"WAIT"}  ;			// wait string
	uint8_t AT_Str [] = {"AT"}  ;				// AT string
	uint8_t START_Str [] = {"START"}  ;			// start string
	uint8_t STOP_Str [] = {"STOP"}  ;			// stop string 
	
	while(1)
	{
		UART_u8ReceiveString(R_Str);					// receive string from terminal 
		if ( Compare_Str (R_Str,START_Str))				
		{
			LED_u8On(led1);
			LED_u8Off(led2);
			LED_u8Off(led3);
			UART_u8SendString("Green LED is on");
			UART_u8SendByte(NEWLINE);
		}
		else if ( Compare_Str (R_Str,STOP_Str))
		{
			LED_u8Off(led1);
			LED_u8On(led2);
			LED_u8Off(led3);
			UART_u8SendString("Red LED is on");
			UART_u8SendByte(NEWLINE);
		}
		else if ( Compare_Str (R_Str,WAIT_Str))
		{
			LED_u8Off(led1);
			LED_u8Off(led2);
			LED_u8On(led3);
			UART_u8SendString("Yellow LED is on");
			UART_u8SendByte(NEWLINE);
		}
		else if ( Compare_Str (R_Str,AT_Str))
		{
			UART_u8SendString("OK");
			UART_u8SendByte(NEWLINE);
		}
		else
		{
			UART_u8SendString("Wrong Input");
			UART_u8SendByte(NEWLINE);
		}		
	}
}

