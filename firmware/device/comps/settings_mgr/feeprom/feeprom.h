/*!
 * \file feeprom.h
 *
 * \brief 
 *
 *
 * \date Apr 3, 2011
 * \author Dan Riedler
 *
 */

#ifndef _FEEPROM_H_
#define _FEEPROM_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "settings_mgr/settings_mgr.h"
#include "feeprom_types.h"

/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/
#define FEEPROM_ADD_ENTRY(key, data, size, flag)



/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

PUBLIC Result FEEPROM_Init( void );

PUBLIC Result FEEPROM_Write( FEEPROM_EntryKey key, void *data, uint16 size, FEEPROM_EntryFlag flags);

PUBLIC Result FEEPROM_Read( FEEPROM_EntryKey key, void *data, uint16 size, uint16 *bytesRead);

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* FEEPROM_H_ */
