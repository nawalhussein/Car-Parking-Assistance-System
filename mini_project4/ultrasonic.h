/*
 * ultrasonic.h
 *
 *  Created on: Oct 7, 2025
 *      Author: Eng.Nawal Hussein
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

/***********Includes***********/

#include "icu.h"
#include "std_types.h"
#include <avr/io.h>

/***********Defines***********/

#define trigger_pin 7
#define trigger_port D
#define _DDR(port) DDR##port
#define DDR(port)  _DDR(port)
#define _PORT(port) PORT##port
#define PORT(port)  _PORT(port)
#define f_cpu 16000000UL
#define f_cpu_prescaler 8




/*******************************************************************************
 *                      Functions Prototypes                               *
 *******************************************************************************/
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
void Ultrasonic_edgeProcessing(void);
uint16 Ultrasonic_readDistance(void);
#endif /* ULTRASONIC_H_ */
