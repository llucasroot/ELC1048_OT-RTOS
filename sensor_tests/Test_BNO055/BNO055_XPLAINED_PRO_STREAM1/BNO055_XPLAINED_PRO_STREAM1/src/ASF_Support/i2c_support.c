/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		i2c_support.c
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
* @file		i2c_support.c
* @author	Ehsan Mohaimeni
*
* @brief	I2C ASF Driver Support Source File
*
*
*/


/************************************************************************/
/**\name Own Header File                                                */
/************************************************************************/
#include "i2c_support.h"

void i2c_initialize(void)
{
	i2c_configure_master();
}

void i2c_configure_master(void)
{
	struct i2c_master_config config_i2c_master;
	i2c_master_get_config_defaults(&config_i2c_master);
	
	config_i2c_master.generator_source = GCLK_GENERATOR_0;
	config_i2c_master.start_hold_time = I2C_MASTER_START_HOLD_TIME_400NS_800NS;
	config_i2c_master.baud_rate = I2C_MASTER_BAUD_RATE_400KHZ;
	
	config_i2c_master.pinmux_pad0 = EXT1_I2C_SERCOM_PINMUX_PAD0;
	config_i2c_master.pinmux_pad1 = EXT1_I2C_SERCOM_PINMUX_PAD1;
	
	while(i2c_master_init(&i2c_master_instance, EXT1_I2C_MODULE, &config_i2c_master) != STATUS_OK);
	i2c_master_enable(&i2c_master_instance);
}
