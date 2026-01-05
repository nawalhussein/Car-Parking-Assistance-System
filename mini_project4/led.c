/*
 * led.c
 *
 *  Created on: Sep 29, 2025
 *      Author: Eng.Nawal Hussein
 */
#include "led.h"
#include <avr/io.h>
#include <util/delay.h>
LED_Config leds[LEDS_NUM] = {
		{&DDRC,&PORTC,0,POSITIVE_LOGIC},
		{&DDRC,&PORTC,1,POSITIVE_LOGIC},
		{&DDRC,&PORTC,2,POSITIVE_LOGIC},
};

void LEDS_init(void){
	/* Initializes all Leds (red, green, blue) pins direction.
Turn off all the Leds*/
	for(uint8 i=0;i<LEDS_NUM; i++) {
		*(leds[i].DDR)|=(1<<leds[i].LED_PIN); // Set as output
		// Turn off initially
		if(leds[i].LED_LOGIC==POSITIVE_LOGIC)
			*(leds[i].PORT)&=~(1<<leds[i].LED_PIN);
		else
			*(leds[i].PORT)|=(1<<leds[i].LED_PIN);
	}
}

void LED_on(LED_ID id) {
	//Turns on the specified LED.
	if(leds[id].LED_LOGIC==POSITIVE_LOGIC)
		*(leds[id].PORT)|=(1<<leds[id].LED_PIN);
	else
		*(leds[id].PORT)&=~(1<<leds[id].LED_PIN);
}

void LED_off(LED_ID id) {
	//Turns off the specified LED.
	if(leds[id].LED_LOGIC==POSITIVE_LOGIC)
		*(leds[id].PORT)&=~(1<<leds[id].LED_PIN);
	else
		*(leds[id].PORT)|=(1<<leds[id].LED_PIN);
}

void LED_flash(LED_ID id){
	 LED_on(id);
	    _delay_ms(200);
	    LED_off(id);
	    _delay_ms(200);
}
