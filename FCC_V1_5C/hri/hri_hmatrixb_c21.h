/**
 * \file
 *
 * \brief SAM HMATRIXB
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

#ifdef _SAMC21_HMATRIXB_COMPONENT_
#ifndef _HRI_HMATRIXB_C21_H_INCLUDED_
#define _HRI_HMATRIXB_C21_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_HMATRIXB_CRITICAL_SECTIONS)
#define HMATRIXB_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define HMATRIXB_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define HMATRIXB_CRITICAL_SECTION_ENTER()
#define HMATRIXB_CRITICAL_SECTION_LEAVE()
#endif

typedef uint32_t hri_hmatrixb_mcfg_reg_t;
typedef uint32_t hri_hmatrixb_mrcr_reg_t;
typedef uint32_t hri_hmatrixb_pras_reg_t;
typedef uint32_t hri_hmatrixb_prbs_reg_t;
typedef uint32_t hri_hmatrixb_scfg_reg_t;
typedef uint32_t hri_hmatrixb_sfr_reg_t;
typedef uint32_t hri_hmatrixbprs_pras_reg_t;
typedef uint32_t hri_hmatrixbprs_prbs_reg_t;

static inline void hri_hmatrixb_set_MCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_mcfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MCFG[index].reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_mcfg_reg_t hri_hmatrixb_get_MCFG_reg(const void *const hw, uint8_t index,
                                                                hri_hmatrixb_mcfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->MCFG[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_MCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_mcfg_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MCFG[index].reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_MCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_mcfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MCFG[index].reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_MCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_mcfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MCFG[index].reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_mcfg_reg_t hri_hmatrixb_read_MCFG_reg(const void *const hw, uint8_t index)
{
	return ((Hmatrixb *)hw)->MCFG[index].reg;
}

static inline void hri_hmatrixb_set_SCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_scfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SCFG[index].reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_scfg_reg_t hri_hmatrixb_get_SCFG_reg(const void *const hw, uint8_t index,
                                                                hri_hmatrixb_scfg_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->SCFG[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_SCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_scfg_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SCFG[index].reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_SCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_scfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SCFG[index].reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_SCFG_reg(const void *const hw, uint8_t index, hri_hmatrixb_scfg_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SCFG[index].reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_scfg_reg_t hri_hmatrixb_read_SCFG_reg(const void *const hw, uint8_t index)
{
	return ((Hmatrixb *)hw)->SCFG[index].reg;
}

static inline void hri_hmatrixb_set_MRCR_reg(const void *const hw, hri_hmatrixb_mrcr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MRCR.reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_mrcr_reg_t hri_hmatrixb_get_MRCR_reg(const void *const hw, hri_hmatrixb_mrcr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->MRCR.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_MRCR_reg(const void *const hw, hri_hmatrixb_mrcr_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MRCR.reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_MRCR_reg(const void *const hw, hri_hmatrixb_mrcr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MRCR.reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_MRCR_reg(const void *const hw, hri_hmatrixb_mrcr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->MRCR.reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_mrcr_reg_t hri_hmatrixb_read_MRCR_reg(const void *const hw)
{
	return ((Hmatrixb *)hw)->MRCR.reg;
}

static inline void hri_hmatrixb_set_SFR_reg(const void *const hw, uint8_t index, hri_hmatrixb_sfr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SFR[index].reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_sfr_reg_t hri_hmatrixb_get_SFR_reg(const void *const hw, uint8_t index,
                                                              hri_hmatrixb_sfr_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->SFR[index].reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_SFR_reg(const void *const hw, uint8_t index, hri_hmatrixb_sfr_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SFR[index].reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_SFR_reg(const void *const hw, uint8_t index, hri_hmatrixb_sfr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SFR[index].reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_SFR_reg(const void *const hw, uint8_t index, hri_hmatrixb_sfr_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->SFR[index].reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_sfr_reg_t hri_hmatrixb_read_SFR_reg(const void *const hw, uint8_t index)
{
	return ((Hmatrixb *)hw)->SFR[index].reg;
}

static inline void hri_hmatrixbprs_set_PRAS_reg(const void *const hw, hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRAS.reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_pras_reg_t hri_hmatrixbprs_get_PRAS_reg(const void *const hw, hri_hmatrixb_pras_reg_t mask)
{
	uint32_t tmp;
	tmp = ((HmatrixbPrs *)hw)->PRAS.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixbprs_write_PRAS_reg(const void *const hw, hri_hmatrixb_pras_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRAS.reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixbprs_clear_PRAS_reg(const void *const hw, hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRAS.reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixbprs_toggle_PRAS_reg(const void *const hw, hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRAS.reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_pras_reg_t hri_hmatrixbprs_read_PRAS_reg(const void *const hw)
{
	return ((HmatrixbPrs *)hw)->PRAS.reg;
}

static inline void hri_hmatrixbprs_set_PRBS_reg(const void *const hw, hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRBS.reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_prbs_reg_t hri_hmatrixbprs_get_PRBS_reg(const void *const hw, hri_hmatrixb_prbs_reg_t mask)
{
	uint32_t tmp;
	tmp = ((HmatrixbPrs *)hw)->PRBS.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixbprs_write_PRBS_reg(const void *const hw, hri_hmatrixb_prbs_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRBS.reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixbprs_clear_PRBS_reg(const void *const hw, hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRBS.reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixbprs_toggle_PRBS_reg(const void *const hw, hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((HmatrixbPrs *)hw)->PRBS.reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_prbs_reg_t hri_hmatrixbprs_read_PRBS_reg(const void *const hw)
{
	return ((HmatrixbPrs *)hw)->PRBS.reg;
}

static inline void hri_hmatrixb_set_PRAS_reg(const void *const hw, uint8_t submodule_index,
                                             hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_pras_reg_t hri_hmatrixb_get_PRAS_reg(const void *const hw, uint8_t submodule_index,
                                                                hri_hmatrixb_pras_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_PRAS_reg(const void *const hw, uint8_t submodule_index,
                                               hri_hmatrixb_pras_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_PRAS_reg(const void *const hw, uint8_t submodule_index,
                                               hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_PRAS_reg(const void *const hw, uint8_t submodule_index,
                                                hri_hmatrixb_pras_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_pras_reg_t hri_hmatrixb_read_PRAS_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Hmatrixb *)hw)->Prs[submodule_index].PRAS.reg;
}

static inline void hri_hmatrixb_set_PRBS_reg(const void *const hw, uint8_t submodule_index,
                                             hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg |= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_prbs_reg_t hri_hmatrixb_get_PRBS_reg(const void *const hw, uint8_t submodule_index,
                                                                hri_hmatrixb_prbs_reg_t mask)
{
	uint32_t tmp;
	tmp = ((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_hmatrixb_write_PRBS_reg(const void *const hw, uint8_t submodule_index,
                                               hri_hmatrixb_prbs_reg_t data)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg = data;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_clear_PRBS_reg(const void *const hw, uint8_t submodule_index,
                                               hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg &= ~mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline void hri_hmatrixb_toggle_PRBS_reg(const void *const hw, uint8_t submodule_index,
                                                hri_hmatrixb_prbs_reg_t mask)
{
	HMATRIXB_CRITICAL_SECTION_ENTER();
	((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg ^= mask;
	HMATRIXB_CRITICAL_SECTION_LEAVE();
}

static inline hri_hmatrixb_prbs_reg_t hri_hmatrixb_read_PRBS_reg(const void *const hw, uint8_t submodule_index)
{
	return ((Hmatrixb *)hw)->Prs[submodule_index].PRBS.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_HMATRIXB_C21_H_INCLUDED */
#endif /* _SAMC21_HMATRIXB_COMPONENT_ */
