/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_usart.h
* Author             : MCD Application Team
* Date First Issued  : 09/29/2006
* Description        : This file contains all the functions prototypes for the
*                      USART firmware library.
********************************************************************************
* History:
* 04/02/2007: V0.2
* 02/05/2007: V0.1
* 09/29/2006: V0.01
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_USART_H
#define __STM32F10x_USART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_map.h"

/* Exported types ------------------------------------------------------------*/
/* UART Init Structure definition */
typedef struct
{
  uint32 USART_BaudRate;
  uint16 USART_WordLength;
  uint16 USART_StopBits;
  uint16 USART_Parity;
  uint16 USART_HardwareFlowControl;
  uint16 USART_Mode;
  uint16 USART_Clock;
  uint16 USART_CPOL;
  uint16 USART_CPHA;
  uint16 USART_LastBit;
} USART_InitTypeDef;

/* Exported constants --------------------------------------------------------*/
/* USART Word Length ---------------------------------------------------------*/
#define USART_WordLength_8b                  ((uint16)0x0000)
#define USART_WordLength_9b                  ((uint16)0x1000)

#define IS_USART_WORD_LENGTH(LENGTH) ((LENGTH == USART_WordLength_8b) || \
                                      (LENGTH == USART_WordLength_9b))

/* USART Stop Bits -----------------------------------------------------------*/
#define USART_StopBits_1                     ((uint16)0x0000)
#define USART_StopBits_0_5                   ((uint16)0x1000)
#define USART_StopBits_2                     ((uint16)0x2000)
#define USART_StopBits_1_5                   ((uint16)0x3000)

#define IS_USART_STOPBITS(STOPBITS) ((STOPBITS == USART_StopBits_1) || \
                                     (STOPBITS == USART_StopBits_0_5) || \
                                     (STOPBITS == USART_StopBits_2) || \
                                     (STOPBITS == USART_StopBits_1_5))
/* USART Parity --------------------------------------------------------------*/
#define USART_Parity_No                      ((uint16)0x0000)
#define USART_Parity_Even                    ((uint16)0x0400)
#define USART_Parity_Odd                     ((uint16)0x0600)

#define IS_USART_PARITY(PARITY) ((PARITY == USART_Parity_No) || \
                                 (PARITY == USART_Parity_Even) || \
                                 (PARITY == USART_Parity_Odd))

/* USART Hardware Flow Control -----------------------------------------------*/
#define USART_HardwareFlowControl_None       ((uint16)0x0000)
#define USART_HardwareFlowControl_RTS        ((uint16)0x0100)
#define USART_HardwareFlowControl_CTS        ((uint16)0x0200)
#define USART_HardwareFlowControl_RTS_CTS    ((uint16)0x0300)

#define IS_USART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              ((CONTROL == USART_HardwareFlowControl_None) || \
                               (CONTROL == USART_HardwareFlowControl_RTS) || \
                               (CONTROL == USART_HardwareFlowControl_CTS) || \
                               (CONTROL == USART_HardwareFlowControl_RTS_CTS))

/* USART Mode ----------------------------------------------------------------*/
#define USART_Mode_Rx                        ((uint16)0x0004)
#define USART_Mode_Tx                        ((uint16)0x0008)

#define IS_USART_MODE(MODE) (((MODE & (uint16)0xFFF3) == 0x00) && (MODE != (uint16)0x00))

/* USART Clock ---------------------------------------------------------------*/
#define USART_Clock_Disable                  ((uint16)0x0000)
#define USART_Clock_Enable                   ((uint16)0x0800)

#define IS_USART_CLOCK(CLOCK) ((CLOCK == USART_Clock_Disable) || \
                               (CLOCK == USART_Clock_Enable))

/* USART Clock Polarity ------------------------------------------------------*/
#define USART_CPOL_Low                       ((uint16)0x0000)
#define USART_CPOL_High                      ((uint16)0x0400)

#define IS_USART_CPOL(CPOL) ((CPOL == USART_CPOL_Low) || (CPOL == USART_CPOL_High))
                               
/* USART Clock Phase ---------------------------------------------------------*/
#define USART_CPHA_1Edge                     ((uint16)0x0000)
#define USART_CPHA_2Edge                     ((uint16)0x0200)
#define IS_USART_CPHA(CPHA) ((CPHA == USART_CPHA_1Edge) || (CPHA == USART_CPHA_2Edge))

/* USART Last Bit ------------------------------------------------------------*/
#define USART_LastBit_Disable                ((uint16)0x0000)
#define USART_LastBit_Enable                 ((uint16)0x0100)

#define IS_USART_LASTBIT(LASTBIT) ((LASTBIT == USART_LastBit_Disable) || \
                                   (LASTBIT == USART_LastBit_Enable))

/* USART Interrupt definition ------------------------------------------------*/
#define USART_IT_PE                          ((uint16)0x0028)
#define USART_IT_TXE                         ((uint16)0x0727)
#define USART_IT_TC                          ((uint16)0x0626)
#define USART_IT_RXNE                        ((uint16)0x0525)
#define USART_IT_IDLE                        ((uint16)0x0424)
#define USART_IT_LBD                         ((uint16)0x0846)
#define USART_IT_CTS                         ((uint16)0x096A)
#define USART_IT_ERR                         ((uint16)0x0060)
#define USART_IT_ORE                         ((uint16)0x0360)
#define USART_IT_NE                          ((uint16)0x0260)
#define USART_IT_FE                          ((uint16)0x0160)

#define IS_USART_CONFIG_IT(IT) ((IT == USART_IT_PE) || (IT == USART_IT_TXE) || \
                               (IT == USART_IT_TC) || (IT == USART_IT_RXNE) || \
                               (IT == USART_IT_IDLE) || (IT == USART_IT_LBD) || \
                               (IT == USART_IT_CTS) || (IT == USART_IT_ERR))

#define IS_USART_IT(IT) ((IT == USART_IT_PE) || (IT == USART_IT_TXE) || \
                         (IT == USART_IT_TC) || (IT == USART_IT_RXNE) || \
                         (IT == USART_IT_IDLE) || (IT == USART_IT_LBD) || \
                         (IT == USART_IT_CTS) || (IT == USART_IT_ORE) || \
                         (IT == USART_IT_NE) || (IT == USART_IT_FE))

/* USART DMA Requests --------------------------------------------------------*/
#define USART_DMAReq_Tx                      ((uint16)0x0080)
#define USART_DMAReq_Rx                      ((uint16)0x0040)

#define IS_USART_DMAREQ(DMAREQ) (((DMAREQ & (uint16)0xFF3F) == 0x00) && (DMAREQ != (uint16)0x00))

/* USART WakeUp methods ------------------------------------------------------*/
#define USART_WakeUp_IdleLine                ((uint16)0x0000)
#define USART_WakeUp_AddressMark             ((uint16)0x0800)

#define IS_USART_WAKEUP(WAKEUP) ((WAKEUP == USART_WakeUp_IdleLine) || \
                                 (WAKEUP == USART_WakeUp_AddressMark))

/* USART LIN Break Detection Length ------------------------------------------*/
#define USART_LINBreakDetectLength_10b      ((uint16)0x0000)
#define USART_LINBreakDetectLength_11b      ((uint16)0x0020)

#define IS_USART_LIN_BREAK_DETECT_LENGTH(LENGTH) \
                               ((LENGTH == USART_LINBreakDetectLength_10b) || \
                                (LENGTH == USART_LINBreakDetectLength_11b))

/* USART IrDA Low Power ------------------------------------------------------*/
#define USART_IrDAMode_LowPower              ((uint16)0x0004)
#define USART_IrDAMode_Normal                ((uint16)0x0000)

#define IS_USART_IRDA_MODE(MODE) ((MODE == USART_IrDAMode_LowPower) || \
                                  (MODE == USART_IrDAMode_Normal))

/* USART Flags ---------------------------------------------------------------*/
#define USART_FLAG_CTS                       ((uint16)0x0200)
#define USART_FLAG_LBD                       ((uint16)0x0100)
#define USART_FLAG_TXE                       ((uint16)0x0080)
#define USART_FLAG_TC                        ((uint16)0x0040)
#define USART_FLAG_RXNE                      ((uint16)0x0020)
#define USART_FLAG_IDLE                      ((uint16)0x0010)
#define USART_FLAG_ORE                       ((uint16)0x0008)
#define USART_FLAG_NE                        ((uint16)0x0004)
#define USART_FLAG_FE                        ((uint16)0x0002)
#define USART_FLAG_PE                        ((uint16)0x0001)

#define IS_USART_FLAG(FLAG) ((FLAG == USART_FLAG_PE) || (FLAG == USART_FLAG_TXE) || \
                             (FLAG == USART_FLAG_TC) || (FLAG == USART_FLAG_RXNE) || \
                             (FLAG == USART_FLAG_IDLE) || (FLAG == USART_FLAG_LBD) || \
                             (FLAG == USART_FLAG_CTS) || (FLAG == USART_FLAG_ORE) || \
                             (FLAG == USART_FLAG_NE) || (FLAG == USART_FLAG_FE))
 
#define IS_USART_CLEAR_FLAG(FLAG) (((FLAG & (uint16)0xFC00) == 0x00) && (FLAG != (uint16)0x00))

#define IS_USART_ADDRESS(ADDRESS) (ADDRESS <= 0xF)
#define IS_USART_DATA(DATA) (DATA <= 0x1FF)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, uint16 USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, uint16 USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, uint8 USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16 USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16 USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16 Data);
uint16 USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8 USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8 USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16 USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16 USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16 USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16 USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16 USART_IT);

#endif /* __STM32F10x_USART_H */

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
