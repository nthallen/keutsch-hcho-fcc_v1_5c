/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMC21 has 9 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7
#define GPIO_PIN_FUNCTION_I 8

#define CS0 GPIO(GPIO_PORTA, 2)
#define UART_TX GPIO(GPIO_PORTA, 22)
#define UART_RX GPIO(GPIO_PORTA, 23)
#define CS1 GPIO(GPIO_PORTA, 27)
#define MOSI GPIO(GPIO_PORTB, 0)
#define SCK GPIO(GPIO_PORTB, 1)
#define MISO GPIO(GPIO_PORTB, 2)
#define CSDAC GPIO(GPIO_PORTB, 4)

#endif // ATMEL_START_PINS_H_INCLUDED
