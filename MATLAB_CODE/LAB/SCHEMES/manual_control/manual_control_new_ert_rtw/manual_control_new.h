//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_control_new.h
//
// Code generated for Simulink model 'manual_control_new'.
//
// Model version                  : 1.25
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 15:10:04 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_manual_control_new_h_
#define RTW_HEADER_manual_control_new_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "manual_control_new_types.h"
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

// Block states (default storage) for system '<S2>/MATLAB Function1'
struct DW_MATLABFunction1_manual_con_T {
  int32_T sfEvent;                     // '<S2>/MATLAB Function1'
  uint8_T is_active_c9_manual_control_new;// '<S2>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S2>/MATLAB Function1'
};

// Block signals (default storage)
struct B_manual_control_new_T {
  real_T TmpSignalConversionAtSFun_a[87];// '<S14>/MATLAB Function'
  real_T b_norm[58];
  px4_Bus_vehicle_odometry In1;        // '<S56>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  real_T dv1[9];
  px4_Bus_sensor_accel b_varargout_2_c;
  px4_Bus_sensor_gyro b_varargout_2_k;
  px4_Bus_sensor_mag In1_f;            // '<S46>/In1'
  px4_Bus_sensor_gyro In1_n;           // '<S44>/In1'
  px4_Bus_sensor_accel In1_i;          // '<S42>/In1'
  px4_Bus_sensor_mag b_varargout_2_cx;
  real_T dv2[6];
  real_T dv3[6];
  real_T dv4[6];
  real_T xt[5];
  real_T A[4];
  real_T Sum24[3];                     // '<S18>/Sum24'
  real_T ManualSwitch[25];             // '<Root>/Manual Switch'
  real_T TmpSignalConversionAt_asyncqueu[26];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To WorkspaceInport1' 
  real_T TmpSignalConversionAtTAQSigLogg[6];
  // '<S3>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_From5_at_outport_0Inport1' 
  real_T u_vect[3];
  real_T TmpSignalConversionAtSFunct[3];// '<S7>/RPY_dot_computation'
  real_T Gain2[3];                     // '<S8>/Gain2'
  real_T Gain_k[3];                    // '<S2>/Gain'
  uint16_T pwmValue[8];
  real_T temp[2];
  real_T temp_b[2];
  real32_T Gain1_d[3];                 // '<Root>/Gain1'
  int8_T A_tmp_p[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T DataTypeConversion;           // '<S3>/Data Type Conversion'
  real_T DataTypeConversion1;          // '<S3>/Data Type Conversion1'
  real_T DataTypeConversion2;          // '<S3>/Data Type Conversion2'
  real_T DataTypeConversion3;          // '<S3>/Data Type Conversion3'
  real_T DataTypeConversion4[15];      // '<S3>/Data Type Conversion4'
  real_T Sum23[3];                     // '<S18>/Sum23'
  real_T y1_e;                         // '<S8>/MATLAB Function7'
  real_T y2_k;                         // '<S8>/MATLAB Function7'
  real_T y3_o;                         // '<S8>/MATLAB Function7'
  real_T xk;                           // '<S19>/EKF_Y'
  real_T RP_estim[2];                  // '<S16>/MATLAB Function'
  real_T RPY_rate[3];                  // '<S7>/RPY_dot_computation'
  real_T y1_b;                         // '<S2>/MATLAB Function1'
  real_T y2_m;                         // '<S2>/MATLAB Function1'
  real_T y3_h;                         // '<S2>/MATLAB Function1'
  real_T y_g[3];                       // '<S5>/MATLAB Function1'
  real_T y_p[3];                       // '<S5>/MATLAB Function'
  real32_T y_k[3];                     // '<S4>/correct sequence'
  real_T numAccum;
  real_T numAccum_c;
  real_T numAccum_f;
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T a22;
  real_T xt_g;
  real_T u_vect_g;
  real_T Sum23_m;
  real_T Delay_DSTATE_k;
  real_T Delay1_DSTATE_f;
  real_T Delay2_DSTATE_b;
  real_T Delay3_DSTATE_f;
  real_T Delay4_DSTATE_l;
  real_T Delay5_DSTATE_d;
  real_T Delay6_DSTATE_c;
  real_T Delay7_DSTATE_p;
  real_T Delay8_DSTATE_g;
  real_T Delay9_DSTATE_a;
  real_T Delay10_DSTATE_e;
  real_T Delay11_DSTATE_b;
  real_T Delay12_DSTATE_i;
  real_T Delay13_DSTATE_d;
  real_T Delay14_DSTATE_d;
  real_T Delay15_DSTATE;
  real_T Delay20_DSTATE_k;
  real_T Delay21_DSTATE_l;
  real_T Delay22_DSTATE_m;
  real_T Delay23_DSTATE_f;
  real_T Delay24_DSTATE;
  real_T Delay25_DSTATE;
  real_T Delay26_DSTATE;
  real_T Delay27_DSTATE;
  real_T Delay16_DSTATE;
  real_T Delay17_DSTATE;
  real_T Delay18_DSTATE;
  real_T y_idx_0;
  real_T rtb_Delay_f_idx_0;
  real_T rtb_Delay1_a_idx_0;
  real_T rtb_Delay2_o_idx_0;
  real_T rtb_Delay3_a_idx_0;
  real_T rtb_Delay4_i_idx_0;
  real_T rtb_Delay5_n_idx_0;
  real_T rtb_Delay6_p_idx_0;
  real_T rtb_Delay7_n_idx_0;
  real_T rtb_Delay8_c_idx_0;
  real_T rtb_Delay9_e_idx_0;
  real_T rtb_Delay10_n_idx_0;
  real_T rtb_Delay11_g_idx_0;
  real_T rtb_Delay12_e_idx_0;
  real_T rtb_Delay13_e_idx_0;
  real_T rtb_Delay14_p_idx_0;
  real_T rtb_Delay15_idx_0;
  real_T rtb_Delay20_h_idx_0;
  real_T rtb_Delay21_b_idx_0;
  real_T rtb_Delay22_k_idx_0;
  real_T rtb_Delay23_g_idx_0;
  real_T rtb_Delay24_idx_0;
  real_T rtb_Delay25_idx_0;
  real_T rtb_Delay26_idx_0;
  real_T rtb_Delay27_idx_0;
  real_T rtb_Delay16_idx_0;
  real_T rtb_Delay17_idx_0;
  real_T rtb_Delay18_idx_0;
  real_T y_idx_1;
  real_T rtb_Delay_f_idx_1;
  real_T rtb_Delay1_a_idx_1;
  real_T rtb_Delay2_o_idx_1;
  real_T rtb_Delay3_a_idx_1;
  real_T rtb_Delay4_i_idx_1;
  real_T rtb_Delay5_n_idx_1;
  real_T rtb_Delay6_p_idx_1;
  real_T rtb_Delay7_n_idx_1;
  real_T rtb_Delay8_c_idx_1;
  real_T rtb_Delay9_e_idx_1;
  real_T rtb_Delay10_n_idx_1;
  real_T rtb_Delay11_g_idx_1;
  real_T rtb_Delay12_e_idx_1;
  real_T rtb_Delay13_e_idx_1;
  real_T rtb_Delay14_p_idx_1;
  real_T rtb_Delay15_idx_1;
  real_T rtb_Delay20_h_idx_1;
  real_T rtb_Delay21_b_idx_1;
  real_T rtb_Delay22_k_idx_1;
  real_T rtb_Delay23_g_idx_1;
  real_T rtb_Delay24_idx_1;
  real_T rtb_Delay25_idx_1;
  real_T rtb_Delay26_idx_1;
  real_T rtb_Delay27_idx_1;
  real_T rtb_Delay16_idx_1;
  real_T rtb_Delay17_idx_1;
  real_T rtb_Delay18_idx_1;
  real_T d;
  real_T d1;
  real32_T y1_ej;                      // '<Root>/MATLAB Function3'
  real32_T y2_i;                       // '<Root>/MATLAB Function3'
  real32_T y3_c;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S48>/Product3'
  int32_T b;
  int32_T r1;
  int32_T r2;
};

// Block states (default storage) for system '<Root>'
struct DW_manual_control_new_T {
  px4_internal_block_PWM_manual_T obj; // '<S3>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_c;// '<S55>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S45>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S43>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jj;// '<S41>/SourceBlock'
  real_T Delay2_DSTATE[3];             // '<S16>/Delay2'
  real_T Delay23_DSTATE[3];            // '<S18>/Delay23'
  real_T Delay22_DSTATE[3];            // '<S18>/Delay22'
  real_T Delay21_DSTATE[3];            // '<S18>/Delay21'
  real_T Delay20_DSTATE[3];            // '<S18>/Delay20'
  real_T Delay14_DSTATE[3];            // '<S18>/Delay14'
  real_T Delay13_DSTATE[3];            // '<S18>/Delay13'
  real_T Delay12_DSTATE[3];            // '<S18>/Delay12'
  real_T Delay11_DSTATE[3];            // '<S18>/Delay11'
  real_T Delay10_DSTATE[3];            // '<S18>/Delay10'
  real_T Delay9_DSTATE[3];             // '<S18>/Delay9'
  real_T Delay8_DSTATE[3];             // '<S18>/Delay8'
  real_T Delay7_DSTATE[3];             // '<S18>/Delay7'
  real_T Delay6_DSTATE[3];             // '<S18>/Delay6'
  real_T Delay5_DSTATE[3];             // '<S18>/Delay5'
  real_T Delay4_DSTATE[3];             // '<S18>/Delay4'
  real_T Delay3_DSTATE[3];             // '<S18>/Delay3'
  real_T Delay2_DSTATE_j[3];           // '<S18>/Delay2'
  real_T Delay1_DSTATE[3];             // '<S18>/Delay1'
  real_T Delay_DSTATE[3];              // '<S18>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S12>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S12>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S12>/Discrete Transfer Fcn2'
  real_T Delay_DSTATE_k[3];            // '<S14>/Delay'
  real_T Delay1_DSTATE_f[3];           // '<S14>/Delay1'
  real_T Delay2_DSTATE_b[3];           // '<S14>/Delay2'
  real_T Delay3_DSTATE_f[3];           // '<S14>/Delay3'
  real_T Delay4_DSTATE_l[3];           // '<S14>/Delay4'
  real_T Delay5_DSTATE_d[3];           // '<S14>/Delay5'
  real_T Delay6_DSTATE_c[3];           // '<S14>/Delay6'
  real_T Delay7_DSTATE_p[3];           // '<S14>/Delay7'
  real_T Delay8_DSTATE_g[3];           // '<S14>/Delay8'
  real_T Delay9_DSTATE_a[3];           // '<S14>/Delay9'
  real_T Delay10_DSTATE_e[3];          // '<S14>/Delay10'
  real_T Delay11_DSTATE_b[3];          // '<S14>/Delay11'
  real_T Delay12_DSTATE_i[3];          // '<S14>/Delay12'
  real_T Delay13_DSTATE_d[3];          // '<S14>/Delay13'
  real_T Delay14_DSTATE_d[3];          // '<S14>/Delay14'
  real_T Delay15_DSTATE[3];            // '<S14>/Delay15'
  real_T Delay20_DSTATE_k[3];          // '<S14>/Delay20'
  real_T Delay21_DSTATE_l[3];          // '<S14>/Delay21'
  real_T Delay22_DSTATE_m[3];          // '<S14>/Delay22'
  real_T Delay23_DSTATE_f[3];          // '<S14>/Delay23'
  real_T Delay24_DSTATE[3];            // '<S14>/Delay24'
  real_T Delay25_DSTATE[3];            // '<S14>/Delay25'
  real_T Delay26_DSTATE[3];            // '<S14>/Delay26'
  real_T Delay27_DSTATE[3];            // '<S14>/Delay27'
  real_T Delay16_DSTATE[3];            // '<S14>/Delay16'
  real_T Delay17_DSTATE[3];            // '<S14>/Delay17'
  real_T Delay18_DSTATE[3];            // '<S14>/Delay18'
  real_T Delay19_DSTATE[3];            // '<S14>/Delay19'
  real_T Delay2_DSTATE_f[3];           // '<S19>/Delay2'
  real_T DiscreteTransferFcn_states_a; // '<S13>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_o;// '<S13>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_i;// '<S13>/Discrete Transfer Fcn2'
  real_T DiscreteTransferFcn_states_d; // '<S11>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_l;// '<S11>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_b;// '<S11>/Discrete Transfer Fcn2'
  real_T Memory4_PreviousInput[5];     // '<S16>/Memory4'
  real_T Memory2_PreviousInput;        // '<S16>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S16>/Memory3'
  real_T Memory4_PreviousInput_l;      // '<S19>/Memory4'
  real_T Memory3_PreviousInput_j;      // '<S19>/Memory3'
  real_T Memory2_PreviousInput_d;      // '<S19>/Memory2'
  real_T Memory5_PreviousInput;        // '<S7>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S7>/Memory6'
  struct {
    void *LoggedData;
  } Scope4_PWORK;                      // '<S3>/Scope4'

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      // '<S3>/Scope5'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<S18>/Scope'

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
    void *LoggedData;
  } Scope3_PWORK;                      // '<S3>/Scope3'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<S3>/Scope2'

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      // '<S3>/Scope1'

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     // '<S3>/Scope'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S55>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S49>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S49>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S49>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S45>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S43>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_js;// '<S41>/Enabled Subsystem'
  uint8_T is_active_c12_manual_control_ne;// '<S4>/correct sequence'
  uint8_T is_active_c6_manual_control_new;// '<S28>/MATLAB Function'
  uint8_T is_active_c13_manual_control_ne;// '<S8>/MATLAB Function2'
  uint8_T is_active_c24_manual_control_ne;// '<S8>/MATLAB Function1'
  uint8_T is_active_c2_manual_control_new;// '<S7>/Y_computation'
  uint8_T is_active_c3_manual_control_new;// '<S19>/EKF_Y'
  uint8_T is_active_c4_manual_control_new;// '<S7>/RP_computation'
  uint8_T is_active_c8_manual_control_new;// '<S16>/MATLAB Function'
  uint8_T is_active_c5_manual_control_new;// '<S16>/EKF_RP'
  uint8_T is_active_c11_manual_control_ne;// '<S7>/RPY_dot_computation'
  uint8_T is_active_c18_manual_control_ne;// '<S14>/MATLAB Function'
  uint8_T is_active_c1_manual_control_new;// '<S5>/MATLAB Function1'
  uint8_T is_active_c10_manual_control_ne;// '<S5>/MATLAB Function'
  uint8_T is_active_c7_manual_control_new;// '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit;    // '<S4>/correct sequence'
  boolean_T doneDoubleBufferReInit_f;  // '<S28>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_c;  // '<S8>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_n;  // '<S8>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_fz; // '<S7>/Y_computation'
  boolean_T doneDoubleBufferReInit_ct; // '<S19>/EKF_Y'
  boolean_T doneDoubleBufferReInit_l;  // '<S7>/RP_computation'
  boolean_T doneDoubleBufferReInit_lz; // '<S16>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_d;  // '<S16>/EKF_RP'
  boolean_T doneDoubleBufferReInit_j;  // '<S7>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_n5; // '<S14>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_e;  // '<S5>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_k;  // '<S5>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_nq; // '<Root>/MATLAB Function3'
  DW_MATLABFunction1_manual_con_T sf_MATLABFunction7;// '<S8>/MATLAB Function7'
  DW_MATLABFunction1_manual_con_T sf_MATLABFunction1_p;// '<S2>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_manual_control_new_T_ {
  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S16>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S19>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S16>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S16>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S5>/Gain'
                                          //    '<S5>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S16>/EKF_RP'
                                          //    '<S19>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S7>/Constant6'
                                          //    '<S16>/EKF_RP'
                                          //    '<S19>/EKF_Y'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S19>/EKF_Y'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S19>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S16>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S19>/Memory4'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S56>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S55>/Constant'

  px4_Bus_sensor_accel Out1_Y0_i;      // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S42>/Out1'

  px4_Bus_sensor_accel Constant_Value_p;// Computed Parameter: Constant_Value_p
                                           //  Referenced by: '<S41>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_b;       // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S44>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e;// Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S43>/Constant'

  px4_Bus_sensor_mag Out1_Y0_d;        // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S46>/Out1'

  px4_Bus_sensor_mag Constant_Value_h; // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S45>/Constant'

  real_T Constant7_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant7'

  real_T Motor1_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor1'

  real_T Constant_Value_n;             // Expression: 1000
                                          //  Referenced by: '<S31>/Constant'

  real_T Constant3_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant3'

  real_T Motor2_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor2'

  real_T Constant_Value_j;             // Expression: 1000
                                          //  Referenced by: '<S32>/Constant'

  real_T Constant5_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant5'

  real_T Motor3_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor3'

  real_T Constant_Value_pr;            // Expression: 1000
                                          //  Referenced by: '<S33>/Constant'

  real_T Constant1_Value;              // Expression: 1
                                          //  Referenced by: '<Root>/Constant1'

  real_T Motor4_Gain;                  // Expression: 0
                                          //  Referenced by: '<Root>/Motor4'

  real_T Constant_Value_d;             // Expression: 1000
                                          //  Referenced by: '<S34>/Constant'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S16>/Delay2'

  real_T Delay23_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay23'

  real_T Delay22_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay22'

  real_T Delay21_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay21'

  real_T Delay20_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay20'

  real_T Delay14_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay14'

  real_T Delay13_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay13'

  real_T Delay12_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay12'

  real_T Delay11_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay11'

  real_T Delay10_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay10'

  real_T Delay9_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay9'

  real_T Delay8_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay8'

  real_T Delay7_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay7'

  real_T Delay6_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay6'

  real_T Delay5_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay5'

  real_T Delay4_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay4'

  real_T Delay3_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay3'

  real_T Delay2_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S18>/Delay'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S12>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S12>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S12>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  real_T Delay_InitialCondition_o[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay'

  real_T Delay1_InitialCondition_n[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay1'

  real_T Delay2_InitialCondition_f[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay2'

  real_T Delay3_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay3'

  real_T Delay4_InitialCondition_h[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay4'

  real_T Delay5_InitialCondition_n[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay5'

  real_T Delay6_InitialCondition_m[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay6'

  real_T Delay7_InitialCondition_j[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay7'

  real_T Delay8_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay8'

  real_T Delay9_InitialCondition_d[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay9'

  real_T Delay10_InitialCondition_a[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay10'

  real_T Delay11_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay11'

  real_T Delay12_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay12'

  real_T Delay13_InitialCondition_o[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay13'

  real_T Delay14_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay14'

  real_T Delay15_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay15'

  real_T Delay20_InitialCondition_d[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay20'

  real_T Delay21_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay21'

  real_T Delay22_InitialCondition_p[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay22'

  real_T Delay23_InitialCondition_l[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay23'

  real_T Delay24_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay24'

  real_T Delay25_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay25'

  real_T Delay26_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay26'

  real_T Delay27_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay27'

  real_T Delay16_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay16'

  real_T Delay17_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay17'

  real_T Delay18_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay18'

  real_T Delay19_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S14>/Delay19'

  real_T Gain_Gain;                    // Expression: 1/20
                                          //  Referenced by: '<S18>/Gain'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S16>/Memory2'

  real_T Delay2_InitialCondition_l;    // Expression: 0.0
                                          //  Referenced by: '<S19>/Delay2'

  real_T Memory2_InitialCondition_d;   // Expression: 0
                                          //  Referenced by: '<S19>/Memory2'

  real_T DiscreteTransferFcn_NumCoef_j;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_n[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_b;// Expression: 0
                                            //  Referenced by: '<S13>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_o;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_e[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_l;// Expression: 0
                                            //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_n;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_a[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_e;// Expression: 0
                                            //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S7>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S7>/Memory6'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S8>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S8>/Gain1'

  real_T Gain_Gain_b;                  // Expression: 180/pi
                                          //  Referenced by: '<S2>/Gain'

  real_T DiscreteTransferFcn_NumCoef_l;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S11>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_g[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S11>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_i;// Expression: 0
                                            //  Referenced by: '<S11>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_l;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_k[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_f;// Expression: 0
                                            //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_c;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_b[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_j;// Expression: 0
                                            //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S50>/Constant'

  real32_T Constant_Value_e5;          // Computed Parameter: Constant_Value_e5
                                          //  Referenced by: '<S51>/Constant'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<Root>/Gain1'

  boolean_T Constant6_Value[25];       // Computed Parameter: Constant6_Value
                                          //  Referenced by: '<Root>/Constant6'

  boolean_T ARMPWM1_Value;             // Computed Parameter: ARMPWM1_Value
                                          //  Referenced by: '<Root>/ARM PWM1'

  boolean_T Constant2_Value;           // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S3>/failsafe'

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

  uint8_T startingswitch_CurrentSetting;
                            // Computed Parameter: startingswitch_CurrentSetting
                               //  Referenced by: '<Root>/starting switch'

};

// Real-time Model Data Structure
struct tag_RTM_manual_control_new_T {
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

  extern P_manual_control_new_T manual_control_new_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_manual_control_new_T manual_control_new_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_manual_control_new_T manual_control_new_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void manual_control_new_initialize(void);
  extern void manual_control_new_step(void);
  extern void manual_control_new_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_manual_control_new_T *const manual_control_new_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S41>/NOT' : Unused code path elimination
//  Block '<S43>/NOT' : Unused code path elimination
//  Block '<S45>/NOT' : Unused code path elimination
//  Block '<S55>/NOT' : Unused code path elimination


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
//  '<Root>' : 'manual_control_new'
//  '<S1>'   : 'manual_control_new/MATLAB Function3'
//  '<S2>'   : 'manual_control_new/Observer'
//  '<S3>'   : 'manual_control_new/PX4'
//  '<S4>'   : 'manual_control_new/Sensors'
//  '<S5>'   : 'manual_control_new/Observer/IMU measurements & rotation'
//  '<S6>'   : 'manual_control_new/Observer/MATLAB Function1'
//  '<S7>'   : 'manual_control_new/Observer/Observer'
//  '<S8>'   : 'manual_control_new/Observer/Subsystem'
//  '<S9>'   : 'manual_control_new/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S10>'  : 'manual_control_new/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S11>'  : 'manual_control_new/Observer/Observer/ filter'
//  '<S12>'  : 'manual_control_new/Observer/Observer/ filter1'
//  '<S13>'  : 'manual_control_new/Observer/Observer/ filter2'
//  '<S14>'  : 'manual_control_new/Observer/Observer/Median Filter'
//  '<S15>'  : 'manual_control_new/Observer/Observer/RPY_dot_computation'
//  '<S16>'  : 'manual_control_new/Observer/Observer/RP_EKF'
//  '<S17>'  : 'manual_control_new/Observer/Observer/RP_computation'
//  '<S18>'  : 'manual_control_new/Observer/Observer/Sliding Filter'
//  '<S19>'  : 'manual_control_new/Observer/Observer/Y_EKF'
//  '<S20>'  : 'manual_control_new/Observer/Observer/Y_computation'
//  '<S21>'  : 'manual_control_new/Observer/Observer/Median Filter/MATLAB Function'
//  '<S22>'  : 'manual_control_new/Observer/Observer/RP_EKF/EKF_RP'
//  '<S23>'  : 'manual_control_new/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S24>'  : 'manual_control_new/Observer/Observer/Y_EKF/EKF_Y'
//  '<S25>'  : 'manual_control_new/Observer/Subsystem/MATLAB Function1'
//  '<S26>'  : 'manual_control_new/Observer/Subsystem/MATLAB Function2'
//  '<S27>'  : 'manual_control_new/Observer/Subsystem/MATLAB Function7'
//  '<S28>'  : 'manual_control_new/PX4/Acquisition'
//  '<S29>'  : 'manual_control_new/PX4/U + BIAS'
//  '<S30>'  : 'manual_control_new/PX4/Acquisition/MATLAB Function'
//  '<S31>'  : 'manual_control_new/PX4/U + BIAS/input1'
//  '<S32>'  : 'manual_control_new/PX4/U + BIAS/input2'
//  '<S33>'  : 'manual_control_new/PX4/U + BIAS/input3'
//  '<S34>'  : 'manual_control_new/PX4/U + BIAS/input4'
//  '<S35>'  : 'manual_control_new/Sensors/Accelerometer'
//  '<S36>'  : 'manual_control_new/Sensors/Gyroscope'
//  '<S37>'  : 'manual_control_new/Sensors/Magnetometer'
//  '<S38>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles'
//  '<S39>'  : 'manual_control_new/Sensors/Vehicle Attitude'
//  '<S40>'  : 'manual_control_new/Sensors/correct sequence'
//  '<S41>'  : 'manual_control_new/Sensors/Accelerometer/PX4 uORB Read'
//  '<S42>'  : 'manual_control_new/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S43>'  : 'manual_control_new/Sensors/Gyroscope/PX4 uORB Read'
//  '<S44>'  : 'manual_control_new/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S45>'  : 'manual_control_new/Sensors/Magnetometer/PX4 uORB Read'
//  '<S46>'  : 'manual_control_new/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S47>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S48>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S49>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S50>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S51>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S52>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S53>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S54>'  : 'manual_control_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S55>'  : 'manual_control_new/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S56>'  : 'manual_control_new/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_manual_control_new_h_

//
// File trailer for generated code.
//
// [EOF]
//
