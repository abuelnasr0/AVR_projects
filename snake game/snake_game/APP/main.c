/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "DIO.h"
#include "LED.h"
#include "LCD.h"

#include "P_B.h"
#include "REG.h"
#include <avr/interrupt.h>
#include <util/delay.h>

u8 v = 1 ;
u8 h = 0 ;
int main(void)
{
	LCD_INIT();
	P_B_INIT();
	LCD_WRITE_CHR('-');
	u8 check_value = 0 ;
    while(1)
    {
    	while(1){
    	check_value = P_B_READ_ALL();
    	if (check_value != 0 ){
    			break;
    	}
    	}
    	switch(check_value){
    	case 1 :
    		while(1){
    		LCD_CLEAR();
    		if ( h == 1 ){
				LCD_WRITE_CMD(0xC0);
				for ( int i = 1 ; i <v ; i++){
				LCD_WRITE_CMD(0x14);}
			}
    		else if ( h == 0 ){
				LCD_WRITE_CMD(0x80);
				for ( int i = 1 ; i <v ; i++){
				LCD_WRITE_CMD(0x14);}
			}
    		LCD_WRITE_CHR('|');
    		_delay_ms(1000);
    		h ++ ;
    		if (h > 1 )  {h = 0; }
    		if (P_B_READ_ALL() == 4  || P_B_READ_ALL() == 3 || P_B_READ_ALL() == 2  )   {   break ;   }
    		 }
    		break;
    	case 2 :
    		while(1){
			LCD_CLEAR();
			if ( h == 1 ){
				LCD_WRITE_CMD(0xC0);
				for ( int i = 1 ; i <v ; i++){
				LCD_WRITE_CMD(0x14);}
			}
			else if ( h == 0 ){
				LCD_WRITE_CMD(0x80);
				for ( int i = 1 ; i <v ; i++){
				LCD_WRITE_CMD(0x14);}
			}
			LCD_WRITE_CHR('|');
			_delay_ms(1000);
			h ++ ;
			if (h > 1 )  {h = 0; }
			if (P_B_READ_ALL() == 4  || P_B_READ_ALL() == 1 || P_B_READ_ALL() == 3  )   {   break ;   }
			 }
    		break;
    	case 3 :
    		while (1){
			LCD_CLEAR();
			if (h == 1 ){
				LCD_WRITE_CMD(0xC0);
			}
			for ( int i = 1 ; i <v ; i++){
			LCD_WRITE_CMD(0x14);
			}
			v -=1;
			LCD_WRITE_CHR('-');
			_delay_ms(1000);
			if ( v < 1)   {   v = 16 ;   }
			if (P_B_READ_ALL() == 4  || P_B_READ_ALL() == 1 || P_B_READ_ALL() == 2  )   {   break ;   }
			}
    		break;
    	case 4 :
    		while (1){
    		LCD_CLEAR();
    		if (h == 1 ){
				LCD_WRITE_CMD(0xC0);
			}
    		for ( int i = 1 ; i <v ; i++){
    		LCD_WRITE_CMD(0x14);
    		}
    		v +=1;
			LCD_WRITE_CHR('-');
			_delay_ms(1000);
			if ( v > 17)   {   v = 1 ;   }
			if (P_B_READ_ALL() == 3  || P_B_READ_ALL() == 1 || P_B_READ_ALL() == 2  )   {   break ;   }
    		}
    		break;
    	default :
    		break ;
    	}

    }
    return 0;
}













ISR(INT0_vect)
{

}

ISR(TIMER0_OVF_vect)
{

}
ISR(TIMER0_COMP_vect)
{

}
ISR(TIMER1_COMPA_vect)
{
LED_ON();
}
