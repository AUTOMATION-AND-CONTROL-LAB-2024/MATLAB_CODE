//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test_RPY.h
//
// Code generated for Simulink model 'test_RPY'.
//
// Model version                  : 1.108
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri May 10 11:28:34 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_test_RPY_h_
#define RTW_HEADER_test_RPY_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_PWM.h"
#include "test_RPY_types.h"
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/sensor_mag.h>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetNaN.h"

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

// Block states (default storage) for system '<Root>/MATLAB Function1'
struct DW_MATLABFunction1_test_RPY_T {
  int32_T sfEvent;                     // '<Root>/MATLAB Function1'
  uint8_T is_active_c1_test_RPY;       // '<Root>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<Root>/MATLAB Function1'
};

// Block signals (default storage)
struct B_test_RPY_T {
  real_T dv[30];
  real_T ManualSwitch1[25];            // '<Root>/Manual Switch1'
  real_T TmpSignalConversionAt_asyncqueu[26];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  px4_Bus_actuator_outputs In1;        // '<S33>/In1'
  px4_Bus_actuator_outputs b_varargout_2;
  real_T dv1[9];
  px4_Bus_sensor_accel In1_l;          // '<S13>/In1'
  px4_Bus_sensor_accel b_varargout_2_c;
  px4_Bus_sensor_gyro b_varargout_2_k;
  px4_Bus_sensor_mag In1_o;            // '<S19>/In1'
  px4_Bus_sensor_gyro In1_m;           // '<S15>/In1'
  px4_Bus_sensor_mag b_varargout_2_cx;
  real_T dv2[6];
  real_T dv3[6];
  real_T dv4[6];
  real_T xt[5];
  real_T A[4];
  real_T IMU_mf_b_bias[3];             // '<Root>/Constant2'
  real_T DataTypeConversion3[3];       // '<S3>/Data Type Conversion3'
  real_T Gain1_b[3];                   // '<S10>/Gain1'
  real_T Gain[3];                      // '<Root>/Gain'
  real_T DataTypeConversion1[3];       // '<S3>/Data Type Conversion1'
  uint16_T pwmValue[8];
  real_T RP_meas[2];
  real_T RP_meas_b[2];
  int8_T A_tmp_p[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T y1;                           // '<S10>/MATLAB Function7'
  real_T y2;                           // '<S10>/MATLAB Function7'
  real_T y3;                           // '<S10>/MATLAB Function7'
  real_T y1_p;                         // '<S10>/MATLAB Function1'
  real_T y2_b;                         // '<S10>/MATLAB Function1'
  real_T y3_g;                         // '<S10>/MATLAB Function1'
  real_T bias_w_b_estim[3];            // '<S21>/MATLAB Function'
  real_T y1_k3;                        // '<Root>/MATLAB Function1'
  real_T y2_n;                         // '<Root>/MATLAB Function1'
  real_T y3_h;                         // '<Root>/MATLAB Function1'
  real_T y[3];                         // '<S3>/MATLAB Function1'
  real_T y_j[3];                       // '<S3>/MATLAB Function'
  real32_T y_o[3];                     // '<Root>/correct sequence'
  real_T numAccum;
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T Pt_c;
  real32_T z;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T y_n;   // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T SignalConversion[2];        // '<S8>/Signal Conversion'
  real32_T y1_ky;                      // '<Root>/MATLAB Function3'
  real32_T y2_k;                       // '<Root>/MATLAB Function3'
  real32_T y3_k;                       // '<Root>/MATLAB Function3'
};

// Block states (default storage) for system '<Root>'
struct DW_test_RPY_T {
  px4_internal_block_Subscriber_T obj; // '<S30>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S18>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S14>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S12>/SourceBlock'
  px4_internal_block_PWM_test_R_T obj_l;// '<S8>/PX4 PWM Output'
  real_T DiscreteTransferFcn_states;   // '<S25>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S25>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S25>/Discrete Transfer Fcn2'
  real_T Delay2_DSTATE[3];             // '<S21>/Delay2'
  real_T Delay2_DSTATE_l[3];           // '<S23>/Delay2'
  real_T lastSin;                      // '<Root>/Sine Wave'
  real_T lastCos;                      // '<Root>/Sine Wave'
  real_T lastSin_c;                    // '<Root>/Sine Wave1'
  real_T lastCos_e;                    // '<Root>/Sine Wave1'
  real_T lastSin_f;                    // '<Root>/Sine Wave2'
  real_T lastCos_b;                    // '<Root>/Sine Wave2'
  real_T lastSin_m;                    // '<Root>/Sine Wave3'
  real_T lastCos_k;                    // '<Root>/Sine Wave3'
  real_T Memory4_PreviousInput[5];     // '<S21>/Memory4'
  real_T Memory2_PreviousInput;        // '<S21>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S21>/Memory3'
  real_T Memory4_PreviousInput_l;      // '<S23>/Memory4'
  real_T Memory3_PreviousInput_i;      // '<S23>/Memory3'
  real_T Memory2_PreviousInput_n;      // '<S23>/Memory2'
  real_T Memory5_PreviousInput;        // '<S7>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S7>/Memory6'
  struct {
    void *LoggedData[2];
  } biasw_b_PWORK;                     // '<Root>/bias w_b'

  struct {
    void *LoggedData[3];
  } PHIangle_PWORK;                    // '<Root>/PHI angle'

  struct {
    void *LoggedData[4];
  } PSIangle_PWORK;                    // '<Root>/PSI angle'

  struct {
    void *LoggedData[3];
  } THETAangle_PWORK;                  // '<Root>/THETA angle'

  struct {
    void *LoggedData[2];
  } PHIrate_PWORK;                     // '<Root>/PHI rate'

  struct {
    void *LoggedData[2];
  } PSIrate_PWORK;                     // '<Root>/PSI rate'

  struct {
    void *LoggedData[2];
  } THETArate_PWORK;                   // '<Root>/THETA rate'

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     // '<Root>/Scope13'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S8>/Scope'

  int32_T systemEnable;                // '<Root>/Sine Wave'
  int32_T systemEnable_o;              // '<Root>/Sine Wave1'
  int32_T systemEnable_o1;             // '<Root>/Sine Wave2'
  int32_T systemEnable_j;              // '<Root>/Sine Wave3'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S40>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S40>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S40>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S30>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S18>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S14>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S12>/Enabled Subsystem'
  uint8_T is_active_c10_test_RPY;      // '<Root>/correct sequence'
  uint8_T is_active_c2_test_RPY;       // '<S10>/MATLAB Function2'
  uint8_T is_active_c3_test_RPY;       // '<S29>/MATLAB Function'
  uint8_T is_active_c19_test_RPY;      // '<S7>/Y_computation'
  uint8_T is_active_c18_test_RPY;      // '<S23>/EKF_Y'
  uint8_T is_active_c17_test_RPY;      // '<S7>/RP_computation'
  uint8_T is_active_c16_test_RPY;      // '<S21>/MATLAB Function'
  uint8_T is_active_c15_test_RPY;      // '<S21>/EKF_RP'
  uint8_T is_active_c14_test_RPY;      // '<S7>/RPY_dot_computation'
  uint8_T is_active_c8_test_RPY;       // '<Root>/MATLAB Function3'
  uint8_T is_active_c5_test_RPY;       // '<S3>/MATLAB Function1'
  uint8_T is_active_c4_test_RPY;       // '<S3>/MATLAB Function'
  boolean_T doneDoubleBufferReInit;    // '<Root>/correct sequence'
  boolean_T doneDoubleBufferReInit_i;  // '<S10>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_d;  // '<S29>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_it; // '<S7>/Y_computation'
  boolean_T doneDoubleBufferReInit_c;  // '<S23>/EKF_Y'
  boolean_T doneDoubleBufferReInit_f;  // '<S7>/RP_computation'
  boolean_T doneDoubleBufferReInit_ip; // '<S21>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_g;  // '<S21>/EKF_RP'
  boolean_T doneDoubleBufferReInit_h;  // '<S7>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_n;  // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_dd; // '<S3>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_o;  // '<S3>/MATLAB Function'
  DW_MATLABFunction1_test_RPY_T sf_MATLABFunction7;// '<S10>/MATLAB Function7'
  DW_MATLABFunction1_test_RPY_T sf_MATLABFunction1_e;// '<S10>/MATLAB Function1' 
  DW_MATLABFunction1_test_RPY_T sf_MATLABFunction1_f;// '<Root>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_test_RPY_T_ {
  real_T IMU_w_b_bias[3];              // Variable: IMU_w_b_bias
                                          //  Referenced by: '<Root>/Constant2'

  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S21>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S23>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S21>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S21>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S3>/Gain'
                                          //    '<S3>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S21>/EKF_RP'
                                          //    '<S23>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S7>/Constant6'
                                          //    '<S21>/EKF_RP'
                                          //    '<S23>/EKF_Y'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S23>/EKF_Y'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S23>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S21>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S23>/Memory4'

  px4_Bus_actuator_outputs Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S33>/Out1'

  px4_Bus_actuator_outputs Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S30>/Constant'

  px4_Bus_sensor_accel Out1_Y0_d;      // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S13>/Out1'

  px4_Bus_sensor_accel Constant_Value_f;// Computed Parameter: Constant_Value_f
                                           //  Referenced by: '<S12>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_h;       // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S15>/Out1'

  px4_Bus_sensor_gyro Constant_Value_o;// Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S14>/Constant'

  px4_Bus_sensor_mag Out1_Y0_a;        // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S19>/Out1'

  px4_Bus_sensor_mag Constant_Value_m; // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S18>/Constant'

  real_T Constant_Value_h;             // Expression: 1
                                          //  Referenced by: '<S41>/Constant'

  real_T Constant_Value_oj;            // Expression: 1
                                          //  Referenced by: '<S42>/Constant'

  real_T SineWave_Amp;                 // Expression: 0
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Bias;                // Expression: 0
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Freq;                // Expression: 1
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Hsin;                // Computed Parameter: SineWave_Hsin
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_HCos;                // Computed Parameter: SineWave_HCos
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PSin;                // Computed Parameter: SineWave_PSin
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PCos;                // Computed Parameter: SineWave_PCos
                                          //  Referenced by: '<Root>/Sine Wave'

  real_T Constant_Value_a;             // Expression: 1000
                                          //  Referenced by: '<S34>/Constant'

  real_T SineWave1_Amp;                // Expression: 0
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Bias;               // Expression: 0
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Freq;               // Expression: 1
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Hsin;               // Computed Parameter: SineWave1_Hsin
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_HCos;               // Computed Parameter: SineWave1_HCos
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_PSin;               // Computed Parameter: SineWave1_PSin
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_PCos;               // Computed Parameter: SineWave1_PCos
                                          //  Referenced by: '<Root>/Sine Wave1'

  real_T Constant_Value_c;             // Expression: 1000
                                          //  Referenced by: '<S35>/Constant'

  real_T SineWave2_Amp;                // Expression: 200
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_Bias;               // Expression: 300
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_Freq;               // Expression: 1
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_Hsin;               // Computed Parameter: SineWave2_Hsin
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_HCos;               // Computed Parameter: SineWave2_HCos
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_PSin;               // Computed Parameter: SineWave2_PSin
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T SineWave2_PCos;               // Computed Parameter: SineWave2_PCos
                                          //  Referenced by: '<Root>/Sine Wave2'

  real_T Constant_Value_h0;            // Expression: 1200
                                          //  Referenced by: '<S36>/Constant'

  real_T SineWave3_Amp;                // Expression: 200
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_Bias;               // Expression: 300
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_Freq;               // Expression: 1
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_Hsin;               // Computed Parameter: SineWave3_Hsin
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_HCos;               // Computed Parameter: SineWave3_HCos
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_PSin;               // Computed Parameter: SineWave3_PSin
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T SineWave3_PCos;               // Computed Parameter: SineWave3_PCos
                                          //  Referenced by: '<Root>/Sine Wave3'

  real_T Constant_Value_op;            // Expression: 1000
                                          //  Referenced by: '<S37>/Constant'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S21>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S21>/Memory2'

  real_T Delay2_InitialCondition_i;    // Expression: 0.0
                                          //  Referenced by: '<S23>/Delay2'

  real_T Memory2_InitialCondition_b;   // Expression: 0
                                          //  Referenced by: '<S23>/Memory2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S7>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S7>/Memory6'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S10>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S10>/Gain1'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<Root>/Gain'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<Root>/Gain1'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  boolean_T Constant_Value_e;          // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<Root>/Constant'

  boolean_T ARMPWM_Value;              // Computed Parameter: ARMPWM_Value
                                          //  Referenced by: '<Root>/ARM PWM'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S8>/failsafe'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T startingswitch_CurrentSetting;
                            // Computed Parameter: startingswitch_CurrentSetting
                               //  Referenced by: '<Root>/starting switch'

};

// Real-time Model Data Structure
struct tag_RTM_test_RPY_T {
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

  extern P_test_RPY_T test_RPY_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_test_RPY_T test_RPY_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_test_RPY_T test_RPY_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void test_RPY_initialize(void);
  extern void test_RPY_step(void);
  extern void test_RPY_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_test_RPY_T *const test_RPY_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S12>/NOT' : Unused code path elimination
//  Block '<S14>/NOT' : Unused code path elimination
//  Block '<S18>/NOT' : Unused code path elimination
//  Block '<S30>/NOT' : Unused code path elimination
//  Block '<S29>/Data Type Conversion6' : Eliminate redundant data type conversion


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
//  '<Root>' : 'test_RPY'
//  '<S1>'   : 'test_RPY/Accelerometer'
//  '<S2>'   : 'test_RPY/Gyroscope'
//  '<S3>'   : 'test_RPY/IMU measurements & rotation'
//  '<S4>'   : 'test_RPY/MATLAB Function1'
//  '<S5>'   : 'test_RPY/MATLAB Function3'
//  '<S6>'   : 'test_RPY/Magnetometer'
//  '<S7>'   : 'test_RPY/Observer'
//  '<S8>'   : 'test_RPY/PX4'
//  '<S9>'   : 'test_RPY/Quaternions to Rotation Angles2'
//  '<S10>'  : 'test_RPY/Subsystem'
//  '<S11>'  : 'test_RPY/correct sequence'
//  '<S12>'  : 'test_RPY/Accelerometer/PX4 uORB Read'
//  '<S13>'  : 'test_RPY/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S14>'  : 'test_RPY/Gyroscope/PX4 uORB Read'
//  '<S15>'  : 'test_RPY/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S16>'  : 'test_RPY/IMU measurements & rotation/MATLAB Function'
//  '<S17>'  : 'test_RPY/IMU measurements & rotation/MATLAB Function1'
//  '<S18>'  : 'test_RPY/Magnetometer/PX4 uORB Read'
//  '<S19>'  : 'test_RPY/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S20>'  : 'test_RPY/Observer/RPY_dot_computation'
//  '<S21>'  : 'test_RPY/Observer/RP_EKF'
//  '<S22>'  : 'test_RPY/Observer/RP_computation'
//  '<S23>'  : 'test_RPY/Observer/Y_EKF'
//  '<S24>'  : 'test_RPY/Observer/Y_computation'
//  '<S25>'  : 'test_RPY/Observer/acceleration filter'
//  '<S26>'  : 'test_RPY/Observer/RP_EKF/EKF_RP'
//  '<S27>'  : 'test_RPY/Observer/RP_EKF/MATLAB Function'
//  '<S28>'  : 'test_RPY/Observer/Y_EKF/EKF_Y'
//  '<S29>'  : 'test_RPY/PX4/AQUISITION'
//  '<S30>'  : 'test_RPY/PX4/PX4 uORB Read'
//  '<S31>'  : 'test_RPY/PX4/U + BIAS'
//  '<S32>'  : 'test_RPY/PX4/AQUISITION/MATLAB Function'
//  '<S33>'  : 'test_RPY/PX4/PX4 uORB Read/Enabled Subsystem'
//  '<S34>'  : 'test_RPY/PX4/U + BIAS/input1'
//  '<S35>'  : 'test_RPY/PX4/U + BIAS/input2'
//  '<S36>'  : 'test_RPY/PX4/U + BIAS/input3'
//  '<S37>'  : 'test_RPY/PX4/U + BIAS/input4'
//  '<S38>'  : 'test_RPY/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S39>'  : 'test_RPY/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S40>'  : 'test_RPY/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S41>'  : 'test_RPY/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S42>'  : 'test_RPY/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S43>'  : 'test_RPY/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S44>'  : 'test_RPY/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S45>'  : 'test_RPY/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S46>'  : 'test_RPY/Subsystem/MATLAB Function1'
//  '<S47>'  : 'test_RPY/Subsystem/MATLAB Function2'
//  '<S48>'  : 'test_RPY/Subsystem/MATLAB Function7'

#endif                                 // RTW_HEADER_test_RPY_h_

//
// File trailer for generated code.
//
// [EOF]
//
