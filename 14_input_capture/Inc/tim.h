/*
 * tim.h
 *
 *  Created on: Sep 26, 2025
 *      Author: garrettfalast
 */

#ifndef TIM_H_
#define TIM_H_

#define SR_UIF 		(1U<<0) // overflow register flag
#define SR_CC1IF	(1U<<01)

void tim2_1hz_init(void);
void tim2_pa5_output_compare(void);
void tim3_pa6_input_capture(void);


#endif /* TIM_H_ */
