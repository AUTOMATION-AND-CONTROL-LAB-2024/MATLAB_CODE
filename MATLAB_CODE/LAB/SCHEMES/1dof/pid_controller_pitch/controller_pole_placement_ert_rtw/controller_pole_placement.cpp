//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_pole_placement.cpp
//
// Code generated for Simulink model 'controller_pole_placement'.
//
// Model version                  : 1.54
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 16:25:55 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_pole_placement.h"
#include "rtwtypes.h"
#include "controller_pole_placement_types.h"
#include "controller_pole_placement_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S3>/MATLAB Function1'
const int32_T controller_pole_plac_CALL_EVENT = -1;

// Block signals (default storage)
B_controller_pole_placement_T controller_pole_placement_B;

// Block states (default storage)
DW_controller_pole_placement_T controller_pole_placement_DW;

// Real-time model
RT_MODEL_controller_pole_plac_T controller_pole_placement_M_ =
  RT_MODEL_controller_pole_plac_T();
RT_MODEL_controller_pole_plac_T *const controller_pole_placement_M =
  &controller_pole_placement_M_;

// Forward declaration for local functions
static void controller_pol_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<S3>/MATLAB Function1'
//    '<S12>/MATLAB Function7'
//
void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_pole_plac_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S3>/MATLAB Function1'
//    '<S12>/MATLAB Function7'
//
void controller_pole_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controller_T *localDW)
{
  localDW->sfEvent = controller_pole_plac_CALL_EVENT;
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

static void controller_pol_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
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
void controller_pole_placement_step(void)
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
  boolean_T rtb_startingswitch;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_js);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_j);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S11>/Discrete Time1'
  //   DigitalClock: '<S20>/Discrete Time'
  //   DigitalClock: '<S23>/Discrete Time'
  //   Step: '<Root>/R ref'

  controller_pole_placement_B.DigitalClock1 =
    controller_pole_placement_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (controller_pole_placement_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = controller_pole_placement_P.Constant2_Value;
  } else {
    rtb_startingswitch = controller_pole_placement_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // DiscreteStateSpace: '<S42>/Internal'
  {
    controller_pole_placement_B.Internal =
      controller_pole_placement_P.Internal_C*
      controller_pole_placement_DW.Internal_DSTATE;
  }

  // Product: '<S6>/Product' incorporates:
  //   Gain: '<S6>/Gain'

  controller_pole_placement_B.Product = controller_pole_placement_P.Gain_Gain_e *
    controller_pole_placement_B.Internal * static_cast<real_T>
    (rtb_startingswitch);

  // MATLAB Function: '<S6>/MATLAB Function1' incorporates:
  //   Constant: '<S6>/Constant3'
  //   Constant: '<S6>/Constant6'

  if (!rtb_startingswitch) {
    controller_pole_placement_DW.Delay2_DSTATE[0] = 0.0;
    controller_pole_placement_DW.Delay2_DSTATE[1] = 0.0;
    controller_pole_placement_DW.Delay2_DSTATE[2] = 0.0;
    controller_pole_placement_DW.Delay3_DSTATE = 0.0;
  }

  controller_pole_placement_B.a21 = 0.0;
  controller_pole_placement_B.Delay2_DSTATE =
    controller_pole_placement_DW.Delay2_DSTATE[1];
  controller_pole_placement_B.Delay2_DSTATE_m =
    controller_pole_placement_DW.Delay2_DSTATE[0];
  controller_pole_placement_B.Delay2_DSTATE_n =
    controller_pole_placement_DW.Delay2_DSTATE[2];
  for (i = 0; i < 3; i++) {
    controller_pole_placement_B.x_g = ((controller_pole_placement_P.A_cond[i + 3]
      * controller_pole_placement_B.Delay2_DSTATE +
      controller_pole_placement_P.A_cond[i] *
      controller_pole_placement_B.Delay2_DSTATE_m) +
      controller_pole_placement_P.A_cond[i + 6] *
      controller_pole_placement_B.Delay2_DSTATE_n) +
      controller_pole_placement_P.B_cond[i] *
      controller_pole_placement_DW.Delay3_DSTATE;
    controller_pole_placement_B.x[i] = controller_pole_placement_B.x_g;
    controller_pole_placement_B.a21 += controller_pole_placement_P.C[i] *
      controller_pole_placement_B.x_g;
  }

  controller_pole_placement_B.u_sat = controller_pole_placement_P.D *
    controller_pole_placement_B.Product + controller_pole_placement_B.a21;
  if ((controller_pole_placement_P.Constant6_Value <=
       controller_pole_placement_B.u_sat) || rtIsNaN
      (controller_pole_placement_B.u_sat)) {
    controller_pole_placement_B.u_sat =
      controller_pole_placement_P.Constant6_Value;
  }

  if ((controller_pole_placement_P.Constant3_Value >=
       controller_pole_placement_B.u_sat) || rtIsNaN
      (controller_pole_placement_B.u_sat)) {
    controller_pole_placement_B.u_sat =
      controller_pole_placement_P.Constant3_Value;
  }

  // End of MATLAB Function: '<S6>/MATLAB Function1'

  // MATLAB Function: '<S6>/MATLAB Function3'
  controller_pole_placement_B.tau_o[1] = controller_pole_placement_B.u_sat;
  controller_pole_placement_B.tau_o[0] = 0.0;
  controller_pole_placement_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (controller_pole_placement_B.tau_o[0] >= 0.0) {
    controller_pole_placement_B.u[3] =
      controller_pole_placement_P.Constant3_Value_m;
    controller_pole_placement_B.u[2] = (controller_pole_placement_P.param[3] *
      controller_pole_placement_P.param[7] *
      controller_pole_placement_P.Constant3_Value_m +
      controller_pole_placement_B.tau_o[0]) /
      (controller_pole_placement_P.param[3] * controller_pole_placement_P.param
       [6]);
  } else {
    controller_pole_placement_B.u[2] =
      controller_pole_placement_P.Constant3_Value_m;
    controller_pole_placement_B.u[3] = (controller_pole_placement_P.param[3] *
      controller_pole_placement_P.param[6] *
      controller_pole_placement_P.Constant3_Value_m -
      controller_pole_placement_B.tau_o[0]) /
      (controller_pole_placement_P.param[3] * controller_pole_placement_P.param
       [7]);
  }

  if (controller_pole_placement_B.tau_o[1] >= 0.0) {
    controller_pole_placement_B.u[0] =
      controller_pole_placement_P.Constant3_Value_m;
    controller_pole_placement_B.u[1] = (controller_pole_placement_P.param[3] *
      controller_pole_placement_P.param[4] *
      controller_pole_placement_P.Constant3_Value_m +
      controller_pole_placement_B.tau_o[1]) /
      (controller_pole_placement_P.param[3] * controller_pole_placement_P.param
       [5]);
  } else {
    controller_pole_placement_B.u[1] =
      controller_pole_placement_P.Constant3_Value_m;
    controller_pole_placement_B.u[0] = (controller_pole_placement_P.param[3] *
      controller_pole_placement_P.param[5] *
      controller_pole_placement_P.Constant3_Value_m -
      controller_pole_placement_B.tau_o[1]) /
      (controller_pole_placement_P.param[3] * controller_pole_placement_P.param
       [4]);
  }

  b_varargout_1 = rtIsNaN(controller_pole_placement_B.u[0]);
  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[0]) || b_varargout_1) {
    controller_pole_placement_B.Delay2_DSTATE =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.Delay2_DSTATE = controller_pole_placement_B.u[0];
  }

  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[0]) || b_varargout_1) {
    controller_pole_placement_B.minval[0] =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.minval[0] = controller_pole_placement_B.u[0];
  }

  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[1]) || rtIsNaN
      (controller_pole_placement_B.u[1])) {
    controller_pole_placement_B.Delay2_DSTATE_m =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.Delay2_DSTATE_m = controller_pole_placement_B.u
      [1];
  }

  b_varargout_1 = rtIsNaN(controller_pole_placement_B.u[2]);
  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[2]) || b_varargout_1) {
    controller_pole_placement_B.Delay2_DSTATE_n =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.Delay2_DSTATE_n = controller_pole_placement_B.u
      [2];
  }

  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[2]) || b_varargout_1) {
    controller_pole_placement_B.minval[2] =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.minval[2] = controller_pole_placement_B.u[2];
  }

  if ((controller_pole_placement_P.Constant1_Value <=
       controller_pole_placement_B.u[3]) || rtIsNaN
      (controller_pole_placement_B.u[3])) {
    controller_pole_placement_B.x_g =
      controller_pole_placement_P.Constant1_Value;
  } else {
    controller_pole_placement_B.x_g = controller_pole_placement_B.u[3];
  }

  controller_pole_placement_B.dv1[0] = 0.0;
  controller_pole_placement_B.dv1[3] = 0.0;
  controller_pole_placement_B.dv1[6] = controller_pole_placement_P.param[3] *
    controller_pole_placement_P.param[6];
  controller_pole_placement_B.dv1[9] = -controller_pole_placement_P.param[3] *
    controller_pole_placement_P.param[7];
  controller_pole_placement_B.dv1[1] = -controller_pole_placement_P.param[3] *
    controller_pole_placement_P.param[4];
  controller_pole_placement_B.dv1[4] = controller_pole_placement_P.param[3] *
    controller_pole_placement_P.param[5];
  controller_pole_placement_B.dv1[7] = 0.0;
  controller_pole_placement_B.dv1[10] = 0.0;
  controller_pole_placement_B.dv1[2] = -controller_pole_placement_P.param[8];
  controller_pole_placement_B.dv1[5] = -controller_pole_placement_P.param[8];
  controller_pole_placement_B.dv1[8] = controller_pole_placement_P.param[8];
  controller_pole_placement_B.dv1[11] = controller_pole_placement_P.param[8];
  controller_pole_placement_B.rtb_Delay_l_idx_0 =
    controller_pole_placement_B.minval[0];
  controller_pole_placement_B.rtb_Delay1_n_idx_0 =
    controller_pole_placement_B.minval[2];
  for (i = 0; i < 3; i++) {
    controller_pole_placement_B.tau_allocated[i] =
      ((controller_pole_placement_B.dv1[i + 3] *
        controller_pole_placement_B.Delay2_DSTATE_m +
        controller_pole_placement_B.dv1[i] *
        controller_pole_placement_B.rtb_Delay_l_idx_0) +
       controller_pole_placement_B.dv1[i + 6] *
       controller_pole_placement_B.rtb_Delay1_n_idx_0) +
      controller_pole_placement_B.dv1[i + 9] * controller_pole_placement_B.x_g;
  }

  controller_pole_placement_B.u[0] = controller_pole_placement_B.Delay2_DSTATE;
  controller_pole_placement_B.u[1] = controller_pole_placement_B.Delay2_DSTATE_m;
  controller_pole_placement_B.u[2] = controller_pole_placement_B.Delay2_DSTATE_n;
  controller_pole_placement_B.u[3] = controller_pole_placement_B.x_g;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  controller_pole_placement_B.u1 = controller_pole_placement_B.u[0];
  controller_pole_placement_B.u2 = controller_pole_placement_B.u[1];
  controller_pole_placement_B.u3 = controller_pole_placement_B.u[2];
  controller_pole_placement_B.u4 = controller_pole_placement_B.u[3];

  // DataTypeConversion: '<S36>/Data Type Conversion1' incorporates:
  //   Constant: '<S36>/Constant'
  //   Sum: '<S36>/Sum'

  controller_pole_placement_B.a21 = floor(controller_pole_placement_B.u1 +
    controller_pole_placement_P.Constant_Value_n);
  if (rtIsNaN(controller_pole_placement_B.a21) || rtIsInf
      (controller_pole_placement_B.a21)) {
    controller_pole_placement_B.a21 = 0.0;
  } else {
    controller_pole_placement_B.a21 = fmod(controller_pole_placement_B.a21,
      65536.0);
  }

  rtb_DataTypeConversion1_c = static_cast<uint16_T>
    (controller_pole_placement_B.a21 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_pole_placement_B.a21)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_pole_placement_B.a21)));

  // End of DataTypeConversion: '<S36>/Data Type Conversion1'

  // DataTypeConversion: '<S37>/Data Type Conversion1' incorporates:
  //   Constant: '<S37>/Constant'
  //   Sum: '<S37>/Sum'

  controller_pole_placement_B.a21 = floor(controller_pole_placement_B.u2 +
    controller_pole_placement_P.Constant_Value_j);
  if (rtIsNaN(controller_pole_placement_B.a21) || rtIsInf
      (controller_pole_placement_B.a21)) {
    controller_pole_placement_B.a21 = 0.0;
  } else {
    controller_pole_placement_B.a21 = fmod(controller_pole_placement_B.a21,
      65536.0);
  }

  rtb_DataTypeConversion1_h = static_cast<uint16_T>
    (controller_pole_placement_B.a21 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_pole_placement_B.a21)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_pole_placement_B.a21)));

  // End of DataTypeConversion: '<S37>/Data Type Conversion1'

  // DataTypeConversion: '<S38>/Data Type Conversion1' incorporates:
  //   Constant: '<S38>/Constant'
  //   Sum: '<S38>/Sum'

  controller_pole_placement_B.a21 = floor(controller_pole_placement_B.u3 +
    controller_pole_placement_P.Constant_Value_pr);
  if (rtIsNaN(controller_pole_placement_B.a21) || rtIsInf
      (controller_pole_placement_B.a21)) {
    controller_pole_placement_B.a21 = 0.0;
  } else {
    controller_pole_placement_B.a21 = fmod(controller_pole_placement_B.a21,
      65536.0);
  }

  rtb_DataTypeConversion1_p = static_cast<uint16_T>
    (controller_pole_placement_B.a21 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_pole_placement_B.a21)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_pole_placement_B.a21)));

  // End of DataTypeConversion: '<S38>/Data Type Conversion1'

  // DataTypeConversion: '<S39>/Data Type Conversion1' incorporates:
  //   Constant: '<S39>/Constant'
  //   Sum: '<S39>/Sum'

  controller_pole_placement_B.a21 = floor(controller_pole_placement_B.u4 +
    controller_pole_placement_P.Constant_Value_d);
  if (rtIsNaN(controller_pole_placement_B.a21) || rtIsInf
      (controller_pole_placement_B.a21)) {
    controller_pole_placement_B.a21 = 0.0;
  } else {
    controller_pole_placement_B.a21 = fmod(controller_pole_placement_B.a21,
      65536.0);
  }

  rtb_DataTypeConversion1_o = static_cast<uint16_T>
    (controller_pole_placement_B.a21 < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-controller_pole_placement_B.a21)))) : static_cast<int32_T>(
      static_cast<uint16_T>(controller_pole_placement_B.a21)));

  // End of DataTypeConversion: '<S39>/Data Type Conversion1'

  // MATLABSystem: '<S68>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (controller_pole_placement_DW.obj_c.orbMetadataObj,
     &controller_pole_placement_DW.obj_c.eventStructObj,
     &controller_pole_placement_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S68>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S69>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S69>/In1'
    controller_pole_placement_B.In1 = controller_pole_placement_B.b_varargout_2;
    srUpdateBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S68>/SourceBlock'
  // End of Outputs for SubSystem: '<S68>/Enabled Subsystem'

  // Sqrt: '<S66>/sqrt' incorporates:
  //   Product: '<S67>/Product'
  //   Product: '<S67>/Product1'
  //   Product: '<S67>/Product2'
  //   Product: '<S67>/Product3'
  //   Sum: '<S67>/Sum'

  controller_pole_placement_B.Product3 = static_cast<real32_T>(sqrt
    (static_cast<real_T>(((controller_pole_placement_B.In1.q[0] *
    controller_pole_placement_B.In1.q[0] + controller_pole_placement_B.In1.q[1] *
    controller_pole_placement_B.In1.q[1]) + controller_pole_placement_B.In1.q[2]
    * controller_pole_placement_B.In1.q[2]) + controller_pole_placement_B.In1.q
    [3] * controller_pole_placement_B.In1.q[3])));

  // Product: '<S61>/Product'
  rtb_fcn5 = controller_pole_placement_B.In1.q[0] /
    controller_pole_placement_B.Product3;

  // Product: '<S61>/Product1'
  rtb_Product1 = controller_pole_placement_B.In1.q[1] /
    controller_pole_placement_B.Product3;

  // Product: '<S61>/Product2'
  rtb_Product2 = controller_pole_placement_B.In1.q[2] /
    controller_pole_placement_B.Product3;

  // Product: '<S61>/Product3'
  controller_pole_placement_B.Product3 = controller_pole_placement_B.In1.q[3] /
    controller_pole_placement_B.Product3;

  // Fcn: '<S51>/fcn3'
  rtb_fcn3 = (rtb_Product1 * controller_pole_placement_B.Product3 - rtb_fcn5 *
              rtb_Product2) * -2.0F;

  // If: '<S62>/If' incorporates:
  //   Constant: '<S63>/Constant'
  //   Constant: '<S64>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
    //   ActionPort: '<S63>/Action Port'

    rtb_fcn3 = controller_pole_placement_P.Constant_Value_o;

    // End of Outputs for SubSystem: '<S62>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S62>/If Action Subsystem' incorporates:
    //   ActionPort: '<S63>/Action Port'

    // Update for If: '<S62>/If' incorporates:
    //   Constant: '<S63>/Constant'

    srUpdateBC(controller_pole_placement_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S64>/Action Port'

    rtb_fcn3 = controller_pole_placement_P.Constant_Value_e5;

    // End of Outputs for SubSystem: '<S62>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S62>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S64>/Action Port'

    // Update for If: '<S62>/If' incorporates:
    //   Constant: '<S64>/Constant'

    srUpdateBC(controller_pole_placement_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S62>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S65>/Action Port'

    // Update for If: '<S62>/If'
    srUpdateBC(controller_pole_placement_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S62>/If Action Subsystem2'
  }

  // End of If: '<S62>/If'

  // Fcn: '<S51>/fcn5' incorporates:
  //   Fcn: '<S51>/fcn2'

  y_k_tmp = rtb_fcn5 * rtb_fcn5;
  y_k_tmp_0 = rtb_Product1 * rtb_Product1;
  y_k_tmp_1 = rtb_Product2 * rtb_Product2;
  y_k_tmp_2 = controller_pole_placement_B.Product3 *
    controller_pole_placement_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S51>/fcn4'
  //   Fcn: '<S51>/fcn5'
  //   Trigonometry: '<S60>/Trigonometric Function3'

  controller_pole_placement_B.y_k[0] = rt_atan2f_snf((rtb_Product2 *
    controller_pole_placement_B.Product3 + rtb_fcn5 * rtb_Product1) * 2.0F,
    ((y_k_tmp - y_k_tmp_0) - y_k_tmp_1) + y_k_tmp_2);

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

  controller_pole_placement_B.y_k[1] = static_cast<real32_T>(asin
    (static_cast<real_T>(rtb_fcn3)));
  controller_pole_placement_B.y_k[2] = rt_atan2f_snf((rtb_Product1 *
    rtb_Product2 + rtb_fcn5 * controller_pole_placement_B.Product3) * 2.0F,
    ((y_k_tmp + y_k_tmp_0) - y_k_tmp_1) - y_k_tmp_2);

  // MATLABSystem: '<S58>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (controller_pole_placement_DW.obj_h.orbMetadataObj,
     &controller_pole_placement_DW.obj_h.eventStructObj,
     &controller_pole_placement_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S58>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S59>/In1'
    controller_pole_placement_B.In1_f =
      controller_pole_placement_B.b_varargout_2_b;
    srUpdateBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_j);
  }

  // End of MATLABSystem: '<S58>/SourceBlock'
  // End of Outputs for SubSystem: '<S58>/Enabled Subsystem'

  // MATLABSystem: '<S54>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (controller_pole_placement_DW.obj_jj.orbMetadataObj,
     &controller_pole_placement_DW.obj_jj.eventStructObj,
     &controller_pole_placement_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S54>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S55>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S55>/In1'
    controller_pole_placement_B.In1_i =
      controller_pole_placement_B.b_varargout_2_k;
    srUpdateBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_js);
  }

  // End of MATLABSystem: '<S54>/SourceBlock'
  // End of Outputs for SubSystem: '<S54>/Enabled Subsystem'

  // MATLABSystem: '<S56>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (controller_pole_placement_DW.obj_j.orbMetadataObj,
     &controller_pole_placement_DW.obj_j.eventStructObj,
     &controller_pole_placement_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S56>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S57>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S57>/In1'
    controller_pole_placement_B.In1_n =
      controller_pole_placement_B.b_varargout_2_cx;
    srUpdateBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S56>/SourceBlock'
  // End of Outputs for SubSystem: '<S56>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn'
  controller_pole_placement_B.Delay2_DSTATE_m =
    controller_pole_placement_P.DiscreteTransferFcn_NumCoef *
    controller_pole_placement_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn1'
  controller_pole_placement_B.Delay2_DSTATE_n =
    controller_pole_placement_P.DiscreteTransferFcn1_NumCoef *
    controller_pole_placement_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn2'
  controller_pole_placement_B.x_g =
    controller_pole_placement_P.DiscreteTransferFcn2_NumCoef *
    controller_pole_placement_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S25>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S18>/MATLAB Function'

  controller_pole_placement_B.TmpSignalConversionAtSFun_e[0] =
    controller_pole_placement_B.Delay2_DSTATE_m;
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[1] =
    controller_pole_placement_B.Delay2_DSTATE_n;
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[2] =
    controller_pole_placement_B.x_g;

  // Delay: '<S18>/Delay'
  controller_pole_placement_B.rtb_Delay_l_idx_0 =
    controller_pole_placement_DW.Delay_DSTATE_p[0];

  // Delay: '<S18>/Delay1'
  controller_pole_placement_B.rtb_Delay1_n_idx_0 =
    controller_pole_placement_DW.Delay1_DSTATE_p[0];

  // Delay: '<S18>/Delay2'
  controller_pole_placement_B.rtb_Delay2_h_idx_0 =
    controller_pole_placement_DW.Delay2_DSTATE_p[0];

  // Delay: '<S18>/Delay3'
  controller_pole_placement_B.rtb_Delay3_p_idx_0 =
    controller_pole_placement_DW.Delay3_DSTATE_j[0];

  // Delay: '<S18>/Delay4'
  controller_pole_placement_B.rtb_Delay4_j_idx_0 =
    controller_pole_placement_DW.Delay4_DSTATE_e[0];

  // Delay: '<S18>/Delay5'
  controller_pole_placement_B.rtb_Delay5_e_idx_0 =
    controller_pole_placement_DW.Delay5_DSTATE_p[0];

  // Delay: '<S18>/Delay6'
  controller_pole_placement_B.rtb_Delay6_f_idx_0 =
    controller_pole_placement_DW.Delay6_DSTATE_p[0];

  // Delay: '<S18>/Delay7'
  controller_pole_placement_B.rtb_Delay7_i_idx_0 =
    controller_pole_placement_DW.Delay7_DSTATE_o[0];

  // Delay: '<S18>/Delay8'
  controller_pole_placement_B.rtb_Delay8_j_idx_0 =
    controller_pole_placement_DW.Delay8_DSTATE_n[0];

  // Delay: '<S18>/Delay9'
  controller_pole_placement_B.rtb_Delay9_j_idx_0 =
    controller_pole_placement_DW.Delay9_DSTATE_i[0];

  // Delay: '<S18>/Delay10'
  controller_pole_placement_B.rtb_Delay10_e_idx_0 =
    controller_pole_placement_DW.Delay10_DSTATE_f[0];

  // Delay: '<S18>/Delay11'
  controller_pole_placement_B.rtb_Delay11_n_idx_0 =
    controller_pole_placement_DW.Delay11_DSTATE_k[0];

  // Delay: '<S18>/Delay12'
  controller_pole_placement_B.rtb_Delay12_a_idx_0 =
    controller_pole_placement_DW.Delay12_DSTATE_n[0];

  // Delay: '<S18>/Delay13'
  controller_pole_placement_B.rtb_Delay13_h_idx_0 =
    controller_pole_placement_DW.Delay13_DSTATE_g[0];

  // Delay: '<S18>/Delay14'
  controller_pole_placement_B.rtb_Delay14_m_idx_0 =
    controller_pole_placement_DW.Delay14_DSTATE_g[0];

  // Delay: '<S18>/Delay15'
  controller_pole_placement_B.rtb_Delay15_idx_0 =
    controller_pole_placement_DW.Delay15_DSTATE[0];

  // Delay: '<S18>/Delay20'
  controller_pole_placement_B.rtb_Delay20_g_idx_0 =
    controller_pole_placement_DW.Delay20_DSTATE_h[0];

  // Delay: '<S18>/Delay21'
  controller_pole_placement_B.rtb_Delay21_e_idx_0 =
    controller_pole_placement_DW.Delay21_DSTATE_d[0];

  // Delay: '<S18>/Delay22'
  controller_pole_placement_B.rtb_Delay22_b_idx_0 =
    controller_pole_placement_DW.Delay22_DSTATE_h[0];

  // Delay: '<S18>/Delay23'
  controller_pole_placement_B.rtb_Delay23_g_idx_0 =
    controller_pole_placement_DW.Delay23_DSTATE_p[0];

  // Delay: '<S18>/Delay24'
  controller_pole_placement_B.rtb_Delay24_idx_0 =
    controller_pole_placement_DW.Delay24_DSTATE[0];

  // Delay: '<S18>/Delay25'
  controller_pole_placement_B.rtb_Delay25_idx_0 =
    controller_pole_placement_DW.Delay25_DSTATE[0];

  // Delay: '<S18>/Delay26'
  controller_pole_placement_B.rtb_Delay26_idx_0 =
    controller_pole_placement_DW.Delay26_DSTATE[0];

  // Delay: '<S18>/Delay27'
  controller_pole_placement_B.rtb_Delay27_idx_0 =
    controller_pole_placement_DW.Delay27_DSTATE[0];

  // Delay: '<S18>/Delay16'
  controller_pole_placement_B.rtb_Delay16_idx_0 =
    controller_pole_placement_DW.Delay16_DSTATE[0];

  // Delay: '<S18>/Delay17'
  controller_pole_placement_B.rtb_Delay17_idx_0 =
    controller_pole_placement_DW.Delay17_DSTATE[0];

  // Delay: '<S18>/Delay18'
  controller_pole_placement_B.rtb_Delay18_idx_0 =
    controller_pole_placement_DW.Delay18_DSTATE[0];

  // SignalConversion generated from: '<S25>/ SFunction ' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay15'
  //   Delay: '<S18>/Delay16'
  //   Delay: '<S18>/Delay17'
  //   Delay: '<S18>/Delay18'
  //   Delay: '<S18>/Delay19'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay24'
  //   Delay: '<S18>/Delay25'
  //   Delay: '<S18>/Delay26'
  //   Delay: '<S18>/Delay27'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   MATLAB Function: '<S18>/MATLAB Function'

  controller_pole_placement_B.TmpSignalConversionAtSFun_e[3] =
    controller_pole_placement_DW.Delay_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[6] =
    controller_pole_placement_DW.Delay1_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[9] =
    controller_pole_placement_DW.Delay2_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[12] =
    controller_pole_placement_DW.Delay3_DSTATE_j[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[15] =
    controller_pole_placement_DW.Delay4_DSTATE_e[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[18] =
    controller_pole_placement_DW.Delay5_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[21] =
    controller_pole_placement_DW.Delay6_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[24] =
    controller_pole_placement_DW.Delay7_DSTATE_o[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[27] =
    controller_pole_placement_DW.Delay8_DSTATE_n[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[30] =
    controller_pole_placement_DW.Delay9_DSTATE_i[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[33] =
    controller_pole_placement_DW.Delay10_DSTATE_f[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[36] =
    controller_pole_placement_DW.Delay11_DSTATE_k[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[39] =
    controller_pole_placement_DW.Delay12_DSTATE_n[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[42] =
    controller_pole_placement_DW.Delay13_DSTATE_g[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[45] =
    controller_pole_placement_DW.Delay14_DSTATE_g[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[48] =
    controller_pole_placement_DW.Delay15_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[51] =
    controller_pole_placement_DW.Delay20_DSTATE_h[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[54] =
    controller_pole_placement_DW.Delay21_DSTATE_d[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[57] =
    controller_pole_placement_DW.Delay22_DSTATE_h[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[60] =
    controller_pole_placement_DW.Delay23_DSTATE_p[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[63] =
    controller_pole_placement_DW.Delay24_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[66] =
    controller_pole_placement_DW.Delay25_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[69] =
    controller_pole_placement_DW.Delay26_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[72] =
    controller_pole_placement_DW.Delay27_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[75] =
    controller_pole_placement_DW.Delay16_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[78] =
    controller_pole_placement_DW.Delay17_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[81] =
    controller_pole_placement_DW.Delay18_DSTATE[0];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[84] =
    controller_pole_placement_DW.Delay19_DSTATE[0];

  // Delay: '<S18>/Delay'
  controller_pole_placement_B.rtb_Delay_l_idx_1 =
    controller_pole_placement_DW.Delay_DSTATE_p[1];

  // Delay: '<S18>/Delay1'
  controller_pole_placement_B.rtb_Delay1_n_idx_1 =
    controller_pole_placement_DW.Delay1_DSTATE_p[1];

  // Delay: '<S18>/Delay2'
  controller_pole_placement_B.rtb_Delay2_h_idx_1 =
    controller_pole_placement_DW.Delay2_DSTATE_p[1];

  // Delay: '<S18>/Delay3'
  controller_pole_placement_B.rtb_Delay3_p_idx_1 =
    controller_pole_placement_DW.Delay3_DSTATE_j[1];

  // Delay: '<S18>/Delay4'
  controller_pole_placement_B.rtb_Delay4_j_idx_1 =
    controller_pole_placement_DW.Delay4_DSTATE_e[1];

  // Delay: '<S18>/Delay5'
  controller_pole_placement_B.rtb_Delay5_e_idx_1 =
    controller_pole_placement_DW.Delay5_DSTATE_p[1];

  // Delay: '<S18>/Delay6'
  controller_pole_placement_B.rtb_Delay6_f_idx_1 =
    controller_pole_placement_DW.Delay6_DSTATE_p[1];

  // Delay: '<S18>/Delay7'
  controller_pole_placement_B.rtb_Delay7_i_idx_1 =
    controller_pole_placement_DW.Delay7_DSTATE_o[1];

  // Delay: '<S18>/Delay8'
  controller_pole_placement_B.rtb_Delay8_j_idx_1 =
    controller_pole_placement_DW.Delay8_DSTATE_n[1];

  // Delay: '<S18>/Delay9'
  controller_pole_placement_B.rtb_Delay9_j_idx_1 =
    controller_pole_placement_DW.Delay9_DSTATE_i[1];

  // Delay: '<S18>/Delay10'
  controller_pole_placement_B.rtb_Delay10_e_idx_1 =
    controller_pole_placement_DW.Delay10_DSTATE_f[1];

  // Delay: '<S18>/Delay11'
  controller_pole_placement_B.rtb_Delay11_n_idx_1 =
    controller_pole_placement_DW.Delay11_DSTATE_k[1];

  // Delay: '<S18>/Delay12'
  controller_pole_placement_B.rtb_Delay12_a_idx_1 =
    controller_pole_placement_DW.Delay12_DSTATE_n[1];

  // Delay: '<S18>/Delay13'
  controller_pole_placement_B.rtb_Delay13_h_idx_1 =
    controller_pole_placement_DW.Delay13_DSTATE_g[1];

  // Delay: '<S18>/Delay14'
  controller_pole_placement_B.rtb_Delay14_m_idx_1 =
    controller_pole_placement_DW.Delay14_DSTATE_g[1];

  // Delay: '<S18>/Delay15'
  controller_pole_placement_B.rtb_Delay15_idx_1 =
    controller_pole_placement_DW.Delay15_DSTATE[1];

  // Delay: '<S18>/Delay20'
  controller_pole_placement_B.rtb_Delay20_g_idx_1 =
    controller_pole_placement_DW.Delay20_DSTATE_h[1];

  // Delay: '<S18>/Delay21'
  controller_pole_placement_B.rtb_Delay21_e_idx_1 =
    controller_pole_placement_DW.Delay21_DSTATE_d[1];

  // Delay: '<S18>/Delay22'
  controller_pole_placement_B.rtb_Delay22_b_idx_1 =
    controller_pole_placement_DW.Delay22_DSTATE_h[1];

  // Delay: '<S18>/Delay23'
  controller_pole_placement_B.rtb_Delay23_g_idx_1 =
    controller_pole_placement_DW.Delay23_DSTATE_p[1];

  // Delay: '<S18>/Delay24'
  controller_pole_placement_B.rtb_Delay24_idx_1 =
    controller_pole_placement_DW.Delay24_DSTATE[1];

  // Delay: '<S18>/Delay25'
  controller_pole_placement_B.rtb_Delay25_idx_1 =
    controller_pole_placement_DW.Delay25_DSTATE[1];

  // Delay: '<S18>/Delay26'
  controller_pole_placement_B.rtb_Delay26_idx_1 =
    controller_pole_placement_DW.Delay26_DSTATE[1];

  // Delay: '<S18>/Delay27'
  controller_pole_placement_B.rtb_Delay27_idx_1 =
    controller_pole_placement_DW.Delay27_DSTATE[1];

  // Delay: '<S18>/Delay16'
  controller_pole_placement_B.rtb_Delay16_idx_1 =
    controller_pole_placement_DW.Delay16_DSTATE[1];

  // Delay: '<S18>/Delay17'
  controller_pole_placement_B.rtb_Delay17_idx_1 =
    controller_pole_placement_DW.Delay17_DSTATE[1];

  // Delay: '<S18>/Delay18'
  controller_pole_placement_B.rtb_Delay18_idx_1 =
    controller_pole_placement_DW.Delay18_DSTATE[1];

  // SignalConversion generated from: '<S25>/ SFunction ' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay15'
  //   Delay: '<S18>/Delay16'
  //   Delay: '<S18>/Delay17'
  //   Delay: '<S18>/Delay18'
  //   Delay: '<S18>/Delay19'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay24'
  //   Delay: '<S18>/Delay25'
  //   Delay: '<S18>/Delay26'
  //   Delay: '<S18>/Delay27'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   MATLAB Function: '<S18>/MATLAB Function'

  controller_pole_placement_B.TmpSignalConversionAtSFun_e[4] =
    controller_pole_placement_DW.Delay_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[7] =
    controller_pole_placement_DW.Delay1_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[10] =
    controller_pole_placement_DW.Delay2_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[13] =
    controller_pole_placement_DW.Delay3_DSTATE_j[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[16] =
    controller_pole_placement_DW.Delay4_DSTATE_e[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[19] =
    controller_pole_placement_DW.Delay5_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[22] =
    controller_pole_placement_DW.Delay6_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[25] =
    controller_pole_placement_DW.Delay7_DSTATE_o[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[28] =
    controller_pole_placement_DW.Delay8_DSTATE_n[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[31] =
    controller_pole_placement_DW.Delay9_DSTATE_i[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[34] =
    controller_pole_placement_DW.Delay10_DSTATE_f[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[37] =
    controller_pole_placement_DW.Delay11_DSTATE_k[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[40] =
    controller_pole_placement_DW.Delay12_DSTATE_n[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[43] =
    controller_pole_placement_DW.Delay13_DSTATE_g[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[46] =
    controller_pole_placement_DW.Delay14_DSTATE_g[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[49] =
    controller_pole_placement_DW.Delay15_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[52] =
    controller_pole_placement_DW.Delay20_DSTATE_h[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[55] =
    controller_pole_placement_DW.Delay21_DSTATE_d[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[58] =
    controller_pole_placement_DW.Delay22_DSTATE_h[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[61] =
    controller_pole_placement_DW.Delay23_DSTATE_p[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[64] =
    controller_pole_placement_DW.Delay24_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[67] =
    controller_pole_placement_DW.Delay25_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[70] =
    controller_pole_placement_DW.Delay26_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[73] =
    controller_pole_placement_DW.Delay27_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[76] =
    controller_pole_placement_DW.Delay16_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[79] =
    controller_pole_placement_DW.Delay17_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[82] =
    controller_pole_placement_DW.Delay18_DSTATE[1];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[85] =
    controller_pole_placement_DW.Delay19_DSTATE[1];

  // Delay: '<S18>/Delay'
  controller_pole_placement_B.Delay_DSTATE_p =
    controller_pole_placement_DW.Delay_DSTATE_p[2];

  // Delay: '<S18>/Delay1'
  controller_pole_placement_B.Delay1_DSTATE_p =
    controller_pole_placement_DW.Delay1_DSTATE_p[2];

  // Delay: '<S18>/Delay2'
  controller_pole_placement_B.Delay2_DSTATE_p =
    controller_pole_placement_DW.Delay2_DSTATE_p[2];

  // Delay: '<S18>/Delay3'
  controller_pole_placement_B.Delay3_DSTATE_j =
    controller_pole_placement_DW.Delay3_DSTATE_j[2];

  // Delay: '<S18>/Delay4'
  controller_pole_placement_B.Delay4_DSTATE_e =
    controller_pole_placement_DW.Delay4_DSTATE_e[2];

  // Delay: '<S18>/Delay5'
  controller_pole_placement_B.Delay5_DSTATE_p =
    controller_pole_placement_DW.Delay5_DSTATE_p[2];

  // Delay: '<S18>/Delay6'
  controller_pole_placement_B.Delay6_DSTATE_p =
    controller_pole_placement_DW.Delay6_DSTATE_p[2];

  // Delay: '<S18>/Delay7'
  controller_pole_placement_B.Delay7_DSTATE_o =
    controller_pole_placement_DW.Delay7_DSTATE_o[2];

  // Delay: '<S18>/Delay8'
  controller_pole_placement_B.Delay8_DSTATE_n =
    controller_pole_placement_DW.Delay8_DSTATE_n[2];

  // Delay: '<S18>/Delay9'
  controller_pole_placement_B.Delay9_DSTATE_i =
    controller_pole_placement_DW.Delay9_DSTATE_i[2];

  // Delay: '<S18>/Delay10'
  controller_pole_placement_B.Delay10_DSTATE_f =
    controller_pole_placement_DW.Delay10_DSTATE_f[2];

  // Delay: '<S18>/Delay11'
  controller_pole_placement_B.Delay11_DSTATE_k =
    controller_pole_placement_DW.Delay11_DSTATE_k[2];

  // Delay: '<S18>/Delay12'
  controller_pole_placement_B.Delay12_DSTATE_n =
    controller_pole_placement_DW.Delay12_DSTATE_n[2];

  // Delay: '<S18>/Delay13'
  controller_pole_placement_B.Delay13_DSTATE_g =
    controller_pole_placement_DW.Delay13_DSTATE_g[2];

  // Delay: '<S18>/Delay14'
  controller_pole_placement_B.Delay14_DSTATE_g =
    controller_pole_placement_DW.Delay14_DSTATE_g[2];

  // Delay: '<S18>/Delay15'
  controller_pole_placement_B.Delay15_DSTATE =
    controller_pole_placement_DW.Delay15_DSTATE[2];

  // Delay: '<S18>/Delay20'
  controller_pole_placement_B.Delay20_DSTATE_h =
    controller_pole_placement_DW.Delay20_DSTATE_h[2];

  // Delay: '<S18>/Delay21'
  controller_pole_placement_B.Delay21_DSTATE_d =
    controller_pole_placement_DW.Delay21_DSTATE_d[2];

  // Delay: '<S18>/Delay22'
  controller_pole_placement_B.Delay22_DSTATE_h =
    controller_pole_placement_DW.Delay22_DSTATE_h[2];

  // Delay: '<S18>/Delay23'
  controller_pole_placement_B.Delay23_DSTATE_p =
    controller_pole_placement_DW.Delay23_DSTATE_p[2];

  // Delay: '<S18>/Delay24'
  controller_pole_placement_B.Delay24_DSTATE =
    controller_pole_placement_DW.Delay24_DSTATE[2];

  // Delay: '<S18>/Delay25'
  controller_pole_placement_B.Delay25_DSTATE =
    controller_pole_placement_DW.Delay25_DSTATE[2];

  // Delay: '<S18>/Delay26'
  controller_pole_placement_B.Delay26_DSTATE =
    controller_pole_placement_DW.Delay26_DSTATE[2];

  // Delay: '<S18>/Delay27'
  controller_pole_placement_B.Delay27_DSTATE =
    controller_pole_placement_DW.Delay27_DSTATE[2];

  // Delay: '<S18>/Delay16'
  controller_pole_placement_B.Delay16_DSTATE =
    controller_pole_placement_DW.Delay16_DSTATE[2];

  // Delay: '<S18>/Delay17'
  controller_pole_placement_B.Delay17_DSTATE =
    controller_pole_placement_DW.Delay17_DSTATE[2];

  // Delay: '<S18>/Delay18'
  controller_pole_placement_B.Delay18_DSTATE =
    controller_pole_placement_DW.Delay18_DSTATE[2];

  // SignalConversion generated from: '<S25>/ SFunction ' incorporates:
  //   Delay: '<S18>/Delay'
  //   Delay: '<S18>/Delay1'
  //   Delay: '<S18>/Delay10'
  //   Delay: '<S18>/Delay11'
  //   Delay: '<S18>/Delay12'
  //   Delay: '<S18>/Delay13'
  //   Delay: '<S18>/Delay14'
  //   Delay: '<S18>/Delay15'
  //   Delay: '<S18>/Delay16'
  //   Delay: '<S18>/Delay17'
  //   Delay: '<S18>/Delay18'
  //   Delay: '<S18>/Delay19'
  //   Delay: '<S18>/Delay2'
  //   Delay: '<S18>/Delay20'
  //   Delay: '<S18>/Delay21'
  //   Delay: '<S18>/Delay22'
  //   Delay: '<S18>/Delay23'
  //   Delay: '<S18>/Delay24'
  //   Delay: '<S18>/Delay25'
  //   Delay: '<S18>/Delay26'
  //   Delay: '<S18>/Delay27'
  //   Delay: '<S18>/Delay3'
  //   Delay: '<S18>/Delay4'
  //   Delay: '<S18>/Delay5'
  //   Delay: '<S18>/Delay6'
  //   Delay: '<S18>/Delay7'
  //   Delay: '<S18>/Delay8'
  //   Delay: '<S18>/Delay9'
  //   MATLAB Function: '<S18>/MATLAB Function'

  controller_pole_placement_B.TmpSignalConversionAtSFun_e[5] =
    controller_pole_placement_DW.Delay_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[8] =
    controller_pole_placement_DW.Delay1_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[11] =
    controller_pole_placement_DW.Delay2_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[14] =
    controller_pole_placement_DW.Delay3_DSTATE_j[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[17] =
    controller_pole_placement_DW.Delay4_DSTATE_e[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[20] =
    controller_pole_placement_DW.Delay5_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[23] =
    controller_pole_placement_DW.Delay6_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[26] =
    controller_pole_placement_DW.Delay7_DSTATE_o[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[29] =
    controller_pole_placement_DW.Delay8_DSTATE_n[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[32] =
    controller_pole_placement_DW.Delay9_DSTATE_i[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[35] =
    controller_pole_placement_DW.Delay10_DSTATE_f[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[38] =
    controller_pole_placement_DW.Delay11_DSTATE_k[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[41] =
    controller_pole_placement_DW.Delay12_DSTATE_n[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[44] =
    controller_pole_placement_DW.Delay13_DSTATE_g[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[47] =
    controller_pole_placement_DW.Delay14_DSTATE_g[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[50] =
    controller_pole_placement_DW.Delay15_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[53] =
    controller_pole_placement_DW.Delay20_DSTATE_h[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[56] =
    controller_pole_placement_DW.Delay21_DSTATE_d[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[59] =
    controller_pole_placement_DW.Delay22_DSTATE_h[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[62] =
    controller_pole_placement_DW.Delay23_DSTATE_p[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[65] =
    controller_pole_placement_DW.Delay24_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[68] =
    controller_pole_placement_DW.Delay25_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[71] =
    controller_pole_placement_DW.Delay26_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[74] =
    controller_pole_placement_DW.Delay27_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[77] =
    controller_pole_placement_DW.Delay16_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[80] =
    controller_pole_placement_DW.Delay17_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[83] =
    controller_pole_placement_DW.Delay18_DSTATE[2];
  controller_pole_placement_B.TmpSignalConversionAtSFun_e[86] =
    controller_pole_placement_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S18>/MATLAB Function'
  for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 < 29;
       controller_pole_placement_B.r2++) {
    i = (controller_pole_placement_B.r2 + 1) * 3;
    controller_pole_placement_B.ph_meas =
      controller_pole_placement_B.TmpSignalConversionAtSFun_e[i - 3];
    controller_pole_placement_B.Delay2_DSTATE =
      controller_pole_placement_B.ph_meas * controller_pole_placement_B.ph_meas;
    controller_pole_placement_B.ph_meas =
      controller_pole_placement_B.TmpSignalConversionAtSFun_e[i - 2];
    controller_pole_placement_B.Delay2_DSTATE +=
      controller_pole_placement_B.ph_meas * controller_pole_placement_B.ph_meas;
    controller_pole_placement_B.ph_meas =
      controller_pole_placement_B.TmpSignalConversionAtSFun_e[i - 1];
    controller_pole_placement_B.b_norm[controller_pole_placement_B.r2] = sqrt
      (controller_pole_placement_B.ph_meas * controller_pole_placement_B.ph_meas
       + controller_pole_placement_B.Delay2_DSTATE);
    controller_pole_placement_B.b_norm[controller_pole_placement_B.r2 + 29] =
      static_cast<real_T>(controller_pole_placement_B.r2) + 1.0;
  }

  for (i = 0; i < 28; i++) {
    controller_pole_placement_B.b = 27 - i;
    for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <=
         controller_pole_placement_B.b; controller_pole_placement_B.r1++) {
      controller_pole_placement_B.ph_meas =
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1];
      controller_pole_placement_B.a21 =
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 1];
      if (controller_pole_placement_B.ph_meas > controller_pole_placement_B.a21)
      {
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1] =
          controller_pole_placement_B.a21;
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 1] =
          controller_pole_placement_B.ph_meas;
        controller_pole_placement_B.a21 =
          controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 29];
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 29] =
          controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 30];
        controller_pole_placement_B.b_norm[controller_pole_placement_B.r1 + 30] =
          controller_pole_placement_B.a21;
      }
    }
  }

  controller_pole_placement_B.ph_meas = controller_pole_placement_B.b_norm[41] *
    3.0 - 2.0;
  controller_pole_placement_B.Delay2_DSTATE =
    controller_pole_placement_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (controller_pole_placement_B.ph_meas) - 1];
  controller_pole_placement_B.y_idx_0 =
    controller_pole_placement_B.Delay2_DSTATE;

  // Sum: '<S22>/Sum23' incorporates:
  //   Delay: '<S22>/Delay'
  //   Delay: '<S22>/Delay1'
  //   Delay: '<S22>/Delay10'
  //   Delay: '<S22>/Delay11'
  //   Delay: '<S22>/Delay12'
  //   Delay: '<S22>/Delay13'
  //   Delay: '<S22>/Delay14'
  //   Delay: '<S22>/Delay2'
  //   Delay: '<S22>/Delay20'
  //   Delay: '<S22>/Delay21'
  //   Delay: '<S22>/Delay22'
  //   Delay: '<S22>/Delay23'
  //   Delay: '<S22>/Delay3'
  //   Delay: '<S22>/Delay4'
  //   Delay: '<S22>/Delay5'
  //   Delay: '<S22>/Delay6'
  //   Delay: '<S22>/Delay7'
  //   Delay: '<S22>/Delay8'
  //   Delay: '<S22>/Delay9'
  //   Sum: '<S22>/Sum'
  //   Sum: '<S22>/Sum1'
  //   Sum: '<S22>/Sum10'
  //   Sum: '<S22>/Sum11'
  //   Sum: '<S22>/Sum12'
  //   Sum: '<S22>/Sum13'
  //   Sum: '<S22>/Sum14'
  //   Sum: '<S22>/Sum2'
  //   Sum: '<S22>/Sum20'
  //   Sum: '<S22>/Sum21'
  //   Sum: '<S22>/Sum22'
  //   Sum: '<S22>/Sum3'
  //   Sum: '<S22>/Sum4'
  //   Sum: '<S22>/Sum5'
  //   Sum: '<S22>/Sum6'
  //   Sum: '<S22>/Sum7'
  //   Sum: '<S22>/Sum8'
  //   Sum: '<S22>/Sum9'

  controller_pole_placement_B.Sum23_g =
    ((((((((((((((((((controller_pole_placement_DW.Delay_DSTATE[0] +
                      controller_pole_placement_B.Delay2_DSTATE) +
                     controller_pole_placement_DW.Delay1_DSTATE[0]) +
                    controller_pole_placement_DW.Delay2_DSTATE_i[0]) +
                   controller_pole_placement_DW.Delay3_DSTATE_d[0]) +
                  controller_pole_placement_DW.Delay4_DSTATE[0]) +
                 controller_pole_placement_DW.Delay5_DSTATE[0]) +
                controller_pole_placement_DW.Delay6_DSTATE[0]) +
               controller_pole_placement_DW.Delay7_DSTATE[0]) +
              controller_pole_placement_DW.Delay8_DSTATE[0]) +
             controller_pole_placement_DW.Delay9_DSTATE[0]) +
            controller_pole_placement_DW.Delay10_DSTATE[0]) +
           controller_pole_placement_DW.Delay11_DSTATE[0]) +
          controller_pole_placement_DW.Delay12_DSTATE[0]) +
         controller_pole_placement_DW.Delay13_DSTATE[0]) +
        controller_pole_placement_DW.Delay14_DSTATE[0]) +
       controller_pole_placement_DW.Delay20_DSTATE[0]) +
      controller_pole_placement_DW.Delay21_DSTATE[0]) +
     controller_pole_placement_DW.Delay22_DSTATE[0]) +
    controller_pole_placement_DW.Delay23_DSTATE[0];
  controller_pole_placement_B.Sum23[0] = controller_pole_placement_B.Sum23_g;

  // Sum: '<S22>/Sum24' incorporates:
  //   Sum: '<S22>/Sum23'

  controller_pole_placement_B.Sum24[0] = controller_pole_placement_B.Sum23_g;

  // MATLAB Function: '<S11>/RP_computation' incorporates:
  //   Gain: '<S22>/Gain'
  //   Sum: '<S22>/Sum23'
  //   Sum: '<S22>/Sum24'

  controller_pole_placement_B.u_vect[0] =
    -(controller_pole_placement_P.Gain_Gain_b *
      controller_pole_placement_B.Sum23_g);

  // MATLAB Function: '<S18>/MATLAB Function'
  controller_pole_placement_B.Delay2_DSTATE =
    controller_pole_placement_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (controller_pole_placement_B.ph_meas + 1.0) - 1];
  controller_pole_placement_B.y_idx_1 =
    controller_pole_placement_B.Delay2_DSTATE;

  // Sum: '<S22>/Sum23' incorporates:
  //   Delay: '<S22>/Delay'
  //   Delay: '<S22>/Delay1'
  //   Delay: '<S22>/Delay10'
  //   Delay: '<S22>/Delay11'
  //   Delay: '<S22>/Delay12'
  //   Delay: '<S22>/Delay13'
  //   Delay: '<S22>/Delay14'
  //   Delay: '<S22>/Delay2'
  //   Delay: '<S22>/Delay20'
  //   Delay: '<S22>/Delay21'
  //   Delay: '<S22>/Delay22'
  //   Delay: '<S22>/Delay23'
  //   Delay: '<S22>/Delay3'
  //   Delay: '<S22>/Delay4'
  //   Delay: '<S22>/Delay5'
  //   Delay: '<S22>/Delay6'
  //   Delay: '<S22>/Delay7'
  //   Delay: '<S22>/Delay8'
  //   Delay: '<S22>/Delay9'
  //   Sum: '<S22>/Sum'
  //   Sum: '<S22>/Sum1'
  //   Sum: '<S22>/Sum10'
  //   Sum: '<S22>/Sum11'
  //   Sum: '<S22>/Sum12'
  //   Sum: '<S22>/Sum13'
  //   Sum: '<S22>/Sum14'
  //   Sum: '<S22>/Sum2'
  //   Sum: '<S22>/Sum20'
  //   Sum: '<S22>/Sum21'
  //   Sum: '<S22>/Sum22'
  //   Sum: '<S22>/Sum3'
  //   Sum: '<S22>/Sum4'
  //   Sum: '<S22>/Sum5'
  //   Sum: '<S22>/Sum6'
  //   Sum: '<S22>/Sum7'
  //   Sum: '<S22>/Sum8'
  //   Sum: '<S22>/Sum9'

  controller_pole_placement_B.Sum23_g =
    ((((((((((((((((((controller_pole_placement_DW.Delay_DSTATE[1] +
                      controller_pole_placement_B.Delay2_DSTATE) +
                     controller_pole_placement_DW.Delay1_DSTATE[1]) +
                    controller_pole_placement_DW.Delay2_DSTATE_i[1]) +
                   controller_pole_placement_DW.Delay3_DSTATE_d[1]) +
                  controller_pole_placement_DW.Delay4_DSTATE[1]) +
                 controller_pole_placement_DW.Delay5_DSTATE[1]) +
                controller_pole_placement_DW.Delay6_DSTATE[1]) +
               controller_pole_placement_DW.Delay7_DSTATE[1]) +
              controller_pole_placement_DW.Delay8_DSTATE[1]) +
             controller_pole_placement_DW.Delay9_DSTATE[1]) +
            controller_pole_placement_DW.Delay10_DSTATE[1]) +
           controller_pole_placement_DW.Delay11_DSTATE[1]) +
          controller_pole_placement_DW.Delay12_DSTATE[1]) +
         controller_pole_placement_DW.Delay13_DSTATE[1]) +
        controller_pole_placement_DW.Delay14_DSTATE[1]) +
       controller_pole_placement_DW.Delay20_DSTATE[1]) +
      controller_pole_placement_DW.Delay21_DSTATE[1]) +
     controller_pole_placement_DW.Delay22_DSTATE[1]) +
    controller_pole_placement_DW.Delay23_DSTATE[1];
  controller_pole_placement_B.Sum23[1] = controller_pole_placement_B.Sum23_g;

  // Sum: '<S22>/Sum24' incorporates:
  //   Sum: '<S22>/Sum23'

  controller_pole_placement_B.Sum24[1] = controller_pole_placement_B.Sum23_g;

  // MATLAB Function: '<S11>/RP_computation' incorporates:
  //   Gain: '<S22>/Gain'
  //   Sum: '<S22>/Sum23'
  //   Sum: '<S22>/Sum24'

  controller_pole_placement_B.u_vect[1] =
    -(controller_pole_placement_P.Gain_Gain_b *
      controller_pole_placement_B.Sum23_g);

  // MATLAB Function: '<S18>/MATLAB Function'
  controller_pole_placement_B.Delay2_DSTATE =
    controller_pole_placement_B.TmpSignalConversionAtSFun_e[static_cast<int32_T>
    (controller_pole_placement_B.ph_meas + 2.0) - 1];

  // Sum: '<S22>/Sum23' incorporates:
  //   Delay: '<S22>/Delay'
  //   Delay: '<S22>/Delay1'
  //   Delay: '<S22>/Delay10'
  //   Delay: '<S22>/Delay11'
  //   Delay: '<S22>/Delay12'
  //   Delay: '<S22>/Delay13'
  //   Delay: '<S22>/Delay14'
  //   Delay: '<S22>/Delay2'
  //   Delay: '<S22>/Delay20'
  //   Delay: '<S22>/Delay21'
  //   Delay: '<S22>/Delay22'
  //   Delay: '<S22>/Delay23'
  //   Delay: '<S22>/Delay3'
  //   Delay: '<S22>/Delay4'
  //   Delay: '<S22>/Delay5'
  //   Delay: '<S22>/Delay6'
  //   Delay: '<S22>/Delay7'
  //   Delay: '<S22>/Delay8'
  //   Delay: '<S22>/Delay9'
  //   Sum: '<S22>/Sum'
  //   Sum: '<S22>/Sum1'
  //   Sum: '<S22>/Sum10'
  //   Sum: '<S22>/Sum11'
  //   Sum: '<S22>/Sum12'
  //   Sum: '<S22>/Sum13'
  //   Sum: '<S22>/Sum14'
  //   Sum: '<S22>/Sum2'
  //   Sum: '<S22>/Sum20'
  //   Sum: '<S22>/Sum21'
  //   Sum: '<S22>/Sum22'
  //   Sum: '<S22>/Sum3'
  //   Sum: '<S22>/Sum4'
  //   Sum: '<S22>/Sum5'
  //   Sum: '<S22>/Sum6'
  //   Sum: '<S22>/Sum7'
  //   Sum: '<S22>/Sum8'
  //   Sum: '<S22>/Sum9'

  controller_pole_placement_B.Sum23_g =
    ((((((((((((((((((controller_pole_placement_DW.Delay_DSTATE[2] +
                      controller_pole_placement_B.Delay2_DSTATE) +
                     controller_pole_placement_DW.Delay1_DSTATE[2]) +
                    controller_pole_placement_DW.Delay2_DSTATE_i[2]) +
                   controller_pole_placement_DW.Delay3_DSTATE_d[2]) +
                  controller_pole_placement_DW.Delay4_DSTATE[2]) +
                 controller_pole_placement_DW.Delay5_DSTATE[2]) +
                controller_pole_placement_DW.Delay6_DSTATE[2]) +
               controller_pole_placement_DW.Delay7_DSTATE[2]) +
              controller_pole_placement_DW.Delay8_DSTATE[2]) +
             controller_pole_placement_DW.Delay9_DSTATE[2]) +
            controller_pole_placement_DW.Delay10_DSTATE[2]) +
           controller_pole_placement_DW.Delay11_DSTATE[2]) +
          controller_pole_placement_DW.Delay12_DSTATE[2]) +
         controller_pole_placement_DW.Delay13_DSTATE[2]) +
        controller_pole_placement_DW.Delay14_DSTATE[2]) +
       controller_pole_placement_DW.Delay20_DSTATE[2]) +
      controller_pole_placement_DW.Delay21_DSTATE[2]) +
     controller_pole_placement_DW.Delay22_DSTATE[2]) +
    controller_pole_placement_DW.Delay23_DSTATE[2];
  controller_pole_placement_B.Sum23[2] = controller_pole_placement_B.Sum23_g;

  // Sum: '<S22>/Sum24' incorporates:
  //   Sum: '<S22>/Sum23'

  controller_pole_placement_B.Sum24[2] = controller_pole_placement_B.Sum23_g;

  // MATLAB Function: '<S11>/RP_computation' incorporates:
  //   Gain: '<S22>/Gain'
  //   Sum: '<S22>/Sum23'
  //   Sum: '<S22>/Sum24'

  controller_pole_placement_B.u_vect[2] =
    -(controller_pole_placement_P.Gain_Gain_b *
      controller_pole_placement_B.Sum23_g);
  controller_pole_placement_B.ph_meas = rt_atan2d_snf
    (controller_pole_placement_B.u_vect[1], controller_pole_placement_B.u_vect[2]);
  controller_pole_placement_B.temp[0] = controller_pole_placement_B.ph_meas;
  controller_pole_placement_B.Sum23_g = rt_atan2d_snf
    (-controller_pole_placement_B.u_vect[0], controller_pole_placement_B.u_vect
     [1] * sin(controller_pole_placement_B.ph_meas) +
     controller_pole_placement_B.u_vect[2] * cos
     (controller_pole_placement_B.ph_meas));
  controller_pole_placement_B.temp[1] = controller_pole_placement_B.Sum23_g;

  // MATLAB Function: '<S20>/EKF_RP' incorporates:
  //   Delay: '<S20>/Delay2'
  //   Memory: '<S20>/Memory2'
  //   Memory: '<S20>/Memory3'

  if (controller_pole_placement_B.DigitalClock1 -
      controller_pole_placement_DW.Memory2_PreviousInput >=
      controller_pole_placement_P.Ts_EKF_meas) {
    controller_pole_placement_DW.Memory2_PreviousInput =
      controller_pole_placement_B.DigitalClock1;
    memcpy(&controller_pole_placement_B.Pt1[0],
           &controller_pole_placement_DW.Memory3_PreviousInput[0], 25U * sizeof
           (real_T));
    controller_pole_placement_B.wq1 =
      controller_pole_placement_DW.Delay2_DSTATE_l[1];
    controller_pole_placement_B.wr1 =
      controller_pole_placement_DW.Delay2_DSTATE_l[2];
    for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 < 5;
         controller_pole_placement_B.r2++) {
      controller_pole_placement_B.xt[controller_pole_placement_B.r2] = 0.0;
    }

    memset(&controller_pole_placement_B.Pt[0], 0, 25U * sizeof(real_T));
    controller_pole_placement_B.b = static_cast<int32_T>(floor
      (controller_pole_placement_P.Ts_EKF_meas /
       controller_pole_placement_P.Ts_EKF_integr));
    for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 <
         controller_pole_placement_B.b; controller_pole_placement_B.r2++) {
      controller_pole_placement_B.cph = cos
        (controller_pole_placement_DW.Memory4_PreviousInput[0]);
      controller_pole_placement_B.cth = cos
        (controller_pole_placement_DW.Memory4_PreviousInput[1]);
      controller_pole_placement_B.sph = sin
        (controller_pole_placement_DW.Memory4_PreviousInput[0]);
      controller_pole_placement_B.tth = sin
        (controller_pole_placement_DW.Memory4_PreviousInput[1]) /
        controller_pole_placement_B.cth;
      controller_pole_placement_B.dv[0] = 1.0;
      controller_pole_placement_B.a21 = controller_pole_placement_B.sph *
        controller_pole_placement_B.tth;
      controller_pole_placement_B.dv[5] = controller_pole_placement_B.a21;
      controller_pole_placement_B.d = controller_pole_placement_B.cph *
        controller_pole_placement_B.tth;
      controller_pole_placement_B.dv[10] = controller_pole_placement_B.d;
      controller_pole_placement_B.dv[15] = 0.0;
      controller_pole_placement_B.dv[20] = 0.0;
      controller_pole_placement_B.dv[25] = 0.0;
      controller_pole_placement_B.dv[1] = 0.0;
      controller_pole_placement_B.dv[6] = controller_pole_placement_B.cph;
      controller_pole_placement_B.dv[11] = -controller_pole_placement_B.sph;
      controller_pole_placement_B.dv[16] = 0.0;
      controller_pole_placement_B.dv[21] = 0.0;
      controller_pole_placement_B.dv[26] = 0.0;
      for (i = 0; i < 6; i++) {
        controller_pole_placement_B.dv[5 * i + 2] = 0.0;
        controller_pole_placement_B.dv[5 * i + 3] = 0.0;
        controller_pole_placement_B.dv[5 * i + 4] = 0.0;
      }

      controller_pole_placement_B.dv3[0] =
        controller_pole_placement_DW.Delay2_DSTATE_l[0] -
        controller_pole_placement_DW.Memory4_PreviousInput[2];
      controller_pole_placement_B.Pt_f = controller_pole_placement_B.wq1 -
        controller_pole_placement_DW.Memory4_PreviousInput[3];
      controller_pole_placement_B.dv3[1] = controller_pole_placement_B.Pt_f;
      controller_pole_placement_B.d1 = controller_pole_placement_B.wr1 -
        controller_pole_placement_DW.Memory4_PreviousInput[4];
      controller_pole_placement_B.dv3[2] = controller_pole_placement_B.d1;
      controller_pole_placement_B.dv3[3] =
        controller_pole_placement_DW.Memory4_PreviousInput[2];
      controller_pole_placement_B.dv3[4] =
        controller_pole_placement_DW.Memory4_PreviousInput[3];
      controller_pole_placement_B.dv3[5] =
        controller_pole_placement_DW.Memory4_PreviousInput[4];
      controller_pole_placement_B.Pt[0] = controller_pole_placement_B.d *
        controller_pole_placement_B.Pt_f - controller_pole_placement_B.a21 *
        controller_pole_placement_B.d1;
      controller_pole_placement_B.a21 = controller_pole_placement_B.d1 *
        controller_pole_placement_B.cph;
      controller_pole_placement_B.Pt[5] = (controller_pole_placement_B.Pt_f *
        controller_pole_placement_B.sph + controller_pole_placement_B.a21) /
        (controller_pole_placement_B.cth * controller_pole_placement_B.cth);
      controller_pole_placement_B.Pt[10] = -1.0;
      controller_pole_placement_B.Pt[15] = -controller_pole_placement_B.sph *
        controller_pole_placement_B.tth;
      controller_pole_placement_B.Pt[20] = -controller_pole_placement_B.cph *
        controller_pole_placement_B.tth;
      controller_pole_placement_B.Pt[1] = controller_pole_placement_B.Pt_f *
        -controller_pole_placement_B.sph - controller_pole_placement_B.a21;
      controller_pole_placement_B.Pt[6] = 0.0;
      controller_pole_placement_B.Pt[11] = 0.0;
      controller_pole_placement_B.Pt[16] = -controller_pole_placement_B.cph;
      controller_pole_placement_B.Pt[21] = controller_pole_placement_B.sph;
      for (i = 0; i < 5; i++) {
        controller_pole_placement_B.a21 = 0.0;
        for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
             6; controller_pole_placement_B.r1++) {
          controller_pole_placement_B.a21 += controller_pole_placement_B.dv[5 *
            controller_pole_placement_B.r1 + i] *
            controller_pole_placement_B.dv3[controller_pole_placement_B.r1];
        }

        controller_pole_placement_B.xt[i] =
          controller_pole_placement_P.Ts_EKF_integr *
          controller_pole_placement_B.a21 +
          controller_pole_placement_DW.Memory4_PreviousInput[i];
        controller_pole_placement_B.Pt[5 * i + 2] = 0.0;
        controller_pole_placement_B.Pt[5 * i + 3] = 0.0;
        controller_pole_placement_B.Pt[5 * i + 4] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
             5; controller_pole_placement_B.r1++) {
          controller_pole_placement_B.a21 = 0.0;
          controller_pole_placement_B.tth = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i;
            controller_pole_placement_B.a21 += controller_pole_placement_B.Pt1[5
              * controller_pole_placement_B.r1 + Pt1_tmp] *
              controller_pole_placement_B.Pt[At1_tmp];
            controller_pole_placement_B.tth += controller_pole_placement_B.Pt[5 *
              Pt1_tmp + controller_pole_placement_B.r1] *
              controller_pole_placement_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * controller_pole_placement_B.r1 + i;
          controller_pole_placement_B.Pt1_m[Pt1_tmp] =
            controller_pole_placement_B.tth;
          controller_pole_placement_B.At1[Pt1_tmp] =
            controller_pole_placement_B.a21;
        }
      }

      for (i = 0; i < 25; i++) {
        controller_pole_placement_B.Pt[i] = ((controller_pole_placement_B.At1[i]
          + controller_pole_placement_B.Pt1_m[i]) +
          controller_pole_placement_P.Q_phth[i]) *
          controller_pole_placement_P.Ts_EKF_integr +
          controller_pole_placement_B.Pt1[i];
      }

      for (i = 0; i < 5; i++) {
        controller_pole_placement_DW.Memory4_PreviousInput[i] =
          controller_pole_placement_B.xt[i];
      }

      memcpy(&controller_pole_placement_B.Pt1[0],
             &controller_pole_placement_B.Pt[0], 25U * sizeof(real_T));
    }

    for (i = 0; i < 10; i++) {
      controller_pole_placement_B.Lk[i] = c[i];
    }

    for (i = 0; i < 2; i++) {
      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           5; controller_pole_placement_B.r1++) {
        controller_pole_placement_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_pole_placement_B.a21 += controller_pole_placement_B.Pt[5 *
            Pt1_tmp + controller_pole_placement_B.r1] *
            controller_pole_placement_B.Lk[5 * i + Pt1_tmp];
        }

        controller_pole_placement_B.B[controller_pole_placement_B.r1 + 5 * i] =
          controller_pole_placement_B.a21;
      }
    }

    for (i = 0; i < 10; i++) {
      controller_pole_placement_B.A_tmp_c[i] = b_b[i];
    }

    for (i = 0; i < 2; i++) {
      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           5; controller_pole_placement_B.r1++) {
        controller_pole_placement_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_pole_placement_B.a21 += static_cast<real_T>
            (controller_pole_placement_B.A_tmp_c[(Pt1_tmp << 1) + i]) *
            controller_pole_placement_B.Pt[5 * controller_pole_placement_B.r1 +
            Pt1_tmp];
        }

        controller_pole_placement_B.A_tmp[i + (controller_pole_placement_B.r1 <<
          1)] = controller_pole_placement_B.a21;
      }

      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           2; controller_pole_placement_B.r1++) {
        controller_pole_placement_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_pole_placement_B.a21 += controller_pole_placement_B.A_tmp
            [(Pt1_tmp << 1) + i] * controller_pole_placement_B.Lk[5 *
            controller_pole_placement_B.r1 + Pt1_tmp];
        }

        controller_pole_placement_B.r2 = (controller_pole_placement_B.r1 << 1) +
          i;
        controller_pole_placement_B.minval[controller_pole_placement_B.r2] =
          controller_pole_placement_P.R_phth[controller_pole_placement_B.r2] +
          controller_pole_placement_B.a21;
      }
    }

    if (fabs(controller_pole_placement_B.minval[1]) > fabs
        (controller_pole_placement_B.minval[0])) {
      controller_pole_placement_B.r1 = 1;
      controller_pole_placement_B.r2 = 0;
    } else {
      controller_pole_placement_B.r1 = 0;
      controller_pole_placement_B.r2 = 1;
    }

    controller_pole_placement_B.a21 =
      controller_pole_placement_B.minval[controller_pole_placement_B.r2] /
      controller_pole_placement_B.minval[controller_pole_placement_B.r1];
    controller_pole_placement_B.tth =
      controller_pole_placement_B.minval[controller_pole_placement_B.r1 + 2];
    controller_pole_placement_B.wq1 =
      controller_pole_placement_B.minval[controller_pole_placement_B.r2 + 2] -
      controller_pole_placement_B.tth * controller_pole_placement_B.a21;
    for (i = 0; i < 5; i++) {
      Pt1_tmp = 5 * controller_pole_placement_B.r1 + i;
      controller_pole_placement_B.Lk[Pt1_tmp] = controller_pole_placement_B.B[i]
        / controller_pole_placement_B.minval[controller_pole_placement_B.r1];
      controller_pole_placement_B.b = 5 * controller_pole_placement_B.r2 + i;
      controller_pole_placement_B.Lk[controller_pole_placement_B.b] =
        (controller_pole_placement_B.B[i + 5] -
         controller_pole_placement_B.Lk[Pt1_tmp] *
         controller_pole_placement_B.tth) / controller_pole_placement_B.wq1;
      controller_pole_placement_B.Lk[Pt1_tmp] -=
        controller_pole_placement_B.Lk[controller_pole_placement_B.b] *
        controller_pole_placement_B.a21;
    }

    for (i = 0; i < 2; i++) {
      controller_pole_placement_B.a21 = 0.0;
      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           5; controller_pole_placement_B.r1++) {
        controller_pole_placement_B.a21 += static_cast<real_T>
          (controller_pole_placement_B.A_tmp_c[(controller_pole_placement_B.r1 <<
            1) + i]) *
          controller_pole_placement_B.xt[controller_pole_placement_B.r1];
      }

      controller_pole_placement_B.temp_p[i] = controller_pole_placement_B.temp[i]
        - controller_pole_placement_B.a21;
    }

    controller_pole_placement_B.a21 = controller_pole_placement_B.temp_p[1];
    controller_pole_placement_B.tth = controller_pole_placement_B.temp_p[0];
    for (i = 0; i < 5; i++) {
      controller_pole_placement_DW.Memory4_PreviousInput[i] =
        (controller_pole_placement_B.Lk[i + 5] * controller_pole_placement_B.a21
         + controller_pole_placement_B.Lk[i] * controller_pole_placement_B.tth)
        + controller_pole_placement_B.xt[i];
    }

    memset(&controller_pole_placement_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      controller_pole_placement_B.Pt1[i + 5 * i] = 1.0;
    }

    for (i = 0; i < 5; i++) {
      controller_pole_placement_B.a21 = controller_pole_placement_B.Lk[i + 5];
      controller_pole_placement_B.tth = controller_pole_placement_B.Lk[i];
      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           5; controller_pole_placement_B.r1++) {
        Pt1_tmp = controller_pole_placement_B.r1 << 1;
        controller_pole_placement_B.r2 = 5 * controller_pole_placement_B.r1 + i;
        controller_pole_placement_B.Pt1_m[controller_pole_placement_B.r2] =
          controller_pole_placement_B.Pt1[controller_pole_placement_B.r2] - (
          static_cast<real_T>(controller_pole_placement_B.A_tmp_c[Pt1_tmp + 1]) *
          controller_pole_placement_B.a21 + static_cast<real_T>
          (controller_pole_placement_B.A_tmp_c[Pt1_tmp]) *
          controller_pole_placement_B.tth);
      }

      for (controller_pole_placement_B.r1 = 0; controller_pole_placement_B.r1 <
           5; controller_pole_placement_B.r1++) {
        controller_pole_placement_B.a21 = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          controller_pole_placement_B.a21 += controller_pole_placement_B.Pt1_m[5
            * Pt1_tmp + i] * controller_pole_placement_B.Pt[5 *
            controller_pole_placement_B.r1 + Pt1_tmp];
        }

        controller_pole_placement_DW.Memory3_PreviousInput[i + 5 *
          controller_pole_placement_B.r1] = controller_pole_placement_B.a21;
      }
    }
  }

  // End of MATLAB Function: '<S20>/EKF_RP'

  // MATLAB Function: '<S11>/Y_computation' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion3'
  //   MATLAB Function: '<S11>/RPY_dot_computation'
  //   MATLAB Function: '<S20>/MATLAB Function'
  //   MATLAB Function: '<S23>/EKF_Y'

  controller_pole_placement_B.wr1 = sin
    (controller_pole_placement_DW.Memory4_PreviousInput[0]);
  controller_pole_placement_B.cph = cos
    (controller_pole_placement_DW.Memory4_PreviousInput[0]);
  controller_pole_placement_B.tth = sin
    (controller_pole_placement_DW.Memory4_PreviousInput[1]);
  controller_pole_placement_B.cth = cos
    (controller_pole_placement_DW.Memory4_PreviousInput[1]);
  controller_pole_placement_B.wq1 = rt_atan2d_snf
    (controller_pole_placement_B.In1_f.z * controller_pole_placement_B.wr1 -
     controller_pole_placement_B.In1_f.y * controller_pole_placement_B.cph,
     (controller_pole_placement_B.In1_f.y * controller_pole_placement_B.tth *
      controller_pole_placement_B.wr1 + controller_pole_placement_B.In1_f.x *
      controller_pole_placement_B.cth) + controller_pole_placement_B.In1_f.z *
     controller_pole_placement_B.tth * controller_pole_placement_B.cph);
  if (controller_pole_placement_B.wq1 < 0.0) {
    controller_pole_placement_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S23>/EKF_Y' incorporates:
  //   Delay: '<S23>/Delay2'
  //   MATLAB Function: '<S11>/Y_computation'
  //   MATLAB Function: '<S20>/MATLAB Function'
  //   Memory: '<S23>/Memory2'

  if (controller_pole_placement_B.DigitalClock1 -
      controller_pole_placement_DW.Memory2_PreviousInput_b >=
      controller_pole_placement_P.Ts_EKF_meas) {
    controller_pole_placement_DW.Memory2_PreviousInput_b =
      controller_pole_placement_B.DigitalClock1;
    controller_pole_placement_B.sph = 0.0;
    controller_pole_placement_B.Pt_f = 0.0;
    controller_pole_placement_B.b = static_cast<int32_T>(floor
      (controller_pole_placement_P.Ts_EKF_meas /
       controller_pole_placement_P.Ts_EKF_integr));
    if (controller_pole_placement_B.b - 1 >= 0) {
      controller_pole_placement_B.dv4[0] = 0.0;
      controller_pole_placement_B.dv4[1] = controller_pole_placement_B.wr1 /
        controller_pole_placement_B.cth;
      controller_pole_placement_B.dv4[2] = controller_pole_placement_B.cph /
        controller_pole_placement_B.cth;
      controller_pole_placement_B.dv4[3] = 0.0;
      controller_pole_placement_B.dv4[4] = 0.0;
      controller_pole_placement_B.dv4[5] = 0.0;
      controller_pole_placement_B.dv5[0] =
        controller_pole_placement_DW.Delay2_DSTATE_n[0] -
        controller_pole_placement_DW.Memory4_PreviousInput[2];
      controller_pole_placement_B.dv5[1] =
        controller_pole_placement_DW.Delay2_DSTATE_n[1] -
        controller_pole_placement_DW.Memory4_PreviousInput[3];
      controller_pole_placement_B.dv5[2] =
        controller_pole_placement_DW.Delay2_DSTATE_n[2] -
        controller_pole_placement_DW.Memory4_PreviousInput[4];
      controller_pole_placement_B.dv5[3] =
        controller_pole_placement_DW.Memory4_PreviousInput[2];
      controller_pole_placement_B.dv5[4] =
        controller_pole_placement_DW.Memory4_PreviousInput[3];
      controller_pole_placement_B.dv5[5] =
        controller_pole_placement_DW.Memory4_PreviousInput[4];
    }

    for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 <
         controller_pole_placement_B.b; controller_pole_placement_B.r2++) {
      controller_pole_placement_B.a21 = 0.0;
      for (i = 0; i < 6; i++) {
        controller_pole_placement_B.a21 += controller_pole_placement_B.dv4[i] *
          controller_pole_placement_B.dv5[i];
      }

      controller_pole_placement_B.sph =
        controller_pole_placement_P.Ts_EKF_integr *
        controller_pole_placement_B.a21 +
        controller_pole_placement_DW.Memory4_PreviousInput_k;
      controller_pole_placement_B.Pt_f = ((0.0 *
        controller_pole_placement_DW.Memory3_PreviousInput_f +
        controller_pole_placement_DW.Memory3_PreviousInput_f * 0.0) +
        controller_pole_placement_P.q_ps) *
        controller_pole_placement_P.Ts_EKF_integr +
        controller_pole_placement_DW.Memory3_PreviousInput_f;
      controller_pole_placement_DW.Memory4_PreviousInput_k =
        controller_pole_placement_B.sph;
      controller_pole_placement_DW.Memory3_PreviousInput_f =
        controller_pole_placement_B.Pt_f;
    }

    controller_pole_placement_B.a21 = controller_pole_placement_B.Pt_f /
      (controller_pole_placement_B.Pt_f + controller_pole_placement_P.r_ps);
    controller_pole_placement_DW.Memory4_PreviousInput_k =
      (controller_pole_placement_B.wq1 - controller_pole_placement_B.sph) *
      controller_pole_placement_B.a21 + controller_pole_placement_B.sph;
    controller_pole_placement_DW.Memory3_PreviousInput_f = (1.0 -
      controller_pole_placement_B.a21) * controller_pole_placement_B.Pt_f;
  }

  // DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn'
  controller_pole_placement_B.a21 =
    controller_pole_placement_P.DiscreteTransferFcn_NumCoef_g *
    controller_pole_placement_DW.DiscreteTransferFcn_states_a;

  // DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn1'
  controller_pole_placement_B.sph =
    controller_pole_placement_P.DiscreteTransferFcn1_NumCoef_m *
    controller_pole_placement_DW.DiscreteTransferFcn1_states_e;

  // DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2'
  controller_pole_placement_B.Pt_f =
    controller_pole_placement_P.DiscreteTransferFcn2_NumCoef_h *
    controller_pole_placement_DW.DiscreteTransferFcn2_states_p;

  // MATLAB Function: '<S11>/RPY_dot_computation' incorporates:
  //   Constant: '<S11>/Constant6'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S11>/Y_computation'
  //   MATLAB Function: '<S20>/MATLAB Function'
  //   Memory: '<S11>/Memory5'

  if ((controller_pole_placement_B.DigitalClock1 -
       controller_pole_placement_DW.Memory5_PreviousInput >=
       controller_pole_placement_P.Ts_EKF_meas) ||
      (controller_pole_placement_B.DigitalClock1 == 0.0)) {
    controller_pole_placement_B.tth /= controller_pole_placement_B.cth;
    controller_pole_placement_DW.Memory5_PreviousInput =
      controller_pole_placement_B.DigitalClock1;
    controller_pole_placement_B.dv2[0] = 1.0;
    controller_pole_placement_B.dv2[3] = controller_pole_placement_B.wr1 *
      controller_pole_placement_B.tth;
    controller_pole_placement_B.dv2[6] = controller_pole_placement_B.cph *
      controller_pole_placement_B.tth;
    controller_pole_placement_B.dv2[1] = 0.0;
    controller_pole_placement_B.dv2[4] = controller_pole_placement_B.cph;
    controller_pole_placement_B.dv2[7] = -controller_pole_placement_B.wr1;
    controller_pole_placement_B.dv2[2] = 0.0;
    controller_pole_placement_B.dv2[5] = controller_pole_placement_B.wr1 /
      controller_pole_placement_B.cth;
    controller_pole_placement_B.dv2[8] = controller_pole_placement_B.cph /
      controller_pole_placement_B.cth;
    controller_pole_placement_B.tth = controller_pole_placement_B.a21 -
      controller_pole_placement_DW.Memory4_PreviousInput[2] * 0.0;
    controller_pole_placement_B.wr1 = controller_pole_placement_B.sph -
      controller_pole_placement_DW.Memory4_PreviousInput[3] * 0.0;
    controller_pole_placement_B.cph = controller_pole_placement_B.Pt_f -
      controller_pole_placement_DW.Memory4_PreviousInput[4] * 0.0;
    for (i = 0; i < 3; i++) {
      controller_pole_placement_DW.Memory6_PreviousInput[i] =
        (controller_pole_placement_B.dv2[i + 3] *
         controller_pole_placement_B.wr1 + controller_pole_placement_B.dv2[i] *
         controller_pole_placement_B.tth) + controller_pole_placement_B.dv2[i +
        6] * controller_pole_placement_B.cph;
    }
  }

  // Step: '<Root>/R ref'
  if (controller_pole_placement_B.DigitalClock1 <
      controller_pole_placement_P.Rref_Time) {
    // Step: '<Root>/R ref'
    controller_pole_placement_B.tth = controller_pole_placement_P.Rref_Y0;
  } else {
    // Step: '<Root>/R ref'
    controller_pole_placement_B.tth = controller_pole_placement_P.Rref_YFinal;
  }

  // ManualSwitch: '<Root>/Manual Switch2'
  if (controller_pole_placement_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 < 28;
         controller_pole_placement_B.r2++) {
      controller_pole_placement_B.ManualSwitch2[controller_pole_placement_B.r2] =
        controller_pole_placement_P.Constant6_Value_f;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant7'
    //   Constant: '<Root>/Constant8'
    //   DataTypeConversion: '<S4>/Data Type Conversion'
    //   DataTypeConversion: '<S4>/Data Type Conversion1'
    //   DataTypeConversion: '<S4>/Data Type Conversion2'
    //   DataTypeConversion: '<S4>/Data Type Conversion3'
    //   DataTypeConversion: '<S4>/Data Type Conversion4'
    //   MATLAB Function: '<S20>/MATLAB Function'
    //   MATLAB Function: '<S23>/EKF_Y'
    //   MATLAB Function: '<S32>/MATLAB Function'
    //   MATLAB Function: '<S32>/MATLAB Function1'
    //   SignalConversion generated from: '<S34>/ SFunction '
    //   SignalConversion generated from: '<S35>/ SFunction '

    controller_pole_placement_B.ManualSwitch2[0] = rtb_DataTypeConversion1_c;
    controller_pole_placement_B.ManualSwitch2[1] = rtb_DataTypeConversion1_h;
    controller_pole_placement_B.ManualSwitch2[2] = rtb_DataTypeConversion1_p;
    controller_pole_placement_B.ManualSwitch2[3] = rtb_DataTypeConversion1_o;
    controller_pole_placement_B.ManualSwitch2[4] =
      controller_pole_placement_B.In1_i.x;
    controller_pole_placement_B.ManualSwitch2[5] =
      controller_pole_placement_B.In1_i.y;
    controller_pole_placement_B.ManualSwitch2[6] =
      controller_pole_placement_B.In1_i.z;
    controller_pole_placement_B.ManualSwitch2[7] =
      controller_pole_placement_B.In1_n.x;
    controller_pole_placement_B.ManualSwitch2[8] =
      controller_pole_placement_B.In1_n.y;
    controller_pole_placement_B.ManualSwitch2[9] =
      controller_pole_placement_B.In1_n.z;
    controller_pole_placement_B.ManualSwitch2[10] =
      controller_pole_placement_B.In1.rollspeed;
    controller_pole_placement_B.ManualSwitch2[11] =
      controller_pole_placement_B.In1.pitchspeed;
    controller_pole_placement_B.ManualSwitch2[12] =
      controller_pole_placement_B.In1.yawspeed;
    controller_pole_placement_B.ManualSwitch2[13] =
      controller_pole_placement_B.y_k[0];
    controller_pole_placement_B.ManualSwitch2[14] =
      controller_pole_placement_B.y_k[1];
    controller_pole_placement_B.ManualSwitch2[15] =
      controller_pole_placement_B.y_k[2];
    controller_pole_placement_B.ManualSwitch2[16] =
      controller_pole_placement_B.In1_f.x;
    controller_pole_placement_B.ManualSwitch2[17] =
      controller_pole_placement_B.In1_f.y;
    controller_pole_placement_B.ManualSwitch2[18] =
      controller_pole_placement_B.In1_f.z;
    controller_pole_placement_B.ManualSwitch2[19] =
      controller_pole_placement_DW.Memory4_PreviousInput[0];
    controller_pole_placement_B.ManualSwitch2[20] =
      controller_pole_placement_DW.Memory4_PreviousInput[1];
    controller_pole_placement_B.ManualSwitch2[21] =
      controller_pole_placement_DW.Memory4_PreviousInput_k;
    controller_pole_placement_B.ManualSwitch2[22] =
      controller_pole_placement_DW.Memory6_PreviousInput[0];
    controller_pole_placement_B.ManualSwitch2[23] =
      controller_pole_placement_DW.Memory6_PreviousInput[1];
    controller_pole_placement_B.ManualSwitch2[24] =
      controller_pole_placement_DW.Memory6_PreviousInput[2];
    controller_pole_placement_B.ManualSwitch2[25] =
      controller_pole_placement_B.tth;
    controller_pole_placement_B.ManualSwitch2[26] =
      controller_pole_placement_P.Constant7_Value;
    controller_pole_placement_B.ManualSwitch2[27] =
      controller_pole_placement_P.Constant8_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  controller_pole_placement_B.TmpSignalConversionAt_asyncqueu[0] =
    controller_pole_placement_B.DigitalClock1;
  memcpy(&controller_pole_placement_B.TmpSignalConversionAt_asyncqueu[1],
         &controller_pole_placement_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S12>/Gain2' incorporates:
  //   MATLAB Function: '<S12>/MATLAB Function2'
  //   MATLAB Function: '<S23>/EKF_Y'
  //   SignalConversion generated from: '<S30>/ SFunction '

  controller_pole_placement_B.Gain2[2] = controller_pole_placement_P.Gain2_Gain *
    controller_pole_placement_DW.Memory4_PreviousInput_k;

  // SignalConversion generated from: '<S20>/Delay2' incorporates:
  //   Delay: '<S23>/Delay2'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2'

  controller_pole_placement_DW.Delay2_DSTATE_n[0] =
    controller_pole_placement_B.a21;
  controller_pole_placement_DW.Delay2_DSTATE_n[1] =
    controller_pole_placement_B.sph;
  controller_pole_placement_DW.Delay2_DSTATE_n[2] =
    controller_pole_placement_B.Pt_f;

  // Gain: '<S12>/Gain2' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function'

  controller_pole_placement_B.Gain2[0] = controller_pole_placement_P.Gain2_Gain *
    controller_pole_placement_DW.Memory4_PreviousInput[0];

  // Gain: '<S3>/Gain' incorporates:
  //   MATLAB Function: '<S11>/RP_computation'

  controller_pole_placement_B.Gain_e[0] =
    controller_pole_placement_P.Gain_Gain_ex *
    controller_pole_placement_B.ph_meas;

  // Gain: '<S12>/Gain2' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function'

  controller_pole_placement_B.Gain2[1] = controller_pole_placement_P.Gain2_Gain *
    controller_pole_placement_DW.Memory4_PreviousInput[1];

  // Gain: '<S3>/Gain' incorporates:
  //   MATLAB Function: '<S11>/Y_computation'

  controller_pole_placement_B.Gain_e[1] = controller_pole_placement_B.Sum23_g *
    controller_pole_placement_P.Gain_Gain_ex;
  controller_pole_placement_B.Gain_e[2] =
    controller_pole_placement_P.Gain_Gain_ex * controller_pole_placement_B.wq1;

  // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion2'

  controller_pole_placement_B.y_c[0] = controller_pole_placement_B.In1_n.x;
  controller_pole_placement_B.y_c[1] = -static_cast<real_T>
    (controller_pole_placement_B.In1_n.y);
  controller_pole_placement_B.y_c[2] = -static_cast<real_T>
    (controller_pole_placement_B.In1_n.z);

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S9>/Data Type Conversion1'

  controller_pole_placement_B.y_p[0] = -static_cast<real_T>
    (controller_pole_placement_B.In1_i.x);
  controller_pole_placement_B.y_p[1] = controller_pole_placement_B.In1_i.y;
  controller_pole_placement_B.y_p[2] = controller_pole_placement_B.In1_i.z;

  // Gain: '<S9>/Gain1'
  controller_pole_placement_B.Sum23_g = controller_pole_placement_B.y_c[0];
  controller_pole_placement_B.a21 = controller_pole_placement_B.y_c[1];
  controller_pole_placement_B.wq1 = controller_pole_placement_B.y_c[2];

  // Gain: '<S9>/Gain'
  controller_pole_placement_B.wr1 = controller_pole_placement_B.y_p[0];
  controller_pole_placement_B.cph = controller_pole_placement_B.y_p[1];
  controller_pole_placement_B.cth = controller_pole_placement_B.y_p[2];
  for (controller_pole_placement_B.r2 = 0; controller_pole_placement_B.r2 < 3;
       controller_pole_placement_B.r2++) {
    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.sph =
      controller_pole_placement_P.Rz[controller_pole_placement_B.r2];

    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.ph_meas = controller_pole_placement_B.sph *
      controller_pole_placement_B.Sum23_g;

    // Gain: '<S9>/Gain'
    controller_pole_placement_B.Pt_f = controller_pole_placement_B.sph *
      controller_pole_placement_B.wr1;

    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.sph =
      controller_pole_placement_P.Rz[controller_pole_placement_B.r2 + 3];

    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.ph_meas += controller_pole_placement_B.sph *
      controller_pole_placement_B.a21;

    // Gain: '<S9>/Gain'
    controller_pole_placement_B.Pt_f += controller_pole_placement_B.sph *
      controller_pole_placement_B.cph;

    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.sph =
      controller_pole_placement_P.Rz[controller_pole_placement_B.r2 + 6];

    // Gain: '<S9>/Gain'
    controller_pole_placement_B.TmpSignalConversionAtSFunct[controller_pole_placement_B.r2]
      = controller_pole_placement_B.sph * controller_pole_placement_B.cth +
      controller_pole_placement_B.Pt_f;

    // Gain: '<S9>/Gain1'
    controller_pole_placement_B.u_vect[controller_pole_placement_B.r2] =
      controller_pole_placement_B.sph * controller_pole_placement_B.wq1 +
      controller_pole_placement_B.ph_meas;

    // Gain: '<Root>/Gain1'
    controller_pole_placement_B.Gain1_d[controller_pole_placement_B.r2] =
      controller_pole_placement_P.Gain1_Gain_b *
      controller_pole_placement_B.y_k[controller_pole_placement_B.r2];
  }

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  controller_pole_placement_B.y1_e = controller_pole_placement_B.Gain1_d[0];
  controller_pole_placement_B.y2_i = controller_pole_placement_B.Gain1_d[1];
  controller_pole_placement_B.y3_c = controller_pole_placement_B.Gain1_d[2];

  // MATLAB Function: '<S12>/MATLAB Function7'
  controller_pole_MATLABFunction1(controller_pole_placement_B.Gain2,
    &controller_pole_placement_B.y1_b, &controller_pole_placement_B.y2_p,
    &controller_pole_placement_B.y3_g,
    &controller_pole_placement_DW.sf_MATLABFunction7);

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant5'
  //   Gain: '<Root>/Gain'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum2'

  if (controller_pole_placement_P.ManualSwitch_CurrentSetting == 1) {
    controller_pole_placement_B.a21 = controller_pole_placement_B.y2_p +
      controller_pole_placement_P.Constant5_Value;
  } else {
    controller_pole_placement_B.a21 = (controller_pole_placement_B.y2_i +
      controller_pole_placement_P.Constant_Value_jx) *
      controller_pole_placement_P.Gain_Gain;
  }

  // Sum: '<S6>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<S41>/Discrete Transfer Fcn1'
  //   Gain: '<Root>/Gain2'
  //   ManualSwitch: '<Root>/Manual Switch'

  controller_pole_placement_B.Sum2_h =
    controller_pole_placement_P.DiscreteTransferFcn1_NumCoef_d *
    controller_pole_placement_DW.DiscreteTransferFcn1_states_eg -
    controller_pole_placement_P.Gain2_Gain_o * controller_pole_placement_B.a21;

  // MATLAB Function: '<S3>/MATLAB Function1'
  controller_pole_MATLABFunction1(controller_pole_placement_B.Gain_e,
    &controller_pole_placement_B.y1_j, &controller_pole_placement_B.y2_pc,
    &controller_pole_placement_B.y3_l,
    &controller_pole_placement_DW.sf_MATLABFunction1_i);

  // MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
  //   Constant: '<S4>/failsafe'

  for (i = 0; i < 8; i++) {
    controller_pole_placement_B.pwmValue[i] = 0U;
  }

  controller_pole_placement_B.pwmValue[0] = rtb_DataTypeConversion1_c;
  controller_pole_placement_B.pwmValue[1] = rtb_DataTypeConversion1_h;
  controller_pole_placement_B.pwmValue[2] = rtb_DataTypeConversion1_p;
  controller_pole_placement_B.pwmValue[3] = rtb_DataTypeConversion1_o;
  if (rtb_startingswitch) {
    if (!controller_pole_placement_DW.obj.isArmed) {
      controller_pole_placement_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_c = pwm_arm
        (&controller_pole_placement_DW.obj.pwmDevHandler,
         &controller_pole_placement_DW.obj.armAdvertiseObj);
      controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_pole_placement_DW.obj.errorStatus |
         rtb_DataTypeConversion1_c);
    }

    rtb_DataTypeConversion1_c = pwm_setServo
      (&controller_pole_placement_DW.obj.pwmDevHandler,
       controller_pole_placement_DW.obj.servoCount,
       controller_pole_placement_DW.obj.channelMask,
       &controller_pole_placement_B.pwmValue[0],
       controller_pole_placement_DW.obj.isMain,
       &controller_pole_placement_DW.obj.actuatorAdvertiseObj);
    controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_pole_placement_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  } else {
    rtb_DataTypeConversion1_c = pwm_disarm
      (&controller_pole_placement_DW.obj.pwmDevHandler,
       &controller_pole_placement_DW.obj.armAdvertiseObj);
    controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_pole_placement_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
    controller_pole_placement_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_c = pwm_resetServo
      (&controller_pole_placement_DW.obj.pwmDevHandler,
       controller_pole_placement_DW.obj.servoCount,
       controller_pole_placement_DW.obj.channelMask,
       controller_pole_placement_DW.obj.isMain,
       &controller_pole_placement_DW.obj.actuatorAdvertiseObj);
    controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_pole_placement_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  if (controller_pole_placement_DW.obj.isMain) {
    rtb_DataTypeConversion1_c = pwm_forceFailsafe
      (&controller_pole_placement_DW.obj.pwmDevHandler, static_cast<int32_T>
       (controller_pole_placement_P.failsafe_Value));
    controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
      (controller_pole_placement_DW.obj.errorStatus | rtb_DataTypeConversion1_c);
  }

  // End of MATLABSystem: '<S4>/PX4 PWM Output'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = uORB_read_step
    (controller_pole_placement_DW.obj_d.orbMetadataObj,
     &controller_pole_placement_DW.obj_d.eventStructObj,
     &controller_pole_placement_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S40>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S40>/In1'
    controller_pole_placement_B.In1_h =
      controller_pole_placement_B.b_varargout_2_c;
    srUpdateBC(controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  controller_pole_placement_B.SignalConversion[0] =
    controller_pole_placement_B.In1_h.output[0];
  controller_pole_placement_B.SignalConversion[1] =
    controller_pole_placement_B.In1_h.output[1];
  controller_pole_placement_B.SignalConversion[2] =
    controller_pole_placement_B.In1_h.output[2];
  controller_pole_placement_B.SignalConversion[3] =
    controller_pole_placement_B.In1_h.output[3];

  // Update for Delay: '<S6>/Delay3'
  controller_pole_placement_DW.Delay3_DSTATE = controller_pole_placement_B.u_sat;

  // Update for DiscreteStateSpace: '<S42>/Internal'
  {
    controller_pole_placement_DW.Internal_DSTATE =
      controller_pole_placement_B.Sum2_h +
      controller_pole_placement_P.Internal_A*
      controller_pole_placement_DW.Internal_DSTATE;
  }

  // Update for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn'

  controller_pole_placement_DW.DiscreteTransferFcn_states =
    (controller_pole_placement_P.DiscreteTransferFcn_NumCoef_gv *
     controller_pole_placement_DW.DiscreteTransferFcn_states_f -
     controller_pole_placement_P.DiscreteTransferFcn_DenCoef[1] *
     controller_pole_placement_DW.DiscreteTransferFcn_states) /
    controller_pole_placement_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn1'

  controller_pole_placement_DW.DiscreteTransferFcn1_states =
    (controller_pole_placement_P.DiscreteTransferFcn1_NumCoef_o *
     controller_pole_placement_DW.DiscreteTransferFcn1_states_d -
     controller_pole_placement_P.DiscreteTransferFcn1_DenCoef[1] *
     controller_pole_placement_DW.DiscreteTransferFcn1_states) /
    controller_pole_placement_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn2'

  controller_pole_placement_DW.DiscreteTransferFcn2_states =
    (controller_pole_placement_P.DiscreteTransferFcn2_NumCoef_g *
     controller_pole_placement_DW.DiscreteTransferFcn2_states_p2 -
     controller_pole_placement_P.DiscreteTransferFcn2_DenCoef[1] *
     controller_pole_placement_DW.DiscreteTransferFcn2_states) /
    controller_pole_placement_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S18>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn2'

  controller_pole_placement_DW.Delay_DSTATE_p[0] =
    controller_pole_placement_B.Delay2_DSTATE_m;
  controller_pole_placement_DW.Delay_DSTATE_p[1] =
    controller_pole_placement_B.Delay2_DSTATE_n;
  controller_pole_placement_DW.Delay_DSTATE_p[2] =
    controller_pole_placement_B.x_g;

  // Update for Delay: '<S6>/Delay2'
  controller_pole_placement_DW.Delay2_DSTATE[0] = controller_pole_placement_B.x
    [0];

  // Update for Delay: '<S22>/Delay23' incorporates:
  //   Delay: '<S22>/Delay22'
  //
  controller_pole_placement_DW.Delay23_DSTATE[0] =
    controller_pole_placement_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S22>/Delay22' incorporates:
  //   Delay: '<S22>/Delay21'
  //
  controller_pole_placement_DW.Delay22_DSTATE[0] =
    controller_pole_placement_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S22>/Delay21' incorporates:
  //   Delay: '<S22>/Delay20'
  //
  controller_pole_placement_DW.Delay21_DSTATE[0] =
    controller_pole_placement_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S22>/Delay20' incorporates:
  //   Delay: '<S22>/Delay14'
  //
  controller_pole_placement_DW.Delay20_DSTATE[0] =
    controller_pole_placement_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S22>/Delay14' incorporates:
  //   Delay: '<S22>/Delay13'
  //
  controller_pole_placement_DW.Delay14_DSTATE[0] =
    controller_pole_placement_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S22>/Delay13' incorporates:
  //   Delay: '<S22>/Delay12'
  //
  controller_pole_placement_DW.Delay13_DSTATE[0] =
    controller_pole_placement_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S22>/Delay12' incorporates:
  //   Delay: '<S22>/Delay11'
  //
  controller_pole_placement_DW.Delay12_DSTATE[0] =
    controller_pole_placement_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S22>/Delay11' incorporates:
  //   Delay: '<S22>/Delay10'
  //
  controller_pole_placement_DW.Delay11_DSTATE[0] =
    controller_pole_placement_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S22>/Delay10' incorporates:
  //   Delay: '<S22>/Delay9'
  //
  controller_pole_placement_DW.Delay10_DSTATE[0] =
    controller_pole_placement_DW.Delay9_DSTATE[0];

  // Update for Delay: '<S22>/Delay9' incorporates:
  //   Delay: '<S22>/Delay8'
  //
  controller_pole_placement_DW.Delay9_DSTATE[0] =
    controller_pole_placement_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S22>/Delay8' incorporates:
  //   Delay: '<S22>/Delay7'
  //
  controller_pole_placement_DW.Delay8_DSTATE[0] =
    controller_pole_placement_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S22>/Delay7' incorporates:
  //   Delay: '<S22>/Delay6'
  //
  controller_pole_placement_DW.Delay7_DSTATE[0] =
    controller_pole_placement_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S22>/Delay6' incorporates:
  //   Delay: '<S22>/Delay5'
  //
  controller_pole_placement_DW.Delay6_DSTATE[0] =
    controller_pole_placement_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S22>/Delay5' incorporates:
  //   Delay: '<S22>/Delay4'
  //
  controller_pole_placement_DW.Delay5_DSTATE[0] =
    controller_pole_placement_DW.Delay4_DSTATE[0];

  // Update for Delay: '<S22>/Delay4' incorporates:
  //   Delay: '<S22>/Delay3'
  //
  controller_pole_placement_DW.Delay4_DSTATE[0] =
    controller_pole_placement_DW.Delay3_DSTATE_d[0];

  // Update for Delay: '<S22>/Delay3' incorporates:
  //   Delay: '<S22>/Delay2'
  //
  controller_pole_placement_DW.Delay3_DSTATE_d[0] =
    controller_pole_placement_DW.Delay2_DSTATE_i[0];

  // Update for Delay: '<S22>/Delay2' incorporates:
  //   Delay: '<S22>/Delay1'
  //
  controller_pole_placement_DW.Delay2_DSTATE_i[0] =
    controller_pole_placement_DW.Delay1_DSTATE[0];

  // Update for Delay: '<S22>/Delay1' incorporates:
  //   Delay: '<S22>/Delay'
  //
  controller_pole_placement_DW.Delay1_DSTATE[0] =
    controller_pole_placement_DW.Delay_DSTATE[0];

  // Update for Delay: '<S22>/Delay'
  controller_pole_placement_DW.Delay_DSTATE[0] =
    controller_pole_placement_B.y_idx_0;

  // Update for Delay: '<S18>/Delay1'
  controller_pole_placement_DW.Delay1_DSTATE_p[0] =
    controller_pole_placement_B.rtb_Delay_l_idx_0;

  // Update for Delay: '<S18>/Delay2'
  controller_pole_placement_DW.Delay2_DSTATE_p[0] =
    controller_pole_placement_B.rtb_Delay1_n_idx_0;

  // Update for Delay: '<S18>/Delay3'
  controller_pole_placement_DW.Delay3_DSTATE_j[0] =
    controller_pole_placement_B.rtb_Delay2_h_idx_0;

  // Update for Delay: '<S18>/Delay4'
  controller_pole_placement_DW.Delay4_DSTATE_e[0] =
    controller_pole_placement_B.rtb_Delay3_p_idx_0;

  // Update for Delay: '<S18>/Delay5'
  controller_pole_placement_DW.Delay5_DSTATE_p[0] =
    controller_pole_placement_B.rtb_Delay4_j_idx_0;

  // Update for Delay: '<S18>/Delay6'
  controller_pole_placement_DW.Delay6_DSTATE_p[0] =
    controller_pole_placement_B.rtb_Delay5_e_idx_0;

  // Update for Delay: '<S18>/Delay7'
  controller_pole_placement_DW.Delay7_DSTATE_o[0] =
    controller_pole_placement_B.rtb_Delay6_f_idx_0;

  // Update for Delay: '<S18>/Delay8'
  controller_pole_placement_DW.Delay8_DSTATE_n[0] =
    controller_pole_placement_B.rtb_Delay7_i_idx_0;

  // Update for Delay: '<S18>/Delay9'
  controller_pole_placement_DW.Delay9_DSTATE_i[0] =
    controller_pole_placement_B.rtb_Delay8_j_idx_0;

  // Update for Delay: '<S18>/Delay10'
  controller_pole_placement_DW.Delay10_DSTATE_f[0] =
    controller_pole_placement_B.rtb_Delay9_j_idx_0;

  // Update for Delay: '<S18>/Delay11'
  controller_pole_placement_DW.Delay11_DSTATE_k[0] =
    controller_pole_placement_B.rtb_Delay10_e_idx_0;

  // Update for Delay: '<S18>/Delay12'
  controller_pole_placement_DW.Delay12_DSTATE_n[0] =
    controller_pole_placement_B.rtb_Delay11_n_idx_0;

  // Update for Delay: '<S18>/Delay13'
  controller_pole_placement_DW.Delay13_DSTATE_g[0] =
    controller_pole_placement_B.rtb_Delay12_a_idx_0;

  // Update for Delay: '<S18>/Delay14'
  controller_pole_placement_DW.Delay14_DSTATE_g[0] =
    controller_pole_placement_B.rtb_Delay13_h_idx_0;

  // Update for Delay: '<S18>/Delay15'
  controller_pole_placement_DW.Delay15_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay14_m_idx_0;

  // Update for Delay: '<S18>/Delay20'
  controller_pole_placement_DW.Delay20_DSTATE_h[0] =
    controller_pole_placement_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S18>/Delay21'
  controller_pole_placement_DW.Delay21_DSTATE_d[0] =
    controller_pole_placement_B.rtb_Delay20_g_idx_0;

  // Update for Delay: '<S18>/Delay22'
  controller_pole_placement_DW.Delay22_DSTATE_h[0] =
    controller_pole_placement_B.rtb_Delay21_e_idx_0;

  // Update for Delay: '<S18>/Delay23'
  controller_pole_placement_DW.Delay23_DSTATE_p[0] =
    controller_pole_placement_B.rtb_Delay22_b_idx_0;

  // Update for Delay: '<S18>/Delay24'
  controller_pole_placement_DW.Delay24_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay23_g_idx_0;

  // Update for Delay: '<S18>/Delay25'
  controller_pole_placement_DW.Delay25_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S18>/Delay26'
  controller_pole_placement_DW.Delay26_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S18>/Delay27'
  controller_pole_placement_DW.Delay27_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S18>/Delay16'
  controller_pole_placement_DW.Delay16_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S18>/Delay17'
  controller_pole_placement_DW.Delay17_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S18>/Delay18'
  controller_pole_placement_DW.Delay18_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S18>/Delay19'
  controller_pole_placement_DW.Delay19_DSTATE[0] =
    controller_pole_placement_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S20>/Delay2' incorporates:
  //   Delay: '<S23>/Delay2'

  controller_pole_placement_DW.Delay2_DSTATE_l[0] =
    controller_pole_placement_DW.Delay2_DSTATE_n[0];

  // Update for Delay: '<S6>/Delay2'
  controller_pole_placement_DW.Delay2_DSTATE[1] = controller_pole_placement_B.x
    [1];

  // Update for Delay: '<S22>/Delay23' incorporates:
  //   Delay: '<S22>/Delay22'
  //
  controller_pole_placement_DW.Delay23_DSTATE[1] =
    controller_pole_placement_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S22>/Delay22' incorporates:
  //   Delay: '<S22>/Delay21'
  //
  controller_pole_placement_DW.Delay22_DSTATE[1] =
    controller_pole_placement_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S22>/Delay21' incorporates:
  //   Delay: '<S22>/Delay20'
  //
  controller_pole_placement_DW.Delay21_DSTATE[1] =
    controller_pole_placement_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S22>/Delay20' incorporates:
  //   Delay: '<S22>/Delay14'
  //
  controller_pole_placement_DW.Delay20_DSTATE[1] =
    controller_pole_placement_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S22>/Delay14' incorporates:
  //   Delay: '<S22>/Delay13'
  //
  controller_pole_placement_DW.Delay14_DSTATE[1] =
    controller_pole_placement_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S22>/Delay13' incorporates:
  //   Delay: '<S22>/Delay12'
  //
  controller_pole_placement_DW.Delay13_DSTATE[1] =
    controller_pole_placement_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S22>/Delay12' incorporates:
  //   Delay: '<S22>/Delay11'
  //
  controller_pole_placement_DW.Delay12_DSTATE[1] =
    controller_pole_placement_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S22>/Delay11' incorporates:
  //   Delay: '<S22>/Delay10'
  //
  controller_pole_placement_DW.Delay11_DSTATE[1] =
    controller_pole_placement_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S22>/Delay10' incorporates:
  //   Delay: '<S22>/Delay9'
  //
  controller_pole_placement_DW.Delay10_DSTATE[1] =
    controller_pole_placement_DW.Delay9_DSTATE[1];

  // Update for Delay: '<S22>/Delay9' incorporates:
  //   Delay: '<S22>/Delay8'
  //
  controller_pole_placement_DW.Delay9_DSTATE[1] =
    controller_pole_placement_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S22>/Delay8' incorporates:
  //   Delay: '<S22>/Delay7'
  //
  controller_pole_placement_DW.Delay8_DSTATE[1] =
    controller_pole_placement_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S22>/Delay7' incorporates:
  //   Delay: '<S22>/Delay6'
  //
  controller_pole_placement_DW.Delay7_DSTATE[1] =
    controller_pole_placement_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S22>/Delay6' incorporates:
  //   Delay: '<S22>/Delay5'
  //
  controller_pole_placement_DW.Delay6_DSTATE[1] =
    controller_pole_placement_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S22>/Delay5' incorporates:
  //   Delay: '<S22>/Delay4'
  //
  controller_pole_placement_DW.Delay5_DSTATE[1] =
    controller_pole_placement_DW.Delay4_DSTATE[1];

  // Update for Delay: '<S22>/Delay4' incorporates:
  //   Delay: '<S22>/Delay3'
  //
  controller_pole_placement_DW.Delay4_DSTATE[1] =
    controller_pole_placement_DW.Delay3_DSTATE_d[1];

  // Update for Delay: '<S22>/Delay3' incorporates:
  //   Delay: '<S22>/Delay2'
  //
  controller_pole_placement_DW.Delay3_DSTATE_d[1] =
    controller_pole_placement_DW.Delay2_DSTATE_i[1];

  // Update for Delay: '<S22>/Delay2' incorporates:
  //   Delay: '<S22>/Delay1'
  //
  controller_pole_placement_DW.Delay2_DSTATE_i[1] =
    controller_pole_placement_DW.Delay1_DSTATE[1];

  // Update for Delay: '<S22>/Delay1' incorporates:
  //   Delay: '<S22>/Delay'
  //
  controller_pole_placement_DW.Delay1_DSTATE[1] =
    controller_pole_placement_DW.Delay_DSTATE[1];

  // Update for Delay: '<S22>/Delay'
  controller_pole_placement_DW.Delay_DSTATE[1] =
    controller_pole_placement_B.y_idx_1;

  // Update for Delay: '<S18>/Delay1'
  controller_pole_placement_DW.Delay1_DSTATE_p[1] =
    controller_pole_placement_B.rtb_Delay_l_idx_1;

  // Update for Delay: '<S18>/Delay2'
  controller_pole_placement_DW.Delay2_DSTATE_p[1] =
    controller_pole_placement_B.rtb_Delay1_n_idx_1;

  // Update for Delay: '<S18>/Delay3'
  controller_pole_placement_DW.Delay3_DSTATE_j[1] =
    controller_pole_placement_B.rtb_Delay2_h_idx_1;

  // Update for Delay: '<S18>/Delay4'
  controller_pole_placement_DW.Delay4_DSTATE_e[1] =
    controller_pole_placement_B.rtb_Delay3_p_idx_1;

  // Update for Delay: '<S18>/Delay5'
  controller_pole_placement_DW.Delay5_DSTATE_p[1] =
    controller_pole_placement_B.rtb_Delay4_j_idx_1;

  // Update for Delay: '<S18>/Delay6'
  controller_pole_placement_DW.Delay6_DSTATE_p[1] =
    controller_pole_placement_B.rtb_Delay5_e_idx_1;

  // Update for Delay: '<S18>/Delay7'
  controller_pole_placement_DW.Delay7_DSTATE_o[1] =
    controller_pole_placement_B.rtb_Delay6_f_idx_1;

  // Update for Delay: '<S18>/Delay8'
  controller_pole_placement_DW.Delay8_DSTATE_n[1] =
    controller_pole_placement_B.rtb_Delay7_i_idx_1;

  // Update for Delay: '<S18>/Delay9'
  controller_pole_placement_DW.Delay9_DSTATE_i[1] =
    controller_pole_placement_B.rtb_Delay8_j_idx_1;

  // Update for Delay: '<S18>/Delay10'
  controller_pole_placement_DW.Delay10_DSTATE_f[1] =
    controller_pole_placement_B.rtb_Delay9_j_idx_1;

  // Update for Delay: '<S18>/Delay11'
  controller_pole_placement_DW.Delay11_DSTATE_k[1] =
    controller_pole_placement_B.rtb_Delay10_e_idx_1;

  // Update for Delay: '<S18>/Delay12'
  controller_pole_placement_DW.Delay12_DSTATE_n[1] =
    controller_pole_placement_B.rtb_Delay11_n_idx_1;

  // Update for Delay: '<S18>/Delay13'
  controller_pole_placement_DW.Delay13_DSTATE_g[1] =
    controller_pole_placement_B.rtb_Delay12_a_idx_1;

  // Update for Delay: '<S18>/Delay14'
  controller_pole_placement_DW.Delay14_DSTATE_g[1] =
    controller_pole_placement_B.rtb_Delay13_h_idx_1;

  // Update for Delay: '<S18>/Delay15'
  controller_pole_placement_DW.Delay15_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay14_m_idx_1;

  // Update for Delay: '<S18>/Delay20'
  controller_pole_placement_DW.Delay20_DSTATE_h[1] =
    controller_pole_placement_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S18>/Delay21'
  controller_pole_placement_DW.Delay21_DSTATE_d[1] =
    controller_pole_placement_B.rtb_Delay20_g_idx_1;

  // Update for Delay: '<S18>/Delay22'
  controller_pole_placement_DW.Delay22_DSTATE_h[1] =
    controller_pole_placement_B.rtb_Delay21_e_idx_1;

  // Update for Delay: '<S18>/Delay23'
  controller_pole_placement_DW.Delay23_DSTATE_p[1] =
    controller_pole_placement_B.rtb_Delay22_b_idx_1;

  // Update for Delay: '<S18>/Delay24'
  controller_pole_placement_DW.Delay24_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay23_g_idx_1;

  // Update for Delay: '<S18>/Delay25'
  controller_pole_placement_DW.Delay25_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S18>/Delay26'
  controller_pole_placement_DW.Delay26_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S18>/Delay27'
  controller_pole_placement_DW.Delay27_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S18>/Delay16'
  controller_pole_placement_DW.Delay16_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S18>/Delay17'
  controller_pole_placement_DW.Delay17_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S18>/Delay18'
  controller_pole_placement_DW.Delay18_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S18>/Delay19'
  controller_pole_placement_DW.Delay19_DSTATE[1] =
    controller_pole_placement_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S20>/Delay2' incorporates:
  //   Delay: '<S23>/Delay2'

  controller_pole_placement_DW.Delay2_DSTATE_l[1] =
    controller_pole_placement_DW.Delay2_DSTATE_n[1];

  // Update for Delay: '<S6>/Delay2'
  controller_pole_placement_DW.Delay2_DSTATE[2] = controller_pole_placement_B.x
    [2];

  // Update for Delay: '<S22>/Delay23' incorporates:
  //   Delay: '<S22>/Delay22'
  //
  controller_pole_placement_DW.Delay23_DSTATE[2] =
    controller_pole_placement_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S22>/Delay22' incorporates:
  //   Delay: '<S22>/Delay21'
  //
  controller_pole_placement_DW.Delay22_DSTATE[2] =
    controller_pole_placement_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S22>/Delay21' incorporates:
  //   Delay: '<S22>/Delay20'
  //
  controller_pole_placement_DW.Delay21_DSTATE[2] =
    controller_pole_placement_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S22>/Delay20' incorporates:
  //   Delay: '<S22>/Delay14'
  //
  controller_pole_placement_DW.Delay20_DSTATE[2] =
    controller_pole_placement_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S22>/Delay14' incorporates:
  //   Delay: '<S22>/Delay13'
  //
  controller_pole_placement_DW.Delay14_DSTATE[2] =
    controller_pole_placement_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S22>/Delay13' incorporates:
  //   Delay: '<S22>/Delay12'
  //
  controller_pole_placement_DW.Delay13_DSTATE[2] =
    controller_pole_placement_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S22>/Delay12' incorporates:
  //   Delay: '<S22>/Delay11'
  //
  controller_pole_placement_DW.Delay12_DSTATE[2] =
    controller_pole_placement_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S22>/Delay11' incorporates:
  //   Delay: '<S22>/Delay10'
  //
  controller_pole_placement_DW.Delay11_DSTATE[2] =
    controller_pole_placement_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S22>/Delay10' incorporates:
  //   Delay: '<S22>/Delay9'
  //
  controller_pole_placement_DW.Delay10_DSTATE[2] =
    controller_pole_placement_DW.Delay9_DSTATE[2];

  // Update for Delay: '<S22>/Delay9' incorporates:
  //   Delay: '<S22>/Delay8'
  //
  controller_pole_placement_DW.Delay9_DSTATE[2] =
    controller_pole_placement_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S22>/Delay8' incorporates:
  //   Delay: '<S22>/Delay7'
  //
  controller_pole_placement_DW.Delay8_DSTATE[2] =
    controller_pole_placement_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S22>/Delay7' incorporates:
  //   Delay: '<S22>/Delay6'
  //
  controller_pole_placement_DW.Delay7_DSTATE[2] =
    controller_pole_placement_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S22>/Delay6' incorporates:
  //   Delay: '<S22>/Delay5'
  //
  controller_pole_placement_DW.Delay6_DSTATE[2] =
    controller_pole_placement_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S22>/Delay5' incorporates:
  //   Delay: '<S22>/Delay4'
  //
  controller_pole_placement_DW.Delay5_DSTATE[2] =
    controller_pole_placement_DW.Delay4_DSTATE[2];

  // Update for Delay: '<S22>/Delay4' incorporates:
  //   Delay: '<S22>/Delay3'
  //
  controller_pole_placement_DW.Delay4_DSTATE[2] =
    controller_pole_placement_DW.Delay3_DSTATE_d[2];

  // Update for Delay: '<S22>/Delay3' incorporates:
  //   Delay: '<S22>/Delay2'
  //
  controller_pole_placement_DW.Delay3_DSTATE_d[2] =
    controller_pole_placement_DW.Delay2_DSTATE_i[2];

  // Update for Delay: '<S22>/Delay2' incorporates:
  //   Delay: '<S22>/Delay1'
  //
  controller_pole_placement_DW.Delay2_DSTATE_i[2] =
    controller_pole_placement_DW.Delay1_DSTATE[2];

  // Update for Delay: '<S22>/Delay1' incorporates:
  //   Delay: '<S22>/Delay'
  //
  controller_pole_placement_DW.Delay1_DSTATE[2] =
    controller_pole_placement_DW.Delay_DSTATE[2];

  // Update for Delay: '<S22>/Delay'
  controller_pole_placement_DW.Delay_DSTATE[2] =
    controller_pole_placement_B.Delay2_DSTATE;

  // Update for Delay: '<S18>/Delay1' incorporates:
  //   Delay: '<S18>/Delay'

  controller_pole_placement_DW.Delay1_DSTATE_p[2] =
    controller_pole_placement_B.Delay_DSTATE_p;

  // Update for Delay: '<S18>/Delay2' incorporates:
  //   Delay: '<S18>/Delay1'

  controller_pole_placement_DW.Delay2_DSTATE_p[2] =
    controller_pole_placement_B.Delay1_DSTATE_p;

  // Update for Delay: '<S18>/Delay3' incorporates:
  //   Delay: '<S18>/Delay2'

  controller_pole_placement_DW.Delay3_DSTATE_j[2] =
    controller_pole_placement_B.Delay2_DSTATE_p;

  // Update for Delay: '<S18>/Delay4' incorporates:
  //   Delay: '<S18>/Delay3'

  controller_pole_placement_DW.Delay4_DSTATE_e[2] =
    controller_pole_placement_B.Delay3_DSTATE_j;

  // Update for Delay: '<S18>/Delay5' incorporates:
  //   Delay: '<S18>/Delay4'

  controller_pole_placement_DW.Delay5_DSTATE_p[2] =
    controller_pole_placement_B.Delay4_DSTATE_e;

  // Update for Delay: '<S18>/Delay6' incorporates:
  //   Delay: '<S18>/Delay5'

  controller_pole_placement_DW.Delay6_DSTATE_p[2] =
    controller_pole_placement_B.Delay5_DSTATE_p;

  // Update for Delay: '<S18>/Delay7' incorporates:
  //   Delay: '<S18>/Delay6'

  controller_pole_placement_DW.Delay7_DSTATE_o[2] =
    controller_pole_placement_B.Delay6_DSTATE_p;

  // Update for Delay: '<S18>/Delay8' incorporates:
  //   Delay: '<S18>/Delay7'

  controller_pole_placement_DW.Delay8_DSTATE_n[2] =
    controller_pole_placement_B.Delay7_DSTATE_o;

  // Update for Delay: '<S18>/Delay9' incorporates:
  //   Delay: '<S18>/Delay8'

  controller_pole_placement_DW.Delay9_DSTATE_i[2] =
    controller_pole_placement_B.Delay8_DSTATE_n;

  // Update for Delay: '<S18>/Delay10' incorporates:
  //   Delay: '<S18>/Delay9'

  controller_pole_placement_DW.Delay10_DSTATE_f[2] =
    controller_pole_placement_B.Delay9_DSTATE_i;

  // Update for Delay: '<S18>/Delay11' incorporates:
  //   Delay: '<S18>/Delay10'

  controller_pole_placement_DW.Delay11_DSTATE_k[2] =
    controller_pole_placement_B.Delay10_DSTATE_f;

  // Update for Delay: '<S18>/Delay12' incorporates:
  //   Delay: '<S18>/Delay11'

  controller_pole_placement_DW.Delay12_DSTATE_n[2] =
    controller_pole_placement_B.Delay11_DSTATE_k;

  // Update for Delay: '<S18>/Delay13' incorporates:
  //   Delay: '<S18>/Delay12'

  controller_pole_placement_DW.Delay13_DSTATE_g[2] =
    controller_pole_placement_B.Delay12_DSTATE_n;

  // Update for Delay: '<S18>/Delay14' incorporates:
  //   Delay: '<S18>/Delay13'

  controller_pole_placement_DW.Delay14_DSTATE_g[2] =
    controller_pole_placement_B.Delay13_DSTATE_g;

  // Update for Delay: '<S18>/Delay15' incorporates:
  //   Delay: '<S18>/Delay14'

  controller_pole_placement_DW.Delay15_DSTATE[2] =
    controller_pole_placement_B.Delay14_DSTATE_g;

  // Update for Delay: '<S18>/Delay20' incorporates:
  //   Delay: '<S18>/Delay15'

  controller_pole_placement_DW.Delay20_DSTATE_h[2] =
    controller_pole_placement_B.Delay15_DSTATE;

  // Update for Delay: '<S18>/Delay21' incorporates:
  //   Delay: '<S18>/Delay20'

  controller_pole_placement_DW.Delay21_DSTATE_d[2] =
    controller_pole_placement_B.Delay20_DSTATE_h;

  // Update for Delay: '<S18>/Delay22' incorporates:
  //   Delay: '<S18>/Delay21'

  controller_pole_placement_DW.Delay22_DSTATE_h[2] =
    controller_pole_placement_B.Delay21_DSTATE_d;

  // Update for Delay: '<S18>/Delay23' incorporates:
  //   Delay: '<S18>/Delay22'

  controller_pole_placement_DW.Delay23_DSTATE_p[2] =
    controller_pole_placement_B.Delay22_DSTATE_h;

  // Update for Delay: '<S18>/Delay24' incorporates:
  //   Delay: '<S18>/Delay23'

  controller_pole_placement_DW.Delay24_DSTATE[2] =
    controller_pole_placement_B.Delay23_DSTATE_p;

  // Update for Delay: '<S18>/Delay25' incorporates:
  //   Delay: '<S18>/Delay24'

  controller_pole_placement_DW.Delay25_DSTATE[2] =
    controller_pole_placement_B.Delay24_DSTATE;

  // Update for Delay: '<S18>/Delay26' incorporates:
  //   Delay: '<S18>/Delay25'

  controller_pole_placement_DW.Delay26_DSTATE[2] =
    controller_pole_placement_B.Delay25_DSTATE;

  // Update for Delay: '<S18>/Delay27' incorporates:
  //   Delay: '<S18>/Delay26'

  controller_pole_placement_DW.Delay27_DSTATE[2] =
    controller_pole_placement_B.Delay26_DSTATE;

  // Update for Delay: '<S18>/Delay16' incorporates:
  //   Delay: '<S18>/Delay27'

  controller_pole_placement_DW.Delay16_DSTATE[2] =
    controller_pole_placement_B.Delay27_DSTATE;

  // Update for Delay: '<S18>/Delay17' incorporates:
  //   Delay: '<S18>/Delay16'

  controller_pole_placement_DW.Delay17_DSTATE[2] =
    controller_pole_placement_B.Delay16_DSTATE;

  // Update for Delay: '<S18>/Delay18' incorporates:
  //   Delay: '<S18>/Delay17'

  controller_pole_placement_DW.Delay18_DSTATE[2] =
    controller_pole_placement_B.Delay17_DSTATE;

  // Update for Delay: '<S18>/Delay19' incorporates:
  //   Delay: '<S18>/Delay18'

  controller_pole_placement_DW.Delay19_DSTATE[2] =
    controller_pole_placement_B.Delay18_DSTATE;

  // Update for Delay: '<S20>/Delay2' incorporates:
  //   Delay: '<S23>/Delay2'

  controller_pole_placement_DW.Delay2_DSTATE_l[2] =
    controller_pole_placement_DW.Delay2_DSTATE_n[2];

  // Update for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn'
  controller_pole_placement_DW.DiscreteTransferFcn_states_a =
    (controller_pole_placement_B.u_vect[0] -
     controller_pole_placement_P.DiscreteTransferFcn_DenCoef_j[1] *
     controller_pole_placement_DW.DiscreteTransferFcn_states_a) /
    controller_pole_placement_P.DiscreteTransferFcn_DenCoef_j[0];

  // Update for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn1'
  controller_pole_placement_DW.DiscreteTransferFcn1_states_e =
    (controller_pole_placement_B.u_vect[1] -
     controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_o[1] *
     controller_pole_placement_DW.DiscreteTransferFcn1_states_e) /
    controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_o[0];

  // Update for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2'
  controller_pole_placement_DW.DiscreteTransferFcn2_states_p =
    (controller_pole_placement_B.u_vect[2] -
     controller_pole_placement_P.DiscreteTransferFcn2_DenCoef_i[1] *
     controller_pole_placement_DW.DiscreteTransferFcn2_states_p) /
    controller_pole_placement_P.DiscreteTransferFcn2_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S41>/Discrete Transfer Fcn1'
  controller_pole_placement_DW.DiscreteTransferFcn1_states_eg =
    (controller_pole_placement_B.tth -
     controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_a[1] *
     controller_pole_placement_DW.DiscreteTransferFcn1_states_eg) /
    controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_a[0];

  // Update for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn'
  controller_pole_placement_DW.DiscreteTransferFcn_states_f =
    (controller_pole_placement_B.TmpSignalConversionAtSFunct[0] -
     controller_pole_placement_P.DiscreteTransferFcn_DenCoef_i[1] *
     controller_pole_placement_DW.DiscreteTransferFcn_states_f) /
    controller_pole_placement_P.DiscreteTransferFcn_DenCoef_i[0];

  // Update for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn1'
  controller_pole_placement_DW.DiscreteTransferFcn1_states_d =
    (controller_pole_placement_B.TmpSignalConversionAtSFunct[1] -
     controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_m[1] *
     controller_pole_placement_DW.DiscreteTransferFcn1_states_d) /
    controller_pole_placement_P.DiscreteTransferFcn1_DenCoef_m[0];

  // Update for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn2'
  controller_pole_placement_DW.DiscreteTransferFcn2_states_p2 =
    (controller_pole_placement_B.TmpSignalConversionAtSFunct[2] -
     controller_pole_placement_P.DiscreteTransferFcn2_DenCoef_e[1] *
     controller_pole_placement_DW.DiscreteTransferFcn2_states_p2) /
    controller_pole_placement_P.DiscreteTransferFcn2_DenCoef_e[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controller_pole_placement_M->Timing.taskTime0 =
    ((time_T)(++controller_pole_placement_M->Timing.clockTick0)) *
    controller_pole_placement_M->Timing.stepSize0;
}

// Model initialize function
void controller_pole_placement_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controller_pole_placement_M, -1);
  controller_pole_placement_M->Timing.stepSize0 = 0.01;

  // External mode info
  controller_pole_placement_M->Sizes.checksums[0] = (3513929119U);
  controller_pole_placement_M->Sizes.checksums[1] = (3000140195U);
  controller_pole_placement_M->Sizes.checksums[2] = (3888302084U);
  controller_pole_placement_M->Sizes.checksums[3] = (2879789181U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[41];
    controller_pole_placement_M->extModeInfo = (&rt_ExtModeInfo);
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
      &controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = (sysRanDType *)
      &controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_js;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = (sysRanDType *)
      &controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC_j;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = (sysRanDType *)
      &controller_pole_placement_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &controller_pole_placement_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &controller_pole_placement_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &controller_pole_placement_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_pole_placement_M->extModeInfo,
      &controller_pole_placement_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_pole_placement_M->extModeInfo,
                        controller_pole_placement_M->Sizes.checksums);
    rteiSetTPtr(controller_pole_placement_M->extModeInfo, rtmGetTPtr
                (controller_pole_placement_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Delay: '<S6>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE =
      controller_pole_placement_P.Delay3_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S42>/Internal'
    controller_pole_placement_DW.Internal_DSTATE =
      controller_pole_placement_P.Internal_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn' 
    controller_pole_placement_DW.DiscreteTransferFcn_states =
      controller_pole_placement_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn1' 
    controller_pole_placement_DW.DiscreteTransferFcn1_states =
      controller_pole_placement_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S16>/Discrete Transfer Fcn2' 
    controller_pole_placement_DW.DiscreteTransferFcn2_states =
      controller_pole_placement_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S6>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE[0] =
      controller_pole_placement_P.Delay2_InitialCondition[0];

    // InitializeConditions for Delay: '<S22>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE[0] =
      controller_pole_placement_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE[0] =
      controller_pole_placement_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE[0] =
      controller_pole_placement_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE[0] =
      controller_pole_placement_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE[0] =
      controller_pole_placement_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE[0] =
      controller_pole_placement_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE[0] =
      controller_pole_placement_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE[0] =
      controller_pole_placement_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE[0] =
      controller_pole_placement_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE[0] =
      controller_pole_placement_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE[0] =
      controller_pole_placement_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE[0] =
      controller_pole_placement_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE[0] =
      controller_pole_placement_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE[0] =
      controller_pole_placement_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE[0] =
      controller_pole_placement_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_d[0] =
      controller_pole_placement_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S22>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_i[0] =
      controller_pole_placement_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S22>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE[0] =
      controller_pole_placement_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay'
    controller_pole_placement_DW.Delay_DSTATE[0] =
      controller_pole_placement_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    controller_pole_placement_DW.Delay_DSTATE_p[0] =
      controller_pole_placement_P.Delay_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S18>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE_p[0] =
      controller_pole_placement_P.Delay1_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S18>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_p[0] =
      controller_pole_placement_P.Delay2_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S18>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_j[0] =
      controller_pole_placement_P.Delay3_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S18>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE_e[0] =
      controller_pole_placement_P.Delay4_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S18>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE_p[0] =
      controller_pole_placement_P.Delay5_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S18>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE_p[0] =
      controller_pole_placement_P.Delay6_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S18>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE_o[0] =
      controller_pole_placement_P.Delay7_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S18>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE_n[0] =
      controller_pole_placement_P.Delay8_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S18>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE_i[0] =
      controller_pole_placement_P.Delay9_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S18>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE_f[0] =
      controller_pole_placement_P.Delay10_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S18>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE_k[0] =
      controller_pole_placement_P.Delay11_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S18>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE_n[0] =
      controller_pole_placement_P.Delay12_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S18>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE_g[0] =
      controller_pole_placement_P.Delay13_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S18>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE_g[0] =
      controller_pole_placement_P.Delay14_InitialCondition_o[0];

    // InitializeConditions for Delay: '<S18>/Delay15'
    controller_pole_placement_DW.Delay15_DSTATE[0] =
      controller_pole_placement_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE_h[0] =
      controller_pole_placement_P.Delay20_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S18>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE_d[0] =
      controller_pole_placement_P.Delay21_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S18>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE_h[0] =
      controller_pole_placement_P.Delay22_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S18>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE_p[0] =
      controller_pole_placement_P.Delay23_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S18>/Delay24'
    controller_pole_placement_DW.Delay24_DSTATE[0] =
      controller_pole_placement_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay25'
    controller_pole_placement_DW.Delay25_DSTATE[0] =
      controller_pole_placement_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay26'
    controller_pole_placement_DW.Delay26_DSTATE[0] =
      controller_pole_placement_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay27'
    controller_pole_placement_DW.Delay27_DSTATE[0] =
      controller_pole_placement_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay16'
    controller_pole_placement_DW.Delay16_DSTATE[0] =
      controller_pole_placement_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay17'
    controller_pole_placement_DW.Delay17_DSTATE[0] =
      controller_pole_placement_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay18'
    controller_pole_placement_DW.Delay18_DSTATE[0] =
      controller_pole_placement_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S18>/Delay19'
    controller_pole_placement_DW.Delay19_DSTATE[0] =
      controller_pole_placement_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S6>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE[1] =
      controller_pole_placement_P.Delay2_InitialCondition[1];

    // InitializeConditions for Delay: '<S22>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE[1] =
      controller_pole_placement_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE[1] =
      controller_pole_placement_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE[1] =
      controller_pole_placement_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE[1] =
      controller_pole_placement_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE[1] =
      controller_pole_placement_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE[1] =
      controller_pole_placement_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE[1] =
      controller_pole_placement_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE[1] =
      controller_pole_placement_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE[1] =
      controller_pole_placement_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE[1] =
      controller_pole_placement_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE[1] =
      controller_pole_placement_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE[1] =
      controller_pole_placement_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE[1] =
      controller_pole_placement_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE[1] =
      controller_pole_placement_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE[1] =
      controller_pole_placement_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_d[1] =
      controller_pole_placement_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S22>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_i[1] =
      controller_pole_placement_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S22>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE[1] =
      controller_pole_placement_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay'
    controller_pole_placement_DW.Delay_DSTATE[1] =
      controller_pole_placement_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    controller_pole_placement_DW.Delay_DSTATE_p[1] =
      controller_pole_placement_P.Delay_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S18>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE_p[1] =
      controller_pole_placement_P.Delay1_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S18>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_p[1] =
      controller_pole_placement_P.Delay2_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S18>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_j[1] =
      controller_pole_placement_P.Delay3_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S18>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE_e[1] =
      controller_pole_placement_P.Delay4_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S18>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE_p[1] =
      controller_pole_placement_P.Delay5_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S18>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE_p[1] =
      controller_pole_placement_P.Delay6_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S18>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE_o[1] =
      controller_pole_placement_P.Delay7_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S18>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE_n[1] =
      controller_pole_placement_P.Delay8_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S18>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE_i[1] =
      controller_pole_placement_P.Delay9_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S18>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE_f[1] =
      controller_pole_placement_P.Delay10_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S18>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE_k[1] =
      controller_pole_placement_P.Delay11_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S18>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE_n[1] =
      controller_pole_placement_P.Delay12_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S18>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE_g[1] =
      controller_pole_placement_P.Delay13_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S18>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE_g[1] =
      controller_pole_placement_P.Delay14_InitialCondition_o[1];

    // InitializeConditions for Delay: '<S18>/Delay15'
    controller_pole_placement_DW.Delay15_DSTATE[1] =
      controller_pole_placement_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE_h[1] =
      controller_pole_placement_P.Delay20_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S18>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE_d[1] =
      controller_pole_placement_P.Delay21_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S18>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE_h[1] =
      controller_pole_placement_P.Delay22_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S18>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE_p[1] =
      controller_pole_placement_P.Delay23_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S18>/Delay24'
    controller_pole_placement_DW.Delay24_DSTATE[1] =
      controller_pole_placement_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay25'
    controller_pole_placement_DW.Delay25_DSTATE[1] =
      controller_pole_placement_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay26'
    controller_pole_placement_DW.Delay26_DSTATE[1] =
      controller_pole_placement_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay27'
    controller_pole_placement_DW.Delay27_DSTATE[1] =
      controller_pole_placement_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay16'
    controller_pole_placement_DW.Delay16_DSTATE[1] =
      controller_pole_placement_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay17'
    controller_pole_placement_DW.Delay17_DSTATE[1] =
      controller_pole_placement_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay18'
    controller_pole_placement_DW.Delay18_DSTATE[1] =
      controller_pole_placement_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S18>/Delay19'
    controller_pole_placement_DW.Delay19_DSTATE[1] =
      controller_pole_placement_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S6>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE[2] =
      controller_pole_placement_P.Delay2_InitialCondition[2];

    // InitializeConditions for Delay: '<S22>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE[2] =
      controller_pole_placement_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE[2] =
      controller_pole_placement_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE[2] =
      controller_pole_placement_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE[2] =
      controller_pole_placement_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE[2] =
      controller_pole_placement_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE[2] =
      controller_pole_placement_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE[2] =
      controller_pole_placement_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE[2] =
      controller_pole_placement_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE[2] =
      controller_pole_placement_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE[2] =
      controller_pole_placement_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE[2] =
      controller_pole_placement_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE[2] =
      controller_pole_placement_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE[2] =
      controller_pole_placement_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE[2] =
      controller_pole_placement_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE[2] =
      controller_pole_placement_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_d[2] =
      controller_pole_placement_P.Delay3_InitialCondition_d;

    // InitializeConditions for Delay: '<S22>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_i[2] =
      controller_pole_placement_P.Delay2_InitialCondition_k;

    // InitializeConditions for Delay: '<S22>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE[2] =
      controller_pole_placement_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S22>/Delay'
    controller_pole_placement_DW.Delay_DSTATE[2] =
      controller_pole_placement_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S18>/Delay'
    controller_pole_placement_DW.Delay_DSTATE_p[2] =
      controller_pole_placement_P.Delay_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S18>/Delay1'
    controller_pole_placement_DW.Delay1_DSTATE_p[2] =
      controller_pole_placement_P.Delay1_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S18>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_p[2] =
      controller_pole_placement_P.Delay2_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S18>/Delay3'
    controller_pole_placement_DW.Delay3_DSTATE_j[2] =
      controller_pole_placement_P.Delay3_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S18>/Delay4'
    controller_pole_placement_DW.Delay4_DSTATE_e[2] =
      controller_pole_placement_P.Delay4_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S18>/Delay5'
    controller_pole_placement_DW.Delay5_DSTATE_p[2] =
      controller_pole_placement_P.Delay5_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S18>/Delay6'
    controller_pole_placement_DW.Delay6_DSTATE_p[2] =
      controller_pole_placement_P.Delay6_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S18>/Delay7'
    controller_pole_placement_DW.Delay7_DSTATE_o[2] =
      controller_pole_placement_P.Delay7_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S18>/Delay8'
    controller_pole_placement_DW.Delay8_DSTATE_n[2] =
      controller_pole_placement_P.Delay8_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S18>/Delay9'
    controller_pole_placement_DW.Delay9_DSTATE_i[2] =
      controller_pole_placement_P.Delay9_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S18>/Delay10'
    controller_pole_placement_DW.Delay10_DSTATE_f[2] =
      controller_pole_placement_P.Delay10_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S18>/Delay11'
    controller_pole_placement_DW.Delay11_DSTATE_k[2] =
      controller_pole_placement_P.Delay11_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S18>/Delay12'
    controller_pole_placement_DW.Delay12_DSTATE_n[2] =
      controller_pole_placement_P.Delay12_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S18>/Delay13'
    controller_pole_placement_DW.Delay13_DSTATE_g[2] =
      controller_pole_placement_P.Delay13_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S18>/Delay14'
    controller_pole_placement_DW.Delay14_DSTATE_g[2] =
      controller_pole_placement_P.Delay14_InitialCondition_o[2];

    // InitializeConditions for Delay: '<S18>/Delay15'
    controller_pole_placement_DW.Delay15_DSTATE[2] =
      controller_pole_placement_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay20'
    controller_pole_placement_DW.Delay20_DSTATE_h[2] =
      controller_pole_placement_P.Delay20_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S18>/Delay21'
    controller_pole_placement_DW.Delay21_DSTATE_d[2] =
      controller_pole_placement_P.Delay21_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S18>/Delay22'
    controller_pole_placement_DW.Delay22_DSTATE_h[2] =
      controller_pole_placement_P.Delay22_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S18>/Delay23'
    controller_pole_placement_DW.Delay23_DSTATE_p[2] =
      controller_pole_placement_P.Delay23_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S18>/Delay24'
    controller_pole_placement_DW.Delay24_DSTATE[2] =
      controller_pole_placement_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay25'
    controller_pole_placement_DW.Delay25_DSTATE[2] =
      controller_pole_placement_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay26'
    controller_pole_placement_DW.Delay26_DSTATE[2] =
      controller_pole_placement_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay27'
    controller_pole_placement_DW.Delay27_DSTATE[2] =
      controller_pole_placement_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay16'
    controller_pole_placement_DW.Delay16_DSTATE[2] =
      controller_pole_placement_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay17'
    controller_pole_placement_DW.Delay17_DSTATE[2] =
      controller_pole_placement_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay18'
    controller_pole_placement_DW.Delay18_DSTATE[2] =
      controller_pole_placement_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S18>/Delay19'
    controller_pole_placement_DW.Delay19_DSTATE[2] =
      controller_pole_placement_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S20>/Memory4'
    for (i = 0; i < 5; i++) {
      controller_pole_placement_DW.Memory4_PreviousInput[i] =
        controller_pole_placement_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S20>/Memory4'

    // InitializeConditions for Delay: '<S20>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_l[0] =
      controller_pole_placement_P.Delay2_InitialCondition_kt;
    controller_pole_placement_DW.Delay2_DSTATE_l[1] =
      controller_pole_placement_P.Delay2_InitialCondition_kt;
    controller_pole_placement_DW.Delay2_DSTATE_l[2] =
      controller_pole_placement_P.Delay2_InitialCondition_kt;

    // InitializeConditions for Memory: '<S20>/Memory2'
    controller_pole_placement_DW.Memory2_PreviousInput =
      controller_pole_placement_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S20>/Memory3'
    memcpy(&controller_pole_placement_DW.Memory3_PreviousInput[0],
           &controller_pole_placement_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S23>/Memory4'
    controller_pole_placement_DW.Memory4_PreviousInput_k =
      controller_pole_placement_P.x0_ps;

    // InitializeConditions for Memory: '<S23>/Memory3'
    controller_pole_placement_DW.Memory3_PreviousInput_f =
      controller_pole_placement_P.P0_ps;

    // InitializeConditions for Memory: '<S23>/Memory2'
    controller_pole_placement_DW.Memory2_PreviousInput_b =
      controller_pole_placement_P.Memory2_InitialCondition_h;

    // InitializeConditions for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn' 
    controller_pole_placement_DW.DiscreteTransferFcn_states_a =
      controller_pole_placement_P.DiscreteTransferFcn_InitialSt_e;

    // InitializeConditions for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn1' 
    controller_pole_placement_DW.DiscreteTransferFcn1_states_e =
      controller_pole_placement_P.DiscreteTransferFcn1_InitialS_j;

    // InitializeConditions for DiscreteTransferFcn: '<S17>/Discrete Transfer Fcn2' 
    controller_pole_placement_DW.DiscreteTransferFcn2_states_p =
      controller_pole_placement_P.DiscreteTransferFcn2_InitialS_c;

    // InitializeConditions for Memory: '<S11>/Memory5'
    controller_pole_placement_DW.Memory5_PreviousInput =
      controller_pole_placement_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_n[0] =
      controller_pole_placement_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S11>/Memory6'
    controller_pole_placement_DW.Memory6_PreviousInput[0] =
      controller_pole_placement_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_n[1] =
      controller_pole_placement_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S11>/Memory6'
    controller_pole_placement_DW.Memory6_PreviousInput[1] =
      controller_pole_placement_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S23>/Delay2'
    controller_pole_placement_DW.Delay2_DSTATE_n[2] =
      controller_pole_placement_P.Delay2_InitialCondition_a;

    // InitializeConditions for Memory: '<S11>/Memory6'
    controller_pole_placement_DW.Memory6_PreviousInput[2] =
      controller_pole_placement_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S41>/Discrete Transfer Fcn1' 
    controller_pole_placement_DW.DiscreteTransferFcn1_states_eg =
      controller_pole_placement_P.DiscreteTransferFcn1_InitialS_h;

    // InitializeConditions for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn' 
    controller_pole_placement_DW.DiscreteTransferFcn_states_f =
      controller_pole_placement_P.DiscreteTransferFcn_InitialSt_i;

    // InitializeConditions for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn1' 
    controller_pole_placement_DW.DiscreteTransferFcn1_states_d =
      controller_pole_placement_P.DiscreteTransferFcn1_InitialS_g;

    // InitializeConditions for DiscreteTransferFcn: '<S15>/Discrete Transfer Fcn2' 
    controller_pole_placement_DW.DiscreteTransferFcn2_states_p2 =
      controller_pole_placement_P.DiscreteTransferFcn2_InitialS_o;

    // SystemInitialize for Enabled SubSystem: '<S68>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S69>/In1' incorporates:
    //   Outport: '<S69>/Out1'

    controller_pole_placement_B.In1 = controller_pole_placement_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S68>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S58>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S59>/In1' incorporates:
    //   Outport: '<S59>/Out1'

    controller_pole_placement_B.In1_f = controller_pole_placement_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S58>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S54>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S55>/In1' incorporates:
    //   Outport: '<S55>/Out1'

    controller_pole_placement_B.In1_i = controller_pole_placement_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S54>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S56>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S57>/In1' incorporates:
    //   Outport: '<S57>/Out1'

    controller_pole_placement_B.In1_n = controller_pole_placement_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S56>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S12>/MATLAB Function7'
    controller_MATLABFunction1_Init
      (&controller_pole_placement_DW.sf_MATLABFunction7);

    // SystemInitialize for MATLAB Function: '<S3>/MATLAB Function1'
    controller_MATLABFunction1_Init
      (&controller_pole_placement_DW.sf_MATLABFunction1_i);

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S40>/In1' incorporates:
    //   Outport: '<S40>/Out1'

    controller_pole_placement_B.In1_h = controller_pole_placement_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S68>/SourceBlock'
    controller_pole_placement_DW.obj_c.matlabCodegenIsDeleted = false;
    controller_pole_placement_DW.obj_c.isInitialized = 1;
    controller_pole_placement_DW.obj_c.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_pole_placement_DW.obj_c.orbMetadataObj,
                         &controller_pole_placement_DW.obj_c.eventStructObj);
    controller_pole_placement_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S58>/SourceBlock'
    controller_pole_placement_DW.obj_h.matlabCodegenIsDeleted = false;
    controller_pole_placement_DW.obj_h.isInitialized = 1;
    controller_pole_placement_DW.obj_h.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(controller_pole_placement_DW.obj_h.orbMetadataObj,
                         &controller_pole_placement_DW.obj_h.eventStructObj);
    controller_pole_placement_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S54>/SourceBlock'
    controller_pole_placement_DW.obj_jj.matlabCodegenIsDeleted = false;
    controller_pole_placement_DW.obj_jj.isInitialized = 1;
    controller_pole_placement_DW.obj_jj.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_pole_placement_DW.obj_jj.orbMetadataObj,
                         &controller_pole_placement_DW.obj_jj.eventStructObj);
    controller_pole_placement_DW.obj_jj.isSetupComplete = true;

    // Start for MATLABSystem: '<S56>/SourceBlock'
    controller_pole_placement_DW.obj_j.matlabCodegenIsDeleted = false;
    controller_pole_placement_DW.obj_j.isInitialized = 1;
    controller_pole_placement_DW.obj_j.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_pole_placement_DW.obj_j.orbMetadataObj,
                         &controller_pole_placement_DW.obj_j.eventStructObj);
    controller_pole_placement_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/PX4 PWM Output' incorporates:
    //   Constant: '<S4>/failsafe'

    controller_pole_placement_DW.obj.errorStatus = 0U;
    controller_pole_placement_DW.obj.isInitialized = 0;
    controller_pole_placement_DW.obj.matlabCodegenIsDeleted = false;
    controller_pol_SystemCore_setup(&controller_pole_placement_DW.obj,
      rtb_startingswitch, controller_pole_placement_P.failsafe_Value);

    // Start for MATLABSystem: '<S5>/SourceBlock'
    controller_pole_placement_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_pole_placement_DW.obj_d.isInitialized = 1;
    controller_pole_placement_DW.obj_d.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(controller_pole_placement_DW.obj_d.orbMetadataObj,
                         &controller_pole_placement_DW.obj_d.eventStructObj);
    controller_pole_placement_DW.obj_d.isSetupComplete = true;
  }
}

// Model terminate function
void controller_pole_placement_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S68>/SourceBlock'
  if (!controller_pole_placement_DW.obj_c.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj_c.isInitialized == 1) &&
        controller_pole_placement_DW.obj_c.isSetupComplete) {
      uORB_read_terminate(&controller_pole_placement_DW.obj_c.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S68>/SourceBlock'

  // Terminate for MATLABSystem: '<S58>/SourceBlock'
  if (!controller_pole_placement_DW.obj_h.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj_h.isInitialized == 1) &&
        controller_pole_placement_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&controller_pole_placement_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S58>/SourceBlock'

  // Terminate for MATLABSystem: '<S54>/SourceBlock'
  if (!controller_pole_placement_DW.obj_jj.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj_jj.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj_jj.isInitialized == 1) &&
        controller_pole_placement_DW.obj_jj.isSetupComplete) {
      uORB_read_terminate(&controller_pole_placement_DW.obj_jj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S54>/SourceBlock'

  // Terminate for MATLABSystem: '<S56>/SourceBlock'
  if (!controller_pole_placement_DW.obj_j.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj_j.isInitialized == 1) &&
        controller_pole_placement_DW.obj_j.isSetupComplete) {
      uORB_read_terminate(&controller_pole_placement_DW.obj_j.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S56>/SourceBlock'
  // Terminate for MATLABSystem: '<S4>/PX4 PWM Output'
  if (!controller_pole_placement_DW.obj.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj.isInitialized == 1) &&
        controller_pole_placement_DW.obj.isSetupComplete) {
      status = pwm_disarm(&controller_pole_placement_DW.obj.pwmDevHandler,
                          &controller_pole_placement_DW.obj.armAdvertiseObj);
      controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_pole_placement_DW.obj.errorStatus | status);
      status = pwm_resetServo(&controller_pole_placement_DW.obj.pwmDevHandler,
        controller_pole_placement_DW.obj.servoCount,
        controller_pole_placement_DW.obj.channelMask,
        controller_pole_placement_DW.obj.isMain,
        &controller_pole_placement_DW.obj.actuatorAdvertiseObj);
      controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_pole_placement_DW.obj.errorStatus | status);
      status = pwm_close(&controller_pole_placement_DW.obj.pwmDevHandler,
                         &controller_pole_placement_DW.obj.actuatorAdvertiseObj,
                         &controller_pole_placement_DW.obj.armAdvertiseObj);
      controller_pole_placement_DW.obj.errorStatus = static_cast<uint16_T>
        (controller_pole_placement_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!controller_pole_placement_DW.obj_d.matlabCodegenIsDeleted) {
    controller_pole_placement_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_pole_placement_DW.obj_d.isInitialized == 1) &&
        controller_pole_placement_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_pole_placement_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
