//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: h2_controller_pitch.cpp
//
// Code generated for Simulink model 'h2_controller_pitch'.
//
// Model version                  : 1.55
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed May 29 10:00:01 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "h2_controller_pitch.h"
#include "rtwtypes.h"
#include "h2_controller_pitch_types.h"
#include "h2_controller_pitch_private.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S4>/MATLAB Function1'
const int32_T h2_controller_pitch_CALL_EVENT = -1;

// Block signals (default storage)
B_h2_controller_pitch_T h2_controller_pitch_B;

// Block states (default storage)
DW_h2_controller_pitch_T h2_controller_pitch_DW;

// Real-time model
RT_MODEL_h2_controller_pitch_T h2_controller_pitch_M_ =
  RT_MODEL_h2_controller_pitch_T();
RT_MODEL_h2_controller_pitch_T *const h2_controller_pitch_M =
  &h2_controller_pitch_M_;

// Forward declaration for local functions
static void h2_controller__SystemCore_setup(px4_internal_block_PWM_h2_con_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
uint32_T plook_u32u16u64n48_evenc_gf(uint16_T u, uint16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint64_T *fraction)
{
  uint32_T bpIndex;
  uint16_T fbpIndex;
  uint16_T uAdjust;

  // Prelookup - Index and Fraction
  // Index Search method: 'even'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'on'
  // Rounding mode: 'floor'

  uAdjust = static_cast<uint16_T>(static_cast<uint32_T>(u) - bp0);
  fbpIndex = static_cast<uint16_T>(static_cast<uint32_T>(uAdjust) / bpSpace);
  if (fbpIndex < maxIndex) {
    bpIndex = fbpIndex;
    *fraction = (static_cast<uint64_T>(static_cast<uint16_T>
      (static_cast<uint32_T>(uAdjust) - static_cast<uint16_T>
       (static_cast<uint32_T>(fbpIndex) * bpSpace))) << 48) / bpSpace;
  } else {
    bpIndex = maxIndex - 1U;
    *fraction = 281474976710656ULL;
  }

  return bpIndex;
}

int16_T intrp1d_s16s32s32u32u64n48l_f(uint32_T bpIndex, uint64_T frac, const
  int16_T table[])
{
  int16_T yL_0d0;

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Rounding mode: 'floor'
  // Overflow mode: 'wrapping'

  yL_0d0 = table[bpIndex];
  return static_cast<int16_T>(static_cast<int16_T>(((table[bpIndex + 1U] -
    yL_0d0) * static_cast<int64_T>(frac)) >> 48) + yL_0d0);
}

//
// System initialize for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S20>/MATLAB Function7'
//
void h2_control_MATLABFunction1_Init(DW_MATLABFunction1_h2_control_T *localDW)
{
  localDW->sfEvent = h2_controller_pitch_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S20>/MATLAB Function7'
//
void h2_controller_p_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_h2_control_T *localDW)
{
  localDW->sfEvent = h2_controller_pitch_CALL_EVENT;
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

static void h2_controller__SystemCore_setup(px4_internal_block_PWM_h2_con_T *obj,
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
void h2_controller_pitch_step(void)
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
  int16_T rtb_SignCorrected;
  uint16_T rtb_CastU16En16;
  uint16_T rtb_DataTypeConversion1_c;
  uint16_T rtb_DataTypeConversion1_f;
  uint16_T rtb_DataTypeConversion1_p;
  boolean_T rtb_LTEp50;
  boolean_T rtb_startingswitch;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_js);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<Root>/Digital Clock'
  //   DigitalClock: '<S19>/Discrete Time1'
  //   DigitalClock: '<S28>/Discrete Time'
  //   DigitalClock: '<S31>/Discrete Time'
  //   Step: '<Root>/R ref'

  h2_controller_pitch_B.DigitalClock1 = h2_controller_pitch_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (h2_controller_pitch_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = h2_controller_pitch_P.Constant2_Value;
  } else {
    rtb_startingswitch = h2_controller_pitch_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // DiscreteStateSpace: '<S11>/Internal'
  {
    h2_controller_pitch_B.Internal = h2_controller_pitch_P.Internal_C*
      h2_controller_pitch_DW.Internal_DSTATE;
  }

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S1>/Gain'

  h2_controller_pitch_B.Product = h2_controller_pitch_P.Gain_Gain *
    h2_controller_pitch_B.Internal * static_cast<real_T>(rtb_startingswitch);

  // DataTypeConversion: '<S72>/CastU16En16' incorporates:
  //   Gain: '<Root>/Gain4'

  h2_controller_pitch_B.a21 = floor(h2_controller_pitch_P.Gain4_Gain *
    h2_controller_pitch_B.DigitalClock1 * 65536.0);
  if (rtIsNaN(h2_controller_pitch_B.a21) || rtIsInf(h2_controller_pitch_B.a21))
  {
    h2_controller_pitch_B.a21 = 0.0;
  } else {
    h2_controller_pitch_B.a21 = fmod(h2_controller_pitch_B.a21, 65536.0);
  }

  rtb_CastU16En16 = static_cast<uint16_T>(h2_controller_pitch_B.a21 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-h2_controller_pitch_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(h2_controller_pitch_B.a21)));

  // End of DataTypeConversion: '<S72>/CastU16En16'

  // RelationalOperator: '<S72>/LTEp50' incorporates:
  //   Constant: '<S72>/Point50'
  //   DataTypeConversion: '<S72>/CastU16En16'

  rtb_LTEp50 = (rtb_CastU16En16 <= h2_controller_pitch_P.Point50_Value);

  // Switch: '<S72>/QuadHandle1' incorporates:
  //   Constant: '<S72>/Point50'
  //   DataTypeConversion: '<S72>/CastU16En16'
  //   Sum: '<S72>/Amp50'

  if (!rtb_LTEp50) {
    rtb_CastU16En16 = static_cast<uint16_T>(rtb_CastU16En16 -
      h2_controller_pitch_P.Point50_Value);
  }

  // End of Switch: '<S72>/QuadHandle1'

  // Switch: '<S72>/QuadHandle2' incorporates:
  //   Constant: '<S72>/Point25'
  //   Constant: '<S72>/Point50'
  //   RelationalOperator: '<S72>/LTEp25'
  //   Sum: '<S72>/p50mA'
  //   Switch: '<S72>/QuadHandle1'

  if (rtb_CastU16En16 > h2_controller_pitch_P.Point25_Value) {
    rtb_CastU16En16 = static_cast<uint16_T>(h2_controller_pitch_P.Point50_Value
      - rtb_CastU16En16);
  }

  // Lookup_n-D: '<S71>/Look-Up Table' incorporates:
  //   Switch: '<S72>/QuadHandle2'

  h2_controller_pitch_B.bpIdx = plook_u32u16u64n48_evenc_gf(rtb_CastU16En16,
    h2_controller_pitch_P.LookUpTable_bp01Data[0], static_cast<uint16_T>(
    static_cast<uint32_T>(h2_controller_pitch_P.LookUpTable_bp01Data[1]) -
    h2_controller_pitch_P.LookUpTable_bp01Data[0]), 32U,
    &h2_controller_pitch_B.frac);

  // Switch: '<S72>/SignCorrected' incorporates:
  //   Lookup_n-D: '<S71>/Look-Up Table'
  //   UnaryMinus: '<S72>/Negate'

  if (rtb_LTEp50) {
    rtb_SignCorrected = intrp1d_s16s32s32u32u64n48l_f
      (h2_controller_pitch_B.bpIdx, h2_controller_pitch_B.frac,
       h2_controller_pitch_P.LookUpTable_tableData);
  } else {
    rtb_SignCorrected = static_cast<int16_T>(-intrp1d_s16s32s32u32u64n48l_f
      (h2_controller_pitch_B.bpIdx, h2_controller_pitch_B.frac,
       h2_controller_pitch_P.LookUpTable_tableData));
  }

  // End of Switch: '<S72>/SignCorrected'

  // MATLABSystem: '<S69>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(h2_controller_pitch_DW.obj_c.orbMetadataObj,
    &h2_controller_pitch_DW.obj_c.eventStructObj,
    &h2_controller_pitch_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S70>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S70>/In1'
    h2_controller_pitch_B.In1 = h2_controller_pitch_B.b_varargout_2;
    srUpdateBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S69>/SourceBlock'
  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // Sqrt: '<S67>/sqrt' incorporates:
  //   Product: '<S68>/Product'
  //   Product: '<S68>/Product1'
  //   Product: '<S68>/Product2'
  //   Product: '<S68>/Product3'
  //   Sum: '<S68>/Sum'

  h2_controller_pitch_B.Product3 = static_cast<real32_T>(sqrt(static_cast<real_T>
    (((h2_controller_pitch_B.In1.q[0] * h2_controller_pitch_B.In1.q[0] +
       h2_controller_pitch_B.In1.q[1] * h2_controller_pitch_B.In1.q[1]) +
      h2_controller_pitch_B.In1.q[2] * h2_controller_pitch_B.In1.q[2]) +
     h2_controller_pitch_B.In1.q[3] * h2_controller_pitch_B.In1.q[3])));

  // Product: '<S62>/Product'
  rtb_fcn5 = h2_controller_pitch_B.In1.q[0] / h2_controller_pitch_B.Product3;

  // Product: '<S62>/Product1'
  rtb_Product1 = h2_controller_pitch_B.In1.q[1] / h2_controller_pitch_B.Product3;

  // Product: '<S62>/Product2'
  rtb_Product2 = h2_controller_pitch_B.In1.q[2] / h2_controller_pitch_B.Product3;

  // Product: '<S62>/Product3'
  h2_controller_pitch_B.Product3 = h2_controller_pitch_B.In1.q[3] /
    h2_controller_pitch_B.Product3;

  // Fcn: '<S52>/fcn3'
  rtb_fcn3 = (rtb_Product1 * h2_controller_pitch_B.Product3 - rtb_fcn5 *
              rtb_Product2) * -2.0F;

  // If: '<S63>/If' incorporates:
  //   Constant: '<S64>/Constant'
  //   Constant: '<S65>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
    //   ActionPort: '<S64>/Action Port'

    rtb_fcn3 = h2_controller_pitch_P.Constant_Value_o;

    // End of Outputs for SubSystem: '<S63>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
    //   ActionPort: '<S64>/Action Port'

    // Update for If: '<S63>/If' incorporates:
    //   Constant: '<S64>/Constant'

    srUpdateBC(h2_controller_pitch_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S63>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S65>/Action Port'

    rtb_fcn3 = h2_controller_pitch_P.Constant_Value_e5;

    // End of Outputs for SubSystem: '<S63>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S65>/Action Port'

    // Update for If: '<S63>/If' incorporates:
    //   Constant: '<S65>/Constant'

    srUpdateBC(h2_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S63>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S63>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S66>/Action Port'

    // Update for If: '<S63>/If'
    srUpdateBC(h2_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S63>/If Action Subsystem2'
  }

  // End of If: '<S63>/If'

  // Fcn: '<S52>/fcn5' incorporates:
  //   Fcn: '<S52>/fcn2'

  y_k_tmp = rtb_fcn5 * rtb_fcn5;
  y_k_tmp_0 = rtb_Product1 * rtb_Product1;
  y_k_tmp_1 = rtb_Product2 * rtb_Product2;
  y_k_tmp_2 = h2_controller_pitch_B.Product3 * h2_controller_pitch_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S52>/fcn4'
  //   Fcn: '<S52>/fcn5'
  //   Trigonometry: '<S61>/Trigonometric Function3'

  h2_controller_pitch_B.y_k[0] = rt_atan2f_snf((rtb_Product2 *
    h2_controller_pitch_B.Product3 + rtb_fcn5 * rtb_Product1) * 2.0F, ((y_k_tmp
    - y_k_tmp_0) - y_k_tmp_1) + y_k_tmp_2);

  // Trigonometry: '<S61>/trigFcn'
  if (rtb_fcn3 > 1.0F) {
    rtb_fcn3 = 1.0F;
  } else if (rtb_fcn3 < -1.0F) {
    rtb_fcn3 = -1.0F;
  }

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S52>/fcn1'
  //   Fcn: '<S52>/fcn2'
  //   Trigonometry: '<S61>/Trigonometric Function1'
  //   Trigonometry: '<S61>/trigFcn'

  h2_controller_pitch_B.y_k[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (rtb_fcn3)));
  h2_controller_pitch_B.y_k[2] = rt_atan2f_snf((rtb_Product1 * rtb_Product2 +
    rtb_fcn5 * h2_controller_pitch_B.Product3) * 2.0F, ((y_k_tmp + y_k_tmp_0) -
    y_k_tmp_1) - y_k_tmp_2);

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  h2_controller_pitch_B.y1_e = h2_controller_pitch_P.Gain1_Gain_b *
    h2_controller_pitch_B.y_k[0];
  h2_controller_pitch_B.y2_i = h2_controller_pitch_P.Gain1_Gain_b *
    h2_controller_pitch_B.y_k[1];
  h2_controller_pitch_B.y3_c = h2_controller_pitch_P.Gain1_Gain_b *
    h2_controller_pitch_B.y_k[2];

  // Gain: '<Root>/Gain2' incorporates:
  //   Constant: '<Root>/Constant'
  //   Gain: '<Root>/Gain'
  //   Gain: '<Root>/Gain3'
  //   Sum: '<Root>/Sum'
  //   Sum: '<Root>/Sum1'
  //   Switch: '<S72>/SignCorrected'

  h2_controller_pitch_B.Gain2 = (static_cast<real_T>
    (h2_controller_pitch_P.Gain3_Gain * rtb_SignCorrected) *
    5.6961890777784355E-306 + (h2_controller_pitch_B.y2_i +
    h2_controller_pitch_P.Constant_Value_j) * h2_controller_pitch_P.Gain_Gain_m)
    * h2_controller_pitch_P.Gain2_Gain;

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   Constant: '<S1>/Constant6'
  //   DataTypeConversion: '<S1>/Data Type Conversion3'
  //   SignalConversion generated from: '<S12>/ SFunction '

  if (!rtb_startingswitch) {
    h2_controller_pitch_DW.Delay2_DSTATE[0] = 0.0;
    h2_controller_pitch_DW.Delay2_DSTATE[1] = 0.0;
    h2_controller_pitch_DW.Delay2_DSTATE[2] = 0.0;
    h2_controller_pitch_DW.Delay2_DSTATE[3] = 0.0;
    h2_controller_pitch_DW.Delay3_DSTATE = 0.0;
  }

  h2_controller_pitch_B.a21 = 0.0;
  h2_controller_pitch_B.Delay2_DSTATE = h2_controller_pitch_DW.Delay2_DSTATE[1];
  h2_controller_pitch_B.Delay2_DSTATE_m = h2_controller_pitch_DW.Delay2_DSTATE[0];
  h2_controller_pitch_B.Delay2_DSTATE_n = h2_controller_pitch_DW.Delay2_DSTATE[2];
  h2_controller_pitch_B.Delay2_DSTATE_pp = h2_controller_pitch_DW.Delay2_DSTATE
    [3];
  for (i = 0; i < 4; i++) {
    h2_controller_pitch_B.x_g = (((h2_controller_pitch_P.A_cond[i + 4] *
      h2_controller_pitch_B.Delay2_DSTATE + h2_controller_pitch_P.A_cond[i] *
      h2_controller_pitch_B.Delay2_DSTATE_m) + h2_controller_pitch_P.A_cond[i +
      8] * h2_controller_pitch_B.Delay2_DSTATE_n) +
      h2_controller_pitch_P.A_cond[i + 12] *
      h2_controller_pitch_B.Delay2_DSTATE_pp) + h2_controller_pitch_P.B_cond[i] *
      h2_controller_pitch_DW.Delay3_DSTATE;
    h2_controller_pitch_B.x[i] = h2_controller_pitch_B.x_g;
    h2_controller_pitch_B.a21 += h2_controller_pitch_P.C[i] *
      h2_controller_pitch_B.x_g;
  }

  h2_controller_pitch_B.Delay2_DSTATE = h2_controller_pitch_P.K[0] *
    h2_controller_pitch_B.Gain2 + h2_controller_pitch_P.K[1] *
    h2_controller_pitch_B.In1.rollspeed;
  h2_controller_pitch_B.Delay2_DSTATE_m = (h2_controller_pitch_P.D *
    h2_controller_pitch_B.Product + h2_controller_pitch_B.a21) +
    h2_controller_pitch_B.Delay2_DSTATE;
  if ((h2_controller_pitch_P.Constant6_Value <=
       h2_controller_pitch_B.Delay2_DSTATE_m) || rtIsNaN
      (h2_controller_pitch_B.Delay2_DSTATE_m)) {
    h2_controller_pitch_B.Delay2_DSTATE_m =
      h2_controller_pitch_P.Constant6_Value;
  }

  if ((h2_controller_pitch_P.Constant3_Value >=
       h2_controller_pitch_B.Delay2_DSTATE_m) || rtIsNaN
      (h2_controller_pitch_B.Delay2_DSTATE_m)) {
    h2_controller_pitch_B.Delay2_DSTATE_m =
      h2_controller_pitch_P.Constant3_Value;
  }

  h2_controller_pitch_B.u_sat = h2_controller_pitch_B.Delay2_DSTATE_m;

  // MATLAB Function: '<S1>/MATLAB Function3'
  h2_controller_pitch_B.tau_o[1] = h2_controller_pitch_B.u_sat;
  h2_controller_pitch_B.tau_o[0] = 0.0;
  h2_controller_pitch_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (h2_controller_pitch_B.tau_o[0] >= 0.0) {
    h2_controller_pitch_B.u[3] = h2_controller_pitch_P.Constant3_Value_m;
    h2_controller_pitch_B.u[2] = (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[7] * h2_controller_pitch_P.Constant3_Value_m +
      h2_controller_pitch_B.tau_o[0]) / (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[6]);
  } else {
    h2_controller_pitch_B.u[2] = h2_controller_pitch_P.Constant3_Value_m;
    h2_controller_pitch_B.u[3] = (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[6] * h2_controller_pitch_P.Constant3_Value_m -
      h2_controller_pitch_B.tau_o[0]) / (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[7]);
  }

  if (h2_controller_pitch_B.tau_o[1] >= 0.0) {
    h2_controller_pitch_B.u[0] = h2_controller_pitch_P.Constant3_Value_m;
    h2_controller_pitch_B.u[1] = (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[4] * h2_controller_pitch_P.Constant3_Value_m +
      h2_controller_pitch_B.tau_o[1]) / (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[5]);
  } else {
    h2_controller_pitch_B.u[1] = h2_controller_pitch_P.Constant3_Value_m;
    h2_controller_pitch_B.u[0] = (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[5] * h2_controller_pitch_P.Constant3_Value_m -
      h2_controller_pitch_B.tau_o[1]) / (h2_controller_pitch_P.param[3] *
      h2_controller_pitch_P.param[4]);
  }

  rtb_LTEp50 = rtIsNaN(h2_controller_pitch_B.u[0]);
  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[0]) ||
      rtb_LTEp50) {
    h2_controller_pitch_B.Delay2_DSTATE_n =
      h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.Delay2_DSTATE_n = h2_controller_pitch_B.u[0];
  }

  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[0]) ||
      rtb_LTEp50) {
    h2_controller_pitch_B.minval[0] = h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.minval[0] = h2_controller_pitch_B.u[0];
  }

  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[1]) ||
      rtIsNaN(h2_controller_pitch_B.u[1])) {
    h2_controller_pitch_B.Delay2_DSTATE_pp =
      h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.Delay2_DSTATE_pp = h2_controller_pitch_B.u[1];
  }

  rtb_LTEp50 = rtIsNaN(h2_controller_pitch_B.u[2]);
  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[2]) ||
      rtb_LTEp50) {
    h2_controller_pitch_B.x_g = h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.x_g = h2_controller_pitch_B.u[2];
  }

  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[2]) ||
      rtb_LTEp50) {
    h2_controller_pitch_B.minval[2] = h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.minval[2] = h2_controller_pitch_B.u[2];
  }

  if ((h2_controller_pitch_P.Constant1_Value <= h2_controller_pitch_B.u[3]) ||
      rtIsNaN(h2_controller_pitch_B.u[3])) {
    h2_controller_pitch_B.y = h2_controller_pitch_P.Constant1_Value;
  } else {
    h2_controller_pitch_B.y = h2_controller_pitch_B.u[3];
  }

  h2_controller_pitch_B.dv1[0] = 0.0;
  h2_controller_pitch_B.dv1[3] = 0.0;
  h2_controller_pitch_B.dv1[6] = h2_controller_pitch_P.param[3] *
    h2_controller_pitch_P.param[6];
  h2_controller_pitch_B.dv1[9] = -h2_controller_pitch_P.param[3] *
    h2_controller_pitch_P.param[7];
  h2_controller_pitch_B.dv1[1] = -h2_controller_pitch_P.param[3] *
    h2_controller_pitch_P.param[4];
  h2_controller_pitch_B.dv1[4] = h2_controller_pitch_P.param[3] *
    h2_controller_pitch_P.param[5];
  h2_controller_pitch_B.dv1[7] = 0.0;
  h2_controller_pitch_B.dv1[10] = 0.0;
  h2_controller_pitch_B.dv1[2] = -h2_controller_pitch_P.param[8];
  h2_controller_pitch_B.dv1[5] = -h2_controller_pitch_P.param[8];
  h2_controller_pitch_B.dv1[8] = h2_controller_pitch_P.param[8];
  h2_controller_pitch_B.dv1[11] = h2_controller_pitch_P.param[8];
  h2_controller_pitch_B.rtb_Delay_l_idx_0 = h2_controller_pitch_B.minval[0];
  h2_controller_pitch_B.rtb_Delay1_n_idx_0 = h2_controller_pitch_B.minval[2];
  for (i = 0; i < 3; i++) {
    h2_controller_pitch_B.tau_allocated[i] = ((h2_controller_pitch_B.dv1[i + 3] *
      h2_controller_pitch_B.Delay2_DSTATE_pp + h2_controller_pitch_B.dv1[i] *
      h2_controller_pitch_B.rtb_Delay_l_idx_0) + h2_controller_pitch_B.dv1[i + 6]
      * h2_controller_pitch_B.rtb_Delay1_n_idx_0) + h2_controller_pitch_B.dv1[i
      + 9] * h2_controller_pitch_B.y;
  }

  h2_controller_pitch_B.u[0] = h2_controller_pitch_B.Delay2_DSTATE_n;
  h2_controller_pitch_B.u[1] = h2_controller_pitch_B.Delay2_DSTATE_pp;
  h2_controller_pitch_B.u[2] = h2_controller_pitch_B.x_g;
  h2_controller_pitch_B.u[3] = h2_controller_pitch_B.y;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  h2_controller_pitch_B.u1 = h2_controller_pitch_B.u[0];
  h2_controller_pitch_B.u2 = h2_controller_pitch_B.u[1];
  h2_controller_pitch_B.u3 = h2_controller_pitch_B.u[2];
  h2_controller_pitch_B.u4 = h2_controller_pitch_B.u[3];

  // DataTypeConversion: '<S44>/Data Type Conversion1' incorporates:
  //   Constant: '<S44>/Constant'
  //   Sum: '<S44>/Sum'

  h2_controller_pitch_B.a21 = floor(h2_controller_pitch_B.u1 +
    h2_controller_pitch_P.Constant_Value_n);
  if (rtIsNaN(h2_controller_pitch_B.a21) || rtIsInf(h2_controller_pitch_B.a21))
  {
    h2_controller_pitch_B.a21 = 0.0;
  } else {
    h2_controller_pitch_B.a21 = fmod(h2_controller_pitch_B.a21, 65536.0);
  }

  rtb_CastU16En16 = static_cast<uint16_T>(h2_controller_pitch_B.a21 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-h2_controller_pitch_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(h2_controller_pitch_B.a21)));

  // End of DataTypeConversion: '<S44>/Data Type Conversion1'

  // DataTypeConversion: '<S45>/Data Type Conversion1' incorporates:
  //   Constant: '<S45>/Constant'
  //   Sum: '<S45>/Sum'

  h2_controller_pitch_B.a21 = floor(h2_controller_pitch_B.u2 +
    h2_controller_pitch_P.Constant_Value_jz);
  if (rtIsNaN(h2_controller_pitch_B.a21) || rtIsInf(h2_controller_pitch_B.a21))
  {
    h2_controller_pitch_B.a21 = 0.0;
  } else {
    h2_controller_pitch_B.a21 = fmod(h2_controller_pitch_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_c = static_cast<uint16_T>(h2_controller_pitch_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-h2_controller_pitch_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(h2_controller_pitch_B.a21)));

  // End of DataTypeConversion: '<S45>/Data Type Conversion1'

  // DataTypeConversion: '<S46>/Data Type Conversion1' incorporates:
  //   Constant: '<S46>/Constant'
  //   Sum: '<S46>/Sum'

  h2_controller_pitch_B.a21 = floor(h2_controller_pitch_B.u3 +
    h2_controller_pitch_P.Constant_Value_pr);
  if (rtIsNaN(h2_controller_pitch_B.a21) || rtIsInf(h2_controller_pitch_B.a21))
  {
    h2_controller_pitch_B.a21 = 0.0;
  } else {
    h2_controller_pitch_B.a21 = fmod(h2_controller_pitch_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_p = static_cast<uint16_T>(h2_controller_pitch_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-h2_controller_pitch_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(h2_controller_pitch_B.a21)));

  // End of DataTypeConversion: '<S46>/Data Type Conversion1'

  // DataTypeConversion: '<S47>/Data Type Conversion1' incorporates:
  //   Constant: '<S47>/Constant'
  //   Sum: '<S47>/Sum'

  h2_controller_pitch_B.a21 = floor(h2_controller_pitch_B.u4 +
    h2_controller_pitch_P.Constant_Value_d);
  if (rtIsNaN(h2_controller_pitch_B.a21) || rtIsInf(h2_controller_pitch_B.a21))
  {
    h2_controller_pitch_B.a21 = 0.0;
  } else {
    h2_controller_pitch_B.a21 = fmod(h2_controller_pitch_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_f = static_cast<uint16_T>(h2_controller_pitch_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-h2_controller_pitch_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(h2_controller_pitch_B.a21)));

  // End of DataTypeConversion: '<S47>/Data Type Conversion1'

  // MATLABSystem: '<S59>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(h2_controller_pitch_DW.obj_h.orbMetadataObj,
    &h2_controller_pitch_DW.obj_h.eventStructObj,
    &h2_controller_pitch_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S59>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S60>/In1'
    h2_controller_pitch_B.In1_f = h2_controller_pitch_B.b_varargout_2_b;
    srUpdateBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of MATLABSystem: '<S59>/SourceBlock'
  // End of Outputs for SubSystem: '<S59>/Enabled Subsystem'

  // MATLABSystem: '<S55>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(h2_controller_pitch_DW.obj_jj.orbMetadataObj,
    &h2_controller_pitch_DW.obj_jj.eventStructObj,
    &h2_controller_pitch_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S56>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S56>/In1'
    h2_controller_pitch_B.In1_i = h2_controller_pitch_B.b_varargout_2_k;
    srUpdateBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_js);
  }

  // End of MATLABSystem: '<S55>/SourceBlock'
  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // MATLABSystem: '<S57>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(h2_controller_pitch_DW.obj_j.orbMetadataObj,
    &h2_controller_pitch_DW.obj_j.eventStructObj,
    &h2_controller_pitch_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S57>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S58>/In1'
    h2_controller_pitch_B.In1_n = h2_controller_pitch_B.b_varargout_2_cx;
    srUpdateBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S57>/SourceBlock'
  // End of Outputs for SubSystem: '<S57>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  h2_controller_pitch_B.Delay2_DSTATE_pp =
    h2_controller_pitch_P.DiscreteTransferFcn_NumCoef *
    h2_controller_pitch_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  h2_controller_pitch_B.x_g = h2_controller_pitch_P.DiscreteTransferFcn1_NumCoef
    * h2_controller_pitch_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  h2_controller_pitch_B.y = h2_controller_pitch_P.DiscreteTransferFcn2_NumCoef *
    h2_controller_pitch_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S26>/MATLAB Function'

  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[0] =
    h2_controller_pitch_B.Delay2_DSTATE_pp;
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[1] =
    h2_controller_pitch_B.x_g;
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[2] = h2_controller_pitch_B.y;

  // Delay: '<S26>/Delay'
  h2_controller_pitch_B.rtb_Delay_l_idx_0 =
    h2_controller_pitch_DW.Delay_DSTATE_p[0];

  // Delay: '<S26>/Delay1'
  h2_controller_pitch_B.rtb_Delay1_n_idx_0 =
    h2_controller_pitch_DW.Delay1_DSTATE_p[0];

  // Delay: '<S26>/Delay2'
  h2_controller_pitch_B.rtb_Delay2_h_idx_0 =
    h2_controller_pitch_DW.Delay2_DSTATE_p[0];

  // Delay: '<S26>/Delay3'
  h2_controller_pitch_B.rtb_Delay3_p_idx_0 =
    h2_controller_pitch_DW.Delay3_DSTATE_j[0];

  // Delay: '<S26>/Delay4'
  h2_controller_pitch_B.rtb_Delay4_j_idx_0 =
    h2_controller_pitch_DW.Delay4_DSTATE_e[0];

  // Delay: '<S26>/Delay5'
  h2_controller_pitch_B.rtb_Delay5_e_idx_0 =
    h2_controller_pitch_DW.Delay5_DSTATE_p[0];

  // Delay: '<S26>/Delay6'
  h2_controller_pitch_B.rtb_Delay6_f_idx_0 =
    h2_controller_pitch_DW.Delay6_DSTATE_p[0];

  // Delay: '<S26>/Delay7'
  h2_controller_pitch_B.rtb_Delay7_i_idx_0 =
    h2_controller_pitch_DW.Delay7_DSTATE_o[0];

  // Delay: '<S26>/Delay8'
  h2_controller_pitch_B.rtb_Delay8_j_idx_0 =
    h2_controller_pitch_DW.Delay8_DSTATE_n[0];

  // Delay: '<S26>/Delay9'
  h2_controller_pitch_B.rtb_Delay9_j_idx_0 =
    h2_controller_pitch_DW.Delay9_DSTATE_i[0];

  // Delay: '<S26>/Delay10'
  h2_controller_pitch_B.rtb_Delay10_e_idx_0 =
    h2_controller_pitch_DW.Delay10_DSTATE_f[0];

  // Delay: '<S26>/Delay11'
  h2_controller_pitch_B.rtb_Delay11_n_idx_0 =
    h2_controller_pitch_DW.Delay11_DSTATE_k[0];

  // Delay: '<S26>/Delay12'
  h2_controller_pitch_B.rtb_Delay12_a_idx_0 =
    h2_controller_pitch_DW.Delay12_DSTATE_n[0];

  // Delay: '<S26>/Delay13'
  h2_controller_pitch_B.rtb_Delay13_h_idx_0 =
    h2_controller_pitch_DW.Delay13_DSTATE_g[0];

  // Delay: '<S26>/Delay14'
  h2_controller_pitch_B.rtb_Delay14_m_idx_0 =
    h2_controller_pitch_DW.Delay14_DSTATE_g[0];

  // Delay: '<S26>/Delay15'
  h2_controller_pitch_B.rtb_Delay15_idx_0 =
    h2_controller_pitch_DW.Delay15_DSTATE[0];

  // Delay: '<S26>/Delay20'
  h2_controller_pitch_B.rtb_Delay20_g_idx_0 =
    h2_controller_pitch_DW.Delay20_DSTATE_h[0];

  // Delay: '<S26>/Delay21'
  h2_controller_pitch_B.rtb_Delay21_e_idx_0 =
    h2_controller_pitch_DW.Delay21_DSTATE_d[0];

  // Delay: '<S26>/Delay22'
  h2_controller_pitch_B.rtb_Delay22_b_idx_0 =
    h2_controller_pitch_DW.Delay22_DSTATE_h[0];

  // Delay: '<S26>/Delay23'
  h2_controller_pitch_B.rtb_Delay23_g_idx_0 =
    h2_controller_pitch_DW.Delay23_DSTATE_p[0];

  // Delay: '<S26>/Delay24'
  h2_controller_pitch_B.rtb_Delay24_idx_0 =
    h2_controller_pitch_DW.Delay24_DSTATE[0];

  // Delay: '<S26>/Delay25'
  h2_controller_pitch_B.rtb_Delay25_idx_0 =
    h2_controller_pitch_DW.Delay25_DSTATE[0];

  // Delay: '<S26>/Delay26'
  h2_controller_pitch_B.rtb_Delay26_idx_0 =
    h2_controller_pitch_DW.Delay26_DSTATE[0];

  // Delay: '<S26>/Delay27'
  h2_controller_pitch_B.rtb_Delay27_idx_0 =
    h2_controller_pitch_DW.Delay27_DSTATE[0];

  // Delay: '<S26>/Delay16'
  h2_controller_pitch_B.rtb_Delay16_idx_0 =
    h2_controller_pitch_DW.Delay16_DSTATE[0];

  // Delay: '<S26>/Delay17'
  h2_controller_pitch_B.rtb_Delay17_idx_0 =
    h2_controller_pitch_DW.Delay17_DSTATE[0];

  // Delay: '<S26>/Delay18'
  h2_controller_pitch_B.rtb_Delay18_idx_0 =
    h2_controller_pitch_DW.Delay18_DSTATE[0];

  // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
  //   Delay: '<S26>/Delay'
  //   Delay: '<S26>/Delay1'
  //   Delay: '<S26>/Delay10'
  //   Delay: '<S26>/Delay11'
  //   Delay: '<S26>/Delay12'
  //   Delay: '<S26>/Delay13'
  //   Delay: '<S26>/Delay14'
  //   Delay: '<S26>/Delay15'
  //   Delay: '<S26>/Delay16'
  //   Delay: '<S26>/Delay17'
  //   Delay: '<S26>/Delay18'
  //   Delay: '<S26>/Delay19'
  //   Delay: '<S26>/Delay2'
  //   Delay: '<S26>/Delay20'
  //   Delay: '<S26>/Delay21'
  //   Delay: '<S26>/Delay22'
  //   Delay: '<S26>/Delay23'
  //   Delay: '<S26>/Delay24'
  //   Delay: '<S26>/Delay25'
  //   Delay: '<S26>/Delay26'
  //   Delay: '<S26>/Delay27'
  //   Delay: '<S26>/Delay3'
  //   Delay: '<S26>/Delay4'
  //   Delay: '<S26>/Delay5'
  //   Delay: '<S26>/Delay6'
  //   Delay: '<S26>/Delay7'
  //   Delay: '<S26>/Delay8'
  //   Delay: '<S26>/Delay9'
  //   MATLAB Function: '<S26>/MATLAB Function'

  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[3] =
    h2_controller_pitch_DW.Delay_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[6] =
    h2_controller_pitch_DW.Delay1_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[9] =
    h2_controller_pitch_DW.Delay2_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[12] =
    h2_controller_pitch_DW.Delay3_DSTATE_j[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[15] =
    h2_controller_pitch_DW.Delay4_DSTATE_e[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[18] =
    h2_controller_pitch_DW.Delay5_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[21] =
    h2_controller_pitch_DW.Delay6_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[24] =
    h2_controller_pitch_DW.Delay7_DSTATE_o[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[27] =
    h2_controller_pitch_DW.Delay8_DSTATE_n[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[30] =
    h2_controller_pitch_DW.Delay9_DSTATE_i[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[33] =
    h2_controller_pitch_DW.Delay10_DSTATE_f[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[36] =
    h2_controller_pitch_DW.Delay11_DSTATE_k[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[39] =
    h2_controller_pitch_DW.Delay12_DSTATE_n[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[42] =
    h2_controller_pitch_DW.Delay13_DSTATE_g[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[45] =
    h2_controller_pitch_DW.Delay14_DSTATE_g[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[48] =
    h2_controller_pitch_DW.Delay15_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[51] =
    h2_controller_pitch_DW.Delay20_DSTATE_h[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[54] =
    h2_controller_pitch_DW.Delay21_DSTATE_d[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[57] =
    h2_controller_pitch_DW.Delay22_DSTATE_h[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[60] =
    h2_controller_pitch_DW.Delay23_DSTATE_p[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[63] =
    h2_controller_pitch_DW.Delay24_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[66] =
    h2_controller_pitch_DW.Delay25_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[69] =
    h2_controller_pitch_DW.Delay26_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[72] =
    h2_controller_pitch_DW.Delay27_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[75] =
    h2_controller_pitch_DW.Delay16_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[78] =
    h2_controller_pitch_DW.Delay17_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[81] =
    h2_controller_pitch_DW.Delay18_DSTATE[0];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[84] =
    h2_controller_pitch_DW.Delay19_DSTATE[0];

  // Delay: '<S26>/Delay'
  h2_controller_pitch_B.rtb_Delay_l_idx_1 =
    h2_controller_pitch_DW.Delay_DSTATE_p[1];

  // Delay: '<S26>/Delay1'
  h2_controller_pitch_B.rtb_Delay1_n_idx_1 =
    h2_controller_pitch_DW.Delay1_DSTATE_p[1];

  // Delay: '<S26>/Delay2'
  h2_controller_pitch_B.rtb_Delay2_h_idx_1 =
    h2_controller_pitch_DW.Delay2_DSTATE_p[1];

  // Delay: '<S26>/Delay3'
  h2_controller_pitch_B.rtb_Delay3_p_idx_1 =
    h2_controller_pitch_DW.Delay3_DSTATE_j[1];

  // Delay: '<S26>/Delay4'
  h2_controller_pitch_B.rtb_Delay4_j_idx_1 =
    h2_controller_pitch_DW.Delay4_DSTATE_e[1];

  // Delay: '<S26>/Delay5'
  h2_controller_pitch_B.rtb_Delay5_e_idx_1 =
    h2_controller_pitch_DW.Delay5_DSTATE_p[1];

  // Delay: '<S26>/Delay6'
  h2_controller_pitch_B.rtb_Delay6_f_idx_1 =
    h2_controller_pitch_DW.Delay6_DSTATE_p[1];

  // Delay: '<S26>/Delay7'
  h2_controller_pitch_B.rtb_Delay7_i_idx_1 =
    h2_controller_pitch_DW.Delay7_DSTATE_o[1];

  // Delay: '<S26>/Delay8'
  h2_controller_pitch_B.rtb_Delay8_j_idx_1 =
    h2_controller_pitch_DW.Delay8_DSTATE_n[1];

  // Delay: '<S26>/Delay9'
  h2_controller_pitch_B.rtb_Delay9_j_idx_1 =
    h2_controller_pitch_DW.Delay9_DSTATE_i[1];

  // Delay: '<S26>/Delay10'
  h2_controller_pitch_B.rtb_Delay10_e_idx_1 =
    h2_controller_pitch_DW.Delay10_DSTATE_f[1];

  // Delay: '<S26>/Delay11'
  h2_controller_pitch_B.rtb_Delay11_n_idx_1 =
    h2_controller_pitch_DW.Delay11_DSTATE_k[1];

  // Delay: '<S26>/Delay12'
  h2_controller_pitch_B.rtb_Delay12_a_idx_1 =
    h2_controller_pitch_DW.Delay12_DSTATE_n[1];

  // Delay: '<S26>/Delay13'
  h2_controller_pitch_B.rtb_Delay13_h_idx_1 =
    h2_controller_pitch_DW.Delay13_DSTATE_g[1];

  // Delay: '<S26>/Delay14'
  h2_controller_pitch_B.rtb_Delay14_m_idx_1 =
    h2_controller_pitch_DW.Delay14_DSTATE_g[1];

  // Delay: '<S26>/Delay15'
  h2_controller_pitch_B.rtb_Delay15_idx_1 =
    h2_controller_pitch_DW.Delay15_DSTATE[1];

  // Delay: '<S26>/Delay20'
  h2_controller_pitch_B.rtb_Delay20_g_idx_1 =
    h2_controller_pitch_DW.Delay20_DSTATE_h[1];

  // Delay: '<S26>/Delay21'
  h2_controller_pitch_B.rtb_Delay21_e_idx_1 =
    h2_controller_pitch_DW.Delay21_DSTATE_d[1];

  // Delay: '<S26>/Delay22'
  h2_controller_pitch_B.rtb_Delay22_b_idx_1 =
    h2_controller_pitch_DW.Delay22_DSTATE_h[1];

  // Delay: '<S26>/Delay23'
  h2_controller_pitch_B.rtb_Delay23_g_idx_1 =
    h2_controller_pitch_DW.Delay23_DSTATE_p[1];

  // Delay: '<S26>/Delay24'
  h2_controller_pitch_B.rtb_Delay24_idx_1 =
    h2_controller_pitch_DW.Delay24_DSTATE[1];

  // Delay: '<S26>/Delay25'
  h2_controller_pitch_B.rtb_Delay25_idx_1 =
    h2_controller_pitch_DW.Delay25_DSTATE[1];

  // Delay: '<S26>/Delay26'
  h2_controller_pitch_B.rtb_Delay26_idx_1 =
    h2_controller_pitch_DW.Delay26_DSTATE[1];

  // Delay: '<S26>/Delay27'
  h2_controller_pitch_B.rtb_Delay27_idx_1 =
    h2_controller_pitch_DW.Delay27_DSTATE[1];

  // Delay: '<S26>/Delay16'
  h2_controller_pitch_B.rtb_Delay16_idx_1 =
    h2_controller_pitch_DW.Delay16_DSTATE[1];

  // Delay: '<S26>/Delay17'
  h2_controller_pitch_B.rtb_Delay17_idx_1 =
    h2_controller_pitch_DW.Delay17_DSTATE[1];

  // Delay: '<S26>/Delay18'
  h2_controller_pitch_B.rtb_Delay18_idx_1 =
    h2_controller_pitch_DW.Delay18_DSTATE[1];

  // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
  //   Delay: '<S26>/Delay'
  //   Delay: '<S26>/Delay1'
  //   Delay: '<S26>/Delay10'
  //   Delay: '<S26>/Delay11'
  //   Delay: '<S26>/Delay12'
  //   Delay: '<S26>/Delay13'
  //   Delay: '<S26>/Delay14'
  //   Delay: '<S26>/Delay15'
  //   Delay: '<S26>/Delay16'
  //   Delay: '<S26>/Delay17'
  //   Delay: '<S26>/Delay18'
  //   Delay: '<S26>/Delay19'
  //   Delay: '<S26>/Delay2'
  //   Delay: '<S26>/Delay20'
  //   Delay: '<S26>/Delay21'
  //   Delay: '<S26>/Delay22'
  //   Delay: '<S26>/Delay23'
  //   Delay: '<S26>/Delay24'
  //   Delay: '<S26>/Delay25'
  //   Delay: '<S26>/Delay26'
  //   Delay: '<S26>/Delay27'
  //   Delay: '<S26>/Delay3'
  //   Delay: '<S26>/Delay4'
  //   Delay: '<S26>/Delay5'
  //   Delay: '<S26>/Delay6'
  //   Delay: '<S26>/Delay7'
  //   Delay: '<S26>/Delay8'
  //   Delay: '<S26>/Delay9'
  //   MATLAB Function: '<S26>/MATLAB Function'

  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[4] =
    h2_controller_pitch_DW.Delay_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[7] =
    h2_controller_pitch_DW.Delay1_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[10] =
    h2_controller_pitch_DW.Delay2_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[13] =
    h2_controller_pitch_DW.Delay3_DSTATE_j[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[16] =
    h2_controller_pitch_DW.Delay4_DSTATE_e[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[19] =
    h2_controller_pitch_DW.Delay5_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[22] =
    h2_controller_pitch_DW.Delay6_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[25] =
    h2_controller_pitch_DW.Delay7_DSTATE_o[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[28] =
    h2_controller_pitch_DW.Delay8_DSTATE_n[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[31] =
    h2_controller_pitch_DW.Delay9_DSTATE_i[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[34] =
    h2_controller_pitch_DW.Delay10_DSTATE_f[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[37] =
    h2_controller_pitch_DW.Delay11_DSTATE_k[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[40] =
    h2_controller_pitch_DW.Delay12_DSTATE_n[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[43] =
    h2_controller_pitch_DW.Delay13_DSTATE_g[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[46] =
    h2_controller_pitch_DW.Delay14_DSTATE_g[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[49] =
    h2_controller_pitch_DW.Delay15_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[52] =
    h2_controller_pitch_DW.Delay20_DSTATE_h[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[55] =
    h2_controller_pitch_DW.Delay21_DSTATE_d[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[58] =
    h2_controller_pitch_DW.Delay22_DSTATE_h[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[61] =
    h2_controller_pitch_DW.Delay23_DSTATE_p[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[64] =
    h2_controller_pitch_DW.Delay24_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[67] =
    h2_controller_pitch_DW.Delay25_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[70] =
    h2_controller_pitch_DW.Delay26_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[73] =
    h2_controller_pitch_DW.Delay27_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[76] =
    h2_controller_pitch_DW.Delay16_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[79] =
    h2_controller_pitch_DW.Delay17_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[82] =
    h2_controller_pitch_DW.Delay18_DSTATE[1];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[85] =
    h2_controller_pitch_DW.Delay19_DSTATE[1];

  // Delay: '<S26>/Delay'
  h2_controller_pitch_B.Delay_DSTATE_p = h2_controller_pitch_DW.Delay_DSTATE_p[2];

  // Delay: '<S26>/Delay1'
  h2_controller_pitch_B.Delay1_DSTATE_p =
    h2_controller_pitch_DW.Delay1_DSTATE_p[2];

  // Delay: '<S26>/Delay2'
  h2_controller_pitch_B.Delay2_DSTATE_p =
    h2_controller_pitch_DW.Delay2_DSTATE_p[2];

  // Delay: '<S26>/Delay3'
  h2_controller_pitch_B.Delay3_DSTATE_j =
    h2_controller_pitch_DW.Delay3_DSTATE_j[2];

  // Delay: '<S26>/Delay4'
  h2_controller_pitch_B.Delay4_DSTATE_e =
    h2_controller_pitch_DW.Delay4_DSTATE_e[2];

  // Delay: '<S26>/Delay5'
  h2_controller_pitch_B.Delay5_DSTATE_p =
    h2_controller_pitch_DW.Delay5_DSTATE_p[2];

  // Delay: '<S26>/Delay6'
  h2_controller_pitch_B.Delay6_DSTATE_p =
    h2_controller_pitch_DW.Delay6_DSTATE_p[2];

  // Delay: '<S26>/Delay7'
  h2_controller_pitch_B.Delay7_DSTATE_o =
    h2_controller_pitch_DW.Delay7_DSTATE_o[2];

  // Delay: '<S26>/Delay8'
  h2_controller_pitch_B.Delay8_DSTATE_n =
    h2_controller_pitch_DW.Delay8_DSTATE_n[2];

  // Delay: '<S26>/Delay9'
  h2_controller_pitch_B.Delay9_DSTATE_i =
    h2_controller_pitch_DW.Delay9_DSTATE_i[2];

  // Delay: '<S26>/Delay10'
  h2_controller_pitch_B.Delay10_DSTATE_f =
    h2_controller_pitch_DW.Delay10_DSTATE_f[2];

  // Delay: '<S26>/Delay11'
  h2_controller_pitch_B.Delay11_DSTATE_k =
    h2_controller_pitch_DW.Delay11_DSTATE_k[2];

  // Delay: '<S26>/Delay12'
  h2_controller_pitch_B.Delay12_DSTATE_n =
    h2_controller_pitch_DW.Delay12_DSTATE_n[2];

  // Delay: '<S26>/Delay13'
  h2_controller_pitch_B.Delay13_DSTATE_g =
    h2_controller_pitch_DW.Delay13_DSTATE_g[2];

  // Delay: '<S26>/Delay14'
  h2_controller_pitch_B.Delay14_DSTATE_g =
    h2_controller_pitch_DW.Delay14_DSTATE_g[2];

  // Delay: '<S26>/Delay15'
  h2_controller_pitch_B.Delay15_DSTATE = h2_controller_pitch_DW.Delay15_DSTATE[2];

  // Delay: '<S26>/Delay20'
  h2_controller_pitch_B.Delay20_DSTATE_h =
    h2_controller_pitch_DW.Delay20_DSTATE_h[2];

  // Delay: '<S26>/Delay21'
  h2_controller_pitch_B.Delay21_DSTATE_d =
    h2_controller_pitch_DW.Delay21_DSTATE_d[2];

  // Delay: '<S26>/Delay22'
  h2_controller_pitch_B.Delay22_DSTATE_h =
    h2_controller_pitch_DW.Delay22_DSTATE_h[2];

  // Delay: '<S26>/Delay23'
  h2_controller_pitch_B.Delay23_DSTATE_p =
    h2_controller_pitch_DW.Delay23_DSTATE_p[2];

  // Delay: '<S26>/Delay24'
  h2_controller_pitch_B.Delay24_DSTATE = h2_controller_pitch_DW.Delay24_DSTATE[2];

  // Delay: '<S26>/Delay25'
  h2_controller_pitch_B.Delay25_DSTATE = h2_controller_pitch_DW.Delay25_DSTATE[2];

  // Delay: '<S26>/Delay26'
  h2_controller_pitch_B.Delay26_DSTATE = h2_controller_pitch_DW.Delay26_DSTATE[2];

  // Delay: '<S26>/Delay27'
  h2_controller_pitch_B.Delay27_DSTATE = h2_controller_pitch_DW.Delay27_DSTATE[2];

  // Delay: '<S26>/Delay16'
  h2_controller_pitch_B.Delay16_DSTATE = h2_controller_pitch_DW.Delay16_DSTATE[2];

  // Delay: '<S26>/Delay17'
  h2_controller_pitch_B.Delay17_DSTATE = h2_controller_pitch_DW.Delay17_DSTATE[2];

  // Delay: '<S26>/Delay18'
  h2_controller_pitch_B.Delay18_DSTATE = h2_controller_pitch_DW.Delay18_DSTATE[2];

  // SignalConversion generated from: '<S33>/ SFunction ' incorporates:
  //   Delay: '<S26>/Delay'
  //   Delay: '<S26>/Delay1'
  //   Delay: '<S26>/Delay10'
  //   Delay: '<S26>/Delay11'
  //   Delay: '<S26>/Delay12'
  //   Delay: '<S26>/Delay13'
  //   Delay: '<S26>/Delay14'
  //   Delay: '<S26>/Delay15'
  //   Delay: '<S26>/Delay16'
  //   Delay: '<S26>/Delay17'
  //   Delay: '<S26>/Delay18'
  //   Delay: '<S26>/Delay19'
  //   Delay: '<S26>/Delay2'
  //   Delay: '<S26>/Delay20'
  //   Delay: '<S26>/Delay21'
  //   Delay: '<S26>/Delay22'
  //   Delay: '<S26>/Delay23'
  //   Delay: '<S26>/Delay24'
  //   Delay: '<S26>/Delay25'
  //   Delay: '<S26>/Delay26'
  //   Delay: '<S26>/Delay27'
  //   Delay: '<S26>/Delay3'
  //   Delay: '<S26>/Delay4'
  //   Delay: '<S26>/Delay5'
  //   Delay: '<S26>/Delay6'
  //   Delay: '<S26>/Delay7'
  //   Delay: '<S26>/Delay8'
  //   Delay: '<S26>/Delay9'
  //   MATLAB Function: '<S26>/MATLAB Function'

  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[5] =
    h2_controller_pitch_DW.Delay_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[8] =
    h2_controller_pitch_DW.Delay1_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[11] =
    h2_controller_pitch_DW.Delay2_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[14] =
    h2_controller_pitch_DW.Delay3_DSTATE_j[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[17] =
    h2_controller_pitch_DW.Delay4_DSTATE_e[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[20] =
    h2_controller_pitch_DW.Delay5_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[23] =
    h2_controller_pitch_DW.Delay6_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[26] =
    h2_controller_pitch_DW.Delay7_DSTATE_o[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[29] =
    h2_controller_pitch_DW.Delay8_DSTATE_n[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[32] =
    h2_controller_pitch_DW.Delay9_DSTATE_i[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[35] =
    h2_controller_pitch_DW.Delay10_DSTATE_f[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[38] =
    h2_controller_pitch_DW.Delay11_DSTATE_k[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[41] =
    h2_controller_pitch_DW.Delay12_DSTATE_n[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[44] =
    h2_controller_pitch_DW.Delay13_DSTATE_g[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[47] =
    h2_controller_pitch_DW.Delay14_DSTATE_g[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[50] =
    h2_controller_pitch_DW.Delay15_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[53] =
    h2_controller_pitch_DW.Delay20_DSTATE_h[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[56] =
    h2_controller_pitch_DW.Delay21_DSTATE_d[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[59] =
    h2_controller_pitch_DW.Delay22_DSTATE_h[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[62] =
    h2_controller_pitch_DW.Delay23_DSTATE_p[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[65] =
    h2_controller_pitch_DW.Delay24_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[68] =
    h2_controller_pitch_DW.Delay25_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[71] =
    h2_controller_pitch_DW.Delay26_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[74] =
    h2_controller_pitch_DW.Delay27_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[77] =
    h2_controller_pitch_DW.Delay16_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[80] =
    h2_controller_pitch_DW.Delay17_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[83] =
    h2_controller_pitch_DW.Delay18_DSTATE[2];
  h2_controller_pitch_B.TmpSignalConversionAtSFun_e[86] =
    h2_controller_pitch_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S26>/MATLAB Function'
  for (h2_controller_pitch_B.r2 = 0; h2_controller_pitch_B.r2 < 29;
       h2_controller_pitch_B.r2++) {
    i = (h2_controller_pitch_B.r2 + 1) * 3;
    h2_controller_pitch_B.ph_meas =
      h2_controller_pitch_B.TmpSignalConversionAtSFun_e[i - 3];
    h2_controller_pitch_B.Delay2_DSTATE_n = h2_controller_pitch_B.ph_meas *
      h2_controller_pitch_B.ph_meas;
    h2_controller_pitch_B.ph_meas =
      h2_controller_pitch_B.TmpSignalConversionAtSFun_e[i - 2];
    h2_controller_pitch_B.Delay2_DSTATE_n += h2_controller_pitch_B.ph_meas *
      h2_controller_pitch_B.ph_meas;
    h2_controller_pitch_B.ph_meas =
      h2_controller_pitch_B.TmpSignalConversionAtSFun_e[i - 1];
    h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r2] = sqrt
      (h2_controller_pitch_B.ph_meas * h2_controller_pitch_B.ph_meas +
       h2_controller_pitch_B.Delay2_DSTATE_n);
    h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r2 + 29] =
      static_cast<real_T>(h2_controller_pitch_B.r2) + 1.0;
  }

  for (i = 0; i < 28; i++) {
    h2_controller_pitch_B.b = 27 - i;
    for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 <=
         h2_controller_pitch_B.b; h2_controller_pitch_B.r1++) {
      h2_controller_pitch_B.ph_meas =
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1];
      h2_controller_pitch_B.a21 =
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 1];
      if (h2_controller_pitch_B.ph_meas > h2_controller_pitch_B.a21) {
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1] =
          h2_controller_pitch_B.a21;
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 1] =
          h2_controller_pitch_B.ph_meas;
        h2_controller_pitch_B.a21 =
          h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 29];
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 29] =
          h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 30];
        h2_controller_pitch_B.b_norm[h2_controller_pitch_B.r1 + 30] =
          h2_controller_pitch_B.a21;
      }
    }
  }

  h2_controller_pitch_B.ph_meas = h2_controller_pitch_B.b_norm[41] * 3.0 - 2.0;
  h2_controller_pitch_B.Delay2_DSTATE_n =
    h2_controller_pitch_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (h2_controller_pitch_B.ph_meas) - 1];
  h2_controller_pitch_B.y_idx_0 = h2_controller_pitch_B.Delay2_DSTATE_n;

  // Sum: '<S30>/Sum23' incorporates:
  //   Delay: '<S30>/Delay'
  //   Delay: '<S30>/Delay1'
  //   Delay: '<S30>/Delay10'
  //   Delay: '<S30>/Delay11'
  //   Delay: '<S30>/Delay12'
  //   Delay: '<S30>/Delay13'
  //   Delay: '<S30>/Delay14'
  //   Delay: '<S30>/Delay2'
  //   Delay: '<S30>/Delay20'
  //   Delay: '<S30>/Delay21'
  //   Delay: '<S30>/Delay22'
  //   Delay: '<S30>/Delay23'
  //   Delay: '<S30>/Delay3'
  //   Delay: '<S30>/Delay4'
  //   Delay: '<S30>/Delay5'
  //   Delay: '<S30>/Delay6'
  //   Delay: '<S30>/Delay7'
  //   Delay: '<S30>/Delay8'
  //   Delay: '<S30>/Delay9'
  //   Sum: '<S30>/Sum'
  //   Sum: '<S30>/Sum1'
  //   Sum: '<S30>/Sum10'
  //   Sum: '<S30>/Sum11'
  //   Sum: '<S30>/Sum12'
  //   Sum: '<S30>/Sum13'
  //   Sum: '<S30>/Sum14'
  //   Sum: '<S30>/Sum2'
  //   Sum: '<S30>/Sum20'
  //   Sum: '<S30>/Sum21'
  //   Sum: '<S30>/Sum22'
  //   Sum: '<S30>/Sum3'
  //   Sum: '<S30>/Sum4'
  //   Sum: '<S30>/Sum5'
  //   Sum: '<S30>/Sum6'
  //   Sum: '<S30>/Sum7'
  //   Sum: '<S30>/Sum8'
  //   Sum: '<S30>/Sum9'

  h2_controller_pitch_B.Sum23_g =
    ((((((((((((((((((h2_controller_pitch_DW.Delay_DSTATE[0] +
                      h2_controller_pitch_B.Delay2_DSTATE_n) +
                     h2_controller_pitch_DW.Delay1_DSTATE[0]) +
                    h2_controller_pitch_DW.Delay2_DSTATE_i[0]) +
                   h2_controller_pitch_DW.Delay3_DSTATE_d[0]) +
                  h2_controller_pitch_DW.Delay4_DSTATE[0]) +
                 h2_controller_pitch_DW.Delay5_DSTATE[0]) +
                h2_controller_pitch_DW.Delay6_DSTATE[0]) +
               h2_controller_pitch_DW.Delay7_DSTATE[0]) +
              h2_controller_pitch_DW.Delay8_DSTATE[0]) +
             h2_controller_pitch_DW.Delay9_DSTATE[0]) +
            h2_controller_pitch_DW.Delay10_DSTATE[0]) +
           h2_controller_pitch_DW.Delay11_DSTATE[0]) +
          h2_controller_pitch_DW.Delay12_DSTATE[0]) +
         h2_controller_pitch_DW.Delay13_DSTATE[0]) +
        h2_controller_pitch_DW.Delay14_DSTATE[0]) +
       h2_controller_pitch_DW.Delay20_DSTATE[0]) +
      h2_controller_pitch_DW.Delay21_DSTATE[0]) +
     h2_controller_pitch_DW.Delay22_DSTATE[0]) +
    h2_controller_pitch_DW.Delay23_DSTATE[0];
  h2_controller_pitch_B.Sum23[0] = h2_controller_pitch_B.Sum23_g;

  // Sum: '<S30>/Sum24' incorporates:
  //   Sum: '<S30>/Sum23'

  h2_controller_pitch_B.Sum24[0] = h2_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S19>/RP_computation' incorporates:
  //   Gain: '<S30>/Gain'
  //   Sum: '<S30>/Sum23'
  //   Sum: '<S30>/Sum24'

  h2_controller_pitch_B.u_vect[0] = -(h2_controller_pitch_P.Gain_Gain_b *
    h2_controller_pitch_B.Sum23_g);

  // MATLAB Function: '<S26>/MATLAB Function'
  h2_controller_pitch_B.Delay2_DSTATE_n =
    h2_controller_pitch_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (h2_controller_pitch_B.ph_meas + 1.0) - 1];
  h2_controller_pitch_B.y_idx_1 = h2_controller_pitch_B.Delay2_DSTATE_n;

  // Sum: '<S30>/Sum23' incorporates:
  //   Delay: '<S30>/Delay'
  //   Delay: '<S30>/Delay1'
  //   Delay: '<S30>/Delay10'
  //   Delay: '<S30>/Delay11'
  //   Delay: '<S30>/Delay12'
  //   Delay: '<S30>/Delay13'
  //   Delay: '<S30>/Delay14'
  //   Delay: '<S30>/Delay2'
  //   Delay: '<S30>/Delay20'
  //   Delay: '<S30>/Delay21'
  //   Delay: '<S30>/Delay22'
  //   Delay: '<S30>/Delay23'
  //   Delay: '<S30>/Delay3'
  //   Delay: '<S30>/Delay4'
  //   Delay: '<S30>/Delay5'
  //   Delay: '<S30>/Delay6'
  //   Delay: '<S30>/Delay7'
  //   Delay: '<S30>/Delay8'
  //   Delay: '<S30>/Delay9'
  //   Sum: '<S30>/Sum'
  //   Sum: '<S30>/Sum1'
  //   Sum: '<S30>/Sum10'
  //   Sum: '<S30>/Sum11'
  //   Sum: '<S30>/Sum12'
  //   Sum: '<S30>/Sum13'
  //   Sum: '<S30>/Sum14'
  //   Sum: '<S30>/Sum2'
  //   Sum: '<S30>/Sum20'
  //   Sum: '<S30>/Sum21'
  //   Sum: '<S30>/Sum22'
  //   Sum: '<S30>/Sum3'
  //   Sum: '<S30>/Sum4'
  //   Sum: '<S30>/Sum5'
  //   Sum: '<S30>/Sum6'
  //   Sum: '<S30>/Sum7'
  //   Sum: '<S30>/Sum8'
  //   Sum: '<S30>/Sum9'

  h2_controller_pitch_B.Sum23_g =
    ((((((((((((((((((h2_controller_pitch_DW.Delay_DSTATE[1] +
                      h2_controller_pitch_B.Delay2_DSTATE_n) +
                     h2_controller_pitch_DW.Delay1_DSTATE[1]) +
                    h2_controller_pitch_DW.Delay2_DSTATE_i[1]) +
                   h2_controller_pitch_DW.Delay3_DSTATE_d[1]) +
                  h2_controller_pitch_DW.Delay4_DSTATE[1]) +
                 h2_controller_pitch_DW.Delay5_DSTATE[1]) +
                h2_controller_pitch_DW.Delay6_DSTATE[1]) +
               h2_controller_pitch_DW.Delay7_DSTATE[1]) +
              h2_controller_pitch_DW.Delay8_DSTATE[1]) +
             h2_controller_pitch_DW.Delay9_DSTATE[1]) +
            h2_controller_pitch_DW.Delay10_DSTATE[1]) +
           h2_controller_pitch_DW.Delay11_DSTATE[1]) +
          h2_controller_pitch_DW.Delay12_DSTATE[1]) +
         h2_controller_pitch_DW.Delay13_DSTATE[1]) +
        h2_controller_pitch_DW.Delay14_DSTATE[1]) +
       h2_controller_pitch_DW.Delay20_DSTATE[1]) +
      h2_controller_pitch_DW.Delay21_DSTATE[1]) +
     h2_controller_pitch_DW.Delay22_DSTATE[1]) +
    h2_controller_pitch_DW.Delay23_DSTATE[1];
  h2_controller_pitch_B.Sum23[1] = h2_controller_pitch_B.Sum23_g;

  // Sum: '<S30>/Sum24' incorporates:
  //   Sum: '<S30>/Sum23'

  h2_controller_pitch_B.Sum24[1] = h2_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S19>/RP_computation' incorporates:
  //   Gain: '<S30>/Gain'
  //   Sum: '<S30>/Sum23'
  //   Sum: '<S30>/Sum24'

  h2_controller_pitch_B.u_vect[1] = -(h2_controller_pitch_P.Gain_Gain_b *
    h2_controller_pitch_B.Sum23_g);

  // MATLAB Function: '<S26>/MATLAB Function'
  h2_controller_pitch_B.Delay2_DSTATE_n =
    h2_controller_pitch_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (h2_controller_pitch_B.ph_meas + 2.0) - 1];

  // Sum: '<S30>/Sum23' incorporates:
  //   Delay: '<S30>/Delay'
  //   Delay: '<S30>/Delay1'
  //   Delay: '<S30>/Delay10'
  //   Delay: '<S30>/Delay11'
  //   Delay: '<S30>/Delay12'
  //   Delay: '<S30>/Delay13'
  //   Delay: '<S30>/Delay14'
  //   Delay: '<S30>/Delay2'
  //   Delay: '<S30>/Delay20'
  //   Delay: '<S30>/Delay21'
  //   Delay: '<S30>/Delay22'
  //   Delay: '<S30>/Delay23'
  //   Delay: '<S30>/Delay3'
  //   Delay: '<S30>/Delay4'
  //   Delay: '<S30>/Delay5'
  //   Delay: '<S30>/Delay6'
  //   Delay: '<S30>/Delay7'
  //   Delay: '<S30>/Delay8'
  //   Delay: '<S30>/Delay9'
  //   Sum: '<S30>/Sum'
  //   Sum: '<S30>/Sum1'
  //   Sum: '<S30>/Sum10'
  //   Sum: '<S30>/Sum11'
  //   Sum: '<S30>/Sum12'
  //   Sum: '<S30>/Sum13'
  //   Sum: '<S30>/Sum14'
  //   Sum: '<S30>/Sum2'
  //   Sum: '<S30>/Sum20'
  //   Sum: '<S30>/Sum21'
  //   Sum: '<S30>/Sum22'
  //   Sum: '<S30>/Sum3'
  //   Sum: '<S30>/Sum4'
  //   Sum: '<S30>/Sum5'
  //   Sum: '<S30>/Sum6'
  //   Sum: '<S30>/Sum7'
  //   Sum: '<S30>/Sum8'
  //   Sum: '<S30>/Sum9'

  h2_controller_pitch_B.Sum23_g =
    ((((((((((((((((((h2_controller_pitch_DW.Delay_DSTATE[2] +
                      h2_controller_pitch_B.Delay2_DSTATE_n) +
                     h2_controller_pitch_DW.Delay1_DSTATE[2]) +
                    h2_controller_pitch_DW.Delay2_DSTATE_i[2]) +
                   h2_controller_pitch_DW.Delay3_DSTATE_d[2]) +
                  h2_controller_pitch_DW.Delay4_DSTATE[2]) +
                 h2_controller_pitch_DW.Delay5_DSTATE[2]) +
                h2_controller_pitch_DW.Delay6_DSTATE[2]) +
               h2_controller_pitch_DW.Delay7_DSTATE[2]) +
              h2_controller_pitch_DW.Delay8_DSTATE[2]) +
             h2_controller_pitch_DW.Delay9_DSTATE[2]) +
            h2_controller_pitch_DW.Delay10_DSTATE[2]) +
           h2_controller_pitch_DW.Delay11_DSTATE[2]) +
          h2_controller_pitch_DW.Delay12_DSTATE[2]) +
         h2_controller_pitch_DW.Delay13_DSTATE[2]) +
        h2_controller_pitch_DW.Delay14_DSTATE[2]) +
       h2_controller_pitch_DW.Delay20_DSTATE[2]) +
      h2_controller_pitch_DW.Delay21_DSTATE[2]) +
     h2_controller_pitch_DW.Delay22_DSTATE[2]) +
    h2_controller_pitch_DW.Delay23_DSTATE[2];
  h2_controller_pitch_B.Sum23[2] = h2_controller_pitch_B.Sum23_g;

  // Sum: '<S30>/Sum24' incorporates:
  //   Sum: '<S30>/Sum23'

  h2_controller_pitch_B.Sum24[2] = h2_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S19>/RP_computation' incorporates:
  //   Gain: '<S30>/Gain'
  //   Sum: '<S30>/Sum23'
  //   Sum: '<S30>/Sum24'

  h2_controller_pitch_B.u_vect[2] = -(h2_controller_pitch_P.Gain_Gain_b *
    h2_controller_pitch_B.Sum23_g);
  h2_controller_pitch_B.ph_meas = rt_atan2d_snf(h2_controller_pitch_B.u_vect[1],
    h2_controller_pitch_B.u_vect[2]);
  h2_controller_pitch_B.temp[0] = h2_controller_pitch_B.ph_meas;
  h2_controller_pitch_B.Sum23_g = rt_atan2d_snf(-h2_controller_pitch_B.u_vect[0],
    h2_controller_pitch_B.u_vect[1] * sin(h2_controller_pitch_B.ph_meas) +
    h2_controller_pitch_B.u_vect[2] * cos(h2_controller_pitch_B.ph_meas));
  h2_controller_pitch_B.temp[1] = h2_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S28>/EKF_RP' incorporates:
  //   Delay: '<S28>/Delay2'
  //   Memory: '<S28>/Memory2'
  //   Memory: '<S28>/Memory3'

  if (h2_controller_pitch_B.DigitalClock1 -
      h2_controller_pitch_DW.Memory2_PreviousInput >=
      h2_controller_pitch_P.Ts_EKF_meas) {
    h2_controller_pitch_DW.Memory2_PreviousInput =
      h2_controller_pitch_B.DigitalClock1;
    memcpy(&h2_controller_pitch_B.Pt1[0],
           &h2_controller_pitch_DW.Memory3_PreviousInput[0], 25U * sizeof(real_T));
    h2_controller_pitch_B.wq1 = h2_controller_pitch_DW.Delay2_DSTATE_l[1];
    h2_controller_pitch_B.wr1 = h2_controller_pitch_DW.Delay2_DSTATE_l[2];
    for (h2_controller_pitch_B.r2 = 0; h2_controller_pitch_B.r2 < 5;
         h2_controller_pitch_B.r2++) {
      h2_controller_pitch_B.xt[h2_controller_pitch_B.r2] = 0.0;
    }

    memset(&h2_controller_pitch_B.Pt[0], 0, 25U * sizeof(real_T));
    h2_controller_pitch_B.b = static_cast<int32_T>(floor
      (h2_controller_pitch_P.Ts_EKF_meas / h2_controller_pitch_P.Ts_EKF_integr));
    for (h2_controller_pitch_B.r2 = 0; h2_controller_pitch_B.r2 <
         h2_controller_pitch_B.b; h2_controller_pitch_B.r2++) {
      h2_controller_pitch_B.cph = cos
        (h2_controller_pitch_DW.Memory4_PreviousInput[0]);
      h2_controller_pitch_B.cth = cos
        (h2_controller_pitch_DW.Memory4_PreviousInput[1]);
      h2_controller_pitch_B.sph = sin
        (h2_controller_pitch_DW.Memory4_PreviousInput[0]);
      h2_controller_pitch_B.tth = sin
        (h2_controller_pitch_DW.Memory4_PreviousInput[1]) /
        h2_controller_pitch_B.cth;
      h2_controller_pitch_B.dv[0] = 1.0;
      h2_controller_pitch_B.a21 = h2_controller_pitch_B.sph *
        h2_controller_pitch_B.tth;
      h2_controller_pitch_B.dv[5] = h2_controller_pitch_B.a21;
      h2_controller_pitch_B.numAccum = h2_controller_pitch_B.cph *
        h2_controller_pitch_B.tth;
      h2_controller_pitch_B.dv[10] = h2_controller_pitch_B.numAccum;
      h2_controller_pitch_B.dv[15] = 0.0;
      h2_controller_pitch_B.dv[20] = 0.0;
      h2_controller_pitch_B.dv[25] = 0.0;
      h2_controller_pitch_B.dv[1] = 0.0;
      h2_controller_pitch_B.dv[6] = h2_controller_pitch_B.cph;
      h2_controller_pitch_B.dv[11] = -h2_controller_pitch_B.sph;
      h2_controller_pitch_B.dv[16] = 0.0;
      h2_controller_pitch_B.dv[21] = 0.0;
      h2_controller_pitch_B.dv[26] = 0.0;
      for (i = 0; i < 6; i++) {
        h2_controller_pitch_B.dv[5 * i + 2] = 0.0;
        h2_controller_pitch_B.dv[5 * i + 3] = 0.0;
        h2_controller_pitch_B.dv[5 * i + 4] = 0.0;
      }

      h2_controller_pitch_B.dv3[0] = h2_controller_pitch_DW.Delay2_DSTATE_l[0] -
        h2_controller_pitch_DW.Memory4_PreviousInput[2];
      h2_controller_pitch_B.Pt_f = h2_controller_pitch_B.wq1 -
        h2_controller_pitch_DW.Memory4_PreviousInput[3];
      h2_controller_pitch_B.dv3[1] = h2_controller_pitch_B.Pt_f;
      h2_controller_pitch_B.d = h2_controller_pitch_B.wr1 -
        h2_controller_pitch_DW.Memory4_PreviousInput[4];
      h2_controller_pitch_B.dv3[2] = h2_controller_pitch_B.d;
      h2_controller_pitch_B.dv3[3] =
        h2_controller_pitch_DW.Memory4_PreviousInput[2];
      h2_controller_pitch_B.dv3[4] =
        h2_controller_pitch_DW.Memory4_PreviousInput[3];
      h2_controller_pitch_B.dv3[5] =
        h2_controller_pitch_DW.Memory4_PreviousInput[4];
      h2_controller_pitch_B.Pt[0] = h2_controller_pitch_B.numAccum *
        h2_controller_pitch_B.Pt_f - h2_controller_pitch_B.a21 *
        h2_controller_pitch_B.d;
      h2_controller_pitch_B.a21 = h2_controller_pitch_B.d *
        h2_controller_pitch_B.cph;
      h2_controller_pitch_B.Pt[5] = (h2_controller_pitch_B.Pt_f *
        h2_controller_pitch_B.sph + h2_controller_pitch_B.a21) /
        (h2_controller_pitch_B.cth * h2_controller_pitch_B.cth);
      h2_controller_pitch_B.Pt[10] = -1.0;
      h2_controller_pitch_B.Pt[15] = -h2_controller_pitch_B.sph *
        h2_controller_pitch_B.tth;
      h2_controller_pitch_B.Pt[20] = -h2_controller_pitch_B.cph *
        h2_controller_pitch_B.tth;
      h2_controller_pitch_B.Pt[1] = h2_controller_pitch_B.Pt_f *
        -h2_controller_pitch_B.sph - h2_controller_pitch_B.a21;
      h2_controller_pitch_B.Pt[6] = 0.0;
      h2_controller_pitch_B.Pt[11] = 0.0;
      h2_controller_pitch_B.Pt[16] = -h2_controller_pitch_B.cph;
      h2_controller_pitch_B.Pt[21] = h2_controller_pitch_B.sph;
      for (i = 0; i < 5; i++) {
        h2_controller_pitch_B.a21 = 0.0;
        for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 6;
             h2_controller_pitch_B.r1++) {
          h2_controller_pitch_B.a21 += h2_controller_pitch_B.dv[5 *
            h2_controller_pitch_B.r1 + i] *
            h2_controller_pitch_B.dv3[h2_controller_pitch_B.r1];
        }

        h2_controller_pitch_B.xt[i] = h2_controller_pitch_P.Ts_EKF_integr *
          h2_controller_pitch_B.a21 +
          h2_controller_pitch_DW.Memory4_PreviousInput[i];
        h2_controller_pitch_B.Pt[5 * i + 2] = 0.0;
        h2_controller_pitch_B.Pt[5 * i + 3] = 0.0;
        h2_controller_pitch_B.Pt[5 * i + 4] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
             h2_controller_pitch_B.r1++) {
          h2_controller_pitch_B.a21 = 0.0;
          h2_controller_pitch_B.tth = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i;
            h2_controller_pitch_B.a21 += h2_controller_pitch_B.Pt1[5 *
              h2_controller_pitch_B.r1 + Pt1_tmp] *
              h2_controller_pitch_B.Pt[At1_tmp];
            h2_controller_pitch_B.tth += h2_controller_pitch_B.Pt[5 * Pt1_tmp +
              h2_controller_pitch_B.r1] * h2_controller_pitch_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * h2_controller_pitch_B.r1 + i;
          h2_controller_pitch_B.Pt1_m[Pt1_tmp] = h2_controller_pitch_B.tth;
          h2_controller_pitch_B.At1[Pt1_tmp] = h2_controller_pitch_B.a21;
        }
      }

      for (i = 0; i < 25; i++) {
        h2_controller_pitch_B.Pt[i] = ((h2_controller_pitch_B.At1[i] +
          h2_controller_pitch_B.Pt1_m[i]) + h2_controller_pitch_P.Q_phth[i]) *
          h2_controller_pitch_P.Ts_EKF_integr + h2_controller_pitch_B.Pt1[i];
      }

      for (i = 0; i < 5; i++) {
        h2_controller_pitch_DW.Memory4_PreviousInput[i] =
          h2_controller_pitch_B.xt[i];
      }

      memcpy(&h2_controller_pitch_B.Pt1[0], &h2_controller_pitch_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (i = 0; i < 10; i++) {
      h2_controller_pitch_B.Lk[i] = c[i];
    }

    for (i = 0; i < 2; i++) {
      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
           h2_controller_pitch_B.r1++) {
        h2_controller_pitch_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          h2_controller_pitch_B.a21 += h2_controller_pitch_B.Pt[5 * Pt1_tmp +
            h2_controller_pitch_B.r1] * h2_controller_pitch_B.Lk[5 * i + Pt1_tmp];
        }

        h2_controller_pitch_B.B[h2_controller_pitch_B.r1 + 5 * i] =
          h2_controller_pitch_B.a21;
      }
    }

    for (i = 0; i < 10; i++) {
      h2_controller_pitch_B.A_tmp_c[i] = b_b[i];
    }

    for (i = 0; i < 2; i++) {
      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
           h2_controller_pitch_B.r1++) {
        h2_controller_pitch_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          h2_controller_pitch_B.a21 += static_cast<real_T>
            (h2_controller_pitch_B.A_tmp_c[(Pt1_tmp << 1) + i]) *
            h2_controller_pitch_B.Pt[5 * h2_controller_pitch_B.r1 + Pt1_tmp];
        }

        h2_controller_pitch_B.A_tmp[i + (h2_controller_pitch_B.r1 << 1)] =
          h2_controller_pitch_B.a21;
      }

      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 2;
           h2_controller_pitch_B.r1++) {
        h2_controller_pitch_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          h2_controller_pitch_B.a21 += h2_controller_pitch_B.A_tmp[(Pt1_tmp << 1)
            + i] * h2_controller_pitch_B.Lk[5 * h2_controller_pitch_B.r1 +
            Pt1_tmp];
        }

        h2_controller_pitch_B.r2 = (h2_controller_pitch_B.r1 << 1) + i;
        h2_controller_pitch_B.minval[h2_controller_pitch_B.r2] =
          h2_controller_pitch_P.R_phth[h2_controller_pitch_B.r2] +
          h2_controller_pitch_B.a21;
      }
    }

    if (fabs(h2_controller_pitch_B.minval[1]) > fabs
        (h2_controller_pitch_B.minval[0])) {
      h2_controller_pitch_B.r1 = 1;
      h2_controller_pitch_B.r2 = 0;
    } else {
      h2_controller_pitch_B.r1 = 0;
      h2_controller_pitch_B.r2 = 1;
    }

    h2_controller_pitch_B.a21 =
      h2_controller_pitch_B.minval[h2_controller_pitch_B.r2] /
      h2_controller_pitch_B.minval[h2_controller_pitch_B.r1];
    h2_controller_pitch_B.tth =
      h2_controller_pitch_B.minval[h2_controller_pitch_B.r1 + 2];
    h2_controller_pitch_B.wq1 =
      h2_controller_pitch_B.minval[h2_controller_pitch_B.r2 + 2] -
      h2_controller_pitch_B.tth * h2_controller_pitch_B.a21;
    for (i = 0; i < 5; i++) {
      Pt1_tmp = 5 * h2_controller_pitch_B.r1 + i;
      h2_controller_pitch_B.Lk[Pt1_tmp] = h2_controller_pitch_B.B[i] /
        h2_controller_pitch_B.minval[h2_controller_pitch_B.r1];
      h2_controller_pitch_B.b = 5 * h2_controller_pitch_B.r2 + i;
      h2_controller_pitch_B.Lk[h2_controller_pitch_B.b] =
        (h2_controller_pitch_B.B[i + 5] - h2_controller_pitch_B.Lk[Pt1_tmp] *
         h2_controller_pitch_B.tth) / h2_controller_pitch_B.wq1;
      h2_controller_pitch_B.Lk[Pt1_tmp] -=
        h2_controller_pitch_B.Lk[h2_controller_pitch_B.b] *
        h2_controller_pitch_B.a21;
    }

    for (i = 0; i < 2; i++) {
      h2_controller_pitch_B.a21 = 0.0;
      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
           h2_controller_pitch_B.r1++) {
        h2_controller_pitch_B.a21 += static_cast<real_T>
          (h2_controller_pitch_B.A_tmp_c[(h2_controller_pitch_B.r1 << 1) + i]) *
          h2_controller_pitch_B.xt[h2_controller_pitch_B.r1];
      }

      h2_controller_pitch_B.temp_p[i] = h2_controller_pitch_B.temp[i] -
        h2_controller_pitch_B.a21;
    }

    h2_controller_pitch_B.a21 = h2_controller_pitch_B.temp_p[1];
    h2_controller_pitch_B.tth = h2_controller_pitch_B.temp_p[0];
    for (i = 0; i < 5; i++) {
      h2_controller_pitch_DW.Memory4_PreviousInput[i] =
        (h2_controller_pitch_B.Lk[i + 5] * h2_controller_pitch_B.a21 +
         h2_controller_pitch_B.Lk[i] * h2_controller_pitch_B.tth) +
        h2_controller_pitch_B.xt[i];
    }

    memset(&h2_controller_pitch_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      h2_controller_pitch_B.Pt1[i + 5 * i] = 1.0;
    }

    for (i = 0; i < 5; i++) {
      h2_controller_pitch_B.a21 = h2_controller_pitch_B.Lk[i + 5];
      h2_controller_pitch_B.tth = h2_controller_pitch_B.Lk[i];
      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
           h2_controller_pitch_B.r1++) {
        Pt1_tmp = h2_controller_pitch_B.r1 << 1;
        h2_controller_pitch_B.r2 = 5 * h2_controller_pitch_B.r1 + i;
        h2_controller_pitch_B.Pt1_m[h2_controller_pitch_B.r2] =
          h2_controller_pitch_B.Pt1[h2_controller_pitch_B.r2] -
          (static_cast<real_T>(h2_controller_pitch_B.A_tmp_c[Pt1_tmp + 1]) *
           h2_controller_pitch_B.a21 + static_cast<real_T>
           (h2_controller_pitch_B.A_tmp_c[Pt1_tmp]) * h2_controller_pitch_B.tth);
      }

      for (h2_controller_pitch_B.r1 = 0; h2_controller_pitch_B.r1 < 5;
           h2_controller_pitch_B.r1++) {
        h2_controller_pitch_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          h2_controller_pitch_B.a21 += h2_controller_pitch_B.Pt1_m[5 * Pt1_tmp +
            i] * h2_controller_pitch_B.Pt[5 * h2_controller_pitch_B.r1 + Pt1_tmp];
        }

        h2_controller_pitch_DW.Memory3_PreviousInput[i + 5 *
          h2_controller_pitch_B.r1] = h2_controller_pitch_B.a21;
      }
    }
  }

  // End of MATLAB Function: '<S28>/EKF_RP'

  // MATLAB Function: '<S19>/Y_computation' incorporates:
  //   DataTypeConversion: '<S17>/Data Type Conversion3'
  //   MATLAB Function: '<S19>/RPY_dot_computation'
  //   MATLAB Function: '<S28>/MATLAB Function'
  //   MATLAB Function: '<S31>/EKF_Y'

  h2_controller_pitch_B.wr1 = sin(h2_controller_pitch_DW.Memory4_PreviousInput[0]);
  h2_controller_pitch_B.cph = cos(h2_controller_pitch_DW.Memory4_PreviousInput[0]);
  h2_controller_pitch_B.tth = sin(h2_controller_pitch_DW.Memory4_PreviousInput[1]);
  h2_controller_pitch_B.cth = cos(h2_controller_pitch_DW.Memory4_PreviousInput[1]);
  h2_controller_pitch_B.wq1 = rt_atan2d_snf(h2_controller_pitch_B.In1_f.z *
    h2_controller_pitch_B.wr1 - h2_controller_pitch_B.In1_f.y *
    h2_controller_pitch_B.cph, (h2_controller_pitch_B.In1_f.y *
    h2_controller_pitch_B.tth * h2_controller_pitch_B.wr1 +
    h2_controller_pitch_B.In1_f.x * h2_controller_pitch_B.cth) +
    h2_controller_pitch_B.In1_f.z * h2_controller_pitch_B.tth *
    h2_controller_pitch_B.cph);
  if (h2_controller_pitch_B.wq1 < 0.0) {
    h2_controller_pitch_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S31>/EKF_Y' incorporates:
  //   Delay: '<S31>/Delay2'
  //   MATLAB Function: '<S19>/Y_computation'
  //   MATLAB Function: '<S28>/MATLAB Function'
  //   Memory: '<S31>/Memory2'

  if (h2_controller_pitch_B.DigitalClock1 -
      h2_controller_pitch_DW.Memory2_PreviousInput_b >=
      h2_controller_pitch_P.Ts_EKF_meas) {
    h2_controller_pitch_DW.Memory2_PreviousInput_b =
      h2_controller_pitch_B.DigitalClock1;
    h2_controller_pitch_B.sph = 0.0;
    h2_controller_pitch_B.Pt_f = 0.0;
    h2_controller_pitch_B.b = static_cast<int32_T>(floor
      (h2_controller_pitch_P.Ts_EKF_meas / h2_controller_pitch_P.Ts_EKF_integr));
    if (h2_controller_pitch_B.b - 1 >= 0) {
      h2_controller_pitch_B.dv4[0] = 0.0;
      h2_controller_pitch_B.dv4[1] = h2_controller_pitch_B.wr1 /
        h2_controller_pitch_B.cth;
      h2_controller_pitch_B.dv4[2] = h2_controller_pitch_B.cph /
        h2_controller_pitch_B.cth;
      h2_controller_pitch_B.dv4[3] = 0.0;
      h2_controller_pitch_B.dv4[4] = 0.0;
      h2_controller_pitch_B.dv4[5] = 0.0;
      h2_controller_pitch_B.dv5[0] = h2_controller_pitch_DW.Delay2_DSTATE_n[0] -
        h2_controller_pitch_DW.Memory4_PreviousInput[2];
      h2_controller_pitch_B.dv5[1] = h2_controller_pitch_DW.Delay2_DSTATE_n[1] -
        h2_controller_pitch_DW.Memory4_PreviousInput[3];
      h2_controller_pitch_B.dv5[2] = h2_controller_pitch_DW.Delay2_DSTATE_n[2] -
        h2_controller_pitch_DW.Memory4_PreviousInput[4];
      h2_controller_pitch_B.dv5[3] =
        h2_controller_pitch_DW.Memory4_PreviousInput[2];
      h2_controller_pitch_B.dv5[4] =
        h2_controller_pitch_DW.Memory4_PreviousInput[3];
      h2_controller_pitch_B.dv5[5] =
        h2_controller_pitch_DW.Memory4_PreviousInput[4];
    }

    for (h2_controller_pitch_B.r2 = 0; h2_controller_pitch_B.r2 <
         h2_controller_pitch_B.b; h2_controller_pitch_B.r2++) {
      h2_controller_pitch_B.a21 = 0.0;
      for (i = 0; i < 6; i++) {
        h2_controller_pitch_B.a21 += h2_controller_pitch_B.dv4[i] *
          h2_controller_pitch_B.dv5[i];
      }

      h2_controller_pitch_B.sph = h2_controller_pitch_P.Ts_EKF_integr *
        h2_controller_pitch_B.a21 +
        h2_controller_pitch_DW.Memory4_PreviousInput_k;
      h2_controller_pitch_B.Pt_f = ((0.0 *
        h2_controller_pitch_DW.Memory3_PreviousInput_f +
        h2_controller_pitch_DW.Memory3_PreviousInput_f * 0.0) +
        h2_controller_pitch_P.q_ps) * h2_controller_pitch_P.Ts_EKF_integr +
        h2_controller_pitch_DW.Memory3_PreviousInput_f;
      h2_controller_pitch_DW.Memory4_PreviousInput_k = h2_controller_pitch_B.sph;
      h2_controller_pitch_DW.Memory3_PreviousInput_f =
        h2_controller_pitch_B.Pt_f;
    }

    h2_controller_pitch_B.a21 = h2_controller_pitch_B.Pt_f /
      (h2_controller_pitch_B.Pt_f + h2_controller_pitch_P.r_ps);
    h2_controller_pitch_DW.Memory4_PreviousInput_k = (h2_controller_pitch_B.wq1
      - h2_controller_pitch_B.sph) * h2_controller_pitch_B.a21 +
      h2_controller_pitch_B.sph;
    h2_controller_pitch_DW.Memory3_PreviousInput_f = (1.0 -
      h2_controller_pitch_B.a21) * h2_controller_pitch_B.Pt_f;
  }

  // DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  h2_controller_pitch_B.sph =
    h2_controller_pitch_P.DiscreteTransferFcn_NumCoef_g *
    h2_controller_pitch_DW.DiscreteTransferFcn_states_a;

  // DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  h2_controller_pitch_B.Pt_f =
    h2_controller_pitch_P.DiscreteTransferFcn1_NumCoef_m *
    h2_controller_pitch_DW.DiscreteTransferFcn1_states_e;

  // DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'
  h2_controller_pitch_B.numAccum =
    h2_controller_pitch_P.DiscreteTransferFcn2_NumCoef_h *
    h2_controller_pitch_DW.DiscreteTransferFcn2_states_p;

  // MATLAB Function: '<S19>/RPY_dot_computation' incorporates:
  //   Constant: '<S19>/Constant6'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S19>/Y_computation'
  //   MATLAB Function: '<S28>/MATLAB Function'
  //   Memory: '<S19>/Memory5'

  if ((h2_controller_pitch_B.DigitalClock1 -
       h2_controller_pitch_DW.Memory5_PreviousInput >=
       h2_controller_pitch_P.Ts_EKF_meas) ||
      (h2_controller_pitch_B.DigitalClock1 == 0.0)) {
    h2_controller_pitch_B.tth /= h2_controller_pitch_B.cth;
    h2_controller_pitch_DW.Memory5_PreviousInput =
      h2_controller_pitch_B.DigitalClock1;
    h2_controller_pitch_B.dv2[0] = 1.0;
    h2_controller_pitch_B.dv2[3] = h2_controller_pitch_B.wr1 *
      h2_controller_pitch_B.tth;
    h2_controller_pitch_B.dv2[6] = h2_controller_pitch_B.cph *
      h2_controller_pitch_B.tth;
    h2_controller_pitch_B.dv2[1] = 0.0;
    h2_controller_pitch_B.dv2[4] = h2_controller_pitch_B.cph;
    h2_controller_pitch_B.dv2[7] = -h2_controller_pitch_B.wr1;
    h2_controller_pitch_B.dv2[2] = 0.0;
    h2_controller_pitch_B.dv2[5] = h2_controller_pitch_B.wr1 /
      h2_controller_pitch_B.cth;
    h2_controller_pitch_B.dv2[8] = h2_controller_pitch_B.cph /
      h2_controller_pitch_B.cth;
    h2_controller_pitch_B.a21 = h2_controller_pitch_B.sph -
      h2_controller_pitch_DW.Memory4_PreviousInput[2] * 0.0;
    h2_controller_pitch_B.tth = h2_controller_pitch_B.Pt_f -
      h2_controller_pitch_DW.Memory4_PreviousInput[3] * 0.0;
    h2_controller_pitch_B.wr1 = h2_controller_pitch_B.numAccum -
      h2_controller_pitch_DW.Memory4_PreviousInput[4] * 0.0;
    for (i = 0; i < 3; i++) {
      h2_controller_pitch_DW.Memory6_PreviousInput[i] =
        (h2_controller_pitch_B.dv2[i + 3] * h2_controller_pitch_B.tth +
         h2_controller_pitch_B.dv2[i] * h2_controller_pitch_B.a21) +
        h2_controller_pitch_B.dv2[i + 6] * h2_controller_pitch_B.wr1;
    }
  }

  // Step: '<Root>/R ref'
  if (h2_controller_pitch_B.DigitalClock1 < h2_controller_pitch_P.Rref_Time) {
    // Step: '<Root>/R ref'
    h2_controller_pitch_B.a21 = h2_controller_pitch_P.Rref_Y0;
  } else {
    // Step: '<Root>/R ref'
    h2_controller_pitch_B.a21 = h2_controller_pitch_P.Rref_YFinal;
  }

  // ManualSwitch: '<Root>/Manual Switch2'
  if (h2_controller_pitch_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (h2_controller_pitch_B.r2 = 0; h2_controller_pitch_B.r2 < 28;
         h2_controller_pitch_B.r2++) {
      h2_controller_pitch_B.ManualSwitch2[h2_controller_pitch_B.r2] =
        h2_controller_pitch_P.Constant6_Value_f;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant7'
    //   Constant: '<Root>/Constant8'
    //   DataTypeConversion: '<S5>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion2'
    //   DataTypeConversion: '<S5>/Data Type Conversion3'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   MATLAB Function: '<S28>/MATLAB Function'
    //   MATLAB Function: '<S31>/EKF_Y'
    //   MATLAB Function: '<S40>/MATLAB Function'
    //   MATLAB Function: '<S40>/MATLAB Function1'
    //   SignalConversion generated from: '<S42>/ SFunction '
    //   SignalConversion generated from: '<S43>/ SFunction '

    h2_controller_pitch_B.ManualSwitch2[0] = rtb_CastU16En16;
    h2_controller_pitch_B.ManualSwitch2[1] = rtb_DataTypeConversion1_c;
    h2_controller_pitch_B.ManualSwitch2[2] = rtb_DataTypeConversion1_p;
    h2_controller_pitch_B.ManualSwitch2[3] = rtb_DataTypeConversion1_f;
    h2_controller_pitch_B.ManualSwitch2[4] = h2_controller_pitch_B.In1_i.x;
    h2_controller_pitch_B.ManualSwitch2[5] = h2_controller_pitch_B.In1_i.y;
    h2_controller_pitch_B.ManualSwitch2[6] = h2_controller_pitch_B.In1_i.z;
    h2_controller_pitch_B.ManualSwitch2[7] = h2_controller_pitch_B.In1_n.x;
    h2_controller_pitch_B.ManualSwitch2[8] = h2_controller_pitch_B.In1_n.y;
    h2_controller_pitch_B.ManualSwitch2[9] = h2_controller_pitch_B.In1_n.z;
    h2_controller_pitch_B.ManualSwitch2[10] =
      h2_controller_pitch_B.In1.rollspeed;
    h2_controller_pitch_B.ManualSwitch2[11] =
      h2_controller_pitch_B.In1.pitchspeed;
    h2_controller_pitch_B.ManualSwitch2[12] = h2_controller_pitch_B.In1.yawspeed;
    h2_controller_pitch_B.ManualSwitch2[13] = h2_controller_pitch_B.y_k[0];
    h2_controller_pitch_B.ManualSwitch2[14] = h2_controller_pitch_B.y_k[1];
    h2_controller_pitch_B.ManualSwitch2[15] = h2_controller_pitch_B.y_k[2];
    h2_controller_pitch_B.ManualSwitch2[16] = h2_controller_pitch_B.In1_f.x;
    h2_controller_pitch_B.ManualSwitch2[17] = h2_controller_pitch_B.In1_f.y;
    h2_controller_pitch_B.ManualSwitch2[18] = h2_controller_pitch_B.In1_f.z;
    h2_controller_pitch_B.ManualSwitch2[19] =
      h2_controller_pitch_DW.Memory4_PreviousInput[0];
    h2_controller_pitch_B.ManualSwitch2[20] =
      h2_controller_pitch_DW.Memory4_PreviousInput[1];
    h2_controller_pitch_B.ManualSwitch2[21] =
      h2_controller_pitch_DW.Memory4_PreviousInput_k;
    h2_controller_pitch_B.ManualSwitch2[22] =
      h2_controller_pitch_DW.Memory6_PreviousInput[0];
    h2_controller_pitch_B.ManualSwitch2[23] =
      h2_controller_pitch_DW.Memory6_PreviousInput[1];
    h2_controller_pitch_B.ManualSwitch2[24] =
      h2_controller_pitch_DW.Memory6_PreviousInput[2];
    h2_controller_pitch_B.ManualSwitch2[25] = h2_controller_pitch_B.a21;
    h2_controller_pitch_B.ManualSwitch2[26] =
      h2_controller_pitch_P.Constant7_Value;
    h2_controller_pitch_B.ManualSwitch2[27] =
      h2_controller_pitch_P.Constant8_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  h2_controller_pitch_B.TmpSignalConversionAt_asyncqueu[0] =
    h2_controller_pitch_B.DigitalClock1;
  memcpy(&h2_controller_pitch_B.TmpSignalConversionAt_asyncqueu[1],
         &h2_controller_pitch_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S20>/Gain2' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function2'
  //   MATLAB Function: '<S31>/EKF_Y'
  //   SignalConversion generated from: '<S38>/ SFunction '

  h2_controller_pitch_B.Gain2_a[2] = h2_controller_pitch_P.Gain2_Gain_e *
    h2_controller_pitch_DW.Memory4_PreviousInput_k;

  // SignalConversion generated from: '<S28>/Delay2' incorporates:
  //   Delay: '<S31>/Delay2'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'

  h2_controller_pitch_DW.Delay2_DSTATE_n[0] = h2_controller_pitch_B.sph;
  h2_controller_pitch_DW.Delay2_DSTATE_n[1] = h2_controller_pitch_B.Pt_f;
  h2_controller_pitch_DW.Delay2_DSTATE_n[2] = h2_controller_pitch_B.numAccum;

  // Gain: '<S20>/Gain2' incorporates:
  //   MATLAB Function: '<S28>/MATLAB Function'

  h2_controller_pitch_B.Gain2_a[0] = h2_controller_pitch_P.Gain2_Gain_e *
    h2_controller_pitch_DW.Memory4_PreviousInput[0];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S19>/RP_computation'

  h2_controller_pitch_B.Gain_e[0] = h2_controller_pitch_P.Gain_Gain_e *
    h2_controller_pitch_B.ph_meas;

  // Gain: '<S20>/Gain2' incorporates:
  //   MATLAB Function: '<S28>/MATLAB Function'

  h2_controller_pitch_B.Gain2_a[1] = h2_controller_pitch_P.Gain2_Gain_e *
    h2_controller_pitch_DW.Memory4_PreviousInput[1];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S19>/Y_computation'

  h2_controller_pitch_B.Gain_e[1] = h2_controller_pitch_B.Sum23_g *
    h2_controller_pitch_P.Gain_Gain_e;
  h2_controller_pitch_B.Gain_e[2] = h2_controller_pitch_P.Gain_Gain_e *
    h2_controller_pitch_B.wq1;

  // MATLAB Function: '<S17>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S17>/Data Type Conversion2'

  h2_controller_pitch_B.y_c[0] = h2_controller_pitch_B.In1_n.x;
  h2_controller_pitch_B.y_c[1] = -static_cast<real_T>
    (h2_controller_pitch_B.In1_n.y);
  h2_controller_pitch_B.y_c[2] = -static_cast<real_T>
    (h2_controller_pitch_B.In1_n.z);

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S17>/Data Type Conversion1'

  h2_controller_pitch_B.y_p[0] = -static_cast<real_T>
    (h2_controller_pitch_B.In1_i.x);
  h2_controller_pitch_B.y_p[1] = h2_controller_pitch_B.In1_i.y;
  h2_controller_pitch_B.y_p[2] = h2_controller_pitch_B.In1_i.z;

  // Gain: '<S17>/Gain1'
  h2_controller_pitch_B.Sum23_g = h2_controller_pitch_B.y_c[0];
  h2_controller_pitch_B.tth = h2_controller_pitch_B.y_c[1];
  h2_controller_pitch_B.wq1 = h2_controller_pitch_B.y_c[2];

  // Gain: '<S17>/Gain'
  h2_controller_pitch_B.wr1 = h2_controller_pitch_B.y_p[0];
  h2_controller_pitch_B.cph = h2_controller_pitch_B.y_p[1];
  h2_controller_pitch_B.cth = h2_controller_pitch_B.y_p[2];
  for (i = 0; i < 3; i++) {
    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.sph = h2_controller_pitch_P.Rz[i];

    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.ph_meas = h2_controller_pitch_B.sph *
      h2_controller_pitch_B.Sum23_g;

    // Gain: '<S17>/Gain'
    h2_controller_pitch_B.Pt_f = h2_controller_pitch_B.sph *
      h2_controller_pitch_B.wr1;

    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.sph = h2_controller_pitch_P.Rz[i + 3];

    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.ph_meas += h2_controller_pitch_B.sph *
      h2_controller_pitch_B.tth;

    // Gain: '<S17>/Gain'
    h2_controller_pitch_B.Pt_f += h2_controller_pitch_B.sph *
      h2_controller_pitch_B.cph;

    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.sph = h2_controller_pitch_P.Rz[i + 6];

    // Gain: '<S17>/Gain'
    h2_controller_pitch_B.TmpSignalConversionAtSFunct[i] =
      h2_controller_pitch_B.sph * h2_controller_pitch_B.cth +
      h2_controller_pitch_B.Pt_f;

    // Gain: '<S17>/Gain1'
    h2_controller_pitch_B.u_vect[i] = h2_controller_pitch_B.sph *
      h2_controller_pitch_B.wq1 + h2_controller_pitch_B.ph_meas;
  }

  // MATLAB Function: '<S4>/MATLAB Function1'
  h2_controller_p_MATLABFunction1(h2_controller_pitch_B.Gain_e,
    &h2_controller_pitch_B.y1_j, &h2_controller_pitch_B.y2_pc,
    &h2_controller_pitch_B.y3_l, &h2_controller_pitch_DW.sf_MATLABFunction1_i);

  // MATLAB Function: '<S20>/MATLAB Function7'
  h2_controller_p_MATLABFunction1(h2_controller_pitch_B.Gain2_a,
    &h2_controller_pitch_B.y1_b, &h2_controller_pitch_B.y2_p,
    &h2_controller_pitch_B.y3_g, &h2_controller_pitch_DW.sf_MATLABFunction7);

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/failsafe'

  for (i = 0; i < 8; i++) {
    h2_controller_pitch_B.pwmValue[i] = 0U;
  }

  h2_controller_pitch_B.pwmValue[0] = rtb_CastU16En16;
  h2_controller_pitch_B.pwmValue[1] = rtb_DataTypeConversion1_c;
  h2_controller_pitch_B.pwmValue[2] = rtb_DataTypeConversion1_p;
  h2_controller_pitch_B.pwmValue[3] = rtb_DataTypeConversion1_f;
  if (rtb_startingswitch) {
    if (!h2_controller_pitch_DW.obj.isArmed) {
      h2_controller_pitch_DW.obj.isArmed = true;
      rtb_CastU16En16 = pwm_arm(&h2_controller_pitch_DW.obj.pwmDevHandler,
        &h2_controller_pitch_DW.obj.armAdvertiseObj);
      h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (h2_controller_pitch_DW.obj.errorStatus | rtb_CastU16En16);
    }

    rtb_CastU16En16 = pwm_setServo(&h2_controller_pitch_DW.obj.pwmDevHandler,
      h2_controller_pitch_DW.obj.servoCount,
      h2_controller_pitch_DW.obj.channelMask, &h2_controller_pitch_B.pwmValue[0],
      h2_controller_pitch_DW.obj.isMain,
      &h2_controller_pitch_DW.obj.actuatorAdvertiseObj);
    h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (h2_controller_pitch_DW.obj.errorStatus | rtb_CastU16En16);
  } else {
    rtb_CastU16En16 = pwm_disarm(&h2_controller_pitch_DW.obj.pwmDevHandler,
      &h2_controller_pitch_DW.obj.armAdvertiseObj);
    h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (h2_controller_pitch_DW.obj.errorStatus | rtb_CastU16En16);
    h2_controller_pitch_DW.obj.isArmed = false;
    rtb_CastU16En16 = pwm_resetServo(&h2_controller_pitch_DW.obj.pwmDevHandler,
      h2_controller_pitch_DW.obj.servoCount,
      h2_controller_pitch_DW.obj.channelMask, h2_controller_pitch_DW.obj.isMain,
      &h2_controller_pitch_DW.obj.actuatorAdvertiseObj);
    h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (h2_controller_pitch_DW.obj.errorStatus | rtb_CastU16En16);
  }

  if (h2_controller_pitch_DW.obj.isMain) {
    rtb_CastU16En16 = pwm_forceFailsafe
      (&h2_controller_pitch_DW.obj.pwmDevHandler, static_cast<int32_T>
       (h2_controller_pitch_P.failsafe_Value));
    h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (h2_controller_pitch_DW.obj.errorStatus | rtb_CastU16En16);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'
  // Sum: '<S1>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1'

  h2_controller_pitch_B.Sum2_h =
    h2_controller_pitch_P.DiscreteTransferFcn1_NumCoef_n *
    h2_controller_pitch_DW.DiscreteTransferFcn1_states_p -
    h2_controller_pitch_B.Gain2;

  // MATLABSystem: '<S6>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(h2_controller_pitch_DW.obj_d.orbMetadataObj,
    &h2_controller_pitch_DW.obj_d.eventStructObj,
    &h2_controller_pitch_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S48>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S48>/In1'
    h2_controller_pitch_B.In1_h = h2_controller_pitch_B.b_varargout_2_c;
    srUpdateBC(h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  h2_controller_pitch_B.SignalConversion[0] =
    h2_controller_pitch_B.In1_h.output[0];
  h2_controller_pitch_B.SignalConversion[1] =
    h2_controller_pitch_B.In1_h.output[1];
  h2_controller_pitch_B.SignalConversion[2] =
    h2_controller_pitch_B.In1_h.output[2];
  h2_controller_pitch_B.SignalConversion[3] =
    h2_controller_pitch_B.In1_h.output[3];

  // Update for Delay: '<S1>/Delay3' incorporates:
  //   MATLAB Function: '<S1>/MATLAB Function1'

  h2_controller_pitch_DW.Delay3_DSTATE = h2_controller_pitch_B.Delay2_DSTATE_m -
    h2_controller_pitch_B.Delay2_DSTATE;

  // Update for DiscreteStateSpace: '<S11>/Internal'
  {
    h2_controller_pitch_DW.Internal_DSTATE = h2_controller_pitch_B.Sum2_h +
      h2_controller_pitch_P.Internal_A*h2_controller_pitch_DW.Internal_DSTATE;
  }

  // Update for Delay: '<S1>/Delay2'
  h2_controller_pitch_DW.Delay2_DSTATE[0] = h2_controller_pitch_B.x[0];
  h2_controller_pitch_DW.Delay2_DSTATE[1] = h2_controller_pitch_B.x[1];
  h2_controller_pitch_DW.Delay2_DSTATE[2] = h2_controller_pitch_B.x[2];
  h2_controller_pitch_DW.Delay2_DSTATE[3] = h2_controller_pitch_B.x[3];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'

  h2_controller_pitch_DW.DiscreteTransferFcn_states =
    (h2_controller_pitch_P.DiscreteTransferFcn_NumCoef_gv *
     h2_controller_pitch_DW.DiscreteTransferFcn_states_f -
     h2_controller_pitch_P.DiscreteTransferFcn_DenCoef[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn_states) /
    h2_controller_pitch_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'

  h2_controller_pitch_DW.DiscreteTransferFcn1_states =
    (h2_controller_pitch_P.DiscreteTransferFcn1_NumCoef_o *
     h2_controller_pitch_DW.DiscreteTransferFcn1_states_d -
     h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn1_states) /
    h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'

  h2_controller_pitch_DW.DiscreteTransferFcn2_states =
    (h2_controller_pitch_P.DiscreteTransferFcn2_NumCoef_g *
     h2_controller_pitch_DW.DiscreteTransferFcn2_states_p2 -
     h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn2_states) /
    h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S26>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'

  h2_controller_pitch_DW.Delay_DSTATE_p[0] =
    h2_controller_pitch_B.Delay2_DSTATE_pp;
  h2_controller_pitch_DW.Delay_DSTATE_p[1] = h2_controller_pitch_B.x_g;
  h2_controller_pitch_DW.Delay_DSTATE_p[2] = h2_controller_pitch_B.y;

  // Update for Delay: '<S30>/Delay23' incorporates:
  //   Delay: '<S30>/Delay22'
  //
  h2_controller_pitch_DW.Delay23_DSTATE[0] =
    h2_controller_pitch_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S30>/Delay22' incorporates:
  //   Delay: '<S30>/Delay21'
  //
  h2_controller_pitch_DW.Delay22_DSTATE[0] =
    h2_controller_pitch_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S30>/Delay21' incorporates:
  //   Delay: '<S30>/Delay20'
  //
  h2_controller_pitch_DW.Delay21_DSTATE[0] =
    h2_controller_pitch_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S30>/Delay20' incorporates:
  //   Delay: '<S30>/Delay14'
  //
  h2_controller_pitch_DW.Delay20_DSTATE[0] =
    h2_controller_pitch_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S30>/Delay14' incorporates:
  //   Delay: '<S30>/Delay13'
  //
  h2_controller_pitch_DW.Delay14_DSTATE[0] =
    h2_controller_pitch_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S30>/Delay13' incorporates:
  //   Delay: '<S30>/Delay12'
  //
  h2_controller_pitch_DW.Delay13_DSTATE[0] =
    h2_controller_pitch_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S30>/Delay12' incorporates:
  //   Delay: '<S30>/Delay11'
  //
  h2_controller_pitch_DW.Delay12_DSTATE[0] =
    h2_controller_pitch_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S30>/Delay11' incorporates:
  //   Delay: '<S30>/Delay10'
  //
  h2_controller_pitch_DW.Delay11_DSTATE[0] =
    h2_controller_pitch_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S30>/Delay10' incorporates:
  //   Delay: '<S30>/Delay9'
  //
  h2_controller_pitch_DW.Delay10_DSTATE[0] =
    h2_controller_pitch_DW.Delay9_DSTATE[0];

  // Update for Delay: '<S30>/Delay9' incorporates:
  //   Delay: '<S30>/Delay8'
  //
  h2_controller_pitch_DW.Delay9_DSTATE[0] =
    h2_controller_pitch_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S30>/Delay8' incorporates:
  //   Delay: '<S30>/Delay7'
  //
  h2_controller_pitch_DW.Delay8_DSTATE[0] =
    h2_controller_pitch_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S30>/Delay7' incorporates:
  //   Delay: '<S30>/Delay6'
  //
  h2_controller_pitch_DW.Delay7_DSTATE[0] =
    h2_controller_pitch_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S30>/Delay6' incorporates:
  //   Delay: '<S30>/Delay5'
  //
  h2_controller_pitch_DW.Delay6_DSTATE[0] =
    h2_controller_pitch_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S30>/Delay5' incorporates:
  //   Delay: '<S30>/Delay4'
  //
  h2_controller_pitch_DW.Delay5_DSTATE[0] =
    h2_controller_pitch_DW.Delay4_DSTATE[0];

  // Update for Delay: '<S30>/Delay4' incorporates:
  //   Delay: '<S30>/Delay3'
  //
  h2_controller_pitch_DW.Delay4_DSTATE[0] =
    h2_controller_pitch_DW.Delay3_DSTATE_d[0];

  // Update for Delay: '<S30>/Delay3' incorporates:
  //   Delay: '<S30>/Delay2'
  //
  h2_controller_pitch_DW.Delay3_DSTATE_d[0] =
    h2_controller_pitch_DW.Delay2_DSTATE_i[0];

  // Update for Delay: '<S30>/Delay2' incorporates:
  //   Delay: '<S30>/Delay1'
  //
  h2_controller_pitch_DW.Delay2_DSTATE_i[0] =
    h2_controller_pitch_DW.Delay1_DSTATE[0];

  // Update for Delay: '<S30>/Delay1' incorporates:
  //   Delay: '<S30>/Delay'
  //
  h2_controller_pitch_DW.Delay1_DSTATE[0] = h2_controller_pitch_DW.Delay_DSTATE
    [0];

  // Update for Delay: '<S30>/Delay'
  h2_controller_pitch_DW.Delay_DSTATE[0] = h2_controller_pitch_B.y_idx_0;

  // Update for Delay: '<S26>/Delay1'
  h2_controller_pitch_DW.Delay1_DSTATE_p[0] =
    h2_controller_pitch_B.rtb_Delay_l_idx_0;

  // Update for Delay: '<S26>/Delay2'
  h2_controller_pitch_DW.Delay2_DSTATE_p[0] =
    h2_controller_pitch_B.rtb_Delay1_n_idx_0;

  // Update for Delay: '<S26>/Delay3'
  h2_controller_pitch_DW.Delay3_DSTATE_j[0] =
    h2_controller_pitch_B.rtb_Delay2_h_idx_0;

  // Update for Delay: '<S26>/Delay4'
  h2_controller_pitch_DW.Delay4_DSTATE_e[0] =
    h2_controller_pitch_B.rtb_Delay3_p_idx_0;

  // Update for Delay: '<S26>/Delay5'
  h2_controller_pitch_DW.Delay5_DSTATE_p[0] =
    h2_controller_pitch_B.rtb_Delay4_j_idx_0;

  // Update for Delay: '<S26>/Delay6'
  h2_controller_pitch_DW.Delay6_DSTATE_p[0] =
    h2_controller_pitch_B.rtb_Delay5_e_idx_0;

  // Update for Delay: '<S26>/Delay7'
  h2_controller_pitch_DW.Delay7_DSTATE_o[0] =
    h2_controller_pitch_B.rtb_Delay6_f_idx_0;

  // Update for Delay: '<S26>/Delay8'
  h2_controller_pitch_DW.Delay8_DSTATE_n[0] =
    h2_controller_pitch_B.rtb_Delay7_i_idx_0;

  // Update for Delay: '<S26>/Delay9'
  h2_controller_pitch_DW.Delay9_DSTATE_i[0] =
    h2_controller_pitch_B.rtb_Delay8_j_idx_0;

  // Update for Delay: '<S26>/Delay10'
  h2_controller_pitch_DW.Delay10_DSTATE_f[0] =
    h2_controller_pitch_B.rtb_Delay9_j_idx_0;

  // Update for Delay: '<S26>/Delay11'
  h2_controller_pitch_DW.Delay11_DSTATE_k[0] =
    h2_controller_pitch_B.rtb_Delay10_e_idx_0;

  // Update for Delay: '<S26>/Delay12'
  h2_controller_pitch_DW.Delay12_DSTATE_n[0] =
    h2_controller_pitch_B.rtb_Delay11_n_idx_0;

  // Update for Delay: '<S26>/Delay13'
  h2_controller_pitch_DW.Delay13_DSTATE_g[0] =
    h2_controller_pitch_B.rtb_Delay12_a_idx_0;

  // Update for Delay: '<S26>/Delay14'
  h2_controller_pitch_DW.Delay14_DSTATE_g[0] =
    h2_controller_pitch_B.rtb_Delay13_h_idx_0;

  // Update for Delay: '<S26>/Delay15'
  h2_controller_pitch_DW.Delay15_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay14_m_idx_0;

  // Update for Delay: '<S26>/Delay20'
  h2_controller_pitch_DW.Delay20_DSTATE_h[0] =
    h2_controller_pitch_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S26>/Delay21'
  h2_controller_pitch_DW.Delay21_DSTATE_d[0] =
    h2_controller_pitch_B.rtb_Delay20_g_idx_0;

  // Update for Delay: '<S26>/Delay22'
  h2_controller_pitch_DW.Delay22_DSTATE_h[0] =
    h2_controller_pitch_B.rtb_Delay21_e_idx_0;

  // Update for Delay: '<S26>/Delay23'
  h2_controller_pitch_DW.Delay23_DSTATE_p[0] =
    h2_controller_pitch_B.rtb_Delay22_b_idx_0;

  // Update for Delay: '<S26>/Delay24'
  h2_controller_pitch_DW.Delay24_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay23_g_idx_0;

  // Update for Delay: '<S26>/Delay25'
  h2_controller_pitch_DW.Delay25_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S26>/Delay26'
  h2_controller_pitch_DW.Delay26_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S26>/Delay27'
  h2_controller_pitch_DW.Delay27_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S26>/Delay16'
  h2_controller_pitch_DW.Delay16_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S26>/Delay17'
  h2_controller_pitch_DW.Delay17_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S26>/Delay18'
  h2_controller_pitch_DW.Delay18_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S26>/Delay19'
  h2_controller_pitch_DW.Delay19_DSTATE[0] =
    h2_controller_pitch_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S28>/Delay2' incorporates:
  //   Delay: '<S31>/Delay2'

  h2_controller_pitch_DW.Delay2_DSTATE_l[0] =
    h2_controller_pitch_DW.Delay2_DSTATE_n[0];

  // Update for Delay: '<S30>/Delay23' incorporates:
  //   Delay: '<S30>/Delay22'
  //
  h2_controller_pitch_DW.Delay23_DSTATE[1] =
    h2_controller_pitch_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S30>/Delay22' incorporates:
  //   Delay: '<S30>/Delay21'
  //
  h2_controller_pitch_DW.Delay22_DSTATE[1] =
    h2_controller_pitch_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S30>/Delay21' incorporates:
  //   Delay: '<S30>/Delay20'
  //
  h2_controller_pitch_DW.Delay21_DSTATE[1] =
    h2_controller_pitch_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S30>/Delay20' incorporates:
  //   Delay: '<S30>/Delay14'
  //
  h2_controller_pitch_DW.Delay20_DSTATE[1] =
    h2_controller_pitch_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S30>/Delay14' incorporates:
  //   Delay: '<S30>/Delay13'
  //
  h2_controller_pitch_DW.Delay14_DSTATE[1] =
    h2_controller_pitch_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S30>/Delay13' incorporates:
  //   Delay: '<S30>/Delay12'
  //
  h2_controller_pitch_DW.Delay13_DSTATE[1] =
    h2_controller_pitch_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S30>/Delay12' incorporates:
  //   Delay: '<S30>/Delay11'
  //
  h2_controller_pitch_DW.Delay12_DSTATE[1] =
    h2_controller_pitch_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S30>/Delay11' incorporates:
  //   Delay: '<S30>/Delay10'
  //
  h2_controller_pitch_DW.Delay11_DSTATE[1] =
    h2_controller_pitch_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S30>/Delay10' incorporates:
  //   Delay: '<S30>/Delay9'
  //
  h2_controller_pitch_DW.Delay10_DSTATE[1] =
    h2_controller_pitch_DW.Delay9_DSTATE[1];

  // Update for Delay: '<S30>/Delay9' incorporates:
  //   Delay: '<S30>/Delay8'
  //
  h2_controller_pitch_DW.Delay9_DSTATE[1] =
    h2_controller_pitch_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S30>/Delay8' incorporates:
  //   Delay: '<S30>/Delay7'
  //
  h2_controller_pitch_DW.Delay8_DSTATE[1] =
    h2_controller_pitch_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S30>/Delay7' incorporates:
  //   Delay: '<S30>/Delay6'
  //
  h2_controller_pitch_DW.Delay7_DSTATE[1] =
    h2_controller_pitch_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S30>/Delay6' incorporates:
  //   Delay: '<S30>/Delay5'
  //
  h2_controller_pitch_DW.Delay6_DSTATE[1] =
    h2_controller_pitch_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S30>/Delay5' incorporates:
  //   Delay: '<S30>/Delay4'
  //
  h2_controller_pitch_DW.Delay5_DSTATE[1] =
    h2_controller_pitch_DW.Delay4_DSTATE[1];

  // Update for Delay: '<S30>/Delay4' incorporates:
  //   Delay: '<S30>/Delay3'
  //
  h2_controller_pitch_DW.Delay4_DSTATE[1] =
    h2_controller_pitch_DW.Delay3_DSTATE_d[1];

  // Update for Delay: '<S30>/Delay3' incorporates:
  //   Delay: '<S30>/Delay2'
  //
  h2_controller_pitch_DW.Delay3_DSTATE_d[1] =
    h2_controller_pitch_DW.Delay2_DSTATE_i[1];

  // Update for Delay: '<S30>/Delay2' incorporates:
  //   Delay: '<S30>/Delay1'
  //
  h2_controller_pitch_DW.Delay2_DSTATE_i[1] =
    h2_controller_pitch_DW.Delay1_DSTATE[1];

  // Update for Delay: '<S30>/Delay1' incorporates:
  //   Delay: '<S30>/Delay'
  //
  h2_controller_pitch_DW.Delay1_DSTATE[1] = h2_controller_pitch_DW.Delay_DSTATE
    [1];

  // Update for Delay: '<S30>/Delay'
  h2_controller_pitch_DW.Delay_DSTATE[1] = h2_controller_pitch_B.y_idx_1;

  // Update for Delay: '<S26>/Delay1'
  h2_controller_pitch_DW.Delay1_DSTATE_p[1] =
    h2_controller_pitch_B.rtb_Delay_l_idx_1;

  // Update for Delay: '<S26>/Delay2'
  h2_controller_pitch_DW.Delay2_DSTATE_p[1] =
    h2_controller_pitch_B.rtb_Delay1_n_idx_1;

  // Update for Delay: '<S26>/Delay3'
  h2_controller_pitch_DW.Delay3_DSTATE_j[1] =
    h2_controller_pitch_B.rtb_Delay2_h_idx_1;

  // Update for Delay: '<S26>/Delay4'
  h2_controller_pitch_DW.Delay4_DSTATE_e[1] =
    h2_controller_pitch_B.rtb_Delay3_p_idx_1;

  // Update for Delay: '<S26>/Delay5'
  h2_controller_pitch_DW.Delay5_DSTATE_p[1] =
    h2_controller_pitch_B.rtb_Delay4_j_idx_1;

  // Update for Delay: '<S26>/Delay6'
  h2_controller_pitch_DW.Delay6_DSTATE_p[1] =
    h2_controller_pitch_B.rtb_Delay5_e_idx_1;

  // Update for Delay: '<S26>/Delay7'
  h2_controller_pitch_DW.Delay7_DSTATE_o[1] =
    h2_controller_pitch_B.rtb_Delay6_f_idx_1;

  // Update for Delay: '<S26>/Delay8'
  h2_controller_pitch_DW.Delay8_DSTATE_n[1] =
    h2_controller_pitch_B.rtb_Delay7_i_idx_1;

  // Update for Delay: '<S26>/Delay9'
  h2_controller_pitch_DW.Delay9_DSTATE_i[1] =
    h2_controller_pitch_B.rtb_Delay8_j_idx_1;

  // Update for Delay: '<S26>/Delay10'
  h2_controller_pitch_DW.Delay10_DSTATE_f[1] =
    h2_controller_pitch_B.rtb_Delay9_j_idx_1;

  // Update for Delay: '<S26>/Delay11'
  h2_controller_pitch_DW.Delay11_DSTATE_k[1] =
    h2_controller_pitch_B.rtb_Delay10_e_idx_1;

  // Update for Delay: '<S26>/Delay12'
  h2_controller_pitch_DW.Delay12_DSTATE_n[1] =
    h2_controller_pitch_B.rtb_Delay11_n_idx_1;

  // Update for Delay: '<S26>/Delay13'
  h2_controller_pitch_DW.Delay13_DSTATE_g[1] =
    h2_controller_pitch_B.rtb_Delay12_a_idx_1;

  // Update for Delay: '<S26>/Delay14'
  h2_controller_pitch_DW.Delay14_DSTATE_g[1] =
    h2_controller_pitch_B.rtb_Delay13_h_idx_1;

  // Update for Delay: '<S26>/Delay15'
  h2_controller_pitch_DW.Delay15_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay14_m_idx_1;

  // Update for Delay: '<S26>/Delay20'
  h2_controller_pitch_DW.Delay20_DSTATE_h[1] =
    h2_controller_pitch_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S26>/Delay21'
  h2_controller_pitch_DW.Delay21_DSTATE_d[1] =
    h2_controller_pitch_B.rtb_Delay20_g_idx_1;

  // Update for Delay: '<S26>/Delay22'
  h2_controller_pitch_DW.Delay22_DSTATE_h[1] =
    h2_controller_pitch_B.rtb_Delay21_e_idx_1;

  // Update for Delay: '<S26>/Delay23'
  h2_controller_pitch_DW.Delay23_DSTATE_p[1] =
    h2_controller_pitch_B.rtb_Delay22_b_idx_1;

  // Update for Delay: '<S26>/Delay24'
  h2_controller_pitch_DW.Delay24_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay23_g_idx_1;

  // Update for Delay: '<S26>/Delay25'
  h2_controller_pitch_DW.Delay25_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S26>/Delay26'
  h2_controller_pitch_DW.Delay26_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S26>/Delay27'
  h2_controller_pitch_DW.Delay27_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S26>/Delay16'
  h2_controller_pitch_DW.Delay16_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S26>/Delay17'
  h2_controller_pitch_DW.Delay17_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S26>/Delay18'
  h2_controller_pitch_DW.Delay18_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S26>/Delay19'
  h2_controller_pitch_DW.Delay19_DSTATE[1] =
    h2_controller_pitch_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S28>/Delay2' incorporates:
  //   Delay: '<S31>/Delay2'

  h2_controller_pitch_DW.Delay2_DSTATE_l[1] =
    h2_controller_pitch_DW.Delay2_DSTATE_n[1];

  // Update for Delay: '<S30>/Delay23' incorporates:
  //   Delay: '<S30>/Delay22'
  //
  h2_controller_pitch_DW.Delay23_DSTATE[2] =
    h2_controller_pitch_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S30>/Delay22' incorporates:
  //   Delay: '<S30>/Delay21'
  //
  h2_controller_pitch_DW.Delay22_DSTATE[2] =
    h2_controller_pitch_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S30>/Delay21' incorporates:
  //   Delay: '<S30>/Delay20'
  //
  h2_controller_pitch_DW.Delay21_DSTATE[2] =
    h2_controller_pitch_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S30>/Delay20' incorporates:
  //   Delay: '<S30>/Delay14'
  //
  h2_controller_pitch_DW.Delay20_DSTATE[2] =
    h2_controller_pitch_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S30>/Delay14' incorporates:
  //   Delay: '<S30>/Delay13'
  //
  h2_controller_pitch_DW.Delay14_DSTATE[2] =
    h2_controller_pitch_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S30>/Delay13' incorporates:
  //   Delay: '<S30>/Delay12'
  //
  h2_controller_pitch_DW.Delay13_DSTATE[2] =
    h2_controller_pitch_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S30>/Delay12' incorporates:
  //   Delay: '<S30>/Delay11'
  //
  h2_controller_pitch_DW.Delay12_DSTATE[2] =
    h2_controller_pitch_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S30>/Delay11' incorporates:
  //   Delay: '<S30>/Delay10'
  //
  h2_controller_pitch_DW.Delay11_DSTATE[2] =
    h2_controller_pitch_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S30>/Delay10' incorporates:
  //   Delay: '<S30>/Delay9'
  //
  h2_controller_pitch_DW.Delay10_DSTATE[2] =
    h2_controller_pitch_DW.Delay9_DSTATE[2];

  // Update for Delay: '<S30>/Delay9' incorporates:
  //   Delay: '<S30>/Delay8'
  //
  h2_controller_pitch_DW.Delay9_DSTATE[2] =
    h2_controller_pitch_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S30>/Delay8' incorporates:
  //   Delay: '<S30>/Delay7'
  //
  h2_controller_pitch_DW.Delay8_DSTATE[2] =
    h2_controller_pitch_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S30>/Delay7' incorporates:
  //   Delay: '<S30>/Delay6'
  //
  h2_controller_pitch_DW.Delay7_DSTATE[2] =
    h2_controller_pitch_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S30>/Delay6' incorporates:
  //   Delay: '<S30>/Delay5'
  //
  h2_controller_pitch_DW.Delay6_DSTATE[2] =
    h2_controller_pitch_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S30>/Delay5' incorporates:
  //   Delay: '<S30>/Delay4'
  //
  h2_controller_pitch_DW.Delay5_DSTATE[2] =
    h2_controller_pitch_DW.Delay4_DSTATE[2];

  // Update for Delay: '<S30>/Delay4' incorporates:
  //   Delay: '<S30>/Delay3'
  //
  h2_controller_pitch_DW.Delay4_DSTATE[2] =
    h2_controller_pitch_DW.Delay3_DSTATE_d[2];

  // Update for Delay: '<S30>/Delay3' incorporates:
  //   Delay: '<S30>/Delay2'
  //
  h2_controller_pitch_DW.Delay3_DSTATE_d[2] =
    h2_controller_pitch_DW.Delay2_DSTATE_i[2];

  // Update for Delay: '<S30>/Delay2' incorporates:
  //   Delay: '<S30>/Delay1'
  //
  h2_controller_pitch_DW.Delay2_DSTATE_i[2] =
    h2_controller_pitch_DW.Delay1_DSTATE[2];

  // Update for Delay: '<S30>/Delay1' incorporates:
  //   Delay: '<S30>/Delay'
  //
  h2_controller_pitch_DW.Delay1_DSTATE[2] = h2_controller_pitch_DW.Delay_DSTATE
    [2];

  // Update for Delay: '<S30>/Delay'
  h2_controller_pitch_DW.Delay_DSTATE[2] = h2_controller_pitch_B.Delay2_DSTATE_n;

  // Update for Delay: '<S26>/Delay1' incorporates:
  //   Delay: '<S26>/Delay'

  h2_controller_pitch_DW.Delay1_DSTATE_p[2] =
    h2_controller_pitch_B.Delay_DSTATE_p;

  // Update for Delay: '<S26>/Delay2' incorporates:
  //   Delay: '<S26>/Delay1'

  h2_controller_pitch_DW.Delay2_DSTATE_p[2] =
    h2_controller_pitch_B.Delay1_DSTATE_p;

  // Update for Delay: '<S26>/Delay3' incorporates:
  //   Delay: '<S26>/Delay2'

  h2_controller_pitch_DW.Delay3_DSTATE_j[2] =
    h2_controller_pitch_B.Delay2_DSTATE_p;

  // Update for Delay: '<S26>/Delay4' incorporates:
  //   Delay: '<S26>/Delay3'

  h2_controller_pitch_DW.Delay4_DSTATE_e[2] =
    h2_controller_pitch_B.Delay3_DSTATE_j;

  // Update for Delay: '<S26>/Delay5' incorporates:
  //   Delay: '<S26>/Delay4'

  h2_controller_pitch_DW.Delay5_DSTATE_p[2] =
    h2_controller_pitch_B.Delay4_DSTATE_e;

  // Update for Delay: '<S26>/Delay6' incorporates:
  //   Delay: '<S26>/Delay5'

  h2_controller_pitch_DW.Delay6_DSTATE_p[2] =
    h2_controller_pitch_B.Delay5_DSTATE_p;

  // Update for Delay: '<S26>/Delay7' incorporates:
  //   Delay: '<S26>/Delay6'

  h2_controller_pitch_DW.Delay7_DSTATE_o[2] =
    h2_controller_pitch_B.Delay6_DSTATE_p;

  // Update for Delay: '<S26>/Delay8' incorporates:
  //   Delay: '<S26>/Delay7'

  h2_controller_pitch_DW.Delay8_DSTATE_n[2] =
    h2_controller_pitch_B.Delay7_DSTATE_o;

  // Update for Delay: '<S26>/Delay9' incorporates:
  //   Delay: '<S26>/Delay8'

  h2_controller_pitch_DW.Delay9_DSTATE_i[2] =
    h2_controller_pitch_B.Delay8_DSTATE_n;

  // Update for Delay: '<S26>/Delay10' incorporates:
  //   Delay: '<S26>/Delay9'

  h2_controller_pitch_DW.Delay10_DSTATE_f[2] =
    h2_controller_pitch_B.Delay9_DSTATE_i;

  // Update for Delay: '<S26>/Delay11' incorporates:
  //   Delay: '<S26>/Delay10'

  h2_controller_pitch_DW.Delay11_DSTATE_k[2] =
    h2_controller_pitch_B.Delay10_DSTATE_f;

  // Update for Delay: '<S26>/Delay12' incorporates:
  //   Delay: '<S26>/Delay11'

  h2_controller_pitch_DW.Delay12_DSTATE_n[2] =
    h2_controller_pitch_B.Delay11_DSTATE_k;

  // Update for Delay: '<S26>/Delay13' incorporates:
  //   Delay: '<S26>/Delay12'

  h2_controller_pitch_DW.Delay13_DSTATE_g[2] =
    h2_controller_pitch_B.Delay12_DSTATE_n;

  // Update for Delay: '<S26>/Delay14' incorporates:
  //   Delay: '<S26>/Delay13'

  h2_controller_pitch_DW.Delay14_DSTATE_g[2] =
    h2_controller_pitch_B.Delay13_DSTATE_g;

  // Update for Delay: '<S26>/Delay15' incorporates:
  //   Delay: '<S26>/Delay14'

  h2_controller_pitch_DW.Delay15_DSTATE[2] =
    h2_controller_pitch_B.Delay14_DSTATE_g;

  // Update for Delay: '<S26>/Delay20' incorporates:
  //   Delay: '<S26>/Delay15'

  h2_controller_pitch_DW.Delay20_DSTATE_h[2] =
    h2_controller_pitch_B.Delay15_DSTATE;

  // Update for Delay: '<S26>/Delay21' incorporates:
  //   Delay: '<S26>/Delay20'

  h2_controller_pitch_DW.Delay21_DSTATE_d[2] =
    h2_controller_pitch_B.Delay20_DSTATE_h;

  // Update for Delay: '<S26>/Delay22' incorporates:
  //   Delay: '<S26>/Delay21'

  h2_controller_pitch_DW.Delay22_DSTATE_h[2] =
    h2_controller_pitch_B.Delay21_DSTATE_d;

  // Update for Delay: '<S26>/Delay23' incorporates:
  //   Delay: '<S26>/Delay22'

  h2_controller_pitch_DW.Delay23_DSTATE_p[2] =
    h2_controller_pitch_B.Delay22_DSTATE_h;

  // Update for Delay: '<S26>/Delay24' incorporates:
  //   Delay: '<S26>/Delay23'

  h2_controller_pitch_DW.Delay24_DSTATE[2] =
    h2_controller_pitch_B.Delay23_DSTATE_p;

  // Update for Delay: '<S26>/Delay25' incorporates:
  //   Delay: '<S26>/Delay24'

  h2_controller_pitch_DW.Delay25_DSTATE[2] =
    h2_controller_pitch_B.Delay24_DSTATE;

  // Update for Delay: '<S26>/Delay26' incorporates:
  //   Delay: '<S26>/Delay25'

  h2_controller_pitch_DW.Delay26_DSTATE[2] =
    h2_controller_pitch_B.Delay25_DSTATE;

  // Update for Delay: '<S26>/Delay27' incorporates:
  //   Delay: '<S26>/Delay26'

  h2_controller_pitch_DW.Delay27_DSTATE[2] =
    h2_controller_pitch_B.Delay26_DSTATE;

  // Update for Delay: '<S26>/Delay16' incorporates:
  //   Delay: '<S26>/Delay27'

  h2_controller_pitch_DW.Delay16_DSTATE[2] =
    h2_controller_pitch_B.Delay27_DSTATE;

  // Update for Delay: '<S26>/Delay17' incorporates:
  //   Delay: '<S26>/Delay16'

  h2_controller_pitch_DW.Delay17_DSTATE[2] =
    h2_controller_pitch_B.Delay16_DSTATE;

  // Update for Delay: '<S26>/Delay18' incorporates:
  //   Delay: '<S26>/Delay17'

  h2_controller_pitch_DW.Delay18_DSTATE[2] =
    h2_controller_pitch_B.Delay17_DSTATE;

  // Update for Delay: '<S26>/Delay19' incorporates:
  //   Delay: '<S26>/Delay18'

  h2_controller_pitch_DW.Delay19_DSTATE[2] =
    h2_controller_pitch_B.Delay18_DSTATE;

  // Update for Delay: '<S28>/Delay2' incorporates:
  //   Delay: '<S31>/Delay2'

  h2_controller_pitch_DW.Delay2_DSTATE_l[2] =
    h2_controller_pitch_DW.Delay2_DSTATE_n[2];

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn'
  h2_controller_pitch_DW.DiscreteTransferFcn_states_a =
    (h2_controller_pitch_B.u_vect[0] -
     h2_controller_pitch_P.DiscreteTransferFcn_DenCoef_j[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn_states_a) /
    h2_controller_pitch_P.DiscreteTransferFcn_DenCoef_j[0];

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1'
  h2_controller_pitch_DW.DiscreteTransferFcn1_states_e =
    (h2_controller_pitch_B.u_vect[1] -
     h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_o[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn1_states_e) /
    h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_o[0];

  // Update for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2'
  h2_controller_pitch_DW.DiscreteTransferFcn2_states_p =
    (h2_controller_pitch_B.u_vect[2] -
     h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef_i[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn2_states_p) /
    h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1'
  h2_controller_pitch_DW.DiscreteTransferFcn1_states_p =
    (h2_controller_pitch_B.a21 -
     h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_g[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn1_states_p) /
    h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_g[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  h2_controller_pitch_DW.DiscreteTransferFcn_states_f =
    (h2_controller_pitch_B.TmpSignalConversionAtSFunct[0] -
     h2_controller_pitch_P.DiscreteTransferFcn_DenCoef_i[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn_states_f) /
    h2_controller_pitch_P.DiscreteTransferFcn_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  h2_controller_pitch_DW.DiscreteTransferFcn1_states_d =
    (h2_controller_pitch_B.TmpSignalConversionAtSFunct[1] -
     h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_m[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn1_states_d) /
    h2_controller_pitch_P.DiscreteTransferFcn1_DenCoef_m[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
  h2_controller_pitch_DW.DiscreteTransferFcn2_states_p2 =
    (h2_controller_pitch_B.TmpSignalConversionAtSFunct[2] -
     h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef_e[1] *
     h2_controller_pitch_DW.DiscreteTransferFcn2_states_p2) /
    h2_controller_pitch_P.DiscreteTransferFcn2_DenCoef_e[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  h2_controller_pitch_M->Timing.taskTime0 =
    ((time_T)(++h2_controller_pitch_M->Timing.clockTick0)) *
    h2_controller_pitch_M->Timing.stepSize0;
}

// Model initialize function
void h2_controller_pitch_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(h2_controller_pitch_M, -1);
  h2_controller_pitch_M->Timing.stepSize0 = 0.01;

  // External mode info
  h2_controller_pitch_M->Sizes.checksums[0] = (3833488621U);
  h2_controller_pitch_M->Sizes.checksums[1] = (2992074858U);
  h2_controller_pitch_M->Sizes.checksums[2] = (2554512723U);
  h2_controller_pitch_M->Sizes.checksums[3] = (1528909796U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[42];
    h2_controller_pitch_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_js;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = (sysRanDType *)
      &h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = (sysRanDType *)
      &h2_controller_pitch_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &h2_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &h2_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &h2_controller_pitch_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(h2_controller_pitch_M->extModeInfo,
      &h2_controller_pitch_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(h2_controller_pitch_M->extModeInfo,
                        h2_controller_pitch_M->Sizes.checksums);
    rteiSetTPtr(h2_controller_pitch_M->extModeInfo, rtmGetTPtr
                (h2_controller_pitch_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Delay: '<S1>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE =
      h2_controller_pitch_P.Delay3_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S11>/Internal'
    h2_controller_pitch_DW.Internal_DSTATE =
      h2_controller_pitch_P.Internal_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE[0] =
      h2_controller_pitch_P.Delay2_InitialCondition[0];
    h2_controller_pitch_DW.Delay2_DSTATE[1] =
      h2_controller_pitch_P.Delay2_InitialCondition[1];
    h2_controller_pitch_DW.Delay2_DSTATE[2] =
      h2_controller_pitch_P.Delay2_InitialCondition[2];
    h2_controller_pitch_DW.Delay2_DSTATE[3] =
      h2_controller_pitch_P.Delay2_InitialCondition[3];

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' 
    h2_controller_pitch_DW.DiscreteTransferFcn_states =
      h2_controller_pitch_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1' 
    h2_controller_pitch_DW.DiscreteTransferFcn1_states =
      h2_controller_pitch_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2' 
    h2_controller_pitch_DW.DiscreteTransferFcn2_states =
      h2_controller_pitch_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S30>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE[0] =
      h2_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE[0] =
      h2_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE[0] =
      h2_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE[0] =
      h2_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE[0] =
      h2_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE[0] =
      h2_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE[0] =
      h2_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE[0] =
      h2_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE[0] =
      h2_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE[0] =
      h2_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE[0] =
      h2_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE[0] =
      h2_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE[0] =
      h2_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE[0] =
      h2_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE[0] =
      h2_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_d[0] =
      h2_controller_pitch_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S30>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_i[0] =
      h2_controller_pitch_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S30>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE[0] =
      h2_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE[0] =
      h2_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S26>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE_p[0] =
      h2_controller_pitch_P.Delay_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S26>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE_p[0] =
      h2_controller_pitch_P.Delay1_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S26>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_p[0] =
      h2_controller_pitch_P.Delay2_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S26>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_j[0] =
      h2_controller_pitch_P.Delay3_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S26>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE_e[0] =
      h2_controller_pitch_P.Delay4_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S26>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE_p[0] =
      h2_controller_pitch_P.Delay5_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S26>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE_p[0] =
      h2_controller_pitch_P.Delay6_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S26>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE_o[0] =
      h2_controller_pitch_P.Delay7_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S26>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE_n[0] =
      h2_controller_pitch_P.Delay8_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S26>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE_i[0] =
      h2_controller_pitch_P.Delay9_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S26>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE_f[0] =
      h2_controller_pitch_P.Delay10_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S26>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE_k[0] =
      h2_controller_pitch_P.Delay11_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S26>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE_n[0] =
      h2_controller_pitch_P.Delay12_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S26>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE_g[0] =
      h2_controller_pitch_P.Delay13_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S26>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE_g[0] =
      h2_controller_pitch_P.Delay14_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S26>/Delay15'
    h2_controller_pitch_DW.Delay15_DSTATE[0] =
      h2_controller_pitch_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE_h[0] =
      h2_controller_pitch_P.Delay20_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S26>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE_d[0] =
      h2_controller_pitch_P.Delay21_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S26>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE_h[0] =
      h2_controller_pitch_P.Delay22_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S26>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE_p[0] =
      h2_controller_pitch_P.Delay23_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S26>/Delay24'
    h2_controller_pitch_DW.Delay24_DSTATE[0] =
      h2_controller_pitch_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay25'
    h2_controller_pitch_DW.Delay25_DSTATE[0] =
      h2_controller_pitch_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay26'
    h2_controller_pitch_DW.Delay26_DSTATE[0] =
      h2_controller_pitch_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay27'
    h2_controller_pitch_DW.Delay27_DSTATE[0] =
      h2_controller_pitch_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay16'
    h2_controller_pitch_DW.Delay16_DSTATE[0] =
      h2_controller_pitch_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay17'
    h2_controller_pitch_DW.Delay17_DSTATE[0] =
      h2_controller_pitch_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay18'
    h2_controller_pitch_DW.Delay18_DSTATE[0] =
      h2_controller_pitch_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S26>/Delay19'
    h2_controller_pitch_DW.Delay19_DSTATE[0] =
      h2_controller_pitch_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S30>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE[1] =
      h2_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE[1] =
      h2_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE[1] =
      h2_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE[1] =
      h2_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE[1] =
      h2_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE[1] =
      h2_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE[1] =
      h2_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE[1] =
      h2_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE[1] =
      h2_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE[1] =
      h2_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE[1] =
      h2_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE[1] =
      h2_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE[1] =
      h2_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE[1] =
      h2_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE[1] =
      h2_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_d[1] =
      h2_controller_pitch_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S30>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_i[1] =
      h2_controller_pitch_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S30>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE[1] =
      h2_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE[1] =
      h2_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S26>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE_p[1] =
      h2_controller_pitch_P.Delay_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S26>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE_p[1] =
      h2_controller_pitch_P.Delay1_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S26>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_p[1] =
      h2_controller_pitch_P.Delay2_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S26>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_j[1] =
      h2_controller_pitch_P.Delay3_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S26>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE_e[1] =
      h2_controller_pitch_P.Delay4_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S26>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE_p[1] =
      h2_controller_pitch_P.Delay5_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S26>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE_p[1] =
      h2_controller_pitch_P.Delay6_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S26>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE_o[1] =
      h2_controller_pitch_P.Delay7_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S26>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE_n[1] =
      h2_controller_pitch_P.Delay8_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S26>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE_i[1] =
      h2_controller_pitch_P.Delay9_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S26>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE_f[1] =
      h2_controller_pitch_P.Delay10_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S26>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE_k[1] =
      h2_controller_pitch_P.Delay11_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S26>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE_n[1] =
      h2_controller_pitch_P.Delay12_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S26>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE_g[1] =
      h2_controller_pitch_P.Delay13_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S26>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE_g[1] =
      h2_controller_pitch_P.Delay14_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S26>/Delay15'
    h2_controller_pitch_DW.Delay15_DSTATE[1] =
      h2_controller_pitch_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE_h[1] =
      h2_controller_pitch_P.Delay20_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S26>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE_d[1] =
      h2_controller_pitch_P.Delay21_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S26>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE_h[1] =
      h2_controller_pitch_P.Delay22_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S26>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE_p[1] =
      h2_controller_pitch_P.Delay23_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S26>/Delay24'
    h2_controller_pitch_DW.Delay24_DSTATE[1] =
      h2_controller_pitch_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay25'
    h2_controller_pitch_DW.Delay25_DSTATE[1] =
      h2_controller_pitch_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay26'
    h2_controller_pitch_DW.Delay26_DSTATE[1] =
      h2_controller_pitch_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay27'
    h2_controller_pitch_DW.Delay27_DSTATE[1] =
      h2_controller_pitch_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay16'
    h2_controller_pitch_DW.Delay16_DSTATE[1] =
      h2_controller_pitch_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay17'
    h2_controller_pitch_DW.Delay17_DSTATE[1] =
      h2_controller_pitch_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay18'
    h2_controller_pitch_DW.Delay18_DSTATE[1] =
      h2_controller_pitch_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S26>/Delay19'
    h2_controller_pitch_DW.Delay19_DSTATE[1] =
      h2_controller_pitch_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S30>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE[2] =
      h2_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE[2] =
      h2_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE[2] =
      h2_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE[2] =
      h2_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE[2] =
      h2_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE[2] =
      h2_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE[2] =
      h2_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE[2] =
      h2_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE[2] =
      h2_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE[2] =
      h2_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE[2] =
      h2_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE[2] =
      h2_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE[2] =
      h2_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE[2] =
      h2_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE[2] =
      h2_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_d[2] =
      h2_controller_pitch_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S30>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_i[2] =
      h2_controller_pitch_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S30>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE[2] =
      h2_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE[2] =
      h2_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S26>/Delay'
    h2_controller_pitch_DW.Delay_DSTATE_p[2] =
      h2_controller_pitch_P.Delay_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S26>/Delay1'
    h2_controller_pitch_DW.Delay1_DSTATE_p[2] =
      h2_controller_pitch_P.Delay1_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S26>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_p[2] =
      h2_controller_pitch_P.Delay2_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S26>/Delay3'
    h2_controller_pitch_DW.Delay3_DSTATE_j[2] =
      h2_controller_pitch_P.Delay3_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S26>/Delay4'
    h2_controller_pitch_DW.Delay4_DSTATE_e[2] =
      h2_controller_pitch_P.Delay4_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S26>/Delay5'
    h2_controller_pitch_DW.Delay5_DSTATE_p[2] =
      h2_controller_pitch_P.Delay5_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S26>/Delay6'
    h2_controller_pitch_DW.Delay6_DSTATE_p[2] =
      h2_controller_pitch_P.Delay6_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S26>/Delay7'
    h2_controller_pitch_DW.Delay7_DSTATE_o[2] =
      h2_controller_pitch_P.Delay7_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S26>/Delay8'
    h2_controller_pitch_DW.Delay8_DSTATE_n[2] =
      h2_controller_pitch_P.Delay8_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S26>/Delay9'
    h2_controller_pitch_DW.Delay9_DSTATE_i[2] =
      h2_controller_pitch_P.Delay9_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S26>/Delay10'
    h2_controller_pitch_DW.Delay10_DSTATE_f[2] =
      h2_controller_pitch_P.Delay10_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S26>/Delay11'
    h2_controller_pitch_DW.Delay11_DSTATE_k[2] =
      h2_controller_pitch_P.Delay11_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S26>/Delay12'
    h2_controller_pitch_DW.Delay12_DSTATE_n[2] =
      h2_controller_pitch_P.Delay12_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S26>/Delay13'
    h2_controller_pitch_DW.Delay13_DSTATE_g[2] =
      h2_controller_pitch_P.Delay13_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S26>/Delay14'
    h2_controller_pitch_DW.Delay14_DSTATE_g[2] =
      h2_controller_pitch_P.Delay14_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S26>/Delay15'
    h2_controller_pitch_DW.Delay15_DSTATE[2] =
      h2_controller_pitch_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay20'
    h2_controller_pitch_DW.Delay20_DSTATE_h[2] =
      h2_controller_pitch_P.Delay20_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S26>/Delay21'
    h2_controller_pitch_DW.Delay21_DSTATE_d[2] =
      h2_controller_pitch_P.Delay21_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S26>/Delay22'
    h2_controller_pitch_DW.Delay22_DSTATE_h[2] =
      h2_controller_pitch_P.Delay22_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S26>/Delay23'
    h2_controller_pitch_DW.Delay23_DSTATE_p[2] =
      h2_controller_pitch_P.Delay23_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S26>/Delay24'
    h2_controller_pitch_DW.Delay24_DSTATE[2] =
      h2_controller_pitch_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay25'
    h2_controller_pitch_DW.Delay25_DSTATE[2] =
      h2_controller_pitch_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay26'
    h2_controller_pitch_DW.Delay26_DSTATE[2] =
      h2_controller_pitch_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay27'
    h2_controller_pitch_DW.Delay27_DSTATE[2] =
      h2_controller_pitch_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay16'
    h2_controller_pitch_DW.Delay16_DSTATE[2] =
      h2_controller_pitch_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay17'
    h2_controller_pitch_DW.Delay17_DSTATE[2] =
      h2_controller_pitch_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay18'
    h2_controller_pitch_DW.Delay18_DSTATE[2] =
      h2_controller_pitch_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S26>/Delay19'
    h2_controller_pitch_DW.Delay19_DSTATE[2] =
      h2_controller_pitch_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S28>/Memory4'
    for (i = 0; i < 5; i++) {
      h2_controller_pitch_DW.Memory4_PreviousInput[i] =
        h2_controller_pitch_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S28>/Memory4'

    // InitializeConditions for Delay: '<S28>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_l[0] =
      h2_controller_pitch_P.Delay2_InitialCondition_kt;
    h2_controller_pitch_DW.Delay2_DSTATE_l[1] =
      h2_controller_pitch_P.Delay2_InitialCondition_kt;
    h2_controller_pitch_DW.Delay2_DSTATE_l[2] =
      h2_controller_pitch_P.Delay2_InitialCondition_kt;

    // InitializeConditions for Memory: '<S28>/Memory2'
    h2_controller_pitch_DW.Memory2_PreviousInput =
      h2_controller_pitch_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S28>/Memory3'
    memcpy(&h2_controller_pitch_DW.Memory3_PreviousInput[0],
           &h2_controller_pitch_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S31>/Memory4'
    h2_controller_pitch_DW.Memory4_PreviousInput_k = h2_controller_pitch_P.x0_ps;

    // InitializeConditions for Memory: '<S31>/Memory3'
    h2_controller_pitch_DW.Memory3_PreviousInput_f = h2_controller_pitch_P.P0_ps;

    // InitializeConditions for Memory: '<S31>/Memory2'
    h2_controller_pitch_DW.Memory2_PreviousInput_b =
      h2_controller_pitch_P.Memory2_InitialCondition_h;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn' 
    h2_controller_pitch_DW.DiscreteTransferFcn_states_a =
      h2_controller_pitch_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn1' 
    h2_controller_pitch_DW.DiscreteTransferFcn1_states_e =
      h2_controller_pitch_P.DiscreteTransferFcn1_InitialS_j;

    // InitializeConditions for DiscreteTransferFcn: '<S25>/Discrete Transfer Fcn2' 
    h2_controller_pitch_DW.DiscreteTransferFcn2_states_p =
      h2_controller_pitch_P.DiscreteTransferFcn2_InitialS_c;

    // InitializeConditions for Memory: '<S19>/Memory5'
    h2_controller_pitch_DW.Memory5_PreviousInput =
      h2_controller_pitch_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_n[0] =
      h2_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S19>/Memory6'
    h2_controller_pitch_DW.Memory6_PreviousInput[0] =
      h2_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_n[1] =
      h2_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S19>/Memory6'
    h2_controller_pitch_DW.Memory6_PreviousInput[1] =
      h2_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay2'
    h2_controller_pitch_DW.Delay2_DSTATE_n[2] =
      h2_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S19>/Memory6'
    h2_controller_pitch_DW.Memory6_PreviousInput[2] =
      h2_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' 
    h2_controller_pitch_DW.DiscreteTransferFcn1_states_p =
      h2_controller_pitch_P.DiscreteTransferFcn1_InitialS_e;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' 
    h2_controller_pitch_DW.DiscreteTransferFcn_states_f =
      h2_controller_pitch_P.DiscreteTransferFcn_InitialSt_i;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' 
    h2_controller_pitch_DW.DiscreteTransferFcn1_states_d =
      h2_controller_pitch_P.DiscreteTransferFcn1_InitialS_g;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' 
    h2_controller_pitch_DW.DiscreteTransferFcn2_states_p2 =
      h2_controller_pitch_P.DiscreteTransferFcn2_InitialS_o;

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S70>/In1' incorporates:
    //   Outport: '<S70>/Out1'

    h2_controller_pitch_B.In1 = h2_controller_pitch_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S59>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S60>/In1' incorporates:
    //   Outport: '<S60>/Out1'

    h2_controller_pitch_B.In1_f = h2_controller_pitch_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S59>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    h2_controller_pitch_B.In1_i = h2_controller_pitch_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S57>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    h2_controller_pitch_B.In1_n = h2_controller_pitch_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S57>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    h2_control_MATLABFunction1_Init(&h2_controller_pitch_DW.sf_MATLABFunction1_i);

    // SystemInitialize for MATLAB Function: '<S20>/MATLAB Function7'
    h2_control_MATLABFunction1_Init(&h2_controller_pitch_DW.sf_MATLABFunction7);

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S48>/In1' incorporates:
    //   Outport: '<S48>/Out1'

    h2_controller_pitch_B.In1_h = h2_controller_pitch_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S69>/SourceBlock'
    h2_controller_pitch_DW.obj_c.matlabCodegenIsDeleted = false;
    h2_controller_pitch_DW.obj_c.isInitialized = 1;
    h2_controller_pitch_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(h2_controller_pitch_DW.obj_c.orbMetadataObj,
                         &h2_controller_pitch_DW.obj_c.eventStructObj);
    h2_controller_pitch_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S59>/SourceBlock'
    h2_controller_pitch_DW.obj_h.matlabCodegenIsDeleted = false;
    h2_controller_pitch_DW.obj_h.isInitialized = 1;
    h2_controller_pitch_DW.obj_h.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(h2_controller_pitch_DW.obj_h.orbMetadataObj,
                         &h2_controller_pitch_DW.obj_h.eventStructObj);
    h2_controller_pitch_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S55>/SourceBlock'
    h2_controller_pitch_DW.obj_jj.matlabCodegenIsDeleted = false;
    h2_controller_pitch_DW.obj_jj.isInitialized = 1;
    h2_controller_pitch_DW.obj_jj.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(h2_controller_pitch_DW.obj_jj.orbMetadataObj,
                         &h2_controller_pitch_DW.obj_jj.eventStructObj);
    h2_controller_pitch_DW.obj_jj.isSetupComplete = true;

    // Start for MATLABSystem: '<S57>/SourceBlock'
    h2_controller_pitch_DW.obj_j.matlabCodegenIsDeleted = false;
    h2_controller_pitch_DW.obj_j.isInitialized = 1;
    h2_controller_pitch_DW.obj_j.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(h2_controller_pitch_DW.obj_j.orbMetadataObj,
                         &h2_controller_pitch_DW.obj_j.eventStructObj);
    h2_controller_pitch_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/failsafe'

    h2_controller_pitch_DW.obj.errorStatus = 0U;
    h2_controller_pitch_DW.obj.isInitialized = 0;
    h2_controller_pitch_DW.obj.matlabCodegenIsDeleted = false;
    h2_controller__SystemCore_setup(&h2_controller_pitch_DW.obj,
      rtb_startingswitch, h2_controller_pitch_P.failsafe_Value);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    h2_controller_pitch_DW.obj_d.matlabCodegenIsDeleted = false;
    h2_controller_pitch_DW.obj_d.isInitialized = 1;
    h2_controller_pitch_DW.obj_d.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(h2_controller_pitch_DW.obj_d.orbMetadataObj,
                         &h2_controller_pitch_DW.obj_d.eventStructObj);
    h2_controller_pitch_DW.obj_d.isSetupComplete = true;
  }
}

// Model terminate function
void h2_controller_pitch_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S69>/SourceBlock'
  if (!h2_controller_pitch_DW.obj_c.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj_c.isInitialized == 1) &&
        h2_controller_pitch_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&h2_controller_pitch_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S69>/SourceBlock'

  // Terminate for MATLABSystem: '<S59>/SourceBlock'
  if (!h2_controller_pitch_DW.obj_h.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj_h.isInitialized == 1) &&
        h2_controller_pitch_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&h2_controller_pitch_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S59>/SourceBlock'

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  if (!h2_controller_pitch_DW.obj_jj.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj_jj.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj_jj.isInitialized == 1) &&
        h2_controller_pitch_DW.obj_jj.isSetupComplete) {
      uORB_read_terminate(&h2_controller_pitch_DW.obj_jj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S55>/SourceBlock'

  // Terminate for MATLABSystem: '<S57>/SourceBlock'
  if (!h2_controller_pitch_DW.obj_j.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj_j.isInitialized == 1) &&
        h2_controller_pitch_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&h2_controller_pitch_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S57>/SourceBlock'
  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!h2_controller_pitch_DW.obj.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj.isInitialized == 1) &&
        h2_controller_pitch_DW.obj.isSetupComplete) {
      status = pwm_disarm(&h2_controller_pitch_DW.obj.pwmDevHandler,
                          &h2_controller_pitch_DW.obj.armAdvertiseObj);
      h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (h2_controller_pitch_DW.obj.errorStatus | status);
      status = pwm_resetServo(&h2_controller_pitch_DW.obj.pwmDevHandler,
        h2_controller_pitch_DW.obj.servoCount,
        h2_controller_pitch_DW.obj.channelMask,
        h2_controller_pitch_DW.obj.isMain,
        &h2_controller_pitch_DW.obj.actuatorAdvertiseObj);
      h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (h2_controller_pitch_DW.obj.errorStatus | status);
      status = pwm_close(&h2_controller_pitch_DW.obj.pwmDevHandler,
                         &h2_controller_pitch_DW.obj.actuatorAdvertiseObj,
                         &h2_controller_pitch_DW.obj.armAdvertiseObj);
      h2_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (h2_controller_pitch_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!h2_controller_pitch_DW.obj_d.matlabCodegenIsDeleted) {
    h2_controller_pitch_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((h2_controller_pitch_DW.obj_d.isInitialized == 1) &&
        h2_controller_pitch_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&h2_controller_pitch_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
