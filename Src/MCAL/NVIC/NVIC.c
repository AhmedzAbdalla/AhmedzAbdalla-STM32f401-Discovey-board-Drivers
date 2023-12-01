/**
 ******************************************************************************
 * @file           : NVIC.c
 * @author         : Ahmed Abdalla
 * @brief          : NVIC APIs Implementation
 * @date		   : 16 Dec 2023 
 ******************************************************************************
 */

/******************** Include Start **********************/
#include "../../../Inc/MCAL/NVIC/NVIC.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/
/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/
/******************** Data Type Declarations End **********************/

/******************** Software Interfaces Declarations Start **********************/
/**
 * @brief Enables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number to be enabled.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_Enable_IRQ(NVIC_IRQn_t IRQn)
{
	if((uint_32)IRQn >=0)
	{
		NVIC->ISER[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1f));
	}
	else
	{
		/*Nothing*/
	}
}

/**
 * @brief Disables a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number to be disabled.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_Disable_IRQ(NVIC_IRQn_t IRQn)
{
	if((uint_32)IRQn >=0)
	{
		NVIC->ICER[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1f));
	}
	else
	{
		/*Nothing*/
	}
}

/**
 * @brief Sets the pending status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the pending status should be set.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_SetPending_IRQ(NVIC_IRQn_t IRQn)
{
	if((uint_32)IRQn >=0)
	{
		NVIC->ISPR[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1f));
	}
	else
	{
		/*Nothing*/
	}
}

/**
 * @brief Clears the pending status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the pending status should be cleared.
 *             Refer to the specific device documentation for the available IRQ numbers.
 */
void NVIC_ClearPending_IRQ(NVIC_IRQn_t IRQn)
{
	if((uint_32)IRQn >=0)
	{
		NVIC->ICPR[((uint_32)IRQn) >> 5] = (1UL << (((uint_32)IRQn) & 0x1f));
	}
	else
	{
		/*Nothing*/
	}
}

/**
 * @brief Gets the active status for a specific interrupt in the Nested Vectored Interrupt Controller (NVIC).
 * 
 * @param IRQn: Interrupt number for which the active status should be retrieved.
 *             Refer to the specific device documentation for the available IRQ numbers.
 *
 * @return 1 if the interrupt is active, 0 otherwise.
 */
uint_8 NVIC_Get_Active(NVIC_IRQn_t IRQn)
{
	uint_8 status =0; 
	if((uint_32)IRQn >=0)
	{
		status = READ_BIT((NVIC->IABR[((uint_32)IRQn) >> 5]) , (1UL << (((uint_32)IRQn) & 0x1f)));
	}
	else
	{
		/*Nothing*/
	}
	return status;
}
/******************** Software Interfaces Declarations End **********************/
