/*!
 * \file composite_usb_ep.c
 *
 * \brief 
 *
 *
 * \date Mar 19, 2011
 * \author Dan Riedler
 *
 */

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "composite_usb_ep.h"
#include "usb/pwr/hw_usb_pwr.h"

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

PROTECTED pCOMPOSITE_USB_ReadVirComCallBack CompositeUsbVirComCallback;

//*****************************************************************************
//
// Exported Functions
//
//*****************************************************************************

PROTECTED Result CompositeUsbEpInit( void )
{

    CompositeUsbVirComCallback = NULL;

    return COMPOSITE_USB_RESULT(SUCCESS);
}


//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************
