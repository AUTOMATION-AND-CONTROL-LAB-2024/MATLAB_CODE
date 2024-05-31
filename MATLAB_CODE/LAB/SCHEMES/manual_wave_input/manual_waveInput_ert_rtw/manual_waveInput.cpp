//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_waveInput.cpp
//
// Code generated for Simulink model 'manual_waveInput'.
//
// Model version                  : 1.76
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr 16 17:55:13 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "manual_waveInput.h"
#include "rtwtypes.h"
#include "manual_waveInput_types.h"
#include "manual_waveInput_private.h"
#include <math.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Named constants for MATLAB Function: '<Root>/reverse RPY'
const int32_T manual_waveInput_CALL_EVENT = -1;

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

//
// System initialize for atomic system:
//    '<Root>/reverse RPY'
//    '<Root>/reverse RPY1'
//
void manual_waveInpu_reverseRPY_Init(DW_reverseRPY_manual_waveInpu_T *localDW)
{
  localDW->sfEvent = manual_waveInput_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<Root>/reverse RPY'
//    '<Root>/reverse RPY1'
//
void manual_waveInput_reverseRPY(const real32_T rtu_u[3], real_T rty_RPY[3],
  DW_reverseRPY_manual_waveInpu_T *localDW)
{
  localDW->sfEvent = manual_waveInput_CALL_EVENT;
  rty_RPY[0] = rtu_u[2];
  rty_RPY[1] = rtu_u[1];
  rty_RPY[2] = rtu_u[0];
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

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = static_cast<real32_T>(atan2(static_cast<real_T>(static_cast<real32_T>
      (tmp)), static_cast<real_T>(static_cast<real32_T>(tmp_0))));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = static_cast<real32_T>(atan2(static_cast<real_T>(u0), static_cast<real_T>
      (u1)));
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
  real32_T ManualSwitch1_tmp;
  real32_T ManualSwitch1_tmp_0;
  real32_T ManualSwitch1_tmp_1;
  real32_T rtb_Product1_tmp;
  real32_T rtb_Product2_tmp;
  real32_T rtb_Product_tmp;
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion1_fx;
  uint16_T rtb_DataTypeConversion1_j;
  uint16_T rtb_DataTypeConversion1_n;
  boolean_T b_varargout_1;
  static const int8_T b[6] = { 0, 0, 0, 1, 0, 0 };

  static const int8_T c[6] = { 0, 0, 0, 0, 1, 0 };

  static const int8_T d[6] = { 0, 0, 0, 0, 0, 1 };

  static const int8_T e[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const int8_T b_b[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  real32_T VectorConcatenate_tmp;
  real32_T rtb_fcn3_tmp;

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_l);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRan_nq);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_a);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_f);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_k);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_p);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_n);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_b);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC);

  // MATLABSystem: '<S24>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_waveInput_DW.obj_a.orbMetadataObj,
    &manual_waveInput_DW.obj_a.eventStructObj,
    &manual_waveInput_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S25>/In1'
    manual_waveInput_B.In1_lx = manual_waveInput_B.b_varargout_2_c;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S24>/SourceBlock'
  // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  manual_waveInput_B.y = manual_waveInput_B.In1_lx.y;

  // SignalConversion generated from: '<S1>/Bus Selector'
  manual_waveInput_B.z = manual_waveInput_B.In1_lx.z;

  // DataTypeConversion: '<S4>/Data Type Conversion4'
  manual_waveInput_B.DataTypeConversion4[0] = manual_waveInput_B.In1_lx.x;
  manual_waveInput_B.DataTypeConversion4[1] = manual_waveInput_B.y;
  manual_waveInput_B.DataTypeConversion4[2] = manual_waveInput_B.z;

  // MATLABSystem: '<S30>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_waveInput_DW.obj_d.orbMetadataObj,
    &manual_waveInput_DW.obj_d.eventStructObj,
    &manual_waveInput_B.b_varargout_2_p, false, 1.0);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S31>/In1'
    manual_waveInput_B.In1_o = manual_waveInput_B.b_varargout_2_p;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of MATLABSystem: '<S30>/SourceBlock'
  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'

  // DataTypeConversion: '<S4>/Data Type Conversion2'
  manual_waveInput_B.DataTypeConversion2[0] = manual_waveInput_B.In1_o.x;
  manual_waveInput_B.DataTypeConversion2[1] = manual_waveInput_B.In1_o.y;
  manual_waveInput_B.DataTypeConversion2[2] = manual_waveInput_B.In1_o.z;

  // MATLAB Function: '<Root>/RPY_computation' incorporates:
  //   Constant: '<Root>/Constant2'

  manual_waveInput_B.y1_k = rt_atan2d_snf
    (-manual_waveInput_B.DataTypeConversion4[1],
     -manual_waveInput_B.DataTypeConversion4[2]);
  manual_waveInput_B.sph = sin(manual_waveInput_B.y1_k);
  manual_waveInput_B.cph = cos(manual_waveInput_B.y1_k);
  manual_waveInput_B.y2_n = rt_atan2d_snf
    (manual_waveInput_B.DataTypeConversion4[0],
     -manual_waveInput_B.DataTypeConversion4[1] * manual_waveInput_B.sph +
     -manual_waveInput_B.DataTypeConversion4[2] * manual_waveInput_B.cph);
  manual_waveInput_B.sth = sin(manual_waveInput_B.y2_n);
  manual_waveInput_B.cth = cos(manual_waveInput_B.y2_n);
  if (fabs(manual_waveInput_B.sth) > 0.1) {
    manual_waveInput_B.method_ps = 1.0;
    manual_waveInput_B.y3_h = rt_atan2d_snf((manual_waveInput_B.sth *
      manual_waveInput_B.cph * manual_waveInput_B.DataTypeConversion2[1] -
      manual_waveInput_B.sth * manual_waveInput_B.sph *
      manual_waveInput_B.DataTypeConversion2[2]) / -manual_waveInput_B.sth,
      ((-manual_waveInput_B.sph * manual_waveInput_B.DataTypeConversion2[1] -
        manual_waveInput_B.cph * manual_waveInput_B.DataTypeConversion2[2]) +
       manual_waveInput_B.cth * manual_waveInput_P.mf[2]) /
      -manual_waveInput_B.sth);
  } else {
    manual_waveInput_B.method_ps = 2.0;
    manual_waveInput_B.y3_h = rt_atan2d_snf
      ((manual_waveInput_B.DataTypeConversion2[1] - manual_waveInput_B.cth *
        manual_waveInput_B.sph * manual_waveInput_P.mf[2]) *
       -manual_waveInput_B.cth, manual_waveInput_B.cph *
       manual_waveInput_B.DataTypeConversion2[0]);
  }

  manual_waveInput_B.RPY_meas[0] = manual_waveInput_B.y1_k;
  manual_waveInput_B.RPY_meas[1] = manual_waveInput_B.y2_n;
  manual_waveInput_B.RPY_meas[2] = manual_waveInput_B.y3_h;

  // End of MATLAB Function: '<Root>/RPY_computation'

  // DigitalClock: '<S2>/Discrete Time' incorporates:
  //   DigitalClock: '<Root>/Digital Clock1'

  manual_waveInput_B.DigitalClock1 = manual_waveInput_M->Timing.taskTime0;

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
  if (manual_waveInput_B.DigitalClock1 == 0.0) {
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      manual_waveInput_B.xk[manual_waveInput_B.i] =
        manual_waveInput_P.x0EKF[manual_waveInput_B.i];
      manual_waveInput_B.xt[manual_waveInput_B.i] =
        manual_waveInput_P.x0EKF[manual_waveInput_B.i];
    }

    memcpy(&manual_waveInput_B.Pt[0], &manual_waveInput_P.P0[0], 36U * sizeof
           (real_T));
    manual_waveInput_B.t_integr1 = 0.0;
    manual_waveInput_B.t_meas1_d = 0.0;
  } else if (manual_waveInput_B.DigitalClock1 - manual_waveInput_B.t_integr1 >=
             manual_waveInput_P.Ts_EKF_integr) {
    manual_waveInput_B.cph = cos(manual_waveInput_DW.Memory3_PreviousInput[0]);
    manual_waveInput_B.cth = cos(manual_waveInput_DW.Memory3_PreviousInput[1]);
    manual_waveInput_B.sph = sin(manual_waveInput_DW.Memory3_PreviousInput[0]);
    manual_waveInput_B.sth = sin(manual_waveInput_DW.Memory3_PreviousInput[1]);
    manual_waveInput_B.tth = manual_waveInput_B.sth / manual_waveInput_B.cth;
    manual_waveInput_B.t_integr1 = manual_waveInput_B.DigitalClock1;
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
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      manual_waveInput_B.r1 = b[manual_waveInput_B.i];
      manual_waveInput_B.TmpSignalConversionAtSFunct[manual_waveInput_B.i] =
        manual_waveInput_B.r1;
      manual_waveInput_B.r2 = c[manual_waveInput_B.i];
      manual_waveInput_B.xt_tmp[manual_waveInput_B.i] = static_cast<int8_T>
        (manual_waveInput_B.r2);
      manual_waveInput_B.r3 = d[manual_waveInput_B.i];
      manual_waveInput_B.xt_tmp_m[manual_waveInput_B.i] = static_cast<int8_T>
        (manual_waveInput_B.r3);
      manual_waveInput_B.At1_c[6 * manual_waveInput_B.i + 3] =
        manual_waveInput_B.r1;
      manual_waveInput_B.At1_c[6 * manual_waveInput_B.i + 4] =
        manual_waveInput_B.r2;
      manual_waveInput_B.At1_c[6 * manual_waveInput_B.i + 5] =
        manual_waveInput_B.r3;
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
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      manual_waveInput_B.At1_tmp_g1 = 0.0;
      for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
           manual_waveInput_B.r1++) {
        manual_waveInput_B.At1_tmp_g1 += manual_waveInput_B.At1_c[6 *
          manual_waveInput_B.r1 + manual_waveInput_B.i] *
          manual_waveInput_B.dv[manual_waveInput_B.r1];
      }

      manual_waveInput_B.xt[manual_waveInput_B.i] =
        manual_waveInput_P.Ts_EKF_integr * manual_waveInput_B.At1_tmp_g1 +
        manual_waveInput_DW.Memory3_PreviousInput[manual_waveInput_B.i];
    }

    manual_waveInput_B.At1[0] = manual_waveInput_B.At1_tmp_g *
      manual_waveInput_B.d - manual_waveInput_B.At1_tmp * manual_waveInput_B.d1;
    manual_waveInput_B.At1_tmp = manual_waveInput_B.cth * manual_waveInput_B.cth;
    manual_waveInput_B.At1_tmp_g = manual_waveInput_B.d1 *
      manual_waveInput_B.cph;
    manual_waveInput_B.At1_tmp_g1 = manual_waveInput_B.d *
      manual_waveInput_B.sph + manual_waveInput_B.At1_tmp_g;
    manual_waveInput_B.At1[6] = manual_waveInput_B.At1_tmp_g1 /
      manual_waveInput_B.At1_tmp;
    manual_waveInput_B.At1[12] = 0.0;
    manual_waveInput_B.At1[18] = -1.0;
    manual_waveInput_B.At1[24] = -manual_waveInput_B.sph *
      manual_waveInput_B.tth;
    manual_waveInput_B.At1[30] = -manual_waveInput_B.cph *
      manual_waveInput_B.tth;
    manual_waveInput_B.At1[1] = manual_waveInput_B.d * -manual_waveInput_B.sph -
      manual_waveInput_B.At1_tmp_g;
    manual_waveInput_B.At1[7] = 0.0;
    manual_waveInput_B.At1[13] = 0.0;
    manual_waveInput_B.At1[19] = 0.0;
    manual_waveInput_B.At1[25] = -manual_waveInput_B.cph;
    manual_waveInput_B.At1[31] = manual_waveInput_B.sph;
    manual_waveInput_B.At1[2] = manual_waveInput_B.d * manual_waveInput_B.cph /
      manual_waveInput_B.cth - manual_waveInput_B.d1 * manual_waveInput_B.sph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1[8] = manual_waveInput_B.sth /
      manual_waveInput_B.At1_tmp * manual_waveInput_B.At1_tmp_g1;
    manual_waveInput_B.At1[14] = 0.0;
    manual_waveInput_B.At1[20] = 0.0;
    manual_waveInput_B.At1[26] = -manual_waveInput_B.sph /
      manual_waveInput_B.cth;
    manual_waveInput_B.At1[32] = -manual_waveInput_B.cph /
      manual_waveInput_B.cth;
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      manual_waveInput_B.At1[6 * manual_waveInput_B.i + 3] =
        manual_waveInput_B.TmpSignalConversionAtSFunct[manual_waveInput_B.i];
      manual_waveInput_B.At1[6 * manual_waveInput_B.i + 4] =
        manual_waveInput_B.xt_tmp[manual_waveInput_B.i];
      manual_waveInput_B.At1[6 * manual_waveInput_B.i + 5] =
        manual_waveInput_B.xt_tmp_m[manual_waveInput_B.i];
    }

    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
           manual_waveInput_B.r1++) {
        manual_waveInput_B.sph = 0.0;
        manual_waveInput_B.At1_tmp = 0.0;
        for (manual_waveInput_B.r2 = 0; manual_waveInput_B.r2 < 6;
             manual_waveInput_B.r2++) {
          manual_waveInput_B.r3 = 6 * manual_waveInput_B.r2 +
            manual_waveInput_B.i;
          manual_waveInput_B.sph += manual_waveInput_DW.Memory2_PreviousInput[6 *
            manual_waveInput_B.r1 + manual_waveInput_B.r2] *
            manual_waveInput_B.At1[manual_waveInput_B.r3];
          manual_waveInput_B.At1_tmp += manual_waveInput_B.At1[6 *
            manual_waveInput_B.r2 + manual_waveInput_B.r1] *
            manual_waveInput_DW.Memory2_PreviousInput[manual_waveInput_B.r3];
        }

        manual_waveInput_B.r2 = 6 * manual_waveInput_B.r1 + manual_waveInput_B.i;
        manual_waveInput_B.At1_c[manual_waveInput_B.r2] =
          manual_waveInput_B.At1_tmp;
        manual_waveInput_B.At1_m[manual_waveInput_B.r2] = manual_waveInput_B.sph;
      }
    }

    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 36;
         manual_waveInput_B.i++) {
      manual_waveInput_B.Pt[manual_waveInput_B.i] =
        ((manual_waveInput_B.At1_m[manual_waveInput_B.i] +
          manual_waveInput_B.At1_c[manual_waveInput_B.i]) +
         manual_waveInput_P.Q[manual_waveInput_B.i]) *
        manual_waveInput_P.Ts_EKF_integr +
        manual_waveInput_DW.Memory2_PreviousInput[manual_waveInput_B.i];
    }

    if (manual_waveInput_B.DigitalClock1 - manual_waveInput_B.t_meas1_d >=
        manual_waveInput_P.Ts_EKF_meas) {
      manual_waveInput_B.t_meas1_d = manual_waveInput_B.DigitalClock1;
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 18;
           manual_waveInput_B.i++) {
        manual_waveInput_B.Lk[manual_waveInput_B.i] = e[manual_waveInput_B.i];
      }

      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3;
           manual_waveInput_B.i++) {
        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.sph = 0.0;
          for (manual_waveInput_B.r2 = 0; manual_waveInput_B.r2 < 6;
               manual_waveInput_B.r2++) {
            manual_waveInput_B.sph += manual_waveInput_B.Pt[6 *
              manual_waveInput_B.r2 + manual_waveInput_B.r1] *
              manual_waveInput_B.Lk[6 * manual_waveInput_B.i +
              manual_waveInput_B.r2];
          }

          manual_waveInput_B.B[manual_waveInput_B.r1 + 6 * manual_waveInput_B.i]
            = manual_waveInput_B.sph;
        }
      }

      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 18;
           manual_waveInput_B.i++) {
        manual_waveInput_B.A_tmp_f[manual_waveInput_B.i] =
          b_b[manual_waveInput_B.i];
      }

      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3;
           manual_waveInput_B.i++) {
        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.sph = 0.0;
          for (manual_waveInput_B.r2 = 0; manual_waveInput_B.r2 < 6;
               manual_waveInput_B.r2++) {
            manual_waveInput_B.sph += static_cast<real_T>
              (manual_waveInput_B.A_tmp_f[3 * manual_waveInput_B.r2 +
               manual_waveInput_B.i]) * manual_waveInput_B.Pt[6 *
              manual_waveInput_B.r1 + manual_waveInput_B.r2];
          }

          manual_waveInput_B.A_tmp[manual_waveInput_B.i + 3 *
            manual_waveInput_B.r1] = manual_waveInput_B.sph;
        }

        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 3;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.At1_tmp = 0.0;
          for (manual_waveInput_B.r2 = 0; manual_waveInput_B.r2 < 6;
               manual_waveInput_B.r2++) {
            manual_waveInput_B.At1_tmp += manual_waveInput_B.A_tmp[3 *
              manual_waveInput_B.r2 + manual_waveInput_B.i] *
              manual_waveInput_B.Lk[6 * manual_waveInput_B.r1 +
              manual_waveInput_B.r2];
          }

          manual_waveInput_B.r2 = 3 * manual_waveInput_B.r1 +
            manual_waveInput_B.i;
          manual_waveInput_B.A[manual_waveInput_B.r2] =
            manual_waveInput_P.R[manual_waveInput_B.r2] +
            manual_waveInput_B.At1_tmp;
        }
      }

      manual_waveInput_B.r1 = 0;
      manual_waveInput_B.r2 = 1;
      manual_waveInput_B.r3 = 2;
      manual_waveInput_B.sph = fabs(manual_waveInput_B.A[0]);
      manual_waveInput_B.cph = fabs(manual_waveInput_B.A[1]);
      if (manual_waveInput_B.cph > manual_waveInput_B.sph) {
        manual_waveInput_B.sph = manual_waveInput_B.cph;
        manual_waveInput_B.r1 = 1;
        manual_waveInput_B.r2 = 0;
      }

      if (fabs(manual_waveInput_B.A[2]) > manual_waveInput_B.sph) {
        manual_waveInput_B.r1 = 2;
        manual_waveInput_B.r2 = 1;
        manual_waveInput_B.r3 = 0;
      }

      manual_waveInput_B.A[manual_waveInput_B.r2] /=
        manual_waveInput_B.A[manual_waveInput_B.r1];
      manual_waveInput_B.A[manual_waveInput_B.r3] /=
        manual_waveInput_B.A[manual_waveInput_B.r1];
      manual_waveInput_B.A[manual_waveInput_B.r2 + 3] -=
        manual_waveInput_B.A[manual_waveInput_B.r1 + 3] *
        manual_waveInput_B.A[manual_waveInput_B.r2];
      manual_waveInput_B.A[manual_waveInput_B.r3 + 3] -=
        manual_waveInput_B.A[manual_waveInput_B.r1 + 3] *
        manual_waveInput_B.A[manual_waveInput_B.r3];
      manual_waveInput_B.A[manual_waveInput_B.r2 + 6] -=
        manual_waveInput_B.A[manual_waveInput_B.r1 + 6] *
        manual_waveInput_B.A[manual_waveInput_B.r2];
      manual_waveInput_B.A[manual_waveInput_B.r3 + 6] -=
        manual_waveInput_B.A[manual_waveInput_B.r1 + 6] *
        manual_waveInput_B.A[manual_waveInput_B.r3];
      if (fabs(manual_waveInput_B.A[manual_waveInput_B.r3 + 3]) > fabs
          (manual_waveInput_B.A[manual_waveInput_B.r2 + 3])) {
        manual_waveInput_B.i = manual_waveInput_B.r2;
        manual_waveInput_B.r2 = manual_waveInput_B.r3;
        manual_waveInput_B.r3 = manual_waveInput_B.i;
      }

      manual_waveInput_B.A[manual_waveInput_B.r3 + 3] /=
        manual_waveInput_B.A[manual_waveInput_B.r2 + 3];
      manual_waveInput_B.A[manual_waveInput_B.r3 + 6] -=
        manual_waveInput_B.A[manual_waveInput_B.r3 + 3] *
        manual_waveInput_B.A[manual_waveInput_B.r2 + 6];
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        Lk_tmp = 6 * manual_waveInput_B.r1 + manual_waveInput_B.i;
        manual_waveInput_B.Lk[Lk_tmp] =
          manual_waveInput_B.B[manual_waveInput_B.i] /
          manual_waveInput_B.A[manual_waveInput_B.r1];
        Lk_tmp_0 = 6 * manual_waveInput_B.r2 + manual_waveInput_B.i;
        manual_waveInput_B.Lk[Lk_tmp_0] =
          manual_waveInput_B.B[manual_waveInput_B.i + 6] -
          manual_waveInput_B.A[manual_waveInput_B.r1 + 3] *
          manual_waveInput_B.Lk[Lk_tmp];
        Lk_tmp_1 = 6 * manual_waveInput_B.r3 + manual_waveInput_B.i;
        manual_waveInput_B.Lk[Lk_tmp_1] =
          manual_waveInput_B.B[manual_waveInput_B.i + 12] -
          manual_waveInput_B.A[manual_waveInput_B.r1 + 6] *
          manual_waveInput_B.Lk[Lk_tmp];
        manual_waveInput_B.Lk[Lk_tmp_0] /=
          manual_waveInput_B.A[manual_waveInput_B.r2 + 3];
        manual_waveInput_B.Lk[Lk_tmp_1] -=
          manual_waveInput_B.A[manual_waveInput_B.r2 + 6] *
          manual_waveInput_B.Lk[Lk_tmp_0];
        manual_waveInput_B.Lk[Lk_tmp_1] /=
          manual_waveInput_B.A[manual_waveInput_B.r3 + 6];
        manual_waveInput_B.Lk[Lk_tmp_0] -=
          manual_waveInput_B.A[manual_waveInput_B.r3 + 3] *
          manual_waveInput_B.Lk[Lk_tmp_1];
        manual_waveInput_B.Lk[Lk_tmp] -= manual_waveInput_B.Lk[Lk_tmp_1] *
          manual_waveInput_B.A[manual_waveInput_B.r3];
        manual_waveInput_B.Lk[Lk_tmp] -= manual_waveInput_B.Lk[Lk_tmp_0] *
          manual_waveInput_B.A[manual_waveInput_B.r2];
      }

      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3;
           manual_waveInput_B.i++) {
        manual_waveInput_B.At1_tmp = 0.0;
        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.At1_tmp += static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * manual_waveInput_B.r1 +
             manual_waveInput_B.i]) *
            manual_waveInput_B.xt[manual_waveInput_B.r1];
        }

        manual_waveInput_B.RPY_meas_c[manual_waveInput_B.i] =
          manual_waveInput_B.RPY_meas[manual_waveInput_B.i] -
          manual_waveInput_B.At1_tmp;
      }

      manual_waveInput_B.sph = manual_waveInput_B.RPY_meas_c[1];
      manual_waveInput_B.cph = manual_waveInput_B.RPY_meas_c[0];
      manual_waveInput_B.cth = manual_waveInput_B.RPY_meas_c[2];
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        manual_waveInput_B.xk[manual_waveInput_B.i] =
          ((manual_waveInput_B.Lk[manual_waveInput_B.i + 6] *
            manual_waveInput_B.sph + manual_waveInput_B.Lk[manual_waveInput_B.i]
            * manual_waveInput_B.cph) +
           manual_waveInput_B.Lk[manual_waveInput_B.i + 12] *
           manual_waveInput_B.cth) + manual_waveInput_B.xt[manual_waveInput_B.i];
      }

      memset(&manual_waveInput_B.At1[0], 0, 36U * sizeof(real_T));
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        manual_waveInput_B.At1[manual_waveInput_B.i + 6 * manual_waveInput_B.i] =
          1.0;
      }

      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        manual_waveInput_B.sph = manual_waveInput_B.Lk[manual_waveInput_B.i + 6];
        manual_waveInput_B.cph = manual_waveInput_B.Lk[manual_waveInput_B.i];
        manual_waveInput_B.cth = manual_waveInput_B.Lk[manual_waveInput_B.i + 12];
        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.r3 = 6 * manual_waveInput_B.r1 +
            manual_waveInput_B.i;
          manual_waveInput_B.At1_m[manual_waveInput_B.r3] =
            manual_waveInput_B.At1[manual_waveInput_B.r3] - ((static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * manual_waveInput_B.r1 + 1]) *
            manual_waveInput_B.sph + static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * manual_waveInput_B.r1]) *
            manual_waveInput_B.cph) + static_cast<real_T>
            (manual_waveInput_B.A_tmp_f[3 * manual_waveInput_B.r1 + 2]) *
            manual_waveInput_B.cth);
        }

        for (manual_waveInput_B.r1 = 0; manual_waveInput_B.r1 < 6;
             manual_waveInput_B.r1++) {
          manual_waveInput_B.sph = 0.0;
          for (manual_waveInput_B.r2 = 0; manual_waveInput_B.r2 < 6;
               manual_waveInput_B.r2++) {
            manual_waveInput_B.sph += manual_waveInput_B.At1_m[6 *
              manual_waveInput_B.r2 + manual_waveInput_B.i] *
              manual_waveInput_B.Pt[6 * manual_waveInput_B.r1 +
              manual_waveInput_B.r2];
          }

          manual_waveInput_B.At1_c[manual_waveInput_B.i + 6 *
            manual_waveInput_B.r1] = manual_waveInput_B.sph;
        }
      }

      memcpy(&manual_waveInput_B.Pt[0], &manual_waveInput_B.At1_c[0], 36U *
             sizeof(real_T));
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        manual_waveInput_B.xt[manual_waveInput_B.i] =
          manual_waveInput_B.xk[manual_waveInput_B.i];
      }
    } else {
      for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
           manual_waveInput_B.i++) {
        manual_waveInput_B.xk[manual_waveInput_B.i] =
          manual_waveInput_DW.Memory4_PreviousInput[manual_waveInput_B.i];
      }
    }
  } else {
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6;
         manual_waveInput_B.i++) {
      manual_waveInput_B.xk[manual_waveInput_B.i] =
        manual_waveInput_DW.Memory3_PreviousInput[manual_waveInput_B.i];
      manual_waveInput_B.xt[manual_waveInput_B.i] =
        manual_waveInput_DW.Memory3_PreviousInput[manual_waveInput_B.i];
    }

    memcpy(&manual_waveInput_B.Pt[0],
           &manual_waveInput_DW.Memory2_PreviousInput[0], 36U * sizeof(real_T));
  }

  // End of MATLAB Function: '<S2>/EKF'

  // Sin: '<Root>/Sine Wave' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable != 0) {
    manual_waveInput_DW.lastSin = sin(manual_waveInput_P.SineWave_Freq *
      manual_waveInput_B.DigitalClock1);
    manual_waveInput_DW.lastCos = cos(manual_waveInput_P.SineWave_Freq *
      manual_waveInput_M->Timing.taskTime0);
    manual_waveInput_DW.systemEnable = 0;
  }

  // DataTypeConversion: '<S37>/Data Type Conversion1' incorporates:
  //   Constant: '<S37>/Constant'
  //   Sin: '<Root>/Sine Wave'
  //   Sum: '<S37>/Sum'

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

  // End of DataTypeConversion: '<S37>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave1' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_o != 0) {
    manual_waveInput_DW.lastSin_c = sin(manual_waveInput_P.SineWave1_Freq *
      manual_waveInput_B.DigitalClock1);
    manual_waveInput_DW.lastCos_e = cos(manual_waveInput_P.SineWave1_Freq *
      manual_waveInput_M->Timing.taskTime0);
    manual_waveInput_DW.systemEnable_o = 0;
  }

  // DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
  //   Constant: '<S38>/Constant'
  //   Sin: '<Root>/Sine Wave1'
  //   Sum: '<S38>/Sum'

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

  // End of DataTypeConversion: '<S38>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave2' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_o1 != 0) {
    manual_waveInput_DW.lastSin_f = sin(manual_waveInput_P.SineWave2_Freq *
      manual_waveInput_B.DigitalClock1);
    manual_waveInput_DW.lastCos_b = cos(manual_waveInput_P.SineWave2_Freq *
      manual_waveInput_M->Timing.taskTime0);
    manual_waveInput_DW.systemEnable_o1 = 0;
  }

  // DataTypeConversion: '<S39>/Data Type Conversion1' incorporates:
  //   Constant: '<S39>/Constant'
  //   Sin: '<Root>/Sine Wave2'
  //   Sum: '<S39>/Sum'

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

  // End of DataTypeConversion: '<S39>/Data Type Conversion1'

  // Sin: '<Root>/Sine Wave3' incorporates:
  //   DigitalClock: '<S2>/Discrete Time'

  if (manual_waveInput_DW.systemEnable_j != 0) {
    manual_waveInput_DW.lastSin_m = sin(manual_waveInput_P.SineWave3_Freq *
      manual_waveInput_B.DigitalClock1);
    manual_waveInput_DW.lastCos_k = cos(manual_waveInput_P.SineWave3_Freq *
      manual_waveInput_M->Timing.taskTime0);
    manual_waveInput_DW.systemEnable_j = 0;
  }

  // DataTypeConversion: '<S40>/Data Type Conversion1' incorporates:
  //   Constant: '<S40>/Constant'
  //   Sin: '<Root>/Sine Wave3'
  //   Sum: '<S40>/Sum'

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

  // End of DataTypeConversion: '<S40>/Data Type Conversion1'

  // MATLABSystem: '<S28>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_waveInput_DW.obj_o.orbMetadataObj,
    &manual_waveInput_DW.obj_o.eventStructObj,
    &manual_waveInput_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S28>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S29>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S29>/In1'
    manual_waveInput_B.In1_m = manual_waveInput_B.b_varargout_2_b;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of MATLABSystem: '<S28>/SourceBlock'
  // End of Outputs for SubSystem: '<S28>/Enabled Subsystem'

  // MATLABSystem: '<S73>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_waveInput_DW.obj.orbMetadataObj,
    &manual_waveInput_DW.obj.eventStructObj, &manual_waveInput_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S73>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S74>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S74>/In1'
    manual_waveInput_B.In1 = manual_waveInput_B.b_varargout_2;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S73>/SourceBlock'
  // End of Outputs for SubSystem: '<S73>/Enabled Subsystem'

  // SignalConversion generated from: '<S21>/Bus Selector'
  manual_waveInput_B.rollspeed = manual_waveInput_B.In1.rollspeed;

  // SignalConversion generated from: '<S21>/Bus Selector'
  manual_waveInput_B.yawspeed = manual_waveInput_B.In1.yawspeed;

  // SignalConversion generated from: '<S21>/Bus Selector'
  manual_waveInput_B.pitchspeed = manual_waveInput_B.In1.pitchspeed;

  // Sqrt: '<S55>/sqrt' incorporates:
  //   Product: '<S56>/Product'
  //   Product: '<S56>/Product1'
  //   Product: '<S56>/Product2'
  //   Product: '<S56>/Product3'
  //   Sqrt: '<S47>/sqrt'
  //   Sqrt: '<S63>/sqrt'
  //   Sqrt: '<S71>/sqrt'
  //   Sum: '<S56>/Sum'

  manual_waveInput_B.rtb_fcn2_o_tmp = static_cast<real32_T>(sqrt
    (static_cast<real_T>(((manual_waveInput_B.In1.q[0] *
    manual_waveInput_B.In1.q[0] + manual_waveInput_B.In1.q[1] *
    manual_waveInput_B.In1.q[1]) + manual_waveInput_B.In1.q[2] *
    manual_waveInput_B.In1.q[2]) + manual_waveInput_B.In1.q[3] *
    manual_waveInput_B.In1.q[3])));

  // Product: '<S50>/Product' incorporates:
  //   Product: '<S42>/Product'
  //   Product: '<S58>/Product'
  //   Product: '<S66>/Product'
  //   Sqrt: '<S55>/sqrt'

  rtb_Product_tmp = manual_waveInput_B.In1.q[0] /
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Product: '<S50>/Product1' incorporates:
  //   Product: '<S42>/Product1'
  //   Product: '<S58>/Product1'
  //   Product: '<S66>/Product1'
  //   Sqrt: '<S55>/sqrt'

  rtb_Product1_tmp = manual_waveInput_B.In1.q[1] /
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Product: '<S50>/Product2' incorporates:
  //   Product: '<S42>/Product2'
  //   Product: '<S58>/Product2'
  //   Product: '<S66>/Product2'
  //   Sqrt: '<S55>/sqrt'

  rtb_Product2_tmp = manual_waveInput_B.In1.q[2] /
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Product: '<S50>/Product3' incorporates:
  //   Product: '<S42>/Product3'
  //   Product: '<S58>/Product3'
  //   Product: '<S66>/Product3'
  //   Sqrt: '<S55>/sqrt'

  manual_waveInput_B.rtb_fcn2_o_tmp = manual_waveInput_B.In1.q[3] /
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Fcn: '<S11>/fcn3' incorporates:
  //   Fcn: '<S10>/fcn3'
  //   Fcn: '<S12>/fcn3'
  //   Fcn: '<S13>/fcn3'
  //   Product: '<S50>/Product'
  //   Product: '<S50>/Product1'
  //   Product: '<S50>/Product2'
  //   Product: '<S50>/Product3'

  rtb_fcn3_tmp = (rtb_Product1_tmp * manual_waveInput_B.rtb_fcn2_o_tmp -
                  rtb_Product_tmp * rtb_Product2_tmp) * -2.0F;
  manual_waveInput_B.fcn3 = rtb_fcn3_tmp;

  // If: '<S51>/If' incorporates:
  //   Constant: '<S52>/Constant'
  //   Constant: '<S53>/Constant'
  //   Fcn: '<S11>/fcn3'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
    //   ActionPort: '<S52>/Action Port'

    manual_waveInput_B.fcn3 = manual_waveInput_P.Constant_Value_ha;

    // End of Outputs for SubSystem: '<S51>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S51>/If Action Subsystem' incorporates:
    //   ActionPort: '<S52>/Action Port'

    // Update for If: '<S51>/If' incorporates:
    //   Constant: '<S52>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_j);

    // End of Update for SubSystem: '<S51>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S53>/Action Port'

    manual_waveInput_B.fcn3 = manual_waveInput_P.Constant_Value_oj;

    // End of Outputs for SubSystem: '<S51>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S53>/Action Port'

    // Update for If: '<S51>/If' incorporates:
    //   Constant: '<S53>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_f);

    // End of Update for SubSystem: '<S51>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S51>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S54>/Action Port'

    // Update for If: '<S51>/If'
    srUpdateBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_k);

    // End of Update for SubSystem: '<S51>/If Action Subsystem2'
  }

  // End of If: '<S51>/If'

  // DataTypeConversion: '<S4>/Data Type Conversion1'
  manual_waveInput_B.DataTypeConversion1[0] = manual_waveInput_B.In1_m.x;
  manual_waveInput_B.DataTypeConversion1[1] = manual_waveInput_B.In1_m.y;
  manual_waveInput_B.DataTypeConversion1[2] = manual_waveInput_B.In1_m.z;

  // MATLAB Function: '<S2>/xk_dot_computation' incorporates:
  //   Constant: '<S2>/Constant6'
  //   DigitalClock: '<S2>/Discrete Time'
  //   Memory: '<S2>/Memory6'

  if (manual_waveInput_B.DigitalClock1 == 0.0) {
    manual_waveInput_DW.Memory5_PreviousInput = 0.0;
  }

  if ((manual_waveInput_B.DigitalClock1 -
       manual_waveInput_DW.Memory5_PreviousInput >=
       manual_waveInput_P.Ts_EKF_meas) || (manual_waveInput_B.DigitalClock1 ==
       0.0)) {
    manual_waveInput_B.cph = cos(manual_waveInput_B.xk[0]);
    manual_waveInput_B.cth = cos(manual_waveInput_B.xk[1]);
    manual_waveInput_B.sph = sin(manual_waveInput_B.xk[0]);
    manual_waveInput_B.tth = sin(manual_waveInput_B.xk[1]) /
      manual_waveInput_B.cth;
    manual_waveInput_DW.Memory5_PreviousInput = manual_waveInput_B.DigitalClock1;
    manual_waveInput_B.A[0] = 1.0;
    manual_waveInput_B.A[3] = manual_waveInput_B.sph * manual_waveInput_B.tth;
    manual_waveInput_B.A[6] = manual_waveInput_B.cph * manual_waveInput_B.tth;
    manual_waveInput_B.A[1] = 0.0;
    manual_waveInput_B.A[4] = manual_waveInput_B.cph;
    manual_waveInput_B.A[7] = -manual_waveInput_B.sph;
    manual_waveInput_B.A[2] = 0.0;
    manual_waveInput_B.A[5] = manual_waveInput_B.sph / manual_waveInput_B.cth;
    manual_waveInput_B.A[8] = manual_waveInput_B.cph / manual_waveInput_B.cth;
    manual_waveInput_B.sph = manual_waveInput_B.DataTypeConversion1[0] -
      manual_waveInput_B.xk[3] * 0.0;
    manual_waveInput_B.cph = manual_waveInput_B.DataTypeConversion1[1] -
      manual_waveInput_B.xk[4] * 0.0;
    manual_waveInput_B.cth = manual_waveInput_B.DataTypeConversion1[2] -
      manual_waveInput_B.xk[5] * 0.0;
    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3;
         manual_waveInput_B.i++) {
      manual_waveInput_B.RPY_rate[manual_waveInput_B.i] =
        (manual_waveInput_B.A[manual_waveInput_B.i + 3] * manual_waveInput_B.cph
         + manual_waveInput_B.A[manual_waveInput_B.i] * manual_waveInput_B.sph)
        + manual_waveInput_B.A[manual_waveInput_B.i + 6] *
        manual_waveInput_B.cth;
    }
  } else {
    manual_waveInput_B.RPY_rate[0] = manual_waveInput_DW.Memory6_PreviousInput[0];
    manual_waveInput_B.RPY_rate[1] = manual_waveInput_DW.Memory6_PreviousInput[1];
    manual_waveInput_B.RPY_rate[2] = manual_waveInput_DW.Memory6_PreviousInput[2];
  }

  // End of MATLAB Function: '<S2>/xk_dot_computation'

  // ManualSwitch: '<Root>/Manual Switch1'
  if (manual_waveInput_P.ManualSwitch1_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Constant5'

    for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 25;
         manual_waveInput_B.i++) {
      manual_waveInput_B.ManualSwitch1[manual_waveInput_B.i] =
        manual_waveInput_P.Constant5_Value;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   DataTypeConversion: '<S32>/Data Type Conversion1'
    //   DataTypeConversion: '<S32>/Data Type Conversion2'
    //   DataTypeConversion: '<S32>/Data Type Conversion3'
    //   DataTypeConversion: '<S32>/Data Type Conversion4'
    //   DataTypeConversion: '<S32>/Data Type Conversion5'

    manual_waveInput_B.ManualSwitch1[0] = rtb_DataTypeConversion1_n;
    manual_waveInput_B.ManualSwitch1[1] = rtb_DataTypeConversion1_fx;
    manual_waveInput_B.ManualSwitch1[2] = rtb_DataTypeConversion1_a;
    manual_waveInput_B.ManualSwitch1[3] = rtb_DataTypeConversion1_j;
    manual_waveInput_B.ManualSwitch1[4] = manual_waveInput_B.In1_lx.x;
    manual_waveInput_B.ManualSwitch1[5] = manual_waveInput_B.y;
    manual_waveInput_B.ManualSwitch1[6] = manual_waveInput_B.z;
    manual_waveInput_B.ManualSwitch1[7] = manual_waveInput_B.In1_m.x;
    manual_waveInput_B.ManualSwitch1[8] = manual_waveInput_B.In1_m.y;
    manual_waveInput_B.ManualSwitch1[9] = manual_waveInput_B.In1_m.z;
    manual_waveInput_B.ManualSwitch1[10] = manual_waveInput_B.rollspeed;
    manual_waveInput_B.ManualSwitch1[11] = manual_waveInput_B.pitchspeed;
    manual_waveInput_B.ManualSwitch1[12] = manual_waveInput_B.yawspeed;

    // Fcn: '<S11>/fcn2' incorporates:
    //   Fcn: '<S11>/fcn5'
    //   Product: '<S50>/Product'
    //   Product: '<S50>/Product1'
    //   Product: '<S50>/Product2'
    //   Product: '<S50>/Product3'

    ManualSwitch1_tmp = rtb_Product_tmp * rtb_Product_tmp;
    ManualSwitch1_tmp_0 = rtb_Product1_tmp * rtb_Product1_tmp;
    ManualSwitch1_tmp_1 = rtb_Product2_tmp * rtb_Product2_tmp;
    manual_waveInput_B.fcn3_h = manual_waveInput_B.rtb_fcn2_o_tmp *
      manual_waveInput_B.rtb_fcn2_o_tmp;

    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Fcn: '<S11>/fcn1'
    //   Fcn: '<S11>/fcn2'
    //   Product: '<S50>/Product'
    //   Product: '<S50>/Product1'
    //   Product: '<S50>/Product2'
    //   Product: '<S50>/Product3'
    //   Trigonometry: '<S49>/Trigonometric Function1'

    manual_waveInput_B.ManualSwitch1[13] = rt_atan2f_snf((rtb_Product1_tmp *
      rtb_Product2_tmp + rtb_Product_tmp * manual_waveInput_B.rtb_fcn2_o_tmp) *
      2.0F, ((ManualSwitch1_tmp + ManualSwitch1_tmp_0) - ManualSwitch1_tmp_1) -
      manual_waveInput_B.fcn3_h);

    // Trigonometry: '<S49>/trigFcn'
    if (manual_waveInput_B.fcn3 > 1.0F) {
      manual_waveInput_B.fcn3 = 1.0F;
    } else if (manual_waveInput_B.fcn3 < -1.0F) {
      manual_waveInput_B.fcn3 = -1.0F;
    }

    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   DataTypeConversion: '<S32>/Data Type Conversion5'
    //   Fcn: '<S11>/fcn4'
    //   Fcn: '<S11>/fcn5'
    //   MATLAB Function: '<S32>/MATLAB Function'
    //   Product: '<S50>/Product'
    //   Product: '<S50>/Product1'
    //   Product: '<S50>/Product2'
    //   Product: '<S50>/Product3'
    //   SignalConversion generated from: '<S35>/ SFunction '
    //   Trigonometry: '<S49>/Trigonometric Function3'
    //   Trigonometry: '<S49>/trigFcn'

    manual_waveInput_B.ManualSwitch1[14] = static_cast<real32_T>(asin(
      static_cast<real_T>(manual_waveInput_B.fcn3)));
    manual_waveInput_B.ManualSwitch1[15] = rt_atan2f_snf((rtb_Product2_tmp *
      manual_waveInput_B.rtb_fcn2_o_tmp + rtb_Product_tmp * rtb_Product1_tmp) *
      2.0F, ((ManualSwitch1_tmp - ManualSwitch1_tmp_0) - ManualSwitch1_tmp_1) +
      manual_waveInput_B.fcn3_h);
    manual_waveInput_B.ManualSwitch1[16] = manual_waveInput_B.In1_o.x;
    manual_waveInput_B.ManualSwitch1[17] = manual_waveInput_B.In1_o.y;
    manual_waveInput_B.ManualSwitch1[18] = manual_waveInput_B.In1_o.z;
    manual_waveInput_B.ManualSwitch1[19] = manual_waveInput_B.xk[0];
    manual_waveInput_B.ManualSwitch1[20] = manual_waveInput_B.xk[1];
    manual_waveInput_B.ManualSwitch1[21] = manual_waveInput_B.xk[2];
    manual_waveInput_B.ManualSwitch1[22] = manual_waveInput_B.RPY_rate[0];
    manual_waveInput_B.ManualSwitch1[23] = manual_waveInput_B.RPY_rate[1];
    manual_waveInput_B.ManualSwitch1[24] = manual_waveInput_B.RPY_rate[2];
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // SignalConversion generated from: '<Root>/To Workspace1'
  manual_waveInput_B.TmpSignalConversionAt_asyncqueu[0] =
    manual_waveInput_B.DigitalClock1;
  memcpy(&manual_waveInput_B.TmpSignalConversionAt_asyncqueu[1],
         &manual_waveInput_B.ManualSwitch1[0], 25U * sizeof(real_T));

  // SignalConversion generated from: '<Root>/From31'
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[0] = manual_waveInput_B.xk
    [0];
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[3] =
    manual_waveInput_B.RPY_rate[0];
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[1] = manual_waveInput_B.xk
    [1];
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[4] =
    manual_waveInput_B.RPY_rate[1];
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[2] = manual_waveInput_B.xk
    [2];
  manual_waveInput_B.TmpSignalConversionAtTAQSigLogg[5] =
    manual_waveInput_B.RPY_rate[2];

  // Fcn: '<S10>/fcn2' incorporates:
  //   Fcn: '<S10>/fcn5'
  //   Fcn: '<S12>/fcn2'
  //   Fcn: '<S13>/fcn2'

  manual_waveInput_B.fcn3 = rtb_Product_tmp * rtb_Product_tmp;
  ManualSwitch1_tmp = rtb_Product1_tmp * rtb_Product1_tmp;
  ManualSwitch1_tmp_0 = rtb_Product2_tmp * rtb_Product2_tmp;
  ManualSwitch1_tmp_1 = manual_waveInput_B.rtb_fcn2_o_tmp *
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Fcn: '<S10>/fcn1' incorporates:
  //   Fcn: '<S12>/fcn1'
  //   Fcn: '<S13>/fcn1'

  VectorConcatenate_tmp = (rtb_Product1_tmp * rtb_Product2_tmp + rtb_Product_tmp
    * manual_waveInput_B.rtb_fcn2_o_tmp) * 2.0F;

  // Trigonometry: '<S41>/Trigonometric Function1' incorporates:
  //   Concatenate: '<S41>/Vector Concatenate'
  //   Fcn: '<S10>/fcn1'
  //   Fcn: '<S10>/fcn2'

  manual_waveInput_B.VectorConcatenate[0] = rt_atan2f_snf(VectorConcatenate_tmp,
    ((manual_waveInput_B.fcn3 + ManualSwitch1_tmp) - ManualSwitch1_tmp_0) -
    ManualSwitch1_tmp_1);

  // Fcn: '<S10>/fcn3'
  manual_waveInput_B.fcn3_h = rtb_fcn3_tmp;

  // If: '<S43>/If' incorporates:
  //   Constant: '<S44>/Constant'
  //   Constant: '<S45>/Constant'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S43>/If Action Subsystem' incorporates:
    //   ActionPort: '<S44>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_ft;

    // End of Outputs for SubSystem: '<S43>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S43>/If Action Subsystem' incorporates:
    //   ActionPort: '<S44>/Action Port'

    // Update for If: '<S43>/If' incorporates:
    //   Constant: '<S44>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_l);

    // End of Update for SubSystem: '<S43>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S43>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S45>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_p;

    // End of Outputs for SubSystem: '<S43>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S43>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S45>/Action Port'

    // Update for If: '<S43>/If' incorporates:
    //   Constant: '<S45>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRan_nq);

    // End of Update for SubSystem: '<S43>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S43>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S46>/Action Port'

    // Update for If: '<S43>/If'
    srUpdateBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_a);

    // End of Update for SubSystem: '<S43>/If Action Subsystem2'
  }

  // End of If: '<S43>/If'

  // Trigonometry: '<S41>/trigFcn' incorporates:
  //   Concatenate: '<S41>/Vector Concatenate'

  if (manual_waveInput_B.fcn3_h > 1.0F) {
    manual_waveInput_B.fcn3_h = 1.0F;
  } else if (manual_waveInput_B.fcn3_h < -1.0F) {
    manual_waveInput_B.fcn3_h = -1.0F;
  }

  manual_waveInput_B.VectorConcatenate[1] = static_cast<real32_T>(asin(
    static_cast<real_T>(manual_waveInput_B.fcn3_h)));

  // End of Trigonometry: '<S41>/trigFcn'

  // Fcn: '<S10>/fcn4' incorporates:
  //   Fcn: '<S12>/fcn4'
  //   Fcn: '<S13>/fcn4'

  rtb_Product_tmp = (rtb_Product2_tmp * manual_waveInput_B.rtb_fcn2_o_tmp +
                     rtb_Product_tmp * rtb_Product1_tmp) * 2.0F;

  // Trigonometry: '<S41>/Trigonometric Function3' incorporates:
  //   Concatenate: '<S41>/Vector Concatenate'
  //   Fcn: '<S10>/fcn2'
  //   Fcn: '<S10>/fcn4'
  //   Fcn: '<S10>/fcn5'

  manual_waveInput_B.VectorConcatenate[2] = rt_atan2f_snf(rtb_Product_tmp,
    ((manual_waveInput_B.fcn3 - ManualSwitch1_tmp) - ManualSwitch1_tmp_0) +
    ManualSwitch1_tmp_1);

  // Fcn: '<S13>/fcn2' incorporates:
  //   Fcn: '<S13>/fcn5'

  ManualSwitch1_tmp_1 = manual_waveInput_B.rtb_fcn2_o_tmp *
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Trigonometry: '<S65>/Trigonometric Function1' incorporates:
  //   Fcn: '<S13>/fcn2'

  manual_waveInput_B.VectorConcatenate_h[0] = rt_atan2f_snf
    (VectorConcatenate_tmp, ((manual_waveInput_B.fcn3 + ManualSwitch1_tmp) -
      ManualSwitch1_tmp_0) - ManualSwitch1_tmp_1);

  // Fcn: '<S13>/fcn3'
  manual_waveInput_B.fcn3_h = rtb_fcn3_tmp;

  // If: '<S67>/If' incorporates:
  //   Constant: '<S68>/Constant'
  //   Constant: '<S69>/Constant'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S67>/If Action Subsystem' incorporates:
    //   ActionPort: '<S68>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_is;

    // End of Outputs for SubSystem: '<S67>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S67>/If Action Subsystem' incorporates:
    //   ActionPort: '<S68>/Action Port'

    // Update for If: '<S67>/If' incorporates:
    //   Constant: '<S68>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S67>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S67>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S69>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_pl;

    // End of Outputs for SubSystem: '<S67>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S67>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S69>/Action Port'

    // Update for If: '<S67>/If' incorporates:
    //   Constant: '<S69>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S67>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S67>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S70>/Action Port'

    // Update for If: '<S67>/If'
    srUpdateBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S67>/If Action Subsystem2'
  }

  // End of If: '<S67>/If'

  // Trigonometry: '<S65>/trigFcn'
  if (manual_waveInput_B.fcn3_h > 1.0F) {
    manual_waveInput_B.fcn3_h = 1.0F;
  } else if (manual_waveInput_B.fcn3_h < -1.0F) {
    manual_waveInput_B.fcn3_h = -1.0F;
  }

  manual_waveInput_B.VectorConcatenate_h[1] = static_cast<real32_T>(asin(
    static_cast<real_T>(manual_waveInput_B.fcn3_h)));

  // End of Trigonometry: '<S65>/trigFcn'

  // Trigonometry: '<S65>/Trigonometric Function3' incorporates:
  //   Fcn: '<S13>/fcn5'

  manual_waveInput_B.VectorConcatenate_h[2] = rt_atan2f_snf(rtb_Product_tmp,
    ((manual_waveInput_B.fcn3 - ManualSwitch1_tmp) - ManualSwitch1_tmp_0) +
    ManualSwitch1_tmp_1);

  // MATLAB Function: '<Root>/reverse RPY1'
  manual_waveInput_reverseRPY(manual_waveInput_B.VectorConcatenate_h,
    manual_waveInput_B.RPY, &manual_waveInput_DW.sf_reverseRPY1);

  // SignalConversion generated from: '<Root>/Mux5'
  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[0] =
    manual_waveInput_B.rollspeed;
  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[1] =
    manual_waveInput_B.pitchspeed;
  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[2] =
    manual_waveInput_B.yawspeed;

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  manual_waveInput_B.DataTypeConversion1_e[0] = static_cast<real32_T>
    (manual_waveInput_B.RPY[0]);

  // SignalConversion generated from: '<Root>/Mux5' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[3] = static_cast<real32_T>
    (manual_waveInput_B.RPY[0]);

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  manual_waveInput_B.DataTypeConversion1_e[1] = static_cast<real32_T>
    (manual_waveInput_B.RPY[1]);

  // SignalConversion generated from: '<Root>/Mux5' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[4] = static_cast<real32_T>
    (manual_waveInput_B.RPY[1]);

  // DataTypeConversion: '<Root>/Data Type Conversion1'
  manual_waveInput_B.DataTypeConversion1_e[2] = static_cast<real32_T>
    (manual_waveInput_B.RPY[2]);

  // SignalConversion generated from: '<Root>/Mux5' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  manual_waveInput_B.TmpSignalConversionAtTAQSigLo_d[5] = static_cast<real32_T>
    (manual_waveInput_B.RPY[2]);
  for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3; manual_waveInput_B.i
       ++) {
    // Gain: '<Root>/Gain' incorporates:
    //   SignalConversion generated from: '<Root>/Gain'

    manual_waveInput_B.Gain_o[manual_waveInput_B.i] =
      (manual_waveInput_P.Rbody_frd[manual_waveInput_B.i + 3] *
       manual_waveInput_B.pitchspeed +
       manual_waveInput_P.Rbody_frd[manual_waveInput_B.i] *
       manual_waveInput_B.rollspeed) +
      manual_waveInput_P.Rbody_frd[manual_waveInput_B.i + 6] *
      manual_waveInput_B.yawspeed;
  }

  // Fcn: '<S12>/fcn2' incorporates:
  //   Fcn: '<S12>/fcn5'

  ManualSwitch1_tmp_1 = manual_waveInput_B.rtb_fcn2_o_tmp *
    manual_waveInput_B.rtb_fcn2_o_tmp;

  // Trigonometry: '<S57>/Trigonometric Function1' incorporates:
  //   Fcn: '<S12>/fcn2'

  manual_waveInput_B.VectorConcatenate_h[0] = rt_atan2f_snf
    (VectorConcatenate_tmp, ((manual_waveInput_B.fcn3 + ManualSwitch1_tmp) -
      ManualSwitch1_tmp_0) - ManualSwitch1_tmp_1);

  // Fcn: '<S12>/fcn3'
  manual_waveInput_B.fcn3_h = rtb_fcn3_tmp;

  // If: '<S59>/If' incorporates:
  //   Constant: '<S60>/Constant'
  //   Constant: '<S61>/Constant'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
    //   ActionPort: '<S60>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_j;

    // End of Outputs for SubSystem: '<S59>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
    //   ActionPort: '<S60>/Action Port'

    // Update for If: '<S59>/If' incorporates:
    //   Constant: '<S60>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_p);

    // End of Update for SubSystem: '<S59>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S61>/Action Port'

    manual_waveInput_B.fcn3_h = manual_waveInput_P.Constant_Value_i;

    // End of Outputs for SubSystem: '<S59>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S61>/Action Port'

    // Update for If: '<S59>/If' incorporates:
    //   Constant: '<S61>/Constant'

    srUpdateBC(manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_n);

    // End of Update for SubSystem: '<S59>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S62>/Action Port'

    // Update for If: '<S59>/If'
    srUpdateBC(manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_b);

    // End of Update for SubSystem: '<S59>/If Action Subsystem2'
  }

  // End of If: '<S59>/If'

  // Trigonometry: '<S57>/trigFcn'
  if (manual_waveInput_B.fcn3_h > 1.0F) {
    manual_waveInput_B.fcn3_h = 1.0F;
  } else if (manual_waveInput_B.fcn3_h < -1.0F) {
    manual_waveInput_B.fcn3_h = -1.0F;
  }

  manual_waveInput_B.VectorConcatenate_h[1] = static_cast<real32_T>(asin(
    static_cast<real_T>(manual_waveInput_B.fcn3_h)));

  // End of Trigonometry: '<S57>/trigFcn'

  // Trigonometry: '<S57>/Trigonometric Function3' incorporates:
  //   Fcn: '<S12>/fcn5'

  manual_waveInput_B.VectorConcatenate_h[2] = rt_atan2f_snf(rtb_Product_tmp,
    ((manual_waveInput_B.fcn3 - ManualSwitch1_tmp) - ManualSwitch1_tmp_0) +
    ManualSwitch1_tmp_1);

  // MATLAB Function: '<Root>/reverse RPY'
  manual_waveInput_reverseRPY(manual_waveInput_B.VectorConcatenate_h,
    manual_waveInput_B.RPY_a, &manual_waveInput_DW.sf_reverseRPY);

  // Gain: '<Root>/Gain1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion5'

  manual_waveInput_B.sph = manual_waveInput_B.RPY_a[1];
  manual_waveInput_B.cph = manual_waveInput_B.RPY_a[0];
  manual_waveInput_B.cth = manual_waveInput_B.RPY_a[2];
  for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 3; manual_waveInput_B.i
       ++) {
    // Gain: '<Root>/Gain1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion5'

    rtb_Product_tmp = (manual_waveInput_P.Rbody_frd[manual_waveInput_B.i + 3] *
                       static_cast<real32_T>(manual_waveInput_B.sph) +
                       manual_waveInput_P.Rbody_frd[manual_waveInput_B.i] *
                       static_cast<real32_T>(manual_waveInput_B.cph)) +
      manual_waveInput_P.Rbody_frd[manual_waveInput_B.i + 6] *
      static_cast<real32_T>(manual_waveInput_B.cth);
    manual_waveInput_B.Gain1[manual_waveInput_B.i] = rtb_Product_tmp;

    // SignalConversion generated from: '<Root>/Mux3' incorporates:
    //   Gain: '<Root>/Gain1'

    manual_waveInput_B.TmpSignalConversionAtTAQSigLo_n[manual_waveInput_B.i] =
      manual_waveInput_B.Gain_o[manual_waveInput_B.i];
    manual_waveInput_B.TmpSignalConversionAtTAQSigLo_n[manual_waveInput_B.i + 3]
      = rtb_Product_tmp;
  }

  // Gain: '<S16>/Gain' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function3'

  manual_waveInput_B.Gain_g = manual_waveInput_P.Gain_Gain_j *
    manual_waveInput_B.VectorConcatenate[0];

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S5>/ SFunction '

  manual_waveInput_B.y1_p = manual_waveInput_B.xk[0];
  manual_waveInput_B.y2_n5 = manual_waveInput_B.xk[1];
  manual_waveInput_B.y3_j = manual_waveInput_B.xk[2];
  manual_waveInput_B.y4_d = manual_waveInput_B.RPY_rate[0];
  manual_waveInput_B.y5_c = manual_waveInput_B.RPY_rate[1];
  manual_waveInput_B.y6_l = manual_waveInput_B.RPY_rate[2];

  // Gain: '<S15>/Gain'
  manual_waveInput_B.Gain = manual_waveInput_P.Gain_Gain *
    manual_waveInput_B.y3_j;

  // Gain: '<S17>/Gain'
  manual_waveInput_B.Gain_m = manual_waveInput_P.Gain_Gain_o *
    manual_waveInput_B.y2_n5;

  // Gain: '<S18>/Gain' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function3'

  manual_waveInput_B.Gain_e = manual_waveInput_P.Gain_Gain_h *
    manual_waveInput_B.VectorConcatenate[1];

  // Gain: '<S19>/Gain'
  manual_waveInput_B.Gain_h = manual_waveInput_P.Gain_Gain_oi *
    manual_waveInput_B.y1_p;

  // Gain: '<S20>/Gain' incorporates:
  //   MATLAB Function: '<Root>/MATLAB Function3'

  manual_waveInput_B.Gain_i = manual_waveInput_P.Gain_Gain_oj *
    manual_waveInput_B.VectorConcatenate[2];

  // MATLABSystem: '<S9>/PX4 PWM Output'
  for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 8; manual_waveInput_B.i
       ++) {
    manual_waveInput_B.pwmValue[manual_waveInput_B.i] = 0U;
  }

  manual_waveInput_B.pwmValue[0] = rtb_DataTypeConversion1_n;
  manual_waveInput_B.pwmValue[1] = rtb_DataTypeConversion1_fx;
  manual_waveInput_B.pwmValue[2] = rtb_DataTypeConversion1_a;
  manual_waveInput_B.pwmValue[3] = rtb_DataTypeConversion1_j;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/Constant'

  if (manual_waveInput_P.startingswitch_CurrentSetting == 1) {
    b_varargout_1 = manual_waveInput_P.Constant_Value_e;
  } else {
    b_varargout_1 = manual_waveInput_P.ARMPWM_Value;
  }

  // MATLABSystem: '<S9>/PX4 PWM Output' incorporates:
  //   Constant: '<S9>/failsafe'
  //   ManualSwitch: '<Root>/starting switch'

  if (b_varargout_1) {
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

  // MATLABSystem: '<S33>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_waveInput_DW.obj_m.orbMetadataObj,
    &manual_waveInput_DW.obj_m.eventStructObj,
    &manual_waveInput_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S36>/In1'
    manual_waveInput_B.In1_l = manual_waveInput_B.b_varargout_2_k;
    srUpdateBC(manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S33>/SourceBlock'
  // End of Outputs for SubSystem: '<S33>/Enabled Subsystem'

  // SignalConversion: '<S9>/Signal Conversion'
  manual_waveInput_B.SignalConversion[0] = manual_waveInput_B.In1_l.output[0];
  manual_waveInput_B.SignalConversion[1] = manual_waveInput_B.In1_l.output[1];

  // Update for Memory: '<S2>/Memory2'
  memcpy(&manual_waveInput_DW.Memory2_PreviousInput[0], &manual_waveInput_B.Pt[0],
         36U * sizeof(real_T));
  for (manual_waveInput_B.i = 0; manual_waveInput_B.i < 6; manual_waveInput_B.i
       ++) {
    // Update for Memory: '<S2>/Memory4'
    manual_waveInput_DW.Memory4_PreviousInput[manual_waveInput_B.i] =
      manual_waveInput_B.xk[manual_waveInput_B.i];

    // Update for Memory: '<S2>/Memory3'
    manual_waveInput_DW.Memory3_PreviousInput[manual_waveInput_B.i] =
      manual_waveInput_B.xt[manual_waveInput_B.i];
  }

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

  // Update for Delay: '<S2>/Delay2'
  manual_waveInput_DW.Delay2_DSTATE[0] = manual_waveInput_B.DataTypeConversion1
    [0];

  // Update for Memory: '<S2>/Memory6'
  manual_waveInput_DW.Memory6_PreviousInput[0] = manual_waveInput_B.RPY_rate[0];

  // Update for Delay: '<S2>/Delay2'
  manual_waveInput_DW.Delay2_DSTATE[1] = manual_waveInput_B.DataTypeConversion1
    [1];

  // Update for Memory: '<S2>/Memory6'
  manual_waveInput_DW.Memory6_PreviousInput[1] = manual_waveInput_B.RPY_rate[1];

  // Update for Delay: '<S2>/Delay2'
  manual_waveInput_DW.Delay2_DSTATE[2] = manual_waveInput_B.DataTypeConversion1
    [2];

  // Update for Memory: '<S2>/Memory6'
  manual_waveInput_DW.Memory6_PreviousInput[2] = manual_waveInput_B.RPY_rate[2];

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
  manual_waveInput_M->Sizes.checksums[0] = (3680644646U);
  manual_waveInput_M->Sizes.checksums[1] = (301325570U);
  manual_waveInput_M->Sizes.checksums[2] = (1586427337U);
  manual_waveInput_M->Sizes.checksums[3] = (721776424U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[36];
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
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_l;
    systemRan[17] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem1_SubsysRan_nq;
    systemRan[18] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_a;
    systemRan[19] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_j;
    systemRan[20] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_f;
    systemRan[21] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_k;
    systemRan[22] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem_SubsysRanBC_p;
    systemRan[23] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem1_SubsysRanB_n;
    systemRan[24] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem2_SubsysRanB_b;
    systemRan[25] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &manual_waveInput_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = (sysRanDType *)
      &manual_waveInput_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
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

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S25>/In1' incorporates:
    //   Outport: '<S25>/Out1'

    manual_waveInput_B.In1_lx = manual_waveInput_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S31>/In1' incorporates:
    //   Outport: '<S31>/Out1'

    manual_waveInput_B.In1_o = manual_waveInput_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S28>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S29>/In1' incorporates:
    //   Outport: '<S29>/Out1'

    manual_waveInput_B.In1_m = manual_waveInput_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S28>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S73>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S74>/In1' incorporates:
    //   Outport: '<S74>/Out1'

    manual_waveInput_B.In1 = manual_waveInput_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S73>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<Root>/reverse RPY1'
    manual_waveInpu_reverseRPY_Init(&manual_waveInput_DW.sf_reverseRPY1);

    // SystemInitialize for MATLAB Function: '<Root>/reverse RPY'
    manual_waveInpu_reverseRPY_Init(&manual_waveInput_DW.sf_reverseRPY);

    // SystemInitialize for Enabled SubSystem: '<S33>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S36>/In1' incorporates:
    //   Outport: '<S36>/Out1'

    manual_waveInput_B.In1_l = manual_waveInput_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S33>/Enabled Subsystem'

    // Start for MATLABSystem: '<S24>/SourceBlock'
    manual_waveInput_DW.obj_a.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_a.isInitialized = 1;
    manual_waveInput_DW.obj_a.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(manual_waveInput_DW.obj_a.orbMetadataObj,
                         &manual_waveInput_DW.obj_a.eventStructObj);
    manual_waveInput_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S30>/SourceBlock'
    manual_waveInput_DW.obj_d.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_d.isInitialized = 1;
    manual_waveInput_DW.obj_d.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(manual_waveInput_DW.obj_d.orbMetadataObj,
                         &manual_waveInput_DW.obj_d.eventStructObj);
    manual_waveInput_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S28>/SourceBlock'
    manual_waveInput_DW.obj_o.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj_o.isInitialized = 1;
    manual_waveInput_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(manual_waveInput_DW.obj_o.orbMetadataObj,
                         &manual_waveInput_DW.obj_o.eventStructObj);
    manual_waveInput_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S73>/SourceBlock'
    manual_waveInput_DW.obj.matlabCodegenIsDeleted = false;
    manual_waveInput_DW.obj.isInitialized = 1;
    manual_waveInput_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(manual_waveInput_DW.obj.orbMetadataObj,
                         &manual_waveInput_DW.obj.eventStructObj);
    manual_waveInput_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/PX4 PWM Output' incorporates:
    //   Constant: '<S9>/failsafe'

    manual_waveInput_DW.obj_l.errorStatus = 0U;
    manual_waveInput_DW.obj_l.isInitialized = 0;
    manual_waveInput_DW.obj_l.matlabCodegenIsDeleted = false;
    manual_waveInp_SystemCore_setup(&manual_waveInput_DW.obj_l,
      rtb_startingswitch, manual_waveInput_P.failsafe_Value);

    // Start for MATLABSystem: '<S33>/SourceBlock'
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

  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!manual_waveInput_DW.obj_a.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_a.isInitialized == 1) &&
        manual_waveInput_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'

  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  if (!manual_waveInput_DW.obj_d.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_d.isInitialized == 1) &&
        manual_waveInput_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S30>/SourceBlock'

  // Terminate for MATLABSystem: '<S28>/SourceBlock'
  if (!manual_waveInput_DW.obj_o.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_o.isInitialized == 1) &&
        manual_waveInput_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S28>/SourceBlock'

  // Terminate for MATLABSystem: '<S73>/SourceBlock'
  if (!manual_waveInput_DW.obj.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj.isInitialized == 1) &&
        manual_waveInput_DW.obj.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S73>/SourceBlock'
  // Terminate for MATLABSystem: '<S9>/PX4 PWM Output'
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

  // End of Terminate for MATLABSystem: '<S9>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S33>/SourceBlock'
  if (!manual_waveInput_DW.obj_m.matlabCodegenIsDeleted) {
    manual_waveInput_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((manual_waveInput_DW.obj_m.isInitialized == 1) &&
        manual_waveInput_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&manual_waveInput_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S33>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
