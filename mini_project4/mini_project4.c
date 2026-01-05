#include "buzzer.h"
#include "common_macros.h"
#include "gpio.h"
#include "icu.h"
#include "lcd.h"
#include "led.h"
#include "std_types.h"
#include "ultrasonic.h"
#include <util/delay.h>
uint16 distance = 0;
uint16 last_distance = 0;

int main(void)
{
	SREG|=(1<<7);
	LCD_init();
	Buzzer_init();
	LEDS_init();
	Ultrasonic_init();
	LCD_clearScreen();
	Buzzer_off();
	LED_off(LED_RED);
	LED_off(LED_GREEN);
	LED_off(LED_BLUE);

	while (1)
	{
		distance = Ultrasonic_readDistance();

		if (distance != last_distance)
		{
			last_distance = distance;
			LCD_clearScreen();
			LCD_displayString("Distance:     ");
			LCD_moveCursor(0, 10);
			LCD_intgerToString(distance);
			LCD_displayString("cm");
			if (distance <= 5)
			{
				Buzzer_on();
				LCD_moveCursor(1, 1);
				LCD_displayString("STOP!!!!     ");
				while (distance <= 5){
				LED_flash(LED_RED);
				LED_flash(LED_GREEN);
				LED_flash(LED_BLUE);
				distance = Ultrasonic_readDistance();
			}}
			else if (distance <= 10)
			{
				Buzzer_off();
				LED_on(LED_RED);
				LED_on(LED_GREEN);
				LED_on(LED_BLUE);
			}
			else if (distance <= 15)
			{
				Buzzer_off();
				LED_on(LED_RED);
				LED_on(LED_GREEN);
				LED_off(LED_BLUE);
			}
			else if (distance <= 20)
			{
				Buzzer_off();
				LED_on(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);
			}
			else
			{
				Buzzer_off();
				LED_off(LED_RED);
				LED_off(LED_GREEN);
				LED_off(LED_BLUE);
				LCD_moveCursor(2, 1);
				LCD_displayString("              ");
			}
		}

		_delay_ms(100);
	}
}
