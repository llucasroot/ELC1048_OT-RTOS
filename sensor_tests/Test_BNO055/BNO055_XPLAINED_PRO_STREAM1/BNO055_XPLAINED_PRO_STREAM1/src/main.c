/**\mainpage
*
*
**************************************************************************
* Copyright (C) 2015 Bosch Sensortec GmbH. All Rights Reserved.
*
* File:		main.c
*
* Date:		2015/02/02
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
* @file		main.c
* @author	Ehsan Mohaimeni
*
* @brief	Main Source File
*			uses Atmel drivers, sensor APIs and driver support facilities
*			to implement the desired application. The application specific functions,
*			constants and variables are all defined here.
*
*
*/



/************************************************************************/
/* Includes                                                             */
/************************************************************************/

/* The interface header for the Atmel MCU framework */
#include "asf.h"
/* Board specified macros such as external ports definitions and components available via these ports */
#include "samd21_xplained_pro.h"
/* Wrapper functions for BNO055 connection to the host microcontroller */
#include "bno055_support.h"
/* Wrapper functions for ASF clock and generic clock modules */
#include "clock_support.h"
/* Wrapper functions for ASF I2C module */
#include "i2c_support.h"
/* Wrapper functions for ASF Timer/Counter module */
#include "tc_support.h"
/* Wrapper functions for ASF USART module */
#include "usart_support.h"
/* Wrapper functions for ASF I/O pins driver */
#include "gpio_support.h"
/* Wrapper functions for ASF external interrupt channels module */
#include "extint_support.h"

/************************************************************************/
/* Macro Definitions                                                    */
/************************************************************************/

/*! Sensor data are read in accordance with TC3 callback */
#define READ_SENSORS_FLAG		tc3_callback_flag

/* Sleep State Macros */
#define SLEEP_STATE_SLEEP		UINT8_C(1)
#define SLEEP_STATE_AWAKE		UINT8_C(0)

/* name RGB LED Macros */
#define RGB_LED_R				EXT1_PIN_8
#define RGB_LED_G				EXT1_PIN_6
#define RGB_LED_B				EXT1_PIN_7
#define RGB_LED_G_ON			false
#define RGB_LED_G_OFF			true
#define RGB_LED_B_VALUE			(0xFFFF - ((bno055_euler_data.h) * 0xFFFF / 5759))
#define RBG_LED_B_OFF			UINT16_C(0xFFFF)
#define RGB_LED_R_VALUE			(0xFFFF - ((bno055_euler_data.p) * 0xFFFF / 5759))
#define RBG_LED_R_OFF			UINT16_C(0xFFFF)

/*! The blue and red colors of the LED are connected to two PWM signals
* derived by TC6 and the capture channel values determine the PWM duty cycle
* and thus the blue and red brightness. */
#define RGB_LED_B_R_UPDATE(cc0_value, cc1_value)\
tc6_capture_channels_update(cc0_value, cc1_value)

/************************************************************************/
/* Global Variables                                                     */
/************************************************************************/

/*! holds BNO055 Euler data which consists of three Euler angles (Heading, Roll and Pitch) */
struct bno055_euler_t			bno055_euler_data;
/*! Holds sleep state of the system */
uint8_t sleep_state;


/************************************************************************/
/* Function Declarations                                                */
/************************************************************************/

static void sensor_init(void);
static void sensors_data_print (void);
static void bno055_interrupt_handler_no_motion(void);
static void bno055_interrupt_handler_any_motion(void);
static void bno055_interrupt_handler(void);

/************************************************************************/
/* Function Definitions                                                 */
/************************************************************************/

/*!
* @brief	Initializes BNO055 smart sensor.
*
* This function calls initialization function of BNO055, sets sensor power mode
* to LOWPOWER, sets sensor operation mode to NDOF and enables the required
* interrupts (Accelerometer Any Motion, Accelerometer No Motion, Gyroscope Any Motion).
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
static void sensor_init(void)
{
	bno055_initialize();
	bno055_set_power_mode(POWER_MODE_LOWPOWER);
	bno055_set_intr_rst(ENABLED);
	
	/* Configure sensor interrupts */
	bno055_set_gyro_any_motion_axis_enable(0, ENABLED);
	bno055_set_gyro_any_motion_axis_enable(1, ENABLED);
	bno055_set_gyro_any_motion_axis_enable(2, ENABLED);
	
	bno055_set_intr_gyro_any_motion(ENABLED);
	bno055_set_intr_mask_gyro_any_motion(ENABLED);
	
	bno055_set_accel_any_motion_no_motion_axis_enable(0, ENABLED);
	bno055_set_accel_any_motion_no_motion_axis_enable(1, ENABLED);
	bno055_set_accel_any_motion_no_motion_axis_enable(2, ENABLED);
	
	bno055_set_accel_any_motion_thres(5);
	bno055_set_accel_any_motion_durn(1);
	bno055_set_intr_accel_any_motion(ENABLED);
	bno055_set_intr_mask_accel_any_motion(ENABLED);
	
	bno055_set_accel_slow_no_motion_thres(5);
	bno055_set_accel_slow_no_motion_durn(1);
	bno055_set_intr_accel_no_motion(ENABLED);
	bno055_set_intr_mask_accel_no_motion(ENABLED);

	bno055_set_operation_mode(OPERATION_MODE_NDOF);
}

/*!
* @brief	Reads output data of the sensor and sends them data via USART.
*
* This function reads output data of BNO055 (Three Euler angles) using
* sensor API functions and sends sensor data in ASCII Format via USART.
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
static void sensors_data_print (void)
{
	uint8_t uart_tx_buf[49] = {0};
	uint8_t accel_calib = 0;
	uint8_t gyro_calib = 0;
	uint8_t mag_calib = 0;
	
	bno055_read_euler_hrp(&bno055_euler_data);
	bno055_get_accel_calib_stat(&accel_calib);
	bno055_get_gyro_calib_stat(&gyro_calib);
	bno055_get_mag_calib_stat(&mag_calib);
	
	
	sprintf((char *)uart_tx_buf, "H: %4d\tR: %4d\tP: %4d\tCalib: %d%d%d\r\n",
	(bno055_euler_data.h)/16, (bno055_euler_data.r)/16, (bno055_euler_data.p)/16,
	accel_calib, gyro_calib, mag_calib);
	usart_write_buffer_wait(&usart_instance, uart_tx_buf,sizeof(uart_tx_buf));
}

/*!
* @brief	No motion interrupt handler.
*
* This function is called when a no-motion interrupt is triggered
* by the accelerometer in BNO055,	turns the LED color to green,
* stops data stream and sends a message to the terminal window.
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
static void bno055_interrupt_handler_no_motion(void)
{
	const uint8_t str_sleeping_message[] = "\r\nShake me to wake me!\r\n\r\n";
	
	tc3_stop_counter();
	port_pin_set_output_level(RGB_LED_G,  RGB_LED_G_ON);
	RGB_LED_B_R_UPDATE(RBG_LED_B_OFF, RBG_LED_R_OFF);
	usart_write_buffer_wait(&usart_instance, str_sleeping_message, sizeof(str_sleeping_message));
}

/*!
* @brief	Any motion interrupt handler.
*
* This function is called when an any-motion interrupt is triggered
* by the accelerometer or gyroscope in BNO055, turns off the green light,
* sends a message to the terminal window and starts data stream.
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/
static void bno055_interrupt_handler_any_motion(void)
{
	const uint8_t str_wakingup_message[] = "\r\nGood job!\r\n\r\n";
	
	usart_write_buffer_wait(&usart_instance, str_wakingup_message, sizeof(str_wakingup_message));
	RGB_LED_B_R_UPDATE(RGB_LED_B_VALUE, RGB_LED_R_VALUE);
	port_pin_set_output_level(RGB_LED_G,  RGB_LED_G_OFF);
	tc3_start_counter();
}

/*!
* @brief	Sensor general interrupt handler, calls specific handlers.
*
* This function is called when an external interrupt is triggered by the sensor,
* checks interrupt registers of BNO055 to determine the source and type of interrupt
* and calls the specific interrupt handler accordingly.
*
* @param[in]	NULL
*
* @param[out]	NULL
*
* @return		NULL
*
*/

static void bno055_interrupt_handler(void)
{
	uint8_t accel_no_motion_status = 0;
	uint8_t accel_any_motion_status = 0;
	uint8_t gyro_any_motion_status = 0;

	bno055_get_intr_stat_accel_no_motion(&accel_no_motion_status);
	bno055_get_intr_stat_accel_any_motion(&accel_any_motion_status);
	bno055_get_intr_stat_gyro_any_motion(&gyro_any_motion_status);
	
	switch (sleep_state)
	{
		case SLEEP_STATE_AWAKE:
		if (accel_no_motion_status)
		{
			sleep_state = SLEEP_STATE_SLEEP;
			bno055_interrupt_handler_no_motion();
		}
		break;
		case SLEEP_STATE_SLEEP:
		if (accel_any_motion_status || gyro_any_motion_status)
		{
			sleep_state = SLEEP_STATE_AWAKE;
			bno055_interrupt_handler_any_motion();
		}
		break;
		default:
		break;
	}
	
	bno055_set_intr_rst(ENABLED);
}


/************************************************************************/
/* Main Function Definition                                             */
/************************************************************************/
/*!
* @brief	Initializes the whole system and runs the desired application
*
* This is the main function of the project. It calls initialization functions
* of the main board and the sensor. It initializes the host microcontroller unit
* and all its required modules such as clock sources, I2C, TC, USART, PINMUX
* and interrupt controllers. It also initializes the global variables.
*/

int main(void)
{
	/* Initialize the main board (SAM D21 Xplained Pro board) */
	
	system_init();
	/* (Main clock: DFLL Closed Loop 48 MHz ) */
	clock_initialize();
	/* (Frequency: 400 KHz) */
	i2c_initialize();
	/* (TC3: Scheduling sensor reads, TC4: Delay, TC6: PWM signals for RGB LED ) */
	tc_initialize();
	/* (Baud rate = 112500, Data bits = 8, Parity = None, Stop bit = 1) */
	usart_initialize();
	/* (BNO055_RESET, BNO055_BOOT_LOAD, BNO055_I2C_ADDR, RGB_LEG_Green) */
	gpio_initialize();
	/* (BNO055 external interrupt) */
	extint_initialize(&bno055_interrupt_handler);
	
	system_interrupt_enable_global();
	
	/* Initialize BNO055 smart sensor */
	sensor_init();
	
	/* Assigns initial values to the global variable sleep_state */
	sleep_state = SLEEP_STATE_AWAKE;
	
	/* RGB LED Green = OFF */
	port_pin_set_output_level(RGB_LED_G,  RGB_LED_G_OFF);
	/* RGB LED Blue and Red = OFF */
	RGB_LED_B_R_UPDATE(RBG_LED_B_OFF, RBG_LED_R_OFF);
	
	
	/* Infinite loop */
	while (true) {
		
		/* Print sensor data periodically regarding TC3 interrupt flag (default period is 100 ms) */
		if (READ_SENSORS_FLAG)
		{
			/* Read Euler angles from BNO055 and send it via USART */
			sensors_data_print();
			/*! Change RGB LED blue and red color proportional to Heading and Pitch Euler angles */
			RGB_LED_B_R_UPDATE(RGB_LED_B_VALUE, RGB_LED_R_VALUE);
			/* Reset the timer's interrupt flag */
			READ_SENSORS_FLAG = false;
		}
		
		/* Check sensor reset button (SW0 button on the main board) */
		if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
			/* turn LED0 on */
			port_pin_set_output_level(LED_0_PIN, LED_0_ACTIVE);
			/* Reset BNO055 */
			sensor_init();
			} else {
			/* turn LED off if the button is not pressed */
			port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		}
		
	}
	
	
}
