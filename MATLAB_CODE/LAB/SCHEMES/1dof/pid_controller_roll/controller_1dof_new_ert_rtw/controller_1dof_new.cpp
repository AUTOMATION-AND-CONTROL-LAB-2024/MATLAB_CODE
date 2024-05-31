//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_1dof_new.cpp
//
// Code generated for Simulink model 'controller_1dof_new'.
//
// Model version                  : 1.50
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed May 29 11:27:42 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_1dof_new.h"
#include "rtwtypes.h"
#include "controller_1dof_new_types.h"
#include "controller_1dof_new_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S4>/MATLAB Function1'
const int32_T controller_1dof_new_CALL_EVENT = -1;

// Block signals (default storage)
B_controller_1dof_new_T controller_1dof_new_B;

// Block states (default storage)
DW_controller_1dof_new_T controller_1dof_new_DW;

// Real-time model
RT_MODEL_controller_1dof_new_T controller_1dof_new_M_ =
  RT_MODEL_controller_1dof_new_T();
RT_MODEL_controller_1dof_new_T *const controller_1dof_new_M =
  &controller_1dof_new_M_;

// Forward declaration for local functions
static void controller_1do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
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
//    '<S19>/MATLAB Function7'
//
void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_1dof_new_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S19>/MATLAB Function7'
//
void controller_1dof_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_1dof_new_CALL_EVENT;
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

static void controller_1do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
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
void controller_1dof_new_step(void)
{
  int32_T At1_tmp;
  int32_T Pt1_tmp;
  int32_T i;
  real32_T rtb_Product1;
  real32_T rtb_fcn3;
  real32_T rtb_fcn5;
  real32_T y_k_tmp;
  real32_T y_k_tmp_0;
  real32_T y_k_tmp_1;
  real32_T y_k_tmp_2;
  int16_T rtb_SignCorrected;
  uint16_T rtb_CastU16En16;
  uint16_T rtb_DataTypeConversion1_c;
  uint16_T rtb_DataTypeConversion1_h;
  uint16_T rtb_DataTypeConversion1_o;
  uint16_T rtb_DataTypeConversion1_p;
  boolean_T rtb_LTEp50;
  boolean_T rtb_startingswitch;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_js);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<Root>/Digital Clock'
  //   DigitalClock: '<S18>/Discrete Time1'
  //   DigitalClock: '<S27>/Discrete Time'
  //   DigitalClock: '<S30>/Discrete Time'
  //   Step: '<Root>/R ref'

  controller_1dof_new_B.DigitalClock1 = controller_1dof_new_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (controller_1dof_new_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = controller_1dof_new_P.Constant2_Value;
  } else {
    rtb_startingswitch = controller_1dof_new_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // DiscreteStateSpace: '<S10>/Internal'
  {
    controller_1dof_new_B.Internal = controller_1dof_new_P.Internal_C*
      controller_1dof_new_DW.Internal_DSTATE;
  }

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S1>/Gain'

  controller_1dof_new_B.Product = controller_1dof_new_P.Gain_Gain *
    controller_1dof_new_B.Internal * static_cast<real_T>(rtb_startingswitch);

  // MATLAB Function: '<S1>/MATLAB Function1'
  if (!rtb_startingswitch) {
    controller_1dof_new_DW.Delay2_DSTATE[0] = 0.0;
    controller_1dof_new_DW.Delay2_DSTATE[1] = 0.0;
    controller_1dof_new_DW.Delay3_DSTATE = 0.0;
  }

  controller_1dof_new_B.x = (controller_1dof_new_P.A_cond[0] *
    controller_1dof_new_DW.Delay2_DSTATE[0] +
    controller_1dof_new_DW.Delay2_DSTATE[1] * controller_1dof_new_P.A_cond[2]) +
    controller_1dof_new_P.B_cond[0] * controller_1dof_new_DW.Delay3_DSTATE;
  controller_1dof_new_B.x_idx_0 = controller_1dof_new_B.x;

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   Constant: '<S1>/Constant6'

  controller_1dof_new_B.a21 = controller_1dof_new_P.C[0] *
    controller_1dof_new_B.x;
  controller_1dof_new_B.x = (controller_1dof_new_DW.Delay2_DSTATE[0] *
    controller_1dof_new_P.A_cond[1] + controller_1dof_new_DW.Delay2_DSTATE[1] *
    controller_1dof_new_P.A_cond[3]) + controller_1dof_new_P.B_cond[1] *
    controller_1dof_new_DW.Delay3_DSTATE;
  controller_1dof_new_B.u_sat = (controller_1dof_new_P.C[1] *
    controller_1dof_new_B.x + controller_1dof_new_B.a21) +
    controller_1dof_new_P.D * controller_1dof_new_B.Product;
  if ((controller_1dof_new_P.Constant6_Value <= controller_1dof_new_B.u_sat) ||
      rtIsNaN(controller_1dof_new_B.u_sat)) {
    controller_1dof_new_B.u_sat = controller_1dof_new_P.Constant6_Value;
  }

  if ((controller_1dof_new_P.Constant3_Value >= controller_1dof_new_B.u_sat) ||
      rtIsNaN(controller_1dof_new_B.u_sat)) {
    controller_1dof_new_B.u_sat = controller_1dof_new_P.Constant3_Value;
  }

  // MATLAB Function: '<S1>/MATLAB Function3'
  controller_1dof_new_B.tau_o[0] = controller_1dof_new_B.u_sat;
  controller_1dof_new_B.tau_o[1] = 0.0;
  controller_1dof_new_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (controller_1dof_new_B.tau_o[0] >= 0.0) {
    controller_1dof_new_B.u[3] = controller_1dof_new_P.Constant3_Value_m;
    controller_1dof_new_B.u[2] = (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[7] * controller_1dof_new_P.Constant3_Value_m +
      controller_1dof_new_B.tau_o[0]) / (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[6]);
  } else {
    controller_1dof_new_B.u[2] = controller_1dof_new_P.Constant3_Value_m;
    controller_1dof_new_B.u[3] = (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[6] * controller_1dof_new_P.Constant3_Value_m -
      controller_1dof_new_B.tau_o[0]) / (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[7]);
  }

  if (controller_1dof_new_B.tau_o[1] >= 0.0) {
    controller_1dof_new_B.u[0] = controller_1dof_new_P.Constant3_Value_m;
    controller_1dof_new_B.u[1] = (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[4] * controller_1dof_new_P.Constant3_Value_m +
      controller_1dof_new_B.tau_o[1]) / (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[5]);
  } else {
    controller_1dof_new_B.u[1] = controller_1dof_new_P.Constant3_Value_m;
    controller_1dof_new_B.u[0] = (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[5] * controller_1dof_new_P.Constant3_Value_m -
      controller_1dof_new_B.tau_o[1]) / (controller_1dof_new_P.param[3] *
      controller_1dof_new_P.param[4]);
  }

  rtb_LTEp50 = rtIsNaN(controller_1dof_new_B.u[0]);
  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[0]) ||
      rtb_LTEp50) {
    controller_1dof_new_B.y = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.y = controller_1dof_new_B.u[0];
  }

  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[0]) ||
      rtb_LTEp50) {
    controller_1dof_new_B.minval[0] = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.minval[0] = controller_1dof_new_B.u[0];
  }

  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[1]) ||
      rtIsNaN(controller_1dof_new_B.u[1])) {
    controller_1dof_new_B.y_g = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.y_g = controller_1dof_new_B.u[1];
  }

  rtb_LTEp50 = rtIsNaN(controller_1dof_new_B.u[2]);
  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[2]) ||
      rtb_LTEp50) {
    controller_1dof_new_B.y_g1 = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.y_g1 = controller_1dof_new_B.u[2];
  }

  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[2]) ||
      rtb_LTEp50) {
    controller_1dof_new_B.minval[2] = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.minval[2] = controller_1dof_new_B.u[2];
  }

  if ((controller_1dof_new_P.Constant1_Value <= controller_1dof_new_B.u[3]) ||
      rtIsNaN(controller_1dof_new_B.u[3])) {
    controller_1dof_new_B.y_m = controller_1dof_new_P.Constant1_Value;
  } else {
    controller_1dof_new_B.y_m = controller_1dof_new_B.u[3];
  }

  controller_1dof_new_B.dv1[0] = 0.0;
  controller_1dof_new_B.dv1[3] = 0.0;
  controller_1dof_new_B.dv1[6] = controller_1dof_new_P.param[3] *
    controller_1dof_new_P.param[6];
  controller_1dof_new_B.dv1[9] = -controller_1dof_new_P.param[3] *
    controller_1dof_new_P.param[7];
  controller_1dof_new_B.dv1[1] = -controller_1dof_new_P.param[3] *
    controller_1dof_new_P.param[4];
  controller_1dof_new_B.dv1[4] = controller_1dof_new_P.param[3] *
    controller_1dof_new_P.param[5];
  controller_1dof_new_B.dv1[7] = 0.0;
  controller_1dof_new_B.dv1[10] = 0.0;
  controller_1dof_new_B.dv1[2] = -controller_1dof_new_P.param[8];
  controller_1dof_new_B.dv1[5] = -controller_1dof_new_P.param[8];
  controller_1dof_new_B.dv1[8] = controller_1dof_new_P.param[8];
  controller_1dof_new_B.dv1[11] = controller_1dof_new_P.param[8];
  controller_1dof_new_B.rtb_Delay_l_idx_0 = controller_1dof_new_B.minval[0];
  controller_1dof_new_B.rtb_Delay1_n_idx_0 = controller_1dof_new_B.minval[2];
  for (i = 0; i < 3; i++) {
    controller_1dof_new_B.tau_allocated[i] = ((controller_1dof_new_B.dv1[i + 3] *
      controller_1dof_new_B.y_g + controller_1dof_new_B.dv1[i] *
      controller_1dof_new_B.rtb_Delay_l_idx_0) + controller_1dof_new_B.dv1[i + 6]
      * controller_1dof_new_B.rtb_Delay1_n_idx_0) + controller_1dof_new_B.dv1[i
      + 9] * controller_1dof_new_B.y_m;
  }

  controller_1dof_new_B.u[0] = controller_1dof_new_B.y;
  controller_1dof_new_B.u[1] = controller_1dof_new_B.y_g;
  controller_1dof_new_B.u[2] = controller_1dof_new_B.y_g1;
  controller_1dof_new_B.u[3] = controller_1dof_new_B.y_m;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  controller_1dof_new_B.u1 = controller_1dof_new_B.u[0];
  controller_1dof_new_B.u2 = controller_1dof_new_B.u[1];
  controller_1dof_new_B.u3 = controller_1dof_new_B.u[2];
  controller_1dof_new_B.u4 = controller_1dof_new_B.u[3];

  // DataTypeConversion: '<S43>/Data Type Conversion1' incorporates:
  //   Constant: '<S43>/Constant'
  //   Sum: '<S43>/Sum'

  controller_1dof_new_B.a21 = floor(controller_1dof_new_B.u1 +
    controller_1dof_new_P.Constant_Value_n);
  if (rtIsNaN(controller_1dof_new_B.a21) || rtIsInf(controller_1dof_new_B.a21))
  {
    controller_1dof_new_B.a21 = 0.0;
  } else {
    controller_1dof_new_B.a21 = fmod(controller_1dof_new_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_c = static_cast<uint16_T>(controller_1dof_new_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_new_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_1dof_new_B.a21)));

  // End of DataTypeConversion: '<S43>/Data Type Conversion1'

  // DataTypeConversion: '<S44>/Data Type Conversion1' incorporates:
  //   Constant: '<S44>/Constant'
  //   Sum: '<S44>/Sum'

  controller_1dof_new_B.a21 = floor(controller_1dof_new_B.u2 +
    controller_1dof_new_P.Constant_Value_j);
  if (rtIsNaN(controller_1dof_new_B.a21) || rtIsInf(controller_1dof_new_B.a21))
  {
    controller_1dof_new_B.a21 = 0.0;
  } else {
    controller_1dof_new_B.a21 = fmod(controller_1dof_new_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_h = static_cast<uint16_T>(controller_1dof_new_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_new_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_1dof_new_B.a21)));

  // End of DataTypeConversion: '<S44>/Data Type Conversion1'

  // DataTypeConversion: '<S45>/Data Type Conversion1' incorporates:
  //   Constant: '<S45>/Constant'
  //   Sum: '<S45>/Sum'

  controller_1dof_new_B.a21 = floor(controller_1dof_new_B.u3 +
    controller_1dof_new_P.Constant_Value_pr);
  if (rtIsNaN(controller_1dof_new_B.a21) || rtIsInf(controller_1dof_new_B.a21))
  {
    controller_1dof_new_B.a21 = 0.0;
  } else {
    controller_1dof_new_B.a21 = fmod(controller_1dof_new_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_p = static_cast<uint16_T>(controller_1dof_new_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_new_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_1dof_new_B.a21)));

  // End of DataTypeConversion: '<S45>/Data Type Conversion1'

  // DataTypeConversion: '<S46>/Data Type Conversion1' incorporates:
  //   Constant: '<S46>/Constant'
  //   Sum: '<S46>/Sum'

  controller_1dof_new_B.a21 = floor(controller_1dof_new_B.u4 +
    controller_1dof_new_P.Constant_Value_d);
  if (rtIsNaN(controller_1dof_new_B.a21) || rtIsInf(controller_1dof_new_B.a21))
  {
    controller_1dof_new_B.a21 = 0.0;
  } else {
    controller_1dof_new_B.a21 = fmod(controller_1dof_new_B.a21, 65536.0);
  }

  rtb_DataTypeConversion1_o = static_cast<uint16_T>(controller_1dof_new_B.a21 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_new_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_1dof_new_B.a21)));

  // End of DataTypeConversion: '<S46>/Data Type Conversion1'

  // MATLABSystem: '<S68>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(controller_1dof_new_DW.obj_c.orbMetadataObj,
    &controller_1dof_new_DW.obj_c.eventStructObj,
    &controller_1dof_new_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S68>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S69>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S69>/In1'
    controller_1dof_new_B.In1 = controller_1dof_new_B.b_varargout_2;
    srUpdateBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S68>/SourceBlock'
  // End of Outputs for SubSystem: '<S68>/Enabled Subsystem'

  // Sqrt: '<S66>/sqrt' incorporates:
  //   Product: '<S67>/Product'
  //   Product: '<S67>/Product1'
  //   Product: '<S67>/Product2'
  //   Product: '<S67>/Product3'
  //   Sum: '<S67>/Sum'

  controller_1dof_new_B.Product3 = static_cast<real32_T>(sqrt(static_cast<real_T>
    (((controller_1dof_new_B.In1.q[0] * controller_1dof_new_B.In1.q[0] +
       controller_1dof_new_B.In1.q[1] * controller_1dof_new_B.In1.q[1]) +
      controller_1dof_new_B.In1.q[2] * controller_1dof_new_B.In1.q[2]) +
     controller_1dof_new_B.In1.q[3] * controller_1dof_new_B.In1.q[3])));

  // Product: '<S61>/Product'
  rtb_fcn5 = controller_1dof_new_B.In1.q[0] / controller_1dof_new_B.Product3;

  // Product: '<S61>/Product1'
  rtb_Product1 = controller_1dof_new_B.In1.q[1] / controller_1dof_new_B.Product3;

  // Product: '<S61>/Product2'
  controller_1dof_new_B.Product2 = controller_1dof_new_B.In1.q[2] /
    controller_1dof_new_B.Product3;

  // Product: '<S61>/Product3'
  controller_1dof_new_B.Product3 = controller_1dof_new_B.In1.q[3] /
    controller_1dof_new_B.Product3;

  // Fcn: '<S51>/fcn3'
  rtb_fcn3 = (rtb_Product1 * controller_1dof_new_B.Product3 - rtb_fcn5 *
              controller_1dof_new_B.Product2) * -2.0F;

  // If: '<S62>/If' incorporates:
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
    //   ActionPort: '<S63>/Action Port'

    rtb_fcn3 = controller_1dof_new_P.Constant_Value_o;

    // End of Outputs for SubSystem: '<S62>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
    //   ActionPort: '<S63>/Action Port'

    // Update for If: '<S62>/If' incorporates:
    //   Constant: '<S63>/Constant'

    srUpdateBC(controller_1dof_new_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S64>/Action Port'

    rtb_fcn3 = controller_1dof_new_P.Constant_Value_e5;

    // End of Outputs for SubSystem: '<S62>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S64>/Action Port'

    // Update for If: '<S62>/If' incorporates:
    //   Constant: '<S64>/Constant'

    srUpdateBC(controller_1dof_new_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S62>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S65>/Action Port'

    // Update for If: '<S62>/If'
    srUpdateBC(controller_1dof_new_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem2'
  }

  // End of If: '<S62>/If'

  // Fcn: '<S51>/fcn5' incorporates:
  //   Fcn: '<S51>/fcn2'

  y_k_tmp = rtb_fcn5 * rtb_fcn5;
  y_k_tmp_0 = rtb_Product1 * rtb_Product1;
  y_k_tmp_1 = controller_1dof_new_B.Product2 * controller_1dof_new_B.Product2;
  y_k_tmp_2 = controller_1dof_new_B.Product3 * controller_1dof_new_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S51>/fcn4'
  //   Fcn: '<S51>/fcn5'
  //   Trigonometry: '<S60>/Trigonometric Function3'

  controller_1dof_new_B.y_k[0] = rt_atan2f_snf((controller_1dof_new_B.Product2 *
    controller_1dof_new_B.Product3 + rtb_fcn5 * rtb_Product1) * 2.0F, ((y_k_tmp
    - y_k_tmp_0) - y_k_tmp_1) + y_k_tmp_2);

  // Trigonometry: '<S60>/trigFcn'
  if (rtb_fcn3 > 1.0F) {
    rtb_fcn3 = 1.0F;
  } else if (rtb_fcn3 < -1.0F) {
    rtb_fcn3 = -1.0F;
  }

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S51>/fcn1'
  //   Fcn: '<S51>/fcn2'
  //   Trigonometry: '<S60>/Trigonometric Function1'
  //   Trigonometry: '<S60>/trigFcn'

  controller_1dof_new_B.y_k[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (rtb_fcn3)));
  controller_1dof_new_B.y_k[2] = rt_atan2f_snf((rtb_Product1 *
    controller_1dof_new_B.Product2 + rtb_fcn5 * controller_1dof_new_B.Product3) *
    2.0F, ((y_k_tmp + y_k_tmp_0) - y_k_tmp_1) - y_k_tmp_2);

  // MATLABSystem: '<S58>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(controller_1dof_new_DW.obj_h.orbMetadataObj,
    &controller_1dof_new_DW.obj_h.eventStructObj,
    &controller_1dof_new_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S58>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S59>/In1'
    controller_1dof_new_B.In1_f = controller_1dof_new_B.b_varargout_2_b;
    srUpdateBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of MATLABSystem: '<S58>/SourceBlock'
  // End of Outputs for SubSystem: '<S58>/Enabled Subsystem'

  // MATLABSystem: '<S54>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(controller_1dof_new_DW.obj_jj.orbMetadataObj,
    &controller_1dof_new_DW.obj_jj.eventStructObj,
    &controller_1dof_new_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S54>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S55>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S55>/In1'
    controller_1dof_new_B.In1_i = controller_1dof_new_B.b_varargout_2_k;
    srUpdateBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_js);
  }

  // End of MATLABSystem: '<S54>/SourceBlock'
  // End of Outputs for SubSystem: '<S54>/Enabled Subsystem'

  // MATLABSystem: '<S56>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(controller_1dof_new_DW.obj_j.orbMetadataObj,
    &controller_1dof_new_DW.obj_j.eventStructObj,
    &controller_1dof_new_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S56>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S57>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S57>/In1'
    controller_1dof_new_B.In1_n = controller_1dof_new_B.b_varargout_2_cx;
    srUpdateBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S56>/SourceBlock'
  // End of Outputs for SubSystem: '<S56>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  controller_1dof_new_B.y_g = controller_1dof_new_P.DiscreteTransferFcn_NumCoef *
    controller_1dof_new_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  controller_1dof_new_B.y_g1 =
    controller_1dof_new_P.DiscreteTransferFcn1_NumCoef *
    controller_1dof_new_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
  controller_1dof_new_B.y_m = controller_1dof_new_P.DiscreteTransferFcn2_NumCoef
    * controller_1dof_new_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S32>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S25>/MATLAB Function'

  controller_1dof_new_B.TmpSignalConversionAtSFun_e[0] =
    controller_1dof_new_B.y_g;
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[1] =
    controller_1dof_new_B.y_g1;
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[2] =
    controller_1dof_new_B.y_m;

  // Delay: '<S25>/Delay'
  controller_1dof_new_B.rtb_Delay_l_idx_0 =
    controller_1dof_new_DW.Delay_DSTATE_p[0];

  // Delay: '<S25>/Delay1'
  controller_1dof_new_B.rtb_Delay1_n_idx_0 =
    controller_1dof_new_DW.Delay1_DSTATE_p[0];

  // Delay: '<S25>/Delay2'
  controller_1dof_new_B.rtb_Delay2_h_idx_0 =
    controller_1dof_new_DW.Delay2_DSTATE_p[0];

  // Delay: '<S25>/Delay3'
  controller_1dof_new_B.rtb_Delay3_p_idx_0 =
    controller_1dof_new_DW.Delay3_DSTATE_j[0];

  // Delay: '<S25>/Delay4'
  controller_1dof_new_B.rtb_Delay4_j_idx_0 =
    controller_1dof_new_DW.Delay4_DSTATE_e[0];

  // Delay: '<S25>/Delay5'
  controller_1dof_new_B.rtb_Delay5_e_idx_0 =
    controller_1dof_new_DW.Delay5_DSTATE_p[0];

  // Delay: '<S25>/Delay6'
  controller_1dof_new_B.rtb_Delay6_f_idx_0 =
    controller_1dof_new_DW.Delay6_DSTATE_p[0];

  // Delay: '<S25>/Delay7'
  controller_1dof_new_B.rtb_Delay7_i_idx_0 =
    controller_1dof_new_DW.Delay7_DSTATE_o[0];

  // Delay: '<S25>/Delay8'
  controller_1dof_new_B.rtb_Delay8_j_idx_0 =
    controller_1dof_new_DW.Delay8_DSTATE_n[0];

  // Delay: '<S25>/Delay9'
  controller_1dof_new_B.rtb_Delay9_j_idx_0 =
    controller_1dof_new_DW.Delay9_DSTATE_i[0];

  // Delay: '<S25>/Delay10'
  controller_1dof_new_B.rtb_Delay10_e_idx_0 =
    controller_1dof_new_DW.Delay10_DSTATE_f[0];

  // Delay: '<S25>/Delay11'
  controller_1dof_new_B.rtb_Delay11_n_idx_0 =
    controller_1dof_new_DW.Delay11_DSTATE_k[0];

  // Delay: '<S25>/Delay12'
  controller_1dof_new_B.rtb_Delay12_a_idx_0 =
    controller_1dof_new_DW.Delay12_DSTATE_n[0];

  // Delay: '<S25>/Delay13'
  controller_1dof_new_B.rtb_Delay13_h_idx_0 =
    controller_1dof_new_DW.Delay13_DSTATE_g[0];

  // Delay: '<S25>/Delay14'
  controller_1dof_new_B.rtb_Delay14_m_idx_0 =
    controller_1dof_new_DW.Delay14_DSTATE_g[0];

  // Delay: '<S25>/Delay15'
  controller_1dof_new_B.rtb_Delay15_idx_0 =
    controller_1dof_new_DW.Delay15_DSTATE[0];

  // Delay: '<S25>/Delay20'
  controller_1dof_new_B.rtb_Delay20_g_idx_0 =
    controller_1dof_new_DW.Delay20_DSTATE_h[0];

  // Delay: '<S25>/Delay21'
  controller_1dof_new_B.rtb_Delay21_e_idx_0 =
    controller_1dof_new_DW.Delay21_DSTATE_d[0];

  // Delay: '<S25>/Delay22'
  controller_1dof_new_B.rtb_Delay22_b_idx_0 =
    controller_1dof_new_DW.Delay22_DSTATE_h[0];

  // Delay: '<S25>/Delay23'
  controller_1dof_new_B.rtb_Delay23_g_idx_0 =
    controller_1dof_new_DW.Delay23_DSTATE_p[0];

  // Delay: '<S25>/Delay24'
  controller_1dof_new_B.rtb_Delay24_idx_0 =
    controller_1dof_new_DW.Delay24_DSTATE[0];

  // Delay: '<S25>/Delay25'
  controller_1dof_new_B.rtb_Delay25_idx_0 =
    controller_1dof_new_DW.Delay25_DSTATE[0];

  // Delay: '<S25>/Delay26'
  controller_1dof_new_B.rtb_Delay26_idx_0 =
    controller_1dof_new_DW.Delay26_DSTATE[0];

  // Delay: '<S25>/Delay27'
  controller_1dof_new_B.rtb_Delay27_idx_0 =
    controller_1dof_new_DW.Delay27_DSTATE[0];

  // Delay: '<S25>/Delay16'
  controller_1dof_new_B.rtb_Delay16_idx_0 =
    controller_1dof_new_DW.Delay16_DSTATE[0];

  // Delay: '<S25>/Delay17'
  controller_1dof_new_B.rtb_Delay17_idx_0 =
    controller_1dof_new_DW.Delay17_DSTATE[0];

  // Delay: '<S25>/Delay18'
  controller_1dof_new_B.rtb_Delay18_idx_0 =
    controller_1dof_new_DW.Delay18_DSTATE[0];

  // SignalConversion generated from: '<S32>/ SFunction ' incorporates:
  //   Delay: '<S25>/Delay'
  //   Delay: '<S25>/Delay1'
  //   Delay: '<S25>/Delay10'
  //   Delay: '<S25>/Delay11'
  //   Delay: '<S25>/Delay12'
  //   Delay: '<S25>/Delay13'
  //   Delay: '<S25>/Delay14'
  //   Delay: '<S25>/Delay15'
  //   Delay: '<S25>/Delay16'
  //   Delay: '<S25>/Delay17'
  //   Delay: '<S25>/Delay18'
  //   Delay: '<S25>/Delay19'
  //   Delay: '<S25>/Delay2'
  //   Delay: '<S25>/Delay20'
  //   Delay: '<S25>/Delay21'
  //   Delay: '<S25>/Delay22'
  //   Delay: '<S25>/Delay23'
  //   Delay: '<S25>/Delay24'
  //   Delay: '<S25>/Delay25'
  //   Delay: '<S25>/Delay26'
  //   Delay: '<S25>/Delay27'
  //   Delay: '<S25>/Delay3'
  //   Delay: '<S25>/Delay4'
  //   Delay: '<S25>/Delay5'
  //   Delay: '<S25>/Delay6'
  //   Delay: '<S25>/Delay7'
  //   Delay: '<S25>/Delay8'
  //   Delay: '<S25>/Delay9'
  //   MATLAB Function: '<S25>/MATLAB Function'

  controller_1dof_new_B.TmpSignalConversionAtSFun_e[3] =
    controller_1dof_new_DW.Delay_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[6] =
    controller_1dof_new_DW.Delay1_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[9] =
    controller_1dof_new_DW.Delay2_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[12] =
    controller_1dof_new_DW.Delay3_DSTATE_j[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[15] =
    controller_1dof_new_DW.Delay4_DSTATE_e[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[18] =
    controller_1dof_new_DW.Delay5_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[21] =
    controller_1dof_new_DW.Delay6_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[24] =
    controller_1dof_new_DW.Delay7_DSTATE_o[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[27] =
    controller_1dof_new_DW.Delay8_DSTATE_n[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[30] =
    controller_1dof_new_DW.Delay9_DSTATE_i[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[33] =
    controller_1dof_new_DW.Delay10_DSTATE_f[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[36] =
    controller_1dof_new_DW.Delay11_DSTATE_k[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[39] =
    controller_1dof_new_DW.Delay12_DSTATE_n[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[42] =
    controller_1dof_new_DW.Delay13_DSTATE_g[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[45] =
    controller_1dof_new_DW.Delay14_DSTATE_g[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[48] =
    controller_1dof_new_DW.Delay15_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[51] =
    controller_1dof_new_DW.Delay20_DSTATE_h[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[54] =
    controller_1dof_new_DW.Delay21_DSTATE_d[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[57] =
    controller_1dof_new_DW.Delay22_DSTATE_h[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[60] =
    controller_1dof_new_DW.Delay23_DSTATE_p[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[63] =
    controller_1dof_new_DW.Delay24_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[66] =
    controller_1dof_new_DW.Delay25_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[69] =
    controller_1dof_new_DW.Delay26_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[72] =
    controller_1dof_new_DW.Delay27_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[75] =
    controller_1dof_new_DW.Delay16_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[78] =
    controller_1dof_new_DW.Delay17_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[81] =
    controller_1dof_new_DW.Delay18_DSTATE[0];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[84] =
    controller_1dof_new_DW.Delay19_DSTATE[0];

  // Delay: '<S25>/Delay'
  controller_1dof_new_B.rtb_Delay_l_idx_1 =
    controller_1dof_new_DW.Delay_DSTATE_p[1];

  // Delay: '<S25>/Delay1'
  controller_1dof_new_B.rtb_Delay1_n_idx_1 =
    controller_1dof_new_DW.Delay1_DSTATE_p[1];

  // Delay: '<S25>/Delay2'
  controller_1dof_new_B.rtb_Delay2_h_idx_1 =
    controller_1dof_new_DW.Delay2_DSTATE_p[1];

  // Delay: '<S25>/Delay3'
  controller_1dof_new_B.rtb_Delay3_p_idx_1 =
    controller_1dof_new_DW.Delay3_DSTATE_j[1];

  // Delay: '<S25>/Delay4'
  controller_1dof_new_B.rtb_Delay4_j_idx_1 =
    controller_1dof_new_DW.Delay4_DSTATE_e[1];

  // Delay: '<S25>/Delay5'
  controller_1dof_new_B.rtb_Delay5_e_idx_1 =
    controller_1dof_new_DW.Delay5_DSTATE_p[1];

  // Delay: '<S25>/Delay6'
  controller_1dof_new_B.rtb_Delay6_f_idx_1 =
    controller_1dof_new_DW.Delay6_DSTATE_p[1];

  // Delay: '<S25>/Delay7'
  controller_1dof_new_B.rtb_Delay7_i_idx_1 =
    controller_1dof_new_DW.Delay7_DSTATE_o[1];

  // Delay: '<S25>/Delay8'
  controller_1dof_new_B.rtb_Delay8_j_idx_1 =
    controller_1dof_new_DW.Delay8_DSTATE_n[1];

  // Delay: '<S25>/Delay9'
  controller_1dof_new_B.rtb_Delay9_j_idx_1 =
    controller_1dof_new_DW.Delay9_DSTATE_i[1];

  // Delay: '<S25>/Delay10'
  controller_1dof_new_B.rtb_Delay10_e_idx_1 =
    controller_1dof_new_DW.Delay10_DSTATE_f[1];

  // Delay: '<S25>/Delay11'
  controller_1dof_new_B.rtb_Delay11_n_idx_1 =
    controller_1dof_new_DW.Delay11_DSTATE_k[1];

  // Delay: '<S25>/Delay12'
  controller_1dof_new_B.rtb_Delay12_a_idx_1 =
    controller_1dof_new_DW.Delay12_DSTATE_n[1];

  // Delay: '<S25>/Delay13'
  controller_1dof_new_B.rtb_Delay13_h_idx_1 =
    controller_1dof_new_DW.Delay13_DSTATE_g[1];

  // Delay: '<S25>/Delay14'
  controller_1dof_new_B.rtb_Delay14_m_idx_1 =
    controller_1dof_new_DW.Delay14_DSTATE_g[1];

  // Delay: '<S25>/Delay15'
  controller_1dof_new_B.rtb_Delay15_idx_1 =
    controller_1dof_new_DW.Delay15_DSTATE[1];

  // Delay: '<S25>/Delay20'
  controller_1dof_new_B.rtb_Delay20_g_idx_1 =
    controller_1dof_new_DW.Delay20_DSTATE_h[1];

  // Delay: '<S25>/Delay21'
  controller_1dof_new_B.rtb_Delay21_e_idx_1 =
    controller_1dof_new_DW.Delay21_DSTATE_d[1];

  // Delay: '<S25>/Delay22'
  controller_1dof_new_B.rtb_Delay22_b_idx_1 =
    controller_1dof_new_DW.Delay22_DSTATE_h[1];

  // Delay: '<S25>/Delay23'
  controller_1dof_new_B.rtb_Delay23_g_idx_1 =
    controller_1dof_new_DW.Delay23_DSTATE_p[1];

  // Delay: '<S25>/Delay24'
  controller_1dof_new_B.rtb_Delay24_idx_1 =
    controller_1dof_new_DW.Delay24_DSTATE[1];

  // Delay: '<S25>/Delay25'
  controller_1dof_new_B.rtb_Delay25_idx_1 =
    controller_1dof_new_DW.Delay25_DSTATE[1];

  // Delay: '<S25>/Delay26'
  controller_1dof_new_B.rtb_Delay26_idx_1 =
    controller_1dof_new_DW.Delay26_DSTATE[1];

  // Delay: '<S25>/Delay27'
  controller_1dof_new_B.rtb_Delay27_idx_1 =
    controller_1dof_new_DW.Delay27_DSTATE[1];

  // Delay: '<S25>/Delay16'
  controller_1dof_new_B.rtb_Delay16_idx_1 =
    controller_1dof_new_DW.Delay16_DSTATE[1];

  // Delay: '<S25>/Delay17'
  controller_1dof_new_B.rtb_Delay17_idx_1 =
    controller_1dof_new_DW.Delay17_DSTATE[1];

  // Delay: '<S25>/Delay18'
  controller_1dof_new_B.rtb_Delay18_idx_1 =
    controller_1dof_new_DW.Delay18_DSTATE[1];

  // SignalConversion generated from: '<S32>/ SFunction ' incorporates:
  //   Delay: '<S25>/Delay'
  //   Delay: '<S25>/Delay1'
  //   Delay: '<S25>/Delay10'
  //   Delay: '<S25>/Delay11'
  //   Delay: '<S25>/Delay12'
  //   Delay: '<S25>/Delay13'
  //   Delay: '<S25>/Delay14'
  //   Delay: '<S25>/Delay15'
  //   Delay: '<S25>/Delay16'
  //   Delay: '<S25>/Delay17'
  //   Delay: '<S25>/Delay18'
  //   Delay: '<S25>/Delay19'
  //   Delay: '<S25>/Delay2'
  //   Delay: '<S25>/Delay20'
  //   Delay: '<S25>/Delay21'
  //   Delay: '<S25>/Delay22'
  //   Delay: '<S25>/Delay23'
  //   Delay: '<S25>/Delay24'
  //   Delay: '<S25>/Delay25'
  //   Delay: '<S25>/Delay26'
  //   Delay: '<S25>/Delay27'
  //   Delay: '<S25>/Delay3'
  //   Delay: '<S25>/Delay4'
  //   Delay: '<S25>/Delay5'
  //   Delay: '<S25>/Delay6'
  //   Delay: '<S25>/Delay7'
  //   Delay: '<S25>/Delay8'
  //   Delay: '<S25>/Delay9'
  //   MATLAB Function: '<S25>/MATLAB Function'

  controller_1dof_new_B.TmpSignalConversionAtSFun_e[4] =
    controller_1dof_new_DW.Delay_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[7] =
    controller_1dof_new_DW.Delay1_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[10] =
    controller_1dof_new_DW.Delay2_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[13] =
    controller_1dof_new_DW.Delay3_DSTATE_j[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[16] =
    controller_1dof_new_DW.Delay4_DSTATE_e[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[19] =
    controller_1dof_new_DW.Delay5_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[22] =
    controller_1dof_new_DW.Delay6_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[25] =
    controller_1dof_new_DW.Delay7_DSTATE_o[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[28] =
    controller_1dof_new_DW.Delay8_DSTATE_n[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[31] =
    controller_1dof_new_DW.Delay9_DSTATE_i[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[34] =
    controller_1dof_new_DW.Delay10_DSTATE_f[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[37] =
    controller_1dof_new_DW.Delay11_DSTATE_k[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[40] =
    controller_1dof_new_DW.Delay12_DSTATE_n[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[43] =
    controller_1dof_new_DW.Delay13_DSTATE_g[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[46] =
    controller_1dof_new_DW.Delay14_DSTATE_g[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[49] =
    controller_1dof_new_DW.Delay15_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[52] =
    controller_1dof_new_DW.Delay20_DSTATE_h[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[55] =
    controller_1dof_new_DW.Delay21_DSTATE_d[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[58] =
    controller_1dof_new_DW.Delay22_DSTATE_h[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[61] =
    controller_1dof_new_DW.Delay23_DSTATE_p[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[64] =
    controller_1dof_new_DW.Delay24_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[67] =
    controller_1dof_new_DW.Delay25_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[70] =
    controller_1dof_new_DW.Delay26_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[73] =
    controller_1dof_new_DW.Delay27_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[76] =
    controller_1dof_new_DW.Delay16_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[79] =
    controller_1dof_new_DW.Delay17_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[82] =
    controller_1dof_new_DW.Delay18_DSTATE[1];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[85] =
    controller_1dof_new_DW.Delay19_DSTATE[1];

  // Delay: '<S25>/Delay'
  controller_1dof_new_B.Delay_DSTATE_p = controller_1dof_new_DW.Delay_DSTATE_p[2];

  // Delay: '<S25>/Delay1'
  controller_1dof_new_B.Delay1_DSTATE_p =
    controller_1dof_new_DW.Delay1_DSTATE_p[2];

  // Delay: '<S25>/Delay2'
  controller_1dof_new_B.Delay2_DSTATE_p =
    controller_1dof_new_DW.Delay2_DSTATE_p[2];

  // Delay: '<S25>/Delay3'
  controller_1dof_new_B.Delay3_DSTATE_j =
    controller_1dof_new_DW.Delay3_DSTATE_j[2];

  // Delay: '<S25>/Delay4'
  controller_1dof_new_B.Delay4_DSTATE_e =
    controller_1dof_new_DW.Delay4_DSTATE_e[2];

  // Delay: '<S25>/Delay5'
  controller_1dof_new_B.Delay5_DSTATE_p =
    controller_1dof_new_DW.Delay5_DSTATE_p[2];

  // Delay: '<S25>/Delay6'
  controller_1dof_new_B.Delay6_DSTATE_p =
    controller_1dof_new_DW.Delay6_DSTATE_p[2];

  // Delay: '<S25>/Delay7'
  controller_1dof_new_B.Delay7_DSTATE_o =
    controller_1dof_new_DW.Delay7_DSTATE_o[2];

  // Delay: '<S25>/Delay8'
  controller_1dof_new_B.Delay8_DSTATE_n =
    controller_1dof_new_DW.Delay8_DSTATE_n[2];

  // Delay: '<S25>/Delay9'
  controller_1dof_new_B.Delay9_DSTATE_i =
    controller_1dof_new_DW.Delay9_DSTATE_i[2];

  // Delay: '<S25>/Delay10'
  controller_1dof_new_B.Delay10_DSTATE_f =
    controller_1dof_new_DW.Delay10_DSTATE_f[2];

  // Delay: '<S25>/Delay11'
  controller_1dof_new_B.Delay11_DSTATE_k =
    controller_1dof_new_DW.Delay11_DSTATE_k[2];

  // Delay: '<S25>/Delay12'
  controller_1dof_new_B.Delay12_DSTATE_n =
    controller_1dof_new_DW.Delay12_DSTATE_n[2];

  // Delay: '<S25>/Delay13'
  controller_1dof_new_B.Delay13_DSTATE_g =
    controller_1dof_new_DW.Delay13_DSTATE_g[2];

  // Delay: '<S25>/Delay14'
  controller_1dof_new_B.Delay14_DSTATE_g =
    controller_1dof_new_DW.Delay14_DSTATE_g[2];

  // Delay: '<S25>/Delay15'
  controller_1dof_new_B.Delay15_DSTATE = controller_1dof_new_DW.Delay15_DSTATE[2];

  // Delay: '<S25>/Delay20'
  controller_1dof_new_B.Delay20_DSTATE_h =
    controller_1dof_new_DW.Delay20_DSTATE_h[2];

  // Delay: '<S25>/Delay21'
  controller_1dof_new_B.Delay21_DSTATE_d =
    controller_1dof_new_DW.Delay21_DSTATE_d[2];

  // Delay: '<S25>/Delay22'
  controller_1dof_new_B.Delay22_DSTATE_h =
    controller_1dof_new_DW.Delay22_DSTATE_h[2];

  // Delay: '<S25>/Delay23'
  controller_1dof_new_B.Delay23_DSTATE_p =
    controller_1dof_new_DW.Delay23_DSTATE_p[2];

  // Delay: '<S25>/Delay24'
  controller_1dof_new_B.Delay24_DSTATE = controller_1dof_new_DW.Delay24_DSTATE[2];

  // Delay: '<S25>/Delay25'
  controller_1dof_new_B.Delay25_DSTATE = controller_1dof_new_DW.Delay25_DSTATE[2];

  // Delay: '<S25>/Delay26'
  controller_1dof_new_B.Delay26_DSTATE = controller_1dof_new_DW.Delay26_DSTATE[2];

  // Delay: '<S25>/Delay27'
  controller_1dof_new_B.Delay27_DSTATE = controller_1dof_new_DW.Delay27_DSTATE[2];

  // Delay: '<S25>/Delay16'
  controller_1dof_new_B.Delay16_DSTATE = controller_1dof_new_DW.Delay16_DSTATE[2];

  // Delay: '<S25>/Delay17'
  controller_1dof_new_B.Delay17_DSTATE = controller_1dof_new_DW.Delay17_DSTATE[2];

  // Delay: '<S25>/Delay18'
  controller_1dof_new_B.Delay18_DSTATE = controller_1dof_new_DW.Delay18_DSTATE[2];

  // SignalConversion generated from: '<S32>/ SFunction ' incorporates:
  //   Delay: '<S25>/Delay'
  //   Delay: '<S25>/Delay1'
  //   Delay: '<S25>/Delay10'
  //   Delay: '<S25>/Delay11'
  //   Delay: '<S25>/Delay12'
  //   Delay: '<S25>/Delay13'
  //   Delay: '<S25>/Delay14'
  //   Delay: '<S25>/Delay15'
  //   Delay: '<S25>/Delay16'
  //   Delay: '<S25>/Delay17'
  //   Delay: '<S25>/Delay18'
  //   Delay: '<S25>/Delay19'
  //   Delay: '<S25>/Delay2'
  //   Delay: '<S25>/Delay20'
  //   Delay: '<S25>/Delay21'
  //   Delay: '<S25>/Delay22'
  //   Delay: '<S25>/Delay23'
  //   Delay: '<S25>/Delay24'
  //   Delay: '<S25>/Delay25'
  //   Delay: '<S25>/Delay26'
  //   Delay: '<S25>/Delay27'
  //   Delay: '<S25>/Delay3'
  //   Delay: '<S25>/Delay4'
  //   Delay: '<S25>/Delay5'
  //   Delay: '<S25>/Delay6'
  //   Delay: '<S25>/Delay7'
  //   Delay: '<S25>/Delay8'
  //   Delay: '<S25>/Delay9'
  //   MATLAB Function: '<S25>/MATLAB Function'

  controller_1dof_new_B.TmpSignalConversionAtSFun_e[5] =
    controller_1dof_new_DW.Delay_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[8] =
    controller_1dof_new_DW.Delay1_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[11] =
    controller_1dof_new_DW.Delay2_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[14] =
    controller_1dof_new_DW.Delay3_DSTATE_j[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[17] =
    controller_1dof_new_DW.Delay4_DSTATE_e[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[20] =
    controller_1dof_new_DW.Delay5_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[23] =
    controller_1dof_new_DW.Delay6_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[26] =
    controller_1dof_new_DW.Delay7_DSTATE_o[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[29] =
    controller_1dof_new_DW.Delay8_DSTATE_n[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[32] =
    controller_1dof_new_DW.Delay9_DSTATE_i[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[35] =
    controller_1dof_new_DW.Delay10_DSTATE_f[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[38] =
    controller_1dof_new_DW.Delay11_DSTATE_k[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[41] =
    controller_1dof_new_DW.Delay12_DSTATE_n[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[44] =
    controller_1dof_new_DW.Delay13_DSTATE_g[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[47] =
    controller_1dof_new_DW.Delay14_DSTATE_g[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[50] =
    controller_1dof_new_DW.Delay15_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[53] =
    controller_1dof_new_DW.Delay20_DSTATE_h[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[56] =
    controller_1dof_new_DW.Delay21_DSTATE_d[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[59] =
    controller_1dof_new_DW.Delay22_DSTATE_h[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[62] =
    controller_1dof_new_DW.Delay23_DSTATE_p[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[65] =
    controller_1dof_new_DW.Delay24_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[68] =
    controller_1dof_new_DW.Delay25_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[71] =
    controller_1dof_new_DW.Delay26_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[74] =
    controller_1dof_new_DW.Delay27_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[77] =
    controller_1dof_new_DW.Delay16_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[80] =
    controller_1dof_new_DW.Delay17_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[83] =
    controller_1dof_new_DW.Delay18_DSTATE[2];
  controller_1dof_new_B.TmpSignalConversionAtSFun_e[86] =
    controller_1dof_new_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S25>/MATLAB Function'
  for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 < 29;
       controller_1dof_new_B.r2++) {
    i = (controller_1dof_new_B.r2 + 1) * 3;
    controller_1dof_new_B.ph_meas =
      controller_1dof_new_B.TmpSignalConversionAtSFun_e[i - 3];
    controller_1dof_new_B.y = controller_1dof_new_B.ph_meas *
      controller_1dof_new_B.ph_meas;
    controller_1dof_new_B.ph_meas =
      controller_1dof_new_B.TmpSignalConversionAtSFun_e[i - 2];
    controller_1dof_new_B.y += controller_1dof_new_B.ph_meas *
      controller_1dof_new_B.ph_meas;
    controller_1dof_new_B.ph_meas =
      controller_1dof_new_B.TmpSignalConversionAtSFun_e[i - 1];
    controller_1dof_new_B.b_norm[controller_1dof_new_B.r2] = sqrt
      (controller_1dof_new_B.ph_meas * controller_1dof_new_B.ph_meas +
       controller_1dof_new_B.y);
    controller_1dof_new_B.b_norm[controller_1dof_new_B.r2 + 29] =
      static_cast<real_T>(controller_1dof_new_B.r2) + 1.0;
  }

  for (i = 0; i < 28; i++) {
    controller_1dof_new_B.b = 27 - i;
    for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 <=
         controller_1dof_new_B.b; controller_1dof_new_B.r1++) {
      controller_1dof_new_B.ph_meas =
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1];
      controller_1dof_new_B.a21 =
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 1];
      if (controller_1dof_new_B.ph_meas > controller_1dof_new_B.a21) {
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1] =
          controller_1dof_new_B.a21;
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 1] =
          controller_1dof_new_B.ph_meas;
        controller_1dof_new_B.a21 =
          controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 29];
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 29] =
          controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 30];
        controller_1dof_new_B.b_norm[controller_1dof_new_B.r1 + 30] =
          controller_1dof_new_B.a21;
      }
    }
  }

  controller_1dof_new_B.ph_meas = controller_1dof_new_B.b_norm[41] * 3.0 - 2.0;
  controller_1dof_new_B.y = controller_1dof_new_B.TmpSignalConversionAtSFun_e[
    static_cast<int32_T>(controller_1dof_new_B.ph_meas) - 1];
  controller_1dof_new_B.y_idx_0 = controller_1dof_new_B.y;

  // Sum: '<S29>/Sum23' incorporates:
  //   Delay: '<S29>/Delay'
  //   Delay: '<S29>/Delay1'
  //   Delay: '<S29>/Delay10'
  //   Delay: '<S29>/Delay11'
  //   Delay: '<S29>/Delay12'
  //   Delay: '<S29>/Delay13'
  //   Delay: '<S29>/Delay14'
  //   Delay: '<S29>/Delay2'
  //   Delay: '<S29>/Delay20'
  //   Delay: '<S29>/Delay21'
  //   Delay: '<S29>/Delay22'
  //   Delay: '<S29>/Delay23'
  //   Delay: '<S29>/Delay3'
  //   Delay: '<S29>/Delay4'
  //   Delay: '<S29>/Delay5'
  //   Delay: '<S29>/Delay6'
  //   Delay: '<S29>/Delay7'
  //   Delay: '<S29>/Delay8'
  //   Delay: '<S29>/Delay9'
  //   Sum: '<S29>/Sum'
  //   Sum: '<S29>/Sum1'
  //   Sum: '<S29>/Sum10'
  //   Sum: '<S29>/Sum11'
  //   Sum: '<S29>/Sum12'
  //   Sum: '<S29>/Sum13'
  //   Sum: '<S29>/Sum14'
  //   Sum: '<S29>/Sum2'
  //   Sum: '<S29>/Sum20'
  //   Sum: '<S29>/Sum21'
  //   Sum: '<S29>/Sum22'
  //   Sum: '<S29>/Sum3'
  //   Sum: '<S29>/Sum4'
  //   Sum: '<S29>/Sum5'
  //   Sum: '<S29>/Sum6'
  //   Sum: '<S29>/Sum7'
  //   Sum: '<S29>/Sum8'
  //   Sum: '<S29>/Sum9'

  controller_1dof_new_B.Sum23_f =
    ((((((((((((((((((controller_1dof_new_DW.Delay_DSTATE[0] +
                      controller_1dof_new_B.y) +
                     controller_1dof_new_DW.Delay1_DSTATE[0]) +
                    controller_1dof_new_DW.Delay2_DSTATE_i[0]) +
                   controller_1dof_new_DW.Delay3_DSTATE_d[0]) +
                  controller_1dof_new_DW.Delay4_DSTATE[0]) +
                 controller_1dof_new_DW.Delay5_DSTATE[0]) +
                controller_1dof_new_DW.Delay6_DSTATE[0]) +
               controller_1dof_new_DW.Delay7_DSTATE[0]) +
              controller_1dof_new_DW.Delay8_DSTATE[0]) +
             controller_1dof_new_DW.Delay9_DSTATE[0]) +
            controller_1dof_new_DW.Delay10_DSTATE[0]) +
           controller_1dof_new_DW.Delay11_DSTATE[0]) +
          controller_1dof_new_DW.Delay12_DSTATE[0]) +
         controller_1dof_new_DW.Delay13_DSTATE[0]) +
        controller_1dof_new_DW.Delay14_DSTATE[0]) +
       controller_1dof_new_DW.Delay20_DSTATE[0]) +
      controller_1dof_new_DW.Delay21_DSTATE[0]) +
     controller_1dof_new_DW.Delay22_DSTATE[0]) +
    controller_1dof_new_DW.Delay23_DSTATE[0];
  controller_1dof_new_B.Sum23[0] = controller_1dof_new_B.Sum23_f;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  controller_1dof_new_B.Sum24[0] = controller_1dof_new_B.Sum23_f;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  controller_1dof_new_B.u_vect[0] = -(controller_1dof_new_P.Gain_Gain_b *
    controller_1dof_new_B.Sum23_f);

  // MATLAB Function: '<S25>/MATLAB Function'
  controller_1dof_new_B.y = controller_1dof_new_B.TmpSignalConversionAtSFun_e[
    static_cast<int32_T>(controller_1dof_new_B.ph_meas + 1.0) - 1];
  controller_1dof_new_B.y_idx_1 = controller_1dof_new_B.y;

  // Sum: '<S29>/Sum23' incorporates:
  //   Delay: '<S29>/Delay'
  //   Delay: '<S29>/Delay1'
  //   Delay: '<S29>/Delay10'
  //   Delay: '<S29>/Delay11'
  //   Delay: '<S29>/Delay12'
  //   Delay: '<S29>/Delay13'
  //   Delay: '<S29>/Delay14'
  //   Delay: '<S29>/Delay2'
  //   Delay: '<S29>/Delay20'
  //   Delay: '<S29>/Delay21'
  //   Delay: '<S29>/Delay22'
  //   Delay: '<S29>/Delay23'
  //   Delay: '<S29>/Delay3'
  //   Delay: '<S29>/Delay4'
  //   Delay: '<S29>/Delay5'
  //   Delay: '<S29>/Delay6'
  //   Delay: '<S29>/Delay7'
  //   Delay: '<S29>/Delay8'
  //   Delay: '<S29>/Delay9'
  //   Sum: '<S29>/Sum'
  //   Sum: '<S29>/Sum1'
  //   Sum: '<S29>/Sum10'
  //   Sum: '<S29>/Sum11'
  //   Sum: '<S29>/Sum12'
  //   Sum: '<S29>/Sum13'
  //   Sum: '<S29>/Sum14'
  //   Sum: '<S29>/Sum2'
  //   Sum: '<S29>/Sum20'
  //   Sum: '<S29>/Sum21'
  //   Sum: '<S29>/Sum22'
  //   Sum: '<S29>/Sum3'
  //   Sum: '<S29>/Sum4'
  //   Sum: '<S29>/Sum5'
  //   Sum: '<S29>/Sum6'
  //   Sum: '<S29>/Sum7'
  //   Sum: '<S29>/Sum8'
  //   Sum: '<S29>/Sum9'

  controller_1dof_new_B.Sum23_f =
    ((((((((((((((((((controller_1dof_new_DW.Delay_DSTATE[1] +
                      controller_1dof_new_B.y) +
                     controller_1dof_new_DW.Delay1_DSTATE[1]) +
                    controller_1dof_new_DW.Delay2_DSTATE_i[1]) +
                   controller_1dof_new_DW.Delay3_DSTATE_d[1]) +
                  controller_1dof_new_DW.Delay4_DSTATE[1]) +
                 controller_1dof_new_DW.Delay5_DSTATE[1]) +
                controller_1dof_new_DW.Delay6_DSTATE[1]) +
               controller_1dof_new_DW.Delay7_DSTATE[1]) +
              controller_1dof_new_DW.Delay8_DSTATE[1]) +
             controller_1dof_new_DW.Delay9_DSTATE[1]) +
            controller_1dof_new_DW.Delay10_DSTATE[1]) +
           controller_1dof_new_DW.Delay11_DSTATE[1]) +
          controller_1dof_new_DW.Delay12_DSTATE[1]) +
         controller_1dof_new_DW.Delay13_DSTATE[1]) +
        controller_1dof_new_DW.Delay14_DSTATE[1]) +
       controller_1dof_new_DW.Delay20_DSTATE[1]) +
      controller_1dof_new_DW.Delay21_DSTATE[1]) +
     controller_1dof_new_DW.Delay22_DSTATE[1]) +
    controller_1dof_new_DW.Delay23_DSTATE[1];
  controller_1dof_new_B.Sum23[1] = controller_1dof_new_B.Sum23_f;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  controller_1dof_new_B.Sum24[1] = controller_1dof_new_B.Sum23_f;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  controller_1dof_new_B.u_vect[1] = -(controller_1dof_new_P.Gain_Gain_b *
    controller_1dof_new_B.Sum23_f);

  // MATLAB Function: '<S25>/MATLAB Function'
  controller_1dof_new_B.y = controller_1dof_new_B.TmpSignalConversionAtSFun_e[
    static_cast<int32_T>(controller_1dof_new_B.ph_meas + 2.0) - 1];

  // Sum: '<S29>/Sum23' incorporates:
  //   Delay: '<S29>/Delay'
  //   Delay: '<S29>/Delay1'
  //   Delay: '<S29>/Delay10'
  //   Delay: '<S29>/Delay11'
  //   Delay: '<S29>/Delay12'
  //   Delay: '<S29>/Delay13'
  //   Delay: '<S29>/Delay14'
  //   Delay: '<S29>/Delay2'
  //   Delay: '<S29>/Delay20'
  //   Delay: '<S29>/Delay21'
  //   Delay: '<S29>/Delay22'
  //   Delay: '<S29>/Delay23'
  //   Delay: '<S29>/Delay3'
  //   Delay: '<S29>/Delay4'
  //   Delay: '<S29>/Delay5'
  //   Delay: '<S29>/Delay6'
  //   Delay: '<S29>/Delay7'
  //   Delay: '<S29>/Delay8'
  //   Delay: '<S29>/Delay9'
  //   Sum: '<S29>/Sum'
  //   Sum: '<S29>/Sum1'
  //   Sum: '<S29>/Sum10'
  //   Sum: '<S29>/Sum11'
  //   Sum: '<S29>/Sum12'
  //   Sum: '<S29>/Sum13'
  //   Sum: '<S29>/Sum14'
  //   Sum: '<S29>/Sum2'
  //   Sum: '<S29>/Sum20'
  //   Sum: '<S29>/Sum21'
  //   Sum: '<S29>/Sum22'
  //   Sum: '<S29>/Sum3'
  //   Sum: '<S29>/Sum4'
  //   Sum: '<S29>/Sum5'
  //   Sum: '<S29>/Sum6'
  //   Sum: '<S29>/Sum7'
  //   Sum: '<S29>/Sum8'
  //   Sum: '<S29>/Sum9'

  controller_1dof_new_B.Sum23_f =
    ((((((((((((((((((controller_1dof_new_DW.Delay_DSTATE[2] +
                      controller_1dof_new_B.y) +
                     controller_1dof_new_DW.Delay1_DSTATE[2]) +
                    controller_1dof_new_DW.Delay2_DSTATE_i[2]) +
                   controller_1dof_new_DW.Delay3_DSTATE_d[2]) +
                  controller_1dof_new_DW.Delay4_DSTATE[2]) +
                 controller_1dof_new_DW.Delay5_DSTATE[2]) +
                controller_1dof_new_DW.Delay6_DSTATE[2]) +
               controller_1dof_new_DW.Delay7_DSTATE[2]) +
              controller_1dof_new_DW.Delay8_DSTATE[2]) +
             controller_1dof_new_DW.Delay9_DSTATE[2]) +
            controller_1dof_new_DW.Delay10_DSTATE[2]) +
           controller_1dof_new_DW.Delay11_DSTATE[2]) +
          controller_1dof_new_DW.Delay12_DSTATE[2]) +
         controller_1dof_new_DW.Delay13_DSTATE[2]) +
        controller_1dof_new_DW.Delay14_DSTATE[2]) +
       controller_1dof_new_DW.Delay20_DSTATE[2]) +
      controller_1dof_new_DW.Delay21_DSTATE[2]) +
     controller_1dof_new_DW.Delay22_DSTATE[2]) +
    controller_1dof_new_DW.Delay23_DSTATE[2];
  controller_1dof_new_B.Sum23[2] = controller_1dof_new_B.Sum23_f;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  controller_1dof_new_B.Sum24[2] = controller_1dof_new_B.Sum23_f;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  controller_1dof_new_B.u_vect[2] = -(controller_1dof_new_P.Gain_Gain_b *
    controller_1dof_new_B.Sum23_f);
  controller_1dof_new_B.ph_meas = rt_atan2d_snf(controller_1dof_new_B.u_vect[1],
    controller_1dof_new_B.u_vect[2]);
  controller_1dof_new_B.temp[0] = controller_1dof_new_B.ph_meas;
  controller_1dof_new_B.Sum23_f = rt_atan2d_snf(-controller_1dof_new_B.u_vect[0],
    controller_1dof_new_B.u_vect[1] * sin(controller_1dof_new_B.ph_meas) +
    controller_1dof_new_B.u_vect[2] * cos(controller_1dof_new_B.ph_meas));
  controller_1dof_new_B.temp[1] = controller_1dof_new_B.Sum23_f;

  // MATLAB Function: '<S27>/EKF_RP' incorporates:
  //   Delay: '<S27>/Delay2'
  //   Memory: '<S27>/Memory2'
  //   Memory: '<S27>/Memory3'

  if (controller_1dof_new_B.DigitalClock1 -
      controller_1dof_new_DW.Memory2_PreviousInput >=
      controller_1dof_new_P.Ts_EKF_meas) {
    controller_1dof_new_DW.Memory2_PreviousInput =
      controller_1dof_new_B.DigitalClock1;
    memcpy(&controller_1dof_new_B.Pt1[0],
           &controller_1dof_new_DW.Memory3_PreviousInput[0], 25U * sizeof(real_T));
    controller_1dof_new_B.wq1 = controller_1dof_new_DW.Delay2_DSTATE_l[1];
    controller_1dof_new_B.wr1 = controller_1dof_new_DW.Delay2_DSTATE_l[2];
    for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 < 5;
         controller_1dof_new_B.r2++) {
      controller_1dof_new_B.xt[controller_1dof_new_B.r2] = 0.0;
    }

    memset(&controller_1dof_new_B.Pt[0], 0, 25U * sizeof(real_T));
    controller_1dof_new_B.b = static_cast<int32_T>(floor
      (controller_1dof_new_P.Ts_EKF_meas / controller_1dof_new_P.Ts_EKF_integr));
    for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 <
         controller_1dof_new_B.b; controller_1dof_new_B.r2++) {
      controller_1dof_new_B.cph = cos
        (controller_1dof_new_DW.Memory4_PreviousInput[0]);
      controller_1dof_new_B.cth = cos
        (controller_1dof_new_DW.Memory4_PreviousInput[1]);
      controller_1dof_new_B.sph = sin
        (controller_1dof_new_DW.Memory4_PreviousInput[0]);
      controller_1dof_new_B.tth = sin
        (controller_1dof_new_DW.Memory4_PreviousInput[1]) /
        controller_1dof_new_B.cth;
      controller_1dof_new_B.dv[0] = 1.0;
      controller_1dof_new_B.a21 = controller_1dof_new_B.sph *
        controller_1dof_new_B.tth;
      controller_1dof_new_B.dv[5] = controller_1dof_new_B.a21;
      controller_1dof_new_B.ps_meas_tmp_tmp = controller_1dof_new_B.cph *
        controller_1dof_new_B.tth;
      controller_1dof_new_B.dv[10] = controller_1dof_new_B.ps_meas_tmp_tmp;
      controller_1dof_new_B.dv[15] = 0.0;
      controller_1dof_new_B.dv[20] = 0.0;
      controller_1dof_new_B.dv[25] = 0.0;
      controller_1dof_new_B.dv[1] = 0.0;
      controller_1dof_new_B.dv[6] = controller_1dof_new_B.cph;
      controller_1dof_new_B.dv[11] = -controller_1dof_new_B.sph;
      controller_1dof_new_B.dv[16] = 0.0;
      controller_1dof_new_B.dv[21] = 0.0;
      controller_1dof_new_B.dv[26] = 0.0;
      for (i = 0; i < 6; i++) {
        controller_1dof_new_B.dv[5 * i + 2] = 0.0;
        controller_1dof_new_B.dv[5 * i + 3] = 0.0;
        controller_1dof_new_B.dv[5 * i + 4] = 0.0;
      }

      controller_1dof_new_B.dv3[0] = controller_1dof_new_DW.Delay2_DSTATE_l[0] -
        controller_1dof_new_DW.Memory4_PreviousInput[2];
      controller_1dof_new_B.cph_tmp = controller_1dof_new_B.wq1 -
        controller_1dof_new_DW.Memory4_PreviousInput[3];
      controller_1dof_new_B.dv3[1] = controller_1dof_new_B.cph_tmp;
      controller_1dof_new_B.d = controller_1dof_new_B.wr1 -
        controller_1dof_new_DW.Memory4_PreviousInput[4];
      controller_1dof_new_B.dv3[2] = controller_1dof_new_B.d;
      controller_1dof_new_B.dv3[3] =
        controller_1dof_new_DW.Memory4_PreviousInput[2];
      controller_1dof_new_B.dv3[4] =
        controller_1dof_new_DW.Memory4_PreviousInput[3];
      controller_1dof_new_B.dv3[5] =
        controller_1dof_new_DW.Memory4_PreviousInput[4];
      controller_1dof_new_B.Pt[0] = controller_1dof_new_B.ps_meas_tmp_tmp *
        controller_1dof_new_B.cph_tmp - controller_1dof_new_B.a21 *
        controller_1dof_new_B.d;
      controller_1dof_new_B.a21 = controller_1dof_new_B.d *
        controller_1dof_new_B.cph;
      controller_1dof_new_B.Pt[5] = (controller_1dof_new_B.cph_tmp *
        controller_1dof_new_B.sph + controller_1dof_new_B.a21) /
        (controller_1dof_new_B.cth * controller_1dof_new_B.cth);
      controller_1dof_new_B.Pt[10] = -1.0;
      controller_1dof_new_B.Pt[15] = -controller_1dof_new_B.sph *
        controller_1dof_new_B.tth;
      controller_1dof_new_B.Pt[20] = -controller_1dof_new_B.cph *
        controller_1dof_new_B.tth;
      controller_1dof_new_B.Pt[1] = controller_1dof_new_B.cph_tmp *
        -controller_1dof_new_B.sph - controller_1dof_new_B.a21;
      controller_1dof_new_B.Pt[6] = 0.0;
      controller_1dof_new_B.Pt[11] = 0.0;
      controller_1dof_new_B.Pt[16] = -controller_1dof_new_B.cph;
      controller_1dof_new_B.Pt[21] = controller_1dof_new_B.sph;
      for (i = 0; i < 5; i++) {
        controller_1dof_new_B.a21 = 0.0;
        for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 6;
             controller_1dof_new_B.r1++) {
          controller_1dof_new_B.a21 += controller_1dof_new_B.dv[5 *
            controller_1dof_new_B.r1 + i] *
            controller_1dof_new_B.dv3[controller_1dof_new_B.r1];
        }

        controller_1dof_new_B.xt[i] = controller_1dof_new_P.Ts_EKF_integr *
          controller_1dof_new_B.a21 +
          controller_1dof_new_DW.Memory4_PreviousInput[i];
        controller_1dof_new_B.Pt[5 * i + 2] = 0.0;
        controller_1dof_new_B.Pt[5 * i + 3] = 0.0;
        controller_1dof_new_B.Pt[5 * i + 4] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
             controller_1dof_new_B.r1++) {
          controller_1dof_new_B.a21 = 0.0;
          controller_1dof_new_B.tth = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i;
            controller_1dof_new_B.a21 += controller_1dof_new_B.Pt1[5 *
              controller_1dof_new_B.r1 + Pt1_tmp] *
              controller_1dof_new_B.Pt[At1_tmp];
            controller_1dof_new_B.tth += controller_1dof_new_B.Pt[5 * Pt1_tmp +
              controller_1dof_new_B.r1] * controller_1dof_new_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * controller_1dof_new_B.r1 + i;
          controller_1dof_new_B.Pt1_m[Pt1_tmp] = controller_1dof_new_B.tth;
          controller_1dof_new_B.At1[Pt1_tmp] = controller_1dof_new_B.a21;
        }
      }

      for (i = 0; i < 25; i++) {
        controller_1dof_new_B.Pt[i] = ((controller_1dof_new_B.At1[i] +
          controller_1dof_new_B.Pt1_m[i]) + controller_1dof_new_P.Q_phth[i]) *
          controller_1dof_new_P.Ts_EKF_integr + controller_1dof_new_B.Pt1[i];
      }

      for (i = 0; i < 5; i++) {
        controller_1dof_new_DW.Memory4_PreviousInput[i] =
          controller_1dof_new_B.xt[i];
      }

      memcpy(&controller_1dof_new_B.Pt1[0], &controller_1dof_new_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (i = 0; i < 10; i++) {
      controller_1dof_new_B.Lk[i] = c[i];
    }

    for (i = 0; i < 2; i++) {
      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
           controller_1dof_new_B.r1++) {
        controller_1dof_new_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_new_B.a21 += controller_1dof_new_B.Pt[5 * Pt1_tmp +
            controller_1dof_new_B.r1] * controller_1dof_new_B.Lk[5 * i + Pt1_tmp];
        }

        controller_1dof_new_B.B[controller_1dof_new_B.r1 + 5 * i] =
          controller_1dof_new_B.a21;
      }
    }

    for (i = 0; i < 10; i++) {
      controller_1dof_new_B.A_tmp_c[i] = b_b[i];
    }

    for (i = 0; i < 2; i++) {
      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
           controller_1dof_new_B.r1++) {
        controller_1dof_new_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_new_B.a21 += static_cast<real_T>
            (controller_1dof_new_B.A_tmp_c[(Pt1_tmp << 1) + i]) *
            controller_1dof_new_B.Pt[5 * controller_1dof_new_B.r1 + Pt1_tmp];
        }

        controller_1dof_new_B.A_tmp[i + (controller_1dof_new_B.r1 << 1)] =
          controller_1dof_new_B.a21;
      }

      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 2;
           controller_1dof_new_B.r1++) {
        controller_1dof_new_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_new_B.a21 += controller_1dof_new_B.A_tmp[(Pt1_tmp << 1)
            + i] * controller_1dof_new_B.Lk[5 * controller_1dof_new_B.r1 +
            Pt1_tmp];
        }

        controller_1dof_new_B.r2 = (controller_1dof_new_B.r1 << 1) + i;
        controller_1dof_new_B.minval[controller_1dof_new_B.r2] =
          controller_1dof_new_P.R_phth[controller_1dof_new_B.r2] +
          controller_1dof_new_B.a21;
      }
    }

    if (fabs(controller_1dof_new_B.minval[1]) > fabs
        (controller_1dof_new_B.minval[0])) {
      controller_1dof_new_B.r1 = 1;
      controller_1dof_new_B.r2 = 0;
    } else {
      controller_1dof_new_B.r1 = 0;
      controller_1dof_new_B.r2 = 1;
    }

    controller_1dof_new_B.a21 =
      controller_1dof_new_B.minval[controller_1dof_new_B.r2] /
      controller_1dof_new_B.minval[controller_1dof_new_B.r1];
    controller_1dof_new_B.tth =
      controller_1dof_new_B.minval[controller_1dof_new_B.r1 + 2];
    controller_1dof_new_B.wq1 =
      controller_1dof_new_B.minval[controller_1dof_new_B.r2 + 2] -
      controller_1dof_new_B.tth * controller_1dof_new_B.a21;
    for (i = 0; i < 5; i++) {
      Pt1_tmp = 5 * controller_1dof_new_B.r1 + i;
      controller_1dof_new_B.Lk[Pt1_tmp] = controller_1dof_new_B.B[i] /
        controller_1dof_new_B.minval[controller_1dof_new_B.r1];
      controller_1dof_new_B.b = 5 * controller_1dof_new_B.r2 + i;
      controller_1dof_new_B.Lk[controller_1dof_new_B.b] =
        (controller_1dof_new_B.B[i + 5] - controller_1dof_new_B.Lk[Pt1_tmp] *
         controller_1dof_new_B.tth) / controller_1dof_new_B.wq1;
      controller_1dof_new_B.Lk[Pt1_tmp] -=
        controller_1dof_new_B.Lk[controller_1dof_new_B.b] *
        controller_1dof_new_B.a21;
    }

    for (i = 0; i < 2; i++) {
      controller_1dof_new_B.a21 = 0.0;
      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
           controller_1dof_new_B.r1++) {
        controller_1dof_new_B.a21 += static_cast<real_T>
          (controller_1dof_new_B.A_tmp_c[(controller_1dof_new_B.r1 << 1) + i]) *
          controller_1dof_new_B.xt[controller_1dof_new_B.r1];
      }

      controller_1dof_new_B.temp_p[i] = controller_1dof_new_B.temp[i] -
        controller_1dof_new_B.a21;
    }

    controller_1dof_new_B.a21 = controller_1dof_new_B.temp_p[1];
    controller_1dof_new_B.tth = controller_1dof_new_B.temp_p[0];
    for (i = 0; i < 5; i++) {
      controller_1dof_new_DW.Memory4_PreviousInput[i] =
        (controller_1dof_new_B.Lk[i + 5] * controller_1dof_new_B.a21 +
         controller_1dof_new_B.Lk[i] * controller_1dof_new_B.tth) +
        controller_1dof_new_B.xt[i];
    }

    memset(&controller_1dof_new_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      controller_1dof_new_B.Pt1[i + 5 * i] = 1.0;
    }

    for (i = 0; i < 5; i++) {
      controller_1dof_new_B.a21 = controller_1dof_new_B.Lk[i + 5];
      controller_1dof_new_B.tth = controller_1dof_new_B.Lk[i];
      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
           controller_1dof_new_B.r1++) {
        Pt1_tmp = controller_1dof_new_B.r1 << 1;
        controller_1dof_new_B.r2 = 5 * controller_1dof_new_B.r1 + i;
        controller_1dof_new_B.Pt1_m[controller_1dof_new_B.r2] =
          controller_1dof_new_B.Pt1[controller_1dof_new_B.r2] -
          (static_cast<real_T>(controller_1dof_new_B.A_tmp_c[Pt1_tmp + 1]) *
           controller_1dof_new_B.a21 + static_cast<real_T>
           (controller_1dof_new_B.A_tmp_c[Pt1_tmp]) * controller_1dof_new_B.tth);
      }

      for (controller_1dof_new_B.r1 = 0; controller_1dof_new_B.r1 < 5;
           controller_1dof_new_B.r1++) {
        controller_1dof_new_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_new_B.a21 += controller_1dof_new_B.Pt1_m[5 * Pt1_tmp +
            i] * controller_1dof_new_B.Pt[5 * controller_1dof_new_B.r1 + Pt1_tmp];
        }

        controller_1dof_new_DW.Memory3_PreviousInput[i + 5 *
          controller_1dof_new_B.r1] = controller_1dof_new_B.a21;
      }
    }
  }

  // End of MATLAB Function: '<S27>/EKF_RP'

  // MATLAB Function: '<S18>/Y_computation' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion3'
  //   MATLAB Function: '<S18>/RPY_dot_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   MATLAB Function: '<S30>/EKF_Y'

  controller_1dof_new_B.sph = sin(controller_1dof_new_DW.Memory4_PreviousInput[0]);
  controller_1dof_new_B.cph_tmp = cos
    (controller_1dof_new_DW.Memory4_PreviousInput[0]);
  controller_1dof_new_B.tth = sin(controller_1dof_new_DW.Memory4_PreviousInput[1]);
  controller_1dof_new_B.ps_meas_tmp_tmp = cos
    (controller_1dof_new_DW.Memory4_PreviousInput[1]);
  controller_1dof_new_B.wq1 = rt_atan2d_snf(controller_1dof_new_B.In1_f.z *
    controller_1dof_new_B.sph - controller_1dof_new_B.In1_f.y *
    controller_1dof_new_B.cph_tmp, (controller_1dof_new_B.In1_f.y *
    controller_1dof_new_B.tth * controller_1dof_new_B.sph +
    controller_1dof_new_B.In1_f.x * controller_1dof_new_B.ps_meas_tmp_tmp) +
    controller_1dof_new_B.In1_f.z * controller_1dof_new_B.tth *
    controller_1dof_new_B.cph_tmp);
  if (controller_1dof_new_B.wq1 < 0.0) {
    controller_1dof_new_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S30>/EKF_Y' incorporates:
  //   Delay: '<S30>/Delay2'
  //   MATLAB Function: '<S18>/Y_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   Memory: '<S30>/Memory2'

  if (controller_1dof_new_B.DigitalClock1 -
      controller_1dof_new_DW.Memory2_PreviousInput_b >=
      controller_1dof_new_P.Ts_EKF_meas) {
    controller_1dof_new_DW.Memory2_PreviousInput_b =
      controller_1dof_new_B.DigitalClock1;
    controller_1dof_new_B.wr1 = 0.0;
    controller_1dof_new_B.cph = 0.0;
    controller_1dof_new_B.b = static_cast<int32_T>(floor
      (controller_1dof_new_P.Ts_EKF_meas / controller_1dof_new_P.Ts_EKF_integr));
    if (controller_1dof_new_B.b - 1 >= 0) {
      controller_1dof_new_B.dv4[0] = 0.0;
      controller_1dof_new_B.dv4[1] = controller_1dof_new_B.sph /
        controller_1dof_new_B.ps_meas_tmp_tmp;
      controller_1dof_new_B.dv4[2] = controller_1dof_new_B.cph_tmp /
        controller_1dof_new_B.ps_meas_tmp_tmp;
      controller_1dof_new_B.dv4[3] = 0.0;
      controller_1dof_new_B.dv4[4] = 0.0;
      controller_1dof_new_B.dv4[5] = 0.0;
      controller_1dof_new_B.dv5[0] = controller_1dof_new_DW.Delay2_DSTATE_n[0] -
        controller_1dof_new_DW.Memory4_PreviousInput[2];
      controller_1dof_new_B.dv5[1] = controller_1dof_new_DW.Delay2_DSTATE_n[1] -
        controller_1dof_new_DW.Memory4_PreviousInput[3];
      controller_1dof_new_B.dv5[2] = controller_1dof_new_DW.Delay2_DSTATE_n[2] -
        controller_1dof_new_DW.Memory4_PreviousInput[4];
      controller_1dof_new_B.dv5[3] =
        controller_1dof_new_DW.Memory4_PreviousInput[2];
      controller_1dof_new_B.dv5[4] =
        controller_1dof_new_DW.Memory4_PreviousInput[3];
      controller_1dof_new_B.dv5[5] =
        controller_1dof_new_DW.Memory4_PreviousInput[4];
    }

    for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 <
         controller_1dof_new_B.b; controller_1dof_new_B.r2++) {
      controller_1dof_new_B.a21 = 0.0;
      for (i = 0; i < 6; i++) {
        controller_1dof_new_B.a21 += controller_1dof_new_B.dv4[i] *
          controller_1dof_new_B.dv5[i];
      }

      controller_1dof_new_B.wr1 = controller_1dof_new_P.Ts_EKF_integr *
        controller_1dof_new_B.a21 +
        controller_1dof_new_DW.Memory4_PreviousInput_k;
      controller_1dof_new_B.cph = ((0.0 *
        controller_1dof_new_DW.Memory3_PreviousInput_f +
        controller_1dof_new_DW.Memory3_PreviousInput_f * 0.0) +
        controller_1dof_new_P.q_ps) * controller_1dof_new_P.Ts_EKF_integr +
        controller_1dof_new_DW.Memory3_PreviousInput_f;
      controller_1dof_new_DW.Memory4_PreviousInput_k = controller_1dof_new_B.wr1;
      controller_1dof_new_DW.Memory3_PreviousInput_f = controller_1dof_new_B.cph;
    }

    controller_1dof_new_B.a21 = controller_1dof_new_B.cph /
      (controller_1dof_new_B.cph + controller_1dof_new_P.r_ps);
    controller_1dof_new_DW.Memory4_PreviousInput_k = (controller_1dof_new_B.wq1
      - controller_1dof_new_B.wr1) * controller_1dof_new_B.a21 +
      controller_1dof_new_B.wr1;
    controller_1dof_new_DW.Memory3_PreviousInput_f = (1.0 -
      controller_1dof_new_B.a21) * controller_1dof_new_B.cph;
  }

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  controller_1dof_new_B.wr1 =
    controller_1dof_new_P.DiscreteTransferFcn_NumCoef_g *
    controller_1dof_new_DW.DiscreteTransferFcn_states_a;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  controller_1dof_new_B.cph =
    controller_1dof_new_P.DiscreteTransferFcn1_NumCoef_m *
    controller_1dof_new_DW.DiscreteTransferFcn1_states_e;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  controller_1dof_new_B.cth =
    controller_1dof_new_P.DiscreteTransferFcn2_NumCoef_h *
    controller_1dof_new_DW.DiscreteTransferFcn2_states_p;

  // MATLAB Function: '<S18>/RPY_dot_computation' incorporates:
  //   Constant: '<S18>/Constant6'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S18>/Y_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   Memory: '<S18>/Memory5'

  if ((controller_1dof_new_B.DigitalClock1 -
       controller_1dof_new_DW.Memory5_PreviousInput >=
       controller_1dof_new_P.Ts_EKF_meas) ||
      (controller_1dof_new_B.DigitalClock1 == 0.0)) {
    controller_1dof_new_B.tth /= controller_1dof_new_B.ps_meas_tmp_tmp;
    controller_1dof_new_DW.Memory5_PreviousInput =
      controller_1dof_new_B.DigitalClock1;
    controller_1dof_new_B.dv2[0] = 1.0;
    controller_1dof_new_B.dv2[3] = controller_1dof_new_B.sph *
      controller_1dof_new_B.tth;
    controller_1dof_new_B.dv2[6] = controller_1dof_new_B.cph_tmp *
      controller_1dof_new_B.tth;
    controller_1dof_new_B.dv2[1] = 0.0;
    controller_1dof_new_B.dv2[4] = controller_1dof_new_B.cph_tmp;
    controller_1dof_new_B.dv2[7] = -controller_1dof_new_B.sph;
    controller_1dof_new_B.dv2[2] = 0.0;
    controller_1dof_new_B.dv2[5] = controller_1dof_new_B.sph /
      controller_1dof_new_B.ps_meas_tmp_tmp;
    controller_1dof_new_B.dv2[8] = controller_1dof_new_B.cph_tmp /
      controller_1dof_new_B.ps_meas_tmp_tmp;
    controller_1dof_new_B.a21 = controller_1dof_new_B.wr1 -
      controller_1dof_new_DW.Memory4_PreviousInput[2] * 0.0;
    controller_1dof_new_B.tth = controller_1dof_new_B.cph -
      controller_1dof_new_DW.Memory4_PreviousInput[3] * 0.0;
    controller_1dof_new_B.sph = controller_1dof_new_B.cth -
      controller_1dof_new_DW.Memory4_PreviousInput[4] * 0.0;
    for (i = 0; i < 3; i++) {
      controller_1dof_new_DW.Memory6_PreviousInput[i] =
        (controller_1dof_new_B.dv2[i + 3] * controller_1dof_new_B.tth +
         controller_1dof_new_B.dv2[i] * controller_1dof_new_B.a21) +
        controller_1dof_new_B.dv2[i + 6] * controller_1dof_new_B.sph;
    }
  }

  // DataTypeConversion: '<S71>/CastU16En16' incorporates:
  //   Gain: '<Root>/Gain4'

  controller_1dof_new_B.a21 = floor(controller_1dof_new_P.Gain4_Gain *
    controller_1dof_new_B.DigitalClock1 * 65536.0);
  if (rtIsNaN(controller_1dof_new_B.a21) || rtIsInf(controller_1dof_new_B.a21))
  {
    controller_1dof_new_B.a21 = 0.0;
  } else {
    controller_1dof_new_B.a21 = fmod(controller_1dof_new_B.a21, 65536.0);
  }

  rtb_CastU16En16 = static_cast<uint16_T>(controller_1dof_new_B.a21 < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_new_B.a21)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_1dof_new_B.a21)));

  // End of DataTypeConversion: '<S71>/CastU16En16'

  // RelationalOperator: '<S71>/LTEp50' incorporates:
  //   Constant: '<S71>/Point50'
  //   DataTypeConversion: '<S71>/CastU16En16'

  rtb_LTEp50 = (rtb_CastU16En16 <= controller_1dof_new_P.Point50_Value);

  // Switch: '<S71>/QuadHandle1' incorporates:
  //   Constant: '<S71>/Point50'
  //   DataTypeConversion: '<S71>/CastU16En16'
  //   Sum: '<S71>/Amp50'

  if (!rtb_LTEp50) {
    rtb_CastU16En16 = static_cast<uint16_T>(rtb_CastU16En16 -
      controller_1dof_new_P.Point50_Value);
  }

  // End of Switch: '<S71>/QuadHandle1'

  // Switch: '<S71>/QuadHandle2' incorporates:
  //   Constant: '<S71>/Point25'
  //   Constant: '<S71>/Point50'
  //   RelationalOperator: '<S71>/LTEp25'
  //   Sum: '<S71>/p50mA'
  //   Switch: '<S71>/QuadHandle1'

  if (rtb_CastU16En16 > controller_1dof_new_P.Point25_Value) {
    rtb_CastU16En16 = static_cast<uint16_T>(controller_1dof_new_P.Point50_Value
      - rtb_CastU16En16);
  }

  // Lookup_n-D: '<S70>/Look-Up Table' incorporates:
  //   Switch: '<S71>/QuadHandle2'

  controller_1dof_new_B.bpIdx = plook_u32u16u64n48_evenc_gf(rtb_CastU16En16,
    controller_1dof_new_P.LookUpTable_bp01Data[0], static_cast<uint16_T>(
    static_cast<uint32_T>(controller_1dof_new_P.LookUpTable_bp01Data[1]) -
    controller_1dof_new_P.LookUpTable_bp01Data[0]), 32U,
    &controller_1dof_new_B.frac);

  // Switch: '<S71>/SignCorrected' incorporates:
  //   Lookup_n-D: '<S70>/Look-Up Table'
  //   UnaryMinus: '<S71>/Negate'

  if (rtb_LTEp50) {
    rtb_SignCorrected = intrp1d_s16s32s32u32u64n48l_f
      (controller_1dof_new_B.bpIdx, controller_1dof_new_B.frac,
       controller_1dof_new_P.LookUpTable_tableData);
  } else {
    rtb_SignCorrected = static_cast<int16_T>(-intrp1d_s16s32s32u32u64n48l_f
      (controller_1dof_new_B.bpIdx, controller_1dof_new_B.frac,
       controller_1dof_new_P.LookUpTable_tableData));
  }

  // End of Switch: '<S71>/SignCorrected'

  // Step: '<Root>/R ref'
  if (controller_1dof_new_B.DigitalClock1 < controller_1dof_new_P.Rref_Time) {
    controller_1dof_new_B.a21 = controller_1dof_new_P.Rref_Y0;
  } else {
    controller_1dof_new_B.a21 = controller_1dof_new_P.Rref_YFinal;
  }

  // Gain: '<Root>/Gain5' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'
  //   Gain: '<Root>/Gain3'
  //   Step: '<Root>/R ref'
  //   Sum: '<Root>/Sum'
  //   Switch: '<S71>/SignCorrected'

  controller_1dof_new_B.tth = (static_cast<real_T>(rtb_SignCorrected) *
    6.103515625E-5 * controller_1dof_new_P.Gain3_Gain +
    controller_1dof_new_B.a21) * controller_1dof_new_P.Gain5_Gain;

  // ManualSwitch: '<Root>/Manual Switch2'
  if (controller_1dof_new_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 < 28;
         controller_1dof_new_B.r2++) {
      controller_1dof_new_B.ManualSwitch2[controller_1dof_new_B.r2] =
        controller_1dof_new_P.Constant6_Value_f;
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
    //   MATLAB Function: '<S27>/MATLAB Function'
    //   MATLAB Function: '<S30>/EKF_Y'
    //   MATLAB Function: '<S39>/MATLAB Function'
    //   MATLAB Function: '<S39>/MATLAB Function1'
    //   SignalConversion generated from: '<S41>/ SFunction '
    //   SignalConversion generated from: '<S42>/ SFunction '

    controller_1dof_new_B.ManualSwitch2[0] = rtb_DataTypeConversion1_c;
    controller_1dof_new_B.ManualSwitch2[1] = rtb_DataTypeConversion1_h;
    controller_1dof_new_B.ManualSwitch2[2] = rtb_DataTypeConversion1_p;
    controller_1dof_new_B.ManualSwitch2[3] = rtb_DataTypeConversion1_o;
    controller_1dof_new_B.ManualSwitch2[4] = controller_1dof_new_B.In1_i.x;
    controller_1dof_new_B.ManualSwitch2[5] = controller_1dof_new_B.In1_i.y;
    controller_1dof_new_B.ManualSwitch2[6] = controller_1dof_new_B.In1_i.z;
    controller_1dof_new_B.ManualSwitch2[7] = controller_1dof_new_B.In1_n.x;
    controller_1dof_new_B.ManualSwitch2[8] = controller_1dof_new_B.In1_n.y;
    controller_1dof_new_B.ManualSwitch2[9] = controller_1dof_new_B.In1_n.z;
    controller_1dof_new_B.ManualSwitch2[10] =
      controller_1dof_new_B.In1.rollspeed;
    controller_1dof_new_B.ManualSwitch2[11] =
      controller_1dof_new_B.In1.pitchspeed;
    controller_1dof_new_B.ManualSwitch2[12] = controller_1dof_new_B.In1.yawspeed;
    controller_1dof_new_B.ManualSwitch2[13] = controller_1dof_new_B.y_k[0];
    controller_1dof_new_B.ManualSwitch2[14] = controller_1dof_new_B.y_k[1];
    controller_1dof_new_B.ManualSwitch2[15] = controller_1dof_new_B.y_k[2];
    controller_1dof_new_B.ManualSwitch2[16] = controller_1dof_new_B.In1_f.x;
    controller_1dof_new_B.ManualSwitch2[17] = controller_1dof_new_B.In1_f.y;
    controller_1dof_new_B.ManualSwitch2[18] = controller_1dof_new_B.In1_f.z;
    controller_1dof_new_B.ManualSwitch2[19] =
      controller_1dof_new_DW.Memory4_PreviousInput[0];
    controller_1dof_new_B.ManualSwitch2[20] =
      controller_1dof_new_DW.Memory4_PreviousInput[1];
    controller_1dof_new_B.ManualSwitch2[21] =
      controller_1dof_new_DW.Memory4_PreviousInput_k;
    controller_1dof_new_B.ManualSwitch2[22] =
      controller_1dof_new_DW.Memory6_PreviousInput[0];
    controller_1dof_new_B.ManualSwitch2[23] =
      controller_1dof_new_DW.Memory6_PreviousInput[1];
    controller_1dof_new_B.ManualSwitch2[24] =
      controller_1dof_new_DW.Memory6_PreviousInput[2];
    controller_1dof_new_B.ManualSwitch2[25] = controller_1dof_new_B.tth;
    controller_1dof_new_B.ManualSwitch2[26] =
      controller_1dof_new_P.Constant7_Value;
    controller_1dof_new_B.ManualSwitch2[27] =
      controller_1dof_new_P.Constant8_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  controller_1dof_new_B.TmpSignalConversionAt_asyncqueu[0] =
    controller_1dof_new_B.DigitalClock1;
  memcpy(&controller_1dof_new_B.TmpSignalConversionAt_asyncqueu[1],
         &controller_1dof_new_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S19>/MATLAB Function2'
  //   MATLAB Function: '<S30>/EKF_Y'
  //   SignalConversion generated from: '<S37>/ SFunction '

  controller_1dof_new_B.Gain2[2] = controller_1dof_new_P.Gain2_Gain *
    controller_1dof_new_DW.Memory4_PreviousInput_k;

  // SignalConversion generated from: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'

  controller_1dof_new_DW.Delay2_DSTATE_n[0] = controller_1dof_new_B.wr1;
  controller_1dof_new_DW.Delay2_DSTATE_n[1] = controller_1dof_new_B.cph;
  controller_1dof_new_DW.Delay2_DSTATE_n[2] = controller_1dof_new_B.cth;

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S27>/MATLAB Function'

  controller_1dof_new_B.Gain2[0] = controller_1dof_new_P.Gain2_Gain *
    controller_1dof_new_DW.Memory4_PreviousInput[0];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S18>/RP_computation'

  controller_1dof_new_B.Gain_e[0] = controller_1dof_new_P.Gain_Gain_e *
    controller_1dof_new_B.ph_meas;

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S27>/MATLAB Function'

  controller_1dof_new_B.Gain2[1] = controller_1dof_new_P.Gain2_Gain *
    controller_1dof_new_DW.Memory4_PreviousInput[1];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S18>/Y_computation'

  controller_1dof_new_B.Gain_e[1] = controller_1dof_new_B.Sum23_f *
    controller_1dof_new_P.Gain_Gain_e;
  controller_1dof_new_B.Gain_e[2] = controller_1dof_new_P.Gain_Gain_e *
    controller_1dof_new_B.wq1;

  // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion2'

  controller_1dof_new_B.y_c[0] = controller_1dof_new_B.In1_n.x;
  controller_1dof_new_B.y_c[1] = -static_cast<real_T>
    (controller_1dof_new_B.In1_n.y);
  controller_1dof_new_B.y_c[2] = -static_cast<real_T>
    (controller_1dof_new_B.In1_n.z);

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion1'

  controller_1dof_new_B.y_p[0] = -static_cast<real_T>
    (controller_1dof_new_B.In1_i.x);
  controller_1dof_new_B.y_p[1] = controller_1dof_new_B.In1_i.y;
  controller_1dof_new_B.y_p[2] = controller_1dof_new_B.In1_i.z;

  // Gain: '<S16>/Gain1'
  controller_1dof_new_B.Sum23_f = controller_1dof_new_B.y_c[0];
  controller_1dof_new_B.a21 = controller_1dof_new_B.y_c[1];
  controller_1dof_new_B.wq1 = controller_1dof_new_B.y_c[2];

  // Gain: '<S16>/Gain'
  controller_1dof_new_B.wr1 = controller_1dof_new_B.y_p[0];
  controller_1dof_new_B.cph = controller_1dof_new_B.y_p[1];
  controller_1dof_new_B.cth = controller_1dof_new_B.y_p[2];
  for (controller_1dof_new_B.r2 = 0; controller_1dof_new_B.r2 < 3;
       controller_1dof_new_B.r2++) {
    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.sph =
      controller_1dof_new_P.Rz[controller_1dof_new_B.r2];

    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.ph_meas = controller_1dof_new_B.sph *
      controller_1dof_new_B.Sum23_f;

    // Gain: '<S16>/Gain'
    controller_1dof_new_B.cph_tmp = controller_1dof_new_B.sph *
      controller_1dof_new_B.wr1;

    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.sph =
      controller_1dof_new_P.Rz[controller_1dof_new_B.r2 + 3];

    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.ph_meas += controller_1dof_new_B.sph *
      controller_1dof_new_B.a21;

    // Gain: '<S16>/Gain'
    controller_1dof_new_B.cph_tmp += controller_1dof_new_B.sph *
      controller_1dof_new_B.cph;

    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.sph =
      controller_1dof_new_P.Rz[controller_1dof_new_B.r2 + 6];

    // Gain: '<S16>/Gain'
    controller_1dof_new_B.TmpSignalConversionAtSFunct[controller_1dof_new_B.r2] =
      controller_1dof_new_B.sph * controller_1dof_new_B.cth +
      controller_1dof_new_B.cph_tmp;

    // Gain: '<S16>/Gain1'
    controller_1dof_new_B.u_vect[controller_1dof_new_B.r2] =
      controller_1dof_new_B.sph * controller_1dof_new_B.wq1 +
      controller_1dof_new_B.ph_meas;

    // Gain: '<Root>/Gain1'
    controller_1dof_new_B.Gain1_d[controller_1dof_new_B.r2] =
      controller_1dof_new_P.Gain1_Gain_b *
      controller_1dof_new_B.y_k[controller_1dof_new_B.r2];
  }

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  controller_1dof_new_B.y1_e = controller_1dof_new_B.Gain1_d[0];
  controller_1dof_new_B.y2_i = controller_1dof_new_B.Gain1_d[1];
  controller_1dof_new_B.y3_c = controller_1dof_new_B.Gain1_d[2];

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant5'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum2'

  if (controller_1dof_new_P.ManualSwitch_CurrentSetting == 1) {
    controller_1dof_new_B.a21 = controller_1dof_new_B.y1_e +
      controller_1dof_new_P.Constant5_Value;
  } else {
    controller_1dof_new_B.a21 = controller_1dof_new_B.y1_e +
      controller_1dof_new_P.Constant_Value_jx;
  }

  // Sum: '<S1>/Sum2' incorporates:
  //   Gain: '<Root>/Gain2'
  //   ManualSwitch: '<Root>/Manual Switch'

  controller_1dof_new_B.Sum2_h = controller_1dof_new_B.tth -
    controller_1dof_new_P.Gain2_Gain_o * controller_1dof_new_B.a21;

  // MATLAB Function: '<S4>/MATLAB Function1'
  controller_1dof_MATLABFunction1(controller_1dof_new_B.Gain_e,
    &controller_1dof_new_B.y1_j, &controller_1dof_new_B.y2_pc,
    &controller_1dof_new_B.y3_l, &controller_1dof_new_DW.sf_MATLABFunction1_i);

  // MATLAB Function: '<S19>/MATLAB Function7'
  controller_1dof_MATLABFunction1(controller_1dof_new_B.Gain2,
    &controller_1dof_new_B.y1_b, &controller_1dof_new_B.y2_p,
    &controller_1dof_new_B.y3_g, &controller_1dof_new_DW.sf_MATLABFunction7);

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/failsafe'

  for (i = 0; i < 8; i++) {
    controller_1dof_new_B.pwmValue[i] = 0U;
  }

  controller_1dof_new_B.pwmValue[0] = rtb_DataTypeConversion1_c;
  controller_1dof_new_B.pwmValue[1] = rtb_DataTypeConversion1_h;
  controller_1dof_new_B.pwmValue[2] = rtb_DataTypeConversion1_p;
  controller_1dof_new_B.pwmValue[3] = rtb_DataTypeConversion1_o;
  if (rtb_startingswitch) {
    if (!controller_1dof_new_DW.obj.isArmed) {
      controller_1dof_new_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_c = pwm_arm
        (&controller_1dof_new_DW.obj.pwmDevHandler,
         &controller_1dof_new_DW.obj.armAdvertiseObj);
      controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
    }

    rtb_DataTypeConversion1_c = pwm_setServo
      (&controller_1dof_new_DW.obj.pwmDevHandler,
       controller_1dof_new_DW.obj.servoCount,
       controller_1dof_new_DW.obj.channelMask, &controller_1dof_new_B.pwmValue[0],
       controller_1dof_new_DW.obj.isMain,
       &controller_1dof_new_DW.obj.actuatorAdvertiseObj);
    controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  } else {
    rtb_DataTypeConversion1_c = pwm_disarm
      (&controller_1dof_new_DW.obj.pwmDevHandler,
       &controller_1dof_new_DW.obj.armAdvertiseObj);
    controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
    controller_1dof_new_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_c = pwm_resetServo
      (&controller_1dof_new_DW.obj.pwmDevHandler,
       controller_1dof_new_DW.obj.servoCount,
       controller_1dof_new_DW.obj.channelMask, controller_1dof_new_DW.obj.isMain,
       &controller_1dof_new_DW.obj.actuatorAdvertiseObj);
    controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  if (controller_1dof_new_DW.obj.isMain) {
    rtb_DataTypeConversion1_c = pwm_forceFailsafe
      (&controller_1dof_new_DW.obj.pwmDevHandler, static_cast<int32_T>
       (controller_1dof_new_P.failsafe_Value));
    controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_new_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'
  // MATLABSystem: '<S6>/SourceBlock'
  rtb_LTEp50 = uORB_read_step(controller_1dof_new_DW.obj_d.orbMetadataObj,
    &controller_1dof_new_DW.obj_d.eventStructObj,
    &controller_1dof_new_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S47>/Enable'

  if (rtb_LTEp50) {
    // SignalConversion generated from: '<S47>/In1'
    controller_1dof_new_B.In1_h = controller_1dof_new_B.b_varargout_2_c;
    srUpdateBC(controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  controller_1dof_new_B.SignalConversion[0] =
    controller_1dof_new_B.In1_h.output[0];
  controller_1dof_new_B.SignalConversion[1] =
    controller_1dof_new_B.In1_h.output[1];
  controller_1dof_new_B.SignalConversion[2] =
    controller_1dof_new_B.In1_h.output[2];
  controller_1dof_new_B.SignalConversion[3] =
    controller_1dof_new_B.In1_h.output[3];

  // Update for Delay: '<S1>/Delay3'
  controller_1dof_new_DW.Delay3_DSTATE = controller_1dof_new_B.u_sat;

  // Update for DiscreteStateSpace: '<S10>/Internal'
  {
    controller_1dof_new_DW.Internal_DSTATE = controller_1dof_new_B.Sum2_h +
      controller_1dof_new_P.Internal_A*controller_1dof_new_DW.Internal_DSTATE;
  }

  // Update for Delay: '<S1>/Delay2'
  controller_1dof_new_DW.Delay2_DSTATE[0] = controller_1dof_new_B.x_idx_0;
  controller_1dof_new_DW.Delay2_DSTATE[1] = controller_1dof_new_B.x;

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn'

  controller_1dof_new_DW.DiscreteTransferFcn_states =
    (controller_1dof_new_P.DiscreteTransferFcn_NumCoef_gv *
     controller_1dof_new_DW.DiscreteTransferFcn_states_f -
     controller_1dof_new_P.DiscreteTransferFcn_DenCoef[1] *
     controller_1dof_new_DW.DiscreteTransferFcn_states) /
    controller_1dof_new_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1'

  controller_1dof_new_DW.DiscreteTransferFcn1_states =
    (controller_1dof_new_P.DiscreteTransferFcn1_NumCoef_o *
     controller_1dof_new_DW.DiscreteTransferFcn1_states_d -
     controller_1dof_new_P.DiscreteTransferFcn1_DenCoef[1] *
     controller_1dof_new_DW.DiscreteTransferFcn1_states) /
    controller_1dof_new_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2'

  controller_1dof_new_DW.DiscreteTransferFcn2_states =
    (controller_1dof_new_P.DiscreteTransferFcn2_NumCoef_g *
     controller_1dof_new_DW.DiscreteTransferFcn2_states_p2 -
     controller_1dof_new_P.DiscreteTransferFcn2_DenCoef[1] *
     controller_1dof_new_DW.DiscreteTransferFcn2_states) /
    controller_1dof_new_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S25>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'

  controller_1dof_new_DW.Delay_DSTATE_p[0] = controller_1dof_new_B.y_g;
  controller_1dof_new_DW.Delay_DSTATE_p[1] = controller_1dof_new_B.y_g1;
  controller_1dof_new_DW.Delay_DSTATE_p[2] = controller_1dof_new_B.y_m;

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  controller_1dof_new_DW.Delay23_DSTATE[0] =
    controller_1dof_new_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  controller_1dof_new_DW.Delay22_DSTATE[0] =
    controller_1dof_new_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  controller_1dof_new_DW.Delay21_DSTATE[0] =
    controller_1dof_new_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  controller_1dof_new_DW.Delay20_DSTATE[0] =
    controller_1dof_new_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  controller_1dof_new_DW.Delay14_DSTATE[0] =
    controller_1dof_new_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  controller_1dof_new_DW.Delay13_DSTATE[0] =
    controller_1dof_new_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  controller_1dof_new_DW.Delay12_DSTATE[0] =
    controller_1dof_new_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  controller_1dof_new_DW.Delay11_DSTATE[0] =
    controller_1dof_new_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  controller_1dof_new_DW.Delay10_DSTATE[0] =
    controller_1dof_new_DW.Delay9_DSTATE[0];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  controller_1dof_new_DW.Delay9_DSTATE[0] =
    controller_1dof_new_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  controller_1dof_new_DW.Delay8_DSTATE[0] =
    controller_1dof_new_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  controller_1dof_new_DW.Delay7_DSTATE[0] =
    controller_1dof_new_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  controller_1dof_new_DW.Delay6_DSTATE[0] =
    controller_1dof_new_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  controller_1dof_new_DW.Delay5_DSTATE[0] =
    controller_1dof_new_DW.Delay4_DSTATE[0];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  controller_1dof_new_DW.Delay4_DSTATE[0] =
    controller_1dof_new_DW.Delay3_DSTATE_d[0];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  controller_1dof_new_DW.Delay3_DSTATE_d[0] =
    controller_1dof_new_DW.Delay2_DSTATE_i[0];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  controller_1dof_new_DW.Delay2_DSTATE_i[0] =
    controller_1dof_new_DW.Delay1_DSTATE[0];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  controller_1dof_new_DW.Delay1_DSTATE[0] = controller_1dof_new_DW.Delay_DSTATE
    [0];

  // Update for Delay: '<S29>/Delay'
  controller_1dof_new_DW.Delay_DSTATE[0] = controller_1dof_new_B.y_idx_0;

  // Update for Delay: '<S25>/Delay1'
  controller_1dof_new_DW.Delay1_DSTATE_p[0] =
    controller_1dof_new_B.rtb_Delay_l_idx_0;

  // Update for Delay: '<S25>/Delay2'
  controller_1dof_new_DW.Delay2_DSTATE_p[0] =
    controller_1dof_new_B.rtb_Delay1_n_idx_0;

  // Update for Delay: '<S25>/Delay3'
  controller_1dof_new_DW.Delay3_DSTATE_j[0] =
    controller_1dof_new_B.rtb_Delay2_h_idx_0;

  // Update for Delay: '<S25>/Delay4'
  controller_1dof_new_DW.Delay4_DSTATE_e[0] =
    controller_1dof_new_B.rtb_Delay3_p_idx_0;

  // Update for Delay: '<S25>/Delay5'
  controller_1dof_new_DW.Delay5_DSTATE_p[0] =
    controller_1dof_new_B.rtb_Delay4_j_idx_0;

  // Update for Delay: '<S25>/Delay6'
  controller_1dof_new_DW.Delay6_DSTATE_p[0] =
    controller_1dof_new_B.rtb_Delay5_e_idx_0;

  // Update for Delay: '<S25>/Delay7'
  controller_1dof_new_DW.Delay7_DSTATE_o[0] =
    controller_1dof_new_B.rtb_Delay6_f_idx_0;

  // Update for Delay: '<S25>/Delay8'
  controller_1dof_new_DW.Delay8_DSTATE_n[0] =
    controller_1dof_new_B.rtb_Delay7_i_idx_0;

  // Update for Delay: '<S25>/Delay9'
  controller_1dof_new_DW.Delay9_DSTATE_i[0] =
    controller_1dof_new_B.rtb_Delay8_j_idx_0;

  // Update for Delay: '<S25>/Delay10'
  controller_1dof_new_DW.Delay10_DSTATE_f[0] =
    controller_1dof_new_B.rtb_Delay9_j_idx_0;

  // Update for Delay: '<S25>/Delay11'
  controller_1dof_new_DW.Delay11_DSTATE_k[0] =
    controller_1dof_new_B.rtb_Delay10_e_idx_0;

  // Update for Delay: '<S25>/Delay12'
  controller_1dof_new_DW.Delay12_DSTATE_n[0] =
    controller_1dof_new_B.rtb_Delay11_n_idx_0;

  // Update for Delay: '<S25>/Delay13'
  controller_1dof_new_DW.Delay13_DSTATE_g[0] =
    controller_1dof_new_B.rtb_Delay12_a_idx_0;

  // Update for Delay: '<S25>/Delay14'
  controller_1dof_new_DW.Delay14_DSTATE_g[0] =
    controller_1dof_new_B.rtb_Delay13_h_idx_0;

  // Update for Delay: '<S25>/Delay15'
  controller_1dof_new_DW.Delay15_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay14_m_idx_0;

  // Update for Delay: '<S25>/Delay20'
  controller_1dof_new_DW.Delay20_DSTATE_h[0] =
    controller_1dof_new_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S25>/Delay21'
  controller_1dof_new_DW.Delay21_DSTATE_d[0] =
    controller_1dof_new_B.rtb_Delay20_g_idx_0;

  // Update for Delay: '<S25>/Delay22'
  controller_1dof_new_DW.Delay22_DSTATE_h[0] =
    controller_1dof_new_B.rtb_Delay21_e_idx_0;

  // Update for Delay: '<S25>/Delay23'
  controller_1dof_new_DW.Delay23_DSTATE_p[0] =
    controller_1dof_new_B.rtb_Delay22_b_idx_0;

  // Update for Delay: '<S25>/Delay24'
  controller_1dof_new_DW.Delay24_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay23_g_idx_0;

  // Update for Delay: '<S25>/Delay25'
  controller_1dof_new_DW.Delay25_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S25>/Delay26'
  controller_1dof_new_DW.Delay26_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S25>/Delay27'
  controller_1dof_new_DW.Delay27_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S25>/Delay16'
  controller_1dof_new_DW.Delay16_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S25>/Delay17'
  controller_1dof_new_DW.Delay17_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S25>/Delay18'
  controller_1dof_new_DW.Delay18_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S25>/Delay19'
  controller_1dof_new_DW.Delay19_DSTATE[0] =
    controller_1dof_new_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  controller_1dof_new_DW.Delay2_DSTATE_l[0] =
    controller_1dof_new_DW.Delay2_DSTATE_n[0];

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  controller_1dof_new_DW.Delay23_DSTATE[1] =
    controller_1dof_new_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  controller_1dof_new_DW.Delay22_DSTATE[1] =
    controller_1dof_new_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  controller_1dof_new_DW.Delay21_DSTATE[1] =
    controller_1dof_new_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  controller_1dof_new_DW.Delay20_DSTATE[1] =
    controller_1dof_new_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  controller_1dof_new_DW.Delay14_DSTATE[1] =
    controller_1dof_new_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  controller_1dof_new_DW.Delay13_DSTATE[1] =
    controller_1dof_new_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  controller_1dof_new_DW.Delay12_DSTATE[1] =
    controller_1dof_new_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  controller_1dof_new_DW.Delay11_DSTATE[1] =
    controller_1dof_new_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  controller_1dof_new_DW.Delay10_DSTATE[1] =
    controller_1dof_new_DW.Delay9_DSTATE[1];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  controller_1dof_new_DW.Delay9_DSTATE[1] =
    controller_1dof_new_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  controller_1dof_new_DW.Delay8_DSTATE[1] =
    controller_1dof_new_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  controller_1dof_new_DW.Delay7_DSTATE[1] =
    controller_1dof_new_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  controller_1dof_new_DW.Delay6_DSTATE[1] =
    controller_1dof_new_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  controller_1dof_new_DW.Delay5_DSTATE[1] =
    controller_1dof_new_DW.Delay4_DSTATE[1];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  controller_1dof_new_DW.Delay4_DSTATE[1] =
    controller_1dof_new_DW.Delay3_DSTATE_d[1];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  controller_1dof_new_DW.Delay3_DSTATE_d[1] =
    controller_1dof_new_DW.Delay2_DSTATE_i[1];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  controller_1dof_new_DW.Delay2_DSTATE_i[1] =
    controller_1dof_new_DW.Delay1_DSTATE[1];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  controller_1dof_new_DW.Delay1_DSTATE[1] = controller_1dof_new_DW.Delay_DSTATE
    [1];

  // Update for Delay: '<S29>/Delay'
  controller_1dof_new_DW.Delay_DSTATE[1] = controller_1dof_new_B.y_idx_1;

  // Update for Delay: '<S25>/Delay1'
  controller_1dof_new_DW.Delay1_DSTATE_p[1] =
    controller_1dof_new_B.rtb_Delay_l_idx_1;

  // Update for Delay: '<S25>/Delay2'
  controller_1dof_new_DW.Delay2_DSTATE_p[1] =
    controller_1dof_new_B.rtb_Delay1_n_idx_1;

  // Update for Delay: '<S25>/Delay3'
  controller_1dof_new_DW.Delay3_DSTATE_j[1] =
    controller_1dof_new_B.rtb_Delay2_h_idx_1;

  // Update for Delay: '<S25>/Delay4'
  controller_1dof_new_DW.Delay4_DSTATE_e[1] =
    controller_1dof_new_B.rtb_Delay3_p_idx_1;

  // Update for Delay: '<S25>/Delay5'
  controller_1dof_new_DW.Delay5_DSTATE_p[1] =
    controller_1dof_new_B.rtb_Delay4_j_idx_1;

  // Update for Delay: '<S25>/Delay6'
  controller_1dof_new_DW.Delay6_DSTATE_p[1] =
    controller_1dof_new_B.rtb_Delay5_e_idx_1;

  // Update for Delay: '<S25>/Delay7'
  controller_1dof_new_DW.Delay7_DSTATE_o[1] =
    controller_1dof_new_B.rtb_Delay6_f_idx_1;

  // Update for Delay: '<S25>/Delay8'
  controller_1dof_new_DW.Delay8_DSTATE_n[1] =
    controller_1dof_new_B.rtb_Delay7_i_idx_1;

  // Update for Delay: '<S25>/Delay9'
  controller_1dof_new_DW.Delay9_DSTATE_i[1] =
    controller_1dof_new_B.rtb_Delay8_j_idx_1;

  // Update for Delay: '<S25>/Delay10'
  controller_1dof_new_DW.Delay10_DSTATE_f[1] =
    controller_1dof_new_B.rtb_Delay9_j_idx_1;

  // Update for Delay: '<S25>/Delay11'
  controller_1dof_new_DW.Delay11_DSTATE_k[1] =
    controller_1dof_new_B.rtb_Delay10_e_idx_1;

  // Update for Delay: '<S25>/Delay12'
  controller_1dof_new_DW.Delay12_DSTATE_n[1] =
    controller_1dof_new_B.rtb_Delay11_n_idx_1;

  // Update for Delay: '<S25>/Delay13'
  controller_1dof_new_DW.Delay13_DSTATE_g[1] =
    controller_1dof_new_B.rtb_Delay12_a_idx_1;

  // Update for Delay: '<S25>/Delay14'
  controller_1dof_new_DW.Delay14_DSTATE_g[1] =
    controller_1dof_new_B.rtb_Delay13_h_idx_1;

  // Update for Delay: '<S25>/Delay15'
  controller_1dof_new_DW.Delay15_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay14_m_idx_1;

  // Update for Delay: '<S25>/Delay20'
  controller_1dof_new_DW.Delay20_DSTATE_h[1] =
    controller_1dof_new_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S25>/Delay21'
  controller_1dof_new_DW.Delay21_DSTATE_d[1] =
    controller_1dof_new_B.rtb_Delay20_g_idx_1;

  // Update for Delay: '<S25>/Delay22'
  controller_1dof_new_DW.Delay22_DSTATE_h[1] =
    controller_1dof_new_B.rtb_Delay21_e_idx_1;

  // Update for Delay: '<S25>/Delay23'
  controller_1dof_new_DW.Delay23_DSTATE_p[1] =
    controller_1dof_new_B.rtb_Delay22_b_idx_1;

  // Update for Delay: '<S25>/Delay24'
  controller_1dof_new_DW.Delay24_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay23_g_idx_1;

  // Update for Delay: '<S25>/Delay25'
  controller_1dof_new_DW.Delay25_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S25>/Delay26'
  controller_1dof_new_DW.Delay26_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S25>/Delay27'
  controller_1dof_new_DW.Delay27_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S25>/Delay16'
  controller_1dof_new_DW.Delay16_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S25>/Delay17'
  controller_1dof_new_DW.Delay17_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S25>/Delay18'
  controller_1dof_new_DW.Delay18_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S25>/Delay19'
  controller_1dof_new_DW.Delay19_DSTATE[1] =
    controller_1dof_new_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  controller_1dof_new_DW.Delay2_DSTATE_l[1] =
    controller_1dof_new_DW.Delay2_DSTATE_n[1];

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  controller_1dof_new_DW.Delay23_DSTATE[2] =
    controller_1dof_new_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  controller_1dof_new_DW.Delay22_DSTATE[2] =
    controller_1dof_new_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  controller_1dof_new_DW.Delay21_DSTATE[2] =
    controller_1dof_new_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  controller_1dof_new_DW.Delay20_DSTATE[2] =
    controller_1dof_new_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  controller_1dof_new_DW.Delay14_DSTATE[2] =
    controller_1dof_new_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  controller_1dof_new_DW.Delay13_DSTATE[2] =
    controller_1dof_new_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  controller_1dof_new_DW.Delay12_DSTATE[2] =
    controller_1dof_new_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  controller_1dof_new_DW.Delay11_DSTATE[2] =
    controller_1dof_new_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  controller_1dof_new_DW.Delay10_DSTATE[2] =
    controller_1dof_new_DW.Delay9_DSTATE[2];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  controller_1dof_new_DW.Delay9_DSTATE[2] =
    controller_1dof_new_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  controller_1dof_new_DW.Delay8_DSTATE[2] =
    controller_1dof_new_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  controller_1dof_new_DW.Delay7_DSTATE[2] =
    controller_1dof_new_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  controller_1dof_new_DW.Delay6_DSTATE[2] =
    controller_1dof_new_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  controller_1dof_new_DW.Delay5_DSTATE[2] =
    controller_1dof_new_DW.Delay4_DSTATE[2];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  controller_1dof_new_DW.Delay4_DSTATE[2] =
    controller_1dof_new_DW.Delay3_DSTATE_d[2];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  controller_1dof_new_DW.Delay3_DSTATE_d[2] =
    controller_1dof_new_DW.Delay2_DSTATE_i[2];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  controller_1dof_new_DW.Delay2_DSTATE_i[2] =
    controller_1dof_new_DW.Delay1_DSTATE[2];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  controller_1dof_new_DW.Delay1_DSTATE[2] = controller_1dof_new_DW.Delay_DSTATE
    [2];

  // Update for Delay: '<S29>/Delay'
  controller_1dof_new_DW.Delay_DSTATE[2] = controller_1dof_new_B.y;

  // Update for Delay: '<S25>/Delay1' incorporates:
  //   Delay: '<S25>/Delay'

  controller_1dof_new_DW.Delay1_DSTATE_p[2] =
    controller_1dof_new_B.Delay_DSTATE_p;

  // Update for Delay: '<S25>/Delay2' incorporates:
  //   Delay: '<S25>/Delay1'

  controller_1dof_new_DW.Delay2_DSTATE_p[2] =
    controller_1dof_new_B.Delay1_DSTATE_p;

  // Update for Delay: '<S25>/Delay3' incorporates:
  //   Delay: '<S25>/Delay2'

  controller_1dof_new_DW.Delay3_DSTATE_j[2] =
    controller_1dof_new_B.Delay2_DSTATE_p;

  // Update for Delay: '<S25>/Delay4' incorporates:
  //   Delay: '<S25>/Delay3'

  controller_1dof_new_DW.Delay4_DSTATE_e[2] =
    controller_1dof_new_B.Delay3_DSTATE_j;

  // Update for Delay: '<S25>/Delay5' incorporates:
  //   Delay: '<S25>/Delay4'

  controller_1dof_new_DW.Delay5_DSTATE_p[2] =
    controller_1dof_new_B.Delay4_DSTATE_e;

  // Update for Delay: '<S25>/Delay6' incorporates:
  //   Delay: '<S25>/Delay5'

  controller_1dof_new_DW.Delay6_DSTATE_p[2] =
    controller_1dof_new_B.Delay5_DSTATE_p;

  // Update for Delay: '<S25>/Delay7' incorporates:
  //   Delay: '<S25>/Delay6'

  controller_1dof_new_DW.Delay7_DSTATE_o[2] =
    controller_1dof_new_B.Delay6_DSTATE_p;

  // Update for Delay: '<S25>/Delay8' incorporates:
  //   Delay: '<S25>/Delay7'

  controller_1dof_new_DW.Delay8_DSTATE_n[2] =
    controller_1dof_new_B.Delay7_DSTATE_o;

  // Update for Delay: '<S25>/Delay9' incorporates:
  //   Delay: '<S25>/Delay8'

  controller_1dof_new_DW.Delay9_DSTATE_i[2] =
    controller_1dof_new_B.Delay8_DSTATE_n;

  // Update for Delay: '<S25>/Delay10' incorporates:
  //   Delay: '<S25>/Delay9'

  controller_1dof_new_DW.Delay10_DSTATE_f[2] =
    controller_1dof_new_B.Delay9_DSTATE_i;

  // Update for Delay: '<S25>/Delay11' incorporates:
  //   Delay: '<S25>/Delay10'

  controller_1dof_new_DW.Delay11_DSTATE_k[2] =
    controller_1dof_new_B.Delay10_DSTATE_f;

  // Update for Delay: '<S25>/Delay12' incorporates:
  //   Delay: '<S25>/Delay11'

  controller_1dof_new_DW.Delay12_DSTATE_n[2] =
    controller_1dof_new_B.Delay11_DSTATE_k;

  // Update for Delay: '<S25>/Delay13' incorporates:
  //   Delay: '<S25>/Delay12'

  controller_1dof_new_DW.Delay13_DSTATE_g[2] =
    controller_1dof_new_B.Delay12_DSTATE_n;

  // Update for Delay: '<S25>/Delay14' incorporates:
  //   Delay: '<S25>/Delay13'

  controller_1dof_new_DW.Delay14_DSTATE_g[2] =
    controller_1dof_new_B.Delay13_DSTATE_g;

  // Update for Delay: '<S25>/Delay15' incorporates:
  //   Delay: '<S25>/Delay14'

  controller_1dof_new_DW.Delay15_DSTATE[2] =
    controller_1dof_new_B.Delay14_DSTATE_g;

  // Update for Delay: '<S25>/Delay20' incorporates:
  //   Delay: '<S25>/Delay15'

  controller_1dof_new_DW.Delay20_DSTATE_h[2] =
    controller_1dof_new_B.Delay15_DSTATE;

  // Update for Delay: '<S25>/Delay21' incorporates:
  //   Delay: '<S25>/Delay20'

  controller_1dof_new_DW.Delay21_DSTATE_d[2] =
    controller_1dof_new_B.Delay20_DSTATE_h;

  // Update for Delay: '<S25>/Delay22' incorporates:
  //   Delay: '<S25>/Delay21'

  controller_1dof_new_DW.Delay22_DSTATE_h[2] =
    controller_1dof_new_B.Delay21_DSTATE_d;

  // Update for Delay: '<S25>/Delay23' incorporates:
  //   Delay: '<S25>/Delay22'

  controller_1dof_new_DW.Delay23_DSTATE_p[2] =
    controller_1dof_new_B.Delay22_DSTATE_h;

  // Update for Delay: '<S25>/Delay24' incorporates:
  //   Delay: '<S25>/Delay23'

  controller_1dof_new_DW.Delay24_DSTATE[2] =
    controller_1dof_new_B.Delay23_DSTATE_p;

  // Update for Delay: '<S25>/Delay25' incorporates:
  //   Delay: '<S25>/Delay24'

  controller_1dof_new_DW.Delay25_DSTATE[2] =
    controller_1dof_new_B.Delay24_DSTATE;

  // Update for Delay: '<S25>/Delay26' incorporates:
  //   Delay: '<S25>/Delay25'

  controller_1dof_new_DW.Delay26_DSTATE[2] =
    controller_1dof_new_B.Delay25_DSTATE;

  // Update for Delay: '<S25>/Delay27' incorporates:
  //   Delay: '<S25>/Delay26'

  controller_1dof_new_DW.Delay27_DSTATE[2] =
    controller_1dof_new_B.Delay26_DSTATE;

  // Update for Delay: '<S25>/Delay16' incorporates:
  //   Delay: '<S25>/Delay27'

  controller_1dof_new_DW.Delay16_DSTATE[2] =
    controller_1dof_new_B.Delay27_DSTATE;

  // Update for Delay: '<S25>/Delay17' incorporates:
  //   Delay: '<S25>/Delay16'

  controller_1dof_new_DW.Delay17_DSTATE[2] =
    controller_1dof_new_B.Delay16_DSTATE;

  // Update for Delay: '<S25>/Delay18' incorporates:
  //   Delay: '<S25>/Delay17'

  controller_1dof_new_DW.Delay18_DSTATE[2] =
    controller_1dof_new_B.Delay17_DSTATE;

  // Update for Delay: '<S25>/Delay19' incorporates:
  //   Delay: '<S25>/Delay18'

  controller_1dof_new_DW.Delay19_DSTATE[2] =
    controller_1dof_new_B.Delay18_DSTATE;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  controller_1dof_new_DW.Delay2_DSTATE_l[2] =
    controller_1dof_new_DW.Delay2_DSTATE_n[2];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  controller_1dof_new_DW.DiscreteTransferFcn_states_a =
    (controller_1dof_new_B.u_vect[0] -
     controller_1dof_new_P.DiscreteTransferFcn_DenCoef_j[1] *
     controller_1dof_new_DW.DiscreteTransferFcn_states_a) /
    controller_1dof_new_P.DiscreteTransferFcn_DenCoef_j[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  controller_1dof_new_DW.DiscreteTransferFcn1_states_e =
    (controller_1dof_new_B.u_vect[1] -
     controller_1dof_new_P.DiscreteTransferFcn1_DenCoef_o[1] *
     controller_1dof_new_DW.DiscreteTransferFcn1_states_e) /
    controller_1dof_new_P.DiscreteTransferFcn1_DenCoef_o[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  controller_1dof_new_DW.DiscreteTransferFcn2_states_p =
    (controller_1dof_new_B.u_vect[2] -
     controller_1dof_new_P.DiscreteTransferFcn2_DenCoef_i[1] *
     controller_1dof_new_DW.DiscreteTransferFcn2_states_p) /
    controller_1dof_new_P.DiscreteTransferFcn2_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn'
  controller_1dof_new_DW.DiscreteTransferFcn_states_f =
    (controller_1dof_new_B.TmpSignalConversionAtSFunct[0] -
     controller_1dof_new_P.DiscreteTransferFcn_DenCoef_i[1] *
     controller_1dof_new_DW.DiscreteTransferFcn_states_f) /
    controller_1dof_new_P.DiscreteTransferFcn_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1'
  controller_1dof_new_DW.DiscreteTransferFcn1_states_d =
    (controller_1dof_new_B.TmpSignalConversionAtSFunct[1] -
     controller_1dof_new_P.DiscreteTransferFcn1_DenCoef_m[1] *
     controller_1dof_new_DW.DiscreteTransferFcn1_states_d) /
    controller_1dof_new_P.DiscreteTransferFcn1_DenCoef_m[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2'
  controller_1dof_new_DW.DiscreteTransferFcn2_states_p2 =
    (controller_1dof_new_B.TmpSignalConversionAtSFunct[2] -
     controller_1dof_new_P.DiscreteTransferFcn2_DenCoef_e[1] *
     controller_1dof_new_DW.DiscreteTransferFcn2_states_p2) /
    controller_1dof_new_P.DiscreteTransferFcn2_DenCoef_e[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controller_1dof_new_M->Timing.taskTime0 =
    ((time_T)(++controller_1dof_new_M->Timing.clockTick0)) *
    controller_1dof_new_M->Timing.stepSize0;
}

// Model initialize function
void controller_1dof_new_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controller_1dof_new_M, -1);
  controller_1dof_new_M->Timing.stepSize0 = 0.01;

  // External mode info
  controller_1dof_new_M->Sizes.checksums[0] = (795010601U);
  controller_1dof_new_M->Sizes.checksums[1] = (2539805470U);
  controller_1dof_new_M->Sizes.checksums[2] = (4290809404U);
  controller_1dof_new_M->Sizes.checksums[3] = (3780107017U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[44];
    controller_1dof_new_M->extModeInfo = (&rt_ExtModeInfo);
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
      &controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_js;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = (sysRanDType *)
      &controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = (sysRanDType *)
      &controller_1dof_new_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &controller_1dof_new_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &controller_1dof_new_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &controller_1dof_new_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_1dof_new_M->extModeInfo,
      &controller_1dof_new_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_1dof_new_M->extModeInfo,
                        controller_1dof_new_M->Sizes.checksums);
    rteiSetTPtr(controller_1dof_new_M->extModeInfo, rtmGetTPtr
                (controller_1dof_new_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Delay: '<S1>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE =
      controller_1dof_new_P.Delay3_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S10>/Internal'
    controller_1dof_new_DW.Internal_DSTATE =
      controller_1dof_new_P.Internal_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE[0] =
      controller_1dof_new_P.Delay2_InitialCondition[0];
    controller_1dof_new_DW.Delay2_DSTATE[1] =
      controller_1dof_new_P.Delay2_InitialCondition[1];

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' 
    controller_1dof_new_DW.DiscreteTransferFcn_states =
      controller_1dof_new_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' 
    controller_1dof_new_DW.DiscreteTransferFcn1_states =
      controller_1dof_new_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' 
    controller_1dof_new_DW.DiscreteTransferFcn2_states =
      controller_1dof_new_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S29>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE[0] =
      controller_1dof_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE[0] =
      controller_1dof_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE[0] =
      controller_1dof_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE[0] =
      controller_1dof_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE[0] =
      controller_1dof_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE[0] =
      controller_1dof_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE[0] =
      controller_1dof_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE[0] =
      controller_1dof_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE[0] =
      controller_1dof_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE[0] =
      controller_1dof_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE[0] =
      controller_1dof_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE[0] =
      controller_1dof_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE[0] =
      controller_1dof_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE[0] =
      controller_1dof_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE[0] =
      controller_1dof_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_d[0] =
      controller_1dof_new_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S29>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_i[0] =
      controller_1dof_new_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S29>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE[0] =
      controller_1dof_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    controller_1dof_new_DW.Delay_DSTATE[0] =
      controller_1dof_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    controller_1dof_new_DW.Delay_DSTATE_p[0] =
      controller_1dof_new_P.Delay_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S25>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE_p[0] =
      controller_1dof_new_P.Delay1_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S25>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_p[0] =
      controller_1dof_new_P.Delay2_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S25>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_j[0] =
      controller_1dof_new_P.Delay3_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S25>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE_e[0] =
      controller_1dof_new_P.Delay4_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S25>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE_p[0] =
      controller_1dof_new_P.Delay5_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S25>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE_p[0] =
      controller_1dof_new_P.Delay6_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S25>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE_o[0] =
      controller_1dof_new_P.Delay7_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S25>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE_n[0] =
      controller_1dof_new_P.Delay8_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S25>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE_i[0] =
      controller_1dof_new_P.Delay9_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S25>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE_f[0] =
      controller_1dof_new_P.Delay10_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S25>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE_k[0] =
      controller_1dof_new_P.Delay11_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S25>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE_n[0] =
      controller_1dof_new_P.Delay12_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S25>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE_g[0] =
      controller_1dof_new_P.Delay13_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S25>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE_g[0] =
      controller_1dof_new_P.Delay14_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S25>/Delay15'
    controller_1dof_new_DW.Delay15_DSTATE[0] =
      controller_1dof_new_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE_h[0] =
      controller_1dof_new_P.Delay20_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S25>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE_d[0] =
      controller_1dof_new_P.Delay21_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S25>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE_h[0] =
      controller_1dof_new_P.Delay22_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S25>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE_p[0] =
      controller_1dof_new_P.Delay23_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S25>/Delay24'
    controller_1dof_new_DW.Delay24_DSTATE[0] =
      controller_1dof_new_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay25'
    controller_1dof_new_DW.Delay25_DSTATE[0] =
      controller_1dof_new_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay26'
    controller_1dof_new_DW.Delay26_DSTATE[0] =
      controller_1dof_new_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay27'
    controller_1dof_new_DW.Delay27_DSTATE[0] =
      controller_1dof_new_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay16'
    controller_1dof_new_DW.Delay16_DSTATE[0] =
      controller_1dof_new_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay17'
    controller_1dof_new_DW.Delay17_DSTATE[0] =
      controller_1dof_new_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay18'
    controller_1dof_new_DW.Delay18_DSTATE[0] =
      controller_1dof_new_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay19'
    controller_1dof_new_DW.Delay19_DSTATE[0] =
      controller_1dof_new_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S29>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE[1] =
      controller_1dof_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE[1] =
      controller_1dof_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE[1] =
      controller_1dof_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE[1] =
      controller_1dof_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE[1] =
      controller_1dof_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE[1] =
      controller_1dof_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE[1] =
      controller_1dof_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE[1] =
      controller_1dof_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE[1] =
      controller_1dof_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE[1] =
      controller_1dof_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE[1] =
      controller_1dof_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE[1] =
      controller_1dof_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE[1] =
      controller_1dof_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE[1] =
      controller_1dof_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE[1] =
      controller_1dof_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_d[1] =
      controller_1dof_new_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S29>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_i[1] =
      controller_1dof_new_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S29>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE[1] =
      controller_1dof_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    controller_1dof_new_DW.Delay_DSTATE[1] =
      controller_1dof_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    controller_1dof_new_DW.Delay_DSTATE_p[1] =
      controller_1dof_new_P.Delay_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S25>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE_p[1] =
      controller_1dof_new_P.Delay1_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S25>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_p[1] =
      controller_1dof_new_P.Delay2_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S25>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_j[1] =
      controller_1dof_new_P.Delay3_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S25>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE_e[1] =
      controller_1dof_new_P.Delay4_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S25>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE_p[1] =
      controller_1dof_new_P.Delay5_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S25>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE_p[1] =
      controller_1dof_new_P.Delay6_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S25>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE_o[1] =
      controller_1dof_new_P.Delay7_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S25>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE_n[1] =
      controller_1dof_new_P.Delay8_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S25>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE_i[1] =
      controller_1dof_new_P.Delay9_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S25>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE_f[1] =
      controller_1dof_new_P.Delay10_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S25>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE_k[1] =
      controller_1dof_new_P.Delay11_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S25>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE_n[1] =
      controller_1dof_new_P.Delay12_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S25>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE_g[1] =
      controller_1dof_new_P.Delay13_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S25>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE_g[1] =
      controller_1dof_new_P.Delay14_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S25>/Delay15'
    controller_1dof_new_DW.Delay15_DSTATE[1] =
      controller_1dof_new_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE_h[1] =
      controller_1dof_new_P.Delay20_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S25>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE_d[1] =
      controller_1dof_new_P.Delay21_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S25>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE_h[1] =
      controller_1dof_new_P.Delay22_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S25>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE_p[1] =
      controller_1dof_new_P.Delay23_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S25>/Delay24'
    controller_1dof_new_DW.Delay24_DSTATE[1] =
      controller_1dof_new_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay25'
    controller_1dof_new_DW.Delay25_DSTATE[1] =
      controller_1dof_new_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay26'
    controller_1dof_new_DW.Delay26_DSTATE[1] =
      controller_1dof_new_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay27'
    controller_1dof_new_DW.Delay27_DSTATE[1] =
      controller_1dof_new_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay16'
    controller_1dof_new_DW.Delay16_DSTATE[1] =
      controller_1dof_new_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay17'
    controller_1dof_new_DW.Delay17_DSTATE[1] =
      controller_1dof_new_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay18'
    controller_1dof_new_DW.Delay18_DSTATE[1] =
      controller_1dof_new_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay19'
    controller_1dof_new_DW.Delay19_DSTATE[1] =
      controller_1dof_new_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S29>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE[2] =
      controller_1dof_new_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE[2] =
      controller_1dof_new_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE[2] =
      controller_1dof_new_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE[2] =
      controller_1dof_new_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE[2] =
      controller_1dof_new_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE[2] =
      controller_1dof_new_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE[2] =
      controller_1dof_new_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE[2] =
      controller_1dof_new_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE[2] =
      controller_1dof_new_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE[2] =
      controller_1dof_new_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE[2] =
      controller_1dof_new_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE[2] =
      controller_1dof_new_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE[2] =
      controller_1dof_new_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE[2] =
      controller_1dof_new_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE[2] =
      controller_1dof_new_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_d[2] =
      controller_1dof_new_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S29>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_i[2] =
      controller_1dof_new_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S29>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE[2] =
      controller_1dof_new_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    controller_1dof_new_DW.Delay_DSTATE[2] =
      controller_1dof_new_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    controller_1dof_new_DW.Delay_DSTATE_p[2] =
      controller_1dof_new_P.Delay_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S25>/Delay1'
    controller_1dof_new_DW.Delay1_DSTATE_p[2] =
      controller_1dof_new_P.Delay1_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S25>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_p[2] =
      controller_1dof_new_P.Delay2_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S25>/Delay3'
    controller_1dof_new_DW.Delay3_DSTATE_j[2] =
      controller_1dof_new_P.Delay3_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S25>/Delay4'
    controller_1dof_new_DW.Delay4_DSTATE_e[2] =
      controller_1dof_new_P.Delay4_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S25>/Delay5'
    controller_1dof_new_DW.Delay5_DSTATE_p[2] =
      controller_1dof_new_P.Delay5_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S25>/Delay6'
    controller_1dof_new_DW.Delay6_DSTATE_p[2] =
      controller_1dof_new_P.Delay6_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S25>/Delay7'
    controller_1dof_new_DW.Delay7_DSTATE_o[2] =
      controller_1dof_new_P.Delay7_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S25>/Delay8'
    controller_1dof_new_DW.Delay8_DSTATE_n[2] =
      controller_1dof_new_P.Delay8_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S25>/Delay9'
    controller_1dof_new_DW.Delay9_DSTATE_i[2] =
      controller_1dof_new_P.Delay9_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S25>/Delay10'
    controller_1dof_new_DW.Delay10_DSTATE_f[2] =
      controller_1dof_new_P.Delay10_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S25>/Delay11'
    controller_1dof_new_DW.Delay11_DSTATE_k[2] =
      controller_1dof_new_P.Delay11_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S25>/Delay12'
    controller_1dof_new_DW.Delay12_DSTATE_n[2] =
      controller_1dof_new_P.Delay12_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S25>/Delay13'
    controller_1dof_new_DW.Delay13_DSTATE_g[2] =
      controller_1dof_new_P.Delay13_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S25>/Delay14'
    controller_1dof_new_DW.Delay14_DSTATE_g[2] =
      controller_1dof_new_P.Delay14_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S25>/Delay15'
    controller_1dof_new_DW.Delay15_DSTATE[2] =
      controller_1dof_new_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay20'
    controller_1dof_new_DW.Delay20_DSTATE_h[2] =
      controller_1dof_new_P.Delay20_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S25>/Delay21'
    controller_1dof_new_DW.Delay21_DSTATE_d[2] =
      controller_1dof_new_P.Delay21_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S25>/Delay22'
    controller_1dof_new_DW.Delay22_DSTATE_h[2] =
      controller_1dof_new_P.Delay22_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S25>/Delay23'
    controller_1dof_new_DW.Delay23_DSTATE_p[2] =
      controller_1dof_new_P.Delay23_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S25>/Delay24'
    controller_1dof_new_DW.Delay24_DSTATE[2] =
      controller_1dof_new_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay25'
    controller_1dof_new_DW.Delay25_DSTATE[2] =
      controller_1dof_new_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay26'
    controller_1dof_new_DW.Delay26_DSTATE[2] =
      controller_1dof_new_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay27'
    controller_1dof_new_DW.Delay27_DSTATE[2] =
      controller_1dof_new_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay16'
    controller_1dof_new_DW.Delay16_DSTATE[2] =
      controller_1dof_new_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay17'
    controller_1dof_new_DW.Delay17_DSTATE[2] =
      controller_1dof_new_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay18'
    controller_1dof_new_DW.Delay18_DSTATE[2] =
      controller_1dof_new_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay19'
    controller_1dof_new_DW.Delay19_DSTATE[2] =
      controller_1dof_new_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S27>/Memory4'
    for (i = 0; i < 5; i++) {
      controller_1dof_new_DW.Memory4_PreviousInput[i] =
        controller_1dof_new_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S27>/Memory4'

    // InitializeConditions for Delay: '<S27>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_l[0] =
      controller_1dof_new_P.Delay2_InitialCondition_kt;
    controller_1dof_new_DW.Delay2_DSTATE_l[1] =
      controller_1dof_new_P.Delay2_InitialCondition_kt;
    controller_1dof_new_DW.Delay2_DSTATE_l[2] =
      controller_1dof_new_P.Delay2_InitialCondition_kt;

    // InitializeConditions for Memory: '<S27>/Memory2'
    controller_1dof_new_DW.Memory2_PreviousInput =
      controller_1dof_new_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S27>/Memory3'
    memcpy(&controller_1dof_new_DW.Memory3_PreviousInput[0],
           &controller_1dof_new_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S30>/Memory4'
    controller_1dof_new_DW.Memory4_PreviousInput_k = controller_1dof_new_P.x0_ps;

    // InitializeConditions for Memory: '<S30>/Memory3'
    controller_1dof_new_DW.Memory3_PreviousInput_f = controller_1dof_new_P.P0_ps;

    // InitializeConditions for Memory: '<S30>/Memory2'
    controller_1dof_new_DW.Memory2_PreviousInput_b =
      controller_1dof_new_P.Memory2_InitialCondition_h;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' 
    controller_1dof_new_DW.DiscreteTransferFcn_states_a =
      controller_1dof_new_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1' 
    controller_1dof_new_DW.DiscreteTransferFcn1_states_e =
      controller_1dof_new_P.DiscreteTransferFcn1_InitialS_j;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2' 
    controller_1dof_new_DW.DiscreteTransferFcn2_states_p =
      controller_1dof_new_P.DiscreteTransferFcn2_InitialS_c;

    // InitializeConditions for Memory: '<S18>/Memory5'
    controller_1dof_new_DW.Memory5_PreviousInput =
      controller_1dof_new_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_n[0] =
      controller_1dof_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S18>/Memory6'
    controller_1dof_new_DW.Memory6_PreviousInput[0] =
      controller_1dof_new_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_n[1] =
      controller_1dof_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S18>/Memory6'
    controller_1dof_new_DW.Memory6_PreviousInput[1] =
      controller_1dof_new_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    controller_1dof_new_DW.Delay2_DSTATE_n[2] =
      controller_1dof_new_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S18>/Memory6'
    controller_1dof_new_DW.Memory6_PreviousInput[2] =
      controller_1dof_new_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn' 
    controller_1dof_new_DW.DiscreteTransferFcn_states_f =
      controller_1dof_new_P.DiscreteTransferFcn_InitialSt_i;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1' 
    controller_1dof_new_DW.DiscreteTransferFcn1_states_d =
      controller_1dof_new_P.DiscreteTransferFcn1_InitialS_g;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2' 
    controller_1dof_new_DW.DiscreteTransferFcn2_states_p2 =
      controller_1dof_new_P.DiscreteTransferFcn2_InitialS_o;

    // SystemInitialize for Enabled SubSystem: '<S68>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S69>/In1' incorporates:
    //   Outport: '<S69>/Out1'

    controller_1dof_new_B.In1 = controller_1dof_new_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S68>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S58>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S59>/In1' incorporates:
    //   Outport: '<S59>/Out1'

    controller_1dof_new_B.In1_f = controller_1dof_new_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S54>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S55>/In1' incorporates:
    //   Outport: '<S55>/Out1'

    controller_1dof_new_B.In1_i = controller_1dof_new_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S54>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S56>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S57>/In1' incorporates:
    //   Outport: '<S57>/Out1'

    controller_1dof_new_B.In1_n = controller_1dof_new_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S56>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    controller_MATLABFunction1_Init(&controller_1dof_new_DW.sf_MATLABFunction1_i);

    // SystemInitialize for MATLAB Function: '<S19>/MATLAB Function7'
    controller_MATLABFunction1_Init(&controller_1dof_new_DW.sf_MATLABFunction7);

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S47>/In1' incorporates:
    //   Outport: '<S47>/Out1'

    controller_1dof_new_B.In1_h = controller_1dof_new_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S68>/SourceBlock'
    controller_1dof_new_DW.obj_c.matlabCodegenIsDeleted = false;
    controller_1dof_new_DW.obj_c.isInitialized = 1;
    controller_1dof_new_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_1dof_new_DW.obj_c.orbMetadataObj,
                         &controller_1dof_new_DW.obj_c.eventStructObj);
    controller_1dof_new_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S58>/SourceBlock'
    controller_1dof_new_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_1dof_new_DW.obj_h.isInitialized = 1;
    controller_1dof_new_DW.obj_h.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(controller_1dof_new_DW.obj_h.orbMetadataObj,
                         &controller_1dof_new_DW.obj_h.eventStructObj);
    controller_1dof_new_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S54>/SourceBlock'
    controller_1dof_new_DW.obj_jj.matlabCodegenIsDeleted = false;
    controller_1dof_new_DW.obj_jj.isInitialized = 1;
    controller_1dof_new_DW.obj_jj.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_1dof_new_DW.obj_jj.orbMetadataObj,
                         &controller_1dof_new_DW.obj_jj.eventStructObj);
    controller_1dof_new_DW.obj_jj.isSetupComplete = true;

    // Start for MATLABSystem: '<S56>/SourceBlock'
    controller_1dof_new_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_1dof_new_DW.obj_j.isInitialized = 1;
    controller_1dof_new_DW.obj_j.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_1dof_new_DW.obj_j.orbMetadataObj,
                         &controller_1dof_new_DW.obj_j.eventStructObj);
    controller_1dof_new_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/failsafe'

    controller_1dof_new_DW.obj.errorStatus = 0U;
    controller_1dof_new_DW.obj.isInitialized = 0;
    controller_1dof_new_DW.obj.matlabCodegenIsDeleted = false;
    controller_1do_SystemCore_setup(&controller_1dof_new_DW.obj,
      rtb_startingswitch, controller_1dof_new_P.failsafe_Value);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controller_1dof_new_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_1dof_new_DW.obj_d.isInitialized = 1;
    controller_1dof_new_DW.obj_d.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(controller_1dof_new_DW.obj_d.orbMetadataObj,
                         &controller_1dof_new_DW.obj_d.eventStructObj);
    controller_1dof_new_DW.obj_d.isSetupComplete = true;
  }
}

// Model terminate function
void controller_1dof_new_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S68>/SourceBlock'
  if (!controller_1dof_new_DW.obj_c.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj_c.isInitialized == 1) &&
        controller_1dof_new_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_new_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S68>/SourceBlock'

  // Terminate for MATLABSystem: '<S58>/SourceBlock'
  if (!controller_1dof_new_DW.obj_h.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj_h.isInitialized == 1) &&
        controller_1dof_new_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_new_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S58>/SourceBlock'

  // Terminate for MATLABSystem: '<S54>/SourceBlock'
  if (!controller_1dof_new_DW.obj_jj.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj_jj.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj_jj.isInitialized == 1) &&
        controller_1dof_new_DW.obj_jj.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_new_DW.obj_jj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S54>/SourceBlock'

  // Terminate for MATLABSystem: '<S56>/SourceBlock'
  if (!controller_1dof_new_DW.obj_j.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj_j.isInitialized == 1) &&
        controller_1dof_new_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_new_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S56>/SourceBlock'
  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!controller_1dof_new_DW.obj.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj.isInitialized == 1) &&
        controller_1dof_new_DW.obj.isSetupComplete) {
      status = pwm_disarm(&controller_1dof_new_DW.obj.pwmDevHandler,
                          &controller_1dof_new_DW.obj.armAdvertiseObj);
      controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_new_DW.obj.errorStatus | status);
      status = pwm_resetServo(&controller_1dof_new_DW.obj.pwmDevHandler,
        controller_1dof_new_DW.obj.servoCount,
        controller_1dof_new_DW.obj.channelMask,
        controller_1dof_new_DW.obj.isMain,
        &controller_1dof_new_DW.obj.actuatorAdvertiseObj);
      controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_new_DW.obj.errorStatus | status);
      status = pwm_close(&controller_1dof_new_DW.obj.pwmDevHandler,
                         &controller_1dof_new_DW.obj.actuatorAdvertiseObj,
                         &controller_1dof_new_DW.obj.armAdvertiseObj);
      controller_1dof_new_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_new_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controller_1dof_new_DW.obj_d.matlabCodegenIsDeleted) {
    controller_1dof_new_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_1dof_new_DW.obj_d.isInitialized == 1) &&
        controller_1dof_new_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_new_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
