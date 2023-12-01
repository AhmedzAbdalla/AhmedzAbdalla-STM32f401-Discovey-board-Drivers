/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Abdalla
 * @brief          : Main program body
 * @date		   : 16 Nov 2023 
 ******************************************************************************
 */

/******************** Include Start **********************/
#include "../Inc/MCAL/NVIC/NVIC.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/

/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/

/******************** Data Type Declarations End **********************/

int main(void)
{
    /* Loop forever */
	NVIC_Enable_IRQ(USART3);
	NVIC_Enable_IRQ(EXTI15_10);
	NVIC_Enable_IRQ(RTC_Alarm);

	NVIC_SetPending_IRQ(USART3);
	NVIC_SetPending_IRQ(EXTI15_10);
	NVIC_SetPending_IRQ(RTC_Alarm);
	for(;;);
	return 0;
}

void USART3_IRQHandler(void)
{
	static uint_8 USART3_IRQHandler_flag  =0;
	USART3_IRQHandler_flag = 1;
}

void EXTI15_10_IRQHandler(void)
{
	static uint_8 EXTI15_10_IRQHandler_flag  =0;
	EXTI15_10_IRQHandler_flag = 1;
}

void RTC_Alarm_IRQHandler(void)
{
	static uint_8 RTC_Alarm_IRQHandler_flag  =0;
	RTC_Alarm_IRQHandler_flag = 1;
}
