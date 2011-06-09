/*!
 * \file device_config.h
 *
 * \brief 
 *
 *
 * \date Mar 3, 2011
 * \author Dan Riedler
 *
 */

#ifndef _DEVICE_CONF_H_
#define _DEVICE_CONF_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include <platform_lib.h>

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*!
 * \brief This defines which device modules to use
 */
#define DEV_MOD_HW_MGR              // Hardware Manager module
#define DEV_MOD_LOG                 // Logging module
#define DEV_MOD_OS                  // Operating System module
#define DEV_MOD_SETTINGS            // Settings module
#define DEV_MOD_COMM_MGR            // Communication Manager module
#define DEV_MOD_COMPS               // Components module

#define DEV_UTIL_TIMER              // Timer utility
#define DEV_UTIL_TIMEOUT            // Timeout utility
#define DEV_UTIL_DELAY              // Delay utility



#if defined STM32F10X_MD || defined STM32F10X_HD

/*!
 * \brief Default (logging) USART config
 */
#define DEFAULT_USART_BUAD          115200
#define DEFAULT_USART_STOP_BITS     USART_StopBits_1
#define DEFAULT_USART_PARITY        USART_Parity_No
#define DEFAULT_USART_WORD_LEN      USART_WordLength_8b
#define DEFAULT_USART_FLOW_CTL      USART_HardwareFlowControl_None


/*!
 * \brief Device Clock Speed
 */
#define DEVICE_CLOCK_RATE 72000000 // 72MHz

/*!
 * \brief Vector Table Offset
 * from the base of memory
 */
#define DEVICE_VECTOR_TABLE_OFFSET (DEVICE_START_ADDR - BOOTLOADER_START_ADDR)



#endif


/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* DEVICE_CONFIG_H_ */
