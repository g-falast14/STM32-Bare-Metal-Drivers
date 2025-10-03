#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)

#define PIN5		(1U<<5)
#define PIN13		(1U<<13)

#define LED_PIN 	PIN5
#define BTN_PIN		PIN13

int main(void) {


	// enable clock access to GPIOA (led) and GPIOC (button)
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;


	// set PA5 as an output pin
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);

	// set PC13 as input pin
	GPIOC->MODER &=~(1U<<26);
	GPIOA->MODER &=~(1U<<27);




	while (1) {

		// button is active low, so turn off led when button is pressed
		// check if button is pressed
		if (GPIOC->IDR & BTN_PIN) { // btn_pin is a value with a 1 in position 13
			// turn on LED
			GPIOA->BSRR = LED_PIN;
		} else {
			// turn off led
			GPIOA->BSRR = (1U<<21);
		}

	}

}

