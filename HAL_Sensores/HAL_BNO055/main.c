/*---------------------------------------------------------------------------*
*  Includes
*---------------------------------------------------------------------------*/
#include <atmel_start.h>
#include <stdio.h>
#include "BNO055/bno055.h"
#include "BNO055/bno055_support.h"
#include "driver_init.h"
#include "utils.h"

struct io_descriptor *I2C_BNO055_io;

int main(){
	
	atmel_start_init();
	
	i2c_m_sync_get_io_descriptor(&I2C_BNO055, &I2C_BNO055_io);
	i2c_m_sync_enable(&I2C_BNO055);
	i2c_m_sync_set_slaveaddr(&I2C_BNO055, BNO055_I2C_ADDR1, I2C_M_SEVEN);
	
	bno055.bus_write = BNO055_I2C_bus_write;
	bno055.bus_read = BNO055_I2C_bus_read;
	bno055.delay_msec = BNO055_delay_msek;
	bno055.dev_addr = BNO055_I2C_ADDR1;
	
	SET_R_LED_OFF();
	SET_G_LED_OFF();
	SET_B_LED_OFF();
	
	char teste_text[20];
	
	// Initialize the BNO055 sensor
	
	if (bno055_init(&bno055) != BNO055_SUCCESS) {
		printf("Failed to initialize BNO055 sensor.\n");
		printf("Valor de retorno = %d.\n", bno055_init(&bno055));
		//return 1;
	}
	
	// Configure sensor settings (if required)
	// ...
	while(1){
		bno055_data_readout_template();
		delay_ms(10);
	
		floatToString(bno055_read_linear_accel_y(&linear_accel_data_y), teste_text, 4);
		printf("Teste = %s\n", teste_text);
		SET_R_LED_ON();
		SET_B_LED_ON();
		delay_ms(500);
		SET_R_LED_OFF();
		SET_B_LED_OFF();
		delay_ms(500);
	}
	return 0;
}