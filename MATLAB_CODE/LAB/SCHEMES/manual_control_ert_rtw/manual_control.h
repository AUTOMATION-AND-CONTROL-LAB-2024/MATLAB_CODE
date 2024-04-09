//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_control.h
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
#ifndef RTW_HEADER_manual_control_h_
#define RTW_HEADER_manual_control_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_PWM.h"
#include "manual_control_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
struct B_manual_control_T {
  px4_Bus_vehicle_odometry In1;        // '<S16>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  px4_Bus_actuator_outputs In1_l;      // '<S14>/In1'
  px4_Bus_actuator_outputs b_varargout_2_m;
  px4_Bus_sensor_accel In1_lx;         // '<S11>/In1'
  px4_Bus_sensor_accel b_varargout_2_c;
  px4_Bus_sensor_gyro In1_m;           // '<S13>/In1'
  px4_Bus_sensor_gyro b_varargout_2_k;
  real_T DigitalClock;                 // '<Root>/Digital Clock'
  real_T ManualSwitch1[15];            // '<Root>/Manual Switch1'
  real_T TmpSignalConversionAt_asyncqueu[16];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1' 
  real32_T z;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T rollspeed;
                  // '<S5>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  real32_T pitchspeed;
                  // '<S5>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T yawspeed;
                  // '<S5>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T SignalConversion[2];        // '<Root>/Signal Conversion'
};

// Block states (default storage) for system '<Root>'
struct DW_manual_control_T {
  px4_internal_block_Subscriber_T obj; // '<S15>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S4>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S12>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S10>/SourceBlock'
  px4_internal_block_PWM_manual_T obj_l;// '<Root>/PX4 PWM Output'
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<Root>/Scope4'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<Root>/Scope'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S15>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S4>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S12>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S10>/Enabled Subsystem'
};

// Parameters (default storage)
struct P_manual_control_T_ {
  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S16>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S15>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_b;  // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S14>/Out1'

  px4_Bus_actuator_outputs Constant_Value_a;// Computed Parameter: Constant_Value_a
                                               //  Referenced by: '<S4>/Constant'

  px4_Bus_sensor_accel Out1_Y0_d;      // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S11>/Out1'

  px4_Bus_sensor_accel Constant_Value_f;// Computed Parameter: Constant_Value_f
                                           //  Referenced by: '<S10>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_h;       // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S13>/Out1'

  px4_Bus_sensor_gyro Constant_Value_o;// Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S12>/Constant'

  real_T ThrustN_Value;                // Expression: 2.7
                                          //  Referenced by: '<Root>/Thrust [N]'

  real_T Constant4_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant4'

  real_T Motor1_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor1'

  real_T Constant_Value_ah;            // Expression: 1000
                                          //  Referenced by: '<S6>/Constant'

  real_T Constant2_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant2'

  real_T Motor2_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor2'

  real_T Constant_Value_c;             // Expression: 1000
                                          //  Referenced by: '<S7>/Constant'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant3'

  real_T Motor3_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor3'

  real_T Constant_Value_h;             // Expression: 1000
                                          //  Referenced by: '<S8>/Constant'

  real_T Constant1_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant1'

  real_T Motor4_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor4'

  real_T Constant_Value_op;            // Expression: 1000
                                          //  Referenced by: '<S9>/Constant'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  boolean_T Constant_Value_e;          // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<Root>/Constant'

  boolean_T ARMPWM_Value;              // Computed Parameter: ARMPWM_Value
                                          //  Referenced by: '<Root>/ARM PWM'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<Root>/failsafe'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_manual_control_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_manual_control_T manual_control_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_manual_control_T manual_control_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_manual_control_T manual_control_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void manual_control_initialize(void);
  extern void manual_control_step(void);
  extern void manual_control_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_manual_control_T *const manual_control_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S10>/NOT' : Unused code path elimination
//  Block '<S12>/NOT' : Unused code path elimination
//  Block '<S4>/NOT' : Unused code path elimination
//  Block '<S15>/NOT' : Unused code path elimination
//  Block '<S2>/Data Type Conversion7' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'manual_control'
//  '<S1>'   : 'manual_control/Accelerometer'
//  '<S2>'   : 'manual_control/Acquisition'
//  '<S3>'   : 'manual_control/Gyroscope'
//  '<S4>'   : 'manual_control/PX4 uORB Read'
//  '<S5>'   : 'manual_control/Vehicle Attitude'
//  '<S6>'   : 'manual_control/input1'
//  '<S7>'   : 'manual_control/input2'
//  '<S8>'   : 'manual_control/input3'
//  '<S9>'   : 'manual_control/input4'
//  '<S10>'  : 'manual_control/Accelerometer/PX4 uORB Read'
//  '<S11>'  : 'manual_control/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S12>'  : 'manual_control/Gyroscope/PX4 uORB Read'
//  '<S13>'  : 'manual_control/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S14>'  : 'manual_control/PX4 uORB Read/Enabled Subsystem'
//  '<S15>'  : 'manual_control/Vehicle Attitude/PX4 uORB Read'
//  '<S16>'  : 'manual_control/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_manual_control_h_

//
// File trailer for generated code.
//
// [EOF]
//
