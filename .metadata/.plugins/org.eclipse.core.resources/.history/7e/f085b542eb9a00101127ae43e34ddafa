#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "uart.h"
#include "adc.h"
#include "systick.h"


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


	while(1) {
		systick_delay_ms(1000);
		GPIOA->ODR ^= LED_PIN;
		printf("One second just passed\n\r");
	}


}







