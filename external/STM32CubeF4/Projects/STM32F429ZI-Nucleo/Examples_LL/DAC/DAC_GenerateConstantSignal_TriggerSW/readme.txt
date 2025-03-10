/**
  @page DAC_GenerateConstantSignal_TriggerSW DAC example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    Examples_LL/DAC/DAC_GenerateConstantSignal_TriggerSW/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the DAC_GenerateConstantSignal_TriggerSW example.
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
This example describes how to use the DAC peripheral to generate
a constant voltage signal; 
This example is based on the STM32F4xx DAC LL API; 
peripheral initialization done using LL unitary services functions
for optimization purpose (performance and size).

Example configuration:
One DAC channel (DAC1 channel1) is configured to connect DAC channel output on GPIO pin
to get the samples from SW (no DMA transfer) and to get conversion trigger from SW.

Example execution:
From the main program execution, LED1 is toggling quickly while waiting for
user button press.
Then, the DAC is configured and activated: constant signal is generated on DAC output
indefinitely.
DAC channel output value is provided by SW, a new value is loaded
at each press on push button: LED1 toggles and the signal starts from 0, increased by a quarter of Vdda and
finishing at Vdda voltage.
Finally, LED1 is turned-on.


Note: In case of noise on DAC channel, DAC output voltage may trig at a voltage level with an uncertainty of tens of mV.

Connection needed:
None. 
Oscilloscope for monitoring DAC channel output (cf pin below).
Other peripheral used:
  1 GPIO for push button
  1 GPIO for DAC channel output PA.04 (Board Nucleo144: morpho connector CN11 pin 32 (in front of Arduino connector CN9 pin A2), Zio connector CN7 pin 17)

@par Keywords

Analog, DAC, Conversion, Voltage output, Oscilloscope, Signal, Software trigger, 

@par Directory contents 

  - DAC/DAC_GenerateConstantSignal_TriggerSW/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - DAC/DAC_GenerateConstantSignal_TriggerSW/Inc/main.h                  Header for main.c module
  - DAC/DAC_GenerateConstantSignal_TriggerSW/Inc/stm32_assert.h          Template file to include assert_failed function
  - DAC/DAC_GenerateConstantSignal_TriggerSW/Src/stm32f4xx_it.c          Interrupt handlers
  - DAC/DAC_GenerateConstantSignal_TriggerSW/Src/main.c                  Main program
  - DAC/DAC_GenerateConstantSignal_TriggerSW/Src/system_stm32f4xx.c      STM32F4xx system source file


@par Hardware and Software environment

  - This example runs on STM32F429xx devices.
    
  - This example has been tested with STM32F429ZI-Nucleo Rev B board and can be
    easily tailored to any other supported device and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
