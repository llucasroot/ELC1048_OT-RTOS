/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_adc_async.h>

#include <hal_usart_sync.h>

#include <hal_i2c_m_sync.h>

#include <hal_delay.h>

extern struct adc_async_descriptor Light_sensor_ADC;

extern struct usart_sync_descriptor USART_debug;

extern struct i2c_m_sync_desc I2C_temperature;

void Light_sensor_ADC_init(void);

void USART_debug_PORT_init(void);
void USART_debug_CLOCK_init(void);
void USART_debug_init(void);

void I2C_temperature_CLOCK_init(void);
void I2C_temperature_init(void);
void I2C_temperature_PORT_init(void);

void delay_driver_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
