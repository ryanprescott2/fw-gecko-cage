/**
  @page ADC_RegularConversion_DMA ADC3 conversion using DMA for Data transfer

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics  *******************
  * @file    ADC/ADC_RegularConversion_DMA/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the ADC RegularConversion DMA example.
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

How to use the ADC3 and DMA to transfer continuously converted data from 
ADC3 to memory.

The ADC3 is configured to convert continuously channel7(for STM32F429I-DISCOVERY)
/channel8(for STM32F429I-Discovery RevC).

Each time an end of conversion occurs the DMA transfers, in circular mode, the
converted data from ADC3 DR register to the uhADCxConvertedValue variable.

In this example, the system clock is 144MHz, APB2 = 72MHz and ADC clock = APB2/2. 
Since ADC3 clock is 36 MHz and sampling time is set to 3 cycles, the conversion 
time to 12bit data is 12 cycles so the total conversion time is (12+3)/36= 0.41us(2.4Msps).

User can vary the ADC3 channel8(for STM32429i-Discovery) voltage probing external
power supply on PF10 Gpio pin.

STM32 Discovery board's LEDs can be used to monitor the transfer status:
 - LED3 is ON when the conversion is complete.
 - LED4 is ON when there are an error in initialization.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Analog, ADC, Analog to Digital Converter, Regular Conversion, DMA, Continuous Conversion

@par Directory contents 

  - ADC/ADC_RegularConversion_DMA/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - ADC/ADC_RegularConversion_DMA/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - ADC/ADC_RegularConversion_DMA/Inc/main.h                  Main program header file  
  - ADC/ADC_RegularConversion_DMA/Src/stm32f4xx_it.c          Interrupt handlers
  - ADC/ADC_RegularConversion_DMA/Src/main.c                  Main program
  - ADC/ADC_RegularConversion_DMA/Src/stm32f4xx_hal_msp.c     HAL MSP module
  - ADC/ADC_RegularConversion_DMA/Src/system_stm32f4xx.c      STM32F4xx system clock configuration file


@par Hardware and Software environment
 
  - This example runs on STM32F429xx devices.
    
  - This example has been tested with STMicroelectronics STM32F429I-Discovery RevC
    boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
