/**
 * \file
 *
 * \brief SAM TAL
 *
 * Copyright (C) 2017 Atmel Corporation. All rights reserved.
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
 */

#ifdef _SAMC21_TAL_COMPONENT_
#ifndef _HRI_TAL_C21_H_INCLUDED_
#define _HRI_TAL_C21_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_TAL_CRITICAL_SECTIONS)
#define TAL_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define TAL_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define TAL_CRITICAL_SECTION_ENTER()
#define TAL_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_tal_brkstatus_reg_t;
typedef uint16_t hri_tal_irqtrig_reg_t;
typedef uint32_t hri_tal_cpuirqs_reg_t;
typedef uint8_t  hri_tal_ctictrla_reg_t;
typedef uint8_t  hri_tal_ctimask_reg_t;
typedef uint8_t  hri_tal_ctrla_reg_t;
typedef uint8_t  hri_tal_evctrl_reg_t;
typedef uint8_t  hri_tal_extctrl_reg_t;
typedef uint8_t  hri_tal_globmask_reg_t;
typedef uint8_t  hri_tal_halt_reg_t;
typedef uint8_t  hri_tal_intenset_reg_t;
typedef uint8_t  hri_tal_intflag_reg_t;
typedef uint8_t  hri_tal_intstatus_reg_t;
typedef uint8_t  hri_tal_restart_reg_t;
typedef uint8_t  hri_tal_rstctrl_reg_t;
typedef uint8_t  hri_talctis_ctictrla_reg_t;
typedef uint8_t  hri_talctis_ctimask_reg_t;

static inline bool hri_tal_get_INTFLAG_BRK_bit(const void *const hw)
{
	return (((Tal *)hw)->INTFLAG.reg & TAL_INTFLAG_BRK) >> TAL_INTFLAG_BRK_Pos;
}

static inline void hri_tal_clear_INTFLAG_BRK_bit(const void *const hw)
{
	((Tal *)hw)->INTFLAG.reg = TAL_INTFLAG_BRK;
}

static inline bool hri_tal_get_interrupt_BRK_bit(const void *const hw)
{
	return (((Tal *)hw)->INTFLAG.reg & TAL_INTFLAG_BRK) >> TAL_INTFLAG_BRK_Pos;
}

static inline void hri_tal_clear_interrupt_BRK_bit(const void *const hw)
{
	((Tal *)hw)->INTFLAG.reg = TAL_INTFLAG_BRK;
}

static inline hri_tal_intflag_reg_t hri_tal_get_INTFLAG_reg(const void *const hw, hri_tal_intflag_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->INTFLAG.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_tal_intflag_reg_t hri_tal_read_INTFLAG_reg(const void *const hw)
{
	return ((Tal *)hw)->INTFLAG.reg;
}

static inline void hri_tal_clear_INTFLAG_reg(const void *const hw, hri_tal_intflag_reg_t mask)
{
	((Tal *)hw)->INTFLAG.reg = mask;
}

static inline void hri_tal_set_CTRLA_SWRST_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg |= TAL_CTRLA_SWRST;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTRLA_SWRST_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->CTRLA.reg;
	tmp = (tmp & TAL_CTRLA_SWRST) >> TAL_CTRLA_SWRST_Pos;
	return (bool)tmp;
}

static inline void hri_tal_set_CTRLA_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg |= TAL_CTRLA_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTRLA_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->CTRLA.reg;
	tmp = (tmp & TAL_CTRLA_ENABLE) >> TAL_CTRLA_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_CTRLA_ENABLE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->CTRLA.reg;
	tmp &= ~TAL_CTRLA_ENABLE;
	tmp |= value << TAL_CTRLA_ENABLE_Pos;
	((Tal *)hw)->CTRLA.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTRLA_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg &= ~TAL_CTRLA_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTRLA_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg ^= TAL_CTRLA_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_CTRLA_reg(const void *const hw, hri_tal_ctrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctrla_reg_t hri_tal_get_CTRLA_reg(const void *const hw, hri_tal_ctrla_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->CTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_CTRLA_reg(const void *const hw, hri_tal_ctrla_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTRLA_reg(const void *const hw, hri_tal_ctrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTRLA_reg(const void *const hw, hri_tal_ctrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->CTRLA.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctrla_reg_t hri_tal_read_CTRLA_reg(const void *const hw)
{
	return ((Tal *)hw)->CTRLA.reg;
}

static inline void hri_tal_set_RSTCTRL_reg(const void *const hw, hri_tal_rstctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->RSTCTRL.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_rstctrl_reg_t hri_tal_get_RSTCTRL_reg(const void *const hw, hri_tal_rstctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->RSTCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_RSTCTRL_reg(const void *const hw, hri_tal_rstctrl_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->RSTCTRL.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_RSTCTRL_reg(const void *const hw, hri_tal_rstctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->RSTCTRL.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_RSTCTRL_reg(const void *const hw, hri_tal_rstctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->RSTCTRL.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_rstctrl_reg_t hri_tal_read_RSTCTRL_reg(const void *const hw)
{
	return ((Tal *)hw)->RSTCTRL.reg;
}

static inline void hri_tal_set_EXTCTRL_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg |= TAL_EXTCTRL_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_EXTCTRL_ENABLE_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EXTCTRL.reg;
	tmp = (tmp & TAL_EXTCTRL_ENABLE) >> TAL_EXTCTRL_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_EXTCTRL_ENABLE_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->EXTCTRL.reg;
	tmp &= ~TAL_EXTCTRL_ENABLE;
	tmp |= value << TAL_EXTCTRL_ENABLE_Pos;
	((Tal *)hw)->EXTCTRL.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EXTCTRL_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg &= ~TAL_EXTCTRL_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EXTCTRL_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg ^= TAL_EXTCTRL_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_EXTCTRL_INV_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg |= TAL_EXTCTRL_INV;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_EXTCTRL_INV_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EXTCTRL.reg;
	tmp = (tmp & TAL_EXTCTRL_INV) >> TAL_EXTCTRL_INV_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_EXTCTRL_INV_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->EXTCTRL.reg;
	tmp &= ~TAL_EXTCTRL_INV;
	tmp |= value << TAL_EXTCTRL_INV_Pos;
	((Tal *)hw)->EXTCTRL.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EXTCTRL_INV_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg &= ~TAL_EXTCTRL_INV;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EXTCTRL_INV_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg ^= TAL_EXTCTRL_INV;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_EXTCTRL_reg(const void *const hw, hri_tal_extctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_extctrl_reg_t hri_tal_get_EXTCTRL_reg(const void *const hw, hri_tal_extctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EXTCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_EXTCTRL_reg(const void *const hw, hri_tal_extctrl_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EXTCTRL_reg(const void *const hw, hri_tal_extctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EXTCTRL_reg(const void *const hw, hri_tal_extctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EXTCTRL.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_extctrl_reg_t hri_tal_read_EXTCTRL_reg(const void *const hw)
{
	return ((Tal *)hw)->EXTCTRL.reg;
}

static inline void hri_tal_set_EVCTRL_BRKEI_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg |= TAL_EVCTRL_BRKEI;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_EVCTRL_BRKEI_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EVCTRL.reg;
	tmp = (tmp & TAL_EVCTRL_BRKEI) >> TAL_EVCTRL_BRKEI_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_EVCTRL_BRKEI_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->EVCTRL.reg;
	tmp &= ~TAL_EVCTRL_BRKEI;
	tmp |= value << TAL_EVCTRL_BRKEI_Pos;
	((Tal *)hw)->EVCTRL.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EVCTRL_BRKEI_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg &= ~TAL_EVCTRL_BRKEI;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EVCTRL_BRKEI_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg ^= TAL_EVCTRL_BRKEI;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_EVCTRL_BRKEO_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg |= TAL_EVCTRL_BRKEO;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_EVCTRL_BRKEO_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EVCTRL.reg;
	tmp = (tmp & TAL_EVCTRL_BRKEO) >> TAL_EVCTRL_BRKEO_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_EVCTRL_BRKEO_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->EVCTRL.reg;
	tmp &= ~TAL_EVCTRL_BRKEO;
	tmp |= value << TAL_EVCTRL_BRKEO_Pos;
	((Tal *)hw)->EVCTRL.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EVCTRL_BRKEO_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg &= ~TAL_EVCTRL_BRKEO;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EVCTRL_BRKEO_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg ^= TAL_EVCTRL_BRKEO;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_EVCTRL_reg(const void *const hw, hri_tal_evctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_evctrl_reg_t hri_tal_get_EVCTRL_reg(const void *const hw, hri_tal_evctrl_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->EVCTRL.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_EVCTRL_reg(const void *const hw, hri_tal_evctrl_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_EVCTRL_reg(const void *const hw, hri_tal_evctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_EVCTRL_reg(const void *const hw, hri_tal_evctrl_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->EVCTRL.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_evctrl_reg_t hri_tal_read_EVCTRL_reg(const void *const hw)
{
	return ((Tal *)hw)->EVCTRL.reg;
}

static inline void hri_tal_set_GLOBMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg |= TAL_GLOBMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_GLOBMASK_CM0P_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp = (tmp & TAL_GLOBMASK_CM0P) >> TAL_GLOBMASK_CM0P_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_GLOBMASK_CM0P_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp &= ~TAL_GLOBMASK_CM0P;
	tmp |= value << TAL_GLOBMASK_CM0P_Pos;
	((Tal *)hw)->GLOBMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_GLOBMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg &= ~TAL_GLOBMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_GLOBMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg ^= TAL_GLOBMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_GLOBMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg |= TAL_GLOBMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_GLOBMASK_EVBRK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp = (tmp & TAL_GLOBMASK_EVBRK) >> TAL_GLOBMASK_EVBRK_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_GLOBMASK_EVBRK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp &= ~TAL_GLOBMASK_EVBRK;
	tmp |= value << TAL_GLOBMASK_EVBRK_Pos;
	((Tal *)hw)->GLOBMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_GLOBMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg &= ~TAL_GLOBMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_GLOBMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg ^= TAL_GLOBMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_GLOBMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg |= TAL_GLOBMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_GLOBMASK_EXTBRK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp = (tmp & TAL_GLOBMASK_EXTBRK) >> TAL_GLOBMASK_EXTBRK_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_GLOBMASK_EXTBRK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp &= ~TAL_GLOBMASK_EXTBRK;
	tmp |= value << TAL_GLOBMASK_EXTBRK_Pos;
	((Tal *)hw)->GLOBMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_GLOBMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg &= ~TAL_GLOBMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_GLOBMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg ^= TAL_GLOBMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_GLOBMASK_reg(const void *const hw, hri_tal_globmask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_globmask_reg_t hri_tal_get_GLOBMASK_reg(const void *const hw, hri_tal_globmask_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->GLOBMASK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_GLOBMASK_reg(const void *const hw, hri_tal_globmask_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_GLOBMASK_reg(const void *const hw, hri_tal_globmask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_GLOBMASK_reg(const void *const hw, hri_tal_globmask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->GLOBMASK.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_globmask_reg_t hri_tal_read_GLOBMASK_reg(const void *const hw)
{
	return ((Tal *)hw)->GLOBMASK.reg;
}

static inline void hri_tal_set_IRQTRIG_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg |= TAL_IRQTRIG_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_IRQTRIG_ENABLE_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp = (tmp & TAL_IRQTRIG_ENABLE) >> TAL_IRQTRIG_ENABLE_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_IRQTRIG_ENABLE_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp &= ~TAL_IRQTRIG_ENABLE;
	tmp |= value << TAL_IRQTRIG_ENABLE_Pos;
	((Tal *)hw)->IRQTRIG.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_IRQTRIG_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg &= ~TAL_IRQTRIG_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_IRQTRIG_ENABLE_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg ^= TAL_IRQTRIG_ENABLE;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_IRQTRIG_IRQNUM_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg |= TAL_IRQTRIG_IRQNUM(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_get_IRQTRIG_IRQNUM_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp = (tmp & TAL_IRQTRIG_IRQNUM(mask)) >> TAL_IRQTRIG_IRQNUM_Pos;
	return tmp;
}

static inline void hri_tal_write_IRQTRIG_IRQNUM_bf(const void *const hw, hri_tal_irqtrig_reg_t data)
{
	uint16_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp &= ~TAL_IRQTRIG_IRQNUM_Msk;
	tmp |= TAL_IRQTRIG_IRQNUM(data);
	((Tal *)hw)->IRQTRIG.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_IRQTRIG_IRQNUM_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg &= ~TAL_IRQTRIG_IRQNUM(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_IRQTRIG_IRQNUM_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg ^= TAL_IRQTRIG_IRQNUM(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_read_IRQTRIG_IRQNUM_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp = (tmp & TAL_IRQTRIG_IRQNUM_Msk) >> TAL_IRQTRIG_IRQNUM_Pos;
	return tmp;
}

static inline void hri_tal_set_IRQTRIG_OVERRIDE_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg |= TAL_IRQTRIG_OVERRIDE(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_get_IRQTRIG_OVERRIDE_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp = (tmp & TAL_IRQTRIG_OVERRIDE(mask)) >> TAL_IRQTRIG_OVERRIDE_Pos;
	return tmp;
}

static inline void hri_tal_write_IRQTRIG_OVERRIDE_bf(const void *const hw, hri_tal_irqtrig_reg_t data)
{
	uint16_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp &= ~TAL_IRQTRIG_OVERRIDE_Msk;
	tmp |= TAL_IRQTRIG_OVERRIDE(data);
	((Tal *)hw)->IRQTRIG.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_IRQTRIG_OVERRIDE_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg &= ~TAL_IRQTRIG_OVERRIDE(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_IRQTRIG_OVERRIDE_bf(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg ^= TAL_IRQTRIG_OVERRIDE(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_read_IRQTRIG_OVERRIDE_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp = (tmp & TAL_IRQTRIG_OVERRIDE_Msk) >> TAL_IRQTRIG_OVERRIDE_Pos;
	return tmp;
}

static inline void hri_tal_set_IRQTRIG_reg(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_get_IRQTRIG_reg(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->IRQTRIG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_IRQTRIG_reg(const void *const hw, hri_tal_irqtrig_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_IRQTRIG_reg(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_IRQTRIG_reg(const void *const hw, hri_tal_irqtrig_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->IRQTRIG.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_irqtrig_reg_t hri_tal_read_IRQTRIG_reg(const void *const hw)
{
	return ((Tal *)hw)->IRQTRIG.reg;
}

static inline void hri_tal_write_HALT_reg(const void *const hw, hri_tal_halt_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->HALT.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_write_RESTART_reg(const void *const hw, hri_tal_restart_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->RESTART.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_INTEN_BRK_bit(const void *const hw)
{
	((Tal *)hw)->INTENSET.reg = TAL_INTENSET_BRK;
}

static inline bool hri_tal_get_INTEN_BRK_bit(const void *const hw)
{
	return (((Tal *)hw)->INTENSET.reg & TAL_INTENSET_BRK) >> TAL_INTENSET_BRK_Pos;
}

static inline void hri_tal_write_INTEN_BRK_bit(const void *const hw, bool value)
{
	if (value == 0x0) {
		((Tal *)hw)->INTENCLR.reg = TAL_INTENSET_BRK;
	} else {
		((Tal *)hw)->INTENSET.reg = TAL_INTENSET_BRK;
	}
}

static inline void hri_tal_clear_INTEN_BRK_bit(const void *const hw)
{
	((Tal *)hw)->INTENCLR.reg = TAL_INTENSET_BRK;
}

static inline void hri_tal_set_INTEN_reg(const void *const hw, hri_tal_intenset_reg_t mask)
{
	((Tal *)hw)->INTENSET.reg = mask;
}

static inline hri_tal_intenset_reg_t hri_tal_get_INTEN_reg(const void *const hw, hri_tal_intenset_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->INTENSET.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_tal_intenset_reg_t hri_tal_read_INTEN_reg(const void *const hw)
{
	return ((Tal *)hw)->INTENSET.reg;
}

static inline void hri_tal_write_INTEN_reg(const void *const hw, hri_tal_intenset_reg_t data)
{
	((Tal *)hw)->INTENSET.reg = data;
	((Tal *)hw)->INTENCLR.reg = ~data;
}

static inline void hri_tal_clear_INTEN_reg(const void *const hw, hri_tal_intenset_reg_t mask)
{
	((Tal *)hw)->INTENCLR.reg = mask;
}

static inline hri_tal_brkstatus_reg_t hri_tal_get_BRKSTATUS_CM0P_bf(const void *const hw, hri_tal_brkstatus_reg_t mask)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_CM0P(mask)) >> TAL_BRKSTATUS_CM0P_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_read_BRKSTATUS_CM0P_bf(const void *const hw)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_CM0P_Msk) >> TAL_BRKSTATUS_CM0P_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_get_BRKSTATUS_EVBRK_bf(const void *const hw, hri_tal_brkstatus_reg_t mask)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_EVBRK(mask)) >> TAL_BRKSTATUS_EVBRK_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_read_BRKSTATUS_EVBRK_bf(const void *const hw)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_EVBRK_Msk) >> TAL_BRKSTATUS_EVBRK_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_get_BRKSTATUS_EXTBRK_bf(const void *const       hw,
                                                                      hri_tal_brkstatus_reg_t mask)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_EXTBRK(mask)) >> TAL_BRKSTATUS_EXTBRK_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_read_BRKSTATUS_EXTBRK_bf(const void *const hw)
{
	return (((Tal *)hw)->BRKSTATUS.reg & TAL_BRKSTATUS_EXTBRK_Msk) >> TAL_BRKSTATUS_EXTBRK_Pos;
}

static inline hri_tal_brkstatus_reg_t hri_tal_get_BRKSTATUS_reg(const void *const hw, hri_tal_brkstatus_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Tal *)hw)->BRKSTATUS.reg;
	tmp &= mask;
	return tmp;
}

static inline hri_tal_brkstatus_reg_t hri_tal_read_BRKSTATUS_reg(const void *const hw)
{
	return ((Tal *)hw)->BRKSTATUS.reg;
}

static inline bool hri_tal_get_INTSTATUS_IRQ0_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ0) >> TAL_INTSTATUS_IRQ0_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ1_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ1) >> TAL_INTSTATUS_IRQ1_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ2_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ2) >> TAL_INTSTATUS_IRQ2_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ3_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ3) >> TAL_INTSTATUS_IRQ3_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ4_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ4) >> TAL_INTSTATUS_IRQ4_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ5_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ5) >> TAL_INTSTATUS_IRQ5_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ6_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ6) >> TAL_INTSTATUS_IRQ6_Pos;
}

static inline bool hri_tal_get_INTSTATUS_IRQ7_bit(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->INTSTATUS[index].reg & TAL_INTSTATUS_IRQ7) >> TAL_INTSTATUS_IRQ7_Pos;
}

static inline hri_tal_intstatus_reg_t hri_tal_get_INTSTATUS_reg(const void *const hw, uint8_t index,
                                                                hri_tal_intstatus_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->INTSTATUS[index].reg;
	tmp &= mask;
	return tmp;
}

static inline hri_tal_intstatus_reg_t hri_tal_read_INTSTATUS_reg(const void *const hw, uint8_t index)
{
	return ((Tal *)hw)->INTSTATUS[index].reg;
}

static inline hri_tal_cpuirqs_reg_t hri_tal_get_CPUIRQS_CPUIRQS_bf(const void *const hw, uint8_t index,
                                                                   hri_tal_cpuirqs_reg_t mask)
{
	return (((Tal *)hw)->CPUIRQS[index].reg & TAL_CPUIRQS_CPUIRQS(mask)) >> TAL_CPUIRQS_CPUIRQS_Pos;
}

static inline hri_tal_cpuirqs_reg_t hri_tal_read_CPUIRQS_CPUIRQS_bf(const void *const hw, uint8_t index)
{
	return (((Tal *)hw)->CPUIRQS[index].reg & TAL_CPUIRQS_CPUIRQS_Msk) >> TAL_CPUIRQS_CPUIRQS_Pos;
}

static inline hri_tal_cpuirqs_reg_t hri_tal_get_CPUIRQS_reg(const void *const hw, uint8_t index,
                                                            hri_tal_cpuirqs_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Tal *)hw)->CPUIRQS[index].reg;
	tmp &= mask;
	return tmp;
}

static inline hri_tal_cpuirqs_reg_t hri_tal_read_CPUIRQS_reg(const void *const hw, uint8_t index)
{
	return ((Tal *)hw)->CPUIRQS[index].reg;
}

static inline void hri_talctis_set_CTICTRLA_RESTART_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg |= TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_talctis_get_CTICTRLA_RESTART_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_RESTART) >> TAL_CTICTRLA_RESTART_Pos;
	return (bool)tmp;
}

static inline void hri_talctis_write_CTICTRLA_RESTART_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp &= ~TAL_CTICTRLA_RESTART;
	tmp |= value << TAL_CTICTRLA_RESTART_Pos;
	((TalCtis *)hw)->CTICTRLA.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTICTRLA_RESTART_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg &= ~TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTICTRLA_RESTART_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg ^= TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_set_CTICTRLA_ACTION_bf(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg |= TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_talctis_get_CTICTRLA_ACTION_bf(const void *const      hw,
                                                                        hri_tal_ctictrla_reg_t mask)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_ACTION(mask)) >> TAL_CTICTRLA_ACTION_Pos;
	return tmp;
}

static inline void hri_talctis_write_CTICTRLA_ACTION_bf(const void *const hw, hri_tal_ctictrla_reg_t data)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp &= ~TAL_CTICTRLA_ACTION_Msk;
	tmp |= TAL_CTICTRLA_ACTION(data);
	((TalCtis *)hw)->CTICTRLA.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTICTRLA_ACTION_bf(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg &= ~TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTICTRLA_ACTION_bf(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg ^= TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_talctis_read_CTICTRLA_ACTION_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_ACTION_Msk) >> TAL_CTICTRLA_ACTION_Pos;
	return tmp;
}

static inline void hri_talctis_set_CTICTRLA_reg(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_talctis_get_CTICTRLA_reg(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTICTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_talctis_write_CTICTRLA_reg(const void *const hw, hri_tal_ctictrla_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTICTRLA_reg(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTICTRLA_reg(const void *const hw, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTICTRLA.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_talctis_read_CTICTRLA_reg(const void *const hw)
{
	return ((TalCtis *)hw)->CTICTRLA.reg;
}

static inline void hri_talctis_set_CTIMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg |= TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_talctis_get_CTIMASK_CM0P_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_CM0P) >> TAL_CTIMASK_CM0P_Pos;
	return (bool)tmp;
}

static inline void hri_talctis_write_CTIMASK_CM0P_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_CM0P;
	tmp |= value << TAL_CTIMASK_CM0P_Pos;
	((TalCtis *)hw)->CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTIMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg &= ~TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTIMASK_CM0P_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg ^= TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_set_CTIMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg |= TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_talctis_get_CTIMASK_EVBRK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_EVBRK) >> TAL_CTIMASK_EVBRK_Pos;
	return (bool)tmp;
}

static inline void hri_talctis_write_CTIMASK_EVBRK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_EVBRK;
	tmp |= value << TAL_CTIMASK_EVBRK_Pos;
	((TalCtis *)hw)->CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTIMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg &= ~TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTIMASK_EVBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg ^= TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_set_CTIMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg |= TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_talctis_get_CTIMASK_EXTBRK_bit(const void *const hw)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_EXTBRK) >> TAL_CTIMASK_EXTBRK_Pos;
	return (bool)tmp;
}

static inline void hri_talctis_write_CTIMASK_EXTBRK_bit(const void *const hw, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_EXTBRK;
	tmp |= value << TAL_CTIMASK_EXTBRK_Pos;
	((TalCtis *)hw)->CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTIMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg &= ~TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTIMASK_EXTBRK_bit(const void *const hw)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg ^= TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_set_CTIMASK_reg(const void *const hw, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctimask_reg_t hri_talctis_get_CTIMASK_reg(const void *const hw, hri_tal_ctimask_reg_t mask)
{
	uint8_t tmp;
	tmp = ((TalCtis *)hw)->CTIMASK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_talctis_write_CTIMASK_reg(const void *const hw, hri_tal_ctimask_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_clear_CTIMASK_reg(const void *const hw, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_talctis_toggle_CTIMASK_reg(const void *const hw, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((TalCtis *)hw)->CTIMASK.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctimask_reg_t hri_talctis_read_CTIMASK_reg(const void *const hw)
{
	return ((TalCtis *)hw)->CTIMASK.reg;
}

static inline void hri_tal_set_CTICTRLA_RESTART_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg |= TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTICTRLA_RESTART_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_RESTART) >> TAL_CTICTRLA_RESTART_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_CTICTRLA_RESTART_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp &= ~TAL_CTICTRLA_RESTART;
	tmp |= value << TAL_CTICTRLA_RESTART_Pos;
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTICTRLA_RESTART_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg &= ~TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTICTRLA_RESTART_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg ^= TAL_CTICTRLA_RESTART;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index,
                                                  hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg |= TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_tal_get_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index,
                                                                    hri_tal_ctictrla_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_ACTION(mask)) >> TAL_CTICTRLA_ACTION_Pos;
	return tmp;
}

static inline void hri_tal_write_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index,
                                                    hri_tal_ctictrla_reg_t data)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp &= ~TAL_CTICTRLA_ACTION_Msk;
	tmp |= TAL_CTICTRLA_ACTION(data);
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index,
                                                    hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg &= ~TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index,
                                                     hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg ^= TAL_CTICTRLA_ACTION(mask);
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_tal_read_CTICTRLA_ACTION_bf(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp = (tmp & TAL_CTICTRLA_ACTION_Msk) >> TAL_CTICTRLA_ACTION_Pos;
	return tmp;
}

static inline void hri_tal_set_CTICTRLA_reg(const void *const hw, uint8_t submodule_index, hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_tal_get_CTICTRLA_reg(const void *const hw, uint8_t submodule_index,
                                                              hri_tal_ctictrla_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_CTICTRLA_reg(const void *const hw, uint8_t submodule_index,
                                              hri_tal_ctictrla_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTICTRLA_reg(const void *const hw, uint8_t submodule_index,
                                              hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTICTRLA_reg(const void *const hw, uint8_t submodule_index,
                                               hri_tal_ctictrla_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctictrla_reg_t hri_tal_read_CTICTRLA_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tal *)hw)->Ctis[submodule_index].CTICTRLA.reg;
}

static inline void hri_tal_set_CTIMASK_CM0P_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg |= TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTIMASK_CM0P_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_CM0P) >> TAL_CTIMASK_CM0P_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_CTIMASK_CM0P_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_CM0P;
	tmp |= value << TAL_CTIMASK_CM0P_Pos;
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTIMASK_CM0P_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg &= ~TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTIMASK_CM0P_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg ^= TAL_CTIMASK_CM0P;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_CTIMASK_EVBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg |= TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTIMASK_EVBRK_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_EVBRK) >> TAL_CTIMASK_EVBRK_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_CTIMASK_EVBRK_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_EVBRK;
	tmp |= value << TAL_CTIMASK_EVBRK_Pos;
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTIMASK_EVBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg &= ~TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTIMASK_EVBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg ^= TAL_CTIMASK_EVBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_CTIMASK_EXTBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg |= TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_tal_get_CTIMASK_EXTBRK_bit(const void *const hw, uint8_t submodule_index)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp = (tmp & TAL_CTIMASK_EXTBRK) >> TAL_CTIMASK_EXTBRK_Pos;
	return (bool)tmp;
}

static inline void hri_tal_write_CTIMASK_EXTBRK_bit(const void *const hw, uint8_t submodule_index, bool value)
{
	uint8_t tmp;
	TAL_CRITICAL_SECTION_ENTER();
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp &= ~TAL_CTIMASK_EXTBRK;
	tmp |= value << TAL_CTIMASK_EXTBRK_Pos;
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg = tmp;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTIMASK_EXTBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg &= ~TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTIMASK_EXTBRK_bit(const void *const hw, uint8_t submodule_index)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg ^= TAL_CTIMASK_EXTBRK;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_set_CTIMASK_reg(const void *const hw, uint8_t submodule_index, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg |= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctimask_reg_t hri_tal_get_CTIMASK_reg(const void *const hw, uint8_t submodule_index,
                                                            hri_tal_ctimask_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_tal_write_CTIMASK_reg(const void *const hw, uint8_t submodule_index, hri_tal_ctimask_reg_t data)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg = data;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_clear_CTIMASK_reg(const void *const hw, uint8_t submodule_index, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg &= ~mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_tal_toggle_CTIMASK_reg(const void *const hw, uint8_t submodule_index, hri_tal_ctimask_reg_t mask)
{
	TAL_CRITICAL_SECTION_ENTER();
	((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg ^= mask;
	TAL_CRITICAL_SECTION_LEAVE();
}

static inline hri_tal_ctimask_reg_t hri_tal_read_CTIMASK_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Tal *)hw)->Ctis[submodule_index].CTIMASK.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_TAL_C21_H_INCLUDED */
#endif /* _SAMC21_TAL_COMPONENT_ */
