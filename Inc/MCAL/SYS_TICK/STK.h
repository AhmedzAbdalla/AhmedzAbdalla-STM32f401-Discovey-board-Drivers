/**
 ******************************************************************************
 * @file           : STK.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains declaration of System Timer interfaces and its memory map
 * @date		   : 10 Dec 2023 
 ******************************************************************************
 */


/******************** Include Start **********************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/
#define STK                    ((STK_T *)(0xE000E010UL))

/*STK_CTRL_REG macros*/
#define CTRL_ENABLE            0UL
#define CTRL_TICKINT           1UL
#define CTRL_CLKSOURCE         2UL
#define CTRL_COUNTFLAG         16UL
/*Macros to select the clock source for system timer*/
#define STK_CLK_SRC_AHB        0UL
#define STK_CLK_SRC_AHB_8      1UL

#define STK_CLK_SRC            STK_CLK_SRC_AHB

/*Macros to select operation mode for system timer*/
#define STK_SINGLE_INTERVAL    0UL
#define STK_PERIOD_INTERVAL    1UL

#define STK_OP_MODE            STK_SINGLE_INTERVAL

/*Macros to enable or disable interrupts for system timer*/
#define STK_INTERRUPT_ENABLE    0UL
#define STK_INTERRUPT_DISABLE   1UL

#define STK_INTERRUPT           STK_INTERRUPT_DISABLE
/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/
typedef struct
{
    volatile uint_32  STK_CTRL_REG;
    volatile uint_32  STK_LOAD_REG;
    volatile uint_32  STK_VAL_REG;
    volatile uint_32  STK_CALIB_REG;

}STK_T;
/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
/**
 * @brief Initializes the SysTick timer.
 * @return Returns a status code indicating the success or failure of the initialization.
 */
STD_Return_t STK_Init(void);

/**
 * @brief Deinitializes the SysTick timer.
 * @return Returns a status code indicating the success or failure of the deinitialization.
 */
STD_Return_t STK_Deinit(void);

/**
 * @brief Sets the SysTick timer for busy waiting.
 * @param Copy_u32Ticks: The number of ticks to wait.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Busy_Wait(uint_32 Copy_u32Ticks);

/**
 * @brief Sets a single-shot interval on the SysTick timer.
 * @param Copy_u32Ticks: The number of ticks for the interval.
 * @param Copy_ptr: Pointer to the function to be executed after the interval.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Interval_Single(uint_32 Copy_u32Ticks, void (*Copy_ptr)(void));

/**
 * @brief Sets a periodic interval on the SysTick timer.
 * @param Copy_u32Ticks: The number of ticks for the interval.
 * @param Copy_ptr: Pointer to the function to be executed after each interval.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Set_Interval_Periodic(uint_32 Copy_u32Ticks, void (*Copy_ptr)(void));

/**
 * @brief Stops the currently active interval on the SysTick timer.
 * @return Returns a status code indicating the success or failure of the operation.
 */
STD_Return_t STK_Stop_Interval(void);

/**
 * @brief Retrieves the elapsed time since the last SysTick timer start or reset.
 * @return Returns the elapsed time in ticks.
 */
uint_32 STK_u32_Get_Elapsed_Time(void);

/**
 * @brief Retrieves the remaining time for the active interval on the SysTick timer.
 * @return Returns the remaining time in ticks.
 */
uint_32 STK_u32_Get_Remaining_Time(void);
/******************** Software Interfaces Declarations End   **********************/


