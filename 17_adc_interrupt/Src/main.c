#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "adc.h"

volatile uint32_t sensor_value;

int main(void) {

	uart2_tx_init();
	pa1_adc_interrupt_init();
	start_conversion();


	while(1) {

	}


}

static adc_callback(void) {
	sensor_value = ADC1->DR;
	printf("Sensor value: %d \n\r", (int)sensor_value);
}

void ADC_IRQHandler(void) {

	// check for EOC in SR
	if (ADC1->SR & SR_EOC) {
		// clear EOC
		ADC1->SR &= ~(SR_EOC);

		// print value
		adc_callback();
	}


}







