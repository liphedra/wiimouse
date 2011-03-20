/*!
 * \file os.h
 *
 * \brief 
 *
 *
 * \date Mar 6, 2011
 * \author Dan Riedler
 *
 */

#ifndef _OS_H_
#define _OS_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "device.h"
#include "os_modules.h"
#include "os_result.h"
#include "os_types.h"

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/
#define OS_SEM_WAIT_INFINITE 0xffffffff

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/
/*!****************************************************************************
 * /brief Hardware Initialization
 *
 * This initializes all hardware based on the hardware configuration.
 *
 * /param
 * /return
 ******************************************************************************/
PUBLIC ModuleInitPrototype OS_Init;

PUBLIC Result OS_CreateSemaphore(pOS_Semaphore *Semaphore, OS_SemaphoreType SemType, uint32 InitValue, uint32 MaxCount );

PUBLIC Result OS_DestroySemaphore(pOS_Semaphore Semaphore);

PUBLIC Result OS_GiveSemaphore(pOS_Semaphore Semaphore);

PUBLIC Result OS_TakeSemaphore(pOS_Semaphore Semaphore, uint32 BlockTime );

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* OS_H_ */