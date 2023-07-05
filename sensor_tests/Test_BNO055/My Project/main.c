#include <atmel_start.h>
#include <stdio.h>

/**
 * Liga o LED Red da placa de expansão
 */
void SET_R_LED_ON(void){
	gpio_set_pin_level(R_LED, false);
}

/**
 * Desliga o LED Red da placa de expansão
 */
void SET_R_LED_OFF(void){
	gpio_set_pin_level(R_LED, true);
}

/**
 * Liga o LED Green da placa de expansão
 */
void SET_G_LED_ON(void){
	gpio_set_pin_level(G_LED, false);
}

/**
 * Desliga o LED Green da placa de expansão
 */
void SET_G_LED_OFF(void){
	gpio_set_pin_level(G_LED, true);
}

/**
 * Liga o LED Blue da placa de expansão
 */
void SET_B_LED_ON(void){
	gpio_set_pin_level(B_LED, false);
}

/**
 * Desliga o LED Blue da placa de expansão
 */
void SET_B_LED_OFF(void){
	gpio_set_pin_level(B_LED, true);
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	SET_R_LED_OFF();
	SET_G_LED_OFF();
	SET_B_LED_OFF();

	/* Replace with your application code */
	while (1) {
		
		SET_B_LED_ON();
		SET_G_LED_ON();
		delay_ms(500);
		SET_B_LED_OFF();
		SET_G_LED_OFF();
		delay_ms(500);
		
	}
}
