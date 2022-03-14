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
  numBytes += sPhasor_k_init(&sPhasor_CcmXOFS5, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_xwCBYkyL, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_wNaOGkXW);
  numBytes += sRPole_init(&sRPole_hR673SGl);
  numBytes += sDel1_init(&sDel1_0IliIWoH);
  numBytes += sPhasor_k_init(&sPhasor_NWktn96e, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_5wS50EET, 0.0f, sampleRate);
  numBytes += sRPole_init(&sRPole_F0i9jqXj);
  numBytes += sDel1_init(&sDel1_fMN2kC8f);
  numBytes += sRPole_init(&sRPole_EZJHzIeg);
  numBytes += sDel1_init(&sDel1_EnXsQ0Da);
  numBytes += sRPole_init(&sRPole_keRSGfgd);
  numBytes += sPhasor_k_init(&sPhasor_6gDyyrqH, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_mXtFabMt, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_sewb8qSg);
  numBytes += sRPole_init(&sRPole_c89MkRri);
  numBytes += sDel1_init(&sDel1_aDjSyI8R);
  numBytes += cBinop_init(&cBinop_x1DFCelF, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_mBX9HHqs, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_i80qZI1t, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_XjfsSBsH, 400.0f);
  numBytes += sVarf_init(&sVarf_6DdTZWNc, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_3LaEQeDH, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_OH6gvL9j, 360.0f);
  numBytes += sVarf_init(&sVarf_zX8kB2YK, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_cUpgY7JG, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_SrWj7uQa, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_bTo8dJpD, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_yqoD9Yv6, 600.0f);
  numBytes += cDelay_init(this, &cDelay_RCrrOtXT, 0.0f);
  numBytes += cBinop_init(&cBinop_CZjkS8d3, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_4D8OPEVr, 100.0f);
  numBytes += cVar_init_f(&cVar_vtM1CRAT, 0.0f);
  numBytes += sVarf_init(&sVarf_Dd5wxQTj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_M6BAU8zO, 0.0f);
  numBytes += cVar_init_f(&cVar_m6vtpdTd, 0.0f);
  numBytes += cDelay_init(this, &cDelay_jWyvqY3T, 1200.0f);
  numBytes += cVar_init_f(&cVar_xP56JvCg, 360.0f);
  numBytes += cBinop_init(&cBinop_PEH0l7m4, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_SBcPebzB, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zjvzYCb4, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_ABP680r9, 200.0f);
  numBytes += cVar_init_f(&cVar_ujAFwPHX, 0.0f);
  numBytes += cRandom_init(&cRandom_iiVwQvcr, 340344099);
  numBytes += cSlice_init(&cSlice_FNJB9gAn, 1, 1);
  numBytes += cVar_init_f(&cVar_FJ1jX5oK, 1000.0f);
  numBytes += cBinop_init(&cBinop_p4hAQCMd, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_ypGm6vaQ, 0.0f);
  numBytes += sVarf_init(&sVarf_QykFE866, 0.0f, 0.0f, false);
  numBytes += cSlice_init(&cSlice_5uSQWkBW, 1, 1);
  numBytes += cRandom_init(&cRandom_1TjPReaK, 1343871999);
  numBytes += sVarf_init(&sVarf_TSgLMtic, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_F4xCkLee, 1.0f);
  numBytes += cDelay_init(this, &cDelay_G0YnY6MT, 800.0f);
  numBytes += cVar_init_f(&cVar_OxN7KD5d, 0.0f);
  numBytes += cVar_init_f(&cVar_9cpX2OQh, 0.0f);
  numBytes += cBinop_init(&cBinop_C2IBAHdc, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_KZA0cUOk, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_buH4fQKK, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_9YzUGhSw, 100.0f);
  numBytes += sVarf_init(&sVarf_ycq9AZ0e, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_mT1yqCB3, 0.0f);
  numBytes += cBinop_init(&cBinop_HRUObonh, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_8TYrgnA2, 0.0f);
  numBytes += cVar_init_f(&cVar_zzsik4n2, 200.0f);
  numBytes += cDelay_init(this, &cDelay_HfhClk6G, 400.0f);
  numBytes += cVar_init_f(&cVar_SYQeomW8, 0.0f);
  numBytes += sVarf_init(&sVarf_SJpc5Aer, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_8oL4iEDY, 0.0f); // __add
  numBytes += cDelay_init(this, &cDelay_1m63IblA, 400.0f);
  numBytes += cVar_init_f(&cVar_D4o23XmP, 0.0f);
  numBytes += cBinop_init(&cBinop_EUoMfH3Q, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_hkofS5jw, 0.0f);
  numBytes += cVar_init_f(&cVar_BCR7UoAY, 360.0f);
  numBytes += cBinop_init(&cBinop_xMUhdSHN, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_MRuPdSiP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_KxsxXQNe, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_TT9ijIuV, 0.0f);
  numBytes += cVar_init_f(&cVar_nxq4Drf4, 1.0f);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mwkGhGd8_sendMessage);
      break;
    }
    case 0x9989090A: { // buttonSelect
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Lk7VTwYK_sendMessage);
      break;
    }
    case 0xD27DD130: { // buttonSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KYjLMcuM_sendMessage);
      break;
    }
    case 0xCC6D2A59: { // checkPointSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YfUAb3v3_sendMessage);
      break;
    }
    case 0xD45231EE: { // checkpointPass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_GCQrsdxn_sendMessage);
      break;
    }
    case 0xBF8ABE63: { // currentNum
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UlLW2tgj_sendMessage);
      break;
    }
    case 0xF8F82CF0: { // lapPass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_OaVoTXpj_sendMessage);
      break;
    }
    case 0x5F10083B: { // lapSound
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_woQcxsJ0_sendMessage);
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
        info->type = HvParameterType::HV_PARAM_TYPE_EVENT_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
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


void Heavy_LaoSFX::cReceive_UlLW2tgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m6vtpdTd, 0, m, &cVar_m6vtpdTd_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SYQeomW8, 0, m, &cVar_SYQeomW8_sendMessage);
}

void Heavy_LaoSFX::cSend_SGLRLI5e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Lk7VTwYK_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_x1DFCelF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sLE3JphU_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSystem_0XR6Xqgf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x1DFCelF, HV_BINOP_DIVIDE, 1, m, &cBinop_x1DFCelF_sendMessage);
}

void Heavy_LaoSFX::cMsg_s2Ufa28p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_0XR6Xqgf_sendMessage);
}

void Heavy_LaoSFX::cBinop_38vS8K3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_THbNu37q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Efz6Eyhm_sendMessage);
}

void Heavy_LaoSFX::cBinop_lmEmlZQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_38vS8K3A_sendMessage);
}

void Heavy_LaoSFX::cBinop_o3NZcsup_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_lmEmlZQb_sendMessage);
}

void Heavy_LaoSFX::cBinop_4e15pabk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_qz9F4nfW_sendMessage);
}

void Heavy_LaoSFX::cMsg_sLE3JphU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_o3NZcsup_sendMessage);
}

void Heavy_LaoSFX::cBinop_Efz6Eyhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_i80qZI1t, m);
}

void Heavy_LaoSFX::cBinop_JOwHJmm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mBX9HHqs, m);
}

void Heavy_LaoSFX::cVar_XjfsSBsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_4e15pabk_sendMessage);
}

void Heavy_LaoSFX::cBinop_qz9F4nfW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_x1DFCelF, HV_BINOP_DIVIDE, 0, m, &cBinop_x1DFCelF_sendMessage);
}

void Heavy_LaoSFX::cBinop_THbNu37q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_JOwHJmm2_sendMessage);
}

void Heavy_LaoSFX::cBinop_0uerL5iA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_UV4SEqdt_sendMessage);
}

void Heavy_LaoSFX::cMsg_NLQhHbtP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LaEQeDH, HV_BINOP_POW, 0, m, &cBinop_3LaEQeDH_sendMessage);
}

void Heavy_LaoSFX::cBinop_3LaEQeDH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_jKjVubGC_sendMessage);
}

void Heavy_LaoSFX::cBinop_jKjVubGC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_M6BAU8zO, 0, m, &cVar_M6BAU8zO_sendMessage);
}

void Heavy_LaoSFX::cBinop_UV4SEqdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3LaEQeDH, HV_BINOP_POW, 1, m, &cBinop_3LaEQeDH_sendMessage);
  cMsg_NLQhHbtP_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_j7s4TyLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fcPJqYpH_sendMessage(_c, 0, m);
  cSwitchcase_glcO4VkD_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_ARIS2CF0_onMessage(_c, NULL, 0, m, NULL);
  cMsg_ZtJDXSOP_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_ZtJDXSOP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  msg_setFloat(m, 1, 600.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wNaOGkXW, 0, m, NULL);
}

void Heavy_LaoSFX::cBinop_bJGiyMNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SrWj7uQa, m);
}

void Heavy_LaoSFX::cBinop_gCxzJCrV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_zZ32LhuZ_sendMessage);
}

void Heavy_LaoSFX::cMsg_J7ESyoTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_gCxzJCrV_sendMessage);
}

void Heavy_LaoSFX::cSystem_H7ac8dwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cUpgY7JG, HV_BINOP_DIVIDE, 1, m, &cBinop_cUpgY7JG_sendMessage);
}

void Heavy_LaoSFX::cMsg_Rx6Cvt75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_H7ac8dwv_sendMessage);
}

void Heavy_LaoSFX::cBinop_e2DsurwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_J8UEW7Ru_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bJGiyMNU_sendMessage);
}

void Heavy_LaoSFX::cBinop_zZ32LhuZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_e2DsurwF_sendMessage);
}

void Heavy_LaoSFX::cBinop_s3PwieIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zX8kB2YK, m);
}

void Heavy_LaoSFX::cVar_OH6gvL9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0L62sR0v_sendMessage);
}

void Heavy_LaoSFX::cBinop_0L62sR0v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_wXYc51Kt_sendMessage);
}

void Heavy_LaoSFX::cBinop_J8UEW7Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_s3PwieIq_sendMessage);
}

void Heavy_LaoSFX::cBinop_cUpgY7JG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J7ESyoTU_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_wXYc51Kt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cUpgY7JG, HV_BINOP_DIVIDE, 0, m, &cBinop_cUpgY7JG_sendMessage);
}

void Heavy_LaoSFX::cSend_xwdOtOkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UlLW2tgj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_Hi5B89zW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wNaOGkXW, 0, m, NULL);
}

void Heavy_LaoSFX::cSend_IDkSq7WS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UlLW2tgj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_bTo8dJpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vtM1CRAT, 0, m, &cVar_vtM1CRAT_sendMessage);
}

void Heavy_LaoSFX::cMsg_YFbZYaDo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yqoD9Yv6, 0, m, &cDelay_yqoD9Yv6_sendMessage);
}

void Heavy_LaoSFX::cDelay_yqoD9Yv6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yqoD9Yv6, m);
  cMsg_WCfdscgP_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_dyaVuosr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yqoD9Yv6, 0, m, &cDelay_yqoD9Yv6_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_glcO4VkD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_YFbZYaDo_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_YFbZYaDo_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_yqoD9Yv6, 1, m, &cDelay_yqoD9Yv6_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dyaVuosr_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_fcPJqYpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65.0f);
  cSend_xwdOtOkX_sendMessage(_c, 0, m);
  cSwitchcase_iKEPbbZQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cBinop_i2EXfJ7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CZjkS8d3, HV_BINOP_MULTIPLY, 1, m, &cBinop_CZjkS8d3_sendMessage);
}

void Heavy_LaoSFX::cDelay_RCrrOtXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_RCrrOtXT, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCrrOtXT, 0, m, &cDelay_RCrrOtXT_sendMessage);
  cMsg_c8Jc6zzz_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_47jGekf1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCrrOtXT, 0, m, &cDelay_RCrrOtXT_sendMessage);
}

void Heavy_LaoSFX::cMsg_YTMo5ib1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FBIcQJep_sendMessage);
}

void Heavy_LaoSFX::cSystem_FBIcQJep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_i2EXfJ7q_sendMessage);
}

void Heavy_LaoSFX::cBinop_CZjkS8d3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_2ZjZ38Qu_sendMessage);
}

void Heavy_LaoSFX::cCast_f7DYLFkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_47jGekf1_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCrrOtXT, 0, m, &cDelay_RCrrOtXT_sendMessage);
  cMsg_c8Jc6zzz_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_2ZjZ38Qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_RCrrOtXT, 2, m, &cDelay_RCrrOtXT_sendMessage);
}

void Heavy_LaoSFX::cVar_4D8OPEVr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_CZjkS8d3, HV_BINOP_MULTIPLY, 0, m, &cBinop_CZjkS8d3_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_iKEPbbZQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_47jGekf1_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_47jGekf1_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_f7DYLFkN_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_WCfdscgP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_iKEPbbZQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_c8Jc6zzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bTo8dJpD, HV_BINOP_ADD, 0, m, &cBinop_bTo8dJpD_sendMessage);
}

void Heavy_LaoSFX::cVar_vtM1CRAT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_IDkSq7WS_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_0uerL5iA_sendMessage);
}

void Heavy_LaoSFX::cVar_M6BAU8zO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_CcmXOFS5, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_xwCBYkyL, 0, m);
}

void Heavy_LaoSFX::cVar_m6vtpdTd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bTo8dJpD, HV_BINOP_ADD, 1, m, &cBinop_bTo8dJpD_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_ARIS2CF0_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_H159xkKA_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_H159xkKA_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_jWyvqY3T, 1, m, &cDelay_jWyvqY3T_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SDGF4odX_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cDelay_jWyvqY3T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_jWyvqY3T, m);
  cMsg_Hi5B89zW_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_H159xkKA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_jWyvqY3T, 0, m, &cDelay_jWyvqY3T_sendMessage);
}

void Heavy_LaoSFX::cCast_SDGF4odX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_jWyvqY3T, 0, m, &cDelay_jWyvqY3T_sendMessage);
}

void Heavy_LaoSFX::cSend_Kqw1qVHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_OaVoTXpj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_qKSMvHki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_2FmrFQVn_sendMessage);
}

void Heavy_LaoSFX::cBinop_zcbvJe0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HWGqtKfA_sendMessage);
}

void Heavy_LaoSFX::cVar_xP56JvCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_qKSMvHki_sendMessage);
}

void Heavy_LaoSFX::cBinop_PEH0l7m4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_TKjzyEOH_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_Xw4eOEBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_n3x916wd_sendMessage);
}

void Heavy_LaoSFX::cMsg_TKjzyEOH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_zcbvJe0E_sendMessage);
}

void Heavy_LaoSFX::cSystem_fmihbv90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PEH0l7m4, HV_BINOP_DIVIDE, 1, m, &cBinop_PEH0l7m4_sendMessage);
}

void Heavy_LaoSFX::cMsg_kiWaQa6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fmihbv90_sendMessage);
}

void Heavy_LaoSFX::cBinop_9LMIkVGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zjvzYCb4, m);
}

void Heavy_LaoSFX::cBinop_HWGqtKfA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_2WRYg6Ry_sendMessage);
}

void Heavy_LaoSFX::cBinop_2WRYg6Ry_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Xw4eOEBo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9LMIkVGO_sendMessage);
}

void Heavy_LaoSFX::cBinop_n3x916wd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SBcPebzB, m);
}

void Heavy_LaoSFX::cBinop_2FmrFQVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PEH0l7m4, HV_BINOP_DIVIDE, 0, m, &cBinop_PEH0l7m4_sendMessage);
}

void Heavy_LaoSFX::cDelay_ABP680r9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ABP680r9, m);
  cMsg_vttHfPip_sendMessage(_c, 0, m);
  cSwitchcase_hc528YdU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cCast_QmPO8yp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ABP680r9, 0, m, &cDelay_ABP680r9_sendMessage);
}

void Heavy_LaoSFX::cMsg_MUjy291u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ABP680r9, 0, m, &cDelay_ABP680r9_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_uV2crvQm_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_MUjy291u_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_MUjy291u_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ABP680r9, 1, m, &cDelay_ABP680r9_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QmPO8yp2_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_vttHfPip_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 3.0f);
  cSwitchcase_uaKVPTsU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cCast_aRdS08Pa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F4xCkLee, 0, m, &cVar_F4xCkLee_sendMessage);
  cSwitchcase_RexRJG0y_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_uV2crvQm_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_ujAFwPHX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ZDnuQnFi_sendMessage);
}

void Heavy_LaoSFX::cCast_O1MoglkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_FYk2TwO5_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P7OsJYpA_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_z8akUuS2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O1MoglkV_sendMessage);
      break;
    }
    default: {
      cMsg_NodRYBM8_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cSwitchcase_RexRJG0y_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_FNJB9gAn, 0, m, &cSlice_FNJB9gAn_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iiVwQvcr, 0, m, &cRandom_iiVwQvcr_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cRandom_iiVwQvcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_km7iUTmN_sendMessage);
}

void Heavy_LaoSFX::cUnop_PNUZg1ax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_uaKVPTsU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cSlice_FNJB9gAn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_iiVwQvcr, 1, m, &cRandom_iiVwQvcr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_LaoSFX::cBinop_km7iUTmN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_PNUZg1ax_sendMessage);
}

void Heavy_LaoSFX::cSystem_sUNR4W30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_i9xybXsm_sendMessage);
}

void Heavy_LaoSFX::cMsg_Qf9LL7Qu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_sUNR4W30_sendMessage);
}

void Heavy_LaoSFX::cCast_QI4B5ZjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E0eve8pc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypGm6vaQ, 0, m, &cDelay_ypGm6vaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aRdS08Pa_sendMessage);
}

void Heavy_LaoSFX::cBinop_i9xybXsm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p4hAQCMd, HV_BINOP_MULTIPLY, 1, m, &cBinop_p4hAQCMd_sendMessage);
}

void Heavy_LaoSFX::cVar_FJ1jX5oK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p4hAQCMd, HV_BINOP_MULTIPLY, 0, m, &cBinop_p4hAQCMd_sendMessage);
}

void Heavy_LaoSFX::cBinop_p4hAQCMd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_lLAqADNL_sendMessage);
}

void Heavy_LaoSFX::cMsg_E0eve8pc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypGm6vaQ, 0, m, &cDelay_ypGm6vaQ_sendMessage);
}

void Heavy_LaoSFX::cDelay_ypGm6vaQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ypGm6vaQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypGm6vaQ, 0, m, &cDelay_ypGm6vaQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aRdS08Pa_sendMessage);
}

void Heavy_LaoSFX::cBinop_lLAqADNL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ypGm6vaQ, 2, m, &cDelay_ypGm6vaQ_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_HCcxs84B_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_E0eve8pc_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_E0eve8pc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QI4B5ZjZ_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_PDHzB7PZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 71.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ujAFwPHX, 0, m, &cVar_ujAFwPHX_sendMessage);
}

void Heavy_LaoSFX::cMsg_bh00jptf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 67.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ujAFwPHX, 0, m, &cVar_ujAFwPHX_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_hc528YdU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5uSQWkBW, 0, m, &cSlice_5uSQWkBW_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1TjPReaK, 0, m, &cRandom_1TjPReaK_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cSlice_5uSQWkBW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_1TjPReaK, 1, m, &cRandom_1TjPReaK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_LaoSFX::cRandom_1TjPReaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 3.0f, 0, m, &cBinop_BwbkVHCn_sendMessage);
}

void Heavy_LaoSFX::cBinop_BwbkVHCn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_JsXa2FhI_sendMessage);
}

void Heavy_LaoSFX::cUnop_JsXa2FhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_NefVRUyW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_F4xCkLee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_aJBIU7Vp_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_QykFE866, m);
}

void Heavy_LaoSFX::cBinop_aJBIU7Vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_F4xCkLee, 1, m, &cVar_F4xCkLee_sendMessage);
}

void Heavy_LaoSFX::cMsg_XPLDPb3X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 69.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_ujAFwPHX, 0, m, &cVar_ujAFwPHX_sendMessage);
}

void Heavy_LaoSFX::cMsg_3DYvzebd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_G0YnY6MT, 0, m, &cDelay_G0YnY6MT_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_BXIJUxwR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_3DYvzebd_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_3DYvzebd_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_G0YnY6MT, 1, m, &cDelay_G0YnY6MT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wxr6gmPW_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cCast_wxr6gmPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_G0YnY6MT, 0, m, &cDelay_G0YnY6MT_sendMessage);
}

void Heavy_LaoSFX::cDelay_G0YnY6MT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_G0YnY6MT, m);
  cMsg_2nTsn3Wj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_GpbuOBCM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PDHzB7PZ_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_AduOv8fN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XPLDPb3X_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_Dx0hrYhh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bh00jptf_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_NefVRUyW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Dx0hrYhh_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AduOv8fN_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GpbuOBCM_sendMessage);
      break;
    }
    default: {
      cMsg_ZH6RUQTm_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cVar_OxN7KD5d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_5wS50EET, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_NWktn96e, 0, m);
}

void Heavy_LaoSFX::cVar_9cpX2OQh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_ZDnuQnFi_sendMessage);
}

void Heavy_LaoSFX::cCast_P7OsJYpA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_BXIJUxwR_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_ZH6RUQTm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9cpX2OQh, 0, m, &cVar_9cpX2OQh_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ujAFwPHX, 0, m, &cVar_ujAFwPHX_sendMessage);
}

void Heavy_LaoSFX::cMsg_2nTsn3Wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_F4xCkLee, 0, m, &cVar_F4xCkLee_sendMessage);
  cSwitchcase_HCcxs84B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_f70IBwii_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 70.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9cpX2OQh, 0, m, &cVar_9cpX2OQh_sendMessage);
}

void Heavy_LaoSFX::cMsg_3l7EjoSW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 66.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9cpX2OQh, 0, m, &cVar_9cpX2OQh_sendMessage);
}

void Heavy_LaoSFX::cMsg_NodRYBM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_F4xCkLee, 0, m, &cVar_F4xCkLee_sendMessage);
  cSwitchcase_HCcxs84B_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_FYk2TwO5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 400.0f);
  cSwitchcase_HCcxs84B_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_FJ1jX5oK, 0, m, &cVar_FJ1jX5oK_sendMessage);
}

void Heavy_LaoSFX::cBinop_7c5SWejt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OxN7KD5d, 0, m, &cVar_OxN7KD5d_sendMessage);
}

void Heavy_LaoSFX::cBinop_qRzhPL8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_C2IBAHdc, HV_BINOP_POW, 1, m, &cBinop_C2IBAHdc_sendMessage);
  cMsg_kR2DXKFK_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_kR2DXKFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_C2IBAHdc, HV_BINOP_POW, 0, m, &cBinop_C2IBAHdc_sendMessage);
}

void Heavy_LaoSFX::cBinop_ZDnuQnFi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qRzhPL8J_sendMessage);
}

void Heavy_LaoSFX::cBinop_C2IBAHdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_7c5SWejt_sendMessage);
}

void Heavy_LaoSFX::cMsg_HfRd6k0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 68.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9cpX2OQh, 0, m, &cVar_9cpX2OQh_sendMessage);
}

void Heavy_LaoSFX::cCast_ovyEhMxT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_f70IBwii_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_HFwwO2cw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HfRd6k0g_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cCast_6kQFX7wj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3l7EjoSW_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_uaKVPTsU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6kQFX7wj_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HFwwO2cw_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ovyEhMxT_sendMessage);
      break;
    }
    default: {
      cMsg_ZH6RUQTm_sendMessage(_c, 0, m);
      break;
    }
  }
}

void Heavy_LaoSFX::cReceive_Lk7VTwYK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_z8akUuS2_onMessage(_c, NULL, 0, m, NULL);
  cMsg_1oBxCrOY_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_r6XtMVaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KZA0cUOk, m);
}

void Heavy_LaoSFX::cMsg_3XdmjSqg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_heKuxKEU_sendMessage);
}

void Heavy_LaoSFX::cSystem_05HaapuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3XdmjSqg_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_0D5CZxew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_05HaapuM_sendMessage);
}

void Heavy_LaoSFX::cBinop_buH4fQKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_gyvrYLSt_sendMessage);
}

void Heavy_LaoSFX::cBinop_heKuxKEU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_buH4fQKK, HV_BINOP_MULTIPLY, 1, m, &cBinop_buH4fQKK_sendMessage);
}

void Heavy_LaoSFX::cVar_9YzUGhSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_buH4fQKK, HV_BINOP_MULTIPLY, 0, m, &cBinop_buH4fQKK_sendMessage);
}

void Heavy_LaoSFX::cBinop_gyvrYLSt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_WYCobSsk_sendMessage);
}

void Heavy_LaoSFX::cBinop_WYCobSsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_r6XtMVaM_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_ycq9AZ0e, m);
}

void Heavy_LaoSFX::cVar_mT1yqCB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_paJouoLy_sendMessage);
}

void Heavy_LaoSFX::cBinop_HRUObonh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_hixLw5Wk_sendMessage);
}

void Heavy_LaoSFX::cBinop_hixLw5Wk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_8TYrgnA2, 2, m, &cDelay_8TYrgnA2_sendMessage);
}

void Heavy_LaoSFX::cSystem_JLx5miWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_B9OsYL9N_sendMessage);
}

void Heavy_LaoSFX::cMsg_D3N3ABCk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_JLx5miWD_sendMessage);
}

void Heavy_LaoSFX::cDelay_8TYrgnA2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_8TYrgnA2, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8TYrgnA2, 0, m, &cDelay_8TYrgnA2_sendMessage);
  cMsg_98X1fzIj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_B9OsYL9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HRUObonh, HV_BINOP_MULTIPLY, 1, m, &cBinop_HRUObonh_sendMessage);
}

void Heavy_LaoSFX::cMsg_mCoklzcI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_8TYrgnA2, 0, m, &cDelay_8TYrgnA2_sendMessage);
}

void Heavy_LaoSFX::cVar_zzsik4n2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HRUObonh, HV_BINOP_MULTIPLY, 0, m, &cBinop_HRUObonh_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_dHyfBg1E_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_mCoklzcI_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_mCoklzcI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ANupa4O7_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cCast_ANupa4O7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mCoklzcI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_8TYrgnA2, 0, m, &cDelay_8TYrgnA2_sendMessage);
  cMsg_98X1fzIj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cDelay_HfhClk6G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_HfhClk6G, m);
  cMsg_MbjQk6CM_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_o5VRDT2L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_HfhClk6G, 0, m, &cDelay_HfhClk6G_sendMessage);
}

void Heavy_LaoSFX::cSwitchcase_aMBK0Slq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_o5VRDT2L_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_o5VRDT2L_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_HfhClk6G, 1, m, &cDelay_HfhClk6G_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IWMduMSr_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cCast_IWMduMSr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_HfhClk6G, 0, m, &cDelay_HfhClk6G_sendMessage);
}

void Heavy_LaoSFX::cVar_SYQeomW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8oL4iEDY, HV_BINOP_ADD, 1, m, &cBinop_8oL4iEDY_sendMessage);
}

void Heavy_LaoSFX::cBinop_8oL4iEDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_D4o23XmP, 0, m, &cVar_D4o23XmP_sendMessage);
}

void Heavy_LaoSFX::cDelay_1m63IblA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1m63IblA, m);
  cMsg_wpCqqZFt_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSwitchcase_HAgAuEQT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_U3v3Efq7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_U3v3Efq7_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_1m63IblA, 1, m, &cDelay_1m63IblA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w9O2uxMk_sendMessage);
      break;
    }
  }
}

void Heavy_LaoSFX::cMsg_U3v3Efq7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1m63IblA, 0, m, &cDelay_1m63IblA_sendMessage);
}

void Heavy_LaoSFX::cCast_w9O2uxMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1m63IblA, 0, m, &cDelay_1m63IblA_sendMessage);
}

void Heavy_LaoSFX::cSend_3rzs5M5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UlLW2tgj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_D4o23XmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_O8erN1MD_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_sZkuc3b1_sendMessage);
}

void Heavy_LaoSFX::cBinop_sZkuc3b1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_bypcsxcZ_sendMessage);
}

void Heavy_LaoSFX::cMsg_XkoVW7tI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EUoMfH3Q, HV_BINOP_POW, 0, m, &cBinop_EUoMfH3Q_sendMessage);
}

void Heavy_LaoSFX::cBinop_vzwkU8e0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hkofS5jw, 0, m, &cVar_hkofS5jw_sendMessage);
}

void Heavy_LaoSFX::cBinop_bypcsxcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EUoMfH3Q, HV_BINOP_POW, 1, m, &cBinop_EUoMfH3Q_sendMessage);
  cMsg_XkoVW7tI_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_EUoMfH3Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_vzwkU8e0_sendMessage);
}

void Heavy_LaoSFX::cCast_kOJzOMsY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OcO7fKS4_sendMessage(_c, 0, m);
  cSwitchcase_dHyfBg1E_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_aMBK0Slq_onMessage(_c, NULL, 0, m, NULL);
  cMsg_2u4dwQpp_sendMessage(_c, 0, m);
  cSwitchcase_HAgAuEQT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_OcO7fKS4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 71.0f);
  cSend_3rzs5M5q_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_wpCqqZFt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 300.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sewb8qSg, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_2u4dwQpp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  msg_setFloat(m, 1, 200.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_sewb8qSg, 0, m, NULL);
}

void Heavy_LaoSFX::cMsg_MbjQk6CM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  cSwitchcase_dHyfBg1E_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_LaoSFX::cVar_hkofS5jw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_6gDyyrqH, 0, m);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_mXtFabMt, 0, m);
}

void Heavy_LaoSFX::cSend_O8erN1MD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_UlLW2tgj_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_98X1fzIj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8oL4iEDY, HV_BINOP_ADD, 0, m, &cBinop_8oL4iEDY_sendMessage);
}

void Heavy_LaoSFX::cMsg_1hkU17Bz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_HaQm1Sd8_sendMessage);
}

void Heavy_LaoSFX::cSystem_HaQm1Sd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xMUhdSHN, HV_BINOP_DIVIDE, 1, m, &cBinop_xMUhdSHN_sendMessage);
}

void Heavy_LaoSFX::cBinop_lunFtrmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xMUhdSHN, HV_BINOP_DIVIDE, 0, m, &cBinop_xMUhdSHN_sendMessage);
}

void Heavy_LaoSFX::cMsg_EOjn13zB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_hwlRUhTg_sendMessage);
}

void Heavy_LaoSFX::cBinop_GJdws79n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_HlZ5v9xD_sendMessage);
}

void Heavy_LaoSFX::cBinop_PZwA0tbO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_KxsxXQNe, m);
}

void Heavy_LaoSFX::cBinop_RUsbVauU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GJdws79n_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_PZwA0tbO_sendMessage);
}

void Heavy_LaoSFX::cBinop_meyiTq3j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_RUsbVauU_sendMessage);
}

void Heavy_LaoSFX::cVar_BCR7UoAY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_EeG65DAb_sendMessage);
}

void Heavy_LaoSFX::cBinop_xMUhdSHN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EOjn13zB_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cBinop_EeG65DAb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_lunFtrmi_sendMessage);
}

void Heavy_LaoSFX::cBinop_hwlRUhTg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_meyiTq3j_sendMessage);
}

void Heavy_LaoSFX::cBinop_HlZ5v9xD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MRuPdSiP, m);
}

void Heavy_LaoSFX::cReceive_YfUAb3v3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wpN1BfYf_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_KYjLMcuM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SGLRLI5e_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cMsg_4STGFgPm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_wpN1BfYf_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_mwkGhGd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Qf9LL7Qu_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_FJ1jX5oK, 0, m, &cVar_FJ1jX5oK_sendMessage);
  cMsg_kiWaQa6t_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_xP56JvCg, 0, m, &cVar_xP56JvCg_sendMessage);
  cMsg_YTMo5ib1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_4D8OPEVr, 0, m, &cVar_4D8OPEVr_sendMessage);
  cMsg_Rx6Cvt75_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_OH6gvL9j, 0, m, &cVar_OH6gvL9j_sendMessage);
  cMsg_1hkU17Bz_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_BCR7UoAY, 0, m, &cVar_BCR7UoAY_sendMessage);
  cMsg_D3N3ABCk_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_zzsik4n2, 0, m, &cVar_zzsik4n2_sendMessage);
  cMsg_0D5CZxew_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9YzUGhSw, 0, m, &cVar_9YzUGhSw_sendMessage);
  cMsg_s2Ufa28p_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_XjfsSBsH, 0, m, &cVar_XjfsSBsH_sendMessage);
}

void Heavy_LaoSFX::cMsg_1oBxCrOY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1500.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_mT1yqCB3, 0, m, &cVar_mT1yqCB3_sendMessage);
}

void Heavy_LaoSFX::cReceive_GCQrsdxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kOJzOMsY_sendMessage);
}

void Heavy_LaoSFX::cMsg_ob2cMvhH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_SGLRLI5e_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cSend_wpN1BfYf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_GCQrsdxn_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cVar_TT9ijIuV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_6DdTZWNc, m);
}

void Heavy_LaoSFX::cBinop_paJouoLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TT9ijIuV, 0, m, &cVar_TT9ijIuV_sendMessage);
}

void Heavy_LaoSFX::cMsg_Mo4BGKjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "pd");
  msg_setSymbol(m, 1, "dsp");
  msg_setElementToFrom(m, 2, n, 0);
}

void Heavy_LaoSFX::cBinop_xebwzQkz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nxq4Drf4, 1, m, &cVar_nxq4Drf4_sendMessage);
}

void Heavy_LaoSFX::cVar_nxq4Drf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_xebwzQkz_sendMessage);
  cMsg_Mo4BGKjC_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_woQcxsJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Kqw1qVHF_sendMessage(_c, 0, m);
}

void Heavy_LaoSFX::cReceive_OaVoTXpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j7s4TyLP_sendMessage);
  cMsg_1oBxCrOY_sendMessage(_c, 0, m);
  cMsg_1oBxCrOY_sendMessage(_c, 0, m);
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
    __hv_phasor_k_f(&sPhasor_CcmXOFS5, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_xwCBYkyL, VOf(Bf1));
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
    __hv_line_f(&sLine_wNaOGkXW, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_SrWj7uQa, VOf(Bf2));
    __hv_rpole_f(&sRPole_hR673SGl, VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_0IliIWoH, VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_zX8kB2YK, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_Dd5wxQTj, VIf(Bf2));
    __hv_phasor_k_f(&sPhasor_NWktn96e, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_5wS50EET, VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf3), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_QykFE866, VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_zjvzYCb4, VOf(Bf4));
    __hv_rpole_f(&sRPole_F0i9jqXj, VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_fMN2kC8f, VIf(Bf4), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_SBcPebzB, VOf(Bf4));
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf2), 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f, 0.08f);
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_f(&sVarf_TSgLMtic, VIf(Bf2));
    __hv_varread_f(&sVarf_Dd5wxQTj, VOf(Bf2));
    __hv_varread_f(&sVarf_TSgLMtic, VOf(Bf4));
    __hv_varread_f(&sVarf_SJpc5Aer, VOf(Bf5));
    __hv_add_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_i80qZI1t, VOf(Bf2));
    __hv_rpole_f(&sRPole_EZJHzIeg, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_EnXsQ0Da, VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_mBX9HHqs, VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_ycq9AZ0e, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_KZA0cUOk, VOf(Bf2));
    __hv_rpole_f(&sRPole_keRSGfgd, VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_6DdTZWNc, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_6gDyyrqH, VOf(Bf2));
    __hv_phasor_k_f(&sPhasor_mXtFabMt, VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f, 6.28318530718f);
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf4));
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f, 0.00783333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f, -0.166666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf6), VIf(Bf0), VOf(Bf0));
    __hv_fma_f(VIf(Bf4), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_sewb8qSg, VOf(Bf2));
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_KxsxXQNe, VOf(Bf0));
    __hv_rpole_f(&sRPole_c89MkRri, VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_aDjSyI8R, VIf(Bf0), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_MRuPdSiP, VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_varwrite_f(&sVarf_SJpc5Aer, VIf(Bf0));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));

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
