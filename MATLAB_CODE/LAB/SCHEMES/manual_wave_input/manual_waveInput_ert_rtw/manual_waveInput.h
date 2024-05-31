//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_waveInput.h
//
// Code generated for Simulink model 'manual_waveInput'.
//
// Model version                  : 1.76
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr 16 17:55:13 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_manual_waveInput_h_
#define RTW_HEADER_manual_waveInput_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_uORB_Read.h"
#include "MW_PX4_PWM.h"
#include "manual_waveInput_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
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

// Block states (default storage) for system '<Root>/reverse RPY'
struct DW_reverseRPY_manual_waveInpu_T {
  int32_T sfEvent;                     // '<Root>/reverse RPY'
  uint8_T is_active_c9_manual_waveInput;// '<Root>/reverse RPY'
  boolean_T doneDoubleBufferReInit;    // '<Root>/reverse RPY'
};

// Block signals (default storage)
struct B_manual_waveInput_T {
  real_T At1[36];
  real_T Pt[36];
  real_T At1_m[36];
  real_T At1_c[36];
  px4_Bus_vehicle_odometry In1;        // '<S74>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T Lk[18];
  real_T B[18];
  real_T A_tmp[18];
  px4_Bus_actuator_outputs In1_l;      // '<S36>/In1'
  px4_Bus_actuator_outputs b_varargout_2_k;
  real_T A[9];
  px4_Bus_sensor_accel b_varargout_2_c;
  px4_Bus_sensor_gyro In1_m;           // '<S29>/In1'
  px4_Bus_sensor_accel In1_lx;         // '<S25>/In1'
  px4_Bus_sensor_gyro b_varargout_2_b;
  px4_Bus_sensor_mag In1_o;            // '<S31>/In1'
  px4_Bus_sensor_mag b_varargout_2_p;
  real_T TmpSignalConversionAtSFunct[6];// '<Root>/MATLAB Function'
  real_T xt[6];
  real_T dv[6];
  real_T DataTypeConversion4[3];       // '<S4>/Data Type Conversion4'
  real_T DataTypeConversion2[3];       // '<S4>/Data Type Conversion2'
  real_T DataTypeConversion1[3];       // '<S4>/Data Type Conversion1'
  real_T ManualSwitch1[25];            // '<Root>/Manual Switch1'
  real_T TmpSignalConversionAt_asyncqueu[26];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T TmpSignalConversionAtTAQSigLogg[6];
  // '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_From31_at_outport_0Inport1' 
  real_T RPY_meas[3];
  real_T RPY_meas_c[3];
  int8_T A_tmp_f[18];
  uint16_T pwmValue[8];
  real32_T VectorConcatenate_h[3];     // '<S49>/Vector Concatenate'
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T Gain;                         // '<S15>/Gain'
  real_T Gain_m;                       // '<S17>/Gain'
  real_T Gain_h;                       // '<S19>/Gain'
  real_T RPY[3];                       // '<Root>/reverse RPY1'
  real_T RPY_a[3];                     // '<Root>/reverse RPY'
  real_T method_ps;                    // '<Root>/RPY_computation'
  real_T y1_k;                         // '<Root>/MATLAB Function1'
  real_T y2_n;                         // '<Root>/MATLAB Function1'
  real_T y3_h;                         // '<Root>/MATLAB Function1'
  real_T y1_p;                         // '<Root>/MATLAB Function'
  real_T y2_n5;                        // '<Root>/MATLAB Function'
  real_T y3_j;                         // '<Root>/MATLAB Function'
  real_T y4_d;                         // '<Root>/MATLAB Function'
  real_T y5_c;                         // '<Root>/MATLAB Function'
  real_T y6_l;                         // '<Root>/MATLAB Function'
  real_T RPY_rate[3];                  // '<S2>/xk_dot_computation'
  real_T xk[6];                        // '<S2>/EKF'
  real_T t_integr1;                    // '<S2>/EKF'
  real_T t_meas1_d;                    // '<S2>/EKF'
  real_T sph;
  real_T cph;
  real_T cth;
  real_T sth;
  real_T tth;
  real_T At1_tmp;
  real_T d;
  real_T d1;
  real_T At1_tmp_g;
  real_T At1_tmp_g1;
  int8_T xt_tmp[6];
  int8_T xt_tmp_m[6];
  real32_T y;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T z;     // '<S1>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T rollspeed;
                 // '<S21>/SigConversion_InsertedFor_Bus Selector_at_outport_0'
  real32_T yawspeed;
                 // '<S21>/SigConversion_InsertedFor_Bus Selector_at_outport_2'
  real32_T pitchspeed;
                 // '<S21>/SigConversion_InsertedFor_Bus Selector_at_outport_1'
  real32_T VectorConcatenate[3];       // '<S41>/Vector Concatenate'
  real32_T DataTypeConversion1_e[3];   // '<Root>/Data Type Conversion1'
  real32_T TmpSignalConversionAtTAQSigLo_d[6];
  // '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux5_at_outport_0Inport1' 
  real32_T Gain_o[3];                  // '<Root>/Gain'
  real32_T Gain1[3];                   // '<Root>/Gain1'
  real32_T TmpSignalConversionAtTAQSigLo_n[6];
  // '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux3_at_outport_0Inport1' 
  real32_T Gain_g;                     // '<S16>/Gain'
  real32_T Gain_e;                     // '<S18>/Gain'
  real32_T Gain_i;                     // '<S20>/Gain'
  real32_T SignalConversion[2];        // '<S9>/Signal Conversion'
  real32_T fcn3;                       // '<S11>/fcn3'
  real32_T fcn3_h;                     // '<S10>/fcn3'
  real32_T rtb_fcn2_o_tmp;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T i;
};

// Block states (default storage) for system '<Root>'
struct DW_manual_waveInput_T {
  px4_internal_block_Subscriber_T obj; // '<S73>/SourceBlock'
  px4_internal_block_Subscriber_T obj_m;// '<S33>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S30>/SourceBlock'
  px4_internal_block_Subscriber_T obj_o;// '<S28>/SourceBlock'
  px4_internal_block_Subscriber_T obj_a;// '<S24>/SourceBlock'
  px4_internal_block_PWM_manual_T obj_l;// '<S9>/PX4 PWM Output'
  real_T Delay2_DSTATE[3];             // '<S2>/Delay2'
  real_T Memory2_PreviousInput[36];    // '<S2>/Memory2'
  real_T Memory4_PreviousInput[6];     // '<S2>/Memory4'
  real_T Memory3_PreviousInput[6];     // '<S2>/Memory3'
  real_T Memory1_PreviousInput;        // '<S2>/Memory1'
  real_T Memory_PreviousInput;         // '<S2>/Memory'
  real_T lastSin;                      // '<Root>/Sine Wave'
  real_T lastCos;                      // '<Root>/Sine Wave'
  real_T lastSin_c;                    // '<Root>/Sine Wave1'
  real_T lastCos_e;                    // '<Root>/Sine Wave1'
  real_T lastSin_f;                    // '<Root>/Sine Wave2'
  real_T lastCos_b;                    // '<Root>/Sine Wave2'
  real_T lastSin_m;                    // '<Root>/Sine Wave3'
  real_T lastCos_k;                    // '<Root>/Sine Wave3'
  real_T Memory5_PreviousInput;        // '<S2>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S2>/Memory6'
  struct {
    void *LoggedData[2];
  } Scope6_PWORK;                      // '<Root>/Scope6'

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } biasw_b_PWORK;                     // '<Root>/bias w_b'

  struct {
    void *LoggedData;
  } biasw_b1_PWORK;                    // '<Root>/bias w_b1'

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      // '<Root>/Scope9'

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     // '<Root>/Scope10'

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      // '<Root>/Scope8'

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      // '<Root>/Scope3'

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
    void *LoggedData[2];
  } PHIrate_PWORK;                     // '<Root>/PHI rate'

  struct {
    void *LoggedData[2];
  } PHIrate1_PWORK;                    // '<Root>/PHI rate1'

  struct {
    void *LoggedData[2];
  } PSIrate_PWORK;                     // '<Root>/PSI rate'

  struct {
    void *LoggedData[2];
  } PSIrate1_PWORK;                    // '<Root>/PSI rate1'

  struct {
    void *LoggedData[2];
  } THETArate_PWORK;                   // '<Root>/THETA rate'

  struct {
    void *LoggedData[2];
  } THETArate1_PWORK;                  // '<Root>/THETA rate1'

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      // '<Root>/Scope4'

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      // '<Root>/Scope5'

  struct {
    void *LoggedData;
  } Scope_PWORK;                       // '<S2>/Scope'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<S2>/Scope1'

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    // '<Root>/Scope1'

  struct {
    void *LoggedData;
  } Scope13_PWORK;                     // '<Root>/Scope13'

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     // '<S9>/Scope'

  int32_T systemEnable;                // '<Root>/Sine Wave'
  int32_T systemEnable_o;              // '<Root>/Sine Wave1'
  int32_T systemEnable_o1;             // '<Root>/Sine Wave2'
  int32_T systemEnable_j;              // '<Root>/Sine Wave3'
  int8_T EnabledSubsystem_SubsysRanBC; // '<S73>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S67>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S67>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S67>/If Action Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_b;// '<S59>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_n;// '<S59>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_p;// '<S59>/If Action Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_k;// '<S51>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanB_f;// '<S51>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_j;// '<S51>/If Action Subsystem'
  int8_T IfActionSubsystem2_SubsysRanB_a;// '<S43>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRan_nq;// '<S43>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC_l;// '<S43>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S33>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_n;// '<S30>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_f;// '<S28>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S24>/Enabled Subsystem'
  uint8_T is_active_c4_manual_waveInput;// '<Root>/RPY_computation'
  uint8_T is_active_c3_manual_waveInput;// '<S32>/MATLAB Function'
  uint8_T is_active_c8_manual_waveInput;// '<Root>/MATLAB Function3'
  uint8_T is_active_c1_manual_waveInput;// '<Root>/MATLAB Function1'
  uint8_T is_active_c2_manual_waveInput;// '<Root>/MATLAB Function'
  uint8_T is_active_c6_manual_waveInput;// '<S2>/xk_dot_computation'
  uint8_T is_active_c5_manual_waveInput;// '<S2>/EKF'
  boolean_T doneDoubleBufferReInit;    // '<Root>/RPY_computation'
  boolean_T doneDoubleBufferReInit_d;  // '<S32>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_n;  // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_p;  // '<Root>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_c;  // '<Root>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_b;  // '<S2>/xk_dot_computation'
  boolean_T doneDoubleBufferReInit_j;  // '<S2>/EKF'
  DW_reverseRPY_manual_waveInpu_T sf_reverseRPY1;// '<Root>/reverse RPY1'
  DW_reverseRPY_manual_waveInpu_T sf_reverseRPY;// '<Root>/reverse RPY'
};

// Parameters (default storage)
struct P_manual_waveInput_T_ {
  real_T P0[36];                       // Variable: P0
                                          //  Referenced by: '<S2>/Constant3'

  real_T Q[36];                        // Variable: Q
                                          //  Referenced by: '<S2>/Constant4'

  real_T R[9];                         // Variable: R
                                          //  Referenced by: '<S2>/Constant5'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by: '<S2>/Constant'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S2>/Constant1'
                                          //    '<S2>/Constant6'

  real_T mf[3];                        // Variable: mf
                                          //  Referenced by: '<Root>/Constant2'

  real_T x0EKF[6];                     // Variable: x0EKF
                                          //  Referenced by: '<S2>/Constant2'

  real32_T Rbody_frd[9];               // Variable: Rbody_frd
                                          //  Referenced by:
                                          //    '<Root>/Gain'
                                          //    '<Root>/Gain1'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S74>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S73>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_b;  // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S36>/Out1'

  px4_Bus_actuator_outputs Constant_Value_a;// Computed Parameter: Constant_Value_a
                                               //  Referenced by: '<S33>/Constant'

  px4_Bus_sensor_accel Out1_Y0_d;      // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S25>/Out1'

  px4_Bus_sensor_accel Constant_Value_f;// Computed Parameter: Constant_Value_f
                                           //  Referenced by: '<S24>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_h;       // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S29>/Out1'

  px4_Bus_sensor_gyro Constant_Value_o;// Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S28>/Constant'

  px4_Bus_sensor_mag Out1_Y0_a;        // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S31>/Out1'

  px4_Bus_sensor_mag Constant_Value_m; // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S30>/Constant'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory2'

  real_T Memory4_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory4'

  real_T Memory3_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory3'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S2>/Delay2'

  real_T Memory1_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory1'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S2>/Memory'

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

  real_T Constant_Value_ah;            // Expression: 1000
                                          //  Referenced by: '<S37>/Constant'

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
                                          //  Referenced by: '<S38>/Constant'

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

  real_T Constant_Value_h;             // Expression: 1200
                                          //  Referenced by: '<S39>/Constant'

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
                                          //  Referenced by: '<S40>/Constant'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S2>/Memory6'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S15>/Gain'

  real_T Gain_Gain_o;                  // Expression: 180/pi
                                          //  Referenced by: '<S17>/Gain'

  real_T Gain_Gain_oi;                 // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain'

  real32_T Constant_Value_ft;          // Computed Parameter: Constant_Value_ft
                                          //  Referenced by: '<S44>/Constant'

  real32_T Constant_Value_p;           // Computed Parameter: Constant_Value_p
                                          //  Referenced by: '<S45>/Constant'

  real32_T Constant_Value_ha;          // Computed Parameter: Constant_Value_ha
                                          //  Referenced by: '<S52>/Constant'

  real32_T Constant_Value_oj;          // Computed Parameter: Constant_Value_oj
                                          //  Referenced by: '<S53>/Constant'

  real32_T Constant_Value_j;           // Computed Parameter: Constant_Value_j
                                          //  Referenced by: '<S60>/Constant'

  real32_T Constant_Value_i;           // Computed Parameter: Constant_Value_i
                                          //  Referenced by: '<S61>/Constant'

  real32_T Constant_Value_is;          // Computed Parameter: Constant_Value_is
                                          //  Referenced by: '<S68>/Constant'

  real32_T Constant_Value_pl;          // Computed Parameter: Constant_Value_pl
                                          //  Referenced by: '<S69>/Constant'

  real32_T Gain_Gain_j;                // Computed Parameter: Gain_Gain_j
                                          //  Referenced by: '<S16>/Gain'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S18>/Gain'

  real32_T Gain_Gain_oj;               // Computed Parameter: Gain_Gain_oj
                                          //  Referenced by: '<S20>/Gain'

  boolean_T Constant5_Value;           // Computed Parameter: Constant5_Value
                                          //  Referenced by: '<Root>/Constant5'

  boolean_T Constant_Value_e;          // Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<Root>/Constant'

  boolean_T ARMPWM_Value;              // Computed Parameter: ARMPWM_Value
                                          //  Referenced by: '<Root>/ARM PWM'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S9>/failsafe'

  uint8_T ManualSwitch1_CurrentSetting;
                             // Computed Parameter: ManualSwitch1_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch1'

  uint8_T startingswitch_CurrentSetting;
                            // Computed Parameter: startingswitch_CurrentSetting
                               //  Referenced by: '<Root>/starting switch'

};

// Real-time Model Data Structure
struct tag_RTM_manual_waveInput_T {
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

  extern P_manual_waveInput_T manual_waveInput_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_manual_waveInput_T manual_waveInput_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_manual_waveInput_T manual_waveInput_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void manual_waveInput_initialize(void);
  extern void manual_waveInput_step(void);
  extern void manual_waveInput_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_manual_waveInput_T *const manual_waveInput_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S24>/NOT' : Unused code path elimination
//  Block '<S28>/NOT' : Unused code path elimination
//  Block '<S30>/NOT' : Unused code path elimination
//  Block '<S33>/NOT' : Unused code path elimination
//  Block '<S73>/NOT' : Unused code path elimination
//  Block '<S32>/Data Type Conversion6' : Eliminate redundant data type conversion


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
//  '<Root>' : 'manual_waveInput'
//  '<S1>'   : 'manual_waveInput/Accelerometer'
//  '<S2>'   : 'manual_waveInput/EKF'
//  '<S3>'   : 'manual_waveInput/Gyroscope'
//  '<S4>'   : 'manual_waveInput/IMU_measurements'
//  '<S5>'   : 'manual_waveInput/MATLAB Function'
//  '<S6>'   : 'manual_waveInput/MATLAB Function1'
//  '<S7>'   : 'manual_waveInput/MATLAB Function3'
//  '<S8>'   : 'manual_waveInput/Magnetometer'
//  '<S9>'   : 'manual_waveInput/PX4'
//  '<S10>'  : 'manual_waveInput/Quaternions to Rotation Angles1'
//  '<S11>'  : 'manual_waveInput/Quaternions to Rotation Angles2'
//  '<S12>'  : 'manual_waveInput/Quaternions to Rotation Angles3'
//  '<S13>'  : 'manual_waveInput/Quaternions to Rotation Angles4'
//  '<S14>'  : 'manual_waveInput/RPY_computation'
//  '<S15>'  : 'manual_waveInput/Radians to Degrees'
//  '<S16>'  : 'manual_waveInput/Radians to Degrees1'
//  '<S17>'  : 'manual_waveInput/Radians to Degrees2'
//  '<S18>'  : 'manual_waveInput/Radians to Degrees3'
//  '<S19>'  : 'manual_waveInput/Radians to Degrees4'
//  '<S20>'  : 'manual_waveInput/Radians to Degrees5'
//  '<S21>'  : 'manual_waveInput/Vehicle Attitude'
//  '<S22>'  : 'manual_waveInput/reverse RPY'
//  '<S23>'  : 'manual_waveInput/reverse RPY1'
//  '<S24>'  : 'manual_waveInput/Accelerometer/PX4 uORB Read'
//  '<S25>'  : 'manual_waveInput/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S26>'  : 'manual_waveInput/EKF/EKF'
//  '<S27>'  : 'manual_waveInput/EKF/xk_dot_computation'
//  '<S28>'  : 'manual_waveInput/Gyroscope/PX4 uORB Read'
//  '<S29>'  : 'manual_waveInput/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S30>'  : 'manual_waveInput/Magnetometer/PX4 uORB Read'
//  '<S31>'  : 'manual_waveInput/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S32>'  : 'manual_waveInput/PX4/Acquisition'
//  '<S33>'  : 'manual_waveInput/PX4/PX4 uORB Read'
//  '<S34>'  : 'manual_waveInput/PX4/Subsystem1'
//  '<S35>'  : 'manual_waveInput/PX4/Acquisition/MATLAB Function'
//  '<S36>'  : 'manual_waveInput/PX4/PX4 uORB Read/Enabled Subsystem'
//  '<S37>'  : 'manual_waveInput/PX4/Subsystem1/input1'
//  '<S38>'  : 'manual_waveInput/PX4/Subsystem1/input2'
//  '<S39>'  : 'manual_waveInput/PX4/Subsystem1/input3'
//  '<S40>'  : 'manual_waveInput/PX4/Subsystem1/input4'
//  '<S41>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Angle Calculation'
//  '<S42>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Quaternion Normalize'
//  '<S43>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input'
//  '<S44>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S45>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S46>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S47>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus'
//  '<S48>'  : 'manual_waveInput/Quaternions to Rotation Angles1/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S49>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Angle Calculation'
//  '<S50>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Quaternion Normalize'
//  '<S51>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input'
//  '<S52>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S53>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S54>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S55>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus'
//  '<S56>'  : 'manual_waveInput/Quaternions to Rotation Angles2/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S57>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Angle Calculation'
//  '<S58>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Quaternion Normalize'
//  '<S59>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Angle Calculation/Protect asincos input'
//  '<S60>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S61>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S62>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S63>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Quaternion Normalize/Quaternion Modulus'
//  '<S64>'  : 'manual_waveInput/Quaternions to Rotation Angles3/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S65>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Angle Calculation'
//  '<S66>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Quaternion Normalize'
//  '<S67>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Angle Calculation/Protect asincos input'
//  '<S68>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S69>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S70>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S71>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Quaternion Normalize/Quaternion Modulus'
//  '<S72>'  : 'manual_waveInput/Quaternions to Rotation Angles4/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S73>'  : 'manual_waveInput/Vehicle Attitude/PX4 uORB Read'
//  '<S74>'  : 'manual_waveInput/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_manual_waveInput_h_

//
// File trailer for generated code.
//
// [EOF]
//
