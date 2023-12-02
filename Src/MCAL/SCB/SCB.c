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
void SCB_Set_Priority_Group(uint_32 Priority_Group )
{
    uint_32 Reg_Val = SCB->AIRCR;
    Reg_Val &= ~(SCB_AIRCR_VECTKEY_MSK | SCB_AIRCR_PRIORITY_GROUP_MSK);
    
    Reg_Val |= (SCB_AIRCR_VECTKEY << SCB_AIRCR_VECTKEY_POS) | (Priority_Group << SCB_AIRCR_PRIORITY_GROUP_POS);
    SCB->AIRCR = Reg_Val;
}
/******************** Software Interfaces Implementation End **********************/
