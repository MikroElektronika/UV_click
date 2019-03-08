/*
    __uv_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __uv_driver.h
@brief    UV Driver
@mainpage UV Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   UV
@brief      UV Click Driver
@{

| Global Library Prefix | **UV** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _UV_H_
#define _UV_H_

/** 
 * @macro T_UV_P
 * @brief Driver Abstract type 
 */
#define T_UV_P    const uint8_t*

/** @defgroup UV_COMPILE Compilation Config */              /** @{ */

   #define   __UV_DRV_SPI__                            /**<     @macro __UV_DRV_SPI__  @brief SPI driver selector */
//  #define   __UV_DRV_I2C__                            /**<     @macro __UV_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __UV_DRV_UART__                           /**<     @macro __UV_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup UV_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup UV_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup UV_INIT Driver Initialization */              /** @{ */

#ifdef   __UV_DRV_SPI__
void uv_spiDriverInit(T_UV_P gpioObj, T_UV_P spiObj);
#endif
#ifdef   __UV_DRV_I2C__
void uv_i2cDriverInit(T_UV_P gpioObj, T_UV_P i2cObj, uint8_t slave);
#endif
#ifdef   __UV_DRV_UART__
void uv_uartDriverInit(T_UV_P gpioObj, T_UV_P uartObj);
#endif


/** @defgroup UV_FUNC Driver Functions */                   /** @{ */



/**
 * @brief Generic write 12-bit data function
 *
 * @param[in] writeData    12-bit data to write
 *
 * Function write 12-bit data via SPI
 * to the MCP3201 chip.
 */
void uv_writeData( uint16_t writeData );

/**
 * @brief Generic read 12-bit data function
 *
 * @return result          12-bit ADC values
 *
 * Function write 12-bit data via SPI
 * to the MCP3201 chip.
 */
uint16_t uv_readData();

/**
 * @brief Calculate ultraviolet radiation levels function
 *
 * @return result          float data from ML8511 IC sensor [ mV ]
 *
 * Function calculate ultraviolet radiation levels
 * from ML8511 IC sensor.
 */
float uv_calculateUV();

/**
 * @brief Enable ML8511 sensor function
 *
 * Function enable ML8511 sensor for reading data.
 */
void uv_enableSensor();

/**
 * @brief Disable ML8511 sensor function
 *
 * Function disable ML8511 sensor.
 */
void uv_disableSensor();

/**
 * @brief Get analog voltage output function
 *
 * @return result          8-bit state of AN pin
 *
 * Function get analog voltage output from AN pin.
 */
uint8_t uv_getAnalogVoltageOutput();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_UV_STM.c
    @example Click_UV_TIVA.c
    @example Click_UV_CEC.c
    @example Click_UV_KINETIS.c
    @example Click_UV_MSP.c
    @example Click_UV_PIC.c
    @example Click_UV_PIC32.c
    @example Click_UV_DSPIC.c
    @example Click_UV_AVR.c
    @example Click_UV_FT90x.c
    @example Click_UV_STM.mbas
    @example Click_UV_TIVA.mbas
    @example Click_UV_CEC.mbas
    @example Click_UV_KINETIS.mbas
    @example Click_UV_MSP.mbas
    @example Click_UV_PIC.mbas
    @example Click_UV_PIC32.mbas
    @example Click_UV_DSPIC.mbas
    @example Click_UV_AVR.mbas
    @example Click_UV_FT90x.mbas
    @example Click_UV_STM.mpas
    @example Click_UV_TIVA.mpas
    @example Click_UV_CEC.mpas
    @example Click_UV_KINETIS.mpas
    @example Click_UV_MSP.mpas
    @example Click_UV_PIC.mpas
    @example Click_UV_PIC32.mpas
    @example Click_UV_DSPIC.mpas
    @example Click_UV_AVR.mpas
    @example Click_UV_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __uv_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */