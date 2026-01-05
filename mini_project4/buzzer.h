/*
 * buzzer.h
 *
 *  Created on: Sep 30, 2025
 *      Author: Eng.Nawal Hussein
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
#define BUZZ_PORT C
#define BUZZ_PIN 5
#define _DDR(port) DDR##port
#define DDR(port)  _DDR(port)
#define _PORT(port) PORT##port
#define PORT(port)  _PORT(port)

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);
#endif /* BUZZER_H_ */
