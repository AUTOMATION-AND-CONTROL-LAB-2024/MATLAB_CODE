//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_waveInput.cpp
//
// Code generated for Simulink model 'manual_waveInput'.
//
// Model version                  : 1.70
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr  9 15:55:51 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "manual_waveInput.h"
#include "manual_waveInput_types.h"
#include "rtwtypes.h"
#include "manual_waveInput_private.h"
#include <math.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_manual_waveInput_T manual_waveInput_B;

// Block states (default storage)
DW_manual_waveInput_T manual_waveInput_DW;

// Real-time model
RT_MODEL_manual_waveInput_T manual_waveInput_M_ = RT_MODEL_manual_waveInput_T();
RT_MODEL_manual_waveInput_T *const manual_waveInput_M = &manual_waveInput_M_;

// Forward declaration for local functions
static void manual_waveInp_SystemCore_setup(px4_internal_block_PWM_manual_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
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

static void manual_waveInp_SystemCore_setup(px4_internal_block_PWM_manual_T *obj,
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
void manual_waveInput_step(void)
{
  int32_T Lk_tmp;
  int32_T Lk_tmp_0;
  int32_T Lk_tmp_1;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion1_fx;
  uint16_T rtb_DataTypeConversion1_j;
  uint16_T rtb_DataTypeConversion1_n;
  int8_T xt_tmp[6];
  int8_T xt_tmp_0[6];
  boolean_T rtb_startingswitch;
  boolean_T tmp;
  static const int8_T b[6] = { 0, 0, 0, 1, 0, 0 };

  static const int8_T c[6] = { 0, 0, 0, 0, 1, 0 };

  static const int8_T d[6] = { 0, 0, 0, 0, 0, 1 };

  static const int8_T e[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const int8_T b_b[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<S2>/Discrete Time' incorporates:
  //   DigitalClock: '<Root>/Digital Clock'

  manual_waveInput_B.DigitalClock = manual_waveInput_M->Timing.taskTime0;

  // MATLABSystem: '<S12>/SourceBlock'
  rtb_startingswitch = uORB_read_step(manual_waveInput_DW.obj_a.orbMetadataObj,
    &manual_waveInput_DW.obj_a.eventStructObj,
    &manual_waveInput_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (rtb_startingswitch) {
    // SignalConversion generated from: '<S13>/In1'
    manual_waveInput_B.In1_lx = manual_waveInput_B.b_varargout_2_c;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S12>/SourceBlock'
  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  manual_waveInput_B.z = manual_waveInput_B.In1_lx.z;

  // SignalConversion generated from: '<S1>/Bus Selector'
  manual_waveInput_B.y = manual_waveInput_B.In1_lx.y;
  for (rtemp = 0; rtemp < 3; rtemp++) {
    // Gain: '<S4>/Gain' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion4'

    manual_waveInput_B.Gain[rtemp] = (manual_waveInput_P.Rbody_frd[rtemp + 3] *
      manual_waveInput_B.y + manual_waveInput_P.Rbody_frd[rtemp] *
      manual_waveInput_B.In1_lx.x) + manual_waveInput_P.Rbody_frd[rtemp + 6] *
      manual_waveInput_B.z;
  }

  // MATLABSystem: '<S18>/SourceBlock'
  rtb_startingswitch = uORB_read_step(manual_waveInput_DW.obj_d.orbMetadataObj,
    &manual_waveInput_DW.obj_d.eventStructObj,
    &manual_waveInput_B.b_varargout_2_p, false, 1.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (rtb_startingswitch) {
    // SignalConversion generated from: '<S19>/In1'
    manual_waveInput_B.In1_o = manual_waveInput_B.b_varargout_2_p;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of MATLABSystem: '<S18>/SourceBlock'
  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'
  for (rtemp = 0; rtemp < 3; rtemp++) {
    // Gain: '<S4>/from Gauss to nT' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion2'
    //   Gain: '<S4>/Gain2'

    manual_waveInput_B.fromGausstonT[rtemp] =
      ((manual_waveInput_P.Rbody_ned[rtemp + 3] * manual_waveInput_B.In1_o.y +
        manual_waveInput_P.Rbody_ned[rtemp] * manual_waveInput_B.In1_o.x) +
       manual_waveInput_P.Rbody_ned[rtemp + 6] * manual_waveInput_B.In1_o.z) *
      manual_waveInput_P.fromGausstonT_Gain;

    // MATLAB Function: '<Root>/RPY_computation'
    manual_waveInput_B.RPY_meas[rtemp] = -manual_waveInput_B.Gain[rtemp];
  }

  // MATLAB Function: '<Root>/RPY_computation' incorporates:
  //   Constant: '<Root>/Constant2'

  manual_waveInput_B.y1_k = rt_atan2d_snf(manual_waveInput_B.RPY_meas[1],
    manual_waveInput_B.RPY_meas[2]);
  manual_waveInput_B.sph = sin(manual_waveInput_B.y1_k);
  manual_waveInput_B.cph = cos(manual_waveInput_B.y1_k);
  manual_waveInput_B.y2_n = rt_atan2d_snf(-manual_waveInput_B.RPY_meas[0],
    manual_waveInput_B.RPY_meas[1] * manual_waveInput_B.sph +
    manual_waveInput_B.RPY_meas[2] * manual_waveInput_B.cph);
  manual_waveInput_B.sth = sin(manual_waveInput_B.y2_n);
  manual_waveInput_B.cth = cos(manual_waveInput_B.y2_n);
  if (fabs(manual_waveInput_B.sth) > 0.1) {
    manual_waveInput_B.method_ps = 1.0;
    manual_waveInput_B.y3_h = rt_atan2d_snf((manual_waveInput_B.sth *
      manual_waveInput_B.cph * manual_waveInput_B.fromGausstonT[1] -
      manual_waveInput_B.sth * manual_waveInput_B.sph *
      manual_waveInput_B.fromGausstonT[2]) / -manual_waveInput_B.sth,
      ((-manual_waveInput_B.sph * manual_waveInput_B.fromGausstonT[1] -
        manual_waveInput_B.cph * manual_waveInput_B.fromGausstonT[2]) +
       manual_waveInput_B.cth * manual_waveInput_P.mf[2]) /
      -manual_waveInput_B.sth);
  } else {
    manual_waveInput_B.method_ps = 2.0;
    manual_waveInput_B.y3_h = rt_atan2d_snf((manual_waveInput_B.fromGausstonT[1]
      - manual_waveInput_B.cth * manual_waveInput_B.sph * manual_waveInput_P.mf
      [2]) * -manual_waveInput_B.cth, manual_waveInput_B.cph *
      manual_waveInput_B.fromGausstonT[0]);
  }

  manual_waveInput_B.RPY_meas[0] = manual_waveInput_B.y1_k;
  manual_waveInput_B.RPY_meas[1] = manual_waveInput_B.y2_n;
  manual_waveInput_B.RPY_meas[2] = manual_waveInput_B.y3_h;

  // MATLAB Function: '<S2>/EKF' incorporates:
  //   Constant: '<S2>/Constant'
  //   Constant: '<S2>/Constant1'
  //   Constant: '<S2>/Constant2'
  //   Constant: '<S2>/Constant3'
  //   Constant: '<S2>/Constant4'
  //   Constant: '<S2>/Constant5'
  //   Delay: '<S2>/Delay2'
  //   DigitalClock: '<S2>/Discrete Time'
  //   Memory: '<S2>/Memory'
  //   Memory: '<S2>/Memory1'
  //   Memory: '<S2>/Memory2'
  //   Memory: '<S2>/Memory3'
  //   Memory: '<S2>/Memory4'

  manual_waveInput_B.t_integr1 = manual_waveInput_DW.Memory1_PreviousInput;
  manual_waveInput_B.t_meas1_d = manual_waveInput_DW.Memory_PreviousInput;
  if (manual_waveInput_B.DigitalClock == 0.0) {
    for (rtemp = 0; rtemp < 6; rtemp++) {
      manual_waveInput_B.xk[rtemp] = manual_waveInput_P.x0EKF[rtemp];
      manual_waveInput_B.xt[rtemp] = manual_waveInput_P.x0EKF[rtemp];
    }

    memcpy(&manual_waveInput_DW.Memory2_PreviousInput[0],
           &manual_waveInput_P.P0[0], 36U * sizeof(real_T));
    manual_waveInput_B.t_integr1 = 0.0;
    manual_waveInput_B.t_meas1_d = 0.0;
  } else if (manual_waveInput_B.DigitalClock - manual_waveInput_B.t_integr1 >=
             manual_waveInput_P.Ts_EKF_integr) {
    manual_waveInput_B.cph = cos(manual_waveInput_DW.Memory3_PreviousInput[0]);
    manual_waveInput_B.cth = cos(manual_waveInput_DW.Memory3_PreviousInput[1]);
    manual_waveInput_B.sph = sin(manual_waveInput_DW.Memory3_PreviousInput[0]);
    manual_waveInput_B.sth = sin(manual_waveInput_DW.Memory3_PreviousInput[1]);
    manual_waveInput_B.tth = manual_waveInput_B.sth / manual_waveInput_B.cth;
    manual_waveInput_B.t_integr1 = manual_waveInput_B.DigitalClock;
    manual_waveInput_B.At1_c[0] = 1.0;
    manual_waveInput_B.At1_tmp = manual_waveInput_B.sph * manual_waveInput_B.tth;
    manual_waveInput_B.At1_c[6] = manual_waveInput_B.At1_tmp;
    manual_waveInput_B.At1_tmp_g = manual_waveInput_B.cph *
      manual_waveInput_B.tth;
    manual_waveInput_B.At1_c[12] = manual_waveInput_B.At1_tmp_g;
    manual_waveInput_B.At1_c[18] = 0.0;
    manual_waveInput_B.At1_c[24] = 0.0;
    manual_waveInput_B.At1_c[30] = 0.0;
    manual_waveInput_B.At1_c[1] = 0.0;
    manual_waveInput_B.At1_c[7] = manual_waveInput_B.cph;
    manual_waveInput_B.At1_c[13] = -manual_waveInput_B.sph;
    manual_waveInput_B.At1_c[19] = 0.0;
    manual_waveInput_B.At1_c[25] = 0.0;
    manual_waveInput_B.At1_c[31] = 0.0;
    manual_waveInput_B.At1_c[2] = 0.0;
    manual_waveInput_B.At1_c[8] = manual_waveInput_B.sph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1_c[14] = manual_waveInput_B.cph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1_c[20] = 0.0;
    manual_waveInput_B.At1_c[26] = 0.0;
    manual_waveInput_B.At1_c[32] = 0.0;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      r1 = b[rtemp];
      manual_waveInput_B.xt_tmp[rtemp] = r1;
      r2 = c[rtemp];
      xt_tmp[rtemp] = static_cast<int8_T>(r2);
      r3 = d[rtemp];
      xt_tmp_0[rtemp] = static_cast<int8_T>(r3);
      manual_waveInput_B.At1_c[6 * rtemp + 3] = r1;
      manual_waveInput_B.At1_c[6 * rtemp + 4] = r2;
      manual_waveInput_B.At1_c[6 * rtemp + 5] = r3;
    }

    manual_waveInput_B.dv[0] = manual_waveInput_DW.Delay2_DSTATE[0] -
      manual_waveInput_DW.Memory3_PreviousInput[3];
    manual_waveInput_B.d = manual_waveInput_DW.Delay2_DSTATE[1] -
      manual_waveInput_DW.Memory3_PreviousInput[4];
    manual_waveInput_B.dv[1] = manual_waveInput_B.d;
    manual_waveInput_B.d1 = manual_waveInput_DW.Delay2_DSTATE[2] -
      manual_waveInput_DW.Memory3_PreviousInput[5];
    manual_waveInput_B.dv[2] = manual_waveInput_B.d1;
    manual_waveInput_B.dv[3] = manual_waveInput_DW.Memory3_PreviousInput[3];
    manual_waveInput_B.dv[4] = manual_waveInput_DW.Memory3_PreviousInput[4];
    manual_waveInput_B.dv[5] = manual_waveInput_DW.Memory3_PreviousInput[5];
    for (rtemp = 0; rtemp < 6; rtemp++) {
      manual_waveInput_B.At1_tmp_g1 = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        manual_waveInput_B.At1_tmp_g1 += manual_waveInput_B.At1_c[6 * r1 + rtemp]
          * manual_waveInput_B.dv[r1];
      }

      manual_waveInput_B.xt[rtemp] = manual_waveInput_P.Ts_EKF_integr *
        manual_waveInput_B.At1_tmp_g1 +
        manual_waveInput_DW.Memory3_PreviousInput[rtemp];
    }

    manual_waveInput_B.At1[0] = manual_waveInput_B.At1_tmp_g *
      manual_waveInput_B.d - manual_waveInput_B.At1_tmp * manual_waveInput_B.d1;
    manual_waveInput_B.At1_tmp = manual_waveInput_B.d1 * manual_waveInput_B.cph;
    manual_waveInput_B.At1_tmp_g = manual_waveInput_B.d * manual_waveInput_B.sph
      + manual_waveInput_B.At1_tmp;
    manual_waveInput_B.At1_tmp_g1 = manual_waveInput_B.cth *
      manual_waveInput_B.cth;
    manual_waveInput_B.At1[6] = manual_waveInput_B.At1_tmp_g /
      manual_waveInput_B.At1_tmp_g1;
    manual_waveInput_B.At1[12] = 0.0;
    manual_waveInput_B.At1[18] = -1.0;
    manual_waveInput_B.At1[24] = -manual_waveInput_B.sph *
      manual_waveInput_B.tth;
    manual_waveInput_B.At1[30] = -manual_waveInput_B.cph *
      manual_waveInput_B.tth;
    manual_waveInput_B.At1[1] = manual_waveInput_B.d * -manual_waveInput_B.sph -
      manual_waveInput_B.At1_tmp;
    manual_waveInput_B.At1[7] = 0.0;
    manual_waveInput_B.At1[13] = 0.0;
    manual_waveInput_B.At1[19] = 0.0;
    manual_waveInput_B.At1[25] = -manual_waveInput_B.cph;
    manual_waveInput_B.At1[31] = manual_waveInput_B.sph;
    manual_waveInput_B.At1[2] = manual_waveInput_B.d * manual_waveInput_B.cph /
      manual_waveInput_B.cth - manual_waveInput_B.d1 * manual_waveInput_B.sph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1[8] = manual_waveInput_B.sth /
      manual_waveInput_B.At1_tmp_g1 * manual_waveInput_B.At1_tmp_g;
    manual_waveInput_B.At1[14] = 0.0;
    manual_waveInput_B.At1[20] = 0.0;
    manual_waveInput_B.At1[26] = -manual_waveInput_B.sph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1[32] = -manual_waveInput_B.cph /
      manual_waveInput_B.cth;
    for (rtemp = 0; rtemp < 6; rtemp++) {
      manual_waveInput_B.At1[6 * rtemp + 3] = manual_waveInput_B.xt_tmp[rtemp];
      manual_waveInput_B.At1[6 * rtemp + 4] = xt_tmp[rtemp];
      manual_waveInput_B.At1[6 * rtemp + 5] = xt_tmp_0[rtemp];
    }

    for (rtemp = 0; rtemp < 6; rtemp++) {
      for (r1 = 0; r1 < 6; r1++) {
        manual_waveInput_B.sph = 0.0;
        manual_waveInput_B.At1_tmp = 0.0;
        for (r2 = 0; r2 < 6; r2++) {
          r3 = 6 * r2 + rtemp;
          manual_waveInput_B.sph += manual_waveInput_DW.Memory2_PreviousInput[6 *
            r1 + r2] * manual_waveInput_B.At1[r3];
          manual_waveInput_B.At1_tmp += manual_waveInput_B.At1[6 * r2 + r1] *
            manual_waveInput_DW.Memory2_PreviousInput[r3];
        }

        r2 = 6 * r1 + rtemp;
        manual_waveInput_B.At1_c[r2] = manual_waveInput_B.At1_tmp;
        manual_waveInput_B.At1_m[r2] = manual_waveInput_B.sph;
      }
    }

    for (rtemp = 0; rtemp < 36; rtemp++) {
      manual_waveInput_DW.Memory2_PreviousInput[rtemp] +=
        ((manual_waveInput_B.At1_m[rtemp] + manual_waveInput_B.At1_c[rtemp]) +
         manual_waveInput_P.Q[rtemp]) * manual_waveInput_P.Ts_EKF_integr;
    }

    if (manual_waveInput_B.DigitalClock - manual_waveInput_B.t_meas1_d >=
        manual_waveInput_P.Ts_EKF_meas) {
      manual_waveInput_B.t_meas1_d = manual_waveInput_B.DigitalClock;
      for (rtemp = 0; rtemp < 18; rtemp++) {
        manual_waveInput_B.Lk[rtemp] = e[rtemp];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (r1 = 0; r1 < 6; r1++) {
          manual_waveInput_B.sph = 0.0;
          for (r2 = 0; r2 < 6; r2++) {
            manual_waveInput_B.sph += manual_waveInput_DW.Memory2_PreviousInput
              [6 * r2 + r1] * manual_waveInput_B.Lk[6 * rtemp + r2];
          }

          manual_waveInput_B.B[r1 + 6 * rtemp] = manual_waveInput_B.sph;
        }
      }

      for (rtemp = 0; rtemp < 18; rtemp++) {
        manual_waveInput_B.A_tmp_f[rtemp] = b_b[rtemp];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        for (r1 = 0; r1 < 6; r1++) {
          manual_waveInput_B.sph = 0.0;
          for (r2 = 0; r2 < 6; r2++) {
            manual_waveInput_B.sph += static_cast<real_T>
              (manual_waveInput_B.A_tmp_f[3 * r2 + rtemp]) *
              manual_waveInput_DW.Memory2_PreviousInput[6 * r1 + r2];
          }

          manual_waveInput_B.A_tmp[rtemp + 3 * r1] = manual_waveInput_B.sph;
        }

        for (r1 = 0; r1 < 3; r1++) {
          manual_waveInput_B.At1_tmp = 0.0;
          for (r2 = 0; r2 < 6; r2++) {
            manual_waveInput_B.At1_tmp += manual_waveInput_B.A_tmp[3 * r2 +
              rtemp] * manual_waveInput_B.Lk[6 * r1 + r2];
          }

          r2 = 3 * r1 + rtemp;
          manual_waveInput_B.A[r2] = manual_waveInput_P.R[r2] +
            manual_waveInput_B.At1_tmp;
        }
      }

      r1 = 0;
      r2 = 1;
      r3 = 2;
      manual_waveInput_B.sph = fabs(manual_waveInput_B.A[0]);
      manual_waveInput_B.cph = fabs(manual_waveInput_B.A[1]);
      if (manual_waveInput_B.cph > manual_waveInput_B.sph) {
        manual_waveInput_B.sph = manual_waveInput_B.cph;
        r1 = 1;
        r2 = 0;
      }

      if (fabs(manual_waveInput_B.A[2]) > manual_waveInput_B.sph) {
        r1 = 2;
        r2 = 1;
        r3 = 0;
      }

      manual_waveInput_B.A[r2] /= manual_waveInput_B.A[r1];
      manual_waveInput_B.A[r3] /= manual_waveInput_B.A[r1];
      manual_waveInput_B.A[r2 + 3] -= manual_waveInput_B.A[r1 + 3] *
        manual_waveInput_B.A[r2];
      manual_waveInput_B.A[r3 + 3] -= manual_waveInput_B.A[r1 + 3] *
        manual_waveInput_B.A[r3];
      manual_waveInput_B.A[r2 + 6] -= manual_waveInput_B.A[r1 + 6] *
        manual_waveInput_B.A[r2];
      manual_waveInput_B.A[r3 + 6] -= manual_waveInput_B.A[r1 + 6] *
        manual_waveInput_B.A[r3];
      if (fabs(manual_waveInput_B.A[r3 + 3]) > fabs(manual_waveInput_B.A[r2 + 3]))
      {
        rtemp = r2;
        r2 = r3;
        r3 = rtemp;
      }

      manual_waveInput_B.A[r3 + 3] /= manual_waveInput_B.A[r2 + 3];
      manual_waveInput_B.A[r3 + 6] -= manual_waveInput_B.A[r3 + 3] *
        manual_waveInput_B.A[r2 + 6];
      for (rtemp = 0; rtemp < 6; rtemp++) {
        Lk_tmp = 6 * r1 + rtemp;
        manual_waveInput_B.Lk[Lk_tmp] = manual_waveInput_B.B[rtemp] /
          manual_waveInput_B.A[r1];
        Lk_tmp_0 = 6 * r2 + rtemp;
        manual_waveInput_B.Lk[Lk_tmp_0] = manual_waveInput_B.B[rtemp + 6] -
          manual_waveInput_B.A[r1 + 3] * manual_waveInput_B.Lk[Lk_tmp];
        Lk_tmp_1 = 6 * r3 + rtemp;
        manual_waveInput_B.Lk[Lk_tmp_1] = manual_waveInput_B.B[rtemp + 12] -
          manual_waveInput_B.A[r1 + 6] * manual_waveInput_B.Lk[Lk_tmp];
        manual_waveInput_B.Lk[Lk_tmp_0] /= manual_waveInput_B.A[r2 + 3];
        manual_waveInput_B.Lk[Lk_tmp_1] -= manual_waveInput_B.A[r2 + 6] *
          manual_waveInput_B.Lk[Lk_tmp_0];
        manual_waveInput_B.Lk[Lk_tmp_1] /= manual_waveInput_B.A[r3 + 6];
        manual_waveInput_B.Lk[Lk_tmp_0] -= manual_waveInput_B.A[r3 + 3] *
          manual_waveInput_B.Lk[Lk_tmp_1];
        manual_waveInput_B.Lk[Lk_tmp] -= manual_waveInput_B.Lk[Lk_tmp_1] *
          manual_waveInput_B.A[r3];
        manual_waveInput_B.Lk[Lk_tmp] -= manual_waveInput_B.Lk[Lk_tmp_0] *
          manual_waveInput_B.A[r2];
      }

      for (rtemp = 0; rtemp < 3; rtemp++) {
        manual_waveInput_B.At1_tmp = 0.0;
        for (r1 = 0; r1 < 6; r1++) {
          manual_waveInput_B.At1_tmp += static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * r1 + rtemp]) *
            manual_waveInput_B.xt[r1];
        }

        manual_waveInput_B.RPY_meas_c[rtemp] = manual_waveInput_B.RPY_meas[rtemp]
          - manual_waveInput_B.At1_tmp;
      }

      manual_waveInput_B.sph = manual_waveInput_B.RPY_meas_c[1];
      manual_waveInput_B.cph = manual_waveInput_B.RPY_meas_c[0];
      manual_waveInput_B.cth = manual_waveInput_B.RPY_meas_c[2];
      for (rtemp = 0; rtemp < 6; rtemp++) {
        manual_waveInput_B.xk[rtemp] = ((manual_waveInput_B.Lk[rtemp + 6] *
          manual_waveInput_B.sph + manual_waveInput_B.Lk[rtemp] *
          manual_waveInput_B.cph) + manual_waveInput_B.Lk[rtemp + 12] *
          manual_waveInput_B.cth) + manual_waveInput_B.xt[rtemp];
      }

      memset(&manual_waveInput_B.At1[0], 0, 36U * sizeof(real_T));
      for (rtemp = 0; rtemp < 6; rtemp++) {
        manual_waveInput_B.At1[rtemp + 6 * rtemp] = 1.0;
      }

      for (rtemp = 0; rtemp < 6; rtemp++) {
        manual_waveInput_B.sph = manual_waveInput_B.Lk[rtemp + 6];
        manual_waveInput_B.cph = manual_waveInput_B.Lk[rtemp];
        manual_waveInput_B.cth = manual_waveInput_B.Lk[rtemp + 12];
        for (r1 = 0; r1 < 6; r1++) {
          r3 = 6 * r1 + rtemp;
          manual_waveInput_B.At1_m[r3] = manual_waveInput_B.At1[r3] - ((
            static_cast<real_T>(manual_waveInput_B.A_tmp_f[3 * r1 + 1]) *
            manual_waveInput_B.sph + static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * r1]) * manual_waveInput_B.cph) +
            static_cast<real_T>(manual_waveInput_B.A_tmp_f[3 * r1 + 2]) *
            manual_waveInput_B.cth);
        }

        for (r1 = 0; r1 < 6; r1++) {
          manual_waveInput_B.sph = 0.0;
          for (r2 = 0; r2 < 6; r2++) {
            manual_waveInput_B.sph += manual_waveInput_B.At1_m[6 * r2 + rtemp] *
              manual_waveInput_DW.Memory2_PreviousInput[6 * r1 + r2];
          }

          manual_waveInput_B.At1_c[rtemp + 6 * r1] = manual_waveInput_B.sph;
        }
      }

      memcpy(&manual_waveInput_DW.Memory2_PreviousInput[0],
             &manual_waveInput_B.At1_c[0], 36U * sizeof(real_T));
      for (rtemp = 0; rtemp < 6; rtemp++) {
        manual_waveInput_B.xt[rtemp] = manual_waveInput_B.xk[rtemp];
      }
    } else {
      for (rtemp = 0; rtemp < 6; rtemp++) {
        manual_waveInput_B.xk[rtemp] =
          manual_waveInput_DW.Memory4_PreviousInput[rtemp];
      }
    }
  } else {
    for (rtemp = 0; rtemp < 6; rtemp++) {
      manual_waveInput_B.xk[rtemp] =
        manual_waveInput_DW.Memory3_PreviousInput[rtemp];
      manual_waveInput_B.xt[rtemp] =
        manual_waveInput_DW.Memory3_PreviousInput[rtemp];
    }
  }

  // End of MATLAB Function: '<S2>/EKF'

  // Sin: '<Root>/Sine Wave' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable != 0) {
    manual_waveInput_B.sph = manual_waveInput_P.SineWave_Freq *
      manual_waveInput_B.DigitalClock;
    manual_waveInput_DW.lastSin = sin(manual_waveInput_B.sph);
    manual_waveInput_DW.lastCos = cos(manual_waveInput_B.sph);
    manual_waveInput_DW.systemEnable = 0;
  }

  // DataTypeConversion: '<S25>/Data Type Conversion1' incorporates:
  //   Constant: '<S25>/Constant'
  //   Sin: '<Root>/Sine Wave'
  //   Sum: '<S25>/Sum'

  manual_waveInput_B.At1_tmp = floor((((manual_waveInput_DW.lastSin *
    manual_waveInput_P.SineWave_PCos + manual_waveInput_DW.lastCos *
    manual_waveInput_P.SineWave_PSin) * manual_waveInput_P.SineWave_HCos +
    (manual_waveInput_DW.lastCos * manual_waveInput_P.SineWave_PCos -
     manual_waveInput_DW.lastSin * manual_waveInput_P.SineWave_PSin) *
    manual_waveInput_P.SineWave_Hsin) * manual_waveInput_P.SineWave_Amp +
    manual_waveInput_P.SineWave_Bias) + manual_waveInput_P.Constant_Value_ah);
  if (rtIsNaN(manual_waveInput_B.At1_tmp) || rtIsInf(manual_waveInput_B.At1_tmp))
  {
    manual_waveInput_B.At1_tmp = 0.0;
  } else {
    manual_waveInput_B.At1_tmp = fmod(manual_waveInput_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_n = static_cast<uint16_T>(manual_waveInput_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_waveInput_B.At1_tmp)))) : static_cast<int32_T>
    (static_cast<uint16_T>(manual_waveInput_B.At1_tmp)));

  // End of DataTypeConversion: '<S25>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave1' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_o != 0) {
    manual_waveInput_B.sph = manual_waveInput_P.SineWave1_Freq *
      manual_waveInput_B.DigitalClock;
    manual_waveInput_DW.lastSin_c = sin(manual_waveInput_B.sph);
    manual_waveInput_DW.lastCos_e = cos(manual_waveInput_B.sph);
    manual_waveInput_DW.systemEnable_o = 0;
  }

  // DataTypeConversion: '<S26>/Data Type Conversion1' incorporates:
  //   Constant: '<S26>/Constant'
  //   Sin: '<Root>/Sine Wave1'
  //   Sum: '<S26>/Sum'

  manual_waveInput_B.At1_tmp = floor((((manual_waveInput_DW.lastSin_c *
    manual_waveInput_P.SineWave1_PCos + manual_waveInput_DW.lastCos_e *
    manual_waveInput_P.SineWave1_PSin) * manual_waveInput_P.SineWave1_HCos +
    (manual_waveInput_DW.lastCos_e * manual_waveInput_P.SineWave1_PCos -
     manual_waveInput_DW.lastSin_c * manual_waveInput_P.SineWave1_PSin) *
    manual_waveInput_P.SineWave1_Hsin) * manual_waveInput_P.SineWave1_Amp +
    manual_waveInput_P.SineWave1_Bias) + manual_waveInput_P.Constant_Value_c);
  if (rtIsNaN(manual_waveInput_B.At1_tmp) || rtIsInf(manual_waveInput_B.At1_tmp))
  {
    manual_waveInput_B.At1_tmp = 0.0;
  } else {
    manual_waveInput_B.At1_tmp = fmod(manual_waveInput_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_fx = static_cast<uint16_T>(manual_waveInput_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_waveInput_B.At1_tmp)))) : static_cast<int32_T>
    (static_cast<uint16_T>(manual_waveInput_B.At1_tmp)));

  // End of DataTypeConversion: '<S26>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave2' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_o1 != 0) {
    manual_waveInput_B.sph = manual_waveInput_P.SineWave2_Freq *
      manual_waveInput_B.DigitalClock;
    manual_waveInput_DW.lastSin_f = sin(manual_waveInput_B.sph);
    manual_waveInput_DW.lastCos_b = cos(manual_waveInput_B.sph);
    manual_waveInput_DW.systemEnable_o1 = 0;
  }

  // DataTypeConversion: '<S27>/Data Type Conversion1' incorporates:
  //   Constant: '<S27>/Constant'
  //   Sin: '<Root>/Sine Wave2'
  //   Sum: '<S27>/Sum'

  manual_waveInput_B.At1_tmp = floor((((manual_waveInput_DW.lastSin_f *
    manual_waveInput_P.SineWave2_PCos + manual_waveInput_DW.lastCos_b *
    manual_waveInput_P.SineWave2_PSin) * manual_waveInput_P.SineWave2_HCos +
    (manual_waveInput_DW.lastCos_b * manual_waveInput_P.SineWave2_PCos -
     manual_waveInput_DW.lastSin_f * manual_waveInput_P.SineWave2_PSin) *
    manual_waveInput_P.SineWave2_Hsin) * manual_waveInput_P.SineWave2_Amp +
    manual_waveInput_P.SineWave2_Bias) + manual_waveInput_P.Constant_Value_h);
  if (rtIsNaN(manual_waveInput_B.At1_tmp) || rtIsInf(manual_waveInput_B.At1_tmp))
  {
    manual_waveInput_B.At1_tmp = 0.0;
  } else {
    manual_waveInput_B.At1_tmp = fmod(manual_waveInput_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_a = static_cast<uint16_T>(manual_waveInput_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_waveInput_B.At1_tmp)))) : static_cast<int32_T>
    (static_cast<uint16_T>(manual_waveInput_B.At1_tmp)));

  // End of DataTypeConversion: '<S27>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave3' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_j != 0) {
    manual_waveInput_B.sph = manual_waveInput_P.SineWave3_Freq *
      manual_waveInput_B.DigitalClock;
    manual_waveInput_DW.lastSin_m = sin(manual_waveInput_B.sph);
    manual_waveInput_DW.lastCos_k = cos(manual_waveInput_B.sph);
    manual_waveInput_DW.systemEnable_j = 0;
  }

  // DataTypeConversion: '<S28>/Data Type Conversion1' incorporates:
  //   Constant: '<S28>/Constant'
  //   Sin: '<Root>/Sine Wave3'
  //   Sum: '<S28>/Sum'

  manual_waveInput_B.At1_tmp = floor((((manual_waveInput_DW.lastSin_m *
    manual_waveInput_P.SineWave3_PCos + manual_waveInput_DW.lastCos_k *
    manual_waveInput_P.SineWave3_PSin) * manual_waveInput_P.SineWave3_HCos +
    (manual_waveInput_DW.lastCos_k * manual_waveInput_P.SineWave3_PCos -
     manual_waveInput_DW.lastSin_m * manual_waveInput_P.SineWave3_PSin) *
    manual_waveInput_P.SineWave3_Hsin) * manual_waveInput_P.SineWave3_Amp +
    manual_waveInput_P.SineWave3_Bias) + manual_waveInput_P.Constant_Value_op);
  if (rtIsNaN(manual_waveInput_B.At1_tmp) || rtIsInf(manual_waveInput_B.At1_tmp))
  {
    manual_waveInput_B.At1_tmp = 0.0;
  } else {
    manual_waveInput_B.At1_tmp = fmod(manual_waveInput_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_j = static_cast<uint16_T>(manual_waveInput_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_waveInput_B.At1_tmp)))) : static_cast<int32_T>
    (static_cast<uint16_T>(manual_waveInput_B.At1_tmp)));

  // End of DataTypeConversion: '<S28>/Data Type Conversion1'

  // MATLABSystem: '<S16>/SourceBlock'
  rtb_startingswitch = uORB_read_step(manual_waveInput_DW.obj_o.orbMetadataObj,
    &manual_waveInput_DW.obj_o.eventStructObj,
    &manual_waveInput_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S17>/Enable'

  if (rtb_startingswitch) {
    // SignalConversion generated from: '<S17>/In1'
    manual_waveInput_B.In1_m = manual_waveInput_B.b_varargout_2_b;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of MATLABSystem: '<S16>/SourceBlock'
  // End of Outputs for SubSystem: '<S16>/Enabled Subsystem'

  // MATLABSystem: '<S29>/SourceBlock'
  rtb_startingswitch = uORB_read_step(manual_waveInput_DW.obj.orbMetadataObj,
    &manual_waveInput_DW.obj.eventStructObj, &manual_waveInput_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S29>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (rtb_startingswitch) {
    // SignalConversion generated from: '<S30>/In1'
    manual_waveInput_B.In1 = manual_waveInput_B.b_varargout_2;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S29>/SourceBlock'
  // End of Outputs for SubSystem: '<S29>/Enabled Subsystem'
  for (rtemp = 0; rtemp < 3; rtemp++) {
    // Gain: '<S4>/Gain1' incorporates:
    //   DataTypeConversion: '<S4>/Data Type Conversion1'

    manual_waveInput_B.Gain1[rtemp] = (manual_waveInput_P.Rbody_frd[rtemp + 3] *
      manual_waveInput_B.In1_m.y + manual_waveInput_P.Rbody_frd[rtemp] *
      manual_waveInput_B.In1_m.x) + manual_waveInput_P.Rbody_frd[rtemp + 6] *
      manual_waveInput_B.In1_m.z;
  }

  // MATLAB Function: '<S2>/xk_dot_computation' incorporates:
  //   Constant: '<S2>/Constant6'
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_B.DigitalClock == 0.0) {
    manual_waveInput_DW.Memory5_PreviousInput = 0.0;
  }

  if ((manual_waveInput_B.DigitalClock -
       manual_waveInput_DW.Memory5_PreviousInput >=
       manual_waveInput_P.Ts_EKF_meas) || (manual_waveInput_B.DigitalClock ==
       0.0)) {
    manual_waveInput_B.cph = cos(manual_waveInput_B.xk[0]);
    manual_waveInput_B.cth = cos(manual_waveInput_B.xk[1]);
    manual_waveInput_B.sph = sin(manual_waveInput_B.xk[0]);
    manual_waveInput_B.tth = sin(manual_waveInput_B.xk[1]) /
      manual_waveInput_B.cth;
    manual_waveInput_DW.Memory5_PreviousInput = manual_waveInput_B.DigitalClock;
    manual_waveInput_B.A[0] = 1.0;
    manual_waveInput_B.A[3] = manual_waveInput_B.sph * manual_waveInput_B.tth;
    manual_waveInput_B.A[6] = manual_waveInput_B.cph * manual_waveInput_B.tth;
    manual_waveInput_B.A[1] = 0.0;
    manual_waveInput_B.A[4] = manual_waveInput_B.cph;
    manual_waveInput_B.A[7] = -manual_waveInput_B.sph;
    manual_waveInput_B.A[2] = 0.0;
    manual_waveInput_B.A[5] = manual_waveInput_B.sph / manual_waveInput_B.cth;
    manual_waveInput_B.A[8] = manual_waveInput_B.cph / manual_waveInput_B.cth;
    manual_waveInput_B.sph = manual_waveInput_B.Gain1[0] -
      manual_waveInput_B.xk[3] * 0.0;
    manual_waveInput_B.cph = manual_waveInput_B.Gain1[1] -
      manual_waveInput_B.xk[4] * 0.0;
    manual_waveInput_B.cth = manual_waveInput_B.Gain1[2] -
      manual_waveInput_B.xk[5] * 0.0;
    for (rtemp = 0; rtemp < 3; rtemp++) {
      manual_waveInput_DW.Memory6_PreviousInput[rtemp] =
        (manual_waveInput_B.A[rtemp + 3] * manual_waveInput_B.cph +
         manual_waveInput_B.A[rtemp] * manual_waveInput_B.sph) +
        manual_waveInput_B.A[rtemp + 6] * manual_waveInput_B.cth;
    }
  }

  // End of MATLAB Function: '<S2>/xk_dot_computation'

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/Constant'

  if (manual_waveInput_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = manual_waveInput_P.Constant_Value_e;
  } else {
    rtb_startingswitch = manual_waveInput_P.ARMPWM_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // ManualSwitch: '<Root>/ending switch' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (manual_waveInput_P.endingswitch_CurrentSetting == 1) {
    tmp = manual_waveInput_P.Constant1_Value;
  } else {
    tmp = manual_waveInput_P.Constant3_Value;
  }

  // Logic: '<S10>/AND' incorporates:
  //   ManualSwitch: '<Root>/ending switch'

  manual_waveInput_B.AND = (rtb_startingswitch && tmp);

  // Switch: '<S10>/Switch'
  if (manual_waveInput_B.AND) {
    // Switch: '<S10>/Switch' incorporates:
    //   DataTypeConversion: '<S20>/Data Type Conversion1'
    //   DataTypeConversion: '<S20>/Data Type Conversion2'
    //   DataTypeConversion: '<S20>/Data Type Conversion3'
    //   DataTypeConversion: '<S20>/Data Type Conversion4'
    //   DataTypeConversion: '<S20>/Data Type Conversion5'
    //   MATLAB Function: '<S20>/MATLAB Function'
    //   SignalConversion generated from: '<S23>/ SFunction '

    manual_waveInput_B.Switch[0] = rtb_DataTypeConversion1_n;
    manual_waveInput_B.Switch[1] = rtb_DataTypeConversion1_fx;
    manual_waveInput_B.Switch[2] = rtb_DataTypeConversion1_a;
    manual_waveInput_B.Switch[3] = rtb_DataTypeConversion1_j;
    manual_waveInput_B.Switch[4] = manual_waveInput_B.In1_lx.x;
    manual_waveInput_B.Switch[5] = manual_waveInput_B.y;
    manual_waveInput_B.Switch[6] = manual_waveInput_B.z;
    manual_waveInput_B.Switch[7] = manual_waveInput_B.In1_m.x;
    manual_waveInput_B.Switch[8] = manual_waveInput_B.In1_m.y;
    manual_waveInput_B.Switch[9] = manual_waveInput_B.In1_m.z;
    manual_waveInput_B.Switch[10] = manual_waveInput_B.In1.rollspeed;
    manual_waveInput_B.Switch[11] = manual_waveInput_B.In1.pitchspeed;
    manual_waveInput_B.Switch[12] = manual_waveInput_B.In1.yawspeed;
    manual_waveInput_B.Switch[13] = manual_waveInput_B.In1_o.x;
    manual_waveInput_B.Switch[14] = manual_waveInput_B.In1_o.y;
    manual_waveInput_B.Switch[15] = manual_waveInput_B.In1_o.z;
    manual_waveInput_B.Switch[16] = manual_waveInput_B.xk[0];
    manual_waveInput_B.Switch[17] = manual_waveInput_B.xk[1];
    manual_waveInput_B.Switch[18] = manual_waveInput_B.xk[2];
    manual_waveInput_B.Switch[19] = manual_waveInput_DW.Memory6_PreviousInput[0];
    manual_waveInput_B.Switch[20] = manual_waveInput_DW.Memory6_PreviousInput[1];
    manual_waveInput_B.Switch[21] = manual_waveInput_DW.Memory6_PreviousInput[2];
  } else {
    // Switch: '<S10>/Switch' incorporates:
    //   Constant: '<S10>/zero'

    for (rtemp = 0; rtemp < 22; rtemp++) {
      manual_waveInput_B.Switch[rtemp] = manual_waveInput_P.zero_Value;
    }
  }

  // End of Switch: '<S10>/Switch'

  // SignalConversion generated from: '<Root>/To Workspace'
  manual_waveInput_B.TmpSignalConversionAt_asyncqueu[0] =
    manual_waveInput_B.DigitalClock;
  memcpy(&manual_waveInput_B.TmpSignalConversionAt_asyncqueu[1],
         &manual_waveInput_B.Switch[0], 22U * sizeof(real_T));

  // MATLABSystem: '<S8>/PX4 PWM Output' incorporates:
  //   Constant: '<S8>/failsafe'

  for (rtemp = 0; rtemp < 8; rtemp++) {
    manual_waveInput_B.pwmValue[rtemp] = 0U;
  }

  manual_waveInput_B.pwmValue[0] = rtb_DataTypeConversion1_n;
  manual_waveInput_B.pwmValue[1] = rtb_DataTypeConversion1_fx;
  manual_waveInput_B.pwmValue[2] = rtb_DataTypeConversion1_a;
  manual_waveInput_B.pwmValue[3] = rtb_DataTypeConversion1_j;
  if (rtb_startingswitch) {
    if (!manual_waveInput_DW.obj_l.isArmed) {
      manual_waveInput_DW.obj_l.isArmed = true;
      rtb_DataTypeConversion1_n = pwm_arm
        (&manual_waveInput_DW.obj_l.pwmDevHandler,
         &manual_waveInput_DW.obj_l.armAdvertiseObj);
      manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_waveInput_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    }

    rtb_DataTypeConversion1_n = pwm_setServo
      (&manual_waveInput_DW.obj_l.pwmDevHandler,
       manual_waveInput_DW.obj_l.servoCount,
       manual_waveInput_DW.obj_l.channelMask, &manual_waveInput_B.pwmValue[0],
       manual_waveInput_DW.obj_l.isMain,
       &manual_waveInput_DW.obj_l.actuatorAdvertiseObj);
    manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_waveInput_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  } else {
    rtb_DataTypeConversion1_n = pwm_disarm
      (&manual_waveInput_DW.obj_l.pwmDevHandler,
       &manual_waveInput_DW.obj_l.armAdvertiseObj);
    manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_waveInput_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    manual_waveInput_DW.obj_l.isArmed = false;
    rtb_DataTypeConversion1_n = pwm_resetServo
      (&manual_waveInput_DW.obj_l.pwmDevHandler,
       manual_waveInput_DW.obj_l.servoCount,
       manual_waveInput_DW.obj_l.channelMask, manual_waveInput_DW.obj_l.isMain,
       &manual_waveInput_DW.obj_l.actuatorAdvertiseObj);
    manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_waveInput_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  if (manual_waveInput_DW.obj_l.isMain) {
    rtb_DataTypeConversion1_n = pwm_forceFailsafe
      (&manual_waveInput_DW.obj_l.pwmDevHandler, static_cast<int32_T>
       (manual_waveInput_P.failsafe_Value));
    manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_waveInput_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  // End of MATLABSystem: '<S8>/PX4 PWM Output'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function'
  //   SignalConversion generated from: '<S23>/ SFunction '

  manual_waveInput_B.y1_p = manual_waveInput_B.xk[0];
  manual_waveInput_B.y2_n5 = manual_waveInput_B.xk[1];
  manual_waveInput_B.y3_j = manual_waveInput_B.xk[2];
  manual_waveInput_B.y4_d = manual_waveInput_DW.Memory6_PreviousInput[0];
  manual_waveInput_B.y5_c = manual_waveInput_DW.Memory6_PreviousInput[1];
  manual_waveInput_B.y6_l = manual_waveInput_DW.Memory6_PreviousInput[2];

  // MATLABSystem: '<S21>/SourceBlock'
  rtb_startingswitch = uORB_read_step(manual_waveInput_DW.obj_m.orbMetadataObj,
    &manual_waveInput_DW.obj_m.eventStructObj,
    &manual_waveInput_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S24>/Enable'

  if (rtb_startingswitch) {
    // SignalConversion generated from: '<S24>/In1'
    manual_waveInput_B.In1_l = manual_waveInput_B.b_varargout_2_k;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S21>/SourceBlock'
  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // SignalConversion: '<S8>/Signal Conversion'
  manual_waveInput_B.SignalConversion[0] = manual_waveInput_B.In1_l.output[0];
  manual_waveInput_B.SignalConversion[1] = manual_waveInput_B.In1_l.output[1];
  for (rtemp = 0; rtemp < 6; rtemp++) {
    // Update for Memory: '<S2>/Memory4'
    manual_waveInput_DW.Memory4_PreviousInput[rtemp] =
      manual_waveInput_B.xk[rtemp];

    // Update for Memory: '<S2>/Memory3'
    manual_waveInput_DW.Memory3_PreviousInput[rtemp] =
      manual_waveInput_B.xt[rtemp];
  }

  // Update for Delay: '<S2>/Delay2'
  manual_waveInput_DW.Delay2_DSTATE[0] = manual_waveInput_B.Gain1[0];
  manual_waveInput_DW.Delay2_DSTATE[1] = manual_waveInput_B.Gain1[1];
  manual_waveInput_DW.Delay2_DSTATE[2] = manual_waveInput_B.Gain1[2];

  // Update for Memory: '<S2>/Memory1'
  manual_waveInput_DW.Memory1_PreviousInput = manual_waveInput_B.t_integr1;

  // Update for Memory: '<S2>/Memory'
  manual_waveInput_DW.Memory_PreviousInput = manual_waveInput_B.t_meas1_d;

  // Update for Sin: '<Root>/Sine Wave'
  manual_waveInput_B.sph = manual_waveInput_DW.lastSin;
  manual_waveInput_DW.lastSin = manual_waveInput_DW.lastSin *
    manual_waveInput_P.SineWave_HCos + manual_waveInput_DW.lastCos *
    manual_waveInput_P.SineWave_Hsin;
  manual_waveInput_DW.lastCos = manual_waveInput_DW.lastCos *
    manual_waveInput_P.SineWave_HCos - manual_waveInput_B.sph *
    manual_waveInput_P.SineWave_Hsin;

  // Update for Sin: '<Root>/Sine Wave1'
  manual_waveInput_B.sph = manual_waveInput_DW.lastSin_c;
  manual_waveInput_DW.lastSin_c = manual_waveInput_DW.lastSin_c *
    manual_waveInput_P.SineWave1_HCos + manual_waveInput_DW.lastCos_e *
    manual_waveInput_P.SineWave1_Hsin;
  manual_waveInput_DW.lastCos_e = manual_waveInput_DW.lastCos_e *
    manual_waveInput_P.SineWave1_HCos - manual_waveInput_B.sph *
    manual_waveInput_P.SineWave1_Hsin;

  // Update for Sin: '<Root>/Sine Wave2'
  manual_waveInput_B.sph = manual_waveInput_DW.lastSin_f;
  manual_waveInput_DW.lastSin_f = manual_waveInput_DW.lastSin_f *
    manual_waveInput_P.SineWave2_HCos + manual_waveInput_DW.lastCos_b *
    manual_waveInput_P.SineWave2_Hsin;
  manual_waveInput_DW.lastCos_b = manual_waveInput_DW.lastCos_b *
    manual_waveInput_P.SineWave2_HCos - manual_waveInput_B.sph *
    manual_waveInput_P.SineWave2_Hsin;

  // Update for Sin: '<Root>/Sine Wave3'
  manual_waveInput_B.sph = manual_waveInput_DW.lastSin_m;
  manual_waveInput_DW.lastSin_m = manual_waveInput_DW.lastSin_m *
    manual_waveInput_P.SineWave3_HCos + manual_waveInput_DW.lastCos_k *
    manual_waveInput_P.SineWave3_Hsin;
  manual_waveInput_DW.lastCos_k = manual_waveInput_DW.lastCos_k *
    manual_waveInput_P.SineWave3_HCos - manual_waveInput_B.sph *
    manual_waveInput_P.SineWave3_Hsin;

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  manual_waveInput_M->Timing.taskTime0 =
    ((time_T)(++manual_waveInput_M->Timing.clockTick0)) *
    manual_waveInput_M->Timing.stepSize0;
}

// Model initialize function
void manual_waveInput_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(manual_waveInput_M, -1);
  manual_waveInput_M->Timing.stepSize0 = 0.01;

  // External mode info
  manual_waveInput_M->Sizes.checksums[0] = (2792735325U);
  manual_waveInput_M->Sizes.checksums[1] = (3604896373U);
  manual_waveInput_M->Sizes.checksums[2] = (1384587169U);
  manual_waveInput_M->Sizes.checksums[3] = (3887830195U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[23];
    manual_waveInput_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[22] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(manual_waveInput_M->extModeInfo,
      &manual_waveInput_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(manual_waveInput_M->extModeInfo,
                        manual_waveInput_M->Sizes.checksums);
    rteiSetTPtr(manual_waveInput_M->extModeInfo, rtmGetTPtr(manual_waveInput_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Memory: '<S2>/Memory2'
    for (i = 0; i < 36; i++) {
      manual_waveInput_DW.Memory2_PreviousInput[i] =
        manual_waveInput_P.Memory2_InitialCondition;
    }

    // End of InitializeConditions for Memory: '<S2>/Memory2'
    for (i = 0; i < 6; i++) {
      // InitializeConditions for Memory: '<S2>/Memory4'
      manual_waveInput_DW.Memory4_PreviousInput[i] =
        manual_waveInput_P.Memory4_InitialCondition;

      // InitializeConditions for Memory: '<S2>/Memory3'
      manual_waveInput_DW.Memory3_PreviousInput[i] =
        manual_waveInput_P.Memory3_InitialCondition;
    }

    // InitializeConditions for Memory: '<S2>/Memory1'
    manual_waveInput_DW.Memory1_PreviousInput =
      manual_waveInput_P.Memory1_InitialCondition;

    // InitializeConditions for Memory: '<S2>/Memory'
    manual_waveInput_DW.Memory_PreviousInput =
      manual_waveInput_P.Memory_InitialCondition;

    // InitializeConditions for Memory: '<S2>/Memory5'
    manual_waveInput_DW.Memory5_PreviousInput =
      manual_waveInput_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S2>/Delay2'
    manual_waveInput_DW.Delay2_DSTATE[0] =
      manual_waveInput_P.Delay2_InitialCondition;

    // InitializeConditions for Memory: '<S2>/Memory6'
    manual_waveInput_DW.Memory6_PreviousInput[0] =
      manual_waveInput_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S2>/Delay2'
    manual_waveInput_DW.Delay2_DSTATE[1] =
      manual_waveInput_P.Delay2_InitialCondition;

    // InitializeConditions for Memory: '<S2>/Memory6'
    manual_waveInput_DW.Memory6_PreviousInput[1] =
      manual_waveInput_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S2>/Delay2'
    manual_waveInput_DW.Delay2_DSTATE[2] =
      manual_waveInput_P.Delay2_InitialCondition;

    // InitializeConditions for Memory: '<S2>/Memory6'
    manual_waveInput_DW.Memory6_PreviousInput[2] =
      manual_waveInput_P.Memory6_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    manual_waveInput_B.In1_lx = manual_waveInput_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    manual_waveInput_B.In1_o = manual_waveInput_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S17>/In1' incorporates:
    //   Outport: '<S17>/Out1'

    manual_waveInput_B.In1_m = manual_waveInput_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S29>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S30>/In1' incorporates:
    //   Outport: '<S30>/Out1'

    manual_waveInput_B.In1 = manual_waveInput_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S29>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S24>/In1' incorporates:
    //   Outport: '<S24>/Out1'

    manual_waveInput_B.In1_l = manual_waveInput_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // Start for MATLABSystem: '<S12>/SourceBlock'
    manual_waveInput_DW.obj_a.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_a.isInitialized = 1;
    manual_waveInput_DW.obj_a.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(manual_waveInput_DW.obj_a.orbMetadataObj,
                         &manual_waveInput_DW.obj_a.eventStructObj);
    manual_waveInput_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S18>/SourceBlock'
    manual_waveInput_DW.obj_d.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_d.isInitialized = 1;
    manual_waveInput_DW.obj_d.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(manual_waveInput_DW.obj_d.orbMetadataObj,
                         &manual_waveInput_DW.obj_d.eventStructObj);
    manual_waveInput_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/SourceBlock'
    manual_waveInput_DW.obj_o.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_o.isInitialized = 1;
    manual_waveInput_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(manual_waveInput_DW.obj_o.orbMetadataObj,
                         &manual_waveInput_DW.obj_o.eventStructObj);
    manual_waveInput_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S29>/SourceBlock'
    manual_waveInput_DW.obj.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj.isInitialized = 1;
    manual_waveInput_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(manual_waveInput_DW.obj.orbMetadataObj,
                         &manual_waveInput_DW.obj.eventStructObj);
    manual_waveInput_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S8>/PX4 PWM Output' incorporates:
    //   Constant: '<S8>/failsafe'

    manual_waveInput_DW.obj_l.errorStatus = 0U;
    manual_waveInput_DW.obj_l.isInitialized = 0;
    manual_waveInput_DW.obj_l.matlabCodegenIsDeleted = false;
    manual_waveInp_SystemCore_setup(&manual_waveInput_DW.obj_l,
      rtb_startingswitch, manual_waveInput_P.failsafe_Value);

    // Start for MATLABSystem: '<S21>/SourceBlock'
    manual_waveInput_DW.obj_m.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_m.isInitialized = 1;
    manual_waveInput_DW.obj_m.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(manual_waveInput_DW.obj_m.orbMetadataObj,
                         &manual_waveInput_DW.obj_m.eventStructObj);
    manual_waveInput_DW.obj_m.isSetupComplete = true;

    // Enable for Sin: '<Root>/Sine Wave'
    manual_waveInput_DW.systemEnable = 1;

    // Enable for Sin: '<Root>/Sine Wave1'
    manual_waveInput_DW.systemEnable_o = 1;

    // Enable for Sin: '<Root>/Sine Wave2'
    manual_waveInput_DW.systemEnable_o1 = 1;

    // Enable for Sin: '<Root>/Sine Wave3'
    manual_waveInput_DW.systemEnable_j = 1;
  }
}

// Model terminate function
void manual_waveInput_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!manual_waveInput_DW.obj_a.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_a.isInitialized == 1) &&
        manual_waveInput_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'

  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!manual_waveInput_DW.obj_d.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_d.isInitialized == 1) &&
        manual_waveInput_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S16>/SourceBlock'
  if (!manual_waveInput_DW.obj_o.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_o.isInitialized == 1) &&
        manual_waveInput_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S16>/SourceBlock'

  // Terminate for MATLABSystem: '<S29>/SourceBlock'
  if (!manual_waveInput_DW.obj.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj.isInitialized == 1) &&
        manual_waveInput_DW.obj.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S29>/SourceBlock'
  // Terminate for MATLABSystem: '<S8>/PX4 PWM Output'
  if (!manual_waveInput_DW.obj_l.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_l.isInitialized == 1) &&
        manual_waveInput_DW.obj_l.isSetupComplete) {
      status = pwm_disarm(&manual_waveInput_DW.obj_l.pwmDevHandler,
                          &manual_waveInput_DW.obj_l.armAdvertiseObj);
      manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_waveInput_DW.obj_l.errorStatus | status);
      status = pwm_resetServo(&manual_waveInput_DW.obj_l.pwmDevHandler,
        manual_waveInput_DW.obj_l.servoCount,
        manual_waveInput_DW.obj_l.channelMask, manual_waveInput_DW.obj_l.isMain,
        &manual_waveInput_DW.obj_l.actuatorAdvertiseObj);
      manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_waveInput_DW.obj_l.errorStatus | status);
      status = pwm_close(&manual_waveInput_DW.obj_l.pwmDevHandler,
                         &manual_waveInput_DW.obj_l.actuatorAdvertiseObj,
                         &manual_waveInput_DW.obj_l.armAdvertiseObj);
      manual_waveInput_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_waveInput_DW.obj_l.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S8>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!manual_waveInput_DW.obj_m.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_m.isInitialized == 1) &&
        manual_waveInput_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
