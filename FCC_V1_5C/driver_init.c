/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

/*! The buffer size for USART */
#define USART_CTRL_BUFFER_SIZE 16

struct usart_async_descriptor USART_CTRL;

static uint8_t USART_CTRL_buffer[USART_CTRL_BUFFER_SIZE];

struct spi_m_async_descriptor SPI_ADC;

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_CTRL_CLOCK_init()
{

	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM3_GCLK_ID_SLOW, CONF_GCLK_SERCOM3_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM3_bit(MCLK);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_CTRL_PORT_init()
{

	gpio_set_pin_function(UART_TX, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_function(UART_RX, PINMUX_PA23C_SERCOM3_PAD1);
}

/**
 * \brief USART initialization function
 *
 * Enables USART peripheral, clocks and initializes USART driver
 */
void USART_CTRL_init(void)
{
	USART_CTRL_CLOCK_init();
	usart_async_init(&USART_CTRL, SERCOM3, USART_CTRL_buffer, USART_CTRL_BUFFER_SIZE, (void *)NULL);
	USART_CTRL_PORT_init();
}

void SPI_ADC_PORT_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(MISO, PINMUX_PB02D_SERCOM5_PAD0);

	// Set pin direction to output
	gpio_set_pin_direction(MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(MOSI, PINMUX_PB00D_SERCOM5_PAD2);

	// Set pin direction to output
	gpio_set_pin_direction(SCK, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(SCK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(SCK, PINMUX_PB01D_SERCOM5_PAD3);
}

void SPI_ADC_CLOCK_init(void)
{
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_CORE, CONF_GCLK_SERCOM5_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_SLOW, CONF_GCLK_SERCOM5_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM5_bit(MCLK);
}

void SPI_ADC_init(void)
{
	SPI_ADC_CLOCK_init();
	spi_m_async_init(&SPI_ADC, SERCOM5);
	SPI_ADC_PORT_init();
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA02

	// Set pin direction to output
	gpio_set_pin_direction(CS0, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(CS0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(CS0, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	// Set pin direction to output
	gpio_set_pin_direction(CS1, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(CS1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_function(CS1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB04

	// Set pin direction to output
	gpio_set_pin_direction(CSDAC, GPIO_DIRECTION_OUT);

	gpio_set_pin_level(CSDAC,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_function(CSDAC, GPIO_PIN_FUNCTION_OFF);

	USART_CTRL_init();

	SPI_ADC_init();
}
