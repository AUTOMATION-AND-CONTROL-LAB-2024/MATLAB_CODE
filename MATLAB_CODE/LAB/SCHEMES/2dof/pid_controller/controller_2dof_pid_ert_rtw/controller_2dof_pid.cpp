//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_2dof_pid.cpp
//
// Code generated for Simulink model 'controller_2dof_pid'.
//
// Model version                  : 1.10
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 18:20:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_2dof_pid.h"
#include "rtwtypes.h"
#include "controller_2dof_pid_types.h"
#include "controller_2dof_pid_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S1>/MATLAB Function1'
const int32_T controller_2dof_pid_CALL_EVENT = -1;

// Named constants for MATLAB Function: '<S4>/MATLAB Function1'
const int32_T controller_2dof_pi_CALL_EVENT_c = -1;

// Block signals (default storage)
B_controller_2dof_pid_T controller_2dof_pid_B;

// Block states (default storage)
DW_controller_2dof_pid_T controller_2dof_pid_DW;

// Real-time model
RT_MODEL_controller_2dof_pid_T controller_2dof_pid_M_ =
  RT_MODEL_controller_2dof_pid_T();
RT_MODEL_controller_2dof_pid_T *const controller_2dof_pid_M =
  &controller_2dof_pid_M_;

// Forward declaration for local functions
static void controller_2do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<S1>/MATLAB Function1'
//    '<S1>/MATLAB Function2'
//
void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_2dof_pid_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S1>/MATLAB Function1'
//    '<S1>/MATLAB Function2'
//
void controller_2dof_MATLABFunction1(const real_T rtu_x1[2], real_T rtu_u_sat1,
  real_T rtu_e, real_T rtu_u_min, real_T rtu_u_max, boolean_T rtu_on_off, real_T
  rty_x[2], real_T *rty_u_sat, DW_MATLABFunction1_controller_T *localDW)
{
  real_T b_b;
  real_T b_idx_0;
  real_T b_idx_1;
  real_T rty_x_0;
  real_T tmp;
  localDW->sfEvent = controller_2dof_pid_CALL_EVENT;
  b_idx_0 = rtu_x1[0];
  b_idx_1 = rtu_x1[1];
  b_b = rtu_u_sat1;
  if (!rtu_on_off) {
    b_idx_0 = 0.0;
    b_idx_1 = 0.0;
    b_b = 0.0;
  }

  rty_x_0 = (controller_2dof_pid_P.A_cond[0] * b_idx_0 +
             controller_2dof_pid_P.A_cond[2] * b_idx_1) +
    controller_2dof_pid_P.B_cond[0] * b_b;
  rty_x[0] = rty_x_0;
  tmp = controller_2dof_pid_P.C[0] * rty_x_0;
  rty_x_0 = (controller_2dof_pid_P.A_cond[1] * b_idx_0 +
             controller_2dof_pid_P.A_cond[3] * b_idx_1) +
    controller_2dof_pid_P.B_cond[1] * b_b;
  rty_x[1] = rty_x_0;
  b_idx_0 = (controller_2dof_pid_P.C[1] * rty_x_0 + tmp) +
    controller_2dof_pid_P.D * rtu_e;
  if ((rtu_u_max <= b_idx_0) || rtIsNaN(b_idx_0)) {
    b_idx_0 = rtu_u_max;
  }

  if ((rtu_u_min >= b_idx_0) || rtIsNaN(b_idx_0)) {
    *rty_u_sat = rtu_u_min;
  } else {
    *rty_u_sat = b_idx_0;
  }
}

//
// System initialize for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S25>/MATLAB Function7'
//
void controll_MATLABFunction1_f_Init(DW_MATLABFunction1_controll_b_T *localDW)
{
  localDW->sfEvent = controller_2dof_pi_CALL_EVENT_c;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S25>/MATLAB Function7'
//
void controller_2d_MATLABFunction1_m(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controll_b_T *localDW)
{
  localDW->sfEvent = controller_2dof_pi_CALL_EVENT_c;
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

static void controller_2do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
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
void controller_2dof_pid_step(void)
{
  // local block i/o variables
  boolean_T rtb_ManualSwitch1;
  int32_T Pt1_tmp;
  uint16_T rtb_DataTypeConversion1_ds;
  uint16_T rtb_DataTypeConversion1_e;
  uint16_T rtb_DataTypeConversion1_f;
  uint16_T rtb_DataTypeConversion1_g;
  boolean_T b_varargout_1;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_kv);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_h);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S24>/Discrete Time1'
  //   DigitalClock: '<S33>/Discrete Time'
  //   DigitalClock: '<S36>/Discrete Time'
  //   Step: '<Root>/RP ref'

  controller_2dof_pid_B.DigitalClock1 = controller_2dof_pid_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/Manual Switch1'
  if (controller_2dof_pid_P.ManualSwitch1_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Constant2'

    rtb_ManualSwitch1 = controller_2dof_pid_P.Constant2_Value_i;
  } else {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/ARM PWM1'

    rtb_ManualSwitch1 = controller_2dof_pid_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // DiscreteStateSpace: '<S11>/Internal'
  {
    controller_2dof_pid_B.Internal = controller_2dof_pid_P.Internal_C*
      controller_2dof_pid_DW.Internal_DSTATE;
  }

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S1>/Gain'

  controller_2dof_pid_B.Product = controller_2dof_pid_P.Gain_Gain_c *
    controller_2dof_pid_B.Internal * static_cast<real_T>(rtb_ManualSwitch1);

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   Constant: '<S1>/Constant6'
  //   Delay: '<S1>/Delay2'
  //   Delay: '<S1>/Delay3'

  controller_2dof_MATLABFunction1(controller_2dof_pid_DW.Delay2_DSTATE,
    controller_2dof_pid_DW.Delay3_DSTATE, controller_2dof_pid_B.Product,
    controller_2dof_pid_P.Constant3_Value, controller_2dof_pid_P.Constant6_Value,
    rtb_ManualSwitch1, controller_2dof_pid_B.x_d, &controller_2dof_pid_B.u_sat_o,
    &controller_2dof_pid_DW.sf_MATLABFunction1);

  // DiscreteStateSpace: '<S12>/Internal'
  {
    controller_2dof_pid_B.Internal_g = controller_2dof_pid_P.Internal_C_e*
      controller_2dof_pid_DW.Internal_DSTATE_f;
  }

  // Product: '<S1>/Product1' incorporates:
  //   Gain: '<S1>/Gain1'

  controller_2dof_pid_B.Product1 = controller_2dof_pid_P.Gain1_Gain *
    controller_2dof_pid_B.Internal_g * static_cast<real_T>(rtb_ManualSwitch1);

  // MATLAB Function: '<S1>/MATLAB Function2' incorporates:
  //   Constant: '<S1>/Constant1'
  //   Constant: '<S1>/Constant2'
  //   Delay: '<S1>/Delay1'
  //   Delay: '<S1>/Delay4'

  controller_2dof_MATLABFunction1(controller_2dof_pid_DW.Delay1_DSTATE,
    controller_2dof_pid_DW.Delay4_DSTATE, controller_2dof_pid_B.Product1,
    controller_2dof_pid_P.Constant1_Value, controller_2dof_pid_P.Constant2_Value,
    rtb_ManualSwitch1, controller_2dof_pid_B.x, &controller_2dof_pid_B.u_sat,
    &controller_2dof_pid_DW.sf_MATLABFunction2);

  // MATLAB Function: '<S1>/MATLAB Function3'
  controller_2dof_pid_B.tau_o[0] = controller_2dof_pid_B.u_sat_o;
  controller_2dof_pid_B.tau_o[1] = controller_2dof_pid_B.u_sat;
  controller_2dof_pid_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (controller_2dof_pid_B.tau_o[0] >= 0.0) {
    controller_2dof_pid_B.u[3] = controller_2dof_pid_P.Constant3_Value_n;
    controller_2dof_pid_B.u[2] = (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[7] * controller_2dof_pid_P.Constant3_Value_n +
      controller_2dof_pid_B.tau_o[0]) / (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[6]);
  } else {
    controller_2dof_pid_B.u[2] = controller_2dof_pid_P.Constant3_Value_n;
    controller_2dof_pid_B.u[3] = (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[6] * controller_2dof_pid_P.Constant3_Value_n -
      controller_2dof_pid_B.tau_o[0]) / (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[7]);
  }

  if (controller_2dof_pid_B.tau_o[1] >= 0.0) {
    controller_2dof_pid_B.u[0] = controller_2dof_pid_P.Constant3_Value_n;
    controller_2dof_pid_B.u[1] = (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[4] * controller_2dof_pid_P.Constant3_Value_n +
      controller_2dof_pid_B.tau_o[1]) / (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[5]);
  } else {
    controller_2dof_pid_B.u[1] = controller_2dof_pid_P.Constant3_Value_n;
    controller_2dof_pid_B.u[0] = (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[5] * controller_2dof_pid_P.Constant3_Value_n -
      controller_2dof_pid_B.tau_o[1]) / (controller_2dof_pid_P.param[3] *
      controller_2dof_pid_P.param[4]);
  }

  b_varargout_1 = rtIsNaN(controller_2dof_pid_B.u[0]);
  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[0]) ||
      b_varargout_1) {
    controller_2dof_pid_B.y = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.y = controller_2dof_pid_B.u[0];
  }

  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[0]) ||
      b_varargout_1) {
    controller_2dof_pid_B.minval[0] = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.minval[0] = controller_2dof_pid_B.u[0];
  }

  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[1]) ||
      rtIsNaN(controller_2dof_pid_B.u[1])) {
    controller_2dof_pid_B.y_g = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.y_g = controller_2dof_pid_B.u[1];
  }

  b_varargout_1 = rtIsNaN(controller_2dof_pid_B.u[2]);
  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[2]) ||
      b_varargout_1) {
    controller_2dof_pid_B.y_g1 = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.y_g1 = controller_2dof_pid_B.u[2];
  }

  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[2]) ||
      b_varargout_1) {
    controller_2dof_pid_B.minval[2] = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.minval[2] = controller_2dof_pid_B.u[2];
  }

  if ((controller_2dof_pid_P.Constant1_Value_j <= controller_2dof_pid_B.u[3]) ||
      rtIsNaN(controller_2dof_pid_B.u[3])) {
    controller_2dof_pid_B.y_m = controller_2dof_pid_P.Constant1_Value_j;
  } else {
    controller_2dof_pid_B.y_m = controller_2dof_pid_B.u[3];
  }

  controller_2dof_pid_B.dv1[0] = 0.0;
  controller_2dof_pid_B.dv1[3] = 0.0;
  controller_2dof_pid_B.dv1[6] = controller_2dof_pid_P.param[3] *
    controller_2dof_pid_P.param[6];
  controller_2dof_pid_B.dv1[9] = -controller_2dof_pid_P.param[3] *
    controller_2dof_pid_P.param[7];
  controller_2dof_pid_B.dv1[1] = -controller_2dof_pid_P.param[3] *
    controller_2dof_pid_P.param[4];
  controller_2dof_pid_B.dv1[4] = controller_2dof_pid_P.param[3] *
    controller_2dof_pid_P.param[5];
  controller_2dof_pid_B.dv1[7] = 0.0;
  controller_2dof_pid_B.dv1[10] = 0.0;
  controller_2dof_pid_B.dv1[2] = -controller_2dof_pid_P.param[8];
  controller_2dof_pid_B.dv1[5] = -controller_2dof_pid_P.param[8];
  controller_2dof_pid_B.dv1[8] = controller_2dof_pid_P.param[8];
  controller_2dof_pid_B.dv1[11] = controller_2dof_pid_P.param[8];
  controller_2dof_pid_B.rtb_Delay_i_idx_0 = controller_2dof_pid_B.minval[0];
  controller_2dof_pid_B.rtb_Delay1_g_idx_0 = controller_2dof_pid_B.minval[2];
  for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 3;
       controller_2dof_pid_B.i++) {
    controller_2dof_pid_B.tau_allocated[controller_2dof_pid_B.i] =
      ((controller_2dof_pid_B.dv1[controller_2dof_pid_B.i + 3] *
        controller_2dof_pid_B.y_g +
        controller_2dof_pid_B.dv1[controller_2dof_pid_B.i] *
        controller_2dof_pid_B.rtb_Delay_i_idx_0) +
       controller_2dof_pid_B.dv1[controller_2dof_pid_B.i + 6] *
       controller_2dof_pid_B.rtb_Delay1_g_idx_0) +
      controller_2dof_pid_B.dv1[controller_2dof_pid_B.i + 9] *
      controller_2dof_pid_B.y_m;
  }

  controller_2dof_pid_B.u[0] = controller_2dof_pid_B.y;
  controller_2dof_pid_B.u[1] = controller_2dof_pid_B.y_g;
  controller_2dof_pid_B.u[2] = controller_2dof_pid_B.y_g1;
  controller_2dof_pid_B.u[3] = controller_2dof_pid_B.y_m;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  controller_2dof_pid_B.u1 = controller_2dof_pid_B.u[0];
  controller_2dof_pid_B.u2 = controller_2dof_pid_B.u[1];
  controller_2dof_pid_B.u3 = controller_2dof_pid_B.u[2];
  controller_2dof_pid_B.u4 = controller_2dof_pid_B.u[3];

  // DataTypeConversion: '<S49>/Data Type Conversion1' incorporates:
  //   Constant: '<S49>/Constant'
  //   Sum: '<S49>/Sum'

  controller_2dof_pid_B.temp_idx_0 = floor(controller_2dof_pid_B.u1 +
    controller_2dof_pid_P.Constant_Value_g);
  if (rtIsNaN(controller_2dof_pid_B.temp_idx_0) || rtIsInf
      (controller_2dof_pid_B.temp_idx_0)) {
    controller_2dof_pid_B.temp_idx_0 = 0.0;
  } else {
    controller_2dof_pid_B.temp_idx_0 = fmod(controller_2dof_pid_B.temp_idx_0,
      65536.0);
  }

  rtb_DataTypeConversion1_ds = static_cast<uint16_T>
    (controller_2dof_pid_B.temp_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_2dof_pid_B.temp_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_2dof_pid_B.temp_idx_0)));

  // End of DataTypeConversion: '<S49>/Data Type Conversion1'

  // DataTypeConversion: '<S50>/Data Type Conversion1' incorporates:
  //   Constant: '<S50>/Constant'
  //   Sum: '<S50>/Sum'

  controller_2dof_pid_B.temp_idx_0 = floor(controller_2dof_pid_B.u2 +
    controller_2dof_pid_P.Constant_Value_e);
  if (rtIsNaN(controller_2dof_pid_B.temp_idx_0) || rtIsInf
      (controller_2dof_pid_B.temp_idx_0)) {
    controller_2dof_pid_B.temp_idx_0 = 0.0;
  } else {
    controller_2dof_pid_B.temp_idx_0 = fmod(controller_2dof_pid_B.temp_idx_0,
      65536.0);
  }

  rtb_DataTypeConversion1_f = static_cast<uint16_T>
    (controller_2dof_pid_B.temp_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_2dof_pid_B.temp_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_2dof_pid_B.temp_idx_0)));

  // End of DataTypeConversion: '<S50>/Data Type Conversion1'

  // DataTypeConversion: '<S51>/Data Type Conversion1' incorporates:
  //   Constant: '<S51>/Constant'
  //   Sum: '<S51>/Sum'

  controller_2dof_pid_B.temp_idx_0 = floor(controller_2dof_pid_B.u3 +
    controller_2dof_pid_P.Constant_Value_l);
  if (rtIsNaN(controller_2dof_pid_B.temp_idx_0) || rtIsInf
      (controller_2dof_pid_B.temp_idx_0)) {
    controller_2dof_pid_B.temp_idx_0 = 0.0;
  } else {
    controller_2dof_pid_B.temp_idx_0 = fmod(controller_2dof_pid_B.temp_idx_0,
      65536.0);
  }

  rtb_DataTypeConversion1_e = static_cast<uint16_T>
    (controller_2dof_pid_B.temp_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_2dof_pid_B.temp_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_2dof_pid_B.temp_idx_0)));

  // End of DataTypeConversion: '<S51>/Data Type Conversion1'

  // DataTypeConversion: '<S52>/Data Type Conversion1' incorporates:
  //   Constant: '<S52>/Constant'
  //   Sum: '<S52>/Sum'

  controller_2dof_pid_B.temp_idx_0 = floor(controller_2dof_pid_B.u4 +
    controller_2dof_pid_P.Constant_Value_eh);
  if (rtIsNaN(controller_2dof_pid_B.temp_idx_0) || rtIsInf
      (controller_2dof_pid_B.temp_idx_0)) {
    controller_2dof_pid_B.temp_idx_0 = 0.0;
  } else {
    controller_2dof_pid_B.temp_idx_0 = fmod(controller_2dof_pid_B.temp_idx_0,
      65536.0);
  }

  rtb_DataTypeConversion1_g = static_cast<uint16_T>
    (controller_2dof_pid_B.temp_idx_0 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_2dof_pid_B.temp_idx_0)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_2dof_pid_B.temp_idx_0)));

  // End of DataTypeConversion: '<S52>/Data Type Conversion1'

  // MATLABSystem: '<S74>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_2dof_pid_DW.obj_n.orbMetadataObj,
    &controller_2dof_pid_DW.obj_n.eventStructObj,
    &controller_2dof_pid_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S74>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S75>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S75>/In1'
    controller_2dof_pid_B.In1 = controller_2dof_pid_B.b_varargout_2;
    srUpdateBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S74>/SourceBlock'
  // End of Outputs for SubSystem: '<S74>/Enabled Subsystem'

  // Sqrt: '<S72>/sqrt' incorporates:
  //   Product: '<S73>/Product'
  //   Product: '<S73>/Product1'
  //   Product: '<S73>/Product2'
  //   Product: '<S73>/Product3'
  //   Sum: '<S73>/Sum'

  controller_2dof_pid_B.Product3 = static_cast<real32_T>(sqrt(static_cast<real_T>
    (((controller_2dof_pid_B.In1.q[0] * controller_2dof_pid_B.In1.q[0] +
       controller_2dof_pid_B.In1.q[1] * controller_2dof_pid_B.In1.q[1]) +
      controller_2dof_pid_B.In1.q[2] * controller_2dof_pid_B.In1.q[2]) +
     controller_2dof_pid_B.In1.q[3] * controller_2dof_pid_B.In1.q[3])));

  // Product: '<S67>/Product'
  controller_2dof_pid_B.fcn5 = controller_2dof_pid_B.In1.q[0] /
    controller_2dof_pid_B.Product3;

  // Product: '<S67>/Product1'
  controller_2dof_pid_B.Product1_n = controller_2dof_pid_B.In1.q[1] /
    controller_2dof_pid_B.Product3;

  // Product: '<S67>/Product2'
  controller_2dof_pid_B.Product2 = controller_2dof_pid_B.In1.q[2] /
    controller_2dof_pid_B.Product3;

  // Product: '<S67>/Product3'
  controller_2dof_pid_B.Product3 = controller_2dof_pid_B.In1.q[3] /
    controller_2dof_pid_B.Product3;

  // Fcn: '<S57>/fcn3'
  controller_2dof_pid_B.fcn3 = (controller_2dof_pid_B.Product1_n *
    controller_2dof_pid_B.Product3 - controller_2dof_pid_B.fcn5 *
    controller_2dof_pid_B.Product2) * -2.0F;

  // If: '<S68>/If' incorporates:
  //   Constant: '<S69>/Constant'
  //   Constant: '<S70>/Constant'

  if (controller_2dof_pid_B.fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S68>/If Action Subsystem' incorporates:
    //   ActionPort: '<S69>/Action Port'

    controller_2dof_pid_B.fcn3 = controller_2dof_pid_P.Constant_Value_md;

    // End of Outputs for SubSystem: '<S68>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S68>/If Action Subsystem' incorporates:
    //   ActionPort: '<S69>/Action Port'

    // Update for If: '<S68>/If' incorporates:
    //   Constant: '<S69>/Constant'

    srUpdateBC(controller_2dof_pid_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S68>/If Action Subsystem'
  } else if (controller_2dof_pid_B.fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S68>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S70>/Action Port'

    controller_2dof_pid_B.fcn3 = controller_2dof_pid_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S68>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S68>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S70>/Action Port'

    // Update for If: '<S68>/If' incorporates:
    //   Constant: '<S70>/Constant'

    srUpdateBC(controller_2dof_pid_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S68>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S68>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S71>/Action Port'

    // Update for If: '<S68>/If'
    srUpdateBC(controller_2dof_pid_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S68>/If Action Subsystem2'
  }

  // End of If: '<S68>/If'

  // Fcn: '<S57>/fcn5' incorporates:
  //   Fcn: '<S57>/fcn2'

  controller_2dof_pid_B.y_f_tmp = controller_2dof_pid_B.fcn5 *
    controller_2dof_pid_B.fcn5;
  controller_2dof_pid_B.y_f_tmp_p = controller_2dof_pid_B.Product1_n *
    controller_2dof_pid_B.Product1_n;
  controller_2dof_pid_B.y_f_tmp_l = controller_2dof_pid_B.Product2 *
    controller_2dof_pid_B.Product2;
  controller_2dof_pid_B.y_f_tmp_j = controller_2dof_pid_B.Product3 *
    controller_2dof_pid_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S57>/fcn4'
  //   Fcn: '<S57>/fcn5'
  //   Trigonometry: '<S66>/Trigonometric Function3'

  controller_2dof_pid_B.y_f[0] = rt_atan2f_snf((controller_2dof_pid_B.Product2 *
    controller_2dof_pid_B.Product3 + controller_2dof_pid_B.fcn5 *
    controller_2dof_pid_B.Product1_n) * 2.0F, ((controller_2dof_pid_B.y_f_tmp -
    controller_2dof_pid_B.y_f_tmp_p) - controller_2dof_pid_B.y_f_tmp_l) +
    controller_2dof_pid_B.y_f_tmp_j);

  // Trigonometry: '<S66>/trigFcn'
  if (controller_2dof_pid_B.fcn3 > 1.0F) {
    controller_2dof_pid_B.fcn3 = 1.0F;
  } else if (controller_2dof_pid_B.fcn3 < -1.0F) {
    controller_2dof_pid_B.fcn3 = -1.0F;
  }

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S57>/fcn1'
  //   Fcn: '<S57>/fcn2'
  //   Trigonometry: '<S66>/Trigonometric Function1'
  //   Trigonometry: '<S66>/trigFcn'

  controller_2dof_pid_B.y_f[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (controller_2dof_pid_B.fcn3)));
  controller_2dof_pid_B.y_f[2] = rt_atan2f_snf((controller_2dof_pid_B.Product1_n
    * controller_2dof_pid_B.Product2 + controller_2dof_pid_B.fcn5 *
    controller_2dof_pid_B.Product3) * 2.0F, ((controller_2dof_pid_B.y_f_tmp +
    controller_2dof_pid_B.y_f_tmp_p) - controller_2dof_pid_B.y_f_tmp_l) -
    controller_2dof_pid_B.y_f_tmp_j);

  // MATLABSystem: '<S64>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_2dof_pid_DW.obj_g.orbMetadataObj,
    &controller_2dof_pid_DW.obj_g.eventStructObj,
    &controller_2dof_pid_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S64>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S65>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S65>/In1'
    controller_2dof_pid_B.In1_k = controller_2dof_pid_B.b_varargout_2_b;
    srUpdateBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_h);
  }

  // End of MATLABSystem: '<S64>/SourceBlock'
  // End of Outputs for SubSystem: '<S64>/Enabled Subsystem'

  // MATLABSystem: '<S60>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_2dof_pid_DW.obj_k.orbMetadataObj,
    &controller_2dof_pid_DW.obj_k.eventStructObj,
    &controller_2dof_pid_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S60>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S61>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S61>/In1'
    controller_2dof_pid_B.In1_dn = controller_2dof_pid_B.b_varargout_2_k;
    srUpdateBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_g);
  }

  // End of MATLABSystem: '<S60>/SourceBlock'
  // End of Outputs for SubSystem: '<S60>/Enabled Subsystem'

  // MATLABSystem: '<S62>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_2dof_pid_DW.obj_gg.orbMetadataObj,
    &controller_2dof_pid_DW.obj_gg.eventStructObj,
    &controller_2dof_pid_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S62>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S63>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S63>/In1'
    controller_2dof_pid_B.In1_d = controller_2dof_pid_B.b_varargout_2_cx;
    srUpdateBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S62>/SourceBlock'
  // End of Outputs for SubSystem: '<S62>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn'
  controller_2dof_pid_B.y_g = controller_2dof_pid_P.DiscreteTransferFcn_NumCoef *
    controller_2dof_pid_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn1'
  controller_2dof_pid_B.y_g1 =
    controller_2dof_pid_P.DiscreteTransferFcn1_NumCoef *
    controller_2dof_pid_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn2'
  controller_2dof_pid_B.y_m = controller_2dof_pid_P.DiscreteTransferFcn2_NumCoef
    * controller_2dof_pid_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S38>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S31>/MATLAB Function'

  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[0] =
    controller_2dof_pid_B.y_g;
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[1] =
    controller_2dof_pid_B.y_g1;
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[2] =
    controller_2dof_pid_B.y_m;

  // Delay: '<S31>/Delay'
  controller_2dof_pid_B.rtb_Delay_i_idx_0 =
    controller_2dof_pid_DW.Delay_DSTATE_e[0];

  // Delay: '<S31>/Delay1'
  controller_2dof_pid_B.rtb_Delay1_g_idx_0 =
    controller_2dof_pid_DW.Delay1_DSTATE_m[0];

  // Delay: '<S31>/Delay2'
  controller_2dof_pid_B.rtb_Delay2_g_idx_0 =
    controller_2dof_pid_DW.Delay2_DSTATE_k[0];

  // Delay: '<S31>/Delay3'
  controller_2dof_pid_B.rtb_Delay3_f_idx_0 =
    controller_2dof_pid_DW.Delay3_DSTATE_c[0];

  // Delay: '<S31>/Delay4'
  controller_2dof_pid_B.rtb_Delay4_p_idx_0 =
    controller_2dof_pid_DW.Delay4_DSTATE_j[0];

  // Delay: '<S31>/Delay5'
  controller_2dof_pid_B.rtb_Delay5_l_idx_0 =
    controller_2dof_pid_DW.Delay5_DSTATE_e[0];

  // Delay: '<S31>/Delay6'
  controller_2dof_pid_B.rtb_Delay6_g_idx_0 =
    controller_2dof_pid_DW.Delay6_DSTATE_j[0];

  // Delay: '<S31>/Delay7'
  controller_2dof_pid_B.rtb_Delay7_l_idx_0 =
    controller_2dof_pid_DW.Delay7_DSTATE_l[0];

  // Delay: '<S31>/Delay8'
  controller_2dof_pid_B.rtb_Delay8_e_idx_0 =
    controller_2dof_pid_DW.Delay8_DSTATE_m[0];

  // Delay: '<S31>/Delay9'
  controller_2dof_pid_B.rtb_Delay9_c_idx_0 =
    controller_2dof_pid_DW.Delay9_DSTATE_e[0];

  // Delay: '<S31>/Delay10'
  controller_2dof_pid_B.rtb_Delay10_g_idx_0 =
    controller_2dof_pid_DW.Delay10_DSTATE_a[0];

  // Delay: '<S31>/Delay11'
  controller_2dof_pid_B.rtb_Delay11_g_idx_0 =
    controller_2dof_pid_DW.Delay11_DSTATE_m[0];

  // Delay: '<S31>/Delay12'
  controller_2dof_pid_B.rtb_Delay12_k_idx_0 =
    controller_2dof_pid_DW.Delay12_DSTATE_h[0];

  // Delay: '<S31>/Delay13'
  controller_2dof_pid_B.rtb_Delay13_o_idx_0 =
    controller_2dof_pid_DW.Delay13_DSTATE_b[0];

  // Delay: '<S31>/Delay14'
  controller_2dof_pid_B.rtb_Delay14_a_idx_0 =
    controller_2dof_pid_DW.Delay14_DSTATE_k[0];

  // Delay: '<S31>/Delay15'
  controller_2dof_pid_B.rtb_Delay15_idx_0 =
    controller_2dof_pid_DW.Delay15_DSTATE[0];

  // Delay: '<S31>/Delay20'
  controller_2dof_pid_B.rtb_Delay20_m_idx_0 =
    controller_2dof_pid_DW.Delay20_DSTATE_m[0];

  // Delay: '<S31>/Delay21'
  controller_2dof_pid_B.rtb_Delay21_j_idx_0 =
    controller_2dof_pid_DW.Delay21_DSTATE_b[0];

  // Delay: '<S31>/Delay22'
  controller_2dof_pid_B.rtb_Delay22_c_idx_0 =
    controller_2dof_pid_DW.Delay22_DSTATE_g[0];

  // Delay: '<S31>/Delay23'
  controller_2dof_pid_B.rtb_Delay23_a_idx_0 =
    controller_2dof_pid_DW.Delay23_DSTATE_e[0];

  // Delay: '<S31>/Delay24'
  controller_2dof_pid_B.rtb_Delay24_idx_0 =
    controller_2dof_pid_DW.Delay24_DSTATE[0];

  // Delay: '<S31>/Delay25'
  controller_2dof_pid_B.rtb_Delay25_idx_0 =
    controller_2dof_pid_DW.Delay25_DSTATE[0];

  // Delay: '<S31>/Delay26'
  controller_2dof_pid_B.rtb_Delay26_idx_0 =
    controller_2dof_pid_DW.Delay26_DSTATE[0];

  // Delay: '<S31>/Delay27'
  controller_2dof_pid_B.rtb_Delay27_idx_0 =
    controller_2dof_pid_DW.Delay27_DSTATE[0];

  // Delay: '<S31>/Delay16'
  controller_2dof_pid_B.rtb_Delay16_idx_0 =
    controller_2dof_pid_DW.Delay16_DSTATE[0];

  // Delay: '<S31>/Delay17'
  controller_2dof_pid_B.rtb_Delay17_idx_0 =
    controller_2dof_pid_DW.Delay17_DSTATE[0];

  // Delay: '<S31>/Delay18'
  controller_2dof_pid_B.rtb_Delay18_idx_0 =
    controller_2dof_pid_DW.Delay18_DSTATE[0];

  // SignalConversion generated from: '<S38>/ SFunction ' incorporates:
  //   Delay: '<S31>/Delay'
  //   Delay: '<S31>/Delay1'
  //   Delay: '<S31>/Delay10'
  //   Delay: '<S31>/Delay11'
  //   Delay: '<S31>/Delay12'
  //   Delay: '<S31>/Delay13'
  //   Delay: '<S31>/Delay14'
  //   Delay: '<S31>/Delay15'
  //   Delay: '<S31>/Delay16'
  //   Delay: '<S31>/Delay17'
  //   Delay: '<S31>/Delay18'
  //   Delay: '<S31>/Delay19'
  //   Delay: '<S31>/Delay2'
  //   Delay: '<S31>/Delay20'
  //   Delay: '<S31>/Delay21'
  //   Delay: '<S31>/Delay22'
  //   Delay: '<S31>/Delay23'
  //   Delay: '<S31>/Delay24'
  //   Delay: '<S31>/Delay25'
  //   Delay: '<S31>/Delay26'
  //   Delay: '<S31>/Delay27'
  //   Delay: '<S31>/Delay3'
  //   Delay: '<S31>/Delay4'
  //   Delay: '<S31>/Delay5'
  //   Delay: '<S31>/Delay6'
  //   Delay: '<S31>/Delay7'
  //   Delay: '<S31>/Delay8'
  //   Delay: '<S31>/Delay9'
  //   MATLAB Function: '<S31>/MATLAB Function'

  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[3] =
    controller_2dof_pid_DW.Delay_DSTATE_e[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[6] =
    controller_2dof_pid_DW.Delay1_DSTATE_m[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[9] =
    controller_2dof_pid_DW.Delay2_DSTATE_k[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[12] =
    controller_2dof_pid_DW.Delay3_DSTATE_c[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[15] =
    controller_2dof_pid_DW.Delay4_DSTATE_j[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[18] =
    controller_2dof_pid_DW.Delay5_DSTATE_e[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[21] =
    controller_2dof_pid_DW.Delay6_DSTATE_j[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[24] =
    controller_2dof_pid_DW.Delay7_DSTATE_l[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[27] =
    controller_2dof_pid_DW.Delay8_DSTATE_m[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[30] =
    controller_2dof_pid_DW.Delay9_DSTATE_e[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[33] =
    controller_2dof_pid_DW.Delay10_DSTATE_a[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[36] =
    controller_2dof_pid_DW.Delay11_DSTATE_m[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[39] =
    controller_2dof_pid_DW.Delay12_DSTATE_h[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[42] =
    controller_2dof_pid_DW.Delay13_DSTATE_b[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[45] =
    controller_2dof_pid_DW.Delay14_DSTATE_k[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[48] =
    controller_2dof_pid_DW.Delay15_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[51] =
    controller_2dof_pid_DW.Delay20_DSTATE_m[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[54] =
    controller_2dof_pid_DW.Delay21_DSTATE_b[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[57] =
    controller_2dof_pid_DW.Delay22_DSTATE_g[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[60] =
    controller_2dof_pid_DW.Delay23_DSTATE_e[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[63] =
    controller_2dof_pid_DW.Delay24_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[66] =
    controller_2dof_pid_DW.Delay25_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[69] =
    controller_2dof_pid_DW.Delay26_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[72] =
    controller_2dof_pid_DW.Delay27_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[75] =
    controller_2dof_pid_DW.Delay16_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[78] =
    controller_2dof_pid_DW.Delay17_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[81] =
    controller_2dof_pid_DW.Delay18_DSTATE[0];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[84] =
    controller_2dof_pid_DW.Delay19_DSTATE[0];

  // Delay: '<S31>/Delay'
  controller_2dof_pid_B.rtb_Delay_i_idx_1 =
    controller_2dof_pid_DW.Delay_DSTATE_e[1];

  // Delay: '<S31>/Delay1'
  controller_2dof_pid_B.rtb_Delay1_g_idx_1 =
    controller_2dof_pid_DW.Delay1_DSTATE_m[1];

  // Delay: '<S31>/Delay2'
  controller_2dof_pid_B.rtb_Delay2_g_idx_1 =
    controller_2dof_pid_DW.Delay2_DSTATE_k[1];

  // Delay: '<S31>/Delay3'
  controller_2dof_pid_B.rtb_Delay3_f_idx_1 =
    controller_2dof_pid_DW.Delay3_DSTATE_c[1];

  // Delay: '<S31>/Delay4'
  controller_2dof_pid_B.rtb_Delay4_p_idx_1 =
    controller_2dof_pid_DW.Delay4_DSTATE_j[1];

  // Delay: '<S31>/Delay5'
  controller_2dof_pid_B.rtb_Delay5_l_idx_1 =
    controller_2dof_pid_DW.Delay5_DSTATE_e[1];

  // Delay: '<S31>/Delay6'
  controller_2dof_pid_B.rtb_Delay6_g_idx_1 =
    controller_2dof_pid_DW.Delay6_DSTATE_j[1];

  // Delay: '<S31>/Delay7'
  controller_2dof_pid_B.rtb_Delay7_l_idx_1 =
    controller_2dof_pid_DW.Delay7_DSTATE_l[1];

  // Delay: '<S31>/Delay8'
  controller_2dof_pid_B.rtb_Delay8_e_idx_1 =
    controller_2dof_pid_DW.Delay8_DSTATE_m[1];

  // Delay: '<S31>/Delay9'
  controller_2dof_pid_B.rtb_Delay9_c_idx_1 =
    controller_2dof_pid_DW.Delay9_DSTATE_e[1];

  // Delay: '<S31>/Delay10'
  controller_2dof_pid_B.rtb_Delay10_g_idx_1 =
    controller_2dof_pid_DW.Delay10_DSTATE_a[1];

  // Delay: '<S31>/Delay11'
  controller_2dof_pid_B.rtb_Delay11_g_idx_1 =
    controller_2dof_pid_DW.Delay11_DSTATE_m[1];

  // Delay: '<S31>/Delay12'
  controller_2dof_pid_B.rtb_Delay12_k_idx_1 =
    controller_2dof_pid_DW.Delay12_DSTATE_h[1];

  // Delay: '<S31>/Delay13'
  controller_2dof_pid_B.rtb_Delay13_o_idx_1 =
    controller_2dof_pid_DW.Delay13_DSTATE_b[1];

  // Delay: '<S31>/Delay14'
  controller_2dof_pid_B.rtb_Delay14_a_idx_1 =
    controller_2dof_pid_DW.Delay14_DSTATE_k[1];

  // Delay: '<S31>/Delay15'
  controller_2dof_pid_B.rtb_Delay15_idx_1 =
    controller_2dof_pid_DW.Delay15_DSTATE[1];

  // Delay: '<S31>/Delay20'
  controller_2dof_pid_B.rtb_Delay20_m_idx_1 =
    controller_2dof_pid_DW.Delay20_DSTATE_m[1];

  // Delay: '<S31>/Delay21'
  controller_2dof_pid_B.rtb_Delay21_j_idx_1 =
    controller_2dof_pid_DW.Delay21_DSTATE_b[1];

  // Delay: '<S31>/Delay22'
  controller_2dof_pid_B.rtb_Delay22_c_idx_1 =
    controller_2dof_pid_DW.Delay22_DSTATE_g[1];

  // Delay: '<S31>/Delay23'
  controller_2dof_pid_B.rtb_Delay23_a_idx_1 =
    controller_2dof_pid_DW.Delay23_DSTATE_e[1];

  // Delay: '<S31>/Delay24'
  controller_2dof_pid_B.rtb_Delay24_idx_1 =
    controller_2dof_pid_DW.Delay24_DSTATE[1];

  // Delay: '<S31>/Delay25'
  controller_2dof_pid_B.rtb_Delay25_idx_1 =
    controller_2dof_pid_DW.Delay25_DSTATE[1];

  // Delay: '<S31>/Delay26'
  controller_2dof_pid_B.rtb_Delay26_idx_1 =
    controller_2dof_pid_DW.Delay26_DSTATE[1];

  // Delay: '<S31>/Delay27'
  controller_2dof_pid_B.rtb_Delay27_idx_1 =
    controller_2dof_pid_DW.Delay27_DSTATE[1];

  // Delay: '<S31>/Delay16'
  controller_2dof_pid_B.rtb_Delay16_idx_1 =
    controller_2dof_pid_DW.Delay16_DSTATE[1];

  // Delay: '<S31>/Delay17'
  controller_2dof_pid_B.rtb_Delay17_idx_1 =
    controller_2dof_pid_DW.Delay17_DSTATE[1];

  // Delay: '<S31>/Delay18'
  controller_2dof_pid_B.rtb_Delay18_idx_1 =
    controller_2dof_pid_DW.Delay18_DSTATE[1];

  // SignalConversion generated from: '<S38>/ SFunction ' incorporates:
  //   Delay: '<S31>/Delay'
  //   Delay: '<S31>/Delay1'
  //   Delay: '<S31>/Delay10'
  //   Delay: '<S31>/Delay11'
  //   Delay: '<S31>/Delay12'
  //   Delay: '<S31>/Delay13'
  //   Delay: '<S31>/Delay14'
  //   Delay: '<S31>/Delay15'
  //   Delay: '<S31>/Delay16'
  //   Delay: '<S31>/Delay17'
  //   Delay: '<S31>/Delay18'
  //   Delay: '<S31>/Delay19'
  //   Delay: '<S31>/Delay2'
  //   Delay: '<S31>/Delay20'
  //   Delay: '<S31>/Delay21'
  //   Delay: '<S31>/Delay22'
  //   Delay: '<S31>/Delay23'
  //   Delay: '<S31>/Delay24'
  //   Delay: '<S31>/Delay25'
  //   Delay: '<S31>/Delay26'
  //   Delay: '<S31>/Delay27'
  //   Delay: '<S31>/Delay3'
  //   Delay: '<S31>/Delay4'
  //   Delay: '<S31>/Delay5'
  //   Delay: '<S31>/Delay6'
  //   Delay: '<S31>/Delay7'
  //   Delay: '<S31>/Delay8'
  //   Delay: '<S31>/Delay9'
  //   MATLAB Function: '<S31>/MATLAB Function'

  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[4] =
    controller_2dof_pid_DW.Delay_DSTATE_e[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[7] =
    controller_2dof_pid_DW.Delay1_DSTATE_m[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[10] =
    controller_2dof_pid_DW.Delay2_DSTATE_k[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[13] =
    controller_2dof_pid_DW.Delay3_DSTATE_c[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[16] =
    controller_2dof_pid_DW.Delay4_DSTATE_j[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[19] =
    controller_2dof_pid_DW.Delay5_DSTATE_e[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[22] =
    controller_2dof_pid_DW.Delay6_DSTATE_j[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[25] =
    controller_2dof_pid_DW.Delay7_DSTATE_l[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[28] =
    controller_2dof_pid_DW.Delay8_DSTATE_m[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[31] =
    controller_2dof_pid_DW.Delay9_DSTATE_e[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[34] =
    controller_2dof_pid_DW.Delay10_DSTATE_a[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[37] =
    controller_2dof_pid_DW.Delay11_DSTATE_m[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[40] =
    controller_2dof_pid_DW.Delay12_DSTATE_h[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[43] =
    controller_2dof_pid_DW.Delay13_DSTATE_b[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[46] =
    controller_2dof_pid_DW.Delay14_DSTATE_k[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[49] =
    controller_2dof_pid_DW.Delay15_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[52] =
    controller_2dof_pid_DW.Delay20_DSTATE_m[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[55] =
    controller_2dof_pid_DW.Delay21_DSTATE_b[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[58] =
    controller_2dof_pid_DW.Delay22_DSTATE_g[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[61] =
    controller_2dof_pid_DW.Delay23_DSTATE_e[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[64] =
    controller_2dof_pid_DW.Delay24_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[67] =
    controller_2dof_pid_DW.Delay25_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[70] =
    controller_2dof_pid_DW.Delay26_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[73] =
    controller_2dof_pid_DW.Delay27_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[76] =
    controller_2dof_pid_DW.Delay16_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[79] =
    controller_2dof_pid_DW.Delay17_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[82] =
    controller_2dof_pid_DW.Delay18_DSTATE[1];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[85] =
    controller_2dof_pid_DW.Delay19_DSTATE[1];

  // Delay: '<S31>/Delay'
  controller_2dof_pid_B.Delay_DSTATE_e = controller_2dof_pid_DW.Delay_DSTATE_e[2];

  // Delay: '<S31>/Delay1'
  controller_2dof_pid_B.Delay1_DSTATE_m =
    controller_2dof_pid_DW.Delay1_DSTATE_m[2];

  // Delay: '<S31>/Delay2'
  controller_2dof_pid_B.Delay2_DSTATE_k =
    controller_2dof_pid_DW.Delay2_DSTATE_k[2];

  // Delay: '<S31>/Delay3'
  controller_2dof_pid_B.Delay3_DSTATE_c =
    controller_2dof_pid_DW.Delay3_DSTATE_c[2];

  // Delay: '<S31>/Delay4'
  controller_2dof_pid_B.Delay4_DSTATE_j =
    controller_2dof_pid_DW.Delay4_DSTATE_j[2];

  // Delay: '<S31>/Delay5'
  controller_2dof_pid_B.Delay5_DSTATE_e =
    controller_2dof_pid_DW.Delay5_DSTATE_e[2];

  // Delay: '<S31>/Delay6'
  controller_2dof_pid_B.Delay6_DSTATE_j =
    controller_2dof_pid_DW.Delay6_DSTATE_j[2];

  // Delay: '<S31>/Delay7'
  controller_2dof_pid_B.Delay7_DSTATE_l =
    controller_2dof_pid_DW.Delay7_DSTATE_l[2];

  // Delay: '<S31>/Delay8'
  controller_2dof_pid_B.Delay8_DSTATE_m =
    controller_2dof_pid_DW.Delay8_DSTATE_m[2];

  // Delay: '<S31>/Delay9'
  controller_2dof_pid_B.Delay9_DSTATE_e =
    controller_2dof_pid_DW.Delay9_DSTATE_e[2];

  // Delay: '<S31>/Delay10'
  controller_2dof_pid_B.Delay10_DSTATE_a =
    controller_2dof_pid_DW.Delay10_DSTATE_a[2];

  // Delay: '<S31>/Delay11'
  controller_2dof_pid_B.Delay11_DSTATE_m =
    controller_2dof_pid_DW.Delay11_DSTATE_m[2];

  // Delay: '<S31>/Delay12'
  controller_2dof_pid_B.Delay12_DSTATE_h =
    controller_2dof_pid_DW.Delay12_DSTATE_h[2];

  // Delay: '<S31>/Delay13'
  controller_2dof_pid_B.Delay13_DSTATE_b =
    controller_2dof_pid_DW.Delay13_DSTATE_b[2];

  // Delay: '<S31>/Delay14'
  controller_2dof_pid_B.Delay14_DSTATE_k =
    controller_2dof_pid_DW.Delay14_DSTATE_k[2];

  // Delay: '<S31>/Delay15'
  controller_2dof_pid_B.Delay15_DSTATE = controller_2dof_pid_DW.Delay15_DSTATE[2];

  // Delay: '<S31>/Delay20'
  controller_2dof_pid_B.Delay20_DSTATE_m =
    controller_2dof_pid_DW.Delay20_DSTATE_m[2];

  // Delay: '<S31>/Delay21'
  controller_2dof_pid_B.Delay21_DSTATE_b =
    controller_2dof_pid_DW.Delay21_DSTATE_b[2];

  // Delay: '<S31>/Delay22'
  controller_2dof_pid_B.Delay22_DSTATE_g =
    controller_2dof_pid_DW.Delay22_DSTATE_g[2];

  // Delay: '<S31>/Delay23'
  controller_2dof_pid_B.Delay23_DSTATE_e =
    controller_2dof_pid_DW.Delay23_DSTATE_e[2];

  // Delay: '<S31>/Delay24'
  controller_2dof_pid_B.Delay24_DSTATE = controller_2dof_pid_DW.Delay24_DSTATE[2];

  // Delay: '<S31>/Delay25'
  controller_2dof_pid_B.Delay25_DSTATE = controller_2dof_pid_DW.Delay25_DSTATE[2];

  // Delay: '<S31>/Delay26'
  controller_2dof_pid_B.Delay26_DSTATE = controller_2dof_pid_DW.Delay26_DSTATE[2];

  // Delay: '<S31>/Delay27'
  controller_2dof_pid_B.Delay27_DSTATE = controller_2dof_pid_DW.Delay27_DSTATE[2];

  // Delay: '<S31>/Delay16'
  controller_2dof_pid_B.Delay16_DSTATE = controller_2dof_pid_DW.Delay16_DSTATE[2];

  // Delay: '<S31>/Delay17'
  controller_2dof_pid_B.Delay17_DSTATE = controller_2dof_pid_DW.Delay17_DSTATE[2];

  // Delay: '<S31>/Delay18'
  controller_2dof_pid_B.Delay18_DSTATE = controller_2dof_pid_DW.Delay18_DSTATE[2];

  // SignalConversion generated from: '<S38>/ SFunction ' incorporates:
  //   Delay: '<S31>/Delay'
  //   Delay: '<S31>/Delay1'
  //   Delay: '<S31>/Delay10'
  //   Delay: '<S31>/Delay11'
  //   Delay: '<S31>/Delay12'
  //   Delay: '<S31>/Delay13'
  //   Delay: '<S31>/Delay14'
  //   Delay: '<S31>/Delay15'
  //   Delay: '<S31>/Delay16'
  //   Delay: '<S31>/Delay17'
  //   Delay: '<S31>/Delay18'
  //   Delay: '<S31>/Delay19'
  //   Delay: '<S31>/Delay2'
  //   Delay: '<S31>/Delay20'
  //   Delay: '<S31>/Delay21'
  //   Delay: '<S31>/Delay22'
  //   Delay: '<S31>/Delay23'
  //   Delay: '<S31>/Delay24'
  //   Delay: '<S31>/Delay25'
  //   Delay: '<S31>/Delay26'
  //   Delay: '<S31>/Delay27'
  //   Delay: '<S31>/Delay3'
  //   Delay: '<S31>/Delay4'
  //   Delay: '<S31>/Delay5'
  //   Delay: '<S31>/Delay6'
  //   Delay: '<S31>/Delay7'
  //   Delay: '<S31>/Delay8'
  //   Delay: '<S31>/Delay9'
  //   MATLAB Function: '<S31>/MATLAB Function'

  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[5] =
    controller_2dof_pid_DW.Delay_DSTATE_e[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[8] =
    controller_2dof_pid_DW.Delay1_DSTATE_m[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[11] =
    controller_2dof_pid_DW.Delay2_DSTATE_k[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[14] =
    controller_2dof_pid_DW.Delay3_DSTATE_c[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[17] =
    controller_2dof_pid_DW.Delay4_DSTATE_j[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[20] =
    controller_2dof_pid_DW.Delay5_DSTATE_e[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[23] =
    controller_2dof_pid_DW.Delay6_DSTATE_j[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[26] =
    controller_2dof_pid_DW.Delay7_DSTATE_l[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[29] =
    controller_2dof_pid_DW.Delay8_DSTATE_m[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[32] =
    controller_2dof_pid_DW.Delay9_DSTATE_e[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[35] =
    controller_2dof_pid_DW.Delay10_DSTATE_a[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[38] =
    controller_2dof_pid_DW.Delay11_DSTATE_m[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[41] =
    controller_2dof_pid_DW.Delay12_DSTATE_h[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[44] =
    controller_2dof_pid_DW.Delay13_DSTATE_b[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[47] =
    controller_2dof_pid_DW.Delay14_DSTATE_k[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[50] =
    controller_2dof_pid_DW.Delay15_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[53] =
    controller_2dof_pid_DW.Delay20_DSTATE_m[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[56] =
    controller_2dof_pid_DW.Delay21_DSTATE_b[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[59] =
    controller_2dof_pid_DW.Delay22_DSTATE_g[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[62] =
    controller_2dof_pid_DW.Delay23_DSTATE_e[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[65] =
    controller_2dof_pid_DW.Delay24_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[68] =
    controller_2dof_pid_DW.Delay25_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[71] =
    controller_2dof_pid_DW.Delay26_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[74] =
    controller_2dof_pid_DW.Delay27_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[77] =
    controller_2dof_pid_DW.Delay16_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[80] =
    controller_2dof_pid_DW.Delay17_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[83] =
    controller_2dof_pid_DW.Delay18_DSTATE[2];
  controller_2dof_pid_B.TmpSignalConversionAtSFun_a[86] =
    controller_2dof_pid_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S31>/MATLAB Function'
  for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 < 29;
       controller_2dof_pid_B.r2++) {
    controller_2dof_pid_B.i = (controller_2dof_pid_B.r2 + 1) * 3;
    controller_2dof_pid_B.ph_meas =
      controller_2dof_pid_B.TmpSignalConversionAtSFun_a[controller_2dof_pid_B.i
      - 3];
    controller_2dof_pid_B.y = controller_2dof_pid_B.ph_meas *
      controller_2dof_pid_B.ph_meas;
    controller_2dof_pid_B.ph_meas =
      controller_2dof_pid_B.TmpSignalConversionAtSFun_a[controller_2dof_pid_B.i
      - 2];
    controller_2dof_pid_B.y += controller_2dof_pid_B.ph_meas *
      controller_2dof_pid_B.ph_meas;
    controller_2dof_pid_B.ph_meas =
      controller_2dof_pid_B.TmpSignalConversionAtSFun_a[controller_2dof_pid_B.i
      - 1];
    controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r2] = sqrt
      (controller_2dof_pid_B.ph_meas * controller_2dof_pid_B.ph_meas +
       controller_2dof_pid_B.y);
    controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r2 + 29] =
      static_cast<real_T>(controller_2dof_pid_B.r2) + 1.0;
  }

  for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 28;
       controller_2dof_pid_B.i++) {
    controller_2dof_pid_B.b = 27 - controller_2dof_pid_B.i;
    for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 <=
         controller_2dof_pid_B.b; controller_2dof_pid_B.r1++) {
      controller_2dof_pid_B.ph_meas =
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1];
      controller_2dof_pid_B.temp_idx_0 =
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 1];
      if (controller_2dof_pid_B.ph_meas > controller_2dof_pid_B.temp_idx_0) {
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1] =
          controller_2dof_pid_B.temp_idx_0;
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 1] =
          controller_2dof_pid_B.ph_meas;
        controller_2dof_pid_B.tth =
          controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 29];
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 29] =
          controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 30];
        controller_2dof_pid_B.b_norm[controller_2dof_pid_B.r1 + 30] =
          controller_2dof_pid_B.tth;
      }
    }
  }

  controller_2dof_pid_B.ph_meas = controller_2dof_pid_B.b_norm[41] * 3.0 - 2.0;
  controller_2dof_pid_B.y = controller_2dof_pid_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(controller_2dof_pid_B.ph_meas) - 1];
  controller_2dof_pid_B.y_idx_0 = controller_2dof_pid_B.y;

  // Sum: '<S35>/Sum23' incorporates:
  //   Delay: '<S35>/Delay'
  //   Delay: '<S35>/Delay1'
  //   Delay: '<S35>/Delay10'
  //   Delay: '<S35>/Delay11'
  //   Delay: '<S35>/Delay12'
  //   Delay: '<S35>/Delay13'
  //   Delay: '<S35>/Delay14'
  //   Delay: '<S35>/Delay2'
  //   Delay: '<S35>/Delay20'
  //   Delay: '<S35>/Delay21'
  //   Delay: '<S35>/Delay22'
  //   Delay: '<S35>/Delay23'
  //   Delay: '<S35>/Delay3'
  //   Delay: '<S35>/Delay4'
  //   Delay: '<S35>/Delay5'
  //   Delay: '<S35>/Delay6'
  //   Delay: '<S35>/Delay7'
  //   Delay: '<S35>/Delay8'
  //   Delay: '<S35>/Delay9'
  //   Sum: '<S35>/Sum'
  //   Sum: '<S35>/Sum1'
  //   Sum: '<S35>/Sum10'
  //   Sum: '<S35>/Sum11'
  //   Sum: '<S35>/Sum12'
  //   Sum: '<S35>/Sum13'
  //   Sum: '<S35>/Sum14'
  //   Sum: '<S35>/Sum2'
  //   Sum: '<S35>/Sum20'
  //   Sum: '<S35>/Sum21'
  //   Sum: '<S35>/Sum22'
  //   Sum: '<S35>/Sum3'
  //   Sum: '<S35>/Sum4'
  //   Sum: '<S35>/Sum5'
  //   Sum: '<S35>/Sum6'
  //   Sum: '<S35>/Sum7'
  //   Sum: '<S35>/Sum8'
  //   Sum: '<S35>/Sum9'

  controller_2dof_pid_B.tth =
    ((((((((((((((((((controller_2dof_pid_DW.Delay_DSTATE[0] +
                      controller_2dof_pid_B.y) +
                     controller_2dof_pid_DW.Delay1_DSTATE_b[0]) +
                    controller_2dof_pid_DW.Delay2_DSTATE_f[0]) +
                   controller_2dof_pid_DW.Delay3_DSTATE_j[0]) +
                  controller_2dof_pid_DW.Delay4_DSTATE_e[0]) +
                 controller_2dof_pid_DW.Delay5_DSTATE[0]) +
                controller_2dof_pid_DW.Delay6_DSTATE[0]) +
               controller_2dof_pid_DW.Delay7_DSTATE[0]) +
              controller_2dof_pid_DW.Delay8_DSTATE[0]) +
             controller_2dof_pid_DW.Delay9_DSTATE[0]) +
            controller_2dof_pid_DW.Delay10_DSTATE[0]) +
           controller_2dof_pid_DW.Delay11_DSTATE[0]) +
          controller_2dof_pid_DW.Delay12_DSTATE[0]) +
         controller_2dof_pid_DW.Delay13_DSTATE[0]) +
        controller_2dof_pid_DW.Delay14_DSTATE[0]) +
       controller_2dof_pid_DW.Delay20_DSTATE[0]) +
      controller_2dof_pid_DW.Delay21_DSTATE[0]) +
     controller_2dof_pid_DW.Delay22_DSTATE[0]) +
    controller_2dof_pid_DW.Delay23_DSTATE[0];
  controller_2dof_pid_B.Sum23[0] = controller_2dof_pid_B.tth;

  // Sum: '<S35>/Sum24' incorporates:
  //   Sum: '<S35>/Sum23'

  controller_2dof_pid_B.Sum24[0] = controller_2dof_pid_B.tth;

  // MATLAB Function: '<S24>/RP_computation' incorporates:
  //   Gain: '<S35>/Gain'
  //   Sum: '<S35>/Sum23'
  //   Sum: '<S35>/Sum24'

  controller_2dof_pid_B.u_vect[0] = -(controller_2dof_pid_P.Gain_Gain_n *
    controller_2dof_pid_B.tth);

  // MATLAB Function: '<S31>/MATLAB Function'
  controller_2dof_pid_B.y = controller_2dof_pid_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(controller_2dof_pid_B.ph_meas + 1.0) - 1];
  controller_2dof_pid_B.y_idx_1 = controller_2dof_pid_B.y;

  // Sum: '<S35>/Sum23' incorporates:
  //   Delay: '<S35>/Delay'
  //   Delay: '<S35>/Delay1'
  //   Delay: '<S35>/Delay10'
  //   Delay: '<S35>/Delay11'
  //   Delay: '<S35>/Delay12'
  //   Delay: '<S35>/Delay13'
  //   Delay: '<S35>/Delay14'
  //   Delay: '<S35>/Delay2'
  //   Delay: '<S35>/Delay20'
  //   Delay: '<S35>/Delay21'
  //   Delay: '<S35>/Delay22'
  //   Delay: '<S35>/Delay23'
  //   Delay: '<S35>/Delay3'
  //   Delay: '<S35>/Delay4'
  //   Delay: '<S35>/Delay5'
  //   Delay: '<S35>/Delay6'
  //   Delay: '<S35>/Delay7'
  //   Delay: '<S35>/Delay8'
  //   Delay: '<S35>/Delay9'
  //   Sum: '<S35>/Sum'
  //   Sum: '<S35>/Sum1'
  //   Sum: '<S35>/Sum10'
  //   Sum: '<S35>/Sum11'
  //   Sum: '<S35>/Sum12'
  //   Sum: '<S35>/Sum13'
  //   Sum: '<S35>/Sum14'
  //   Sum: '<S35>/Sum2'
  //   Sum: '<S35>/Sum20'
  //   Sum: '<S35>/Sum21'
  //   Sum: '<S35>/Sum22'
  //   Sum: '<S35>/Sum3'
  //   Sum: '<S35>/Sum4'
  //   Sum: '<S35>/Sum5'
  //   Sum: '<S35>/Sum6'
  //   Sum: '<S35>/Sum7'
  //   Sum: '<S35>/Sum8'
  //   Sum: '<S35>/Sum9'

  controller_2dof_pid_B.tth =
    ((((((((((((((((((controller_2dof_pid_DW.Delay_DSTATE[1] +
                      controller_2dof_pid_B.y) +
                     controller_2dof_pid_DW.Delay1_DSTATE_b[1]) +
                    controller_2dof_pid_DW.Delay2_DSTATE_f[1]) +
                   controller_2dof_pid_DW.Delay3_DSTATE_j[1]) +
                  controller_2dof_pid_DW.Delay4_DSTATE_e[1]) +
                 controller_2dof_pid_DW.Delay5_DSTATE[1]) +
                controller_2dof_pid_DW.Delay6_DSTATE[1]) +
               controller_2dof_pid_DW.Delay7_DSTATE[1]) +
              controller_2dof_pid_DW.Delay8_DSTATE[1]) +
             controller_2dof_pid_DW.Delay9_DSTATE[1]) +
            controller_2dof_pid_DW.Delay10_DSTATE[1]) +
           controller_2dof_pid_DW.Delay11_DSTATE[1]) +
          controller_2dof_pid_DW.Delay12_DSTATE[1]) +
         controller_2dof_pid_DW.Delay13_DSTATE[1]) +
        controller_2dof_pid_DW.Delay14_DSTATE[1]) +
       controller_2dof_pid_DW.Delay20_DSTATE[1]) +
      controller_2dof_pid_DW.Delay21_DSTATE[1]) +
     controller_2dof_pid_DW.Delay22_DSTATE[1]) +
    controller_2dof_pid_DW.Delay23_DSTATE[1];
  controller_2dof_pid_B.Sum23[1] = controller_2dof_pid_B.tth;

  // Sum: '<S35>/Sum24' incorporates:
  //   Sum: '<S35>/Sum23'

  controller_2dof_pid_B.Sum24[1] = controller_2dof_pid_B.tth;

  // MATLAB Function: '<S24>/RP_computation' incorporates:
  //   Gain: '<S35>/Gain'
  //   Sum: '<S35>/Sum23'
  //   Sum: '<S35>/Sum24'

  controller_2dof_pid_B.u_vect[1] = -(controller_2dof_pid_P.Gain_Gain_n *
    controller_2dof_pid_B.tth);

  // MATLAB Function: '<S31>/MATLAB Function'
  controller_2dof_pid_B.y = controller_2dof_pid_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(controller_2dof_pid_B.ph_meas + 2.0) - 1];

  // Sum: '<S35>/Sum23' incorporates:
  //   Delay: '<S35>/Delay'
  //   Delay: '<S35>/Delay1'
  //   Delay: '<S35>/Delay10'
  //   Delay: '<S35>/Delay11'
  //   Delay: '<S35>/Delay12'
  //   Delay: '<S35>/Delay13'
  //   Delay: '<S35>/Delay14'
  //   Delay: '<S35>/Delay2'
  //   Delay: '<S35>/Delay20'
  //   Delay: '<S35>/Delay21'
  //   Delay: '<S35>/Delay22'
  //   Delay: '<S35>/Delay23'
  //   Delay: '<S35>/Delay3'
  //   Delay: '<S35>/Delay4'
  //   Delay: '<S35>/Delay5'
  //   Delay: '<S35>/Delay6'
  //   Delay: '<S35>/Delay7'
  //   Delay: '<S35>/Delay8'
  //   Delay: '<S35>/Delay9'
  //   Sum: '<S35>/Sum'
  //   Sum: '<S35>/Sum1'
  //   Sum: '<S35>/Sum10'
  //   Sum: '<S35>/Sum11'
  //   Sum: '<S35>/Sum12'
  //   Sum: '<S35>/Sum13'
  //   Sum: '<S35>/Sum14'
  //   Sum: '<S35>/Sum2'
  //   Sum: '<S35>/Sum20'
  //   Sum: '<S35>/Sum21'
  //   Sum: '<S35>/Sum22'
  //   Sum: '<S35>/Sum3'
  //   Sum: '<S35>/Sum4'
  //   Sum: '<S35>/Sum5'
  //   Sum: '<S35>/Sum6'
  //   Sum: '<S35>/Sum7'
  //   Sum: '<S35>/Sum8'
  //   Sum: '<S35>/Sum9'

  controller_2dof_pid_B.tth =
    ((((((((((((((((((controller_2dof_pid_DW.Delay_DSTATE[2] +
                      controller_2dof_pid_B.y) +
                     controller_2dof_pid_DW.Delay1_DSTATE_b[2]) +
                    controller_2dof_pid_DW.Delay2_DSTATE_f[2]) +
                   controller_2dof_pid_DW.Delay3_DSTATE_j[2]) +
                  controller_2dof_pid_DW.Delay4_DSTATE_e[2]) +
                 controller_2dof_pid_DW.Delay5_DSTATE[2]) +
                controller_2dof_pid_DW.Delay6_DSTATE[2]) +
               controller_2dof_pid_DW.Delay7_DSTATE[2]) +
              controller_2dof_pid_DW.Delay8_DSTATE[2]) +
             controller_2dof_pid_DW.Delay9_DSTATE[2]) +
            controller_2dof_pid_DW.Delay10_DSTATE[2]) +
           controller_2dof_pid_DW.Delay11_DSTATE[2]) +
          controller_2dof_pid_DW.Delay12_DSTATE[2]) +
         controller_2dof_pid_DW.Delay13_DSTATE[2]) +
        controller_2dof_pid_DW.Delay14_DSTATE[2]) +
       controller_2dof_pid_DW.Delay20_DSTATE[2]) +
      controller_2dof_pid_DW.Delay21_DSTATE[2]) +
     controller_2dof_pid_DW.Delay22_DSTATE[2]) +
    controller_2dof_pid_DW.Delay23_DSTATE[2];
  controller_2dof_pid_B.Sum23[2] = controller_2dof_pid_B.tth;

  // Sum: '<S35>/Sum24' incorporates:
  //   Sum: '<S35>/Sum23'

  controller_2dof_pid_B.Sum24[2] = controller_2dof_pid_B.tth;

  // MATLAB Function: '<S24>/RP_computation' incorporates:
  //   Gain: '<S35>/Gain'
  //   Sum: '<S35>/Sum23'
  //   Sum: '<S35>/Sum24'

  controller_2dof_pid_B.u_vect[2] = -(controller_2dof_pid_P.Gain_Gain_n *
    controller_2dof_pid_B.tth);
  controller_2dof_pid_B.ph_meas = rt_atan2d_snf(controller_2dof_pid_B.u_vect[1],
    controller_2dof_pid_B.u_vect[2]);
  controller_2dof_pid_B.RP_meas[0] = controller_2dof_pid_B.ph_meas;
  controller_2dof_pid_B.RP_meas[1] = rt_atan2d_snf
    (-controller_2dof_pid_B.u_vect[0], controller_2dof_pid_B.u_vect[1] * sin
     (controller_2dof_pid_B.ph_meas) + controller_2dof_pid_B.u_vect[2] * cos
     (controller_2dof_pid_B.ph_meas));

  // MATLAB Function: '<S33>/EKF_RP' incorporates:
  //   Delay: '<S33>/Delay2'
  //   Memory: '<S33>/Memory2'
  //   Memory: '<S33>/Memory3'

  if (controller_2dof_pid_B.DigitalClock1 -
      controller_2dof_pid_DW.Memory2_PreviousInput >=
      controller_2dof_pid_P.Ts_EKF_meas) {
    controller_2dof_pid_DW.Memory2_PreviousInput =
      controller_2dof_pid_B.DigitalClock1;
    memcpy(&controller_2dof_pid_B.Pt1[0],
           &controller_2dof_pid_DW.Memory3_PreviousInput[0], 25U * sizeof(real_T));
    controller_2dof_pid_B.wq1 = controller_2dof_pid_DW.Delay2_DSTATE_l[1];
    controller_2dof_pid_B.wr1 = controller_2dof_pid_DW.Delay2_DSTATE_l[2];
    for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 < 5;
         controller_2dof_pid_B.r2++) {
      controller_2dof_pid_B.xt[controller_2dof_pid_B.r2] = 0.0;
    }

    memset(&controller_2dof_pid_B.Pt[0], 0, 25U * sizeof(real_T));
    controller_2dof_pid_B.b = static_cast<int32_T>(floor
      (controller_2dof_pid_P.Ts_EKF_meas / controller_2dof_pid_P.Ts_EKF_integr));
    for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 <
         controller_2dof_pid_B.b; controller_2dof_pid_B.r2++) {
      controller_2dof_pid_B.cph = cos
        (controller_2dof_pid_DW.Memory4_PreviousInput[0]);
      controller_2dof_pid_B.cth = cos
        (controller_2dof_pid_DW.Memory4_PreviousInput[1]);
      controller_2dof_pid_B.sph = sin
        (controller_2dof_pid_DW.Memory4_PreviousInput[0]);
      controller_2dof_pid_B.tth = sin
        (controller_2dof_pid_DW.Memory4_PreviousInput[1]) /
        controller_2dof_pid_B.cth;
      controller_2dof_pid_B.dv[0] = 1.0;
      controller_2dof_pid_B.temp_idx_0 = controller_2dof_pid_B.sph *
        controller_2dof_pid_B.tth;
      controller_2dof_pid_B.dv[5] = controller_2dof_pid_B.temp_idx_0;
      controller_2dof_pid_B.ps_meas_tmp_tmp = controller_2dof_pid_B.cph *
        controller_2dof_pid_B.tth;
      controller_2dof_pid_B.dv[10] = controller_2dof_pid_B.ps_meas_tmp_tmp;
      controller_2dof_pid_B.dv[15] = 0.0;
      controller_2dof_pid_B.dv[20] = 0.0;
      controller_2dof_pid_B.dv[25] = 0.0;
      controller_2dof_pid_B.dv[1] = 0.0;
      controller_2dof_pid_B.dv[6] = controller_2dof_pid_B.cph;
      controller_2dof_pid_B.dv[11] = -controller_2dof_pid_B.sph;
      controller_2dof_pid_B.dv[16] = 0.0;
      controller_2dof_pid_B.dv[21] = 0.0;
      controller_2dof_pid_B.dv[26] = 0.0;
      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 6;
           controller_2dof_pid_B.i++) {
        controller_2dof_pid_B.dv[5 * controller_2dof_pid_B.i + 2] = 0.0;
        controller_2dof_pid_B.dv[5 * controller_2dof_pid_B.i + 3] = 0.0;
        controller_2dof_pid_B.dv[5 * controller_2dof_pid_B.i + 4] = 0.0;
      }

      controller_2dof_pid_B.dv3[0] = controller_2dof_pid_DW.Delay2_DSTATE_l[0] -
        controller_2dof_pid_DW.Memory4_PreviousInput[2];
      controller_2dof_pid_B.cph_tmp = controller_2dof_pid_B.wq1 -
        controller_2dof_pid_DW.Memory4_PreviousInput[3];
      controller_2dof_pid_B.dv3[1] = controller_2dof_pid_B.cph_tmp;
      controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f =
        controller_2dof_pid_B.wr1 -
        controller_2dof_pid_DW.Memory4_PreviousInput[4];
      controller_2dof_pid_B.dv3[2] =
        controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f;
      controller_2dof_pid_B.dv3[3] =
        controller_2dof_pid_DW.Memory4_PreviousInput[2];
      controller_2dof_pid_B.dv3[4] =
        controller_2dof_pid_DW.Memory4_PreviousInput[3];
      controller_2dof_pid_B.dv3[5] =
        controller_2dof_pid_DW.Memory4_PreviousInput[4];
      controller_2dof_pid_B.Pt[0] = controller_2dof_pid_B.ps_meas_tmp_tmp *
        controller_2dof_pid_B.cph_tmp - controller_2dof_pid_B.temp_idx_0 *
        controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f;
      controller_2dof_pid_B.temp_idx_0 =
        controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f *
        controller_2dof_pid_B.cph;
      controller_2dof_pid_B.Pt[5] = (controller_2dof_pid_B.cph_tmp *
        controller_2dof_pid_B.sph + controller_2dof_pid_B.temp_idx_0) /
        (controller_2dof_pid_B.cth * controller_2dof_pid_B.cth);
      controller_2dof_pid_B.Pt[10] = -1.0;
      controller_2dof_pid_B.Pt[15] = -controller_2dof_pid_B.sph *
        controller_2dof_pid_B.tth;
      controller_2dof_pid_B.Pt[20] = -controller_2dof_pid_B.cph *
        controller_2dof_pid_B.tth;
      controller_2dof_pid_B.Pt[1] = controller_2dof_pid_B.cph_tmp *
        -controller_2dof_pid_B.sph - controller_2dof_pid_B.temp_idx_0;
      controller_2dof_pid_B.Pt[6] = 0.0;
      controller_2dof_pid_B.Pt[11] = 0.0;
      controller_2dof_pid_B.Pt[16] = -controller_2dof_pid_B.cph;
      controller_2dof_pid_B.Pt[21] = controller_2dof_pid_B.sph;
      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
           controller_2dof_pid_B.i++) {
        controller_2dof_pid_B.temp_idx_0 = 0.0;
        for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 6;
             controller_2dof_pid_B.r1++) {
          controller_2dof_pid_B.temp_idx_0 += controller_2dof_pid_B.dv[5 *
            controller_2dof_pid_B.r1 + controller_2dof_pid_B.i] *
            controller_2dof_pid_B.dv3[controller_2dof_pid_B.r1];
        }

        controller_2dof_pid_B.xt[controller_2dof_pid_B.i] =
          controller_2dof_pid_P.Ts_EKF_integr * controller_2dof_pid_B.temp_idx_0
          + controller_2dof_pid_DW.Memory4_PreviousInput[controller_2dof_pid_B.i];
        controller_2dof_pid_B.Pt[5 * controller_2dof_pid_B.i + 2] = 0.0;
        controller_2dof_pid_B.Pt[5 * controller_2dof_pid_B.i + 3] = 0.0;
        controller_2dof_pid_B.Pt[5 * controller_2dof_pid_B.i + 4] = 0.0;
      }

      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
           controller_2dof_pid_B.i++) {
        for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
             controller_2dof_pid_B.r1++) {
          controller_2dof_pid_B.tth = 0.0;
          controller_2dof_pid_B.temp_idx_0 = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            controller_2dof_pid_B.At1_tmp = 5 * Pt1_tmp +
              controller_2dof_pid_B.i;
            controller_2dof_pid_B.tth += controller_2dof_pid_B.Pt1[5 *
              controller_2dof_pid_B.r1 + Pt1_tmp] *
              controller_2dof_pid_B.Pt[controller_2dof_pid_B.At1_tmp];
            controller_2dof_pid_B.temp_idx_0 += controller_2dof_pid_B.Pt[5 *
              Pt1_tmp + controller_2dof_pid_B.r1] *
              controller_2dof_pid_B.Pt1[controller_2dof_pid_B.At1_tmp];
          }

          Pt1_tmp = 5 * controller_2dof_pid_B.r1 + controller_2dof_pid_B.i;
          controller_2dof_pid_B.Pt1_m[Pt1_tmp] =
            controller_2dof_pid_B.temp_idx_0;
          controller_2dof_pid_B.At1[Pt1_tmp] = controller_2dof_pid_B.tth;
        }
      }

      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 25;
           controller_2dof_pid_B.i++) {
        controller_2dof_pid_B.Pt[controller_2dof_pid_B.i] =
          ((controller_2dof_pid_B.At1[controller_2dof_pid_B.i] +
            controller_2dof_pid_B.Pt1_m[controller_2dof_pid_B.i]) +
           controller_2dof_pid_P.Q_phth[controller_2dof_pid_B.i]) *
          controller_2dof_pid_P.Ts_EKF_integr +
          controller_2dof_pid_B.Pt1[controller_2dof_pid_B.i];
      }

      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
           controller_2dof_pid_B.i++) {
        controller_2dof_pid_DW.Memory4_PreviousInput[controller_2dof_pid_B.i] =
          controller_2dof_pid_B.xt[controller_2dof_pid_B.i];
      }

      memcpy(&controller_2dof_pid_B.Pt1[0], &controller_2dof_pid_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 10;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_B.Lk[controller_2dof_pid_B.i] =
        c[controller_2dof_pid_B.i];
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 2;
         controller_2dof_pid_B.i++) {
      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
           controller_2dof_pid_B.r1++) {
        controller_2dof_pid_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_2dof_pid_B.tth += controller_2dof_pid_B.Pt[5 * Pt1_tmp +
            controller_2dof_pid_B.r1] * controller_2dof_pid_B.Lk[5 *
            controller_2dof_pid_B.i + Pt1_tmp];
        }

        controller_2dof_pid_B.B[controller_2dof_pid_B.r1 + 5 *
          controller_2dof_pid_B.i] = controller_2dof_pid_B.tth;
      }
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 10;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_B.A_tmp_c[controller_2dof_pid_B.i] =
        b_b[controller_2dof_pid_B.i];
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 2;
         controller_2dof_pid_B.i++) {
      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
           controller_2dof_pid_B.r1++) {
        controller_2dof_pid_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_2dof_pid_B.tth += static_cast<real_T>
            (controller_2dof_pid_B.A_tmp_c[(Pt1_tmp << 1) +
             controller_2dof_pid_B.i]) * controller_2dof_pid_B.Pt[5 *
            controller_2dof_pid_B.r1 + Pt1_tmp];
        }

        controller_2dof_pid_B.A_tmp[controller_2dof_pid_B.i +
          (controller_2dof_pid_B.r1 << 1)] = controller_2dof_pid_B.tth;
      }

      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 2;
           controller_2dof_pid_B.r1++) {
        controller_2dof_pid_B.temp_idx_0 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_2dof_pid_B.temp_idx_0 += controller_2dof_pid_B.A_tmp
            [(Pt1_tmp << 1) + controller_2dof_pid_B.i] *
            controller_2dof_pid_B.Lk[5 * controller_2dof_pid_B.r1 + Pt1_tmp];
        }

        controller_2dof_pid_B.r2 = (controller_2dof_pid_B.r1 << 1) +
          controller_2dof_pid_B.i;
        controller_2dof_pid_B.minval[controller_2dof_pid_B.r2] =
          controller_2dof_pid_P.R_phth[controller_2dof_pid_B.r2] +
          controller_2dof_pid_B.temp_idx_0;
      }
    }

    if (fabs(controller_2dof_pid_B.minval[1]) > fabs
        (controller_2dof_pid_B.minval[0])) {
      controller_2dof_pid_B.r1 = 1;
      controller_2dof_pid_B.r2 = 0;
    } else {
      controller_2dof_pid_B.r1 = 0;
      controller_2dof_pid_B.r2 = 1;
    }

    controller_2dof_pid_B.tth =
      controller_2dof_pid_B.minval[controller_2dof_pid_B.r2] /
      controller_2dof_pid_B.minval[controller_2dof_pid_B.r1];
    controller_2dof_pid_B.temp_idx_0 =
      controller_2dof_pid_B.minval[controller_2dof_pid_B.r1 + 2];
    controller_2dof_pid_B.wq1 =
      controller_2dof_pid_B.minval[controller_2dof_pid_B.r2 + 2] -
      controller_2dof_pid_B.temp_idx_0 * controller_2dof_pid_B.tth;
    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
         controller_2dof_pid_B.i++) {
      Pt1_tmp = 5 * controller_2dof_pid_B.r1 + controller_2dof_pid_B.i;
      controller_2dof_pid_B.Lk[Pt1_tmp] =
        controller_2dof_pid_B.B[controller_2dof_pid_B.i] /
        controller_2dof_pid_B.minval[controller_2dof_pid_B.r1];
      controller_2dof_pid_B.b = 5 * controller_2dof_pid_B.r2 +
        controller_2dof_pid_B.i;
      controller_2dof_pid_B.Lk[controller_2dof_pid_B.b] =
        (controller_2dof_pid_B.B[controller_2dof_pid_B.i + 5] -
         controller_2dof_pid_B.Lk[Pt1_tmp] * controller_2dof_pid_B.temp_idx_0) /
        controller_2dof_pid_B.wq1;
      controller_2dof_pid_B.Lk[Pt1_tmp] -=
        controller_2dof_pid_B.Lk[controller_2dof_pid_B.b] *
        controller_2dof_pid_B.tth;
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 2;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_B.temp_idx_0 = 0.0;
      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
           controller_2dof_pid_B.r1++) {
        controller_2dof_pid_B.temp_idx_0 += static_cast<real_T>
          (controller_2dof_pid_B.A_tmp_c[(controller_2dof_pid_B.r1 << 1) +
           controller_2dof_pid_B.i]) *
          controller_2dof_pid_B.xt[controller_2dof_pid_B.r1];
      }

      controller_2dof_pid_B.RP_meas_p[controller_2dof_pid_B.i] =
        controller_2dof_pid_B.RP_meas[controller_2dof_pid_B.i] -
        controller_2dof_pid_B.temp_idx_0;
    }

    controller_2dof_pid_B.tth = controller_2dof_pid_B.RP_meas_p[1];
    controller_2dof_pid_B.temp_idx_0 = controller_2dof_pid_B.RP_meas_p[0];
    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_DW.Memory4_PreviousInput[controller_2dof_pid_B.i] =
        (controller_2dof_pid_B.Lk[controller_2dof_pid_B.i + 5] *
         controller_2dof_pid_B.tth +
         controller_2dof_pid_B.Lk[controller_2dof_pid_B.i] *
         controller_2dof_pid_B.temp_idx_0) +
        controller_2dof_pid_B.xt[controller_2dof_pid_B.i];
    }

    memset(&controller_2dof_pid_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_B.Pt1[controller_2dof_pid_B.i + 5 *
        controller_2dof_pid_B.i] = 1.0;
    }

    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 5;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_B.temp_idx_0 =
        controller_2dof_pid_B.Lk[controller_2dof_pid_B.i + 5];
      controller_2dof_pid_B.tth =
        controller_2dof_pid_B.Lk[controller_2dof_pid_B.i];
      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
           controller_2dof_pid_B.r1++) {
        Pt1_tmp = controller_2dof_pid_B.r1 << 1;
        controller_2dof_pid_B.r2 = 5 * controller_2dof_pid_B.r1 +
          controller_2dof_pid_B.i;
        controller_2dof_pid_B.Pt1_m[controller_2dof_pid_B.r2] =
          controller_2dof_pid_B.Pt1[controller_2dof_pid_B.r2] -
          (static_cast<real_T>(controller_2dof_pid_B.A_tmp_c[Pt1_tmp + 1]) *
           controller_2dof_pid_B.temp_idx_0 + static_cast<real_T>
           (controller_2dof_pid_B.A_tmp_c[Pt1_tmp]) * controller_2dof_pid_B.tth);
      }

      for (controller_2dof_pid_B.r1 = 0; controller_2dof_pid_B.r1 < 5;
           controller_2dof_pid_B.r1++) {
        controller_2dof_pid_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_2dof_pid_B.tth += controller_2dof_pid_B.Pt1_m[5 * Pt1_tmp +
            controller_2dof_pid_B.i] * controller_2dof_pid_B.Pt[5 *
            controller_2dof_pid_B.r1 + Pt1_tmp];
        }

        controller_2dof_pid_DW.Memory3_PreviousInput[controller_2dof_pid_B.i + 5
          * controller_2dof_pid_B.r1] = controller_2dof_pid_B.tth;
      }
    }
  }

  // End of MATLAB Function: '<S33>/EKF_RP'

  // MATLAB Function: '<S24>/Y_computation' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion3'
  //   MATLAB Function: '<S24>/RPY_dot_computation'
  //   MATLAB Function: '<S33>/MATLAB Function'
  //   MATLAB Function: '<S36>/EKF_Y'

  controller_2dof_pid_B.sph = sin(controller_2dof_pid_DW.Memory4_PreviousInput[0]);
  controller_2dof_pid_B.cph_tmp = cos
    (controller_2dof_pid_DW.Memory4_PreviousInput[0]);
  controller_2dof_pid_B.tth = sin(controller_2dof_pid_DW.Memory4_PreviousInput[1]);
  controller_2dof_pid_B.ps_meas_tmp_tmp = cos
    (controller_2dof_pid_DW.Memory4_PreviousInput[1]);
  controller_2dof_pid_B.wq1 = rt_atan2d_snf(controller_2dof_pid_B.In1_k.z *
    controller_2dof_pid_B.sph - controller_2dof_pid_B.In1_k.y *
    controller_2dof_pid_B.cph_tmp, (controller_2dof_pid_B.In1_k.y *
    controller_2dof_pid_B.tth * controller_2dof_pid_B.sph +
    controller_2dof_pid_B.In1_k.x * controller_2dof_pid_B.ps_meas_tmp_tmp) +
    controller_2dof_pid_B.In1_k.z * controller_2dof_pid_B.tth *
    controller_2dof_pid_B.cph_tmp);
  if (controller_2dof_pid_B.wq1 < 0.0) {
    controller_2dof_pid_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S36>/EKF_Y' incorporates:
  //   Delay: '<S36>/Delay2'
  //   MATLAB Function: '<S24>/Y_computation'
  //   MATLAB Function: '<S33>/MATLAB Function'
  //   Memory: '<S36>/Memory2'

  if (controller_2dof_pid_B.DigitalClock1 -
      controller_2dof_pid_DW.Memory2_PreviousInput_f >=
      controller_2dof_pid_P.Ts_EKF_meas) {
    controller_2dof_pid_DW.Memory2_PreviousInput_f =
      controller_2dof_pid_B.DigitalClock1;
    controller_2dof_pid_B.wr1 = 0.0;
    controller_2dof_pid_B.cph = 0.0;
    controller_2dof_pid_B.b = static_cast<int32_T>(floor
      (controller_2dof_pid_P.Ts_EKF_meas / controller_2dof_pid_P.Ts_EKF_integr));
    if (controller_2dof_pid_B.b - 1 >= 0) {
      controller_2dof_pid_B.dv4[0] = 0.0;
      controller_2dof_pid_B.dv4[1] = controller_2dof_pid_B.sph /
        controller_2dof_pid_B.ps_meas_tmp_tmp;
      controller_2dof_pid_B.dv4[2] = controller_2dof_pid_B.cph_tmp /
        controller_2dof_pid_B.ps_meas_tmp_tmp;
      controller_2dof_pid_B.dv4[3] = 0.0;
      controller_2dof_pid_B.dv4[4] = 0.0;
      controller_2dof_pid_B.dv4[5] = 0.0;
      controller_2dof_pid_B.dv5[0] = controller_2dof_pid_DW.Delay2_DSTATE_fv[0]
        - controller_2dof_pid_DW.Memory4_PreviousInput[2];
      controller_2dof_pid_B.dv5[1] = controller_2dof_pid_DW.Delay2_DSTATE_fv[1]
        - controller_2dof_pid_DW.Memory4_PreviousInput[3];
      controller_2dof_pid_B.dv5[2] = controller_2dof_pid_DW.Delay2_DSTATE_fv[2]
        - controller_2dof_pid_DW.Memory4_PreviousInput[4];
      controller_2dof_pid_B.dv5[3] =
        controller_2dof_pid_DW.Memory4_PreviousInput[2];
      controller_2dof_pid_B.dv5[4] =
        controller_2dof_pid_DW.Memory4_PreviousInput[3];
      controller_2dof_pid_B.dv5[5] =
        controller_2dof_pid_DW.Memory4_PreviousInput[4];
    }

    for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 <
         controller_2dof_pid_B.b; controller_2dof_pid_B.r2++) {
      controller_2dof_pid_B.temp_idx_0 = 0.0;
      for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 6;
           controller_2dof_pid_B.i++) {
        controller_2dof_pid_B.temp_idx_0 +=
          controller_2dof_pid_B.dv4[controller_2dof_pid_B.i] *
          controller_2dof_pid_B.dv5[controller_2dof_pid_B.i];
      }

      controller_2dof_pid_B.wr1 = controller_2dof_pid_P.Ts_EKF_integr *
        controller_2dof_pid_B.temp_idx_0 +
        controller_2dof_pid_DW.Memory4_PreviousInput_d;
      controller_2dof_pid_B.cph = ((0.0 *
        controller_2dof_pid_DW.Memory3_PreviousInput_g +
        controller_2dof_pid_DW.Memory3_PreviousInput_g * 0.0) +
        controller_2dof_pid_P.q_ps) * controller_2dof_pid_P.Ts_EKF_integr +
        controller_2dof_pid_DW.Memory3_PreviousInput_g;
      controller_2dof_pid_DW.Memory4_PreviousInput_d = controller_2dof_pid_B.wr1;
      controller_2dof_pid_DW.Memory3_PreviousInput_g = controller_2dof_pid_B.cph;
    }

    controller_2dof_pid_B.temp_idx_0 = controller_2dof_pid_B.cph /
      (controller_2dof_pid_B.cph + controller_2dof_pid_P.r_ps);
    controller_2dof_pid_DW.Memory4_PreviousInput_d = (controller_2dof_pid_B.wq1
      - controller_2dof_pid_B.wr1) * controller_2dof_pid_B.temp_idx_0 +
      controller_2dof_pid_B.wr1;
    controller_2dof_pid_DW.Memory3_PreviousInput_g = (1.0 -
      controller_2dof_pid_B.temp_idx_0) * controller_2dof_pid_B.cph;
  }

  // DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn'
  controller_2dof_pid_B.wr1 =
    controller_2dof_pid_P.DiscreteTransferFcn_NumCoef_h *
    controller_2dof_pid_DW.DiscreteTransferFcn_states_i;

  // DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn1'
  controller_2dof_pid_B.cph =
    controller_2dof_pid_P.DiscreteTransferFcn1_NumCoef_k *
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_p;

  // DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn2'
  controller_2dof_pid_B.cth =
    controller_2dof_pid_P.DiscreteTransferFcn2_NumCoef_b *
    controller_2dof_pid_DW.DiscreteTransferFcn2_states_o;

  // MATLAB Function: '<S24>/RPY_dot_computation' incorporates:
  //   Constant: '<S24>/Constant6'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S24>/Y_computation'
  //   MATLAB Function: '<S33>/MATLAB Function'
  //   Memory: '<S24>/Memory5'

  if ((controller_2dof_pid_B.DigitalClock1 -
       controller_2dof_pid_DW.Memory5_PreviousInput >=
       controller_2dof_pid_P.Ts_EKF_meas) ||
      (controller_2dof_pid_B.DigitalClock1 == 0.0)) {
    controller_2dof_pid_B.tth /= controller_2dof_pid_B.ps_meas_tmp_tmp;
    controller_2dof_pid_DW.Memory5_PreviousInput =
      controller_2dof_pid_B.DigitalClock1;
    controller_2dof_pid_B.dv2[0] = 1.0;
    controller_2dof_pid_B.dv2[3] = controller_2dof_pid_B.sph *
      controller_2dof_pid_B.tth;
    controller_2dof_pid_B.dv2[6] = controller_2dof_pid_B.cph_tmp *
      controller_2dof_pid_B.tth;
    controller_2dof_pid_B.dv2[1] = 0.0;
    controller_2dof_pid_B.dv2[4] = controller_2dof_pid_B.cph_tmp;
    controller_2dof_pid_B.dv2[7] = -controller_2dof_pid_B.sph;
    controller_2dof_pid_B.dv2[2] = 0.0;
    controller_2dof_pid_B.dv2[5] = controller_2dof_pid_B.sph /
      controller_2dof_pid_B.ps_meas_tmp_tmp;
    controller_2dof_pid_B.dv2[8] = controller_2dof_pid_B.cph_tmp /
      controller_2dof_pid_B.ps_meas_tmp_tmp;
    controller_2dof_pid_B.tth = controller_2dof_pid_B.wr1 -
      controller_2dof_pid_DW.Memory4_PreviousInput[2] * 0.0;
    controller_2dof_pid_B.temp_idx_0 = controller_2dof_pid_B.cph -
      controller_2dof_pid_DW.Memory4_PreviousInput[3] * 0.0;
    controller_2dof_pid_B.sph = controller_2dof_pid_B.cth -
      controller_2dof_pid_DW.Memory4_PreviousInput[4] * 0.0;
    for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 3;
         controller_2dof_pid_B.i++) {
      controller_2dof_pid_DW.Memory6_PreviousInput[controller_2dof_pid_B.i] =
        (controller_2dof_pid_B.dv2[controller_2dof_pid_B.i + 3] *
         controller_2dof_pid_B.temp_idx_0 +
         controller_2dof_pid_B.dv2[controller_2dof_pid_B.i] *
         controller_2dof_pid_B.tth) +
        controller_2dof_pid_B.dv2[controller_2dof_pid_B.i + 6] *
        controller_2dof_pid_B.sph;
    }
  }

  // Step: '<Root>/RP ref'
  b_varargout_1 = (controller_2dof_pid_B.DigitalClock1 <
                   controller_2dof_pid_P.RPref_Time);
  if (b_varargout_1) {
    // Step: '<Root>/RP ref'
    controller_2dof_pid_B.tth = controller_2dof_pid_P.RPref_Y0;
  } else {
    // Step: '<Root>/RP ref'
    controller_2dof_pid_B.tth = controller_2dof_pid_P.RPref_YFinal[0];
  }

  controller_2dof_pid_B.temp_idx_0 = controller_2dof_pid_B.tth;

  // SignalConversion generated from: '<S48>/ SFunction ' incorporates:
  //   MATLAB Function: '<S45>/MATLAB Function1'

  controller_2dof_pid_B.u_vect[0] = controller_2dof_pid_B.tth;

  // Step: '<Root>/RP ref'
  if (b_varargout_1) {
    // Step: '<Root>/RP ref'
    controller_2dof_pid_B.tth = controller_2dof_pid_P.RPref_Y0;
  } else {
    // Step: '<Root>/RP ref'
    controller_2dof_pid_B.tth = controller_2dof_pid_P.RPref_YFinal[1];
  }

  // ManualSwitch: '<Root>/Manual Switch2'
  if (controller_2dof_pid_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 < 28;
         controller_2dof_pid_B.r2++) {
      controller_2dof_pid_B.ManualSwitch2[controller_2dof_pid_B.r2] =
        controller_2dof_pid_P.Constant6_Value_g;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/yaw_ref'
    //   DataTypeConversion: '<S5>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion2'
    //   DataTypeConversion: '<S5>/Data Type Conversion3'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   MATLAB Function: '<S33>/MATLAB Function'
    //   MATLAB Function: '<S36>/EKF_Y'
    //   MATLAB Function: '<S45>/MATLAB Function'
    //   MATLAB Function: '<S45>/MATLAB Function1'
    //   SignalConversion generated from: '<S47>/ SFunction '
    //   SignalConversion generated from: '<S48>/ SFunction '

    controller_2dof_pid_B.ManualSwitch2[0] = rtb_DataTypeConversion1_ds;
    controller_2dof_pid_B.ManualSwitch2[1] = rtb_DataTypeConversion1_f;
    controller_2dof_pid_B.ManualSwitch2[2] = rtb_DataTypeConversion1_e;
    controller_2dof_pid_B.ManualSwitch2[3] = rtb_DataTypeConversion1_g;
    controller_2dof_pid_B.ManualSwitch2[4] = controller_2dof_pid_B.In1_dn.x;
    controller_2dof_pid_B.ManualSwitch2[5] = controller_2dof_pid_B.In1_dn.y;
    controller_2dof_pid_B.ManualSwitch2[6] = controller_2dof_pid_B.In1_dn.z;
    controller_2dof_pid_B.ManualSwitch2[7] = controller_2dof_pid_B.In1_d.x;
    controller_2dof_pid_B.ManualSwitch2[8] = controller_2dof_pid_B.In1_d.y;
    controller_2dof_pid_B.ManualSwitch2[9] = controller_2dof_pid_B.In1_d.z;
    controller_2dof_pid_B.ManualSwitch2[10] =
      controller_2dof_pid_B.In1.rollspeed;
    controller_2dof_pid_B.ManualSwitch2[11] =
      controller_2dof_pid_B.In1.pitchspeed;
    controller_2dof_pid_B.ManualSwitch2[12] = controller_2dof_pid_B.In1.yawspeed;
    controller_2dof_pid_B.ManualSwitch2[13] = controller_2dof_pid_B.y_f[0];
    controller_2dof_pid_B.ManualSwitch2[14] = controller_2dof_pid_B.y_f[1];
    controller_2dof_pid_B.ManualSwitch2[15] = controller_2dof_pid_B.y_f[2];
    controller_2dof_pid_B.ManualSwitch2[16] = controller_2dof_pid_B.In1_k.x;
    controller_2dof_pid_B.ManualSwitch2[17] = controller_2dof_pid_B.In1_k.y;
    controller_2dof_pid_B.ManualSwitch2[18] = controller_2dof_pid_B.In1_k.z;
    controller_2dof_pid_B.ManualSwitch2[19] =
      controller_2dof_pid_DW.Memory4_PreviousInput[0];
    controller_2dof_pid_B.ManualSwitch2[20] =
      controller_2dof_pid_DW.Memory4_PreviousInput[1];
    controller_2dof_pid_B.ManualSwitch2[21] =
      controller_2dof_pid_DW.Memory4_PreviousInput_d;
    controller_2dof_pid_B.ManualSwitch2[22] =
      controller_2dof_pid_DW.Memory6_PreviousInput[0];
    controller_2dof_pid_B.ManualSwitch2[23] =
      controller_2dof_pid_DW.Memory6_PreviousInput[1];
    controller_2dof_pid_B.ManualSwitch2[24] =
      controller_2dof_pid_DW.Memory6_PreviousInput[2];
    controller_2dof_pid_B.ManualSwitch2[25] = controller_2dof_pid_B.u_vect[0];
    controller_2dof_pid_B.ManualSwitch2[26] = controller_2dof_pid_B.tth;
    controller_2dof_pid_B.ManualSwitch2[27] =
      controller_2dof_pid_P.yaw_ref_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  controller_2dof_pid_B.TmpSignalConversionAt_asyncqueu[0] =
    controller_2dof_pid_B.DigitalClock1;
  memcpy(&controller_2dof_pid_B.TmpSignalConversionAt_asyncqueu[1],
         &controller_2dof_pid_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S25>/Gain2' incorporates:
  //   MATLAB Function: '<S25>/MATLAB Function2'
  //   MATLAB Function: '<S36>/EKF_Y'
  //   SignalConversion generated from: '<S43>/ SFunction '

  controller_2dof_pid_B.Gain2[2] = controller_2dof_pid_P.Gain2_Gain *
    controller_2dof_pid_DW.Memory4_PreviousInput_d;

  // SignalConversion generated from: '<S33>/Delay2' incorporates:
  //   Delay: '<S36>/Delay2'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn2'

  controller_2dof_pid_DW.Delay2_DSTATE_fv[0] = controller_2dof_pid_B.wr1;
  controller_2dof_pid_DW.Delay2_DSTATE_fv[1] = controller_2dof_pid_B.cph;
  controller_2dof_pid_DW.Delay2_DSTATE_fv[2] = controller_2dof_pid_B.cth;

  // Gain: '<S25>/Gain2' incorporates:
  //   MATLAB Function: '<S33>/MATLAB Function'

  controller_2dof_pid_B.Gain2[0] = controller_2dof_pid_P.Gain2_Gain *
    controller_2dof_pid_DW.Memory4_PreviousInput[0];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S24>/RP_computation'

  controller_2dof_pid_B.Gain_e[0] = controller_2dof_pid_P.Gain_Gain_d *
    controller_2dof_pid_B.ph_meas;

  // Gain: '<S25>/Gain2' incorporates:
  //   MATLAB Function: '<S33>/MATLAB Function'

  controller_2dof_pid_B.Gain2[1] = controller_2dof_pid_P.Gain2_Gain *
    controller_2dof_pid_DW.Memory4_PreviousInput[1];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S24>/Y_computation'

  controller_2dof_pid_B.Gain_e[1] = controller_2dof_pid_P.Gain_Gain_d *
    controller_2dof_pid_B.RP_meas[1];
  controller_2dof_pid_B.Gain_e[2] = controller_2dof_pid_P.Gain_Gain_d *
    controller_2dof_pid_B.wq1;

  // MATLAB Function: '<S22>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion2'

  controller_2dof_pid_B.y_c[0] = controller_2dof_pid_B.In1_d.x;
  controller_2dof_pid_B.y_c[1] = -static_cast<real_T>
    (controller_2dof_pid_B.In1_d.y);
  controller_2dof_pid_B.y_c[2] = -static_cast<real_T>
    (controller_2dof_pid_B.In1_d.z);

  // MATLAB Function: '<S22>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion1'

  controller_2dof_pid_B.y_i[0] = -static_cast<real_T>
    (controller_2dof_pid_B.In1_dn.x);
  controller_2dof_pid_B.y_i[1] = controller_2dof_pid_B.In1_dn.y;
  controller_2dof_pid_B.y_i[2] = controller_2dof_pid_B.In1_dn.z;

  // Gain: '<S22>/Gain1'
  controller_2dof_pid_B.wq1 = controller_2dof_pid_B.y_c[0];
  controller_2dof_pid_B.wr1 = controller_2dof_pid_B.y_c[1];
  controller_2dof_pid_B.cph = controller_2dof_pid_B.y_c[2];

  // Gain: '<S22>/Gain'
  controller_2dof_pid_B.cth = controller_2dof_pid_B.y_i[0];
  controller_2dof_pid_B.sph = controller_2dof_pid_B.y_i[1];
  controller_2dof_pid_B.cph_tmp = controller_2dof_pid_B.y_i[2];
  for (controller_2dof_pid_B.r2 = 0; controller_2dof_pid_B.r2 < 3;
       controller_2dof_pid_B.r2++) {
    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.ps_meas_tmp_tmp =
      controller_2dof_pid_P.Rz[controller_2dof_pid_B.r2];

    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.ph_meas = controller_2dof_pid_B.ps_meas_tmp_tmp *
      controller_2dof_pid_B.wq1;

    // Gain: '<S22>/Gain'
    controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f =
      controller_2dof_pid_B.ps_meas_tmp_tmp * controller_2dof_pid_B.cth;

    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.ps_meas_tmp_tmp =
      controller_2dof_pid_P.Rz[controller_2dof_pid_B.r2 + 3];

    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.ph_meas += controller_2dof_pid_B.ps_meas_tmp_tmp *
      controller_2dof_pid_B.wr1;

    // Gain: '<S22>/Gain'
    controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f +=
      controller_2dof_pid_B.ps_meas_tmp_tmp * controller_2dof_pid_B.sph;

    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.ps_meas_tmp_tmp =
      controller_2dof_pid_P.Rz[controller_2dof_pid_B.r2 + 6];

    // Gain: '<S22>/Gain'
    controller_2dof_pid_B.TmpSignalConversionAtSFunct[controller_2dof_pid_B.r2] =
      controller_2dof_pid_B.ps_meas_tmp_tmp * controller_2dof_pid_B.cph_tmp +
      controller_2dof_pid_B.rtb_TmpSignalConversionAtSFun_f;

    // Gain: '<S22>/Gain1'
    controller_2dof_pid_B.u_vect[controller_2dof_pid_B.r2] =
      controller_2dof_pid_B.ps_meas_tmp_tmp * controller_2dof_pid_B.cph +
      controller_2dof_pid_B.ph_meas;

    // Gain: '<Root>/Gain1'
    controller_2dof_pid_B.Gain1_g[controller_2dof_pid_B.r2] =
      controller_2dof_pid_P.Gain1_Gain_n *
      controller_2dof_pid_B.y_f[controller_2dof_pid_B.r2];
  }

  // MATLAB Function: '<S25>/MATLAB Function7'
  controller_2d_MATLABFunction1_m(controller_2dof_pid_B.Gain2,
    &controller_2dof_pid_B.y1_k, &controller_2dof_pid_B.y2_b,
    &controller_2dof_pid_B.y3_j, &controller_2dof_pid_DW.sf_MATLABFunction7);

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  controller_2dof_pid_B.y1_p = controller_2dof_pid_B.Gain1_g[0];
  controller_2dof_pid_B.y2_ew = controller_2dof_pid_B.Gain1_g[1];
  controller_2dof_pid_B.y3_o = controller_2dof_pid_B.Gain1_g[2];

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant7'
  //   Constant: '<Root>/Constant8'
  //   Gain: '<Root>/Gain'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum2'
  //   Sum: '<Root>/Sum3'
  //   Sum: '<Root>/Sum4'

  if (controller_2dof_pid_P.ManualSwitch_CurrentSetting == 1) {
    controller_2dof_pid_B.RP_meas[0] = controller_2dof_pid_B.y1_k +
      controller_2dof_pid_P.Constant5_Value;
    controller_2dof_pid_B.RP_meas[1] = controller_2dof_pid_B.y2_b +
      controller_2dof_pid_P.Constant7_Value;
  } else {
    controller_2dof_pid_B.RP_meas[0] = controller_2dof_pid_B.y1_p +
      controller_2dof_pid_P.Constant_Value_be;
    controller_2dof_pid_B.RP_meas[1] = (controller_2dof_pid_B.y2_ew +
      controller_2dof_pid_P.Constant8_Value) * controller_2dof_pid_P.Gain_Gain;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Gain: '<Root>/Gain2'
  controller_2dof_pid_B.RP_meas[0] *= controller_2dof_pid_P.Gain2_Gain_b;
  controller_2dof_pid_B.RP_meas[1] *= controller_2dof_pid_P.Gain2_Gain_b;

  // Sum: '<S1>/Sum1' incorporates:
  //   DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1'

  controller_2dof_pid_B.Sum1_d =
    controller_2dof_pid_P.DiscreteTransferFcn1_NumCoef_h *
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_c -
    controller_2dof_pid_B.RP_meas[1];

  // Sum: '<S1>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1'

  controller_2dof_pid_B.Sum2_b =
    controller_2dof_pid_P.DiscreteTransferFcn1_NumCoef_g *
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_m -
    controller_2dof_pid_B.RP_meas[0];

  // MATLAB Function: '<S4>/MATLAB Function1'
  controller_2d_MATLABFunction1_m(controller_2dof_pid_B.Gain_e,
    &controller_2dof_pid_B.y1_l, &controller_2dof_pid_B.y2_k,
    &controller_2dof_pid_B.y3_a, &controller_2dof_pid_DW.sf_MATLABFunction1_m);

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/failsafe'

  for (controller_2dof_pid_B.i = 0; controller_2dof_pid_B.i < 8;
       controller_2dof_pid_B.i++) {
    controller_2dof_pid_B.pwmValue[controller_2dof_pid_B.i] = 0U;
  }

  controller_2dof_pid_B.pwmValue[0] = rtb_DataTypeConversion1_ds;
  controller_2dof_pid_B.pwmValue[1] = rtb_DataTypeConversion1_f;
  controller_2dof_pid_B.pwmValue[2] = rtb_DataTypeConversion1_e;
  controller_2dof_pid_B.pwmValue[3] = rtb_DataTypeConversion1_g;
  if (rtb_ManualSwitch1) {
    if (!controller_2dof_pid_DW.obj.isArmed) {
      controller_2dof_pid_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_ds = pwm_arm
        (&controller_2dof_pid_DW.obj.pwmDevHandler,
         &controller_2dof_pid_DW.obj.armAdvertiseObj);
      controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_2dof_pid_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
    }

    rtb_DataTypeConversion1_ds = pwm_setServo
      (&controller_2dof_pid_DW.obj.pwmDevHandler,
       controller_2dof_pid_DW.obj.servoCount,
       controller_2dof_pid_DW.obj.channelMask, &controller_2dof_pid_B.pwmValue[0],
       controller_2dof_pid_DW.obj.isMain,
       &controller_2dof_pid_DW.obj.actuatorAdvertiseObj);
    controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_2dof_pid_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  } else {
    rtb_DataTypeConversion1_ds = pwm_disarm
      (&controller_2dof_pid_DW.obj.pwmDevHandler,
       &controller_2dof_pid_DW.obj.armAdvertiseObj);
    controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_2dof_pid_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
    controller_2dof_pid_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_ds = pwm_resetServo
      (&controller_2dof_pid_DW.obj.pwmDevHandler,
       controller_2dof_pid_DW.obj.servoCount,
       controller_2dof_pid_DW.obj.channelMask, controller_2dof_pid_DW.obj.isMain,
       &controller_2dof_pid_DW.obj.actuatorAdvertiseObj);
    controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_2dof_pid_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  }

  if (controller_2dof_pid_DW.obj.isMain) {
    rtb_DataTypeConversion1_ds = pwm_forceFailsafe
      (&controller_2dof_pid_DW.obj.pwmDevHandler, static_cast<int32_T>
       (controller_2dof_pid_P.failsafe_Value));
    controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_2dof_pid_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(controller_2dof_pid_DW.obj_h.orbMetadataObj,
    &controller_2dof_pid_DW.obj_h.eventStructObj,
    &controller_2dof_pid_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S53>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S53>/In1'
    controller_2dof_pid_B.In1_h = controller_2dof_pid_B.b_varargout_2_c;
    srUpdateBC(controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_kv);
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  controller_2dof_pid_B.SignalConversion[0] =
    controller_2dof_pid_B.In1_h.output[0];
  controller_2dof_pid_B.SignalConversion[1] =
    controller_2dof_pid_B.In1_h.output[1];
  controller_2dof_pid_B.SignalConversion[2] =
    controller_2dof_pid_B.In1_h.output[2];
  controller_2dof_pid_B.SignalConversion[3] =
    controller_2dof_pid_B.In1_h.output[3];

  // Update for Delay: '<S1>/Delay3'
  controller_2dof_pid_DW.Delay3_DSTATE = controller_2dof_pid_B.u_sat_o;

  // Update for DiscreteStateSpace: '<S11>/Internal'
  {
    controller_2dof_pid_DW.Internal_DSTATE = controller_2dof_pid_B.Sum2_b +
      controller_2dof_pid_P.Internal_A*controller_2dof_pid_DW.Internal_DSTATE;
  }

  // Update for Delay: '<S1>/Delay2'
  controller_2dof_pid_DW.Delay2_DSTATE[0] = controller_2dof_pid_B.x_d[0];
  controller_2dof_pid_DW.Delay2_DSTATE[1] = controller_2dof_pid_B.x_d[1];

  // Update for Delay: '<S1>/Delay4'
  controller_2dof_pid_DW.Delay4_DSTATE = controller_2dof_pid_B.u_sat;

  // Update for DiscreteStateSpace: '<S12>/Internal'
  {
    controller_2dof_pid_DW.Internal_DSTATE_f = controller_2dof_pid_B.Sum1_d +
      controller_2dof_pid_P.Internal_A_i*
      controller_2dof_pid_DW.Internal_DSTATE_f;
  }

  // Update for Delay: '<S1>/Delay1'
  controller_2dof_pid_DW.Delay1_DSTATE[0] = controller_2dof_pid_B.x[0];
  controller_2dof_pid_DW.Delay1_DSTATE[1] = controller_2dof_pid_B.x[1];

  // Update for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn'

  controller_2dof_pid_DW.DiscreteTransferFcn_states =
    (controller_2dof_pid_P.DiscreteTransferFcn_NumCoef_o *
     controller_2dof_pid_DW.DiscreteTransferFcn_states_p -
     controller_2dof_pid_P.DiscreteTransferFcn_DenCoef[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn_states) /
    controller_2dof_pid_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn1'

  controller_2dof_pid_DW.DiscreteTransferFcn1_states =
    (controller_2dof_pid_P.DiscreteTransferFcn1_NumCoef_c *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states_l -
     controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states) /
    controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn2'

  controller_2dof_pid_DW.DiscreteTransferFcn2_states =
    (controller_2dof_pid_P.DiscreteTransferFcn2_NumCoef_l *
     controller_2dof_pid_DW.DiscreteTransferFcn2_states_g -
     controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn2_states) /
    controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S31>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn2'

  controller_2dof_pid_DW.Delay_DSTATE_e[0] = controller_2dof_pid_B.y_g;
  controller_2dof_pid_DW.Delay_DSTATE_e[1] = controller_2dof_pid_B.y_g1;
  controller_2dof_pid_DW.Delay_DSTATE_e[2] = controller_2dof_pid_B.y_m;

  // Update for Delay: '<S35>/Delay23' incorporates:
  //   Delay: '<S35>/Delay22'
  //
  controller_2dof_pid_DW.Delay23_DSTATE[0] =
    controller_2dof_pid_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S35>/Delay22' incorporates:
  //   Delay: '<S35>/Delay21'
  //
  controller_2dof_pid_DW.Delay22_DSTATE[0] =
    controller_2dof_pid_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S35>/Delay21' incorporates:
  //   Delay: '<S35>/Delay20'
  //
  controller_2dof_pid_DW.Delay21_DSTATE[0] =
    controller_2dof_pid_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S35>/Delay20' incorporates:
  //   Delay: '<S35>/Delay14'
  //
  controller_2dof_pid_DW.Delay20_DSTATE[0] =
    controller_2dof_pid_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S35>/Delay14' incorporates:
  //   Delay: '<S35>/Delay13'
  //
  controller_2dof_pid_DW.Delay14_DSTATE[0] =
    controller_2dof_pid_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S35>/Delay13' incorporates:
  //   Delay: '<S35>/Delay12'
  //
  controller_2dof_pid_DW.Delay13_DSTATE[0] =
    controller_2dof_pid_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S35>/Delay12' incorporates:
  //   Delay: '<S35>/Delay11'
  //
  controller_2dof_pid_DW.Delay12_DSTATE[0] =
    controller_2dof_pid_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S35>/Delay11' incorporates:
  //   Delay: '<S35>/Delay10'
  //
  controller_2dof_pid_DW.Delay11_DSTATE[0] =
    controller_2dof_pid_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S35>/Delay10' incorporates:
  //   Delay: '<S35>/Delay9'
  //
  controller_2dof_pid_DW.Delay10_DSTATE[0] =
    controller_2dof_pid_DW.Delay9_DSTATE[0];

  // Update for Delay: '<S35>/Delay9' incorporates:
  //   Delay: '<S35>/Delay8'
  //
  controller_2dof_pid_DW.Delay9_DSTATE[0] =
    controller_2dof_pid_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S35>/Delay8' incorporates:
  //   Delay: '<S35>/Delay7'
  //
  controller_2dof_pid_DW.Delay8_DSTATE[0] =
    controller_2dof_pid_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S35>/Delay7' incorporates:
  //   Delay: '<S35>/Delay6'
  //
  controller_2dof_pid_DW.Delay7_DSTATE[0] =
    controller_2dof_pid_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S35>/Delay6' incorporates:
  //   Delay: '<S35>/Delay5'
  //
  controller_2dof_pid_DW.Delay6_DSTATE[0] =
    controller_2dof_pid_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S35>/Delay5' incorporates:
  //   Delay: '<S35>/Delay4'
  //
  controller_2dof_pid_DW.Delay5_DSTATE[0] =
    controller_2dof_pid_DW.Delay4_DSTATE_e[0];

  // Update for Delay: '<S35>/Delay4' incorporates:
  //   Delay: '<S35>/Delay3'
  //
  controller_2dof_pid_DW.Delay4_DSTATE_e[0] =
    controller_2dof_pid_DW.Delay3_DSTATE_j[0];

  // Update for Delay: '<S35>/Delay3' incorporates:
  //   Delay: '<S35>/Delay2'
  //
  controller_2dof_pid_DW.Delay3_DSTATE_j[0] =
    controller_2dof_pid_DW.Delay2_DSTATE_f[0];

  // Update for Delay: '<S35>/Delay2' incorporates:
  //   Delay: '<S35>/Delay1'
  //
  controller_2dof_pid_DW.Delay2_DSTATE_f[0] =
    controller_2dof_pid_DW.Delay1_DSTATE_b[0];

  // Update for Delay: '<S35>/Delay1' incorporates:
  //   Delay: '<S35>/Delay'
  //
  controller_2dof_pid_DW.Delay1_DSTATE_b[0] =
    controller_2dof_pid_DW.Delay_DSTATE[0];

  // Update for Delay: '<S35>/Delay'
  controller_2dof_pid_DW.Delay_DSTATE[0] = controller_2dof_pid_B.y_idx_0;

  // Update for Delay: '<S31>/Delay1'
  controller_2dof_pid_DW.Delay1_DSTATE_m[0] =
    controller_2dof_pid_B.rtb_Delay_i_idx_0;

  // Update for Delay: '<S31>/Delay2'
  controller_2dof_pid_DW.Delay2_DSTATE_k[0] =
    controller_2dof_pid_B.rtb_Delay1_g_idx_0;

  // Update for Delay: '<S31>/Delay3'
  controller_2dof_pid_DW.Delay3_DSTATE_c[0] =
    controller_2dof_pid_B.rtb_Delay2_g_idx_0;

  // Update for Delay: '<S31>/Delay4'
  controller_2dof_pid_DW.Delay4_DSTATE_j[0] =
    controller_2dof_pid_B.rtb_Delay3_f_idx_0;

  // Update for Delay: '<S31>/Delay5'
  controller_2dof_pid_DW.Delay5_DSTATE_e[0] =
    controller_2dof_pid_B.rtb_Delay4_p_idx_0;

  // Update for Delay: '<S31>/Delay6'
  controller_2dof_pid_DW.Delay6_DSTATE_j[0] =
    controller_2dof_pid_B.rtb_Delay5_l_idx_0;

  // Update for Delay: '<S31>/Delay7'
  controller_2dof_pid_DW.Delay7_DSTATE_l[0] =
    controller_2dof_pid_B.rtb_Delay6_g_idx_0;

  // Update for Delay: '<S31>/Delay8'
  controller_2dof_pid_DW.Delay8_DSTATE_m[0] =
    controller_2dof_pid_B.rtb_Delay7_l_idx_0;

  // Update for Delay: '<S31>/Delay9'
  controller_2dof_pid_DW.Delay9_DSTATE_e[0] =
    controller_2dof_pid_B.rtb_Delay8_e_idx_0;

  // Update for Delay: '<S31>/Delay10'
  controller_2dof_pid_DW.Delay10_DSTATE_a[0] =
    controller_2dof_pid_B.rtb_Delay9_c_idx_0;

  // Update for Delay: '<S31>/Delay11'
  controller_2dof_pid_DW.Delay11_DSTATE_m[0] =
    controller_2dof_pid_B.rtb_Delay10_g_idx_0;

  // Update for Delay: '<S31>/Delay12'
  controller_2dof_pid_DW.Delay12_DSTATE_h[0] =
    controller_2dof_pid_B.rtb_Delay11_g_idx_0;

  // Update for Delay: '<S31>/Delay13'
  controller_2dof_pid_DW.Delay13_DSTATE_b[0] =
    controller_2dof_pid_B.rtb_Delay12_k_idx_0;

  // Update for Delay: '<S31>/Delay14'
  controller_2dof_pid_DW.Delay14_DSTATE_k[0] =
    controller_2dof_pid_B.rtb_Delay13_o_idx_0;

  // Update for Delay: '<S31>/Delay15'
  controller_2dof_pid_DW.Delay15_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay14_a_idx_0;

  // Update for Delay: '<S31>/Delay20'
  controller_2dof_pid_DW.Delay20_DSTATE_m[0] =
    controller_2dof_pid_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S31>/Delay21'
  controller_2dof_pid_DW.Delay21_DSTATE_b[0] =
    controller_2dof_pid_B.rtb_Delay20_m_idx_0;

  // Update for Delay: '<S31>/Delay22'
  controller_2dof_pid_DW.Delay22_DSTATE_g[0] =
    controller_2dof_pid_B.rtb_Delay21_j_idx_0;

  // Update for Delay: '<S31>/Delay23'
  controller_2dof_pid_DW.Delay23_DSTATE_e[0] =
    controller_2dof_pid_B.rtb_Delay22_c_idx_0;

  // Update for Delay: '<S31>/Delay24'
  controller_2dof_pid_DW.Delay24_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay23_a_idx_0;

  // Update for Delay: '<S31>/Delay25'
  controller_2dof_pid_DW.Delay25_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S31>/Delay26'
  controller_2dof_pid_DW.Delay26_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S31>/Delay27'
  controller_2dof_pid_DW.Delay27_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S31>/Delay16'
  controller_2dof_pid_DW.Delay16_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S31>/Delay17'
  controller_2dof_pid_DW.Delay17_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S31>/Delay18'
  controller_2dof_pid_DW.Delay18_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S31>/Delay19'
  controller_2dof_pid_DW.Delay19_DSTATE[0] =
    controller_2dof_pid_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S33>/Delay2' incorporates:
  //   Delay: '<S36>/Delay2'

  controller_2dof_pid_DW.Delay2_DSTATE_l[0] =
    controller_2dof_pid_DW.Delay2_DSTATE_fv[0];

  // Update for Delay: '<S35>/Delay23' incorporates:
  //   Delay: '<S35>/Delay22'
  //
  controller_2dof_pid_DW.Delay23_DSTATE[1] =
    controller_2dof_pid_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S35>/Delay22' incorporates:
  //   Delay: '<S35>/Delay21'
  //
  controller_2dof_pid_DW.Delay22_DSTATE[1] =
    controller_2dof_pid_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S35>/Delay21' incorporates:
  //   Delay: '<S35>/Delay20'
  //
  controller_2dof_pid_DW.Delay21_DSTATE[1] =
    controller_2dof_pid_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S35>/Delay20' incorporates:
  //   Delay: '<S35>/Delay14'
  //
  controller_2dof_pid_DW.Delay20_DSTATE[1] =
    controller_2dof_pid_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S35>/Delay14' incorporates:
  //   Delay: '<S35>/Delay13'
  //
  controller_2dof_pid_DW.Delay14_DSTATE[1] =
    controller_2dof_pid_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S35>/Delay13' incorporates:
  //   Delay: '<S35>/Delay12'
  //
  controller_2dof_pid_DW.Delay13_DSTATE[1] =
    controller_2dof_pid_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S35>/Delay12' incorporates:
  //   Delay: '<S35>/Delay11'
  //
  controller_2dof_pid_DW.Delay12_DSTATE[1] =
    controller_2dof_pid_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S35>/Delay11' incorporates:
  //   Delay: '<S35>/Delay10'
  //
  controller_2dof_pid_DW.Delay11_DSTATE[1] =
    controller_2dof_pid_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S35>/Delay10' incorporates:
  //   Delay: '<S35>/Delay9'
  //
  controller_2dof_pid_DW.Delay10_DSTATE[1] =
    controller_2dof_pid_DW.Delay9_DSTATE[1];

  // Update for Delay: '<S35>/Delay9' incorporates:
  //   Delay: '<S35>/Delay8'
  //
  controller_2dof_pid_DW.Delay9_DSTATE[1] =
    controller_2dof_pid_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S35>/Delay8' incorporates:
  //   Delay: '<S35>/Delay7'
  //
  controller_2dof_pid_DW.Delay8_DSTATE[1] =
    controller_2dof_pid_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S35>/Delay7' incorporates:
  //   Delay: '<S35>/Delay6'
  //
  controller_2dof_pid_DW.Delay7_DSTATE[1] =
    controller_2dof_pid_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S35>/Delay6' incorporates:
  //   Delay: '<S35>/Delay5'
  //
  controller_2dof_pid_DW.Delay6_DSTATE[1] =
    controller_2dof_pid_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S35>/Delay5' incorporates:
  //   Delay: '<S35>/Delay4'
  //
  controller_2dof_pid_DW.Delay5_DSTATE[1] =
    controller_2dof_pid_DW.Delay4_DSTATE_e[1];

  // Update for Delay: '<S35>/Delay4' incorporates:
  //   Delay: '<S35>/Delay3'
  //
  controller_2dof_pid_DW.Delay4_DSTATE_e[1] =
    controller_2dof_pid_DW.Delay3_DSTATE_j[1];

  // Update for Delay: '<S35>/Delay3' incorporates:
  //   Delay: '<S35>/Delay2'
  //
  controller_2dof_pid_DW.Delay3_DSTATE_j[1] =
    controller_2dof_pid_DW.Delay2_DSTATE_f[1];

  // Update for Delay: '<S35>/Delay2' incorporates:
  //   Delay: '<S35>/Delay1'
  //
  controller_2dof_pid_DW.Delay2_DSTATE_f[1] =
    controller_2dof_pid_DW.Delay1_DSTATE_b[1];

  // Update for Delay: '<S35>/Delay1' incorporates:
  //   Delay: '<S35>/Delay'
  //
  controller_2dof_pid_DW.Delay1_DSTATE_b[1] =
    controller_2dof_pid_DW.Delay_DSTATE[1];

  // Update for Delay: '<S35>/Delay'
  controller_2dof_pid_DW.Delay_DSTATE[1] = controller_2dof_pid_B.y_idx_1;

  // Update for Delay: '<S31>/Delay1'
  controller_2dof_pid_DW.Delay1_DSTATE_m[1] =
    controller_2dof_pid_B.rtb_Delay_i_idx_1;

  // Update for Delay: '<S31>/Delay2'
  controller_2dof_pid_DW.Delay2_DSTATE_k[1] =
    controller_2dof_pid_B.rtb_Delay1_g_idx_1;

  // Update for Delay: '<S31>/Delay3'
  controller_2dof_pid_DW.Delay3_DSTATE_c[1] =
    controller_2dof_pid_B.rtb_Delay2_g_idx_1;

  // Update for Delay: '<S31>/Delay4'
  controller_2dof_pid_DW.Delay4_DSTATE_j[1] =
    controller_2dof_pid_B.rtb_Delay3_f_idx_1;

  // Update for Delay: '<S31>/Delay5'
  controller_2dof_pid_DW.Delay5_DSTATE_e[1] =
    controller_2dof_pid_B.rtb_Delay4_p_idx_1;

  // Update for Delay: '<S31>/Delay6'
  controller_2dof_pid_DW.Delay6_DSTATE_j[1] =
    controller_2dof_pid_B.rtb_Delay5_l_idx_1;

  // Update for Delay: '<S31>/Delay7'
  controller_2dof_pid_DW.Delay7_DSTATE_l[1] =
    controller_2dof_pid_B.rtb_Delay6_g_idx_1;

  // Update for Delay: '<S31>/Delay8'
  controller_2dof_pid_DW.Delay8_DSTATE_m[1] =
    controller_2dof_pid_B.rtb_Delay7_l_idx_1;

  // Update for Delay: '<S31>/Delay9'
  controller_2dof_pid_DW.Delay9_DSTATE_e[1] =
    controller_2dof_pid_B.rtb_Delay8_e_idx_1;

  // Update for Delay: '<S31>/Delay10'
  controller_2dof_pid_DW.Delay10_DSTATE_a[1] =
    controller_2dof_pid_B.rtb_Delay9_c_idx_1;

  // Update for Delay: '<S31>/Delay11'
  controller_2dof_pid_DW.Delay11_DSTATE_m[1] =
    controller_2dof_pid_B.rtb_Delay10_g_idx_1;

  // Update for Delay: '<S31>/Delay12'
  controller_2dof_pid_DW.Delay12_DSTATE_h[1] =
    controller_2dof_pid_B.rtb_Delay11_g_idx_1;

  // Update for Delay: '<S31>/Delay13'
  controller_2dof_pid_DW.Delay13_DSTATE_b[1] =
    controller_2dof_pid_B.rtb_Delay12_k_idx_1;

  // Update for Delay: '<S31>/Delay14'
  controller_2dof_pid_DW.Delay14_DSTATE_k[1] =
    controller_2dof_pid_B.rtb_Delay13_o_idx_1;

  // Update for Delay: '<S31>/Delay15'
  controller_2dof_pid_DW.Delay15_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay14_a_idx_1;

  // Update for Delay: '<S31>/Delay20'
  controller_2dof_pid_DW.Delay20_DSTATE_m[1] =
    controller_2dof_pid_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S31>/Delay21'
  controller_2dof_pid_DW.Delay21_DSTATE_b[1] =
    controller_2dof_pid_B.rtb_Delay20_m_idx_1;

  // Update for Delay: '<S31>/Delay22'
  controller_2dof_pid_DW.Delay22_DSTATE_g[1] =
    controller_2dof_pid_B.rtb_Delay21_j_idx_1;

  // Update for Delay: '<S31>/Delay23'
  controller_2dof_pid_DW.Delay23_DSTATE_e[1] =
    controller_2dof_pid_B.rtb_Delay22_c_idx_1;

  // Update for Delay: '<S31>/Delay24'
  controller_2dof_pid_DW.Delay24_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay23_a_idx_1;

  // Update for Delay: '<S31>/Delay25'
  controller_2dof_pid_DW.Delay25_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S31>/Delay26'
  controller_2dof_pid_DW.Delay26_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S31>/Delay27'
  controller_2dof_pid_DW.Delay27_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S31>/Delay16'
  controller_2dof_pid_DW.Delay16_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S31>/Delay17'
  controller_2dof_pid_DW.Delay17_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S31>/Delay18'
  controller_2dof_pid_DW.Delay18_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S31>/Delay19'
  controller_2dof_pid_DW.Delay19_DSTATE[1] =
    controller_2dof_pid_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S33>/Delay2' incorporates:
  //   Delay: '<S36>/Delay2'

  controller_2dof_pid_DW.Delay2_DSTATE_l[1] =
    controller_2dof_pid_DW.Delay2_DSTATE_fv[1];

  // Update for Delay: '<S35>/Delay23' incorporates:
  //   Delay: '<S35>/Delay22'
  //
  controller_2dof_pid_DW.Delay23_DSTATE[2] =
    controller_2dof_pid_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S35>/Delay22' incorporates:
  //   Delay: '<S35>/Delay21'
  //
  controller_2dof_pid_DW.Delay22_DSTATE[2] =
    controller_2dof_pid_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S35>/Delay21' incorporates:
  //   Delay: '<S35>/Delay20'
  //
  controller_2dof_pid_DW.Delay21_DSTATE[2] =
    controller_2dof_pid_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S35>/Delay20' incorporates:
  //   Delay: '<S35>/Delay14'
  //
  controller_2dof_pid_DW.Delay20_DSTATE[2] =
    controller_2dof_pid_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S35>/Delay14' incorporates:
  //   Delay: '<S35>/Delay13'
  //
  controller_2dof_pid_DW.Delay14_DSTATE[2] =
    controller_2dof_pid_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S35>/Delay13' incorporates:
  //   Delay: '<S35>/Delay12'
  //
  controller_2dof_pid_DW.Delay13_DSTATE[2] =
    controller_2dof_pid_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S35>/Delay12' incorporates:
  //   Delay: '<S35>/Delay11'
  //
  controller_2dof_pid_DW.Delay12_DSTATE[2] =
    controller_2dof_pid_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S35>/Delay11' incorporates:
  //   Delay: '<S35>/Delay10'
  //
  controller_2dof_pid_DW.Delay11_DSTATE[2] =
    controller_2dof_pid_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S35>/Delay10' incorporates:
  //   Delay: '<S35>/Delay9'
  //
  controller_2dof_pid_DW.Delay10_DSTATE[2] =
    controller_2dof_pid_DW.Delay9_DSTATE[2];

  // Update for Delay: '<S35>/Delay9' incorporates:
  //   Delay: '<S35>/Delay8'
  //
  controller_2dof_pid_DW.Delay9_DSTATE[2] =
    controller_2dof_pid_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S35>/Delay8' incorporates:
  //   Delay: '<S35>/Delay7'
  //
  controller_2dof_pid_DW.Delay8_DSTATE[2] =
    controller_2dof_pid_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S35>/Delay7' incorporates:
  //   Delay: '<S35>/Delay6'
  //
  controller_2dof_pid_DW.Delay7_DSTATE[2] =
    controller_2dof_pid_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S35>/Delay6' incorporates:
  //   Delay: '<S35>/Delay5'
  //
  controller_2dof_pid_DW.Delay6_DSTATE[2] =
    controller_2dof_pid_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S35>/Delay5' incorporates:
  //   Delay: '<S35>/Delay4'
  //
  controller_2dof_pid_DW.Delay5_DSTATE[2] =
    controller_2dof_pid_DW.Delay4_DSTATE_e[2];

  // Update for Delay: '<S35>/Delay4' incorporates:
  //   Delay: '<S35>/Delay3'
  //
  controller_2dof_pid_DW.Delay4_DSTATE_e[2] =
    controller_2dof_pid_DW.Delay3_DSTATE_j[2];

  // Update for Delay: '<S35>/Delay3' incorporates:
  //   Delay: '<S35>/Delay2'
  //
  controller_2dof_pid_DW.Delay3_DSTATE_j[2] =
    controller_2dof_pid_DW.Delay2_DSTATE_f[2];

  // Update for Delay: '<S35>/Delay2' incorporates:
  //   Delay: '<S35>/Delay1'
  //
  controller_2dof_pid_DW.Delay2_DSTATE_f[2] =
    controller_2dof_pid_DW.Delay1_DSTATE_b[2];

  // Update for Delay: '<S35>/Delay1' incorporates:
  //   Delay: '<S35>/Delay'
  //
  controller_2dof_pid_DW.Delay1_DSTATE_b[2] =
    controller_2dof_pid_DW.Delay_DSTATE[2];

  // Update for Delay: '<S35>/Delay'
  controller_2dof_pid_DW.Delay_DSTATE[2] = controller_2dof_pid_B.y;

  // Update for Delay: '<S31>/Delay1' incorporates:
  //   Delay: '<S31>/Delay'

  controller_2dof_pid_DW.Delay1_DSTATE_m[2] =
    controller_2dof_pid_B.Delay_DSTATE_e;

  // Update for Delay: '<S31>/Delay2' incorporates:
  //   Delay: '<S31>/Delay1'

  controller_2dof_pid_DW.Delay2_DSTATE_k[2] =
    controller_2dof_pid_B.Delay1_DSTATE_m;

  // Update for Delay: '<S31>/Delay3' incorporates:
  //   Delay: '<S31>/Delay2'

  controller_2dof_pid_DW.Delay3_DSTATE_c[2] =
    controller_2dof_pid_B.Delay2_DSTATE_k;

  // Update for Delay: '<S31>/Delay4' incorporates:
  //   Delay: '<S31>/Delay3'

  controller_2dof_pid_DW.Delay4_DSTATE_j[2] =
    controller_2dof_pid_B.Delay3_DSTATE_c;

  // Update for Delay: '<S31>/Delay5' incorporates:
  //   Delay: '<S31>/Delay4'

  controller_2dof_pid_DW.Delay5_DSTATE_e[2] =
    controller_2dof_pid_B.Delay4_DSTATE_j;

  // Update for Delay: '<S31>/Delay6' incorporates:
  //   Delay: '<S31>/Delay5'

  controller_2dof_pid_DW.Delay6_DSTATE_j[2] =
    controller_2dof_pid_B.Delay5_DSTATE_e;

  // Update for Delay: '<S31>/Delay7' incorporates:
  //   Delay: '<S31>/Delay6'

  controller_2dof_pid_DW.Delay7_DSTATE_l[2] =
    controller_2dof_pid_B.Delay6_DSTATE_j;

  // Update for Delay: '<S31>/Delay8' incorporates:
  //   Delay: '<S31>/Delay7'

  controller_2dof_pid_DW.Delay8_DSTATE_m[2] =
    controller_2dof_pid_B.Delay7_DSTATE_l;

  // Update for Delay: '<S31>/Delay9' incorporates:
  //   Delay: '<S31>/Delay8'

  controller_2dof_pid_DW.Delay9_DSTATE_e[2] =
    controller_2dof_pid_B.Delay8_DSTATE_m;

  // Update for Delay: '<S31>/Delay10' incorporates:
  //   Delay: '<S31>/Delay9'

  controller_2dof_pid_DW.Delay10_DSTATE_a[2] =
    controller_2dof_pid_B.Delay9_DSTATE_e;

  // Update for Delay: '<S31>/Delay11' incorporates:
  //   Delay: '<S31>/Delay10'

  controller_2dof_pid_DW.Delay11_DSTATE_m[2] =
    controller_2dof_pid_B.Delay10_DSTATE_a;

  // Update for Delay: '<S31>/Delay12' incorporates:
  //   Delay: '<S31>/Delay11'

  controller_2dof_pid_DW.Delay12_DSTATE_h[2] =
    controller_2dof_pid_B.Delay11_DSTATE_m;

  // Update for Delay: '<S31>/Delay13' incorporates:
  //   Delay: '<S31>/Delay12'

  controller_2dof_pid_DW.Delay13_DSTATE_b[2] =
    controller_2dof_pid_B.Delay12_DSTATE_h;

  // Update for Delay: '<S31>/Delay14' incorporates:
  //   Delay: '<S31>/Delay13'

  controller_2dof_pid_DW.Delay14_DSTATE_k[2] =
    controller_2dof_pid_B.Delay13_DSTATE_b;

  // Update for Delay: '<S31>/Delay15' incorporates:
  //   Delay: '<S31>/Delay14'

  controller_2dof_pid_DW.Delay15_DSTATE[2] =
    controller_2dof_pid_B.Delay14_DSTATE_k;

  // Update for Delay: '<S31>/Delay20' incorporates:
  //   Delay: '<S31>/Delay15'

  controller_2dof_pid_DW.Delay20_DSTATE_m[2] =
    controller_2dof_pid_B.Delay15_DSTATE;

  // Update for Delay: '<S31>/Delay21' incorporates:
  //   Delay: '<S31>/Delay20'

  controller_2dof_pid_DW.Delay21_DSTATE_b[2] =
    controller_2dof_pid_B.Delay20_DSTATE_m;

  // Update for Delay: '<S31>/Delay22' incorporates:
  //   Delay: '<S31>/Delay21'

  controller_2dof_pid_DW.Delay22_DSTATE_g[2] =
    controller_2dof_pid_B.Delay21_DSTATE_b;

  // Update for Delay: '<S31>/Delay23' incorporates:
  //   Delay: '<S31>/Delay22'

  controller_2dof_pid_DW.Delay23_DSTATE_e[2] =
    controller_2dof_pid_B.Delay22_DSTATE_g;

  // Update for Delay: '<S31>/Delay24' incorporates:
  //   Delay: '<S31>/Delay23'

  controller_2dof_pid_DW.Delay24_DSTATE[2] =
    controller_2dof_pid_B.Delay23_DSTATE_e;

  // Update for Delay: '<S31>/Delay25' incorporates:
  //   Delay: '<S31>/Delay24'

  controller_2dof_pid_DW.Delay25_DSTATE[2] =
    controller_2dof_pid_B.Delay24_DSTATE;

  // Update for Delay: '<S31>/Delay26' incorporates:
  //   Delay: '<S31>/Delay25'

  controller_2dof_pid_DW.Delay26_DSTATE[2] =
    controller_2dof_pid_B.Delay25_DSTATE;

  // Update for Delay: '<S31>/Delay27' incorporates:
  //   Delay: '<S31>/Delay26'

  controller_2dof_pid_DW.Delay27_DSTATE[2] =
    controller_2dof_pid_B.Delay26_DSTATE;

  // Update for Delay: '<S31>/Delay16' incorporates:
  //   Delay: '<S31>/Delay27'

  controller_2dof_pid_DW.Delay16_DSTATE[2] =
    controller_2dof_pid_B.Delay27_DSTATE;

  // Update for Delay: '<S31>/Delay17' incorporates:
  //   Delay: '<S31>/Delay16'

  controller_2dof_pid_DW.Delay17_DSTATE[2] =
    controller_2dof_pid_B.Delay16_DSTATE;

  // Update for Delay: '<S31>/Delay18' incorporates:
  //   Delay: '<S31>/Delay17'

  controller_2dof_pid_DW.Delay18_DSTATE[2] =
    controller_2dof_pid_B.Delay17_DSTATE;

  // Update for Delay: '<S31>/Delay19' incorporates:
  //   Delay: '<S31>/Delay18'

  controller_2dof_pid_DW.Delay19_DSTATE[2] =
    controller_2dof_pid_B.Delay18_DSTATE;

  // Update for Delay: '<S33>/Delay2' incorporates:
  //   Delay: '<S36>/Delay2'

  controller_2dof_pid_DW.Delay2_DSTATE_l[2] =
    controller_2dof_pid_DW.Delay2_DSTATE_fv[2];

  // Update for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn'
  controller_2dof_pid_DW.DiscreteTransferFcn_states_i =
    (controller_2dof_pid_B.u_vect[0] -
     controller_2dof_pid_P.DiscreteTransferFcn_DenCoef_p[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn_states_i) /
    controller_2dof_pid_P.DiscreteTransferFcn_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn1'
  controller_2dof_pid_DW.DiscreteTransferFcn1_states_p =
    (controller_2dof_pid_B.u_vect[1] -
     controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_k[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states_p) /
    controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_k[0];

  // Update for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn2'
  controller_2dof_pid_DW.DiscreteTransferFcn2_states_o =
    (controller_2dof_pid_B.u_vect[2] -
     controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef_p[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn2_states_o) /
    controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1'
  controller_2dof_pid_DW.DiscreteTransferFcn1_states_c =
    (controller_2dof_pid_B.tth -
     controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_e[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states_c) /
    controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_e[0];

  // Update for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1'
  controller_2dof_pid_DW.DiscreteTransferFcn1_states_m =
    (controller_2dof_pid_B.temp_idx_0 -
     controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_m[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states_m) /
    controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_m[0];

  // Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn'
  controller_2dof_pid_DW.DiscreteTransferFcn_states_p =
    (controller_2dof_pid_B.TmpSignalConversionAtSFunct[0] -
     controller_2dof_pid_P.DiscreteTransferFcn_DenCoef_g[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn_states_p) /
    controller_2dof_pid_P.DiscreteTransferFcn_DenCoef_g[0];

  // Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn1'
  controller_2dof_pid_DW.DiscreteTransferFcn1_states_l =
    (controller_2dof_pid_B.TmpSignalConversionAtSFunct[1] -
     controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_p[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn1_states_l) /
    controller_2dof_pid_P.DiscreteTransferFcn1_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn2'
  controller_2dof_pid_DW.DiscreteTransferFcn2_states_g =
    (controller_2dof_pid_B.TmpSignalConversionAtSFunct[2] -
     controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef_o[1] *
     controller_2dof_pid_DW.DiscreteTransferFcn2_states_g) /
    controller_2dof_pid_P.DiscreteTransferFcn2_DenCoef_o[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controller_2dof_pid_M->Timing.taskTime0 =
    ((time_T)(++controller_2dof_pid_M->Timing.clockTick0)) *
    controller_2dof_pid_M->Timing.stepSize0;
}

// Model initialize function
void controller_2dof_pid_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controller_2dof_pid_M, -1);
  controller_2dof_pid_M->Timing.stepSize0 = 0.01;

  // External mode info
  controller_2dof_pid_M->Sizes.checksums[0] = (1419636814U);
  controller_2dof_pid_M->Sizes.checksums[1] = (3813756344U);
  controller_2dof_pid_M->Sizes.checksums[2] = (4183930769U);
  controller_2dof_pid_M->Sizes.checksums[3] = (587166201U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[41];
    controller_2dof_pid_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = (sysRanDType *)
      &controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_kv;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)
      &controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_g;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)
      &controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = (sysRanDType *)
      &controller_2dof_pid_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &controller_2dof_pid_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &controller_2dof_pid_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &controller_2dof_pid_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_2dof_pid_M->extModeInfo,
      &controller_2dof_pid_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_2dof_pid_M->extModeInfo,
                        controller_2dof_pid_M->Sizes.checksums);
    rteiSetTPtr(controller_2dof_pid_M->extModeInfo, rtmGetTPtr
                (controller_2dof_pid_M));
  }

  {
    // local block i/o variables
    boolean_T rtb_ManualSwitch1;
    int32_T i;

    // InitializeConditions for Delay: '<S1>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE =
      controller_2dof_pid_P.Delay3_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S11>/Internal'
    controller_2dof_pid_DW.Internal_DSTATE =
      controller_2dof_pid_P.Internal_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE[0] =
      controller_2dof_pid_P.Delay2_InitialCondition[0];
    controller_2dof_pid_DW.Delay2_DSTATE[1] =
      controller_2dof_pid_P.Delay2_InitialCondition[1];

    // InitializeConditions for Delay: '<S1>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE =
      controller_2dof_pid_P.Delay4_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S12>/Internal'
    controller_2dof_pid_DW.Internal_DSTATE_f =
      controller_2dof_pid_P.Internal_InitialCondition_i;

    // InitializeConditions for Delay: '<S1>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE[0] =
      controller_2dof_pid_P.Delay1_InitialCondition[0];
    controller_2dof_pid_DW.Delay1_DSTATE[1] =
      controller_2dof_pid_P.Delay1_InitialCondition[1];

    // InitializeConditions for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn' 
    controller_2dof_pid_DW.DiscreteTransferFcn_states =
      controller_2dof_pid_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn1' 
    controller_2dof_pid_DW.DiscreteTransferFcn1_states =
      controller_2dof_pid_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S29>/Discrete Transfer Fcn2' 
    controller_2dof_pid_DW.DiscreteTransferFcn2_states =
      controller_2dof_pid_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S35>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE[0] =
      controller_2dof_pid_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE[0] =
      controller_2dof_pid_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE[0] =
      controller_2dof_pid_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE[0] =
      controller_2dof_pid_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE[0] =
      controller_2dof_pid_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE[0] =
      controller_2dof_pid_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE[0] =
      controller_2dof_pid_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE[0] =
      controller_2dof_pid_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE[0] =
      controller_2dof_pid_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE[0] =
      controller_2dof_pid_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE[0] =
      controller_2dof_pid_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE[0] =
      controller_2dof_pid_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE[0] =
      controller_2dof_pid_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE[0] =
      controller_2dof_pid_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_e[0] =
      controller_2dof_pid_P.Delay4_InitialCondition_g;

    // InitializeConditions for Delay: '<S35>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_j[0] =
      controller_2dof_pid_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S35>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_f[0] =
      controller_2dof_pid_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S35>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_b[0] =
      controller_2dof_pid_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S35>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE[0] =
      controller_2dof_pid_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE_e[0] =
      controller_2dof_pid_P.Delay_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S31>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_m[0] =
      controller_2dof_pid_P.Delay1_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S31>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_k[0] =
      controller_2dof_pid_P.Delay2_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S31>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_c[0] =
      controller_2dof_pid_P.Delay3_InitialCondition_g[0];

    // InitializeConditions for Delay: '<S31>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_j[0] =
      controller_2dof_pid_P.Delay4_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S31>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE_e[0] =
      controller_2dof_pid_P.Delay5_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S31>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE_j[0] =
      controller_2dof_pid_P.Delay6_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S31>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE_l[0] =
      controller_2dof_pid_P.Delay7_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S31>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE_m[0] =
      controller_2dof_pid_P.Delay8_InitialCondition_g[0];

    // InitializeConditions for Delay: '<S31>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE_e[0] =
      controller_2dof_pid_P.Delay9_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S31>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE_a[0] =
      controller_2dof_pid_P.Delay10_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S31>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE_m[0] =
      controller_2dof_pid_P.Delay11_InitialCondition_e[0];

    // InitializeConditions for Delay: '<S31>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE_h[0] =
      controller_2dof_pid_P.Delay12_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S31>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE_b[0] =
      controller_2dof_pid_P.Delay13_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S31>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE_k[0] =
      controller_2dof_pid_P.Delay14_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S31>/Delay15'
    controller_2dof_pid_DW.Delay15_DSTATE[0] =
      controller_2dof_pid_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE_m[0] =
      controller_2dof_pid_P.Delay20_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S31>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE_b[0] =
      controller_2dof_pid_P.Delay21_InitialCondition_l[0];

    // InitializeConditions for Delay: '<S31>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE_g[0] =
      controller_2dof_pid_P.Delay22_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S31>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE_e[0] =
      controller_2dof_pid_P.Delay23_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S31>/Delay24'
    controller_2dof_pid_DW.Delay24_DSTATE[0] =
      controller_2dof_pid_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay25'
    controller_2dof_pid_DW.Delay25_DSTATE[0] =
      controller_2dof_pid_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay26'
    controller_2dof_pid_DW.Delay26_DSTATE[0] =
      controller_2dof_pid_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay27'
    controller_2dof_pid_DW.Delay27_DSTATE[0] =
      controller_2dof_pid_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay16'
    controller_2dof_pid_DW.Delay16_DSTATE[0] =
      controller_2dof_pid_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay17'
    controller_2dof_pid_DW.Delay17_DSTATE[0] =
      controller_2dof_pid_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay18'
    controller_2dof_pid_DW.Delay18_DSTATE[0] =
      controller_2dof_pid_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S31>/Delay19'
    controller_2dof_pid_DW.Delay19_DSTATE[0] =
      controller_2dof_pid_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S35>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE[1] =
      controller_2dof_pid_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE[1] =
      controller_2dof_pid_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE[1] =
      controller_2dof_pid_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE[1] =
      controller_2dof_pid_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE[1] =
      controller_2dof_pid_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE[1] =
      controller_2dof_pid_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE[1] =
      controller_2dof_pid_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE[1] =
      controller_2dof_pid_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE[1] =
      controller_2dof_pid_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE[1] =
      controller_2dof_pid_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE[1] =
      controller_2dof_pid_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE[1] =
      controller_2dof_pid_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE[1] =
      controller_2dof_pid_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE[1] =
      controller_2dof_pid_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_e[1] =
      controller_2dof_pid_P.Delay4_InitialCondition_g;

    // InitializeConditions for Delay: '<S35>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_j[1] =
      controller_2dof_pid_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S35>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_f[1] =
      controller_2dof_pid_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S35>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_b[1] =
      controller_2dof_pid_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S35>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE[1] =
      controller_2dof_pid_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE_e[1] =
      controller_2dof_pid_P.Delay_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S31>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_m[1] =
      controller_2dof_pid_P.Delay1_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S31>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_k[1] =
      controller_2dof_pid_P.Delay2_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S31>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_c[1] =
      controller_2dof_pid_P.Delay3_InitialCondition_g[1];

    // InitializeConditions for Delay: '<S31>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_j[1] =
      controller_2dof_pid_P.Delay4_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S31>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE_e[1] =
      controller_2dof_pid_P.Delay5_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S31>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE_j[1] =
      controller_2dof_pid_P.Delay6_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S31>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE_l[1] =
      controller_2dof_pid_P.Delay7_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S31>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE_m[1] =
      controller_2dof_pid_P.Delay8_InitialCondition_g[1];

    // InitializeConditions for Delay: '<S31>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE_e[1] =
      controller_2dof_pid_P.Delay9_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S31>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE_a[1] =
      controller_2dof_pid_P.Delay10_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S31>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE_m[1] =
      controller_2dof_pid_P.Delay11_InitialCondition_e[1];

    // InitializeConditions for Delay: '<S31>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE_h[1] =
      controller_2dof_pid_P.Delay12_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S31>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE_b[1] =
      controller_2dof_pid_P.Delay13_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S31>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE_k[1] =
      controller_2dof_pid_P.Delay14_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S31>/Delay15'
    controller_2dof_pid_DW.Delay15_DSTATE[1] =
      controller_2dof_pid_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE_m[1] =
      controller_2dof_pid_P.Delay20_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S31>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE_b[1] =
      controller_2dof_pid_P.Delay21_InitialCondition_l[1];

    // InitializeConditions for Delay: '<S31>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE_g[1] =
      controller_2dof_pid_P.Delay22_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S31>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE_e[1] =
      controller_2dof_pid_P.Delay23_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S31>/Delay24'
    controller_2dof_pid_DW.Delay24_DSTATE[1] =
      controller_2dof_pid_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay25'
    controller_2dof_pid_DW.Delay25_DSTATE[1] =
      controller_2dof_pid_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay26'
    controller_2dof_pid_DW.Delay26_DSTATE[1] =
      controller_2dof_pid_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay27'
    controller_2dof_pid_DW.Delay27_DSTATE[1] =
      controller_2dof_pid_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay16'
    controller_2dof_pid_DW.Delay16_DSTATE[1] =
      controller_2dof_pid_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay17'
    controller_2dof_pid_DW.Delay17_DSTATE[1] =
      controller_2dof_pid_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay18'
    controller_2dof_pid_DW.Delay18_DSTATE[1] =
      controller_2dof_pid_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S31>/Delay19'
    controller_2dof_pid_DW.Delay19_DSTATE[1] =
      controller_2dof_pid_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S35>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE[2] =
      controller_2dof_pid_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE[2] =
      controller_2dof_pid_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE[2] =
      controller_2dof_pid_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE[2] =
      controller_2dof_pid_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE[2] =
      controller_2dof_pid_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE[2] =
      controller_2dof_pid_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE[2] =
      controller_2dof_pid_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE[2] =
      controller_2dof_pid_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE[2] =
      controller_2dof_pid_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE[2] =
      controller_2dof_pid_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE[2] =
      controller_2dof_pid_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE[2] =
      controller_2dof_pid_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE[2] =
      controller_2dof_pid_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE[2] =
      controller_2dof_pid_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S35>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_e[2] =
      controller_2dof_pid_P.Delay4_InitialCondition_g;

    // InitializeConditions for Delay: '<S35>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_j[2] =
      controller_2dof_pid_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S35>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_f[2] =
      controller_2dof_pid_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S35>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_b[2] =
      controller_2dof_pid_P.Delay1_InitialCondition_l;

    // InitializeConditions for Delay: '<S35>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE[2] =
      controller_2dof_pid_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S31>/Delay'
    controller_2dof_pid_DW.Delay_DSTATE_e[2] =
      controller_2dof_pid_P.Delay_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S31>/Delay1'
    controller_2dof_pid_DW.Delay1_DSTATE_m[2] =
      controller_2dof_pid_P.Delay1_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S31>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_k[2] =
      controller_2dof_pid_P.Delay2_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S31>/Delay3'
    controller_2dof_pid_DW.Delay3_DSTATE_c[2] =
      controller_2dof_pid_P.Delay3_InitialCondition_g[2];

    // InitializeConditions for Delay: '<S31>/Delay4'
    controller_2dof_pid_DW.Delay4_DSTATE_j[2] =
      controller_2dof_pid_P.Delay4_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S31>/Delay5'
    controller_2dof_pid_DW.Delay5_DSTATE_e[2] =
      controller_2dof_pid_P.Delay5_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S31>/Delay6'
    controller_2dof_pid_DW.Delay6_DSTATE_j[2] =
      controller_2dof_pid_P.Delay6_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S31>/Delay7'
    controller_2dof_pid_DW.Delay7_DSTATE_l[2] =
      controller_2dof_pid_P.Delay7_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S31>/Delay8'
    controller_2dof_pid_DW.Delay8_DSTATE_m[2] =
      controller_2dof_pid_P.Delay8_InitialCondition_g[2];

    // InitializeConditions for Delay: '<S31>/Delay9'
    controller_2dof_pid_DW.Delay9_DSTATE_e[2] =
      controller_2dof_pid_P.Delay9_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S31>/Delay10'
    controller_2dof_pid_DW.Delay10_DSTATE_a[2] =
      controller_2dof_pid_P.Delay10_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S31>/Delay11'
    controller_2dof_pid_DW.Delay11_DSTATE_m[2] =
      controller_2dof_pid_P.Delay11_InitialCondition_e[2];

    // InitializeConditions for Delay: '<S31>/Delay12'
    controller_2dof_pid_DW.Delay12_DSTATE_h[2] =
      controller_2dof_pid_P.Delay12_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S31>/Delay13'
    controller_2dof_pid_DW.Delay13_DSTATE_b[2] =
      controller_2dof_pid_P.Delay13_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S31>/Delay14'
    controller_2dof_pid_DW.Delay14_DSTATE_k[2] =
      controller_2dof_pid_P.Delay14_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S31>/Delay15'
    controller_2dof_pid_DW.Delay15_DSTATE[2] =
      controller_2dof_pid_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay20'
    controller_2dof_pid_DW.Delay20_DSTATE_m[2] =
      controller_2dof_pid_P.Delay20_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S31>/Delay21'
    controller_2dof_pid_DW.Delay21_DSTATE_b[2] =
      controller_2dof_pid_P.Delay21_InitialCondition_l[2];

    // InitializeConditions for Delay: '<S31>/Delay22'
    controller_2dof_pid_DW.Delay22_DSTATE_g[2] =
      controller_2dof_pid_P.Delay22_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S31>/Delay23'
    controller_2dof_pid_DW.Delay23_DSTATE_e[2] =
      controller_2dof_pid_P.Delay23_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S31>/Delay24'
    controller_2dof_pid_DW.Delay24_DSTATE[2] =
      controller_2dof_pid_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay25'
    controller_2dof_pid_DW.Delay25_DSTATE[2] =
      controller_2dof_pid_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay26'
    controller_2dof_pid_DW.Delay26_DSTATE[2] =
      controller_2dof_pid_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay27'
    controller_2dof_pid_DW.Delay27_DSTATE[2] =
      controller_2dof_pid_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay16'
    controller_2dof_pid_DW.Delay16_DSTATE[2] =
      controller_2dof_pid_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay17'
    controller_2dof_pid_DW.Delay17_DSTATE[2] =
      controller_2dof_pid_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay18'
    controller_2dof_pid_DW.Delay18_DSTATE[2] =
      controller_2dof_pid_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S31>/Delay19'
    controller_2dof_pid_DW.Delay19_DSTATE[2] =
      controller_2dof_pid_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S33>/Memory4'
    for (i = 0; i < 5; i++) {
      controller_2dof_pid_DW.Memory4_PreviousInput[i] =
        controller_2dof_pid_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S33>/Memory4'

    // InitializeConditions for Delay: '<S33>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_l[0] =
      controller_2dof_pid_P.Delay2_InitialCondition_j;
    controller_2dof_pid_DW.Delay2_DSTATE_l[1] =
      controller_2dof_pid_P.Delay2_InitialCondition_j;
    controller_2dof_pid_DW.Delay2_DSTATE_l[2] =
      controller_2dof_pid_P.Delay2_InitialCondition_j;

    // InitializeConditions for Memory: '<S33>/Memory2'
    controller_2dof_pid_DW.Memory2_PreviousInput =
      controller_2dof_pid_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S33>/Memory3'
    memcpy(&controller_2dof_pid_DW.Memory3_PreviousInput[0],
           &controller_2dof_pid_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S36>/Memory4'
    controller_2dof_pid_DW.Memory4_PreviousInput_d = controller_2dof_pid_P.x0_ps;

    // InitializeConditions for Memory: '<S36>/Memory3'
    controller_2dof_pid_DW.Memory3_PreviousInput_g = controller_2dof_pid_P.P0_ps;

    // InitializeConditions for Memory: '<S36>/Memory2'
    controller_2dof_pid_DW.Memory2_PreviousInput_f =
      controller_2dof_pid_P.Memory2_InitialCondition_c;

    // InitializeConditions for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn' 
    controller_2dof_pid_DW.DiscreteTransferFcn_states_i =
      controller_2dof_pid_P.DiscreteTransferFcn_InitialSt_d;

    // InitializeConditions for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn1' 
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_p =
      controller_2dof_pid_P.DiscreteTransferFcn1_InitialS_m;

    // InitializeConditions for DiscreteTransferFcn: '<S30>/Discrete Transfer Fcn2' 
    controller_2dof_pid_DW.DiscreteTransferFcn2_states_o =
      controller_2dof_pid_P.DiscreteTransferFcn2_InitialS_i;

    // InitializeConditions for Memory: '<S24>/Memory5'
    controller_2dof_pid_DW.Memory5_PreviousInput =
      controller_2dof_pid_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S36>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_fv[0] =
      controller_2dof_pid_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S24>/Memory6'
    controller_2dof_pid_DW.Memory6_PreviousInput[0] =
      controller_2dof_pid_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S36>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_fv[1] =
      controller_2dof_pid_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S24>/Memory6'
    controller_2dof_pid_DW.Memory6_PreviousInput[1] =
      controller_2dof_pid_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S36>/Delay2'
    controller_2dof_pid_DW.Delay2_DSTATE_fv[2] =
      controller_2dof_pid_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S24>/Memory6'
    controller_2dof_pid_DW.Memory6_PreviousInput[2] =
      controller_2dof_pid_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S10>/Discrete Transfer Fcn1' 
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_c =
      controller_2dof_pid_P.DiscreteTransferFcn1_InitialS_e;

    // InitializeConditions for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1' 
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_m =
      controller_2dof_pid_P.DiscreteTransferFcn1_InitialS_o;

    // InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn' 
    controller_2dof_pid_DW.DiscreteTransferFcn_states_p =
      controller_2dof_pid_P.DiscreteTransferFcn_InitialSt_a;

    // InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn1' 
    controller_2dof_pid_DW.DiscreteTransferFcn1_states_l =
      controller_2dof_pid_P.DiscreteTransferFcn1_InitialS_a;

    // InitializeConditions for DiscreteTransferFcn: '<S28>/Discrete Transfer Fcn2' 
    controller_2dof_pid_DW.DiscreteTransferFcn2_states_g =
      controller_2dof_pid_P.DiscreteTransferFcn2_Initial_iv;

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1'
    controller_MATLABFunction1_Init(&controller_2dof_pid_DW.sf_MATLABFunction1);

    // SystemInitialize for MATLAB Function: '<S1>/MATLAB Function2'
    controller_MATLABFunction1_Init(&controller_2dof_pid_DW.sf_MATLABFunction2);

    // SystemInitialize for Enabled SubSystem: '<S74>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S75>/In1' incorporates:
    //   Outport: '<S75>/Out1'

    controller_2dof_pid_B.In1 = controller_2dof_pid_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S74>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S64>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S65>/In1' incorporates:
    //   Outport: '<S65>/Out1'

    controller_2dof_pid_B.In1_k = controller_2dof_pid_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S64>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S60>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S61>/In1' incorporates:
    //   Outport: '<S61>/Out1'

    controller_2dof_pid_B.In1_dn = controller_2dof_pid_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S60>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S62>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S63>/In1' incorporates:
    //   Outport: '<S63>/Out1'

    controller_2dof_pid_B.In1_d = controller_2dof_pid_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S62>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S25>/MATLAB Function7'
    controll_MATLABFunction1_f_Init(&controller_2dof_pid_DW.sf_MATLABFunction7);

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    controll_MATLABFunction1_f_Init(&controller_2dof_pid_DW.sf_MATLABFunction1_m);

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S53>/In1' incorporates:
    //   Outport: '<S53>/Out1'

    controller_2dof_pid_B.In1_h = controller_2dof_pid_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S74>/SourceBlock'
    controller_2dof_pid_DW.obj_n.matlabCodegenIsDeleted = false;
    controller_2dof_pid_DW.obj_n.isInitialized = 1;
    controller_2dof_pid_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_2dof_pid_DW.obj_n.orbMetadataObj,
                         &controller_2dof_pid_DW.obj_n.eventStructObj);
    controller_2dof_pid_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S64>/SourceBlock'
    controller_2dof_pid_DW.obj_g.matlabCodegenIsDeleted = false;
    controller_2dof_pid_DW.obj_g.isInitialized = 1;
    controller_2dof_pid_DW.obj_g.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(controller_2dof_pid_DW.obj_g.orbMetadataObj,
                         &controller_2dof_pid_DW.obj_g.eventStructObj);
    controller_2dof_pid_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S60>/SourceBlock'
    controller_2dof_pid_DW.obj_k.matlabCodegenIsDeleted = false;
    controller_2dof_pid_DW.obj_k.isInitialized = 1;
    controller_2dof_pid_DW.obj_k.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_2dof_pid_DW.obj_k.orbMetadataObj,
                         &controller_2dof_pid_DW.obj_k.eventStructObj);
    controller_2dof_pid_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S62>/SourceBlock'
    controller_2dof_pid_DW.obj_gg.matlabCodegenIsDeleted = false;
    controller_2dof_pid_DW.obj_gg.isInitialized = 1;
    controller_2dof_pid_DW.obj_gg.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_2dof_pid_DW.obj_gg.orbMetadataObj,
                         &controller_2dof_pid_DW.obj_gg.eventStructObj);
    controller_2dof_pid_DW.obj_gg.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/failsafe'

    controller_2dof_pid_DW.obj.errorStatus = 0U;
    controller_2dof_pid_DW.obj.isInitialized = 0;
    controller_2dof_pid_DW.obj.matlabCodegenIsDeleted = false;
    controller_2do_SystemCore_setup(&controller_2dof_pid_DW.obj,
      rtb_ManualSwitch1, controller_2dof_pid_P.failsafe_Value);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    controller_2dof_pid_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_2dof_pid_DW.obj_h.isInitialized = 1;
    controller_2dof_pid_DW.obj_h.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(controller_2dof_pid_DW.obj_h.orbMetadataObj,
                         &controller_2dof_pid_DW.obj_h.eventStructObj);
    controller_2dof_pid_DW.obj_h.isSetupComplete = true;
  }
}

// Model terminate function
void controller_2dof_pid_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S74>/SourceBlock'
  if (!controller_2dof_pid_DW.obj_n.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj_n.isInitialized == 1) &&
        controller_2dof_pid_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&controller_2dof_pid_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S74>/SourceBlock'

  // Terminate for MATLABSystem: '<S64>/SourceBlock'
  if (!controller_2dof_pid_DW.obj_g.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj_g.isInitialized == 1) &&
        controller_2dof_pid_DW.obj_g.isSetupComplete) {
      uORB_read_terminate(&controller_2dof_pid_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S64>/SourceBlock'

  // Terminate for MATLABSystem: '<S60>/SourceBlock'
  if (!controller_2dof_pid_DW.obj_k.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj_k.isInitialized == 1) &&
        controller_2dof_pid_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&controller_2dof_pid_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S60>/SourceBlock'

  // Terminate for MATLABSystem: '<S62>/SourceBlock'
  if (!controller_2dof_pid_DW.obj_gg.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj_gg.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj_gg.isInitialized == 1) &&
        controller_2dof_pid_DW.obj_gg.isSetupComplete) {
      uORB_read_terminate(&controller_2dof_pid_DW.obj_gg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S62>/SourceBlock'
  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!controller_2dof_pid_DW.obj.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj.isInitialized == 1) &&
        controller_2dof_pid_DW.obj.isSetupComplete) {
      status = pwm_disarm(&controller_2dof_pid_DW.obj.pwmDevHandler,
                          &controller_2dof_pid_DW.obj.armAdvertiseObj);
      controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_2dof_pid_DW.obj.errorStatus | status);
      status = pwm_resetServo(&controller_2dof_pid_DW.obj.pwmDevHandler,
        controller_2dof_pid_DW.obj.servoCount,
        controller_2dof_pid_DW.obj.channelMask,
        controller_2dof_pid_DW.obj.isMain,
        &controller_2dof_pid_DW.obj.actuatorAdvertiseObj);
      controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_2dof_pid_DW.obj.errorStatus | status);
      status = pwm_close(&controller_2dof_pid_DW.obj.pwmDevHandler,
                         &controller_2dof_pid_DW.obj.actuatorAdvertiseObj,
                         &controller_2dof_pid_DW.obj.armAdvertiseObj);
      controller_2dof_pid_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_2dof_pid_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!controller_2dof_pid_DW.obj_h.matlabCodegenIsDeleted) {
    controller_2dof_pid_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_2dof_pid_DW.obj_h.isInitialized == 1) &&
        controller_2dof_pid_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&controller_2dof_pid_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
