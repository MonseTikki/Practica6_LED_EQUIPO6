/*
 * uart_app.h
 * Módulo para enviar mensajes por UART.
 */

#ifndef UART_APP_H
#define UART_APP_H

/* Envía un texto cualquiera por UART */
void UART_EnviarTexto(const char *texto);

/* Envía el estado del LED*/
void UART_EnviarEstado(const char *estado);

#endif /* UART_APP_H */
