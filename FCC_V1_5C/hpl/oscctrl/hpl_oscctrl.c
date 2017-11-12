/**
 * \file
 *
 * \brief SAM Oscillators Controller.
 *
 * Copyright (C) 2015 - 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
#include <compiler.h>
#include <hpl_init.h>
#include <hpl_oscctrl_config.h>

/**
 * \brief Initialize clock sources
 */
void _oscctrl_init_sources(void)
{
	void *hw = (void *)OSCCTRL;

#if CONF_XOSC_CONFIG == 1
	hri_oscctrl_write_XOSCCTRL_reg(hw,
	                               OSCCTRL_XOSCCTRL_STARTUP(CONF_XOSC_STARTUP)
	                                   | (CONF_XOSC_AMPGC << OSCCTRL_XOSCCTRL_AMPGC_Pos)
	                                   | OSCCTRL_XOSCCTRL_GAIN(CONF_XOSC_GAIN)
	                                   | (CONF_XOSC_RUNSTDBY << OSCCTRL_XOSCCTRL_RUNSTDBY_Pos)
	                                   | (CONF_XOSC_SWBEN << OSCCTRL_XOSCCTRL_SWBEN_Pos)
	                                   | (CONF_XOSC_CFDEN << OSCCTRL_XOSCCTRL_CFDEN_Pos)
	                                   | (CONF_XOSC_XTALEN << OSCCTRL_XOSCCTRL_XTALEN_Pos)
	                                   | (CONF_XOSC_ENABLE << OSCCTRL_XOSCCTRL_ENABLE_Pos));

	hri_oscctrl_write_EVCTRL_reg(hw, (CONF_XOSC_CFDEO << OSCCTRL_EVCTRL_CFDEO_Pos));
#endif
#if CONF_OSC48M_CONFIG == 1
	hri_oscctrl_write_OSC48MCTRL_reg(hw,
	                                 (CONF_OSC48M_RUNSTDBY << OSCCTRL_OSC48MCTRL_RUNSTDBY_Pos)
	                                     | (CONF_OSC48M_ENABLE << OSCCTRL_OSC48MCTRL_ENABLE_Pos));
	hri_oscctrl_write_OSC48MDIV_reg(hw, OSCCTRL_OSC48MDIV_DIV(CONF_OSC48M_DIV));
	while (hri_oscctrl_get_OSC48MSYNCBUSY_OSC48MDIV_bit(hw))
		;
	hri_oscctrl_write_OSC48MSTUP_reg(hw, OSCCTRL_OSC48MSTUP_STARTUP(CONF_OSC48M_STARTUP));
#endif

#if CONF_XOSC_CONFIG == 1
#if CONF_XOSC_ENABLE == 1
	while (!hri_oscctrl_get_STATUS_XOSCRDY_bit(hw))
		;
#endif
#if CONF_XOSC_ONDEMAND == 1
	hri_oscctrl_set_XOSCCTRL_ONDEMAND_bit(hw);
#endif
#endif

#if CONF_OSC48M_CONFIG == 1
#if CONF_OSC48M_ENABLE == 1
	while (!hri_oscctrl_get_STATUS_OSC48MRDY_bit(hw))
		;
#endif
#if CONF_OSC48M_ONDEMAND == 1
	hri_oscctrl_set_OSC48MCTRL_ONDEMAND_bit(hw);
#endif
#endif
	(void)hw;
}

void _oscctrl_init_referenced_generators(void)
{
	void *hw = (void *)OSCCTRL;

#if CONF_DPLL_CONFIG == 1
#if CONF_DPLL_REFCLK == 2
	hri_gclk_write_PCHCTRL_reg(GCLK, 0, (1 << GCLK_PCHCTRL_CHEN_Pos) | GCLK_PCHCTRL_GEN(CONF_DPLL_GCLK));
#endif
	hri_oscctrl_write_DPLLRATIO_reg(
	    hw, OSCCTRL_DPLLRATIO_LDRFRAC(CONF_DPLL_LDRFRAC) | OSCCTRL_DPLLRATIO_LDR(CONF_DPLL_LDR));
	hri_oscctrl_write_DPLLCTRLB_reg(hw,
	                                OSCCTRL_DPLLCTRLB_DIV(CONF_DPLL_DIV)
	                                    | (CONF_DPLL_LBYPASS << OSCCTRL_DPLLCTRLB_LBYPASS_Pos)
	                                    | OSCCTRL_DPLLCTRLB_LTIME(CONF_DPLL_LTIME)
	                                    | OSCCTRL_DPLLCTRLB_REFCLK(CONF_DPLL_REFCLK)
	                                    | (CONF_DPLL_WUF << OSCCTRL_DPLLCTRLB_WUF_Pos)
	                                    | (CONF_DPLL_LPEN << OSCCTRL_DPLLCTRLB_LPEN_Pos)
	                                    | OSCCTRL_DPLLCTRLB_FILTER(CONF_DPLL_FILTER));
	hri_oscctrl_write_DPLLPRESC_reg(hw, OSCCTRL_DPLLPRESC_PRESC(CONF_DPLL_PRESC));
	hri_oscctrl_write_DPLLCTRLA_reg(hw,
	                                (CONF_DPLL_RUNSTDBY << OSCCTRL_DPLLCTRLA_RUNSTDBY_Pos)
	                                    | (CONF_DPLL_ENABLE << OSCCTRL_DPLLCTRLA_ENABLE_Pos));
#endif

#if CONF_DPLL_CONFIG == 1
#if CONF_DPLL_ENABLE == 1
	while (!(hri_oscctrl_get_DPLLSTATUS_LOCK_bit(hw) || hri_oscctrl_get_DPLLSTATUS_CLKRDY_bit(hw)))
		;
#endif
#if CONF_DPLL_ONDEMAND == 1
	hri_oscctrl_set_DPLLCTRLA_ONDEMAND_bit(hw);
#endif
#endif
	(void)hw;
}
