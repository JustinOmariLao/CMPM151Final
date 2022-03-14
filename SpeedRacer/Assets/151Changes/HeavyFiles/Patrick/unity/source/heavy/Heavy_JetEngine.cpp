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

#include "Heavy_JetEngine.hpp"

#define Context(_c) reinterpret_cast<Heavy_JetEngine *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_JetEngine_new(double sampleRate) {
    return new Heavy_JetEngine(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_JetEngine_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_JetEngine(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_JetEngine::Heavy_JetEngine(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sRPole_init(&sRPole_7Pn0JOhJ);
  numBytes += sPhasor_init(&sPhasor_OAi9Juy8, sampleRate);
  numBytes += sPhasor_init(&sPhasor_Xz5F7p8I, sampleRate);
  numBytes += sPhasor_init(&sPhasor_qN45Zo9Z, sampleRate);
  numBytes += sPhasor_init(&sPhasor_ycn3vJTN, sampleRate);
  numBytes += sPhasor_init(&sPhasor_qxnOtsaK, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_nHGlVm6G, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sCPole_init(&sCPole_owL7gz17);
  numBytes += sRPole_init(&sRPole_xNmz4x6S);
  numBytes += sDel1_init(&sDel1_Z3ClEiOM);
  numBytes += sCPole_init(&sCPole_JFqELqD8);
  numBytes += sRPole_init(&sRPole_LPEzeG7O);
  numBytes += cBinop_init(&cBinop_TxzhM7a1, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Fo93yNMq, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_PU0aXk9T, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TltFakeI, 11000.0f);
  numBytes += sVarf_init(&sVarf_L3Wbp57T, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_MtaijPmX, 0.0f);
  numBytes += sVarf_init(&sVarf_yrxTiAuT, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_F4GlrLrm, 0.2f);
  numBytes += sVarf_init(&sVarf_HFMoBDuP, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_lTuKWW21, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_CxckfKQu, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Po8hx7C0, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_142x1T4v, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_o9nRDfFi, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_13T21vtZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LZf1F0s6, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_ojC8mgzD, 0.0f);
  numBytes += sVarf_init(&sVarf_CPU2UNWB, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_lesM5uQC, false);
  numBytes += sVarf_init(&sVarf_Q6gevBZJ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_YCXGI3Tt, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_h5acc6vD, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ClSZQd61, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mw2tu7Aa, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_aq7dwIl2, 0.5f);
  numBytes += cVar_init_f(&cVar_YYsu6tMK, 8000.0f);
  numBytes += cBinop_init(&cBinop_3vm71CM0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Un1NCTT9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QdckfkJM, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_sjBoqMWa, 120.0f);
  numBytes += sVarf_init(&sVarf_0rGZKPMD, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LbMdg2Hk, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_uZbjIcTW, 0.0f); // __div
  numBytes += sVari_init(&sVari_iggD1EbF, 0, 0, false);
  numBytes += cSlice_init(&cSlice_NGVk8N3j, 1, 1);
  numBytes += cRandom_init(&cRandom_wpCa65fw, -781112574);
  numBytes += sVarf_init(&sVarf_BoGX1Jlf, 0.0f, 0.0f, false);
  numBytes += cIf_init(&cIf_yxUTA79P, false);
  numBytes += sVarf_init(&sVarf_63PZek92, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_bNR3n0Ut, 0.0f);
  numBytes += sVarf_init(&sVarf_6I0uPLR6, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_iMU0nxw5, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_JetEngine::~Heavy_JetEngine() {
  // nothing to free
}

HvTable *Heavy_JetEngine::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_JetEngine::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QejpWXmk_sendMessage);
      break;
    }
    case 0xB2D63F95: { // sped
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rZAP9mtN_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_JetEngine::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "sped";
        info->hash = 0xB2D63F95;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
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
  return 1;
}



/*
 * Send Function Implementations
 */


void Heavy_JetEngine::cReceive_rZAP9mtN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MtaijPmX, 0, m, &cVar_MtaijPmX_sendMessage);
}

void Heavy_JetEngine::cBinop_DJGQHJy9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_l8QgBu8A_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Fo93yNMq, m);
}

void Heavy_JetEngine::cBinop_AvBW8kkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DJGQHJy9_sendMessage);
}

void Heavy_JetEngine::cBinop_l8QgBu8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_PU0aXk9T, m);
}

void Heavy_JetEngine::cBinop_I0xoU4uv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TxzhM7a1, HV_BINOP_MULTIPLY, 1, m, &cBinop_TxzhM7a1_sendMessage);
}

void Heavy_JetEngine::cMsg_c2mc9rTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hE0GjciV_sendMessage);
}

void Heavy_JetEngine::cSystem_hE0GjciV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Hgg1slCf_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cBinop_TxzhM7a1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AvBW8kkP_sendMessage);
}

void Heavy_JetEngine::cMsg_Hgg1slCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_I0xoU4uv_sendMessage);
}

void Heavy_JetEngine::cVar_TltFakeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TxzhM7a1, HV_BINOP_MULTIPLY, 0, m, &cBinop_TxzhM7a1_sendMessage);
}

void Heavy_JetEngine::cVar_MtaijPmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_L3Wbp57T, m);
}

void Heavy_JetEngine::cBinop_AWyaziiJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_yrxTiAuT, m);
}

void Heavy_JetEngine::cBinop_UV0200x1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_AWyaziiJ_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_HFMoBDuP, m);
}

void Heavy_JetEngine::cBinop_K9cI2Jx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_UV0200x1_sendMessage);
}

void Heavy_JetEngine::cVar_F4GlrLrm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lTuKWW21, HV_BINOP_MULTIPLY, 0, m, &cBinop_lTuKWW21_sendMessage);
}

void Heavy_JetEngine::cSystem_tf8nCM20_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bNoibraJ_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cMsg_zXLKdX02_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_tf8nCM20_sendMessage);
}

void Heavy_JetEngine::cMsg_bNoibraJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_UfcJZ40W_sendMessage);
}

void Heavy_JetEngine::cBinop_lTuKWW21_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_K9cI2Jx2_sendMessage);
}

void Heavy_JetEngine::cBinop_UfcJZ40W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lTuKWW21, HV_BINOP_MULTIPLY, 1, m, &cBinop_lTuKWW21_sendMessage);
}

void Heavy_JetEngine::cMsg_9sSD298m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 4495.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_CxckfKQu, m);
}

void Heavy_JetEngine::cMsg_kDA9Z7ZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 5588.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_142x1T4v, m);
}

void Heavy_JetEngine::cMsg_cWxAJXyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3097.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Po8hx7C0, m);
}

void Heavy_JetEngine::cMsg_AOGsQO0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 7471.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_13T21vtZ, m);
}

void Heavy_JetEngine::cMsg_wvBMUTZD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 11000.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_o9nRDfFi, m);
}

void Heavy_JetEngine::cMsg_BrVnUGak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_8a1aqSYd_sendMessage);
}

void Heavy_JetEngine::cBinop_YTEE1s6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LZf1F0s6, m);
}

void Heavy_JetEngine::cVar_ojC8mgzD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_5vQ1i64U_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_lesM5uQC, 0, m, &cIf_lesM5uQC_sendMessage);
}

void Heavy_JetEngine::cIf_lesM5uQC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_sFP0ABjk_sendMessage(_c, 0, m);
      cMsg_d5OCQe5g_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_BrVnUGak_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_VZbCyAZQ_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_Q6gevBZJ, m);
      break;
    }
    default: return;
  }
}

void Heavy_JetEngine::cBinop_5vQ1i64U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_lesM5uQC, 1, m, &cIf_lesM5uQC_sendMessage);
}

void Heavy_JetEngine::cMsg_RE9SjrYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_TFabaYeq_sendMessage);
}

void Heavy_JetEngine::cBinop_CPKVzJya_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_CPU2UNWB, m);
}

void Heavy_JetEngine::cBinop_VZbCyAZQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RE9SjrYN_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cBinop_TFabaYeq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_iprfDJGs_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cMsg_eBqhjNzd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_To4fhSzU_sendMessage);
}

void Heavy_JetEngine::cSystem_To4fhSzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SDDt9R3S_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cMsg_SDDt9R3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_YTEE1s6w_sendMessage);
}

void Heavy_JetEngine::cMsg_sFP0ABjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_VZbCyAZQ_sendMessage);
}

void Heavy_JetEngine::cMsg_iprfDJGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_CPKVzJya_sendMessage);
}

void Heavy_JetEngine::cBinop_8a1aqSYd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_YCXGI3Tt, m);
}

void Heavy_JetEngine::cMsg_d5OCQe5g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_YCXGI3Tt, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q6gevBZJ, m);
}

void Heavy_JetEngine::cBinop_h5acc6vD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mw2tu7Aa, HV_BINOP_MULTIPLY, 1, m, &cBinop_mw2tu7Aa_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_ShwXnXpl_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3vm71CM0, HV_BINOP_DIVIDE, 0, m, &cBinop_3vm71CM0_sendMessage);
}

void Heavy_JetEngine::cBinop_ClSZQd61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GUT6X0Be_sendMessage);
}

void Heavy_JetEngine::cBinop_YHuy1mpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ClSZQd61, HV_BINOP_MULTIPLY, 1, m, &cBinop_ClSZQd61_sendMessage);
}

void Heavy_JetEngine::cBinop_9vCUqGwt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_htKzADUv_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ClSZQd61, HV_BINOP_MULTIPLY, 0, m, &cBinop_ClSZQd61_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mw2tu7Aa, HV_BINOP_MULTIPLY, 0, m, &cBinop_mw2tu7Aa_sendMessage);
}

void Heavy_JetEngine::cUnop_ShwXnXpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_YHuy1mpy_sendMessage);
}

void Heavy_JetEngine::cBinop_mw2tu7Aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QdckfkJM, HV_BINOP_ADD, 1, m, &cBinop_QdckfkJM_sendMessage);
}

void Heavy_JetEngine::cBinop_W3zrsm4Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h5acc6vD, HV_BINOP_DIVIDE, 0, m, &cBinop_h5acc6vD_sendMessage);
}

void Heavy_JetEngine::cVar_aq7dwIl2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_8QTFYI0I_sendMessage);
}

void Heavy_JetEngine::cBinop_VKc7JET2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_9vCUqGwt_sendMessage);
}

void Heavy_JetEngine::cBinop_htKzADUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OyKOwSX3_sendMessage);
}

void Heavy_JetEngine::cBinop_zqeJe1mz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VKc7JET2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QdckfkJM, HV_BINOP_ADD, 0, m, &cBinop_QdckfkJM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_I8N17tZT_sendMessage);
}

void Heavy_JetEngine::cVar_YYsu6tMK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_W3zrsm4Z_sendMessage);
}

void Heavy_JetEngine::cBinop_GUT6X0Be_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nHGlVm6G, 4, m);
}

void Heavy_JetEngine::cBinop_3vm71CM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zqeJe1mz_sendMessage);
}

void Heavy_JetEngine::cMsg_yi5mv6Ox_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_CSa77ytw_sendMessage);
}

void Heavy_JetEngine::cSystem_CSa77ytw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h5acc6vD, HV_BINOP_DIVIDE, 1, m, &cBinop_h5acc6vD_sendMessage);
}

void Heavy_JetEngine::cCast_Q8ouVVWJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YYsu6tMK, 0, m, &cVar_YYsu6tMK_sendMessage);
}

void Heavy_JetEngine::cBinop_WfSAf1GT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nHGlVm6G, 5, m);
}

void Heavy_JetEngine::cBinop_Un1NCTT9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nHGlVm6G, 1, m);
}

void Heavy_JetEngine::cBinop_I8N17tZT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Un1NCTT9, HV_BINOP_MULTIPLY, 0, m, &cBinop_Un1NCTT9_sendMessage);
}

void Heavy_JetEngine::cBinop_8QTFYI0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3vm71CM0, HV_BINOP_DIVIDE, 1, m, &cBinop_3vm71CM0_sendMessage);
}

void Heavy_JetEngine::cBinop_QdckfkJM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Un1NCTT9, HV_BINOP_MULTIPLY, 1, m, &cBinop_Un1NCTT9_sendMessage);
}

void Heavy_JetEngine::cBinop_OyKOwSX3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WfSAf1GT_sendMessage);
}

void Heavy_JetEngine::cVar_sjBoqMWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ztwPWsRo_sendMessage);
}

void Heavy_JetEngine::cBinop_fh3yuAD5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_i7j3OeaM_sendMessage);
}

void Heavy_JetEngine::cMsg_8Ha1e9Z7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_fh3yuAD5_sendMessage);
}

void Heavy_JetEngine::cBinop_2vENFo7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZbjIcTW, HV_BINOP_DIVIDE, 0, m, &cBinop_uZbjIcTW_sendMessage);
}

void Heavy_JetEngine::cBinop_cSAzFE9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0rGZKPMD, m);
}

void Heavy_JetEngine::cBinop_uZbjIcTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_8Ha1e9Z7_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cBinop_edTN9rLU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_f0HRlyWF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_TgjiUlm7_sendMessage);
}

void Heavy_JetEngine::cBinop_i7j3OeaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_edTN9rLU_sendMessage);
}

void Heavy_JetEngine::cBinop_f0HRlyWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_cSAzFE9R_sendMessage);
}

void Heavy_JetEngine::cMsg_HWthRCs8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hnojqRtQ_sendMessage);
}

void Heavy_JetEngine::cSystem_hnojqRtQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZbjIcTW, HV_BINOP_DIVIDE, 1, m, &cBinop_uZbjIcTW_sendMessage);
}

void Heavy_JetEngine::cBinop_TgjiUlm7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LbMdg2Hk, m);
}

void Heavy_JetEngine::cBinop_ztwPWsRo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_2vENFo7O_sendMessage);
}

void Heavy_JetEngine::cMsg_jIXQBo2h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.6f);
  cVar_onMessage(_c, &Context(_c)->cVar_bNR3n0Ut, 0, m, &cVar_bNR3n0Ut_sendMessage);
}

void Heavy_JetEngine::cMsg_DSLxASUK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_iggD1EbF, m);
}

void Heavy_JetEngine::cBinop_XOIBkxGV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_smRmtGDy_sendMessage);
}

void Heavy_JetEngine::cSwitchcase_X3qX5ZLr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NGVk8N3j, 0, m, &cSlice_NGVk8N3j_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wpCa65fw, 0, m, &cRandom_wpCa65fw_sendMessage);
      break;
    }
  }
}

void Heavy_JetEngine::cUnop_smRmtGDy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DSLxASUK_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cSlice_NGVk8N3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_wpCa65fw, 1, m, &cRandom_wpCa65fw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_JetEngine::cRandom_wpCa65fw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_XOIBkxGV_sendMessage);
}

void Heavy_JetEngine::cBinop_jajrFXIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RlUAwn2R_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cBinop_Od1XmLTi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aiT9iVDv_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cMsg_USGL7vwV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jajrFXIm_sendMessage);
}

void Heavy_JetEngine::cMsg_DoxHAHTl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_v99i3Dvu_sendMessage);
}

void Heavy_JetEngine::cMsg_RlUAwn2R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_Od1XmLTi_sendMessage);
}

void Heavy_JetEngine::cBinop_1VehYUS3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_BoGX1Jlf, m);
}

void Heavy_JetEngine::cBinop_H5NWu5Xq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_yxUTA79P, 1, m, &cIf_yxUTA79P_sendMessage);
}

void Heavy_JetEngine::cIf_yxUTA79P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_USGL7vwV_sendMessage(_c, 0, m);
      cMsg_1KEnOcVG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_DoxHAHTl_sendMessage(_c, 0, m);
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 2.0f, 0, m, &cBinop_jajrFXIm_sendMessage);
      sVarf_onMessage(_c, &Context(_c)->sVarf_iMU0nxw5, m);
      break;
    }
    default: return;
  }
}

void Heavy_JetEngine::cMsg_1KEnOcVG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  sVarf_onMessage(_c, &Context(_c)->sVarf_6I0uPLR6, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_iMU0nxw5, m);
}

void Heavy_JetEngine::cSystem_KsrnKLxF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jXHO03mk_sendMessage(_c, 0, m);
}

void Heavy_JetEngine::cMsg_eMIv4HVg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KsrnKLxF_sendMessage);
}

void Heavy_JetEngine::cMsg_aiT9iVDv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_inyubKif_sendMessage);
}

void Heavy_JetEngine::cMsg_jXHO03mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_1VehYUS3_sendMessage);
}

void Heavy_JetEngine::cBinop_v99i3Dvu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6I0uPLR6, m);
}

void Heavy_JetEngine::cVar_bNR3n0Ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1e-05f, 0, m, &cBinop_H5NWu5Xq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_yxUTA79P, 0, m, &cIf_yxUTA79P_sendMessage);
}

void Heavy_JetEngine::cBinop_inyubKif_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_63PZek92, m);
}

void Heavy_JetEngine::cMsg_3JqVE1WC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ojC8mgzD, 0, m, &cVar_ojC8mgzD_sendMessage);
}

void Heavy_JetEngine::cReceive_QejpWXmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_X3qX5ZLr_onMessage(_c, NULL, 0, m, NULL);
  cMsg_HWthRCs8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sjBoqMWa, 0, m, &cVar_sjBoqMWa_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aq7dwIl2, 0, m, &cVar_aq7dwIl2_sendMessage);
  cMsg_yi5mv6Ox_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_YYsu6tMK, 0, m, &cVar_YYsu6tMK_sendMessage);
  cMsg_eBqhjNzd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ojC8mgzD, 0, m, &cVar_ojC8mgzD_sendMessage);
  cMsg_eMIv4HVg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_bNR3n0Ut, 0, m, &cVar_bNR3n0Ut_sendMessage);
  cMsg_zXLKdX02_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_F4GlrLrm, 0, m, &cVar_F4GlrLrm_sendMessage);
  cMsg_jIXQBo2h_sendMessage(_c, 0, m);
  cMsg_3JqVE1WC_sendMessage(_c, 0, m);
  cMsg_cWxAJXyv_sendMessage(_c, 0, m);
  cMsg_9sSD298m_sendMessage(_c, 0, m);
  cMsg_kDA9Z7ZG_sendMessage(_c, 0, m);
  cMsg_AOGsQO0X_sendMessage(_c, 0, m);
  cMsg_wvBMUTZD_sendMessage(_c, 0, m);
  cMsg_c2mc9rTl_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TltFakeI, 0, m, &cVar_TltFakeI_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_JetEngine::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9;
  hv_bufferi_t Bi0, Bi1;

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
    __hv_varread_f(&sVarf_L3Wbp57T, VOf(Bf0));
    __hv_varread_f(&sVarf_HFMoBDuP, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_yrxTiAuT, VOf(Bf0));
    __hv_rpole_f(&sRPole_7Pn0JOhJ, VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_Po8hx7C0, VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_phasor_f(&sPhasor_OAi9Juy8, VIf(Bf1), VOf(Bf1));
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
    __hv_varread_f(&sVarf_CxckfKQu, VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf4));
    __hv_phasor_f(&sPhasor_Xz5F7p8I, VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf4), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_varread_f(&sVarf_13T21vtZ, VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf3));
    __hv_phasor_f(&sPhasor_qN45Zo9Z, VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_o9nRDfFi, VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf5));
    __hv_phasor_f(&sPhasor_ycn3vJTN, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf3), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf5), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf5));
    __hv_mul_f(VIf(Bf3), VIf(Bf5), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_varread_f(&sVarf_142x1T4v, VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf6));
    __hv_phasor_f(&sPhasor_qxnOtsaK, VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf7), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf9), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf6), VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf3), VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f, 0.9f);
    __hv_min_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f, -0.9f);
    __hv_max_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_varread_i(&sVari_iggD1EbF, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_iggD1EbF, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_biquad_k_f(&sBiquad_k_nHGlVm6G, VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f, 150.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_LZf1F0s6, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_Q6gevBZJ, VOf(Bf1));
    __hv_min_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_YCXGI3Tt, VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf4));
    __hv_varread_f(&sVarf_CPU2UNWB, VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf7));
    __hv_cos_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_zero_f(VOf(Bf4));
    __hv_gt_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_sqrt_f(VIf(Bf3), VOf(Bf3));
    __hv_and_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf7), VIf(Bf3), VOf(Bf3));
    __hv_cpole_f(&sCPole_owL7gz17, VIf(Bf1), VIf(ZERO), VIf(Bf6), VIf(Bf3), VOf(Bf3), VOf(Bf6));
    __hv_varread_f(&sVarf_LbMdg2Hk, VOf(Bf6));
    __hv_rpole_f(&sRPole_xNmz4x6S, VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_Z3ClEiOM, VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_0rGZKPMD, VOf(Bf6));
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f, 120.0f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f, 12000.0f);
    __hv_mul_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_BoGX1Jlf, VOf(Bf0));
    __hv_mul_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf6), 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f, 1e-05f);
    __hv_max_f(VIf(Bf0), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_iMU0nxw5, VOf(Bf0));
    __hv_min_f(VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_6I0uPLR6, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf3));
    __hv_varread_f(&sVarf_63PZek92, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf1));
    __hv_cos_f(VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf6));
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_zero_f(VOf(Bf3));
    __hv_gt_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_sqrt_f(VIf(Bf6), VOf(Bf6));
    __hv_and_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_cpole_f(&sCPole_JFqELqD8, VIf(Bf0), VIf(ZERO), VIf(Bf7), VIf(Bf6), VOf(Bf6), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_Fo93yNMq, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_PU0aXk9T, VOf(Bf6));
    __hv_rpole_f(&sRPole_LPEzeG7O, VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_JetEngine::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_JetEngine::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
