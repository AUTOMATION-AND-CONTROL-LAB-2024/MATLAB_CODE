//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_3dof.h
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
#ifndef RTW_HEADER_controller_3dof_h_
#define RTW_HEADER_controller_3dof_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_PWM.h"
#include "controller_3dof_types.h"
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/sensor_mag.h>

extern "C"
{

#include "rtGetNaN.h"

}

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

// Block signals for system '<S27>/SourceBlock'
struct B_SourceBlock_controller_3dof_T {
  px4_Bus_actuator_outputs SourceBlock_o2;// '<S27>/SourceBlock'
  boolean_T SourceBlock_o1;            // '<S27>/SourceBlock'
};

// Block states (default storage) for system '<S27>/SourceBlock'
struct DW_SourceBlock_controller_3do_T {
  px4_internal_block_Subscriber_T obj; // '<S27>/SourceBlock'
  boolean_T objisempty;                // '<S27>/SourceBlock'
};

// Block signals (default storage)
struct B_controller_3dof_T {
  real_T At1[36];
  real_T Pt[36];
  real_T At1_m[36];
  real_T At1_c[36];
  px4_Bus_vehicle_odometry In1;        // '<S53>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T Lk[18];
  real_T B[18];
  real_T A_tmp[18];
  real_T Mtau_u[12];
  real_T x_tmp[12];
  px4_Bus_actuator_outputs In1_l;      // '<S35>/In1'
  px4_Bus_actuator_outputs In1_m;      // '<S30>/In1'
  real_T A[9];
  real_T b_x[9];
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro b_varargout_2_c;
  px4_Bus_sensor_mag In1_o;            // '<S25>/In1'
  px4_Bus_sensor_gyro In1_mv;          // '<S23>/In1'
  px4_Bus_sensor_accel In1_lx;         // '<S19>/In1'
  px4_Bus_sensor_mag b_varargout_2_b;
  real_T xt[6];
  real_T xt_tmp[6];
  real_T dv[6];
  real_T un[4];
  real_T Gain[3];                      // '<S5>/Gain'
  real_T Gain2[3];                     // '<S5>/Gain2'
  real_T Sum5[3];                      // '<S2>/Sum5'
  real_T Gain1[3];                     // '<S5>/Gain1'
  real_T ManualSwitch1[25];            // '<Root>/Manual Switch1'
  real_T TmpSignalConversionAt_asyncqueu[26];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1' 
  real_T Product[3];                   // '<S2>/Product'
  real_T RPY[3];                       // '<Root>/reverse RPY'
  real_T u[4];                         // '<Root>/allocation_logic'
  real_T tau_allocated[3];             // '<Root>/allocation_logic'
  real_T RPY_meas[3];
  real_T RPY_meas_p[3];
  int8_T A_tmp_c[18];
  uint16_T pwmValue[8];
  real_T DigitalClock;                 // '<Root>/Digital Clock'
  real_T method_ps;                    // '<Root>/RPY_computation'
  real_T y1_k;                         // '<Root>/MATLAB Function1'
  real_T y2_n;                         // '<Root>/MATLAB Function1'
  real_T y3_h;                         // '<Root>/MATLAB Function1'
  real_T y1_pr;                        // '<Root>/MATLAB Function'
  real_T y2_n5;                        // '<Root>/MATLAB Function'
  real_T y3_j;                         // '<Root>/MATLAB Function'
  real_T y4_d;                         // '<Root>/MATLAB Function'
  real_T y5_c;                         // '<Root>/MATLAB Function'
  real_T y6_l;                         // '<Root>/MATLAB Function'
  real_T xk[6];                        // '<S3>/EKF'
  real_T t_integr1;                    // '<S3>/EKF'
  real_T t_meas1_d;                    // '<S3>/EKF'
  real_T sph;
  real_T cph;
  real_T sth;
  real_T cth;
  real_T tth;
  real_T At1_tmp;
  real_T d;
  real_T d1;
  real_T At1_tmp_f;
  real_T At1_tmp_g;
  real_T x;
  real32_T SignalConversion[2];        // '<S10>/Signal Conversion'
  real32_T SignalConversion_g[2];      // '<Root>/Signal Conversion'
  int8_T xt_tmp_g[6];
  int8_T xt_tmp_m[6];
  real32_T z;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T y;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T Gain_i[3];                  // '<Root>/Gain'
  real32_T Gain1_n[3];                 // '<Root>/Gain1'
  real32_T TmpSignalConversionAtGain2Inpor[6];
                                   // '<S2>/TmpSignal ConversionAtGain2Inport1'
  real32_T fcn3;                       // '<S12>/fcn3'
  real32_T rtb_Product3_l_tmp;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  int32_T Lk_tmp;
  B_SourceBlock_controller_3dof_T SourceBlock_h;// '<S27>/SourceBlock'
  B_SourceBlock_controller_3dof_T SourceBlock_k;// '<S27>/SourceBlock'
};

// Block states (default storage) for system '<Root>'
struct DW_controller_3dof_T {
  px4_internal_block_Subscriber_T obj; // '<S52>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S24>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S22>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S18>/SourceBlock'
  px4_internal_block_PWM_contro_T obj_dh;// '<S10>/PX4 PWM Output'
  real_T Delay2_DSTATE[3];             // '<S3>/Delay2'
  real_T DiscreteTimeIntegrator_DSTATE[3];// '<S2>/Discrete-Time Integrator'
  real_T Memory2_PreviousInput[36];    // '<S3>/Memory2'
  real_T Memory4_PreviousInput[6];     // '<S3>/Memory4'
  real_T Memory3_PreviousInput[6];     // '<S3>/Memory3'
  real_T Memory1_PreviousInput;        // '<S3>/Memory1'
  real_T Memory_PreviousInput;         // '<S3>/Memory'
  real_T Memory5_PreviousInput;        // '<S3>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S3>/Memory6'
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } biasw_b_PWORK;                     // '<Root>/bias w_b'

  struct {
    void *LoggedData;
  } PWM_PWORK;                         // '<Root>/PWM'

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      // '<Root>/Scope9'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Tau_PWORK;                         // '<Root>/Tau'

  struct {
    void *LoggedData;
  } Angle_meas_PWORK;                  // '<S2>/Angle_meas'

  struct {
    void *LoggedData;
  } error_PWORK;                       // '<S2>/error'

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     // '<Root>/Scope10'

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      // '<Root>/Scope8'

  struct {
    void *LoggedData[2];
  } PHIangle_PWORK;                    // '<Root>/PHI angle'

  struct {
    void *LoggedData[3];
  } PSIangle_PWORK;                    // '<Root>/PSI angle'

  struct {
    void *LoggedData[2];
  } THETAangle_PWORK;                  // '<Root>/THETA angle'

  struct {
    void *LoggedData;
  } PHIrate_PWORK;                     // '<Root>/PHI rate'

  struct {
    void *LoggedData;
  } PSIrate_PWORK;                     // '<Root>/PSI rate'

  struct {
    void *LoggedData;
  } THETArate_PWORK;                   // '<Root>/THETA rate'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S3>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<S3>/Scope1'

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     // '<Root>/Scope13'

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     // '<S10>/Scope'

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     // '<Root>/Scope'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S52>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S46>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S46>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S46>/If Action Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_c;// '<S38>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_m;// '<S38>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_g;// '<S38>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S11>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S27>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S24>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_fn;// '<S22>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S18>/Enabled Subsystem'
  uint8_T is_active_c9_controller_3dof;// '<Root>/reverse RPY'
  uint8_T is_active_c7_controller_3dof;// '<Root>/allocation_logic'
  uint8_T is_active_c4_controller_3dof;// '<Root>/RPY_computation'
  uint8_T is_active_c8_controller_3dof;// '<S26>/MATLAB Function'
  uint8_T is_active_c3_controller_3dof;// '<Root>/MATLAB Function2'
  uint8_T is_active_c1_controller_3dof;// '<Root>/MATLAB Function1'
  uint8_T is_active_c2_controller_3dof;// '<Root>/MATLAB Function'
  uint8_T is_active_c6_controller_3dof;// '<S3>/xk_dot_computation'
  uint8_T is_active_c5_controller_3dof;// '<S3>/EKF'
  boolean_T doneDoubleBufferReInit;    // '<Root>/reverse RPY'
  boolean_T doneDoubleBufferReInit_a;  // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_ap; // '<Root>/RPY_computation'
  boolean_T doneDoubleBufferReInit_d;  // '<S26>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_i;  // '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_p;  // '<Root>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_c;  // '<Root>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_b;  // '<S3>/xk_dot_computation'
  boolean_T doneDoubleBufferReInit_j;  // '<S3>/EKF'
  DW_SourceBlock_controller_3do_T SourceBlock_h;// '<S27>/SourceBlock'
  DW_SourceBlock_controller_3do_T SourceBlock_k;// '<S27>/SourceBlock'
};

// Parameters (default storage)
struct P_controller_3dof_T_ {
  real_T Kv[9];                        // Variable: Kv
                                          //  Referenced by: '<S2>/Gain3'

  real_T P0[36];                       // Variable: P0
                                          //  Referenced by: '<S3>/Constant3'

  real_T Q[36];                        // Variable: Q
                                          //  Referenced by: '<S3>/Constant4'

  real_T R[9];                         // Variable: R
                                          //  Referenced by: '<S3>/Constant5'

  real_T Rbody_ned[9];                 // Variable: Rbody_ned
                                          //  Referenced by: '<S5>/Gain2'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by: '<S3>/Constant'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S3>/Constant1'
                                          //    '<S3>/Constant6'

  real_T mf[3];                        // Variable: mf
                                          //  Referenced by: '<Root>/Constant2'

  real_T param[7];                     // Variable: param
                                          //  Referenced by: '<Root>/Constant1'

  real_T x0EKF[6];                     // Variable: x0EKF
                                          //  Referenced by: '<S3>/Constant2'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S53>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S52>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_i;  // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S30>/Out1'

  px4_Bus_actuator_outputs Out1_Y0_b;  // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S35>/Out1'

  px4_Bus_actuator_outputs Constant_Value_o;// Computed Parameter: Constant_Value_o
                                               //  Referenced by: '<S27>/Constant'

  px4_Bus_actuator_outputs Constant_Value_a;// Computed Parameter: Constant_Value_a
                                               //  Referenced by: '<S11>/Constant'

  px4_Bus_sensor_accel Out1_Y0_d;      // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_sensor_accel Constant_Value_f;// Computed Parameter: Constant_Value_f
                                           //  Referenced by: '<S18>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_h;       // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S23>/Out1'

  px4_Bus_sensor_gyro Constant_Value_ou;// Computed Parameter: Constant_Value_ou
                                           //  Referenced by: '<S22>/Constant'

  px4_Bus_sensor_mag Out1_Y0_a;        // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S25>/Out1'

  px4_Bus_sensor_mag Constant_Value_m; // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S24>/Constant'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory2'

  real_T Memory4_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory4'

  real_T Memory3_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory3'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S3>/Delay2'

  real_T Gain_Gain[9];                 // Expression: Rbody_frd
                                          //  Referenced by: '<S5>/Gain'

  real_T Memory1_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S3>/Memory'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S2>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                          //  Referenced by: '<S2>/Discrete-Time Integrator'

  real_T Constant3_Value;              // Expression: 10
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_l;             // Expression: 1500
                                          //  Referenced by: '<S31>/Constant'

  real_T Constant_Value_h;             // Expression: 1700
                                          //  Referenced by: '<S32>/Constant'

  real_T Constant_Value_g;             // Expression: 1000
                                          //  Referenced by: '<S33>/Constant'

  real_T Constant_Value_c;             // Expression: 1700
                                          //  Referenced by: '<S34>/Constant'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory5'

  real_T Gain1_Gain[9];                // Expression: Rbody_frd
                                          //  Referenced by: '<S5>/Gain1'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S3>/Memory6'

  real_T RPYangle_ref_Time;            // Expression: 0
                                          //  Referenced by: '<Root>/RPY angle_ref'

  real_T RPYangle_ref_Y0;              // Expression: 0
                                          //  Referenced by: '<Root>/RPY angle_ref'

  real_T RPYangle_ref_YFinal[3];       // Expression: zeros(3,1)
                                          //  Referenced by: '<Root>/RPY angle_ref'

  real32_T Constant_Value_ck;          // Computed Parameter: Constant_Value_ck
                                          //  Referenced by: '<S39>/Constant'

  real32_T Constant_Value_aa;          // Computed Parameter: Constant_Value_aa
                                          //  Referenced by: '<S40>/Constant'

  real32_T Constant_Value_h0;          // Computed Parameter: Constant_Value_h0
                                          //  Referenced by: '<S47>/Constant'

  real32_T Constant_Value_n;           // Computed Parameter: Constant_Value_n
                                          //  Referenced by: '<S48>/Constant'

  real32_T Gain_Gain_e[9];             // Expression: Rbody_frd
                                          //  Referenced by: '<Root>/Gain'

  real32_T Gain1_Gain_c[9];            // Expression: Rbody_frd
                                          //  Referenced by: '<Root>/Gain1'

  real32_T Gain2_Gain[18];             // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S2>/Gain2'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  boolean_T Constant_Value_e;          // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<Root>/Constant'

  boolean_T ARMPWM_Value;              // Computed Parameter: ARMPWM_Value
                                          //  Referenced by: '<Root>/ARM PWM'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S10>/failsafe'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_controller_3dof_T {
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

  extern P_controller_3dof_T controller_3dof_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controller_3dof_T controller_3dof_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controller_3dof_T controller_3dof_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_3dof_initialize(void);
  extern void controller_3dof_step(void);
  extern void controller_3dof_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controller_3dof_T *const controller_3dof_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S18>/NOT' : Unused code path elimination
//  Block '<S22>/NOT' : Unused code path elimination
//  Block '<S24>/NOT' : Unused code path elimination
//  Block '<S27>/NOT' : Unused code path elimination
//  Block '<S11>/NOT' : Unused code path elimination
//  Block '<S52>/NOT' : Unused code path elimination
//  Block '<S26>/Data Type Conversion6' : Eliminate redundant data type conversion


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
//  '<Root>' : 'controller_3dof'
//  '<S1>'   : 'controller_3dof/Accelerometer'
//  '<S2>'   : 'controller_3dof/Controller'
//  '<S3>'   : 'controller_3dof/EKF'
//  '<S4>'   : 'controller_3dof/Gyroscope'
//  '<S5>'   : 'controller_3dof/IMU_measurements'
//  '<S6>'   : 'controller_3dof/MATLAB Function'
//  '<S7>'   : 'controller_3dof/MATLAB Function1'
//  '<S8>'   : 'controller_3dof/MATLAB Function2'
//  '<S9>'   : 'controller_3dof/Magnetometer'
//  '<S10>'  : 'controller_3dof/PX4'
//  '<S11>'  : 'controller_3dof/PX4 uORB Read'
//  '<S12>'  : 'controller_3dof/Quaternions to Rotation Angles1'
//  '<S13>'  : 'controller_3dof/Quaternions to Rotation Angles2'
//  '<S14>'  : 'controller_3dof/RPY_computation'
//  '<S15>'  : 'controller_3dof/Vehicle Attitude'
//  '<S16>'  : 'controller_3dof/allocation_logic'
//  '<S17>'  : 'controller_3dof/reverse RPY'
//  '<S18>'  : 'controller_3dof/Accelerometer/PX4 uORB Read'
//  '<S19>'  : 'controller_3dof/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S20>'  : 'controller_3dof/EKF/EKF'
//  '<S21>'  : 'controller_3dof/EKF/xk_dot_computation'
//  '<S22>'  : 'controller_3dof/Gyroscope/PX4 uORB Read'
//  '<S23>'  : 'controller_3dof/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S24>'  : 'controller_3dof/Magnetometer/PX4 uORB Read'
//  '<S25>'  : 'controller_3dof/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S26>'  : 'controller_3dof/PX4/Acquisition'
//  '<S27>'  : 'controller_3dof/PX4/PX4 uORB Read'
//  '<S28>'  : 'controller_3dof/PX4/Subsystem1'
//  '<S29>'  : 'controller_3dof/PX4/Acquisition/MATLAB Function'
//  '<S30>'  : 'controller_3dof/PX4/PX4 uORB Read/Enabled Subsystem'
//  '<S31>'  : 'controller_3dof/PX4/Subsystem1/input1'
//  '<S32>'  : 'controller_3dof/PX4/Subsystem1/input2'
//  '<S33>'  : 'controller_3dof/PX4/Subsystem1/input3'
//  '<S34>'  : 'controller_3dof/PX4/Subsystem1/input4'
//  '<S35>'  : 'controller_3dof/PX4 uORB Read/Enabled Subsystem'
//  '<S36>'  : 'controller_3dof/Quaternions to Rotation Angles1/Angle Calculation'
//  '<S37>'  : 'controller_3dof/Quaternions to Rotation Angles1/Quaternion Normalize'
//  '<S38>'  : 'controller_3dof/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input'
//  '<S39>'  : 'controller_3dof/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S40>'  : 'controller_3dof/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S41>'  : 'controller_3dof/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S42>'  : 'controller_3dof/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus'
//  '<S43>'  : 'controller_3dof/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S44>'  : 'controller_3dof/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S45>'  : 'controller_3dof/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S46>'  : 'controller_3dof/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S47>'  : 'controller_3dof/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S48>'  : 'controller_3dof/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S49>'  : 'controller_3dof/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S50>'  : 'controller_3dof/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S51>'  : 'controller_3dof/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S52>'  : 'controller_3dof/Vehicle Attitude/PX4 uORB Read'
//  '<S53>'  : 'controller_3dof/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_controller_3dof_h_

//
// File trailer for generated code.
//
// [EOF]
//
