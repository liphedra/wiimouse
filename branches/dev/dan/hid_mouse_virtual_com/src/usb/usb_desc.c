/******************** (C) COPYRIGHT 2010 STMicroelectronics ********************
 * File Name          : usb_desc.c
 * Author             : MCD Application Team
 * Version            : V3.2.1
 * Date               : 07/05/2010
 * Description        : Descriptors for Virtual Com Port Demo
 ********************************************************************************
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
 * AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
 * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
 * CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
 * INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_conf.h"

/* USB Standard Device Descriptor */
const uint8 Virtual_Com_Port_DeviceDescriptor[USB_DEVICE_DESCRIPTOR_SIZE] =
{
		USB_DEVICE_DESCRIPTOR_SIZE,        /* bLength */
		USB_DEVICE_DESCRIPTOR_TYPE,        /* bDescriptorType */
		WBVAL(0x0110), /* 2.0 */           /* bcdUSB */
		USB_DEVICE_CLASS_MISC,        	   	/* bDeviceClass */
		0x02,                              /* bDeviceSubClass: common */
		0x01,                              /* bDeviceProtocol: IAD */
		0x40,                              /* bMaxPacketSize0 (64 bytes) */
		WBVAL(0xF46D),    					/* idVendor */
		WBVAL(0xF52B),   					/* idProduct */
		WBVAL(0x0000),        				/* 2.00 */   /* bcdDevice */
		1,									/*Index of string descriptor describing manufacturer */
		2,									/*Index of string descriptor describing product*/
		3, 									/*Index of string descriptor describing the device serial number */
		0x01                               /* bNumConfigurations */
};

const uint8 Virtual_Com_Port_ConfigDescriptor[DEVICE_CONFIGURATION_DESCRIPTOR_SIZE] =
{
		USB_CONFIGURATION_DESCRIPTOR_SIZE, /* bLength */
		USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType */
		WBVAL(DEVICE_CONFIGURATION_DESCRIPTOR_SIZE),   /* wTotalLength */
		IFC_NUM,             		        /* bNumInterfaces */
		1,        							/* bConfigurationValue */
		0,									/* iConfiguration: Index of string descriptor describing the configuration*/
		USB_CONFIG_BUS_POWERED, /*|*/       /* bmAttributes */
		/*USB_CONFIG_REMOTE_WAKEUP*/
		USB_CONFIG_POWER_MA(100),          /* bMaxPower */

/********************************************************************************
 Interface 0, Generic HID Mouse
*********************************************************************************/
		USB_INTERFACE_DESCRIPTOR_SIZE,     	/* bLength */
		USB_INTERFACE_DESCRIPTOR_TYPE,     	/* bDescriptorType */
		HID_IFC_NUM,   					   	/* bInterfaceNumber */
		0x00,                              	/* bAlternateSetting */
		1,                                 	/* bNumEndpoints */
		USB_INTERFACE_CLASS_HUMAN_INTERFACE,  /* bInterfaceClass */
		HID_SUBCLASS_BOOT,                 /* bInterfaceSubClass */
		HID_PROTOCOL_MOUSE,                /* bInterfaceProtocol */
		0,									/* iInterface: Index of string descriptor */

/********************************************************************************
 HID Class Descriptor
*********************************************************************************/
		HID_DESCRIPTOR_SIZE,               /* bLength */
		HID_HID_DESCRIPTOR_TYPE,           /* bDescriptorType */
		WBVAL(0x0110), /* 1.10 */          /* bcdHID */
		0x00,                              /* bCountryCode */
		0x01,                              /* bNumDescriptors */
		HID_REPORT_DESCRIPTOR_TYPE,        /* bDescriptorType */
		WBVAL(HID_MOUSE_REPORT_DESCRIPTOR_SIZE),        /* wDescriptorLength */

/********************************************************************************
 Endpoint 1, HID Interrupt In
*********************************************************************************/

		USB_ENDPOINT_DESCRIPTOR_SIZE,		/* bLength */
		USB_ENDPOINT_DESCRIPTOR_TYPE,		/* bDescriptorType */
		USB_ENDPOINT_IN(1), 				/* bEndpointAddress */
		USB_ENDPOINT_TYPE_INTERRUPT,		/* bmAttributes */
		WBVAL(HID_MOUSE_REPORT_SIZE), 		/* wMaxPacketSize */
		0x20,                				/* bInterval  (32 ms) */

/********************************************************************************
 CDC Interface Association Descriptor
*********************************************************************************/								//
		INTERFACE_ASSOCIATION_DESCRIPTOR_SIZE,  	// bLength
		USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE,	// bDescriptorType = 11
		CDC_IFC_NUM,								// bFirstInterface
		0x02,										// bInterfaceCount
		USB_INTERFACE_CLASS_COMMUNICATIONS,			// bFunctionClass (Communication Class)
		CDC_SUBCLASS_ACM,							// bFunctionSubClass (Abstract Control Model)
		CDC_PROTOCOL_AT,							// bFunctionProcotol (V.25ter, Common AT commands)
		0x00,										// iInterface

/********************************************************************************
 Interface 0, Communications Device Control
*********************************************************************************/
		USB_INTERFACE_DESCRIPTOR_SIZE,     	/* bLength */
		USB_INTERFACE_DESCRIPTOR_TYPE, 		/* bDescriptorType */
		CDC_IFC_NUM,   						/* bInterfaceNumber */
		0x00,                 				/* bAlternateSetting */
		1,                                 	/* bNumEndpoints */
		USB_INTERFACE_CLASS_COMMUNICATIONS,	/* bInterfaceClass: Communication Interface Class */
		CDC_SUBCLASS_ACM,              	/* bInterfaceSubClass: Abstract Control Model */
	    CDC_PROTOCOL_AT,                   	/* bInterfaceProtocol: Common AT commands */
	    0,									/* iInterface: Index of string descriptor */

/********************************************************************************
 CDC Header Functional Descriptor
*********************************************************************************/
		CDC_HEADER_DESCRIPTOR_SIZE,   		/* bLength: Endpoint Descriptor size */
		CDC_CS_INTERFACE_DESCRIPTOR_TYPE,   /* bDescriptorType: CS_INTERFACE */
		CDC_HEADER_FUNC_DESCRIPTOR_SUBTYPE, /* bDescriptorSubtype: Header Func Desc */
		WBVAL(0x0110),   					/* bcdCDC: spec release number: 1.10 */

/********************************************************************************
 CDC Call Management Functional Descriptor
*********************************************************************************/
		CDC_CM_DESCRIPTOR_SIZE,     		/* bLength */
		CDC_CS_INTERFACE_DESCRIPTOR_TYPE,   /* bDescriptorType: CS_INTERFACE */
		CDC_CM_FUNC_DESCRIPTOR_SUBTYPE,  	/* bDescriptorSubtype: Call Management Func Desc */
		0x01,   							/* bmCapabilities: D0+D1 */
		CDC_DATA_IFC_NUM,   				/* bDataInterface: 1 */

/********************************************************************************
 CDC ACM Functional Descriptor
*********************************************************************************/
		CDC_ACM_DESCRIPTOR_SIZE,			/* bFunctionLength */
		CDC_CS_INTERFACE_DESCRIPTOR_TYPE,   /* bDescriptorType: CS_INTERFACE */
		CDC_ACM_FUNC_DESCRIPTOR_SUBTYPE,	/* bDescriptorSubtype: Abstract Control Management desc */
		0x02,   							/* bmCapabilities */

/********************************************************************************
 CDC Union Functional Descriptor
*********************************************************************************/
		CDC_UNION_IFC_DESCRIPTOR_SIZE,		/* bFunctionLength */
		CDC_CS_INTERFACE_DESCRIPTOR_TYPE,   /* bDescriptorType: CS_INTERFACE */
		CDC_UNION_IFC_FUNC_DESCRIPTOR_SUBTYPE, /* bDescriptorType: CS_INTERFACE */
		CDC_IFC_NUM,   				        /* bMasterInterface: Communication class interface */
		CDC_DATA_IFC_NUM,   				/* bSlaveInterface0: Data Class Interface */

/********************************************************************************
 Endpoint 2, CDC Interrupt In
*********************************************************************************/
		USB_ENDPOINT_DESCRIPTOR_SIZE,		/* bLength */
		USB_ENDPOINT_DESCRIPTOR_TYPE,		/* bDescriptorType */
		USB_ENDPOINT_IN(2), 				/* bEndpointAddress */
		USB_ENDPOINT_TYPE_INTERRUPT,		/* bmAttributes */
		WBVAL(VIRTUAL_COM_PORT_INT_SIZE),   /* wMaxPacketSize */
		0x1,                				/* bInterval  */

/********************************************************************************
 Interface 2, CDC Data Interface
*********************************************************************************/
		USB_INTERFACE_DESCRIPTOR_SIZE,     	/* bLength */
		USB_INTERFACE_DESCRIPTOR_TYPE, 		/* bDescriptorType */
		CDC_DATA_IFC_NUM,   				/* bInterfaceNumber */
		0x00,                 				/* bAlternateSetting */
		2,                                 	/* bNumEndpoints */
		USB_INTERFACE_CLASS_CDC_DATA,		/* bInterfaceClass: CDC-Data */
		0x00,              					/* bInterfaceSubClass:  */
	    0x00,                   			/* bInterfaceProtocol:  */
	    0,									/* iInterface: Index of string descriptor */

/********************************************************************************
 Endpoint 3, CDC-Data Bulk Out
*********************************************************************************/
		USB_ENDPOINT_DESCRIPTOR_SIZE,		/* bLength */
		USB_ENDPOINT_DESCRIPTOR_TYPE,		/* bDescriptorType */
		USB_ENDPOINT_OUT(3), 				/* bEndpointAddress */
		USB_ENDPOINT_TYPE_BULK,				/* bmAttributes */
		WBVAL(VIRTUAL_COM_PORT_DATA_SIZE),  /* wMaxPacketSize */
		0x00,                				/* bInterval: Ignore bulk transfer  */

/********************************************************************************
 Endpoint 4, CDC-Data Bulk In
*********************************************************************************/
		USB_ENDPOINT_DESCRIPTOR_SIZE,		/* bLength */
		USB_ENDPOINT_DESCRIPTOR_TYPE,		/* bDescriptorType */
		USB_ENDPOINT_IN(1), 				/* bEndpointAddress */
		USB_ENDPOINT_TYPE_BULK,				/* bmAttributes */
		WBVAL(VIRTUAL_COM_PORT_DATA_SIZE),  /* wMaxPacketSize */
		0x00,                				/* bInterval: Ignore bulk transfer  */
};



/********************************************************************************
HID Report Descriptor for a 3 Button Mouse with RELATIVE positioning

Description:
HID Report Descriptor for a 3 button mouse.

Byte                Bits                  Description
0                   0                     Left Button
					1                     Right Button
					2                     Middle Button
					3..7                  Unused
1                   0..7                  X Displacement (-127..127)
2                   0..7                  Y Displacement (-127..127)
 *********************************************************************************/
const uint8 CustomHID_ReportDescriptor[HID_MOUSE_REPORT_DESCRIPTOR_SIZE] =
{
		HID_UsagePage(HID_USAGE_PAGE_GENERIC),
		HID_Usage(HID_USAGE_GENERIC_MOUSE),
		HID_Collection(HID_Application),
		HID_Usage(HID_USAGE_GENERIC_POINTER),
		HID_Collection(HID_Physical),
		HID_ReportCount(3),
		HID_ReportSize(1),
		HID_UsagePage(HID_USAGE_PAGE_BUTTON),
		HID_UsageMin(1),
		HID_UsageMax(3),
		HID_LogicalMin(0),
		HID_LogicalMax(1),
		HID_Input(HID_Data | HID_Variable | HID_Absolute),
		HID_ReportCount(1),
		HID_ReportSize(5),
		HID_Input(HID_Constant),
		HID_ReportSize(8),
		HID_ReportCount(2),
		HID_UsagePage(HID_USAGE_PAGE_GENERIC),
		HID_Usage(HID_USAGE_GENERIC_X),
		HID_Usage(HID_USAGE_GENERIC_Y),
		HID_LogicalMin(HID_MOUSE_REL_MIN_XY),
		HID_LogicalMax(HID_MOUSE_REL_MAX_XY),
		HID_Input(HID_Data | HID_Variable | HID_Relative),
		HID_EndCollection,
		HID_EndCollection,
}; /* CustomHID_ReportDescriptor */




/* USB String Descriptors */
const uint8 Virtual_Com_Port_StringLangID[VIRTUAL_COM_PORT_SIZ_STRING_LANGID] =
{
		VIRTUAL_COM_PORT_SIZ_STRING_LANGID,
		USB_STRING_DESCRIPTOR_TYPE,
		0x09,
		0x04 /* LangID = 0x0409: U.S. English */
};

const uint8 Virtual_Com_Port_StringVendor[VIRTUAL_COM_PORT_SIZ_STRING_VENDOR] =
{
		VIRTUAL_COM_PORT_SIZ_STRING_VENDOR,     /* Size of Vendor string */
		USB_STRING_DESCRIPTOR_TYPE,             /* bDescriptorType*/
		/* Manufacturer: "STMicroelectronics" */
		'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
		'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
		'c', 0, 's', 0
};

const uint8 Virtual_Com_Port_StringProduct[VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT] =
{
		VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT,          /* bLength */
		USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
		/* Product name: "STM32 Virtual COM Port" */
		'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, ' ', 0, 'V', 0, 'i', 0,
		'r', 0, 't', 0, 'u', 0, 'a', 0, 'l', 0, ' ', 0, 'C', 0, 'O', 0,
		'M', 0, ' ', 0, 'P', 0, 'o', 0, 'r', 0, 't', 0, ' ', 0, ' ', 0
};

uint8 Virtual_Com_Port_StringSerial[VIRTUAL_COM_PORT_SIZ_STRING_SERIAL] =
{
		VIRTUAL_COM_PORT_SIZ_STRING_SERIAL,           /* bLength */
		USB_STRING_DESCRIPTOR_TYPE,                   /* bDescriptorType */
		'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, '1', 0, '0', 0
};
