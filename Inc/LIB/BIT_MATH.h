/**
 ******************************************************************************
 * @file           : BIT_MATH.h
 * @author         : Ahmed Abdalla
 * @brief          : this file contains some bitmath operation
 * @date		   : 16 Nov 2023 
 ******************************************************************************
 */

#ifndef HEADER_FILES_BIT_MATH_H_
#define HEADER_FILES_BIT_MATH_H_

#define BIT_MASK 1UL

#define SET_BIT(REG , POS) 	 	(REG|=(1<<POS))
#define CLR_BIT(REG , POS)  	(REG&=(~(1<<POS)))
#define Toggle_BIT(REG , POS)   (REG^=(1<<POS))
#define READ_BIT(REG , POS) 	((REG>>POS) & BIT_MASK)

#define READ_REG(REG)       ((REG))
#define WRITE_TEG(REG,VAL)  ((REG) = (VAL))

#define MODIFY_REG(REG,CLR_MSK,SET_MSK) WRITE_TEG((REG) , (((READ_REG(REG)) & (~(CLR_MSK))) | SET_MSK))


#endif /* HEADER_FILES_BIT_MATH_H_ */
