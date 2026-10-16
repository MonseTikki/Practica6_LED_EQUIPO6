/*
 * timebase.h
 * Timer module: generates a periodic time base using TIM2.
 * Public interface: what other modules can use.
 */

#ifndef TIMEBASE_H      /* Include guard */
#define TIMEBASE_H

#include <stdint.h>

#define TIMEBASE_PERIOD_MS  100U    /* Interrupt period: 100 ms */

/* Starts TIM2 with interrupt. Returns 1 if OK, 0 if error. */
uint8_t Timebase_Start(void);

/* Returns 1 if a new 100 ms tick happened (and clears the flag). */
uint8_t Timebase_HasTicked(void);

/* Returns how many ticks have happened since the timer started. */
uint32_t Timebase_GetTickCount(void);

#endif /* TIMEBASE_H */
