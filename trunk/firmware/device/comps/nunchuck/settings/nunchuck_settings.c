/*!
 * \file nunchuck_settings.c
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
#include "nunchuck_settings.h"
#include "settings_mgr/settings_mgr.h"


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
PROTECTED NunchuckSettingsInfo NunchuckSettings;



//*****************************************************************************
//
// Exported Functions
//
//*****************************************************************************


//****************************************************************************/
PROTECTED Result NunchuckSettingsInit( void )
{
    //uint16 bytesRead;

    //return SETTINGS_MGR_Read(SETTINGS_MGR_ENTRY_NUNCHUCK_SETTINGS, &NunchuckSettings, sizeof(NunchuckSettingsInfo), &bytesRead);

    NunchuckSettings.DataPointsPerHidReport = 10;
    NunchuckSettings.HidReportInterval = 10;
    NunchuckSettings.ProfileIndex = 0;

    return NUNCHUCK_RESULT(SUCCESS);
}


//****************************************************************************/
PROTECTED Result NunchuckSettingsUpdate( void )
{
    return SETTINGS_MGR_Write(SETTINGS_MGR_ENTRY_NUNCHUCK_SETTINGS, &NunchuckSettings, sizeof(NunchuckSettingsInfo), FEEPROM_ENTRY_FLAG_FORCE_WRITE);
}



//*****************************************************************************
//
// Local Functions
//
//*****************************************************************************

