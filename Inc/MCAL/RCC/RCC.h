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
                           
/** Buses Macros **/
#define AHB1                                  0UL   /* Advanced High-Performance Bus 1 */
#define AHB2                                  1UL   /* Advanced High-Performance Bus 2 */
#define AHB3                                  2UL   /* Advanced High-Performance Bus 3 */
#define APB1                                  3UL   /* Advanced Peripheral Bus 1 */
#define APB2                                  4UL   /* Advanced Peripheral Bus 2 */

/** Peripherals on AHB1 bus **/
#define AHB1_CLK_GPIOA                        0UL   /* GPIO port A clock source */
#define AHB1_CLK_GPIOB                        1UL   /* GPIO port B clock source */
#define AHB1_CLK_GPIOC                        2UL   /* GPIO port C clock source */
#define AHB1_CLK_GPIOD                        3UL   /* GPIO port D clock source */
#define AHB1_CLK_GPIOE                        4UL   /* GPIO port E clock source */
#define AHB1_CLK_GPIOF                        5UL   /* GPIO port F clock source */
#define AHB1_CLK_GPIOG                        6UL   /* GPIO port G clock source */
#define AHB1_CLK_GPIOH                        7UL   /* GPIO port H clock source */
#define AHB1_CLK_GPIOI                        8UL   /* GPIO port I clock source */
#define AHB1_CLK_CRC                          12UL  /* CRC clock source */
#define AHB1_CLK_FLITF                        15UL  /* Flash interface clock source */
#define AHB1_CLK_SRAM_1                       16UL  /* SRAM 1 clock source */
#define AHB1_CLK_SRAM_2                       17UL  /* SRAM 2 clock source */
#define AHB1_CLK_BKPSRAM                      18UL  /* Backup SRAM clock source */
#define AHB1_CLK_DMA1                         21UL  /* DMA1 clock source */
#define AHB1_CLK_DMA2                         22UL  /* DMA2 clock source */
#define AHB1_CLK_ETHMAC                       25UL  /* Ethernet MAC clock source */
#define AHB1_CLK_ETHTX                        26UL  /* Ethernet TX clock source */
#define AHB1_CLK_ETHRX                        27UL  /* Ethernet RX clock source */
#define AHB1_CLK_ETHMACPTP                    28UL  /* Ethernet MAC PTP clock source */
#define AHB1_CLK_OTGHS                        29UL  /* USB OTG HS clock source */
#define AHB1_CLK_OTGHSULPI                    30UL  /* USB OTG HS ULPI clock source */

/** Peripherals on AHB2 bus **/
#define AHB2_CLK_DCMI                         32UL  /* DCMI clock source */
#define AHB2_CLK_CRYP                         36UL  /* CRYP clock source */
#define AHB2_CLK_HASH                         37UL  /* HASH clock source */
#define AHB2_CLK_RNG                          38UL  /* RNG clock source */
#define AHB2_CLK_OTGFS                        39UL  /* USB OTG FS clock source */

/** Peripherals on AHB3 bus **/
#define AHB3_CLK_FSMC                         64UL  /* FSMC clock source */

/** Peripherals on APB1 bus **/
#define APB1_CLK_TIM2                         0UL   /* Timer 2 clock source */
#define APB1_CLK_TIM3                         1UL   /* Timer 3 clock source */
#define APB1_CLK_TIM4                         2UL   /* Timer 4 clock source */
#define APB1_CLK_TIM5                         3UL   /* Timer 5 clock source */
#define APB1_CLK_TIM6                         4UL   /* Timer 6 clock source */
#define APB1_CLK_TIM7                         5UL   /* Timer 7 clock source */
#define APB1_CLK_TIM12                        6UL   /* Timer 12 clock source */
#define APB1_CLK_TIM13                        7UL   /* Timer 13 clock source */
#define APB1_CLK_TIM14                        8UL   /* Timer 14 clock source */
#define APB1_CLK_WWDG                         11UL  /* Window Watchdog clock source */
#define APB1_CLK_SPI2                         14UL  /* SPI2 clock source */
#define APB1_CLK_SPI3                         15UL  /* SPI3 clock source */
#define APB1_CLK_USART2                       17UL  /* USART2 clock source */
#define APB1_CLK_USART3                       18UL  /* USART3 clock source */
#define APB1_CLK_UART4                        19UL  /* UART4 clock source */
#define APB1_CLK_UART5                        20UL  /* UART5 clock source */
#define APB1_CLK_I2C1                         21UL  /* I2C1 clock source */
#define APB1_CLK_I2C2                         22UL  /* I2C2 clock source */
#define APB1_CLK_I2C3                         23UL  /* I2C3 clock source */
#define APB1_CLK_CAN1                         25UL  /* CAN1 clock source */
#define APB1_CLK_CAN2                         26UL  /* CAN2 clock source */
#define APB1_CLK_PWR                          28UL  /* Power interface clock source */
#define APB1_CLK_DAC                          29UL  /* DAC clock source */

/** Peripherals on APB2 bus **/
#define APB2_CLK_TIM1                         32UL  /* Timer 1 clock source */
#define APB2_CLK_TIM8                         33UL  /* Timer 8 clock source */
#define APB2_CLK_USART1                       36UL  /* USART1 clock source */
#define APB2_CLK_USART6                       37UL  /* USART6 clock source */
#define APB2_CLK_ADC1                         40UL  /* ADC1 clock source */
#define APB2_CLK_ADC2                         41UL  /* ADC2 clock source */
#define APB2_CLK_ADC3                         42UL  /* ADC3 clock source */
#define APB2_CLK_SDIO                         43UL  /* SDIO clock source */
#define APB2_CLK_SPI1                         44UL  /* SPI1 clock source */
#define APB2_CLK_SYSCFG                       46UL  /* System configuration clock source */
#define APB2_CLK_TIM9                         48UL  /* Timer 9 clock source */
#define APB2_CLK_TIM10                        49UL  /* Timer 10 clock source */
#define APB2_CLK_TIM11                        50UL  /* Timer 11 clock source */

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
    volatile uint_32 RCC_CR_Reg;              /* RCC Control Register */
    volatile uint_32 RCC_PLLCFGR_Reg;         /* RCC PLL Configuration Register */
    volatile uint_32 RCC_CFGR_Reg;            /* RCC Configuration Register */
    volatile uint_32 RCC_CIR_Reg;             /* RCC Clock Interrupt Register */
    volatile uint_32 RCC_AHB1RSTR_Reg;        /* RCC AHB1 Peripheral Reset Register */
    volatile uint_32 RCC_AHB2RSTR_Reg;        /* RCC AHB2 Peripheral Reset Register */
    volatile uint_32 RCC_AHB3RSTR_Reg;        /* RCC AHB3 Peripheral Reset Register */
    uint_32 Rserved0;                         /* Reserved space */
    volatile uint_32 RCC_APB1RSTR_Reg;        /* RCC APB1 Peripheral Reset Register */
    volatile uint_32 RCC_APB2RSTR_Reg;        /* RCC APB2 Peripheral Reset Register */
    uint_32 Rserved1[2];                      /* Reserved space */
    volatile uint_32 RCC_AHB1ENR_Reg;         /* RCC AHB1 Peripheral Clock Enable Register */
    volatile uint_32 RCC_AHB2ENR_Reg;         /* RCC AHB2 Peripheral Clock Enable Register */
    volatile uint_32 RCC_AHB3ENR_Reg;         /* RCC AHB3 Peripheral Clock Enable Register */
    uint_32 Rserved2;                         /* Reserved space */
    volatile uint_32 RCC_APB1ENR_Reg;         /* RCC APB1 Peripheral Clock Enable Register */
    volatile uint_32 RCC_APB2ENR_Reg;         /* RCC APB2 Peripheral Clock Enable Register */
    uint_32 Rserved3[2];                      /* Reserved space */
    volatile uint_32 RCC__AHB1LPENR_Reg;      /* RCC AHB1 Peripheral Clock Enable in Low Power Mode Register */
    volatile uint_32 RCC__AHB2LPENR_Reg;      /* RCC AHB2 Peripheral Clock Enable in Low Power Mode Register */
    volatile uint_32 RCC__AHB3LPENR_Reg;      /* RCC AHB3 Peripheral Clock Enable in Low Power Mode Register */
    uint_32 Rserved4;                         /* Reserved space */
    volatile uint_32 RCC_APB1LPENR_Reg;       /* RCC APB1 Peripheral Clock Enable in Low Power Mode Register */
    volatile uint_32 RCC_APB2LPENR_Reg;       /* RCC APB2 Peripheral Clock Enable in Low Power Mode Register */
    uint_32 Rserved5[2];                      /* Reserved space */
    volatile uint_32 RCC_BDCR_Reg;            /* RCC Backup Domain Control Register */
    volatile uint_32 RCC_CSR_Reg;             /* RCC Control/Status Register */
    uint_32 Rserved6[2];                      /* Reserved space */
    volatile uint_32 RCC_SSCGR_Reg;           /* RCC Spread Spectrum Clock Generation Register */
    volatile uint_32 RCC_PLLI2SCFGR_Reg;      /* RCC PLLI2S Configuration Register */

} RCC_t;


/**
 * @brief Structure to represent bus clock configuration factors.
 *
 * This structure holds the division factors for different buses in the system.
 * These factors are used to configure the clock prescalers for the AHB, APB1, and APB2 buses.
 */
typedef struct
{
    uint_32 AHB_DIV_FACT;   /**< Division factor for the AHB bus clock */
    uint_32 APB1_DIV_FACT;  /**< Division factor for the APB1 bus clock */
    uint_32 APB2_DIV_FACT;  /**< Division factor for the APB2 bus clock */
} BUS_CLK;

/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
/**
 * @brief Initialize the system clock.
 *
 * This function is responsible for initializing the system clock and related configurations.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Init_CLK(void);

/**
 * @brief Enable the clock for a specific peripheral on a specified bus.
 *
 * This function enables the clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to enable the clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_Clk_En(const uint_8 Periphral_ID, const uint_8 Bus_ID);

/**
 * @brief Reset the clock for a specific peripheral on a specified bus.
 *
 * This function resets the clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to reset the clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_Clk_RST(const uint_8 Periphral_ID, const uint_8 Bus_ID);

/**
 * @brief Enable the low-power clock for a specific peripheral on a specified bus.
 *
 * This function enables the low-power clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to enable the low-power clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_LPClk_En(const uint_8 Periphral_ID, const uint_8 Bus_ID);

/**
 * @brief Set the clock configuration for different buses.
 *
 * This function sets the clock configuration for different buses using the provided configuration structure.
 *
 * @param[in] Config_BUS_CLK Pointer to the configuration structure holding bus clock division factors.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Set_Bus_CLK(const BUS_CLK *const Config_BUS_CLK);

/******************** Software Interfaces Declarations End   **********************/


#endif /*MCAL_RCC_H_*/
