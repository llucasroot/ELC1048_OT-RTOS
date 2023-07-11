#include <IO1X_Plained_drivers.h> 

/** 
 * Faz a conversão analógico digital do sensor de luz e avisa quando terminar 
 */
volatile bool conversion_done = false;
static void convert_cb_Light_sensor_ADC(const struct adc_async_descriptor *const descr, const uint8_t channel)
{
	conversion_done = true;
}

void sensors_init(void){
	/* Inicialização parametros sensor de luz */
	adc_async_register_callback(&Light_sensor_ADC, 0, ADC_ASYNC_CONVERT_CB, convert_cb_Light_sensor_ADC);
	adc_async_enable_channel(&Light_sensor_ADC, 0);
	adc_async_start_conversion(&Light_sensor_ADC);
	
	/* Inicialização paramentros USART */
	usart_sync_get_io_descriptor(&USART_debug, &USART_debug_io);
	
	/* Inicialização paramentros do sensor de temperatura */
	i2c_m_sync_enable(&I2C_temperature);
	AT30TSE75X = at30tse75x_construct(&AT30TSE75X_descr.parent, &I2C_temperature, CONF_AT30TSE75X_RESOLUTION);
}

/**
 * Escreve 1 byte na UART de debug
 */
void UART_write_byte(uint8_t byte_to_send){
	io_write(USART_debug_io, &byte_to_send, 1);
}

/**
 * Le o valor digital do sensor de luz após passar pelo ADC e calcula e entrega a iluminancia com base nas caracteristicas elétricas do sensor
 */
float GET_light_sensor(void){
	uint8_t lightSensorValue;
	float voltageSensor;
	float iluminance;
	
	/* Faz a conversão AD do sensor de luz*/
	adc_async_start_conversion(&Light_sensor_ADC);
	while(!conversion_done){}
	adc_async_read_channel(&Light_sensor_ADC, 0, &lightSensorValue, 1);
	
	/* Faz a definição dos valores de tensão lidos do sensor a partir dos dados quantizados do ADC*/
	voltageSensor = lightSensorValue * VCC_TARGET / 255;
	
	/* Calcula a iluminancia com base na corrente do resistor de coletor do fototransistor e na relação entre lux e corrente*/
	iluminance = (VCC_TARGET - voltageSensor) * 200;
	
	return iluminance;
}

uint16_t GET_temperature_sensor(void){
	return (uint16_t)temperature_sensor_read(AT30TSE75X);
}

/**
 * Liga o LED da placa de expansão IO1X
 */
void SET_IO1X_LED_ON(void){
	gpio_set_pin_level(LED, false);
}

/**
 * Desliga o LED da placa de expansão IO1X
 */
void SET_IO1X_LED_OFF(void){
	gpio_set_pin_level(LED, true);
}

/**
 * Converte um número float em string com a precisão informada
 * É usada para poder printar valor float em tela usando o sprintf
 * O compilador usado não aceita float no sprintf
 */
void floatToString(float num, char* str, int precision) {
	int i = 0;

	// Extract the integral part
	int integralPart = (int)num;

	// Convert the integral part to string
	do {
		str[i++] = integralPart % 10 + '0';
		integralPart /= 10;
	} while (integralPart > 0);

	// Reverse the integral part string
	int j;
	int len = i;
	for (j = 0; j < len / 2; j++) {
		char temp = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}

	// Add decimal point
	str[i++] = '.';

	// Extract the fractional part
	float fractionalPart = num - (int)num;

	// Convert the fractional part to string
	int k;
	for (k = 0; k < precision; k++) {
		fractionalPart *= 10;
		int digit = (int)fractionalPart;
		str[i++] = digit + '0';
		fractionalPart -= digit;
	}

	// Add null-terminating character
	str[i] = '\0';
}
