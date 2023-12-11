/**
 ******************************************************************************
 * @file           : GPIO_Mem_Map.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains Memory Map for GPIO Ports
 * @date		   : 11 Dec 2023 
 ******************************************************************************
 */

#ifndef GPIO_MEM_MAP
#define GPIO_MEM_MAP


/******************** Include Start **********************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/
#define PERIPH_BASE                     0x40000000 /*< Peripheral base address in the alias region*/

#define GPIO_BASE_ADD                   0x40020000

#define GPIOn_BASE(GPIO_NUM)            ((GPIO_NUM<<(uint_16)10) + GPIO_BASE_ADD)

#define GPIO_GEN_REG(GPIO_NUM,OFFSET)   (((GPIOn_BASE(GPIO_NUM) + OFFSET )))
#define ACCESS_REG(REG_ADDRESS)         (*((uint_32 *)(REG_ADDRESS)))

#define GET_CLEAR_MSK_for_2BITS(PIN_ID) (3UL << (2UL * PIN_ID))


#define GPIO_MODER_REG_OFFEST     0x00
#define GPIO_OTYPER_REG_OFFEST    0x04
#define GPIO_OSPEEDR_REG_OFFEST   0x08
#define GPIO_PUPDR_REG_OFFEST     0x0C
#define GPIO_IDR_REG_OFFEST       0x10
#define GPIO_ODR_REG_OFFEST       0x14
#define GPIO_BSRR_REG_OFFEST      0x18
#define GPIO_LCKR_REG_OFFEST      0x1C
#define GPIO_AFR_REG_OFFEST[2]    0x20

#define GPIOA                     1UL
#define GPIOB                     2UL
#define GPIOC                     3UL
#define GPIOD                     4UL
#define GPIOE                     5UL
#define GPIOF                     6UL
#define GPIOG                     7UL
#define GPIOH                     8UL
#define GPIOI                     9UL

/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER_PIN0_Pos            (0U)
#define GPIO_MODER_MODER_PIN0_Msk            (0x3UL << GPIO_MODER_MODER_PIN0_Pos)       
#define GPIO_MODER_MODER_PIN1_Pos            (2U)
#define GPIO_MODER_MODER_PIN1_Msk            (0x3UL << GPIO_MODER_MODER_PIN1_Pos)      
#define GPIO_MODER_MODER_PIN2_Pos            (4U)
#define GPIO_MODER_MODER_PIN2_Msk            (0x3UL << GPIO_MODER_MODER_PIN2_Pos)      
#define GPIO_MODER_MODER_PIN3_Pos            (6U)
#define GPIO_MODER_MODER_PIN3_Msk            (0x3UL << GPIO_MODER_MODER_PIN3_Pos)      
#define GPIO_MODER_MODER_PIN4_Pos            (8U)
#define GPIO_MODER_MODER_PIN4_Msk            (0x3UL << GPIO_MODER_MODER_PIN4_Pos)      
#define GPIO_MODER_MODER_PIN5_Pos            (10U)
#define GPIO_MODER_MODER_PIN5_Msk            (0x3UL << GPIO_MODER_MODER_PIN5_Pos)      
#define GPIO_MODER_MODER_PIN6_Pos            (12U)
#define GPIO_MODER_MODER_PIN6_Msk            (0x3UL << GPIO_MODER_MODER_PIN6_Pos)      
#define GPIO_MODER_MODER_PIN7_Pos            (14U)
#define GPIO_MODER_MODER_PIN7_Msk            (0x3UL << GPIO_MODER_MODER_PIN7_Pos)      
#define GPIO_MODER_MODER_PIN8_Pos            (16U)
#define GPIO_MODER_MODER_PIN8_Msk            (0x3UL << GPIO_MODER_MODER_PIN8_Pos)      
#define GPIO_MODER_MODER_PIN9_Pos            (18U)
#define GPIO_MODER_MODER_PIN9_Msk            (0x3UL << GPIO_MODER_MODER_PIN9_Pos)      
#define GPIO_MODER_MODER_PIN10_Pos           (20U)
#define GPIO_MODER_MODER_PIN10_Msk           (0x3UL << GPIO_MODER_MODER_PIN10_Pos)      
#define GPIO_MODER_MODER_PIN11_Pos           (22U)
#define GPIO_MODER_MODER_PIN11_Msk           (0x3UL << GPIO_MODER_MODER_PIN11_Pos)      
#define GPIO_MODER_MODER_PIN12_Pos           (24U)
#define GPIO_MODER_MODER_PIN12_Msk           (0x3UL << GPIO_MODER_MODER_PIN12_Pos)      
#define GPIO_MODER_MODER_PIN13_Pos           (26U)
#define GPIO_MODER_MODER_PIN13_Msk           (0x3UL << GPIO_MODER_MODER_PIN13_Pos)      
#define GPIO_MODER_MODER_PIN14_Pos           (28U)
#define GPIO_MODER_MODER_PIN14_Msk           (0x3UL << GPIO_MODER_MODER_PIN14_Pos)      
#define GPIO_MODER_MODER_PIN15_Pos           (30U)
#define GPIO_MODER_MODER_PIN15_Msk           (0x3UL << GPIO_MODER_MODER_PIN15_Pos)            


/******************** Macro Declarations End **********************/

/******************** Data Type Declarations Start **********************/


typedef struct
{
  uint_32 MODER;                /* GPIO port mode register,               Address offset: 0x00      */
  uint_32 OTYPER;               /* GPIO port output type register,        Address offset: 0x04      */
  uint_32 OSPEEDR;              /* GPIO port output speed register,       Address offset: 0x08      */
  uint_32 PUPDR;                /* GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  uint_32 IDR;                  /* GPIO port input data register,         Address offset: 0x10      */
  uint_32 ODR;                  /* GPIO port output data register,        Address offset: 0x14      */
  uint_32 BSRR;                 /* GPIO port bit set/reset register,      Address offset: 0x18      */
  uint_32 LCKR;                 /* GPIO port configuration lock register, Address offset: 0x1C      */
  uint_32 AFR[2];               /* GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;
/******************** Data Type Declarations End   **********************/




#endif /*GPIO_MEM_MAP*/