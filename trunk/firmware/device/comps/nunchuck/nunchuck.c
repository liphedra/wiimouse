/*!
 * \file nunchuck.c
 *
 * \brief 
 *
 *
 * \date Apr 9, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "nunchuck.h"
#include "nunchuck/settings/nunchuck_settings.h"
#include "nunchuck/processor/nunchuck_processor.h"
#include "nunchuck/statemachine/nunchuck_sm.h"
#include "nunchuck/ctl/nunchuck_ctl.h"


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
PUBLIC Result NUNCHUCK_Init( void )
{
    Result result = NUNCHUCK_RESULT(SUCCESS);



    if( RESULT_IS_ERROR(result, NunchuckSettingsInit()) )
    {
    }
    else if( RESULT_IS_ERROR(result, NunchuckReaderInit()) )
	{
	}
	else if( RESULT_IS_ERROR(result, NunchuckProcessorInit()) )
	{
	}
	else if( RESULT_IS_ERROR(result, NunchuckHidReporterInit()) )
	{
	}
	else if( RESULT_IS_ERROR(result, NunchuckCtlInit()) )
	{
	}
	else if( RESULT_IS_ERROR(result, NunchuckSmInit()) )
	{
	}


    return result;
}


//****************************************************************************/
PUBLIC Result NUNCHUCK_PowerUp( void )
{
    Result result = NUNCHUCK_RESULT_INIT();

    return result;
}


//****************************************************************************/
PUBLIC Result NUNCHUCK_PowerDown( void )
{
    Result result = NUNCHUCK_RESULT_INIT();

    return result;
}


//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************

