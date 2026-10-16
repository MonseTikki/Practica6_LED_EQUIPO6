/*
 * uart_app.c
 * Implementación del módulo UART.
 */

#include "uart_app.h"
#include "usart.h"
#include <string.h>

#define UART_TIMEOUT_MS  100    // Tmáx de espera al enviar

static UART_HandleTypeDef *uart_ptr = &huart2;   // Apuntador al UART

void UART_EnviarTexto(const char *texto)
{
    if (texto == NULL)
    {
        return;
    }

    HAL_UART_Transmit(uart_ptr, (uint8_t *)texto, strlen(texto), UART_TIMEOUT_MS);
}

void UART_EnviarEstado(const char *estado)
{
    UART_EnviarTexto("Estado del LED: ");
    UART_EnviarTexto(estado);
    UART_EnviarTexto("\r\n");
}
