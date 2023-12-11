/**
 ******************************************************************************
 * @file           : GPIO.c
 * @author         : Ahmed Abdalla
 * @brief          : Contains implementation of interfaces 
 * @date		   : 11 Dec 2023 
 ******************************************************************************
 */
/******************** Include Start **********************/
#include "../../../Inc/MCAL/GPIO/GPIO.h"
/******************** Include End **********************/

STD_Return_t GPIO_void_Set_Pin_Mode(PIN_ID_t Copy_Pin_ID, uint_8 Copy_mode)
{
    STD_Return_t ret = Not_OK;
    if((Copy_Pin_ID > PI_15))
    {
        /*Noting*/
    }
    else
    {
    	/*the commneted lines below has the same effect as the macro function  <MODIFY_REG>*/
        //uint_32 * reg_add =  (*((uint_32 *)(GPIO_GEN_REG((uint_8)(Copy_Pin_ID / 16) , GPIO_MODER_REG_OFFEST))));
        //uint_32 clr_MSk = GET_CLEAR_MSK_for_2BITS((uint_32)(Copy_Pin_ID % 16));
        //uint_32 temp = (~(GPIO_MODER_MODER_PIN4_Msk)) & (* reg_add);
        //temp |= Copy_mode << GPIO_MODER_MODER_PIN4_Pos;
        //* reg_add =  temp;

        MODIFY_REG( ACCESS_REG(((((GPIO_GEN_REG((uint_8)(Copy_Pin_ID / 16) , GPIO_MODER_REG_OFFEST)))))) ,(GET_CLEAR_MSK_for_2BITS((uint_32)(Copy_Pin_ID % 16))) , (Copy_mode << GPIO_MODER_MODER_PIN4_Pos));
        //MODIFY_REG( ((*((uint_32 *)(GPIO_GEN_REG((uint_8)(Copy_Pin_ID / 16) , GPIO_MODER_REG_OFFEST))))) ,(GET_CLEAR_MSK_for_2BITS((uint_32)(Copy_Pin_ID % 16))) , (Copy_mode << GPIO_MODER_MODER_PIN4_Pos));
        ret = OK;
    }
    return ret;
}


STD_Return_t GPIO_void_Set_Pin_Type(PIN_ID_t Copy_Pin_ID, uint_8 Copy_Type )
{
    STD_Return_t ret = Not_OK;
    if((Copy_Pin_ID > PI_15))
    {
        /*Noting*/
    }
    else
    {
    	switch (Copy_Type)
        {
        case push_pull:
            CLR_BIT(ACCESS_REG((((GPIO_GEN_REG((uint_8)(Copy_Pin_ID / 16) , GPIO_MODER_REG_OFFEST))))) , ((uint_32)(Copy_Pin_ID % 16)));
            break;
        case open_drain:
            SET_BIT(ACCESS_REG((((GPIO_GEN_REG((uint_8)(Copy_Pin_ID / 16) , GPIO_MODER_REG_OFFEST))))) , ((uint_32)(Copy_Pin_ID % 16)));
            break;
        default:
            break;
        }
        ret = OK;
    }
    return ret;
}
