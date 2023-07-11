/**
 * \file
 *
 * \brief SAM RFCTRL
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 */

#ifdef _SAMR21_RFCTRL_COMPONENT_
#ifndef _HRI_RFCTRL_R21_H_INCLUDED_
#define _HRI_RFCTRL_R21_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <hal_atomic.h>

#if defined(ENABLE_RFCTRL_CRITICAL_SECTIONS)
#define RFCTRL_CRITICAL_SECTION_ENTER() CRITICAL_SECTION_ENTER()
#define RFCTRL_CRITICAL_SECTION_LEAVE() CRITICAL_SECTION_LEAVE()
#else
#define RFCTRL_CRITICAL_SECTION_ENTER()
#define RFCTRL_CRITICAL_SECTION_LEAVE()
#endif

typedef uint16_t hri_rfctrl_fecfg_reg_t;

static inline void hri_rfctrl_set_FECFG_F0CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F0CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F0CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F0CFG(mask)) >> RFCTRL_FECFG_F0CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F0CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F0CFG_Msk;
	tmp |= RFCTRL_FECFG_F0CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F0CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F0CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F0CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F0CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F0CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F0CFG_Msk) >> RFCTRL_FECFG_F0CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_F1CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F1CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F1CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F1CFG(mask)) >> RFCTRL_FECFG_F1CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F1CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F1CFG_Msk;
	tmp |= RFCTRL_FECFG_F1CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F1CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F1CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F1CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F1CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F1CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F1CFG_Msk) >> RFCTRL_FECFG_F1CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_F2CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F2CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F2CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F2CFG(mask)) >> RFCTRL_FECFG_F2CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F2CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F2CFG_Msk;
	tmp |= RFCTRL_FECFG_F2CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F2CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F2CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F2CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F2CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F2CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F2CFG_Msk) >> RFCTRL_FECFG_F2CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_F3CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F3CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F3CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F3CFG(mask)) >> RFCTRL_FECFG_F3CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F3CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F3CFG_Msk;
	tmp |= RFCTRL_FECFG_F3CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F3CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F3CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F3CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F3CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F3CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F3CFG_Msk) >> RFCTRL_FECFG_F3CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_F4CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F4CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F4CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F4CFG(mask)) >> RFCTRL_FECFG_F4CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F4CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F4CFG_Msk;
	tmp |= RFCTRL_FECFG_F4CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F4CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F4CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F4CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F4CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F4CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F4CFG_Msk) >> RFCTRL_FECFG_F4CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_F5CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= RFCTRL_FECFG_F5CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_F5CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F5CFG(mask)) >> RFCTRL_FECFG_F5CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_F5CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	uint16_t tmp;
	RFCTRL_CRITICAL_SECTION_ENTER();
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= ~RFCTRL_FECFG_F5CFG_Msk;
	tmp |= RFCTRL_FECFG_F5CFG(data);
	((Rfctrl *)hw)->FECFG.reg = tmp;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_F5CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~RFCTRL_FECFG_F5CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_F5CFG_bf(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= RFCTRL_FECFG_F5CFG(mask);
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_F5CFG_bf(const void *const hw)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp = (tmp & RFCTRL_FECFG_F5CFG_Msk) >> RFCTRL_FECFG_F5CFG_Pos;
	return tmp;
}

static inline void hri_rfctrl_set_FECFG_reg(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg |= mask;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_get_FECFG_reg(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	uint16_t tmp;
	tmp = ((Rfctrl *)hw)->FECFG.reg;
	tmp &= mask;
	return tmp;
}

static inline void hri_rfctrl_write_FECFG_reg(const void *const hw, hri_rfctrl_fecfg_reg_t data)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg = data;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_clear_FECFG_reg(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg &= ~mask;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline void hri_rfctrl_toggle_FECFG_reg(const void *const hw, hri_rfctrl_fecfg_reg_t mask)
{
	RFCTRL_CRITICAL_SECTION_ENTER();
	((Rfctrl *)hw)->FECFG.reg ^= mask;
	RFCTRL_CRITICAL_SECTION_LEAVE();
}

static inline hri_rfctrl_fecfg_reg_t hri_rfctrl_read_FECFG_reg(const void *const hw)
{
	return ((Rfctrl *)hw)->FECFG.reg;
}

#ifdef __cplusplus
}
#endif

#endif /* _HRI_RFCTRL_R21_H_INCLUDED */
#endif /* _SAMR21_RFCTRL_COMPONENT_ */
