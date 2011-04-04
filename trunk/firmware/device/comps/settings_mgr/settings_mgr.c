/*!
 * \file settings_mgr.c
 *
 * \brief 
 *
 *
 * \date Apr 3, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "settings_mgr.h"


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

//****************************************************************************/
PUBLIC Result SETTINGS_MGR_Init( void )
{
    Result result = SETTINGS_MGR_RESULT(SETTINGS_MGR_RESULT_SUCCESS);


    return result;
}


//****************************************************************************/
PUBLIC Result SETTINGS_MGR_PowerUp( void )
{
    Result result = SETTINGS_MGR_RESULT_INIT();

    return result;
}


//****************************************************************************/
PUBLIC Result SETTINGS_MGR_PowerDown( void )
{
    Result result = SETTINGS_MGR_RESULT_INIT();

    return result;
}

//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************

