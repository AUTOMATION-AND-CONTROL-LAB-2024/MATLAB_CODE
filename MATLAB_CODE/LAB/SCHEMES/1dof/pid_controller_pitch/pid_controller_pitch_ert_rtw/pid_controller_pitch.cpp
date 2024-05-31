//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_controller_pitch.cpp
//
// Code generated for Simulink model 'pid_controller_pitch'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 15:38:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pid_controller_pitch.h"
#include "rtwtypes.h"
#include "pid_controller_pitch_types.h"
#include "pid_controller_pitch_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include <string.h>
#include "rt_defines.h"

// Named constants for MATLAB Function: '<S4>/MATLAB Function1'
const int32_T pid_controller_pitch_CALL_EVENT = -1;

// Block signals (default storage)
B_pid_controller_pitch_T pid_controller_pitch_B;

// Block states (default storage)
DW_pid_controller_pitch_T pid_controller_pitch_DW;

// Real-time model
RT_MODEL_pid_controller_pitch_T pid_controller_pitch_M_ =
  RT_MODEL_pid_controller_pitch_T();
RT_MODEL_pid_controller_pitch_T *const pid_controller_pitch_M =
  &pid_controller_pitch_M_;

// Forward declaration for local functions
static void pid_controller_SystemCore_setup(px4_internal_block_PWM_pid_co_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

//
// System initialize for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S19>/MATLAB Function7'
//
void pid_contro_MATLABFunction1_Init(DW_MATLABFunction1_pid_contro_T *localDW)
{
  localDW->sfEvent = pid_controller_pitch_CALL_EVENT;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function1'
//    '<S19>/MATLAB Function7'
//
void pid_controller__MATLABFunction1(const real_T rtu_u[3], real_T *rty_y1,
  real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_pid_contro_T *localDW)
{
  localDW->sfEvent = pid_controller_pitch_CALL_EVENT;
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

static void pid_controller_SystemCore_setup(px4_internal_block_PWM_pid_co_T *obj,
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
void pid_controller_pitch_step(void)
{
  int32_T At1_tmp;
  int32_T Pt1_tmp;
  int32_T i;
  real32_T rtb_Product1;
  real32_T rtb_Product2;
  real32_T rtb_fcn3;
  real32_T rtb_fcn5;
  real32_T y_f_tmp;
  real32_T y_f_tmp_0;
  real32_T y_f_tmp_1;
  real32_T y_f_tmp_2;
  uint16_T rtb_DataTypeConversion1_ds;
  uint16_T rtb_DataTypeConversion1_e;
  uint16_T rtb_DataTypeConversion1_f;
  uint16_T rtb_DataTypeConversion1_g;
  boolean_T b_varargout_1;
  boolean_T rtb_startingswitch;
  static const int8_T c[10] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 };

  static const int8_T b_b[10] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_kv);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_h);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock1' incorporates:
  //   DigitalClock: '<S18>/Discrete Time1'
  //   DigitalClock: '<S27>/Discrete Time'
  //   DigitalClock: '<S30>/Discrete Time'
  //   Step: '<Root>/RPY ref'

  pid_controller_pitch_B.DigitalClock1 =
    pid_controller_pitch_M->Timing.taskTime0;

  // ManualSwitch: '<Root>/starting switch' incorporates:
  //   Constant: '<Root>/ARM PWM1'
  //   Constant: '<Root>/Constant2'

  if (pid_controller_pitch_P.startingswitch_CurrentSetting == 1) {
    rtb_startingswitch = pid_controller_pitch_P.Constant2_Value;
  } else {
    rtb_startingswitch = pid_controller_pitch_P.ARMPWM1_Value;
  }

  // End of ManualSwitch: '<Root>/starting switch'

  // DiscreteStateSpace: '<S10>/Internal'
  {
    pid_controller_pitch_B.Internal = pid_controller_pitch_P.Internal_C*
      pid_controller_pitch_DW.Internal_DSTATE;
  }

  // Product: '<S1>/Product' incorporates:
  //   Gain: '<S1>/Gain'

  pid_controller_pitch_B.Product = pid_controller_pitch_P.Gain_Gain *
    pid_controller_pitch_B.Internal * static_cast<real_T>(rtb_startingswitch);

  // MATLAB Function: '<S1>/MATLAB Function1'
  if (!rtb_startingswitch) {
    pid_controller_pitch_DW.Delay2_DSTATE[0] = 0.0;
    pid_controller_pitch_DW.Delay2_DSTATE[1] = 0.0;
    pid_controller_pitch_DW.Delay3_DSTATE = 0.0;
  }

  pid_controller_pitch_B.x = (pid_controller_pitch_P.A_cond[0] *
    pid_controller_pitch_DW.Delay2_DSTATE[0] +
    pid_controller_pitch_DW.Delay2_DSTATE[1] * pid_controller_pitch_P.A_cond[2])
    + pid_controller_pitch_P.B_cond[0] * pid_controller_pitch_DW.Delay3_DSTATE;
  pid_controller_pitch_B.x_idx_0 = pid_controller_pitch_B.x;

  // MATLAB Function: '<S1>/MATLAB Function1' incorporates:
  //   Constant: '<S1>/Constant3'
  //   Constant: '<S1>/Constant6'

  pid_controller_pitch_B.At1_tmp = pid_controller_pitch_P.C[0] *
    pid_controller_pitch_B.x;
  pid_controller_pitch_B.x = (pid_controller_pitch_DW.Delay2_DSTATE[0] *
    pid_controller_pitch_P.A_cond[1] + pid_controller_pitch_DW.Delay2_DSTATE[1] *
    pid_controller_pitch_P.A_cond[3]) + pid_controller_pitch_P.B_cond[1] *
    pid_controller_pitch_DW.Delay3_DSTATE;
  pid_controller_pitch_B.u_sat = (pid_controller_pitch_P.C[1] *
    pid_controller_pitch_B.x + pid_controller_pitch_B.At1_tmp) +
    pid_controller_pitch_P.D * pid_controller_pitch_B.Product;
  if ((pid_controller_pitch_P.Constant6_Value <= pid_controller_pitch_B.u_sat) ||
      rtIsNaN(pid_controller_pitch_B.u_sat)) {
    pid_controller_pitch_B.u_sat = pid_controller_pitch_P.Constant6_Value;
  }

  if ((pid_controller_pitch_P.Constant3_Value >= pid_controller_pitch_B.u_sat) ||
      rtIsNaN(pid_controller_pitch_B.u_sat)) {
    pid_controller_pitch_B.u_sat = pid_controller_pitch_P.Constant3_Value;
  }

  // MATLAB Function: '<S1>/MATLAB Function3'
  pid_controller_pitch_B.tau_o[1] = pid_controller_pitch_B.u_sat;
  pid_controller_pitch_B.tau_o[0] = 0.0;
  pid_controller_pitch_B.tau_o[2] = 0.0;

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant3'

  if (pid_controller_pitch_B.tau_o[0] >= 0.0) {
    pid_controller_pitch_B.u[3] = pid_controller_pitch_P.Constant3_Value_n;
    pid_controller_pitch_B.u[2] = (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[7] * pid_controller_pitch_P.Constant3_Value_n
      + pid_controller_pitch_B.tau_o[0]) / (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[6]);
  } else {
    pid_controller_pitch_B.u[2] = pid_controller_pitch_P.Constant3_Value_n;
    pid_controller_pitch_B.u[3] = (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[6] * pid_controller_pitch_P.Constant3_Value_n
      - pid_controller_pitch_B.tau_o[0]) / (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[7]);
  }

  if (pid_controller_pitch_B.tau_o[1] >= 0.0) {
    pid_controller_pitch_B.u[0] = pid_controller_pitch_P.Constant3_Value_n;
    pid_controller_pitch_B.u[1] = (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[4] * pid_controller_pitch_P.Constant3_Value_n
      + pid_controller_pitch_B.tau_o[1]) / (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[5]);
  } else {
    pid_controller_pitch_B.u[1] = pid_controller_pitch_P.Constant3_Value_n;
    pid_controller_pitch_B.u[0] = (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[5] * pid_controller_pitch_P.Constant3_Value_n
      - pid_controller_pitch_B.tau_o[1]) / (pid_controller_pitch_P.param[3] *
      pid_controller_pitch_P.param[4]);
  }

  b_varargout_1 = rtIsNaN(pid_controller_pitch_B.u[0]);
  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[0]) ||
      b_varargout_1) {
    pid_controller_pitch_B.y = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.y = pid_controller_pitch_B.u[0];
  }

  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[0]) ||
      b_varargout_1) {
    pid_controller_pitch_B.minval[0] = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.minval[0] = pid_controller_pitch_B.u[0];
  }

  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[1]) ||
      rtIsNaN(pid_controller_pitch_B.u[1])) {
    pid_controller_pitch_B.y_g = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.y_g = pid_controller_pitch_B.u[1];
  }

  b_varargout_1 = rtIsNaN(pid_controller_pitch_B.u[2]);
  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[2]) ||
      b_varargout_1) {
    pid_controller_pitch_B.y_m = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.y_m = pid_controller_pitch_B.u[2];
  }

  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[2]) ||
      b_varargout_1) {
    pid_controller_pitch_B.minval[2] = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.minval[2] = pid_controller_pitch_B.u[2];
  }

  if ((pid_controller_pitch_P.Constant1_Value_j <= pid_controller_pitch_B.u[3]) ||
      rtIsNaN(pid_controller_pitch_B.u[3])) {
    pid_controller_pitch_B.y_n = pid_controller_pitch_P.Constant1_Value_j;
  } else {
    pid_controller_pitch_B.y_n = pid_controller_pitch_B.u[3];
  }

  pid_controller_pitch_B.dv1[0] = 0.0;
  pid_controller_pitch_B.dv1[3] = 0.0;
  pid_controller_pitch_B.dv1[6] = pid_controller_pitch_P.param[3] *
    pid_controller_pitch_P.param[6];
  pid_controller_pitch_B.dv1[9] = -pid_controller_pitch_P.param[3] *
    pid_controller_pitch_P.param[7];
  pid_controller_pitch_B.dv1[1] = -pid_controller_pitch_P.param[3] *
    pid_controller_pitch_P.param[4];
  pid_controller_pitch_B.dv1[4] = pid_controller_pitch_P.param[3] *
    pid_controller_pitch_P.param[5];
  pid_controller_pitch_B.dv1[7] = 0.0;
  pid_controller_pitch_B.dv1[10] = 0.0;
  pid_controller_pitch_B.dv1[2] = -pid_controller_pitch_P.param[8];
  pid_controller_pitch_B.dv1[5] = -pid_controller_pitch_P.param[8];
  pid_controller_pitch_B.dv1[8] = pid_controller_pitch_P.param[8];
  pid_controller_pitch_B.dv1[11] = pid_controller_pitch_P.param[8];
  pid_controller_pitch_B.rtb_Delay_i_idx_0 = pid_controller_pitch_B.minval[0];
  pid_controller_pitch_B.rtb_Delay1_g_idx_0 = pid_controller_pitch_B.minval[2];
  for (i = 0; i < 3; i++) {
    pid_controller_pitch_B.tau_allocated[i] = ((pid_controller_pitch_B.dv1[i + 3]
      * pid_controller_pitch_B.y_g + pid_controller_pitch_B.dv1[i] *
      pid_controller_pitch_B.rtb_Delay_i_idx_0) + pid_controller_pitch_B.dv1[i +
      6] * pid_controller_pitch_B.rtb_Delay1_g_idx_0) +
      pid_controller_pitch_B.dv1[i + 9] * pid_controller_pitch_B.y_n;
  }

  pid_controller_pitch_B.u[0] = pid_controller_pitch_B.y;
  pid_controller_pitch_B.u[1] = pid_controller_pitch_B.y_g;
  pid_controller_pitch_B.u[2] = pid_controller_pitch_B.y_m;
  pid_controller_pitch_B.u[3] = pid_controller_pitch_B.y_n;

  // End of MATLAB Function: '<Root>/allocation_logic'

  // MATLAB Function: '<Root>/MATLAB Function2'
  pid_controller_pitch_B.u1 = pid_controller_pitch_B.u[0];
  pid_controller_pitch_B.u2 = pid_controller_pitch_B.u[1];
  pid_controller_pitch_B.u3 = pid_controller_pitch_B.u[2];
  pid_controller_pitch_B.u4 = pid_controller_pitch_B.u[3];

  // DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
  //   Constant: '<S42>/Constant'
  //   Sum: '<S42>/Sum'

  pid_controller_pitch_B.At1_tmp = floor(pid_controller_pitch_B.u1 +
    pid_controller_pitch_P.Constant_Value_g);
  if (rtIsNaN(pid_controller_pitch_B.At1_tmp) || rtIsInf
      (pid_controller_pitch_B.At1_tmp)) {
    pid_controller_pitch_B.At1_tmp = 0.0;
  } else {
    pid_controller_pitch_B.At1_tmp = fmod(pid_controller_pitch_B.At1_tmp,
      65536.0);
  }

  rtb_DataTypeConversion1_ds = static_cast<uint16_T>
    (pid_controller_pitch_B.At1_tmp < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-pid_controller_pitch_B.At1_tmp)))) : static_cast<int32_T>
     (static_cast<uint16_T>(pid_controller_pitch_B.At1_tmp)));

  // End of DataTypeConversion: '<S42>/Data Type Conversion1'

  // DataTypeConversion: '<S43>/Data Type Conversion1' incorporates:
  //   Constant: '<S43>/Constant'
  //   Sum: '<S43>/Sum'

  pid_controller_pitch_B.At1_tmp = floor(pid_controller_pitch_B.u2 +
    pid_controller_pitch_P.Constant_Value_e);
  if (rtIsNaN(pid_controller_pitch_B.At1_tmp) || rtIsInf
      (pid_controller_pitch_B.At1_tmp)) {
    pid_controller_pitch_B.At1_tmp = 0.0;
  } else {
    pid_controller_pitch_B.At1_tmp = fmod(pid_controller_pitch_B.At1_tmp,
      65536.0);
  }

  rtb_DataTypeConversion1_f = static_cast<uint16_T>
    (pid_controller_pitch_B.At1_tmp < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-pid_controller_pitch_B.At1_tmp)))) : static_cast<int32_T>
     (static_cast<uint16_T>(pid_controller_pitch_B.At1_tmp)));

  // End of DataTypeConversion: '<S43>/Data Type Conversion1'

  // DataTypeConversion: '<S44>/Data Type Conversion1' incorporates:
  //   Constant: '<S44>/Constant'
  //   Sum: '<S44>/Sum'

  pid_controller_pitch_B.At1_tmp = floor(pid_controller_pitch_B.u3 +
    pid_controller_pitch_P.Constant_Value_l);
  if (rtIsNaN(pid_controller_pitch_B.At1_tmp) || rtIsInf
      (pid_controller_pitch_B.At1_tmp)) {
    pid_controller_pitch_B.At1_tmp = 0.0;
  } else {
    pid_controller_pitch_B.At1_tmp = fmod(pid_controller_pitch_B.At1_tmp,
      65536.0);
  }

  rtb_DataTypeConversion1_e = static_cast<uint16_T>
    (pid_controller_pitch_B.At1_tmp < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-pid_controller_pitch_B.At1_tmp)))) : static_cast<int32_T>
     (static_cast<uint16_T>(pid_controller_pitch_B.At1_tmp)));

  // End of DataTypeConversion: '<S44>/Data Type Conversion1'

  // DataTypeConversion: '<S45>/Data Type Conversion1' incorporates:
  //   Constant: '<S45>/Constant'
  //   Sum: '<S45>/Sum'

  pid_controller_pitch_B.At1_tmp = floor(pid_controller_pitch_B.u4 +
    pid_controller_pitch_P.Constant_Value_eh);
  if (rtIsNaN(pid_controller_pitch_B.At1_tmp) || rtIsInf
      (pid_controller_pitch_B.At1_tmp)) {
    pid_controller_pitch_B.At1_tmp = 0.0;
  } else {
    pid_controller_pitch_B.At1_tmp = fmod(pid_controller_pitch_B.At1_tmp,
      65536.0);
  }

  rtb_DataTypeConversion1_g = static_cast<uint16_T>
    (pid_controller_pitch_B.At1_tmp < 0.0 ? static_cast<int32_T>
     (static_cast<uint16_T>(-static_cast<int16_T>(static_cast<uint16_T>
        (-pid_controller_pitch_B.At1_tmp)))) : static_cast<int32_T>
     (static_cast<uint16_T>(pid_controller_pitch_B.At1_tmp)));

  // End of DataTypeConversion: '<S45>/Data Type Conversion1'

  // MATLABSystem: '<S67>/SourceBlock'
  b_varargout_1 = uORB_read_step(pid_controller_pitch_DW.obj_n.orbMetadataObj,
    &pid_controller_pitch_DW.obj_n.eventStructObj,
    &pid_controller_pitch_B.b_varargout_2, false, 1.0);

  // Outputs for Enabled SubSystem: '<S67>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S68>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S68>/In1'
    pid_controller_pitch_B.In1 = pid_controller_pitch_B.b_varargout_2;
    srUpdateBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S67>/SourceBlock'
  // End of Outputs for SubSystem: '<S67>/Enabled Subsystem'

  // Sqrt: '<S65>/sqrt' incorporates:
  //   Product: '<S66>/Product'
  //   Product: '<S66>/Product1'
  //   Product: '<S66>/Product2'
  //   Product: '<S66>/Product3'
  //   Sum: '<S66>/Sum'

  pid_controller_pitch_B.Product3 = static_cast<real32_T>(sqrt
    (static_cast<real_T>(((pid_controller_pitch_B.In1.q[0] *
    pid_controller_pitch_B.In1.q[0] + pid_controller_pitch_B.In1.q[1] *
    pid_controller_pitch_B.In1.q[1]) + pid_controller_pitch_B.In1.q[2] *
    pid_controller_pitch_B.In1.q[2]) + pid_controller_pitch_B.In1.q[3] *
    pid_controller_pitch_B.In1.q[3])));

  // Product: '<S60>/Product'
  rtb_fcn5 = pid_controller_pitch_B.In1.q[0] / pid_controller_pitch_B.Product3;

  // Product: '<S60>/Product1'
  rtb_Product1 = pid_controller_pitch_B.In1.q[1] /
    pid_controller_pitch_B.Product3;

  // Product: '<S60>/Product2'
  rtb_Product2 = pid_controller_pitch_B.In1.q[2] /
    pid_controller_pitch_B.Product3;

  // Product: '<S60>/Product3'
  pid_controller_pitch_B.Product3 = pid_controller_pitch_B.In1.q[3] /
    pid_controller_pitch_B.Product3;

  // Fcn: '<S50>/fcn3'
  rtb_fcn3 = (rtb_Product1 * pid_controller_pitch_B.Product3 - rtb_fcn5 *
              rtb_Product2) * -2.0F;

  // If: '<S61>/If' incorporates:
  //   Constant: '<S62>/Constant'
  //   Constant: '<S63>/Constant'

  if (rtb_fcn3 > 1.0F) {
    // Outputs for IfAction SubSystem: '<S61>/If Action Subsystem' incorporates:
    //   ActionPort: '<S62>/Action Port'

    rtb_fcn3 = pid_controller_pitch_P.Constant_Value_md;

    // End of Outputs for SubSystem: '<S61>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S61>/If Action Subsystem' incorporates:
    //   ActionPort: '<S62>/Action Port'

    // Update for If: '<S61>/If' incorporates:
    //   Constant: '<S62>/Constant'

    srUpdateBC(pid_controller_pitch_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S61>/If Action Subsystem'
  } else if (rtb_fcn3 < -1.0F) {
    // Outputs for IfAction SubSystem: '<S61>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S63>/Action Port'

    rtb_fcn3 = pid_controller_pitch_P.Constant_Value_f;

    // End of Outputs for SubSystem: '<S61>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S61>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S63>/Action Port'

    // Update for If: '<S61>/If' incorporates:
    //   Constant: '<S63>/Constant'

    srUpdateBC(pid_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S61>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S61>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S64>/Action Port'

    // Update for If: '<S61>/If'
    srUpdateBC(pid_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S61>/If Action Subsystem2'
  }

  // End of If: '<S61>/If'

  // Fcn: '<S50>/fcn5' incorporates:
  //   Fcn: '<S50>/fcn2'

  y_f_tmp = rtb_fcn5 * rtb_fcn5;
  y_f_tmp_0 = rtb_Product1 * rtb_Product1;
  y_f_tmp_1 = rtb_Product2 * rtb_Product2;
  y_f_tmp_2 = pid_controller_pitch_B.Product3 * pid_controller_pitch_B.Product3;

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S50>/fcn4'
  //   Fcn: '<S50>/fcn5'
  //   Trigonometry: '<S59>/Trigonometric Function3'

  pid_controller_pitch_B.y_f[0] = rt_atan2f_snf((rtb_Product2 *
    pid_controller_pitch_B.Product3 + rtb_fcn5 * rtb_Product1) * 2.0F, ((y_f_tmp
    - y_f_tmp_0) - y_f_tmp_1) + y_f_tmp_2);

  // Trigonometry: '<S59>/trigFcn'
  if (rtb_fcn3 > 1.0F) {
    rtb_fcn3 = 1.0F;
  } else if (rtb_fcn3 < -1.0F) {
    rtb_fcn3 = -1.0F;
  }

  // MATLAB Function: '<S7>/correct sequence' incorporates:
  //   Fcn: '<S50>/fcn1'
  //   Fcn: '<S50>/fcn2'
  //   Trigonometry: '<S59>/Trigonometric Function1'
  //   Trigonometry: '<S59>/trigFcn'

  pid_controller_pitch_B.y_f[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (rtb_fcn3)));
  pid_controller_pitch_B.y_f[2] = rt_atan2f_snf((rtb_Product1 * rtb_Product2 +
    rtb_fcn5 * pid_controller_pitch_B.Product3) * 2.0F, ((y_f_tmp + y_f_tmp_0) -
    y_f_tmp_1) - y_f_tmp_2);

  // MATLABSystem: '<S57>/SourceBlock'
  b_varargout_1 = uORB_read_step(pid_controller_pitch_DW.obj_g.orbMetadataObj,
    &pid_controller_pitch_DW.obj_g.eventStructObj,
    &pid_controller_pitch_B.b_varargout_2_b, false, 1.0);

  // Outputs for Enabled SubSystem: '<S57>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S58>/In1'
    pid_controller_pitch_B.In1_k = pid_controller_pitch_B.b_varargout_2_b;
    srUpdateBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_h);
  }

  // End of MATLABSystem: '<S57>/SourceBlock'
  // End of Outputs for SubSystem: '<S57>/Enabled Subsystem'

  // MATLABSystem: '<S53>/SourceBlock'
  b_varargout_1 = uORB_read_step(pid_controller_pitch_DW.obj_k.orbMetadataObj,
    &pid_controller_pitch_DW.obj_k.eventStructObj,
    &pid_controller_pitch_B.b_varargout_2_k, false, 1.0);

  // Outputs for Enabled SubSystem: '<S53>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S54>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S54>/In1'
    pid_controller_pitch_B.In1_dn = pid_controller_pitch_B.b_varargout_2_k;
    srUpdateBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_g);
  }

  // End of MATLABSystem: '<S53>/SourceBlock'
  // End of Outputs for SubSystem: '<S53>/Enabled Subsystem'

  // MATLABSystem: '<S55>/SourceBlock'
  b_varargout_1 = uORB_read_step(pid_controller_pitch_DW.obj_gg.orbMetadataObj,
    &pid_controller_pitch_DW.obj_gg.eventStructObj,
    &pid_controller_pitch_B.b_varargout_2_cx, false, 1.0);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S56>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S56>/In1'
    pid_controller_pitch_B.In1_d = pid_controller_pitch_B.b_varargout_2_cx;
    srUpdateBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S55>/SourceBlock'
  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  pid_controller_pitch_B.y_g =
    pid_controller_pitch_P.DiscreteTransferFcn_NumCoef *
    pid_controller_pitch_DW.DiscreteTransferFcn_states;

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  pid_controller_pitch_B.y_m =
    pid_controller_pitch_P.DiscreteTransferFcn1_NumCoef *
    pid_controller_pitch_DW.DiscreteTransferFcn1_states;

  // DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
  pid_controller_pitch_B.y_n =
    pid_controller_pitch_P.DiscreteTransferFcn2_NumCoef *
    pid_controller_pitch_DW.DiscreteTransferFcn2_states;

  // SignalConversion generated from: '<S32>/ SFunction ' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S25>/MATLAB Function'

  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[0] =
    pid_controller_pitch_B.y_g;
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[1] =
    pid_controller_pitch_B.y_m;
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[2] =
    pid_controller_pitch_B.y_n;

  // Delay: '<S25>/Delay'
  pid_controller_pitch_B.rtb_Delay_i_idx_0 =
    pid_controller_pitch_DW.Delay_DSTATE_e[0];

  // Delay: '<S25>/Delay1'
  pid_controller_pitch_B.rtb_Delay1_g_idx_0 =
    pid_controller_pitch_DW.Delay1_DSTATE_m[0];

  // Delay: '<S25>/Delay2'
  pid_controller_pitch_B.rtb_Delay2_g_idx_0 =
    pid_controller_pitch_DW.Delay2_DSTATE_k[0];

  // Delay: '<S25>/Delay3'
  pid_controller_pitch_B.rtb_Delay3_f_idx_0 =
    pid_controller_pitch_DW.Delay3_DSTATE_c[0];

  // Delay: '<S25>/Delay4'
  pid_controller_pitch_B.rtb_Delay4_p_idx_0 =
    pid_controller_pitch_DW.Delay4_DSTATE_j[0];

  // Delay: '<S25>/Delay5'
  pid_controller_pitch_B.rtb_Delay5_l_idx_0 =
    pid_controller_pitch_DW.Delay5_DSTATE_e[0];

  // Delay: '<S25>/Delay6'
  pid_controller_pitch_B.rtb_Delay6_g_idx_0 =
    pid_controller_pitch_DW.Delay6_DSTATE_j[0];

  // Delay: '<S25>/Delay7'
  pid_controller_pitch_B.rtb_Delay7_l_idx_0 =
    pid_controller_pitch_DW.Delay7_DSTATE_l[0];

  // Delay: '<S25>/Delay8'
  pid_controller_pitch_B.rtb_Delay8_e_idx_0 =
    pid_controller_pitch_DW.Delay8_DSTATE_m[0];

  // Delay: '<S25>/Delay9'
  pid_controller_pitch_B.rtb_Delay9_c_idx_0 =
    pid_controller_pitch_DW.Delay9_DSTATE_e[0];

  // Delay: '<S25>/Delay10'
  pid_controller_pitch_B.rtb_Delay10_g_idx_0 =
    pid_controller_pitch_DW.Delay10_DSTATE_a[0];

  // Delay: '<S25>/Delay11'
  pid_controller_pitch_B.rtb_Delay11_g_idx_0 =
    pid_controller_pitch_DW.Delay11_DSTATE_m[0];

  // Delay: '<S25>/Delay12'
  pid_controller_pitch_B.rtb_Delay12_k_idx_0 =
    pid_controller_pitch_DW.Delay12_DSTATE_h[0];

  // Delay: '<S25>/Delay13'
  pid_controller_pitch_B.rtb_Delay13_o_idx_0 =
    pid_controller_pitch_DW.Delay13_DSTATE_b[0];

  // Delay: '<S25>/Delay14'
  pid_controller_pitch_B.rtb_Delay14_a_idx_0 =
    pid_controller_pitch_DW.Delay14_DSTATE_k[0];

  // Delay: '<S25>/Delay15'
  pid_controller_pitch_B.rtb_Delay15_idx_0 =
    pid_controller_pitch_DW.Delay15_DSTATE[0];

  // Delay: '<S25>/Delay20'
  pid_controller_pitch_B.rtb_Delay20_m_idx_0 =
    pid_controller_pitch_DW.Delay20_DSTATE_m[0];

  // Delay: '<S25>/Delay21'
  pid_controller_pitch_B.rtb_Delay21_j_idx_0 =
    pid_controller_pitch_DW.Delay21_DSTATE_b[0];

  // Delay: '<S25>/Delay22'
  pid_controller_pitch_B.rtb_Delay22_c_idx_0 =
    pid_controller_pitch_DW.Delay22_DSTATE_g[0];

  // Delay: '<S25>/Delay23'
  pid_controller_pitch_B.rtb_Delay23_a_idx_0 =
    pid_controller_pitch_DW.Delay23_DSTATE_e[0];

  // Delay: '<S25>/Delay24'
  pid_controller_pitch_B.rtb_Delay24_idx_0 =
    pid_controller_pitch_DW.Delay24_DSTATE[0];

  // Delay: '<S25>/Delay25'
  pid_controller_pitch_B.rtb_Delay25_idx_0 =
    pid_controller_pitch_DW.Delay25_DSTATE[0];

  // Delay: '<S25>/Delay26'
  pid_controller_pitch_B.rtb_Delay26_idx_0 =
    pid_controller_pitch_DW.Delay26_DSTATE[0];

  // Delay: '<S25>/Delay27'
  pid_controller_pitch_B.rtb_Delay27_idx_0 =
    pid_controller_pitch_DW.Delay27_DSTATE[0];

  // Delay: '<S25>/Delay16'
  pid_controller_pitch_B.rtb_Delay16_idx_0 =
    pid_controller_pitch_DW.Delay16_DSTATE[0];

  // Delay: '<S25>/Delay17'
  pid_controller_pitch_B.rtb_Delay17_idx_0 =
    pid_controller_pitch_DW.Delay17_DSTATE[0];

  // Delay: '<S25>/Delay18'
  pid_controller_pitch_B.rtb_Delay18_idx_0 =
    pid_controller_pitch_DW.Delay18_DSTATE[0];

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

  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[3] =
    pid_controller_pitch_DW.Delay_DSTATE_e[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[6] =
    pid_controller_pitch_DW.Delay1_DSTATE_m[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[9] =
    pid_controller_pitch_DW.Delay2_DSTATE_k[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[12] =
    pid_controller_pitch_DW.Delay3_DSTATE_c[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[15] =
    pid_controller_pitch_DW.Delay4_DSTATE_j[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[18] =
    pid_controller_pitch_DW.Delay5_DSTATE_e[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[21] =
    pid_controller_pitch_DW.Delay6_DSTATE_j[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[24] =
    pid_controller_pitch_DW.Delay7_DSTATE_l[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[27] =
    pid_controller_pitch_DW.Delay8_DSTATE_m[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[30] =
    pid_controller_pitch_DW.Delay9_DSTATE_e[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[33] =
    pid_controller_pitch_DW.Delay10_DSTATE_a[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[36] =
    pid_controller_pitch_DW.Delay11_DSTATE_m[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[39] =
    pid_controller_pitch_DW.Delay12_DSTATE_h[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[42] =
    pid_controller_pitch_DW.Delay13_DSTATE_b[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[45] =
    pid_controller_pitch_DW.Delay14_DSTATE_k[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[48] =
    pid_controller_pitch_DW.Delay15_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[51] =
    pid_controller_pitch_DW.Delay20_DSTATE_m[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[54] =
    pid_controller_pitch_DW.Delay21_DSTATE_b[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[57] =
    pid_controller_pitch_DW.Delay22_DSTATE_g[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[60] =
    pid_controller_pitch_DW.Delay23_DSTATE_e[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[63] =
    pid_controller_pitch_DW.Delay24_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[66] =
    pid_controller_pitch_DW.Delay25_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[69] =
    pid_controller_pitch_DW.Delay26_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[72] =
    pid_controller_pitch_DW.Delay27_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[75] =
    pid_controller_pitch_DW.Delay16_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[78] =
    pid_controller_pitch_DW.Delay17_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[81] =
    pid_controller_pitch_DW.Delay18_DSTATE[0];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[84] =
    pid_controller_pitch_DW.Delay19_DSTATE[0];

  // Delay: '<S25>/Delay'
  pid_controller_pitch_B.rtb_Delay_i_idx_1 =
    pid_controller_pitch_DW.Delay_DSTATE_e[1];

  // Delay: '<S25>/Delay1'
  pid_controller_pitch_B.rtb_Delay1_g_idx_1 =
    pid_controller_pitch_DW.Delay1_DSTATE_m[1];

  // Delay: '<S25>/Delay2'
  pid_controller_pitch_B.rtb_Delay2_g_idx_1 =
    pid_controller_pitch_DW.Delay2_DSTATE_k[1];

  // Delay: '<S25>/Delay3'
  pid_controller_pitch_B.rtb_Delay3_f_idx_1 =
    pid_controller_pitch_DW.Delay3_DSTATE_c[1];

  // Delay: '<S25>/Delay4'
  pid_controller_pitch_B.rtb_Delay4_p_idx_1 =
    pid_controller_pitch_DW.Delay4_DSTATE_j[1];

  // Delay: '<S25>/Delay5'
  pid_controller_pitch_B.rtb_Delay5_l_idx_1 =
    pid_controller_pitch_DW.Delay5_DSTATE_e[1];

  // Delay: '<S25>/Delay6'
  pid_controller_pitch_B.rtb_Delay6_g_idx_1 =
    pid_controller_pitch_DW.Delay6_DSTATE_j[1];

  // Delay: '<S25>/Delay7'
  pid_controller_pitch_B.rtb_Delay7_l_idx_1 =
    pid_controller_pitch_DW.Delay7_DSTATE_l[1];

  // Delay: '<S25>/Delay8'
  pid_controller_pitch_B.rtb_Delay8_e_idx_1 =
    pid_controller_pitch_DW.Delay8_DSTATE_m[1];

  // Delay: '<S25>/Delay9'
  pid_controller_pitch_B.rtb_Delay9_c_idx_1 =
    pid_controller_pitch_DW.Delay9_DSTATE_e[1];

  // Delay: '<S25>/Delay10'
  pid_controller_pitch_B.rtb_Delay10_g_idx_1 =
    pid_controller_pitch_DW.Delay10_DSTATE_a[1];

  // Delay: '<S25>/Delay11'
  pid_controller_pitch_B.rtb_Delay11_g_idx_1 =
    pid_controller_pitch_DW.Delay11_DSTATE_m[1];

  // Delay: '<S25>/Delay12'
  pid_controller_pitch_B.rtb_Delay12_k_idx_1 =
    pid_controller_pitch_DW.Delay12_DSTATE_h[1];

  // Delay: '<S25>/Delay13'
  pid_controller_pitch_B.rtb_Delay13_o_idx_1 =
    pid_controller_pitch_DW.Delay13_DSTATE_b[1];

  // Delay: '<S25>/Delay14'
  pid_controller_pitch_B.rtb_Delay14_a_idx_1 =
    pid_controller_pitch_DW.Delay14_DSTATE_k[1];

  // Delay: '<S25>/Delay15'
  pid_controller_pitch_B.rtb_Delay15_idx_1 =
    pid_controller_pitch_DW.Delay15_DSTATE[1];

  // Delay: '<S25>/Delay20'
  pid_controller_pitch_B.rtb_Delay20_m_idx_1 =
    pid_controller_pitch_DW.Delay20_DSTATE_m[1];

  // Delay: '<S25>/Delay21'
  pid_controller_pitch_B.rtb_Delay21_j_idx_1 =
    pid_controller_pitch_DW.Delay21_DSTATE_b[1];

  // Delay: '<S25>/Delay22'
  pid_controller_pitch_B.rtb_Delay22_c_idx_1 =
    pid_controller_pitch_DW.Delay22_DSTATE_g[1];

  // Delay: '<S25>/Delay23'
  pid_controller_pitch_B.rtb_Delay23_a_idx_1 =
    pid_controller_pitch_DW.Delay23_DSTATE_e[1];

  // Delay: '<S25>/Delay24'
  pid_controller_pitch_B.rtb_Delay24_idx_1 =
    pid_controller_pitch_DW.Delay24_DSTATE[1];

  // Delay: '<S25>/Delay25'
  pid_controller_pitch_B.rtb_Delay25_idx_1 =
    pid_controller_pitch_DW.Delay25_DSTATE[1];

  // Delay: '<S25>/Delay26'
  pid_controller_pitch_B.rtb_Delay26_idx_1 =
    pid_controller_pitch_DW.Delay26_DSTATE[1];

  // Delay: '<S25>/Delay27'
  pid_controller_pitch_B.rtb_Delay27_idx_1 =
    pid_controller_pitch_DW.Delay27_DSTATE[1];

  // Delay: '<S25>/Delay16'
  pid_controller_pitch_B.rtb_Delay16_idx_1 =
    pid_controller_pitch_DW.Delay16_DSTATE[1];

  // Delay: '<S25>/Delay17'
  pid_controller_pitch_B.rtb_Delay17_idx_1 =
    pid_controller_pitch_DW.Delay17_DSTATE[1];

  // Delay: '<S25>/Delay18'
  pid_controller_pitch_B.rtb_Delay18_idx_1 =
    pid_controller_pitch_DW.Delay18_DSTATE[1];

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

  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[4] =
    pid_controller_pitch_DW.Delay_DSTATE_e[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[7] =
    pid_controller_pitch_DW.Delay1_DSTATE_m[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[10] =
    pid_controller_pitch_DW.Delay2_DSTATE_k[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[13] =
    pid_controller_pitch_DW.Delay3_DSTATE_c[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[16] =
    pid_controller_pitch_DW.Delay4_DSTATE_j[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[19] =
    pid_controller_pitch_DW.Delay5_DSTATE_e[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[22] =
    pid_controller_pitch_DW.Delay6_DSTATE_j[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[25] =
    pid_controller_pitch_DW.Delay7_DSTATE_l[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[28] =
    pid_controller_pitch_DW.Delay8_DSTATE_m[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[31] =
    pid_controller_pitch_DW.Delay9_DSTATE_e[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[34] =
    pid_controller_pitch_DW.Delay10_DSTATE_a[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[37] =
    pid_controller_pitch_DW.Delay11_DSTATE_m[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[40] =
    pid_controller_pitch_DW.Delay12_DSTATE_h[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[43] =
    pid_controller_pitch_DW.Delay13_DSTATE_b[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[46] =
    pid_controller_pitch_DW.Delay14_DSTATE_k[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[49] =
    pid_controller_pitch_DW.Delay15_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[52] =
    pid_controller_pitch_DW.Delay20_DSTATE_m[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[55] =
    pid_controller_pitch_DW.Delay21_DSTATE_b[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[58] =
    pid_controller_pitch_DW.Delay22_DSTATE_g[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[61] =
    pid_controller_pitch_DW.Delay23_DSTATE_e[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[64] =
    pid_controller_pitch_DW.Delay24_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[67] =
    pid_controller_pitch_DW.Delay25_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[70] =
    pid_controller_pitch_DW.Delay26_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[73] =
    pid_controller_pitch_DW.Delay27_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[76] =
    pid_controller_pitch_DW.Delay16_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[79] =
    pid_controller_pitch_DW.Delay17_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[82] =
    pid_controller_pitch_DW.Delay18_DSTATE[1];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[85] =
    pid_controller_pitch_DW.Delay19_DSTATE[1];

  // Delay: '<S25>/Delay'
  pid_controller_pitch_B.Delay_DSTATE_e =
    pid_controller_pitch_DW.Delay_DSTATE_e[2];

  // Delay: '<S25>/Delay1'
  pid_controller_pitch_B.Delay1_DSTATE_m =
    pid_controller_pitch_DW.Delay1_DSTATE_m[2];

  // Delay: '<S25>/Delay2'
  pid_controller_pitch_B.Delay2_DSTATE_k =
    pid_controller_pitch_DW.Delay2_DSTATE_k[2];

  // Delay: '<S25>/Delay3'
  pid_controller_pitch_B.Delay3_DSTATE_c =
    pid_controller_pitch_DW.Delay3_DSTATE_c[2];

  // Delay: '<S25>/Delay4'
  pid_controller_pitch_B.Delay4_DSTATE_j =
    pid_controller_pitch_DW.Delay4_DSTATE_j[2];

  // Delay: '<S25>/Delay5'
  pid_controller_pitch_B.Delay5_DSTATE_e =
    pid_controller_pitch_DW.Delay5_DSTATE_e[2];

  // Delay: '<S25>/Delay6'
  pid_controller_pitch_B.Delay6_DSTATE_j =
    pid_controller_pitch_DW.Delay6_DSTATE_j[2];

  // Delay: '<S25>/Delay7'
  pid_controller_pitch_B.Delay7_DSTATE_l =
    pid_controller_pitch_DW.Delay7_DSTATE_l[2];

  // Delay: '<S25>/Delay8'
  pid_controller_pitch_B.Delay8_DSTATE_m =
    pid_controller_pitch_DW.Delay8_DSTATE_m[2];

  // Delay: '<S25>/Delay9'
  pid_controller_pitch_B.Delay9_DSTATE_e =
    pid_controller_pitch_DW.Delay9_DSTATE_e[2];

  // Delay: '<S25>/Delay10'
  pid_controller_pitch_B.Delay10_DSTATE_a =
    pid_controller_pitch_DW.Delay10_DSTATE_a[2];

  // Delay: '<S25>/Delay11'
  pid_controller_pitch_B.Delay11_DSTATE_m =
    pid_controller_pitch_DW.Delay11_DSTATE_m[2];

  // Delay: '<S25>/Delay12'
  pid_controller_pitch_B.Delay12_DSTATE_h =
    pid_controller_pitch_DW.Delay12_DSTATE_h[2];

  // Delay: '<S25>/Delay13'
  pid_controller_pitch_B.Delay13_DSTATE_b =
    pid_controller_pitch_DW.Delay13_DSTATE_b[2];

  // Delay: '<S25>/Delay14'
  pid_controller_pitch_B.Delay14_DSTATE_k =
    pid_controller_pitch_DW.Delay14_DSTATE_k[2];

  // Delay: '<S25>/Delay15'
  pid_controller_pitch_B.Delay15_DSTATE =
    pid_controller_pitch_DW.Delay15_DSTATE[2];

  // Delay: '<S25>/Delay20'
  pid_controller_pitch_B.Delay20_DSTATE_m =
    pid_controller_pitch_DW.Delay20_DSTATE_m[2];

  // Delay: '<S25>/Delay21'
  pid_controller_pitch_B.Delay21_DSTATE_b =
    pid_controller_pitch_DW.Delay21_DSTATE_b[2];

  // Delay: '<S25>/Delay22'
  pid_controller_pitch_B.Delay22_DSTATE_g =
    pid_controller_pitch_DW.Delay22_DSTATE_g[2];

  // Delay: '<S25>/Delay23'
  pid_controller_pitch_B.Delay23_DSTATE_e =
    pid_controller_pitch_DW.Delay23_DSTATE_e[2];

  // Delay: '<S25>/Delay24'
  pid_controller_pitch_B.Delay24_DSTATE =
    pid_controller_pitch_DW.Delay24_DSTATE[2];

  // Delay: '<S25>/Delay25'
  pid_controller_pitch_B.Delay25_DSTATE =
    pid_controller_pitch_DW.Delay25_DSTATE[2];

  // Delay: '<S25>/Delay26'
  pid_controller_pitch_B.Delay26_DSTATE =
    pid_controller_pitch_DW.Delay26_DSTATE[2];

  // Delay: '<S25>/Delay27'
  pid_controller_pitch_B.Delay27_DSTATE =
    pid_controller_pitch_DW.Delay27_DSTATE[2];

  // Delay: '<S25>/Delay16'
  pid_controller_pitch_B.Delay16_DSTATE =
    pid_controller_pitch_DW.Delay16_DSTATE[2];

  // Delay: '<S25>/Delay17'
  pid_controller_pitch_B.Delay17_DSTATE =
    pid_controller_pitch_DW.Delay17_DSTATE[2];

  // Delay: '<S25>/Delay18'
  pid_controller_pitch_B.Delay18_DSTATE =
    pid_controller_pitch_DW.Delay18_DSTATE[2];

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

  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[5] =
    pid_controller_pitch_DW.Delay_DSTATE_e[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[8] =
    pid_controller_pitch_DW.Delay1_DSTATE_m[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[11] =
    pid_controller_pitch_DW.Delay2_DSTATE_k[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[14] =
    pid_controller_pitch_DW.Delay3_DSTATE_c[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[17] =
    pid_controller_pitch_DW.Delay4_DSTATE_j[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[20] =
    pid_controller_pitch_DW.Delay5_DSTATE_e[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[23] =
    pid_controller_pitch_DW.Delay6_DSTATE_j[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[26] =
    pid_controller_pitch_DW.Delay7_DSTATE_l[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[29] =
    pid_controller_pitch_DW.Delay8_DSTATE_m[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[32] =
    pid_controller_pitch_DW.Delay9_DSTATE_e[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[35] =
    pid_controller_pitch_DW.Delay10_DSTATE_a[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[38] =
    pid_controller_pitch_DW.Delay11_DSTATE_m[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[41] =
    pid_controller_pitch_DW.Delay12_DSTATE_h[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[44] =
    pid_controller_pitch_DW.Delay13_DSTATE_b[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[47] =
    pid_controller_pitch_DW.Delay14_DSTATE_k[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[50] =
    pid_controller_pitch_DW.Delay15_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[53] =
    pid_controller_pitch_DW.Delay20_DSTATE_m[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[56] =
    pid_controller_pitch_DW.Delay21_DSTATE_b[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[59] =
    pid_controller_pitch_DW.Delay22_DSTATE_g[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[62] =
    pid_controller_pitch_DW.Delay23_DSTATE_e[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[65] =
    pid_controller_pitch_DW.Delay24_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[68] =
    pid_controller_pitch_DW.Delay25_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[71] =
    pid_controller_pitch_DW.Delay26_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[74] =
    pid_controller_pitch_DW.Delay27_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[77] =
    pid_controller_pitch_DW.Delay16_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[80] =
    pid_controller_pitch_DW.Delay17_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[83] =
    pid_controller_pitch_DW.Delay18_DSTATE[2];
  pid_controller_pitch_B.TmpSignalConversionAtSFun_a[86] =
    pid_controller_pitch_DW.Delay19_DSTATE[2];

  // MATLAB Function: '<S25>/MATLAB Function'
  for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 < 29;
       pid_controller_pitch_B.r2++) {
    i = (pid_controller_pitch_B.r2 + 1) * 3;
    pid_controller_pitch_B.ph_meas =
      pid_controller_pitch_B.TmpSignalConversionAtSFun_a[i - 3];
    pid_controller_pitch_B.y = pid_controller_pitch_B.ph_meas *
      pid_controller_pitch_B.ph_meas;
    pid_controller_pitch_B.ph_meas =
      pid_controller_pitch_B.TmpSignalConversionAtSFun_a[i - 2];
    pid_controller_pitch_B.y += pid_controller_pitch_B.ph_meas *
      pid_controller_pitch_B.ph_meas;
    pid_controller_pitch_B.ph_meas =
      pid_controller_pitch_B.TmpSignalConversionAtSFun_a[i - 1];
    pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r2] = sqrt
      (pid_controller_pitch_B.ph_meas * pid_controller_pitch_B.ph_meas +
       pid_controller_pitch_B.y);
    pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r2 + 29] = static_cast<
      real_T>(pid_controller_pitch_B.r2) + 1.0;
  }

  for (i = 0; i < 28; i++) {
    pid_controller_pitch_B.b = 27 - i;
    for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 <=
         pid_controller_pitch_B.b; pid_controller_pitch_B.r1++) {
      pid_controller_pitch_B.ph_meas =
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1];
      pid_controller_pitch_B.At1_tmp =
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 1];
      if (pid_controller_pitch_B.ph_meas > pid_controller_pitch_B.At1_tmp) {
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1] =
          pid_controller_pitch_B.At1_tmp;
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 1] =
          pid_controller_pitch_B.ph_meas;
        pid_controller_pitch_B.tth =
          pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 29];
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 29] =
          pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 30];
        pid_controller_pitch_B.b_norm[pid_controller_pitch_B.r1 + 30] =
          pid_controller_pitch_B.tth;
      }
    }
  }

  pid_controller_pitch_B.ph_meas = pid_controller_pitch_B.b_norm[41] * 3.0 - 2.0;
  pid_controller_pitch_B.y = pid_controller_pitch_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(pid_controller_pitch_B.ph_meas) - 1];
  pid_controller_pitch_B.y_idx_0 = pid_controller_pitch_B.y;

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

  pid_controller_pitch_B.Sum23_g =
    ((((((((((((((((((pid_controller_pitch_DW.Delay_DSTATE[0] +
                      pid_controller_pitch_B.y) +
                     pid_controller_pitch_DW.Delay1_DSTATE[0]) +
                    pid_controller_pitch_DW.Delay2_DSTATE_f[0]) +
                   pid_controller_pitch_DW.Delay3_DSTATE_j[0]) +
                  pid_controller_pitch_DW.Delay4_DSTATE[0]) +
                 pid_controller_pitch_DW.Delay5_DSTATE[0]) +
                pid_controller_pitch_DW.Delay6_DSTATE[0]) +
               pid_controller_pitch_DW.Delay7_DSTATE[0]) +
              pid_controller_pitch_DW.Delay8_DSTATE[0]) +
             pid_controller_pitch_DW.Delay9_DSTATE[0]) +
            pid_controller_pitch_DW.Delay10_DSTATE[0]) +
           pid_controller_pitch_DW.Delay11_DSTATE[0]) +
          pid_controller_pitch_DW.Delay12_DSTATE[0]) +
         pid_controller_pitch_DW.Delay13_DSTATE[0]) +
        pid_controller_pitch_DW.Delay14_DSTATE[0]) +
       pid_controller_pitch_DW.Delay20_DSTATE[0]) +
      pid_controller_pitch_DW.Delay21_DSTATE[0]) +
     pid_controller_pitch_DW.Delay22_DSTATE[0]) +
    pid_controller_pitch_DW.Delay23_DSTATE[0];
  pid_controller_pitch_B.Sum23[0] = pid_controller_pitch_B.Sum23_g;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  pid_controller_pitch_B.Sum24[0] = pid_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  pid_controller_pitch_B.u_vect[0] = -(pid_controller_pitch_P.Gain_Gain_n *
    pid_controller_pitch_B.Sum23_g);

  // MATLAB Function: '<S25>/MATLAB Function'
  pid_controller_pitch_B.y = pid_controller_pitch_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(pid_controller_pitch_B.ph_meas + 1.0) - 1];
  pid_controller_pitch_B.y_idx_1 = pid_controller_pitch_B.y;

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

  pid_controller_pitch_B.Sum23_g =
    ((((((((((((((((((pid_controller_pitch_DW.Delay_DSTATE[1] +
                      pid_controller_pitch_B.y) +
                     pid_controller_pitch_DW.Delay1_DSTATE[1]) +
                    pid_controller_pitch_DW.Delay2_DSTATE_f[1]) +
                   pid_controller_pitch_DW.Delay3_DSTATE_j[1]) +
                  pid_controller_pitch_DW.Delay4_DSTATE[1]) +
                 pid_controller_pitch_DW.Delay5_DSTATE[1]) +
                pid_controller_pitch_DW.Delay6_DSTATE[1]) +
               pid_controller_pitch_DW.Delay7_DSTATE[1]) +
              pid_controller_pitch_DW.Delay8_DSTATE[1]) +
             pid_controller_pitch_DW.Delay9_DSTATE[1]) +
            pid_controller_pitch_DW.Delay10_DSTATE[1]) +
           pid_controller_pitch_DW.Delay11_DSTATE[1]) +
          pid_controller_pitch_DW.Delay12_DSTATE[1]) +
         pid_controller_pitch_DW.Delay13_DSTATE[1]) +
        pid_controller_pitch_DW.Delay14_DSTATE[1]) +
       pid_controller_pitch_DW.Delay20_DSTATE[1]) +
      pid_controller_pitch_DW.Delay21_DSTATE[1]) +
     pid_controller_pitch_DW.Delay22_DSTATE[1]) +
    pid_controller_pitch_DW.Delay23_DSTATE[1];
  pid_controller_pitch_B.Sum23[1] = pid_controller_pitch_B.Sum23_g;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  pid_controller_pitch_B.Sum24[1] = pid_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  pid_controller_pitch_B.u_vect[1] = -(pid_controller_pitch_P.Gain_Gain_n *
    pid_controller_pitch_B.Sum23_g);

  // MATLAB Function: '<S25>/MATLAB Function'
  pid_controller_pitch_B.y = pid_controller_pitch_B.TmpSignalConversionAtSFun_a[
    static_cast<int32_T>(pid_controller_pitch_B.ph_meas + 2.0) - 1];

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

  pid_controller_pitch_B.Sum23_g =
    ((((((((((((((((((pid_controller_pitch_DW.Delay_DSTATE[2] +
                      pid_controller_pitch_B.y) +
                     pid_controller_pitch_DW.Delay1_DSTATE[2]) +
                    pid_controller_pitch_DW.Delay2_DSTATE_f[2]) +
                   pid_controller_pitch_DW.Delay3_DSTATE_j[2]) +
                  pid_controller_pitch_DW.Delay4_DSTATE[2]) +
                 pid_controller_pitch_DW.Delay5_DSTATE[2]) +
                pid_controller_pitch_DW.Delay6_DSTATE[2]) +
               pid_controller_pitch_DW.Delay7_DSTATE[2]) +
              pid_controller_pitch_DW.Delay8_DSTATE[2]) +
             pid_controller_pitch_DW.Delay9_DSTATE[2]) +
            pid_controller_pitch_DW.Delay10_DSTATE[2]) +
           pid_controller_pitch_DW.Delay11_DSTATE[2]) +
          pid_controller_pitch_DW.Delay12_DSTATE[2]) +
         pid_controller_pitch_DW.Delay13_DSTATE[2]) +
        pid_controller_pitch_DW.Delay14_DSTATE[2]) +
       pid_controller_pitch_DW.Delay20_DSTATE[2]) +
      pid_controller_pitch_DW.Delay21_DSTATE[2]) +
     pid_controller_pitch_DW.Delay22_DSTATE[2]) +
    pid_controller_pitch_DW.Delay23_DSTATE[2];
  pid_controller_pitch_B.Sum23[2] = pid_controller_pitch_B.Sum23_g;

  // Sum: '<S29>/Sum24' incorporates:
  //   Sum: '<S29>/Sum23'

  pid_controller_pitch_B.Sum24[2] = pid_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S18>/RP_computation' incorporates:
  //   Gain: '<S29>/Gain'
  //   Sum: '<S29>/Sum23'
  //   Sum: '<S29>/Sum24'

  pid_controller_pitch_B.u_vect[2] = -(pid_controller_pitch_P.Gain_Gain_n *
    pid_controller_pitch_B.Sum23_g);
  pid_controller_pitch_B.ph_meas = rt_atan2d_snf(pid_controller_pitch_B.u_vect[1],
    pid_controller_pitch_B.u_vect[2]);
  pid_controller_pitch_B.temp[0] = pid_controller_pitch_B.ph_meas;
  pid_controller_pitch_B.Sum23_g = rt_atan2d_snf(-pid_controller_pitch_B.u_vect
    [0], pid_controller_pitch_B.u_vect[1] * sin(pid_controller_pitch_B.ph_meas)
    + pid_controller_pitch_B.u_vect[2] * cos(pid_controller_pitch_B.ph_meas));
  pid_controller_pitch_B.temp[1] = pid_controller_pitch_B.Sum23_g;

  // MATLAB Function: '<S27>/EKF_RP' incorporates:
  //   Delay: '<S27>/Delay2'
  //   Memory: '<S27>/Memory2'
  //   Memory: '<S27>/Memory3'

  if (pid_controller_pitch_B.DigitalClock1 -
      pid_controller_pitch_DW.Memory2_PreviousInput >=
      pid_controller_pitch_P.Ts_EKF_meas) {
    pid_controller_pitch_DW.Memory2_PreviousInput =
      pid_controller_pitch_B.DigitalClock1;
    memcpy(&pid_controller_pitch_B.Pt1[0],
           &pid_controller_pitch_DW.Memory3_PreviousInput[0], 25U * sizeof
           (real_T));
    pid_controller_pitch_B.wq1 = pid_controller_pitch_DW.Delay2_DSTATE_l[1];
    pid_controller_pitch_B.wr1 = pid_controller_pitch_DW.Delay2_DSTATE_l[2];
    for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 < 5;
         pid_controller_pitch_B.r2++) {
      pid_controller_pitch_B.xt[pid_controller_pitch_B.r2] = 0.0;
    }

    memset(&pid_controller_pitch_B.Pt[0], 0, 25U * sizeof(real_T));
    pid_controller_pitch_B.b = static_cast<int32_T>(floor
      (pid_controller_pitch_P.Ts_EKF_meas / pid_controller_pitch_P.Ts_EKF_integr));
    for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 <
         pid_controller_pitch_B.b; pid_controller_pitch_B.r2++) {
      pid_controller_pitch_B.cph = cos
        (pid_controller_pitch_DW.Memory4_PreviousInput[0]);
      pid_controller_pitch_B.cth = cos
        (pid_controller_pitch_DW.Memory4_PreviousInput[1]);
      pid_controller_pitch_B.sph = sin
        (pid_controller_pitch_DW.Memory4_PreviousInput[0]);
      pid_controller_pitch_B.tth = sin
        (pid_controller_pitch_DW.Memory4_PreviousInput[1]) /
        pid_controller_pitch_B.cth;
      pid_controller_pitch_B.dv[0] = 1.0;
      pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.sph *
        pid_controller_pitch_B.tth;
      pid_controller_pitch_B.dv[5] = pid_controller_pitch_B.At1_tmp;
      pid_controller_pitch_B.d = pid_controller_pitch_B.cph *
        pid_controller_pitch_B.tth;
      pid_controller_pitch_B.dv[10] = pid_controller_pitch_B.d;
      pid_controller_pitch_B.dv[15] = 0.0;
      pid_controller_pitch_B.dv[20] = 0.0;
      pid_controller_pitch_B.dv[25] = 0.0;
      pid_controller_pitch_B.dv[1] = 0.0;
      pid_controller_pitch_B.dv[6] = pid_controller_pitch_B.cph;
      pid_controller_pitch_B.dv[11] = -pid_controller_pitch_B.sph;
      pid_controller_pitch_B.dv[16] = 0.0;
      pid_controller_pitch_B.dv[21] = 0.0;
      pid_controller_pitch_B.dv[26] = 0.0;
      for (i = 0; i < 6; i++) {
        pid_controller_pitch_B.dv[5 * i + 2] = 0.0;
        pid_controller_pitch_B.dv[5 * i + 3] = 0.0;
        pid_controller_pitch_B.dv[5 * i + 4] = 0.0;
      }

      pid_controller_pitch_B.dv3[0] = pid_controller_pitch_DW.Delay2_DSTATE_l[0]
        - pid_controller_pitch_DW.Memory4_PreviousInput[2];
      pid_controller_pitch_B.Pt_f = pid_controller_pitch_B.wq1 -
        pid_controller_pitch_DW.Memory4_PreviousInput[3];
      pid_controller_pitch_B.dv3[1] = pid_controller_pitch_B.Pt_f;
      pid_controller_pitch_B.d1 = pid_controller_pitch_B.wr1 -
        pid_controller_pitch_DW.Memory4_PreviousInput[4];
      pid_controller_pitch_B.dv3[2] = pid_controller_pitch_B.d1;
      pid_controller_pitch_B.dv3[3] =
        pid_controller_pitch_DW.Memory4_PreviousInput[2];
      pid_controller_pitch_B.dv3[4] =
        pid_controller_pitch_DW.Memory4_PreviousInput[3];
      pid_controller_pitch_B.dv3[5] =
        pid_controller_pitch_DW.Memory4_PreviousInput[4];
      pid_controller_pitch_B.Pt[0] = pid_controller_pitch_B.d *
        pid_controller_pitch_B.Pt_f - pid_controller_pitch_B.At1_tmp *
        pid_controller_pitch_B.d1;
      pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.d1 *
        pid_controller_pitch_B.cph;
      pid_controller_pitch_B.Pt[5] = (pid_controller_pitch_B.Pt_f *
        pid_controller_pitch_B.sph + pid_controller_pitch_B.At1_tmp) /
        (pid_controller_pitch_B.cth * pid_controller_pitch_B.cth);
      pid_controller_pitch_B.Pt[10] = -1.0;
      pid_controller_pitch_B.Pt[15] = -pid_controller_pitch_B.sph *
        pid_controller_pitch_B.tth;
      pid_controller_pitch_B.Pt[20] = -pid_controller_pitch_B.cph *
        pid_controller_pitch_B.tth;
      pid_controller_pitch_B.Pt[1] = pid_controller_pitch_B.Pt_f *
        -pid_controller_pitch_B.sph - pid_controller_pitch_B.At1_tmp;
      pid_controller_pitch_B.Pt[6] = 0.0;
      pid_controller_pitch_B.Pt[11] = 0.0;
      pid_controller_pitch_B.Pt[16] = -pid_controller_pitch_B.cph;
      pid_controller_pitch_B.Pt[21] = pid_controller_pitch_B.sph;
      for (i = 0; i < 5; i++) {
        pid_controller_pitch_B.At1_tmp = 0.0;
        for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 6;
             pid_controller_pitch_B.r1++) {
          pid_controller_pitch_B.At1_tmp += pid_controller_pitch_B.dv[5 *
            pid_controller_pitch_B.r1 + i] *
            pid_controller_pitch_B.dv3[pid_controller_pitch_B.r1];
        }

        pid_controller_pitch_B.xt[i] = pid_controller_pitch_P.Ts_EKF_integr *
          pid_controller_pitch_B.At1_tmp +
          pid_controller_pitch_DW.Memory4_PreviousInput[i];
        pid_controller_pitch_B.Pt[5 * i + 2] = 0.0;
        pid_controller_pitch_B.Pt[5 * i + 3] = 0.0;
        pid_controller_pitch_B.Pt[5 * i + 4] = 0.0;
      }

      for (i = 0; i < 5; i++) {
        for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
             pid_controller_pitch_B.r1++) {
          pid_controller_pitch_B.tth = 0.0;
          pid_controller_pitch_B.At1_tmp = 0.0;
          for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
            At1_tmp = 5 * Pt1_tmp + i;
            pid_controller_pitch_B.tth += pid_controller_pitch_B.Pt1[5 *
              pid_controller_pitch_B.r1 + Pt1_tmp] *
              pid_controller_pitch_B.Pt[At1_tmp];
            pid_controller_pitch_B.At1_tmp += pid_controller_pitch_B.Pt[5 *
              Pt1_tmp + pid_controller_pitch_B.r1] *
              pid_controller_pitch_B.Pt1[At1_tmp];
          }

          Pt1_tmp = 5 * pid_controller_pitch_B.r1 + i;
          pid_controller_pitch_B.Pt1_m[Pt1_tmp] = pid_controller_pitch_B.At1_tmp;
          pid_controller_pitch_B.At1[Pt1_tmp] = pid_controller_pitch_B.tth;
        }
      }

      for (i = 0; i < 25; i++) {
        pid_controller_pitch_B.Pt[i] = ((pid_controller_pitch_B.At1[i] +
          pid_controller_pitch_B.Pt1_m[i]) + pid_controller_pitch_P.Q_phth[i]) *
          pid_controller_pitch_P.Ts_EKF_integr + pid_controller_pitch_B.Pt1[i];
      }

      for (i = 0; i < 5; i++) {
        pid_controller_pitch_DW.Memory4_PreviousInput[i] =
          pid_controller_pitch_B.xt[i];
      }

      memcpy(&pid_controller_pitch_B.Pt1[0], &pid_controller_pitch_B.Pt[0], 25U *
             sizeof(real_T));
    }

    for (i = 0; i < 10; i++) {
      pid_controller_pitch_B.Lk[i] = c[i];
    }

    for (i = 0; i < 2; i++) {
      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
           pid_controller_pitch_B.r1++) {
        pid_controller_pitch_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          pid_controller_pitch_B.tth += pid_controller_pitch_B.Pt[5 * Pt1_tmp +
            pid_controller_pitch_B.r1] * pid_controller_pitch_B.Lk[5 * i +
            Pt1_tmp];
        }

        pid_controller_pitch_B.B[pid_controller_pitch_B.r1 + 5 * i] =
          pid_controller_pitch_B.tth;
      }
    }

    for (i = 0; i < 10; i++) {
      pid_controller_pitch_B.A_tmp_c[i] = b_b[i];
    }

    for (i = 0; i < 2; i++) {
      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
           pid_controller_pitch_B.r1++) {
        pid_controller_pitch_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          pid_controller_pitch_B.tth += static_cast<real_T>
            (pid_controller_pitch_B.A_tmp_c[(Pt1_tmp << 1) + i]) *
            pid_controller_pitch_B.Pt[5 * pid_controller_pitch_B.r1 + Pt1_tmp];
        }

        pid_controller_pitch_B.A_tmp[i + (pid_controller_pitch_B.r1 << 1)] =
          pid_controller_pitch_B.tth;
      }

      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 2;
           pid_controller_pitch_B.r1++) {
        pid_controller_pitch_B.At1_tmp = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          pid_controller_pitch_B.At1_tmp += pid_controller_pitch_B.A_tmp
            [(Pt1_tmp << 1) + i] * pid_controller_pitch_B.Lk[5 *
            pid_controller_pitch_B.r1 + Pt1_tmp];
        }

        pid_controller_pitch_B.r2 = (pid_controller_pitch_B.r1 << 1) + i;
        pid_controller_pitch_B.minval[pid_controller_pitch_B.r2] =
          pid_controller_pitch_P.R_phth[pid_controller_pitch_B.r2] +
          pid_controller_pitch_B.At1_tmp;
      }
    }

    if (fabs(pid_controller_pitch_B.minval[1]) > fabs
        (pid_controller_pitch_B.minval[0])) {
      pid_controller_pitch_B.r1 = 1;
      pid_controller_pitch_B.r2 = 0;
    } else {
      pid_controller_pitch_B.r1 = 0;
      pid_controller_pitch_B.r2 = 1;
    }

    pid_controller_pitch_B.tth =
      pid_controller_pitch_B.minval[pid_controller_pitch_B.r2] /
      pid_controller_pitch_B.minval[pid_controller_pitch_B.r1];
    pid_controller_pitch_B.At1_tmp =
      pid_controller_pitch_B.minval[pid_controller_pitch_B.r1 + 2];
    pid_controller_pitch_B.wq1 =
      pid_controller_pitch_B.minval[pid_controller_pitch_B.r2 + 2] -
      pid_controller_pitch_B.At1_tmp * pid_controller_pitch_B.tth;
    for (i = 0; i < 5; i++) {
      Pt1_tmp = 5 * pid_controller_pitch_B.r1 + i;
      pid_controller_pitch_B.Lk[Pt1_tmp] = pid_controller_pitch_B.B[i] /
        pid_controller_pitch_B.minval[pid_controller_pitch_B.r1];
      pid_controller_pitch_B.b = 5 * pid_controller_pitch_B.r2 + i;
      pid_controller_pitch_B.Lk[pid_controller_pitch_B.b] =
        (pid_controller_pitch_B.B[i + 5] - pid_controller_pitch_B.Lk[Pt1_tmp] *
         pid_controller_pitch_B.At1_tmp) / pid_controller_pitch_B.wq1;
      pid_controller_pitch_B.Lk[Pt1_tmp] -=
        pid_controller_pitch_B.Lk[pid_controller_pitch_B.b] *
        pid_controller_pitch_B.tth;
    }

    for (i = 0; i < 2; i++) {
      pid_controller_pitch_B.At1_tmp = 0.0;
      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
           pid_controller_pitch_B.r1++) {
        pid_controller_pitch_B.At1_tmp += static_cast<real_T>
          (pid_controller_pitch_B.A_tmp_c[(pid_controller_pitch_B.r1 << 1) + i])
          * pid_controller_pitch_B.xt[pid_controller_pitch_B.r1];
      }

      pid_controller_pitch_B.temp_p[i] = pid_controller_pitch_B.temp[i] -
        pid_controller_pitch_B.At1_tmp;
    }

    pid_controller_pitch_B.tth = pid_controller_pitch_B.temp_p[1];
    pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.temp_p[0];
    for (i = 0; i < 5; i++) {
      pid_controller_pitch_DW.Memory4_PreviousInput[i] =
        (pid_controller_pitch_B.Lk[i + 5] * pid_controller_pitch_B.tth +
         pid_controller_pitch_B.Lk[i] * pid_controller_pitch_B.At1_tmp) +
        pid_controller_pitch_B.xt[i];
    }

    memset(&pid_controller_pitch_B.Pt1[0], 0, 25U * sizeof(real_T));
    for (i = 0; i < 5; i++) {
      pid_controller_pitch_B.Pt1[i + 5 * i] = 1.0;
    }

    for (i = 0; i < 5; i++) {
      pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.Lk[i + 5];
      pid_controller_pitch_B.tth = pid_controller_pitch_B.Lk[i];
      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
           pid_controller_pitch_B.r1++) {
        Pt1_tmp = pid_controller_pitch_B.r1 << 1;
        pid_controller_pitch_B.r2 = 5 * pid_controller_pitch_B.r1 + i;
        pid_controller_pitch_B.Pt1_m[pid_controller_pitch_B.r2] =
          pid_controller_pitch_B.Pt1[pid_controller_pitch_B.r2] -
          (static_cast<real_T>(pid_controller_pitch_B.A_tmp_c[Pt1_tmp + 1]) *
           pid_controller_pitch_B.At1_tmp + static_cast<real_T>
           (pid_controller_pitch_B.A_tmp_c[Pt1_tmp]) *
           pid_controller_pitch_B.tth);
      }

      for (pid_controller_pitch_B.r1 = 0; pid_controller_pitch_B.r1 < 5;
           pid_controller_pitch_B.r1++) {
        pid_controller_pitch_B.tth = 0.0;
        for (Pt1_tmp = 0; Pt1_tmp < 5; Pt1_tmp++) {
          pid_controller_pitch_B.tth += pid_controller_pitch_B.Pt1_m[5 * Pt1_tmp
            + i] * pid_controller_pitch_B.Pt[5 * pid_controller_pitch_B.r1 +
            Pt1_tmp];
        }

        pid_controller_pitch_DW.Memory3_PreviousInput[i + 5 *
          pid_controller_pitch_B.r1] = pid_controller_pitch_B.tth;
      }
    }
  }

  // End of MATLAB Function: '<S27>/EKF_RP'

  // MATLAB Function: '<S18>/Y_computation' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion3'
  //   MATLAB Function: '<S18>/RPY_dot_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   MATLAB Function: '<S30>/EKF_Y'

  pid_controller_pitch_B.wr1 = sin
    (pid_controller_pitch_DW.Memory4_PreviousInput[0]);
  pid_controller_pitch_B.cph = cos
    (pid_controller_pitch_DW.Memory4_PreviousInput[0]);
  pid_controller_pitch_B.tth = sin
    (pid_controller_pitch_DW.Memory4_PreviousInput[1]);
  pid_controller_pitch_B.cth = cos
    (pid_controller_pitch_DW.Memory4_PreviousInput[1]);
  pid_controller_pitch_B.wq1 = rt_atan2d_snf(pid_controller_pitch_B.In1_k.z *
    pid_controller_pitch_B.wr1 - pid_controller_pitch_B.In1_k.y *
    pid_controller_pitch_B.cph, (pid_controller_pitch_B.In1_k.y *
    pid_controller_pitch_B.tth * pid_controller_pitch_B.wr1 +
    pid_controller_pitch_B.In1_k.x * pid_controller_pitch_B.cth) +
    pid_controller_pitch_B.In1_k.z * pid_controller_pitch_B.tth *
    pid_controller_pitch_B.cph);
  if (pid_controller_pitch_B.wq1 < 0.0) {
    pid_controller_pitch_B.wq1 += 6.2831853071795862;
  }

  // MATLAB Function: '<S30>/EKF_Y' incorporates:
  //   Delay: '<S30>/Delay2'
  //   MATLAB Function: '<S18>/Y_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   Memory: '<S30>/Memory2'

  if (pid_controller_pitch_B.DigitalClock1 -
      pid_controller_pitch_DW.Memory2_PreviousInput_f >=
      pid_controller_pitch_P.Ts_EKF_meas) {
    pid_controller_pitch_DW.Memory2_PreviousInput_f =
      pid_controller_pitch_B.DigitalClock1;
    pid_controller_pitch_B.sph = 0.0;
    pid_controller_pitch_B.Pt_f = 0.0;
    pid_controller_pitch_B.b = static_cast<int32_T>(floor
      (pid_controller_pitch_P.Ts_EKF_meas / pid_controller_pitch_P.Ts_EKF_integr));
    if (pid_controller_pitch_B.b - 1 >= 0) {
      pid_controller_pitch_B.dv4[0] = 0.0;
      pid_controller_pitch_B.dv4[1] = pid_controller_pitch_B.wr1 /
        pid_controller_pitch_B.cth;
      pid_controller_pitch_B.dv4[2] = pid_controller_pitch_B.cph /
        pid_controller_pitch_B.cth;
      pid_controller_pitch_B.dv4[3] = 0.0;
      pid_controller_pitch_B.dv4[4] = 0.0;
      pid_controller_pitch_B.dv4[5] = 0.0;
      pid_controller_pitch_B.dv5[0] = pid_controller_pitch_DW.Delay2_DSTATE_fv[0]
        - pid_controller_pitch_DW.Memory4_PreviousInput[2];
      pid_controller_pitch_B.dv5[1] = pid_controller_pitch_DW.Delay2_DSTATE_fv[1]
        - pid_controller_pitch_DW.Memory4_PreviousInput[3];
      pid_controller_pitch_B.dv5[2] = pid_controller_pitch_DW.Delay2_DSTATE_fv[2]
        - pid_controller_pitch_DW.Memory4_PreviousInput[4];
      pid_controller_pitch_B.dv5[3] =
        pid_controller_pitch_DW.Memory4_PreviousInput[2];
      pid_controller_pitch_B.dv5[4] =
        pid_controller_pitch_DW.Memory4_PreviousInput[3];
      pid_controller_pitch_B.dv5[5] =
        pid_controller_pitch_DW.Memory4_PreviousInput[4];
    }

    for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 <
         pid_controller_pitch_B.b; pid_controller_pitch_B.r2++) {
      pid_controller_pitch_B.At1_tmp = 0.0;
      for (i = 0; i < 6; i++) {
        pid_controller_pitch_B.At1_tmp += pid_controller_pitch_B.dv4[i] *
          pid_controller_pitch_B.dv5[i];
      }

      pid_controller_pitch_B.sph = pid_controller_pitch_P.Ts_EKF_integr *
        pid_controller_pitch_B.At1_tmp +
        pid_controller_pitch_DW.Memory4_PreviousInput_d;
      pid_controller_pitch_B.Pt_f = ((0.0 *
        pid_controller_pitch_DW.Memory3_PreviousInput_g +
        pid_controller_pitch_DW.Memory3_PreviousInput_g * 0.0) +
        pid_controller_pitch_P.q_ps) * pid_controller_pitch_P.Ts_EKF_integr +
        pid_controller_pitch_DW.Memory3_PreviousInput_g;
      pid_controller_pitch_DW.Memory4_PreviousInput_d =
        pid_controller_pitch_B.sph;
      pid_controller_pitch_DW.Memory3_PreviousInput_g =
        pid_controller_pitch_B.Pt_f;
    }

    pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.Pt_f /
      (pid_controller_pitch_B.Pt_f + pid_controller_pitch_P.r_ps);
    pid_controller_pitch_DW.Memory4_PreviousInput_d =
      (pid_controller_pitch_B.wq1 - pid_controller_pitch_B.sph) *
      pid_controller_pitch_B.At1_tmp + pid_controller_pitch_B.sph;
    pid_controller_pitch_DW.Memory3_PreviousInput_g = (1.0 -
      pid_controller_pitch_B.At1_tmp) * pid_controller_pitch_B.Pt_f;
  }

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  pid_controller_pitch_B.At1_tmp =
    pid_controller_pitch_P.DiscreteTransferFcn_NumCoef_h *
    pid_controller_pitch_DW.DiscreteTransferFcn_states_i;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  pid_controller_pitch_B.sph =
    pid_controller_pitch_P.DiscreteTransferFcn1_NumCoef_k *
    pid_controller_pitch_DW.DiscreteTransferFcn1_states_p;

  // DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  pid_controller_pitch_B.Pt_f =
    pid_controller_pitch_P.DiscreteTransferFcn2_NumCoef_b *
    pid_controller_pitch_DW.DiscreteTransferFcn2_states_o;

  // MATLAB Function: '<S18>/RPY_dot_computation' incorporates:
  //   Constant: '<S18>/Constant6'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  //   MATLAB Function: '<S18>/Y_computation'
  //   MATLAB Function: '<S27>/MATLAB Function'
  //   Memory: '<S18>/Memory5'

  if ((pid_controller_pitch_B.DigitalClock1 -
       pid_controller_pitch_DW.Memory5_PreviousInput >=
       pid_controller_pitch_P.Ts_EKF_meas) ||
      (pid_controller_pitch_B.DigitalClock1 == 0.0)) {
    pid_controller_pitch_B.tth /= pid_controller_pitch_B.cth;
    pid_controller_pitch_DW.Memory5_PreviousInput =
      pid_controller_pitch_B.DigitalClock1;
    pid_controller_pitch_B.dv2[0] = 1.0;
    pid_controller_pitch_B.dv2[3] = pid_controller_pitch_B.wr1 *
      pid_controller_pitch_B.tth;
    pid_controller_pitch_B.dv2[6] = pid_controller_pitch_B.cph *
      pid_controller_pitch_B.tth;
    pid_controller_pitch_B.dv2[1] = 0.0;
    pid_controller_pitch_B.dv2[4] = pid_controller_pitch_B.cph;
    pid_controller_pitch_B.dv2[7] = -pid_controller_pitch_B.wr1;
    pid_controller_pitch_B.dv2[2] = 0.0;
    pid_controller_pitch_B.dv2[5] = pid_controller_pitch_B.wr1 /
      pid_controller_pitch_B.cth;
    pid_controller_pitch_B.dv2[8] = pid_controller_pitch_B.cph /
      pid_controller_pitch_B.cth;
    pid_controller_pitch_B.tth = pid_controller_pitch_B.At1_tmp -
      pid_controller_pitch_DW.Memory4_PreviousInput[2] * 0.0;
    pid_controller_pitch_B.wr1 = pid_controller_pitch_B.sph -
      pid_controller_pitch_DW.Memory4_PreviousInput[3] * 0.0;
    pid_controller_pitch_B.cph = pid_controller_pitch_B.Pt_f -
      pid_controller_pitch_DW.Memory4_PreviousInput[4] * 0.0;
    for (i = 0; i < 3; i++) {
      pid_controller_pitch_DW.Memory6_PreviousInput[i] =
        (pid_controller_pitch_B.dv2[i + 3] * pid_controller_pitch_B.wr1 +
         pid_controller_pitch_B.dv2[i] * pid_controller_pitch_B.tth) +
        pid_controller_pitch_B.dv2[i + 6] * pid_controller_pitch_B.cph;
    }
  }

  // Step: '<Root>/RPY ref'
  if (pid_controller_pitch_B.DigitalClock1 < pid_controller_pitch_P.RPYref_Time)
  {
    // Step: '<Root>/RPY ref'
    pid_controller_pitch_B.tth = pid_controller_pitch_P.RPYref_Y0;
  } else {
    // Step: '<Root>/RPY ref'
    pid_controller_pitch_B.tth = pid_controller_pitch_P.RPYref_YFinal;
  }

  // ManualSwitch: '<Root>/Manual Switch2'
  if (pid_controller_pitch_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'

    for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 < 28;
         pid_controller_pitch_B.r2++) {
      pid_controller_pitch_B.ManualSwitch2[pid_controller_pitch_B.r2] =
        pid_controller_pitch_P.Constant6_Value_g;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<S39>/Constant'
    //   Constant: '<S39>/Constant1'
    //   DataTypeConversion: '<S5>/Data Type Conversion'
    //   DataTypeConversion: '<S5>/Data Type Conversion1'
    //   DataTypeConversion: '<S5>/Data Type Conversion2'
    //   DataTypeConversion: '<S5>/Data Type Conversion3'
    //   DataTypeConversion: '<S5>/Data Type Conversion4'
    //   MATLAB Function: '<S27>/MATLAB Function'
    //   MATLAB Function: '<S30>/EKF_Y'
    //   MATLAB Function: '<S39>/MATLAB Function'
    //   SignalConversion generated from: '<S41>/ SFunction '

    pid_controller_pitch_B.ManualSwitch2[0] = rtb_DataTypeConversion1_ds;
    pid_controller_pitch_B.ManualSwitch2[1] = rtb_DataTypeConversion1_f;
    pid_controller_pitch_B.ManualSwitch2[2] = rtb_DataTypeConversion1_e;
    pid_controller_pitch_B.ManualSwitch2[3] = rtb_DataTypeConversion1_g;
    pid_controller_pitch_B.ManualSwitch2[4] = pid_controller_pitch_B.In1_dn.x;
    pid_controller_pitch_B.ManualSwitch2[5] = pid_controller_pitch_B.In1_dn.y;
    pid_controller_pitch_B.ManualSwitch2[6] = pid_controller_pitch_B.In1_dn.z;
    pid_controller_pitch_B.ManualSwitch2[7] = pid_controller_pitch_B.In1_d.x;
    pid_controller_pitch_B.ManualSwitch2[8] = pid_controller_pitch_B.In1_d.y;
    pid_controller_pitch_B.ManualSwitch2[9] = pid_controller_pitch_B.In1_d.z;
    pid_controller_pitch_B.ManualSwitch2[10] =
      pid_controller_pitch_B.In1.rollspeed;
    pid_controller_pitch_B.ManualSwitch2[11] =
      pid_controller_pitch_B.In1.pitchspeed;
    pid_controller_pitch_B.ManualSwitch2[12] =
      pid_controller_pitch_B.In1.yawspeed;
    pid_controller_pitch_B.ManualSwitch2[13] = pid_controller_pitch_B.y_f[0];
    pid_controller_pitch_B.ManualSwitch2[14] = pid_controller_pitch_B.y_f[1];
    pid_controller_pitch_B.ManualSwitch2[15] = pid_controller_pitch_B.y_f[2];
    pid_controller_pitch_B.ManualSwitch2[16] = pid_controller_pitch_B.In1_k.x;
    pid_controller_pitch_B.ManualSwitch2[17] = pid_controller_pitch_B.In1_k.y;
    pid_controller_pitch_B.ManualSwitch2[18] = pid_controller_pitch_B.In1_k.z;
    pid_controller_pitch_B.ManualSwitch2[19] =
      pid_controller_pitch_DW.Memory4_PreviousInput[0];
    pid_controller_pitch_B.ManualSwitch2[20] =
      pid_controller_pitch_DW.Memory4_PreviousInput[1];
    pid_controller_pitch_B.ManualSwitch2[21] =
      pid_controller_pitch_DW.Memory4_PreviousInput_d;
    pid_controller_pitch_B.ManualSwitch2[22] =
      pid_controller_pitch_DW.Memory6_PreviousInput[0];
    pid_controller_pitch_B.ManualSwitch2[23] =
      pid_controller_pitch_DW.Memory6_PreviousInput[1];
    pid_controller_pitch_B.ManualSwitch2[24] =
      pid_controller_pitch_DW.Memory6_PreviousInput[2];
    pid_controller_pitch_B.ManualSwitch2[25] = pid_controller_pitch_B.tth;
    pid_controller_pitch_B.ManualSwitch2[26] =
      pid_controller_pitch_P.Constant_Value_db;
    pid_controller_pitch_B.ManualSwitch2[27] =
      pid_controller_pitch_P.Constant1_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // SignalConversion generated from: '<Root>/To Workspace1'
  pid_controller_pitch_B.TmpSignalConversionAt_asyncqueu[0] =
    pid_controller_pitch_B.DigitalClock1;
  memcpy(&pid_controller_pitch_B.TmpSignalConversionAt_asyncqueu[1],
         &pid_controller_pitch_B.ManualSwitch2[0], 28U * sizeof(real_T));

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S19>/MATLAB Function2'
  //   MATLAB Function: '<S30>/EKF_Y'
  //   SignalConversion generated from: '<S37>/ SFunction '

  pid_controller_pitch_B.Gain2[2] = pid_controller_pitch_P.Gain2_Gain *
    pid_controller_pitch_DW.Memory4_PreviousInput_d;

  // SignalConversion generated from: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'

  pid_controller_pitch_DW.Delay2_DSTATE_fv[0] = pid_controller_pitch_B.At1_tmp;
  pid_controller_pitch_DW.Delay2_DSTATE_fv[1] = pid_controller_pitch_B.sph;
  pid_controller_pitch_DW.Delay2_DSTATE_fv[2] = pid_controller_pitch_B.Pt_f;

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S27>/MATLAB Function'

  pid_controller_pitch_B.Gain2[0] = pid_controller_pitch_P.Gain2_Gain *
    pid_controller_pitch_DW.Memory4_PreviousInput[0];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S18>/RP_computation'

  pid_controller_pitch_B.Gain_e[0] = pid_controller_pitch_P.Gain_Gain_d *
    pid_controller_pitch_B.ph_meas;

  // Gain: '<S19>/Gain2' incorporates:
  //   MATLAB Function: '<S27>/MATLAB Function'

  pid_controller_pitch_B.Gain2[1] = pid_controller_pitch_P.Gain2_Gain *
    pid_controller_pitch_DW.Memory4_PreviousInput[1];

  // Gain: '<S4>/Gain' incorporates:
  //   MATLAB Function: '<S18>/Y_computation'

  pid_controller_pitch_B.Gain_e[1] = pid_controller_pitch_B.Sum23_g *
    pid_controller_pitch_P.Gain_Gain_d;
  pid_controller_pitch_B.Gain_e[2] = pid_controller_pitch_P.Gain_Gain_d *
    pid_controller_pitch_B.wq1;

  // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion2'

  pid_controller_pitch_B.y_c[0] = pid_controller_pitch_B.In1_d.x;
  pid_controller_pitch_B.y_c[1] = -static_cast<real_T>
    (pid_controller_pitch_B.In1_d.y);
  pid_controller_pitch_B.y_c[2] = -static_cast<real_T>
    (pid_controller_pitch_B.In1_d.z);

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<S16>/Data Type Conversion1'

  pid_controller_pitch_B.y_i[0] = -static_cast<real_T>
    (pid_controller_pitch_B.In1_dn.x);
  pid_controller_pitch_B.y_i[1] = pid_controller_pitch_B.In1_dn.y;
  pid_controller_pitch_B.y_i[2] = pid_controller_pitch_B.In1_dn.z;

  // Gain: '<S16>/Gain1'
  pid_controller_pitch_B.Sum23_g = pid_controller_pitch_B.y_c[0];
  pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.y_c[1];
  pid_controller_pitch_B.wq1 = pid_controller_pitch_B.y_c[2];

  // Gain: '<S16>/Gain'
  pid_controller_pitch_B.wr1 = pid_controller_pitch_B.y_i[0];
  pid_controller_pitch_B.cph = pid_controller_pitch_B.y_i[1];
  pid_controller_pitch_B.cth = pid_controller_pitch_B.y_i[2];
  for (pid_controller_pitch_B.r2 = 0; pid_controller_pitch_B.r2 < 3;
       pid_controller_pitch_B.r2++) {
    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.sph =
      pid_controller_pitch_P.Rz[pid_controller_pitch_B.r2];

    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.ph_meas = pid_controller_pitch_B.sph *
      pid_controller_pitch_B.Sum23_g;

    // Gain: '<S16>/Gain'
    pid_controller_pitch_B.Pt_f = pid_controller_pitch_B.sph *
      pid_controller_pitch_B.wr1;

    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.sph =
      pid_controller_pitch_P.Rz[pid_controller_pitch_B.r2 + 3];

    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.ph_meas += pid_controller_pitch_B.sph *
      pid_controller_pitch_B.At1_tmp;

    // Gain: '<S16>/Gain'
    pid_controller_pitch_B.Pt_f += pid_controller_pitch_B.sph *
      pid_controller_pitch_B.cph;

    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.sph =
      pid_controller_pitch_P.Rz[pid_controller_pitch_B.r2 + 6];

    // Gain: '<S16>/Gain'
    pid_controller_pitch_B.TmpSignalConversionAtSFunct[pid_controller_pitch_B.r2]
      = pid_controller_pitch_B.sph * pid_controller_pitch_B.cth +
      pid_controller_pitch_B.Pt_f;

    // Gain: '<S16>/Gain1'
    pid_controller_pitch_B.u_vect[pid_controller_pitch_B.r2] =
      pid_controller_pitch_B.sph * pid_controller_pitch_B.wq1 +
      pid_controller_pitch_B.ph_meas;

    // Gain: '<Root>/Gain1'
    pid_controller_pitch_B.Gain1_g[pid_controller_pitch_B.r2] =
      pid_controller_pitch_P.Gain1_Gain_n *
      pid_controller_pitch_B.y_f[pid_controller_pitch_B.r2];
  }

  // MATLAB Function: '<Root>/MATLAB Function3' incorporates:
  //   Gain: '<Root>/Gain1'

  pid_controller_pitch_B.y1_p = pid_controller_pitch_B.Gain1_g[0];
  pid_controller_pitch_B.y2_ew = pid_controller_pitch_B.Gain1_g[1];
  pid_controller_pitch_B.y3_o = pid_controller_pitch_B.Gain1_g[2];

  // MATLAB Function: '<S19>/MATLAB Function7'
  pid_controller__MATLABFunction1(pid_controller_pitch_B.Gain2,
    &pid_controller_pitch_B.y1_k, &pid_controller_pitch_B.y2_b,
    &pid_controller_pitch_B.y3_j, &pid_controller_pitch_DW.sf_MATLABFunction7);

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant5'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<Root>/Sum2'

  if (pid_controller_pitch_P.ManualSwitch_CurrentSetting == 1) {
    pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.y2_b +
      pid_controller_pitch_P.Constant5_Value;
  } else {
    pid_controller_pitch_B.At1_tmp = pid_controller_pitch_B.y2_ew +
      pid_controller_pitch_P.Constant_Value_be;
  }

  // Sum: '<S1>/Sum2' incorporates:
  //   DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1'
  //   Gain: '<Root>/Gain2'
  //   ManualSwitch: '<Root>/Manual Switch'

  pid_controller_pitch_B.Sum2_b =
    pid_controller_pitch_P.DiscreteTransferFcn1_NumCoef_ks *
    pid_controller_pitch_DW.DiscreteTransferFcn1_states_e -
    pid_controller_pitch_P.Gain2_Gain_b * pid_controller_pitch_B.At1_tmp;

  // MATLAB Function: '<S4>/MATLAB Function1'
  pid_controller__MATLABFunction1(pid_controller_pitch_B.Gain_e,
    &pid_controller_pitch_B.y1_l, &pid_controller_pitch_B.y2_k,
    &pid_controller_pitch_B.y3_a, &pid_controller_pitch_DW.sf_MATLABFunction1_m);

  // MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
  //   Constant: '<S5>/failsafe'

  for (i = 0; i < 8; i++) {
    pid_controller_pitch_B.pwmValue[i] = 0U;
  }

  pid_controller_pitch_B.pwmValue[0] = rtb_DataTypeConversion1_ds;
  pid_controller_pitch_B.pwmValue[1] = rtb_DataTypeConversion1_f;
  pid_controller_pitch_B.pwmValue[2] = rtb_DataTypeConversion1_e;
  pid_controller_pitch_B.pwmValue[3] = rtb_DataTypeConversion1_g;
  if (rtb_startingswitch) {
    if (!pid_controller_pitch_DW.obj.isArmed) {
      pid_controller_pitch_DW.obj.isArmed = true;
      rtb_DataTypeConversion1_ds = pwm_arm
        (&pid_controller_pitch_DW.obj.pwmDevHandler,
         &pid_controller_pitch_DW.obj.armAdvertiseObj);
      pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (pid_controller_pitch_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
    }

    rtb_DataTypeConversion1_ds = pwm_setServo
      (&pid_controller_pitch_DW.obj.pwmDevHandler,
       pid_controller_pitch_DW.obj.servoCount,
       pid_controller_pitch_DW.obj.channelMask,
       &pid_controller_pitch_B.pwmValue[0], pid_controller_pitch_DW.obj.isMain,
       &pid_controller_pitch_DW.obj.actuatorAdvertiseObj);
    pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (pid_controller_pitch_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  } else {
    rtb_DataTypeConversion1_ds = pwm_disarm
      (&pid_controller_pitch_DW.obj.pwmDevHandler,
       &pid_controller_pitch_DW.obj.armAdvertiseObj);
    pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (pid_controller_pitch_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
    pid_controller_pitch_DW.obj.isArmed = false;
    rtb_DataTypeConversion1_ds = pwm_resetServo
      (&pid_controller_pitch_DW.obj.pwmDevHandler,
       pid_controller_pitch_DW.obj.servoCount,
       pid_controller_pitch_DW.obj.channelMask,
       pid_controller_pitch_DW.obj.isMain,
       &pid_controller_pitch_DW.obj.actuatorAdvertiseObj);
    pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (pid_controller_pitch_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  }

  if (pid_controller_pitch_DW.obj.isMain) {
    rtb_DataTypeConversion1_ds = pwm_forceFailsafe
      (&pid_controller_pitch_DW.obj.pwmDevHandler, static_cast<int32_T>
       (pid_controller_pitch_P.failsafe_Value));
    pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
      (pid_controller_pitch_DW.obj.errorStatus | rtb_DataTypeConversion1_ds);
  }

  // End of MATLABSystem: '<S5>/PX4 PWM Output'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = uORB_read_step(pid_controller_pitch_DW.obj_h.orbMetadataObj,
    &pid_controller_pitch_DW.obj_h.eventStructObj,
    &pid_controller_pitch_B.b_varargout_2_c, false, 1.0);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S46>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S46>/In1'
    pid_controller_pitch_B.In1_h = pid_controller_pitch_B.b_varargout_2_c;
    srUpdateBC(pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_kv);
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  pid_controller_pitch_B.SignalConversion[0] =
    pid_controller_pitch_B.In1_h.output[0];
  pid_controller_pitch_B.SignalConversion[1] =
    pid_controller_pitch_B.In1_h.output[1];
  pid_controller_pitch_B.SignalConversion[2] =
    pid_controller_pitch_B.In1_h.output[2];
  pid_controller_pitch_B.SignalConversion[3] =
    pid_controller_pitch_B.In1_h.output[3];

  // Update for Delay: '<S1>/Delay3'
  pid_controller_pitch_DW.Delay3_DSTATE = pid_controller_pitch_B.u_sat;

  // Update for DiscreteStateSpace: '<S10>/Internal'
  {
    pid_controller_pitch_DW.Internal_DSTATE = pid_controller_pitch_B.Sum2_b +
      pid_controller_pitch_P.Internal_A*pid_controller_pitch_DW.Internal_DSTATE;
  }

  // Update for Delay: '<S1>/Delay2'
  pid_controller_pitch_DW.Delay2_DSTATE[0] = pid_controller_pitch_B.x_idx_0;
  pid_controller_pitch_DW.Delay2_DSTATE[1] = pid_controller_pitch_B.x;

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn'

  pid_controller_pitch_DW.DiscreteTransferFcn_states =
    (pid_controller_pitch_P.DiscreteTransferFcn_NumCoef_o *
     pid_controller_pitch_DW.DiscreteTransferFcn_states_p -
     pid_controller_pitch_P.DiscreteTransferFcn_DenCoef[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn_states) /
    pid_controller_pitch_P.DiscreteTransferFcn_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1'

  pid_controller_pitch_DW.DiscreteTransferFcn1_states =
    (pid_controller_pitch_P.DiscreteTransferFcn1_NumCoef_c *
     pid_controller_pitch_DW.DiscreteTransferFcn1_states_l -
     pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn1_states) /
    pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef[0];

  // Update for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' incorporates:
  //   DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2'

  pid_controller_pitch_DW.DiscreteTransferFcn2_states =
    (pid_controller_pitch_P.DiscreteTransferFcn2_NumCoef_l *
     pid_controller_pitch_DW.DiscreteTransferFcn2_states_g -
     pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn2_states) /
    pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef[0];

  // Update for Delay: '<S25>/Delay' incorporates:
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1'
  //   DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2'

  pid_controller_pitch_DW.Delay_DSTATE_e[0] = pid_controller_pitch_B.y_g;
  pid_controller_pitch_DW.Delay_DSTATE_e[1] = pid_controller_pitch_B.y_m;
  pid_controller_pitch_DW.Delay_DSTATE_e[2] = pid_controller_pitch_B.y_n;

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  pid_controller_pitch_DW.Delay23_DSTATE[0] =
    pid_controller_pitch_DW.Delay22_DSTATE[0];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  pid_controller_pitch_DW.Delay22_DSTATE[0] =
    pid_controller_pitch_DW.Delay21_DSTATE[0];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  pid_controller_pitch_DW.Delay21_DSTATE[0] =
    pid_controller_pitch_DW.Delay20_DSTATE[0];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  pid_controller_pitch_DW.Delay20_DSTATE[0] =
    pid_controller_pitch_DW.Delay14_DSTATE[0];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  pid_controller_pitch_DW.Delay14_DSTATE[0] =
    pid_controller_pitch_DW.Delay13_DSTATE[0];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  pid_controller_pitch_DW.Delay13_DSTATE[0] =
    pid_controller_pitch_DW.Delay12_DSTATE[0];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  pid_controller_pitch_DW.Delay12_DSTATE[0] =
    pid_controller_pitch_DW.Delay11_DSTATE[0];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  pid_controller_pitch_DW.Delay11_DSTATE[0] =
    pid_controller_pitch_DW.Delay10_DSTATE[0];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  pid_controller_pitch_DW.Delay10_DSTATE[0] =
    pid_controller_pitch_DW.Delay9_DSTATE[0];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  pid_controller_pitch_DW.Delay9_DSTATE[0] =
    pid_controller_pitch_DW.Delay8_DSTATE[0];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  pid_controller_pitch_DW.Delay8_DSTATE[0] =
    pid_controller_pitch_DW.Delay7_DSTATE[0];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  pid_controller_pitch_DW.Delay7_DSTATE[0] =
    pid_controller_pitch_DW.Delay6_DSTATE[0];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  pid_controller_pitch_DW.Delay6_DSTATE[0] =
    pid_controller_pitch_DW.Delay5_DSTATE[0];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  pid_controller_pitch_DW.Delay5_DSTATE[0] =
    pid_controller_pitch_DW.Delay4_DSTATE[0];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  pid_controller_pitch_DW.Delay4_DSTATE[0] =
    pid_controller_pitch_DW.Delay3_DSTATE_j[0];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  pid_controller_pitch_DW.Delay3_DSTATE_j[0] =
    pid_controller_pitch_DW.Delay2_DSTATE_f[0];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  pid_controller_pitch_DW.Delay2_DSTATE_f[0] =
    pid_controller_pitch_DW.Delay1_DSTATE[0];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  pid_controller_pitch_DW.Delay1_DSTATE[0] =
    pid_controller_pitch_DW.Delay_DSTATE[0];

  // Update for Delay: '<S29>/Delay'
  pid_controller_pitch_DW.Delay_DSTATE[0] = pid_controller_pitch_B.y_idx_0;

  // Update for Delay: '<S25>/Delay1'
  pid_controller_pitch_DW.Delay1_DSTATE_m[0] =
    pid_controller_pitch_B.rtb_Delay_i_idx_0;

  // Update for Delay: '<S25>/Delay2'
  pid_controller_pitch_DW.Delay2_DSTATE_k[0] =
    pid_controller_pitch_B.rtb_Delay1_g_idx_0;

  // Update for Delay: '<S25>/Delay3'
  pid_controller_pitch_DW.Delay3_DSTATE_c[0] =
    pid_controller_pitch_B.rtb_Delay2_g_idx_0;

  // Update for Delay: '<S25>/Delay4'
  pid_controller_pitch_DW.Delay4_DSTATE_j[0] =
    pid_controller_pitch_B.rtb_Delay3_f_idx_0;

  // Update for Delay: '<S25>/Delay5'
  pid_controller_pitch_DW.Delay5_DSTATE_e[0] =
    pid_controller_pitch_B.rtb_Delay4_p_idx_0;

  // Update for Delay: '<S25>/Delay6'
  pid_controller_pitch_DW.Delay6_DSTATE_j[0] =
    pid_controller_pitch_B.rtb_Delay5_l_idx_0;

  // Update for Delay: '<S25>/Delay7'
  pid_controller_pitch_DW.Delay7_DSTATE_l[0] =
    pid_controller_pitch_B.rtb_Delay6_g_idx_0;

  // Update for Delay: '<S25>/Delay8'
  pid_controller_pitch_DW.Delay8_DSTATE_m[0] =
    pid_controller_pitch_B.rtb_Delay7_l_idx_0;

  // Update for Delay: '<S25>/Delay9'
  pid_controller_pitch_DW.Delay9_DSTATE_e[0] =
    pid_controller_pitch_B.rtb_Delay8_e_idx_0;

  // Update for Delay: '<S25>/Delay10'
  pid_controller_pitch_DW.Delay10_DSTATE_a[0] =
    pid_controller_pitch_B.rtb_Delay9_c_idx_0;

  // Update for Delay: '<S25>/Delay11'
  pid_controller_pitch_DW.Delay11_DSTATE_m[0] =
    pid_controller_pitch_B.rtb_Delay10_g_idx_0;

  // Update for Delay: '<S25>/Delay12'
  pid_controller_pitch_DW.Delay12_DSTATE_h[0] =
    pid_controller_pitch_B.rtb_Delay11_g_idx_0;

  // Update for Delay: '<S25>/Delay13'
  pid_controller_pitch_DW.Delay13_DSTATE_b[0] =
    pid_controller_pitch_B.rtb_Delay12_k_idx_0;

  // Update for Delay: '<S25>/Delay14'
  pid_controller_pitch_DW.Delay14_DSTATE_k[0] =
    pid_controller_pitch_B.rtb_Delay13_o_idx_0;

  // Update for Delay: '<S25>/Delay15'
  pid_controller_pitch_DW.Delay15_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay14_a_idx_0;

  // Update for Delay: '<S25>/Delay20'
  pid_controller_pitch_DW.Delay20_DSTATE_m[0] =
    pid_controller_pitch_B.rtb_Delay15_idx_0;

  // Update for Delay: '<S25>/Delay21'
  pid_controller_pitch_DW.Delay21_DSTATE_b[0] =
    pid_controller_pitch_B.rtb_Delay20_m_idx_0;

  // Update for Delay: '<S25>/Delay22'
  pid_controller_pitch_DW.Delay22_DSTATE_g[0] =
    pid_controller_pitch_B.rtb_Delay21_j_idx_0;

  // Update for Delay: '<S25>/Delay23'
  pid_controller_pitch_DW.Delay23_DSTATE_e[0] =
    pid_controller_pitch_B.rtb_Delay22_c_idx_0;

  // Update for Delay: '<S25>/Delay24'
  pid_controller_pitch_DW.Delay24_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay23_a_idx_0;

  // Update for Delay: '<S25>/Delay25'
  pid_controller_pitch_DW.Delay25_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay24_idx_0;

  // Update for Delay: '<S25>/Delay26'
  pid_controller_pitch_DW.Delay26_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay25_idx_0;

  // Update for Delay: '<S25>/Delay27'
  pid_controller_pitch_DW.Delay27_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay26_idx_0;

  // Update for Delay: '<S25>/Delay16'
  pid_controller_pitch_DW.Delay16_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay27_idx_0;

  // Update for Delay: '<S25>/Delay17'
  pid_controller_pitch_DW.Delay17_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay16_idx_0;

  // Update for Delay: '<S25>/Delay18'
  pid_controller_pitch_DW.Delay18_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay17_idx_0;

  // Update for Delay: '<S25>/Delay19'
  pid_controller_pitch_DW.Delay19_DSTATE[0] =
    pid_controller_pitch_B.rtb_Delay18_idx_0;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  pid_controller_pitch_DW.Delay2_DSTATE_l[0] =
    pid_controller_pitch_DW.Delay2_DSTATE_fv[0];

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  pid_controller_pitch_DW.Delay23_DSTATE[1] =
    pid_controller_pitch_DW.Delay22_DSTATE[1];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  pid_controller_pitch_DW.Delay22_DSTATE[1] =
    pid_controller_pitch_DW.Delay21_DSTATE[1];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  pid_controller_pitch_DW.Delay21_DSTATE[1] =
    pid_controller_pitch_DW.Delay20_DSTATE[1];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  pid_controller_pitch_DW.Delay20_DSTATE[1] =
    pid_controller_pitch_DW.Delay14_DSTATE[1];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  pid_controller_pitch_DW.Delay14_DSTATE[1] =
    pid_controller_pitch_DW.Delay13_DSTATE[1];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  pid_controller_pitch_DW.Delay13_DSTATE[1] =
    pid_controller_pitch_DW.Delay12_DSTATE[1];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  pid_controller_pitch_DW.Delay12_DSTATE[1] =
    pid_controller_pitch_DW.Delay11_DSTATE[1];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  pid_controller_pitch_DW.Delay11_DSTATE[1] =
    pid_controller_pitch_DW.Delay10_DSTATE[1];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  pid_controller_pitch_DW.Delay10_DSTATE[1] =
    pid_controller_pitch_DW.Delay9_DSTATE[1];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  pid_controller_pitch_DW.Delay9_DSTATE[1] =
    pid_controller_pitch_DW.Delay8_DSTATE[1];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  pid_controller_pitch_DW.Delay8_DSTATE[1] =
    pid_controller_pitch_DW.Delay7_DSTATE[1];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  pid_controller_pitch_DW.Delay7_DSTATE[1] =
    pid_controller_pitch_DW.Delay6_DSTATE[1];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  pid_controller_pitch_DW.Delay6_DSTATE[1] =
    pid_controller_pitch_DW.Delay5_DSTATE[1];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  pid_controller_pitch_DW.Delay5_DSTATE[1] =
    pid_controller_pitch_DW.Delay4_DSTATE[1];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  pid_controller_pitch_DW.Delay4_DSTATE[1] =
    pid_controller_pitch_DW.Delay3_DSTATE_j[1];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  pid_controller_pitch_DW.Delay3_DSTATE_j[1] =
    pid_controller_pitch_DW.Delay2_DSTATE_f[1];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  pid_controller_pitch_DW.Delay2_DSTATE_f[1] =
    pid_controller_pitch_DW.Delay1_DSTATE[1];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  pid_controller_pitch_DW.Delay1_DSTATE[1] =
    pid_controller_pitch_DW.Delay_DSTATE[1];

  // Update for Delay: '<S29>/Delay'
  pid_controller_pitch_DW.Delay_DSTATE[1] = pid_controller_pitch_B.y_idx_1;

  // Update for Delay: '<S25>/Delay1'
  pid_controller_pitch_DW.Delay1_DSTATE_m[1] =
    pid_controller_pitch_B.rtb_Delay_i_idx_1;

  // Update for Delay: '<S25>/Delay2'
  pid_controller_pitch_DW.Delay2_DSTATE_k[1] =
    pid_controller_pitch_B.rtb_Delay1_g_idx_1;

  // Update for Delay: '<S25>/Delay3'
  pid_controller_pitch_DW.Delay3_DSTATE_c[1] =
    pid_controller_pitch_B.rtb_Delay2_g_idx_1;

  // Update for Delay: '<S25>/Delay4'
  pid_controller_pitch_DW.Delay4_DSTATE_j[1] =
    pid_controller_pitch_B.rtb_Delay3_f_idx_1;

  // Update for Delay: '<S25>/Delay5'
  pid_controller_pitch_DW.Delay5_DSTATE_e[1] =
    pid_controller_pitch_B.rtb_Delay4_p_idx_1;

  // Update for Delay: '<S25>/Delay6'
  pid_controller_pitch_DW.Delay6_DSTATE_j[1] =
    pid_controller_pitch_B.rtb_Delay5_l_idx_1;

  // Update for Delay: '<S25>/Delay7'
  pid_controller_pitch_DW.Delay7_DSTATE_l[1] =
    pid_controller_pitch_B.rtb_Delay6_g_idx_1;

  // Update for Delay: '<S25>/Delay8'
  pid_controller_pitch_DW.Delay8_DSTATE_m[1] =
    pid_controller_pitch_B.rtb_Delay7_l_idx_1;

  // Update for Delay: '<S25>/Delay9'
  pid_controller_pitch_DW.Delay9_DSTATE_e[1] =
    pid_controller_pitch_B.rtb_Delay8_e_idx_1;

  // Update for Delay: '<S25>/Delay10'
  pid_controller_pitch_DW.Delay10_DSTATE_a[1] =
    pid_controller_pitch_B.rtb_Delay9_c_idx_1;

  // Update for Delay: '<S25>/Delay11'
  pid_controller_pitch_DW.Delay11_DSTATE_m[1] =
    pid_controller_pitch_B.rtb_Delay10_g_idx_1;

  // Update for Delay: '<S25>/Delay12'
  pid_controller_pitch_DW.Delay12_DSTATE_h[1] =
    pid_controller_pitch_B.rtb_Delay11_g_idx_1;

  // Update for Delay: '<S25>/Delay13'
  pid_controller_pitch_DW.Delay13_DSTATE_b[1] =
    pid_controller_pitch_B.rtb_Delay12_k_idx_1;

  // Update for Delay: '<S25>/Delay14'
  pid_controller_pitch_DW.Delay14_DSTATE_k[1] =
    pid_controller_pitch_B.rtb_Delay13_o_idx_1;

  // Update for Delay: '<S25>/Delay15'
  pid_controller_pitch_DW.Delay15_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay14_a_idx_1;

  // Update for Delay: '<S25>/Delay20'
  pid_controller_pitch_DW.Delay20_DSTATE_m[1] =
    pid_controller_pitch_B.rtb_Delay15_idx_1;

  // Update for Delay: '<S25>/Delay21'
  pid_controller_pitch_DW.Delay21_DSTATE_b[1] =
    pid_controller_pitch_B.rtb_Delay20_m_idx_1;

  // Update for Delay: '<S25>/Delay22'
  pid_controller_pitch_DW.Delay22_DSTATE_g[1] =
    pid_controller_pitch_B.rtb_Delay21_j_idx_1;

  // Update for Delay: '<S25>/Delay23'
  pid_controller_pitch_DW.Delay23_DSTATE_e[1] =
    pid_controller_pitch_B.rtb_Delay22_c_idx_1;

  // Update for Delay: '<S25>/Delay24'
  pid_controller_pitch_DW.Delay24_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay23_a_idx_1;

  // Update for Delay: '<S25>/Delay25'
  pid_controller_pitch_DW.Delay25_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay24_idx_1;

  // Update for Delay: '<S25>/Delay26'
  pid_controller_pitch_DW.Delay26_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay25_idx_1;

  // Update for Delay: '<S25>/Delay27'
  pid_controller_pitch_DW.Delay27_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay26_idx_1;

  // Update for Delay: '<S25>/Delay16'
  pid_controller_pitch_DW.Delay16_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay27_idx_1;

  // Update for Delay: '<S25>/Delay17'
  pid_controller_pitch_DW.Delay17_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay16_idx_1;

  // Update for Delay: '<S25>/Delay18'
  pid_controller_pitch_DW.Delay18_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay17_idx_1;

  // Update for Delay: '<S25>/Delay19'
  pid_controller_pitch_DW.Delay19_DSTATE[1] =
    pid_controller_pitch_B.rtb_Delay18_idx_1;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  pid_controller_pitch_DW.Delay2_DSTATE_l[1] =
    pid_controller_pitch_DW.Delay2_DSTATE_fv[1];

  // Update for Delay: '<S29>/Delay23' incorporates:
  //   Delay: '<S29>/Delay22'
  //
  pid_controller_pitch_DW.Delay23_DSTATE[2] =
    pid_controller_pitch_DW.Delay22_DSTATE[2];

  // Update for Delay: '<S29>/Delay22' incorporates:
  //   Delay: '<S29>/Delay21'
  //
  pid_controller_pitch_DW.Delay22_DSTATE[2] =
    pid_controller_pitch_DW.Delay21_DSTATE[2];

  // Update for Delay: '<S29>/Delay21' incorporates:
  //   Delay: '<S29>/Delay20'
  //
  pid_controller_pitch_DW.Delay21_DSTATE[2] =
    pid_controller_pitch_DW.Delay20_DSTATE[2];

  // Update for Delay: '<S29>/Delay20' incorporates:
  //   Delay: '<S29>/Delay14'
  //
  pid_controller_pitch_DW.Delay20_DSTATE[2] =
    pid_controller_pitch_DW.Delay14_DSTATE[2];

  // Update for Delay: '<S29>/Delay14' incorporates:
  //   Delay: '<S29>/Delay13'
  //
  pid_controller_pitch_DW.Delay14_DSTATE[2] =
    pid_controller_pitch_DW.Delay13_DSTATE[2];

  // Update for Delay: '<S29>/Delay13' incorporates:
  //   Delay: '<S29>/Delay12'
  //
  pid_controller_pitch_DW.Delay13_DSTATE[2] =
    pid_controller_pitch_DW.Delay12_DSTATE[2];

  // Update for Delay: '<S29>/Delay12' incorporates:
  //   Delay: '<S29>/Delay11'
  //
  pid_controller_pitch_DW.Delay12_DSTATE[2] =
    pid_controller_pitch_DW.Delay11_DSTATE[2];

  // Update for Delay: '<S29>/Delay11' incorporates:
  //   Delay: '<S29>/Delay10'
  //
  pid_controller_pitch_DW.Delay11_DSTATE[2] =
    pid_controller_pitch_DW.Delay10_DSTATE[2];

  // Update for Delay: '<S29>/Delay10' incorporates:
  //   Delay: '<S29>/Delay9'
  //
  pid_controller_pitch_DW.Delay10_DSTATE[2] =
    pid_controller_pitch_DW.Delay9_DSTATE[2];

  // Update for Delay: '<S29>/Delay9' incorporates:
  //   Delay: '<S29>/Delay8'
  //
  pid_controller_pitch_DW.Delay9_DSTATE[2] =
    pid_controller_pitch_DW.Delay8_DSTATE[2];

  // Update for Delay: '<S29>/Delay8' incorporates:
  //   Delay: '<S29>/Delay7'
  //
  pid_controller_pitch_DW.Delay8_DSTATE[2] =
    pid_controller_pitch_DW.Delay7_DSTATE[2];

  // Update for Delay: '<S29>/Delay7' incorporates:
  //   Delay: '<S29>/Delay6'
  //
  pid_controller_pitch_DW.Delay7_DSTATE[2] =
    pid_controller_pitch_DW.Delay6_DSTATE[2];

  // Update for Delay: '<S29>/Delay6' incorporates:
  //   Delay: '<S29>/Delay5'
  //
  pid_controller_pitch_DW.Delay6_DSTATE[2] =
    pid_controller_pitch_DW.Delay5_DSTATE[2];

  // Update for Delay: '<S29>/Delay5' incorporates:
  //   Delay: '<S29>/Delay4'
  //
  pid_controller_pitch_DW.Delay5_DSTATE[2] =
    pid_controller_pitch_DW.Delay4_DSTATE[2];

  // Update for Delay: '<S29>/Delay4' incorporates:
  //   Delay: '<S29>/Delay3'
  //
  pid_controller_pitch_DW.Delay4_DSTATE[2] =
    pid_controller_pitch_DW.Delay3_DSTATE_j[2];

  // Update for Delay: '<S29>/Delay3' incorporates:
  //   Delay: '<S29>/Delay2'
  //
  pid_controller_pitch_DW.Delay3_DSTATE_j[2] =
    pid_controller_pitch_DW.Delay2_DSTATE_f[2];

  // Update for Delay: '<S29>/Delay2' incorporates:
  //   Delay: '<S29>/Delay1'
  //
  pid_controller_pitch_DW.Delay2_DSTATE_f[2] =
    pid_controller_pitch_DW.Delay1_DSTATE[2];

  // Update for Delay: '<S29>/Delay1' incorporates:
  //   Delay: '<S29>/Delay'
  //
  pid_controller_pitch_DW.Delay1_DSTATE[2] =
    pid_controller_pitch_DW.Delay_DSTATE[2];

  // Update for Delay: '<S29>/Delay'
  pid_controller_pitch_DW.Delay_DSTATE[2] = pid_controller_pitch_B.y;

  // Update for Delay: '<S25>/Delay1' incorporates:
  //   Delay: '<S25>/Delay'

  pid_controller_pitch_DW.Delay1_DSTATE_m[2] =
    pid_controller_pitch_B.Delay_DSTATE_e;

  // Update for Delay: '<S25>/Delay2' incorporates:
  //   Delay: '<S25>/Delay1'

  pid_controller_pitch_DW.Delay2_DSTATE_k[2] =
    pid_controller_pitch_B.Delay1_DSTATE_m;

  // Update for Delay: '<S25>/Delay3' incorporates:
  //   Delay: '<S25>/Delay2'

  pid_controller_pitch_DW.Delay3_DSTATE_c[2] =
    pid_controller_pitch_B.Delay2_DSTATE_k;

  // Update for Delay: '<S25>/Delay4' incorporates:
  //   Delay: '<S25>/Delay3'

  pid_controller_pitch_DW.Delay4_DSTATE_j[2] =
    pid_controller_pitch_B.Delay3_DSTATE_c;

  // Update for Delay: '<S25>/Delay5' incorporates:
  //   Delay: '<S25>/Delay4'

  pid_controller_pitch_DW.Delay5_DSTATE_e[2] =
    pid_controller_pitch_B.Delay4_DSTATE_j;

  // Update for Delay: '<S25>/Delay6' incorporates:
  //   Delay: '<S25>/Delay5'

  pid_controller_pitch_DW.Delay6_DSTATE_j[2] =
    pid_controller_pitch_B.Delay5_DSTATE_e;

  // Update for Delay: '<S25>/Delay7' incorporates:
  //   Delay: '<S25>/Delay6'

  pid_controller_pitch_DW.Delay7_DSTATE_l[2] =
    pid_controller_pitch_B.Delay6_DSTATE_j;

  // Update for Delay: '<S25>/Delay8' incorporates:
  //   Delay: '<S25>/Delay7'

  pid_controller_pitch_DW.Delay8_DSTATE_m[2] =
    pid_controller_pitch_B.Delay7_DSTATE_l;

  // Update for Delay: '<S25>/Delay9' incorporates:
  //   Delay: '<S25>/Delay8'

  pid_controller_pitch_DW.Delay9_DSTATE_e[2] =
    pid_controller_pitch_B.Delay8_DSTATE_m;

  // Update for Delay: '<S25>/Delay10' incorporates:
  //   Delay: '<S25>/Delay9'

  pid_controller_pitch_DW.Delay10_DSTATE_a[2] =
    pid_controller_pitch_B.Delay9_DSTATE_e;

  // Update for Delay: '<S25>/Delay11' incorporates:
  //   Delay: '<S25>/Delay10'

  pid_controller_pitch_DW.Delay11_DSTATE_m[2] =
    pid_controller_pitch_B.Delay10_DSTATE_a;

  // Update for Delay: '<S25>/Delay12' incorporates:
  //   Delay: '<S25>/Delay11'

  pid_controller_pitch_DW.Delay12_DSTATE_h[2] =
    pid_controller_pitch_B.Delay11_DSTATE_m;

  // Update for Delay: '<S25>/Delay13' incorporates:
  //   Delay: '<S25>/Delay12'

  pid_controller_pitch_DW.Delay13_DSTATE_b[2] =
    pid_controller_pitch_B.Delay12_DSTATE_h;

  // Update for Delay: '<S25>/Delay14' incorporates:
  //   Delay: '<S25>/Delay13'

  pid_controller_pitch_DW.Delay14_DSTATE_k[2] =
    pid_controller_pitch_B.Delay13_DSTATE_b;

  // Update for Delay: '<S25>/Delay15' incorporates:
  //   Delay: '<S25>/Delay14'

  pid_controller_pitch_DW.Delay15_DSTATE[2] =
    pid_controller_pitch_B.Delay14_DSTATE_k;

  // Update for Delay: '<S25>/Delay20' incorporates:
  //   Delay: '<S25>/Delay15'

  pid_controller_pitch_DW.Delay20_DSTATE_m[2] =
    pid_controller_pitch_B.Delay15_DSTATE;

  // Update for Delay: '<S25>/Delay21' incorporates:
  //   Delay: '<S25>/Delay20'

  pid_controller_pitch_DW.Delay21_DSTATE_b[2] =
    pid_controller_pitch_B.Delay20_DSTATE_m;

  // Update for Delay: '<S25>/Delay22' incorporates:
  //   Delay: '<S25>/Delay21'

  pid_controller_pitch_DW.Delay22_DSTATE_g[2] =
    pid_controller_pitch_B.Delay21_DSTATE_b;

  // Update for Delay: '<S25>/Delay23' incorporates:
  //   Delay: '<S25>/Delay22'

  pid_controller_pitch_DW.Delay23_DSTATE_e[2] =
    pid_controller_pitch_B.Delay22_DSTATE_g;

  // Update for Delay: '<S25>/Delay24' incorporates:
  //   Delay: '<S25>/Delay23'

  pid_controller_pitch_DW.Delay24_DSTATE[2] =
    pid_controller_pitch_B.Delay23_DSTATE_e;

  // Update for Delay: '<S25>/Delay25' incorporates:
  //   Delay: '<S25>/Delay24'

  pid_controller_pitch_DW.Delay25_DSTATE[2] =
    pid_controller_pitch_B.Delay24_DSTATE;

  // Update for Delay: '<S25>/Delay26' incorporates:
  //   Delay: '<S25>/Delay25'

  pid_controller_pitch_DW.Delay26_DSTATE[2] =
    pid_controller_pitch_B.Delay25_DSTATE;

  // Update for Delay: '<S25>/Delay27' incorporates:
  //   Delay: '<S25>/Delay26'

  pid_controller_pitch_DW.Delay27_DSTATE[2] =
    pid_controller_pitch_B.Delay26_DSTATE;

  // Update for Delay: '<S25>/Delay16' incorporates:
  //   Delay: '<S25>/Delay27'

  pid_controller_pitch_DW.Delay16_DSTATE[2] =
    pid_controller_pitch_B.Delay27_DSTATE;

  // Update for Delay: '<S25>/Delay17' incorporates:
  //   Delay: '<S25>/Delay16'

  pid_controller_pitch_DW.Delay17_DSTATE[2] =
    pid_controller_pitch_B.Delay16_DSTATE;

  // Update for Delay: '<S25>/Delay18' incorporates:
  //   Delay: '<S25>/Delay17'

  pid_controller_pitch_DW.Delay18_DSTATE[2] =
    pid_controller_pitch_B.Delay17_DSTATE;

  // Update for Delay: '<S25>/Delay19' incorporates:
  //   Delay: '<S25>/Delay18'

  pid_controller_pitch_DW.Delay19_DSTATE[2] =
    pid_controller_pitch_B.Delay18_DSTATE;

  // Update for Delay: '<S27>/Delay2' incorporates:
  //   Delay: '<S30>/Delay2'

  pid_controller_pitch_DW.Delay2_DSTATE_l[2] =
    pid_controller_pitch_DW.Delay2_DSTATE_fv[2];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn'
  pid_controller_pitch_DW.DiscreteTransferFcn_states_i =
    (pid_controller_pitch_B.u_vect[0] -
     pid_controller_pitch_P.DiscreteTransferFcn_DenCoef_p[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn_states_i) /
    pid_controller_pitch_P.DiscreteTransferFcn_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1'
  pid_controller_pitch_DW.DiscreteTransferFcn1_states_p =
    (pid_controller_pitch_B.u_vect[1] -
     pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_k[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn1_states_p) /
    pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_k[0];

  // Update for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2'
  pid_controller_pitch_DW.DiscreteTransferFcn2_states_o =
    (pid_controller_pitch_B.u_vect[2] -
     pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef_p[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn2_states_o) /
    pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1'
  pid_controller_pitch_DW.DiscreteTransferFcn1_states_e =
    (pid_controller_pitch_B.tth -
     pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_p[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn1_states_e) /
    pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_p[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn'
  pid_controller_pitch_DW.DiscreteTransferFcn_states_p =
    (pid_controller_pitch_B.TmpSignalConversionAtSFunct[0] -
     pid_controller_pitch_P.DiscreteTransferFcn_DenCoef_g[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn_states_p) /
    pid_controller_pitch_P.DiscreteTransferFcn_DenCoef_g[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1'
  pid_controller_pitch_DW.DiscreteTransferFcn1_states_l =
    (pid_controller_pitch_B.TmpSignalConversionAtSFunct[1] -
     pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_pa[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn1_states_l) /
    pid_controller_pitch_P.DiscreteTransferFcn1_DenCoef_pa[0];

  // Update for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2'
  pid_controller_pitch_DW.DiscreteTransferFcn2_states_g =
    (pid_controller_pitch_B.TmpSignalConversionAtSFunct[2] -
     pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef_o[1] *
     pid_controller_pitch_DW.DiscreteTransferFcn2_states_g) /
    pid_controller_pitch_P.DiscreteTransferFcn2_DenCoef_o[0];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  pid_controller_pitch_M->Timing.taskTime0 =
    ((time_T)(++pid_controller_pitch_M->Timing.clockTick0)) *
    pid_controller_pitch_M->Timing.stepSize0;
}

// Model initialize function
void pid_controller_pitch_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(pid_controller_pitch_M, -1);
  pid_controller_pitch_M->Timing.stepSize0 = 0.01;

  // External mode info
  pid_controller_pitch_M->Sizes.checksums[0] = (690580579U);
  pid_controller_pitch_M->Sizes.checksums[1] = (3000780889U);
  pid_controller_pitch_M->Sizes.checksums[2] = (4185478652U);
  pid_controller_pitch_M->Sizes.checksums[3] = (2538067386U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[40];
    pid_controller_pitch_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[20] = (sysRanDType *)
      &pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_kv;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = (sysRanDType *)
      &pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_g;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)
      &pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC_h;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)
      &pid_controller_pitch_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &pid_controller_pitch_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &pid_controller_pitch_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &pid_controller_pitch_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pid_controller_pitch_M->extModeInfo,
      &pid_controller_pitch_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pid_controller_pitch_M->extModeInfo,
                        pid_controller_pitch_M->Sizes.checksums);
    rteiSetTPtr(pid_controller_pitch_M->extModeInfo, rtmGetTPtr
                (pid_controller_pitch_M));
  }

  {
    int32_T i;
    boolean_T rtb_startingswitch;

    // InitializeConditions for Delay: '<S1>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE =
      pid_controller_pitch_P.Delay3_InitialCondition;

    // InitializeConditions for DiscreteStateSpace: '<S10>/Internal'
    pid_controller_pitch_DW.Internal_DSTATE =
      pid_controller_pitch_P.Internal_InitialCondition;

    // InitializeConditions for Delay: '<S1>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE[0] =
      pid_controller_pitch_P.Delay2_InitialCondition[0];
    pid_controller_pitch_DW.Delay2_DSTATE[1] =
      pid_controller_pitch_P.Delay2_InitialCondition[1];

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn' 
    pid_controller_pitch_DW.DiscreteTransferFcn_states =
      pid_controller_pitch_P.DiscreteTransferFcn_InitialStat;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn1' 
    pid_controller_pitch_DW.DiscreteTransferFcn1_states =
      pid_controller_pitch_P.DiscreteTransferFcn1_InitialSta;

    // InitializeConditions for DiscreteTransferFcn: '<S23>/Discrete Transfer Fcn2' 
    pid_controller_pitch_DW.DiscreteTransferFcn2_states =
      pid_controller_pitch_P.DiscreteTransferFcn2_InitialSta;

    // InitializeConditions for Delay: '<S29>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE[0] =
      pid_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE[0] =
      pid_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE[0] =
      pid_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE[0] =
      pid_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE[0] =
      pid_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE[0] =
      pid_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE[0] =
      pid_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE[0] =
      pid_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE[0] =
      pid_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE[0] =
      pid_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE[0] =
      pid_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE[0] =
      pid_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE[0] =
      pid_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE[0] =
      pid_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE[0] =
      pid_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_j[0] =
      pid_controller_pitch_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S29>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_f[0] =
      pid_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S29>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE[0] =
      pid_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE[0] =
      pid_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE_e[0] =
      pid_controller_pitch_P.Delay_InitialCondition_j[0];

    // InitializeConditions for Delay: '<S25>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE_m[0] =
      pid_controller_pitch_P.Delay1_InitialCondition_b[0];

    // InitializeConditions for Delay: '<S25>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_k[0] =
      pid_controller_pitch_P.Delay2_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S25>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_c[0] =
      pid_controller_pitch_P.Delay3_InitialCondition_g[0];

    // InitializeConditions for Delay: '<S25>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE_j[0] =
      pid_controller_pitch_P.Delay4_InitialCondition_i[0];

    // InitializeConditions for Delay: '<S25>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE_e[0] =
      pid_controller_pitch_P.Delay5_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S25>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE_j[0] =
      pid_controller_pitch_P.Delay6_InitialCondition_h[0];

    // InitializeConditions for Delay: '<S25>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE_l[0] =
      pid_controller_pitch_P.Delay7_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S25>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE_m[0] =
      pid_controller_pitch_P.Delay8_InitialCondition_g[0];

    // InitializeConditions for Delay: '<S25>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE_e[0] =
      pid_controller_pitch_P.Delay9_InitialCondition_a[0];

    // InitializeConditions for Delay: '<S25>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE_a[0] =
      pid_controller_pitch_P.Delay10_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S25>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE_m[0] =
      pid_controller_pitch_P.Delay11_InitialCondition_e[0];

    // InitializeConditions for Delay: '<S25>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE_h[0] =
      pid_controller_pitch_P.Delay12_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S25>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE_b[0] =
      pid_controller_pitch_P.Delay13_InitialCondition_f[0];

    // InitializeConditions for Delay: '<S25>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE_k[0] =
      pid_controller_pitch_P.Delay14_InitialCondition_m[0];

    // InitializeConditions for Delay: '<S25>/Delay15'
    pid_controller_pitch_DW.Delay15_DSTATE[0] =
      pid_controller_pitch_P.Delay15_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE_m[0] =
      pid_controller_pitch_P.Delay20_InitialCondition_p[0];

    // InitializeConditions for Delay: '<S25>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE_b[0] =
      pid_controller_pitch_P.Delay21_InitialCondition_l[0];

    // InitializeConditions for Delay: '<S25>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE_g[0] =
      pid_controller_pitch_P.Delay22_InitialCondition_d[0];

    // InitializeConditions for Delay: '<S25>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE_e[0] =
      pid_controller_pitch_P.Delay23_InitialCondition_n[0];

    // InitializeConditions for Delay: '<S25>/Delay24'
    pid_controller_pitch_DW.Delay24_DSTATE[0] =
      pid_controller_pitch_P.Delay24_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay25'
    pid_controller_pitch_DW.Delay25_DSTATE[0] =
      pid_controller_pitch_P.Delay25_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay26'
    pid_controller_pitch_DW.Delay26_DSTATE[0] =
      pid_controller_pitch_P.Delay26_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay27'
    pid_controller_pitch_DW.Delay27_DSTATE[0] =
      pid_controller_pitch_P.Delay27_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay16'
    pid_controller_pitch_DW.Delay16_DSTATE[0] =
      pid_controller_pitch_P.Delay16_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay17'
    pid_controller_pitch_DW.Delay17_DSTATE[0] =
      pid_controller_pitch_P.Delay17_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay18'
    pid_controller_pitch_DW.Delay18_DSTATE[0] =
      pid_controller_pitch_P.Delay18_InitialCondition[0];

    // InitializeConditions for Delay: '<S25>/Delay19'
    pid_controller_pitch_DW.Delay19_DSTATE[0] =
      pid_controller_pitch_P.Delay19_InitialCondition[0];

    // InitializeConditions for Delay: '<S29>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE[1] =
      pid_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE[1] =
      pid_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE[1] =
      pid_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE[1] =
      pid_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE[1] =
      pid_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE[1] =
      pid_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE[1] =
      pid_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE[1] =
      pid_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE[1] =
      pid_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE[1] =
      pid_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE[1] =
      pid_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE[1] =
      pid_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE[1] =
      pid_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE[1] =
      pid_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE[1] =
      pid_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_j[1] =
      pid_controller_pitch_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S29>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_f[1] =
      pid_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S29>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE[1] =
      pid_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE[1] =
      pid_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE_e[1] =
      pid_controller_pitch_P.Delay_InitialCondition_j[1];

    // InitializeConditions for Delay: '<S25>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE_m[1] =
      pid_controller_pitch_P.Delay1_InitialCondition_b[1];

    // InitializeConditions for Delay: '<S25>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_k[1] =
      pid_controller_pitch_P.Delay2_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S25>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_c[1] =
      pid_controller_pitch_P.Delay3_InitialCondition_g[1];

    // InitializeConditions for Delay: '<S25>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE_j[1] =
      pid_controller_pitch_P.Delay4_InitialCondition_i[1];

    // InitializeConditions for Delay: '<S25>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE_e[1] =
      pid_controller_pitch_P.Delay5_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S25>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE_j[1] =
      pid_controller_pitch_P.Delay6_InitialCondition_h[1];

    // InitializeConditions for Delay: '<S25>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE_l[1] =
      pid_controller_pitch_P.Delay7_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S25>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE_m[1] =
      pid_controller_pitch_P.Delay8_InitialCondition_g[1];

    // InitializeConditions for Delay: '<S25>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE_e[1] =
      pid_controller_pitch_P.Delay9_InitialCondition_a[1];

    // InitializeConditions for Delay: '<S25>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE_a[1] =
      pid_controller_pitch_P.Delay10_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S25>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE_m[1] =
      pid_controller_pitch_P.Delay11_InitialCondition_e[1];

    // InitializeConditions for Delay: '<S25>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE_h[1] =
      pid_controller_pitch_P.Delay12_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S25>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE_b[1] =
      pid_controller_pitch_P.Delay13_InitialCondition_f[1];

    // InitializeConditions for Delay: '<S25>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE_k[1] =
      pid_controller_pitch_P.Delay14_InitialCondition_m[1];

    // InitializeConditions for Delay: '<S25>/Delay15'
    pid_controller_pitch_DW.Delay15_DSTATE[1] =
      pid_controller_pitch_P.Delay15_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE_m[1] =
      pid_controller_pitch_P.Delay20_InitialCondition_p[1];

    // InitializeConditions for Delay: '<S25>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE_b[1] =
      pid_controller_pitch_P.Delay21_InitialCondition_l[1];

    // InitializeConditions for Delay: '<S25>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE_g[1] =
      pid_controller_pitch_P.Delay22_InitialCondition_d[1];

    // InitializeConditions for Delay: '<S25>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE_e[1] =
      pid_controller_pitch_P.Delay23_InitialCondition_n[1];

    // InitializeConditions for Delay: '<S25>/Delay24'
    pid_controller_pitch_DW.Delay24_DSTATE[1] =
      pid_controller_pitch_P.Delay24_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay25'
    pid_controller_pitch_DW.Delay25_DSTATE[1] =
      pid_controller_pitch_P.Delay25_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay26'
    pid_controller_pitch_DW.Delay26_DSTATE[1] =
      pid_controller_pitch_P.Delay26_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay27'
    pid_controller_pitch_DW.Delay27_DSTATE[1] =
      pid_controller_pitch_P.Delay27_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay16'
    pid_controller_pitch_DW.Delay16_DSTATE[1] =
      pid_controller_pitch_P.Delay16_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay17'
    pid_controller_pitch_DW.Delay17_DSTATE[1] =
      pid_controller_pitch_P.Delay17_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay18'
    pid_controller_pitch_DW.Delay18_DSTATE[1] =
      pid_controller_pitch_P.Delay18_InitialCondition[1];

    // InitializeConditions for Delay: '<S25>/Delay19'
    pid_controller_pitch_DW.Delay19_DSTATE[1] =
      pid_controller_pitch_P.Delay19_InitialCondition[1];

    // InitializeConditions for Delay: '<S29>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE[2] =
      pid_controller_pitch_P.Delay23_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE[2] =
      pid_controller_pitch_P.Delay22_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE[2] =
      pid_controller_pitch_P.Delay21_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE[2] =
      pid_controller_pitch_P.Delay20_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE[2] =
      pid_controller_pitch_P.Delay14_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE[2] =
      pid_controller_pitch_P.Delay13_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE[2] =
      pid_controller_pitch_P.Delay12_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE[2] =
      pid_controller_pitch_P.Delay11_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE[2] =
      pid_controller_pitch_P.Delay10_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE[2] =
      pid_controller_pitch_P.Delay9_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE[2] =
      pid_controller_pitch_P.Delay8_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE[2] =
      pid_controller_pitch_P.Delay7_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE[2] =
      pid_controller_pitch_P.Delay6_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE[2] =
      pid_controller_pitch_P.Delay5_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE[2] =
      pid_controller_pitch_P.Delay4_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_j[2] =
      pid_controller_pitch_P.Delay3_InitialCondition_h;

    // InitializeConditions for Delay: '<S29>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_f[2] =
      pid_controller_pitch_P.Delay2_InitialCondition_a;

    // InitializeConditions for Delay: '<S29>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE[2] =
      pid_controller_pitch_P.Delay1_InitialCondition;

    // InitializeConditions for Delay: '<S29>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE[2] =
      pid_controller_pitch_P.Delay_InitialCondition;

    // InitializeConditions for Delay: '<S25>/Delay'
    pid_controller_pitch_DW.Delay_DSTATE_e[2] =
      pid_controller_pitch_P.Delay_InitialCondition_j[2];

    // InitializeConditions for Delay: '<S25>/Delay1'
    pid_controller_pitch_DW.Delay1_DSTATE_m[2] =
      pid_controller_pitch_P.Delay1_InitialCondition_b[2];

    // InitializeConditions for Delay: '<S25>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_k[2] =
      pid_controller_pitch_P.Delay2_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S25>/Delay3'
    pid_controller_pitch_DW.Delay3_DSTATE_c[2] =
      pid_controller_pitch_P.Delay3_InitialCondition_g[2];

    // InitializeConditions for Delay: '<S25>/Delay4'
    pid_controller_pitch_DW.Delay4_DSTATE_j[2] =
      pid_controller_pitch_P.Delay4_InitialCondition_i[2];

    // InitializeConditions for Delay: '<S25>/Delay5'
    pid_controller_pitch_DW.Delay5_DSTATE_e[2] =
      pid_controller_pitch_P.Delay5_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S25>/Delay6'
    pid_controller_pitch_DW.Delay6_DSTATE_j[2] =
      pid_controller_pitch_P.Delay6_InitialCondition_h[2];

    // InitializeConditions for Delay: '<S25>/Delay7'
    pid_controller_pitch_DW.Delay7_DSTATE_l[2] =
      pid_controller_pitch_P.Delay7_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S25>/Delay8'
    pid_controller_pitch_DW.Delay8_DSTATE_m[2] =
      pid_controller_pitch_P.Delay8_InitialCondition_g[2];

    // InitializeConditions for Delay: '<S25>/Delay9'
    pid_controller_pitch_DW.Delay9_DSTATE_e[2] =
      pid_controller_pitch_P.Delay9_InitialCondition_a[2];

    // InitializeConditions for Delay: '<S25>/Delay10'
    pid_controller_pitch_DW.Delay10_DSTATE_a[2] =
      pid_controller_pitch_P.Delay10_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S25>/Delay11'
    pid_controller_pitch_DW.Delay11_DSTATE_m[2] =
      pid_controller_pitch_P.Delay11_InitialCondition_e[2];

    // InitializeConditions for Delay: '<S25>/Delay12'
    pid_controller_pitch_DW.Delay12_DSTATE_h[2] =
      pid_controller_pitch_P.Delay12_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S25>/Delay13'
    pid_controller_pitch_DW.Delay13_DSTATE_b[2] =
      pid_controller_pitch_P.Delay13_InitialCondition_f[2];

    // InitializeConditions for Delay: '<S25>/Delay14'
    pid_controller_pitch_DW.Delay14_DSTATE_k[2] =
      pid_controller_pitch_P.Delay14_InitialCondition_m[2];

    // InitializeConditions for Delay: '<S25>/Delay15'
    pid_controller_pitch_DW.Delay15_DSTATE[2] =
      pid_controller_pitch_P.Delay15_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay20'
    pid_controller_pitch_DW.Delay20_DSTATE_m[2] =
      pid_controller_pitch_P.Delay20_InitialCondition_p[2];

    // InitializeConditions for Delay: '<S25>/Delay21'
    pid_controller_pitch_DW.Delay21_DSTATE_b[2] =
      pid_controller_pitch_P.Delay21_InitialCondition_l[2];

    // InitializeConditions for Delay: '<S25>/Delay22'
    pid_controller_pitch_DW.Delay22_DSTATE_g[2] =
      pid_controller_pitch_P.Delay22_InitialCondition_d[2];

    // InitializeConditions for Delay: '<S25>/Delay23'
    pid_controller_pitch_DW.Delay23_DSTATE_e[2] =
      pid_controller_pitch_P.Delay23_InitialCondition_n[2];

    // InitializeConditions for Delay: '<S25>/Delay24'
    pid_controller_pitch_DW.Delay24_DSTATE[2] =
      pid_controller_pitch_P.Delay24_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay25'
    pid_controller_pitch_DW.Delay25_DSTATE[2] =
      pid_controller_pitch_P.Delay25_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay26'
    pid_controller_pitch_DW.Delay26_DSTATE[2] =
      pid_controller_pitch_P.Delay26_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay27'
    pid_controller_pitch_DW.Delay27_DSTATE[2] =
      pid_controller_pitch_P.Delay27_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay16'
    pid_controller_pitch_DW.Delay16_DSTATE[2] =
      pid_controller_pitch_P.Delay16_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay17'
    pid_controller_pitch_DW.Delay17_DSTATE[2] =
      pid_controller_pitch_P.Delay17_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay18'
    pid_controller_pitch_DW.Delay18_DSTATE[2] =
      pid_controller_pitch_P.Delay18_InitialCondition[2];

    // InitializeConditions for Delay: '<S25>/Delay19'
    pid_controller_pitch_DW.Delay19_DSTATE[2] =
      pid_controller_pitch_P.Delay19_InitialCondition[2];

    // InitializeConditions for Memory: '<S27>/Memory4'
    for (i = 0; i < 5; i++) {
      pid_controller_pitch_DW.Memory4_PreviousInput[i] =
        pid_controller_pitch_P.x0_phth[i];
    }

    // End of InitializeConditions for Memory: '<S27>/Memory4'

    // InitializeConditions for Delay: '<S27>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_l[0] =
      pid_controller_pitch_P.Delay2_InitialCondition_j;
    pid_controller_pitch_DW.Delay2_DSTATE_l[1] =
      pid_controller_pitch_P.Delay2_InitialCondition_j;
    pid_controller_pitch_DW.Delay2_DSTATE_l[2] =
      pid_controller_pitch_P.Delay2_InitialCondition_j;

    // InitializeConditions for Memory: '<S27>/Memory2'
    pid_controller_pitch_DW.Memory2_PreviousInput =
      pid_controller_pitch_P.Memory2_InitialCondition;

    // InitializeConditions for Memory: '<S27>/Memory3'
    memcpy(&pid_controller_pitch_DW.Memory3_PreviousInput[0],
           &pid_controller_pitch_P.P0_phth[0], 25U * sizeof(real_T));

    // InitializeConditions for Memory: '<S30>/Memory4'
    pid_controller_pitch_DW.Memory4_PreviousInput_d =
      pid_controller_pitch_P.x0_ps;

    // InitializeConditions for Memory: '<S30>/Memory3'
    pid_controller_pitch_DW.Memory3_PreviousInput_g =
      pid_controller_pitch_P.P0_ps;

    // InitializeConditions for Memory: '<S30>/Memory2'
    pid_controller_pitch_DW.Memory2_PreviousInput_f =
      pid_controller_pitch_P.Memory2_InitialCondition_c;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn' 
    pid_controller_pitch_DW.DiscreteTransferFcn_states_i =
      pid_controller_pitch_P.DiscreteTransferFcn_InitialSt_d;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn1' 
    pid_controller_pitch_DW.DiscreteTransferFcn1_states_p =
      pid_controller_pitch_P.DiscreteTransferFcn1_InitialS_m;

    // InitializeConditions for DiscreteTransferFcn: '<S24>/Discrete Transfer Fcn2' 
    pid_controller_pitch_DW.DiscreteTransferFcn2_states_o =
      pid_controller_pitch_P.DiscreteTransferFcn2_InitialS_i;

    // InitializeConditions for Memory: '<S18>/Memory5'
    pid_controller_pitch_DW.Memory5_PreviousInput =
      pid_controller_pitch_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_fv[0] =
      pid_controller_pitch_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S18>/Memory6'
    pid_controller_pitch_DW.Memory6_PreviousInput[0] =
      pid_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_fv[1] =
      pid_controller_pitch_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S18>/Memory6'
    pid_controller_pitch_DW.Memory6_PreviousInput[1] =
      pid_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S30>/Delay2'
    pid_controller_pitch_DW.Delay2_DSTATE_fv[2] =
      pid_controller_pitch_P.Delay2_InitialCondition_i;

    // InitializeConditions for Memory: '<S18>/Memory6'
    pid_controller_pitch_DW.Memory6_PreviousInput[2] =
      pid_controller_pitch_P.Memory6_InitialCondition;

    // InitializeConditions for DiscreteTransferFcn: '<S9>/Discrete Transfer Fcn1' 
    pid_controller_pitch_DW.DiscreteTransferFcn1_states_e =
      pid_controller_pitch_P.DiscreteTransferFcn1_InitialS_e;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn' 
    pid_controller_pitch_DW.DiscreteTransferFcn_states_p =
      pid_controller_pitch_P.DiscreteTransferFcn_InitialSt_a;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn1' 
    pid_controller_pitch_DW.DiscreteTransferFcn1_states_l =
      pid_controller_pitch_P.DiscreteTransferFcn1_InitialS_a;

    // InitializeConditions for DiscreteTransferFcn: '<S22>/Discrete Transfer Fcn2' 
    pid_controller_pitch_DW.DiscreteTransferFcn2_states_g =
      pid_controller_pitch_P.DiscreteTransferFcn2_Initial_iv;

    // SystemInitialize for Enabled SubSystem: '<S67>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S68>/In1' incorporates:
    //   Outport: '<S68>/Out1'

    pid_controller_pitch_B.In1 = pid_controller_pitch_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S67>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S57>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    pid_controller_pitch_B.In1_k = pid_controller_pitch_P.Out1_Y0_l;

    // End of SystemInitialize for SubSystem: '<S57>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S53>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S54>/In1' incorporates:
    //   Outport: '<S54>/Out1'

    pid_controller_pitch_B.In1_dn = pid_controller_pitch_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S53>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S56>/In1' incorporates:
    //   Outport: '<S56>/Out1'

    pid_controller_pitch_B.In1_d = pid_controller_pitch_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

    // SystemInitialize for MATLAB Function: '<S19>/MATLAB Function7'
    pid_contro_MATLABFunction1_Init(&pid_controller_pitch_DW.sf_MATLABFunction7);

    // SystemInitialize for MATLAB Function: '<S4>/MATLAB Function1'
    pid_contro_MATLABFunction1_Init
      (&pid_controller_pitch_DW.sf_MATLABFunction1_m);

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S46>/In1' incorporates:
    //   Outport: '<S46>/Out1'

    pid_controller_pitch_B.In1_h = pid_controller_pitch_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S67>/SourceBlock'
    pid_controller_pitch_DW.obj_n.matlabCodegenIsDeleted = false;
    pid_controller_pitch_DW.obj_n.isInitialized = 1;
    pid_controller_pitch_DW.obj_n.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(pid_controller_pitch_DW.obj_n.orbMetadataObj,
                         &pid_controller_pitch_DW.obj_n.eventStructObj);
    pid_controller_pitch_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S57>/SourceBlock'
    pid_controller_pitch_DW.obj_g.matlabCodegenIsDeleted = false;
    pid_controller_pitch_DW.obj_g.isInitialized = 1;
    pid_controller_pitch_DW.obj_g.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(pid_controller_pitch_DW.obj_g.orbMetadataObj,
                         &pid_controller_pitch_DW.obj_g.eventStructObj);
    pid_controller_pitch_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S53>/SourceBlock'
    pid_controller_pitch_DW.obj_k.matlabCodegenIsDeleted = false;
    pid_controller_pitch_DW.obj_k.isInitialized = 1;
    pid_controller_pitch_DW.obj_k.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(pid_controller_pitch_DW.obj_k.orbMetadataObj,
                         &pid_controller_pitch_DW.obj_k.eventStructObj);
    pid_controller_pitch_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S55>/SourceBlock'
    pid_controller_pitch_DW.obj_gg.matlabCodegenIsDeleted = false;
    pid_controller_pitch_DW.obj_gg.isInitialized = 1;
    pid_controller_pitch_DW.obj_gg.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(pid_controller_pitch_DW.obj_gg.orbMetadataObj,
                         &pid_controller_pitch_DW.obj_gg.eventStructObj);
    pid_controller_pitch_DW.obj_gg.isSetupComplete = true;

    // Start for MATLABSystem: '<S5>/PX4 PWM Output' incorporates:
    //   Constant: '<S5>/failsafe'

    pid_controller_pitch_DW.obj.errorStatus = 0U;
    pid_controller_pitch_DW.obj.isInitialized = 0;
    pid_controller_pitch_DW.obj.matlabCodegenIsDeleted = false;
    pid_controller_SystemCore_setup(&pid_controller_pitch_DW.obj,
      rtb_startingswitch, pid_controller_pitch_P.failsafe_Value);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    pid_controller_pitch_DW.obj_h.matlabCodegenIsDeleted = false;
    pid_controller_pitch_DW.obj_h.isInitialized = 1;
    pid_controller_pitch_DW.obj_h.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(pid_controller_pitch_DW.obj_h.orbMetadataObj,
                         &pid_controller_pitch_DW.obj_h.eventStructObj);
    pid_controller_pitch_DW.obj_h.isSetupComplete = true;
  }
}

// Model terminate function
void pid_controller_pitch_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S67>/SourceBlock'
  if (!pid_controller_pitch_DW.obj_n.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj_n.isInitialized == 1) &&
        pid_controller_pitch_DW.obj_n.isSetupComplete) {
      uORB_read_terminate(&pid_controller_pitch_DW.obj_n.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S67>/SourceBlock'

  // Terminate for MATLABSystem: '<S57>/SourceBlock'
  if (!pid_controller_pitch_DW.obj_g.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj_g.isInitialized == 1) &&
        pid_controller_pitch_DW.obj_g.isSetupComplete) {
      uORB_read_terminate(&pid_controller_pitch_DW.obj_g.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S57>/SourceBlock'

  // Terminate for MATLABSystem: '<S53>/SourceBlock'
  if (!pid_controller_pitch_DW.obj_k.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj_k.isInitialized == 1) &&
        pid_controller_pitch_DW.obj_k.isSetupComplete) {
      uORB_read_terminate(&pid_controller_pitch_DW.obj_k.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S53>/SourceBlock'

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  if (!pid_controller_pitch_DW.obj_gg.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj_gg.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj_gg.isInitialized == 1) &&
        pid_controller_pitch_DW.obj_gg.isSetupComplete) {
      uORB_read_terminate(&pid_controller_pitch_DW.obj_gg.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S55>/SourceBlock'
  // Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  if (!pid_controller_pitch_DW.obj.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj.isInitialized == 1) &&
        pid_controller_pitch_DW.obj.isSetupComplete) {
      status = pwm_disarm(&pid_controller_pitch_DW.obj.pwmDevHandler,
                          &pid_controller_pitch_DW.obj.armAdvertiseObj);
      pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (pid_controller_pitch_DW.obj.errorStatus | status);
      status = pwm_resetServo(&pid_controller_pitch_DW.obj.pwmDevHandler,
        pid_controller_pitch_DW.obj.servoCount,
        pid_controller_pitch_DW.obj.channelMask,
        pid_controller_pitch_DW.obj.isMain,
        &pid_controller_pitch_DW.obj.actuatorAdvertiseObj);
      pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (pid_controller_pitch_DW.obj.errorStatus | status);
      status = pwm_close(&pid_controller_pitch_DW.obj.pwmDevHandler,
                         &pid_controller_pitch_DW.obj.actuatorAdvertiseObj,
                         &pid_controller_pitch_DW.obj.armAdvertiseObj);
      pid_controller_pitch_DW.obj.errorStatus = static_cast<uint16_T>
        (pid_controller_pitch_DW.obj.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S5>/PX4 PWM Output'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!pid_controller_pitch_DW.obj_h.matlabCodegenIsDeleted) {
    pid_controller_pitch_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((pid_controller_pitch_DW.obj_h.isInitialized == 1) &&
        pid_controller_pitch_DW.obj_h.isSetupComplete) {
      uORB_read_terminate(&pid_controller_pitch_DW.obj_h.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
