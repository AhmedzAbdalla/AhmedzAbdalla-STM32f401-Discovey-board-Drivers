/**
 ******************************************************************************
 * @file           : BIT_MATH.h
 * @author         : Ahmed Abdalla
 * @brief          : this file contains some bitmath operation
 * @date		   : 16 Dec 2023 
 ******************************************************************************
 */

#ifndef HEADER_FILES_BIT_MATH_H_
#define HEADER_FILES_BIT_MATH_H_

#define BIT_MASK 1UL

#define SET_BIT(REG , POS) 	 	(REG|=(1<<POS))
#define CLR_BIT(REG , POS)  	(REG&=(~(1<<POS)))
#define Toggle_BIT(REG , POS)   (REG^=(1<<POS))
#define READ_BIT(REG , POS) 	((REG>>POS) & BIT_MASK)

#define SET_BIT(REG , POS) 	 	(REG|=(1<<POS))
#define CLR_BIT(REG , POS)  	(REG&=(~(1<<POS)))
#define Toggle_BIT(REG , POS)   (REG^=(1<<POS))
#define READ_BIT(REG , POS) 	((REG>>POS) & BIT_MASK)

#endif /* HEADER_FILES_BIT_MATH_H_ */
