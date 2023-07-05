/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		clock_support.h
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
* @file		clock_support.h
* @author	Ehsan Mohaimeni
*
* @brief	Clock Management ASF Driver Support Header File
*
* Clock support uses ASF clock management modules and defines
* initialization and configuration functions for the microcontroller’s
* clock sources and generic clock generators that are needed.
*
*
*/

#ifndef clock_support_h_
#define clock_support_h_

/************************************************************************/
/**\name Includes                                                       */
/************************************************************************/

#include <clock.h>
#include <gclk.h>

/************************************************************************/
/**\name Function Prototype Declaration                                 */
/************************************************************************/

/*!
* @brief		Initializes clock sources, generic clock generators and system main clock of the MCU
*
* This function calls configuration functions for DFLL48M and OSC8M clock sources,
* generic clock generators 1, 3 and 4 and the main clock of the system (generic clock generator 0).
* After initialization, the clock sources’ and generic clock generators’ frequencies are as follows:
*	OSC8M:	8 MHz
*	DFLL:	Closed Loop, 48 MHz
*	GCLK0:	48 MHz
*	GCLK1:	8 MHz
*	GLCK3:	500 KHz
*	GCLK4:	8 MHz
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_initialize(void);

/*!
* @brief		Configures the DFLL48M clock source of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_dfll(void);

/*!
* @brief		Configures the 8 MHz internal clock source of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_osc8m(void);

/*!
* @brief		Configures system main clock source
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_system_clock(void);

/*!
* @brief		Configures generic clock generator 1
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_gclk_generator_1(void);

/*!
* @brief		Configures generic clock generator 3
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_gclk_generator_3(void);

/*!
* @brief		Configures generic clock generator 4
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void clock_configure_gclk_generator_4(void);




#endif /* clock_support_h_ */