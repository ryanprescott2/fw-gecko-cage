/**
  ******************************************************************************
  * @file    USB_Device/DFU_Standalone/Src/usbd_dfu_flash.c
  * @author  MCD Application Team
  * @brief   Memory management layer
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
/* Includes ------------------------------------------------------------------ */
#include "usbd_dfu_flash.h"
#include "stm32f4xx_hal_conf.h"

/* Private typedef ----------------------------------------------------------- */
/* Private define ------------------------------------------------------------ */
#define FLASH_DESC_STR      "@Internal Flash   /0x08000000/03*016Ka,01*016Kg,01*064Kg,07*128Kg,04*016Kg,01*064Kg,07*128Kg"

#define FLASH_ERASE_TIME    (uint16_t)50
#define FLASH_PROGRAM_TIME  (uint16_t)50

/* Private macro ------------------------------------------------------------- */
/* Private variables --------------------------------------------------------- */
/* Private function prototypes ----------------------------------------------- */
static uint32_t GetSector(uint32_t Address);

/* Extern function prototypes ------------------------------------------------ */
uint16_t Flash_If_Init(void);
uint16_t Flash_If_Erase(uint32_t Add);
uint16_t Flash_If_Write(uint8_t * src, uint8_t * dest, uint32_t Len);
uint8_t *Flash_If_Read(uint8_t * src, uint8_t * dest, uint32_t Len);
uint16_t Flash_If_DeInit(void);
uint16_t Flash_If_GetStatus(uint32_t Add, uint8_t Cmd, uint8_t * buffer);

#if defined ( __ICCARM__ )      /* !< IAR Compiler */
#pragma data_alignment=4
#endif
__ALIGN_BEGIN USBD_DFU_MediaTypeDef USBD_DFU_Flash_fops __ALIGN_END = {
  (uint8_t *) FLASH_DESC_STR,
  Flash_If_Init,
  Flash_If_DeInit,
  Flash_If_Erase,
  Flash_If_Write,
  Flash_If_Read,
  Flash_If_GetStatus,
};

/* Private functions --------------------------------------------------------- */
/**
  * @brief  Initializes Memory.
  * @param  None
  * @retval 0 if operation is successeful, MAL_FAIL else.
  */
uint16_t Flash_If_Init(void)
{
  /* Unlock the internal flash */
  HAL_FLASH_Unlock();
  return 0;
}

/**
  * @brief  De-Initializes Memory.
  * @param  None
  * @retval 0 if operation is successeful, MAL_FAIL else.
  */
uint16_t Flash_If_DeInit(void)
{
  /* Lock the internal flash */
  HAL_FLASH_Lock();
  return 0;
}

/**
  * @brief  Erases sector.
  * @param  Add: Address of sector to be erased.
  * @retval 0 if operation is successeful, MAL_FAIL else.
  */
uint16_t Flash_If_Erase(uint32_t Add)
{
  uint32_t startsector = 0;
  uint32_t sectornb = 0;
  /* Variable contains Flash operation status */
  HAL_StatusTypeDef status;
  FLASH_EraseInitTypeDef eraseinitstruct;

  /* Get the number of sector */
  startsector = GetSector(Add);

  eraseinitstruct.TypeErase = FLASH_TYPEERASE_SECTORS;
  eraseinitstruct.VoltageRange = FLASH_VOLTAGE_RANGE_3;
  eraseinitstruct.Sector = startsector;
  eraseinitstruct.NbSectors = 1;
  status = HAL_FLASHEx_Erase(&eraseinitstruct, &sectornb);

  if (status != HAL_OK)
  {
    return 1;
  }
  return 0;
}

/**
  * @brief  Writes Data into Memory.
  * @param  src: Pointer to the source buffer. Address to be written to.
  * @param  dest: Pointer to the destination buffer.
  * @param  Len: Number of data to be written (in bytes).
  * @retval 0 if operation is successeful, MAL_FAIL else.
  */
uint16_t Flash_If_Write(uint8_t * src, uint8_t * dest, uint32_t Len)
{
  uint32_t i = 0;

  for (i = 0; i < Len; i += 4)
  {
    /* Device voltage range supposed to be [2.7V to 3.6V], the operation will
     * be done by byte */
    if (HAL_FLASH_Program
        (FLASH_TYPEPROGRAM_WORD, (uint32_t) (dest + i),
         *(uint32_t *) (src + i)) == HAL_OK)
    {
      /* Check the written value */
      if (*(uint32_t *) (src + i) != *(uint32_t *) (dest + i))
      {
        /* Flash content doesn't match SRAM content */
        return 2;
      }
    }
    else
    {
      /* Error occurred while writing data in Flash memory */
      return 1;
    }
  }
  return 0;
}

/**
  * @brief  Reads Data into Memory.
  * @param  src: Pointer to the source buffer. Address to be written to.
  * @param  dest: Pointer to the destination buffer.
  * @param  Len: Number of data to be read (in bytes).
  * @retval Pointer to the physical address where data should be read.
  */
uint8_t *Flash_If_Read(uint8_t * src, uint8_t * dest, uint32_t Len)
{
  uint32_t i = 0;
  uint8_t *psrc = src;

  for (i = 0; i < Len; i++)
  {
    dest[i] = *psrc++;
  }
  /* Return a valid address to avoid HardFault */
  return (uint8_t *) (dest);
}

/**
  * @brief  Gets Memory Status.
  * @param  Add: Address to be read from.
  * @param  Cmd: Number of data to be read (in bytes).
  * @retval 0 if operation is successeful
  */
uint16_t Flash_If_GetStatus(uint32_t Add, uint8_t Cmd, uint8_t * buffer)
{
  switch (Cmd)
  {
  case DFU_MEDIA_PROGRAM:
    buffer[1] = (uint8_t) FLASH_PROGRAM_TIME;
    buffer[2] = (uint8_t) (FLASH_PROGRAM_TIME << 8);
    buffer[3] = 0;
    break;

  case DFU_MEDIA_ERASE:
  default:
    buffer[1] = (uint8_t) FLASH_ERASE_TIME;
    buffer[2] = (uint8_t) (FLASH_ERASE_TIME << 8);
    buffer[3] = 0;
    break;
  }
  return 0;
}

/**
  * @brief  Gets the sector of a given address
  * @param  Address Address of the FLASH Memory
  * @retval The sector of a given address
  */
static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if ((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if ((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if ((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if ((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if ((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if ((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if ((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else if ((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
  {
    sector = FLASH_SECTOR_7;
  }
  else if ((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
  {
    sector = FLASH_SECTOR_8;
  }
  else if ((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
  {
    sector = FLASH_SECTOR_9;
  }
  else if ((Address < ADDR_FLASH_SECTOR_11)
           && (Address >= ADDR_FLASH_SECTOR_10))
  {
    sector = FLASH_SECTOR_10;
  }
  else if ((Address < ADDR_FLASH_SECTOR_12)
           && (Address >= ADDR_FLASH_SECTOR_11))
  {
    sector = FLASH_SECTOR_11;
  }
  else if ((Address < ADDR_FLASH_SECTOR_13)
           && (Address >= ADDR_FLASH_SECTOR_12))
  {
    sector = FLASH_SECTOR_12;
  }
  else if ((Address < ADDR_FLASH_SECTOR_14)
           && (Address >= ADDR_FLASH_SECTOR_13))
  {
    sector = FLASH_SECTOR_13;
  }
  else if ((Address < ADDR_FLASH_SECTOR_15)
           && (Address >= ADDR_FLASH_SECTOR_14))
  {
    sector = FLASH_SECTOR_14;
  }
  else if ((Address < ADDR_FLASH_SECTOR_16)
           && (Address >= ADDR_FLASH_SECTOR_15))
  {
    sector = FLASH_SECTOR_15;
  }
  else if ((Address < ADDR_FLASH_SECTOR_17)
           && (Address >= ADDR_FLASH_SECTOR_16))
  {
    sector = FLASH_SECTOR_16;
  }
  else if ((Address < ADDR_FLASH_SECTOR_18)
           && (Address >= ADDR_FLASH_SECTOR_17))
  {
    sector = FLASH_SECTOR_17;
  }
  else if ((Address < ADDR_FLASH_SECTOR_19)
           && (Address >= ADDR_FLASH_SECTOR_18))
  {
    sector = FLASH_SECTOR_18;
  }
  else if ((Address < ADDR_FLASH_SECTOR_20)
           && (Address >= ADDR_FLASH_SECTOR_19))
  {
    sector = FLASH_SECTOR_19;
  }
  else if ((Address < ADDR_FLASH_SECTOR_21)
           && (Address >= ADDR_FLASH_SECTOR_20))
  {
    sector = FLASH_SECTOR_20;
  }
  else if ((Address < ADDR_FLASH_SECTOR_22)
           && (Address >= ADDR_FLASH_SECTOR_21))
  {
    sector = FLASH_SECTOR_21;
  }
  else if ((Address < ADDR_FLASH_SECTOR_23)
           && (Address >= ADDR_FLASH_SECTOR_22))
  {
    sector = FLASH_SECTOR_22;
  }
  else
  {
    sector = FLASH_SECTOR_23;
  }
  return sector;
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
