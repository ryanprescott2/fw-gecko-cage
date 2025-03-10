/**
  @page STemWin_MemoryDevice  STemWin memory device Readme file
 
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    STemWin/STemWin_MemoryDevice/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of STemWin memory device application. 
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0044
  *
  ******************************************************************************
   @endverbatim

@par Application Description

This directory contains a set of source files that implement a simple "memory device" 
application based on STemWin for STM32F4xx devices.

The application shows the capability of STemWin to use the memory devices toi achieve tricky operations
like rotations, shifts and zoom. 

 How to interact with the application
 ------------------------------------
 - The application is an automatic run.
 - It will show an alternance between rotating, zooming, shifting of different wheels
 - It will loop infinetly.  

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Display, STemWin, Memory device, LCD, GUI, Demonstration, Touch screen

@par Directory contents 

    - STemWin/STemWin_MemoryDevice/Core/Inc/main.h			Main program header file
    - STemWin/STemWin_MemoryDevice/Core/Inc/stm32f4xx_hal_conf.h	Library Configuration file
    - STemWin/STemWin_MemoryDevice/Core/Inc/stm32f4xx_it.h		Interrupt handlers header file
    - STemWin/STemWin_MemoryDevice/Core/Src/main.c			Main program file
    - STemWin/STemWin_MemoryDevice/Core/Src/stm32f4xx_it.c		STM32F4xx Interrupt handlers
    - STemWin/STemWin_MemoryDevice/Core/Src/system_stm32f4xx.c		STM32F4xx system file
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel2.c	Wheel2 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel3.c	Wheel3 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel4.c	Wheel4 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/Wheel5.c	Wheel5 picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/generated/garage.c 	garage picture
    - STemWin/STemWin_MemoryDevice/STemWin/App/memory_device_app.c     memory devce application
    - STemWin/STemWin_MemoryDevice/STemWin/Target/GUIConf.c		Display controller initialization
    - STemWin/STemWin_MemoryDevice/STemWin/Target/GUIConf.h		Header for GUIConf.c
    - STemWin/STemWin_MemoryDevice/STemWin/Target/LCDConf.c		Configuration file for the GUI library
    - STemWin/STemWin_MemoryDevice/STemWin/Target/LCDConf.h		Header for LCDConf.c

  
@par Hardware and Software environment  

  - This application runs on STM32F429xx devices.

  - This application has been tested with STMicroelectronics STM32F429I-Discovery
    boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
  - Open your preferred toolchain 
  - Rebuild all files and load your image into target memory
  - Run the application
 
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
