/*
 * adc.c
 *
 *  Created on: Sep 25, 2025
 *      Author: garrettfalast
 */

#include "adc.h"
#include "stm32f4xx.h"

#define GPIOAEN			(1U<<0)
#define ADC1EN			(1U<<8)

// channels for adc
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	0x00
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART 	(1U<<30)
#define SR_EOC			(1U<<1)


void pa1_adc_init(void) {

	// Configure the ADC GPIO pin
	// enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;

	// set the mode of pa1 to analog mode
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	// configure the ADC module
	// enable clock access to adc
	RCC->APB2ENR |= ADC1EN;

	// Configure ADC parameters
	// conversion sequence start
	ADC1->SQR3 = ADC_CH1;

	// conversion sequence length
	ADC1->SQR1 = ADC_SEQ_LEN_1;

	// enable ADC module
	ADC1->CR2 |= CR2_ADON;


}

void start_conversion(void) {

	// start adc conversion
	ADC1->CR2 |= CR2_SWSTART;

}

uint32_t adc_read(void) {
	// wait for conversion to be complete
	while(!(ADC1->SR & SR_EOC)) {} // wait until complete flag is set

	// read converted result
	return (ADC1->DR);
}


