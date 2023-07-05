/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		extint_support.h
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
**************************************************************************
*
*
* @file		extint_support.h
* @author	Ehsan Mohaimeni
*
* @brief	EXTINT ASF Driver Support Header File
*
* External interrupt support uses ASF EXTINT driver modules and
* defines initialization and configuration functions for the microcontroller’s
* external interrupt channel that is needed.
*
*
*/


#ifndef EXTINT_SUPPORT_H_
#define EXTINT_SUPPORT_H_

/************************************************************************/
/**\name Includes                                                       */
/************************************************************************/

#include "extint.h"
#include "extint_callback.h"
#include "samd21_xplained_pro.h"

/************************************************************************/
/**\name Global Variables                                               */
/************************************************************************/

/*! the flag is set by the external interrupt callback function */
volatile bool extint_callback_detect_flag;

/************************************************************************/
/**\name Function Prototype Declaration                                 */
/************************************************************************/

/*!
* @brief		Initializes the external interrupt channel of the MCU
*
* @param[in]	extint_handler_function		Pointer to the interrupt handler function
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void extint_initialize(void (*extint_handler_function)(void));

/*!
* @brief		Configures the external interrupt channel of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void extint_configure(void);

/*!
* @brief
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void extint_configure_callbacks(void);

/*!
* @brief		Configures external interrupt callback register
				(sensitive to rising signal edge)
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void extint_detection_callback(void);

/*!
* @brief		Called after external interrupt detected
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void (*extint_handler_function_ptr)(void);



#endif /* EXTINT_SUPPORT_H_ */