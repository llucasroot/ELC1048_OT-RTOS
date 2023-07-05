/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		tc_support.c
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
* @file		tc_support.c
* @author	Ehsan Mohaimeni
*
* @brief	TC ASF Driver Support Source File
*
*
*/

/************************************************************************/
/**\name Own Header File                                                */
/************************************************************************/
#include "tc_support.h"

void tc_initialize(void)
{
	tc3_configure();
	tc3_configure_callbacks();
	
	tc4_configure ();
	tc4_configure_callbacks();
	
	tc6_configure();
}

void tc3_configure(void)
{
	struct tc_config config_tc;
	tc_get_config_defaults(&config_tc);
	
	config_tc.counter_size = TC_COUNTER_SIZE_16BIT;
	config_tc.clock_source = GCLK_GENERATOR_3;
	config_tc.clock_prescaler = TC_CLOCK_PRESCALER_DIV1;
	config_tc.counter_16_bit.value = TC3_COUNT_VALUE;
	tc_init(&tc3_instance,TC3,&config_tc);
	tc_enable(&tc3_instance);
}


void tc3_configure_callbacks(void)
{
	tc_register_callback(&tc3_instance, tc3_callback, TC_CALLBACK_OVERFLOW);
	tc3_callback_flag = false;
	tc_enable_callback(&tc3_instance, TC_CALLBACK_OVERFLOW);
}

void tc3_callback (struct tc_module *const module_inst_ptr)
{
	tc_set_count_value(&tc3_instance, TC3_COUNT_VALUE);
	tc3_callback_flag = true;
}

void tc3_stop_counter (void)
{
	tc_stop_counter(&tc3_instance);
}

void tc3_start_counter (void)
{
	tc_set_count_value(&tc3_instance, TC3_COUNT_VALUE);
	tc_start_counter(&tc3_instance);
}

void tc4_configure (void)
{
	struct tc_config config_tc;
	tc_get_config_defaults(&config_tc);
	
	config_tc.clock_source = GCLK_GENERATOR_3;
	config_tc.counter_size = TC_COUNTER_SIZE_32BIT;
	config_tc.counter_32_bit.value = 500;
	
	tc_init(&tc4_instance, TC4, &config_tc);
	tc_enable(&tc4_instance);
	tc_stop_counter(&tc4_instance);
}


void tc4_configure_callbacks (void)
{
	tc_register_callback(&tc4_instance, tc4_callback, TC_CALLBACK_CC_CHANNEL0);
	tc4_callback_flag = false;
	tc_enable_callback(&tc4_instance, TC_CALLBACK_CC_CHANNEL0);
}

void tc4_callback (struct tc_module *const module_inst_ptr)
{
	tc4_callback_flag = true;
}

void tc4_wait_for_msec (uint32_t msec)
{
	tc_set_compare_value(&tc4_instance, TC_COMPARE_CAPTURE_CHANNEL_0, (msec *500));
	tc_start_counter(&tc4_instance);
	
	while (!tc4_callback_flag);
	
	tc_stop_counter(&tc4_instance);
	tc4_callback_flag = false;
}


void tc6_configure(void)
{
	struct tc_config config_tc;
	tc_get_config_defaults(&config_tc);
	
	config_tc.counter_size = TC_COUNTER_SIZE_16BIT;
	config_tc.clock_source = GCLK_GENERATOR_1;
	config_tc.wave_generation = TC_WAVE_GENERATION_NORMAL_PWM;
	
	config_tc.counter_16_bit.compare_capture_channel[0] = 0xFFFF;
	config_tc.pwm_channel[0].enabled = true;
	config_tc.pwm_channel[0].pin_out = PIN_PB02E_TC6_WO0;
	config_tc.pwm_channel[0].pin_mux = PINMUX_PB02E_TC6_WO0;
	
	config_tc.counter_16_bit.compare_capture_channel[1] = 0xFFFF;
	config_tc.pwm_channel[1].enabled = true;
	config_tc.pwm_channel[1].pin_out = PIN_PB03E_TC6_WO1;
	config_tc.pwm_channel[1].pin_mux = PINMUX_PB03E_TC6_WO1;
	
	tc_init(&tc6_instance,TC6,&config_tc);
	tc_enable(&tc6_instance);
	
}

void tc6_capture_channels_update(uint32_t cc0_value, uint32_t cc1_value)
{
	tc_set_compare_value(&tc6_instance, TC_COMPARE_CAPTURE_CHANNEL_0, cc0_value);
	tc_set_compare_value(&tc6_instance, TC_COMPARE_CAPTURE_CHANNEL_1, cc1_value);
}