//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test_RPY.cpp
//
// Code generated for Simulink model 'test_RPY'.
//
// Model version                  : 1.108
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri May 10 11:28:34 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "test_RPY.h"
#include "rtwtypes.h"
#include "test_RPY_types.h"
#include "test_RPY_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<Root>/MATLAB Function1'
const int32_T test_RPY_CALL_EVENT = -1;

// Block signals (default storage)
B_test_RPY_T test_RPY_B;

// Block states (default storage)
DW_test_RPY_T test_RPY_DW;

// Real-time model
RT_MODEL_test_RPY_T test_RPY_M_ = RT_MODEL_test_RPY_T();
RT_MODEL_test_RPY_T *const test_RPY_M = &test_RPY_M_;

// Forward declaration for local functions
static void test_RPY_SystemCore_setup(px4_internal_block_PWM_test_R_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<Root>/MATLAB Function1'
//    '<S10>/MATLAB Function1'
//    '<S10>/MATLAB Function7'
//
void test_RPY_MATLABFunction1_Init(DW_MATLABFunction1_test_RPY_T *localDW)
{
  localDW->sfEvent = test_RPY_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<Root>/MATLAB Function1'
//    '<S10>/MATLAB Function1'
//    '<S10>/MATLAB Function7'
//
void test_RPY_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1, real_T
  *rty_y2, real_T *rty_y3, DW_MATLABFunction1_test_RPY_T *localDW)
{
  localDW->sfEvent = test_RPY_CALL_EVENT;
  *rty_y1 = rtu_u[0];
  *rty_y2 = rtu_u[1];
  *rty_y3 = rtu_u[2];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void test_RPY_SystemCore_setup(px4_internal_block_PWM_test_R_T *obj,
  boolean_T varargin_1, boolean_T varargin_2)
{
  uint16_T status;
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->isMain = true;
  obj->pwmDevObj = MW_PWM_OUTPUT_MAIN_DEVICE_PATH;
  status = pwm_open(&obj->pwmDevHandler, obj->pwmDevObj,
                    &obj->actuatorAdvertiseObj, &obj->armAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->servoCount = 0;
  status = pwm_getServoCount(&obj->pwmDevHandler, &obj->servoCount);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (varargin_1) {
    status = pwm_arm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = true;
  } else {
    status = pwm_disarm(&obj->pwmDevHandler, &obj->armAdvertiseObj);
    obj->isArmed = false;
  }

  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setPWMRate(&obj->pwmDevHandler, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  obj->channelMask = 15;
  status = pwm_setChannelMask(&obj->pwmDevHandler, obj->channelMask);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setFailsafePWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  status = pwm_setDisarmedPWM(&obj->pwmDevHandler, obj->servoCount,
    obj->channelMask, obj->isMain, &obj->actuatorAdvertiseObj);
  obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  if (obj->isMain) {
    status = pwm_forceFailsafe(&obj->pwmDevHandler, static_cast<int32_T>
      (varargin_2));
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
    status = pwm_forceTerminateFailsafe(&obj->pwmDevHandler, 0);
    obj->errorStatus = static_cast<uint16_T>(obj->errorStatus | status);
  }

  obj->isSetupComplete = true;
}

// Model step function
void test_RPY_step(void)
{
  real_T tmp;
  real_T tmp_0;
  int32_T At1_tmp;
  int32_T Pt1_tmp;
  int32_T b;
  int32_T i;
  int32_T i_0;
  int32_T r1;
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion1_fx;
  uint16_T rtb_DataTypeConversion1_j;
  uint16_T rtb_DataTypeConversion1_n;
  boolean_T b_varargout_1;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(test_RPY_DW.IfActionSubsystem2_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S21>/Discrete Time'
  //   DigitalClock: '<S23>/Discrete Time'
  //   DigitalClock: '<S7>/Discrete Time1'
  //   Sin: '<Root>/Sine Wave'
  //   Sin: '<Root>/Sine Wave1'
  //   Sin: '<Root>/Sine Wave2'
  //   Sin: '<Root>/Sine Wave3'

  test_RPY_B.DigitalClock1 = test_RPY_M->Timing.taskTime0;

  // Sin: '<Root>/Sine Wave'
  if (test_RPY_DW.systemEnable != 0) {
    test_RPY_B.ph_meas = test_RPY_P.SineWave_Freq * test_RPY_B.DigitalClock1;
    test_RPY_DW.lastSin = sin(test_RPY_B.ph_meas);
    test_RPY_DW.lastCos = cos(test_RPY_B.ph_meas);
    test_RPY_DW.systemEnable = 0;
  }

  // DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
  //   Constant: '<S34>/Constant'
  //   Sin: '<Root>/Sine Wave'
  //   Sum: '<S34>/Sum'

  test_RPY_B.numAccum = floor((((test_RPY_DW.lastSin * test_RPY_P.SineWave_PCos
    + test_RPY_DW.lastCos * test_RPY_P.SineWave_PSin) * test_RPY_P.SineWave_HCos
    + (test_RPY_DW.lastCos * test_RPY_P.SineWave_PCos - test_RPY_DW.lastSin *
       test_RPY_P.SineWave_PSin) * test_RPY_P.SineWave_Hsin) *
    test_RPY_P.SineWave_Amp + test_RPY_P.SineWave_Bias) +
    test_RPY_P.Constant_Value_a);
  if (rtIsNaN(test_RPY_B.numAccum) || rtIsInf(test_RPY_B.numAccum)) {
    test_RPY_B.numAccum = 0.0;
  } else {
    test_RPY_B.numAccum = fmod(test_RPY_B.numAccum, 65536.0);
  }

  rtb_DataTypeConversion1_n = static_cast<uint16_T>(test_RPY_B.numAccum < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-test_RPY_B.numAccum)))) : static_cast<int32_T>(
    static_cast<uint16_T>(test_RPY_B.numAccum)));

  // End of DataTypeConversion: '<S34>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave1'
  if (test_RPY_DW.systemEnable_o != 0) {
    test_RPY_B.ph_meas = test_RPY_P.SineWave1_Freq * test_RPY_B.DigitalClock1;
    test_RPY_DW.lastSin_c = sin(test_RPY_B.ph_meas);
    test_RPY_DW.lastCos_e = cos(test_RPY_B.ph_meas);
    test_RPY_DW.systemEnable_o = 0;
  }

  // DataTypeConversion: '<S35>/Data Type Conversion1' incorporates:
  //   Constant: '<S35>/Constant'
  //   Sin: '<Root>/Sine Wave1'
  //   Sum: '<S35>/Sum'

  test_RPY_B.numAccum = floor((((test_RPY_DW.lastSin_c *
    test_RPY_P.SineWave1_PCos + test_RPY_DW.lastCos_e *
    test_RPY_P.SineWave1_PSin) * test_RPY_P.SineWave1_HCos +
    (test_RPY_DW.lastCos_e * test_RPY_P.SineWave1_PCos - test_RPY_DW.lastSin_c *
     test_RPY_P.SineWave1_PSin) * test_RPY_P.SineWave1_Hsin) *
    test_RPY_P.SineWave1_Amp + test_RPY_P.SineWave1_Bias) +
    test_RPY_P.Constant_Value_c);
  if (rtIsNaN(test_RPY_B.numAccum) || rtIsInf(test_RPY_B.numAccum)) {
    test_RPY_B.numAccum = 0.0;
  } else {
    test_RPY_B.numAccum = fmod(test_RPY_B.numAccum, 65536.0);
  }

  rtb_DataTypeConversion1_fx = static_cast<uint16_T>(test_RPY_B.numAccum < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-test_RPY_B.numAccum)))) : static_cast<int32_T>(
    static_cast<uint16_T>(test_RPY_B.numAccum)));

  // End of DataTypeConversion: '<S35>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave2'
  if (test_RPY_DW.systemEnable_o1 != 0) {
    test_RPY_B.ph_meas = test_RPY_P.SineWave2_Freq * test_RPY_B.DigitalClock1;
    test_RPY_DW.lastSin_f = sin(test_RPY_B.ph_meas);
    test_RPY_DW.lastCos_b = cos(test_RPY_B.ph_meas);
    test_RPY_DW.systemEnable_o1 = 0;
  }

  // DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
  //   Constant: '<S36>/Constant'
  //   Sin: '<Root>/Sine Wave2'
  //   Sum: '<S36>/Sum'

  test_RPY_B.numAccum = floor((((test_RPY_DW.lastSin_f *
    test_RPY_P.SineWave2_PCos + test_RPY_DW.lastCos_b *
    test_RPY_P.SineWave2_PSin) * test_RPY_P.SineWave2_HCos +
    (test_RPY_DW.lastCos_b * test_RPY_P.SineWave2_PCos - test_RPY_DW.lastSin_f *
     test_RPY_P.SineWave2_PSin) * test_RPY_P.SineWave2_Hsin) *
    test_RPY_P.SineWave2_Amp + test_RPY_P.SineWave2_Bias) +
    test_RPY_P.Constant_Value_h0);
  if (rtIsNaN(test_RPY_B.numAccum) || rtIsInf(test_RPY_B.numAccum)) {
    test_RPY_B.numAccum = 0.0;
  } else {
    test_RPY_B.numAccum = fmod(test_RPY_B.numAccum, 65536.0);
  }

  rtb_DataTypeConversion1_a = static_cast<uint16_T>(test_RPY_B.numAccum < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-test_RPY_B.numAccum)))) : static_cast<int32_T>(
    static_cast<uint16_T>(test_RPY_B.numAccum)));

  // End of DataTypeConversion: '<S36>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave3'
  if (test_RPY_DW.systemEnable_j != 0) {
    test_RPY_B.ph_meas = test_RPY_P.SineWave3_Freq * test_RPY_B.DigitalClock1;
    test_RPY_DW.lastSin_m = sin(test_RPY_B.ph_meas);
    test_RPY_DW.lastCos_k = cos(test_RPY_B.ph_meas);
    test_RPY_DW.systemEnable_j = 0;
  }

  // DataTypeConversion: '<S37>/Data Type Conversion1' incorporates:
  //   Constant: '<S37>/Constant'
  //   Sin: '<Root>/Sine Wave3'
  //   Sum: '<S37>/Sum'

  test_RPY_B.numAccum = floor((((test_RPY_DW.lastSin_m *
    test_RPY_P.SineWave3_PCos + test_RPY_DW.lastCos_k *
    test_RPY_P.SineWave3_PSin) * test_RPY_P.SineWave3_HCos +
    (test_RPY_DW.lastCos_k * test_RPY_P.SineWave3_PCos - test_RPY_DW.lastSin_m *
     test_RPY_P.SineWave3_PSin) * test_RPY_P.SineWave3_Hsin) *
    test_RPY_P.SineWave3_Amp + test_RPY_P.SineWave3_Bias) +
    test_RPY_P.Constant_Value_op);
  if (rtIsNaN(test_RPY_B.numAccum) || rtIsInf(test_RPY_B.numAccum)) {
    test_RPY_B.numAccum = 0.0;
  } else {
    test_RPY_B.numAccum = fmod(test_RPY_B.numAccum, 65536.0);
  }

  rtb_DataTypeConversion1_j = static_cast<uint16_T>(test_RPY_B.numAccum < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-test_RPY_B.numAccum)))) : static_cast<int32_T>(
    static_cast<uint16_T>(test_RPY_B.numAccum)));

  // End of DataTypeConversion: '<S37>/Data Type Conversion1'

  // Update for IfAction SubSystem: '<S40>/If Action Subsystem2' incorporates:
  //   ActionPort: '<S43>/Action Port'

  // Update for If: '<S40>/If'
  srUpdateBC(test_RPY_DW.IfActionSubsystem2_SubsysRanBC);

  // End of Update for SubSystem: '<S40>/If Action Subsystem2'

  // MATLAB Function: '<Root>/correct sequence' incorporates:
  //   Fcn: '<S9>/fcn1'
  //   Fcn: '<S9>/fcn2'
  //   Fcn: '<S9>/fcn4'
  //   Fcn: '<S9>/fcn5'
  //   Trigonometry: '<S38>/Trigonometric Function1'
  //   Trigonometry: '<S38>/Trigonometric Function3'
  //   Trigonometry: '<S38>/trigFcn'

  test_RPY_B.y_o[0] = (rtNaNF);
  test_RPY_B.y_o[1] = (rtNaNF);
  test_RPY_B.y_o[2] = (rtNaNF);

  // MATLABSystem: '<S18>/SourceBlock'
  b_varargout_1 = uORB_read_step(test_RPY_DW.obj_d.orbMetadataObj,
    &test_RPY_DW.obj_d.eventStructObj, &test_RPY_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S19>/In1'
    test_RPY_B.In1_o = test_RPY_B.b_varargout_2_cx;
    srUpdateBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of MATLABSystem: '<S18>/SourceBlock'
  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // MATLABSystem: '<S14>/SourceBlock'
  b_varargout_1 = uORB_read_step(test_RPY_DW.obj_o.orbMetadataObj,
    &test_RPY_DW.obj_o.eventStructObj, &test_RPY_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S15>/In1'
    test_RPY_B.In1_m = test_RPY_B.b_varargout_2_k;
    srUpdateBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of MATLABSystem: '<S14>/SourceBlock'
  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // MATLABSystem: '<S12>/SourceBlock'
  b_varargout_1 = uORB_read_step(test_RPY_DW.obj_a.orbMetadataObj,
    &test_RPY_DW.obj_a.eventStructObj, &test_RPY_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    test_RPY_B.In1_l = test_RPY_B.b_varargout_2_c;
    srUpdateBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S12>/SourceBlock'
  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  test_RPY_B.z = test_RPY_B.In1_l.z;

  // SignalConversion generated from: '<S1>/Bus Selector'
  test_RPY_B.y_n = test_RPY_B.In1_l.y;

  // DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  test_RPY_B.wq1 = test_RPY_P.DiscreteTransferFcn1_NumCoef *
    test_RPY_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'
  test_RPY_B.numAccum = test_RPY_P.DiscreteTransferFcn2_NumCoef *
    test_RPY_DW.DiscreteTransferFcn2_states;

  // MATLAB Function: '<S7>/RP_computation' incorporates:
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'

  test_RPY_B.ph_meas = rt_atan2d_snf(-test_RPY_B.wq1, -test_RPY_B.numAccum);
  test_RPY_B.RP_meas[0] = test_RPY_B.ph_meas;
  test_RPY_B.RP_meas[1] = rt_atan2d_snf(test_RPY_P.DiscreteTransferFcn_NumCoef *
    test_RPY_DW.DiscreteTransferFcn_states, -test_RPY_B.wq1 * sin
    (test_RPY_B.ph_meas) + -test_RPY_B.numAccum * cos(test_RPY_B.ph_meas));

  // MATLAB Function: '<S21>/EKF_RP' incorporates:
  //   Delay: '<S21>/Delay2'
  //   Memory: '<S21>/Memory2'
  //   Memory: '<S21>/Memory3'

  if (test_RPY_B.DigitalClock1 - test_RPY_DW.Memory2_PreviousInput >=
      test_RPY_P.Ts_EKF_meas) {
    test_RPY_DW.Memory2_PreviousInput = test_RPY_B.DigitalClock1;
    memcpy(&test_RPY_B.Pt1[0], &test_RPY_DW.Memory3_PreviousInput[0], 25U *
           sizeof(real_T));
    test_RPY_B.wq1 = test_RPY_DW.Delay2_DSTATE[1];
    test_RPY_B.wr1 = test_RPY_DW.Delay2_DSTATE[2];
    for (i = 0; i < 5; i++) {
      test_RPY_B.xt[i] = 0.0;
    }

    memset(&test_RPY_B.Pt[0], 0, 25U * sizeof(real_T));
    b = static_cast<int32_T>(floor(test_RPY_P.Ts_EKF_meas /
      test_RPY_P.Ts_EKF_integr));
    for (i = 0; i < b; i++) {
      test_RPY_B.cph = cos(test_RPY_DW.Memory4_PreviousInput[0]);
      test_RPY_B.cth = cos(test_RPY_DW.Memory4_PreviousInput[1]);
      test_RPY_B.sph = sin(test_RPY_DW.Memory4_PreviousInput[0]);
      test_RPY_B.tth = sin(test_RPY_DW.Memory4_PreviousInput[1]) /
        test_RPY_B.cth;
      test_RPY_B.dv[0] = 1.0;
      test_RPY_B.numAccum = test_RPY_B.sph * test_RPY_B.tth;
      test_RPY_B.dv[5] = test_RPY_B.numAccum;
      tmp = test_RPY_B.cph * test_RPY_B.tth;
      test_RPY_B.dv[10] = tmp;
      test_RPY_B.dv[15] = 0.0;
      test_RPY_B.dv[20] = 0.0;
      test_RPY_B.dv[25] = 0.0;
      test_RPY_B.dv[1] = 0.0;
      test_RPY_B.dv[6] = test_RPY_B.cph;
      test_RPY_B.dv[11] = -test_RPY_B.sph;
      test_RPY_B.dv[16] = 0.0;
      test_RPY_B.dv[21] = 0.0;
      test_RPY_B.dv[26] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        test_RPY_B.dv[5 * i_0 + 2] = 0.0;
        test_RPY_B.dv[5 * i_0 + 3] = 0.0;
        test_RPY_B.dv[5 * i_0 + 4] = 0.0;
      }

      test_RPY_B.dv2[0] = test_RPY_DW.Delay2_DSTATE[0] -
        test_RPY_DW.Memory4_PreviousInput[2];
      test_RPY_B.Pt_c = test_RPY_B.wq1 - test_RPY_DW.Memory4_PreviousInput[3];
      test_RPY_B.dv2[1] = test_RPY_B.Pt_c;
      tmp_0 = test_RPY_B.wr1 - test_RPY_DW.Memory4_PreviousInput[4];
      test_RPY_B.dv2[2] = tmp_0;
      test_RPY_B.dv2[3] = test_RPY_DW.Memory4_PreviousInput[2];
      test_RPY_B.dv2[4] = test_RPY_DW.Memory4_PreviousInput[3];
      test_RPY_B.dv2[5] = test_RPY_DW.Memory4_PreviousInput[4];
      test_RPY_B.Pt[0] = tmp * test_RPY_B.Pt_c - test_RPY_B.numAccum * tmp_0;
      test_RPY_B.numAccum = tmp_0 * test_RPY_B.cph;
      test_RPY_B.Pt[5] = (test_RPY_B.Pt_c * test_RPY_B.sph + test_RPY_B.numAccum)
        / (test_RPY_B.cth * test_RPY_B.cth);
      test_RPY_B.Pt[10] = -1.0;
      test_RPY_B.Pt[15] = -test_RPY_B.sph * test_RPY_B.tth;
      test_RPY_B.Pt[20] = -test_RPY_B.cph * test_RPY_B.tth;
      test_RPY_B.Pt[1] = test_RPY_B.Pt_c * -test_RPY_B.sph - test_RPY_B.numAccum;
      test_RPY_B.Pt[6] = 0.0;
      test_RPY_B.Pt[11] = 0.0;
      test_RPY_B.Pt[16] = -test_RPY_B.cph;
      test_RPY_B.Pt[21] = test_RPY_B.sph;
      for (i_0 = 0; i_0 < 5; i_0++) {
        test_RPY_B.numAccum = 0.0;
        for (r1 = 0; r1 < 6; r1++) {
          test_RPY_B.numAccum += test_RPY_B.dv[5 * r1 + i_0] * test_RPY_B.dv2[r1];
        }

        test_RPY_B.xt[i_0] = test_RPY_P.Ts_EKF_integr * test_RPY_B.numAccum +
          test_RPY_DW.Memory4_PreviousInput[i_0];
        test_RPY_B.Pt[5 * i_0 + 2] = 0.0;
        test_RPY_B.Pt[5 * i_0 + 3] = 0.0;
        test_RPY_B.Pt[5 * i_0 + 4] = 0.0;
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        for (r1 = 0; r1 < 5; r1++) {
          test_RPY_B.numAccum = 0.0;
          test_RPY_B.tth = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i_0;
            test_RPY_B.numAccum += test_RPY_B.Pt1[5 * r1 + Pt1_tmp] *
              test_RPY_B.Pt[At1_tmp];
            test_RPY_B.tth += test_RPY_B.Pt[5 * Pt1_tmp + r1] *
              test_RPY_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * r1 + i_0;
          test_RPY_B.Pt1_m[Pt1_tmp] = test_RPY_B.tth;
          test_RPY_B.At1[Pt1_tmp] = test_RPY_B.numAccum;
        }
      }

      for (i_0 = 0; i_0 < 25; i_0++) {
        test_RPY_B.Pt[i_0] = ((test_RPY_B.At1[i_0] + test_RPY_B.Pt1_m[i_0]) +
                              test_RPY_P.Q_phth[i_0]) * test_RPY_P.Ts_EKF_integr
          + test_RPY_B.Pt1[i_0];
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        test_RPY_DW.Memory4_PreviousInput[i_0] = test_RPY_B.xt[i_0];
      }

      memcpy(&test_RPY_B.Pt1[0], &test_RPY_B.Pt[0], 25U * sizeof(real_T));
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      test_RPY_B.Lk[i_0] = c[i_0];
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (r1 = 0; r1 < 5; r1++) {
        test_RPY_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          test_RPY_B.wq1 += test_RPY_B.Pt[5 * Pt1_tmp + r1] * test_RPY_B.Lk[5 *
            i_0 + Pt1_tmp];
        }

        test_RPY_B.B[r1 + 5 * i_0] = test_RPY_B.wq1;
      }
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      test_RPY_B.A_tmp_p[i_0] = b_b[i_0];
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (r1 = 0; r1 < 5; r1++) {
        test_RPY_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          test_RPY_B.wq1 += static_cast<real_T>(test_RPY_B.A_tmp_p[(Pt1_tmp << 1)
            + i_0]) * test_RPY_B.Pt[5 * r1 + Pt1_tmp];
        }

        test_RPY_B.A_tmp[i_0 + (r1 << 1)] = test_RPY_B.wq1;
      }

      for (r1 = 0; r1 < 2; r1++) {
        test_RPY_B.numAccum = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          test_RPY_B.numAccum += test_RPY_B.A_tmp[(Pt1_tmp << 1) + i_0] *
            test_RPY_B.Lk[5 * r1 + Pt1_tmp];
        }

        i = (r1 << 1) + i_0;
        test_RPY_B.A[i] = test_RPY_P.R_phth[i] + test_RPY_B.numAccum;
      }
    }

    if (fabs(test_RPY_B.A[1]) > fabs(test_RPY_B.A[0])) {
      r1 = 1;
      i = 0;
    } else {
      r1 = 0;
      i = 1;
    }

    test_RPY_B.wq1 = test_RPY_B.A[i] / test_RPY_B.A[r1];
    test_RPY_B.numAccum = test_RPY_B.A[r1 + 2];
    test_RPY_B.tth = test_RPY_B.A[i + 2] - test_RPY_B.numAccum * test_RPY_B.wq1;
    for (i_0 = 0; i_0 < 5; i_0++) {
      Pt1_tmp = 5 * r1 + i_0;
      test_RPY_B.Lk[Pt1_tmp] = test_RPY_B.B[i_0] / test_RPY_B.A[r1];
      b = 5 * i + i_0;
      test_RPY_B.Lk[b] = (test_RPY_B.B[i_0 + 5] - test_RPY_B.Lk[Pt1_tmp] *
                          test_RPY_B.numAccum) / test_RPY_B.tth;
      test_RPY_B.Lk[Pt1_tmp] -= test_RPY_B.Lk[b] * test_RPY_B.wq1;
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      test_RPY_B.numAccum = 0.0;
      for (r1 = 0; r1 < 5; r1++) {
        test_RPY_B.numAccum += static_cast<real_T>(test_RPY_B.A_tmp_p[(r1 << 1)
          + i_0]) * test_RPY_B.xt[r1];
      }

      test_RPY_B.RP_meas_b[i_0] = test_RPY_B.RP_meas[i_0] - test_RPY_B.numAccum;
    }

    test_RPY_B.wq1 = test_RPY_B.RP_meas_b[1];
    test_RPY_B.numAccum = test_RPY_B.RP_meas_b[0];
    for (i_0 = 0; i_0 < 5; i_0++) {
      test_RPY_DW.Memory4_PreviousInput[i_0] = (test_RPY_B.Lk[i_0 + 5] *
        test_RPY_B.wq1 + test_RPY_B.Lk[i_0] * test_RPY_B.numAccum) +
        test_RPY_B.xt[i_0];
    }

    memset(&test_RPY_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i_0 = 0; i_0 < 5; i_0++) {
      test_RPY_B.Pt1[i_0 + 5 * i_0] = 1.0;
    }

    for (i_0 = 0; i_0 < 5; i_0++) {
      test_RPY_B.numAccum = test_RPY_B.Lk[i_0 + 5];
      test_RPY_B.wq1 = test_RPY_B.Lk[i_0];
      for (r1 = 0; r1 < 5; r1++) {
        Pt1_tmp = r1 << 1;
        i = 5 * r1 + i_0;
        test_RPY_B.Pt1_m[i] = test_RPY_B.Pt1[i] - (static_cast<real_T>
          (test_RPY_B.A_tmp_p[Pt1_tmp + 1]) * test_RPY_B.numAccum +
          static_cast<real_T>(test_RPY_B.A_tmp_p[Pt1_tmp]) * test_RPY_B.wq1);
      }

      for (r1 = 0; r1 < 5; r1++) {
        test_RPY_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          test_RPY_B.wq1 += test_RPY_B.Pt1_m[5 * Pt1_tmp + i_0] * test_RPY_B.Pt
            [5 * r1 + Pt1_tmp];
        }

        test_RPY_DW.Memory3_PreviousInput[i_0 + 5 * r1] = test_RPY_B.wq1;
      }
    }
  }

  // End of MATLAB Function: '<S21>/EKF_RP'

  // MATLAB Function: '<S21>/MATLAB Function'
  test_RPY_B.bias_w_b_estim[0] = test_RPY_DW.Memory4_PreviousInput[2];
  test_RPY_B.bias_w_b_estim[1] = test_RPY_DW.Memory4_PreviousInput[3];
  test_RPY_B.bias_w_b_estim[2] = test_RPY_DW.Memory4_PreviousInput[4];

  // MATLAB Function: '<S7>/Y_computation' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion3'
  //   MATLAB Function: '<S21>/MATLAB Function'
  //   MATLAB Function: '<S23>/EKF_Y'
  //   MATLAB Function: '<S7>/RPY_dot_computation'

  test_RPY_B.wr1 = sin(test_RPY_DW.Memory4_PreviousInput[0]);
  test_RPY_B.cph = cos(test_RPY_DW.Memory4_PreviousInput[0]);
  test_RPY_B.tth = sin(test_RPY_DW.Memory4_PreviousInput[1]);
  test_RPY_B.cth = cos(test_RPY_DW.Memory4_PreviousInput[1]);
  test_RPY_B.wq1 = rt_atan2d_snf(test_RPY_B.In1_o.z * test_RPY_B.wr1 -
    test_RPY_B.In1_o.y * test_RPY_B.cph, (test_RPY_B.In1_o.y * test_RPY_B.tth *
    test_RPY_B.wr1 + test_RPY_B.In1_o.x * test_RPY_B.cth) + test_RPY_B.In1_o.z *
    test_RPY_B.tth * test_RPY_B.cph);
  if (test_RPY_B.wq1 < 0.0) {
    test_RPY_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S23>/EKF_Y' incorporates:
  //   Delay: '<S23>/Delay2'
  //   MATLAB Function: '<S7>/Y_computation'
  //   Memory: '<S23>/Memory2'

  if (test_RPY_B.DigitalClock1 - test_RPY_DW.Memory2_PreviousInput_n >=
      test_RPY_P.Ts_EKF_meas) {
    test_RPY_DW.Memory2_PreviousInput_n = test_RPY_B.DigitalClock1;
    test_RPY_B.sph = 0.0;
    test_RPY_B.Pt_c = 0.0;
    b = static_cast<int32_T>(floor(test_RPY_P.Ts_EKF_meas /
      test_RPY_P.Ts_EKF_integr));
    if (b - 1 >= 0) {
      test_RPY_B.dv3[0] = 0.0;
      test_RPY_B.dv3[1] = test_RPY_B.wr1 / test_RPY_B.cth;
      test_RPY_B.dv3[2] = test_RPY_B.cph / test_RPY_B.cth;
      test_RPY_B.dv3[3] = 0.0;
      test_RPY_B.dv3[4] = 0.0;
      test_RPY_B.dv3[5] = 0.0;
      test_RPY_B.dv4[0] = test_RPY_DW.Delay2_DSTATE_l[0] -
        test_RPY_B.bias_w_b_estim[0];
      test_RPY_B.dv4[1] = test_RPY_DW.Delay2_DSTATE_l[1] -
        test_RPY_B.bias_w_b_estim[1];
      test_RPY_B.dv4[2] = test_RPY_DW.Delay2_DSTATE_l[2] -
        test_RPY_B.bias_w_b_estim[2];
      test_RPY_B.dv4[3] = test_RPY_B.bias_w_b_estim[0];
      test_RPY_B.dv4[4] = test_RPY_B.bias_w_b_estim[1];
      test_RPY_B.dv4[5] = test_RPY_B.bias_w_b_estim[2];
    }

    for (i = 0; i < b; i++) {
      test_RPY_B.numAccum = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        test_RPY_B.numAccum += test_RPY_B.dv3[i_0] * test_RPY_B.dv4[i_0];
      }

      test_RPY_B.sph = test_RPY_P.Ts_EKF_integr * test_RPY_B.numAccum +
        test_RPY_DW.Memory4_PreviousInput_l;
      test_RPY_B.Pt_c = ((0.0 * test_RPY_DW.Memory3_PreviousInput_i +
                          test_RPY_DW.Memory3_PreviousInput_i * 0.0) +
                         test_RPY_P.q_ps) * test_RPY_P.Ts_EKF_integr +
        test_RPY_DW.Memory3_PreviousInput_i;
      test_RPY_DW.Memory4_PreviousInput_l = test_RPY_B.sph;
      test_RPY_DW.Memory3_PreviousInput_i = test_RPY_B.Pt_c;
    }

    test_RPY_B.numAccum = test_RPY_B.Pt_c / (test_RPY_B.Pt_c + test_RPY_P.r_ps);
    test_RPY_DW.Memory4_PreviousInput_l = (test_RPY_B.wq1 - test_RPY_B.sph) *
      test_RPY_B.numAccum + test_RPY_B.sph;
    test_RPY_DW.Memory3_PreviousInput_i = (1.0 - test_RPY_B.numAccum) *
      test_RPY_B.Pt_c;
  }

  // MATLAB Function: '<S3>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion2'

  test_RPY_B.y[0] = test_RPY_B.In1_m.x;
  test_RPY_B.y[1] = -static_cast<real_T>(test_RPY_B.In1_m.y);
  test_RPY_B.y[2] = -static_cast<real_T>(test_RPY_B.In1_m.z);

  // Gain: '<S3>/Gain1'
  test_RPY_B.numAccum = test_RPY_B.y[1];
  test_RPY_B.sph = test_RPY_B.y[0];
  test_RPY_B.Pt_c = test_RPY_B.y[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    // Delay: '<S21>/Delay2'
    test_RPY_DW.Delay2_DSTATE[i_0] = (test_RPY_P.Rz[i_0 + 3] *
      test_RPY_B.numAccum + test_RPY_P.Rz[i_0] * test_RPY_B.sph) +
      test_RPY_P.Rz[i_0 + 6] * test_RPY_B.Pt_c;
  }

  // End of Gain: '<S3>/Gain1'

  // MATLAB Function: '<S7>/RPY_dot_computation' incorporates:
  //   Constant: '<S7>/Constant6'
  //   Delay: '<S21>/Delay2'
  //   MATLAB Function: '<S7>/Y_computation'
  //   Memory: '<S7>/Memory5'

  if ((test_RPY_B.DigitalClock1 - test_RPY_DW.Memory5_PreviousInput >=
       test_RPY_P.Ts_EKF_meas) || (test_RPY_B.DigitalClock1 == 0.0)) {
    test_RPY_B.tth /= test_RPY_B.cth;
    test_RPY_DW.Memory5_PreviousInput = test_RPY_B.DigitalClock1;
    test_RPY_B.dv1[0] = 1.0;
    test_RPY_B.dv1[3] = test_RPY_B.wr1 * test_RPY_B.tth;
    test_RPY_B.dv1[6] = test_RPY_B.cph * test_RPY_B.tth;
    test_RPY_B.dv1[1] = 0.0;
    test_RPY_B.dv1[4] = test_RPY_B.cph;
    test_RPY_B.dv1[7] = -test_RPY_B.wr1;
    test_RPY_B.dv1[2] = 0.0;
    test_RPY_B.dv1[5] = test_RPY_B.wr1 / test_RPY_B.cth;
    test_RPY_B.dv1[8] = test_RPY_B.cph / test_RPY_B.cth;
    test_RPY_B.numAccum = test_RPY_DW.Delay2_DSTATE[0] -
      test_RPY_B.bias_w_b_estim[0] * 0.0;
    test_RPY_B.tth = test_RPY_DW.Delay2_DSTATE[1] - test_RPY_B.bias_w_b_estim[1]
      * 0.0;
    test_RPY_B.wr1 = test_RPY_DW.Delay2_DSTATE[2] - test_RPY_B.bias_w_b_estim[2]
      * 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      test_RPY_DW.Memory6_PreviousInput[i_0] = (test_RPY_B.dv1[i_0 + 3] *
        test_RPY_B.tth + test_RPY_B.dv1[i_0] * test_RPY_B.numAccum) +
        test_RPY_B.dv1[i_0 + 6] * test_RPY_B.wr1;
    }
  }

  // ManualSwitch: '<Root>/Manual Switch1'
  if (test_RPY_P.ManualSwitch1_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Constant5'

    for (i = 0; i < 25; i++) {
      test_RPY_B.ManualSwitch1[i] = test_RPY_P.Constant5_Value;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   DataTypeConversion: '<S29>/Data Type Conversion1'
    //   DataTypeConversion: '<S29>/Data Type Conversion2'
    //   DataTypeConversion: '<S29>/Data Type Conversion3'
    //   DataTypeConversion: '<S29>/Data Type Conversion4'
    //   DataTypeConversion: '<S29>/Data Type Conversion5'
    //   MATLAB Function: '<S21>/MATLAB Function'
    //   MATLAB Function: '<S23>/EKF_Y'
    //   MATLAB Function: '<S29>/MATLAB Function'
    //   SignalConversion generated from: '<S32>/ SFunction '

    test_RPY_B.ManualSwitch1[0] = rtb_DataTypeConversion1_n;
    test_RPY_B.ManualSwitch1[1] = rtb_DataTypeConversion1_fx;
    test_RPY_B.ManualSwitch1[2] = rtb_DataTypeConversion1_a;
    test_RPY_B.ManualSwitch1[3] = rtb_DataTypeConversion1_j;
    test_RPY_B.ManualSwitch1[4] = test_RPY_B.In1_l.x;
    test_RPY_B.ManualSwitch1[5] = test_RPY_B.y_n;
    test_RPY_B.ManualSwitch1[6] = test_RPY_B.z;
    test_RPY_B.ManualSwitch1[7] = test_RPY_B.In1_m.x;
    test_RPY_B.ManualSwitch1[8] = test_RPY_B.In1_m.y;
    test_RPY_B.ManualSwitch1[9] = test_RPY_B.In1_m.z;
    test_RPY_B.ManualSwitch1[10] = 0.0F;
    test_RPY_B.ManualSwitch1[11] = 0.0F;
    test_RPY_B.ManualSwitch1[12] = 0.0F;
    test_RPY_B.ManualSwitch1[13] = (rtNaN);
    test_RPY_B.ManualSwitch1[14] = (rtNaN);
    test_RPY_B.ManualSwitch1[15] = (rtNaN);
    test_RPY_B.ManualSwitch1[16] = test_RPY_B.In1_o.x;
    test_RPY_B.ManualSwitch1[17] = test_RPY_B.In1_o.y;
    test_RPY_B.ManualSwitch1[18] = test_RPY_B.In1_o.z;
    test_RPY_B.ManualSwitch1[19] = test_RPY_DW.Memory4_PreviousInput[0];
    test_RPY_B.ManualSwitch1[20] = test_RPY_DW.Memory4_PreviousInput[1];
    test_RPY_B.ManualSwitch1[21] = test_RPY_DW.Memory4_PreviousInput_l;
    test_RPY_B.ManualSwitch1[22] = test_RPY_DW.Memory6_PreviousInput[0];
    test_RPY_B.ManualSwitch1[23] = test_RPY_DW.Memory6_PreviousInput[1];
    test_RPY_B.ManualSwitch1[24] = test_RPY_DW.Memory6_PreviousInput[2];
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // SignalConversion generated from: '<Root>/To Workspace1'
  test_RPY_B.TmpSignalConversionAt_asyncqueu[0] = test_RPY_B.DigitalClock1;
  memcpy(&test_RPY_B.TmpSignalConversionAt_asyncqueu[1],
         &test_RPY_B.ManualSwitch1[0], 25U * sizeof(real_T));

  // Gain: '<S10>/Gain2' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function'

  test_RPY_B.DataTypeConversion3[0] = test_RPY_P.Gain2_Gain *
    test_RPY_DW.Memory4_PreviousInput[0];

  // Gain: '<S10>/Gain1' incorporates:
  //   MATLAB Function: '<S10>/MATLAB Function2'
  //   SignalConversion generated from: '<S47>/ SFunction '

  test_RPY_B.Gain1_b[0] = test_RPY_P.Gain1_Gain *
    test_RPY_DW.Memory6_PreviousInput[0];

  // Gain: '<S10>/Gain2' incorporates:
  //   MATLAB Function: '<S21>/MATLAB Function'

  test_RPY_B.DataTypeConversion3[1] = test_RPY_P.Gain2_Gain *
    test_RPY_DW.Memory4_PreviousInput[1];

  // Gain: '<S10>/Gain1' incorporates:
  //   MATLAB Function: '<S10>/MATLAB Function2'
  //   SignalConversion generated from: '<S47>/ SFunction '

  test_RPY_B.Gain1_b[1] = test_RPY_P.Gain1_Gain *
    test_RPY_DW.Memory6_PreviousInput[1];

  // Gain: '<S10>/Gain2' incorporates:
  //   MATLAB Function: '<S23>/EKF_Y'

  test_RPY_B.DataTypeConversion3[2] = test_RPY_P.Gain2_Gain *
    test_RPY_DW.Memory4_PreviousInput_l;

  // Gain: '<S10>/Gain1' incorporates:
  //   MATLAB Function: '<S10>/MATLAB Function2'
  //   SignalConversion generated from: '<S47>/ SFunction '

  test_RPY_B.Gain1_b[2] = test_RPY_P.Gain1_Gain *
    test_RPY_DW.Memory6_PreviousInput[2];

  // Gain: '<Root>/Gain' incorporates:
  //   MATLAB Function: '<S7>/RP_computation'
  //   MATLAB Function: '<S7>/Y_computation'

  test_RPY_B.Gain[0] = test_RPY_P.Gain_Gain * test_RPY_B.ph_meas;
  test_RPY_B.Gain[1] = test_RPY_P.Gain_Gain * test_RPY_B.RP_meas[1];
  test_RPY_B.Gain[2] = test_RPY_P.Gain_Gain * test_RPY_B.wq1;

  // Constant: '<Root>/Constant2'
  test_RPY_B.IMU_mf_b_bias[0] = test_RPY_P.IMU_w_b_bias[0];
  test_RPY_B.IMU_mf_b_bias[1] = test_RPY_P.IMU_w_b_bias[1];
  test_RPY_B.IMU_mf_b_bias[2] = test_RPY_P.IMU_w_b_bias[2];

  // MATLAB Function: '<S3>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S3>/Data Type Conversion1'

  test_RPY_B.y_j[0] = -static_cast<real_T>(test_RPY_B.In1_l.x);
  test_RPY_B.y_j[1] = test_RPY_B.y_n;
  test_RPY_B.y_j[2] = test_RPY_B.z;

  // Gain: '<S3>/Gain'
  test_RPY_B.ph_meas = test_RPY_B.y_j[1];
  test_RPY_B.wq1 = test_RPY_B.y_j[0];
  test_RPY_B.numAccum = test_RPY_B.y_j[2];
  for (i = 0; i < 3; i++) {
    // Gain: '<S3>/Gain'
    test_RPY_B.DataTypeConversion1[i] = (test_RPY_P.Rz[i + 3] *
      test_RPY_B.ph_meas + test_RPY_P.Rz[i] * test_RPY_B.wq1) + test_RPY_P.Rz[i
      + 6] * test_RPY_B.numAccum;
  }

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  test_RPY_B.y1_ky = (rtNaNF);
  test_RPY_B.y2_k = (rtNaNF);
  test_RPY_B.y3_k = (rtNaNF);

  // MATLAB Function: '<Root>/MATLAB Function1'
  test_RPY_MATLABFunction1(test_RPY_B.Gain, &test_RPY_B.y1_k3, &test_RPY_B.y2_n,
    &test_RPY_B.y3_h, &test_RPY_DW.sf_MATLABFunction1_f);

  // MATLAB Function: '<S10>/MATLAB Function7'
  test_RPY_MATLABFunction1(test_RPY_B.DataTypeConversion3, &test_RPY_B.y1,
    &test_RPY_B.y2, &test_RPY_B.y3, &test_RPY_DW.sf_MATLABFunction7);

  // MATLAB Function: '<S10>/MATLAB Function1'
  test_RPY_MATLABFunction1(test_RPY_B.Gain1_b, &test_RPY_B.y1_p,
    &test_RPY_B.y2_b, &test_RPY_B.y3_g, &test_RPY_DW.sf_MATLABFunction1_e);

  // MATLABSystem: '<S8>/PX4 PWM Output'
  for (i_0 = 0; i_0 < 8; i_0++) {
    test_RPY_B.pwmValue[i_0] = 0U;
  }

  test_RPY_B.pwmValue[0] = rtb_DataTypeConversion1_n;
  test_RPY_B.pwmValue[1] = rtb_DataTypeConversion1_fx;
  test_RPY_B.pwmValue[2] = rtb_DataTypeConversion1_a;
  test_RPY_B.pwmValue[3] = rtb_DataTypeConversion1_j;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/Constant'

  if (test_RPY_P.startingswitch_CurrentSetting == 1) {
    b_varargout_1 = test_RPY_P.Constant_Value_e;
  } else {
    b_varargout_1 = test_RPY_P.ARMPWM_Value;
  }

  // MATLABSystem: '<S8>/PX4 PWM Output' incorporates:
  //   Constant: '<S8>/failsafe'
  //   ManualSwitch: '<Root>/starting switch'

  if (b_varargout_1) {
    if (!test_RPY_DW.obj_l.isArmed) {
      test_RPY_DW.obj_l.isArmed = true;
      rtb_DataTypeConversion1_n = pwm_arm(&test_RPY_DW.obj_l.pwmDevHandler,
        &test_RPY_DW.obj_l.armAdvertiseObj);
      test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
        (test_RPY_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    }

    rtb_DataTypeConversion1_n = pwm_setServo(&test_RPY_DW.obj_l.pwmDevHandler,
      test_RPY_DW.obj_l.servoCount, test_RPY_DW.obj_l.channelMask,
      &test_RPY_B.pwmValue[0], test_RPY_DW.obj_l.isMain,
      &test_RPY_DW.obj_l.actuatorAdvertiseObj);
    test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
      (test_RPY_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  } else {
    rtb_DataTypeConversion1_n = pwm_disarm(&test_RPY_DW.obj_l.pwmDevHandler,
      &test_RPY_DW.obj_l.armAdvertiseObj);
    test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
      (test_RPY_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    test_RPY_DW.obj_l.isArmed = false;
    rtb_DataTypeConversion1_n = pwm_resetServo(&test_RPY_DW.obj_l.pwmDevHandler,
      test_RPY_DW.obj_l.servoCount, test_RPY_DW.obj_l.channelMask,
      test_RPY_DW.obj_l.isMain, &test_RPY_DW.obj_l.actuatorAdvertiseObj);
    test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
      (test_RPY_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  if (test_RPY_DW.obj_l.isMain) {
    rtb_DataTypeConversion1_n = pwm_forceFailsafe
      (&test_RPY_DW.obj_l.pwmDevHandler, static_cast<int32_T>
       (test_RPY_P.failsafe_Value));
    test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
      (test_RPY_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  // MATLABSystem: '<S30>/SourceBlock'
  b_varargout_1 = uORB_read_step(test_RPY_DW.obj.orbMetadataObj,
    &test_RPY_DW.obj.eventStructObj, &test_RPY_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S33>/In1'
    test_RPY_B.In1 = test_RPY_B.b_varargout_2;
    srUpdateBC(test_RPY_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S30>/SourceBlock'
  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'

  // SignalConversion: '<S8>/Signal Conversion'
  test_RPY_B.SignalConversion[0] = test_RPY_B.In1.output[0];
  test_RPY_B.SignalConversion[1] = test_RPY_B.In1.output[1];

  // Update for Sin: '<Root>/Sine Wave'
  test_RPY_B.ph_meas = test_RPY_DW.lastSin;
  test_RPY_DW.lastSin = test_RPY_DW.lastSin * test_RPY_P.SineWave_HCos +
    test_RPY_DW.lastCos * test_RPY_P.SineWave_Hsin;
  test_RPY_DW.lastCos = test_RPY_DW.lastCos * test_RPY_P.SineWave_HCos -
    test_RPY_B.ph_meas * test_RPY_P.SineWave_Hsin;

  // Update for Sin: '<Root>/Sine Wave1'
  test_RPY_B.ph_meas = test_RPY_DW.lastSin_c;
  test_RPY_DW.lastSin_c = test_RPY_DW.lastSin_c * test_RPY_P.SineWave1_HCos +
    test_RPY_DW.lastCos_e * test_RPY_P.SineWave1_Hsin;
  test_RPY_DW.lastCos_e = test_RPY_DW.lastCos_e * test_RPY_P.SineWave1_HCos -
    test_RPY_B.ph_meas * test_RPY_P.SineWave1_Hsin;

  // Update for Sin: '<Root>/Sine Wave2'
  test_RPY_B.ph_meas = test_RPY_DW.lastSin_f;
  test_RPY_DW.lastSin_f = test_RPY_DW.lastSin_f * test_RPY_P.SineWave2_HCos +
    test_RPY_DW.lastCos_b * test_RPY_P.SineWave2_Hsin;
  test_RPY_DW.lastCos_b = test_RPY_DW.lastCos_b * test_RPY_P.SineWave2_HCos -
    test_RPY_B.ph_meas * test_RPY_P.SineWave2_Hsin;

  // Update for Sin: '<Root>/Sine Wave3'
  test_RPY_B.ph_meas = test_RPY_DW.lastSin_m;
  test_RPY_DW.lastSin_m = test_RPY_DW.lastSin_m * test_RPY_P.SineWave3_HCos +
    test_RPY_DW.lastCos_k * test_RPY_P.SineWave3_Hsin;
  test_RPY_DW.lastCos_k = test_RPY_DW.lastCos_k * test_RPY_P.SineWave3_HCos -
    test_RPY_B.ph_meas * test_RPY_P.SineWave3_Hsin;

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  test_RPY_DW.DiscreteTransferFcn_states = (test_RPY_B.DataTypeConversion1[0] -
    test_RPY_P.DiscreteTransferFcn_DenCoef[1] *
    test_RPY_DW.DiscreteTransferFcn_states) /
    test_RPY_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  test_RPY_DW.DiscreteTransferFcn1_states = (test_RPY_B.DataTypeConversion1[1] -
    test_RPY_P.DiscreteTransferFcn1_DenCoef[1] *
    test_RPY_DW.DiscreteTransferFcn1_states) /
    test_RPY_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'
  test_RPY_DW.DiscreteTransferFcn2_states = (test_RPY_B.DataTypeConversion1[2] -
    test_RPY_P.DiscreteTransferFcn2_DenCoef[1] *
    test_RPY_DW.DiscreteTransferFcn2_states) /
    test_RPY_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S23>/Delay2' incorporates:
  //   Delay: '<S21>/Delay2'

  test_RPY_DW.Delay2_DSTATE_l[0] = test_RPY_DW.Delay2_DSTATE[0];
  test_RPY_DW.Delay2_DSTATE_l[1] = test_RPY_DW.Delay2_DSTATE[1];
  test_RPY_DW.Delay2_DSTATE_l[2] = test_RPY_DW.Delay2_DSTATE[2];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  test_RPY_M->Timing.taskTime0 =
    ((time_T)(++test_RPY_M->Timing.clockTick0)) * test_RPY_M->Timing.stepSize0;
}

// Model initialize function
void test_RPY_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(test_RPY_M, -1);
  test_RPY_M->Timing.stepSize0 = 0.01;

  // External mode info
  test_RPY_M->Sizes.checksums[0] = (940109398U);
  test_RPY_M->Sizes.checksums[1] = (3361238258U);
  test_RPY_M->Sizes.checksums[2] = (400658688U);
  test_RPY_M->Sizes.checksums[3] = (675066873U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[31];
    test_RPY_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&test_RPY_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&test_RPY_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&test_RPY_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)&test_RPY_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)&test_RPY_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&test_RPY_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&test_RPY_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_RPY_M->extModeInfo,
      &test_RPY_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_RPY_M->extModeInfo, test_RPY_M->Sizes.checksums);
    rteiSetTPtr(test_RPY_M->extModeInfo, rtmGetTPtr(test_RPY_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn' 
    test_RPY_DW.DiscreteTransferFcn_states =
      test_RPY_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1' 
    test_RPY_DW.DiscreteTransferFcn1_states =
      test_RPY_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2' 
    test_RPY_DW.DiscreteTransferFcn2_states =
      test_RPY_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Memory: '<S21>/Memory4'
    for (i = 0; i < 5; i++) {
      test_RPY_DW.Memory4_PreviousInput[i] = test_RPY_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S21>/Memory4'

    // InitializeConditions for Delay: '<S21>/Delay2'
    test_RPY_DW.Delay2_DSTATE[0] = test_RPY_P.Delay2_InitialCondition;
    test_RPY_DW.Delay2_DSTATE[1] = test_RPY_P.Delay2_InitialCondition;
    test_RPY_DW.Delay2_DSTATE[2] = test_RPY_P.Delay2_InitialCondition;

    // InitializeConditions for Memory: '<S21>/Memory2'
    test_RPY_DW.Memory2_PreviousInput = test_RPY_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S21>/Memory3'
    memcpy(&test_RPY_DW.Memory3_PreviousInput[0], &test_RPY_P.P0_phth[0], 25U *
           sizeof(real_T));

    // InitializeConditions for Memory: '<S23>/Memory4'
    test_RPY_DW.Memory4_PreviousInput_l = test_RPY_P.x0_ps;

    // InitializeConditions for Memory: '<S23>/Memory3'
    test_RPY_DW.Memory3_PreviousInput_i = test_RPY_P.P0_ps;

    // InitializeConditions for Memory: '<S23>/Memory2'
    test_RPY_DW.Memory2_PreviousInput_n = test_RPY_P.Memory2_InitialCondition_b;

    // InitializeConditions for Memory: '<S7>/Memory5'
    test_RPY_DW.Memory5_PreviousInput = test_RPY_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    test_RPY_DW.Delay2_DSTATE_l[0] = test_RPY_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S7>/Memory6'
    test_RPY_DW.Memory6_PreviousInput[0] = test_RPY_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    test_RPY_DW.Delay2_DSTATE_l[1] = test_RPY_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S7>/Memory6'
    test_RPY_DW.Memory6_PreviousInput[1] = test_RPY_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    test_RPY_DW.Delay2_DSTATE_l[2] = test_RPY_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S7>/Memory6'
    test_RPY_DW.Memory6_PreviousInput[2] = test_RPY_P.Memory6_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    test_RPY_B.In1_o = test_RPY_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S15>/In1' incorporates:
    //   Outport: '<S15>/Out1'

    test_RPY_B.In1_m = test_RPY_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    test_RPY_B.In1_l = test_RPY_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1'
    test_RPY_MATLABFunction1_Init(&test_RPY_DW.sf_MATLABFunction1_f);

    // SystemInitialize for MATLAB Function: '<S10>/MATLAB Function7'
    test_RPY_MATLABFunction1_Init(&test_RPY_DW.sf_MATLABFunction7);

    // SystemInitialize for MATLAB Function: '<S10>/MATLAB Function1'
    test_RPY_MATLABFunction1_Init(&test_RPY_DW.sf_MATLABFunction1_e);

    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S33>/In1' incorporates:
    //   Outport: '<S33>/Out1'

    test_RPY_B.In1 = test_RPY_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    test_RPY_DW.obj_d.matlabCodegenIsDeleted = false;
    test_RPY_DW.obj_d.isInitialized = 1;
    test_RPY_DW.obj_d.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(test_RPY_DW.obj_d.orbMetadataObj,
                         &test_RPY_DW.obj_d.eventStructObj);
    test_RPY_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/SourceBlock'
    test_RPY_DW.obj_o.matlabCodegenIsDeleted = false;
    test_RPY_DW.obj_o.isInitialized = 1;
    test_RPY_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(test_RPY_DW.obj_o.orbMetadataObj,
                         &test_RPY_DW.obj_o.eventStructObj);
    test_RPY_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/SourceBlock'
    test_RPY_DW.obj_a.matlabCodegenIsDeleted = false;
    test_RPY_DW.obj_a.isInitialized = 1;
    test_RPY_DW.obj_a.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(test_RPY_DW.obj_a.orbMetadataObj,
                         &test_RPY_DW.obj_a.eventStructObj);
    test_RPY_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S8>/PX4 PWM Output' incorporates:
    //   Constant: '<S8>/failsafe'

    test_RPY_DW.obj_l.errorStatus = 0U;
    test_RPY_DW.obj_l.isInitialized = 0;
    test_RPY_DW.obj_l.matlabCodegenIsDeleted = false;
    test_RPY_SystemCore_setup(&test_RPY_DW.obj_l, rtb_startingswitch,
      test_RPY_P.failsafe_Value);

    // Start for MATLABSystem: '<S30>/SourceBlock'
    test_RPY_DW.obj.matlabCodegenIsDeleted = false;
    test_RPY_DW.obj.isInitialized = 1;
    test_RPY_DW.obj.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(test_RPY_DW.obj.orbMetadataObj,
                         &test_RPY_DW.obj.eventStructObj);
    test_RPY_DW.obj.isSetupComplete = true;

    // Enable for Sin: '<Root>/Sine Wave'
    test_RPY_DW.systemEnable = 1;

    // Enable for Sin: '<Root>/Sine Wave1'
    test_RPY_DW.systemEnable_o = 1;

    // Enable for Sin: '<Root>/Sine Wave2'
    test_RPY_DW.systemEnable_o1 = 1;

    // Enable for Sin: '<Root>/Sine Wave3'
    test_RPY_DW.systemEnable_j = 1;
  }
}

// Model terminate function
void test_RPY_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!test_RPY_DW.obj_d.matlabCodegenIsDeleted) {
    test_RPY_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((test_RPY_DW.obj_d.isInitialized == 1) &&
        test_RPY_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&test_RPY_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!test_RPY_DW.obj_o.matlabCodegenIsDeleted) {
    test_RPY_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((test_RPY_DW.obj_o.isInitialized == 1) &&
        test_RPY_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&test_RPY_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!test_RPY_DW.obj_a.matlabCodegenIsDeleted) {
    test_RPY_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((test_RPY_DW.obj_a.isInitialized == 1) &&
        test_RPY_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&test_RPY_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
  // Terminate for MATLABSystem: '<S8>/PX4 PWM Output'
  if (!test_RPY_DW.obj_l.matlabCodegenIsDeleted) {
    test_RPY_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((test_RPY_DW.obj_l.isInitialized == 1) &&
        test_RPY_DW.obj_l.isSetupComplete) {
      status = pwm_disarm(&test_RPY_DW.obj_l.pwmDevHandler,
                          &test_RPY_DW.obj_l.armAdvertiseObj);
      test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
        (test_RPY_DW.obj_l.errorStatus | status);
      status = pwm_resetServo(&test_RPY_DW.obj_l.pwmDevHandler,
        test_RPY_DW.obj_l.servoCount, test_RPY_DW.obj_l.channelMask,
        test_RPY_DW.obj_l.isMain, &test_RPY_DW.obj_l.actuatorAdvertiseObj);
      test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
        (test_RPY_DW.obj_l.errorStatus | status);
      status = pwm_close(&test_RPY_DW.obj_l.pwmDevHandler,
                         &test_RPY_DW.obj_l.actuatorAdvertiseObj,
                         &test_RPY_DW.obj_l.armAdvertiseObj);
      test_RPY_DW.obj_l.errorStatus = static_cast<uint16_T>
        (test_RPY_DW.obj_l.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  if (!test_RPY_DW.obj.matlabCodegenIsDeleted) {
    test_RPY_DW.obj.matlabCodegenIsDeleted = true;
    if ((test_RPY_DW.obj.isInitialized == 1) && test_RPY_DW.obj.isSetupComplete)
    {
      uORB_read_terminate(&test_RPY_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S30>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
