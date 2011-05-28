/*!
 * \file os_task_mge_freertos.c
 *
 * \brief 
 *
 *
 * \date Mar 6, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include <os_platform.h>
#include "task_mgr/os_task_mgr.h"

#ifdef FREERTOS
#ifdef OS_MOD_TASK_MGR

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


/***************************************************************************/
PUBLIC inline Result OS_TASK_MGR_StartScheduler( void )
{
    vTaskStartScheduler();

    // shouldn't get to this point if every worked fine

    return OS_TASK_MGR_RESULT(START_SCHEDULER_FAIL);
}


/***************************************************************************/
PUBLIC inline Result OS_TASK_MGR_SuspendTask(OS_TaskHandle Handle)
{

	vTaskSuspend((xTaskHandle)Handle);
	return OS_TASK_MGR_RESULT(SUCCESS);
}


/***************************************************************************/
PUBLIC inline Result OS_TASK_MGR_ResumeTask(OS_TaskHandle Handle)
{
	vTaskResume((xTaskHandle)Handle);
	return OS_TASK_MGR_RESULT(SUCCESS);
}


/***************************************************************************/
PROTECTED inline Result TaskMgrCreateTask( pOS_TaskProtoType StartAddress,
                                           char* Name, uint32 StackSize,
                                           void* Parameter,
                                           OS_TaskPriorities Priority,
                                           pOS_TaskHandle Handle )
{
    Result result =  OS_TASK_MGR_RESULT(SUCCESS);
    signed portBASE_TYPE retval;

    if( (retval = xTaskCreate( (pdTASK_CODE)StartAddress, ( signed char * ) Name, StackSize, Parameter, Priority, (xTaskHandle*)Handle )) != pdPASS )
    {
        switch( retval )
        {
        case errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY:
            result = OS_TASK_MGR_RESULT(NOT_ENOUGH_MEM);
        }
    }

    return result;
}




//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************

#endif
#endif
