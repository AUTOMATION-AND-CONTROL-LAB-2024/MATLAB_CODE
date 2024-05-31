//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_control_new.cpp
//
// Code generated for Simulink model 'manual_control_new'.
//
// Model version                  : 1.25
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 15:10:04 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "manual_control_new.h"
#include "rtwtypes.h"
#include "manual_control_new_types.h"
#include "manual_control_new_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S2>/MATLAB Function1'
const int32_T manual_control_new_CALL_EVENT = -1;

// Block signals (default storage)
B_manual_control_new_T manual_control_new_B;

// Block states (default storage)
DW_manual_control_new_T manual_control_new_DW;

// Real-time model
RT_MODEL_manual_control_new_T manual_control_new_M_ =
  RT_MODEL_manual_control_new_T();
RT_MODEL_manual_control_new_T *const manual_control_new_M =
  &manual_control_new_M_;

// Forward declaration for local functions
static void manual_control_SystemCore_setup(px4_internal_block_PWM_manual_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<S2>/MATLAB Function1'
//    '<S8>/MATLAB Function7'
//
void manual_con_MATLABFunction1_Init(DW_MATLABFunction1_manual_con_T *localDW)
{
  localDW->sfEvent = manual_control_new_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S2>/MATLAB Function1'
//    '<S8>/MATLAB Function7'
//
void manual_control__MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_manual_con_T *localDW)
{
  localDW->sfEvent = manual_control_new_CALL_EVENT;
  *rty_y1 = rtu_u[0];
  *rty_y2 = rtu_u[1];
  *rty_y3 = rtu_u[2];
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

static void manual_control_SystemCore_setup(px4_internal_block_PWM_manual_T *obj,
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
void manual_control_new_step(void)
{
  int32_T At1_tmp;
  int32_T Pt1_tmp;
  int32_T i;
  real32_T rtb_Product1;
  real32_T rtb_Product2;
  real32_T rtb_fcn3;
  real32_T rtb_fcn5;
  real32_T y_k_tmp;
  real32_T y_k_tmp_0;
  real32_T y_k_tmp_1;
  real32_T y_k_tmp_2;
  uint16_T rtb_DataTypeConversion1_c;
  uint16_T rtb_DataTypeConversion1_h;
  uint16_T rtb_DataTypeConversion1_o;
  uint16_T rtb_DataTypeConversion1_p;
  boolean_T b_varargout_1;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_js);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S16>/Discrete Time'
  //   DigitalClock: '<S19>/Discrete Time'
  //   DigitalClock: '<S7>/Discrete Time1'

  manual_control_new_B.DigitalClock1 = manual_control_new_M->Timing.taskTime0;

  // DataTypeConversion: '<S31>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant7'
  //   Constant: '<S31>/Constant'
  //   Gain: '<Root>/Motor1'
  //   Sum: '<S31>/Sum'

  manual_control_new_B.a22 = floor(manual_control_new_P.Motor1_Gain *
    manual_control_new_P.Constant7_Value + manual_control_new_P.Constant_Value_n);
  if (rtIsNaN(manual_control_new_B.a22) || rtIsInf(manual_control_new_B.a22)) {
    manual_control_new_B.a22 = 0.0;
  } else {
    manual_control_new_B.a22 = fmod(manual_control_new_B.a22, 65536.0);
  }

  rtb_DataTypeConversion1_c = static_cast<uint16_T>(manual_control_new_B.a22 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_control_new_B.a22)))) : static_cast<int32_T>(
    static_cast<uint16_T>(manual_control_new_B.a22)));

  // End of DataTypeConversion: '<S31>/Data Type Conversion1'

  // DataTypeConversion: '<S3>/Data Type Conversion'
  manual_control_new_B.DataTypeConversion = rtb_DataTypeConversion1_c;

  // DataTypeConversion: '<S32>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S32>/Constant'
  //   Gain: '<Root>/Motor2'
  //   Sum: '<S32>/Sum'

  manual_control_new_B.a22 = floor(manual_control_new_P.Motor2_Gain *
    manual_control_new_P.Constant3_Value + manual_control_new_P.Constant_Value_j);
  if (rtIsNaN(manual_control_new_B.a22) || rtIsInf(manual_control_new_B.a22)) {
    manual_control_new_B.a22 = 0.0;
  } else {
    manual_control_new_B.a22 = fmod(manual_control_new_B.a22, 65536.0);
  }

  rtb_DataTypeConversion1_h = static_cast<uint16_T>(manual_control_new_B.a22 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_control_new_B.a22)))) : static_cast<int32_T>(
    static_cast<uint16_T>(manual_control_new_B.a22)));

  // End of DataTypeConversion: '<S32>/Data Type Conversion1'

  // DataTypeConversion: '<S3>/Data Type Conversion1'
  manual_control_new_B.DataTypeConversion1 = rtb_DataTypeConversion1_h;

  // DataTypeConversion: '<S33>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant5'
  //   Constant: '<S33>/Constant'
  //   Gain: '<Root>/Motor3'
  //   Sum: '<S33>/Sum'

  manual_control_new_B.a22 = floor(manual_control_new_P.Motor3_Gain *
    manual_control_new_P.Constant5_Value +
    manual_control_new_P.Constant_Value_pr);
  if (rtIsNaN(manual_control_new_B.a22) || rtIsInf(manual_control_new_B.a22)) {
    manual_control_new_B.a22 = 0.0;
  } else {
    manual_control_new_B.a22 = fmod(manual_control_new_B.a22, 65536.0);
  }

  rtb_DataTypeConversion1_p = static_cast<uint16_T>(manual_control_new_B.a22 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_control_new_B.a22)))) : static_cast<int32_T>(
    static_cast<uint16_T>(manual_control_new_B.a22)));

  // End of DataTypeConversion: '<S33>/Data Type Conversion1'

  // DataTypeConversion: '<S3>/Data Type Conversion2'
  manual_control_new_B.DataTypeConversion2 = rtb_DataTypeConversion1_p;

  // DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S34>/Constant'
  //   Gain: '<Root>/Motor4'
  //   Sum: '<S34>/Sum'

  manual_control_new_B.a22 = floor(manual_control_new_P.Motor4_Gain *
    manual_control_new_P.Constant1_Value + manual_control_new_P.Constant_Value_d);
  if (rtIsNaN(manual_control_new_B.a22) || rtIsInf(manual_control_new_B.a22)) {
    manual_control_new_B.a22 = 0.0;
  } else {
    manual_control_new_B.a22 = fmod(manual_control_new_B.a22, 65536.0);
  }

  rtb_DataTypeConversion1_o = static_cast<uint16_T>(manual_control_new_B.a22 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-manual_control_new_B.a22)))) : static_cast<int32_T>(
    static_cast<uint16_T>(manual_control_new_B.a22)));

  // End of DataTypeConversion: '<S34>/Data Type Conversion1'

  // DataTypeConversion: '<S3>/Data Type Conversion3'
  manual_control_new_B.DataTypeConversion3 = rtb_DataTypeConversion1_o;

  // MATLABSystem: '<S41>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_new_DW.obj_jj.orbMetadataObj,
    &manual_control_new_DW.obj_jj.eventStructObj,
    &manual_control_new_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S41>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S42>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S42>/In1'
    manual_control_new_B.In1_i = manual_control_new_B.b_varargout_2_c;
    srUpdateBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_js);
  }

  // End of MATLABSystem: '<S41>/SourceBlock'
  // End of Outputs for SubSystem: '<S41>/Enabled Subsystem'

  // MATLABSystem: '<S43>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_new_DW.obj_j.orbMetadataObj,
    &manual_control_new_DW.obj_j.eventStructObj,
    &manual_control_new_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S43>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S44>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S44>/In1'
    manual_control_new_B.In1_n = manual_control_new_B.b_varargout_2_k;
    srUpdateBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S43>/SourceBlock'
  // End of Outputs for SubSystem: '<S43>/Enabled Subsystem'

  // MATLABSystem: '<S55>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_new_DW.obj_c.orbMetadataObj,
    &manual_control_new_DW.obj_c.eventStructObj,
    &manual_control_new_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S56>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S56>/In1'
    manual_control_new_B.In1 = manual_control_new_B.b_varargout_2;
    srUpdateBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S55>/SourceBlock'
  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // Sqrt: '<S53>/sqrt' incorporates:
  //   Product: '<S54>/Product'
  //   Product: '<S54>/Product1'
  //   Product: '<S54>/Product2'
  //   Product: '<S54>/Product3'
  //   Sum: '<S54>/Sum'

  manual_control_new_B.Product3 = static_cast<real32_T>(sqrt(static_cast<real_T>
    (((manual_control_new_B.In1.q[0] * manual_control_new_B.In1.q[0] +
       manual_control_new_B.In1.q[1] * manual_control_new_B.In1.q[1]) +
      manual_control_new_B.In1.q[2] * manual_control_new_B.In1.q[2]) +
     manual_control_new_B.In1.q[3] * manual_control_new_B.In1.q[3])));

  // Product: '<S48>/Product'
  rtb_fcn5 = manual_control_new_B.In1.q[0] / manual_control_new_B.Product3;

  // Product: '<S48>/Product1'
  rtb_Product1 = manual_control_new_B.In1.q[1] / manual_control_new_B.Product3;

  // Product: '<S48>/Product2'
  rtb_Product2 = manual_control_new_B.In1.q[2] / manual_control_new_B.Product3;

  // Product: '<S48>/Product3'
  manual_control_new_B.Product3 = manual_control_new_B.In1.q[3] /
    manual_control_new_B.Product3;

  // Fcn: '<S38>/fcn3'
  rtb_fcn3 = (rtb_Product1 * manual_control_new_B.Product3 - rtb_fcn5 *
              rtb_Product2) * -2.0F;

  // If: '<S49>/If' incorporates:
  //   Constant: '<S50>/Constant'
  //   Constant: '<S51>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S49>/If Action Subsystem' incorporates:
    //   ActionPort: '<S50>/Action Port'

    rtb_fcn3 = manual_control_new_P.Constant_Value_o;

    // End of Outputs for SubSystem: '<S49>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S49>/If Action Subsystem' incorporates:
    //   ActionPort: '<S50>/Action Port'

    // Update for If: '<S49>/If' incorporates:
    //   Constant: '<S50>/Constant'

    srUpdateBC(manual_control_new_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S49>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S49>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S51>/Action Port'

    rtb_fcn3 = manual_control_new_P.Constant_Value_e5;

    // End of Outputs for SubSystem: '<S49>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S49>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S51>/Action Port'

    // Update for If: '<S49>/If' incorporates:
    //   Constant: '<S51>/Constant'

    srUpdateBC(manual_control_new_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S49>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S49>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S52>/Action Port'

    // Update for If: '<S49>/If'
    srUpdateBC(manual_control_new_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S49>/If Action Subsystem2'
  }

  // End of If: '<S49>/If'

  // Fcn: '<S38>/fcn5' incorporates:
  //   Fcn: '<S38>/fcn2'

  y_k_tmp = rtb_fcn5 * rtb_fcn5;
  y_k_tmp_0 = rtb_Product1 * rtb_Product1;
  y_k_tmp_1 = rtb_Product2 * rtb_Product2;
  y_k_tmp_2 = manual_control_new_B.Product3 * manual_control_new_B.Product3;

  // MATLAB Function: '<S4>/correct sequence' incorporates:
  //   Fcn: '<S38>/fcn4'
  //   Fcn: '<S38>/fcn5'
  //   Trigonometry: '<S47>/Trigonometric Function3'

  manual_control_new_B.y_k[0] = rt_atan2f_snf((rtb_Product2 *
    manual_control_new_B.Product3 + rtb_fcn5 * rtb_Product1) * 2.0F, ((y_k_tmp -
    y_k_tmp_0) - y_k_tmp_1) + y_k_tmp_2);

  // Trigonometry: '<S47>/trigFcn'
  if (rtb_fcn3 > 1.0F) {
    rtb_fcn3 = 1.0F;
  } else if (rtb_fcn3 < -1.0F) {
    rtb_fcn3 = -1.0F;
  }

  // MATLAB Function: '<S4>/correct sequence' incorporates:
  //   Fcn: '<S38>/fcn1'
  //   Fcn: '<S38>/fcn2'
  //   Trigonometry: '<S47>/Trigonometric Function1'
  //   Trigonometry: '<S47>/trigFcn'

  manual_control_new_B.y_k[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (rtb_fcn3)));
  manual_control_new_B.y_k[2] = rt_atan2f_snf((rtb_Product1 * rtb_Product2 +
    rtb_fcn5 * manual_control_new_B.Product3) * 2.0F, ((y_k_tmp + y_k_tmp_0) -
    y_k_tmp_1) - y_k_tmp_2);

  // MATLABSystem: '<S45>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_new_DW.obj_h.orbMetadataObj,
    &manual_control_new_DW.obj_h.eventStructObj,
    &manual_control_new_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S45>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S46>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S46>/In1'
    manual_control_new_B.In1_f = manual_control_new_B.b_varargout_2_cx;
    srUpdateBC(manual_control_new_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of MATLABSystem: '<S45>/SourceBlock'
  // End of Outputs for SubSystem: '<S45>/Enabled Subsystem'

  // DataTypeConversion: '<S3>/Data Type Conversion4'
  manual_control_new_B.DataTypeConversion4[0] = manual_control_new_B.In1_i.x;
  manual_control_new_B.DataTypeConversion4[1] = manual_control_new_B.In1_i.y;
  manual_control_new_B.DataTypeConversion4[2] = manual_control_new_B.In1_i.z;
  manual_control_new_B.DataTypeConversion4[3] = manual_control_new_B.In1_n.x;
  manual_control_new_B.DataTypeConversion4[4] = manual_control_new_B.In1_n.y;
  manual_control_new_B.DataTypeConversion4[5] = manual_control_new_B.In1_n.z;
  manual_control_new_B.DataTypeConversion4[6] =
    manual_control_new_B.In1.rollspeed;
  manual_control_new_B.DataTypeConversion4[7] =
    manual_control_new_B.In1.pitchspeed;
  manual_control_new_B.DataTypeConversion4[8] =
    manual_control_new_B.In1.yawspeed;
  manual_control_new_B.DataTypeConversion4[12] = manual_control_new_B.In1_f.x;
  manual_control_new_B.DataTypeConversion4[13] = manual_control_new_B.In1_f.y;
  manual_control_new_B.DataTypeConversion4[14] = manual_control_new_B.In1_f.z;

  // DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn'
  manual_control_new_B.numAccum =
    manual_control_new_P.DiscreteTransferFcn_NumCoef *
    manual_control_new_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn1'
  manual_control_new_B.numAccum_c =
    manual_control_new_P.DiscreteTransferFcn1_NumCoef *
    manual_control_new_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn2'
  manual_control_new_B.numAccum_f =
    manual_control_new_P.DiscreteTransferFcn2_NumCoef *
    manual_control_new_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S21>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S14>/MATLAB Function'

  manual_control_new_B.TmpSignalConversionAtSFun_a[0] =
    manual_control_new_B.numAccum;
  manual_control_new_B.TmpSignalConversionAtSFun_a[1] =
    manual_control_new_B.numAccum_c;
  manual_control_new_B.TmpSignalConversionAtSFun_a[2] =
    manual_control_new_B.numAccum_f;

  // DataTypeConversion: '<S3>/Data Type Conversion4'
  manual_control_new_B.DataTypeConversion4[9] = manual_control_new_B.y_k[0];

  // Delay: '<S14>/Delay'
  manual_control_new_B.rtb_Delay_f_idx_0 = manual_control_new_DW.Delay_DSTATE_k
    [0];

  // Delay: '<S14>/Delay1'
  manual_control_new_B.rtb_Delay1_a_idx_0 =
    manual_control_new_DW.Delay1_DSTATE_f[0];

  // Delay: '<S14>/Delay2'
  manual_control_new_B.rtb_Delay2_o_idx_0 =
    manual_control_new_DW.Delay2_DSTATE_b[0];

  // Delay: '<S14>/Delay3'
  manual_control_new_B.rtb_Delay3_a_idx_0 =
    manual_control_new_DW.Delay3_DSTATE_f[0];

  // Delay: '<S14>/Delay4'
  manual_control_new_B.rtb_Delay4_i_idx_0 =
    manual_control_new_DW.Delay4_DSTATE_l[0];

  // Delay: '<S14>/Delay5'
  manual_control_new_B.rtb_Delay5_n_idx_0 =
    manual_control_new_DW.Delay5_DSTATE_d[0];

  // Delay: '<S14>/Delay6'
  manual_control_new_B.rtb_Delay6_p_idx_0 =
    manual_control_new_DW.Delay6_DSTATE_c[0];

  // Delay: '<S14>/Delay7'
  manual_control_new_B.rtb_Delay7_n_idx_0 =
    manual_control_new_DW.Delay7_DSTATE_p[0];

  // Delay: '<S14>/Delay8'
  manual_control_new_B.rtb_Delay8_c_idx_0 =
    manual_control_new_DW.Delay8_DSTATE_g[0];

  // Delay: '<S14>/Delay9'
  manual_control_new_B.rtb_Delay9_e_idx_0 =
    manual_control_new_DW.Delay9_DSTATE_a[0];

  // Delay: '<S14>/Delay10'
  manual_control_new_B.rtb_Delay10_n_idx_0 =
    manual_control_new_DW.Delay10_DSTATE_e[0];

  // Delay: '<S14>/Delay11'
  manual_control_new_B.rtb_Delay11_g_idx_0 =
    manual_control_new_DW.Delay11_DSTATE_b[0];

  // Delay: '<S14>/Delay12'
  manual_control_new_B.rtb_Delay12_e_idx_0 =
    manual_control_new_DW.Delay12_DSTATE_i[0];

  // Delay: '<S14>/Delay13'
  manual_control_new_B.rtb_Delay13_e_idx_0 =
    manual_control_new_DW.Delay13_DSTATE_d[0];

  // Delay: '<S14>/Delay14'
  manual_control_new_B.rtb_Delay14_p_idx_0 =
    manual_control_new_DW.Delay14_DSTATE_d[0];

  // Delay: '<S14>/Delay15'
  manual_control_new_B.rtb_Delay15_idx_0 = manual_control_new_DW.Delay15_DSTATE
    [0];

  // Delay: '<S14>/Delay20'
  manual_control_new_B.rtb_Delay20_h_idx_0 =
    manual_control_new_DW.Delay20_DSTATE_k[0];

  // Delay: '<S14>/Delay21'
  manual_control_new_B.rtb_Delay21_b_idx_0 =
    manual_control_new_DW.Delay21_DSTATE_l[0];

  // Delay: '<S14>/Delay22'
  manual_control_new_B.rtb_Delay22_k_idx_0 =
    manual_control_new_DW.Delay22_DSTATE_m[0];

  // Delay: '<S14>/Delay23'
  manual_control_new_B.rtb_Delay23_g_idx_0 =
    manual_control_new_DW.Delay23_DSTATE_f[0];

  // Delay: '<S14>/Delay24'
  manual_control_new_B.rtb_Delay24_idx_0 = manual_control_new_DW.Delay24_DSTATE
    [0];

  // Delay: '<S14>/Delay25'
  manual_control_new_B.rtb_Delay25_idx_0 = manual_control_new_DW.Delay25_DSTATE
    [0];

  // Delay: '<S14>/Delay26'
  manual_control_new_B.rtb_Delay26_idx_0 = manual_control_new_DW.Delay26_DSTATE
    [0];

  // Delay: '<S14>/Delay27'
  manual_control_new_B.rtb_Delay27_idx_0 = manual_control_new_DW.Delay27_DSTATE
    [0];

  // Delay: '<S14>/Delay16'
  manual_control_new_B.rtb_Delay16_idx_0 = manual_control_new_DW.Delay16_DSTATE
    [0];

  // Delay: '<S14>/Delay17'
  manual_control_new_B.rtb_Delay17_idx_0 = manual_control_new_DW.Delay17_DSTATE
    [0];

  // Delay: '<S14>/Delay18'
  manual_control_new_B.rtb_Delay18_idx_0 = manual_control_new_DW.Delay18_DSTATE
    [0];

  // SignalConversion generated from: '<S21>/ SFunction ' incorporates:
  //   Delay: '<S14>/Delay'
  //   Delay: '<S14>/Delay1'
  //   Delay: '<S14>/Delay10'
  //   Delay: '<S14>/Delay11'
  //   Delay: '<S14>/Delay12'
  //   Delay: '<S14>/Delay13'
  //   Delay: '<S14>/Delay14'
  //   Delay: '<S14>/Delay15'
  //   Delay: '<S14>/Delay16'
  //   Delay: '<S14>/Delay17'
  //   Delay: '<S14>/Delay18'
  //   Delay: '<S14>/Delay19'
  //   Delay: '<S14>/Delay2'
  //   Delay: '<S14>/Delay20'
  //   Delay: '<S14>/Delay21'
  //   Delay: '<S14>/Delay22'
  //   Delay: '<S14>/Delay23'
  //   Delay: '<S14>/Delay24'
  //   Delay: '<S14>/Delay25'
  //   Delay: '<S14>/Delay26'
  //   Delay: '<S14>/Delay27'
  //   Delay: '<S14>/Delay3'
  //   Delay: '<S14>/Delay4'
  //   Delay: '<S14>/Delay5'
  //   Delay: '<S14>/Delay6'
  //   Delay: '<S14>/Delay7'
  //   Delay: '<S14>/Delay8'
  //   Delay: '<S14>/Delay9'
  //   MATLAB Function: '<S14>/MATLAB Function'

  manual_control_new_B.TmpSignalConversionAtSFun_a[3] =
    manual_control_new_DW.Delay_DSTATE_k[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[6] =
    manual_control_new_DW.Delay1_DSTATE_f[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[9] =
    manual_control_new_DW.Delay2_DSTATE_b[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[12] =
    manual_control_new_DW.Delay3_DSTATE_f[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[15] =
    manual_control_new_DW.Delay4_DSTATE_l[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[18] =
    manual_control_new_DW.Delay5_DSTATE_d[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[21] =
    manual_control_new_DW.Delay6_DSTATE_c[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[24] =
    manual_control_new_DW.Delay7_DSTATE_p[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[27] =
    manual_control_new_DW.Delay8_DSTATE_g[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[30] =
    manual_control_new_DW.Delay9_DSTATE_a[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[33] =
    manual_control_new_DW.Delay10_DSTATE_e[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[36] =
    manual_control_new_DW.Delay11_DSTATE_b[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[39] =
    manual_control_new_DW.Delay12_DSTATE_i[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[42] =
    manual_control_new_DW.Delay13_DSTATE_d[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[45] =
    manual_control_new_DW.Delay14_DSTATE_d[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[48] =
    manual_control_new_DW.Delay15_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[51] =
    manual_control_new_DW.Delay20_DSTATE_k[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[54] =
    manual_control_new_DW.Delay21_DSTATE_l[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[57] =
    manual_control_new_DW.Delay22_DSTATE_m[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[60] =
    manual_control_new_DW.Delay23_DSTATE_f[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[63] =
    manual_control_new_DW.Delay24_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[66] =
    manual_control_new_DW.Delay25_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[69] =
    manual_control_new_DW.Delay26_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[72] =
    manual_control_new_DW.Delay27_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[75] =
    manual_control_new_DW.Delay16_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[78] =
    manual_control_new_DW.Delay17_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[81] =
    manual_control_new_DW.Delay18_DSTATE[0];
  manual_control_new_B.TmpSignalConversionAtSFun_a[84] =
    manual_control_new_DW.Delay19_DSTATE[0];

  // DataTypeConversion: '<S3>/Data Type Conversion4'
  manual_control_new_B.DataTypeConversion4[10] = manual_control_new_B.y_k[1];

  // Delay: '<S14>/Delay'
  manual_control_new_B.rtb_Delay_f_idx_1 = manual_control_new_DW.Delay_DSTATE_k
    [1];

  // Delay: '<S14>/Delay1'
  manual_control_new_B.rtb_Delay1_a_idx_1 =
    manual_control_new_DW.Delay1_DSTATE_f[1];

  // Delay: '<S14>/Delay2'
  manual_control_new_B.rtb_Delay2_o_idx_1 =
    manual_control_new_DW.Delay2_DSTATE_b[1];

  // Delay: '<S14>/Delay3'
  manual_control_new_B.rtb_Delay3_a_idx_1 =
    manual_control_new_DW.Delay3_DSTATE_f[1];

  // Delay: '<S14>/Delay4'
  manual_control_new_B.rtb_Delay4_i_idx_1 =
    manual_control_new_DW.Delay4_DSTATE_l[1];

  // Delay: '<S14>/Delay5'
  manual_control_new_B.rtb_Delay5_n_idx_1 =
    manual_control_new_DW.Delay5_DSTATE_d[1];

  // Delay: '<S14>/Delay6'
  manual_control_new_B.rtb_Delay6_p_idx_1 =
    manual_control_new_DW.Delay6_DSTATE_c[1];

  // Delay: '<S14>/Delay7'
  manual_control_new_B.rtb_Delay7_n_idx_1 =
    manual_control_new_DW.Delay7_DSTATE_p[1];

  // Delay: '<S14>/Delay8'
  manual_control_new_B.rtb_Delay8_c_idx_1 =
    manual_control_new_DW.Delay8_DSTATE_g[1];

  // Delay: '<S14>/Delay9'
  manual_control_new_B.rtb_Delay9_e_idx_1 =
    manual_control_new_DW.Delay9_DSTATE_a[1];

  // Delay: '<S14>/Delay10'
  manual_control_new_B.rtb_Delay10_n_idx_1 =
    manual_control_new_DW.Delay10_DSTATE_e[1];

  // Delay: '<S14>/Delay11'
  manual_control_new_B.rtb_Delay11_g_idx_1 =
    manual_control_new_DW.Delay11_DSTATE_b[1];

  // Delay: '<S14>/Delay12'
  manual_control_new_B.rtb_Delay12_e_idx_1 =
    manual_control_new_DW.Delay12_DSTATE_i[1];

  // Delay: '<S14>/Delay13'
  manual_control_new_B.rtb_Delay13_e_idx_1 =
    manual_control_new_DW.Delay13_DSTATE_d[1];

  // Delay: '<S14>/Delay14'
  manual_control_new_B.rtb_Delay14_p_idx_1 =
    manual_control_new_DW.Delay14_DSTATE_d[1];

  // Delay: '<S14>/Delay15'
  manual_control_new_B.rtb_Delay15_idx_1 = manual_control_new_DW.Delay15_DSTATE
    [1];

  // Delay: '<S14>/Delay20'
  manual_control_new_B.rtb_Delay20_h_idx_1 =
    manual_control_new_DW.Delay20_DSTATE_k[1];

  // Delay: '<S14>/Delay21'
  manual_control_new_B.rtb_Delay21_b_idx_1 =
    manual_control_new_DW.Delay21_DSTATE_l[1];

  // Delay: '<S14>/Delay22'
  manual_control_new_B.rtb_Delay22_k_idx_1 =
    manual_control_new_DW.Delay22_DSTATE_m[1];

  // Delay: '<S14>/Delay23'
  manual_control_new_B.rtb_Delay23_g_idx_1 =
    manual_control_new_DW.Delay23_DSTATE_f[1];

  // Delay: '<S14>/Delay24'
  manual_control_new_B.rtb_Delay24_idx_1 = manual_control_new_DW.Delay24_DSTATE
    [1];

  // Delay: '<S14>/Delay25'
  manual_control_new_B.rtb_Delay25_idx_1 = manual_control_new_DW.Delay25_DSTATE
    [1];

  // Delay: '<S14>/Delay26'
  manual_control_new_B.rtb_Delay26_idx_1 = manual_control_new_DW.Delay26_DSTATE
    [1];

  // Delay: '<S14>/Delay27'
  manual_control_new_B.rtb_Delay27_idx_1 = manual_control_new_DW.Delay27_DSTATE
    [1];

  // Delay: '<S14>/Delay16'
  manual_control_new_B.rtb_Delay16_idx_1 = manual_control_new_DW.Delay16_DSTATE
    [1];

  // Delay: '<S14>/Delay17'
  manual_control_new_B.rtb_Delay17_idx_1 = manual_control_new_DW.Delay17_DSTATE
    [1];

  // Delay: '<S14>/Delay18'
  manual_control_new_B.rtb_Delay18_idx_1 = manual_control_new_DW.Delay18_DSTATE
    [1];

  // SignalConversion generated from: '<S21>/ SFunction ' incorporates:
  //   Delay: '<S14>/Delay'
  //   Delay: '<S14>/Delay1'
  //   Delay: '<S14>/Delay10'
  //   Delay: '<S14>/Delay11'
  //   Delay: '<S14>/Delay12'
  //   Delay: '<S14>/Delay13'
  //   Delay: '<S14>/Delay14'
  //   Delay: '<S14>/Delay15'
  //   Delay: '<S14>/Delay16'
  //   Delay: '<S14>/Delay17'
  //   Delay: '<S14>/Delay18'
  //   Delay: '<S14>/Delay19'
  //   Delay: '<S14>/Delay2'
  //   Delay: '<S14>/Delay20'
  //   Delay: '<S14>/Delay21'
  //   Delay: '<S14>/Delay22'
  //   Delay: '<S14>/Delay23'
  //   Delay: '<S14>/Delay24'
  //   Delay: '<S14>/Delay25'
  //   Delay: '<S14>/Delay26'
  //   Delay: '<S14>/Delay27'
  //   Delay: '<S14>/Delay3'
  //   Delay: '<S14>/Delay4'
  //   Delay: '<S14>/Delay5'
  //   Delay: '<S14>/Delay6'
  //   Delay: '<S14>/Delay7'
  //   Delay: '<S14>/Delay8'
  //   Delay: '<S14>/Delay9'
  //   MATLAB Function: '<S14>/MATLAB Function'

  manual_control_new_B.TmpSignalConversionAtSFun_a[4] =
    manual_control_new_DW.Delay_DSTATE_k[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[7] =
    manual_control_new_DW.Delay1_DSTATE_f[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[10] =
    manual_control_new_DW.Delay2_DSTATE_b[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[13] =
    manual_control_new_DW.Delay3_DSTATE_f[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[16] =
    manual_control_new_DW.Delay4_DSTATE_l[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[19] =
    manual_control_new_DW.Delay5_DSTATE_d[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[22] =
    manual_control_new_DW.Delay6_DSTATE_c[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[25] =
    manual_control_new_DW.Delay7_DSTATE_p[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[28] =
    manual_control_new_DW.Delay8_DSTATE_g[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[31] =
    manual_control_new_DW.Delay9_DSTATE_a[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[34] =
    manual_control_new_DW.Delay10_DSTATE_e[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[37] =
    manual_control_new_DW.Delay11_DSTATE_b[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[40] =
    manual_control_new_DW.Delay12_DSTATE_i[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[43] =
    manual_control_new_DW.Delay13_DSTATE_d[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[46] =
    manual_control_new_DW.Delay14_DSTATE_d[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[49] =
    manual_control_new_DW.Delay15_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[52] =
    manual_control_new_DW.Delay20_DSTATE_k[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[55] =
    manual_control_new_DW.Delay21_DSTATE_l[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[58] =
    manual_control_new_DW.Delay22_DSTATE_m[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[61] =
    manual_control_new_DW.Delay23_DSTATE_f[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[64] =
    manual_control_new_DW.Delay24_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[67] =
    manual_control_new_DW.Delay25_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[70] =
    manual_control_new_DW.Delay26_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[73] =
    manual_control_new_DW.Delay27_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[76] =
    manual_control_new_DW.Delay16_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[79] =
    manual_control_new_DW.Delay17_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[82] =
    manual_control_new_DW.Delay18_DSTATE[1];
  manual_control_new_B.TmpSignalConversionAtSFun_a[85] =
    manual_control_new_DW.Delay19_DSTATE[1];

  // DataTypeConversion: '<S3>/Data Type Conversion4'
  manual_control_new_B.DataTypeConversion4[11] = manual_control_new_B.y_k[2];

  // Delay: '<S14>/Delay'
  manual_control_new_B.Delay_DSTATE_k = manual_control_new_DW.Delay_DSTATE_k[2];

  // Delay: '<S14>/Delay1'
  manual_control_new_B.Delay1_DSTATE_f = manual_control_new_DW.Delay1_DSTATE_f[2];

  // Delay: '<S14>/Delay2'
  manual_control_new_B.Delay2_DSTATE_b = manual_control_new_DW.Delay2_DSTATE_b[2];

  // Delay: '<S14>/Delay3'
  manual_control_new_B.Delay3_DSTATE_f = manual_control_new_DW.Delay3_DSTATE_f[2];

  // Delay: '<S14>/Delay4'
  manual_control_new_B.Delay4_DSTATE_l = manual_control_new_DW.Delay4_DSTATE_l[2];

  // Delay: '<S14>/Delay5'
  manual_control_new_B.Delay5_DSTATE_d = manual_control_new_DW.Delay5_DSTATE_d[2];

  // Delay: '<S14>/Delay6'
  manual_control_new_B.Delay6_DSTATE_c = manual_control_new_DW.Delay6_DSTATE_c[2];

  // Delay: '<S14>/Delay7'
  manual_control_new_B.Delay7_DSTATE_p = manual_control_new_DW.Delay7_DSTATE_p[2];

  // Delay: '<S14>/Delay8'
  manual_control_new_B.Delay8_DSTATE_g = manual_control_new_DW.Delay8_DSTATE_g[2];

  // Delay: '<S14>/Delay9'
  manual_control_new_B.Delay9_DSTATE_a = manual_control_new_DW.Delay9_DSTATE_a[2];

  // Delay: '<S14>/Delay10'
  manual_control_new_B.Delay10_DSTATE_e =
    manual_control_new_DW.Delay10_DSTATE_e[2];

  // Delay: '<S14>/Delay11'
  manual_control_new_B.Delay11_DSTATE_b =
    manual_control_new_DW.Delay11_DSTATE_b[2];

  // Delay: '<S14>/Delay12'
  manual_control_new_B.Delay12_DSTATE_i =
    manual_control_new_DW.Delay12_DSTATE_i[2];

  // Delay: '<S14>/Delay13'
  manual_control_new_B.Delay13_DSTATE_d =
    manual_control_new_DW.Delay13_DSTATE_d[2];

  // Delay: '<S14>/Delay14'
  manual_control_new_B.Delay14_DSTATE_d =
    manual_control_new_DW.Delay14_DSTATE_d[2];

  // Delay: '<S14>/Delay15'
  manual_control_new_B.Delay15_DSTATE = manual_control_new_DW.Delay15_DSTATE[2];

  // Delay: '<S14>/Delay20'
  manual_control_new_B.Delay20_DSTATE_k =
    manual_control_new_DW.Delay20_DSTATE_k[2];

  // Delay: '<S14>/Delay21'
  manual_control_new_B.Delay21_DSTATE_l =
    manual_control_new_DW.Delay21_DSTATE_l[2];

  // Delay: '<S14>/Delay22'
  manual_control_new_B.Delay22_DSTATE_m =
    manual_control_new_DW.Delay22_DSTATE_m[2];

  // Delay: '<S14>/Delay23'
  manual_control_new_B.Delay23_DSTATE_f =
    manual_control_new_DW.Delay23_DSTATE_f[2];

  // Delay: '<S14>/Delay24'
  manual_control_new_B.Delay24_DSTATE = manual_control_new_DW.Delay24_DSTATE[2];

  // Delay: '<S14>/Delay25'
  manual_control_new_B.Delay25_DSTATE = manual_control_new_DW.Delay25_DSTATE[2];

  // Delay: '<S14>/Delay26'
  manual_control_new_B.Delay26_DSTATE = manual_control_new_DW.Delay26_DSTATE[2];

  // Delay: '<S14>/Delay27'
  manual_control_new_B.Delay27_DSTATE = manual_control_new_DW.Delay27_DSTATE[2];

  // Delay: '<S14>/Delay16'
  manual_control_new_B.Delay16_DSTATE = manual_control_new_DW.Delay16_DSTATE[2];

  // Delay: '<S14>/Delay17'
  manual_control_new_B.Delay17_DSTATE = manual_control_new_DW.Delay17_DSTATE[2];

  // Delay: '<S14>/Delay18'
  manual_control_new_B.Delay18_DSTATE = manual_control_new_DW.Delay18_DSTATE[2];

  // SignalConversion generated from: '<S21>/ SFunction ' incorporates:
  //   Delay: '<S14>/Delay'
  //   Delay: '<S14>/Delay1'
  //   Delay: '<S14>/Delay10'
  //   Delay: '<S14>/Delay11'
  //   Delay: '<S14>/Delay12'
  //   Delay: '<S14>/Delay13'
  //   Delay: '<S14>/Delay14'
  //   Delay: '<S14>/Delay15'
  //   Delay: '<S14>/Delay16'
  //   Delay: '<S14>/Delay17'
  //   Delay: '<S14>/Delay18'
  //   Delay: '<S14>/Delay19'
  //   Delay: '<S14>/Delay2'
  //   Delay: '<S14>/Delay20'
  //   Delay: '<S14>/Delay21'
  //   Delay: '<S14>/Delay22'
  //   Delay: '<S14>/Delay23'
  //   Delay: '<S14>/Delay24'
  //   Delay: '<S14>/Delay25'
  //   Delay: '<S14>/Delay26'
  //   Delay: '<S14>/Delay27'
  //   Delay: '<S14>/Delay3'
  //   Delay: '<S14>/Delay4'
  //   Delay: '<S14>/Delay5'
  //   Delay: '<S14>/Delay6'
  //   Delay: '<S14>/Delay7'
  //   Delay: '<S14>/Delay8'
  //   Delay: '<S14>/Delay9'
  //   MATLAB Function: '<S14>/MATLAB Function'

  manual_control_new_B.TmpSignalConversionAtSFun_a[5] =
    manual_control_new_DW.Delay_DSTATE_k[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[8] =
    manual_control_new_DW.Delay1_DSTATE_f[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[11] =
    manual_control_new_DW.Delay2_DSTATE_b[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[14] =
    manual_control_new_DW.Delay3_DSTATE_f[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[17] =
    manual_control_new_DW.Delay4_DSTATE_l[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[20] =
    manual_control_new_DW.Delay5_DSTATE_d[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[23] =
    manual_control_new_DW.Delay6_DSTATE_c[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[26] =
    manual_control_new_DW.Delay7_DSTATE_p[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[29] =
    manual_control_new_DW.Delay8_DSTATE_g[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[32] =
    manual_control_new_DW.Delay9_DSTATE_a[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[35] =
    manual_control_new_DW.Delay10_DSTATE_e[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[38] =
    manual_control_new_DW.Delay11_DSTATE_b[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[41] =
    manual_control_new_DW.Delay12_DSTATE_i[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[44] =
    manual_control_new_DW.Delay13_DSTATE_d[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[47] =
    manual_control_new_DW.Delay14_DSTATE_d[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[50] =
    manual_control_new_DW.Delay15_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[53] =
    manual_control_new_DW.Delay20_DSTATE_k[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[56] =
    manual_control_new_DW.Delay21_DSTATE_l[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[59] =
    manual_control_new_DW.Delay22_DSTATE_m[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[62] =
    manual_control_new_DW.Delay23_DSTATE_f[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[65] =
    manual_control_new_DW.Delay24_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[68] =
    manual_control_new_DW.Delay25_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[71] =
    manual_control_new_DW.Delay26_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[74] =
    manual_control_new_DW.Delay27_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[77] =
    manual_control_new_DW.Delay16_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[80] =
    manual_control_new_DW.Delay17_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[83] =
    manual_control_new_DW.Delay18_DSTATE[2];
  manual_control_new_B.TmpSignalConversionAtSFun_a[86] =
    manual_control_new_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S14>/MATLAB Function'
  for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 < 29;
       manual_control_new_B.r2++) {
    i = (manual_control_new_B.r2 + 1) * 3;
    manual_control_new_B.ph_meas =
      manual_control_new_B.TmpSignalConversionAtSFun_a[i - 3];
    manual_control_new_B.u_vect_g = manual_control_new_B.ph_meas *
      manual_control_new_B.ph_meas;
    manual_control_new_B.ph_meas =
      manual_control_new_B.TmpSignalConversionAtSFun_a[i - 2];
    manual_control_new_B.u_vect_g += manual_control_new_B.ph_meas *
      manual_control_new_B.ph_meas;
    manual_control_new_B.ph_meas =
      manual_control_new_B.TmpSignalConversionAtSFun_a[i - 1];
    manual_control_new_B.b_norm[manual_control_new_B.r2] = sqrt
      (manual_control_new_B.ph_meas * manual_control_new_B.ph_meas +
       manual_control_new_B.u_vect_g);
    manual_control_new_B.b_norm[manual_control_new_B.r2 + 29] =
      static_cast<real_T>(manual_control_new_B.r2) + 1.0;
  }

  for (i = 0; i < 28; i++) {
    manual_control_new_B.b = 27 - i;
    for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 <=
         manual_control_new_B.b; manual_control_new_B.r1++) {
      manual_control_new_B.ph_meas =
        manual_control_new_B.b_norm[manual_control_new_B.r1];
      manual_control_new_B.a22 =
        manual_control_new_B.b_norm[manual_control_new_B.r1 + 1];
      if (manual_control_new_B.ph_meas > manual_control_new_B.a22) {
        manual_control_new_B.b_norm[manual_control_new_B.r1] =
          manual_control_new_B.a22;
        manual_control_new_B.b_norm[manual_control_new_B.r1 + 1] =
          manual_control_new_B.ph_meas;
        manual_control_new_B.tth =
          manual_control_new_B.b_norm[manual_control_new_B.r1 + 29];
        manual_control_new_B.b_norm[manual_control_new_B.r1 + 29] =
          manual_control_new_B.b_norm[manual_control_new_B.r1 + 30];
        manual_control_new_B.b_norm[manual_control_new_B.r1 + 30] =
          manual_control_new_B.tth;
      }
    }
  }

  manual_control_new_B.ph_meas = manual_control_new_B.b_norm[41] * 3.0 - 2.0;
  manual_control_new_B.u_vect_g =
    manual_control_new_B.TmpSignalConversionAtSFun_a[static_cast<int32_T>
    (manual_control_new_B.ph_meas) - 1];
  manual_control_new_B.y_idx_0 = manual_control_new_B.u_vect_g;

  // Sum: '<S18>/Sum23' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S18>/Sum1'
  //   Sum: '<S18>/Sum10'
  //   Sum: '<S18>/Sum11'
  //   Sum: '<S18>/Sum12'
  //   Sum: '<S18>/Sum13'
  //   Sum: '<S18>/Sum14'
  //   Sum: '<S18>/Sum2'
  //   Sum: '<S18>/Sum20'
  //   Sum: '<S18>/Sum21'
  //   Sum: '<S18>/Sum22'
  //   Sum: '<S18>/Sum3'
  //   Sum: '<S18>/Sum4'
  //   Sum: '<S18>/Sum5'
  //   Sum: '<S18>/Sum6'
  //   Sum: '<S18>/Sum7'
  //   Sum: '<S18>/Sum8'
  //   Sum: '<S18>/Sum9'

  manual_control_new_B.Sum23_m =
    ((((((((((((((((((manual_control_new_DW.Delay_DSTATE[0] +
                      manual_control_new_B.u_vect_g) +
                     manual_control_new_DW.Delay1_DSTATE[0]) +
                    manual_control_new_DW.Delay2_DSTATE_j[0]) +
                   manual_control_new_DW.Delay3_DSTATE[0]) +
                  manual_control_new_DW.Delay4_DSTATE[0]) +
                 manual_control_new_DW.Delay5_DSTATE[0]) +
                manual_control_new_DW.Delay6_DSTATE[0]) +
               manual_control_new_DW.Delay7_DSTATE[0]) +
              manual_control_new_DW.Delay8_DSTATE[0]) +
             manual_control_new_DW.Delay9_DSTATE[0]) +
            manual_control_new_DW.Delay10_DSTATE[0]) +
           manual_control_new_DW.Delay11_DSTATE[0]) +
          manual_control_new_DW.Delay12_DSTATE[0]) +
         manual_control_new_DW.Delay13_DSTATE[0]) +
        manual_control_new_DW.Delay14_DSTATE[0]) +
       manual_control_new_DW.Delay20_DSTATE[0]) +
      manual_control_new_DW.Delay21_DSTATE[0]) +
     manual_control_new_DW.Delay22_DSTATE[0]) +
    manual_control_new_DW.Delay23_DSTATE[0];
  manual_control_new_B.Sum23[0] = manual_control_new_B.Sum23_m;

  // Sum: '<S18>/Sum24' incorporates:
  //   Sum: '<S18>/Sum23'

  manual_control_new_B.Sum24[0] = manual_control_new_B.Sum23_m;

  // MATLAB Function: '<S7>/RP_computation' incorporates:
  //   Gain: '<S18>/Gain'
  //   Sum: '<S18>/Sum23'
  //   Sum: '<S18>/Sum24'

  manual_control_new_B.u_vect[0] = -(manual_control_new_P.Gain_Gain *
    manual_control_new_B.Sum23_m);

  // MATLAB Function: '<S14>/MATLAB Function'
  manual_control_new_B.u_vect_g =
    manual_control_new_B.TmpSignalConversionAtSFun_a[static_cast<int32_T>
    (manual_control_new_B.ph_meas + 1.0) - 1];
  manual_control_new_B.y_idx_1 = manual_control_new_B.u_vect_g;

  // Sum: '<S18>/Sum23' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S18>/Sum1'
  //   Sum: '<S18>/Sum10'
  //   Sum: '<S18>/Sum11'
  //   Sum: '<S18>/Sum12'
  //   Sum: '<S18>/Sum13'
  //   Sum: '<S18>/Sum14'
  //   Sum: '<S18>/Sum2'
  //   Sum: '<S18>/Sum20'
  //   Sum: '<S18>/Sum21'
  //   Sum: '<S18>/Sum22'
  //   Sum: '<S18>/Sum3'
  //   Sum: '<S18>/Sum4'
  //   Sum: '<S18>/Sum5'
  //   Sum: '<S18>/Sum6'
  //   Sum: '<S18>/Sum7'
  //   Sum: '<S18>/Sum8'
  //   Sum: '<S18>/Sum9'

  manual_control_new_B.Sum23_m =
    ((((((((((((((((((manual_control_new_DW.Delay_DSTATE[1] +
                      manual_control_new_B.u_vect_g) +
                     manual_control_new_DW.Delay1_DSTATE[1]) +
                    manual_control_new_DW.Delay2_DSTATE_j[1]) +
                   manual_control_new_DW.Delay3_DSTATE[1]) +
                  manual_control_new_DW.Delay4_DSTATE[1]) +
                 manual_control_new_DW.Delay5_DSTATE[1]) +
                manual_control_new_DW.Delay6_DSTATE[1]) +
               manual_control_new_DW.Delay7_DSTATE[1]) +
              manual_control_new_DW.Delay8_DSTATE[1]) +
             manual_control_new_DW.Delay9_DSTATE[1]) +
            manual_control_new_DW.Delay10_DSTATE[1]) +
           manual_control_new_DW.Delay11_DSTATE[1]) +
          manual_control_new_DW.Delay12_DSTATE[1]) +
         manual_control_new_DW.Delay13_DSTATE[1]) +
        manual_control_new_DW.Delay14_DSTATE[1]) +
       manual_control_new_DW.Delay20_DSTATE[1]) +
      manual_control_new_DW.Delay21_DSTATE[1]) +
     manual_control_new_DW.Delay22_DSTATE[1]) +
    manual_control_new_DW.Delay23_DSTATE[1];
  manual_control_new_B.Sum23[1] = manual_control_new_B.Sum23_m;

  // Sum: '<S18>/Sum24' incorporates:
  //   Sum: '<S18>/Sum23'

  manual_control_new_B.Sum24[1] = manual_control_new_B.Sum23_m;

  // MATLAB Function: '<S7>/RP_computation' incorporates:
  //   Gain: '<S18>/Gain'
  //   Sum: '<S18>/Sum23'
  //   Sum: '<S18>/Sum24'

  manual_control_new_B.u_vect[1] = -(manual_control_new_P.Gain_Gain *
    manual_control_new_B.Sum23_m);

  // MATLAB Function: '<S14>/MATLAB Function'
  manual_control_new_B.u_vect_g =
    manual_control_new_B.TmpSignalConversionAtSFun_a[static_cast<int32_T>
    (manual_control_new_B.ph_meas + 2.0) - 1];

  // Sum: '<S18>/Sum23' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   Sum: '<S18>/Sum'
  //   Sum: '<S18>/Sum1'
  //   Sum: '<S18>/Sum10'
  //   Sum: '<S18>/Sum11'
  //   Sum: '<S18>/Sum12'
  //   Sum: '<S18>/Sum13'
  //   Sum: '<S18>/Sum14'
  //   Sum: '<S18>/Sum2'
  //   Sum: '<S18>/Sum20'
  //   Sum: '<S18>/Sum21'
  //   Sum: '<S18>/Sum22'
  //   Sum: '<S18>/Sum3'
  //   Sum: '<S18>/Sum4'
  //   Sum: '<S18>/Sum5'
  //   Sum: '<S18>/Sum6'
  //   Sum: '<S18>/Sum7'
  //   Sum: '<S18>/Sum8'
  //   Sum: '<S18>/Sum9'

  manual_control_new_B.Sum23_m =
    ((((((((((((((((((manual_control_new_DW.Delay_DSTATE[2] +
                      manual_control_new_B.u_vect_g) +
                     manual_control_new_DW.Delay1_DSTATE[2]) +
                    manual_control_new_DW.Delay2_DSTATE_j[2]) +
                   manual_control_new_DW.Delay3_DSTATE[2]) +
                  manual_control_new_DW.Delay4_DSTATE[2]) +
                 manual_control_new_DW.Delay5_DSTATE[2]) +
                manual_control_new_DW.Delay6_DSTATE[2]) +
               manual_control_new_DW.Delay7_DSTATE[2]) +
              manual_control_new_DW.Delay8_DSTATE[2]) +
             manual_control_new_DW.Delay9_DSTATE[2]) +
            manual_control_new_DW.Delay10_DSTATE[2]) +
           manual_control_new_DW.Delay11_DSTATE[2]) +
          manual_control_new_DW.Delay12_DSTATE[2]) +
         manual_control_new_DW.Delay13_DSTATE[2]) +
        manual_control_new_DW.Delay14_DSTATE[2]) +
       manual_control_new_DW.Delay20_DSTATE[2]) +
      manual_control_new_DW.Delay21_DSTATE[2]) +
     manual_control_new_DW.Delay22_DSTATE[2]) +
    manual_control_new_DW.Delay23_DSTATE[2];
  manual_control_new_B.Sum23[2] = manual_control_new_B.Sum23_m;

  // Sum: '<S18>/Sum24' incorporates:
  //   Sum: '<S18>/Sum23'

  manual_control_new_B.Sum24[2] = manual_control_new_B.Sum23_m;

  // MATLAB Function: '<S7>/RP_computation' incorporates:
  //   Gain: '<S18>/Gain'
  //   Sum: '<S18>/Sum23'
  //   Sum: '<S18>/Sum24'

  manual_control_new_B.u_vect[2] = -(manual_control_new_P.Gain_Gain *
    manual_control_new_B.Sum23_m);
  manual_control_new_B.ph_meas = rt_atan2d_snf(manual_control_new_B.u_vect[1],
    manual_control_new_B.u_vect[2]);
  manual_control_new_B.temp[0] = manual_control_new_B.ph_meas;
  manual_control_new_B.Sum23_m = rt_atan2d_snf(-manual_control_new_B.u_vect[0],
    manual_control_new_B.u_vect[1] * sin(manual_control_new_B.ph_meas) +
    manual_control_new_B.u_vect[2] * cos(manual_control_new_B.ph_meas));
  manual_control_new_B.temp[1] = manual_control_new_B.Sum23_m;

  // MATLAB Function: '<S16>/EKF_RP' incorporates:
  //   Delay: '<S16>/Delay2'
  //   Memory: '<S16>/Memory2'
  //   Memory: '<S16>/Memory3'

  if (manual_control_new_B.DigitalClock1 -
      manual_control_new_DW.Memory2_PreviousInput >=
      manual_control_new_P.Ts_EKF_meas) {
    manual_control_new_DW.Memory2_PreviousInput =
      manual_control_new_B.DigitalClock1;
    memcpy(&manual_control_new_B.Pt1[0],
           &manual_control_new_DW.Memory3_PreviousInput[0], 25U * sizeof(real_T));
    manual_control_new_B.wq1 = manual_control_new_DW.Delay2_DSTATE[1];
    manual_control_new_B.wr1 = manual_control_new_DW.Delay2_DSTATE[2];
    for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 < 5;
         manual_control_new_B.r2++) {
      manual_control_new_B.xt[manual_control_new_B.r2] = 0.0;
    }

    memset(&manual_control_new_B.Pt[0], 0, 25U * sizeof(real_T));
    manual_control_new_B.b = static_cast<int32_T>(floor
      (manual_control_new_P.Ts_EKF_meas / manual_control_new_P.Ts_EKF_integr));
    for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 <
         manual_control_new_B.b; manual_control_new_B.r2++) {
      manual_control_new_B.cph = cos
        (manual_control_new_DW.Memory4_PreviousInput[0]);
      manual_control_new_B.cth = cos
        (manual_control_new_DW.Memory4_PreviousInput[1]);
      manual_control_new_B.sph = sin
        (manual_control_new_DW.Memory4_PreviousInput[0]);
      manual_control_new_B.tth = sin
        (manual_control_new_DW.Memory4_PreviousInput[1]) /
        manual_control_new_B.cth;
      manual_control_new_B.dv[0] = 1.0;
      manual_control_new_B.a22 = manual_control_new_B.sph *
        manual_control_new_B.tth;
      manual_control_new_B.dv[5] = manual_control_new_B.a22;
      manual_control_new_B.d = manual_control_new_B.cph *
        manual_control_new_B.tth;
      manual_control_new_B.dv[10] = manual_control_new_B.d;
      manual_control_new_B.dv[15] = 0.0;
      manual_control_new_B.dv[20] = 0.0;
      manual_control_new_B.dv[25] = 0.0;
      manual_control_new_B.dv[1] = 0.0;
      manual_control_new_B.dv[6] = manual_control_new_B.cph;
      manual_control_new_B.dv[11] = -manual_control_new_B.sph;
      manual_control_new_B.dv[16] = 0.0;
      manual_control_new_B.dv[21] = 0.0;
      manual_control_new_B.dv[26] = 0.0;
      for (i = 0; i < 6; i++) {
        manual_control_new_B.dv[5 * i + 2] = 0.0;
        manual_control_new_B.dv[5 * i + 3] = 0.0;
        manual_control_new_B.dv[5 * i + 4] = 0.0;
      }

      manual_control_new_B.dv2[0] = manual_control_new_DW.Delay2_DSTATE[0] -
        manual_control_new_DW.Memory4_PreviousInput[2];
      manual_control_new_B.xt_g = manual_control_new_B.wq1 -
        manual_control_new_DW.Memory4_PreviousInput[3];
      manual_control_new_B.dv2[1] = manual_control_new_B.xt_g;
      manual_control_new_B.d1 = manual_control_new_B.wr1 -
        manual_control_new_DW.Memory4_PreviousInput[4];
      manual_control_new_B.dv2[2] = manual_control_new_B.d1;
      manual_control_new_B.dv2[3] = manual_control_new_DW.Memory4_PreviousInput
        [2];
      manual_control_new_B.dv2[4] = manual_control_new_DW.Memory4_PreviousInput
        [3];
      manual_control_new_B.dv2[5] = manual_control_new_DW.Memory4_PreviousInput
        [4];
      manual_control_new_B.Pt[0] = manual_control_new_B.d *
        manual_control_new_B.xt_g - manual_control_new_B.a22 *
        manual_control_new_B.d1;
      manual_control_new_B.a22 = manual_control_new_B.d1 *
        manual_control_new_B.cph;
      manual_control_new_B.Pt[5] = (manual_control_new_B.xt_g *
        manual_control_new_B.sph + manual_control_new_B.a22) /
        (manual_control_new_B.cth * manual_control_new_B.cth);
      manual_control_new_B.Pt[10] = -1.0;
      manual_control_new_B.Pt[15] = -manual_control_new_B.sph *
        manual_control_new_B.tth;
      manual_control_new_B.Pt[20] = -manual_control_new_B.cph *
        manual_control_new_B.tth;
      manual_control_new_B.Pt[1] = manual_control_new_B.xt_g *
        -manual_control_new_B.sph - manual_control_new_B.a22;
      manual_control_new_B.Pt[6] = 0.0;
      manual_control_new_B.Pt[11] = 0.0;
      manual_control_new_B.Pt[16] = -manual_control_new_B.cph;
      manual_control_new_B.Pt[21] = manual_control_new_B.sph;
      for (i = 0; i < 5; i++) {
        manual_control_new_B.a22 = 0.0;
        for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 6;
             manual_control_new_B.r1++) {
          manual_control_new_B.a22 += manual_control_new_B.dv[5 *
            manual_control_new_B.r1 + i] *
            manual_control_new_B.dv2[manual_control_new_B.r1];
        }

        manual_control_new_B.xt[i] = manual_control_new_P.Ts_EKF_integr *
          manual_control_new_B.a22 +
          manual_control_new_DW.Memory4_PreviousInput[i];
        manual_control_new_B.Pt[5 * i + 2] = 0.0;
        manual_control_new_B.Pt[5 * i + 3] = 0.0;
        manual_control_new_B.Pt[5 * i + 4] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
             manual_control_new_B.r1++) {
          manual_control_new_B.tth = 0.0;
          manual_control_new_B.a22 = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i;
            manual_control_new_B.tth += manual_control_new_B.Pt1[5 *
              manual_control_new_B.r1 + Pt1_tmp] *
              manual_control_new_B.Pt[At1_tmp];
            manual_control_new_B.a22 += manual_control_new_B.Pt[5 * Pt1_tmp +
              manual_control_new_B.r1] * manual_control_new_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * manual_control_new_B.r1 + i;
          manual_control_new_B.Pt1_m[Pt1_tmp] = manual_control_new_B.a22;
          manual_control_new_B.At1[Pt1_tmp] = manual_control_new_B.tth;
        }
      }

      for (i = 0; i < 25; i++) {
        manual_control_new_B.Pt[i] = ((manual_control_new_B.At1[i] +
          manual_control_new_B.Pt1_m[i]) + manual_control_new_P.Q_phth[i]) *
          manual_control_new_P.Ts_EKF_integr + manual_control_new_B.Pt1[i];
      }

      for (i = 0; i < 5; i++) {
        manual_control_new_DW.Memory4_PreviousInput[i] =
          manual_control_new_B.xt[i];
      }

      memcpy(&manual_control_new_B.Pt1[0], &manual_control_new_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (i = 0; i < 10; i++) {
      manual_control_new_B.Lk[i] = c[i];
    }

    for (i = 0; i < 2; i++) {
      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
           manual_control_new_B.r1++) {
        manual_control_new_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          manual_control_new_B.tth += manual_control_new_B.Pt[5 * Pt1_tmp +
            manual_control_new_B.r1] * manual_control_new_B.Lk[5 * i + Pt1_tmp];
        }

        manual_control_new_B.B[manual_control_new_B.r1 + 5 * i] =
          manual_control_new_B.tth;
      }
    }

    for (i = 0; i < 10; i++) {
      manual_control_new_B.A_tmp_p[i] = b_b[i];
    }

    for (i = 0; i < 2; i++) {
      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
           manual_control_new_B.r1++) {
        manual_control_new_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          manual_control_new_B.tth += static_cast<real_T>
            (manual_control_new_B.A_tmp_p[(Pt1_tmp << 1) + i]) *
            manual_control_new_B.Pt[5 * manual_control_new_B.r1 + Pt1_tmp];
        }

        manual_control_new_B.A_tmp[i + (manual_control_new_B.r1 << 1)] =
          manual_control_new_B.tth;
      }

      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 2;
           manual_control_new_B.r1++) {
        manual_control_new_B.a22 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          manual_control_new_B.a22 += manual_control_new_B.A_tmp[(Pt1_tmp << 1)
            + i] * manual_control_new_B.Lk[5 * manual_control_new_B.r1 + Pt1_tmp];
        }

        manual_control_new_B.r2 = (manual_control_new_B.r1 << 1) + i;
        manual_control_new_B.A[manual_control_new_B.r2] =
          manual_control_new_P.R_phth[manual_control_new_B.r2] +
          manual_control_new_B.a22;
      }
    }

    if (fabs(manual_control_new_B.A[1]) > fabs(manual_control_new_B.A[0])) {
      manual_control_new_B.r1 = 1;
      manual_control_new_B.r2 = 0;
    } else {
      manual_control_new_B.r1 = 0;
      manual_control_new_B.r2 = 1;
    }

    manual_control_new_B.tth = manual_control_new_B.A[manual_control_new_B.r2] /
      manual_control_new_B.A[manual_control_new_B.r1];
    manual_control_new_B.wq1 = manual_control_new_B.A[manual_control_new_B.r1 +
      2];
    manual_control_new_B.a22 = manual_control_new_B.A[manual_control_new_B.r2 +
      2] - manual_control_new_B.wq1 * manual_control_new_B.tth;
    for (i = 0; i < 5; i++) {
      Pt1_tmp = 5 * manual_control_new_B.r1 + i;
      manual_control_new_B.Lk[Pt1_tmp] = manual_control_new_B.B[i] /
        manual_control_new_B.A[manual_control_new_B.r1];
      manual_control_new_B.b = 5 * manual_control_new_B.r2 + i;
      manual_control_new_B.Lk[manual_control_new_B.b] =
        (manual_control_new_B.B[i + 5] - manual_control_new_B.Lk[Pt1_tmp] *
         manual_control_new_B.wq1) / manual_control_new_B.a22;
      manual_control_new_B.Lk[Pt1_tmp] -=
        manual_control_new_B.Lk[manual_control_new_B.b] *
        manual_control_new_B.tth;
    }

    for (i = 0; i < 2; i++) {
      manual_control_new_B.a22 = 0.0;
      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
           manual_control_new_B.r1++) {
        manual_control_new_B.a22 += static_cast<real_T>
          (manual_control_new_B.A_tmp_p[(manual_control_new_B.r1 << 1) + i]) *
          manual_control_new_B.xt[manual_control_new_B.r1];
      }

      manual_control_new_B.temp_b[i] = manual_control_new_B.temp[i] -
        manual_control_new_B.a22;
    }

    manual_control_new_B.tth = manual_control_new_B.temp_b[1];
    manual_control_new_B.wq1 = manual_control_new_B.temp_b[0];
    for (i = 0; i < 5; i++) {
      manual_control_new_DW.Memory4_PreviousInput[i] =
        (manual_control_new_B.Lk[i + 5] * manual_control_new_B.tth +
         manual_control_new_B.Lk[i] * manual_control_new_B.wq1) +
        manual_control_new_B.xt[i];
    }

    memset(&manual_control_new_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      manual_control_new_B.Pt1[i + 5 * i] = 1.0;
    }

    for (i = 0; i < 5; i++) {
      manual_control_new_B.a22 = manual_control_new_B.Lk[i + 5];
      manual_control_new_B.tth = manual_control_new_B.Lk[i];
      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
           manual_control_new_B.r1++) {
        Pt1_tmp = manual_control_new_B.r1 << 1;
        manual_control_new_B.r2 = 5 * manual_control_new_B.r1 + i;
        manual_control_new_B.Pt1_m[manual_control_new_B.r2] =
          manual_control_new_B.Pt1[manual_control_new_B.r2] -
          (static_cast<real_T>(manual_control_new_B.A_tmp_p[Pt1_tmp + 1]) *
           manual_control_new_B.a22 + static_cast<real_T>
           (manual_control_new_B.A_tmp_p[Pt1_tmp]) * manual_control_new_B.tth);
      }

      for (manual_control_new_B.r1 = 0; manual_control_new_B.r1 < 5;
           manual_control_new_B.r1++) {
        manual_control_new_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          manual_control_new_B.tth += manual_control_new_B.Pt1_m[5 * Pt1_tmp + i]
            * manual_control_new_B.Pt[5 * manual_control_new_B.r1 + Pt1_tmp];
        }

        manual_control_new_DW.Memory3_PreviousInput[i + 5 *
          manual_control_new_B.r1] = manual_control_new_B.tth;
      }
    }
  }

  // End of MATLAB Function: '<S16>/EKF_RP'

  // MATLAB Function: '<S16>/MATLAB Function'
  manual_control_new_B.RP_estim[0] =
    manual_control_new_DW.Memory4_PreviousInput[0];
  manual_control_new_B.RP_estim[1] =
    manual_control_new_DW.Memory4_PreviousInput[1];

  // MATLAB Function: '<S7>/Y_computation' incorporates:
  //   DataTypeConversion: '<S5>/Data Type Conversion3'
  //   MATLAB Function: '<S19>/EKF_Y'
  //   MATLAB Function: '<S7>/RPY_dot_computation'

  manual_control_new_B.wr1 = sin(manual_control_new_B.RP_estim[0]);
  manual_control_new_B.cph = cos(manual_control_new_B.RP_estim[0]);
  manual_control_new_B.tth = sin(manual_control_new_B.RP_estim[1]);
  manual_control_new_B.cth = cos(manual_control_new_B.RP_estim[1]);
  manual_control_new_B.wq1 = rt_atan2d_snf(manual_control_new_B.In1_f.z *
    manual_control_new_B.wr1 - manual_control_new_B.In1_f.y *
    manual_control_new_B.cph, (manual_control_new_B.In1_f.y *
    manual_control_new_B.tth * manual_control_new_B.wr1 +
    manual_control_new_B.In1_f.x * manual_control_new_B.cth) +
    manual_control_new_B.In1_f.z * manual_control_new_B.tth *
    manual_control_new_B.cph);
  if (manual_control_new_B.wq1 < 0.0) {
    manual_control_new_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S19>/EKF_Y' incorporates:
  //   Delay: '<S19>/Delay2'
  //   MATLAB Function: '<S16>/MATLAB Function'
  //   MATLAB Function: '<S7>/Y_computation'
  //   Memory: '<S19>/Memory2'
  //   Memory: '<S19>/Memory4'

  if (manual_control_new_B.DigitalClock1 -
      manual_control_new_DW.Memory2_PreviousInput_d >=
      manual_control_new_P.Ts_EKF_meas) {
    manual_control_new_DW.Memory2_PreviousInput_d =
      manual_control_new_B.DigitalClock1;
    manual_control_new_B.xt_g = 0.0;
    manual_control_new_B.sph = 0.0;
    manual_control_new_B.b = static_cast<int32_T>(floor
      (manual_control_new_P.Ts_EKF_meas / manual_control_new_P.Ts_EKF_integr));
    if (manual_control_new_B.b - 1 >= 0) {
      manual_control_new_B.dv3[0] = 0.0;
      manual_control_new_B.dv3[1] = manual_control_new_B.wr1 /
        manual_control_new_B.cth;
      manual_control_new_B.dv3[2] = manual_control_new_B.cph /
        manual_control_new_B.cth;
      manual_control_new_B.dv3[3] = 0.0;
      manual_control_new_B.dv3[4] = 0.0;
      manual_control_new_B.dv3[5] = 0.0;
      manual_control_new_B.dv4[0] = manual_control_new_DW.Delay2_DSTATE_f[0] -
        manual_control_new_DW.Memory4_PreviousInput[2];
      manual_control_new_B.dv4[1] = manual_control_new_DW.Delay2_DSTATE_f[1] -
        manual_control_new_DW.Memory4_PreviousInput[3];
      manual_control_new_B.dv4[2] = manual_control_new_DW.Delay2_DSTATE_f[2] -
        manual_control_new_DW.Memory4_PreviousInput[4];
      manual_control_new_B.dv4[3] = manual_control_new_DW.Memory4_PreviousInput
        [2];
      manual_control_new_B.dv4[4] = manual_control_new_DW.Memory4_PreviousInput
        [3];
      manual_control_new_B.dv4[5] = manual_control_new_DW.Memory4_PreviousInput
        [4];
    }

    for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 <
         manual_control_new_B.b; manual_control_new_B.r2++) {
      manual_control_new_B.a22 = 0.0;
      for (i = 0; i < 6; i++) {
        manual_control_new_B.a22 += manual_control_new_B.dv3[i] *
          manual_control_new_B.dv4[i];
      }

      manual_control_new_B.xt_g = manual_control_new_P.Ts_EKF_integr *
        manual_control_new_B.a22 + manual_control_new_DW.Memory4_PreviousInput_l;
      manual_control_new_B.sph = ((0.0 *
        manual_control_new_DW.Memory3_PreviousInput_j +
        manual_control_new_DW.Memory3_PreviousInput_j * 0.0) +
        manual_control_new_P.q_ps) * manual_control_new_P.Ts_EKF_integr +
        manual_control_new_DW.Memory3_PreviousInput_j;
      manual_control_new_DW.Memory4_PreviousInput_l = manual_control_new_B.xt_g;
      manual_control_new_DW.Memory3_PreviousInput_j = manual_control_new_B.sph;
    }

    manual_control_new_B.a22 = manual_control_new_B.sph /
      (manual_control_new_B.sph + manual_control_new_P.r_ps);
    manual_control_new_B.xk = (manual_control_new_B.wq1 -
      manual_control_new_B.xt_g) * manual_control_new_B.a22 +
      manual_control_new_B.xt_g;
    manual_control_new_DW.Memory3_PreviousInput_j = (1.0 -
      manual_control_new_B.a22) * manual_control_new_B.sph;
  } else {
    manual_control_new_B.xk = manual_control_new_DW.Memory4_PreviousInput_l;
  }

  // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
  manual_control_new_B.a22 = manual_control_new_P.DiscreteTransferFcn_NumCoef_j *
    manual_control_new_DW.DiscreteTransferFcn_states_a;

  // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn1'
  manual_control_new_B.sph = manual_control_new_P.DiscreteTransferFcn1_NumCoef_o
    * manual_control_new_DW.DiscreteTransferFcn1_states_o;

  // DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn2'
  manual_control_new_B.xt_g =
    manual_control_new_P.DiscreteTransferFcn2_NumCoef_n *
    manual_control_new_DW.DiscreteTransferFcn2_states_i;

  // MATLAB Function: '<S7>/RPY_dot_computation' incorporates:
  //   Constant: '<S7>/Constant6'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S16>/MATLAB Function'
  //   MATLAB Function: '<S7>/Y_computation'
  //   Memory: '<S7>/Memory5'
  //   Memory: '<S7>/Memory6'

  if ((manual_control_new_B.DigitalClock1 -
       manual_control_new_DW.Memory5_PreviousInput >=
       manual_control_new_P.Ts_EKF_meas) || (manual_control_new_B.DigitalClock1 ==
       0.0)) {
    manual_control_new_B.tth /= manual_control_new_B.cth;
    manual_control_new_DW.Memory5_PreviousInput =
      manual_control_new_B.DigitalClock1;
    manual_control_new_B.dv1[0] = 1.0;
    manual_control_new_B.dv1[3] = manual_control_new_B.wr1 *
      manual_control_new_B.tth;
    manual_control_new_B.dv1[6] = manual_control_new_B.cph *
      manual_control_new_B.tth;
    manual_control_new_B.dv1[1] = 0.0;
    manual_control_new_B.dv1[4] = manual_control_new_B.cph;
    manual_control_new_B.dv1[7] = -manual_control_new_B.wr1;
    manual_control_new_B.dv1[2] = 0.0;
    manual_control_new_B.dv1[5] = manual_control_new_B.wr1 /
      manual_control_new_B.cth;
    manual_control_new_B.dv1[8] = manual_control_new_B.cph /
      manual_control_new_B.cth;
    manual_control_new_B.tth = manual_control_new_B.a22 -
      manual_control_new_DW.Memory4_PreviousInput[2] * 0.0;
    manual_control_new_B.wr1 = manual_control_new_B.sph -
      manual_control_new_DW.Memory4_PreviousInput[3] * 0.0;
    manual_control_new_B.cph = manual_control_new_B.xt_g -
      manual_control_new_DW.Memory4_PreviousInput[4] * 0.0;
    for (i = 0; i < 3; i++) {
      manual_control_new_B.RPY_rate[i] = (manual_control_new_B.dv1[i + 3] *
        manual_control_new_B.wr1 + manual_control_new_B.dv1[i] *
        manual_control_new_B.tth) + manual_control_new_B.dv1[i + 6] *
        manual_control_new_B.cph;
    }
  } else {
    manual_control_new_B.RPY_rate[0] =
      manual_control_new_DW.Memory6_PreviousInput[0];
    manual_control_new_B.RPY_rate[1] =
      manual_control_new_DW.Memory6_PreviousInput[1];
    manual_control_new_B.RPY_rate[2] =
      manual_control_new_DW.Memory6_PreviousInput[2];
  }

  // ManualSwitch: '<Root>/Manual Switch'
  if (manual_control_new_P.ManualSwitch_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch' incorporates:
    //   Constant: '<Root>/Constant6'

    manual_control_new_B.ManualSwitch[0] = manual_control_new_P.Constant6_Value
      [0];
    manual_control_new_B.ManualSwitch[1] = manual_control_new_P.Constant6_Value
      [1];
    manual_control_new_B.ManualSwitch[2] = manual_control_new_P.Constant6_Value
      [2];
    manual_control_new_B.ManualSwitch[3] = manual_control_new_P.Constant6_Value
      [3];
  } else {
    // ManualSwitch: '<Root>/Manual Switch'
    manual_control_new_B.ManualSwitch[0] =
      manual_control_new_B.DataTypeConversion;
    manual_control_new_B.ManualSwitch[1] =
      manual_control_new_B.DataTypeConversion1;
    manual_control_new_B.ManualSwitch[2] =
      manual_control_new_B.DataTypeConversion2;
    manual_control_new_B.ManualSwitch[3] =
      manual_control_new_B.DataTypeConversion3;
  }

  for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 < 15;
       manual_control_new_B.r2++) {
    // ManualSwitch: '<Root>/Manual Switch'
    if (manual_control_new_P.ManualSwitch_CurrentSetting == 1) {
      // ManualSwitch: '<Root>/Manual Switch' incorporates:
      //   Constant: '<Root>/Constant6'

      manual_control_new_B.ManualSwitch[manual_control_new_B.r2 + 4] =
        manual_control_new_P.Constant6_Value[manual_control_new_B.r2 + 4];
    } else {
      // ManualSwitch: '<Root>/Manual Switch'
      manual_control_new_B.ManualSwitch[manual_control_new_B.r2 + 4] =
        manual_control_new_B.DataTypeConversion4[manual_control_new_B.r2];
    }
  }

  // ManualSwitch: '<Root>/Manual Switch'
  if (manual_control_new_P.ManualSwitch_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch' incorporates:
    //   Constant: '<Root>/Constant6'

    manual_control_new_B.ManualSwitch[19] =
      manual_control_new_P.Constant6_Value[19];
    manual_control_new_B.ManualSwitch[20] =
      manual_control_new_P.Constant6_Value[20];
    manual_control_new_B.ManualSwitch[21] =
      manual_control_new_P.Constant6_Value[21];
    manual_control_new_B.ManualSwitch[22] =
      manual_control_new_P.Constant6_Value[22];
    manual_control_new_B.ManualSwitch[23] =
      manual_control_new_P.Constant6_Value[23];
    manual_control_new_B.ManualSwitch[24] =
      manual_control_new_P.Constant6_Value[24];
  } else {
    // ManualSwitch: '<Root>/Manual Switch' incorporates:
    //   MATLAB Function: '<S28>/MATLAB Function'
    //   SignalConversion generated from: '<S30>/ SFunction '

    manual_control_new_B.ManualSwitch[19] = manual_control_new_B.RP_estim[0];
    manual_control_new_B.ManualSwitch[20] = manual_control_new_B.RP_estim[1];
    manual_control_new_B.ManualSwitch[21] = manual_control_new_B.xk;
    manual_control_new_B.ManualSwitch[22] = manual_control_new_B.RPY_rate[0];
    manual_control_new_B.ManualSwitch[23] = manual_control_new_B.RPY_rate[1];
    manual_control_new_B.ManualSwitch[24] = manual_control_new_B.RPY_rate[2];
  }

  // SignalConversion generated from: '<Root>/To Workspace'
  manual_control_new_B.TmpSignalConversionAt_asyncqueu[0] =
    manual_control_new_B.DigitalClock1;
  memcpy(&manual_control_new_B.TmpSignalConversionAt_asyncqueu[1],
         &manual_control_new_B.ManualSwitch[0], 25U * sizeof(real_T));

  // SignalConversion generated from: '<S3>/From5'
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[0] =
    manual_control_new_B.RP_estim[0];
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[1] =
    manual_control_new_B.RP_estim[1];
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[2] =
    manual_control_new_B.xk;
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[3] =
    manual_control_new_B.RPY_rate[0];
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[4] =
    manual_control_new_B.RPY_rate[1];
  manual_control_new_B.TmpSignalConversionAtTAQSigLogg[5] =
    manual_control_new_B.RPY_rate[2];

  // Gain: '<S8>/Gain2' incorporates:
  //   MATLAB Function: '<S8>/MATLAB Function2'
  //   SignalConversion generated from: '<S26>/ SFunction '

  manual_control_new_B.Gain2[2] = manual_control_new_P.Gain2_Gain *
    manual_control_new_B.xk;

  // SignalConversion generated from: '<S16>/Delay2' incorporates:
  //   Delay: '<S16>/Delay2'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn2'

  manual_control_new_DW.Delay2_DSTATE[0] = manual_control_new_B.a22;
  manual_control_new_DW.Delay2_DSTATE[1] = manual_control_new_B.sph;
  manual_control_new_DW.Delay2_DSTATE[2] = manual_control_new_B.xt_g;

  // Gain: '<S8>/Gain2' incorporates:
  //   MATLAB Function: '<S8>/MATLAB Function2'
  //   SignalConversion generated from: '<S26>/ SFunction '

  manual_control_new_B.Gain2[0] = manual_control_new_P.Gain2_Gain *
    manual_control_new_B.RP_estim[0];

  // Gain: '<S2>/Gain' incorporates:
  //   MATLAB Function: '<S7>/RP_computation'

  manual_control_new_B.Gain_k[0] = manual_control_new_P.Gain_Gain_b *
    manual_control_new_B.ph_meas;

  // Gain: '<S8>/Gain2' incorporates:
  //   MATLAB Function: '<S8>/MATLAB Function2'
  //   SignalConversion generated from: '<S26>/ SFunction '

  manual_control_new_B.Gain2[1] = manual_control_new_P.Gain2_Gain *
    manual_control_new_B.RP_estim[1];

  // Gain: '<S2>/Gain' incorporates:
  //   MATLAB Function: '<S7>/Y_computation'

  manual_control_new_B.Gain_k[1] = manual_control_new_B.Sum23_m *
    manual_control_new_P.Gain_Gain_b;
  manual_control_new_B.Gain_k[2] = manual_control_new_P.Gain_Gain_b *
    manual_control_new_B.wq1;

  // MATLAB Function: '<S5>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S5>/Data Type Conversion2'

  manual_control_new_B.y_g[0] = manual_control_new_B.In1_n.x;
  manual_control_new_B.y_g[1] = -static_cast<real_T>
    (manual_control_new_B.In1_n.y);
  manual_control_new_B.y_g[2] = -static_cast<real_T>
    (manual_control_new_B.In1_n.z);

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S5>/Data Type Conversion1'

  manual_control_new_B.y_p[0] = -static_cast<real_T>
    (manual_control_new_B.In1_i.x);
  manual_control_new_B.y_p[1] = manual_control_new_B.In1_i.y;
  manual_control_new_B.y_p[2] = manual_control_new_B.In1_i.z;

  // Gain: '<S5>/Gain1'
  manual_control_new_B.Sum23_m = manual_control_new_B.y_g[0];
  manual_control_new_B.tth = manual_control_new_B.y_g[1];
  manual_control_new_B.wq1 = manual_control_new_B.y_g[2];

  // Gain: '<S5>/Gain'
  manual_control_new_B.a22 = manual_control_new_B.y_p[0];
  manual_control_new_B.wr1 = manual_control_new_B.y_p[1];
  manual_control_new_B.cph = manual_control_new_B.y_p[2];
  for (manual_control_new_B.r2 = 0; manual_control_new_B.r2 < 3;
       manual_control_new_B.r2++) {
    // Gain: '<Root>/Gain1'
    manual_control_new_B.Gain1_d[manual_control_new_B.r2] =
      manual_control_new_P.Gain1_Gain_b *
      manual_control_new_B.y_k[manual_control_new_B.r2];

    // Gain: '<S5>/Gain1'
    manual_control_new_B.cth = manual_control_new_P.Rz[manual_control_new_B.r2];

    // Gain: '<S5>/Gain1'
    manual_control_new_B.ph_meas = manual_control_new_B.cth *
      manual_control_new_B.Sum23_m;

    // Gain: '<S5>/Gain'
    manual_control_new_B.sph = manual_control_new_B.cth *
      manual_control_new_B.a22;

    // Gain: '<S5>/Gain1'
    manual_control_new_B.cth = manual_control_new_P.Rz[manual_control_new_B.r2 +
      3];

    // Gain: '<S5>/Gain1'
    manual_control_new_B.ph_meas += manual_control_new_B.cth *
      manual_control_new_B.tth;

    // Gain: '<S5>/Gain'
    manual_control_new_B.sph += manual_control_new_B.cth *
      manual_control_new_B.wr1;

    // Gain: '<S5>/Gain1'
    manual_control_new_B.cth = manual_control_new_P.Rz[manual_control_new_B.r2 +
      6];

    // Gain: '<S5>/Gain'
    manual_control_new_B.TmpSignalConversionAtSFunct[manual_control_new_B.r2] =
      manual_control_new_B.cth * manual_control_new_B.cph +
      manual_control_new_B.sph;

    // Gain: '<S5>/Gain1'
    manual_control_new_B.u_vect[manual_control_new_B.r2] =
      manual_control_new_B.cth * manual_control_new_B.wq1 +
      manual_control_new_B.ph_meas;
  }

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  manual_control_new_B.y1_ej = manual_control_new_B.Gain1_d[0];
  manual_control_new_B.y2_i = manual_control_new_B.Gain1_d[1];
  manual_control_new_B.y3_c = manual_control_new_B.Gain1_d[2];

  // MATLAB Function: '<S2>/MATLAB Function1'
  manual_control__MATLABFunction1(manual_control_new_B.Gain_k,
    &manual_control_new_B.y1_b, &manual_control_new_B.y2_m,
    &manual_control_new_B.y3_h, &manual_control_new_DW.sf_MATLABFunction1_p);

  // MATLAB Function: '<S8>/MATLAB Function7'
  manual_control__MATLABFunction1(manual_control_new_B.Gain2,
    &manual_control_new_B.y1_e, &manual_control_new_B.y2_k,
    &manual_control_new_B.y3_o, &manual_control_new_DW.sf_MATLABFunction7);

  // MATLABSystem: '<S3>/PX4 PWM Output'
  for (i = 0; i < 8; i++) {
    manual_control_new_B.pwmValue[i] = 0U;
  }

  manual_control_new_B.pwmValue[0] = rtb_DataTypeConversion1_c;
  manual_control_new_B.pwmValue[1] = rtb_DataTypeConversion1_h;
  manual_control_new_B.pwmValue[2] = rtb_DataTypeConversion1_p;
  manual_control_new_B.pwmValue[3] = rtb_DataTypeConversion1_o;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (manual_control_new_P.startingswitch_CurrentSetting == 1) {
    b_varargout_1 = manual_control_new_P.Constant2_Value;
  } else {
    b_varargout_1 = manual_control_new_P.ARMPWM1_Value;
  }

  // MATLABSystem: '<S3>/PX4 PWM Output' incorporates:
  //   Constant: '<S3>/failsafe'
  //   ManualSwitch: '<Root>/starting switch'

  if (b_varargout_1) {
    if (!manual_control_new_DW.obj.isArmed) {
      manual_control_new_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_c = pwm_arm
        (&manual_control_new_DW.obj.pwmDevHandler,
         &manual_control_new_DW.obj.armAdvertiseObj);
      manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
        (manual_control_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
    }

    rtb_DataTypeConversion1_c = pwm_setServo
      (&manual_control_new_DW.obj.pwmDevHandler,
       manual_control_new_DW.obj.servoCount,
       manual_control_new_DW.obj.channelMask, &manual_control_new_B.pwmValue[0],
       manual_control_new_DW.obj.isMain,
       &manual_control_new_DW.obj.actuatorAdvertiseObj);
    manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
      (manual_control_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  } else {
    rtb_DataTypeConversion1_c = pwm_disarm
      (&manual_control_new_DW.obj.pwmDevHandler,
       &manual_control_new_DW.obj.armAdvertiseObj);
    manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
      (manual_control_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
    manual_control_new_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_c = pwm_resetServo
      (&manual_control_new_DW.obj.pwmDevHandler,
       manual_control_new_DW.obj.servoCount,
       manual_control_new_DW.obj.channelMask, manual_control_new_DW.obj.isMain,
       &manual_control_new_DW.obj.actuatorAdvertiseObj);
    manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
      (manual_control_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  if (manual_control_new_DW.obj.isMain) {
    rtb_DataTypeConversion1_c = pwm_forceFailsafe
      (&manual_control_new_DW.obj.pwmDevHandler, static_cast<int32_T>
       (manual_control_new_P.failsafe_Value));
    manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
      (manual_control_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  // Update for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn'

  manual_control_new_DW.DiscreteTransferFcn_states =
    (manual_control_new_P.DiscreteTransferFcn_NumCoef_l *
     manual_control_new_DW.DiscreteTransferFcn_states_d -
     manual_control_new_P.DiscreteTransferFcn_DenCoef[1] *
     manual_control_new_DW.DiscreteTransferFcn_states) /
    manual_control_new_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn1'

  manual_control_new_DW.DiscreteTransferFcn1_states =
    (manual_control_new_P.DiscreteTransferFcn1_NumCoef_l *
     manual_control_new_DW.DiscreteTransferFcn1_states_l -
     manual_control_new_P.DiscreteTransferFcn1_DenCoef[1] *
     manual_control_new_DW.DiscreteTransferFcn1_states) /
    manual_control_new_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn2'

  manual_control_new_DW.DiscreteTransferFcn2_states =
    (manual_control_new_P.DiscreteTransferFcn2_NumCoef_c *
     manual_control_new_DW.DiscreteTransferFcn2_states_b -
     manual_control_new_P.DiscreteTransferFcn2_DenCoef[1] *
     manual_control_new_DW.DiscreteTransferFcn2_states) /
    manual_control_new_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S14>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn2'

  manual_control_new_DW.Delay_DSTATE_k[0] = manual_control_new_B.numAccum;
  manual_control_new_DW.Delay_DSTATE_k[1] = manual_control_new_B.numAccum_c;
  manual_control_new_DW.Delay_DSTATE_k[2] = manual_control_new_B.numAccum_f;

  // Update for Memory: '<S19>/Memory4'
  manual_control_new_DW.Memory4_PreviousInput_l = manual_control_new_B.xk;

  // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn'
  manual_control_new_DW.DiscreteTransferFcn_states_a =
    (manual_control_new_B.u_vect[0] -
     manual_control_new_P.DiscreteTransferFcn_DenCoef_n[1] *
     manual_control_new_DW.DiscreteTransferFcn_states_a) /
    manual_control_new_P.DiscreteTransferFcn_DenCoef_n[0];

  // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn1'
  manual_control_new_DW.DiscreteTransferFcn1_states_o =
    (manual_control_new_B.u_vect[1] -
     manual_control_new_P.DiscreteTransferFcn1_DenCoef_e[1] *
     manual_control_new_DW.DiscreteTransferFcn1_states_o) /
    manual_control_new_P.DiscreteTransferFcn1_DenCoef_e[0];

  // Update for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn2'
  manual_control_new_DW.DiscreteTransferFcn2_states_i =
    (manual_control_new_B.u_vect[2] -
     manual_control_new_P.DiscreteTransferFcn2_DenCoef_a[1] *
     manual_control_new_DW.DiscreteTransferFcn2_states_i) /
    manual_control_new_P.DiscreteTransferFcn2_DenCoef_a[0];

  // Update for Delay: '<S18>/Delay23' incorporates:
  //   Delay: '<S18>/Delay22'
  //
  manual_control_new_DW.Delay23_DSTATE[0] =
    manual_control_new_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S18>/Delay22' incorporates:
  //   Delay: '<S18>/Delay21'
  //
  manual_control_new_DW.Delay22_DSTATE[0] =
    manual_control_new_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S18>/Delay21' incorporates:
  //   Delay: '<S18>/Delay20'
  //
  manual_control_new_DW.Delay21_DSTATE[0] =
    manual_control_new_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S18>/Delay20' incorporates:
  //   Delay: '<S18>/Delay14'
  //
  manual_control_new_DW.Delay20_DSTATE[0] =
    manual_control_new_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S18>/Delay14' incorporates:
  //   Delay: '<S18>/Delay13'
  //
  manual_control_new_DW.Delay14_DSTATE[0] =
    manual_control_new_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S18>/Delay13' incorporates:
  //   Delay: '<S18>/Delay12'
  //
  manual_control_new_DW.Delay13_DSTATE[0] =
    manual_control_new_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S18>/Delay12' incorporates:
  //   Delay: '<S18>/Delay11'
  //
  manual_control_new_DW.Delay12_DSTATE[0] =
    manual_control_new_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S18>/Delay11' incorporates:
  //   Delay: '<S18>/Delay10'
  //
  manual_control_new_DW.Delay11_DSTATE[0] =
    manual_control_new_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S18>/Delay10' incorporates:
  //   Delay: '<S18>/Delay9'
  //
  manual_control_new_DW.Delay10_DSTATE[0] = manual_control_new_DW.Delay9_DSTATE
    [0];

  // Update for Delay: '<S18>/Delay9' incorporates:
  //   Delay: '<S18>/Delay8'
  //
  manual_control_new_DW.Delay9_DSTATE[0] = manual_control_new_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S18>/Delay8' incorporates:
  //   Delay: '<S18>/Delay7'
  //
  manual_control_new_DW.Delay8_DSTATE[0] = manual_control_new_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S18>/Delay7' incorporates:
  //   Delay: '<S18>/Delay6'
  //
  manual_control_new_DW.Delay7_DSTATE[0] = manual_control_new_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S18>/Delay6' incorporates:
  //   Delay: '<S18>/Delay5'
  //
  manual_control_new_DW.Delay6_DSTATE[0] = manual_control_new_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S18>/Delay5' incorporates:
  //   Delay: '<S18>/Delay4'
  //
  manual_control_new_DW.Delay5_DSTATE[0] = manual_control_new_DW.Delay4_DSTATE[0];

  // Update for Delay: '<S18>/Delay4' incorporates:
  //   Delay: '<S18>/Delay3'
  //
  manual_control_new_DW.Delay4_DSTATE[0] = manual_control_new_DW.Delay3_DSTATE[0];

  // Update for Delay: '<S18>/Delay3' incorporates:
  //   Delay: '<S18>/Delay2'
  //
  manual_control_new_DW.Delay3_DSTATE[0] =
    manual_control_new_DW.Delay2_DSTATE_j[0];

  // Update for Delay: '<S18>/Delay2' incorporates:
  //   Delay: '<S18>/Delay1'
  //
  manual_control_new_DW.Delay2_DSTATE_j[0] =
    manual_control_new_DW.Delay1_DSTATE[0];

  // Update for Delay: '<S18>/Delay1' incorporates:
  //   Delay: '<S18>/Delay'
  //
  manual_control_new_DW.Delay1_DSTATE[0] = manual_control_new_DW.Delay_DSTATE[0];

  // Update for Delay: '<S18>/Delay'
  manual_control_new_DW.Delay_DSTATE[0] = manual_control_new_B.y_idx_0;

  // Update for Delay: '<S14>/Delay1'
  manual_control_new_DW.Delay1_DSTATE_f[0] =
    manual_control_new_B.rtb_Delay_f_idx_0;

  // Update for Delay: '<S14>/Delay2'
  manual_control_new_DW.Delay2_DSTATE_b[0] =
    manual_control_new_B.rtb_Delay1_a_idx_0;

  // Update for Delay: '<S14>/Delay3'
  manual_control_new_DW.Delay3_DSTATE_f[0] =
    manual_control_new_B.rtb_Delay2_o_idx_0;

  // Update for Delay: '<S14>/Delay4'
  manual_control_new_DW.Delay4_DSTATE_l[0] =
    manual_control_new_B.rtb_Delay3_a_idx_0;

  // Update for Delay: '<S14>/Delay5'
  manual_control_new_DW.Delay5_DSTATE_d[0] =
    manual_control_new_B.rtb_Delay4_i_idx_0;

  // Update for Delay: '<S14>/Delay6'
  manual_control_new_DW.Delay6_DSTATE_c[0] =
    manual_control_new_B.rtb_Delay5_n_idx_0;

  // Update for Delay: '<S14>/Delay7'
  manual_control_new_DW.Delay7_DSTATE_p[0] =
    manual_control_new_B.rtb_Delay6_p_idx_0;

  // Update for Delay: '<S14>/Delay8'
  manual_control_new_DW.Delay8_DSTATE_g[0] =
    manual_control_new_B.rtb_Delay7_n_idx_0;

  // Update for Delay: '<S14>/Delay9'
  manual_control_new_DW.Delay9_DSTATE_a[0] =
    manual_control_new_B.rtb_Delay8_c_idx_0;

  // Update for Delay: '<S14>/Delay10'
  manual_control_new_DW.Delay10_DSTATE_e[0] =
    manual_control_new_B.rtb_Delay9_e_idx_0;

  // Update for Delay: '<S14>/Delay11'
  manual_control_new_DW.Delay11_DSTATE_b[0] =
    manual_control_new_B.rtb_Delay10_n_idx_0;

  // Update for Delay: '<S14>/Delay12'
  manual_control_new_DW.Delay12_DSTATE_i[0] =
    manual_control_new_B.rtb_Delay11_g_idx_0;

  // Update for Delay: '<S14>/Delay13'
  manual_control_new_DW.Delay13_DSTATE_d[0] =
    manual_control_new_B.rtb_Delay12_e_idx_0;

  // Update for Delay: '<S14>/Delay14'
  manual_control_new_DW.Delay14_DSTATE_d[0] =
    manual_control_new_B.rtb_Delay13_e_idx_0;

  // Update for Delay: '<S14>/Delay15'
  manual_control_new_DW.Delay15_DSTATE[0] =
    manual_control_new_B.rtb_Delay14_p_idx_0;

  // Update for Delay: '<S14>/Delay20'
  manual_control_new_DW.Delay20_DSTATE_k[0] =
    manual_control_new_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S14>/Delay21'
  manual_control_new_DW.Delay21_DSTATE_l[0] =
    manual_control_new_B.rtb_Delay20_h_idx_0;

  // Update for Delay: '<S14>/Delay22'
  manual_control_new_DW.Delay22_DSTATE_m[0] =
    manual_control_new_B.rtb_Delay21_b_idx_0;

  // Update for Delay: '<S14>/Delay23'
  manual_control_new_DW.Delay23_DSTATE_f[0] =
    manual_control_new_B.rtb_Delay22_k_idx_0;

  // Update for Delay: '<S14>/Delay24'
  manual_control_new_DW.Delay24_DSTATE[0] =
    manual_control_new_B.rtb_Delay23_g_idx_0;

  // Update for Delay: '<S14>/Delay25'
  manual_control_new_DW.Delay25_DSTATE[0] =
    manual_control_new_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S14>/Delay26'
  manual_control_new_DW.Delay26_DSTATE[0] =
    manual_control_new_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S14>/Delay27'
  manual_control_new_DW.Delay27_DSTATE[0] =
    manual_control_new_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S14>/Delay16'
  manual_control_new_DW.Delay16_DSTATE[0] =
    manual_control_new_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S14>/Delay17'
  manual_control_new_DW.Delay17_DSTATE[0] =
    manual_control_new_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S14>/Delay18'
  manual_control_new_DW.Delay18_DSTATE[0] =
    manual_control_new_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S14>/Delay19'
  manual_control_new_DW.Delay19_DSTATE[0] =
    manual_control_new_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S19>/Delay2' incorporates:
  //   Delay: '<S16>/Delay2'

  manual_control_new_DW.Delay2_DSTATE_f[0] =
    manual_control_new_DW.Delay2_DSTATE[0];

  // Update for Memory: '<S7>/Memory6'
  manual_control_new_DW.Memory6_PreviousInput[0] =
    manual_control_new_B.RPY_rate[0];

  // Update for Delay: '<S18>/Delay23' incorporates:
  //   Delay: '<S18>/Delay22'
  //
  manual_control_new_DW.Delay23_DSTATE[1] =
    manual_control_new_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S18>/Delay22' incorporates:
  //   Delay: '<S18>/Delay21'
  //
  manual_control_new_DW.Delay22_DSTATE[1] =
    manual_control_new_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S18>/Delay21' incorporates:
  //   Delay: '<S18>/Delay20'
  //
  manual_control_new_DW.Delay21_DSTATE[1] =
    manual_control_new_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S18>/Delay20' incorporates:
  //   Delay: '<S18>/Delay14'
  //
  manual_control_new_DW.Delay20_DSTATE[1] =
    manual_control_new_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S18>/Delay14' incorporates:
  //   Delay: '<S18>/Delay13'
  //
  manual_control_new_DW.Delay14_DSTATE[1] =
    manual_control_new_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S18>/Delay13' incorporates:
  //   Delay: '<S18>/Delay12'
  //
  manual_control_new_DW.Delay13_DSTATE[1] =
    manual_control_new_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S18>/Delay12' incorporates:
  //   Delay: '<S18>/Delay11'
  //
  manual_control_new_DW.Delay12_DSTATE[1] =
    manual_control_new_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S18>/Delay11' incorporates:
  //   Delay: '<S18>/Delay10'
  //
  manual_control_new_DW.Delay11_DSTATE[1] =
    manual_control_new_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S18>/Delay10' incorporates:
  //   Delay: '<S18>/Delay9'
  //
  manual_control_new_DW.Delay10_DSTATE[1] = manual_control_new_DW.Delay9_DSTATE
    [1];

  // Update for Delay: '<S18>/Delay9' incorporates:
  //   Delay: '<S18>/Delay8'
  //
  manual_control_new_DW.Delay9_DSTATE[1] = manual_control_new_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S18>/Delay8' incorporates:
  //   Delay: '<S18>/Delay7'
  //
  manual_control_new_DW.Delay8_DSTATE[1] = manual_control_new_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S18>/Delay7' incorporates:
  //   Delay: '<S18>/Delay6'
  //
  manual_control_new_DW.Delay7_DSTATE[1] = manual_control_new_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S18>/Delay6' incorporates:
  //   Delay: '<S18>/Delay5'
  //
  manual_control_new_DW.Delay6_DSTATE[1] = manual_control_new_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S18>/Delay5' incorporates:
  //   Delay: '<S18>/Delay4'
  //
  manual_control_new_DW.Delay5_DSTATE[1] = manual_control_new_DW.Delay4_DSTATE[1];

  // Update for Delay: '<S18>/Delay4' incorporates:
  //   Delay: '<S18>/Delay3'
  //
  manual_control_new_DW.Delay4_DSTATE[1] = manual_control_new_DW.Delay3_DSTATE[1];

  // Update for Delay: '<S18>/Delay3' incorporates:
  //   Delay: '<S18>/Delay2'
  //
  manual_control_new_DW.Delay3_DSTATE[1] =
    manual_control_new_DW.Delay2_DSTATE_j[1];

  // Update for Delay: '<S18>/Delay2' incorporates:
  //   Delay: '<S18>/Delay1'
  //
  manual_control_new_DW.Delay2_DSTATE_j[1] =
    manual_control_new_DW.Delay1_DSTATE[1];

  // Update for Delay: '<S18>/Delay1' incorporates:
  //   Delay: '<S18>/Delay'
  //
  manual_control_new_DW.Delay1_DSTATE[1] = manual_control_new_DW.Delay_DSTATE[1];

  // Update for Delay: '<S18>/Delay'
  manual_control_new_DW.Delay_DSTATE[1] = manual_control_new_B.y_idx_1;

  // Update for Delay: '<S14>/Delay1'
  manual_control_new_DW.Delay1_DSTATE_f[1] =
    manual_control_new_B.rtb_Delay_f_idx_1;

  // Update for Delay: '<S14>/Delay2'
  manual_control_new_DW.Delay2_DSTATE_b[1] =
    manual_control_new_B.rtb_Delay1_a_idx_1;

  // Update for Delay: '<S14>/Delay3'
  manual_control_new_DW.Delay3_DSTATE_f[1] =
    manual_control_new_B.rtb_Delay2_o_idx_1;

  // Update for Delay: '<S14>/Delay4'
  manual_control_new_DW.Delay4_DSTATE_l[1] =
    manual_control_new_B.rtb_Delay3_a_idx_1;

  // Update for Delay: '<S14>/Delay5'
  manual_control_new_DW.Delay5_DSTATE_d[1] =
    manual_control_new_B.rtb_Delay4_i_idx_1;

  // Update for Delay: '<S14>/Delay6'
  manual_control_new_DW.Delay6_DSTATE_c[1] =
    manual_control_new_B.rtb_Delay5_n_idx_1;

  // Update for Delay: '<S14>/Delay7'
  manual_control_new_DW.Delay7_DSTATE_p[1] =
    manual_control_new_B.rtb_Delay6_p_idx_1;

  // Update for Delay: '<S14>/Delay8'
  manual_control_new_DW.Delay8_DSTATE_g[1] =
    manual_control_new_B.rtb_Delay7_n_idx_1;

  // Update for Delay: '<S14>/Delay9'
  manual_control_new_DW.Delay9_DSTATE_a[1] =
    manual_control_new_B.rtb_Delay8_c_idx_1;

  // Update for Delay: '<S14>/Delay10'
  manual_control_new_DW.Delay10_DSTATE_e[1] =
    manual_control_new_B.rtb_Delay9_e_idx_1;

  // Update for Delay: '<S14>/Delay11'
  manual_control_new_DW.Delay11_DSTATE_b[1] =
    manual_control_new_B.rtb_Delay10_n_idx_1;

  // Update for Delay: '<S14>/Delay12'
  manual_control_new_DW.Delay12_DSTATE_i[1] =
    manual_control_new_B.rtb_Delay11_g_idx_1;

  // Update for Delay: '<S14>/Delay13'
  manual_control_new_DW.Delay13_DSTATE_d[1] =
    manual_control_new_B.rtb_Delay12_e_idx_1;

  // Update for Delay: '<S14>/Delay14'
  manual_control_new_DW.Delay14_DSTATE_d[1] =
    manual_control_new_B.rtb_Delay13_e_idx_1;

  // Update for Delay: '<S14>/Delay15'
  manual_control_new_DW.Delay15_DSTATE[1] =
    manual_control_new_B.rtb_Delay14_p_idx_1;

  // Update for Delay: '<S14>/Delay20'
  manual_control_new_DW.Delay20_DSTATE_k[1] =
    manual_control_new_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S14>/Delay21'
  manual_control_new_DW.Delay21_DSTATE_l[1] =
    manual_control_new_B.rtb_Delay20_h_idx_1;

  // Update for Delay: '<S14>/Delay22'
  manual_control_new_DW.Delay22_DSTATE_m[1] =
    manual_control_new_B.rtb_Delay21_b_idx_1;

  // Update for Delay: '<S14>/Delay23'
  manual_control_new_DW.Delay23_DSTATE_f[1] =
    manual_control_new_B.rtb_Delay22_k_idx_1;

  // Update for Delay: '<S14>/Delay24'
  manual_control_new_DW.Delay24_DSTATE[1] =
    manual_control_new_B.rtb_Delay23_g_idx_1;

  // Update for Delay: '<S14>/Delay25'
  manual_control_new_DW.Delay25_DSTATE[1] =
    manual_control_new_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S14>/Delay26'
  manual_control_new_DW.Delay26_DSTATE[1] =
    manual_control_new_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S14>/Delay27'
  manual_control_new_DW.Delay27_DSTATE[1] =
    manual_control_new_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S14>/Delay16'
  manual_control_new_DW.Delay16_DSTATE[1] =
    manual_control_new_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S14>/Delay17'
  manual_control_new_DW.Delay17_DSTATE[1] =
    manual_control_new_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S14>/Delay18'
  manual_control_new_DW.Delay18_DSTATE[1] =
    manual_control_new_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S14>/Delay19'
  manual_control_new_DW.Delay19_DSTATE[1] =
    manual_control_new_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S19>/Delay2' incorporates:
  //   Delay: '<S16>/Delay2'

  manual_control_new_DW.Delay2_DSTATE_f[1] =
    manual_control_new_DW.Delay2_DSTATE[1];

  // Update for Memory: '<S7>/Memory6'
  manual_control_new_DW.Memory6_PreviousInput[1] =
    manual_control_new_B.RPY_rate[1];

  // Update for Delay: '<S18>/Delay23' incorporates:
  //   Delay: '<S18>/Delay22'
  //
  manual_control_new_DW.Delay23_DSTATE[2] =
    manual_control_new_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S18>/Delay22' incorporates:
  //   Delay: '<S18>/Delay21'
  //
  manual_control_new_DW.Delay22_DSTATE[2] =
    manual_control_new_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S18>/Delay21' incorporates:
  //   Delay: '<S18>/Delay20'
  //
  manual_control_new_DW.Delay21_DSTATE[2] =
    manual_control_new_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S18>/Delay20' incorporates:
  //   Delay: '<S18>/Delay14'
  //
  manual_control_new_DW.Delay20_DSTATE[2] =
    manual_control_new_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S18>/Delay14' incorporates:
  //   Delay: '<S18>/Delay13'
  //
  manual_control_new_DW.Delay14_DSTATE[2] =
    manual_control_new_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S18>/Delay13' incorporates:
  //   Delay: '<S18>/Delay12'
  //
  manual_control_new_DW.Delay13_DSTATE[2] =
    manual_control_new_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S18>/Delay12' incorporates:
  //   Delay: '<S18>/Delay11'
  //
  manual_control_new_DW.Delay12_DSTATE[2] =
    manual_control_new_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S18>/Delay11' incorporates:
  //   Delay: '<S18>/Delay10'
  //
  manual_control_new_DW.Delay11_DSTATE[2] =
    manual_control_new_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S18>/Delay10' incorporates:
  //   Delay: '<S18>/Delay9'
  //
  manual_control_new_DW.Delay10_DSTATE[2] = manual_control_new_DW.Delay9_DSTATE
    [2];

  // Update for Delay: '<S18>/Delay9' incorporates:
  //   Delay: '<S18>/Delay8'
  //
  manual_control_new_DW.Delay9_DSTATE[2] = manual_control_new_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S18>/Delay8' incorporates:
  //   Delay: '<S18>/Delay7'
  //
  manual_control_new_DW.Delay8_DSTATE[2] = manual_control_new_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S18>/Delay7' incorporates:
  //   Delay: '<S18>/Delay6'
  //
  manual_control_new_DW.Delay7_DSTATE[2] = manual_control_new_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S18>/Delay6' incorporates:
  //   Delay: '<S18>/Delay5'
  //
  manual_control_new_DW.Delay6_DSTATE[2] = manual_control_new_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S18>/Delay5' incorporates:
  //   Delay: '<S18>/Delay4'
  //
  manual_control_new_DW.Delay5_DSTATE[2] = manual_control_new_DW.Delay4_DSTATE[2];

  // Update for Delay: '<S18>/Delay4' incorporates:
  //   Delay: '<S18>/Delay3'
  //
  manual_control_new_DW.Delay4_DSTATE[2] = manual_control_new_DW.Delay3_DSTATE[2];

  // Update for Delay: '<S18>/Delay3' incorporates:
  //   Delay: '<S18>/Delay2'
  //
  manual_control_new_DW.Delay3_DSTATE[2] =
    manual_control_new_DW.Delay2_DSTATE_j[2];

  // Update for Delay: '<S18>/Delay2' incorporates:
  //   Delay: '<S18>/Delay1'
  //
  manual_control_new_DW.Delay2_DSTATE_j[2] =
    manual_control_new_DW.Delay1_DSTATE[2];

  // Update for Delay: '<S18>/Delay1' incorporates:
  //   Delay: '<S18>/Delay'
  //
  manual_control_new_DW.Delay1_DSTATE[2] = manual_control_new_DW.Delay_DSTATE[2];

  // Update for Delay: '<S18>/Delay'
  manual_control_new_DW.Delay_DSTATE[2] = manual_control_new_B.u_vect_g;

  // Update for Delay: '<S14>/Delay1' incorporates:
  //   Delay: '<S14>/Delay'

  manual_control_new_DW.Delay1_DSTATE_f[2] = manual_control_new_B.Delay_DSTATE_k;

  // Update for Delay: '<S14>/Delay2' incorporates:
  //   Delay: '<S14>/Delay1'

  manual_control_new_DW.Delay2_DSTATE_b[2] =
    manual_control_new_B.Delay1_DSTATE_f;

  // Update for Delay: '<S14>/Delay3' incorporates:
  //   Delay: '<S14>/Delay2'

  manual_control_new_DW.Delay3_DSTATE_f[2] =
    manual_control_new_B.Delay2_DSTATE_b;

  // Update for Delay: '<S14>/Delay4' incorporates:
  //   Delay: '<S14>/Delay3'

  manual_control_new_DW.Delay4_DSTATE_l[2] =
    manual_control_new_B.Delay3_DSTATE_f;

  // Update for Delay: '<S14>/Delay5' incorporates:
  //   Delay: '<S14>/Delay4'

  manual_control_new_DW.Delay5_DSTATE_d[2] =
    manual_control_new_B.Delay4_DSTATE_l;

  // Update for Delay: '<S14>/Delay6' incorporates:
  //   Delay: '<S14>/Delay5'

  manual_control_new_DW.Delay6_DSTATE_c[2] =
    manual_control_new_B.Delay5_DSTATE_d;

  // Update for Delay: '<S14>/Delay7' incorporates:
  //   Delay: '<S14>/Delay6'

  manual_control_new_DW.Delay7_DSTATE_p[2] =
    manual_control_new_B.Delay6_DSTATE_c;

  // Update for Delay: '<S14>/Delay8' incorporates:
  //   Delay: '<S14>/Delay7'

  manual_control_new_DW.Delay8_DSTATE_g[2] =
    manual_control_new_B.Delay7_DSTATE_p;

  // Update for Delay: '<S14>/Delay9' incorporates:
  //   Delay: '<S14>/Delay8'

  manual_control_new_DW.Delay9_DSTATE_a[2] =
    manual_control_new_B.Delay8_DSTATE_g;

  // Update for Delay: '<S14>/Delay10' incorporates:
  //   Delay: '<S14>/Delay9'

  manual_control_new_DW.Delay10_DSTATE_e[2] =
    manual_control_new_B.Delay9_DSTATE_a;

  // Update for Delay: '<S14>/Delay11' incorporates:
  //   Delay: '<S14>/Delay10'

  manual_control_new_DW.Delay11_DSTATE_b[2] =
    manual_control_new_B.Delay10_DSTATE_e;

  // Update for Delay: '<S14>/Delay12' incorporates:
  //   Delay: '<S14>/Delay11'

  manual_control_new_DW.Delay12_DSTATE_i[2] =
    manual_control_new_B.Delay11_DSTATE_b;

  // Update for Delay: '<S14>/Delay13' incorporates:
  //   Delay: '<S14>/Delay12'

  manual_control_new_DW.Delay13_DSTATE_d[2] =
    manual_control_new_B.Delay12_DSTATE_i;

  // Update for Delay: '<S14>/Delay14' incorporates:
  //   Delay: '<S14>/Delay13'

  manual_control_new_DW.Delay14_DSTATE_d[2] =
    manual_control_new_B.Delay13_DSTATE_d;

  // Update for Delay: '<S14>/Delay15' incorporates:
  //   Delay: '<S14>/Delay14'

  manual_control_new_DW.Delay15_DSTATE[2] =
    manual_control_new_B.Delay14_DSTATE_d;

  // Update for Delay: '<S14>/Delay20' incorporates:
  //   Delay: '<S14>/Delay15'

  manual_control_new_DW.Delay20_DSTATE_k[2] =
    manual_control_new_B.Delay15_DSTATE;

  // Update for Delay: '<S14>/Delay21' incorporates:
  //   Delay: '<S14>/Delay20'

  manual_control_new_DW.Delay21_DSTATE_l[2] =
    manual_control_new_B.Delay20_DSTATE_k;

  // Update for Delay: '<S14>/Delay22' incorporates:
  //   Delay: '<S14>/Delay21'

  manual_control_new_DW.Delay22_DSTATE_m[2] =
    manual_control_new_B.Delay21_DSTATE_l;

  // Update for Delay: '<S14>/Delay23' incorporates:
  //   Delay: '<S14>/Delay22'

  manual_control_new_DW.Delay23_DSTATE_f[2] =
    manual_control_new_B.Delay22_DSTATE_m;

  // Update for Delay: '<S14>/Delay24' incorporates:
  //   Delay: '<S14>/Delay23'

  manual_control_new_DW.Delay24_DSTATE[2] =
    manual_control_new_B.Delay23_DSTATE_f;

  // Update for Delay: '<S14>/Delay25' incorporates:
  //   Delay: '<S14>/Delay24'

  manual_control_new_DW.Delay25_DSTATE[2] = manual_control_new_B.Delay24_DSTATE;

  // Update for Delay: '<S14>/Delay26' incorporates:
  //   Delay: '<S14>/Delay25'

  manual_control_new_DW.Delay26_DSTATE[2] = manual_control_new_B.Delay25_DSTATE;

  // Update for Delay: '<S14>/Delay27' incorporates:
  //   Delay: '<S14>/Delay26'

  manual_control_new_DW.Delay27_DSTATE[2] = manual_control_new_B.Delay26_DSTATE;

  // Update for Delay: '<S14>/Delay16' incorporates:
  //   Delay: '<S14>/Delay27'

  manual_control_new_DW.Delay16_DSTATE[2] = manual_control_new_B.Delay27_DSTATE;

  // Update for Delay: '<S14>/Delay17' incorporates:
  //   Delay: '<S14>/Delay16'

  manual_control_new_DW.Delay17_DSTATE[2] = manual_control_new_B.Delay16_DSTATE;

  // Update for Delay: '<S14>/Delay18' incorporates:
  //   Delay: '<S14>/Delay17'

  manual_control_new_DW.Delay18_DSTATE[2] = manual_control_new_B.Delay17_DSTATE;

  // Update for Delay: '<S14>/Delay19' incorporates:
  //   Delay: '<S14>/Delay18'

  manual_control_new_DW.Delay19_DSTATE[2] = manual_control_new_B.Delay18_DSTATE;

  // Update for Delay: '<S19>/Delay2' incorporates:
  //   Delay: '<S16>/Delay2'

  manual_control_new_DW.Delay2_DSTATE_f[2] =
    manual_control_new_DW.Delay2_DSTATE[2];

  // Update for Memory: '<S7>/Memory6'
  manual_control_new_DW.Memory6_PreviousInput[2] =
    manual_control_new_B.RPY_rate[2];

  // Update for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn'
  manual_control_new_DW.DiscreteTransferFcn_states_d =
    (manual_control_new_B.TmpSignalConversionAtSFunct[0] -
     manual_control_new_P.DiscreteTransferFcn_DenCoef_g[1] *
     manual_control_new_DW.DiscreteTransferFcn_states_d) /
    manual_control_new_P.DiscreteTransferFcn_DenCoef_g[0];

  // Update for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn1'
  manual_control_new_DW.DiscreteTransferFcn1_states_l =
    (manual_control_new_B.TmpSignalConversionAtSFunct[1] -
     manual_control_new_P.DiscreteTransferFcn1_DenCoef_k[1] *
     manual_control_new_DW.DiscreteTransferFcn1_states_l) /
    manual_control_new_P.DiscreteTransferFcn1_DenCoef_k[0];

  // Update for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn2'
  manual_control_new_DW.DiscreteTransferFcn2_states_b =
    (manual_control_new_B.TmpSignalConversionAtSFunct[2] -
     manual_control_new_P.DiscreteTransferFcn2_DenCoef_b[1] *
     manual_control_new_DW.DiscreteTransferFcn2_states_b) /
    manual_control_new_P.DiscreteTransferFcn2_DenCoef_b[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  manual_control_new_M->Timing.taskTime0 =
    ((time_T)(++manual_control_new_M->Timing.clockTick0)) *
    manual_control_new_M->Timing.stepSize0;
}

// Model initialize function
void manual_control_new_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(manual_control_new_M, -1);
  manual_control_new_M->Timing.stepSize0 = 0.01;

  // External mode info
  manual_control_new_M->Sizes.checksums[0] = (3124607050U);
  manual_control_new_M->Sizes.checksums[1] = (2570955651U);
  manual_control_new_M->Sizes.checksums[2] = (1292153217U);
  manual_control_new_M->Sizes.checksums[3] = (1749228868U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[30];
    manual_control_new_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)
      &manual_control_new_DW.EnabledSubsystem_SubsysRanBC_js;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = (sysRanDType *)
      &manual_control_new_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &manual_control_new_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &manual_control_new_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &manual_control_new_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &manual_control_new_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &manual_control_new_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(manual_control_new_M->extModeInfo,
      &manual_control_new_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(manual_control_new_M->extModeInfo,
                        manual_control_new_M->Sizes.checksums);
    rteiSetTPtr(manual_control_new_M->extModeInfo, rtmGetTPtr
                (manual_control_new_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Memory: '<S16>/Memory4'
    for (i = 0; i < 5; i++) {
      manual_control_new_DW.Memory4_PreviousInput[i] =
        manual_control_new_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S16>/Memory4'

    // InitializeConditions for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn' 
    manual_control_new_DW.DiscreteTransferFcn_states =
      manual_control_new_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn1' 
    manual_control_new_DW.DiscreteTransferFcn1_states =
      manual_control_new_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S12>/Discrete Transfer Fcn2' 
    manual_control_new_DW.DiscreteTransferFcn2_states =
      manual_control_new_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S16>/Delay2'
    manual_control_new_DW.Delay2_DSTATE[0] =
      manual_control_new_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay23'
    manual_control_new_DW.Delay23_DSTATE[0] =
      manual_control_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay22'
    manual_control_new_DW.Delay22_DSTATE[0] =
      manual_control_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay21'
    manual_control_new_DW.Delay21_DSTATE[0] =
      manual_control_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay20'
    manual_control_new_DW.Delay20_DSTATE[0] =
      manual_control_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay14'
    manual_control_new_DW.Delay14_DSTATE[0] =
      manual_control_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay13'
    manual_control_new_DW.Delay13_DSTATE[0] =
      manual_control_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay12'
    manual_control_new_DW.Delay12_DSTATE[0] =
      manual_control_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay11'
    manual_control_new_DW.Delay11_DSTATE[0] =
      manual_control_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay10'
    manual_control_new_DW.Delay10_DSTATE[0] =
      manual_control_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay9'
    manual_control_new_DW.Delay9_DSTATE[0] =
      manual_control_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay8'
    manual_control_new_DW.Delay8_DSTATE[0] =
      manual_control_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay7'
    manual_control_new_DW.Delay7_DSTATE[0] =
      manual_control_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay6'
    manual_control_new_DW.Delay6_DSTATE[0] =
      manual_control_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay5'
    manual_control_new_DW.Delay5_DSTATE[0] =
      manual_control_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay4'
    manual_control_new_DW.Delay4_DSTATE[0] =
      manual_control_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay3'
    manual_control_new_DW.Delay3_DSTATE[0] =
      manual_control_new_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_j[0] =
      manual_control_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S18>/Delay1'
    manual_control_new_DW.Delay1_DSTATE[0] =
      manual_control_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    manual_control_new_DW.Delay_DSTATE[0] =
      manual_control_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S14>/Delay'
    manual_control_new_DW.Delay_DSTATE_k[0] =
      manual_control_new_P.Delay_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S14>/Delay1'
    manual_control_new_DW.Delay1_DSTATE_f[0] =
      manual_control_new_P.Delay1_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S14>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_b[0] =
      manual_control_new_P.Delay2_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S14>/Delay3'
    manual_control_new_DW.Delay3_DSTATE_f[0] =
      manual_control_new_P.Delay3_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S14>/Delay4'
    manual_control_new_DW.Delay4_DSTATE_l[0] =
      manual_control_new_P.Delay4_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S14>/Delay5'
    manual_control_new_DW.Delay5_DSTATE_d[0] =
      manual_control_new_P.Delay5_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S14>/Delay6'
    manual_control_new_DW.Delay6_DSTATE_c[0] =
      manual_control_new_P.Delay6_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S14>/Delay7'
    manual_control_new_DW.Delay7_DSTATE_p[0] =
      manual_control_new_P.Delay7_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S14>/Delay8'
    manual_control_new_DW.Delay8_DSTATE_g[0] =
      manual_control_new_P.Delay8_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S14>/Delay9'
    manual_control_new_DW.Delay9_DSTATE_a[0] =
      manual_control_new_P.Delay9_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S14>/Delay10'
    manual_control_new_DW.Delay10_DSTATE_e[0] =
      manual_control_new_P.Delay10_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S14>/Delay11'
    manual_control_new_DW.Delay11_DSTATE_b[0] =
      manual_control_new_P.Delay11_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S14>/Delay12'
    manual_control_new_DW.Delay12_DSTATE_i[0] =
      manual_control_new_P.Delay12_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S14>/Delay13'
    manual_control_new_DW.Delay13_DSTATE_d[0] =
      manual_control_new_P.Delay13_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S14>/Delay14'
    manual_control_new_DW.Delay14_DSTATE_d[0] =
      manual_control_new_P.Delay14_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S14>/Delay15'
    manual_control_new_DW.Delay15_DSTATE[0] =
      manual_control_new_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay20'
    manual_control_new_DW.Delay20_DSTATE_k[0] =
      manual_control_new_P.Delay20_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S14>/Delay21'
    manual_control_new_DW.Delay21_DSTATE_l[0] =
      manual_control_new_P.Delay21_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S14>/Delay22'
    manual_control_new_DW.Delay22_DSTATE_m[0] =
      manual_control_new_P.Delay22_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S14>/Delay23'
    manual_control_new_DW.Delay23_DSTATE_f[0] =
      manual_control_new_P.Delay23_InitialCondition_l[0];

    // InitializeConditions for Delay: '<S14>/Delay24'
    manual_control_new_DW.Delay24_DSTATE[0] =
      manual_control_new_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay25'
    manual_control_new_DW.Delay25_DSTATE[0] =
      manual_control_new_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay26'
    manual_control_new_DW.Delay26_DSTATE[0] =
      manual_control_new_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay27'
    manual_control_new_DW.Delay27_DSTATE[0] =
      manual_control_new_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay16'
    manual_control_new_DW.Delay16_DSTATE[0] =
      manual_control_new_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay17'
    manual_control_new_DW.Delay17_DSTATE[0] =
      manual_control_new_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay18'
    manual_control_new_DW.Delay18_DSTATE[0] =
      manual_control_new_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S14>/Delay19'
    manual_control_new_DW.Delay19_DSTATE[0] =
      manual_control_new_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S16>/Delay2'
    manual_control_new_DW.Delay2_DSTATE[1] =
      manual_control_new_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay23'
    manual_control_new_DW.Delay23_DSTATE[1] =
      manual_control_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay22'
    manual_control_new_DW.Delay22_DSTATE[1] =
      manual_control_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay21'
    manual_control_new_DW.Delay21_DSTATE[1] =
      manual_control_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay20'
    manual_control_new_DW.Delay20_DSTATE[1] =
      manual_control_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay14'
    manual_control_new_DW.Delay14_DSTATE[1] =
      manual_control_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay13'
    manual_control_new_DW.Delay13_DSTATE[1] =
      manual_control_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay12'
    manual_control_new_DW.Delay12_DSTATE[1] =
      manual_control_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay11'
    manual_control_new_DW.Delay11_DSTATE[1] =
      manual_control_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay10'
    manual_control_new_DW.Delay10_DSTATE[1] =
      manual_control_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay9'
    manual_control_new_DW.Delay9_DSTATE[1] =
      manual_control_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay8'
    manual_control_new_DW.Delay8_DSTATE[1] =
      manual_control_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay7'
    manual_control_new_DW.Delay7_DSTATE[1] =
      manual_control_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay6'
    manual_control_new_DW.Delay6_DSTATE[1] =
      manual_control_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay5'
    manual_control_new_DW.Delay5_DSTATE[1] =
      manual_control_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay4'
    manual_control_new_DW.Delay4_DSTATE[1] =
      manual_control_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay3'
    manual_control_new_DW.Delay3_DSTATE[1] =
      manual_control_new_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_j[1] =
      manual_control_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S18>/Delay1'
    manual_control_new_DW.Delay1_DSTATE[1] =
      manual_control_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    manual_control_new_DW.Delay_DSTATE[1] =
      manual_control_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S14>/Delay'
    manual_control_new_DW.Delay_DSTATE_k[1] =
      manual_control_new_P.Delay_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S14>/Delay1'
    manual_control_new_DW.Delay1_DSTATE_f[1] =
      manual_control_new_P.Delay1_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S14>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_b[1] =
      manual_control_new_P.Delay2_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S14>/Delay3'
    manual_control_new_DW.Delay3_DSTATE_f[1] =
      manual_control_new_P.Delay3_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S14>/Delay4'
    manual_control_new_DW.Delay4_DSTATE_l[1] =
      manual_control_new_P.Delay4_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S14>/Delay5'
    manual_control_new_DW.Delay5_DSTATE_d[1] =
      manual_control_new_P.Delay5_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S14>/Delay6'
    manual_control_new_DW.Delay6_DSTATE_c[1] =
      manual_control_new_P.Delay6_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S14>/Delay7'
    manual_control_new_DW.Delay7_DSTATE_p[1] =
      manual_control_new_P.Delay7_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S14>/Delay8'
    manual_control_new_DW.Delay8_DSTATE_g[1] =
      manual_control_new_P.Delay8_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S14>/Delay9'
    manual_control_new_DW.Delay9_DSTATE_a[1] =
      manual_control_new_P.Delay9_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S14>/Delay10'
    manual_control_new_DW.Delay10_DSTATE_e[1] =
      manual_control_new_P.Delay10_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S14>/Delay11'
    manual_control_new_DW.Delay11_DSTATE_b[1] =
      manual_control_new_P.Delay11_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S14>/Delay12'
    manual_control_new_DW.Delay12_DSTATE_i[1] =
      manual_control_new_P.Delay12_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S14>/Delay13'
    manual_control_new_DW.Delay13_DSTATE_d[1] =
      manual_control_new_P.Delay13_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S14>/Delay14'
    manual_control_new_DW.Delay14_DSTATE_d[1] =
      manual_control_new_P.Delay14_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S14>/Delay15'
    manual_control_new_DW.Delay15_DSTATE[1] =
      manual_control_new_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay20'
    manual_control_new_DW.Delay20_DSTATE_k[1] =
      manual_control_new_P.Delay20_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S14>/Delay21'
    manual_control_new_DW.Delay21_DSTATE_l[1] =
      manual_control_new_P.Delay21_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S14>/Delay22'
    manual_control_new_DW.Delay22_DSTATE_m[1] =
      manual_control_new_P.Delay22_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S14>/Delay23'
    manual_control_new_DW.Delay23_DSTATE_f[1] =
      manual_control_new_P.Delay23_InitialCondition_l[1];

    // InitializeConditions for Delay: '<S14>/Delay24'
    manual_control_new_DW.Delay24_DSTATE[1] =
      manual_control_new_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay25'
    manual_control_new_DW.Delay25_DSTATE[1] =
      manual_control_new_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay26'
    manual_control_new_DW.Delay26_DSTATE[1] =
      manual_control_new_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay27'
    manual_control_new_DW.Delay27_DSTATE[1] =
      manual_control_new_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay16'
    manual_control_new_DW.Delay16_DSTATE[1] =
      manual_control_new_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay17'
    manual_control_new_DW.Delay17_DSTATE[1] =
      manual_control_new_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay18'
    manual_control_new_DW.Delay18_DSTATE[1] =
      manual_control_new_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S14>/Delay19'
    manual_control_new_DW.Delay19_DSTATE[1] =
      manual_control_new_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S16>/Delay2'
    manual_control_new_DW.Delay2_DSTATE[2] =
      manual_control_new_P.Delay2_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay23'
    manual_control_new_DW.Delay23_DSTATE[2] =
      manual_control_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay22'
    manual_control_new_DW.Delay22_DSTATE[2] =
      manual_control_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay21'
    manual_control_new_DW.Delay21_DSTATE[2] =
      manual_control_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay20'
    manual_control_new_DW.Delay20_DSTATE[2] =
      manual_control_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay14'
    manual_control_new_DW.Delay14_DSTATE[2] =
      manual_control_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay13'
    manual_control_new_DW.Delay13_DSTATE[2] =
      manual_control_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay12'
    manual_control_new_DW.Delay12_DSTATE[2] =
      manual_control_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay11'
    manual_control_new_DW.Delay11_DSTATE[2] =
      manual_control_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay10'
    manual_control_new_DW.Delay10_DSTATE[2] =
      manual_control_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay9'
    manual_control_new_DW.Delay9_DSTATE[2] =
      manual_control_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay8'
    manual_control_new_DW.Delay8_DSTATE[2] =
      manual_control_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay7'
    manual_control_new_DW.Delay7_DSTATE[2] =
      manual_control_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay6'
    manual_control_new_DW.Delay6_DSTATE[2] =
      manual_control_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay5'
    manual_control_new_DW.Delay5_DSTATE[2] =
      manual_control_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay4'
    manual_control_new_DW.Delay4_DSTATE[2] =
      manual_control_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay3'
    manual_control_new_DW.Delay3_DSTATE[2] =
      manual_control_new_P.Delay3_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_j[2] =
      manual_control_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S18>/Delay1'
    manual_control_new_DW.Delay1_DSTATE[2] =
      manual_control_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    manual_control_new_DW.Delay_DSTATE[2] =
      manual_control_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S14>/Delay'
    manual_control_new_DW.Delay_DSTATE_k[2] =
      manual_control_new_P.Delay_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S14>/Delay1'
    manual_control_new_DW.Delay1_DSTATE_f[2] =
      manual_control_new_P.Delay1_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S14>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_b[2] =
      manual_control_new_P.Delay2_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S14>/Delay3'
    manual_control_new_DW.Delay3_DSTATE_f[2] =
      manual_control_new_P.Delay3_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S14>/Delay4'
    manual_control_new_DW.Delay4_DSTATE_l[2] =
      manual_control_new_P.Delay4_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S14>/Delay5'
    manual_control_new_DW.Delay5_DSTATE_d[2] =
      manual_control_new_P.Delay5_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S14>/Delay6'
    manual_control_new_DW.Delay6_DSTATE_c[2] =
      manual_control_new_P.Delay6_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S14>/Delay7'
    manual_control_new_DW.Delay7_DSTATE_p[2] =
      manual_control_new_P.Delay7_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S14>/Delay8'
    manual_control_new_DW.Delay8_DSTATE_g[2] =
      manual_control_new_P.Delay8_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S14>/Delay9'
    manual_control_new_DW.Delay9_DSTATE_a[2] =
      manual_control_new_P.Delay9_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S14>/Delay10'
    manual_control_new_DW.Delay10_DSTATE_e[2] =
      manual_control_new_P.Delay10_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S14>/Delay11'
    manual_control_new_DW.Delay11_DSTATE_b[2] =
      manual_control_new_P.Delay11_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S14>/Delay12'
    manual_control_new_DW.Delay12_DSTATE_i[2] =
      manual_control_new_P.Delay12_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S14>/Delay13'
    manual_control_new_DW.Delay13_DSTATE_d[2] =
      manual_control_new_P.Delay13_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S14>/Delay14'
    manual_control_new_DW.Delay14_DSTATE_d[2] =
      manual_control_new_P.Delay14_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S14>/Delay15'
    manual_control_new_DW.Delay15_DSTATE[2] =
      manual_control_new_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay20'
    manual_control_new_DW.Delay20_DSTATE_k[2] =
      manual_control_new_P.Delay20_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S14>/Delay21'
    manual_control_new_DW.Delay21_DSTATE_l[2] =
      manual_control_new_P.Delay21_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S14>/Delay22'
    manual_control_new_DW.Delay22_DSTATE_m[2] =
      manual_control_new_P.Delay22_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S14>/Delay23'
    manual_control_new_DW.Delay23_DSTATE_f[2] =
      manual_control_new_P.Delay23_InitialCondition_l[2];

    // InitializeConditions for Delay: '<S14>/Delay24'
    manual_control_new_DW.Delay24_DSTATE[2] =
      manual_control_new_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay25'
    manual_control_new_DW.Delay25_DSTATE[2] =
      manual_control_new_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay26'
    manual_control_new_DW.Delay26_DSTATE[2] =
      manual_control_new_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay27'
    manual_control_new_DW.Delay27_DSTATE[2] =
      manual_control_new_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay16'
    manual_control_new_DW.Delay16_DSTATE[2] =
      manual_control_new_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay17'
    manual_control_new_DW.Delay17_DSTATE[2] =
      manual_control_new_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay18'
    manual_control_new_DW.Delay18_DSTATE[2] =
      manual_control_new_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S14>/Delay19'
    manual_control_new_DW.Delay19_DSTATE[2] =
      manual_control_new_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S16>/Memory2'
    manual_control_new_DW.Memory2_PreviousInput =
      manual_control_new_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S16>/Memory3'
    memcpy(&manual_control_new_DW.Memory3_PreviousInput[0],
           &manual_control_new_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S19>/Memory4'
    manual_control_new_DW.Memory4_PreviousInput_l = manual_control_new_P.x0_ps;

    // InitializeConditions for Memory: '<S19>/Memory3'
    manual_control_new_DW.Memory3_PreviousInput_j = manual_control_new_P.P0_ps;

    // InitializeConditions for Memory: '<S19>/Memory2'
    manual_control_new_DW.Memory2_PreviousInput_d =
      manual_control_new_P.Memory2_InitialCondition_d;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn' 
    manual_control_new_DW.DiscreteTransferFcn_states_a =
      manual_control_new_P.DiscreteTransferFcn_InitialSt_b;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn1' 
    manual_control_new_DW.DiscreteTransferFcn1_states_o =
      manual_control_new_P.DiscreteTransferFcn1_InitialS_l;

    // InitializeConditions for DiscreteTransferFcn: '<S13>/Discrete Transfer Fcn2' 
    manual_control_new_DW.DiscreteTransferFcn2_states_i =
      manual_control_new_P.DiscreteTransferFcn2_InitialS_e;

    // InitializeConditions for Memory: '<S7>/Memory5'
    manual_control_new_DW.Memory5_PreviousInput =
      manual_control_new_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S19>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_f[0] =
      manual_control_new_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S7>/Memory6'
    manual_control_new_DW.Memory6_PreviousInput[0] =
      manual_control_new_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S19>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_f[1] =
      manual_control_new_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S7>/Memory6'
    manual_control_new_DW.Memory6_PreviousInput[1] =
      manual_control_new_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S19>/Delay2'
    manual_control_new_DW.Delay2_DSTATE_f[2] =
      manual_control_new_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S7>/Memory6'
    manual_control_new_DW.Memory6_PreviousInput[2] =
      manual_control_new_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn' 
    manual_control_new_DW.DiscreteTransferFcn_states_d =
      manual_control_new_P.DiscreteTransferFcn_InitialSt_i;

    // InitializeConditions for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn1' 
    manual_control_new_DW.DiscreteTransferFcn1_states_l =
      manual_control_new_P.DiscreteTransferFcn1_InitialS_f;

    // InitializeConditions for DiscreteTransferFcn: '<S11>/Discrete Transfer Fcn2' 
    manual_control_new_DW.DiscreteTransferFcn2_states_b =
      manual_control_new_P.DiscreteTransferFcn2_InitialS_j;

    // SystemInitialize for Enabled SubSystem: '<S41>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S42>/In1' incorporates:
    //   Outport: '<S42>/Out1'

    manual_control_new_B.In1_i = manual_control_new_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S41>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S43>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S44>/In1' incorporates:
    //   Outport: '<S44>/Out1'

    manual_control_new_B.In1_n = manual_control_new_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S43>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    manual_control_new_B.In1 = manual_control_new_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S45>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S46>/In1' incorporates:
    //   Outport: '<S46>/Out1'

    manual_control_new_B.In1_f = manual_control_new_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S45>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S2>/MATLAB Function1'
    manual_con_MATLABFunction1_Init(&manual_control_new_DW.sf_MATLABFunction1_p);

    // SystemInitialize for MATLAB Function: '<S8>/MATLAB Function7'
    manual_con_MATLABFunction1_Init(&manual_control_new_DW.sf_MATLABFunction7);

    // Start for MATLABSystem: '<S41>/SourceBlock'
    manual_control_new_DW.obj_jj.matlabCodegenIsDeleted = false;
    manual_control_new_DW.obj_jj.isInitialized = 1;
    manual_control_new_DW.obj_jj.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(manual_control_new_DW.obj_jj.orbMetadataObj,
                         &manual_control_new_DW.obj_jj.eventStructObj);
    manual_control_new_DW.obj_jj.isSetupComplete = true;

    // Start for MATLABSystem: '<S43>/SourceBlock'
    manual_control_new_DW.obj_j.matlabCodegenIsDeleted = false;
    manual_control_new_DW.obj_j.isInitialized = 1;
    manual_control_new_DW.obj_j.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(manual_control_new_DW.obj_j.orbMetadataObj,
                         &manual_control_new_DW.obj_j.eventStructObj);
    manual_control_new_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S55>/SourceBlock'
    manual_control_new_DW.obj_c.matlabCodegenIsDeleted = false;
    manual_control_new_DW.obj_c.isInitialized = 1;
    manual_control_new_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(manual_control_new_DW.obj_c.orbMetadataObj,
                         &manual_control_new_DW.obj_c.eventStructObj);
    manual_control_new_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S45>/SourceBlock'
    manual_control_new_DW.obj_h.matlabCodegenIsDeleted = false;
    manual_control_new_DW.obj_h.isInitialized = 1;
    manual_control_new_DW.obj_h.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(manual_control_new_DW.obj_h.orbMetadataObj,
                         &manual_control_new_DW.obj_h.eventStructObj);
    manual_control_new_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/PX4 PWM Output' incorporates:
    //   Constant: '<S3>/failsafe'

    manual_control_new_DW.obj.errorStatus = 0U;
    manual_control_new_DW.obj.isInitialized = 0;
    manual_control_new_DW.obj.matlabCodegenIsDeleted = false;
    manual_control_SystemCore_setup(&manual_control_new_DW.obj,
      rtb_startingswitch, manual_control_new_P.failsafe_Value);
  }
}

// Model terminate function
void manual_control_new_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S41>/SourceBlock'
  if (!manual_control_new_DW.obj_jj.matlabCodegenIsDeleted) {
    manual_control_new_DW.obj_jj.matlabCodegenIsDeleted = true;
    if ((manual_control_new_DW.obj_jj.isInitialized == 1) &&
        manual_control_new_DW.obj_jj.isSetupComplete) {
      uORB_read_terminate(&manual_control_new_DW.obj_jj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S41>/SourceBlock'

  // Terminate for MATLABSystem: '<S43>/SourceBlock'
  if (!manual_control_new_DW.obj_j.matlabCodegenIsDeleted) {
    manual_control_new_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((manual_control_new_DW.obj_j.isInitialized == 1) &&
        manual_control_new_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&manual_control_new_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S43>/SourceBlock'

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  if (!manual_control_new_DW.obj_c.matlabCodegenIsDeleted) {
    manual_control_new_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((manual_control_new_DW.obj_c.isInitialized == 1) &&
        manual_control_new_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&manual_control_new_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S55>/SourceBlock'

  // Terminate for MATLABSystem: '<S45>/SourceBlock'
  if (!manual_control_new_DW.obj_h.matlabCodegenIsDeleted) {
    manual_control_new_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((manual_control_new_DW.obj_h.isInitialized == 1) &&
        manual_control_new_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&manual_control_new_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S45>/SourceBlock'
  // Terminate for MATLABSystem: '<S3>/PX4 PWM Output'
  if (!manual_control_new_DW.obj.matlabCodegenIsDeleted) {
    manual_control_new_DW.obj.matlabCodegenIsDeleted = true;
    if ((manual_control_new_DW.obj.isInitialized == 1) &&
        manual_control_new_DW.obj.isSetupComplete) {
      status = pwm_disarm(&manual_control_new_DW.obj.pwmDevHandler,
                          &manual_control_new_DW.obj.armAdvertiseObj);
      manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
        (manual_control_new_DW.obj.errorStatus | status);
      status = pwm_resetServo(&manual_control_new_DW.obj.pwmDevHandler,
        manual_control_new_DW.obj.servoCount,
        manual_control_new_DW.obj.channelMask, manual_control_new_DW.obj.isMain,
        &manual_control_new_DW.obj.actuatorAdvertiseObj);
      manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
        (manual_control_new_DW.obj.errorStatus | status);
      status = pwm_close(&manual_control_new_DW.obj.pwmDevHandler,
                         &manual_control_new_DW.obj.actuatorAdvertiseObj,
                         &manual_control_new_DW.obj.armAdvertiseObj);
      manual_control_new_DW.obj.errorStatus = static_cast<uint16_T>
        (manual_control_new_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S3>/PX4 PWM Output'
}

//
// File trailer for generated code.
//
// [EOF]
//
