/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

#include <hpl_adc_base.h>

/* The channel amount for ADC */
#define LIGHT_SENSOR_ADC_CH_AMOUNT 1

/* The buffer size for ADC */
#define LIGHT_SENSOR_ADC_BUFFER_SIZE 16

/* The maximal channel number of enabled channels */
#define LIGHT_SENSOR_ADC_CH_MAX 0

struct adc_async_descriptor         Light_sensor_ADC;
struct adc_async_channel_descriptor Light_sensor_ADC_ch[LIGHT_SENSOR_ADC_CH_AMOUNT];

static uint8_t Light_sensor_ADC_buffer[LIGHT_SENSOR_ADC_BUFFER_SIZE];
static uint8_t Light_sensor_ADC_map[LIGHT_SENSOR_ADC_CH_MAX + 1];

struct usart_sync_descriptor USART_debug;

/**
 * \brief ADC initialization function
 *
 * Enables ADC peripheral, clocks and initializes ADC driver
 */
void Light_sensor_ADC_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
	adc_async_init(&Light_sensor_ADC,
	               ADC,
	               Light_sensor_ADC_map,
	               LIGHT_SENSOR_ADC_CH_MAX,
	               LIGHT_SENSOR_ADC_CH_AMOUNT,
	               &Light_sensor_ADC_ch[0],
	               (void *)NULL);
	adc_async_register_channel_buffer(&Light_sensor_ADC, 0, Light_sensor_ADC_buffer, LIGHT_SENSOR_ADC_BUFFER_SIZE);

	// Disable digital pin circuitry
	gpio_set_pin_direction(PA06, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(PA06, PINMUX_PA06B_ADC_AIN6);
}

void USART_debug_PORT_init(void)
{

	gpio_set_pin_function(PA04, PINMUX_PA04D_SERCOM0_PAD0);

	gpio_set_pin_function(PA05, PINMUX_PA05D_SERCOM0_PAD1);
}

void USART_debug_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM0);
	_gclk_enable_channel(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
}

void USART_debug_init(void)
{
	USART_debug_CLOCK_init();
	usart_sync_init(&USART_debug, SERCOM0, (void *)NULL);
	USART_debug_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA18

	gpio_set_pin_level(LED,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(LED, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED, GPIO_PIN_FUNCTION_OFF);

	Light_sensor_ADC_init();

	USART_debug_init();

	delay_driver_init();
}
