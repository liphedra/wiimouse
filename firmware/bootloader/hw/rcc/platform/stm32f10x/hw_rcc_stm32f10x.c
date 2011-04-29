/*!
 * \file hw_rcc_stm32f10x.c
 *
 * \brief 
 *
 *
 * \date Mar 5, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include <platform_lib.h>
#include "rcc/hw_rcc.h"

#ifdef STM32F10X_MD

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Local Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Data Members
------------------------------------------------------------------------------*/


//*****************************************************************************
//
// Exported Functions
//
//*****************************************************************************
PUBLIC uint32 HW_RCC_ApbPeriphGpio[HW_RCC_APB_PERIPH_GPIO_COUNT] =
{
#ifdef RCC_APB2Periph_GPIOA
        RCC_APB2Periph_GPIOA,
#else
        NULL,
#endif
#ifdef RCC_APB2Periph_GPIOB
        RCC_APB2Periph_GPIOB,
#else
        NULL,
#endif
#ifdef RCC_APB2Periph_GPIOC
        RCC_APB2Periph_GPIOC,
#else
        NULL,
#endif
#ifdef RCC_APB2Periph_GPIOD
        RCC_APB2Periph_GPIOD,
#else
        NULL,
#endif
#ifdef RCC_APB2Periph_GPIOE
        RCC_APB2Periph_GPIOE,
#else
        NULL,
#endif
};



//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************


#endif
