/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		bno055_support.h
*
* Date:		2015/01/30
*
* Revision:	1.0
*
* Usage:	Part of BNO055 Xplained Pro - Data Stream Pro Project
*
**************************************************************************
* \section License
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*   Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
*
*   Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
*   Neither the name of the copyright holder nor the names of the
*   contributors may be used to endorse or promote products derived from
*   this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER
* OR CONTRIBUTORS BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE
*
* The information provided is believed to be accurate and reliable.
* The copyright holder assumes no responsibility
* for the consequences of use
* of such information nor for any infringement of patents or
* other rights of third parties which may result from its use.
* No license is granted by implication or otherwise under any patent or
* patent rights of the copyright holder.
*
*
*************************************************************************/
/*!
*
* @file		bno055_support.h
* @author	Ehsan Mohaimeni
*
* @brief	BNO055 API Support Header File
*
* BNO055 support defines functions to interface the sensor API
* with the actual BNO055 smart sensor via I2C.
* It implements bus read/write, delay and reset functions
* that are needed for this communication.
* It also defines the sensor initialization routine.
*
*
*/


#ifndef BNO055_SUPPORT_H_
#define BNO055_SUPPORT_H_

/************************************************************************/
/**\name Includes                                                       */
/************************************************************************/

#include "bno055.h"
#include "samd21_xplained_pro.h"
#include "i2c_support.h"
#include "tc_support.h"
#include "gpio_support.h"

/************************************************************************/
/**\name Macros                                                         */
/************************************************************************/

/*! determines the I2C slave address of BNO055
* The default I2C address of the BNO055 device is 0101001b (0x29). */
#define BNO055_I2C_SLAVE_ADDRESS		BNO055_I2C_ADDR2
/*! the external pin on the main board connected to the BNO055 I2C ADDR pin */
#define BNO055_I2C_ADDR_PIN				EXT1_PIN_5
/*! the external pin on the main board connected to the BNO055 BOOTLOAD pin */
#define BNO055_BOOT_LOAD_PIN			EXT1_PIN_10
/*! the external pin on the main board connected to the BNO055 RESET pin */
#define BNO055_RESET_PIN				EXT1_PIN_15
/*! determines the active state of BNO055 reset */
#define BNO055_RESET_ACTIVE				false
/*! the delay required to wait for BNO055 chip to reset */
#define BNO055_RESET_DELAY_MS			UINT32_C(650)

/************************************************************************/
/**\name Global Variables                                               */
/************************************************************************/

/*! instantiates a BNO055 software instance structure which retains
* chip ID, internal sensors IDs, I2C address and pointers
* to required functions (bus read/write and delay functions) */
struct bno055_t bno055;
/*! instantiates an I2C packet software instance structure which retains
* I2C slave address, data buffer and data length and is used to read/write
* data on the I2C bus */
struct i2c_master_packet bno_i2c_packet;

/************************************************************************/
/**\name Function Prototype Declarations                                */
/************************************************************************/

/*!
* @brief		Initializes BNO055 smart sensor and its required connections
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void bno055_initialize(void);

/*!
* @brief		Sends data to BNO055 via I2C
*
* @param[in]	dev_addr	Device I2C slave address
*
* @param[in]	reg_addr	Address of destination register
*
* @param[in]	reg_data	Pointer to data buffer to be sent
*
* @param[in]	length		Length of the data to be sent
*
* @retval		0			BNO055_SUCCESS
* @retval		-1			BNO055_ERROR
*
*/
int8_t bno055_i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t length);

/*!
* @brief		Receives data from BNO055 on I2C
*
* @param[in]	dev_addr	Device I2C slave address
*
* @param[in]	reg_addr	Address of destination register
*
* @param[out]	reg_data	Pointer to data buffer to be received
*
* @param[in]	length		Length of the data to be received
*
* @retval		0			BNO055_SUCCESS
* @retval		-1			BNO055_ERROR
*
*/
int8_t bno055_i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *rx_data, uint8_t length);

/*!
* @brief		Initiates a delay of the length of the argument in milliseconds
*
* @param[in]	msec	Delay length in terms of milliseconds
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void bno055_delay_msec(uint32_t msec);

/*!
* @brief		Resets the BNO055 chip
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void bno055_reset(void);



#endif /* BNO055_SUPPORT_H_ */