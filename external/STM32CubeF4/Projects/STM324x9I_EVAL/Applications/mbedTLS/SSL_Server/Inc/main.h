/**
  ******************************************************************************
  * @file    main.h
  * @author  MCD Application Team
  * @brief   main application header file. 
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */ 

#ifndef __MAIN_H
#define __MAIN_H

#define USE_DHCP

#include "stm32f4xx_hal.h"
#include "stm324x9i_eval.h"
#include "stm324x9i_eval_io.h"
#include "cmsis_os.h"

#ifdef USE_LCD
#include "stm324x9i_eval_lcd.h"
#include "stm324x9i_eval_sdram.h"
#include "lcd_log.h"
#endif

#define GW_ADDRESS      "157.168.9.254"
#define NETMASK_ADDRESS "255.255.254.0"

#define SERVER_PORT "4433"
#define SERVER_NAME "10.157.9.150"

#define  HTTP_RESPONSE \
    "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n" \
    "<h2>mbed TLS Test Server</h2>\r\n" \
    "<p>Successful connection using: %s</p>\r\n"


#ifdef USE_DHCP

#define IP_ADDR0  0
#define IP_ADDR1  0
#define IP_ADDR2  0
#define IP_ADDR3  0

#define GW_ADDR0  0
#define GW_ADDR1  0
#define GW_ADDR2  0
#define GW_ADDR3  0

#define MASK_ADDR0  0
#define MASK_ADDR1  0
#define MASK_ADDR2  0
#define MASK_ADDR3  0

#else

#define IP_ADDR0  10
#define IP_ADDR1  157
#define IP_ADDR2  9
#define IP_ADDR3  133

#define GW_ADDR0  10
#define GW_ADDR1  157
#define GW_ADDR2  9
#define GW_ADDR3  254

#define MASK_ADDR0  255
#define MASK_ADDR1  255
#define MASK_ADDR2  254
#define MASK_ADDR3  0

#endif /* USE_DHCP */
#ifdef MBEDTLS_MEMORY_BUFFER_ALLOC_C
#define MAX_MEM_SIZE 35 * 1024
#endif

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

void SSL_Server(void const *argument);
void Error_Handler(void);
void Success_Handler(void);


#endif /*__MAIN_H */
