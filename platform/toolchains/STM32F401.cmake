set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")

set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -specs=nano.specs -lc -lm -lnosys -Wl,--gc-sections" CACHE INTERNAL "")
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -fdata-sections -ffunction-sections -g -gdwarf-2" CACHE INTERNAL "")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -fdata-sections -ffunction-sections -g -gdwarf-2" CACHE INTERNAL "")

set(UNSPUN_CROSSCOMPILING ON CACHE BOOL "TRUE" FORCE)
set(UNSPUN_PLATFORM "stm32f4" CACHE STRING "stm32f4" FORCE)
set(UNSPUN_CHIPSET "STM32F413" CACHE STRING "STM32F413" FORCE)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)