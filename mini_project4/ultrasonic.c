#include "ultrasonic.h"
#include <util/delay.h>

/* Global variables */
static volatile uint8 g_edgeCount = 0;
static volatile uint16 g_timeHigh = 0;

/* ICU configuration structure */
ICU_ConfigType ICU_Configurations = {F_CPU_8, RAISING};

/* ---------------- Functions Implementation ---------------- */

void Ultrasonic_init(void)
{
    ICU_init(&ICU_Configurations);
    ICU_setCallBack(Ultrasonic_edgeProcessing);
    DDR(trigger_port) |= (1 << trigger_pin); // Trigger as output
}

void Ultrasonic_Trigger(void)
{
    PORT(trigger_port) &= ~(1 << trigger_pin);
    _delay_us(2);
    PORT(trigger_port) |= (1 << trigger_pin);
    _delay_us(10);
    PORT(trigger_port) &= ~(1 << trigger_pin);
}

void Ultrasonic_edgeProcessing(void)
{
    g_edgeCount++;

    if (g_edgeCount == 1)
    {
        ICU_clearTimerValue();
        ICU_setEdgeDetectionType(FALLING);
    }
    else if (g_edgeCount == 2)
    {
        g_timeHigh = ICU_getInputCaptureValue();
        ICU_clearTimerValue();
        ICU_setEdgeDetectionType(RAISING);
    }
}

uint16 Ultrasonic_readDistance(void)
{
    uint16 distance = 0;
    double real_time;
    g_edgeCount = 0; // Reset before each new measurement
    Ultrasonic_Trigger();

    uint32 timeout = 0;
    while (g_edgeCount < 2)
    {
        _delay_us(10);
        if (++timeout > 30000)
            return 0;
    }

    /* Convert timer ticks to time in seconds */
    real_time = (double)g_timeHigh / (f_cpu/f_cpu_prescaler);

    /* Calculate distance in cm
     * we added 1 due to correct the sensor reading on proteus*/
    distance = (uint16)((real_time * 34300.0)/2.0)+1;

    return distance;
}
