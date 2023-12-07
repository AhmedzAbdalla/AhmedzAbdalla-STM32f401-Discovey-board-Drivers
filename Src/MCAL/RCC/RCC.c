/**
 ******************************************************************************
 * @file           : RCC.c
 * @author         : Ahmed Abdalla
 * @brief          : Contains Program of RCC and memory map
 * @date		   : 06 Dec 2023 
 ******************************************************************************
 */



/******************** Include Start **********************/
#include "../../../Inc/MCAL/RCC/RCC.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/

/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/

/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
void RCC_void_RCC_Periphral_Clk_En(uint_8 Periphral_ID, uint_8 Bus_ID)
{
    if((Bus_ID >4) || (Bus_ID < 0))
    {
        /*Nothing*/
    }
    else
    {
        switch (Bus_ID)
        {
        case AHB1:
            SET_BIT((RCC->RCC_AHB1ENR_Reg),(Periphral_ID % 32));
            break;
        case AHB2:
            SET_BIT((RCC->RCC_AHB2ENR_Reg),(Periphral_ID % 32));
            break;
        case AHB3:
            SET_BIT((RCC->RCC_AHB3ENR_Reg),(Periphral_ID % 32));
            break;
        case APB1:
            SET_BIT((RCC->RCC_APB1ENR_Reg),(Periphral_ID % 32));
            break;
        case APB2:
            SET_BIT((RCC->RCC_APB2ENR_Reg),(Periphral_ID % 32));
            break;
        
        default:
            break;
        }
    }
}

void RCC_void_RCC_Periphral_Clk_RST(uint_8 Periphral_ID, uint_8 Bus_ID)
{
    if(Bus_ID >4 || Bus_ID < 0)
    {
        /*Nothing*/
    }
    else
    {
        /*
        if((Periphral_ID > 12UL) && ( (Periphral_ID == 21) || (Periphral_ID == 22) || (Periphral_ID == 29)))
        {
            
        }*/
        switch (Bus_ID)
        {
        case AHB1:
            if((Periphral_ID > AHB1_CLK_CRC) && ( (Periphral_ID != AHB1_CLK_DMA1) || (Periphral_ID != AHB1_CLK_DMA2) || (Periphral_ID != AHB1_CLK_OTGHS) || (Periphral_ID != AHB1_CLK_ETHMAC)))
            {
                /*Nothing*/
            }
            else
            {
                SET_BIT((RCC->RCC_AHB1ENR_Reg),(Periphral_ID % 32));
            }
            break;
        case AHB2:
            SET_BIT((RCC->RCC_AHB2ENR_Reg),(Periphral_ID % 32));
            break;
        case AHB3:
            SET_BIT((RCC->RCC_AHB3ENR_Reg),(Periphral_ID % 32));
            break;
        case APB1:
            SET_BIT((RCC->RCC_APB1ENR_Reg),(Periphral_ID % 32));
            break;
        case APB2:
            if(( (Periphral_ID == APB2_CLK_ADC1) || (Periphral_ID == APB2_CLK_ADC2) || (Periphral_ID == APB2_CLK_ADC3)))
            {
                SET_BIT((RCC->RCC_APB2ENR_Reg),(APB2_CLK_ADC1 % 32));
            }
            else
            {
                /*Nothing*/
            }
            break;
        
        default:
            break;
        }
    }
}
void RCC_void_RCC_Periphral_LPClk_En(uint_8 Periphral_ID, uint_8 Bus_ID)
{
    if(Bus_ID > 4 || Bus_ID < 0)
    {
        /*Nothing*/
    }
    else
    {
        switch (Bus_ID)
        {
        case AHB1:
            SET_BIT((RCC->RCC__AHB1LPENR_Reg),(Periphral_ID % 32));
            break;
        case AHB2:
            SET_BIT((RCC->RCC__AHB2LPENR_Reg),(Periphral_ID % 32));
            break;
        case AHB3:
            SET_BIT((RCC->RCC__AHB3LPENR_Reg),(Periphral_ID % 32));
            break;
        case APB1:
            SET_BIT((RCC->RCC_APB1LPENR_Reg),(Periphral_ID % 32));
            break;
        case APB2:
            SET_BIT((RCC->RCC_APB2LPENR_Reg),(Periphral_ID % 32));
            break;
        
        default:
            break;
        }
    }
}

/******************** Software Interfaces Declarations End   **********************/
