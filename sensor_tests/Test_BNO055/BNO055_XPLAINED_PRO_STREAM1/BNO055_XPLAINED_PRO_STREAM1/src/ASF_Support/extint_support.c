/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		extint_support.c
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
* <license disclaimer>
*
* @file		extint_support.c
* @author	Ehsan Mohaimeni
*
* @brief	EXTINT ASF Driver Support Source File
*
*
*/



/************************************************************************/
/**\name Own Header File                                                */
/************************************************************************/
#include "extint_support.h"

void extint_initialize(void (*extint_handler_function)(void))
{
	extint_handler_function_ptr = extint_handler_function;
	extint_configure();
	extint_configure_callbacks();
}

void extint_configure(void)
{
	struct extint_chan_conf config_extint_chan;
	extint_chan_get_config_defaults(&config_extint_chan);
	
	config_extint_chan.gpio_pin = EXT1_IRQ_PIN;
	config_extint_chan.gpio_pin_mux = EXT1_IRQ_PINMUX;
	config_extint_chan.gpio_pin_pull = EXTINT_PULL_DOWN;
	config_extint_chan.detection_criteria = EXTINT_DETECT_RISING;
	
	extint_chan_set_config(EXT1_IRQ_INPUT, &config_extint_chan);
}

void extint_configure_callbacks(void)
{
	extint_register_callback(extint_detection_callback, EXT1_IRQ_INPUT, EXTINT_CALLBACK_TYPE_DETECT);
	extint_callback_detect_flag = false;
	extint_chan_enable_callback(EXT1_IRQ_INPUT, EXTINT_CALLBACK_TYPE_DETECT);
}

void extint_detection_callback(void)
{
	extint_callback_detect_flag = true;
	extint_handler_function_ptr();
}