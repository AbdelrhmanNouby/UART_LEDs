/*
 * STRING.c
 *
 * Created: 1/15/2022 8:47:31 PM
 *  Author: Abdelrhman Elsawy
 */

#include "STRING.h"

uint8_t Compare_Str (uint8_t * str1,uint8_t * str2)
{
	while ( *str1 == *str2 )
	{
		if (( *str1 == '\0' ) || ( *str2 == '\0' ))
		break ;
		str1++ ;
		str2++ ;
	}
	if (( *str1 == '\0' ) && ( *str2 == '\0' ))
	return 1 ;
	else
	return 0 ;
}

uint8_t arrBits_toInt ( uint8_t * arrBits,uint16_t * integer)
{
	uint8_t state = 0 ;
	*integer = 0 ;
	while ( *arrBits != '\0')
	{
		if (( *arrBits != '1') && ( *arrBits != '0'))
		{
			state = 1 ;
			break ;
		}
		integer += ( 10 * (*arrBits) ) ;
		arrBits++ ;
	}
	return state ;
}