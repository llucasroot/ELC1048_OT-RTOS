/**
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		tc_support.h
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
* @file		tc_support.h
* @author	Ehsan Mohaimeni
*
* @brief	TC ASF Driver Support Header File
*
* TC support uses ASF timer/counter driver modules and defines
* initialization, configuration and callback functions for
* the microcontroller’s timer/counter peripherals that that are needed
* for scheduling tasks or initiating delays. In addition to these
* some wrapper functions are defined that are needed.
*
*
*/


#ifndef TC_SUPPORT_H_
#define TC_SUPPORT_H_

/************************************************************************/
/**\name Includes                                                       */
/************************************************************************/
#include "tc.h"
#include "tc_interrupt.h"
#include "bno055.h"

/************************************************************************/
/**\name Macro Definitions                                              */
/************************************************************************/

/*! Maximum value of a 32-bit counter */
#define COUNT_MAX_32BIT			UINT32_C(0xFFFFFFFF)
/*! Maximum value of a 16-bit counter */
#define COUNT_MAX_16BIT			UINT16_C(0xFFFF)
/*! TC3 count value to overflow after 100 milliseconds */
#define TC3_PERIOD_100MS		COUNT_MAX_16BIT - UINT16_C(50000)
/*! TC3 count value to overflow after 50 milliseconds */
#define TC3_PERIOD_50MS			COUNT_MAX_16BIT - UINT16_C(25000)
/*! the value loaded onto TC3 count register */
#define TC3_COUNT_VALUE			TC3_PERIOD_100MS

/************************************************************************/
/**\name Global Variables                                               */
/************************************************************************/

/*! Instantiates a TC software instance structure, used to retain
* software state information of the associated hardware module instance TC3 */
struct tc_module tc3_instance;
/*! Instantiates a TC software instance structure, used to retain
* software state information of the associated hardware module instance TC4 */
struct tc_module tc4_instance;
/*! Instantiates a TC software instance structure, used to retain
* software state information of the associated hardware module instance TC6*/
struct tc_module tc6_instance;


/*! Callback flag for TC3 (Overflow Flag) */
volatile bool tc3_callback_flag;
/*! Callback flag for TC4 (Compare Flag) */
volatile bool tc4_callback_flag;

/************************************************************************/
/**\name Function Prototype Declaration                                 */
/************************************************************************/

/*!
* @brief		Initializes TC3, TC4 and TC6 timer/counter modules of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc_initialize(void);

/*!
* @brief		Configures TC3 of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc3_configure(void);

/*!
* @brief		Configures TC3 callback register
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc3_configure_callbacks(void);

/*!
* @brief		Called when TC3 counter is equal to its capture channel 0 value
*
* @param[in]	module_inst_ptr	Pointer to the TC module which triggered the interrupt
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc3_callback(struct tc_module *const module_inst_ptr);

/*!
* @brief		Stops TC3 counter
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc3_stop_counter(void);

/*!
* @brief		Starts TC3 counter
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc3_start_counter(void);



/*!
* @brief		Configures TC4 of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc4_configure(void);

/*!
* @brief		Configures TC4 callback register
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc4_configure_callbacks(void);

/*!
* @brief		Called when TC4 counter is equal to its capture channel 0 value
*
* @param[in]	module_inst_ptr	Pointer to the TC module which triggered the interrupt
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc4_callback(struct tc_module *const module_inst_ptr);

/*!
* @brief		Implements a delay of the length of the argument in milliseconds
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc4_wait_for_msec(uint32_t msec);


/*!
* @brief		Configures TC6 of the MCU
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc6_configure(void);

/*!
* @brief		Changes the compare value of two capture channels of TC6
*
* @param[in]	cc0_value	Compare Value of Capture Channel 0
*
* @param[in]	cc1_value	Compare Value of Capture Channel 1
*
* @param[out]	NULL
*
* @return		NULL
*
*/
void tc6_capture_channels_update(uint32_t cc0_value, uint32_t cc1_value);



#endif /* TC_SUPPORT_H_ */

