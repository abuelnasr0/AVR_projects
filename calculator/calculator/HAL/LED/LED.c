/*
 * LED.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */


/*
 * LED.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#include "DIO.h"
#include "LED_CFG.h"
void LED_INIT(void)
{

	DIO_PIN_DIRECTION(LED_PORT,LED_PIN,OUTPUT);
	DIO_PIN_DIRECTION(LED_PORT,LED_PIN_BLUE,OUTPUT);
	DIO_PIN_DIRECTION(LED_PORT,LED_PIN_GREEN,OUTPUT);


}
void LED_ON(void)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,HIGH);

}
void LED_OFF(void)
{

	DIO_PIN_WRITE(LED_PORT,LED_PIN,LOW);

}
void LED_TOG(void)
{
	DIO_PIN_TOG(LED_PORT,LED_PIN);
}
void LED_TOG_BLUE(void)
{
	DIO_PIN_TOG(LED_PORT,LED_PIN_BLUE);
}
void LED_TOG_GREEN(void)
{
	DIO_PIN_TOG(LED_PORT,LED_PIN_GREEN);
}
