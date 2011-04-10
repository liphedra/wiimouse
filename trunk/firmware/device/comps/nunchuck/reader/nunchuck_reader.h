/*!
 * \file nunchuck_reader.h
 *
 * \brief 
 *
 *
 * \date Apr 9, 2011
 * \author Dan Riedler
 *
 */

#ifndef _NUNCHUCK_READER_H_
#define _NUNCHUCK_READER_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "nunchuck/nunchuck.h"


/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/
PROTECTED typedef struct {
    uint8 TotalDataPtCount;
    uint8 LastPoint;
    bool NewDataAvailable;
    pNunchuckData DataPts;
} NunchuckRawDataInfo;


/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/
PROTECTED Result NunchuckReaderInit( void );

PUBLIC void NUNCHUCK_READER_ReadDataPoint( void );


/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/
PROTECTED extern NunchuckRawDataInfo NunchuckRawData;

#endif /* NUNCHUCK_READER_H_ */
