/*
 * P_B.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "P_B_CFG.h"
#include "DIO.h"
#include <util/delay.h>

void P_B_INIT(void)
{
	DIO_PIN_DIRECTION(P_B_PORT,UP,INPUT);
	DIO_PIN_WRITE(P_B_PORT,UP,HIGH);

	DIO_PIN_DIRECTION(P_B_PORT,DOWN,INPUT);
	DIO_PIN_WRITE(P_B_PORT,DOWN,HIGH);

	DIO_PIN_DIRECTION(P_B_PORT,LEFT,INPUT);
	DIO_PIN_WRITE(P_B_PORT,LEFT,HIGH);

	DIO_PIN_DIRECTION(P_B_PORT,RIGHT,INPUT);
	DIO_PIN_WRITE(P_B_PORT,RIGHT,HIGH);
}
u8 P_B_READ(u8 pin)
{
	u8 value = 0;
	value = DIO_PIN_READ(P_B_PORT,pin);
	return value;
}
u8 P_B_READ_ALL(void){
		u8 ret_value =0 ;
		u8 x = 1 ;
		x = P_B_READ(UP);
		if (x == 0 ) {
			_delay_ms(150);
			x = P_B_READ(UP);
			if(x == 0){
			ret_value = 1 ;
			}
		}
		/**************************/
		x = P_B_READ(DOWN);
		if (x == 0 ) {
			_delay_ms(150);
			x = P_B_READ(DOWN);
			if(x == 0){
			ret_value = 2 ;
		}
		}
		/**************************/
		x = P_B_READ(LEFT);
		if (x == 0 ) {
			_delay_ms(150);
			x = P_B_READ(LEFT);
			if(x == 0){
			ret_value = 3;
			}
		}
		/*************************/
		x = P_B_READ(RIGHT);
		if (x == 0 ) {
			_delay_ms(150);
			x = P_B_READ(RIGHT);
			if(x == 0){
			ret_value = 4 ;
			}
		}
		/************************/
		return ret_value ;
}
