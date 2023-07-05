/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		bno055_support.c
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
* @file		bno055_support.c
* @author	Ehsan Mohaimeni
*
* @brief	BNO055 API Support Source File
*
*
*/

/************************************************************************/
/**\name Own Header File                                                */
/************************************************************************/
#include "bno055_support.h"

void bno055_initialize(void)
{
	bno055.bus_write = &bno055_i2c_write;
	bno055.bus_read = &bno055_i2c_read;
	bno055.delay_msec = &bno055_delay_msec;
	bno055.dev_addr = BNO055_I2C_SLAVE_ADDRESS;
	
	#if BNO055_I2C_SLAVE_ADDRESS == BNO055_I2C_ADDR1
	port_pin_set_output_level(BNO055_I2C_ADDR_PIN, false);
	#else
	port_pin_set_output_level(BNO055_I2C_ADDR_PIN, true);
	#endif
	
	port_pin_set_output_level(BNO055_BOOT_LOAD_PIN,  true);
	bno055_reset();
	bno055_init(&bno055);
	
	
}

int8_t bno055_i2c_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *reg_data, uint8_t length)
{
	enum status_code bno_write_stat = STATUS_NO_CHANGE;
	uint8_t packet_buffer[length + 1];
	packet_buffer[0] = reg_addr;
	uint16_t i;
	for (i=0; i<=length; i++)
	{
		packet_buffer[i+1] = reg_data[i];
	}
	bno_i2c_packet.address = dev_addr;
	bno_i2c_packet.ten_bit_address = false;
	bno_i2c_packet.high_speed = false;
	bno_i2c_packet.data = packet_buffer;
	bno_i2c_packet.data_length = length + 1;
	bno_write_stat = i2c_master_write_packet_wait(&i2c_master_instance, &bno_i2c_packet);
	
	if (bno_write_stat != STATUS_OK)
	{
		i2c_master_send_stop(&i2c_master_instance);
		i2c_master_disable(&i2c_master_instance);
		i2c_initialize();
		return BNO055_ERROR;
	}
	
	return BNO055_SUCCESS;
}

int8_t bno055_i2c_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *rx_data, uint8_t length)
{
	enum status_code bno_read_stat = STATUS_NO_CHANGE;
	
	bno_i2c_packet.address = dev_addr;
	bno_i2c_packet.ten_bit_address = false;
	bno_i2c_packet.high_speed = false;
	bno_i2c_packet.data = &reg_addr;
	bno_i2c_packet.data_length = 1;
	bno_read_stat = i2c_master_write_packet_wait_no_stop(&i2c_master_instance, &bno_i2c_packet);
	
	if (bno_read_stat == STATUS_OK)
	{
		bno_i2c_packet.data = rx_data;
		bno_i2c_packet.data_length = length;
		bno_read_stat = i2c_master_read_packet_wait(&i2c_master_instance, &bno_i2c_packet);
	}
	
	
	if (bno_read_stat != STATUS_OK)
	{
		i2c_master_disable(&i2c_master_instance);
		i2c_initialize();
		return BNO055_ERROR;
	}
	
	return BNO055_SUCCESS;
}

void bno055_delay_msec(uint32_t msec)
{
	tc4_wait_for_msec(msec);
}

void bno055_reset(void)
{
	port_pin_set_output_level(BNO055_RESET_PIN,  BNO055_RESET_ACTIVE);
	tc4_wait_for_msec(BNO055_RESET_DELAY_MS);
	port_pin_set_output_level(BNO055_RESET_PIN, !BNO055_RESET_ACTIVE);
	tc4_wait_for_msec(BNO055_RESET_DELAY_MS);
}
