/*
 * led.h
 *
 *  Created on: Sep 29, 2025
 *      Author: Eng.Nawal Hussein
 */

#ifndef LED_H_
#define LED_H_

#include "std_types.h"
#include <avr/io.h>
#define LEDS_NUM 3
#define POSITIVE_LOGIC 1
#define NEGATIVE_LOGIC 0

typedef enum{
	LED_RED, LED_GREEN, LED_BLUE
}LED_ID;

typedef struct {
    volatile uint8_t *DDR;
    volatile uint8_t *PORT;
    uint8_t LED_PIN;
    uint8 LED_LOGIC;
} LED_Config;

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);
void LED_flash(LED_ID id);
#endif /* LED_H_ */
