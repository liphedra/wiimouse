/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_nvic.h
* Author             : MCD Application Team
* Date First Issued  : 09/29/2006
* Description        : This file contains all the functions prototypes for the
*                      NVIC firmware library.
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
#ifndef __STM32F10x_NVIC_H
#define __STM32F10x_NVIC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* NVIC Init Structure definition */
typedef struct
{
  uint8 NVIC_IRQChannel;
  uint8 NVIC_IRQChannelPreemptionPriority;
  uint8 NVIC_IRQChannelSubPriority;
  FunctionalState NVIC_IRQChannelCmd;
} NVIC_InitTypeDef;

/* Exported constants --------------------------------------------------------*/
/* IRQ Channels --------------------------------------------------------------*/
#define WWDG_IRQChannel              ((uint8)0x00)  /* Window WatchDog Interrupt */
#define PVD_IRQChannel               ((uint8)0x01)  /* PVD through EXTI Line detection Interrupt */
#define TAMPER_IRQChannel            ((uint8)0x02)  /* Tamper Interrupt */
#define RTC_IRQChannel               ((uint8)0x03)  /* RTC global Interrupt */
#define FLASH_IRQChannel             ((uint8)0x04)  /* FLASH global Interrupt */
#define RCC_IRQChannel               ((uint8)0x05)  /* RCC global Interrupt */
#define EXTI0_IRQChannel             ((uint8)0x06)  /* EXTI Line0 Interrupt */
#define EXTI1_IRQChannel             ((uint8)0x07)  /* EXTI Line1 Interrupt */
#define EXTI2_IRQChannel             ((uint8)0x08)  /* EXTI Line2 Interrupt */
#define EXTI3_IRQChannel             ((uint8)0x09)  /* EXTI Line3 Interrupt */
#define EXTI4_IRQChannel             ((uint8)0x0A)  /* EXTI Line4 Interrupt */
#define DMAChannel1_IRQChannel       ((uint8)0x0B)  /* DMA Channel 1 global Interrupt */
#define DMAChannel2_IRQChannel       ((uint8)0x0C)  /* DMA Channel 2 global Interrupt */
#define DMAChannel3_IRQChannel       ((uint8)0x0D)  /* DMA Channel 3 global Interrupt */
#define DMAChannel4_IRQChannel       ((uint8)0x0E)  /* DMA Channel 4 global Interrupt */
#define DMAChannel5_IRQChannel       ((uint8)0x0F)  /* DMA Channel 5 global Interrupt */
#define DMAChannel6_IRQChannel       ((uint8)0x10)  /* DMA Channel 6 global Interrupt */
#define DMAChannel7_IRQChannel       ((uint8)0x11)  /* DMA Channel 7 global Interrupt */
#define ADC_IRQChannel               ((uint8)0x12)  /* ADC global Interrupt */
#define USB_HP_CAN_TX_IRQChannel     ((uint8)0x13)  /* USB High Priority or CAN TX Interrupts */
#define USB_LP_CAN_RX0_IRQChannel    ((uint8)0x14)  /* USB Low Priority or CAN RX0 Interrupts */
#define CAN_RX1_IRQChannel           ((uint8)0x15)  /* CAN RX1 Interrupt */
#define CAN_SCE_IRQChannel           ((uint8)0x16)  /* CAN SCE Interrupt */
#define EXTI9_5_IRQChannel           ((uint8)0x17)  /* External Line[9:5] Interrupts */
#define TIM1_BRK_IRQChannel          ((uint8)0x18)  /* TIM1 Break Interrupt */
#define TIM1_UP_IRQChannel           ((uint8)0x19)  /* TIM1 Update Interrupt */
#define TIM1_TRG_COM_IRQChannel      ((uint8)0x1A)  /* TIM1 Trigger and Commutation Interrupt */
#define TIM1_CC_IRQChannel           ((uint8)0x1B)  /* TIM1 Capture Compare Interrupt */
#define TIM2_IRQChannel              ((uint8)0x1C)  /* TIM2 global Interrupt */
#define TIM3_IRQChannel              ((uint8)0x1D)  /* TIM3 global Interrupt */
#define TIM4_IRQChannel              ((uint8)0x1E)  /* TIM4 global Interrupt */
#define I2C1_EV_IRQChannel           ((uint8)0x1F)  /* I2C1 Event Interrupt */
#define I2C1_ER_IRQChannel           ((uint8)0x20)  /* I2C1 Error Interrupt */
#define I2C2_EV_IRQChannel           ((uint8)0x21)  /* I2C2 Event Interrupt */
#define I2C2_ER_IRQChannel           ((uint8)0x22)  /* I2C2 Error Interrupt */
#define SPI1_IRQChannel              ((uint8)0x23)  /* SPI1 global Interrupt */
#define SPI2_IRQChannel              ((uint8)0x24)  /* SPI2 global Interrupt */
#define USART1_IRQChannel            ((uint8)0x25)  /* USART1 global Interrupt */
#define USART2_IRQChannel            ((uint8)0x26)  /* USART2 global Interrupt */
#define USART3_IRQChannel            ((uint8)0x27)  /* USART3 global Interrupt */
#define EXTI15_10_IRQChannel         ((uint8)0x28)  /* External Line[15:10] Interrupts */
#define RTCAlarm_IRQChannel          ((uint8)0x29)  /* RTC Alarm through EXTI Line Interrupt */
#define USBWakeUp_IRQChannel         ((uint8)0x2A)  /* USB WakeUp from suspend through EXTI Line Interrupt */

#define IS_NVIC_IRQ_CHANNEL(CHANNEL) ((CHANNEL == WWDG_IRQChannel) || \
                                      (CHANNEL == PVD_IRQChannel) || \
                                      (CHANNEL == TAMPER_IRQChannel) || \
                                      (CHANNEL == RTC_IRQChannel) || \
                                      (CHANNEL == FLASH_IRQChannel) || \
                                      (CHANNEL == RCC_IRQChannel) || \
                                      (CHANNEL == EXTI0_IRQChannel) || \
                                      (CHANNEL == EXTI1_IRQChannel) || \
                                      (CHANNEL == EXTI2_IRQChannel) || \
                                      (CHANNEL == EXTI3_IRQChannel) || \
                                      (CHANNEL == EXTI4_IRQChannel) || \
                                      (CHANNEL == DMAChannel1_IRQChannel) || \
                                      (CHANNEL == DMAChannel2_IRQChannel) || \
                                      (CHANNEL == DMAChannel3_IRQChannel) || \
                                      (CHANNEL == DMAChannel4_IRQChannel) || \
                                      (CHANNEL == DMAChannel5_IRQChannel) || \
                                      (CHANNEL == DMAChannel6_IRQChannel) || \
                                      (CHANNEL == DMAChannel7_IRQChannel) || \
                                      (CHANNEL == ADC_IRQChannel) || \
                                      (CHANNEL == USB_HP_CAN_TX_IRQChannel) || \
                                      (CHANNEL == USB_LP_CAN_RX0_IRQChannel) || \
                                      (CHANNEL == CAN_RX1_IRQChannel) || \
                                      (CHANNEL == CAN_SCE_IRQChannel) || \
                                      (CHANNEL == EXTI9_5_IRQChannel) || \
                                      (CHANNEL == TIM1_BRK_IRQChannel) || \
                                      (CHANNEL == TIM1_UP_IRQChannel) || \
                                      (CHANNEL == TIM1_TRG_COM_IRQChannel) || \
                                      (CHANNEL == TIM1_CC_IRQChannel) || \
                                      (CHANNEL == TIM2_IRQChannel) || \
                                      (CHANNEL == TIM3_IRQChannel) || \
                                      (CHANNEL == TIM4_IRQChannel) || \
                                      (CHANNEL == I2C1_EV_IRQChannel) || \
                                      (CHANNEL == I2C1_ER_IRQChannel) || \
                                      (CHANNEL == I2C2_EV_IRQChannel) || \
                                      (CHANNEL == I2C2_ER_IRQChannel) || \
                                      (CHANNEL == SPI1_IRQChannel) || \
                                      (CHANNEL == SPI2_IRQChannel) || \
                                      (CHANNEL == USART1_IRQChannel) || \
                                      (CHANNEL == USART2_IRQChannel) || \
                                      (CHANNEL == USART3_IRQChannel) || \
                                      (CHANNEL == EXTI15_10_IRQChannel) || \
                                      (CHANNEL == RTCAlarm_IRQChannel) || \
                                      (CHANNEL == USBWakeUp_IRQChannel))

/* System Handlers -----------------------------------------------------------*/
#define SystemHandler_NMI            ((uint32)0x00001F) /* NMI Handler */
#define SystemHandler_HardFault      ((uint32)0x000000) /* Hard Fault Handler */
#define SystemHandler_MemoryManage   ((uint32)0x043430) /* Memory Manage Handler */
#define SystemHandler_BusFault       ((uint32)0x547931) /* Bus Fault Handler */
#define SystemHandler_UsageFault     ((uint32)0x24C232) /* Usage Fault Handler */
#define SystemHandler_SVCall         ((uint32)0x01FF40) /* SVCall Handler */
#define SystemHandler_DebugMonitor   ((uint32)0x0A0080) /* Debug Monitor Handler */
#define SystemHandler_PSV            ((uint32)0x02829C) /* PSV Handler */
#define SystemHandler_SysTick        ((uint32)0x02C39A) /* SysTick Handler */

#define IS_CONFIG_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_MemoryManage) || \
                                           (HANDLER == SystemHandler_BusFault) || \
                                           (HANDLER == SystemHandler_UsageFault))

#define IS_PRIORITY_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_MemoryManage) || \
                                             (HANDLER == SystemHandler_BusFault) || \
                                             (HANDLER == SystemHandler_UsageFault) || \
                                             (HANDLER == SystemHandler_SVCall) || \
                                             (HANDLER == SystemHandler_DebugMonitor) || \
                                             (HANDLER == SystemHandler_PSV) || \
                                             (HANDLER == SystemHandler_SysTick))

#define IS_GET_PENDING_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_MemoryManage) || \
                                                (HANDLER == SystemHandler_BusFault) || \
                                                (HANDLER == SystemHandler_SVCall))

#define IS_SET_PENDING_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_NMI) || \
                                                (HANDLER == SystemHandler_PSV) || \
                                                (HANDLER == SystemHandler_SysTick))

#define IS_CLEAR_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_PSV) || \
                                          (HANDLER == SystemHandler_SysTick))

#define IS_GET_ACTIVE_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_MemoryManage) || \
                                               (HANDLER == SystemHandler_BusFault) || \
                                               (HANDLER == SystemHandler_UsageFault) || \
                                               (HANDLER == SystemHandler_SVCall) || \
                                               (HANDLER == SystemHandler_DebugMonitor) || \
                                               (HANDLER == SystemHandler_PSV) || \
                                               (HANDLER == SystemHandler_SysTick))

#define IS_FAULT_SOURCE_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_HardFault) || \
                                                 (HANDLER == SystemHandler_MemoryManage) || \
                                                 (HANDLER == SystemHandler_BusFault) || \
                                                 (HANDLER == SystemHandler_UsageFault) || \
                                                 (HANDLER == SystemHandler_DebugMonitor)) 

#define IS_FAULT_ADDRESS_SYSTEM_HANDLER(HANDLER) ((HANDLER == SystemHandler_MemoryManage) || \
                                                  (HANDLER == SystemHandler_BusFault))


/* Vector Table Base ---------------------------------------------------------*/
#define NVIC_VectTab_RAM             ((uint32)0x20000000)
#define NVIC_VectTab_FLASH           ((uint32)0x00000000)

#define IS_NVIC_VECTTAB(VECTTAB) ((VECTTAB == NVIC_VectTab_RAM) || \
                                  (VECTTAB == NVIC_VectTab_FLASH))

/* System Low Power ----------------------------------------------------------*/
#define NVIC_LP_SEVONPEND            ((uint8)0x10)
#define NVIC_LP_SLEEPDEEP            ((uint8)0x04)
#define NVIC_LP_SLEEPONEXIT          ((uint8)0x02)

#define IS_NVIC_LP(LP) ((LP == NVIC_LP_SEVONPEND) || \
                        (LP == NVIC_LP_SLEEPDEEP) || \
                        (LP == NVIC_LP_SLEEPONEXIT))

/* Preemption Priority Group -------------------------------------------------*/
#define NVIC_PriorityGroup_0         ((uint32)0x700) /* 0 bits for pre-emption priority
                                                     4 bits for subpriority */
#define NVIC_PriorityGroup_1         ((uint32)0x600) /* 1 bits for pre-emption priority
                                                     3 bits for subpriority */
#define NVIC_PriorityGroup_2         ((uint32)0x500) /* 2 bits for pre-emption priority
                                                     2 bits for subpriority */
#define NVIC_PriorityGroup_3         ((uint32)0x400) /* 3 bits for pre-emption priority
                                                     1 bits for subpriority */
#define NVIC_PriorityGroup_4         ((uint32)0x300) /* 4 bits for pre-emption priority
                                                     0 bits for subpriority */

#define IS_NVIC_PRIORITY_GROUP(GROUP) ((GROUP == NVIC_PriorityGroup_0) || \
                                       (GROUP == NVIC_PriorityGroup_1) || \
                                       (GROUP == NVIC_PriorityGroup_2) || \
                                       (GROUP == NVIC_PriorityGroup_3) || \
                                       (GROUP == NVIC_PriorityGroup_4))

#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  (PRIORITY < 0x10)
#define IS_NVIC_SUB_PRIORITY(PRIORITY)  (PRIORITY < 0x10)
#define IS_NVIC_OFFSET(OFFSET)  (OFFSET < 0x3FFFFF)
#define IS_NVIC_BASE_PRI(PRI) ((PRI > 0x00) && (PRI < 0x10))

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void NVIC_DeInit(void);
void NVIC_SCBDeInit(void);
void NVIC_PriorityGroupConfig(uint32 NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_StructInit(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SETPRIMASK(void);
void NVIC_RESETPRIMASK(void);
void NVIC_SETFAULTMASK(void);
void NVIC_RESETFAULTMASK(void);
void NVIC_BASEPRICONFIG(uint32 NewPriority);
uint32 NVIC_GetBASEPRI(void);
uint16 NVIC_GetCurrentPendingIRQChannel(void);
ITStatus NVIC_GetIRQChannelPendingBitStatus(uint32 NVIC_IRQChannel);
void NVIC_SetIRQChannelPendingBit(uint32 NVIC_IRQChannel);
void NVIC_ClearIRQChannelPendingBit(uint32 NVIC_IRQChannel);
uint16 NVIC_GetCurrentActiveHandler(void);
ITStatus NVIC_GetIRQChannelActiveBitStatus(uint32 NVIC_IRQChannel);
uint32 NVIC_GetCPUID(void);
void NVIC_SetVectorTable(uint32 NVIC_VectTab, uint32 Offset);
void NVIC_GenerateSystemReset(void);
void NVIC_GenerateCoreReset(void);
void NVIC_SystemLPConfig(uint32 LowPowerMode, FunctionalState NewState);
void NVIC_SystemHandlerConfig(uint32 SystemHandler, FunctionalState NewState);
void NVIC_SystemHandlerPriorityConfig(uint32 SystemHandler, uint32 SystemHandlerPreemptionPriority,
                                      uint32 SystemHandlerSubPriority);
ITStatus NVIC_GetSystemHandlerPendingBitStatus(uint32 SystemHandler);
void NVIC_SetSystemHandlerPendingBit(uint32 SystemHandler);
void NVIC_ClearSystemHandlerPendingBit(uint32 SystemHandler);
ITStatus NVIC_GetSystemHandlerActiveBitStatus(uint32 SystemHandler);
uint32 NVIC_GetFaultHandlerSources(uint32 SystemHandler);
uint32 NVIC_GetFaultAddress(uint32 SystemHandler);

#endif /* __STM32F10x_NVIC_H */

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
