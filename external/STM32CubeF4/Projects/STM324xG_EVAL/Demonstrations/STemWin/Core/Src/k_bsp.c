/**
  ******************************************************************************
  * @file    k_bsp.c
  * @author  MCD Application Team
  * @brief   This file provides the kernel bsp functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "k_bsp.h"
#include "k_calibration.h"
#include "GUI.h"
#include "DIALOG.h"

/** @addtogroup CORE
  * @{
  */

/** @defgroup KERNEL_BSP
  * @brief Kernel BSP routines
  * @{
  */


/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes LEDs, touch screen, CRC and SRAM.
  * @param  None 
  * @retval None
  */
void k_BspInit(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Configure LED1, LED2, LED3 and LED4 */
  BSP_LED_Init(LED1);
  BSP_LED_Init(LED2);
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);  
  
  /* Initialize the SRAM */
  BSP_SRAM_Init();
  
  /* Initialize the Touch screen */
  BSP_TS_Init(320, 240);
  
  /* Enable CRC to Unlock GUI */
  __HAL_RCC_CRC_CLK_ENABLE();
  
  /* Enable Back up SRAM */
  __HAL_RCC_BKPSRAM_CLK_ENABLE();
  
  
  /* reconfigure FSMC NE3 pin */
  GPIO_InitStructure.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStructure.Pull      = GPIO_PULLUP;
  GPIO_InitStructure.Speed     = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Alternate = GPIO_AF12_FSMC;
  GPIO_InitStructure.Pin   = GPIO_PIN_10;
  
  HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);  
}

/**
  * @brief  Initializes BSP Audio
  * @param  None 
  * @retval None
  */
void k_BspAudioInit(void)
{
  BSP_AUDIO_OUT_Init(OUTPUT_DEVICE_AUTO, AUDIO_DEFAULT_VOLUME, I2S_AUDIOFREQ_44K);
}


/**
  * @brief  Read the coordinate of the point touched and assign their
  *         value to the variables u32_TSXCoordinate and u32_TSYCoordinate
  * @param  None
  * @retval None
  */
void k_TouchUpdate(void)
{
  GUI_PID_STATE TS_State;
  static TS_StateTypeDef prev_state;
  __IO TS_StateTypeDef  ts;
  uint16_t xDiff, yDiff;  
  
  BSP_TS_GetState((TS_StateTypeDef *)&ts);
  
  TS_State.Pressed = ts.TouchDetected;

  xDiff = (prev_state.x > ts.x) ? (prev_state.x - ts.x) : (ts.x - prev_state.x);
  yDiff = (prev_state.y > ts.y) ? (prev_state.y - ts.y) : (ts.y - prev_state.y);
  
  if((prev_state.TouchDetected != ts.TouchDetected )||
     (xDiff > 3 )||
       (yDiff > 3))
  {
    prev_state.TouchDetected = ts.TouchDetected;
    
    if((ts.x != 0) &&  (ts.y != 0)) 
    {
      prev_state.x = ts.x;
      prev_state.y = ts.y;
    }
      
    if(k_CalibrationIsDone())
    {
      TS_State.Layer = 0;
      TS_State.x = k_CalibrationGetX (prev_state.x);
      TS_State.y = k_CalibrationGetY (prev_state.y);
    }
    else
    {
      TS_State.Layer = 0;
      TS_State.x = prev_state.x;
      TS_State.y = prev_state.y;
    }
    
    GUI_TOUCH_StoreStateEx(&TS_State);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
