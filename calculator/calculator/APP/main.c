/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


#include "DIO.h"
#include "LED.h"
#include "LCD.h"
#include "S_SEG.h"
#include "KEY_PAD.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "INT.h"
u32 char_to_int(u8  );
int main(void)
{
	KEY_PAD_INIT();
	LCD_INIT();
	LED_INIT();
	u8 i = 0 ;
	u8 x = 0 ;
	u8 arr[60];
	u32 numbers [15];
	u8 operator[15];
	u8 num_arr_count =0 ;
	u8 op_count=0 ;
	while(1)
	{	x = KEY_PAD_READ();
		if( x != 0)
		{	LCD_WRITE_CHR(x);
			arr[i] = x ;
			i++ ;
			if ( x == '=' ){
				u8 check = -1 ;
				u8 j  ;
				for (j = 0 ; j < i ; j++ ){
					LED_TOG_BLUE();
					if (arr[j] == '+' || arr[j] == '-' || arr[j] == '*' || arr[j] == '/' || arr[j] =='=' ){
						u32 c = 0 ;
						u32 mult = 1 ;
						u8 a = j-1;
						while (a != check){
							LED_TOG();
							u32 num = char_to_int(arr[a]);
							u32 nom2 = num*mult ;
							c = c + nom2 ;
							mult = mult * 10 ;
							a = a-1;
						}
						check = j ;
						numbers[num_arr_count] = c ;
						num_arr_count =num_arr_count+ 1;
						operator[op_count] = arr[j] ;
						op_count = op_count + 1;
					}
				}
				u8 v ;
				for ( v = 0 ; v < num_arr_count-1 ; v++){
						LED_TOG_GREEN();
						u32 res ;
						switch (operator[v]){
						case '+':
							res = numbers[v] + numbers[v+1] ;
							break ;
						case '-':
							res = numbers[v] - numbers[v+1] ;
							break ;
						case '*':
							res = numbers[v] * numbers[v+1] ;
							break ;
						case '/':
							res = numbers[v] / numbers[v+1] ;
							break ;
						}
						numbers[v+1] = res ;
				}
				LCD_WRITE_INT(numbers[num_arr_count-1]);
				_delay_ms(1000);
				i = 0 ;
				num_arr_count = 0;
			}
		}
	}
}
/*
ISR(INT0_vect){
	LED_TOG();
}*/
u32 char_to_int(u8 x ){
	u32 y = x - 48 ;
	return y ;
}
