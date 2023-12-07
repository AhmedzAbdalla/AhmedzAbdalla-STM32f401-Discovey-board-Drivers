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
#define RCC                                   ((RCC_t *)(0x40023800))

/*System Clock Sorces Macros*/
                           

/*Buses macrros*/
#define AHB1                                  0UL
#define AHB2                                  1UL
#define AHB3                                  2UL
#define APB1                                  3UL
#define APB2                                  4UL

/*Periphrals on AHB1 bus*/
#define AHB1_CLK_GPIOA                        0UL
#define AHB1_CLK_GPIOB                        1UL
#define AHB1_CLK_GPIOC                        2UL
#define AHB1_CLK_GPIOD                        3UL
#define AHB1_CLK_GPIOE                        4UL
#define AHB1_CLK_GPIOF                        5UL
#define AHB1_CLK_GPIOG                        6UL
#define AHB1_CLK_GPIOH                        7UL
#define AHB1_CLK_GPIOI                        8UL
#define AHB1_CLK_CRC                          12UL
#define AHB1_CLK_FLITF                        15UL
#define AHB1_CLK_SRAM_1                       16UL
#define AHB1_CLK_SRAM_2                       17UL
#define AHB1_CLK_BKPSRAM                      18UL
#define AHB1_CLK_DMA1                         21UL
#define AHB1_CLK_DMA2                         22UL
#define AHB1_CLK_ETHMAC                       25UL
#define AHB1_CLK_ETHTX                        26UL
#define AHB1_CLK_ETHRX                        27UL
#define AHB1_CLK_ETHMACPTP                    28UL
#define AHB1_CLK_OTGHS                        29UL
#define AHB1_CLK_OTGHSULPI                    30UL

/*Periphrals on AHB2 bus*/
#define AHB2_CLK_DCMI                         32UL
#define AHB2_CLK_CRYP                         36UL
#define AHB2_CLK_HASH                         37UL
#define AHB2_CLK_RNG                          38UL
#define AHB2_CLK_OTGFS                        39UL

/*Periphrals on AHB2 bus*/
#define AHB3_CLK_FSMC                         64UL


/*Periphrals on APB1 bus*/
#define APB1_CLK_TIM2                         0UL
#define APB1_CLK_TIM3                         1UL
#define APB1_CLK_TIM4                         2UL
#define APB1_CLK_TIM5                         3UL
#define APB1_CLK_TIM6                         4UL
#define APB1_CLK_TIM7                         5UL
#define APB1_CLK_TIM12                        6UL
#define APB1_CLK_TIM13                        7UL
#define APB1_CLK_TIM14                        8UL
#define APB1_CLK_WWDG                         11UL
#define APB1_CLK_SPI2                         14UL
#define APB1_CLK_SPI3                         15UL
#define APB1_CLK_USART2                       17UL
#define APB1_CLK_USART3                       18UL
#define APB1_CLK_UART4                        19UL
#define APB1_CLK_UART5                        20UL
#define APB1_CLK_I2C1                         21UL
#define APB1_CLK_I2C2                         22UL
#define APB1_CLK_I2C3                         23UL
#define APB1_CLK_CAN1                         25UL
#define APB1_CLK_CAN2                         26UL
#define APB1_CLK_PWR                          28UL
#define APB1_CLK_DAC                          29UL

/*Periphrals on APB2 bus*/
#define APB2_CLK_TIM1                         32UL
#define APB2_CLK_TIM8                         33UL
#define APB2_CLK_USART1                       36UL
#define APB2_CLK_USART6                       37UL
#define APB2_CLK_ADC1                         40UL
#define APB2_CLK_ADC2                         41UL
#define APB2_CLK_ADC3                         42UL
#define APB2_CLK_SDIO                         43UL
#define APB2_CLK_SPI1                         44UL
#define APB2_CLK_SYSCFG                       46UL
#define APB2_CLK_TIM9                         48UL
#define APB2_CLK_TIM10                        49UL
#define APB2_CLK_TIM11                        50UL

/*Prescalar values for AHB clock source*/
#define HPRE_BIT_POS    4UL
#define HPRE_BIT_MSK    (0xFUL << HPRE_BIT_POS)

#define HPRE_DIV_1        ((uint_32) 0x00) /*system clock not divided*/
#define HPRE_DIV_2        ((uint_32) 0x80) /*system clock divided by 2*/
#define HPRE_DIV_4        ((uint_32) 0x90) /*system clock divided by 4*/
#define HPRE_DIV_8        ((uint_32) 0xA0) /*system clock divided by 8*/
#define HPRE_DIV_16       ((uint_32) 0xB0) /*system clock divided by 16*/
#define HPRE_DIV_64       ((uint_32) 0xC0) /*system clock divided by 64*/
#define HPRE_DIV_128      ((uint_32) 0xD0) /*system clock divided by 128*/
#define HPRE_DIV_256      ((uint_32) 0xE0) /*system clock divided by 256*/
#define HPRE_DIV_512      ((uint_32) 0xF0) /*system clock divided by 512*/

/*Prescalar values for APB1 clock source*/
#define PPRE1_BIT_POS    10UL
#define PPRE1_BIT_MSK    (0x7UL << PPRE1_BIT_POS)

#define PPRE1_DIV_1        ((uint_32) 0x0)    /*system clock not divided*/
#define PPRE1_DIV_2        ((uint_32) 0x1000) /*system clock divided by 2*/
#define PPRE1_DIV_4        ((uint_32) 0x1400) /*system clock divided by 4*/
#define PPRE1_DIV_8        ((uint_32) 0x1800) /*system clock divided by 8*/
#define PPRE1_DIV_16       ((uint_32) 0x1C00) /*system clock divided by 16*/


/*Prescalar values for APB2 clock source*/
#define PPRE2_BIT_POS    13UL
#define PPRE2_BIT_MSK    (0x7UL << PPRE2_BIT_POS)

#define PPRE2_DIV_1        ((uint_32) 0x0)    /*system clock not divided*/
#define PPRE2_DIV_2        ((uint_32) (0x1000 << 3)) /*system clock divided by 2*/
#define PPRE2_DIV_4        ((uint_32) (0x1400 << 3)) /*system clock divided by 4*/
#define PPRE2_DIV_8        ((uint_32) (0x1800 << 3)) /*system clock divided by 8*/
#define PPRE2_DIV_16       ((uint_32) (0x1C00 << 3)) /*system clock divided by 16*/
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


typedef struct
{
    uint_32 AHB_DIV_FACT;
    uint_32 APB1_DIV_FACT;
    uint_32 APB2_DIV_FACT;
}BUS_CLK;

/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
STD_Return_t RCC_void_RCC_Init_CLK(void );
STD_Return_t RCC_void_RCC_Periphral_Clk_En( const uint_8 Periphral_ID, const uint_8 Bus_ID);
STD_Return_t RCC_void_RCC_Periphral_Clk_RST(const uint_8 Periphral_ID, const uint_8 Bus_ID);
STD_Return_t RCC_void_RCC_Periphral_LPClk_En(const uint_8 Periphral_ID, const uint_8 Bus_ID);
STD_Return_t RCC_void_RCC_Set_Bus_CLK(const BUS_CLK *const Config_BUS_CLK);
/******************** Software Interfaces Declarations End   **********************/


#endif /*MCAL_RCC_H_*/
