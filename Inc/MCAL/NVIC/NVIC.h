/**
 ******************************************************************************
 * @file           : NVIC.h
 * @author         : Ahmed Abdalla
 * @brief          : Header file of NVIC
 * @date		   : 16 Nov 2023 
 ******************************************************************************
 */
#ifndef MCAL_NVIC_NVIC_H_
#define MCAL_NVIC_NVIC_H_

/******************** Include Start **********************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/
#define NVIC_BASE_ADDRESS   (0xE000E100UL)
#define NVIC                ((NVIC_t *)NVIC_BASE_ADDRESS)
/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/
typedef struct
{
    uint_32 volatile ISER[8];
    uint_32 Reserved_0[24];
    uint_32 volatile ICER[8];
    uint_32 Reserved_1[24];
    uint_32 volatile ISPR[8];
    uint_32 Reserved_2[24];
    uint_32 volatile ICPR[8];
    uint_32 Reserved_3[24];
    uint_32 volatile IABR[8];
    uint_32 Reserved_4[56];
    uint_32 volatile IPR[60];
    uint_32 Reserved_5[643];
    uint_32 STIR;
}NVIC_t;

typedef enum
{
    /*Cortrex M4 Exceptions number*/
    NMI = -14,
    MemManage = -12,
    BusFault = -11,
    UsageFault = -10,
    SVCall = -5,
    DebugMonitor = -4,
    PendSV = -2, 
    SysTick = -1,
    /*Cortrex M4 Specific Interrupt number*/
    WWDG = 0,
    PVD = 1,
    TAMP_STAMP = 2,
    RTC_WKUP = 3,
    FLASH = 4,
    RCC = 5,
    EXTI0 = 6,
    EXTI1 = 7,
    EXTI2 = 8,
    EXTI3 = 9,
    EXTI4 = 10,
    DMA1_Stream0 = 11,
    DMA1_Stream1 = 12,
    DMA1_Stream2 = 13,
    DMA1_Stream3 = 14,
    DMA1_Stream4 = 15,
    DMA1_Stream5 = 16,
    DMA1_Stream6 = 17,
    ADC = 18,
    CAN1_TX = 19,
    CAN1_RX0 = 20,
    CAN1_RX1 = 21,
    CAN1_SCE = 22,
    EXTI9_5 = 23,
    TIM1_BRK_TIM9 = 24,
    TIM1_UP_TIM10 = 25,
    TIM1_TRG_COM_TIM11 = 26,
    TIM1_CC = 27,
    TIM2 = 28,
    TIM3 = 29,
    TIM4 = 30,
    I2C1_EV = 31,
    I2C1_ER = 32,
    I2C2_EV = 33,
    I2C2_ER = 34,
    SPI1 = 35,
    SPI2 = 36,
    USART1 = 37,
    USART2 = 38,
    USART3 = 39,
    EXTI15_10 = 40,
    RTC_Alarm = 41,
    OTG_FS_WKUP = 42,
    TIM8_BRK_TIM12 = 43,
    TIM8_UP_TIM13 = 44,
    TIM8_TRG_COM_TIM14 = 45,
    TIM8_CC = 46,
    DMA1_Stream7 = 47,
    FSMC = 48,
    SDIO = 49,
    TIM5 = 50,
    SPI3 = 51,
    UART4 = 52,
    UART5 = 53,
    TIM6_DAC = 54,
    TIM7 = 55,
    DMA2_Stream0 = 56,
    DMA2_Stream1 = 57,
    DMA2_Stream2= 58,
    DMA2_Stream3= 59,
    DMA2_Stream4 = 60,
    ETH = 61,
    ETH_WKUP = 62,
    CAN2_TX = 63,
    CAN2_RX0 = 64,
    CAN2_RX1 = 65,
    CAN2_SCE = 66,
    OTG_FS = 67,
    DMA2_Stream5 = 68,
    DMA2_Stream6 = 69,
    DMA2_Stream7 = 70,
    USART6 = 71,
    I2C3_EV = 72,
    I2C3_ER = 73,
    OTG_HS_EP1_OUT = 74,
    OTG_HS_EP1_IN = 75,
    OTG_HS_WKUP = 76,
    OTG_HS = 77,
    DCMI = 78,
    CRYP = 79,
    HASH_RNG = 80,
    FPU = 81


}NVIC_IRQn_t;
/******************** Data Type Declarations End **********************/

/******************** Software Interfaces Declarations Start **********************/

/**
 * @brief Enables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number to be enabled.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_Enable_IRQ(NVIC_IRQn_t IRQn);

/**
 * @brief Disables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number to be disabled.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_Disable_IRQ(NVIC_IRQn_t IRQn);

/**
 * @brief Sets the pending status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the pending status should be set.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_SetPending_IRQ(NVIC_IRQn_t IRQn);

/**
 * @brief Clears the pending status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the pending status should be cleared.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_ClearPending_IRQ(NVIC_IRQn_t IRQn);

/**
 * @brief Gets the active status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the active status should be retrieved.
 *             Refer to the specific device documentation for the available IRQ numbers.
 *
 * @return 1 if the interrupt is active, 0 otherwise.
 */
uint_8 NVIC_Get_Active(NVIC_IRQn_t IRQn);
/******************** Software Interfaces Declarations End **********************/


#endif /* MCAL_NVIC_NVIC_H_ */
