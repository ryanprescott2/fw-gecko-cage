/**
  @page GPIO_EXTI GPIO EXTI example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    GPIO/GPIO_EXTI/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the GPIO EXTI example.
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

How to configure external interrupt lines.

In this example, 2 EXTI lines (EXTI Line0 and Line13) are configured  to generate
an interrupt on each rising and falling edge, respectively. 
In the interrupt routine a LED connected to a specific GPIO pin is toggled.

In this example:
    - EXTI Line0 is connected to PA0 pin
    - EXTI Line13 is connected to PC13 pin

- when falling edge is detected on EXTI Line0, LED1 toggles
- when falling edge is detected on EXTI Line13, LED2 toggles

On STM324x9I-EVAL:
    - EXTI Line0 is connected to Wakeup push-button
    - EXTI Line13 is connected to Key push-button

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, GPIO, Output, Alternate function, EXTI, Toggle

@par Directory contents 

  - GPIO/GPIO_IOToggle/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - GPIO/GPIO_IOToggle/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - GPIO/GPIO_IOToggle/Inc/main.h                  Main program header file  
  - GPIO/GPIO_IOToggle/Src/stm32f4xx_it.c          Interrupt handlers
  - GPIO/GPIO_IOToggle/Src/main.c                  Main program
  - GPIO/GPIO_IOToggle/Src/system_stm32f4xx.c      STM32F4xx system clock configuration file


@par Hardware and Software environment

  - This example runs on STM32F42xxx/STM32F43xxx devices.
    
  - This example has been tested with STM324x9I-EVAL RevB evaluation board and can be
    easily tailored to any other supported device and development board.      


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
