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
/**
 * @brief Enable the clock for a specific peripheral on a specified bus.
 *
 * This function enables the clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to enable the clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_Clk_En(const uint_8 Periphral_ID, const uint_8 Bus_ID)
{
    STD_Return_t Ret = Not_OK;
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
        Ret = OK;
    }
    return Ret;
}

/**
 * @brief Reset the clock for a specific peripheral on a specified bus.
 *
 * This function resets the clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to reset the clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_Clk_RST(const uint_8 Periphral_ID, const uint_8 Bus_ID)
{
    STD_Return_t Ret = Not_OK;
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
        Ret = OK;
    }
    return Ret;
}

/**
 * @brief Enable the low-power clock for a specific peripheral on a specified bus.
 *
 * This function enables the low-power clock for a specific peripheral on the specified bus.
 *
 * @param[in] Periphral_ID Identifier of the peripheral to enable the low-power clock for.
 * @param[in] Bus_ID Identifier of the bus on which the peripheral is connected.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Periphral_LPClk_En(const uint_8 Periphral_ID, const uint_8 Bus_ID)
{
    STD_Return_t Ret = Not_OK;
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
        Ret = OK;
    }
    return Ret;
}

/**
 * @brief Set the clock configuration for different buses.
 *
 * This function sets the clock configuration for different buses using the provided configuration structure.
 *
 * @param[in] Config_BUS_CLK Pointer to the configuration structure holding bus clock division factors.
 *
 * @return STD_Return_t Status of the operation.
 */
STD_Return_t RCC_void_RCC_Set_Bus_CLK(const BUS_CLK *const Config_BUS_CLK)
{
    uint_32 Ret = Not_OK;
    if(NULL == Config_BUS_CLK)
    {
        /*Nothing*/
    }
    else
    {
        MODIFY_REG((RCC->RCC_CFGR_Reg) , HPRE_BIT_MSK ,(Config_BUS_CLK->AHB_DIV_FACT) );
        MODIFY_REG((RCC->RCC_CFGR_Reg) , PPRE1_BIT_MSK ,(Config_BUS_CLK->APB1_DIV_FACT) );
        MODIFY_REG((RCC->RCC_CFGR_Reg) , PPRE2_BIT_MSK ,(Config_BUS_CLK->APB2_DIV_FACT) );
        Ret = OK;
    }
    return Ret;
}

/******************** Software Interfaces Declarations End   **********************/
