/*
 * BIT_MATH.h
 *
 *  Created on: ???/???/????
 *      Author: dell
 */

#ifndef APP_LIB_BIT_MATH_H_
#define APP_LIB_BIT_MATH_H_

#define SET_BIT(REG,BIT)       (REG = REG  | (1 << BIT))
#define CLR_BIT(REG,BIT)       (REG = REG   & (~(1 << BIT)))
#define TOG_BIT(REG,BIT)       (REG =  REG ^ (1 << BIT))
#define GET_BIT(REG,BIT)       ((REG>>BIT)  &1    )

#endif /* APP_LIB_BIT_MATH_H_ */
