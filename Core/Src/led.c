#include "gpio.h"

void led(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
