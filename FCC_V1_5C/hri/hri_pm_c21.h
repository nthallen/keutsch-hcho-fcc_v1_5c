/**
 * \file
 *
 * \brief SAM PM
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

#ifdef _SAMC21_PM_COMPONENT_
#ifndef _HRI_PM_C21_H_INCLUDED_
#define _HRI_PM_C21_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_PM_CRITICAL_SECTIONS)
#define PM_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define PM_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define PM_CRITICAL_SECTION_ENTER()
#define PM_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_pm_stdbycfg_reg_t;
typedef uint8_t  hri_pm_sleepcfg_reg_t;

static inline void hri_pm_set_SLEEPCFG_SLEEPMODE_bf(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg |= PM_SLEEPCFG_SLEEPMODE(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_sleepcfg_reg_t hri_pm_get_SLEEPCFG_SLEEPMODE_bf(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Pm *)hw)->SLEEPCFG.reg;
	tmp = (tmp & PM_SLEEPCFG_SLEEPMODE(mask)) >> PM_SLEEPCFG_SLEEPMODE_Pos;
	return tmp;
}

static inline void hri_pm_write_SLEEPCFG_SLEEPMODE_bf(const void *const hw, hri_pm_sleepcfg_reg_t data)
{
	uint8_t tmp;
	PM_CRITICAL_SECTION_ENTER();
	tmp = ((Pm *)hw)->SLEEPCFG.reg;
	tmp &= ~PM_SLEEPCFG_SLEEPMODE_Msk;
	tmp |= PM_SLEEPCFG_SLEEPMODE(data);
	((Pm *)hw)->SLEEPCFG.reg = tmp;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_clear_SLEEPCFG_SLEEPMODE_bf(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg &= ~PM_SLEEPCFG_SLEEPMODE(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_toggle_SLEEPCFG_SLEEPMODE_bf(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg ^= PM_SLEEPCFG_SLEEPMODE(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_sleepcfg_reg_t hri_pm_read_SLEEPCFG_SLEEPMODE_bf(const void *const hw)
{
	uint8_t tmp;
	tmp = ((Pm *)hw)->SLEEPCFG.reg;
	tmp = (tmp & PM_SLEEPCFG_SLEEPMODE_Msk) >> PM_SLEEPCFG_SLEEPMODE_Pos;
	return tmp;
}

static inline void hri_pm_set_SLEEPCFG_reg(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg |= mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_sleepcfg_reg_t hri_pm_get_SLEEPCFG_reg(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	uint8_t tmp;
	tmp = ((Pm *)hw)->SLEEPCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_pm_write_SLEEPCFG_reg(const void *const hw, hri_pm_sleepcfg_reg_t data)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg = data;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_clear_SLEEPCFG_reg(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg &= ~mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_toggle_SLEEPCFG_reg(const void *const hw, hri_pm_sleepcfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->SLEEPCFG.reg ^= mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_sleepcfg_reg_t hri_pm_read_SLEEPCFG_reg(const void *const hw)
{
	return ((Pm *)hw)->SLEEPCFG.reg;
}

static inline void hri_pm_set_STDBYCFG_BBIASHS_bit(const void *const hw)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg |= PM_STDBYCFG_BBIASHS_Msk;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline bool hri_pm_get_STDBYCFG_BBIASHS_bit(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp = (tmp & PM_STDBYCFG_BBIASHS_Msk) >> PM_STDBYCFG_BBIASHS_Pos;
	return (bool)tmp;
}

static inline void hri_pm_write_STDBYCFG_BBIASHS_bit(const void *const hw, bool value)
{
	uint16_t tmp;
	PM_CRITICAL_SECTION_ENTER();
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp &= ~PM_STDBYCFG_BBIASHS_Msk;
	tmp |= value << PM_STDBYCFG_BBIASHS_Pos;
	((Pm *)hw)->STDBYCFG.reg = tmp;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_clear_STDBYCFG_BBIASHS_bit(const void *const hw)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg &= ~PM_STDBYCFG_BBIASHS_Msk;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_toggle_STDBYCFG_BBIASHS_bit(const void *const hw)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg ^= PM_STDBYCFG_BBIASHS_Msk;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_set_STDBYCFG_VREGSMOD_bf(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg |= PM_STDBYCFG_VREGSMOD(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_stdbycfg_reg_t hri_pm_get_STDBYCFG_VREGSMOD_bf(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp = (tmp & PM_STDBYCFG_VREGSMOD(mask)) >> PM_STDBYCFG_VREGSMOD_Pos;
	return tmp;
}

static inline void hri_pm_write_STDBYCFG_VREGSMOD_bf(const void *const hw, hri_pm_stdbycfg_reg_t data)
{
	uint16_t tmp;
	PM_CRITICAL_SECTION_ENTER();
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp &= ~PM_STDBYCFG_VREGSMOD_Msk;
	tmp |= PM_STDBYCFG_VREGSMOD(data);
	((Pm *)hw)->STDBYCFG.reg = tmp;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_clear_STDBYCFG_VREGSMOD_bf(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg &= ~PM_STDBYCFG_VREGSMOD(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_toggle_STDBYCFG_VREGSMOD_bf(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg ^= PM_STDBYCFG_VREGSMOD(mask);
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_stdbycfg_reg_t hri_pm_read_STDBYCFG_VREGSMOD_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp = (tmp & PM_STDBYCFG_VREGSMOD_Msk) >> PM_STDBYCFG_VREGSMOD_Pos;
	return tmp;
}

static inline void hri_pm_set_STDBYCFG_reg(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg |= mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_stdbycfg_reg_t hri_pm_get_STDBYCFG_reg(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Pm *)hw)->STDBYCFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_pm_write_STDBYCFG_reg(const void *const hw, hri_pm_stdbycfg_reg_t data)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg = data;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_clear_STDBYCFG_reg(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg &= ~mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline void hri_pm_toggle_STDBYCFG_reg(const void *const hw, hri_pm_stdbycfg_reg_t mask)
{
	PM_CRITICAL_SECTION_ENTER();
	((Pm *)hw)->STDBYCFG.reg ^= mask;
	PM_CRITICAL_SECTION_LEAVE();
}

static inline hri_pm_stdbycfg_reg_t hri_pm_read_STDBYCFG_reg(const void *const hw)
{
	return ((Pm *)hw)->STDBYCFG.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_PM_C21_H_INCLUDED */
#endif /* _SAMC21_PM_COMPONENT_ */
