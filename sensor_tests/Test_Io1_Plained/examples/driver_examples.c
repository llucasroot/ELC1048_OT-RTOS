/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static void convert_cb_Light_sensor_ADC(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
}

/**
 * Example of using Light_sensor_ADC to generate waveform.
 */
void Light_sensor_ADC_example(void)
{
	adc_async_register_callback(&Light_sensor_ADC, 0, ADC_ASYNC_CONVERT_CB, convert_cb_Light_sensor_ADC);
	adc_async_enable_channel(&Light_sensor_ADC, 0);
	adc_async_start_conversion(&Light_sensor_ADC);
}

/**
 * Example of using USART_debug to write "Hello World" using the IO abstraction.
 */
void USART_debug_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&USART_debug, &io);
	usart_sync_enable(&USART_debug);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

void delay_example(void)
{
	delay_ms(5000);
}
