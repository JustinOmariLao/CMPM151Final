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
  struct Event {
    struct In {
      enum EventIn : hv_uint32_t {
        BUTTONSOUND = 0xD27DD130, // buttonSound
        CHECKPOINTSOUND = 0xCC6D2A59, // checkPointSound
        LAPSOUND = 0x5F10083B, // lapSound
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cReceive_UlLW2tgj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_SGLRLI5e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x1DFCelF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0XR6Xqgf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_s2Ufa28p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_38vS8K3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lmEmlZQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o3NZcsup_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4e15pabk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sLE3JphU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Efz6Eyhm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JOwHJmm2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XjfsSBsH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qz9F4nfW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_THbNu37q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0uerL5iA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NLQhHbtP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3LaEQeDH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jKjVubGC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UV4SEqdt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_j7s4TyLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZtJDXSOP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bJGiyMNU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gCxzJCrV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J7ESyoTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_H7ac8dwv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Rx6Cvt75_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e2DsurwF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zZ32LhuZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s3PwieIq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OH6gvL9j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0L62sR0v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J8UEW7Ru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cUpgY7JG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wXYc51Kt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_xwdOtOkX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Hi5B89zW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_IDkSq7WS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bTo8dJpD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YFbZYaDo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_yqoD9Yv6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dyaVuosr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_glcO4VkD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_fcPJqYpH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i2EXfJ7q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_RCrrOtXT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_47jGekf1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YTMo5ib1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FBIcQJep_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CZjkS8d3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f7DYLFkN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2ZjZ38Qu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4D8OPEVr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_iKEPbbZQ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_WCfdscgP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_c8Jc6zzz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vtM1CRAT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_M6BAU8zO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_m6vtpdTd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_ARIS2CF0_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_jWyvqY3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_H159xkKA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SDGF4odX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Kqw1qVHF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qKSMvHki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zcbvJe0E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xP56JvCg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PEH0l7m4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xw4eOEBo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TKjzyEOH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_fmihbv90_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kiWaQa6t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9LMIkVGO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HWGqtKfA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2WRYg6Ry_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n3x916wd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2FmrFQVn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ABP680r9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QmPO8yp2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MUjy291u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uV2crvQm_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_vttHfPip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aRdS08Pa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ujAFwPHX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O1MoglkV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_z8akUuS2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSwitchcase_RexRJG0y_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_iiVwQvcr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_PNUZg1ax_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_FNJB9gAn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_km7iUTmN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_sUNR4W30_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Qf9LL7Qu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QI4B5ZjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i9xybXsm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FJ1jX5oK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p4hAQCMd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_E0eve8pc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_ypGm6vaQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lLAqADNL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HCcxs84B_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_PDHzB7PZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bh00jptf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hc528YdU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_5uSQWkBW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_1TjPReaK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BwbkVHCn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_JsXa2FhI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F4xCkLee_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aJBIU7Vp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XPLDPb3X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3DYvzebd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_BXIJUxwR_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_wxr6gmPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_G0YnY6MT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GpbuOBCM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AduOv8fN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Dx0hrYhh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_NefVRUyW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cVar_OxN7KD5d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9cpX2OQh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_P7OsJYpA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZH6RUQTm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2nTsn3Wj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_f70IBwii_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3l7EjoSW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NodRYBM8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FYk2TwO5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7c5SWejt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qRzhPL8J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kR2DXKFK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZDnuQnFi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C2IBAHdc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HfRd6k0g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ovyEhMxT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HFwwO2cw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6kQFX7wj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_uaKVPTsU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cReceive_Lk7VTwYK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r6XtMVaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3XdmjSqg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_05HaapuM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0D5CZxew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_buH4fQKK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_heKuxKEU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9YzUGhSw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gyvrYLSt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WYCobSsk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mT1yqCB3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HRUObonh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hixLw5Wk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_JLx5miWD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_D3N3ABCk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_8TYrgnA2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B9OsYL9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mCoklzcI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zzsik4n2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dHyfBg1E_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_ANupa4O7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_HfhClk6G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_o5VRDT2L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aMBK0Slq_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_IWMduMSr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_SYQeomW8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8oL4iEDY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_1m63IblA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_HAgAuEQT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_U3v3Efq7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w9O2uxMk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_3rzs5M5q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_D4o23XmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sZkuc3b1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XkoVW7tI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vzwkU8e0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bypcsxcZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EUoMfH3Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_kOJzOMsY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OcO7fKS4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wpCqqZFt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2u4dwQpp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MbjQk6CM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hkofS5jw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_O8erN1MD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_98X1fzIj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1hkU17Bz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_HaQm1Sd8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lunFtrmi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EOjn13zB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GJdws79n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PZwA0tbO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RUsbVauU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_meyiTq3j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_BCR7UoAY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xMUhdSHN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EeG65DAb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hwlRUhTg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HlZ5v9xD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_YfUAb3v3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KYjLMcuM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4STGFgPm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mwkGhGd8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1oBxCrOY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GCQrsdxn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ob2cMvhH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_wpN1BfYf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TT9ijIuV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_paJouoLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Mo4BGKjC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xebwzQkz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nxq4Drf4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_woQcxsJ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OaVoTXpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_CcmXOFS5;
  SignalPhasor sPhasor_xwCBYkyL;
  SignalLine sLine_wNaOGkXW;
  SignalRPole sRPole_hR673SGl;
  SignalDel1 sDel1_0IliIWoH;
  SignalPhasor sPhasor_NWktn96e;
  SignalPhasor sPhasor_5wS50EET;
  SignalRPole sRPole_F0i9jqXj;
  SignalDel1 sDel1_fMN2kC8f;
  SignalRPole sRPole_EZJHzIeg;
  SignalDel1 sDel1_EnXsQ0Da;
  SignalRPole sRPole_keRSGfgd;
  SignalPhasor sPhasor_6gDyyrqH;
  SignalPhasor sPhasor_mXtFabMt;
  SignalLine sLine_sewb8qSg;
  SignalRPole sRPole_c89MkRri;
  SignalDel1 sDel1_aDjSyI8R;
  ControlBinop cBinop_x1DFCelF;
  ControlBinop cBinop_38vS8K3A;
  ControlBinop cBinop_lmEmlZQb;
  ControlBinop cBinop_o3NZcsup;
  ControlBinop cBinop_4e15pabk;
  SignalVarf sVarf_mBX9HHqs;
  ControlBinop cBinop_Efz6Eyhm;
  SignalVarf sVarf_i80qZI1t;
  ControlBinop cBinop_JOwHJmm2;
  ControlVar cVar_XjfsSBsH;
  ControlBinop cBinop_qz9F4nfW;
  ControlBinop cBinop_THbNu37q;
  SignalVarf sVarf_6DdTZWNc;
  ControlBinop cBinop_0uerL5iA;
  ControlBinop cBinop_3LaEQeDH;
  ControlBinop cBinop_jKjVubGC;
  ControlBinop cBinop_UV4SEqdt;
  ControlBinop cBinop_bJGiyMNU;
  ControlBinop cBinop_gCxzJCrV;
  ControlBinop cBinop_e2DsurwF;
  ControlBinop cBinop_zZ32LhuZ;
  ControlBinop cBinop_s3PwieIq;
  ControlVar cVar_OH6gvL9j;
  SignalVarf sVarf_zX8kB2YK;
  ControlBinop cBinop_0L62sR0v;
  ControlBinop cBinop_J8UEW7Ru;
  ControlBinop cBinop_cUpgY7JG;
  ControlBinop cBinop_wXYc51Kt;
  SignalVarf sVarf_SrWj7uQa;
  ControlBinop cBinop_bTo8dJpD;
  ControlDelay cDelay_yqoD9Yv6;
  ControlBinop cBinop_i2EXfJ7q;
  ControlDelay cDelay_RCrrOtXT;
  ControlBinop cBinop_CZjkS8d3;
  ControlBinop cBinop_2ZjZ38Qu;
  ControlVar cVar_4D8OPEVr;
  ControlVar cVar_vtM1CRAT;
  SignalVarf sVarf_Dd5wxQTj;
  ControlVar cVar_M6BAU8zO;
  ControlVar cVar_m6vtpdTd;
  ControlDelay cDelay_jWyvqY3T;
  ControlBinop cBinop_qKSMvHki;
  ControlBinop cBinop_zcbvJe0E;
  ControlVar cVar_xP56JvCg;
  ControlBinop cBinop_PEH0l7m4;
  ControlBinop cBinop_Xw4eOEBo;
  SignalVarf sVarf_SBcPebzB;
  ControlBinop cBinop_9LMIkVGO;
  ControlBinop cBinop_HWGqtKfA;
  ControlBinop cBinop_2WRYg6Ry;
  ControlBinop cBinop_n3x916wd;
  ControlBinop cBinop_2FmrFQVn;
  SignalVarf sVarf_zjvzYCb4;
  ControlDelay cDelay_ABP680r9;
  ControlVar cVar_ujAFwPHX;
  ControlRandom cRandom_iiVwQvcr;
  ControlSlice cSlice_FNJB9gAn;
  ControlBinop cBinop_km7iUTmN;
  ControlBinop cBinop_i9xybXsm;
  ControlVar cVar_FJ1jX5oK;
  ControlBinop cBinop_p4hAQCMd;
  ControlDelay cDelay_ypGm6vaQ;
  ControlBinop cBinop_lLAqADNL;
  SignalVarf sVarf_QykFE866;
  ControlSlice cSlice_5uSQWkBW;
  ControlRandom cRandom_1TjPReaK;
  ControlBinop cBinop_BwbkVHCn;
  SignalVarf sVarf_TSgLMtic;
  ControlVar cVar_F4xCkLee;
  ControlBinop cBinop_aJBIU7Vp;
  ControlDelay cDelay_G0YnY6MT;
  ControlVar cVar_OxN7KD5d;
  ControlVar cVar_9cpX2OQh;
  ControlBinop cBinop_7c5SWejt;
  ControlBinop cBinop_qRzhPL8J;
  ControlBinop cBinop_ZDnuQnFi;
  ControlBinop cBinop_C2IBAHdc;
  SignalVarf sVarf_KZA0cUOk;
  ControlBinop cBinop_r6XtMVaM;
  ControlBinop cBinop_buH4fQKK;
  ControlBinop cBinop_heKuxKEU;
  ControlVar cVar_9YzUGhSw;
  ControlBinop cBinop_gyvrYLSt;
  ControlBinop cBinop_WYCobSsk;
  SignalVarf sVarf_ycq9AZ0e;
  ControlVar cVar_mT1yqCB3;
  ControlBinop cBinop_HRUObonh;
  ControlBinop cBinop_hixLw5Wk;
  ControlDelay cDelay_8TYrgnA2;
  ControlBinop cBinop_B9OsYL9N;
  ControlVar cVar_zzsik4n2;
  ControlDelay cDelay_HfhClk6G;
  ControlVar cVar_SYQeomW8;
  SignalVarf sVarf_SJpc5Aer;
  ControlBinop cBinop_8oL4iEDY;
  ControlDelay cDelay_1m63IblA;
  ControlVar cVar_D4o23XmP;
  ControlBinop cBinop_sZkuc3b1;
  ControlBinop cBinop_vzwkU8e0;
  ControlBinop cBinop_bypcsxcZ;
  ControlBinop cBinop_EUoMfH3Q;
  ControlVar cVar_hkofS5jw;
  ControlBinop cBinop_lunFtrmi;
  ControlBinop cBinop_GJdws79n;
  ControlBinop cBinop_PZwA0tbO;
  ControlBinop cBinop_RUsbVauU;
  ControlBinop cBinop_meyiTq3j;
  ControlVar cVar_BCR7UoAY;
  ControlBinop cBinop_xMUhdSHN;
  ControlBinop cBinop_EeG65DAb;
  SignalVarf sVarf_MRuPdSiP;
  ControlBinop cBinop_hwlRUhTg;
  ControlBinop cBinop_HlZ5v9xD;
  SignalVarf sVarf_KxsxXQNe;
  ControlVar cVar_TT9ijIuV;
  ControlBinop cBinop_paJouoLy;
  ControlBinop cBinop_xebwzQkz;
  ControlVar cVar_nxq4Drf4;
};

#endif // _HEAVY_CONTEXT_LAOSFX_HPP_
