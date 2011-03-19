/*!
 * \file hw.c
 *
 * \brief 
 *
 *
 * \date Mar 3, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "hw_mgr.h"

#ifdef DEV_MOD_HW_MGR

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

/******************************************************************************/
Result HW_MGR_Init( void )
{
    LOG_RegisterModule(MOD_MGR_HW_MGR, NULL_MOD, TRUE);


    hwMgrModules[HW_MGR_USB].Init(0, 0);


    return HW_MGR_RESULT(HW_MGR_RESULT_SUCCESS);
}




//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************

#endif
