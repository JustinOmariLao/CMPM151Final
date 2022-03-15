/**
 * Copyright (c) 2022 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_LAOSFX_HPP_
#define _HEAVY_CONTEXT_LAOSFX_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlDelay.h"
#include "HvMath.h"
#include "HvSignalRPole.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_LaoSFX : public HeavyContext {

 public:
  Heavy_LaoSFX(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_LaoSFX();

  const char *getName() override { return "LaoSFX"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BUTTONSOUND = 0xD27DD130, // buttonSound
      };
    };
  };
  struct Event {
    struct In {
      enum EventIn : hv_uint32_t {
        CHECKPOINTSOUND = 0xCC6D2A59, // checkPointSound
        LAPSOUND = 0x5F10083B, // lapSound
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_2TFjfahs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XdfYeexr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VBbHE34T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vQ4si8WM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xt7HuXQf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HbQmD94u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ElvacCJT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_44FdAvxF_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_CXhFTCJ8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_15GNpFya_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_99UxY0E2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3AO15RYe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4ryzf7ZQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_c1xY3lmG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dZZ2toCg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VzafKwsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SBv3q7ph_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_Q65DH5NK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_0TTYUnYH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rXNJo7xu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_J279JfQF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4O2y3CNC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FCDqTrUE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m8vSg19n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KrCMcBoE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ix62SGFH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oYLNb11U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HkMoIbct_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4Ak0olHr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_rRDr2fkw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VG1zGZmB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2M6riWvy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FBeNZKUQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l4OtYb8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qEGZXn2B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FkmE50cC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WRSaQdEe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_TZq25fZW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Up21xAR0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_joLyyk5B_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_SyxqMXa1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PzUHzzMS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_rHvgcLex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_tac01CQs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_weCaJ1hi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GYNzOt6j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4D5d6nYy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_MPYykQDF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BnDEbbcM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_3UMAynTH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ymUlz7Ow_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_C5xVL114_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kmZyeVCz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ma5241ud_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_s0dSkVYH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oOz82ely_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QR2K4aaH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9LPXYS0i_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_bN0M8OD2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SWAXZU9K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f14Vx8mL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MAVc0lL4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Sa7TVNtW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1eBZ04UW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PKF9QHBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TtHRtFyE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_mEc7Pk7m_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSystem_BmRRzN77_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hjCFeROr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TIJurgXb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OCoRf0AP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_y4TV9jQI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5DSL3Jcn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_a43lbBQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WQX6NVIw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_N3aZ48qc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rv2WZcL9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Wb9OeAiP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tGe7xAIg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_V2tPiZIX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_eOOTF3Tv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6JSaGcKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_IRLUp2K7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dmOgRXPR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UHiodyLk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1J4LuFf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mE2otge3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VnGjTWqD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cG6apQj6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6TFZ8Q7O_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_tuJAZqYA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_1oxbsqO8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cBAQQdX7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q7Q2NZTC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ow2QB6wg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nhUjqef7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RmVyHEJ3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_NJZTFpZb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_81POk6Ws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_FNfU5WIV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ozi7ZMmD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_L13nANhC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NXgvcI6A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xWdzFAEX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xd3Svnfp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_sVGLXSeK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KUxT09At_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KU9OCuIr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Hpo8uNyc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HwQzQtB7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RT2C0ZUm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VwsmUbDn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nZAfD5Uy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_hvWVSVR2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4vbqRG1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QoMehBou_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_FcKQyncI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_A6ZLOGSA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0vXAvrGq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fJST91UF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RNlHETou_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TSLGcSrP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HxWBDGrp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_efhI7UqO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jozqu1dA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bSLs538U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SiaaU1ay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_mfA2ELkH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tmiFLlGF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fKhtgHSB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JUdqJgxL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_dYw9MoJ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kkpAZLBD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_xXwf2PrP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qRQ1Z3ph_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jyxNaN0v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PrrINNQL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Do29Z3Ck_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rMiqfmAv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s3Y6VXal_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Et6FPAae_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_m05ZzpDB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jQuxyDbN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PlHYGxNT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HcXlI8KL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yg4R8Tif_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_swu2UvMI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hpmAMlGx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_0nuApZLT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fpsBQydi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_yqcP05vA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Cjwu0mEK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fuHLNtWL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ATISH3NH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fsi5YPoZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6oAkdZYq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_sTlHhTiC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_ujcNXrLF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mPRPSkpK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9TQ9qBnv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_aERgcNkP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fYM9JCdo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O4QHOSkx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iUr9sJZK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kcTBUm3m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WnRq06me_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JkiZilA0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bfARnvOi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_9whfHyAd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ePVjBG5W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_49Ta75ye_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OXlWwjzb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DiajGLNe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_kXPj9EVv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HDhYu8y1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ep7StOub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_opnJZp2b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4K3Wbmg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cCIIuBb5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3cwCCiUd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_ROCqxqbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nMmAlImj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dKEP7D2R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MLvtLbiO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9sWInkYw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B6ByjLtq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5j4faBIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CgSwakJc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_76HqqPXN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2Dn2Cax0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uiH3fBTf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M2S75mJ9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YqkLMuHl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BUhK0ZZj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nI0SQ9Bs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NcP1pCEL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pJxilcPF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eKlO8Ikk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oFNldEA1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_n4nVXVYQ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_M1CY1D2U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_lkYeIplF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JZ9YR7dG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G5Djiol3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KXDBfInD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hAMwKGfY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s2BVG576_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Q26AeMFD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hcAdyJus_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_632Vttu7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OcZvGAJb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_lfPk2Av3_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_uvC3rvLh;
  SignalPhasor sPhasor_dKsSFH3R;
  SignalRPole sRPole_9JsfHKg5;
  SignalDel1 sDel1_lMMYin4J;
  SignalRPole sRPole_OWzFh378;
  SignalDel1 sDel1_SCA1IK6L;
  SignalRPole sRPole_N0OFjrXp;
  SignalPhasor sPhasor_nMXUQKcd;
  SignalPhasor sPhasor_scq71DJt;
  SignalLine sLine_fpykiDmt;
  SignalRPole sRPole_6nBLLJem;
  SignalDel1 sDel1_QzH4r81c;
  SignalPhasor sPhasor_kGiYDgS6;
  SignalPhasor sPhasor_QgCvNMQK;
  SignalLine sLine_e7InKUzV;
  SignalRPole sRPole_OKgqz2aq;
  SignalDel1 sDel1_QFxyWlcu;
  ControlBinop cBinop_2TFjfahs;
  ControlVar cVar_vQ4si8WM;
  ControlBinop cBinop_Xt7HuXQf;
  ControlDelay cDelay_HbQmD94u;
  ControlVar cVar_99UxY0E2;
  ControlVar cVar_c1xY3lmG;
  ControlRandom cRandom_0TTYUnYH;
  ControlBinop cBinop_rXNJo7xu;
  ControlSlice cSlice_J279JfQF;
  ControlBinop cBinop_4O2y3CNC;
  SignalVarf sVarf_XTR0IDye;
  ControlBinop cBinop_FCDqTrUE;
  ControlBinop cBinop_KrCMcBoE;
  ControlBinop cBinop_ix62SGFH;
  ControlBinop cBinop_oYLNb11U;
  ControlBinop cBinop_HkMoIbct;
  SignalVarf sVarf_Qrz93rcb;
  ControlVar cVar_VG1zGZmB;
  ControlBinop cBinop_2M6riWvy;
  ControlBinop cBinop_FBeNZKUQ;
  ControlBinop cBinop_l4OtYb8k;
  ControlSlice cSlice_SyxqMXa1;
  ControlRandom cRandom_rHvgcLex;
  ControlBinop cBinop_weCaJ1hi;
  ControlDelay cDelay_MPYykQDF;
  ControlVar cVar_kmZyeVCz;
  SignalVarf sVarf_TcWULEJW;
  SignalVarf sVarf_2mFPNTk4;
  ControlBinop cBinop_SWAXZU9K;
  ControlBinop cBinop_MAVc0lL4;
  ControlVar cVar_Sa7TVNtW;
  ControlDelay cDelay_PKF9QHBp;
  ControlBinop cBinop_TtHRtFyE;
  ControlBinop cBinop_OCoRf0AP;
  ControlBinop cBinop_y4TV9jQI;
  ControlBinop cBinop_a43lbBQE;
  ControlBinop cBinop_WQX6NVIw;
  ControlBinop cBinop_dmOgRXPR;
  ControlBinop cBinop_UHiodyLk;
  ControlBinop cBinop_1J4LuFf5;
  ControlBinop cBinop_mE2otge3;
  ControlDelay cDelay_tuJAZqYA;
  ControlVar cVar_cBAQQdX7;
  ControlBinop cBinop_ow2QB6wg;
  ControlBinop cBinop_NJZTFpZb;
  ControlBinop cBinop_81POk6Ws;
  ControlDelay cDelay_FNfU5WIV;
  ControlVar cVar_xWdzFAEX;
  ControlVar cVar_KUxT09At;
  ControlVar cVar_VwsmUbDn;
  ControlBinop cBinop_nZAfD5Uy;
  ControlDelay cDelay_hvWVSVR2;
  SignalVarf sVarf_zMN6NUbx;
  ControlBinop cBinop_0vXAvrGq;
  ControlBinop cBinop_fJST91UF;
  SignalVarf sVarf_nbutMxvK;
  ControlBinop cBinop_RNlHETou;
  ControlBinop cBinop_TSLGcSrP;
  ControlBinop cBinop_HxWBDGrp;
  ControlBinop cBinop_efhI7UqO;
  ControlBinop cBinop_Jozqu1dA;
  ControlBinop cBinop_bSLs538U;
  ControlVar cVar_tmiFLlGF;
  ControlBinop cBinop_fKhtgHSB;
  SignalVarf sVarf_TmQxVSdn;
  ControlVar cVar_qRQ1Z3ph;
  SignalVarf sVarf_9qRGnpay;
  ControlBinop cBinop_jyxNaN0v;
  ControlBinop cBinop_Do29Z3Ck;
  SignalVarf sVarf_MHaZtNUo;
  ControlVar cVar_rMiqfmAv;
  ControlBinop cBinop_s3Y6VXal;
  ControlBinop cBinop_jQuxyDbN;
  ControlBinop cBinop_PlHYGxNT;
  ControlBinop cBinop_HcXlI8KL;
  ControlBinop cBinop_yg4R8Tif;
  ControlBinop cBinop_swu2UvMI;
  ControlBinop cBinop_hpmAMlGx;
  SignalVarf sVarf_ICfG5Wey;
  ControlBinop cBinop_Cjwu0mEK;
  ControlVar cVar_fuHLNtWL;
  ControlVar cVar_ATISH3NH;
  SignalVarf sVarf_YGoa4zsA;
  ControlDelay cDelay_ujcNXrLF;
  ControlBinop cBinop_iUr9sJZK;
  ControlBinop cBinop_kcTBUm3m;
  ControlBinop cBinop_WnRq06me;
  ControlBinop cBinop_JkiZilA0;
  ControlVar cVar_bfARnvOi;
  ControlBinop cBinop_ePVjBG5W;
  ControlDelay cDelay_HDhYu8y1;
  ControlBinop cBinop_ep7StOub;
  ControlBinop cBinop_4K3Wbmg0;
  ControlBinop cBinop_cCIIuBb5;
  ControlVar cVar_ROCqxqbV;
  ControlVar cVar_MLvtLbiO;
  ControlVar cVar_9sWInkYw;
  ControlBinop cBinop_B6ByjLtq;
  SignalVarf sVarf_BqjHXIXn;
  SignalVarf sVarf_zhtoXP1u;
  ControlBinop cBinop_5j4faBIs;
  ControlBinop cBinop_CgSwakJc;
  ControlBinop cBinop_76HqqPXN;
  ControlBinop cBinop_uiH3fBTf;
  ControlBinop cBinop_M2S75mJ9;
  ControlBinop cBinop_YqkLMuHl;
  ControlVar cVar_BUhK0ZZj;
  ControlBinop cBinop_nI0SQ9Bs;
  ControlBinop cBinop_eKlO8Ikk;
  ControlDelay cDelay_lkYeIplF;
  ControlBinop cBinop_JZ9YR7dG;
  ControlBinop cBinop_G5Djiol3;
  SignalVarf sVarf_q5xycr4H;
  ControlBinop cBinop_s2BVG576;
  ControlBinop cBinop_hcAdyJus;
  ControlVar cVar_632Vttu7;
  ControlBinop cBinop_OcZvGAJb;
  SignalVarf sVarf_KPtuSliq;
};

#endif // _HEAVY_CONTEXT_LAOSFX_HPP_
