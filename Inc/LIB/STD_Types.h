/**
 ******************************************************************************
 * @file           : STD_Types
 * @author         : Ahmed Abdalla
 * @brief          : this file contains data type defintions for potability
 * @date		   : 16 Dec 2023 
 ******************************************************************************
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#define NULL (void *) 0UL

typedef unsigned char	uint_8;
typedef unsigned short 	uint_16;
typedef unsigned int 	uint_32;

typedef signed char 	sint_8;
typedef signed short 	sint_16;
typedef signed int 		sint_32;

typedef float 			f32;
typedef double 			f64;

typedef enum STD_Return
{
	Not_OK = 0,
	OK,
}STD_Return_t;


#endif	/* STD_TYPES_H */
