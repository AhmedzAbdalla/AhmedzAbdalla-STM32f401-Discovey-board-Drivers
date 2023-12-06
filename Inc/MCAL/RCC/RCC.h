/**
 ******************************************************************************
 * @file           : RCC.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains declaration of RCC and memory map
 * @date		   : 06 Dec 2023 
 ******************************************************************************
 */

#ifndef MCAL_RCC_H
#define MCAL_RCC_H

/******************** Include Start **********************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/
#define RCC                     ((RCC_t *)(0x40023800))

#define CLOCK_GPIOA             0UL
#define CLOCK_GPIOB             1UL
#define CLOCK_GPIOC             2UL
#define CLOCK_GPIOD             3UL
#define CLOCK_GPIOE             4UL
#define CLOCK_GPIOF             5UL
#define CLOCK_GPIOG             6UL
#define CLOCK_GPIOH             7UL
#define CLOCK_GPIOI             8UL
#define CLOCK_CRC               12UL
#define CLOCK_FLITF             15UL
#define CLOCK_SRAM_1            16UL
#define CLOCK_SRAM_2            17UL
#define CLOCK_BKPSRAM           18UL
#define CLOCK_DMA1              21UL
#define CLOCK_DMA2              22UL
#define CLOCK_ETHMAC            25UL
#define CLOCK_ETHTX             26UL
#define CLOCK_ETHRX             27UL
#define CLOCK_ETHMACPTP         28UL
#define CLOCK_OTGHS             28UL
#define CLOCK_OTGHSULPI         28UL
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