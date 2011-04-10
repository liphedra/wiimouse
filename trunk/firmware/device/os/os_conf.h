/*!
 * \file os_conf.h
 *
 * \brief 
 *
 *
 * \date Mar 6, 2011
 * \author Dan Riedler
 *
 */

#ifndef _OS_CONF_H_
#define _OS_CONF_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "device_conf.h"

#ifdef DEV_MOD_OS


#ifndef FREERTOS
#error OS Module enable but no RTOS defined. Define a preprocessor os platform. Supported OS platforms: FREERTOS
#endif

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/


#define OS_MOD_TASK_MGR
//#define OS_MOD_SEM_MGR
//#define OS_MOD_MEM_MGR
//#define OS_MOD_EVNT_MGR

#define OS_TASK_NAME_LEN                16
#define OS_TICK_RATE_HZ                 1000
#define OS_MAX_PRIORITIES               5
#define OS_MIN_STACK_SIZE               120
#define OS_TOTAL_HEAP_SIZE              ( 4 * 1024 )

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


#endif

#endif /* OS_CONF_H_ */
