/*
 * buzzer.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Eng.Nawal Hussein
 */

#include "buzzer.h"
#include <avr/io.h>
void Buzzer_init(void){
/*Initializes the buzzer pin direction and turn off the buzzer. */
	DDR(BUZZ_PORT) |= (1<<BUZZ_PIN);
	PORT(BUZZ_PORT) &=~ (1<<BUZZ_PIN);
}
void Buzzer_on(void){
/*Activates the buzzer. */
	PORT(BUZZ_PORT) |= (1<<BUZZ_PIN);
}
void Buzzer_off(void){
/*Deactivates the buzzer.*/
	PORT(BUZZ_PORT) &=~ (1<<BUZZ_PIN);
}
