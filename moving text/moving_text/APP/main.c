/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "DIO.h"
#include "LCD.h"
#include "REG.h"
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{   u8 v = 1 ;
	LCD_INIT();
	u8 text[17] = "DRESS";
	u8 i = 0 ;
	while ( text[i] != '\0'){
		i ++ ;
	}
	u8 save = i ;
	u8 check = 16 - i ;
	while (1){
		LCD_CLEAR();
		if (v >= check ){
			for ( u8 j = i ; j <=save+1 ; j++ ){
				LCD_WRITE_CHR(text[j]);
			}
			i--;
		}
		for ( int i = 1 ; i <v ; i++){
		LCD_WRITE_CMD(0x14);
		}

		LCD_WRITE_STR(text);
		_delay_ms(2000);
		v +=1 ;
		if (v > 17){
			v = 1 ;
			i = save ;
		}
	}

    return 0;
}






