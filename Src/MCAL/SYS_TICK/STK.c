/**
 ******************************************************************************
 * @file           : STK.c
 * @author         : Ahmed Abdalla
 * @brief          : Contains Implementation of System Timer interfaces
 * @date		   : 10 Dec 2023 
 ******************************************************************************
 */



/******************** Include Start **********************/
#include "../../../Inc/MCAL/SYS_TICK/STK.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/

/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/
/******************** Data Type Declarations End   **********************/

/* Define Callback Global Variable */
static void (*STK_CallBack) (void) = NULL;

/* Define Variable for interval mode */
static uint_8 STK_ModeOfInterval;

/******************** Software Interfaces Implementation Start **********************/
/**
 * @brief Initializes the SysTick timer.
 * @return Returns a status code indicating the success or failure of the initialization.
 */
STD_Return_t STK_Init(void)
{
    uint_8 ret = Not_OK;
#if STK_CLK_SRC == STK_CLK_SRC_AHB
    SET_BIT((STK->STK_CTRL_REG) , CTRL_CLKSOURCE );
    ret = OK;
#elif STK_CLK_SRC == STK_CLK_SRC_AHB_8
    CLR_BIT((STK->STK_CTRL_REG) , CTRL_CLKSOURCE );
    ret = OK;
#else
    ret = Not_OK;
#endif

#if STK_INTERRUPT == STK_INTERRUPT_ENABLE
    SET_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
    ret = OK;
#elif STK_INTERRUPT == STK_INTERRUPT_DISABLE
    CLR_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
    ret = OK;
#else
    ret = Not_OK;
#endif
    STK->STK_LOAD_REG = 0;
    STK->STK_VAL_REG = 0;

    return ret;
}

/**
 * @brief Deinitializes the SysTick timer.
 * @return Returns a status code indicating the success or failure of the deinitialization.
 */
STD_Return_t STK_Deinit(void)
{
    uint_8 ret = Not_OK;
    CLR_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE );
    if(READ_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE) == 0)
    {
        ret = OK;
    }
    else
    {
        /*Noting*/
    }
    return ret;
}

/**
 * @brief Sets the SysTick timer for busy waiting.
 * @param Copy_u32Ticks: The number of ticks to wait.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Busy_Wait(uint_32 Copy_u32Ticks)
{
    uint_8 ret = Not_OK;
    if((!(0xffffff >= Copy_u32Ticks)))
    {
        /*Nothing*/
    }
    else
    {
        /* Load ticks to load register */
        STK->STK_LOAD_REG = Copy_u32Ticks;
        /*Disable Interrupt*/
        CLR_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
        /* Start Timer */
        SET_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);
        /* Wait till flag is raised */
        while (READ_BIT((STK->STK_CTRL_REG) , CTRL_COUNTFLAG));
        /* Stop Timer */
        CLR_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);
        STK->STK_LOAD_REG = 0;
        STK->STK_VAL_REG = 0;
        ret = OK;
    }
    return ret;
}

/**
 * @brief Sets a single-shot interval on the SysTick timer.
 * @param Copy_u32Ticks: The number of ticks for the interval.
 * @param Copy_ptr: Pointer to the function to be executed after the interval.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Interval_Single(uint_32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    uint_8 ret = Not_OK;
    if( (!(0xffffff >= Copy_u32Ticks)) || (NULL == Copy_ptr))
    {
        /*Nothing*/
    }
    else
    {
        /* Load ticks to load register */
        STK->STK_LOAD_REG = Copy_u32Ticks;
        
        /* Save CallBack */
	    STK_CallBack = Copy_ptr;
        /* Set Mode to Single */
	    STK_ModeOfInterval = STK_SINGLE_INTERVAL;
        /*Enable Interrupt*/
        SET_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
        /* Start Timer */
        SET_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);

        ret = OK;
    }
    return ret;
}

/**
 * @brief Sets a periodic interval on the SysTick timer.
 * @param Copy_u32Ticks: The number of ticks for the interval.
 * @param Copy_ptr: Pointer to the function to be executed after each interval.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Interval_Periodic(uint_32 Copy_u32Ticks, void (*Copy_ptr)(void))
{
    uint_8 ret = Not_OK;
    if((!(0xffffff >= Copy_u32Ticks)) || (NULL == Copy_ptr))
    {
        /*Nothing*/
    }
    else
    {
        /* Load ticks to load register */
        STK->STK_LOAD_REG = Copy_u32Ticks;
        
        /* Save CallBack */
	    STK_CallBack = Copy_ptr;
        /* Set Mode to Single */
	    STK_ModeOfInterval = STK_PERIOD_INTERVAL;
        /*Enable Interrupt*/
        SET_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
        /* Start Timer */
        SET_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);

        ret = OK;
    }
    return ret;
}

/**
 * @brief Stops the currently active interval on the SysTick timer.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Stop_Interval(void)
{
    uint_8 ret = Not_OK;

    /* Stop Timer */
    CLR_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);
    STK->STK_LOAD_REG = 0;
    STK->STK_VAL_REG = 0;
    /*Disable Interrupt*/
    CLR_BIT((STK->STK_CTRL_REG) , CTRL_TICKINT );
    if(READ_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE) == 0)
    {
        ret = OK;
    }
    else{ /*Noting*/}
    return ret;
}

/**
 * @brief Retrieves the elapsed time since the last SysTick timer start or reset.
 * @return Returns the elapsed time in ticks.
 */
uint_32 STK_u32_Get_Elapsed_Time(void)
{
    return (uint_32)((STK->STK_LOAD_REG) - (STK->STK_VAL_REG));
}

/**
 * @brief Retrieves the remaining time for the active interval on the SysTick timer.
 * @return Returns the remaining time in ticks.
 */
uint_32 STK_u32_Get_Remaining_Time(void)
{
    return (uint_32)((STK->STK_VAL_REG));
}
/******************** Software Interfaces Declarations End   **********************/


void SysTick_Handler(void)
{
    uint_8 temp = 0;
    
    if( STK_SINGLE_INTERVAL == STK_ModeOfInterval)
    {
        /* Stop Timer */
        CLR_BIT((STK->STK_CTRL_REG) , CTRL_ENABLE);
        STK->STK_LOAD_REG = 0;
        STK->STK_VAL_REG = 0;
    }
    else
    {/*Nothing*/}

    STK_CallBack();

    /* Clear interrupt flag */
	temp = READ_BIT((STK->STK_CTRL_REG),CTRL_COUNTFLAG);

}
