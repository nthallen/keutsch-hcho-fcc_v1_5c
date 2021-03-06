/************************************************************************/
/* \file spi.c                                                          */
/************************************************************************/
#include <peripheral_clk_config.h>
#include <hal_spi_m_async.h>
#include <hal_gpio.h>
#include <hpl_pm_base.h>
#include <hpl_gclk_base.h>
#include "atmel_start_pins.h"
#include "spi.h"
#include "subbus.h"

static struct spi_m_async_descriptor SPI_ADC;
static volatile bool SPI_ADC_txfr_complete = true;
static struct io_descriptor *SPI_ADC_io;
static bool spi_enabled = SPI_ENABLE_DEFAULT;

void spi_enable(bool value) {
  spi_enabled = value;
}

static inline void chip_select(uint8_t pin) {
  gpio_set_pin_level(pin, false);
}
static inline void chip_deselect(uint8_t pin) {
  gpio_set_pin_level(pin, true);
}

static void SPI_ADC_PORT_init(void) {
  // PB02 SERCOM5 PAD[0] MISO
  gpio_set_pin_direction(MISO, GPIO_DIRECTION_IN);
  gpio_set_pin_pull_mode(MISO, GPIO_PULL_OFF);
  gpio_set_pin_function(MISO, PINMUX_PB02D_SERCOM5_PAD0);

  // PB00 SERCOM5 PAD[2] MOSI
  gpio_set_pin_direction(MOSI, GPIO_DIRECTION_OUT);
  gpio_set_pin_level(MOSI, false);
	gpio_set_pin_function(MOSI, PINMUX_PB00D_SERCOM5_PAD2);

  // PB01 SERCOM5 PAD[3] SCK
  gpio_set_pin_direction(SCK, GPIO_DIRECTION_OUT);
  gpio_set_pin_level(SCK, false);
	gpio_set_pin_function(SCK, PINMUX_PB01D_SERCOM5_PAD3);

  // PA02: CS0/
  gpio_set_pin_direction(CS0, GPIO_DIRECTION_OUT);
  gpio_set_pin_level(CS0, true);
  gpio_set_pin_function(CS0, GPIO_PIN_FUNCTION_OFF);
  // PA27: CS1
	gpio_set_pin_direction(CS1, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(CS1,	false);
	gpio_set_pin_function(CS1, GPIO_PIN_FUNCTION_OFF);
  // PB04: CSDAC (was DACSYNC/)
	gpio_set_pin_direction(CSDAC, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(CSDAC,	true);
	gpio_set_pin_function(CSDAC, GPIO_PIN_FUNCTION_OFF);
}

static void SPI_ADC_CLOCK_init(void) {
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_CORE,
    CONF_GCLK_SERCOM5_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM5_GCLK_ID_SLOW,
    CONF_GCLK_SERCOM5_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM5_bit(MCLK);
}

static void complete_cb_SPI_ADC(const struct spi_m_async_descriptor *const io_descr) {
  SPI_ADC_txfr_complete = true;
}

static uint8_t spi_read_data[MAX_SPI_READ_LENGTH];

static void start_spi_transfer(uint8_t pin, uint8_t const *txbuf, int length) {
  assert(length <= MAX_SPI_READ_LENGTH,__FILE__,__LINE__);
  chip_select(pin);
  SPI_ADC_txfr_complete = false;
  spi_m_async_transfer(&SPI_ADC, txbuf, spi_read_data, length);
}

/* The bytes need to be swapped on output, since the driver transmits LSB first */
static uint8_t CONVERT_AIN0[4] = { 0x81, 0x8B, 0x81, 0x8B };
static uint8_t CONVERT_AIN2[4] = { 0xD1, 0x8B, 0xD1, 0x8B };
static uint8_t CONVERT_TEMP[4] = { 0x81, 0x9B, 0x81, 0x9B };

enum adc_state_t {adc_init, adc_init_tx,
           adc_ain0_wait, adc_ain0_tx,
           adc_ain2_wait, adc_ain2_tx,
           adc_temp_wait, adc_temp_tx};
typedef struct {
  bool enabled;
  enum adc_state_t state;
  uint8_t cs_pin;
  uint16_t AIN0_addr;
  uint16_t AIN2_addr;
  uint16_t TEMP_addr;
  uint16_t poll_count;
} adc_poll_def;

static adc_poll_def adc_u2 = {SPI_ADC_U2_ENABLED, adc_init, CS0, 0x10, 0x11, 0x19};
static adc_poll_def adc_u3 = {SPI_ADC_U3_ENABLED, adc_init, CS1, 0x12, 0x13, 0x1A};

/**
 * poll_adc() is only called when SPI_ADC_txfr_complete is non-zero 
 * @return true if we are relinquishing the SPI bus
 */
static bool poll_adc(adc_poll_def *adc) {
  uint16_t value;
  if (!adc->enabled) return true;
  switch (adc->state) {
    case adc_init:
      start_spi_transfer(adc->cs_pin, CONVERT_AIN0, 4);
      adc->state = adc_init_tx;
      return false;
    case adc_init_tx:
      chip_deselect(adc->cs_pin);
      adc->poll_count = 0;
      adc->state = adc_ain0_wait;
      return true;
    case adc_ain0_wait:
      chip_select(adc->cs_pin);
      if (gpio_get_pin_level(MISO)) {
        chip_deselect(adc->cs_pin);
        if (++adc->poll_count <= ADC_CONVERT_TIMEOUT) {
          return true;
        } // Otherwise just go ahead to the next step
      }
      start_spi_transfer(adc->cs_pin, CONVERT_AIN2, 4);
      adc->state = adc_ain0_tx;
      return false;
    case adc_ain0_tx:
      chip_deselect(adc->cs_pin);
      value = (spi_read_data[0] << 8) + spi_read_data[1];
      subbus_cache_update(adc->AIN0_addr, value);
      adc->poll_count = 0;
      adc->state = adc_ain2_wait;
      return true;
    case adc_ain2_wait:
      chip_select(adc->cs_pin);
      if (gpio_get_pin_level(MISO)) {
        chip_deselect(adc->cs_pin);
        if (++adc->poll_count <= ADC_CONVERT_TIMEOUT) {
          return true;
        } // Otherwise just go ahead to the next step
      }
      start_spi_transfer(adc->cs_pin, CONVERT_TEMP, 4);
      adc->state = adc_ain2_tx;
      return false;
    case adc_ain2_tx:
      chip_deselect(adc->cs_pin);
      value = (spi_read_data[0] << 8) + spi_read_data[1];
      subbus_cache_update(adc->AIN2_addr, value);
      adc->poll_count = 0;
      adc->state = adc_temp_wait;
      return true;
    case adc_temp_wait:
      chip_select(adc->cs_pin);
      if (gpio_get_pin_level(MISO)) {
        chip_deselect(adc->cs_pin);
        if (++adc->poll_count <= ADC_CONVERT_TIMEOUT) {
          return true;
        } // Otherwise just go ahead to the next step
      }
      start_spi_transfer(adc->cs_pin, CONVERT_AIN0, 4);
      adc->state = adc_temp_tx;
      return false;
    case adc_temp_tx:
      chip_deselect(adc->cs_pin);
      value = (spi_read_data[0] << 8) + spi_read_data[1];
      subbus_cache_update(adc->TEMP_addr, value);
      adc->poll_count = 0;
      adc->state = adc_ain0_wait;
      return true;
    default:
      assert(false, __FILE__, __LINE__);
  }
  return true;
}

enum dac_state_t {dac_init, dac_tx, dac_idle};
typedef struct {
  bool enabled;
  enum dac_state_t state;
  uint8_t cs_pin;
  uint16_t addr[4];
  uint16_t current;
} dac_poll_def;

static dac_poll_def dac_u5 = {SPI_DAC_U5_ENABLED, dac_init, CSDAC, {0x14, 0x15, 0x16, 0x17}, 0};
static uint8_t DACREFENABLE[3] = {0x38, 0x00, 0x01};
static uint8_t DACupdate[3];

/** 
 * Only called when SPI bus is free
 * @return true if we have relinquished the bus and cleared our chip select
 */
static bool poll_dac(void) {
  uint16_t value;
  if (!dac_u5.enabled) return true;
  switch (dac_u5.state) {
    case dac_init: // Need to send the internal reference enable signal
      start_spi_transfer(dac_u5.cs_pin, DACREFENABLE, 3);
      dac_u5.state = dac_tx;
      return false;
    case dac_tx:
      chip_deselect(dac_u5.cs_pin);
      dac_u5.state = dac_idle;
      return true;
    case dac_idle:
      if (subbus_cache_iswritten(dac_u5.addr[dac_u5.current], &value)) {
        DACupdate[0] = 0x18+dac_u5.current;
        DACupdate[1] = (value>>8) & 0xFF;
        DACupdate[2] = value & 0xFF;
        start_spi_transfer(dac_u5.cs_pin, DACupdate, 3);
        subbus_cache_update(dac_u5.addr[dac_u5.current], value);
        dac_u5.current = (dac_u5.current + 1) & 0x3;
        dac_u5.state = dac_tx;
        return false;
      } else {
        dac_u5.current = (dac_u5.current + 1) & 0x3;
        return true;
      }
    default:
      assert(false,__FILE__,__LINE__);
  }
  return true;
}

enum spi_state_t {spi_adc_u2, spi_adc_u3, spi_dac };
static enum spi_state_t spi_state = spi_adc_u2;

void poll_spi(void) {
  enum spi_state_t input_state = spi_state;
  if (!spi_enabled) return;
  while (SPI_ADC_txfr_complete) {
    switch (spi_state) {
      case spi_adc_u2:
        if (poll_adc(&adc_u2)) {
          spi_state = spi_adc_u3;
        }
        break;
      case spi_adc_u3:
        if (poll_adc(&adc_u3)) {
          spi_state = spi_dac;
        }
        break;
      case spi_dac:
        if (poll_dac()) {
          spi_state = spi_adc_u2;
        }
        break;
      default:
        assert(false, __FILE__, __LINE__);
    }
    if (spi_state == input_state) break;
  }
}

void spi_init(void) {
  SPI_ADC_CLOCK_init();
  spi_m_async_init(&SPI_ADC, SERCOM5);
  SPI_ADC_PORT_init();
  spi_m_async_get_io_descriptor(&SPI_ADC, &SPI_ADC_io);
  spi_m_async_register_callback(&SPI_ADC, SPI_M_ASYNC_CB_XFER, (FUNC_PTR)complete_cb_SPI_ADC);
  spi_m_async_enable(&SPI_ADC);
  subbus_cache_config(dac_u5.addr[0], true);
  subbus_cache_config(dac_u5.addr[1], true);
  subbus_cache_config(dac_u5.addr[2], true);
  subbus_cache_config(dac_u5.addr[3], true);
}
