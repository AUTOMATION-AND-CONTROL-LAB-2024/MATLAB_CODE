//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_3dof.cpp
//
// Code generated for Simulink model 'controller_3dof'.
//
// Model version                  : 1.70
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr 16 17:37:26 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_3dof.h"
#include <uORB/topics/actuator_outputs.h>
#include "controller_3dof_types.h"
#include "rtwtypes.h"
#include "controller_3dof_private.h"
#include <math.h>
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Block signals (default storage)
B_controller_3dof_T controller_3dof_B;

// Block states (default storage)
DW_controller_3dof_T controller_3dof_DW;

// Real-time model
RT_MODEL_controller_3dof_T controller_3dof_M_ = RT_MODEL_controller_3dof_T();
RT_MODEL_controller_3dof_T *const controller_3dof_M = &controller_3dof_M_;

// Forward declaration for local functions
static real_T controller_3dof_minimum(const real_T x[4]);
static void controller_3do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);

// System initialize for atomic system:
void controller_3do_SourceBlock_Init(DW_SourceBlock_controller_3do_T *localDW)
{
  // Start for MATLABSystem: '<S27>/SourceBlock'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.orbMetadataObj = ORB_ID(actuator_outputs);
  uORB_read_initialize(localDW->obj.orbMetadataObj, &localDW->obj.eventStructObj);
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void controller_3dof_SourceBlock(B_SourceBlock_controller_3dof_T *localB,
  DW_SourceBlock_controller_3do_T *localDW)
{
  // MATLABSystem: '<S27>/SourceBlock'
  localB->SourceBlock_o1 = uORB_read_step(localDW->obj.orbMetadataObj,
    &localDW->obj.eventStructObj, &localB->SourceBlock_o2, false, 1.0);
}

// Termination for atomic system:
void controller_3do_SourceBlock_Term(DW_SourceBlock_controller_3do_T *localDW)
{
  // Terminate for MATLABSystem: '<S27>/SourceBlock'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uORB_read_terminate(&localDW->obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S27>/SourceBlock'
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

// Function for MATLAB Function: '<Root>/allocation_logic'
static real_T controller_3dof_minimum(const real_T x[4])
{
  real_T ex;
  int32_T idx;
  int32_T k;
  if (!rtIsNaN(x[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 5)) {
      if (!rtIsNaN(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    for (k = idx + 1; k < 5; k++) {
      controller_3dof_B.x = x[k - 1];
      if (ex > controller_3dof_B.x) {
        ex = controller_3dof_B.x;
      }
    }
  }

  return ex;
}

static void controller_3do_SystemCore_setup(px4_internal_block_PWM_contro_T *obj,
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
void controller_3dof_step(void)
{
  int32_T Lk_tmp;
  int32_T Lk_tmp_0;
  real32_T rtb_Product2_n_tmp;
  real32_T rtb_Product2_o_tmp;
  real32_T rtb_Product3_o_tmp;
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion1_c;
  uint16_T rtb_DataTypeConversion1_e;
  uint16_T rtb_DataTypeConversion1_o;
  boolean_T rtb_ManualSwitch;
  static const int8_T b[6] = { 0, 0, 0, 1, 0, 0 };

  static const int8_T c[6] = { 0, 0, 0, 0, 1, 0 };

  static const int8_T d[6] = { 0, 0, 0, 0, 0, 1 };

  static const int8_T e[18] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 0 };

  static const int8_T b_b[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0 };

  real32_T RPY_tmp;
  real32_T RPY_tmp_tmp;
  real32_T RPY_tmp_tmp_0;
  real32_T RPY_tmp_tmp_1;
  real32_T RPY_tmp_tmp_2;
  real32_T rtb_fcn3_tmp;

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_fn);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_n);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem_SubsysRanBC_g);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem1_SubsysRanB_m);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem2_SubsysRanB_c);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem1_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.IfActionSubsystem2_SubsysRanBC);

  // Reset subsysRan breadcrumbs
  srClearBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<S3>/Discrete Time' incorporates:
  //   DigitalClock: '<Root>/Digital Clock'

  controller_3dof_B.DigitalClock = controller_3dof_M->Timing.taskTime0;

  // MATLABSystem: '<S18>/SourceBlock'
  rtb_ManualSwitch = uORB_read_step(controller_3dof_DW.obj_a.orbMetadataObj,
    &controller_3dof_DW.obj_a.eventStructObj, &controller_3dof_B.b_varargout_2_k,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S19>/Enable'

  if (rtb_ManualSwitch) {
    // SignalConversion generated from: '<S19>/In1'
    controller_3dof_B.In1_lx = controller_3dof_B.b_varargout_2_k;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S18>/SourceBlock'
  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  controller_3dof_B.z = controller_3dof_B.In1_lx.z;

  // SignalConversion generated from: '<S1>/Bus Selector'
  controller_3dof_B.y = controller_3dof_B.In1_lx.y;
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
       controller_3dof_B.rtemp++) {
    // Gain: '<S5>/Gain' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion4'

    controller_3dof_B.Gain[controller_3dof_B.rtemp] =
      (controller_3dof_P.Gain_Gain[controller_3dof_B.rtemp + 3] *
       controller_3dof_B.y + controller_3dof_P.Gain_Gain[controller_3dof_B.rtemp]
       * controller_3dof_B.In1_lx.x) +
      controller_3dof_P.Gain_Gain[controller_3dof_B.rtemp + 6] *
      controller_3dof_B.z;
  }

  // MATLABSystem: '<S24>/SourceBlock'
  rtb_ManualSwitch = uORB_read_step(controller_3dof_DW.obj_d.orbMetadataObj,
    &controller_3dof_DW.obj_d.eventStructObj, &controller_3dof_B.b_varargout_2_b,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S24>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  if (rtb_ManualSwitch) {
    // SignalConversion generated from: '<S25>/In1'
    controller_3dof_B.In1_o = controller_3dof_B.b_varargout_2_b;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_n);
  }

  // End of MATLABSystem: '<S24>/SourceBlock'
  // End of Outputs for SubSystem: '<S24>/Enabled Subsystem'
  for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 3; controller_3dof_B.r1
       ++) {
    // Gain: '<S5>/Gain2' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion2'

    controller_3dof_B.Gain2[controller_3dof_B.r1] =
      (controller_3dof_P.Rbody_ned[controller_3dof_B.r1 + 3] *
       controller_3dof_B.In1_o.y +
       controller_3dof_P.Rbody_ned[controller_3dof_B.r1] *
       controller_3dof_B.In1_o.x) +
      controller_3dof_P.Rbody_ned[controller_3dof_B.r1 + 6] *
      controller_3dof_B.In1_o.z;

    // MATLAB Function: '<Root>/RPY_computation'
    controller_3dof_B.RPY_meas[controller_3dof_B.r1] =
      -controller_3dof_B.Gain[controller_3dof_B.r1];
  }

  // MATLAB Function: '<Root>/RPY_computation'
  controller_3dof_B.y1_k = rt_atan2d_snf(controller_3dof_B.RPY_meas[1],
    controller_3dof_B.RPY_meas[2]);
  controller_3dof_B.sph = sin(controller_3dof_B.y1_k);
  controller_3dof_B.cph = cos(controller_3dof_B.y1_k);
  controller_3dof_B.y2_n = rt_atan2d_snf(-controller_3dof_B.RPY_meas[0],
    controller_3dof_B.RPY_meas[1] * controller_3dof_B.sph +
    controller_3dof_B.RPY_meas[2] * controller_3dof_B.cph);
  controller_3dof_B.sth = sin(controller_3dof_B.y2_n);
  controller_3dof_B.sth = (controller_3dof_B.Gain2[1] * controller_3dof_B.sth *
    controller_3dof_B.cph + controller_3dof_B.Gain2[0] * cos
    (controller_3dof_B.y2_n)) + controller_3dof_B.Gain2[2] *
    controller_3dof_B.sth * controller_3dof_B.cph;
  if (fabs(controller_3dof_B.sth) > 0.1) {
    controller_3dof_B.y3_h = rt_atan2d_snf(controller_3dof_B.Gain2[2] *
      controller_3dof_B.sph - controller_3dof_B.Gain2[1] * controller_3dof_B.cph,
      controller_3dof_B.sth);
    controller_3dof_B.method_ps = 1.0;
  } else {
    if (controller_3dof_B.Gain2[2] * controller_3dof_B.sph -
        controller_3dof_B.Gain2[1] * controller_3dof_B.cph > 0.0) {
      controller_3dof_B.y3_h = 1.5707963267948966;
    } else {
      controller_3dof_B.y3_h = -1.5707963267948966;
    }

    controller_3dof_B.method_ps = 2.0;
  }

  controller_3dof_B.RPY_meas[0] = controller_3dof_B.y1_k;
  controller_3dof_B.RPY_meas[1] = controller_3dof_B.y2_n;
  controller_3dof_B.RPY_meas[2] = controller_3dof_B.y3_h;

  // MATLAB Function: '<S3>/EKF' incorporates:
  //   Constant: '<S3>/Constant'
  //   Constant: '<S3>/Constant1'
  //   Constant: '<S3>/Constant2'
  //   Constant: '<S3>/Constant3'
  //   Constant: '<S3>/Constant4'
  //   Constant: '<S3>/Constant5'
  //   Delay: '<S3>/Delay2'
  //   DigitalClock: '<S3>/Discrete Time'
  //   Memory: '<S3>/Memory'
  //   Memory: '<S3>/Memory1'
  //   Memory: '<S3>/Memory2'
  //   Memory: '<S3>/Memory3'
  //   Memory: '<S3>/Memory4'

  controller_3dof_B.t_integr1 = controller_3dof_DW.Memory1_PreviousInput;
  controller_3dof_B.t_meas1_d = controller_3dof_DW.Memory_PreviousInput;
  if (controller_3dof_B.DigitalClock == 0.0) {
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.xk[controller_3dof_B.rtemp] =
        controller_3dof_P.x0EKF[controller_3dof_B.rtemp];
      controller_3dof_B.xt[controller_3dof_B.rtemp] =
        controller_3dof_P.x0EKF[controller_3dof_B.rtemp];
    }

    memcpy(&controller_3dof_B.Pt[0], &controller_3dof_P.P0[0], 36U * sizeof
           (real_T));
    controller_3dof_B.t_integr1 = 0.0;
    controller_3dof_B.t_meas1_d = 0.0;
  } else if (controller_3dof_B.DigitalClock - controller_3dof_B.t_integr1 >=
             controller_3dof_P.Ts_EKF_integr) {
    controller_3dof_B.cph = cos(controller_3dof_DW.Memory3_PreviousInput[0]);
    controller_3dof_B.cth = cos(controller_3dof_DW.Memory3_PreviousInput[1]);
    controller_3dof_B.sph = sin(controller_3dof_DW.Memory3_PreviousInput[0]);
    controller_3dof_B.sth = sin(controller_3dof_DW.Memory3_PreviousInput[1]);
    controller_3dof_B.tth = controller_3dof_B.sth / controller_3dof_B.cth;
    controller_3dof_B.t_integr1 = controller_3dof_B.DigitalClock;
    controller_3dof_B.At1_c[0] = 1.0;
    controller_3dof_B.At1_tmp = controller_3dof_B.sph * controller_3dof_B.tth;
    controller_3dof_B.At1_c[6] = controller_3dof_B.At1_tmp;
    controller_3dof_B.At1_tmp_f = controller_3dof_B.cph * controller_3dof_B.tth;
    controller_3dof_B.At1_c[12] = controller_3dof_B.At1_tmp_f;
    controller_3dof_B.At1_c[18] = 0.0;
    controller_3dof_B.At1_c[24] = 0.0;
    controller_3dof_B.At1_c[30] = 0.0;
    controller_3dof_B.At1_c[1] = 0.0;
    controller_3dof_B.At1_c[7] = controller_3dof_B.cph;
    controller_3dof_B.At1_c[13] = -controller_3dof_B.sph;
    controller_3dof_B.At1_c[19] = 0.0;
    controller_3dof_B.At1_c[25] = 0.0;
    controller_3dof_B.At1_c[31] = 0.0;
    controller_3dof_B.At1_c[2] = 0.0;
    controller_3dof_B.At1_c[8] = controller_3dof_B.sph / controller_3dof_B.cth;
    controller_3dof_B.At1_c[14] = controller_3dof_B.cph / controller_3dof_B.cth;
    controller_3dof_B.At1_c[20] = 0.0;
    controller_3dof_B.At1_c[26] = 0.0;
    controller_3dof_B.At1_c[32] = 0.0;
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.r1 = b[controller_3dof_B.rtemp];
      controller_3dof_B.xt_tmp[controller_3dof_B.rtemp] = controller_3dof_B.r1;
      controller_3dof_B.r2 = c[controller_3dof_B.rtemp];
      controller_3dof_B.xt_tmp_g[controller_3dof_B.rtemp] = static_cast<int8_T>
        (controller_3dof_B.r2);
      controller_3dof_B.r3 = d[controller_3dof_B.rtemp];
      controller_3dof_B.xt_tmp_m[controller_3dof_B.rtemp] = static_cast<int8_T>
        (controller_3dof_B.r3);
      controller_3dof_B.At1_c[6 * controller_3dof_B.rtemp + 3] =
        controller_3dof_B.r1;
      controller_3dof_B.At1_c[6 * controller_3dof_B.rtemp + 4] =
        controller_3dof_B.r2;
      controller_3dof_B.At1_c[6 * controller_3dof_B.rtemp + 5] =
        controller_3dof_B.r3;
    }

    controller_3dof_B.dv[0] = controller_3dof_DW.Delay2_DSTATE[0] -
      controller_3dof_DW.Memory3_PreviousInput[3];
    controller_3dof_B.d = controller_3dof_DW.Delay2_DSTATE[1] -
      controller_3dof_DW.Memory3_PreviousInput[4];
    controller_3dof_B.dv[1] = controller_3dof_B.d;
    controller_3dof_B.d1 = controller_3dof_DW.Delay2_DSTATE[2] -
      controller_3dof_DW.Memory3_PreviousInput[5];
    controller_3dof_B.dv[2] = controller_3dof_B.d1;
    controller_3dof_B.dv[3] = controller_3dof_DW.Memory3_PreviousInput[3];
    controller_3dof_B.dv[4] = controller_3dof_DW.Memory3_PreviousInput[4];
    controller_3dof_B.dv[5] = controller_3dof_DW.Memory3_PreviousInput[5];
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.At1_tmp_g = 0.0;
      for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
           controller_3dof_B.r1++) {
        controller_3dof_B.At1_tmp_g += controller_3dof_B.At1_c[6 *
          controller_3dof_B.r1 + controller_3dof_B.rtemp] *
          controller_3dof_B.dv[controller_3dof_B.r1];
      }

      controller_3dof_B.xt[controller_3dof_B.rtemp] =
        controller_3dof_P.Ts_EKF_integr * controller_3dof_B.At1_tmp_g +
        controller_3dof_DW.Memory3_PreviousInput[controller_3dof_B.rtemp];
    }

    controller_3dof_B.At1[0] = controller_3dof_B.At1_tmp_f * controller_3dof_B.d
      - controller_3dof_B.At1_tmp * controller_3dof_B.d1;
    controller_3dof_B.At1_tmp = controller_3dof_B.cth * controller_3dof_B.cth;
    controller_3dof_B.At1_tmp_f = controller_3dof_B.d1 * controller_3dof_B.cph;
    controller_3dof_B.At1_tmp_g = controller_3dof_B.d * controller_3dof_B.sph +
      controller_3dof_B.At1_tmp_f;
    controller_3dof_B.At1[6] = controller_3dof_B.At1_tmp_g /
      controller_3dof_B.At1_tmp;
    controller_3dof_B.At1[12] = 0.0;
    controller_3dof_B.At1[18] = -1.0;
    controller_3dof_B.At1[24] = -controller_3dof_B.sph * controller_3dof_B.tth;
    controller_3dof_B.At1[30] = -controller_3dof_B.cph * controller_3dof_B.tth;
    controller_3dof_B.At1[1] = controller_3dof_B.d * -controller_3dof_B.sph -
      controller_3dof_B.At1_tmp_f;
    controller_3dof_B.At1[7] = 0.0;
    controller_3dof_B.At1[13] = 0.0;
    controller_3dof_B.At1[19] = 0.0;
    controller_3dof_B.At1[25] = -controller_3dof_B.cph;
    controller_3dof_B.At1[31] = controller_3dof_B.sph;
    controller_3dof_B.At1[2] = controller_3dof_B.d * controller_3dof_B.cph /
      controller_3dof_B.cth - controller_3dof_B.d1 * controller_3dof_B.sph /
      controller_3dof_B.cth;
    controller_3dof_B.At1[8] = controller_3dof_B.sth / controller_3dof_B.At1_tmp
      * controller_3dof_B.At1_tmp_g;
    controller_3dof_B.At1[14] = 0.0;
    controller_3dof_B.At1[20] = 0.0;
    controller_3dof_B.At1[26] = -controller_3dof_B.sph / controller_3dof_B.cth;
    controller_3dof_B.At1[32] = -controller_3dof_B.cph / controller_3dof_B.cth;
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.At1[6 * controller_3dof_B.rtemp + 3] =
        controller_3dof_B.xt_tmp[controller_3dof_B.rtemp];
      controller_3dof_B.At1[6 * controller_3dof_B.rtemp + 4] =
        controller_3dof_B.xt_tmp_g[controller_3dof_B.rtemp];
      controller_3dof_B.At1[6 * controller_3dof_B.rtemp + 5] =
        controller_3dof_B.xt_tmp_m[controller_3dof_B.rtemp];
    }

    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
           controller_3dof_B.r1++) {
        controller_3dof_B.sph = 0.0;
        controller_3dof_B.At1_tmp = 0.0;
        for (controller_3dof_B.r2 = 0; controller_3dof_B.r2 < 6;
             controller_3dof_B.r2++) {
          controller_3dof_B.r3 = 6 * controller_3dof_B.r2 +
            controller_3dof_B.rtemp;
          controller_3dof_B.sph += controller_3dof_DW.Memory2_PreviousInput[6 *
            controller_3dof_B.r1 + controller_3dof_B.r2] *
            controller_3dof_B.At1[controller_3dof_B.r3];
          controller_3dof_B.At1_tmp += controller_3dof_B.At1[6 *
            controller_3dof_B.r2 + controller_3dof_B.r1] *
            controller_3dof_DW.Memory2_PreviousInput[controller_3dof_B.r3];
        }

        controller_3dof_B.r2 = 6 * controller_3dof_B.r1 +
          controller_3dof_B.rtemp;
        controller_3dof_B.At1_c[controller_3dof_B.r2] =
          controller_3dof_B.At1_tmp;
        controller_3dof_B.At1_m[controller_3dof_B.r2] = controller_3dof_B.sph;
      }
    }

    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 36;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.Pt[controller_3dof_B.rtemp] =
        ((controller_3dof_B.At1_m[controller_3dof_B.rtemp] +
          controller_3dof_B.At1_c[controller_3dof_B.rtemp]) +
         controller_3dof_P.Q[controller_3dof_B.rtemp]) *
        controller_3dof_P.Ts_EKF_integr +
        controller_3dof_DW.Memory2_PreviousInput[controller_3dof_B.rtemp];
    }

    if (controller_3dof_B.DigitalClock - controller_3dof_B.t_meas1_d >=
        controller_3dof_P.Ts_EKF_meas) {
      controller_3dof_B.t_meas1_d = controller_3dof_B.DigitalClock;
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 18;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.Lk[controller_3dof_B.rtemp] =
          e[controller_3dof_B.rtemp];
      }

      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
           controller_3dof_B.rtemp++) {
        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
             controller_3dof_B.r1++) {
          controller_3dof_B.sph = 0.0;
          for (controller_3dof_B.r2 = 0; controller_3dof_B.r2 < 6;
               controller_3dof_B.r2++) {
            controller_3dof_B.sph += controller_3dof_B.Pt[6 *
              controller_3dof_B.r2 + controller_3dof_B.r1] *
              controller_3dof_B.Lk[6 * controller_3dof_B.rtemp +
              controller_3dof_B.r2];
          }

          controller_3dof_B.B[controller_3dof_B.r1 + 6 * controller_3dof_B.rtemp]
            = controller_3dof_B.sph;
        }
      }

      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 18;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.A_tmp_c[controller_3dof_B.rtemp] =
          b_b[controller_3dof_B.rtemp];
      }

      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
           controller_3dof_B.rtemp++) {
        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
             controller_3dof_B.r1++) {
          controller_3dof_B.sph = 0.0;
          for (controller_3dof_B.r2 = 0; controller_3dof_B.r2 < 6;
               controller_3dof_B.r2++) {
            controller_3dof_B.sph += static_cast<real_T>
              (controller_3dof_B.A_tmp_c[3 * controller_3dof_B.r2 +
               controller_3dof_B.rtemp]) * controller_3dof_B.Pt[6 *
              controller_3dof_B.r1 + controller_3dof_B.r2];
          }

          controller_3dof_B.A_tmp[controller_3dof_B.rtemp + 3 *
            controller_3dof_B.r1] = controller_3dof_B.sph;
        }

        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 3;
             controller_3dof_B.r1++) {
          controller_3dof_B.At1_tmp = 0.0;
          for (controller_3dof_B.r2 = 0; controller_3dof_B.r2 < 6;
               controller_3dof_B.r2++) {
            controller_3dof_B.At1_tmp += controller_3dof_B.A_tmp[3 *
              controller_3dof_B.r2 + controller_3dof_B.rtemp] *
              controller_3dof_B.Lk[6 * controller_3dof_B.r1 +
              controller_3dof_B.r2];
          }

          controller_3dof_B.r2 = 3 * controller_3dof_B.r1 +
            controller_3dof_B.rtemp;
          controller_3dof_B.A[controller_3dof_B.r2] =
            controller_3dof_P.R[controller_3dof_B.r2] +
            controller_3dof_B.At1_tmp;
        }
      }

      controller_3dof_B.r1 = 0;
      controller_3dof_B.r2 = 1;
      controller_3dof_B.r3 = 2;
      controller_3dof_B.sph = fabs(controller_3dof_B.A[0]);
      controller_3dof_B.cph = fabs(controller_3dof_B.A[1]);
      if (controller_3dof_B.cph > controller_3dof_B.sph) {
        controller_3dof_B.sph = controller_3dof_B.cph;
        controller_3dof_B.r1 = 1;
        controller_3dof_B.r2 = 0;
      }

      if (fabs(controller_3dof_B.A[2]) > controller_3dof_B.sph) {
        controller_3dof_B.r1 = 2;
        controller_3dof_B.r2 = 1;
        controller_3dof_B.r3 = 0;
      }

      controller_3dof_B.A[controller_3dof_B.r2] /=
        controller_3dof_B.A[controller_3dof_B.r1];
      controller_3dof_B.A[controller_3dof_B.r3] /=
        controller_3dof_B.A[controller_3dof_B.r1];
      controller_3dof_B.A[controller_3dof_B.r2 + 3] -=
        controller_3dof_B.A[controller_3dof_B.r1 + 3] *
        controller_3dof_B.A[controller_3dof_B.r2];
      controller_3dof_B.A[controller_3dof_B.r3 + 3] -=
        controller_3dof_B.A[controller_3dof_B.r1 + 3] *
        controller_3dof_B.A[controller_3dof_B.r3];
      controller_3dof_B.A[controller_3dof_B.r2 + 6] -=
        controller_3dof_B.A[controller_3dof_B.r1 + 6] *
        controller_3dof_B.A[controller_3dof_B.r2];
      controller_3dof_B.A[controller_3dof_B.r3 + 6] -=
        controller_3dof_B.A[controller_3dof_B.r1 + 6] *
        controller_3dof_B.A[controller_3dof_B.r3];
      if (fabs(controller_3dof_B.A[controller_3dof_B.r3 + 3]) > fabs
          (controller_3dof_B.A[controller_3dof_B.r2 + 3])) {
        controller_3dof_B.rtemp = controller_3dof_B.r2;
        controller_3dof_B.r2 = controller_3dof_B.r3;
        controller_3dof_B.r3 = controller_3dof_B.rtemp;
      }

      controller_3dof_B.A[controller_3dof_B.r3 + 3] /=
        controller_3dof_B.A[controller_3dof_B.r2 + 3];
      controller_3dof_B.A[controller_3dof_B.r3 + 6] -=
        controller_3dof_B.A[controller_3dof_B.r3 + 3] *
        controller_3dof_B.A[controller_3dof_B.r2 + 6];
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.Lk_tmp = 6 * controller_3dof_B.r1 +
          controller_3dof_B.rtemp;
        controller_3dof_B.Lk[controller_3dof_B.Lk_tmp] =
          controller_3dof_B.B[controller_3dof_B.rtemp] /
          controller_3dof_B.A[controller_3dof_B.r1];
        Lk_tmp = 6 * controller_3dof_B.r2 + controller_3dof_B.rtemp;
        controller_3dof_B.Lk[Lk_tmp] =
          controller_3dof_B.B[controller_3dof_B.rtemp + 6] -
          controller_3dof_B.A[controller_3dof_B.r1 + 3] *
          controller_3dof_B.Lk[controller_3dof_B.Lk_tmp];
        Lk_tmp_0 = 6 * controller_3dof_B.r3 + controller_3dof_B.rtemp;
        controller_3dof_B.Lk[Lk_tmp_0] =
          controller_3dof_B.B[controller_3dof_B.rtemp + 12] -
          controller_3dof_B.A[controller_3dof_B.r1 + 6] *
          controller_3dof_B.Lk[controller_3dof_B.Lk_tmp];
        controller_3dof_B.Lk[Lk_tmp] /= controller_3dof_B.A[controller_3dof_B.r2
          + 3];
        controller_3dof_B.Lk[Lk_tmp_0] -=
          controller_3dof_B.A[controller_3dof_B.r2 + 6] *
          controller_3dof_B.Lk[Lk_tmp];
        controller_3dof_B.Lk[Lk_tmp_0] /=
          controller_3dof_B.A[controller_3dof_B.r3 + 6];
        controller_3dof_B.Lk[Lk_tmp] -= controller_3dof_B.A[controller_3dof_B.r3
          + 3] * controller_3dof_B.Lk[Lk_tmp_0];
        controller_3dof_B.Lk[controller_3dof_B.Lk_tmp] -=
          controller_3dof_B.Lk[Lk_tmp_0] *
          controller_3dof_B.A[controller_3dof_B.r3];
        controller_3dof_B.Lk[controller_3dof_B.Lk_tmp] -=
          controller_3dof_B.Lk[Lk_tmp] *
          controller_3dof_B.A[controller_3dof_B.r2];
      }

      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.At1_tmp = 0.0;
        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
             controller_3dof_B.r1++) {
          controller_3dof_B.At1_tmp += static_cast<real_T>
            (controller_3dof_B.A_tmp_c[3 * controller_3dof_B.r1 +
             controller_3dof_B.rtemp]) *
            controller_3dof_B.xt[controller_3dof_B.r1];
        }

        controller_3dof_B.RPY_meas_p[controller_3dof_B.rtemp] =
          controller_3dof_B.RPY_meas[controller_3dof_B.rtemp] -
          controller_3dof_B.At1_tmp;
      }

      controller_3dof_B.sph = controller_3dof_B.RPY_meas_p[1];
      controller_3dof_B.cph = controller_3dof_B.RPY_meas_p[0];
      controller_3dof_B.sth = controller_3dof_B.RPY_meas_p[2];
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.xk[controller_3dof_B.rtemp] =
          ((controller_3dof_B.Lk[controller_3dof_B.rtemp + 6] *
            controller_3dof_B.sph + controller_3dof_B.Lk[controller_3dof_B.rtemp]
            * controller_3dof_B.cph) +
           controller_3dof_B.Lk[controller_3dof_B.rtemp + 12] *
           controller_3dof_B.sth) + controller_3dof_B.xt[controller_3dof_B.rtemp];
      }

      memset(&controller_3dof_B.At1[0], 0, 36U * sizeof(real_T));
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.At1[controller_3dof_B.rtemp + 6 *
          controller_3dof_B.rtemp] = 1.0;
      }

      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.sph = controller_3dof_B.Lk[controller_3dof_B.rtemp + 6];
        controller_3dof_B.cph = controller_3dof_B.Lk[controller_3dof_B.rtemp];
        controller_3dof_B.sth = controller_3dof_B.Lk[controller_3dof_B.rtemp +
          12];
        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
             controller_3dof_B.r1++) {
          controller_3dof_B.r3 = 6 * controller_3dof_B.r1 +
            controller_3dof_B.rtemp;
          controller_3dof_B.At1_m[controller_3dof_B.r3] =
            controller_3dof_B.At1[controller_3dof_B.r3] - ((static_cast<real_T>
            (controller_3dof_B.A_tmp_c[3 * controller_3dof_B.r1 + 1]) *
            controller_3dof_B.sph + static_cast<real_T>
            (controller_3dof_B.A_tmp_c[3 * controller_3dof_B.r1]) *
            controller_3dof_B.cph) + static_cast<real_T>
            (controller_3dof_B.A_tmp_c[3 * controller_3dof_B.r1 + 2]) *
            controller_3dof_B.sth);
        }

        for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
             controller_3dof_B.r1++) {
          controller_3dof_B.sph = 0.0;
          for (controller_3dof_B.r2 = 0; controller_3dof_B.r2 < 6;
               controller_3dof_B.r2++) {
            controller_3dof_B.sph += controller_3dof_B.At1_m[6 *
              controller_3dof_B.r2 + controller_3dof_B.rtemp] *
              controller_3dof_B.Pt[6 * controller_3dof_B.r1 +
              controller_3dof_B.r2];
          }

          controller_3dof_B.At1_c[controller_3dof_B.rtemp + 6 *
            controller_3dof_B.r1] = controller_3dof_B.sph;
        }
      }

      memcpy(&controller_3dof_B.Pt[0], &controller_3dof_B.At1_c[0], 36U * sizeof
             (real_T));
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.xt[controller_3dof_B.rtemp] =
          controller_3dof_B.xk[controller_3dof_B.rtemp];
      }
    } else {
      for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
           controller_3dof_B.rtemp++) {
        controller_3dof_B.xk[controller_3dof_B.rtemp] =
          controller_3dof_DW.Memory4_PreviousInput[controller_3dof_B.rtemp];
      }
    }
  } else {
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 6;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.xk[controller_3dof_B.rtemp] =
        controller_3dof_DW.Memory3_PreviousInput[controller_3dof_B.rtemp];
      controller_3dof_B.xt[controller_3dof_B.rtemp] =
        controller_3dof_DW.Memory3_PreviousInput[controller_3dof_B.rtemp];
    }

    memcpy(&controller_3dof_B.Pt[0], &controller_3dof_DW.Memory2_PreviousInput[0],
           36U * sizeof(real_T));
  }

  // End of MATLAB Function: '<S3>/EKF'

  // MATLABSystem: '<S52>/SourceBlock'
  rtb_ManualSwitch = uORB_read_step(controller_3dof_DW.obj.orbMetadataObj,
    &controller_3dof_DW.obj.eventStructObj, &controller_3dof_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S52>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S53>/Enable'

  if (rtb_ManualSwitch) {
    // SignalConversion generated from: '<S53>/In1'
    controller_3dof_B.In1 = controller_3dof_B.b_varargout_2;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S52>/SourceBlock'
  // End of Outputs for SubSystem: '<S52>/Enabled Subsystem'
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
       controller_3dof_B.rtemp++) {
    // Gain: '<Root>/Gain' incorporates:
    //   SignalConversion generated from: '<Root>/Gain'

    controller_3dof_B.Gain_i[controller_3dof_B.rtemp] =
      (controller_3dof_P.Gain_Gain_e[controller_3dof_B.rtemp + 3] *
       controller_3dof_B.In1.pitchspeed +
       controller_3dof_P.Gain_Gain_e[controller_3dof_B.rtemp] *
       controller_3dof_B.In1.rollspeed) +
      controller_3dof_P.Gain_Gain_e[controller_3dof_B.rtemp + 6] *
      controller_3dof_B.In1.yawspeed;
  }

  // Sqrt: '<S42>/sqrt' incorporates:
  //   Product: '<S43>/Product'
  //   Product: '<S43>/Product1'
  //   Product: '<S43>/Product2'
  //   Product: '<S43>/Product3'
  //   Sqrt: '<S50>/sqrt'
  //   Sum: '<S43>/Sum'

  controller_3dof_B.rtb_Product3_l_tmp = static_cast<real32_T>(sqrt(static_cast<
    real_T>(((controller_3dof_B.In1.q[0] * controller_3dof_B.In1.q[0] +
              controller_3dof_B.In1.q[1] * controller_3dof_B.In1.q[1]) +
             controller_3dof_B.In1.q[2] * controller_3dof_B.In1.q[2]) +
            controller_3dof_B.In1.q[3] * controller_3dof_B.In1.q[3])));

  // Product: '<S37>/Product' incorporates:
  //   Product: '<S45>/Product'
  //   Sqrt: '<S42>/sqrt'

  rtb_Product2_n_tmp = controller_3dof_B.In1.q[0] /
    controller_3dof_B.rtb_Product3_l_tmp;

  // Product: '<S37>/Product1' incorporates:
  //   Product: '<S45>/Product1'
  //   Sqrt: '<S42>/sqrt'

  rtb_Product3_o_tmp = controller_3dof_B.In1.q[1] /
    controller_3dof_B.rtb_Product3_l_tmp;

  // Product: '<S37>/Product2' incorporates:
  //   Product: '<S45>/Product2'
  //   Sqrt: '<S42>/sqrt'

  rtb_Product2_o_tmp = controller_3dof_B.In1.q[2] /
    controller_3dof_B.rtb_Product3_l_tmp;

  // Product: '<S37>/Product3' incorporates:
  //   Product: '<S45>/Product3'
  //   Sqrt: '<S42>/sqrt'

  controller_3dof_B.rtb_Product3_l_tmp = controller_3dof_B.In1.q[3] /
    controller_3dof_B.rtb_Product3_l_tmp;

  // Fcn: '<S12>/fcn3' incorporates:
  //   Fcn: '<S13>/fcn3'
  //   Product: '<S37>/Product'
  //   Product: '<S37>/Product1'
  //   Product: '<S37>/Product2'
  //   Product: '<S37>/Product3'

  rtb_fcn3_tmp = (rtb_Product3_o_tmp * controller_3dof_B.rtb_Product3_l_tmp -
                  rtb_Product2_n_tmp * rtb_Product2_o_tmp) * -2.0F;
  controller_3dof_B.fcn3 = rtb_fcn3_tmp;

  // If: '<S38>/If' incorporates:
  //   Constant: '<S39>/Constant'
  //   Constant: '<S40>/Constant'
  //   Fcn: '<S12>/fcn3'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S38>/If Action Subsystem' incorporates:
    //   ActionPort: '<S39>/Action Port'

    controller_3dof_B.fcn3 = controller_3dof_P.Constant_Value_ck;

    // End of Outputs for SubSystem: '<S38>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S38>/If Action Subsystem' incorporates:
    //   ActionPort: '<S39>/Action Port'

    // Update for If: '<S38>/If' incorporates:
    //   Constant: '<S39>/Constant'

    srUpdateBC(controller_3dof_DW.IfActionSubsystem_SubsysRanBC_g);

    // End of Update for SubSystem: '<S38>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S38>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S40>/Action Port'

    controller_3dof_B.fcn3 = controller_3dof_P.Constant_Value_aa;

    // End of Outputs for SubSystem: '<S38>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S38>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S40>/Action Port'

    // Update for If: '<S38>/If' incorporates:
    //   Constant: '<S40>/Constant'

    srUpdateBC(controller_3dof_DW.IfActionSubsystem1_SubsysRanB_m);

    // End of Update for SubSystem: '<S38>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S38>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S41>/Action Port'

    // Update for If: '<S38>/If'
    srUpdateBC(controller_3dof_DW.IfActionSubsystem2_SubsysRanB_c);

    // End of Update for SubSystem: '<S38>/If Action Subsystem2'
  }

  // End of If: '<S38>/If'

  // Fcn: '<S12>/fcn5' incorporates:
  //   Fcn: '<S13>/fcn2'
  //   ManualSwitch: '<Root>/Manual Switch1'
  //   Product: '<S37>/Product'
  //   Product: '<S37>/Product1'
  //   Product: '<S37>/Product2'
  //   Product: '<S37>/Product3'

  RPY_tmp_tmp = rtb_Product2_n_tmp * rtb_Product2_n_tmp;
  RPY_tmp_tmp_0 = rtb_Product3_o_tmp * rtb_Product3_o_tmp;
  RPY_tmp_tmp_1 = rtb_Product2_o_tmp * rtb_Product2_o_tmp;
  RPY_tmp_tmp_2 = controller_3dof_B.rtb_Product3_l_tmp *
    controller_3dof_B.rtb_Product3_l_tmp;

  // Fcn: '<S12>/fcn4' incorporates:
  //   Fcn: '<S13>/fcn4'
  //   ManualSwitch: '<Root>/Manual Switch1'
  //   Product: '<S37>/Product'
  //   Product: '<S37>/Product1'
  //   Product: '<S37>/Product2'
  //   Product: '<S37>/Product3'

  RPY_tmp = (rtb_Product2_o_tmp * controller_3dof_B.rtb_Product3_l_tmp +
             rtb_Product2_n_tmp * rtb_Product3_o_tmp) * 2.0F;

  // MATLAB Function: '<Root>/reverse RPY' incorporates:
  //   Fcn: '<S12>/fcn4'
  //   Fcn: '<S12>/fcn5'
  //   Trigonometry: '<S36>/Trigonometric Function3'

  controller_3dof_B.RPY[0] = rt_atan2f_snf(RPY_tmp, ((RPY_tmp_tmp -
    RPY_tmp_tmp_0) - RPY_tmp_tmp_1) + RPY_tmp_tmp_2);

  // Trigonometry: '<S36>/trigFcn'
  if (controller_3dof_B.fcn3 > 1.0F) {
    controller_3dof_B.fcn3 = 1.0F;
  } else if (controller_3dof_B.fcn3 < -1.0F) {
    controller_3dof_B.fcn3 = -1.0F;
  }

  // MATLAB Function: '<Root>/reverse RPY' incorporates:
  //   Trigonometry: '<S36>/trigFcn'

  controller_3dof_B.RPY[1] = static_cast<real32_T>(asin(static_cast<real_T>
    (controller_3dof_B.fcn3)));

  // Fcn: '<S12>/fcn1' incorporates:
  //   Fcn: '<S13>/fcn1'
  //   ManualSwitch: '<Root>/Manual Switch1'
  //   Product: '<S37>/Product'
  //   Product: '<S37>/Product1'
  //   Product: '<S37>/Product2'
  //   Product: '<S37>/Product3'

  controller_3dof_B.rtb_Product3_l_tmp = (rtb_Product3_o_tmp *
    rtb_Product2_o_tmp + rtb_Product2_n_tmp *
    controller_3dof_B.rtb_Product3_l_tmp) * 2.0F;

  // MATLAB Function: '<Root>/reverse RPY' incorporates:
  //   Fcn: '<S12>/fcn1'
  //   Fcn: '<S12>/fcn2'
  //   Fcn: '<S12>/fcn5'
  //   Trigonometry: '<S36>/Trigonometric Function1'

  controller_3dof_B.RPY[2] = rt_atan2f_snf(controller_3dof_B.rtb_Product3_l_tmp,
    ((RPY_tmp_tmp + RPY_tmp_tmp_0) - RPY_tmp_tmp_1) - RPY_tmp_tmp_2);

  // Gain: '<Root>/Gain1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion5'

  controller_3dof_B.sph = controller_3dof_B.RPY[1];
  controller_3dof_B.cph = controller_3dof_B.RPY[0];
  controller_3dof_B.sth = controller_3dof_B.RPY[2];
  for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 3; controller_3dof_B.r1
       ++) {
    // Gain: '<Root>/Gain1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion5'

    controller_3dof_B.fcn3 =
      (controller_3dof_P.Gain1_Gain_c[controller_3dof_B.r1 + 3] *
       static_cast<real32_T>(controller_3dof_B.sph) +
       controller_3dof_P.Gain1_Gain_c[controller_3dof_B.r1] *
       static_cast<real32_T>(controller_3dof_B.cph)) +
      controller_3dof_P.Gain1_Gain_c[controller_3dof_B.r1 + 6] *
      static_cast<real32_T>(controller_3dof_B.sth);
    controller_3dof_B.Gain1_n[controller_3dof_B.r1] = controller_3dof_B.fcn3;

    // SignalConversion generated from: '<S2>/Gain2' incorporates:
    //   Gain: '<Root>/Gain1'

    controller_3dof_B.TmpSignalConversionAtGain2Inpor[controller_3dof_B.r1] =
      controller_3dof_B.Gain_i[controller_3dof_B.r1];
    controller_3dof_B.TmpSignalConversionAtGain2Inpor[controller_3dof_B.r1 + 3] =
      controller_3dof_B.fcn3;
  }

  // Gain: '<S2>/Gain3'
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 9;
       controller_3dof_B.rtemp++) {
    controller_3dof_B.b_x[controller_3dof_B.rtemp] =
      -controller_3dof_P.Kv[controller_3dof_B.rtemp];
  }

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant1'

  controller_3dof_B.Mtau_u[0] = 0.0;
  controller_3dof_B.Mtau_u[3] = 0.0;
  controller_3dof_B.sph = controller_3dof_P.param[3] * controller_3dof_P.param[4];
  controller_3dof_B.Mtau_u[6] = controller_3dof_B.sph;
  controller_3dof_B.cph = -controller_3dof_P.param[3] * controller_3dof_P.param
    [4];
  controller_3dof_B.Mtau_u[9] = controller_3dof_B.cph;
  controller_3dof_B.Mtau_u[1] = controller_3dof_B.cph;
  controller_3dof_B.Mtau_u[4] = controller_3dof_B.sph;
  controller_3dof_B.Mtau_u[7] = 0.0;
  controller_3dof_B.Mtau_u[10] = 0.0;
  controller_3dof_B.Mtau_u[2] = -controller_3dof_P.param[5];
  controller_3dof_B.Mtau_u[5] = -controller_3dof_P.param[5];
  controller_3dof_B.Mtau_u[8] = controller_3dof_P.param[5];
  controller_3dof_B.Mtau_u[11] = controller_3dof_P.param[5];
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
       controller_3dof_B.rtemp++) {
    // Sum: '<S2>/Sum5' incorporates:
    //   Gain: '<S2>/Gain2'

    controller_3dof_B.fcn3 = 0.0F;
    for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6;
         controller_3dof_B.r1++) {
      controller_3dof_B.fcn3 += controller_3dof_P.Gain2_Gain[3 *
        controller_3dof_B.r1 + controller_3dof_B.rtemp] *
        controller_3dof_B.TmpSignalConversionAtGain2Inpor[controller_3dof_B.r1];
    }

    // Sum: '<S2>/Sum5' incorporates:
    //   DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
    //   Gain: '<S2>/Gain3'

    controller_3dof_B.Sum5[controller_3dof_B.rtemp] =
      ((controller_3dof_B.b_x[controller_3dof_B.rtemp + 3] *
        controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[1] +
        controller_3dof_B.b_x[controller_3dof_B.rtemp] *
        controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[0]) +
       controller_3dof_B.b_x[controller_3dof_B.rtemp + 6] *
       controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[2]) +
      controller_3dof_B.fcn3;

    // MATLAB Function: '<Root>/allocation_logic'
    controller_3dof_B.cph = controller_3dof_B.Mtau_u[controller_3dof_B.rtemp];
    controller_3dof_B.r1 = controller_3dof_B.rtemp << 2;
    controller_3dof_B.x_tmp[controller_3dof_B.r1] = controller_3dof_B.cph;
    controller_3dof_B.sth = controller_3dof_B.Mtau_u[controller_3dof_B.rtemp + 3];
    controller_3dof_B.x_tmp[controller_3dof_B.r1 + 1] = controller_3dof_B.sth;
    controller_3dof_B.cth = controller_3dof_B.Mtau_u[controller_3dof_B.rtemp + 6];
    controller_3dof_B.x_tmp[controller_3dof_B.r1 + 2] = controller_3dof_B.cth;
    controller_3dof_B.sph = controller_3dof_B.Mtau_u[controller_3dof_B.rtemp + 9];
    controller_3dof_B.x_tmp[controller_3dof_B.r1 + 3] = controller_3dof_B.sph;
    for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 3;
         controller_3dof_B.r1++) {
      controller_3dof_B.A[controller_3dof_B.r1 + 3 * controller_3dof_B.rtemp] =
        ((controller_3dof_B.Mtau_u[controller_3dof_B.r1 + 3] *
          controller_3dof_B.sth + controller_3dof_B.cph *
          controller_3dof_B.Mtau_u[controller_3dof_B.r1]) +
         controller_3dof_B.Mtau_u[controller_3dof_B.r1 + 6] *
         controller_3dof_B.cth) + controller_3dof_B.Mtau_u[controller_3dof_B.r1
        + 9] * controller_3dof_B.sph;
    }
  }

  // MATLAB Function: '<Root>/allocation_logic' incorporates:
  //   Constant: '<Root>/Constant3'

  memcpy(&controller_3dof_B.b_x[0], &controller_3dof_B.A[0], 9U * sizeof(real_T));
  controller_3dof_B.rtemp = 0;
  controller_3dof_B.r1 = 3;
  controller_3dof_B.r2 = 6;
  controller_3dof_B.sph = fabs(controller_3dof_B.A[0]);
  controller_3dof_B.cph = fabs(controller_3dof_B.A[1]);
  controller_3dof_B.sth = fabs(controller_3dof_B.A[2]);
  if ((controller_3dof_B.cph > controller_3dof_B.sph) && (controller_3dof_B.cph >
       controller_3dof_B.sth)) {
    controller_3dof_B.rtemp = 3;
    controller_3dof_B.r1 = 0;
    controller_3dof_B.b_x[0] = controller_3dof_B.A[1];
    controller_3dof_B.b_x[1] = controller_3dof_B.A[0];
    controller_3dof_B.b_x[3] = controller_3dof_B.A[4];
    controller_3dof_B.b_x[4] = controller_3dof_B.A[3];
    controller_3dof_B.b_x[6] = controller_3dof_B.A[7];
    controller_3dof_B.b_x[7] = controller_3dof_B.A[6];
  } else if (controller_3dof_B.sth > controller_3dof_B.sph) {
    controller_3dof_B.rtemp = 6;
    controller_3dof_B.r2 = 0;
    controller_3dof_B.b_x[0] = controller_3dof_B.A[2];
    controller_3dof_B.b_x[2] = controller_3dof_B.A[0];
    controller_3dof_B.b_x[3] = controller_3dof_B.A[5];
    controller_3dof_B.b_x[5] = controller_3dof_B.A[3];
    controller_3dof_B.b_x[6] = controller_3dof_B.A[8];
    controller_3dof_B.b_x[8] = controller_3dof_B.A[6];
  }

  controller_3dof_B.b_x[1] /= controller_3dof_B.b_x[0];
  controller_3dof_B.b_x[2] /= controller_3dof_B.b_x[0];
  controller_3dof_B.b_x[4] -= controller_3dof_B.b_x[1] * controller_3dof_B.b_x[3];
  controller_3dof_B.b_x[5] -= controller_3dof_B.b_x[2] * controller_3dof_B.b_x[3];
  controller_3dof_B.b_x[7] -= controller_3dof_B.b_x[1] * controller_3dof_B.b_x[6];
  controller_3dof_B.b_x[8] -= controller_3dof_B.b_x[2] * controller_3dof_B.b_x[6];
  if (fabs(controller_3dof_B.b_x[5]) > fabs(controller_3dof_B.b_x[4])) {
    controller_3dof_B.r3 = controller_3dof_B.r1;
    controller_3dof_B.r1 = controller_3dof_B.r2;
    controller_3dof_B.r2 = controller_3dof_B.r3;
    controller_3dof_B.sph = controller_3dof_B.b_x[1];
    controller_3dof_B.b_x[1] = controller_3dof_B.b_x[2];
    controller_3dof_B.b_x[2] = controller_3dof_B.sph;
    controller_3dof_B.sph = controller_3dof_B.b_x[4];
    controller_3dof_B.b_x[4] = controller_3dof_B.b_x[5];
    controller_3dof_B.b_x[5] = controller_3dof_B.sph;
    controller_3dof_B.sph = controller_3dof_B.b_x[7];
    controller_3dof_B.b_x[7] = controller_3dof_B.b_x[8];
    controller_3dof_B.b_x[8] = controller_3dof_B.sph;
  }

  controller_3dof_B.b_x[5] /= controller_3dof_B.b_x[4];
  controller_3dof_B.b_x[8] -= controller_3dof_B.b_x[5] * controller_3dof_B.b_x[7];
  controller_3dof_B.sph = (controller_3dof_B.b_x[1] * controller_3dof_B.b_x[5] -
    controller_3dof_B.b_x[2]) / controller_3dof_B.b_x[8];
  controller_3dof_B.cph = -(controller_3dof_B.b_x[7] * controller_3dof_B.sph +
    controller_3dof_B.b_x[1]) / controller_3dof_B.b_x[4];
  controller_3dof_B.A[controller_3dof_B.rtemp] = ((1.0 - controller_3dof_B.b_x[3]
    * controller_3dof_B.cph) - controller_3dof_B.b_x[6] * controller_3dof_B.sph)
    / controller_3dof_B.b_x[0];
  controller_3dof_B.A[controller_3dof_B.rtemp + 1] = controller_3dof_B.cph;
  controller_3dof_B.A[controller_3dof_B.rtemp + 2] = controller_3dof_B.sph;
  controller_3dof_B.sph = -controller_3dof_B.b_x[5] / controller_3dof_B.b_x[8];
  controller_3dof_B.cph = (1.0 - controller_3dof_B.b_x[7] *
    controller_3dof_B.sph) / controller_3dof_B.b_x[4];
  controller_3dof_B.A[controller_3dof_B.r1] = -(controller_3dof_B.b_x[3] *
    controller_3dof_B.cph + controller_3dof_B.b_x[6] * controller_3dof_B.sph) /
    controller_3dof_B.b_x[0];
  controller_3dof_B.A[controller_3dof_B.r1 + 1] = controller_3dof_B.cph;
  controller_3dof_B.A[controller_3dof_B.r1 + 2] = controller_3dof_B.sph;
  controller_3dof_B.sph = 1.0 / controller_3dof_B.b_x[8];
  controller_3dof_B.cph = -controller_3dof_B.b_x[7] * controller_3dof_B.sph /
    controller_3dof_B.b_x[4];
  controller_3dof_B.A[controller_3dof_B.r2] = -(controller_3dof_B.b_x[3] *
    controller_3dof_B.cph + controller_3dof_B.b_x[6] * controller_3dof_B.sph) /
    controller_3dof_B.b_x[0];
  controller_3dof_B.A[controller_3dof_B.r2 + 1] = controller_3dof_B.cph;
  controller_3dof_B.A[controller_3dof_B.r2 + 2] = controller_3dof_B.sph;
  for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 4; controller_3dof_B.r1
       ++) {
    controller_3dof_B.sph = 0.0;
    controller_3dof_B.cph = controller_3dof_B.x_tmp[controller_3dof_B.r1 + 4];
    controller_3dof_B.sth = controller_3dof_B.x_tmp[controller_3dof_B.r1];
    controller_3dof_B.cth = controller_3dof_B.x_tmp[controller_3dof_B.r1 + 8];
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
         controller_3dof_B.rtemp++) {
      controller_3dof_B.sph += ((controller_3dof_B.A[3 * controller_3dof_B.rtemp
        + 1] * controller_3dof_B.cph + controller_3dof_B.A[3 *
        controller_3dof_B.rtemp] * controller_3dof_B.sth) + controller_3dof_B.A
        [3 * controller_3dof_B.rtemp + 2] * controller_3dof_B.cth) *
        controller_3dof_B.Sum5[controller_3dof_B.rtemp];
    }

    controller_3dof_B.u[controller_3dof_B.r1] = controller_3dof_B.sph;
    controller_3dof_B.un[controller_3dof_B.r1] = 0.0;
  }

  controller_3dof_B.At1_tmp = controller_3dof_minimum(controller_3dof_B.u);
  if (controller_3dof_B.At1_tmp < controller_3dof_P.Constant3_Value) {
    controller_3dof_B.sph = controller_3dof_P.Constant3_Value -
      controller_3dof_B.At1_tmp;
    controller_3dof_B.un[0] = controller_3dof_B.sph;
    controller_3dof_B.un[1] = controller_3dof_B.sph;
    controller_3dof_B.un[2] = controller_3dof_B.sph;
    controller_3dof_B.un[3] = controller_3dof_B.sph;
  }

  controller_3dof_B.sph = controller_3dof_B.u[0] + controller_3dof_B.un[0];
  controller_3dof_B.u[0] = controller_3dof_B.sph;
  if (controller_3dof_B.sph > 1000.0) {
    controller_3dof_B.u[0] = 1000.0;
  }

  controller_3dof_B.sph = controller_3dof_B.u[1] + controller_3dof_B.un[1];
  controller_3dof_B.u[1] = controller_3dof_B.sph;
  if (controller_3dof_B.sph > 1000.0) {
    controller_3dof_B.u[1] = 1000.0;
  }

  controller_3dof_B.sph = controller_3dof_B.u[2] + controller_3dof_B.un[2];
  controller_3dof_B.u[2] = controller_3dof_B.sph;
  if (controller_3dof_B.sph > 1000.0) {
    controller_3dof_B.u[2] = 1000.0;
  }

  controller_3dof_B.sph = controller_3dof_B.u[3] + controller_3dof_B.un[3];
  controller_3dof_B.u[3] = controller_3dof_B.sph;
  if (controller_3dof_B.sph > 1000.0) {
    controller_3dof_B.u[3] = 1000.0;
  }

  controller_3dof_B.sph = controller_3dof_B.u[1];
  controller_3dof_B.cph = controller_3dof_B.u[0];
  controller_3dof_B.sth = controller_3dof_B.u[2];
  controller_3dof_B.cth = controller_3dof_B.u[3];
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
       controller_3dof_B.rtemp++) {
    controller_3dof_B.tau_allocated[controller_3dof_B.rtemp] =
      ((controller_3dof_B.Mtau_u[controller_3dof_B.rtemp + 3] *
        controller_3dof_B.sph + controller_3dof_B.Mtau_u[controller_3dof_B.rtemp]
        * controller_3dof_B.cph) +
       controller_3dof_B.Mtau_u[controller_3dof_B.rtemp + 6] *
       controller_3dof_B.sth) + controller_3dof_B.Mtau_u[controller_3dof_B.rtemp
      + 9] * controller_3dof_B.cth;
  }

  // DataTypeConversion: '<S31>/Data Type Conversion1' incorporates:
  //   Constant: '<S31>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function2'
  //   Sum: '<S31>/Sum'

  controller_3dof_B.At1_tmp = floor(controller_3dof_B.u[0] +
    controller_3dof_P.Constant_Value_l);
  if (rtIsNaN(controller_3dof_B.At1_tmp) || rtIsInf(controller_3dof_B.At1_tmp))
  {
    controller_3dof_B.At1_tmp = 0.0;
  } else {
    controller_3dof_B.At1_tmp = fmod(controller_3dof_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_e = static_cast<uint16_T>(controller_3dof_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_3dof_B.At1_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_3dof_B.At1_tmp)));

  // End of DataTypeConversion: '<S31>/Data Type Conversion1'

  // DataTypeConversion: '<S32>/Data Type Conversion1' incorporates:
  //   Constant: '<S32>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function2'
  //   Sum: '<S32>/Sum'

  controller_3dof_B.At1_tmp = floor(controller_3dof_B.u[1] +
    controller_3dof_P.Constant_Value_h);
  if (rtIsNaN(controller_3dof_B.At1_tmp) || rtIsInf(controller_3dof_B.At1_tmp))
  {
    controller_3dof_B.At1_tmp = 0.0;
  } else {
    controller_3dof_B.At1_tmp = fmod(controller_3dof_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_o = static_cast<uint16_T>(controller_3dof_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_3dof_B.At1_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_3dof_B.At1_tmp)));

  // End of DataTypeConversion: '<S32>/Data Type Conversion1'

  // DataTypeConversion: '<S33>/Data Type Conversion1' incorporates:
  //   Constant: '<S33>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function2'
  //   Sum: '<S33>/Sum'

  controller_3dof_B.At1_tmp = floor(controller_3dof_B.u[2] +
    controller_3dof_P.Constant_Value_g);
  if (rtIsNaN(controller_3dof_B.At1_tmp) || rtIsInf(controller_3dof_B.At1_tmp))
  {
    controller_3dof_B.At1_tmp = 0.0;
  } else {
    controller_3dof_B.At1_tmp = fmod(controller_3dof_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_a = static_cast<uint16_T>(controller_3dof_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_3dof_B.At1_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_3dof_B.At1_tmp)));

  // End of DataTypeConversion: '<S33>/Data Type Conversion1'

  // DataTypeConversion: '<S34>/Data Type Conversion1' incorporates:
  //   Constant: '<S34>/Constant'
  //   MATLAB Function: '<Root>/MATLAB Function2'
  //   Sum: '<S34>/Sum'

  controller_3dof_B.At1_tmp = floor(controller_3dof_B.u[3] +
    controller_3dof_P.Constant_Value_c);
  if (rtIsNaN(controller_3dof_B.At1_tmp) || rtIsInf(controller_3dof_B.At1_tmp))
  {
    controller_3dof_B.At1_tmp = 0.0;
  } else {
    controller_3dof_B.At1_tmp = fmod(controller_3dof_B.At1_tmp, 65536.0);
  }

  rtb_DataTypeConversion1_c = static_cast<uint16_T>(controller_3dof_B.At1_tmp <
    0.0 ? static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-controller_3dof_B.At1_tmp)))) : static_cast<int32_T>(
    static_cast<uint16_T>(controller_3dof_B.At1_tmp)));

  // End of DataTypeConversion: '<S34>/Data Type Conversion1'

  // MATLABSystem: '<S22>/SourceBlock'
  rtb_ManualSwitch = uORB_read_step(controller_3dof_DW.obj_o.orbMetadataObj,
    &controller_3dof_DW.obj_o.eventStructObj, &controller_3dof_B.b_varargout_2_c,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S22>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  if (rtb_ManualSwitch) {
    // SignalConversion generated from: '<S23>/In1'
    controller_3dof_B.In1_mv = controller_3dof_B.b_varargout_2_c;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_fn);
  }

  // End of MATLABSystem: '<S22>/SourceBlock'
  // End of Outputs for SubSystem: '<S22>/Enabled Subsystem'

  // Fcn: '<S13>/fcn3'
  controller_3dof_B.fcn3 = rtb_fcn3_tmp;

  // If: '<S46>/If' incorporates:
  //   Constant: '<S47>/Constant'
  //   Constant: '<S48>/Constant'

  if (rtb_fcn3_tmp > 1.0F) {
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
    //   ActionPort: '<S47>/Action Port'

    controller_3dof_B.fcn3 = controller_3dof_P.Constant_Value_h0;

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem'

    // Update for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
    //   ActionPort: '<S47>/Action Port'

    // Update for If: '<S46>/If' incorporates:
    //   Constant: '<S47>/Constant'

    srUpdateBC(controller_3dof_DW.IfActionSubsystem_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem'
  } else if (rtb_fcn3_tmp < -1.0F) {
    // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S48>/Action Port'

    controller_3dof_B.fcn3 = controller_3dof_P.Constant_Value_n;

    // End of Outputs for SubSystem: '<S46>/If Action Subsystem1'

    // Update for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S48>/Action Port'

    // Update for If: '<S46>/If' incorporates:
    //   Constant: '<S48>/Constant'

    srUpdateBC(controller_3dof_DW.IfActionSubsystem1_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem1'
  } else {
    // Update for IfAction SubSystem: '<S46>/If Action Subsystem2' incorporates:
    //   ActionPort: '<S49>/Action Port'

    // Update for If: '<S46>/If'
    srUpdateBC(controller_3dof_DW.IfActionSubsystem2_SubsysRanBC);

    // End of Update for SubSystem: '<S46>/If Action Subsystem2'
  }

  // End of If: '<S46>/If'
  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
       controller_3dof_B.rtemp++) {
    // Gain: '<S5>/Gain1' incorporates:
    //   DataTypeConversion: '<S5>/Data Type Conversion1'

    controller_3dof_B.Gain1[controller_3dof_B.rtemp] =
      (controller_3dof_P.Gain1_Gain[controller_3dof_B.rtemp + 3] *
       controller_3dof_B.In1_mv.y +
       controller_3dof_P.Gain1_Gain[controller_3dof_B.rtemp] *
       controller_3dof_B.In1_mv.x) +
      controller_3dof_P.Gain1_Gain[controller_3dof_B.rtemp + 6] *
      controller_3dof_B.In1_mv.z;
  }

  // MATLAB Function: '<S3>/xk_dot_computation' incorporates:
  //   Constant: '<S3>/Constant6'
  //   DigitalClock: '<S3>/Discrete Time'

  if (controller_3dof_B.DigitalClock == 0.0) {
    controller_3dof_DW.Memory5_PreviousInput = 0.0;
  }

  if ((controller_3dof_B.DigitalClock - controller_3dof_DW.Memory5_PreviousInput
       >= controller_3dof_P.Ts_EKF_meas) || (controller_3dof_B.DigitalClock ==
       0.0)) {
    controller_3dof_B.cph = cos(controller_3dof_B.xk[0]);
    controller_3dof_B.cth = cos(controller_3dof_B.xk[1]);
    controller_3dof_B.sph = sin(controller_3dof_B.xk[0]);
    controller_3dof_B.tth = sin(controller_3dof_B.xk[1]) / controller_3dof_B.cth;
    controller_3dof_DW.Memory5_PreviousInput = controller_3dof_B.DigitalClock;
    controller_3dof_B.b_x[0] = 1.0;
    controller_3dof_B.b_x[3] = controller_3dof_B.sph * controller_3dof_B.tth;
    controller_3dof_B.b_x[6] = controller_3dof_B.cph * controller_3dof_B.tth;
    controller_3dof_B.b_x[1] = 0.0;
    controller_3dof_B.b_x[4] = controller_3dof_B.cph;
    controller_3dof_B.b_x[7] = -controller_3dof_B.sph;
    controller_3dof_B.b_x[2] = 0.0;
    controller_3dof_B.b_x[5] = controller_3dof_B.sph / controller_3dof_B.cth;
    controller_3dof_B.b_x[8] = controller_3dof_B.cph / controller_3dof_B.cth;
    controller_3dof_B.sph = controller_3dof_B.Gain1[0] - controller_3dof_B.xk[3]
      * 0.0;
    controller_3dof_B.cph = controller_3dof_B.Gain1[1] - controller_3dof_B.xk[4]
      * 0.0;
    controller_3dof_B.sth = controller_3dof_B.Gain1[2] - controller_3dof_B.xk[5]
      * 0.0;
    for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 3;
         controller_3dof_B.rtemp++) {
      controller_3dof_DW.Memory6_PreviousInput[controller_3dof_B.rtemp] =
        (controller_3dof_B.b_x[controller_3dof_B.rtemp + 3] *
         controller_3dof_B.cph + controller_3dof_B.b_x[controller_3dof_B.rtemp] *
         controller_3dof_B.sph) + controller_3dof_B.b_x[controller_3dof_B.rtemp
        + 6] * controller_3dof_B.sth;
    }
  }

  // End of MATLAB Function: '<S3>/xk_dot_computation'

  // ManualSwitch: '<Root>/Manual Switch1'
  if (controller_3dof_P.ManualSwitch1_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Constant5'

    for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 25;
         controller_3dof_B.r1++) {
      controller_3dof_B.ManualSwitch1[controller_3dof_B.r1] =
        controller_3dof_P.Constant5_Value;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   DataTypeConversion: '<S26>/Data Type Conversion1'
    //   DataTypeConversion: '<S26>/Data Type Conversion2'
    //   DataTypeConversion: '<S26>/Data Type Conversion3'
    //   DataTypeConversion: '<S26>/Data Type Conversion4'
    //   DataTypeConversion: '<S26>/Data Type Conversion5'
    //   Fcn: '<S13>/fcn2'
    //   Trigonometry: '<S44>/Trigonometric Function1'

    controller_3dof_B.ManualSwitch1[0] = rtb_DataTypeConversion1_e;
    controller_3dof_B.ManualSwitch1[1] = rtb_DataTypeConversion1_o;
    controller_3dof_B.ManualSwitch1[2] = rtb_DataTypeConversion1_a;
    controller_3dof_B.ManualSwitch1[3] = rtb_DataTypeConversion1_c;
    controller_3dof_B.ManualSwitch1[4] = controller_3dof_B.In1_lx.x;
    controller_3dof_B.ManualSwitch1[5] = controller_3dof_B.y;
    controller_3dof_B.ManualSwitch1[6] = controller_3dof_B.z;
    controller_3dof_B.ManualSwitch1[7] = controller_3dof_B.In1_mv.x;
    controller_3dof_B.ManualSwitch1[8] = controller_3dof_B.In1_mv.y;
    controller_3dof_B.ManualSwitch1[9] = controller_3dof_B.In1_mv.z;
    controller_3dof_B.ManualSwitch1[10] = controller_3dof_B.In1.rollspeed;
    controller_3dof_B.ManualSwitch1[11] = controller_3dof_B.In1.pitchspeed;
    controller_3dof_B.ManualSwitch1[12] = controller_3dof_B.In1.yawspeed;
    controller_3dof_B.ManualSwitch1[13] = rt_atan2f_snf
      (controller_3dof_B.rtb_Product3_l_tmp, ((RPY_tmp_tmp + RPY_tmp_tmp_0) -
        RPY_tmp_tmp_1) - RPY_tmp_tmp_2);

    // Trigonometry: '<S44>/trigFcn'
    if (controller_3dof_B.fcn3 > 1.0F) {
      controller_3dof_B.fcn3 = 1.0F;
    } else if (controller_3dof_B.fcn3 < -1.0F) {
      controller_3dof_B.fcn3 = -1.0F;
    }

    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   DataTypeConversion: '<S26>/Data Type Conversion5'
    //   Fcn: '<S13>/fcn5'
    //   MATLAB Function: '<S26>/MATLAB Function'
    //   SignalConversion generated from: '<S29>/ SFunction '
    //   Trigonometry: '<S44>/Trigonometric Function3'
    //   Trigonometry: '<S44>/trigFcn'

    controller_3dof_B.ManualSwitch1[14] = static_cast<real32_T>(asin(
      static_cast<real_T>(controller_3dof_B.fcn3)));
    controller_3dof_B.ManualSwitch1[15] = rt_atan2f_snf(RPY_tmp, ((RPY_tmp_tmp -
      RPY_tmp_tmp_0) - RPY_tmp_tmp_1) + RPY_tmp_tmp_2);
    controller_3dof_B.ManualSwitch1[16] = controller_3dof_B.In1_o.x;
    controller_3dof_B.ManualSwitch1[17] = controller_3dof_B.In1_o.y;
    controller_3dof_B.ManualSwitch1[18] = controller_3dof_B.In1_o.z;
    controller_3dof_B.ManualSwitch1[19] = controller_3dof_B.xk[0];
    controller_3dof_B.ManualSwitch1[20] = controller_3dof_B.xk[1];
    controller_3dof_B.ManualSwitch1[21] = controller_3dof_B.xk[2];
    controller_3dof_B.ManualSwitch1[22] =
      controller_3dof_DW.Memory6_PreviousInput[0];
    controller_3dof_B.ManualSwitch1[23] =
      controller_3dof_DW.Memory6_PreviousInput[1];
    controller_3dof_B.ManualSwitch1[24] =
      controller_3dof_DW.Memory6_PreviousInput[2];
  }

  // SignalConversion generated from: '<Root>/To Workspace'
  controller_3dof_B.TmpSignalConversionAt_asyncqueu[0] =
    controller_3dof_B.DigitalClock;
  memcpy(&controller_3dof_B.TmpSignalConversionAt_asyncqueu[1],
         &controller_3dof_B.ManualSwitch1[0], 25U * sizeof(real_T));

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/Constant'

  if (controller_3dof_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = controller_3dof_P.Constant_Value_e;
  } else {
    rtb_ManualSwitch = controller_3dof_P.ARMPWM_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Step: '<Root>/RPY angle_ref' incorporates:
  //   DigitalClock: '<S3>/Discrete Time'

  if (controller_3dof_B.DigitalClock < controller_3dof_P.RPYangle_ref_Time) {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_Y0;
  } else {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_YFinal[0];
  }

  // Product: '<S2>/Product' incorporates:
  //   Step: '<Root>/RPY angle_ref'
  //   Sum: '<S2>/Sum'

  controller_3dof_B.Product[0] = (controller_3dof_B.At1_tmp -
    controller_3dof_B.Gain_i[0]) * static_cast<real_T>(rtb_ManualSwitch);

  // Step: '<Root>/RPY angle_ref' incorporates:
  //   DigitalClock: '<S3>/Discrete Time'

  if (controller_3dof_B.DigitalClock < controller_3dof_P.RPYangle_ref_Time) {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_Y0;
  } else {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_YFinal[1];
  }

  // Product: '<S2>/Product' incorporates:
  //   Step: '<Root>/RPY angle_ref'
  //   Sum: '<S2>/Sum'

  controller_3dof_B.Product[1] = (controller_3dof_B.At1_tmp -
    controller_3dof_B.Gain_i[1]) * static_cast<real_T>(rtb_ManualSwitch);

  // Step: '<Root>/RPY angle_ref' incorporates:
  //   DigitalClock: '<S3>/Discrete Time'

  if (controller_3dof_B.DigitalClock < controller_3dof_P.RPYangle_ref_Time) {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_Y0;
  } else {
    controller_3dof_B.At1_tmp = controller_3dof_P.RPYangle_ref_YFinal[2];
  }

  // Product: '<S2>/Product' incorporates:
  //   Step: '<Root>/RPY angle_ref'
  //   Sum: '<S2>/Sum'

  controller_3dof_B.Product[2] = (controller_3dof_B.At1_tmp -
    controller_3dof_B.Gain_i[2]) * static_cast<real_T>(rtb_ManualSwitch);

  // MATLABSystem: '<S10>/PX4 PWM Output' incorporates:
  //   Constant: '<S10>/failsafe'

  for (controller_3dof_B.rtemp = 0; controller_3dof_B.rtemp < 8;
       controller_3dof_B.rtemp++) {
    controller_3dof_B.pwmValue[controller_3dof_B.rtemp] = 0U;
  }

  controller_3dof_B.pwmValue[0] = rtb_DataTypeConversion1_e;
  controller_3dof_B.pwmValue[1] = rtb_DataTypeConversion1_o;
  controller_3dof_B.pwmValue[2] = rtb_DataTypeConversion1_a;
  controller_3dof_B.pwmValue[3] = rtb_DataTypeConversion1_c;
  if (rtb_ManualSwitch) {
    if (!controller_3dof_DW.obj_dh.isArmed) {
      controller_3dof_DW.obj_dh.isArmed = true;
      rtb_DataTypeConversion1_e = pwm_arm
        (&controller_3dof_DW.obj_dh.pwmDevHandler,
         &controller_3dof_DW.obj_dh.armAdvertiseObj);
      controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
        (controller_3dof_DW.obj_dh.errorStatus | rtb_DataTypeConversion1_e);
    }

    rtb_DataTypeConversion1_e = pwm_setServo
      (&controller_3dof_DW.obj_dh.pwmDevHandler,
       controller_3dof_DW.obj_dh.servoCount,
       controller_3dof_DW.obj_dh.channelMask, &controller_3dof_B.pwmValue[0],
       controller_3dof_DW.obj_dh.isMain,
       &controller_3dof_DW.obj_dh.actuatorAdvertiseObj);
    controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
      (controller_3dof_DW.obj_dh.errorStatus | rtb_DataTypeConversion1_e);
  } else {
    rtb_DataTypeConversion1_e = pwm_disarm
      (&controller_3dof_DW.obj_dh.pwmDevHandler,
       &controller_3dof_DW.obj_dh.armAdvertiseObj);
    controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
      (controller_3dof_DW.obj_dh.errorStatus | rtb_DataTypeConversion1_e);
    controller_3dof_DW.obj_dh.isArmed = false;
    rtb_DataTypeConversion1_e = pwm_resetServo
      (&controller_3dof_DW.obj_dh.pwmDevHandler,
       controller_3dof_DW.obj_dh.servoCount,
       controller_3dof_DW.obj_dh.channelMask, controller_3dof_DW.obj_dh.isMain,
       &controller_3dof_DW.obj_dh.actuatorAdvertiseObj);
    controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
      (controller_3dof_DW.obj_dh.errorStatus | rtb_DataTypeConversion1_e);
  }

  if (controller_3dof_DW.obj_dh.isMain) {
    rtb_DataTypeConversion1_e = pwm_forceFailsafe
      (&controller_3dof_DW.obj_dh.pwmDevHandler, static_cast<int32_T>
       (controller_3dof_P.failsafe_Value));
    controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
      (controller_3dof_DW.obj_dh.errorStatus | rtb_DataTypeConversion1_e);
  }

  // End of MATLABSystem: '<S10>/PX4 PWM Output'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   MATLAB Function: '<S26>/MATLAB Function'
  //   SignalConversion generated from: '<S29>/ SFunction '

  controller_3dof_B.y1_pr = controller_3dof_B.xk[0];
  controller_3dof_B.y2_n5 = controller_3dof_B.xk[1];
  controller_3dof_B.y3_j = controller_3dof_B.xk[2];
  controller_3dof_B.y4_d = controller_3dof_DW.Memory6_PreviousInput[0];
  controller_3dof_B.y5_c = controller_3dof_DW.Memory6_PreviousInput[1];
  controller_3dof_B.y6_l = controller_3dof_DW.Memory6_PreviousInput[2];

  // Constant: '<S27>/Constant'
  controller_3dof_SourceBlock(&controller_3dof_B.SourceBlock_k,
    &controller_3dof_DW.SourceBlock_k);

  // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  if (controller_3dof_B.SourceBlock_k.SourceBlock_o1) {
    // SignalConversion generated from: '<S30>/In1' incorporates:
    //   MATLABSystem: '<S27>/SourceBlock'

    controller_3dof_B.In1_m = controller_3dof_B.SourceBlock_k.SourceBlock_o2;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of Outputs for SubSystem: '<S27>/Enabled Subsystem'

  // SignalConversion: '<S10>/Signal Conversion'
  controller_3dof_B.SignalConversion[0] = controller_3dof_B.In1_m.output[0];
  controller_3dof_B.SignalConversion[1] = controller_3dof_B.In1_m.output[1];

  // Constant: '<S11>/Constant'
  controller_3dof_SourceBlock(&controller_3dof_B.SourceBlock_h,
    &controller_3dof_DW.SourceBlock_h);

  // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S35>/Enable'

  if (controller_3dof_B.SourceBlock_h.SourceBlock_o1) {
    // SignalConversion generated from: '<S35>/In1' incorporates:
    //   MATLABSystem: '<S11>/SourceBlock'

    controller_3dof_B.In1_l = controller_3dof_B.SourceBlock_h.SourceBlock_o2;
    srUpdateBC(controller_3dof_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  controller_3dof_B.SignalConversion_g[0] = controller_3dof_B.In1_l.output[0];
  controller_3dof_B.SignalConversion_g[1] = controller_3dof_B.In1_l.output[1];

  // Update for Memory: '<S3>/Memory2'
  memcpy(&controller_3dof_DW.Memory2_PreviousInput[0], &controller_3dof_B.Pt[0],
         36U * sizeof(real_T));
  for (controller_3dof_B.r1 = 0; controller_3dof_B.r1 < 6; controller_3dof_B.r1
       ++) {
    // Update for Memory: '<S3>/Memory4'
    controller_3dof_DW.Memory4_PreviousInput[controller_3dof_B.r1] =
      controller_3dof_B.xk[controller_3dof_B.r1];

    // Update for Memory: '<S3>/Memory3'
    controller_3dof_DW.Memory3_PreviousInput[controller_3dof_B.r1] =
      controller_3dof_B.xt[controller_3dof_B.r1];
  }

  // Update for Memory: '<S3>/Memory1'
  controller_3dof_DW.Memory1_PreviousInput = controller_3dof_B.t_integr1;

  // Update for Memory: '<S3>/Memory'
  controller_3dof_DW.Memory_PreviousInput = controller_3dof_B.t_meas1_d;

  // Update for Delay: '<S3>/Delay2'
  controller_3dof_DW.Delay2_DSTATE[0] = controller_3dof_B.Gain1[0];

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    controller_3dof_P.DiscreteTimeIntegrator_gainval *
    controller_3dof_B.Product[0];

  // Update for Delay: '<S3>/Delay2'
  controller_3dof_DW.Delay2_DSTATE[1] = controller_3dof_B.Gain1[1];

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    controller_3dof_P.DiscreteTimeIntegrator_gainval *
    controller_3dof_B.Product[1];

  // Update for Delay: '<S3>/Delay2'
  controller_3dof_DW.Delay2_DSTATE[2] = controller_3dof_B.Gain1[2];

  // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
  controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[2] +=
    controller_3dof_P.DiscreteTimeIntegrator_gainval *
    controller_3dof_B.Product[2];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  controller_3dof_M->Timing.taskTime0 =
    ((time_T)(++controller_3dof_M->Timing.clockTick0)) *
    controller_3dof_M->Timing.stepSize0;
}

// Model initialize function
void controller_3dof_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(controller_3dof_M, -1);
  controller_3dof_M->Timing.stepSize0 = 0.01;

  // External mode info
  controller_3dof_M->Sizes.checksums[0] = (2081844829U);
  controller_3dof_M->Sizes.checksums[1] = (2557203609U);
  controller_3dof_M->Sizes.checksums[2] = (971415948U);
  controller_3dof_M->Sizes.checksums[3] = (2188146401U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[32];
    controller_3dof_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC_fn;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC_n;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[19] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem1_SubsysRanB_m;
    systemRan[20] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem2_SubsysRanB_c;
    systemRan[21] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &controller_3dof_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = (sysRanDType *)
      &controller_3dof_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(controller_3dof_M->extModeInfo,
      &controller_3dof_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_3dof_M->extModeInfo,
                        controller_3dof_M->Sizes.checksums);
    rteiSetTPtr(controller_3dof_M->extModeInfo, rtmGetTPtr(controller_3dof_M));
  }

  {
    int32_T i;
    boolean_T rtb_ManualSwitch;

    // InitializeConditions for Memory: '<S3>/Memory2'
    for (i = 0; i < 36; i++) {
      controller_3dof_DW.Memory2_PreviousInput[i] =
        controller_3dof_P.Memory2_InitialCondition;
    }

    // End of InitializeConditions for Memory: '<S3>/Memory2'
    for (i = 0; i < 6; i++) {
      // InitializeConditions for Memory: '<S3>/Memory4'
      controller_3dof_DW.Memory4_PreviousInput[i] =
        controller_3dof_P.Memory4_InitialCondition;

      // InitializeConditions for Memory: '<S3>/Memory3'
      controller_3dof_DW.Memory3_PreviousInput[i] =
        controller_3dof_P.Memory3_InitialCondition;
    }

    // InitializeConditions for Memory: '<S3>/Memory1'
    controller_3dof_DW.Memory1_PreviousInput =
      controller_3dof_P.Memory1_InitialCondition;

    // InitializeConditions for Memory: '<S3>/Memory'
    controller_3dof_DW.Memory_PreviousInput =
      controller_3dof_P.Memory_InitialCondition;

    // InitializeConditions for Memory: '<S3>/Memory5'
    controller_3dof_DW.Memory5_PreviousInput =
      controller_3dof_P.Memory5_InitialCondition;

    // InitializeConditions for Delay: '<S3>/Delay2'
    controller_3dof_DW.Delay2_DSTATE[0] =
      controller_3dof_P.Delay2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
    controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[0] =
      controller_3dof_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S3>/Memory6'
    controller_3dof_DW.Memory6_PreviousInput[0] =
      controller_3dof_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S3>/Delay2'
    controller_3dof_DW.Delay2_DSTATE[1] =
      controller_3dof_P.Delay2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
    controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[1] =
      controller_3dof_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S3>/Memory6'
    controller_3dof_DW.Memory6_PreviousInput[1] =
      controller_3dof_P.Memory6_InitialCondition;

    // InitializeConditions for Delay: '<S3>/Delay2'
    controller_3dof_DW.Delay2_DSTATE[2] =
      controller_3dof_P.Delay2_InitialCondition;

    // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
    controller_3dof_DW.DiscreteTimeIntegrator_DSTATE[2] =
      controller_3dof_P.DiscreteTimeIntegrator_IC;

    // InitializeConditions for Memory: '<S3>/Memory6'
    controller_3dof_DW.Memory6_PreviousInput[2] =
      controller_3dof_P.Memory6_InitialCondition;

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    controller_3dof_B.In1_lx = controller_3dof_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S24>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S25>/In1' incorporates:
    //   Outport: '<S25>/Out1'

    controller_3dof_B.In1_o = controller_3dof_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S24>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S52>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S53>/In1' incorporates:
    //   Outport: '<S53>/Out1'

    controller_3dof_B.In1 = controller_3dof_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S52>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S22>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    controller_3dof_B.In1_mv = controller_3dof_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S22>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S30>/In1' incorporates:
    //   Outport: '<S30>/Out1'

    controller_3dof_B.In1_m = controller_3dof_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S35>/In1' incorporates:
    //   Outport: '<S35>/Out1'

    controller_3dof_B.In1_l = controller_3dof_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'

    // Start for MATLABSystem: '<S18>/SourceBlock'
    controller_3dof_DW.obj_a.matlabCodegenIsDeleted = false;
    controller_3dof_DW.obj_a.isInitialized = 1;
    controller_3dof_DW.obj_a.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(controller_3dof_DW.obj_a.orbMetadataObj,
                         &controller_3dof_DW.obj_a.eventStructObj);
    controller_3dof_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S24>/SourceBlock'
    controller_3dof_DW.obj_d.matlabCodegenIsDeleted = false;
    controller_3dof_DW.obj_d.isInitialized = 1;
    controller_3dof_DW.obj_d.orbMetadataObj = ORB_ID(sensor_mag);
    uORB_read_initialize(controller_3dof_DW.obj_d.orbMetadataObj,
                         &controller_3dof_DW.obj_d.eventStructObj);
    controller_3dof_DW.obj_d.isSetupComplete = true;

    // Start for MATLABSystem: '<S52>/SourceBlock'
    controller_3dof_DW.obj.matlabCodegenIsDeleted = false;
    controller_3dof_DW.obj.isInitialized = 1;
    controller_3dof_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(controller_3dof_DW.obj.orbMetadataObj,
                         &controller_3dof_DW.obj.eventStructObj);
    controller_3dof_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SourceBlock'
    controller_3dof_DW.obj_o.matlabCodegenIsDeleted = false;
    controller_3dof_DW.obj_o.isInitialized = 1;
    controller_3dof_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(controller_3dof_DW.obj_o.orbMetadataObj,
                         &controller_3dof_DW.obj_o.eventStructObj);
    controller_3dof_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S10>/PX4 PWM Output' incorporates:
    //   Constant: '<S10>/failsafe'

    controller_3dof_DW.obj_dh.errorStatus = 0U;
    controller_3dof_DW.obj_dh.isInitialized = 0;
    controller_3dof_DW.obj_dh.matlabCodegenIsDeleted = false;
    controller_3do_SystemCore_setup(&controller_3dof_DW.obj_dh, rtb_ManualSwitch,
      controller_3dof_P.failsafe_Value);

    // Constant: '<S27>/Constant'
    controller_3do_SourceBlock_Init(&controller_3dof_DW.SourceBlock_k);

    // Constant: '<S11>/Constant'
    controller_3do_SourceBlock_Init(&controller_3dof_DW.SourceBlock_h);
  }
}

// Model terminate function
void controller_3dof_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!controller_3dof_DW.obj_a.matlabCodegenIsDeleted) {
    controller_3dof_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((controller_3dof_DW.obj_a.isInitialized == 1) &&
        controller_3dof_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&controller_3dof_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S24>/SourceBlock'
  if (!controller_3dof_DW.obj_d.matlabCodegenIsDeleted) {
    controller_3dof_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((controller_3dof_DW.obj_d.isInitialized == 1) &&
        controller_3dof_DW.obj_d.isSetupComplete) {
      uORB_read_terminate(&controller_3dof_DW.obj_d.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S24>/SourceBlock'

  // Terminate for MATLABSystem: '<S52>/SourceBlock'
  if (!controller_3dof_DW.obj.matlabCodegenIsDeleted) {
    controller_3dof_DW.obj.matlabCodegenIsDeleted = true;
    if ((controller_3dof_DW.obj.isInitialized == 1) &&
        controller_3dof_DW.obj.isSetupComplete) {
      uORB_read_terminate(&controller_3dof_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S52>/SourceBlock'

  // Terminate for MATLABSystem: '<S22>/SourceBlock'
  if (!controller_3dof_DW.obj_o.matlabCodegenIsDeleted) {
    controller_3dof_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((controller_3dof_DW.obj_o.isInitialized == 1) &&
        controller_3dof_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&controller_3dof_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S22>/SourceBlock'
  // Terminate for MATLABSystem: '<S10>/PX4 PWM Output'
  if (!controller_3dof_DW.obj_dh.matlabCodegenIsDeleted) {
    controller_3dof_DW.obj_dh.matlabCodegenIsDeleted = true;
    if ((controller_3dof_DW.obj_dh.isInitialized == 1) &&
        controller_3dof_DW.obj_dh.isSetupComplete) {
      status = pwm_disarm(&controller_3dof_DW.obj_dh.pwmDevHandler,
                          &controller_3dof_DW.obj_dh.armAdvertiseObj);
      controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
        (controller_3dof_DW.obj_dh.errorStatus | status);
      status = pwm_resetServo(&controller_3dof_DW.obj_dh.pwmDevHandler,
        controller_3dof_DW.obj_dh.servoCount,
        controller_3dof_DW.obj_dh.channelMask, controller_3dof_DW.obj_dh.isMain,
        &controller_3dof_DW.obj_dh.actuatorAdvertiseObj);
      controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
        (controller_3dof_DW.obj_dh.errorStatus | status);
      status = pwm_close(&controller_3dof_DW.obj_dh.pwmDevHandler,
                         &controller_3dof_DW.obj_dh.actuatorAdvertiseObj,
                         &controller_3dof_DW.obj_dh.armAdvertiseObj);
      controller_3dof_DW.obj_dh.errorStatus = static_cast<uint16_T>
        (controller_3dof_DW.obj_dh.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<S10>/PX4 PWM Output'
  controller_3do_SourceBlock_Term(&controller_3dof_DW.SourceBlock_k);
  controller_3do_SourceBlock_Term(&controller_3dof_DW.SourceBlock_h);
}

//
// File trailer for generated code.
//
// [EOF]
//
