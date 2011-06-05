/*!
 * \file hw.h
 *
 * \brief 
 *
 *
 * \date Apr 28, 2011
 * \author Dan Riedler
 *
 */

#ifndef _HW_H_
#define _HW_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include <platform_lib.h>

#include "system.h"
#include "hw_conf.h"

#include "hw/usart/hw_usart.h"
#include "hw/sysclk/hw_sysclk.h"
#include "hw/sysinit/hw_sysinit.h"
#include "hw/nvic/hw_nvic.h"
#include "hw/usb/hw_usb.h"

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
PUBLIC void HW_Init( void );


/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/


#endif /* HW_H_ */