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

#include "Heavy_LaoSFX.hpp"

#define Context(_c) reinterpret_cast<Heavy_LaoSFX *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_LaoSFX_new(double sampleRate) {
    return new Heavy_LaoSFX(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_LaoSFX_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_LaoSFX(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_LaoSFX::Heavy_LaoSFX(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_uvC3rvLh, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_dKsSFH3R, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_9JsfHKg5);
  numBytes += sDel1_init(&sDel1_lMMYin4J);
  numBytes += sRPole_init(&sRPole_OWzFh378);
  numBytes += sDel1_init(&sDel1_SCA1IK6L);
  numBytes += sRPole_init(&sRPole_N0OFjrXp);
  numBytes += sPhasor_k_init(&sPhasor_nMXUQKcd, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_scq71DJt, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_fpykiDmt);
  numBytes += sRPole_init(&sRPole_6nBLLJem);
  numBytes += sDel1_init(&sDel1_QzH4r81c);
  numBytes += sPhasor_k_init(&sPhasor_kGiYDgS6, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_QgCvNMQK, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_e7InKUzV);
  numBytes += sRPole_init(&sRPole_OKgqz2aq);
  numBytes += sDel1_init(&sDel1_QFxyWlcu);
  numBytes += cVar_init_f(&cVar_vQ4si8WM, 1.0f);
  numBytes += cDelay_init(this, &cDelay_HbQmD94u, 200.0f);
  numBytes += cVar_init_f(&cVar_99UxY0E2, 0.0f);
  numBytes += cVar_init_f(&cVar_c1xY3lmG, 0.0f);
  numBytes += cRandom_init(&cRandom_0TTYUnYH, 1879728901);
  numBytes += cSlice_init(&cSlice_J279JfQF, 1, 1);
  numBytes += sVarf_init(&sVarf_XTR0IDye, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_KrCMcBoE, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_Qrz93rcb, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_VG1zGZmB, 360.0f);
  numBytes += cSlice_init(&cSlice_SyxqMXa1, 1, 1);
  numBytes += cRandom_init(&cRandom_rHvgcLex, -1318136702);
  numBytes += cDelay_init(this, &cDelay_MPYykQDF, 800.0f);
  numBytes += cVar_init_f(&cVar_kmZyeVCz, 0.0f);
  numBytes += sVarf_init(&sVarf_TcWULEJW, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_2mFPNTk4, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_SWAXZU9K, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Sa7TVNtW, 1000.0f);
  numBytes += cDelay_init(this, &cDelay_PKF9QHBp, 0.0f);
  numBytes += cBinop_init(&cBinop_a43lbBQE, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_dmOgRXPR, 1.0f); // __pow
  numBytes += cDelay_init(this, &cDelay_tuJAZqYA, 400.0f);
  numBytes += cVar_init_f(&cVar_cBAQQdX7, 200.0f);
  numBytes += cBinop_init(&cBinop_NJZTFpZb, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_FNfU5WIV, 0.0f);
  numBytes += cVar_init_f(&cVar_xWdzFAEX, 0.0f);
  numBytes += cVar_init_f(&cVar_KUxT09At, 0.0f);
  numBytes += cVar_init_f(&cVar_VwsmUbDn, 0.0f);
  numBytes += cBinop_init(&cBinop_nZAfD5Uy, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_hvWVSVR2, 400.0f);
  numBytes += sVarf_init(&sVarf_zMN6NUbx, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nbutMxvK, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_HxWBDGrp, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_tmiFLlGF, 360.0f);
  numBytes += sVarf_init(&sVarf_TmQxVSdn, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_qRQ1Z3ph, 0.0f);
  numBytes += sVarf_init(&sVarf_9qRGnpay, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_MHaZtNUo, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_rMiqfmAv, 400.0f);
  numBytes += cBinop_init(&cBinop_jQuxyDbN, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_ICfG5Wey, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fuHLNtWL, 1.0f);
  numBytes += cVar_init_f(&cVar_ATISH3NH, 0.0f);
  numBytes += sVarf_init(&sVarf_YGoa4zsA, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_ujcNXrLF, 1200.0f);
  numBytes += cBinop_init(&cBinop_WnRq06me, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_bfARnvOi, 0.0f);
  numBytes += cBinop_init(&cBinop_ePVjBG5W, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_HDhYu8y1, 0.0f);
  numBytes += cBinop_init(&cBinop_ep7StOub, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ROCqxqbV, 100.0f);
  numBytes += cVar_init_f(&cVar_MLvtLbiO, 0.0f);
  numBytes += cVar_init_f(&cVar_9sWInkYw, 0.0f);
  numBytes += sVarf_init(&sVarf_BqjHXIXn, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zhtoXP1u, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_YqkLMuHl, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_BUhK0ZZj, 360.0f);
  numBytes += cDelay_init(this, &cDelay_lkYeIplF, 600.0f);
  numBytes += sVarf_init(&sVarf_q5xycr4H, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_hcAdyJus, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_632Vttu7, 100.0f);
  numBytes += sVarf_init(&sVarf_KPtuSliq, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_LaoSFX::~Heavy_LaoSFX() {
  // nothing to free
}

HvTable *Heavy_LaoSFX::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_LaoSFX::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_V2tPiZIX_sendMessage);
      break;
    }
    case 0x9989090A: { // buttonSelect
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xXwf2PrP_sendMessage);
      break;
    }
    case 0xD27DD130: { // buttonSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fpsBQydi_sendMessage);
      break;
    }
    case 0xCC6D2A59: { // checkPointSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Wb9OeAiP_sendMessage);
      break;
    }
    case 0xD45231EE: { // checkpointPass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0nuApZLT_sendMessage);
      break;
    }
    case 0xBF8ABE63: { // currentNum
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_lfPk2Av3_sendMessage);
      break;
    }
    case 0xF8F82CF0: { // lapPass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eOOTF3Tv_sendMessage);
      break;
    }
    case 0x5F10083B: { // lapSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_N3aZ48qc_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_LaoSFX::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "checkPointSound";
        info->hash = 0xCC6D2A59;
        info->type = HvParameterType::HV_PARAM_TYPE_EVENT_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 1: {
        info->name = "buttonSound";
        info->hash = 0xD27DD130;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "lapSound";
        info->hash = 0x5F10083B;
        info->type = HvParameterType::HV_PARAM_TYPE_EVENT_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 3;
}



/*
 * Send Function Implementations
 */


void Heavy_LaoSFX::cBinop_2TFjfahs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ATISH3NH, 0, m, &cVar_ATISH3NH_sendMessage);
}

void Heavy_LaoSFX::cMsg_XdfYeexr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 66.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kmZyeVCz, 0, m, &cVar_kmZyeVCz_sendMessage);
}

void Heavy_LaoSFX::cMsg_VBbHE34T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 70.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kmZyeVCz, 0, m, &cVar_kmZyeVCz_sendMessage);
}

void Heavy_LaoSFX::cVar_vQ4si8WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Xt7HuXQf_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_TcWULEJW, m);
}

void Heavy_LaoSFX::cBinop_Xt7HuXQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vQ4si8WM, 1, m, &cVar_vQ4si8WM_sendMessage);
}

void Heavy_LaoSFX::cDelay_HbQmD94u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HbQmD94u, m);
  cMsg_bN0M8OD2_sendMessage(_c, 0, m);
  cSwitchcase_PzUHzzMS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cCast_ElvacCJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HbQmD94u, 0, m, &cDelay_HbQmD94u_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_44FdAvxF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CXhFTCJ8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CXhFTCJ8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HbQmD94u, 1, m, &cDelay_HbQmD94u_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ElvacCJT_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_CXhFTCJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HbQmD94u, 0, m, &cDelay_HbQmD94u_sendMessage);
}

void Heavy_LaoSFX::cMsg_15GNpFya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 69.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_c1xY3lmG, 0, m, &cVar_c1xY3lmG_sendMessage);
}

void Heavy_LaoSFX::cVar_99UxY0E2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_dKsSFH3R, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_uvC3rvLh, 0, m);
}

void Heavy_LaoSFX::cMsg_3AO15RYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 71.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_c1xY3lmG, 0, m, &cVar_c1xY3lmG_sendMessage);
}

void Heavy_LaoSFX::cCast_4ryzf7ZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vQ4si8WM, 0, m, &cVar_vQ4si8WM_sendMessage);
  cSwitchcase_SBv3q7ph_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_44FdAvxF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_c1xY3lmG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OCoRf0AP_sendMessage);
}

void Heavy_LaoSFX::cMsg_dZZ2toCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 400.0f);
  cSwitchcase_mEc7Pk7m_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_Sa7TVNtW, 0, m, &cVar_Sa7TVNtW_sendMessage);
}

void Heavy_LaoSFX::cMsg_VzafKwsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vQ4si8WM, 0, m, &cVar_vQ4si8WM_sendMessage);
  cSwitchcase_mEc7Pk7m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cSwitchcase_SBv3q7ph_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_J279JfQF, 0, m, &cSlice_J279JfQF_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0TTYUnYH, 0, m, &cRandom_0TTYUnYH_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cUnop_Q65DH5NK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_TZq25fZW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cRandom_0TTYUnYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_rXNJo7xu_sendMessage);
}

void Heavy_LaoSFX::cBinop_rXNJo7xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Q65DH5NK_sendMessage);
}

void Heavy_LaoSFX::cSlice_J279JfQF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_0TTYUnYH, 1, m, &cRandom_0TTYUnYH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_LaoSFX::cBinop_4O2y3CNC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KrCMcBoE, HV_BINOP_DIVIDE, 0, m, &cBinop_KrCMcBoE_sendMessage);
}

void Heavy_LaoSFX::cBinop_FCDqTrUE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_XTR0IDye, m);
}

void Heavy_LaoSFX::cMsg_m8vSg19n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_FBeNZKUQ_sendMessage);
}

void Heavy_LaoSFX::cBinop_KrCMcBoE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m8vSg19n_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_ix62SGFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_oYLNb11U_sendMessage);
}

void Heavy_LaoSFX::cBinop_oYLNb11U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_2M6riWvy_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FCDqTrUE_sendMessage);
}

void Heavy_LaoSFX::cBinop_HkMoIbct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Qrz93rcb, m);
}

void Heavy_LaoSFX::cMsg_4Ak0olHr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rRDr2fkw_sendMessage);
}

void Heavy_LaoSFX::cSystem_rRDr2fkw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KrCMcBoE, HV_BINOP_DIVIDE, 1, m, &cBinop_KrCMcBoE_sendMessage);
}

void Heavy_LaoSFX::cVar_VG1zGZmB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_l4OtYb8k_sendMessage);
}

void Heavy_LaoSFX::cBinop_2M6riWvy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_HkMoIbct_sendMessage);
}

void Heavy_LaoSFX::cBinop_FBeNZKUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ix62SGFH_sendMessage);
}

void Heavy_LaoSFX::cBinop_l4OtYb8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_4O2y3CNC_sendMessage);
}

void Heavy_LaoSFX::cCast_qEGZXn2B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VBbHE34T_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_FkmE50cC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ma5241ud_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_WRSaQdEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XdfYeexr_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_TZq25fZW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WRSaQdEe_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FkmE50cC_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qEGZXn2B_sendMessage);
      break;
    }
    default: {
      cMsg_GYNzOt6j_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cCast_Up21xAR0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dZZ2toCg_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ymUlz7Ow_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_joLyyk5B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Up21xAR0_sendMessage);
      break;
    }
    default: {
      cMsg_TIJurgXb_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cSlice_SyxqMXa1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rHvgcLex, 1, m, &cRandom_rHvgcLex_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_LaoSFX::cSwitchcase_PzUHzzMS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_SyxqMXa1, 0, m, &cSlice_SyxqMXa1_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_rHvgcLex, 0, m, &cRandom_rHvgcLex_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cRandom_rHvgcLex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_weCaJ1hi_sendMessage);
}

void Heavy_LaoSFX::cUnop_tac01CQs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_9LPXYS0i_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cBinop_weCaJ1hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tac01CQs_sendMessage);
}

void Heavy_LaoSFX::cMsg_GYNzOt6j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kmZyeVCz, 0, m, &cVar_kmZyeVCz_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_c1xY3lmG, 0, m, &cVar_c1xY3lmG_sendMessage);
}

void Heavy_LaoSFX::cCast_4D5d6nYy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_MPYykQDF, 0, m, &cDelay_MPYykQDF_sendMessage);
}

void Heavy_LaoSFX::cDelay_MPYykQDF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_MPYykQDF, m);
  cMsg_VzafKwsV_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_BnDEbbcM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3UMAynTH_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3UMAynTH_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_MPYykQDF, 1, m, &cDelay_MPYykQDF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4D5d6nYy_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_3UMAynTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_MPYykQDF, 0, m, &cDelay_MPYykQDF_sendMessage);
}

void Heavy_LaoSFX::cCast_ymUlz7Ow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BnDEbbcM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_C5xVL114_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 67.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_c1xY3lmG, 0, m, &cVar_c1xY3lmG_sendMessage);
}

void Heavy_LaoSFX::cVar_kmZyeVCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OCoRf0AP_sendMessage);
}

void Heavy_LaoSFX::cMsg_Ma5241ud_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 68.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_kmZyeVCz, 0, m, &cVar_kmZyeVCz_sendMessage);
}

void Heavy_LaoSFX::cCast_s0dSkVYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3AO15RYe_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_oOz82ely_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_15GNpFya_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_QR2K4aaH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_C5xVL114_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_9LPXYS0i_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QR2K4aaH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oOz82ely_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s0dSkVYH_sendMessage);
      break;
    }
    default: {
      cMsg_GYNzOt6j_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_bN0M8OD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  cSwitchcase_TZq25fZW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cBinop_SWAXZU9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_TtHRtFyE_sendMessage);
}

void Heavy_LaoSFX::cMsg_f14Vx8mL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PKF9QHBp, 0, m, &cDelay_PKF9QHBp_sendMessage);
}

void Heavy_LaoSFX::cBinop_MAVc0lL4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWAXZU9K, HV_BINOP_MULTIPLY, 1, m, &cBinop_SWAXZU9K_sendMessage);
}

void Heavy_LaoSFX::cVar_Sa7TVNtW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SWAXZU9K, HV_BINOP_MULTIPLY, 0, m, &cBinop_SWAXZU9K_sendMessage);
}

void Heavy_LaoSFX::cCast_1eBZ04UW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f14Vx8mL_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PKF9QHBp, 0, m, &cDelay_PKF9QHBp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ryzf7ZQ_sendMessage);
}

void Heavy_LaoSFX::cDelay_PKF9QHBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PKF9QHBp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PKF9QHBp, 0, m, &cDelay_PKF9QHBp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_4ryzf7ZQ_sendMessage);
}

void Heavy_LaoSFX::cBinop_TtHRtFyE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PKF9QHBp, 2, m, &cDelay_PKF9QHBp_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_mEc7Pk7m_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_f14Vx8mL_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_f14Vx8mL_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1eBZ04UW_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cSystem_BmRRzN77_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MAVc0lL4_sendMessage);
}

void Heavy_LaoSFX::cMsg_hjCFeROr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_BmRRzN77_sendMessage);
}

void Heavy_LaoSFX::cMsg_TIJurgXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_vQ4si8WM, 0, m, &cVar_vQ4si8WM_sendMessage);
  cSwitchcase_mEc7Pk7m_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cBinop_OCoRf0AP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_WQX6NVIw_sendMessage);
}

void Heavy_LaoSFX::cBinop_y4TV9jQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_99UxY0E2, 0, m, &cVar_99UxY0E2_sendMessage);
}

void Heavy_LaoSFX::cMsg_5DSL3Jcn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a43lbBQE, HV_BINOP_POW, 0, m, &cBinop_a43lbBQE_sendMessage);
}

void Heavy_LaoSFX::cBinop_a43lbBQE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_y4TV9jQI_sendMessage);
}

void Heavy_LaoSFX::cBinop_WQX6NVIw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a43lbBQE, HV_BINOP_POW, 1, m, &cBinop_a43lbBQE_sendMessage);
  cMsg_5DSL3Jcn_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_N3aZ48qc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IRLUp2K7_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_rv2WZcL9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_dYw9MoJ5_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_Wb9OeAiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_yqcP05vA_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_tGe7xAIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_qRQ1Z3ph, 0, m, &cVar_qRQ1Z3ph_sendMessage);
}

void Heavy_LaoSFX::cReceive_V2tPiZIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_hjCFeROr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Sa7TVNtW, 0, m, &cVar_Sa7TVNtW_sendMessage);
  cMsg_4Ak0olHr_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VG1zGZmB, 0, m, &cVar_VG1zGZmB_sendMessage);
  cMsg_DiajGLNe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ROCqxqbV, 0, m, &cVar_ROCqxqbV_sendMessage);
  cMsg_pJxilcPF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BUhK0ZZj, 0, m, &cVar_BUhK0ZZj_sendMessage);
  cMsg_SiaaU1ay_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tmiFLlGF, 0, m, &cVar_tmiFLlGF_sendMessage);
  cMsg_Ozi7ZMmD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cBAQQdX7, 0, m, &cVar_cBAQQdX7_sendMessage);
  cMsg_KXDBfInD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_632Vttu7, 0, m, &cVar_632Vttu7_sendMessage);
  cMsg_m05ZzpDB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rMiqfmAv, 0, m, &cVar_rMiqfmAv_sendMessage);
}

void Heavy_LaoSFX::cReceive_eOOTF3Tv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_49Ta75ye_sendMessage);
  cMsg_tGe7xAIg_sendMessage(_c, 0, m);
  cMsg_tGe7xAIg_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_6JSaGcKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "pd");
  msg_setSymbol(m, 1, "dsp");
  msg_setElementToFrom(m, 2, n, 0);
}

void Heavy_LaoSFX::cSend_IRLUp2K7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_eOOTF3Tv_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_dmOgRXPR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_mE2otge3_sendMessage);
}

void Heavy_LaoSFX::cBinop_UHiodyLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmOgRXPR, HV_BINOP_POW, 1, m, &cBinop_dmOgRXPR_sendMessage);
  cMsg_VnGjTWqD_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_1J4LuFf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_UHiodyLk_sendMessage);
}

void Heavy_LaoSFX::cBinop_mE2otge3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VwsmUbDn, 0, m, &cVar_VwsmUbDn_sendMessage);
}

void Heavy_LaoSFX::cMsg_VnGjTWqD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dmOgRXPR, HV_BINOP_POW, 0, m, &cBinop_dmOgRXPR_sendMessage);
}

void Heavy_LaoSFX::cMsg_cG6apQj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_tuJAZqYA, 0, m, &cDelay_tuJAZqYA_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_6TFZ8Q7O_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_cG6apQj6_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_cG6apQj6_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_tuJAZqYA, 1, m, &cDelay_tuJAZqYA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1oxbsqO8_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cDelay_tuJAZqYA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_tuJAZqYA, m);
  cMsg_xd3Svnfp_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_1oxbsqO8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_tuJAZqYA, 0, m, &cDelay_tuJAZqYA_sendMessage);
}

void Heavy_LaoSFX::cVar_cBAQQdX7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NJZTFpZb, HV_BINOP_MULTIPLY, 0, m, &cBinop_NJZTFpZb_sendMessage);
}

void Heavy_LaoSFX::cMsg_q7Q2NZTC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNfU5WIV, 0, m, &cDelay_FNfU5WIV_sendMessage);
}

void Heavy_LaoSFX::cBinop_ow2QB6wg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NJZTFpZb, HV_BINOP_MULTIPLY, 1, m, &cBinop_NJZTFpZb_sendMessage);
}

void Heavy_LaoSFX::cCast_nhUjqef7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q7Q2NZTC_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNfU5WIV, 0, m, &cDelay_FNfU5WIV_sendMessage);
  cMsg_KU9OCuIr_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_RmVyHEJ3_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_q7Q2NZTC_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_q7Q2NZTC_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nhUjqef7_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cBinop_NJZTFpZb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_81POk6Ws_sendMessage);
}

void Heavy_LaoSFX::cBinop_81POk6Ws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNfU5WIV, 2, m, &cDelay_FNfU5WIV_sendMessage);
}

void Heavy_LaoSFX::cDelay_FNfU5WIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FNfU5WIV, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FNfU5WIV, 0, m, &cDelay_FNfU5WIV_sendMessage);
  cMsg_KU9OCuIr_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_Ozi7ZMmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L13nANhC_sendMessage);
}

void Heavy_LaoSFX::cSystem_L13nANhC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ow2QB6wg_sendMessage);
}

void Heavy_LaoSFX::cMsg_NXgvcI6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_RmVyHEJ3_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_xWdzFAEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nZAfD5Uy, HV_BINOP_ADD, 1, m, &cBinop_nZAfD5Uy_sendMessage);
}

void Heavy_LaoSFX::cMsg_xd3Svnfp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fpykiDmt, 0, m, NULL);
}

void Heavy_LaoSFX::cSend_sVGLXSeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lfPk2Av3_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_KUxT09At_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_sVGLXSeK_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1J4LuFf5_sendMessage);
}

void Heavy_LaoSFX::cMsg_KU9OCuIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nZAfD5Uy, HV_BINOP_ADD, 0, m, &cBinop_nZAfD5Uy_sendMessage);
}

void Heavy_LaoSFX::cSend_Hpo8uNyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lfPk2Av3_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_HwQzQtB7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  msg_setFloat(m, 1, 200.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_fpykiDmt, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_RT2C0ZUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 71.0f);
  cSend_Hpo8uNyc_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_VwsmUbDn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_nMXUQKcd, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_scq71DJt, 0, m);
}

void Heavy_LaoSFX::cBinop_nZAfD5Uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KUxT09At, 0, m, &cVar_KUxT09At_sendMessage);
}

void Heavy_LaoSFX::cDelay_hvWVSVR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hvWVSVR2, m);
  cMsg_NXgvcI6A_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_4vbqRG1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hvWVSVR2, 0, m, &cDelay_hvWVSVR2_sendMessage);
}

void Heavy_LaoSFX::cCast_QoMehBou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hvWVSVR2, 0, m, &cDelay_hvWVSVR2_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_FcKQyncI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_4vbqRG1O_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_4vbqRG1O_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hvWVSVR2, 1, m, &cDelay_hvWVSVR2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QoMehBou_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_A6ZLOGSA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_TSLGcSrP_sendMessage);
}

void Heavy_LaoSFX::cBinop_0vXAvrGq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bSLs538U_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_RNlHETou_sendMessage);
}

void Heavy_LaoSFX::cBinop_fJST91UF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_0vXAvrGq_sendMessage);
}

void Heavy_LaoSFX::cBinop_RNlHETou_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nbutMxvK, m);
}

void Heavy_LaoSFX::cBinop_TSLGcSrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_fJST91UF_sendMessage);
}

void Heavy_LaoSFX::cBinop_HxWBDGrp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_A6ZLOGSA_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_efhI7UqO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_fKhtgHSB_sendMessage);
}

void Heavy_LaoSFX::cBinop_Jozqu1dA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zMN6NUbx, m);
}

void Heavy_LaoSFX::cBinop_bSLs538U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_Jozqu1dA_sendMessage);
}

void Heavy_LaoSFX::cMsg_SiaaU1ay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mfA2ELkH_sendMessage);
}

void Heavy_LaoSFX::cSystem_mfA2ELkH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxWBDGrp, HV_BINOP_DIVIDE, 1, m, &cBinop_HxWBDGrp_sendMessage);
}

void Heavy_LaoSFX::cVar_tmiFLlGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_efhI7UqO_sendMessage);
}

void Heavy_LaoSFX::cBinop_fKhtgHSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HxWBDGrp, HV_BINOP_DIVIDE, 0, m, &cBinop_HxWBDGrp_sendMessage);
}

void Heavy_LaoSFX::cCast_JUdqJgxL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RT2C0ZUm_sendMessage(_c, 0, m);
  cSwitchcase_RmVyHEJ3_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_FcKQyncI_onMessage(_c, NULL, 0, m, NULL);
  cMsg_HwQzQtB7_sendMessage(_c, 0, m);
  cSwitchcase_6TFZ8Q7O_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cSend_dYw9MoJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_xXwf2PrP_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_kkpAZLBD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_yqcP05vA_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_xXwf2PrP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_joLyyk5B_onMessage(_c, NULL, 0, m, NULL);
  cMsg_tGe7xAIg_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_qRQ1Z3ph_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_2TFjfahs_sendMessage);
}

void Heavy_LaoSFX::cBinop_jyxNaN0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_s3Y6VXal_sendMessage);
}

void Heavy_LaoSFX::cMsg_PrrINNQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_PlHYGxNT_sendMessage);
}

void Heavy_LaoSFX::cBinop_Do29Z3Ck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQuxyDbN, HV_BINOP_DIVIDE, 0, m, &cBinop_jQuxyDbN_sendMessage);
}

void Heavy_LaoSFX::cVar_rMiqfmAv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_yg4R8Tif_sendMessage);
}

void Heavy_LaoSFX::cBinop_s3Y6VXal_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_9qRGnpay, m);
}

void Heavy_LaoSFX::cSystem_Et6FPAae_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jQuxyDbN, HV_BINOP_DIVIDE, 1, m, &cBinop_jQuxyDbN_sendMessage);
}

void Heavy_LaoSFX::cMsg_m05ZzpDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Et6FPAae_sendMessage);
}

void Heavy_LaoSFX::cBinop_jQuxyDbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PrrINNQL_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_PlHYGxNT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_swu2UvMI_sendMessage);
}

void Heavy_LaoSFX::cBinop_HcXlI8KL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MHaZtNUo, m);
}

void Heavy_LaoSFX::cBinop_yg4R8Tif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Do29Z3Ck_sendMessage);
}

void Heavy_LaoSFX::cBinop_swu2UvMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_hpmAMlGx_sendMessage);
}

void Heavy_LaoSFX::cBinop_hpmAMlGx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jyxNaN0v_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HcXlI8KL_sendMessage);
}

void Heavy_LaoSFX::cReceive_0nuApZLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JUdqJgxL_sendMessage);
}

void Heavy_LaoSFX::cReceive_fpsBQydi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dYw9MoJ5_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSend_yqcP05vA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0nuApZLT_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_Cjwu0mEK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fuHLNtWL, 1, m, &cVar_fuHLNtWL_sendMessage);
}

void Heavy_LaoSFX::cVar_fuHLNtWL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Cjwu0mEK_sendMessage);
  cMsg_6JSaGcKt_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_ATISH3NH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ICfG5Wey, m);
}

void Heavy_LaoSFX::cMsg_fsi5YPoZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  msg_setFloat(m, 1, 600.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_e7InKUzV, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_6oAkdZYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65.0f);
  cSend_9whfHyAd_sendMessage(_c, 0, m);
  cSwitchcase_3cwCCiUd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cSwitchcase_sTlHhTiC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_9TQ9qBnv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_9TQ9qBnv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ujcNXrLF, 1, m, &cDelay_ujcNXrLF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mPRPSkpK_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cDelay_ujcNXrLF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ujcNXrLF, m);
  cMsg_fYM9JCdo_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_mPRPSkpK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujcNXrLF, 0, m, &cDelay_ujcNXrLF_sendMessage);
}

void Heavy_LaoSFX::cMsg_9TQ9qBnv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ujcNXrLF, 0, m, &cDelay_ujcNXrLF_sendMessage);
}

void Heavy_LaoSFX::cSend_aERgcNkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lfPk2Av3_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_fYM9JCdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_e7InKUzV, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_O4QHOSkx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WnRq06me, HV_BINOP_POW, 0, m, &cBinop_WnRq06me_sendMessage);
}

void Heavy_LaoSFX::cBinop_iUr9sJZK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_kcTBUm3m_sendMessage);
}

void Heavy_LaoSFX::cBinop_kcTBUm3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WnRq06me, HV_BINOP_POW, 1, m, &cBinop_WnRq06me_sendMessage);
  cMsg_O4QHOSkx_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_WnRq06me_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_JkiZilA0_sendMessage);
}

void Heavy_LaoSFX::cBinop_JkiZilA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MLvtLbiO, 0, m, &cVar_MLvtLbiO_sendMessage);
}

void Heavy_LaoSFX::cVar_bfARnvOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aERgcNkP_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_iUr9sJZK_sendMessage);
}

void Heavy_LaoSFX::cSend_9whfHyAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_lfPk2Av3_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_ePVjBG5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bfARnvOi, 0, m, &cVar_bfARnvOi_sendMessage);
}

void Heavy_LaoSFX::cCast_49Ta75ye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6oAkdZYq_sendMessage(_c, 0, m);
  cSwitchcase_n4nVXVYQ_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_sTlHhTiC_onMessage(_c, NULL, 0, m, NULL);
  cMsg_fsi5YPoZ_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_OXlWwjzb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ePVjBG5W, HV_BINOP_ADD, 0, m, &cBinop_ePVjBG5W_sendMessage);
}

void Heavy_LaoSFX::cMsg_DiajGLNe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_kXPj9EVv_sendMessage);
}

void Heavy_LaoSFX::cSystem_kXPj9EVv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4K3Wbmg0_sendMessage);
}

void Heavy_LaoSFX::cDelay_HDhYu8y1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HDhYu8y1, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HDhYu8y1, 0, m, &cDelay_HDhYu8y1_sendMessage);
  cMsg_OXlWwjzb_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_ep7StOub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_cCIIuBb5_sendMessage);
}

void Heavy_LaoSFX::cMsg_opnJZp2b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HDhYu8y1, 0, m, &cDelay_HDhYu8y1_sendMessage);
}

void Heavy_LaoSFX::cBinop_4K3Wbmg0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ep7StOub, HV_BINOP_MULTIPLY, 1, m, &cBinop_ep7StOub_sendMessage);
}

void Heavy_LaoSFX::cBinop_cCIIuBb5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HDhYu8y1, 2, m, &cDelay_HDhYu8y1_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_3cwCCiUd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_opnJZp2b_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_opnJZp2b_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nMmAlImj_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cVar_ROCqxqbV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ep7StOub, HV_BINOP_MULTIPLY, 0, m, &cBinop_ep7StOub_sendMessage);
}

void Heavy_LaoSFX::cCast_nMmAlImj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_opnJZp2b_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_HDhYu8y1, 0, m, &cDelay_HDhYu8y1_sendMessage);
  cMsg_OXlWwjzb_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_dKEP7D2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_3cwCCiUd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_MLvtLbiO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_kGiYDgS6, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_QgCvNMQK, 0, m);
}

void Heavy_LaoSFX::cVar_9sWInkYw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ePVjBG5W, HV_BINOP_ADD, 1, m, &cBinop_ePVjBG5W_sendMessage);
}

void Heavy_LaoSFX::cBinop_B6ByjLtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zhtoXP1u, m);
}

void Heavy_LaoSFX::cBinop_5j4faBIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_nI0SQ9Bs_sendMessage);
}

void Heavy_LaoSFX::cBinop_CgSwakJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_76HqqPXN_sendMessage);
}

void Heavy_LaoSFX::cBinop_76HqqPXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_eKlO8Ikk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_uiH3fBTf_sendMessage);
}

void Heavy_LaoSFX::cMsg_2Dn2Cax0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_M2S75mJ9_sendMessage);
}

void Heavy_LaoSFX::cBinop_uiH3fBTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BqjHXIXn, m);
}

void Heavy_LaoSFX::cBinop_M2S75mJ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_CgSwakJc_sendMessage);
}

void Heavy_LaoSFX::cBinop_YqkLMuHl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2Dn2Cax0_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_BUhK0ZZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_5j4faBIs_sendMessage);
}

void Heavy_LaoSFX::cBinop_nI0SQ9Bs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YqkLMuHl, HV_BINOP_DIVIDE, 0, m, &cBinop_YqkLMuHl_sendMessage);
}

void Heavy_LaoSFX::cSystem_NcP1pCEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YqkLMuHl, HV_BINOP_DIVIDE, 1, m, &cBinop_YqkLMuHl_sendMessage);
}

void Heavy_LaoSFX::cMsg_pJxilcPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NcP1pCEL_sendMessage);
}

void Heavy_LaoSFX::cBinop_eKlO8Ikk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_B6ByjLtq_sendMessage);
}

void Heavy_LaoSFX::cCast_oFNldEA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkYeIplF, 0, m, &cDelay_lkYeIplF_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_n4nVXVYQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_M1CY1D2U_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_M1CY1D2U_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_lkYeIplF, 1, m, &cDelay_lkYeIplF_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oFNldEA1_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_M1CY1D2U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_lkYeIplF, 0, m, &cDelay_lkYeIplF_sendMessage);
}

void Heavy_LaoSFX::cDelay_lkYeIplF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_lkYeIplF, m);
  cMsg_dKEP7D2R_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_JZ9YR7dG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_G5Djiol3_sendMessage);
}

void Heavy_LaoSFX::cBinop_G5Djiol3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_OcZvGAJb_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_q5xycr4H, m);
}

void Heavy_LaoSFX::cMsg_KXDBfInD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hAMwKGfY_sendMessage);
}

void Heavy_LaoSFX::cSystem_hAMwKGfY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Q26AeMFD_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_s2BVG576_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcAdyJus, HV_BINOP_MULTIPLY, 1, m, &cBinop_hcAdyJus_sendMessage);
}

void Heavy_LaoSFX::cMsg_Q26AeMFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_s2BVG576_sendMessage);
}

void Heavy_LaoSFX::cBinop_hcAdyJus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_JZ9YR7dG_sendMessage);
}

void Heavy_LaoSFX::cVar_632Vttu7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hcAdyJus, HV_BINOP_MULTIPLY, 0, m, &cBinop_hcAdyJus_sendMessage);
}

void Heavy_LaoSFX::cBinop_OcZvGAJb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KPtuSliq, m);
}

void Heavy_LaoSFX::cReceive_lfPk2Av3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9sWInkYw, 0, m, &cVar_9sWInkYw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_xWdzFAEX, 0, m, &cVar_xWdzFAEX_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_LaoSFX::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_uvC3rvLh, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_dKsSFH3R, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_TcWULEJW, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_XTR0IDye, VOf(Bf2));
    __hv_rpole_f(&sRPole_9JsfHKg5, VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_lMMYin4J, VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Qrz93rcb, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f);
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_2mFPNTk4, VIf(Bf0));
    __hv_varread_f(&sVarf_2mFPNTk4, VOf(Bf0));
    __hv_varread_f(&sVarf_TmQxVSdn, VOf(Bf2));
    __hv_varread_f(&sVarf_YGoa4zsA, VOf(Bf4));
    __hv_add_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_MHaZtNUo, VOf(Bf0));
    __hv_rpole_f(&sRPole_OWzFh378, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_SCA1IK6L, VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_9qRGnpay, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_q5xycr4H, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_KPtuSliq, VOf(Bf0));
    __hv_rpole_f(&sRPole_N0OFjrXp, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_ICfG5Wey, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));
    __hv_phasor_k_f(&sPhasor_nMXUQKcd, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_scq71DJt, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_fpykiDmt, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_nbutMxvK, VOf(Bf1));
    __hv_rpole_f(&sRPole_6nBLLJem, VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QzH4r81c, VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zMN6NUbx, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_f(&sVarf_TmQxVSdn, VIf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_kGiYDgS6, VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_QgCvNMQK, VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_e7InKUzV, VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_BqjHXIXn, VOf(Bf0));
    __hv_rpole_f(&sRPole_OKgqz2aq, VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_QFxyWlcu, VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_zhtoXP1u, VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_YGoa4zsA, VIf(Bf0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_LaoSFX::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_LaoSFX::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
