/**
  @page CortexM_MPU CortexM MPU example

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Cortex/CORTEXM_MPU/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the CortexM MPU example.
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

This example presents the MPU feature. Its purpose is to configure a memory area
as privileged read-only area and attempt to perform read and write operations
in different modes.

The example purpose is to configure a memory region as privileged read only region
and tries to perform read and write operation in different mode.

If the access is permitted LED1 is toggling. If the access is not permitted, 
a memory management fault is generated and LED2 is ON.
To generate an MPU memory fault exception due to an access right error, uncomment
the following line "PrivilegedReadOnlyArray[0] = 'e';" in the "stm32_mpu.c" file.


@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

System, Cortex, Memory regions, Privileged area, permitted access, memory management fault, MPU memory fault

@par Directory contents 

  - Cortex/CORTEXM_MPU/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - Cortex/CORTEXM_MPU/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - Cortex/CORTEXM_MPU/Inc/main.h                  Main program header file  
  - Cortex/CORTEXM_MPU/Src/stm32f4xx_it.c          Interrupt handlers
  - Cortex/CORTEXM_MPU/Src/main.c                  Main program
  - Cortex/CORTEXM_MPU/Src/system_stm32f4xx.c      STM32F4xx system clock configuration file


@par Hardware and Software environment

  - This example runs on STM32F407xx/417xx devices.
  
  - This example has been tested with STMicroelectronics STM324xG-EVAL RevC 
    evaluation boards and can be easily tailored to any other supported device 
    and development board


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
