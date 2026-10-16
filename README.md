<div align="center">

# Practica6_LED_EQUIPO6

![STM32](https://img.shields.io/badge/MCU-STM32F446RE-03234B?logo=stmicroelectronics&logoColor=white)
![HAL](https://img.shields.io/badge/Lib-STM32%20HAL-blue)
![C](https://img.shields.io/badge/Lang-C-informational?logo=c)
![Status](https://img.shields.io/badge/LED-blinking-ff3b3b)

</div>

**Proposito:** - Desarrollar un codigo para controlar un led :)

## Hardware

| Elemento | Detalle |
|---|---|
| Tarjeta | Nucleo STM32 |
| LED | Pin `PA5` (GPIOA, salida digital) |

## Cómo funciona

El `main` inicializa el GPIO y, dentro del loop, se llama a `led()`, la cual invierte la senal del pin digital.

```c
// Funcion donde led se prende
void led(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}
```
