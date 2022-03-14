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

#ifndef _HEAVY_CONTEXT_JETENGINE_HPP_
#define _HEAVY_CONTEXT_JETENGINE_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvSignalBiquad.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlIf.h"
#include "HvSignalCPole.h"
#include "HvMath.h"
#include "HvSignalRPole.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"
#include "HvSignalDel1.h"

class Heavy_JetEngine : public HeavyContext {

 public:
  Heavy_JetEngine(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_JetEngine();

  const char *getName() override { return "JetEngine"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        SPED = 0xB2D63F95, // sped
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cReceive_rZAP9mtN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DJGQHJy9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AvBW8kkP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l8QgBu8A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_I0xoU4uv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_c2mc9rTl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hE0GjciV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TxzhM7a1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Hgg1slCf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TltFakeI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MtaijPmX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AWyaziiJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UV0200x1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K9cI2Jx2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_F4GlrLrm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_tf8nCM20_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zXLKdX02_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bNoibraJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lTuKWW21_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UfcJZ40W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9sSD298m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kDA9Z7ZG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cWxAJXyv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AOGsQO0X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wvBMUTZD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BrVnUGak_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YTEE1s6w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ojC8mgzD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_lesM5uQC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5vQ1i64U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RE9SjrYN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CPKVzJya_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VZbCyAZQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TFabaYeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eBqhjNzd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_To4fhSzU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SDDt9R3S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sFP0ABjk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iprfDJGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8a1aqSYd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d5OCQe5g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h5acc6vD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ClSZQd61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YHuy1mpy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9vCUqGwt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ShwXnXpl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mw2tu7Aa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W3zrsm4Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aq7dwIl2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VKc7JET2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_htKzADUv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zqeJe1mz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YYsu6tMK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GUT6X0Be_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3vm71CM0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yi5mv6Ox_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_CSa77ytw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Q8ouVVWJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WfSAf1GT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Un1NCTT9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_I8N17tZT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8QTFYI0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QdckfkJM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OyKOwSX3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_sjBoqMWa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fh3yuAD5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8Ha1e9Z7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2vENFo7O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cSAzFE9R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uZbjIcTW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_edTN9rLU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i7j3OeaM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_f0HRlyWF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HWthRCs8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hnojqRtQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TgjiUlm7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ztwPWsRo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jIXQBo2h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DSLxASUK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XOIBkxGV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_X3qX5ZLr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_smRmtGDy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NGVk8N3j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_wpCa65fw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jajrFXIm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Od1XmLTi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_USGL7vwV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DoxHAHTl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RlUAwn2R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1VehYUS3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H5NWu5Xq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_yxUTA79P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1KEnOcVG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KsrnKLxF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_eMIv4HVg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_aiT9iVDv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jXHO03mk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_v99i3Dvu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bNR3n0Ut_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_inyubKif_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3JqVE1WC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QejpWXmk_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalRPole sRPole_7Pn0JOhJ;
  SignalPhasor sPhasor_OAi9Juy8;
  SignalPhasor sPhasor_Xz5F7p8I;
  SignalPhasor sPhasor_qN45Zo9Z;
  SignalPhasor sPhasor_ycn3vJTN;
  SignalPhasor sPhasor_qxnOtsaK;
  SignalBiquad_k sBiquad_k_nHGlVm6G;
  SignalCPole sCPole_owL7gz17;
  SignalRPole sRPole_xNmz4x6S;
  SignalDel1 sDel1_Z3ClEiOM;
  SignalCPole sCPole_JFqELqD8;
  SignalRPole sRPole_LPEzeG7O;
  ControlBinop cBinop_DJGQHJy9;
  ControlBinop cBinop_AvBW8kkP;
  ControlBinop cBinop_l8QgBu8A;
  ControlBinop cBinop_I0xoU4uv;
  ControlBinop cBinop_TxzhM7a1;
  SignalVarf sVarf_Fo93yNMq;
  SignalVarf sVarf_PU0aXk9T;
  ControlVar cVar_TltFakeI;
  SignalVarf sVarf_L3Wbp57T;
  ControlVar cVar_MtaijPmX;
  ControlBinop cBinop_AWyaziiJ;
  ControlBinop cBinop_UV0200x1;
  ControlBinop cBinop_K9cI2Jx2;
  SignalVarf sVarf_yrxTiAuT;
  ControlVar cVar_F4GlrLrm;
  SignalVarf sVarf_HFMoBDuP;
  ControlBinop cBinop_lTuKWW21;
  ControlBinop cBinop_UfcJZ40W;
  SignalVarf sVarf_CxckfKQu;
  SignalVarf sVarf_Po8hx7C0;
  SignalVarf sVarf_142x1T4v;
  SignalVarf sVarf_o9nRDfFi;
  SignalVarf sVarf_13T21vtZ;
  SignalVarf sVarf_LZf1F0s6;
  ControlBinop cBinop_YTEE1s6w;
  ControlVar cVar_ojC8mgzD;
  SignalVarf sVarf_CPU2UNWB;
  ControlIf cIf_lesM5uQC;
  ControlBinop cBinop_5vQ1i64U;
  ControlBinop cBinop_CPKVzJya;
  ControlBinop cBinop_VZbCyAZQ;
  ControlBinop cBinop_TFabaYeq;
  SignalVarf sVarf_Q6gevBZJ;
  SignalVarf sVarf_YCXGI3Tt;
  ControlBinop cBinop_8a1aqSYd;
  ControlBinop cBinop_h5acc6vD;
  ControlBinop cBinop_ClSZQd61;
  ControlBinop cBinop_YHuy1mpy;
  ControlBinop cBinop_9vCUqGwt;
  ControlBinop cBinop_mw2tu7Aa;
  ControlBinop cBinop_W3zrsm4Z;
  ControlVar cVar_aq7dwIl2;
  ControlBinop cBinop_VKc7JET2;
  ControlBinop cBinop_htKzADUv;
  ControlBinop cBinop_zqeJe1mz;
  ControlVar cVar_YYsu6tMK;
  ControlBinop cBinop_GUT6X0Be;
  ControlBinop cBinop_3vm71CM0;
  ControlBinop cBinop_WfSAf1GT;
  ControlBinop cBinop_Un1NCTT9;
  ControlBinop cBinop_I8N17tZT;
  ControlBinop cBinop_8QTFYI0I;
  ControlBinop cBinop_QdckfkJM;
  ControlBinop cBinop_OyKOwSX3;
  ControlVar cVar_sjBoqMWa;
  ControlBinop cBinop_fh3yuAD5;
  SignalVarf sVarf_0rGZKPMD;
  ControlBinop cBinop_2vENFo7O;
  ControlBinop cBinop_cSAzFE9R;
  SignalVarf sVarf_LbMdg2Hk;
  ControlBinop cBinop_uZbjIcTW;
  ControlBinop cBinop_edTN9rLU;
  ControlBinop cBinop_i7j3OeaM;
  ControlBinop cBinop_f0HRlyWF;
  ControlBinop cBinop_TgjiUlm7;
  ControlBinop cBinop_ztwPWsRo;
  SignalVari sVari_iggD1EbF;
  ControlBinop cBinop_XOIBkxGV;
  ControlSlice cSlice_NGVk8N3j;
  ControlRandom cRandom_wpCa65fw;
  ControlBinop cBinop_jajrFXIm;
  ControlBinop cBinop_Od1XmLTi;
  SignalVarf sVarf_BoGX1Jlf;
  ControlBinop cBinop_1VehYUS3;
  ControlBinop cBinop_H5NWu5Xq;
  ControlIf cIf_yxUTA79P;
  ControlBinop cBinop_v99i3Dvu;
  SignalVarf sVarf_63PZek92;
  ControlVar cVar_bNR3n0Ut;
  SignalVarf sVarf_6I0uPLR6;
  ControlBinop cBinop_inyubKif;
  SignalVarf sVarf_iMU0nxw5;
};

#endif // _HEAVY_CONTEXT_JETENGINE_HPP_
