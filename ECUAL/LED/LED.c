/*
 * Led.c
 *
 * Created: 1/10/2022 12:27:19 AM
 *  Author: Abdelrhman Elsawy
 */ 


#include "../../MCAL/DIO/DIO.h"
#include "LED.h"
#include "LED_ERR_HANDLE.h"

// function to initialize LED 
uint8_t LED_u8Init ( LED_t led )
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// set direction of LED's pin
	u8ErrorState = DIO_u8SetPinDirection(led.port,led.pin,OUTPUTPIN);
	// error Checking 
	if ( u8ErrorState == SetPinData_Error )
		u8ErrorState = LED_Init_Error ;
		
	return u8ErrorState ;	
}

// function to turn LED on 
uint8_t LED_u8On ( LED_t led )
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// set LES's pin state to HIGH
	u8ErrorState = DIO_u8SetPinData(led.port,led.pin,HIGH);
	// error Checking 
	if ( u8ErrorState == SetPinData_Error )
		u8ErrorState = LED_On_Error ;
		
	return u8ErrorState ;
}

// function to turn LED off
uint8_t LED_u8Off ( LED_t led )
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// set LES's pin state to LOW 
	u8ErrorState = DIO_u8SetPinData(led.port,led.pin,LOW);
	// error Checking 
	if ( u8ErrorState == SetPinData_Error )
		u8ErrorState = LED_Off_Error ;
		
	return u8ErrorState ;
}

// function to toggle LED state 
uint8_t LED_u8Toggle ( LED_t led )
{
	uint8_t u8ErrorState = STD_TYPES_OK ;
	// toggle pin state 
	u8ErrorState = DIO_u8TogglePinData(led.port,led.pin);
	// error Checking 
	if ( u8ErrorState == TogglePinData_Error )
		u8ErrorState = LED_Toggle_Error ;
		
	return u8ErrorState ;
}
