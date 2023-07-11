/**
 * Código de teste dos sensores 
 * 
 * Desenvolvimento atual por Guilherme Ribeiro Silveira
 *
 * Link do relatório com os calculos utilizados neste código
 * https://docs.google.com/document/d/14jGzlbBa0Ey1IuW73ailFBDOAaCUMx8I5gUdWG36onQ/edit?usp=sharing
 *
 */
 
#include <atmel_start.h>
#include <stdio.h>
#include <IO1X_Plained_drivers.h> // Inclui os arquivos de função dos sensores da placa IO1X Plained

/* Testa o sensor de temperatura, exibindo o valor no terminal serial*/
#define Test_temperature_sensor 

/* Testa o sensor de luz, exibindo o valor no terminal serial*/
#define Test_sensor_light

/* Testa o LED*/
#define Test_LED


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	sensors_init();
	
	char message[15]; // Mensagem a ser enviada pela serial para o terminal
	
	while (1) {
				
		//UART_write_byte(light_sensor);
		//delay_ms(50);
				
		#ifdef Test_sensor_light
			/* Usa e envia para a serial a iluminancia calculada */
			float light_sensor; // Iluminancia calculado a partir do sensor de luz
			char iluminance_str[10];
			
			floatToString(light_sensor, iluminance_str, 4);
			
			light_sensor = GET_light_sensor();
			
			sprintf(message, "Sensor de Luz: %s\r\n", iluminance_str);
			printf(message);
		#endif
		
		#ifdef Test_temperature_sensor
			/* Adquire valor de temperatura e envia para a serial*/
			uint16_t temperature;
			
			temperature = GET_temperature_sensor();
			
			sprintf(message, "Sensor de temperatura: %d\r\n\n\n", temperature);
			printf(message);
		#endif
	    
		#ifdef Test_LED
			/* Liga e desliga o LED da placa de expansão*/
			SET_IO1X_LED_ON();
			delay_ms(100);
			
			SET_IO1X_LED_OFF();
			delay_ms(100);
		#endif
	}
}




