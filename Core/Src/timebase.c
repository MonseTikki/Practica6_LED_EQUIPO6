/*
 * timebase.c
 * Timer module implementation.
 * TIM2 config (from CubeMX): 16 MHz clock, PSC = 15999, ARR = 99 -> 100 ms
 */

#include "timebase.h"
#include "tim.h"        /* htim2 is declared here by CubeMX */

/* ===== Private variables (only visible inside this file) ===== */

/* volatile: these values change inside the interrupt */
static volatile uint8_t  tick_flag  = 0;
static volatile uint32_t tick_count = 0;

/* ===== Public functions ===== */

uint8_t Timebase_Start(void)
{
    /* Start TIM2 WITH interrupt (_IT). Check for errors. */
    if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
    {
        return 0;
    }
    return 1;
}

uint8_t Timebase_HasTicked(void)
{
    if (tick_flag == 1)
    {
        tick_flag = 0;      /* Clear the flag after reading it */
        return 1;
    }
    return 0;
}

uint32_t Timebase_GetTickCount(void)
{
    return tick_count;
}

/* ===== Interrupt callback ===== */

/* Called automatically by HAL every time TIM2 overflows (every 100 ms).
 * Kept short: it only sets a flag and counts. */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick_flag = 1;
        tick_count++;
    }
}
