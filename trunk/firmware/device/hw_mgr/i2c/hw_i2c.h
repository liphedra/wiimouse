/*!
 * \file hw_i2c.h
 *
 * \brief 
 *
 *
 * \date Apr 3, 2011
 * \author Dan Riedler
 *
 */

#ifndef _HW_I2C_H_
#define _HW_I2C_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "device.h"
#include "hw_mgr.h"
#include "hw_i2c_result.h"
#include "hw_mgr_types.h"
#include "hw_i2c_types.h"


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
 Exported Function Prototypes
------------------------------------------------------------------------------*/

PUBLIC HwModuleInitPrototype HW_I2C_Init;

PUBLIC HwModulePowerUpPrototype HW_I2C_PowerUp;

PUBLIC HwModulePowerDownPrototype HW_I2C_PowerDown;

PUBLIC Result HW_I2C_ReadSlave(HW_I2C_BlockId Id, uint8 SlaveAddress, uint8 Register, uint8 *Buffer, uint32 BytesToRead, uint32 *BytesRead);

PUBLIC Result HW_I2C_WriteSlave(HW_I2C_BlockId Id, uint8 SlaveAddress, uint8 *Buffer, uint32 BytesToWrite, uint32 *ByteWritten);

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* HW_I2C_H_ */
