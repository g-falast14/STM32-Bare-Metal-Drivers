/*
 * tim.c
 *
 *  Created on: Sep 26, 2025
 *      Author: garrettfalast
 */

#include "stm32f4xx.h"

#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define DIER_UIE	(1U<<0)

void tim2_1hz_init(void) {
	// enable clock access to timer2
	RCC->AHB1ENR |= TIM2EN;

	// set prescalar value
	TIM2->PSC = 1600 - 1; // 16mhz / 1600 = 10000

	// set auto-reload value
	TIM2->ARR = 10000 - 1;


	// clear timer counter
	TIM2->CNT = 0;

	// enable the timer
	TIM2->CR1 |= CR1_CEN;


}

void tim2_1hz_interrupt_init(void) {
	// enable clock access to timer2
	RCC->AHB1ENR |= TIM2EN;

	// set prescalar value
	TIM2->PSC = 1600 - 1; // 16mhz / 1600 = 10000

	// set auto-reload value
	TIM2->ARR = 10000 - 1;


	// clear timer counter
	TIM2->CNT = 0;

	// enable the timer
	TIM2->CR1 |= CR1_CEN;

	// enable timer interrupt
	TIM2->DIER |= DIER_UIE;

	//enable tim interrupt in nvic
	NVIC_EnableIRQ(TIM2_IRQn);

}
