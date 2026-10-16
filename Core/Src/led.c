#include "gpio.h"

// Esta Funcion prende un Led
void led(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
