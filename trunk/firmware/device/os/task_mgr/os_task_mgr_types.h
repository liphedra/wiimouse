/*!
 * \file os_task_mgr_types.h
 *
 * \brief 
 *
 *
 * \date Mar 6, 2011
 * \author Dan Riedler
 *
 */

#ifndef _OS_TASK_MGR_TYPES_H_
#define _OS_TASK_MGR_TYPES_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "device.h"
#include "os_conf.h"

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/
PUBLIC typedef void (OS_TASK_MGR_TaskProtoType)(void*);
PUBLIC typedef void (*pOS_TASK_MGR_TaskProtoType)(void*);

PUBLIC typedef struct {
    char Name[OS_TASK_NAME_LEN];
    pOS_TASK_MGR_TaskProtoType StartAddr;
    uint32 StackSize;
    uint32 Priority;
    void* Parameter;
    void* Handle;
} OS_TASK_MGR_TaskInfo, *pOS_TASK_MGR_TaskInfo;

/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* OS_TASK_MGR_TYPES_H_ */
