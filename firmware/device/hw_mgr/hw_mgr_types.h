/*!
 * \file hw_mgr_types.h
 *
 * \brief 
 *
 *
 * \date Mar 5, 2011
 * \author Dan Riedler
 *
 */

#ifndef _HW_MGR_TYPES_H_
#define _HW_MGR_TYPES_H_

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
typedef Result (HwModulePowerUpPrototype)( uint32 );
typedef Result (*pHwModulePowerUpPrototype)( uint32 );

typedef Result (HwModulePowerDownPrototype)( uint32 );
typedef Result (*pHwModulePowerDownPrototype)( uint32 );

typedef Result (HwModuleInitPrototype)( uint32, void* );
typedef Result (*pHwModuleInitPrototype)( uint32, void* );


/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* HW_MGR_TYPES_H_ */
