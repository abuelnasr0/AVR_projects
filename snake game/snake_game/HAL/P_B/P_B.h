/*
 * P_B.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef HAL_P_B_P_B_H_
#define HAL_P_B_P_B_H_

#include "STD_TYPES.h"
#include "P_B_CFG.h"


void P_B_INIT(void);
u8 P_B_READ(u8 pin);
u8 P_B_READ_ALL(void);
#endif /* HAL_P_B_P_B_H_ */
