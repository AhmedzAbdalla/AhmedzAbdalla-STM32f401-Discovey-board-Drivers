/**
 ******************************************************************************
 * @file           : SCB.c
 * @author         : Ahmed Abdalla
 * @brief          : SCB APIs Implementation
 * @date		   : 02 Dec 2023 
 ******************************************************************************
 */

/******************** Include Start **********************/
#include "../../../Inc/MCAL/SCB/SCB.h"
/******************** Include End **********************/

/******************** Macro Declarations Start **********************/
/******************** Macro Declarations end **********************/

/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End **********************/

/******************** Data Type Declarations Start **********************/
/******************** Data Type Declarations End **********************/

/******************** Software Interfaces Implementation Start **********************/

/**
 * @brief Set the priority grouping for the System Control Block (SCB).
 *
 * This function sets the priority grouping for the SCB (System Control Block).
 *
 * @param Priority_Group: The priority grouping to be set.
 */
void SCB_Set_Priority_Group(uint_32 Priority_Group)
{
    // Read the current value of the AIRCR register
    uint_32 Reg_Val = SCB->AIRCR;

    // Clear the bits related to VECTKEY and PRIORITY GROUP in AIRCR
    Reg_Val &= ~(SCB_AIRCR_VECTKEY_MSK | SCB_AIRCR_PRIORITY_GROUP_MSK);

    // Set the VECTKEY and PRIORITY GROUP bits with the provided values
    Reg_Val |= (SCB_AIRCR_VECTKEY << SCB_AIRCR_VECTKEY_POS) | (Priority_Group << SCB_AIRCR_PRIORITY_GROUP_POS);

    // Write the modified value back to the AIRCR register to set the new priority grouping
    SCB->AIRCR = Reg_Val;
}

/******************** Software Interfaces Implementation End **********************/
