/*
 * Copyright (c) 2019-2023, NVIDIA CORPORATION.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
/*
 * Function/Macro naming determines intended use:
 *
 *     <x>_r(void) : Returns the offset for register <x>.
 *
 *     <x>_o(void) : Returns the offset for element <x>.
 *
 *     <x>_w(void) : Returns the word offset for word (4 byte) element <x>.
 *
 *     <x>_<y>_s(void) : Returns size of field <y> of register <x> in bits.
 *
 *     <x>_<y>_f(u32 v) : Returns a value based on 'v' which has been shifted
 *         and masked to place it at field <y> of register <x>.  This value
 *         can be |'d with others to produce a full register value for
 *         register <x>.
 *
 *     <x>_<y>_m(void) : Returns a mask for field <y> of register <x>.  This
 *         value can be ~'d and then &'d to clear the value of field <y> for
 *         register <x>.
 *
 *     <x>_<y>_<z>_f(void) : Returns the constant value <z> after being shifted
 *         to place it at field <y> of register <x>.  This value can be |'d
 *         with others to produce a full register value for <x>.
 *
 *     <x>_<y>_v(u32 r) : Returns the value of field <y> from a full register
 *         <x> value 'r' after being shifted to place its LSB at bit 0.
 *         This value is suitable for direct comparison with other unshifted
 *         values appropriate for use in field <y> of register <x>.
 *
 *     <x>_<y>_<z>_v(void) : Returns the constant value for <z> defined for
 *         field <y> of register <x>.  This value is suitable for direct
 *         comparison with unshifted values appropriate for use in field <y>
 *         of register <x>.
 */
#ifndef NVGPU_HW_THERM_GA10B_H
#define NVGPU_HW_THERM_GA10B_H

#include <nvgpu/types.h>
#include <nvgpu/static_analysis.h>

#define therm_use_a_r()                                            (0x00020798U)
#define therm_use_a_ext_therm_0_enable_f()                                (0x1U)
#define therm_use_a_ext_therm_1_enable_f()                                (0x2U)
#define therm_use_a_ext_therm_2_enable_f()                                (0x4U)
#define therm_evt_ext_therm_0_r()                                  (0x00020700U)
#define therm_evt_ext_therm_0_slow_factor_f(v)         ((U32(v) & 0x3fU) << 24U)
#define therm_evt_ext_therm_1_r()                                  (0x00020704U)
#define therm_evt_ext_therm_1_slow_factor_f(v)         ((U32(v) & 0x3fU) << 24U)
#define therm_evt_ext_therm_2_r()                                  (0x00020708U)
#define therm_evt_ext_therm_2_slow_factor_f(v)         ((U32(v) & 0x3fU) << 24U)
#define therm_config2_r()                                          (0x00020130U)
#define therm_config2_grad_step_duration_f(v)            ((U32(v) & 0xfU) << 8U)
#define therm_config2_grad_step_duration_m()                   (U32(0xfU) << 8U)
#define therm_config2_slowdown_factor_extended_f(v)     ((U32(v) & 0x1U) << 24U)
#define therm_config2_grad_enable_f(v)                  ((U32(v) & 0x1U) << 31U)
#define therm_gate_ctrl_r(i)\
		(nvgpu_safe_add_u32(0x00020200U, nvgpu_safe_mult_u32((i), 4U)))
#define therm_gate_ctrl_eng_clk_m()                            (U32(0x3U) << 0U)
#define therm_gate_ctrl_eng_clk_run_f()                                   (0x0U)
#define therm_gate_ctrl_eng_clk_auto_f()                                  (0x1U)
#define therm_gate_ctrl_eng_clk_stop_f()                                  (0x2U)
#define therm_gate_ctrl_blk_clk_m()                            (U32(0x3U) << 2U)
#define therm_gate_ctrl_blk_clk_run_f()                                   (0x0U)
#define therm_gate_ctrl_blk_clk_auto_f()                                  (0x4U)
#define therm_gate_ctrl_idle_holdoff_m()                       (U32(0x1U) << 4U)
#define therm_gate_ctrl_idle_holdoff_on_f()                              (0x10U)
#define therm_gate_ctrl_eng_idle_filt_exp_m()                 (U32(0x1fU) << 8U)
#define therm_gate_ctrl_eng_idle_filt_exp__prod_f()                     (0x600U)
#define therm_gate_ctrl_eng_idle_filt_mant_m()                (U32(0x7U) << 13U)
#define therm_gate_ctrl_eng_idle_filt_mant__prod_f()                   (0x2000U)
#define therm_gate_ctrl_eng_delay_before_m()                  (U32(0xfU) << 16U)
#define therm_gate_ctrl_eng_delay_before__prod_f()                    (0xa0000U)
#define therm_gate_ctrl_eng_delay_after_m()                   (U32(0xfU) << 20U)
#define therm_gate_ctrl_eng_delay_after__prod_f()                         (0x0U)
#define therm_fecs_idle_filter_r()                                 (0x00020288U)
#define therm_fecs_idle_filter_value_m()                (U32(0xffffffffU) << 0U)
#define therm_fecs_idle_filter_value__prod_f()                            (0x0U)
#define therm_hubmmu_idle_filter_r()                               (0x0002028cU)
#define therm_hubmmu_idle_filter_value_m()              (U32(0xffffffffU) << 0U)
#define therm_hubmmu_idle_filter_value__prod_f()                          (0x0U)
#define therm_clk_slowdown_2_r(i)\
		(nvgpu_safe_add_u32(0x000201a0U, nvgpu_safe_mult_u32((i), 4U)))
#define therm_clk_slowdown_2_idle_condition_a_select_f(v)\
				((U32(v) & 0xfU) << 0U)
#define therm_clk_slowdown_2_idle_condition_a_type_never_f()             (0x40U)
#define therm_clk_slowdown_2_idle_condition_b_type_never_f()           (0x4000U)
#define therm_grad_stepping_table_r(i)\
		(nvgpu_safe_add_u32(0x000202c8U, nvgpu_safe_mult_u32((i), 4U)))
#define therm_grad_stepping_table_slowdown_factor0_f(v) ((U32(v) & 0x3fU) << 0U)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by1_f()          (0x0U)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by1p5_f()        (0x1U)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by2_f()          (0x2U)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by4_f()          (0x6U)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by8_f()          (0xeU)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by16_f()        (0x1eU)
#define therm_grad_stepping_table_slowdown_factor0_fpdiv_by31_f()        (0x3cU)
#define therm_grad_stepping_table_slowdown_factor1_f(v) ((U32(v) & 0x3fU) << 6U)
#define therm_grad_stepping_table_slowdown_factor2_f(v)\
				((U32(v) & 0x3fU) << 12U)
#define therm_grad_stepping_table_slowdown_factor3_f(v)\
				((U32(v) & 0x3fU) << 18U)
#define therm_grad_stepping_table_slowdown_factor4_f(v)\
				((U32(v) & 0x3fU) << 24U)
#define therm_grad_stepping0_r()                                   (0x000202c0U)
#define therm_grad_stepping0_feature_enable_f()                           (0x1U)
#define therm_grad_stepping1_r()                                   (0x000202c4U)
#define therm_grad_stepping1_pdiv_duration_f(v)      ((U32(v) & 0x1ffffU) << 0U)
#define therm_clk_timing_r(i)\
		(nvgpu_safe_add_u32(0x000203c0U, nvgpu_safe_mult_u32((i), 4U)))
#define therm_clk_timing_grad_slowdown_enabled_f()                    (0x10000U)
#endif
