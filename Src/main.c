/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Abdalla
 * @brief          : Main program body
 * @date		   : 16 Nov 2023 
 ******************************************************************************
 */

/******************** Include Start **********************/
#include "../Inc/LIB/STD_Types.h"
#include "../Inc/LIB/BIT_MATH.h"
#include "../Inc/MCAL/NVIC/NVIC.h"
#include "../Inc/MCAL/SCB/SCB.h"
#include "../Inc/MCAL/RCC/RCC.h"
#include "../Inc/MCAL/SYS_TICK/STK.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/

/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/

/******************** Data Type Declarations End **********************/
	 static uint_32 counter = 0;
void test(void)
 {

	 counter++;
 }
int main(void)
{
	BUS_CLK my_config = {.AHB_DIV_FACT = HPRE_DIV_16,
						 .APB1_DIV_FACT = PPRE1_DIV_4,
						 .APB2_DIV_FACT = PPRE2_DIV_8
						 };
    /* Loop forever */
	NVIC_Enable_IRQ(USART3);
	NVIC_Enable_IRQ(EXTI15_10);
//	NVIC_Enable_IRQ(RTC_Alarm);
//
//	NVIC_SetPending_IRQ(USART3);
//	NVIC_SetPending_IRQ(EXTI15_10);
//	NVIC_SetPending_IRQ(RTC_Alarm);
	//SET_BIT((RCC->RCC_AHB1ENR_Reg), (CLOCK_GPIOC % 32UL));
	//RCC->RCC_AHB1ENR_Reg =
	//SCB->AIRCR = ( 0x05FA << 16) | (5 << 8);
	SCB_Set_Priority_Group(SCB_PRIORITY_GROUP_2);
	NVIC_Set_Priority(USART3 , 4);
	NVIC_Set_Priority(EXTI15_10 , 0);
	RCC_void_RCC_Periphral_Clk_En(AHB1_CLK_GPIOG  , AHB1);
	RCC_void_RCC_Periphral_Clk_En( AHB1_CLK_DMA1  , AHB1);
	RCC_void_RCC_Periphral_Clk_En( AHB1_CLK_OTGHS , AHB1);
	RCC_void_RCC_Periphral_Clk_En( AHB2_CLK_DCMI  , AHB2);
	RCC_void_RCC_Periphral_Clk_En( AHB2_CLK_HASH  , AHB2);
	RCC_void_RCC_Periphral_Clk_En( AHB2_CLK_RNG   , AHB2);
	RCC_void_RCC_Periphral_Clk_En( AHB3_CLK_FSMC  , AHB3);

	RCC_void_RCC_Set_Bus_CLK(&my_config);

	STK_Init();
	STK_Set_Interval_Periodic(1000000 , &test);
	//NVIC_SetPending_IRQ(USART3);
	while(1);
	return 0;
}

void USART3_IRQHandler(void)
{
	static uint_8 USART3_IRQHandler_flag  =0;
	
	USART3_IRQHandler_flag = 1;
	NVIC_SetPending_IRQ(EXTI15_10);
	USART3_IRQHandler_flag = 2;
}

void EXTI15_10_IRQHandler(void)
{
	static uint_8 EXTI15_10_IRQHandler_flag  =0;
	EXTI15_10_IRQHandler_flag = 1;
}
//
//void RTC_Alarm_IRQHandler(void)
//{
//	static uint_8 RTC_Alarm_IRQHandler_flag  =0;
//	RTC_Alarm_IRQHandler_flag = 1;
//}
