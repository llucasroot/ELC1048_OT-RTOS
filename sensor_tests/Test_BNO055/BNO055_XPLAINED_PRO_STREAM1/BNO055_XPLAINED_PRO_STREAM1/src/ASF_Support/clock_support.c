/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		clock_support.c
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
* @file		clock_support.c
* @author	Ehsan Mohaimeni
*
* @brief	Clock Management ASF Driver Support Source File
*
*/


//************************************************************************/
/**\name Own Header File                                                */
/************************************************************************/
#include "clock_support.h"

void clock_initialize(void)
{
	clock_configure_osc8m();
	clock_configure_gclk_generator_1();
	clock_configure_dfll();
	
	clock_configure_system_clock ();
	
	clock_configure_gclk_generator_3();
	clock_configure_gclk_generator_4();
}

void clock_configure_dfll(void)
{
	struct system_gclk_chan_config dfll_gclk_chan_conf;
	
	system_gclk_chan_get_config_defaults(&dfll_gclk_chan_conf);
	dfll_gclk_chan_conf.source_generator = GCLK_GENERATOR_1;
	system_gclk_chan_set_config(SYSCTRL_GCLK_ID_DFLL48, &dfll_gclk_chan_conf);
	system_gclk_chan_enable(SYSCTRL_GCLK_ID_DFLL48);
		
	struct system_clock_source_dfll_config config_dfll;
	system_clock_source_dfll_get_config_defaults(&config_dfll);
	config_dfll.loop_mode = SYSTEM_CLOCK_DFLL_LOOP_MODE_CLOSED;
	config_dfll.on_demand = false;
	config_dfll.coarse_max_step	= (0x1f / 4);
	config_dfll.fine_max_step	= 1;
	
	system_clock_source_dfll_set_config(&config_dfll);
	enum status_code dfll_status = system_clock_source_enable(SYSTEM_CLOCK_SOURCE_DFLL);

	while (dfll_status != STATUS_OK) {
		/* Error enabling the clock source */
	}
}

void clock_configure_osc8m(void)
{
	struct system_clock_source_osc8m_config config_osc8m;
	system_clock_source_osc8m_get_config_defaults(&config_osc8m);
	config_osc8m.prescaler = SYSTEM_OSC8M_DIV_1;
	system_clock_source_osc8m_set_config(&config_osc8m);
}

void clock_configure_system_clock(void)
{
	system_flash_set_waitstates(2);
	
	struct system_gclk_gen_config config_gclock_gen;
	system_gclk_gen_get_config_defaults(&config_gclock_gen);
	config_gclock_gen.source_clock = SYSTEM_CLOCK_SOURCE_DFLL;
	config_gclock_gen.division_factor = 1;
	system_gclk_gen_set_config(GCLK_GENERATOR_0, &config_gclock_gen);
}


void clock_configure_gclk_generator_1(void)
{
	struct system_gclk_gen_config gclock_gen_conf;
	system_gclk_gen_get_config_defaults(&gclock_gen_conf);
	gclock_gen_conf.source_clock    = SYSTEM_CLOCK_SOURCE_OSC8M;
	gclock_gen_conf.division_factor = 1;
	
	system_gclk_gen_set_config(GCLK_GENERATOR_1, &gclock_gen_conf);
	system_gclk_gen_enable(GCLK_GENERATOR_1);
}


void clock_configure_gclk_generator_3(void)
{
	struct system_gclk_gen_config gclock_gen_conf;
	system_gclk_gen_get_config_defaults(&gclock_gen_conf);
	gclock_gen_conf.source_clock = SYSTEM_CLOCK_SOURCE_OSC8M;
	gclock_gen_conf.division_factor = 16;
	
	system_gclk_gen_set_config(GCLK_GENERATOR_3, &gclock_gen_conf);
	system_gclk_gen_enable(GCLK_GENERATOR_3);
}

void clock_configure_gclk_generator_4(void)
{
	struct system_gclk_gen_config gclock_gen_conf;
	system_gclk_gen_get_config_defaults(&gclock_gen_conf);
	gclock_gen_conf.source_clock = SYSTEM_CLOCK_SOURCE_OSC8M;
	gclock_gen_conf.division_factor = 1;
	
	system_gclk_gen_set_config(GCLK_GENERATOR_4, &gclock_gen_conf);
	system_gclk_gen_enable(GCLK_GENERATOR_4);
}

