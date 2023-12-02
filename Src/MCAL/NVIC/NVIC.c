/**
 ******************************************************************************
 * @file           : NVIC.c
 * @author         : Ahmed Abdalla
 * @brief          : NVIC APIs Implementation
 * @date		   : 16 Nov 2023 
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

/******************** Software Interfaces Implementation Start **********************/
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
		status = 0xff;
	}
	return status;
}

/**
 * @brief Set the priority level for the specified NVIC interrupt.
 *
 * This function sets the priority level for the specified NVIC (Nested Vectored Interrupt Controller) interrupt.
 *
 * @param IRQn: The NVIC interrupt number.
 * @param Priority: The priority level to be set.
 */
void NVIC_Set_Priority(NVIC_IRQn_t IRQn, uint_8 Priority)
{
    // Check if the provided interrupt number is valid
    if (IRQn >= 0)
    {
        // Calculate the priority value and set it in the appropriate IPR register
        NVIC->IPR[(uint_32)IRQn] = (uint_8)((Priority << (8UL - NVIC_PRI_NITS)) & 0xFF);
    }
    else
    {
        // Invalid interrupt number, do nothing
        /* Nothing */
    }
}

/**
 * @brief Get the priority level for the specified NVIC interrupt.
 *
 * This function retrieves the priority level for the specified NVIC interrupt.
 *
 * @param IRQn: The NVIC interrupt number.
 * @return uint_8: The priority level of the specified interrupt.
 */
uint_8 NVIC_Get_Priority(NVIC_IRQn_t IRQn)
{
    uint_8 ret = 0;

    // Check if the provided interrupt number is valid
    if ((uint_32)IRQn >= 0)
    {
        // Retrieve the priority value from the appropriate IPR register
        ret = NVIC->IPR[(uint_32)IRQn] >> (8UL - NVIC_PRI_NITS);
    }
    else
    {
        // Invalid interrupt number, return 0xff to indicate an error
        ret = 0xff;
    }

    return ret;
}
/******************** Software Interfaces Implementation End **********************/
