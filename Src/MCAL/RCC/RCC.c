/**
 ******************************************************************************
 * @file           : RCC.c
 * @author         : Ahmed Abdalla
 * @brief          : Contains Program of RCC and memory map
 * @date		   : 06 Dec 2023 
 ******************************************************************************
 */



/******************** Include Start **********************/
#include "../../../Inc/MCAL/RCC/RCC.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/
/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/
typedef struct
{
    volatile uint_32 RCC_CR_Reg;
    volatile uint_32 RCC_PLLCFGR_Reg;
    volatile uint_32 RCC_CFGR_Reg;
    volatile uint_32 RCC_CIR_Reg;
    volatile uint_32 RCC_AHB1RSTR_Reg;
    volatile uint_32 RCC_AHB2RSTR_Reg;
    volatile uint_32 RCC_AHB3RSTR_Reg;
    uint_32 Rserved0;
    volatile uint_32 RCC_APB1RSTR_Reg;
    volatile uint_32 RCC_APB2RSTR_Reg;
    uint_32 Rserved1[2];
    volatile uint_32 RCC_AHB1ENR_Reg;
    volatile uint_32 RCC_AHB2ENR_Reg;
    volatile uint_32 RCC_AHB3ENR_Reg;
    uint_32 Rserved2;
    volatile uint_32 RCC_APB1ENR_Reg;
    volatile uint_32 RCC_APB2ENR_Reg;
    uint_32 Rserved3[2];
    volatile uint_32 RCC__AHB1LPENR_Reg;
    volatile uint_32 RCC__AHB2LPENR_Reg;
    volatile uint_32 RCC__AHB3LPENR_Reg;
    uint_32 Rserved4;
    volatile uint_32 RCC_APB1LPENR_Reg;
    volatile uint_32 RCC_APB2LPENR_Reg;
    uint_32 Rserved5[2];
    volatile uint_32 RCC_BDCR_Reg;
    volatile uint_32 RCC_CSR_Reg;
    uint_32 Rserved6[2];
    volatile uint_32 RCC_SSCGR_Reg;
    volatile uint_32 RCC_PLLI2SCFGR_Reg;

}RCC_t;
/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
/******************** Software Interfaces Declarations End   **********************/


#endif /*MCAL_RCC_H_*/