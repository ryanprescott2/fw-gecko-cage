/**
  @page TIM_OCInactive Output Compare Inactive example

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    TIM/TIM_OCInactive/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four 
  *          delayed signals.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
   @endverbatim

@par Example Description 

  This example shows how to configure the TIM peripheral in Output Compare Inactive 
  mode with the corresponding Interrupt requests for each channel.

  The TIM2CLK frequency is set to SystemCoreClock / 2 (Hz), and the objective is
  to get TIM2 counter clock at 2 KHz so the Prescaler is computed as following:
  - Prescaler = (TIM2CLK / TIM2 counter clock) - 1
  SystemCoreClock is set to 168 MHz for STM32F4xx devices

  The TIM2 CCR1 register value is equal to 1000:
  TIM2_CC1 delay = CCR1_Val/TIM2 counter clock  = 500 ms
  so the PA.00  is reset after a delay equal to 500 ms.

  The TIM2 CCR2 register value is equal to 500:
  TIM2_CC2 delay = CCR2_Val/TIM2 counter clock = 250 ms
  so the PA.01  is reset after a delay equal to 250 ms.

  The TIM2 CCR3 register value is equal to 250:
  TIM2_CC3 delay = CCR3_Val/TIM2 counter clock = 125 ms
  so the PA.02  is reset after a delay equal to 125 ms.

  The TIM2 CCR4 register value is equal to 125:
  TIM2_CC4 delay = CCR4_Val/TIM2 counter clock = 62.5 ms
  so the PA.03  is reset after a delay equal to 62.5 ms.

  While the counter is lower than the Output compare registers values, which 
  determines the Output delay, the PG.06, PG.08, PI.09 and PC.07 pin are turned ON. 

  When the counter value reaches the Output compare registers values, the Output 
  Compare interrupts are generated and, in the handler routine, these pins are turned OFF.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Timers, Output, Compare, InActive, Signals, Delay, Frequency

@par Directory contents 

  - TIM/TIM_OCInactive/Inc/stm32f4xx_hal_conf.h         HAL configuration file
  - TIM/TIM_OCInactive/Inc/stm32f4xx_it.h               Interrupt handlers header file
  - TIM/TIM_OCInactive/Inc/main.h                       Main program header file  
  - TIM/TIM_OCInactive/Src/stm32f4xx_it.c               Interrupt handlers
  - TIM/TIM_OCInactive/Src/main.c                       Main program
  - TIM/TIM_OCInactive/Src/stm32f4xx_hal_msp.c          HAL MSP module
  - TIM/TIM_OCInactive/Src/system_stm32f4xx.c           STM32F4xx system clock configuration file

                                           
@par Hardware and Software environment 

  - This example runs on STM32F407xx/417xx devices.
    
  - This example has been tested with STMicroelectronics STM324xG-EVAL RevC  
    evaluation boards and can be easily tailored to any other supported device and development board

  - STM324xG-EVAL RevC Set-up 
    - Use LED1, LED2, LED3 and LED4 and connect them an oscilloscope to monitor 
      the different waveforms.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
