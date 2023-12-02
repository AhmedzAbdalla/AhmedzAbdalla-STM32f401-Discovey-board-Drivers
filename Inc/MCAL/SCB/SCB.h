/**
 ******************************************************************************
 * @file           : SCB.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains declaration of SCB and memory map
 * @date		   : 02 Dec 2023 
 ******************************************************************************
 */
#ifndef MCAL_ٍSCB_SCB_H_
#define MCAL_ٍSCB_SCB_H_

/******************** Include Start **********************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/
#define SCB_Base        0xE000ED00
#define SCB             ((SCB_t *)SCB_Base)

#define SCB_PRIORITY_GROUP_0    0x7UL   /* 0 bits for Group Priorities */
                                        /* 4 bits for Subpriority bits   */  
#define SCB_PRIORITY_GROUP_1    0x6UL   /* 1 bits for Group Priorities */
                                        /* 3 bits for Subpriority bits   */  
#define SCB_PRIORITY_GROUP_2    0x5UL   /* 2 bits for Group Priorities */
                                        /* 2 bits for Subpriority bits   */  
#define SCB_PRIORITY_GROUP_3    0x4UL   /* 3 bits for Group Priorities */
                                        /* 1 bits for Subpriority bits   */  
#define SCB_PRIORITY_GROUP_4    0x3UL   /* 4 bits for Group Priorities */
                                        /* 0 bits for Subpriority bits   */  

#define SCB_AIRCR_PRIORITY_GROUP_POS    8UL
#define SCB_AIRCR_PRIORITY_GROUP_MSK    (0x7UL << SCB_AIRCR_PRIORITY_GROUP_POS)


#define SCB_AIRCR_VECTKEY       0x05FAUL
#define SCB_AIRCR_VECTKEY_POS   16UL
#define SCB_AIRCR_VECTKEY_MSK   (0xFFFFUL << SCB_AIRCR_VECTKEY_POS )
/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/
typedef struct
{
    volatile uint_32 CPUID;
    volatile uint_32 ICSR;
    volatile uint_32 VTOR;
    volatile uint_32 AIRCR;
    volatile uint_32 SCR;
    volatile uint_32 CCR;
    volatile uint_32 SHPR1;
    volatile uint_32 SHPR2;
    volatile uint_32 SHPR3;
    volatile uint_32 SHCSR;
    volatile uint_32 CFSR;
    volatile uint_32 MMSR;
    volatile uint_32 BFSR;
    volatile uint_32 UFSR;
    volatile uint_32 HFSR;
    volatile uint_32 MMAR;
    volatile uint_32 BFAR;
    volatile uint_32 AFSR;

}SCB_t;
/******************** Data Type Declarations End **********************/

/******************** Software Interfaces Declarations Start **********************/
void SCB_Set_Priority_Group(uint_32 Priority_Group );

/******************** Software Interfaces Declarations End **********************/


#endif /* MCAL_ٍSCB_SCB_H_ */
