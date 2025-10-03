#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"

// standard LED enable
#define GPIOAEN			(1U<<0)
#define PIN5			(1U<<5)
#define LED_PIN			PIN5



int main(void) {

	// enable clock access to led
	RCC->AHB1ENR |= GPIOAEN;

	// set PA5 as output pin
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);


	uart2_tx_init();
	tim2_1hz_init();


	while(1) {

		while (!(TIM2->SR & SR_UIF)) {} // wait for UIF

		// clear UIF
		TIM2->SR &= 0;

		printf("A second passed!\n\r");
		GPIOA->ODR ^= LED_PIN;
	}


}







