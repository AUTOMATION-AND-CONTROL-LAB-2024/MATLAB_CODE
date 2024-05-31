//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_1dof_VSC.cpp
//
// Code generated for Simulink model 'controller_1dof_VSC'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri May 24 12:31:24 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_1dof_VSC.h"
#include "rtwtypes.h"
#include "controller_1dof_VSC_types.h"
#include "controller_1dof_VSC_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S4>/MATLAB Function1'
const int32_T controller_1dof_VSC_CALL_EVENT = -1;

// Block signals (default storage)
B_controller_1dof_VSC_T controller_1dof_VSC_B;

// Block states (default storage)
DW_controller_1dof_VSC_T controller_1dof_VSC_DW;

// Real-time model
RT_MODEL_controller_1dof_VSC_T controller_1dof_VSC_M_ =
  RT_MODEL_controller_1dof_VSC_T();
RT_MODEL_controller_1dof_VSC_T *const controller_1dof_VSC_M =
  &controller_1dof_VSC_M_;

// Forward declaration for local functions
static void controller_1do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S28>/MATLAB Function7'
//
void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_1dof_VSC_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S28>/MATLAB Function7'
//
void controller_1dof_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_1dof_VSC_CALL_EVENT;
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
void controller_1dof_VSC_step(void)
{
  int32_T At1_tmp;
  int32_T Pt1_tmp;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Product1_d;
  real32_T rtb_fcn3;
  real32_T rtb_fcn5;
  real32_T y_l_tmp;
  real32_T y_l_tmp_0;
  real32_T y_l_tmp_1;
  real32_T y_l_tmp_2;
  uint16_T rtb_DataTypeConversion1_b;
  uint16_T rtb_DataTypeConversion1_j;
  uint16_T rtb_DataTypeConversion1_jl;
  uint16_T rtb_DataTypeConversion1_m;
  boolean_T b_varargout_1;
  boolean_T rtb_startingswitch;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_p);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_iw);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_i);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_a);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S27>/Discrete Time1'
  //   DigitalClock: '<S32>/Discrete Time'
  //   DigitalClock: '<S34>/Discrete Time'
  //   Step: '<Root>/RPY ref'

  controller_1dof_VSC_B.DigitalClock1 = controller_1dof_VSC_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (controller_1dof_VSC_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = controller_1dof_VSC_P.Constant2_Value;
  } else {
    rtb_startingswitch = controller_1dof_VSC_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // MATLAB Function: '<S9>/Integrator' incorporates:
  //   Constant: '<S9>/Constant'
  //   Constant: '<S9>/Constant1'
  //   Memory: '<S9>/Memory'

  if (!rtb_startingswitch) {
    controller_1dof_VSC_DW.Delay_DSTATE = 0.0;
  }

  controller_1dof_VSC_B.u_d = controller_1dof_VSC_P.Ts_slk *
    controller_1dof_VSC_DW.Memory_PreviousInput +
    controller_1dof_VSC_DW.Delay_DSTATE;
  if ((controller_1dof_VSC_P.Constant_Value_c <= controller_1dof_VSC_B.u_d) ||
      rtIsNaN(controller_1dof_VSC_B.u_d)) {
    controller_1dof_VSC_B.u_d = controller_1dof_VSC_P.Constant_Value_c;
  }

  if ((controller_1dof_VSC_P.Constant1_Value_d >= controller_1dof_VSC_B.u_d) ||
      rtIsNaN(controller_1dof_VSC_B.u_d)) {
    controller_1dof_VSC_B.u_d = controller_1dof_VSC_P.Constant1_Value_d;
  }

  // End of MATLAB Function: '<S9>/Integrator'

  // MATLAB Function: '<S1>/MATLAB Function3'
  controller_1dof_VSC_B.tau_o[0] = controller_1dof_VSC_B.u_d;
  controller_1dof_VSC_B.tau_o[1] = 0.0;
  controller_1dof_VSC_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (controller_1dof_VSC_B.tau_o[0] >= 0.0) {
    controller_1dof_VSC_B.u[3] = controller_1dof_VSC_P.Constant3_Value;
    controller_1dof_VSC_B.u[2] = (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[7] * controller_1dof_VSC_P.Constant3_Value +
      controller_1dof_VSC_B.tau_o[0]) / (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[6]);
  } else {
    controller_1dof_VSC_B.u[2] = controller_1dof_VSC_P.Constant3_Value;
    controller_1dof_VSC_B.u[3] = (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[6] * controller_1dof_VSC_P.Constant3_Value -
      controller_1dof_VSC_B.tau_o[0]) / (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[7]);
  }

  if (controller_1dof_VSC_B.tau_o[1] >= 0.0) {
    controller_1dof_VSC_B.u[0] = controller_1dof_VSC_P.Constant3_Value;
    controller_1dof_VSC_B.u[1] = (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[4] * controller_1dof_VSC_P.Constant3_Value +
      controller_1dof_VSC_B.tau_o[1]) / (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[5]);
  } else {
    controller_1dof_VSC_B.u[1] = controller_1dof_VSC_P.Constant3_Value;
    controller_1dof_VSC_B.u[0] = (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[5] * controller_1dof_VSC_P.Constant3_Value -
      controller_1dof_VSC_B.tau_o[1]) / (controller_1dof_VSC_P.param[3] *
      controller_1dof_VSC_P.param[4]);
  }

  b_varargout_1 = rtIsNaN(controller_1dof_VSC_B.u[0]);
  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[0]) ||
      b_varargout_1) {
    controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.u[0];
  }

  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[0]) ||
      b_varargout_1) {
    controller_1dof_VSC_B.minval[0] = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.minval[0] = controller_1dof_VSC_B.u[0];
  }

  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[1]) ||
      rtIsNaN(controller_1dof_VSC_B.u[1])) {
    controller_1dof_VSC_B.sph = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.sph = controller_1dof_VSC_B.u[1];
  }

  b_varargout_1 = rtIsNaN(controller_1dof_VSC_B.u[2]);
  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[2]) ||
      b_varargout_1) {
    controller_1dof_VSC_B.Pt_g = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.Pt_g = controller_1dof_VSC_B.u[2];
  }

  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[2]) ||
      b_varargout_1) {
    controller_1dof_VSC_B.minval[2] = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.minval[2] = controller_1dof_VSC_B.u[2];
  }

  if ((controller_1dof_VSC_P.Constant1_Value_j <= controller_1dof_VSC_B.u[3]) ||
      rtIsNaN(controller_1dof_VSC_B.u[3])) {
    controller_1dof_VSC_B.ph_meas = controller_1dof_VSC_P.Constant1_Value_j;
  } else {
    controller_1dof_VSC_B.ph_meas = controller_1dof_VSC_B.u[3];
  }

  controller_1dof_VSC_B.dv1[0] = 0.0;
  controller_1dof_VSC_B.dv1[3] = 0.0;
  controller_1dof_VSC_B.dv1[6] = controller_1dof_VSC_P.param[3] *
    controller_1dof_VSC_P.param[6];
  controller_1dof_VSC_B.dv1[9] = -controller_1dof_VSC_P.param[3] *
    controller_1dof_VSC_P.param[7];
  controller_1dof_VSC_B.dv1[1] = -controller_1dof_VSC_P.param[3] *
    controller_1dof_VSC_P.param[4];
  controller_1dof_VSC_B.dv1[4] = controller_1dof_VSC_P.param[3] *
    controller_1dof_VSC_P.param[5];
  controller_1dof_VSC_B.dv1[7] = 0.0;
  controller_1dof_VSC_B.dv1[10] = 0.0;
  controller_1dof_VSC_B.dv1[2] = -controller_1dof_VSC_P.param[8];
  controller_1dof_VSC_B.dv1[5] = -controller_1dof_VSC_P.param[8];
  controller_1dof_VSC_B.dv1[8] = controller_1dof_VSC_P.param[8];
  controller_1dof_VSC_B.dv1[11] = controller_1dof_VSC_P.param[8];
  controller_1dof_VSC_B.wq1 = controller_1dof_VSC_B.minval[0];
  controller_1dof_VSC_B.tth = controller_1dof_VSC_B.minval[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    controller_1dof_VSC_B.tau_allocated[i_0] = ((controller_1dof_VSC_B.dv1[i_0 +
      3] * controller_1dof_VSC_B.sph + controller_1dof_VSC_B.dv1[i_0] *
      controller_1dof_VSC_B.wq1) + controller_1dof_VSC_B.dv1[i_0 + 6] *
      controller_1dof_VSC_B.tth) + controller_1dof_VSC_B.dv1[i_0 + 9] *
      controller_1dof_VSC_B.ph_meas;
  }

  controller_1dof_VSC_B.u[0] = controller_1dof_VSC_B.Gain9;
  controller_1dof_VSC_B.u[1] = controller_1dof_VSC_B.sph;
  controller_1dof_VSC_B.u[2] = controller_1dof_VSC_B.Pt_g;
  controller_1dof_VSC_B.u[3] = controller_1dof_VSC_B.ph_meas;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  controller_1dof_VSC_B.u1 = controller_1dof_VSC_B.u[0];
  controller_1dof_VSC_B.u2 = controller_1dof_VSC_B.u[1];
  controller_1dof_VSC_B.u3 = controller_1dof_VSC_B.u[2];
  controller_1dof_VSC_B.u4 = controller_1dof_VSC_B.u[3];

  // DiscreteStateSpace: '<S17>/Internal' incorporates:
  //   Constant: '<S46>/Constant'
  //   Sum: '<S46>/Sum'

  controller_1dof_VSC_B.Internal = controller_1dof_VSC_B.u1 +
    controller_1dof_VSC_P.Constant_Value_n0;

  // DataTypeConversion: '<S46>/Data Type Conversion1'
  controller_1dof_VSC_B.Gain9 = floor(controller_1dof_VSC_B.Internal);
  if (rtIsNaN(controller_1dof_VSC_B.Gain9) || rtIsInf
      (controller_1dof_VSC_B.Gain9)) {
    controller_1dof_VSC_B.Gain9 = 0.0;
  } else {
    controller_1dof_VSC_B.Gain9 = fmod(controller_1dof_VSC_B.Gain9, 65536.0);
  }

  rtb_DataTypeConversion1_b = static_cast<uint16_T>(controller_1dof_VSC_B.Gain9 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_VSC_B.Gain9)))) : static_cast<int32_T>
    (static_cast<uint16_T>(controller_1dof_VSC_B.Gain9)));

  // End of DataTypeConversion: '<S46>/Data Type Conversion1'

  // DiscreteStateSpace: '<S17>/Internal' incorporates:
  //   Constant: '<S47>/Constant'
  //   Sum: '<S47>/Sum'

  controller_1dof_VSC_B.Internal = controller_1dof_VSC_B.u2 +
    controller_1dof_VSC_P.Constant_Value_ln;

  // DataTypeConversion: '<S47>/Data Type Conversion1'
  controller_1dof_VSC_B.Gain9 = floor(controller_1dof_VSC_B.Internal);
  if (rtIsNaN(controller_1dof_VSC_B.Gain9) || rtIsInf
      (controller_1dof_VSC_B.Gain9)) {
    controller_1dof_VSC_B.Gain9 = 0.0;
  } else {
    controller_1dof_VSC_B.Gain9 = fmod(controller_1dof_VSC_B.Gain9, 65536.0);
  }

  rtb_DataTypeConversion1_jl = static_cast<uint16_T>(controller_1dof_VSC_B.Gain9
    < 0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_VSC_B.Gain9)))) : static_cast<int32_T>
    (static_cast<uint16_T>(controller_1dof_VSC_B.Gain9)));

  // End of DataTypeConversion: '<S47>/Data Type Conversion1'

  // DiscreteStateSpace: '<S17>/Internal' incorporates:
  //   Constant: '<S48>/Constant'
  //   Sum: '<S48>/Sum'

  controller_1dof_VSC_B.Internal = controller_1dof_VSC_B.u3 +
    controller_1dof_VSC_P.Constant_Value_bn;

  // DataTypeConversion: '<S48>/Data Type Conversion1'
  controller_1dof_VSC_B.Gain9 = floor(controller_1dof_VSC_B.Internal);
  if (rtIsNaN(controller_1dof_VSC_B.Gain9) || rtIsInf
      (controller_1dof_VSC_B.Gain9)) {
    controller_1dof_VSC_B.Gain9 = 0.0;
  } else {
    controller_1dof_VSC_B.Gain9 = fmod(controller_1dof_VSC_B.Gain9, 65536.0);
  }

  rtb_DataTypeConversion1_m = static_cast<uint16_T>(controller_1dof_VSC_B.Gain9 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_VSC_B.Gain9)))) : static_cast<int32_T>
    (static_cast<uint16_T>(controller_1dof_VSC_B.Gain9)));

  // End of DataTypeConversion: '<S48>/Data Type Conversion1'

  // DiscreteStateSpace: '<S17>/Internal' incorporates:
  //   Constant: '<S49>/Constant'
  //   Sum: '<S49>/Sum'

  controller_1dof_VSC_B.Internal = controller_1dof_VSC_B.u4 +
    controller_1dof_VSC_P.Constant_Value_ch;

  // DataTypeConversion: '<S49>/Data Type Conversion1'
  controller_1dof_VSC_B.Gain9 = floor(controller_1dof_VSC_B.Internal);
  if (rtIsNaN(controller_1dof_VSC_B.Gain9) || rtIsInf
      (controller_1dof_VSC_B.Gain9)) {
    controller_1dof_VSC_B.Gain9 = 0.0;
  } else {
    controller_1dof_VSC_B.Gain9 = fmod(controller_1dof_VSC_B.Gain9, 65536.0);
  }

  rtb_DataTypeConversion1_j = static_cast<uint16_T>(controller_1dof_VSC_B.Gain9 <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_1dof_VSC_B.Gain9)))) : static_cast<int32_T>
    (static_cast<uint16_T>(controller_1dof_VSC_B.Gain9)));

  // End of DataTypeConversion: '<S49>/Data Type Conversion1'

  // MATLABSystem: '<S71>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_1dof_VSC_DW.obj_m.orbMetadataObj,
    &controller_1dof_VSC_DW.obj_m.eventStructObj,
    &controller_1dof_VSC_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S71>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S72>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S72>/In1'
    controller_1dof_VSC_B.In1 = controller_1dof_VSC_B.b_varargout_2;
    srUpdateBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S71>/SourceBlock'
  // End of Outputs for SubSystem: '<S71>/Enabled Subsystem'

  // Sqrt: '<S69>/sqrt' incorporates:
  //   Product: '<S70>/Product'
  //   Product: '<S70>/Product1'
  //   Product: '<S70>/Product2'
  //   Product: '<S70>/Product3'
  //   Sum: '<S70>/Sum'

  controller_1dof_VSC_B.Product3 = static_cast<real32_T>(sqrt(static_cast<real_T>
    (((controller_1dof_VSC_B.In1.q[0] * controller_1dof_VSC_B.In1.q[0] +
       controller_1dof_VSC_B.In1.q[1] * controller_1dof_VSC_B.In1.q[1]) +
      controller_1dof_VSC_B.In1.q[2] * controller_1dof_VSC_B.In1.q[2]) +
     controller_1dof_VSC_B.In1.q[3] * controller_1dof_VSC_B.In1.q[3])));

  // Product: '<S64>/Product'
  rtb_fcn5 = controller_1dof_VSC_B.In1.q[0] / controller_1dof_VSC_B.Product3;

  // Product: '<S64>/Product1'
  rtb_Product1_d = controller_1dof_VSC_B.In1.q[1] /
    controller_1dof_VSC_B.Product3;

  // Product: '<S64>/Product2'
  controller_1dof_VSC_B.Product2 = controller_1dof_VSC_B.In1.q[2] /
    controller_1dof_VSC_B.Product3;

  // Product: '<S64>/Product3'
  controller_1dof_VSC_B.Product3 = controller_1dof_VSC_B.In1.q[3] /
    controller_1dof_VSC_B.Product3;

  // Fcn: '<S54>/fcn3'
  rtb_fcn3 = (rtb_Product1_d * controller_1dof_VSC_B.Product3 - rtb_fcn5 *
              controller_1dof_VSC_B.Product2) * -2.0F;

  // If: '<S65>/If' incorporates:
  //   Constant: '<S66>/Constant'
  //   Constant: '<S67>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S65>/If Action Subsystem' incorporates:
    //   ActionPort: '<S66>/Action Port'

    rtb_fcn3 = controller_1dof_VSC_P.Constant_Value_g;

    // End of Outputs for SubSystem: '<S65>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S65>/If Action Subsystem' incorporates:
    //   ActionPort: '<S66>/Action Port'

    // Update for If: '<S65>/If' incorporates:
    //   Constant: '<S66>/Constant'

    srUpdateBC(controller_1dof_VSC_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S65>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S65>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S67>/Action Port'

    rtb_fcn3 = controller_1dof_VSC_P.Constant_Value_k;

    // End of Outputs for SubSystem: '<S65>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S65>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S67>/Action Port'

    // Update for If: '<S65>/If' incorporates:
    //   Constant: '<S67>/Constant'

    srUpdateBC(controller_1dof_VSC_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S65>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S65>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S68>/Action Port'

    // Update for If: '<S65>/If'
    srUpdateBC(controller_1dof_VSC_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S65>/If Action Subsystem2'
  }

  // End of If: '<S65>/If'

  // Fcn: '<S54>/fcn5' incorporates:
  //   Fcn: '<S54>/fcn2'

  y_l_tmp = rtb_fcn5 * rtb_fcn5;
  y_l_tmp_0 = rtb_Product1_d * rtb_Product1_d;
  y_l_tmp_1 = controller_1dof_VSC_B.Product2 * controller_1dof_VSC_B.Product2;
  y_l_tmp_2 = controller_1dof_VSC_B.Product3 * controller_1dof_VSC_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S54>/fcn4'
  //   Fcn: '<S54>/fcn5'
  //   Trigonometry: '<S63>/Trigonometric Function3'

  controller_1dof_VSC_B.y_l[0] = rt_atan2f_snf((controller_1dof_VSC_B.Product2 *
    controller_1dof_VSC_B.Product3 + rtb_fcn5 * rtb_Product1_d) * 2.0F,
    ((y_l_tmp - y_l_tmp_0) - y_l_tmp_1) + y_l_tmp_2);

  // Trigonometry: '<S63>/trigFcn'
  if (rtb_fcn3 > 1.0F) {
    rtb_fcn3 = 1.0F;
  } else if (rtb_fcn3 < -1.0F) {
    rtb_fcn3 = -1.0F;
  }

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S54>/fcn1'
  //   Fcn: '<S54>/fcn2'
  //   Trigonometry: '<S63>/Trigonometric Function1'
  //   Trigonometry: '<S63>/trigFcn'

  controller_1dof_VSC_B.y_l[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (rtb_fcn3)));
  controller_1dof_VSC_B.y_l[2] = rt_atan2f_snf((rtb_Product1_d *
    controller_1dof_VSC_B.Product2 + rtb_fcn5 * controller_1dof_VSC_B.Product3) *
    2.0F, ((y_l_tmp + y_l_tmp_0) - y_l_tmp_1) - y_l_tmp_2);

  // MATLABSystem: '<S61>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_1dof_VSC_DW.obj_c.orbMetadataObj,
    &controller_1dof_VSC_DW.obj_c.eventStructObj,
    &controller_1dof_VSC_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S61>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S62>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S62>/In1'
    controller_1dof_VSC_B.In1_m = controller_1dof_VSC_B.b_varargout_2_b;
    srUpdateBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_a);
  }

  // End of MATLABSystem: '<S61>/SourceBlock'
  // End of Outputs for SubSystem: '<S61>/Enabled Subsystem'

  // MATLABSystem: '<S59>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_1dof_VSC_DW.obj_d.orbMetadataObj,
    &controller_1dof_VSC_DW.obj_d.eventStructObj,
    &controller_1dof_VSC_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S59>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S60>/In1'
    controller_1dof_VSC_B.In1_f = controller_1dof_VSC_B.b_varargout_2_cx;
    srUpdateBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_i);
  }

  // End of MATLABSystem: '<S59>/SourceBlock'
  // End of Outputs for SubSystem: '<S59>/Enabled Subsystem'

  // MATLABSystem: '<S57>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_1dof_VSC_DW.obj_f.orbMetadataObj,
    &controller_1dof_VSC_DW.obj_f.eventStructObj,
    &controller_1dof_VSC_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S57>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S58>/In1'
    controller_1dof_VSC_B.In1_c = controller_1dof_VSC_B.b_varargout_2_k;
    srUpdateBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_iw);
  }

  // End of MATLABSystem: '<S57>/SourceBlock'
  // End of Outputs for SubSystem: '<S57>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn1'
  controller_1dof_VSC_B.wq1 = controller_1dof_VSC_P.DiscreteTransferFcn1_NumCoef
    * controller_1dof_VSC_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn2'
  controller_1dof_VSC_B.Gain9 =
    controller_1dof_VSC_P.DiscreteTransferFcn2_NumCoef *
    controller_1dof_VSC_DW.DiscreteTransferFcn2_states;

  // MATLAB Function: '<S27>/RP_computation' incorporates:
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn2'

  controller_1dof_VSC_B.ph_meas = rt_atan2d_snf(-controller_1dof_VSC_B.wq1,
    -controller_1dof_VSC_B.Gain9);
  controller_1dof_VSC_B.RP_meas[0] = controller_1dof_VSC_B.ph_meas;
  controller_1dof_VSC_B.RP_meas[1] = rt_atan2d_snf
    (controller_1dof_VSC_P.DiscreteTransferFcn_NumCoef *
     controller_1dof_VSC_DW.DiscreteTransferFcn_states,
     -controller_1dof_VSC_B.wq1 * sin(controller_1dof_VSC_B.ph_meas) +
     -controller_1dof_VSC_B.Gain9 * cos(controller_1dof_VSC_B.ph_meas));

  // MATLAB Function: '<S32>/EKF_RP' incorporates:
  //   Delay: '<S32>/Delay2'
  //   Memory: '<S32>/Memory2'
  //   Memory: '<S32>/Memory3'

  if (controller_1dof_VSC_B.DigitalClock1 -
      controller_1dof_VSC_DW.Memory2_PreviousInput >=
      controller_1dof_VSC_P.Ts_EKF_meas) {
    controller_1dof_VSC_DW.Memory2_PreviousInput =
      controller_1dof_VSC_B.DigitalClock1;
    memcpy(&controller_1dof_VSC_B.Pt1[0],
           &controller_1dof_VSC_DW.Memory3_PreviousInput[0], 25U * sizeof(real_T));
    controller_1dof_VSC_B.wq1 = controller_1dof_VSC_DW.Delay2_DSTATE[1];
    controller_1dof_VSC_B.wr1 = controller_1dof_VSC_DW.Delay2_DSTATE[2];
    for (i = 0; i < 5; i++) {
      controller_1dof_VSC_B.xt[i] = 0.0;
    }

    memset(&controller_1dof_VSC_B.Pt[0], 0, 25U * sizeof(real_T));
    controller_1dof_VSC_B.b = static_cast<int32_T>(floor
      (controller_1dof_VSC_P.Ts_EKF_meas / controller_1dof_VSC_P.Ts_EKF_integr));
    for (i = 0; i < controller_1dof_VSC_B.b; i++) {
      controller_1dof_VSC_B.cph = cos
        (controller_1dof_VSC_DW.Memory4_PreviousInput[0]);
      controller_1dof_VSC_B.cth = cos
        (controller_1dof_VSC_DW.Memory4_PreviousInput[1]);
      controller_1dof_VSC_B.sph = sin
        (controller_1dof_VSC_DW.Memory4_PreviousInput[0]);
      controller_1dof_VSC_B.tth = sin
        (controller_1dof_VSC_DW.Memory4_PreviousInput[1]) /
        controller_1dof_VSC_B.cth;
      controller_1dof_VSC_B.dv[0] = 1.0;
      controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.sph *
        controller_1dof_VSC_B.tth;
      controller_1dof_VSC_B.dv[5] = controller_1dof_VSC_B.Gain9;
      controller_1dof_VSC_B.d = controller_1dof_VSC_B.cph *
        controller_1dof_VSC_B.tth;
      controller_1dof_VSC_B.dv[10] = controller_1dof_VSC_B.d;
      controller_1dof_VSC_B.dv[15] = 0.0;
      controller_1dof_VSC_B.dv[20] = 0.0;
      controller_1dof_VSC_B.dv[25] = 0.0;
      controller_1dof_VSC_B.dv[1] = 0.0;
      controller_1dof_VSC_B.dv[6] = controller_1dof_VSC_B.cph;
      controller_1dof_VSC_B.dv[11] = -controller_1dof_VSC_B.sph;
      controller_1dof_VSC_B.dv[16] = 0.0;
      controller_1dof_VSC_B.dv[21] = 0.0;
      controller_1dof_VSC_B.dv[26] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        controller_1dof_VSC_B.dv[5 * i_0 + 2] = 0.0;
        controller_1dof_VSC_B.dv[5 * i_0 + 3] = 0.0;
        controller_1dof_VSC_B.dv[5 * i_0 + 4] = 0.0;
      }

      controller_1dof_VSC_B.dv3[0] = controller_1dof_VSC_DW.Delay2_DSTATE[0] -
        controller_1dof_VSC_DW.Memory4_PreviousInput[2];
      controller_1dof_VSC_B.Pt_g = controller_1dof_VSC_B.wq1 -
        controller_1dof_VSC_DW.Memory4_PreviousInput[3];
      controller_1dof_VSC_B.dv3[1] = controller_1dof_VSC_B.Pt_g;
      controller_1dof_VSC_B.d1 = controller_1dof_VSC_B.wr1 -
        controller_1dof_VSC_DW.Memory4_PreviousInput[4];
      controller_1dof_VSC_B.dv3[2] = controller_1dof_VSC_B.d1;
      controller_1dof_VSC_B.dv3[3] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[2];
      controller_1dof_VSC_B.dv3[4] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[3];
      controller_1dof_VSC_B.dv3[5] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[4];
      controller_1dof_VSC_B.Pt[0] = controller_1dof_VSC_B.d *
        controller_1dof_VSC_B.Pt_g - controller_1dof_VSC_B.Gain9 *
        controller_1dof_VSC_B.d1;
      controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.d1 *
        controller_1dof_VSC_B.cph;
      controller_1dof_VSC_B.Pt[5] = (controller_1dof_VSC_B.Pt_g *
        controller_1dof_VSC_B.sph + controller_1dof_VSC_B.Gain9) /
        (controller_1dof_VSC_B.cth * controller_1dof_VSC_B.cth);
      controller_1dof_VSC_B.Pt[10] = -1.0;
      controller_1dof_VSC_B.Pt[15] = -controller_1dof_VSC_B.sph *
        controller_1dof_VSC_B.tth;
      controller_1dof_VSC_B.Pt[20] = -controller_1dof_VSC_B.cph *
        controller_1dof_VSC_B.tth;
      controller_1dof_VSC_B.Pt[1] = controller_1dof_VSC_B.Pt_g *
        -controller_1dof_VSC_B.sph - controller_1dof_VSC_B.Gain9;
      controller_1dof_VSC_B.Pt[6] = 0.0;
      controller_1dof_VSC_B.Pt[11] = 0.0;
      controller_1dof_VSC_B.Pt[16] = -controller_1dof_VSC_B.cph;
      controller_1dof_VSC_B.Pt[21] = controller_1dof_VSC_B.sph;
      for (i_0 = 0; i_0 < 5; i_0++) {
        controller_1dof_VSC_B.Gain9 = 0.0;
        for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 6;
             controller_1dof_VSC_B.r1++) {
          controller_1dof_VSC_B.Gain9 += controller_1dof_VSC_B.dv[5 *
            controller_1dof_VSC_B.r1 + i_0] *
            controller_1dof_VSC_B.dv3[controller_1dof_VSC_B.r1];
        }

        controller_1dof_VSC_B.xt[i_0] = controller_1dof_VSC_P.Ts_EKF_integr *
          controller_1dof_VSC_B.Gain9 +
          controller_1dof_VSC_DW.Memory4_PreviousInput[i_0];
        controller_1dof_VSC_B.Pt[5 * i_0 + 2] = 0.0;
        controller_1dof_VSC_B.Pt[5 * i_0 + 3] = 0.0;
        controller_1dof_VSC_B.Pt[5 * i_0 + 4] = 0.0;
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
             controller_1dof_VSC_B.r1++) {
          controller_1dof_VSC_B.Gain9 = 0.0;
          controller_1dof_VSC_B.tth = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i_0;
            controller_1dof_VSC_B.Gain9 += controller_1dof_VSC_B.Pt1[5 *
              controller_1dof_VSC_B.r1 + Pt1_tmp] *
              controller_1dof_VSC_B.Pt[At1_tmp];
            controller_1dof_VSC_B.tth += controller_1dof_VSC_B.Pt[5 * Pt1_tmp +
              controller_1dof_VSC_B.r1] * controller_1dof_VSC_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * controller_1dof_VSC_B.r1 + i_0;
          controller_1dof_VSC_B.Pt1_m[Pt1_tmp] = controller_1dof_VSC_B.tth;
          controller_1dof_VSC_B.At1[Pt1_tmp] = controller_1dof_VSC_B.Gain9;
        }
      }

      for (i_0 = 0; i_0 < 25; i_0++) {
        controller_1dof_VSC_B.Pt[i_0] = ((controller_1dof_VSC_B.At1[i_0] +
          controller_1dof_VSC_B.Pt1_m[i_0]) + controller_1dof_VSC_P.Q_phth[i_0])
          * controller_1dof_VSC_P.Ts_EKF_integr + controller_1dof_VSC_B.Pt1[i_0];
      }

      for (i_0 = 0; i_0 < 5; i_0++) {
        controller_1dof_VSC_DW.Memory4_PreviousInput[i_0] =
          controller_1dof_VSC_B.xt[i_0];
      }

      memcpy(&controller_1dof_VSC_B.Pt1[0], &controller_1dof_VSC_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      controller_1dof_VSC_B.Lk[i_0] = c[i_0];
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
           controller_1dof_VSC_B.r1++) {
        controller_1dof_VSC_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_VSC_B.wq1 += controller_1dof_VSC_B.Pt[5 * Pt1_tmp +
            controller_1dof_VSC_B.r1] * controller_1dof_VSC_B.Lk[5 * i_0 +
            Pt1_tmp];
        }

        controller_1dof_VSC_B.B[controller_1dof_VSC_B.r1 + 5 * i_0] =
          controller_1dof_VSC_B.wq1;
      }
    }

    for (i_0 = 0; i_0 < 10; i_0++) {
      controller_1dof_VSC_B.A_tmp_f[i_0] = b_b[i_0];
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
           controller_1dof_VSC_B.r1++) {
        controller_1dof_VSC_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_VSC_B.wq1 += static_cast<real_T>
            (controller_1dof_VSC_B.A_tmp_f[(Pt1_tmp << 1) + i_0]) *
            controller_1dof_VSC_B.Pt[5 * controller_1dof_VSC_B.r1 + Pt1_tmp];
        }

        controller_1dof_VSC_B.A_tmp[i_0 + (controller_1dof_VSC_B.r1 << 1)] =
          controller_1dof_VSC_B.wq1;
      }

      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 2;
           controller_1dof_VSC_B.r1++) {
        controller_1dof_VSC_B.Gain9 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_VSC_B.Gain9 += controller_1dof_VSC_B.A_tmp[(Pt1_tmp <<
            1) + i_0] * controller_1dof_VSC_B.Lk[5 * controller_1dof_VSC_B.r1 +
            Pt1_tmp];
        }

        i = (controller_1dof_VSC_B.r1 << 1) + i_0;
        controller_1dof_VSC_B.minval[i] = controller_1dof_VSC_P.R_phth[i] +
          controller_1dof_VSC_B.Gain9;
      }
    }

    if (fabs(controller_1dof_VSC_B.minval[1]) > fabs
        (controller_1dof_VSC_B.minval[0])) {
      controller_1dof_VSC_B.r1 = 1;
      i = 0;
    } else {
      controller_1dof_VSC_B.r1 = 0;
      i = 1;
    }

    controller_1dof_VSC_B.wq1 = controller_1dof_VSC_B.minval[i] /
      controller_1dof_VSC_B.minval[controller_1dof_VSC_B.r1];
    controller_1dof_VSC_B.Gain9 =
      controller_1dof_VSC_B.minval[controller_1dof_VSC_B.r1 + 2];
    controller_1dof_VSC_B.tth = controller_1dof_VSC_B.minval[i + 2] -
      controller_1dof_VSC_B.Gain9 * controller_1dof_VSC_B.wq1;
    for (i_0 = 0; i_0 < 5; i_0++) {
      Pt1_tmp = 5 * controller_1dof_VSC_B.r1 + i_0;
      controller_1dof_VSC_B.Lk[Pt1_tmp] = controller_1dof_VSC_B.B[i_0] /
        controller_1dof_VSC_B.minval[controller_1dof_VSC_B.r1];
      controller_1dof_VSC_B.b = 5 * i + i_0;
      controller_1dof_VSC_B.Lk[controller_1dof_VSC_B.b] =
        (controller_1dof_VSC_B.B[i_0 + 5] - controller_1dof_VSC_B.Lk[Pt1_tmp] *
         controller_1dof_VSC_B.Gain9) / controller_1dof_VSC_B.tth;
      controller_1dof_VSC_B.Lk[Pt1_tmp] -=
        controller_1dof_VSC_B.Lk[controller_1dof_VSC_B.b] *
        controller_1dof_VSC_B.wq1;
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      controller_1dof_VSC_B.Gain9 = 0.0;
      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
           controller_1dof_VSC_B.r1++) {
        controller_1dof_VSC_B.Gain9 += static_cast<real_T>
          (controller_1dof_VSC_B.A_tmp_f[(controller_1dof_VSC_B.r1 << 1) + i_0])
          * controller_1dof_VSC_B.xt[controller_1dof_VSC_B.r1];
      }

      controller_1dof_VSC_B.RP_meas_c[i_0] = controller_1dof_VSC_B.RP_meas[i_0]
        - controller_1dof_VSC_B.Gain9;
    }

    controller_1dof_VSC_B.wq1 = controller_1dof_VSC_B.RP_meas_c[1];
    controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.RP_meas_c[0];
    for (i_0 = 0; i_0 < 5; i_0++) {
      controller_1dof_VSC_DW.Memory4_PreviousInput[i_0] =
        (controller_1dof_VSC_B.Lk[i_0 + 5] * controller_1dof_VSC_B.wq1 +
         controller_1dof_VSC_B.Lk[i_0] * controller_1dof_VSC_B.Gain9) +
        controller_1dof_VSC_B.xt[i_0];
    }

    memset(&controller_1dof_VSC_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i_0 = 0; i_0 < 5; i_0++) {
      controller_1dof_VSC_B.Pt1[i_0 + 5 * i_0] = 1.0;
    }

    for (i_0 = 0; i_0 < 5; i_0++) {
      controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.Lk[i_0 + 5];
      controller_1dof_VSC_B.wq1 = controller_1dof_VSC_B.Lk[i_0];
      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
           controller_1dof_VSC_B.r1++) {
        Pt1_tmp = controller_1dof_VSC_B.r1 << 1;
        i = 5 * controller_1dof_VSC_B.r1 + i_0;
        controller_1dof_VSC_B.Pt1_m[i] = controller_1dof_VSC_B.Pt1[i] - (
          static_cast<real_T>(controller_1dof_VSC_B.A_tmp_f[Pt1_tmp + 1]) *
          controller_1dof_VSC_B.Gain9 + static_cast<real_T>
          (controller_1dof_VSC_B.A_tmp_f[Pt1_tmp]) * controller_1dof_VSC_B.wq1);
      }

      for (controller_1dof_VSC_B.r1 = 0; controller_1dof_VSC_B.r1 < 5;
           controller_1dof_VSC_B.r1++) {
        controller_1dof_VSC_B.wq1 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_1dof_VSC_B.wq1 += controller_1dof_VSC_B.Pt1_m[5 * Pt1_tmp +
            i_0] * controller_1dof_VSC_B.Pt[5 * controller_1dof_VSC_B.r1 +
            Pt1_tmp];
        }

        controller_1dof_VSC_DW.Memory3_PreviousInput[i_0 + 5 *
          controller_1dof_VSC_B.r1] = controller_1dof_VSC_B.wq1;
      }
    }
  }

  // End of MATLAB Function: '<S32>/EKF_RP'

  // MATLAB Function: '<S27>/Y_computation' incorporates:
  //   DataTypeConversion: '<S25>/Data Type Conversion3'
  //   MATLAB Function: '<S27>/RPY_dot_computation'
  //   MATLAB Function: '<S32>/MATLAB Function'
  //   MATLAB Function: '<S34>/EKF_Y'

  controller_1dof_VSC_B.wr1 = sin(controller_1dof_VSC_DW.Memory4_PreviousInput[0]);
  controller_1dof_VSC_B.cph = cos(controller_1dof_VSC_DW.Memory4_PreviousInput[0]);
  controller_1dof_VSC_B.tth = sin(controller_1dof_VSC_DW.Memory4_PreviousInput[1]);
  controller_1dof_VSC_B.cth = cos(controller_1dof_VSC_DW.Memory4_PreviousInput[1]);
  controller_1dof_VSC_B.wq1 = rt_atan2d_snf(controller_1dof_VSC_B.In1_m.z *
    controller_1dof_VSC_B.wr1 - controller_1dof_VSC_B.In1_m.y *
    controller_1dof_VSC_B.cph, (controller_1dof_VSC_B.In1_m.y *
    controller_1dof_VSC_B.tth * controller_1dof_VSC_B.wr1 +
    controller_1dof_VSC_B.In1_m.x * controller_1dof_VSC_B.cth) +
    controller_1dof_VSC_B.In1_m.z * controller_1dof_VSC_B.tth *
    controller_1dof_VSC_B.cph);
  if (controller_1dof_VSC_B.wq1 < 0.0) {
    controller_1dof_VSC_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S34>/EKF_Y' incorporates:
  //   Delay: '<S34>/Delay2'
  //   MATLAB Function: '<S27>/Y_computation'
  //   MATLAB Function: '<S32>/MATLAB Function'
  //   Memory: '<S34>/Memory2'

  if (controller_1dof_VSC_B.DigitalClock1 -
      controller_1dof_VSC_DW.Memory2_PreviousInput_p >=
      controller_1dof_VSC_P.Ts_EKF_meas) {
    controller_1dof_VSC_DW.Memory2_PreviousInput_p =
      controller_1dof_VSC_B.DigitalClock1;
    controller_1dof_VSC_B.sph = 0.0;
    controller_1dof_VSC_B.Pt_g = 0.0;
    controller_1dof_VSC_B.b = static_cast<int32_T>(floor
      (controller_1dof_VSC_P.Ts_EKF_meas / controller_1dof_VSC_P.Ts_EKF_integr));
    if (controller_1dof_VSC_B.b - 1 >= 0) {
      controller_1dof_VSC_B.dv4[0] = 0.0;
      controller_1dof_VSC_B.dv4[1] = controller_1dof_VSC_B.wr1 /
        controller_1dof_VSC_B.cth;
      controller_1dof_VSC_B.dv4[2] = controller_1dof_VSC_B.cph /
        controller_1dof_VSC_B.cth;
      controller_1dof_VSC_B.dv4[3] = 0.0;
      controller_1dof_VSC_B.dv4[4] = 0.0;
      controller_1dof_VSC_B.dv4[5] = 0.0;
      controller_1dof_VSC_B.dv5[0] = controller_1dof_VSC_DW.Delay2_DSTATE_b[0] -
        controller_1dof_VSC_DW.Memory4_PreviousInput[2];
      controller_1dof_VSC_B.dv5[1] = controller_1dof_VSC_DW.Delay2_DSTATE_b[1] -
        controller_1dof_VSC_DW.Memory4_PreviousInput[3];
      controller_1dof_VSC_B.dv5[2] = controller_1dof_VSC_DW.Delay2_DSTATE_b[2] -
        controller_1dof_VSC_DW.Memory4_PreviousInput[4];
      controller_1dof_VSC_B.dv5[3] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[2];
      controller_1dof_VSC_B.dv5[4] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[3];
      controller_1dof_VSC_B.dv5[5] =
        controller_1dof_VSC_DW.Memory4_PreviousInput[4];
    }

    for (i = 0; i < controller_1dof_VSC_B.b; i++) {
      controller_1dof_VSC_B.Gain9 = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        controller_1dof_VSC_B.Gain9 += controller_1dof_VSC_B.dv4[i_0] *
          controller_1dof_VSC_B.dv5[i_0];
      }

      controller_1dof_VSC_B.sph = controller_1dof_VSC_P.Ts_EKF_integr *
        controller_1dof_VSC_B.Gain9 +
        controller_1dof_VSC_DW.Memory4_PreviousInput_e;
      controller_1dof_VSC_B.Pt_g = ((0.0 *
        controller_1dof_VSC_DW.Memory3_PreviousInput_h +
        controller_1dof_VSC_DW.Memory3_PreviousInput_h * 0.0) +
        controller_1dof_VSC_P.q_ps) * controller_1dof_VSC_P.Ts_EKF_integr +
        controller_1dof_VSC_DW.Memory3_PreviousInput_h;
      controller_1dof_VSC_DW.Memory4_PreviousInput_e = controller_1dof_VSC_B.sph;
      controller_1dof_VSC_DW.Memory3_PreviousInput_h =
        controller_1dof_VSC_B.Pt_g;
    }

    controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.Pt_g /
      (controller_1dof_VSC_B.Pt_g + controller_1dof_VSC_P.r_ps);
    controller_1dof_VSC_DW.Memory4_PreviousInput_e = (controller_1dof_VSC_B.wq1
      - controller_1dof_VSC_B.sph) * controller_1dof_VSC_B.Gain9 +
      controller_1dof_VSC_B.sph;
    controller_1dof_VSC_DW.Memory3_PreviousInput_h = (1.0 -
      controller_1dof_VSC_B.Gain9) * controller_1dof_VSC_B.Pt_g;
  }

  // MATLAB Function: '<S25>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S25>/Data Type Conversion2'

  controller_1dof_VSC_B.y[0] = controller_1dof_VSC_B.In1_f.x;
  controller_1dof_VSC_B.y[1] = -static_cast<real_T>
    (controller_1dof_VSC_B.In1_f.y);
  controller_1dof_VSC_B.y[2] = -static_cast<real_T>
    (controller_1dof_VSC_B.In1_f.z);

  // Gain: '<S25>/Gain1'
  controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.y[1];
  controller_1dof_VSC_B.sph = controller_1dof_VSC_B.y[0];
  controller_1dof_VSC_B.Pt_g = controller_1dof_VSC_B.y[2];
  for (i_0 = 0; i_0 < 3; i_0++) {
    // Delay: '<S32>/Delay2'
    controller_1dof_VSC_DW.Delay2_DSTATE[i_0] = (controller_1dof_VSC_P.Rz[i_0 +
      3] * controller_1dof_VSC_B.Gain9 + controller_1dof_VSC_P.Rz[i_0] *
      controller_1dof_VSC_B.sph) + controller_1dof_VSC_P.Rz[i_0 + 6] *
      controller_1dof_VSC_B.Pt_g;
  }

  // End of Gain: '<S25>/Gain1'

  // MATLAB Function: '<S27>/RPY_dot_computation' incorporates:
  //   Constant: '<S27>/Constant6'
  //   Delay: '<S32>/Delay2'
  //   MATLAB Function: '<S27>/Y_computation'
  //   MATLAB Function: '<S32>/MATLAB Function'
  //   Memory: '<S27>/Memory5'

  if ((controller_1dof_VSC_B.DigitalClock1 -
       controller_1dof_VSC_DW.Memory5_PreviousInput >=
       controller_1dof_VSC_P.Ts_EKF_meas) ||
      (controller_1dof_VSC_B.DigitalClock1 == 0.0)) {
    controller_1dof_VSC_B.tth /= controller_1dof_VSC_B.cth;
    controller_1dof_VSC_DW.Memory5_PreviousInput =
      controller_1dof_VSC_B.DigitalClock1;
    controller_1dof_VSC_B.dv2[0] = 1.0;
    controller_1dof_VSC_B.dv2[3] = controller_1dof_VSC_B.wr1 *
      controller_1dof_VSC_B.tth;
    controller_1dof_VSC_B.dv2[6] = controller_1dof_VSC_B.cph *
      controller_1dof_VSC_B.tth;
    controller_1dof_VSC_B.dv2[1] = 0.0;
    controller_1dof_VSC_B.dv2[4] = controller_1dof_VSC_B.cph;
    controller_1dof_VSC_B.dv2[7] = -controller_1dof_VSC_B.wr1;
    controller_1dof_VSC_B.dv2[2] = 0.0;
    controller_1dof_VSC_B.dv2[5] = controller_1dof_VSC_B.wr1 /
      controller_1dof_VSC_B.cth;
    controller_1dof_VSC_B.dv2[8] = controller_1dof_VSC_B.cph /
      controller_1dof_VSC_B.cth;
    controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_DW.Delay2_DSTATE[0] -
      controller_1dof_VSC_DW.Memory4_PreviousInput[2] * 0.0;
    controller_1dof_VSC_B.tth = controller_1dof_VSC_DW.Delay2_DSTATE[1] -
      controller_1dof_VSC_DW.Memory4_PreviousInput[3] * 0.0;
    controller_1dof_VSC_B.wr1 = controller_1dof_VSC_DW.Delay2_DSTATE[2] -
      controller_1dof_VSC_DW.Memory4_PreviousInput[4] * 0.0;
    for (i_0 = 0; i_0 < 3; i_0++) {
      controller_1dof_VSC_DW.Memory6_PreviousInput[i_0] =
        (controller_1dof_VSC_B.dv2[i_0 + 3] * controller_1dof_VSC_B.tth +
         controller_1dof_VSC_B.dv2[i_0] * controller_1dof_VSC_B.Gain9) +
        controller_1dof_VSC_B.dv2[i_0 + 6] * controller_1dof_VSC_B.wr1;
    }
  }

  // Step: '<Root>/RPY ref'
  if (controller_1dof_VSC_B.DigitalClock1 < controller_1dof_VSC_P.RPYref_Time) {
    // Step: '<Root>/RPY ref'
    controller_1dof_VSC_B.RPYref = controller_1dof_VSC_P.RPYref_Y0;
  } else {
    // Step: '<Root>/RPY ref'
    controller_1dof_VSC_B.RPYref = controller_1dof_VSC_P.RPYref_YFinal;
  }

  // ManualSwitch: '<Root>/Manual Switch2'
  if (controller_1dof_VSC_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (i = 0; i < 28; i++) {
      controller_1dof_VSC_B.ManualSwitch2[i] =
        controller_1dof_VSC_P.Constant6_Value;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<S43>/Constant'
    //   Constant: '<S43>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion2'
    //   DataTypeConversion: '<S5>/Data Type Conversion3'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   MATLAB Function: '<S32>/MATLAB Function'
    //   MATLAB Function: '<S34>/EKF_Y'
    //   MATLAB Function: '<S43>/MATLAB Function'
    //   SignalConversion generated from: '<S45>/ SFunction '

    controller_1dof_VSC_B.ManualSwitch2[0] = rtb_DataTypeConversion1_b;
    controller_1dof_VSC_B.ManualSwitch2[1] = rtb_DataTypeConversion1_jl;
    controller_1dof_VSC_B.ManualSwitch2[2] = rtb_DataTypeConversion1_m;
    controller_1dof_VSC_B.ManualSwitch2[3] = rtb_DataTypeConversion1_j;
    controller_1dof_VSC_B.ManualSwitch2[4] = controller_1dof_VSC_B.In1_c.x;
    controller_1dof_VSC_B.ManualSwitch2[5] = controller_1dof_VSC_B.In1_c.y;
    controller_1dof_VSC_B.ManualSwitch2[6] = controller_1dof_VSC_B.In1_c.z;
    controller_1dof_VSC_B.ManualSwitch2[7] = controller_1dof_VSC_B.In1_f.x;
    controller_1dof_VSC_B.ManualSwitch2[8] = controller_1dof_VSC_B.In1_f.y;
    controller_1dof_VSC_B.ManualSwitch2[9] = controller_1dof_VSC_B.In1_f.z;
    controller_1dof_VSC_B.ManualSwitch2[10] =
      controller_1dof_VSC_B.In1.rollspeed;
    controller_1dof_VSC_B.ManualSwitch2[11] =
      controller_1dof_VSC_B.In1.pitchspeed;
    controller_1dof_VSC_B.ManualSwitch2[12] = controller_1dof_VSC_B.In1.yawspeed;
    controller_1dof_VSC_B.ManualSwitch2[13] = controller_1dof_VSC_B.y_l[0];
    controller_1dof_VSC_B.ManualSwitch2[14] = controller_1dof_VSC_B.y_l[1];
    controller_1dof_VSC_B.ManualSwitch2[15] = controller_1dof_VSC_B.y_l[2];
    controller_1dof_VSC_B.ManualSwitch2[16] = controller_1dof_VSC_B.In1_m.x;
    controller_1dof_VSC_B.ManualSwitch2[17] = controller_1dof_VSC_B.In1_m.y;
    controller_1dof_VSC_B.ManualSwitch2[18] = controller_1dof_VSC_B.In1_m.z;
    controller_1dof_VSC_B.ManualSwitch2[19] =
      controller_1dof_VSC_DW.Memory4_PreviousInput[0];
    controller_1dof_VSC_B.ManualSwitch2[20] =
      controller_1dof_VSC_DW.Memory4_PreviousInput[1];
    controller_1dof_VSC_B.ManualSwitch2[21] =
      controller_1dof_VSC_DW.Memory4_PreviousInput_e;
    controller_1dof_VSC_B.ManualSwitch2[22] =
      controller_1dof_VSC_DW.Memory6_PreviousInput[0];
    controller_1dof_VSC_B.ManualSwitch2[23] =
      controller_1dof_VSC_DW.Memory6_PreviousInput[1];
    controller_1dof_VSC_B.ManualSwitch2[24] =
      controller_1dof_VSC_DW.Memory6_PreviousInput[2];
    controller_1dof_VSC_B.ManualSwitch2[25] = controller_1dof_VSC_B.RPYref;
    controller_1dof_VSC_B.ManualSwitch2[26] =
      controller_1dof_VSC_P.Constant_Value_d;
    controller_1dof_VSC_B.ManualSwitch2[27] =
      controller_1dof_VSC_P.Constant1_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  controller_1dof_VSC_B.TmpSignalConversionAt_asyncqueu[0] =
    controller_1dof_VSC_B.DigitalClock1;
  memcpy(&controller_1dof_VSC_B.TmpSignalConversionAt_asyncqueu[1],
         &controller_1dof_VSC_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S28>/Gain2' incorporates:
  //   MATLAB Function: '<S28>/MATLAB Function2'
  //   MATLAB Function: '<S32>/MATLAB Function'
  //   MATLAB Function: '<S34>/EKF_Y'
  //   SignalConversion generated from: '<S41>/ SFunction '

  controller_1dof_VSC_B.DataTypeConversion3[2] =
    controller_1dof_VSC_P.Gain2_Gain *
    controller_1dof_VSC_DW.Memory4_PreviousInput_e;
  controller_1dof_VSC_B.DataTypeConversion3[0] =
    controller_1dof_VSC_P.Gain2_Gain *
    controller_1dof_VSC_DW.Memory4_PreviousInput[0];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S27>/RP_computation'

  controller_1dof_VSC_B.Gain[0] = controller_1dof_VSC_P.Gain_Gain *
    controller_1dof_VSC_B.ph_meas;

  // Gain: '<S28>/Gain2' incorporates:
  //   MATLAB Function: '<S32>/MATLAB Function'

  controller_1dof_VSC_B.DataTypeConversion3[1] =
    controller_1dof_VSC_P.Gain2_Gain *
    controller_1dof_VSC_DW.Memory4_PreviousInput[1];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S27>/Y_computation'

  controller_1dof_VSC_B.Gain[1] = controller_1dof_VSC_P.Gain_Gain *
    controller_1dof_VSC_B.RP_meas[1];
  controller_1dof_VSC_B.Gain[2] = controller_1dof_VSC_P.Gain_Gain *
    controller_1dof_VSC_B.wq1;

  // MATLAB Function: '<S25>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S25>/Data Type Conversion1'

  controller_1dof_VSC_B.y_g[0] = -static_cast<real_T>
    (controller_1dof_VSC_B.In1_c.x);
  controller_1dof_VSC_B.y_g[1] = controller_1dof_VSC_B.In1_c.y;
  controller_1dof_VSC_B.y_g[2] = controller_1dof_VSC_B.In1_c.z;

  // Gain: '<S25>/Gain'
  controller_1dof_VSC_B.ph_meas = controller_1dof_VSC_B.y_g[1];
  controller_1dof_VSC_B.wq1 = controller_1dof_VSC_B.y_g[0];
  controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_B.y_g[2];
  for (i = 0; i < 3; i++) {
    // Gain: '<S25>/Gain'
    controller_1dof_VSC_B.Gain_p[i] = (controller_1dof_VSC_P.Rz[i + 3] *
      controller_1dof_VSC_B.ph_meas + controller_1dof_VSC_P.Rz[i] *
      controller_1dof_VSC_B.wq1) + controller_1dof_VSC_P.Rz[i + 6] *
      controller_1dof_VSC_B.Gain9;

    // Gain: '<Root>/Gain1'
    controller_1dof_VSC_B.Gain1_j[i] = controller_1dof_VSC_P.Gain1_Gain_d *
      controller_1dof_VSC_B.y_l[i];
  }

  // DiscreteStateSpace: '<S17>/Internal'
  {
    controller_1dof_VSC_B.Internal = controller_1dof_VSC_P.Internal_C*
      controller_1dof_VSC_DW.Internal_DSTATE;
  }

  // DiscreteStateSpace: '<S18>/Internal'
  {
    controller_1dof_VSC_B.Gain6 = controller_1dof_VSC_P.Internal_C_a*
      controller_1dof_VSC_DW.Internal_DSTATE_h;
  }

  // SignalConversion generated from: '<S1>/Gain6'
  controller_1dof_VSC_B.ph_meas = controller_1dof_VSC_B.Gain6;

  // Gain: '<S1>/Gain6' incorporates:
  //   Gain: '<S1>/Gain7'
  //   SignalConversion generated from: '<S1>/Gain6'

  controller_1dof_VSC_B.Gain6 = (controller_1dof_VSC_P.beta_t_en[0] *
    controller_1dof_VSC_B.Internal + controller_1dof_VSC_P.beta_t_en[1] *
    controller_1dof_VSC_B.Gain6) + controller_1dof_VSC_P.beta_t_en[2] *
    controller_1dof_VSC_B.u_d;

  // DiscreteStateSpace: '<S10>/Internal'
  {
    controller_1dof_VSC_B.Product = controller_1dof_VSC_P.Internal_C_g*
      controller_1dof_VSC_DW.Internal_DSTATE_f;
  }

  // Gain: '<S1>/Gain6' incorporates:
  //   DiscreteIntegrator: '<S1>/Discrete-Time Integrator1'
  //   Gain: '<S1>/Gain3'
  //   Product: '<S1>/Product1'
  //   Sum: '<S1>/Sum5'

  controller_1dof_VSC_B.Gain6 = controller_1dof_VSC_P.Gain3_Gain *
    controller_1dof_VSC_DW.DiscreteTimeIntegrator1_DSTATE *
    controller_1dof_VSC_B.Product - controller_1dof_VSC_B.Gain6;

  // Gain: '<S1>/Gain8'
  controller_1dof_VSC_B.wq1 = controller_1dof_VSC_P.r *
    controller_1dof_VSC_B.Gain6;

  // Relay: '<S1>/Relay1'
  controller_1dof_VSC_DW.Relay1_Mode = ((controller_1dof_VSC_B.Gain6 >=
    controller_1dof_VSC_P.Relay1_OnVal) || ((!(controller_1dof_VSC_B.Gain6 <=
    controller_1dof_VSC_P.Relay1_OffVal)) && controller_1dof_VSC_DW.Relay1_Mode));
  if (controller_1dof_VSC_DW.Relay1_Mode) {
    // Gain: '<S1>/Gain6'
    controller_1dof_VSC_B.Gain6 = controller_1dof_VSC_P.Relay1_YOn;
  } else {
    // Gain: '<S1>/Gain6'
    controller_1dof_VSC_B.Gain6 = controller_1dof_VSC_P.Relay1_YOff;
  }

  // End of Relay: '<S1>/Relay1'

  // Gain: '<S1>/Gain9'
  controller_1dof_VSC_B.Gain9 = controller_1dof_VSC_P.q_en *
    controller_1dof_VSC_B.Gain6;

  // Gain: '<S1>/Gain6' incorporates:
  //   SignalConversion generated from: '<S1>/Gain6'

  controller_1dof_VSC_B.Gain6 = (controller_1dof_VSC_P.alpha_t_en[0] *
    controller_1dof_VSC_B.Internal + controller_1dof_VSC_P.alpha_t_en[1] *
    controller_1dof_VSC_B.ph_meas) + controller_1dof_VSC_P.alpha_t_en[2] *
    controller_1dof_VSC_B.u_d;

  // Sum: '<S1>/Sum4' incorporates:
  //   Gain: '<S1>/Gain'
  //   Gain: '<S1>/Gain1'

  controller_1dof_VSC_B.v = (controller_1dof_VSC_P.Gain_Gain_o *
    controller_1dof_VSC_B.wq1 + controller_1dof_VSC_P.Gain1_Gain_k *
    controller_1dof_VSC_B.Gain9) - controller_1dof_VSC_B.Gain6;

  // Sum: '<S1>/Sum7'
  controller_1dof_VSC_B.Sum7 = controller_1dof_VSC_B.Product -
    controller_1dof_VSC_B.Internal;

  // Product: '<S1>/Product'
  controller_1dof_VSC_B.Product = static_cast<real_T>(rtb_startingswitch) *
    controller_1dof_VSC_B.Sum7;

  // Gain: '<S1>/Gain2'
  controller_1dof_VSC_B.ph_meas = controller_1dof_VSC_P.Gain2_Gain_a *
    controller_1dof_VSC_B.Product;

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  controller_1dof_VSC_B.y1_i = controller_1dof_VSC_B.Gain1_j[0];
  controller_1dof_VSC_B.y2_k = controller_1dof_VSC_B.Gain1_j[1];
  controller_1dof_VSC_B.y3_d = controller_1dof_VSC_B.Gain1_j[2];

  // MATLAB Function: '<S4>/MATLAB Function1'
  controller_1dof_MATLABFunction1(controller_1dof_VSC_B.Gain,
    &controller_1dof_VSC_B.y1_f, &controller_1dof_VSC_B.y2_l,
    &controller_1dof_VSC_B.y3_i, &controller_1dof_VSC_DW.sf_MATLABFunction1_p);

  // MATLAB Function: '<S28>/MATLAB Function7'
  controller_1dof_MATLABFunction1(controller_1dof_VSC_B.DataTypeConversion3,
    &controller_1dof_VSC_B.y1_l, &controller_1dof_VSC_B.y2_b,
    &controller_1dof_VSC_B.y3_f, &controller_1dof_VSC_DW.sf_MATLABFunction7);

  // Gain: '<Root>/Gain2' incorporates:
  //   Constant: '<Root>/Constant'
  //   Sum: '<Root>/Sum1'

  controller_1dof_VSC_B.Gain2_b = (controller_1dof_VSC_B.y1_i +
    controller_1dof_VSC_P.Constant_Value_be) *
    controller_1dof_VSC_P.Gain2_Gain_n;

  // DataTypeConversion: '<Root>/Data Type Conversion'
  controller_1dof_VSC_B.DataTypeConversion = controller_1dof_VSC_B.In1.rollspeed;

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/failsafe'

  for (i_0 = 0; i_0 < 8; i_0++) {
    controller_1dof_VSC_B.pwmValue[i_0] = 0U;
  }

  controller_1dof_VSC_B.pwmValue[0] = rtb_DataTypeConversion1_b;
  controller_1dof_VSC_B.pwmValue[1] = rtb_DataTypeConversion1_jl;
  controller_1dof_VSC_B.pwmValue[2] = rtb_DataTypeConversion1_m;
  controller_1dof_VSC_B.pwmValue[3] = rtb_DataTypeConversion1_j;
  if (rtb_startingswitch) {
    if (!controller_1dof_VSC_DW.obj.isArmed) {
      controller_1dof_VSC_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_b = pwm_arm
        (&controller_1dof_VSC_DW.obj.pwmDevHandler,
         &controller_1dof_VSC_DW.obj.armAdvertiseObj);
      controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_VSC_DW.obj.errorStatus | rtb_DataTypeConversion1_b);
    }

    rtb_DataTypeConversion1_b = pwm_setServo
      (&controller_1dof_VSC_DW.obj.pwmDevHandler,
       controller_1dof_VSC_DW.obj.servoCount,
       controller_1dof_VSC_DW.obj.channelMask, &controller_1dof_VSC_B.pwmValue[0],
       controller_1dof_VSC_DW.obj.isMain,
       &controller_1dof_VSC_DW.obj.actuatorAdvertiseObj);
    controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_VSC_DW.obj.errorStatus | rtb_DataTypeConversion1_b);
  } else {
    rtb_DataTypeConversion1_b = pwm_disarm
      (&controller_1dof_VSC_DW.obj.pwmDevHandler,
       &controller_1dof_VSC_DW.obj.armAdvertiseObj);
    controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_VSC_DW.obj.errorStatus | rtb_DataTypeConversion1_b);
    controller_1dof_VSC_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_b = pwm_resetServo
      (&controller_1dof_VSC_DW.obj.pwmDevHandler,
       controller_1dof_VSC_DW.obj.servoCount,
       controller_1dof_VSC_DW.obj.channelMask, controller_1dof_VSC_DW.obj.isMain,
       &controller_1dof_VSC_DW.obj.actuatorAdvertiseObj);
    controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_VSC_DW.obj.errorStatus | rtb_DataTypeConversion1_b);
  }

  if (controller_1dof_VSC_DW.obj.isMain) {
    rtb_DataTypeConversion1_b = pwm_forceFailsafe
      (&controller_1dof_VSC_DW.obj.pwmDevHandler, static_cast<int32_T>
       (controller_1dof_VSC_P.failsafe_Value));
    controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_1dof_VSC_DW.obj.errorStatus | rtb_DataTypeConversion1_b);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_1dof_VSC_DW.obj_dc.orbMetadataObj,
    &controller_1dof_VSC_DW.obj_dc.eventStructObj,
    &controller_1dof_VSC_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S50>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S50>/In1'
    controller_1dof_VSC_B.In1_p = controller_1dof_VSC_B.b_varargout_2_c;
    srUpdateBC(controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_p);
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  controller_1dof_VSC_B.SignalConversion[0] =
    controller_1dof_VSC_B.In1_p.output[0];
  controller_1dof_VSC_B.SignalConversion[1] =
    controller_1dof_VSC_B.In1_p.output[1];
  controller_1dof_VSC_B.SignalConversion[2] =
    controller_1dof_VSC_B.In1_p.output[2];
  controller_1dof_VSC_B.SignalConversion[3] =
    controller_1dof_VSC_B.In1_p.output[3];

  // Update for Delay: '<S9>/Delay'
  controller_1dof_VSC_DW.Delay_DSTATE = controller_1dof_VSC_B.u_d;

  // Update for Memory: '<S9>/Memory'
  controller_1dof_VSC_DW.Memory_PreviousInput = controller_1dof_VSC_B.v;

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn'
  controller_1dof_VSC_DW.DiscreteTransferFcn_states =
    (controller_1dof_VSC_B.Gain_p[0] -
     controller_1dof_VSC_P.DiscreteTransferFcn_DenCoef[1] *
     controller_1dof_VSC_DW.DiscreteTransferFcn_states) /
    controller_1dof_VSC_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn1'
  controller_1dof_VSC_DW.DiscreteTransferFcn1_states =
    (controller_1dof_VSC_B.Gain_p[1] -
     controller_1dof_VSC_P.DiscreteTransferFcn1_DenCoef[1] *
     controller_1dof_VSC_DW.DiscreteTransferFcn1_states) /
    controller_1dof_VSC_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn2'
  controller_1dof_VSC_DW.DiscreteTransferFcn2_states =
    (controller_1dof_VSC_B.Gain_p[2] -
     controller_1dof_VSC_P.DiscreteTransferFcn2_DenCoef[1] *
     controller_1dof_VSC_DW.DiscreteTransferFcn2_states) /
    controller_1dof_VSC_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S34>/Delay2' incorporates:
  //   Delay: '<S32>/Delay2'

  controller_1dof_VSC_DW.Delay2_DSTATE_b[0] =
    controller_1dof_VSC_DW.Delay2_DSTATE[0];
  controller_1dof_VSC_DW.Delay2_DSTATE_b[1] =
    controller_1dof_VSC_DW.Delay2_DSTATE[1];
  controller_1dof_VSC_DW.Delay2_DSTATE_b[2] =
    controller_1dof_VSC_DW.Delay2_DSTATE[2];

  // Update for DiscreteStateSpace: '<S17>/Internal'
  {
    real_T xnew[1];
    xnew[0] = controller_1dof_VSC_P.Internal_A*
      controller_1dof_VSC_DW.Internal_DSTATE;
    xnew[0] += controller_1dof_VSC_P.Internal_B*controller_1dof_VSC_B.Gain2_b;
    (void) memcpy(&controller_1dof_VSC_DW.Internal_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  // Update for DiscreteStateSpace: '<S18>/Internal'
  {
    real_T xnew[1];
    xnew[0] = controller_1dof_VSC_P.Internal_A_d*
      controller_1dof_VSC_DW.Internal_DSTATE_h;
    xnew[0] += controller_1dof_VSC_P.Internal_B_f*
      controller_1dof_VSC_B.DataTypeConversion;
    (void) memcpy(&controller_1dof_VSC_DW.Internal_DSTATE_h, xnew,
                  sizeof(real_T)*1);
  }

  // Update for DiscreteStateSpace: '<S10>/Internal'
  {
    real_T xnew[1];
    xnew[0] = controller_1dof_VSC_P.Internal_A_n*
      controller_1dof_VSC_DW.Internal_DSTATE_f;
    xnew[0] += controller_1dof_VSC_P.Internal_B_p*controller_1dof_VSC_B.RPYref;
    (void) memcpy(&controller_1dof_VSC_DW.Internal_DSTATE_f, xnew,
                  sizeof(real_T)*1);
  }

  // Update for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' incorporates:
  //   Gain: '<S1>/Gain11'

  controller_1dof_VSC_DW.DiscreteTimeIntegrator1_DSTATE +=
    controller_1dof_VSC_P.epsilon * controller_1dof_VSC_B.ph_meas *
    controller_1dof_VSC_P.DiscreteTimeIntegrator1_gainval;

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controller_1dof_VSC_M->Timing.taskTime0 =
    ((time_T)(++controller_1dof_VSC_M->Timing.clockTick0)) *
    controller_1dof_VSC_M->Timing.stepSize0;
}

// Model initialize function
void controller_1dof_VSC_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controller_1dof_VSC_M, -1);
  controller_1dof_VSC_M->Timing.stepSize0 = 0.01;

  // External mode info
  controller_1dof_VSC_M->Sizes.checksums[0] = (2876202576U);
  controller_1dof_VSC_M->Sizes.checksums[1] = (307460338U);
  controller_1dof_VSC_M->Sizes.checksums[2] = (3304566105U);
  controller_1dof_VSC_M->Sizes.checksums[3] = (3275934033U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[37];
    controller_1dof_VSC_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[19] = (sysRanDType *)
      &controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_p;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = (sysRanDType *)
      &controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_iw;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_i;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC_a;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = (sysRanDType *)
      &controller_1dof_VSC_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &controller_1dof_VSC_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &controller_1dof_VSC_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &controller_1dof_VSC_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_1dof_VSC_M->extModeInfo,
      &controller_1dof_VSC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_1dof_VSC_M->extModeInfo,
                        controller_1dof_VSC_M->Sizes.checksums);
    rteiSetTPtr(controller_1dof_VSC_M->extModeInfo, rtmGetTPtr
                (controller_1dof_VSC_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Delay: '<S9>/Delay'
    controller_1dof_VSC_DW.Delay_DSTATE =
      controller_1dof_VSC_P.Delay_InitialCondition;

    // InitializeConditions for Memory: '<S9>/Memory'
    controller_1dof_VSC_DW.Memory_PreviousInput =
      controller_1dof_VSC_P.Memory_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn' 
    controller_1dof_VSC_DW.DiscreteTransferFcn_states =
      controller_1dof_VSC_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn1' 
    controller_1dof_VSC_DW.DiscreteTransferFcn1_states =
      controller_1dof_VSC_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S36>/Discrete Transfer Fcn2' 
    controller_1dof_VSC_DW.DiscreteTransferFcn2_states =
      controller_1dof_VSC_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Memory: '<S32>/Memory4'
    for (i = 0; i < 5; i++) {
      controller_1dof_VSC_DW.Memory4_PreviousInput[i] =
        controller_1dof_VSC_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S32>/Memory4'

    // InitializeConditions for Delay: '<S32>/Delay2'
    controller_1dof_VSC_DW.Delay2_DSTATE[0] =
      controller_1dof_VSC_P.Delay2_InitialCondition;
    controller_1dof_VSC_DW.Delay2_DSTATE[1] =
      controller_1dof_VSC_P.Delay2_InitialCondition;
    controller_1dof_VSC_DW.Delay2_DSTATE[2] =
      controller_1dof_VSC_P.Delay2_InitialCondition;

    // InitializeConditions for Memory: '<S32>/Memory2'
    controller_1dof_VSC_DW.Memory2_PreviousInput =
      controller_1dof_VSC_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S32>/Memory3'
    memcpy(&controller_1dof_VSC_DW.Memory3_PreviousInput[0],
           &controller_1dof_VSC_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S34>/Memory4'
    controller_1dof_VSC_DW.Memory4_PreviousInput_e = controller_1dof_VSC_P.x0_ps;

    // InitializeConditions for Memory: '<S34>/Memory3'
    controller_1dof_VSC_DW.Memory3_PreviousInput_h = controller_1dof_VSC_P.P0_ps;

    // InitializeConditions for Memory: '<S34>/Memory2'
    controller_1dof_VSC_DW.Memory2_PreviousInput_p =
      controller_1dof_VSC_P.Memory2_InitialCondition_g;

    // InitializeConditions for Memory: '<S27>/Memory5'
    controller_1dof_VSC_DW.Memory5_PreviousInput =
      controller_1dof_VSC_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S34>/Delay2'
    controller_1dof_VSC_DW.Delay2_DSTATE_b[0] =
      controller_1dof_VSC_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S27>/Memory6'
    controller_1dof_VSC_DW.Memory6_PreviousInput[0] =
      controller_1dof_VSC_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S34>/Delay2'
    controller_1dof_VSC_DW.Delay2_DSTATE_b[1] =
      controller_1dof_VSC_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S27>/Memory6'
    controller_1dof_VSC_DW.Memory6_PreviousInput[1] =
      controller_1dof_VSC_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S34>/Delay2'
    controller_1dof_VSC_DW.Delay2_DSTATE_b[2] =
      controller_1dof_VSC_P.Delay2_InitialCondition_l;

    // InitializeConditions for Memory: '<S27>/Memory6'
    controller_1dof_VSC_DW.Memory6_PreviousInput[2] =
      controller_1dof_VSC_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S17>/Internal'
    controller_1dof_VSC_DW.Internal_DSTATE =
      controller_1dof_VSC_P.Internal_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S18>/Internal'
    controller_1dof_VSC_DW.Internal_DSTATE_h =
      controller_1dof_VSC_P.Internal_InitialCondition_p;

    // InitializeConditions for DiscreteStateSpace: '<S10>/Internal'
    controller_1dof_VSC_DW.Internal_DSTATE_f =
      controller_1dof_VSC_P.Internal_InitialCondition_k;

    // InitializeConditions for DiscreteIntegrator: '<S1>/Discrete-Time Integrator1' 
    controller_1dof_VSC_DW.DiscreteTimeIntegrator1_DSTATE =
      controller_1dof_VSC_P.DiscreteTimeIntegrator1_IC;

    // SystemInitialize for Enabled SubSystem: '<S71>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    controller_1dof_VSC_B.In1 = controller_1dof_VSC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S71>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S61>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S62>/In1' incorporates:
    //   Outport: '<S62>/Out1'

    controller_1dof_VSC_B.In1_m = controller_1dof_VSC_P.Out1_Y0_kk;

    // End of SystemInitialize for SubSystem: '<S61>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S59>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S60>/In1' incorporates:
    //   Outport: '<S60>/Out1'

    controller_1dof_VSC_B.In1_f = controller_1dof_VSC_P.Out1_Y0_hr;

    // End of SystemInitialize for SubSystem: '<S59>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S57>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    controller_1dof_VSC_B.In1_c = controller_1dof_VSC_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S57>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    controller_MATLABFunction1_Init(&controller_1dof_VSC_DW.sf_MATLABFunction1_p);

    // SystemInitialize for MATLAB Function: '<S28>/MATLAB Function7'
    controller_MATLABFunction1_Init(&controller_1dof_VSC_DW.sf_MATLABFunction7);

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S50>/In1' incorporates:
    //   Outport: '<S50>/Out1'

    controller_1dof_VSC_B.In1_p = controller_1dof_VSC_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S71>/SourceBlock'
    controller_1dof_VSC_DW.obj_m.matlabCodegenIsDeleted = false;
    controller_1dof_VSC_DW.obj_m.isInitialized = 1;
    controller_1dof_VSC_DW.obj_m.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_1dof_VSC_DW.obj_m.orbMetadataObj,
                         &controller_1dof_VSC_DW.obj_m.eventStructObj);
    controller_1dof_VSC_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S61>/SourceBlock'
    controller_1dof_VSC_DW.obj_c.matlabCodegenIsDeleted = false;
    controller_1dof_VSC_DW.obj_c.isInitialized = 1;
    controller_1dof_VSC_DW.obj_c.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(controller_1dof_VSC_DW.obj_c.orbMetadataObj,
                         &controller_1dof_VSC_DW.obj_c.eventStructObj);
    controller_1dof_VSC_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S59>/SourceBlock'
    controller_1dof_VSC_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_1dof_VSC_DW.obj_d.isInitialized = 1;
    controller_1dof_VSC_DW.obj_d.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_1dof_VSC_DW.obj_d.orbMetadataObj,
                         &controller_1dof_VSC_DW.obj_d.eventStructObj);
    controller_1dof_VSC_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S57>/SourceBlock'
    controller_1dof_VSC_DW.obj_f.matlabCodegenIsDeleted = false;
    controller_1dof_VSC_DW.obj_f.isInitialized = 1;
    controller_1dof_VSC_DW.obj_f.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_1dof_VSC_DW.obj_f.orbMetadataObj,
                         &controller_1dof_VSC_DW.obj_f.eventStructObj);
    controller_1dof_VSC_DW.obj_f.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/failsafe'

    controller_1dof_VSC_DW.obj.errorStatus = 0U;
    controller_1dof_VSC_DW.obj.isInitialized = 0;
    controller_1dof_VSC_DW.obj.matlabCodegenIsDeleted = false;
    controller_1do_SystemCore_setup(&controller_1dof_VSC_DW.obj,
      rtb_startingswitch, controller_1dof_VSC_P.failsafe_Value);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controller_1dof_VSC_DW.obj_dc.matlabCodegenIsDeleted = false;
    controller_1dof_VSC_DW.obj_dc.isInitialized = 1;
    controller_1dof_VSC_DW.obj_dc.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(controller_1dof_VSC_DW.obj_dc.orbMetadataObj,
                         &controller_1dof_VSC_DW.obj_dc.eventStructObj);
    controller_1dof_VSC_DW.obj_dc.isSetupComplete = true;
  }
}

// Model terminate function
void controller_1dof_VSC_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S71>/SourceBlock'
  if (!controller_1dof_VSC_DW.obj_m.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj_m.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_VSC_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S71>/SourceBlock'

  // Terminate for MATLABSystem: '<S61>/SourceBlock'
  if (!controller_1dof_VSC_DW.obj_c.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj_c.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_VSC_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S61>/SourceBlock'

  // Terminate for MATLABSystem: '<S59>/SourceBlock'
  if (!controller_1dof_VSC_DW.obj_d.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj_d.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_VSC_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S59>/SourceBlock'

  // Terminate for MATLABSystem: '<S57>/SourceBlock'
  if (!controller_1dof_VSC_DW.obj_f.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj_f.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj_f.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_VSC_DW.obj_f.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S57>/SourceBlock'
  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!controller_1dof_VSC_DW.obj.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj.isSetupComplete) {
      status = pwm_disarm(&controller_1dof_VSC_DW.obj.pwmDevHandler,
                          &controller_1dof_VSC_DW.obj.armAdvertiseObj);
      controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_VSC_DW.obj.errorStatus | status);
      status = pwm_resetServo(&controller_1dof_VSC_DW.obj.pwmDevHandler,
        controller_1dof_VSC_DW.obj.servoCount,
        controller_1dof_VSC_DW.obj.channelMask,
        controller_1dof_VSC_DW.obj.isMain,
        &controller_1dof_VSC_DW.obj.actuatorAdvertiseObj);
      controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_VSC_DW.obj.errorStatus | status);
      status = pwm_close(&controller_1dof_VSC_DW.obj.pwmDevHandler,
                         &controller_1dof_VSC_DW.obj.actuatorAdvertiseObj,
                         &controller_1dof_VSC_DW.obj.armAdvertiseObj);
      controller_1dof_VSC_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_1dof_VSC_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controller_1dof_VSC_DW.obj_dc.matlabCodegenIsDeleted) {
    controller_1dof_VSC_DW.obj_dc.matlabCodegenIsDeleted = true;
    if ((controller_1dof_VSC_DW.obj_dc.isInitialized == 1) &&
        controller_1dof_VSC_DW.obj_dc.isSetupComplete) {
      uORB_read_terminate(&controller_1dof_VSC_DW.obj_dc.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
