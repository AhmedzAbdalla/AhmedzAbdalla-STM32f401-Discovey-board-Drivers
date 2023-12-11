/**
 ******************************************************************************
 * @file           : GPIO.h
 * @author         : Ahmed Abdalla
 * @brief          : Contains declarations of interfaces and users macros
 * @date		   : 11 Dec 2023 
 ******************************************************************************
 */


/******************** Include Start **********************/
#include "./GPIO_Mem_Map.h"
/******************** Include End **********************/
/******************** Macro Declarations Start **********************/
//Pin Modes
#define INPUT           0UL
#define OUTPUT          1UL
#define AF              2UL
#define ANALOG          3UL

//Pin output states
#define push_pull       0UL
#define open_drain      1UL

//I/O output pins speed
#define Low_speed       0UL
#define Medium_speed    1UL
#define High_speed      2UL
#define Very_high_speed 3UL

//I/O Input pins State
#define FLOATING        0UL // No pull-up, pull-down
#define PULL_UP         1UL
#define PULL_DOWN       2UL

// I/O output pins Sense level
#define SET             1UL
#define RST             0UL

/******************** Macro Declarations End   **********************/
/******************** Macro Function Declarations Start **********************/
/******************** Macro Function Declarations End   **********************/

/******************** Data Type Declarations Start **********************/
typedef enum
{
    PIN_OUTPUT,
    PIN_INPUT
} Port_PinDirectionType;
typedef enum
{
    /*GPIOA Pins IDs*/
    PA_0 = 0, PA_1, PA_2, PA_3, PA_4, PA_5, PA_6, PA_7, PA_8, PA_9, PA_10, PA_11, PA_12, PA_13, PA_14, PA_15,

    /*GPIOB Pins IDs*/
    PB_0 = 16, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7, PB_8, PB_9, PB_10, PB_11, PB_12, PB_13, PB_14, PB_15,

    /*GPIOC Pins IDs*/
    PC_0 = 32, PC_1, PC_2, PC_3, PC_4, PC_5, PC_6, PC_7, PC_8, PC_9, PC_10, PC_11, PC_12, PC_13, PC_14, PC_15,

    /*GPIOD Pins IDs*/
    PD_0 = 48, PD_1, PD_2, PD_3, PD_4, PD_5, PD_6, PD_7, PD_8, PD_9, PD_10, PD_11, PD_12, PD_13, PD_14, PD_15,

    /*GPIOE Pins IDs*/
    PE_0 = 64, PE_1, PE_2, PE_3, PE_4, PE_5, PE_6, PE_7, PE_8, PE_9, PE_10, PE_11, PE_12, PE_13, PE_14, PE_15,

    /*GPIOF Pins IDs*/
    PF_0 = 80, PF_1, PF_2, PF_3, PF_4, PF_5, PF_6, PF_7, PF_8, PF_9, PF_10, PF_11, PF_12, PF_13, PF_14, PF_15,

    /*GPIOG Pins IDs*/
    PG_0 = 96, PG_1, PG_2, PG_3, PG_4, PG_5, PG_6, PG_7, PG_8, PG_9, PG_10, PG_11, PG_12, PG_13, PG_14, PG_15,

    /*GPIOH Pins IDs*/
    PH_0 = 112, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7, PH_8, PH_9, PH_10, PH_11, PH_12, PH_13, PH_14, PH_15,

    /*GPIOI Pins IDs*/
    PI_0 = 128, PI_1, PI_2, PI_3, PI_4, PI_5, PI_6, PI_7, PI_8, PI_9, PI_10, PI_11, PI_12, PI_13, PI_14, PI_15

}PIN_ID_t;
/******************** Data Type Declarations End   **********************/

/******************** Software Interfaces Declarations Start **********************/
STD_Return_t GPIO_void_Set_Pin_Mode(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_mode);
STD_Return_t GPIO_void_Set_Pin_Type(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_u8_Type );
STD_Return_t GPIO_void_Set_Pin_Speed(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_Speed );
STD_Return_t GPIO_void_Set_Pin_Pull_State(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_Pull_State );
STD_Return_t GPIO_void_Set_Pin_Value_Non_Atomic(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_Sense_level );
STD_Return_t GPIO_void_Set_Pin_Value_Atomic(const PIN_ID_t Copy_Pin_ID, const uint_8 Copy_Sense_level );
STD_Return_t GPIO_u8_Set_Pin_Get_Value(const PIN_ID_t Copy_Pin_ID, uint_8 *const Ref_Data );
/******************** Software Interfaces Declarations End   **********************/