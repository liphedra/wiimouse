/*!
 * \file os_tasks.h
 *
 * \brief 
 *
 *
 * \date Mar 8, 2011
 * \author Dan Riedler
 *
 */

#ifndef _OS_TASKS_H_
#define _OS_TASKS_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "device.h"

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/
PUBLIC typedef enum {
    OS_TASK_IDLE,
    OS_TASK_PACKET_MGR,
    OS_TASK_NUNCHUCK_DATA_PROCESSOR,
    OS_TASK_NUNCHUCK_DATA_REPORTER,
    OS_TASK_COUNT
} OS_TaskId;



PUBLIC typedef enum {
    OS_TASK_PRIORITY_IDLE  = 0,
    OS_TASK_PRIORITY_LOWEST = OS_TASK_PRIORITY_IDLE,
    OS_TASK_PRIORITY_HIGHEST = (OS_MAX_PRIORITIES-1),
    OS_TASK_PRIORITY_MEDIUM = ((OS_TASK_PRIORITY_HIGHEST - OS_TASK_PRIORITY_LOWEST)/2),
} OS_TaskPriorities;


/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* OS_TASKS_H_ */
