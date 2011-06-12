/*!
 * \file nunchuck_filter_acc.c
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
#include "nunchuck_filter_acc.h"


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

//*****************************************************************************//

// TODO: actually filter the acclerometer data
PROTECTED void NunchuckFilterAccelerometerData( void )
{
    int8 newest;

    newest = NunchuckRawData.NextPoint - 1;
    if(newest < 0) newest = NunchuckRawData.TotalDataPtCount - 1;

}


//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************
