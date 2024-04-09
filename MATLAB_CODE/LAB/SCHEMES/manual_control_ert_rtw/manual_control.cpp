//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_control.cpp
//
// Code generated for Simulink model 'manual_control'.
//
// Model version                  : 1.36
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr  9 14:44:41 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "manual_control.h"
#include "manual_control_types.h"
#include "rtwtypes.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "manual_control_private.h"

// Block signals (default storage)
B_manual_control_T manual_control_B;

// Block states (default storage)
DW_manual_control_T manual_control_DW;

// Real-time model
RT_MODEL_manual_control_T manual_control_M_ = RT_MODEL_manual_control_T();
RT_MODEL_manual_control_T *const manual_control_M = &manual_control_M_;

// Forward declaration for local functions
static void manual_control_SystemCore_setup(px4_internal_block_PWM_manual_T *obj,
  boolean_T varargin_1, boolean_T varargin_2);
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
void manual_control_step(void)
{
  real_T tmp;
  int32_T i;
  uint16_T pwmValue[8];
  uint16_T rtb_DataTypeConversion1_a;
  uint16_T rtb_DataTypeConversion1_fx;
  uint16_T rtb_DataTypeConversion1_j;
  uint16_T rtb_DataTypeConversion1_n;
  boolean_T b_varargout_1;

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_c);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_f);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_k);

  // Reset subsysRan breadcrumbs
  srClearBC(manual_control_DW.EnabledSubsystem_SubsysRanBC);

  // DigitalClock: '<Root>/Digital Clock'
  manual_control_B.DigitalClock = manual_control_M->Timing.taskTime0;

  // DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S6>/Constant'
  //   Gain: '<Root>/Motor1'
  //   Sum: '<S6>/Sum'

  tmp = floor(manual_control_P.Motor1_Gain * manual_control_P.Constant4_Value +
              manual_control_P.Constant_Value_ah);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1_n = static_cast<uint16_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
    (tmp)));

  // End of DataTypeConversion: '<S6>/Data Type Conversion1'

  // DataTypeConversion: '<S7>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<S7>/Constant'
  //   Gain: '<Root>/Motor2'
  //   Sum: '<S7>/Sum'

  tmp = floor(manual_control_P.Motor2_Gain * manual_control_P.Constant2_Value +
              manual_control_P.Constant_Value_c);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1_fx = static_cast<uint16_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
    (tmp)));

  // End of DataTypeConversion: '<S7>/Data Type Conversion1'

  // DataTypeConversion: '<S8>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<S8>/Constant'
  //   Gain: '<Root>/Motor3'
  //   Sum: '<S8>/Sum'

  tmp = floor(manual_control_P.Motor3_Gain * manual_control_P.Constant3_Value +
              manual_control_P.Constant_Value_h);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1_a = static_cast<uint16_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
    (tmp)));

  // End of DataTypeConversion: '<S8>/Data Type Conversion1'

  // DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<S9>/Constant'
  //   Gain: '<Root>/Motor4'
  //   Sum: '<S9>/Sum'

  tmp = floor(manual_control_P.Motor4_Gain * manual_control_P.Constant1_Value +
              manual_control_P.Constant_Value_op);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion1_j = static_cast<uint16_T>(tmp < 0.0 ?
    static_cast<int32_T>(static_cast<uint16_T>(-static_cast<int16_T>(
    static_cast<uint16_T>(-tmp)))) : static_cast<int32_T>(static_cast<uint16_T>
    (tmp)));

  // End of DataTypeConversion: '<S9>/Data Type Conversion1'

  // MATLABSystem: '<S10>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_DW.obj_a.orbMetadataObj,
    &manual_control_DW.obj_a.eventStructObj, &manual_control_B.b_varargout_2_c,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S11>/In1'
    manual_control_B.In1_lx = manual_control_B.b_varargout_2_c;
    srUpdateBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_c);
  }

  // End of MATLABSystem: '<S10>/SourceBlock'
  // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'

  // SignalConversion generated from: '<S1>/Bus Selector'
  manual_control_B.z = manual_control_B.In1_lx.z;

  // MATLABSystem: '<S15>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_DW.obj.orbMetadataObj,
    &manual_control_DW.obj.eventStructObj, &manual_control_B.b_varargout_2,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S15>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S16>/In1'
    manual_control_B.In1 = manual_control_B.b_varargout_2;
    srUpdateBC(manual_control_DW.EnabledSubsystem_SubsysRanBC);
  }

  // End of MATLABSystem: '<S15>/SourceBlock'
  // End of Outputs for SubSystem: '<S15>/Enabled Subsystem'

  // SignalConversion generated from: '<S5>/Bus Selector'
  manual_control_B.rollspeed = manual_control_B.In1.rollspeed;

  // SignalConversion generated from: '<S5>/Bus Selector'
  manual_control_B.pitchspeed = manual_control_B.In1.pitchspeed;

  // SignalConversion generated from: '<S5>/Bus Selector'
  manual_control_B.yawspeed = manual_control_B.In1.yawspeed;

  // MATLABSystem: '<S12>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_DW.obj_o.orbMetadataObj,
    &manual_control_DW.obj_o.eventStructObj, &manual_control_B.b_varargout_2_k,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    manual_control_B.In1_m = manual_control_B.b_varargout_2_k;
    srUpdateBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_f);
  }

  // End of MATLABSystem: '<S12>/SourceBlock'
  // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'

  // ManualSwitch: '<Root>/Manual Switch1'
  if (manual_control_P.ManualSwitch1_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Constant5'

    for (i = 0; i < 15; i++) {
      manual_control_B.ManualSwitch1[i] = manual_control_P.Constant5_Value;
    }
  } else {
    // ManualSwitch: '<Root>/Manual Switch1' incorporates:
    //   Constant: '<Root>/Thrust [N]'
    //   DataTypeConversion: '<S2>/Data Type Conversion1'
    //   DataTypeConversion: '<S2>/Data Type Conversion2'
    //   DataTypeConversion: '<S2>/Data Type Conversion3'
    //   DataTypeConversion: '<S2>/Data Type Conversion4'
    //   DataTypeConversion: '<S2>/Data Type Conversion5'

    manual_control_B.ManualSwitch1[0] = rtb_DataTypeConversion1_n;
    manual_control_B.ManualSwitch1[1] = rtb_DataTypeConversion1_fx;
    manual_control_B.ManualSwitch1[2] = rtb_DataTypeConversion1_a;
    manual_control_B.ManualSwitch1[3] = rtb_DataTypeConversion1_j;
    manual_control_B.ManualSwitch1[4] = manual_control_B.In1_lx.x;
    manual_control_B.ManualSwitch1[5] = manual_control_B.In1_lx.y;
    manual_control_B.ManualSwitch1[6] = manual_control_B.z;
    manual_control_B.ManualSwitch1[7] = manual_control_B.In1_m.x;
    manual_control_B.ManualSwitch1[8] = manual_control_B.In1_m.y;
    manual_control_B.ManualSwitch1[9] = manual_control_B.In1_m.z;
    manual_control_B.ManualSwitch1[10] = manual_control_B.rollspeed;
    manual_control_B.ManualSwitch1[11] = manual_control_B.pitchspeed;
    manual_control_B.ManualSwitch1[12] = manual_control_B.yawspeed;
    manual_control_B.ManualSwitch1[13] = rtb_DataTypeConversion1_fx;
    manual_control_B.ManualSwitch1[14] = manual_control_P.ThrustN_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // SignalConversion generated from: '<Root>/To Workspace'
  manual_control_B.TmpSignalConversionAt_asyncqueu[0] =
    manual_control_B.DigitalClock;
  memcpy(&manual_control_B.TmpSignalConversionAt_asyncqueu[1],
         &manual_control_B.ManualSwitch1[0], 15U * sizeof(real_T));

  // MATLABSystem: '<Root>/PX4 PWM Output'
  for (i = 0; i < 8; i++) {
    pwmValue[i] = 0U;
  }

  pwmValue[0] = rtb_DataTypeConversion1_n;
  pwmValue[1] = rtb_DataTypeConversion1_fx;
  pwmValue[2] = rtb_DataTypeConversion1_a;
  pwmValue[3] = rtb_DataTypeConversion1_j;

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/ARM PWM'
  //   Constant: '<Root>/Constant'

  if (manual_control_P.ManualSwitch_CurrentSetting == 1) {
    b_varargout_1 = manual_control_P.Constant_Value_e;
  } else {
    b_varargout_1 = manual_control_P.ARMPWM_Value;
  }

  // MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
  //   Constant: '<Root>/failsafe'
  //   ManualSwitch: '<Root>/Manual Switch'

  if (b_varargout_1) {
    if (!manual_control_DW.obj_l.isArmed) {
      manual_control_DW.obj_l.isArmed = true;
      rtb_DataTypeConversion1_n = pwm_arm(&manual_control_DW.obj_l.pwmDevHandler,
        &manual_control_DW.obj_l.armAdvertiseObj);
      manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_control_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    }

    rtb_DataTypeConversion1_n = pwm_setServo
      (&manual_control_DW.obj_l.pwmDevHandler,
       manual_control_DW.obj_l.servoCount, manual_control_DW.obj_l.channelMask,
       &pwmValue[0], manual_control_DW.obj_l.isMain,
       &manual_control_DW.obj_l.actuatorAdvertiseObj);
    manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_control_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  } else {
    rtb_DataTypeConversion1_n = pwm_disarm
      (&manual_control_DW.obj_l.pwmDevHandler,
       &manual_control_DW.obj_l.armAdvertiseObj);
    manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_control_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
    manual_control_DW.obj_l.isArmed = false;
    rtb_DataTypeConversion1_n = pwm_resetServo
      (&manual_control_DW.obj_l.pwmDevHandler,
       manual_control_DW.obj_l.servoCount, manual_control_DW.obj_l.channelMask,
       manual_control_DW.obj_l.isMain,
       &manual_control_DW.obj_l.actuatorAdvertiseObj);
    manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_control_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  if (manual_control_DW.obj_l.isMain) {
    rtb_DataTypeConversion1_n = pwm_forceFailsafe
      (&manual_control_DW.obj_l.pwmDevHandler, static_cast<int32_T>
       (manual_control_P.failsafe_Value));
    manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
      (manual_control_DW.obj_l.errorStatus | rtb_DataTypeConversion1_n);
  }

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = uORB_read_step(manual_control_DW.obj_m.orbMetadataObj,
    &manual_control_DW.obj_m.eventStructObj, &manual_control_B.b_varargout_2_m,
    false, 1.0);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S14>/In1'
    manual_control_B.In1_l = manual_control_B.b_varargout_2_m;
    srUpdateBC(manual_control_DW.EnabledSubsystem_SubsysRanBC_k);
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // SignalConversion: '<Root>/Signal Conversion'
  manual_control_B.SignalConversion[0] = manual_control_B.In1_l.output[0];
  manual_control_B.SignalConversion[1] = manual_control_B.In1_l.output[1];

  {                                    // Sample time: [0.01s, 0.0s]
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  manual_control_M->Timing.taskTime0 =
    ((time_T)(++manual_control_M->Timing.clockTick0)) *
    manual_control_M->Timing.stepSize0;
}

// Model initialize function
void manual_control_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(manual_control_M, -1);
  manual_control_M->Timing.stepSize0 = 0.01;

  // External mode info
  manual_control_M->Sizes.checksums[0] = (2709253241U);
  manual_control_M->Sizes.checksums[1] = (3274677470U);
  manual_control_M->Sizes.checksums[2] = (243878964U);
  manual_control_M->Sizes.checksums[3] = (3335405697U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    manual_control_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &manual_control_DW.EnabledSubsystem_SubsysRanBC_c;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &manual_control_DW.EnabledSubsystem_SubsysRanBC_f;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)
      &manual_control_DW.EnabledSubsystem_SubsysRanBC_k;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = (sysRanDType *)
      &manual_control_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(manual_control_M->extModeInfo,
      &manual_control_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(manual_control_M->extModeInfo,
                        manual_control_M->Sizes.checksums);
    rteiSetTPtr(manual_control_M->extModeInfo, rtmGetTPtr(manual_control_M));
  }

  {
    boolean_T rtb_ManualSwitch;

    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    manual_control_B.In1_lx = manual_control_P.Out1_Y0_d;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S15>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S16>/In1' incorporates:
    //   Outport: '<S16>/Out1'

    manual_control_B.In1 = manual_control_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S15>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    manual_control_B.In1_m = manual_control_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S14>/In1' incorporates:
    //   Outport: '<S14>/Out1'

    manual_control_B.In1_l = manual_control_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    manual_control_DW.obj_a.matlabCodegenIsDeleted = false;
    manual_control_DW.obj_a.isInitialized = 1;
    manual_control_DW.obj_a.orbMetadataObj = ORB_ID(sensor_accel);
    uORB_read_initialize(manual_control_DW.obj_a.orbMetadataObj,
                         &manual_control_DW.obj_a.eventStructObj);
    manual_control_DW.obj_a.isSetupComplete = true;

    // Start for MATLABSystem: '<S15>/SourceBlock'
    manual_control_DW.obj.matlabCodegenIsDeleted = false;
    manual_control_DW.obj.isInitialized = 1;
    manual_control_DW.obj.orbMetadataObj = ORB_ID(vehicle_odometry);
    uORB_read_initialize(manual_control_DW.obj.orbMetadataObj,
                         &manual_control_DW.obj.eventStructObj);
    manual_control_DW.obj.isSetupComplete = true;

    // Start for MATLABSystem: '<S12>/SourceBlock'
    manual_control_DW.obj_o.matlabCodegenIsDeleted = false;
    manual_control_DW.obj_o.isInitialized = 1;
    manual_control_DW.obj_o.orbMetadataObj = ORB_ID(sensor_gyro);
    uORB_read_initialize(manual_control_DW.obj_o.orbMetadataObj,
                         &manual_control_DW.obj_o.eventStructObj);
    manual_control_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/PX4 PWM Output' incorporates:
    //   Constant: '<Root>/failsafe'

    manual_control_DW.obj_l.errorStatus = 0U;
    manual_control_DW.obj_l.isInitialized = 0;
    manual_control_DW.obj_l.matlabCodegenIsDeleted = false;
    manual_control_SystemCore_setup(&manual_control_DW.obj_l, rtb_ManualSwitch,
      manual_control_P.failsafe_Value);

    // Start for MATLABSystem: '<S4>/SourceBlock'
    manual_control_DW.obj_m.matlabCodegenIsDeleted = false;
    manual_control_DW.obj_m.isInitialized = 1;
    manual_control_DW.obj_m.orbMetadataObj = ORB_ID(actuator_outputs);
    uORB_read_initialize(manual_control_DW.obj_m.orbMetadataObj,
                         &manual_control_DW.obj_m.eventStructObj);
    manual_control_DW.obj_m.isSetupComplete = true;
  }
}

// Model terminate function
void manual_control_terminate(void)
{
  uint16_T status;

  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!manual_control_DW.obj_a.matlabCodegenIsDeleted) {
    manual_control_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((manual_control_DW.obj_a.isInitialized == 1) &&
        manual_control_DW.obj_a.isSetupComplete) {
      uORB_read_terminate(&manual_control_DW.obj_a.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'

  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!manual_control_DW.obj.matlabCodegenIsDeleted) {
    manual_control_DW.obj.matlabCodegenIsDeleted = true;
    if ((manual_control_DW.obj.isInitialized == 1) &&
        manual_control_DW.obj.isSetupComplete) {
      uORB_read_terminate(&manual_control_DW.obj.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'

  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!manual_control_DW.obj_o.matlabCodegenIsDeleted) {
    manual_control_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((manual_control_DW.obj_o.isInitialized == 1) &&
        manual_control_DW.obj_o.isSetupComplete) {
      uORB_read_terminate(&manual_control_DW.obj_o.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
  // Terminate for MATLABSystem: '<Root>/PX4 PWM Output'
  if (!manual_control_DW.obj_l.matlabCodegenIsDeleted) {
    manual_control_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((manual_control_DW.obj_l.isInitialized == 1) &&
        manual_control_DW.obj_l.isSetupComplete) {
      status = pwm_disarm(&manual_control_DW.obj_l.pwmDevHandler,
                          &manual_control_DW.obj_l.armAdvertiseObj);
      manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_control_DW.obj_l.errorStatus | status);
      status = pwm_resetServo(&manual_control_DW.obj_l.pwmDevHandler,
        manual_control_DW.obj_l.servoCount, manual_control_DW.obj_l.channelMask,
        manual_control_DW.obj_l.isMain,
        &manual_control_DW.obj_l.actuatorAdvertiseObj);
      manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_control_DW.obj_l.errorStatus | status);
      status = pwm_close(&manual_control_DW.obj_l.pwmDevHandler,
                         &manual_control_DW.obj_l.actuatorAdvertiseObj,
                         &manual_control_DW.obj_l.armAdvertiseObj);
      manual_control_DW.obj_l.errorStatus = static_cast<uint16_T>
        (manual_control_DW.obj_l.errorStatus | status);
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/PX4 PWM Output'

  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!manual_control_DW.obj_m.matlabCodegenIsDeleted) {
    manual_control_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((manual_control_DW.obj_m.isInitialized == 1) &&
        manual_control_DW.obj_m.isSetupComplete) {
      uORB_read_terminate(&manual_control_DW.obj_m.eventStructObj);
    }
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
}

//
// File trailer for generated code.
//
// [EOF]
//
