//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: h2_controller_pitch.h
//
// Code generated for Simulink model 'h2_controller_pitch'.
//
// Model version                  : 1.55
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed May 29 10:00:01 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_h2_controller_pitch_h_
#define RTW_HEADER_h2_controller_pitch_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "h2_controller_pitch_types.h"
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

// Block states (default storage) for system '<S4>/MATLAB Function1'
struct DW_MATLABFunction1_h2_control_T {
  int32_T sfEvent;                     // '<S4>/MATLAB Function1'
  uint8_T is_active_c9_h2_controller_pitc;// '<S4>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S4>/MATLAB Function1'
};

// Block signals (default storage)
struct B_h2_controller_pitch_T {
  real_T TmpSignalConversionAtSFun_e[87];// '<S26>/MATLAB Function'
  real_T b_norm[58];
  px4_Bus_vehicle_odometry In1;        // '<S70>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T dv1[12];
  px4_Bus_actuator_outputs In1_h;      // '<S48>/In1'
  px4_Bus_actuator_outputs b_varargout_2_c;
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  real_T dv2[9];
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro b_varargout_2_cx;
  px4_Bus_sensor_mag In1_f;            // '<S60>/In1'
  px4_Bus_sensor_gyro In1_n;           // '<S58>/In1'
  px4_Bus_sensor_accel In1_i;          // '<S56>/In1'
  px4_Bus_sensor_mag b_varargout_2_b;
  real_T dv3[6];
  real_T dv4[6];
  real_T dv5[6];
  real_T xt[5];
  real_T u[4];                         // '<Root>/allocation_logic'
  real_T minval[4];
  real_T x[4];
  real_T tau_allocated[3];             // '<Root>/allocation_logic'
  real_T u_vect[3];
  real_T TmpSignalConversionAtSFunct[3];// '<S19>/RPY_dot_computation'
  real_T Gain2_a[3];                   // '<S20>/Gain2'
  real_T Gain_e[3];                    // '<S4>/Gain'
  uint16_T pwmValue[8];
  real_T temp[2];
  real_T temp_p[2];
  int8_T A_tmp_c[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T Internal;                     // '<S11>/Internal'
  real_T Product;                      // '<S1>/Product'
  real_T Sum23[3];                     // '<S30>/Sum23'
  real_T Sum24[3];                     // '<S30>/Sum24'
  real_T ManualSwitch2[28];            // '<Root>/Manual Switch2'
  real_T TmpSignalConversionAt_asyncqueu[29];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T y1_b;                         // '<S20>/MATLAB Function7'
  real_T y2_p;                         // '<S20>/MATLAB Function7'
  real_T y3_g;                         // '<S20>/MATLAB Function7'
  real_T y1_j;                         // '<S4>/MATLAB Function1'
  real_T y2_pc;                        // '<S4>/MATLAB Function1'
  real_T y3_l;                         // '<S4>/MATLAB Function1'
  real_T y_c[3];                       // '<S17>/MATLAB Function1'
  real_T y_p[3];                       // '<S17>/MATLAB Function'
  real_T u1;                           // '<Root>/MATLAB Function2'
  real_T u2;                           // '<Root>/MATLAB Function2'
  real_T u3;                           // '<Root>/MATLAB Function2'
  real_T u4;                           // '<Root>/MATLAB Function2'
  real_T tau_o[3];                     // '<S1>/MATLAB Function3'
  real_T u_sat;                        // '<S1>/MATLAB Function1'
  real32_T SignalConversion[4];        // '<Root>/Signal Conversion'
  real32_T y_k[3];                     // '<S7>/correct sequence'
  real_T numAccum;
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T a21;
  real_T Pt_f;
  real_T Gain2;                        // '<Root>/Gain2'
  real_T Sum23_g;
  real_T Delay_DSTATE_p;
  real_T Delay1_DSTATE_p;
  real_T Delay2_DSTATE_p;
  real_T Delay3_DSTATE_j;
  real_T Delay4_DSTATE_e;
  real_T Delay5_DSTATE_p;
  real_T Delay6_DSTATE_p;
  real_T Delay7_DSTATE_o;
  real_T Delay8_DSTATE_n;
  real_T Delay9_DSTATE_i;
  real_T Delay10_DSTATE_f;
  real_T Delay11_DSTATE_k;
  real_T Delay12_DSTATE_n;
  real_T Delay13_DSTATE_g;
  real_T Delay14_DSTATE_g;
  real_T Delay15_DSTATE;
  real_T Delay20_DSTATE_h;
  real_T Delay21_DSTATE_d;
  real_T Delay22_DSTATE_h;
  real_T Delay23_DSTATE_p;
  real_T Delay24_DSTATE;
  real_T Delay25_DSTATE;
  real_T Delay26_DSTATE;
  real_T Delay27_DSTATE;
  real_T Delay16_DSTATE;
  real_T Delay17_DSTATE;
  real_T Delay18_DSTATE;
  real_T x_g;
  real_T y_idx_0;
  real_T rtb_Delay_l_idx_0;
  real_T rtb_Delay1_n_idx_0;
  real_T rtb_Delay2_h_idx_0;
  real_T rtb_Delay3_p_idx_0;
  real_T rtb_Delay4_j_idx_0;
  real_T rtb_Delay5_e_idx_0;
  real_T rtb_Delay6_f_idx_0;
  real_T rtb_Delay7_i_idx_0;
  real_T rtb_Delay8_j_idx_0;
  real_T rtb_Delay9_j_idx_0;
  real_T rtb_Delay10_e_idx_0;
  real_T rtb_Delay11_n_idx_0;
  real_T rtb_Delay12_a_idx_0;
  real_T rtb_Delay13_h_idx_0;
  real_T rtb_Delay14_m_idx_0;
  real_T rtb_Delay15_idx_0;
  real_T rtb_Delay20_g_idx_0;
  real_T rtb_Delay21_e_idx_0;
  real_T rtb_Delay22_b_idx_0;
  real_T rtb_Delay23_g_idx_0;
  real_T rtb_Delay24_idx_0;
  real_T rtb_Delay25_idx_0;
  real_T rtb_Delay26_idx_0;
  real_T rtb_Delay27_idx_0;
  real_T rtb_Delay16_idx_0;
  real_T rtb_Delay17_idx_0;
  real_T rtb_Delay18_idx_0;
  real_T y_idx_1;
  real_T rtb_Delay_l_idx_1;
  real_T rtb_Delay1_n_idx_1;
  real_T rtb_Delay2_h_idx_1;
  real_T rtb_Delay3_p_idx_1;
  real_T rtb_Delay4_j_idx_1;
  real_T rtb_Delay5_e_idx_1;
  real_T rtb_Delay6_f_idx_1;
  real_T rtb_Delay7_i_idx_1;
  real_T rtb_Delay8_j_idx_1;
  real_T rtb_Delay9_j_idx_1;
  real_T rtb_Delay10_e_idx_1;
  real_T rtb_Delay11_n_idx_1;
  real_T rtb_Delay12_a_idx_1;
  real_T rtb_Delay13_h_idx_1;
  real_T rtb_Delay14_m_idx_1;
  real_T rtb_Delay15_idx_1;
  real_T rtb_Delay20_g_idx_1;
  real_T rtb_Delay21_e_idx_1;
  real_T rtb_Delay22_b_idx_1;
  real_T rtb_Delay23_g_idx_1;
  real_T rtb_Delay24_idx_1;
  real_T rtb_Delay25_idx_1;
  real_T rtb_Delay26_idx_1;
  real_T rtb_Delay27_idx_1;
  real_T rtb_Delay16_idx_1;
  real_T rtb_Delay17_idx_1;
  real_T rtb_Delay18_idx_1;
  real_T y;
  real_T Delay2_DSTATE;
  real_T Delay2_DSTATE_m;
  real_T Delay2_DSTATE_n;
  real_T Delay2_DSTATE_pp;
  real_T d;
  real_T Sum2_h;                       // '<S1>/Sum2'
  uint64_T frac;
  real32_T y1_e;                       // '<Root>/MATLAB Function3'
  real32_T y2_i;                       // '<Root>/MATLAB Function3'
  real32_T y3_c;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S62>/Product3'
  int32_T b;
  int32_T r1;
  int32_T r2;
  uint32_T bpIdx;
};

// Block states (default storage) for system '<Root>'
struct DW_h2_controller_pitch_T {
  px4_internal_block_PWM_h2_con_T obj; // '<S5>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_c;// '<S69>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S59>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S57>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jj;// '<S55>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S6>/SourceBlock'
  real_T Delay3_DSTATE;                // '<S1>/Delay3'
  real_T Internal_DSTATE;              // '<S11>/Internal'
  real_T Delay2_DSTATE[4];             // '<S1>/Delay2'
  real_T Delay23_DSTATE[3];            // '<S30>/Delay23'
  real_T Delay22_DSTATE[3];            // '<S30>/Delay22'
  real_T Delay21_DSTATE[3];            // '<S30>/Delay21'
  real_T Delay20_DSTATE[3];            // '<S30>/Delay20'
  real_T Delay14_DSTATE[3];            // '<S30>/Delay14'
  real_T Delay13_DSTATE[3];            // '<S30>/Delay13'
  real_T Delay12_DSTATE[3];            // '<S30>/Delay12'
  real_T Delay11_DSTATE[3];            // '<S30>/Delay11'
  real_T Delay10_DSTATE[3];            // '<S30>/Delay10'
  real_T Delay9_DSTATE[3];             // '<S30>/Delay9'
  real_T Delay8_DSTATE[3];             // '<S30>/Delay8'
  real_T Delay7_DSTATE[3];             // '<S30>/Delay7'
  real_T Delay6_DSTATE[3];             // '<S30>/Delay6'
  real_T Delay5_DSTATE[3];             // '<S30>/Delay5'
  real_T Delay4_DSTATE[3];             // '<S30>/Delay4'
  real_T Delay3_DSTATE_d[3];           // '<S30>/Delay3'
  real_T Delay2_DSTATE_i[3];           // '<S30>/Delay2'
  real_T Delay1_DSTATE[3];             // '<S30>/Delay1'
  real_T Delay_DSTATE[3];              // '<S30>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S24>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S24>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S24>/Discrete Transfer Fcn2'
  real_T Delay_DSTATE_p[3];            // '<S26>/Delay'
  real_T Delay1_DSTATE_p[3];           // '<S26>/Delay1'
  real_T Delay2_DSTATE_p[3];           // '<S26>/Delay2'
  real_T Delay3_DSTATE_j[3];           // '<S26>/Delay3'
  real_T Delay4_DSTATE_e[3];           // '<S26>/Delay4'
  real_T Delay5_DSTATE_p[3];           // '<S26>/Delay5'
  real_T Delay6_DSTATE_p[3];           // '<S26>/Delay6'
  real_T Delay7_DSTATE_o[3];           // '<S26>/Delay7'
  real_T Delay8_DSTATE_n[3];           // '<S26>/Delay8'
  real_T Delay9_DSTATE_i[3];           // '<S26>/Delay9'
  real_T Delay10_DSTATE_f[3];          // '<S26>/Delay10'
  real_T Delay11_DSTATE_k[3];          // '<S26>/Delay11'
  real_T Delay12_DSTATE_n[3];          // '<S26>/Delay12'
  real_T Delay13_DSTATE_g[3];          // '<S26>/Delay13'
  real_T Delay14_DSTATE_g[3];          // '<S26>/Delay14'
  real_T Delay15_DSTATE[3];            // '<S26>/Delay15'
  real_T Delay20_DSTATE_h[3];          // '<S26>/Delay20'
  real_T Delay21_DSTATE_d[3];          // '<S26>/Delay21'
  real_T Delay22_DSTATE_h[3];          // '<S26>/Delay22'
  real_T Delay23_DSTATE_p[3];          // '<S26>/Delay23'
  real_T Delay24_DSTATE[3];            // '<S26>/Delay24'
  real_T Delay25_DSTATE[3];            // '<S26>/Delay25'
  real_T Delay26_DSTATE[3];            // '<S26>/Delay26'
  real_T Delay27_DSTATE[3];            // '<S26>/Delay27'
  real_T Delay16_DSTATE[3];            // '<S26>/Delay16'
  real_T Delay17_DSTATE[3];            // '<S26>/Delay17'
  real_T Delay18_DSTATE[3];            // '<S26>/Delay18'
  real_T Delay19_DSTATE[3];            // '<S26>/Delay19'
  real_T Delay2_DSTATE_l[3];           // '<S28>/Delay2'
  real_T Delay2_DSTATE_n[3];           // '<S31>/Delay2'
  real_T DiscreteTransferFcn_states_a; // '<S25>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_e;// '<S25>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p;// '<S25>/Discrete Transfer Fcn2'
  real_T DiscreteTransferFcn1_states_p;// '<S10>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn_states_f; // '<S23>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_d;// '<S23>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p2;// '<S23>/Discrete Transfer Fcn2'
  real_T Memory4_PreviousInput[5];     // '<S28>/Memory4'
  real_T Memory2_PreviousInput;        // '<S28>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S28>/Memory3'
  real_T Memory4_PreviousInput_k;      // '<S31>/Memory4'
  real_T Memory3_PreviousInput_f;      // '<S31>/Memory3'
  real_T Memory2_PreviousInput_b;      // '<S31>/Memory2'
  real_T Memory5_PreviousInput;        // '<S19>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S19>/Memory6'
  struct {
    void *LoggedData;
  } PWM_PWORK;                         // '<Root>/PWM'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<S30>/Scope'

  struct {
    void *LoggedData[2];
  } TAU_PWORK;                         // '<Root>/TAU'

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
  } TAU_PITCH_PWORK;                   // '<S1>/TAU_PITCH'

  struct {
    void *LoggedData;
  } ERROR1_PWORK;                      // '<S1>/ERROR1'

  struct {
    void *LoggedData;
  } ERROR_PWORK;                       // '<S1>/ERROR'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S69>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S63>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S63>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S63>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S59>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S57>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_js;// '<S55>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S6>/Enabled Subsystem'
  uint8_T is_active_c17_h2_controller_pit;// '<Root>/allocation_logic'
  uint8_T is_active_c12_h2_controller_pit;// '<S7>/correct sequence'
  uint8_T is_active_c25_h2_controller_pit;// '<S40>/MATLAB Function1'
  uint8_T is_active_c6_h2_controller_pitc;// '<S40>/MATLAB Function'
  uint8_T is_active_c13_h2_controller_pit;// '<S20>/MATLAB Function2'
  uint8_T is_active_c24_h2_controller_pit;// '<S20>/MATLAB Function1'
  uint8_T is_active_c2_h2_controller_pitc;// '<S19>/Y_computation'
  uint8_T is_active_c3_h2_controller_pitc;// '<S31>/EKF_Y'
  uint8_T is_active_c4_h2_controller_pitc;// '<S19>/RP_computation'
  uint8_T is_active_c8_h2_controller_pitc;// '<S28>/MATLAB Function'
  uint8_T is_active_c5_h2_controller_pitc;// '<S28>/EKF_RP'
  uint8_T is_active_c11_h2_controller_pit;// '<S19>/RPY_dot_computation'
  uint8_T is_active_c18_h2_controller_pit;// '<S26>/MATLAB Function'
  uint8_T is_active_c1_h2_controller_pitc;// '<S17>/MATLAB Function1'
  uint8_T is_active_c10_h2_controller_pit;// '<S17>/MATLAB Function'
  uint8_T is_active_c7_h2_controller_pitc;// '<Root>/MATLAB Function3'
  uint8_T is_active_c16_h2_controller_pit;// '<Root>/MATLAB Function2'
  uint8_T is_active_c19_h2_controller_pit;// '<S1>/MATLAB Function3'
  uint8_T is_active_c14_h2_controller_pit;// '<S1>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_h;  // '<S7>/correct sequence'
  boolean_T doneDoubleBufferReInit_b;  // '<S40>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_f;  // '<S40>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_g;  // '<S20>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_n;  // '<S20>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_e;  // '<S19>/Y_computation'
  boolean_T doneDoubleBufferReInit_o;  // '<S31>/EKF_Y'
  boolean_T doneDoubleBufferReInit_c;  // '<S19>/RP_computation'
  boolean_T doneDoubleBufferReInit_f0; // '<S28>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_k;  // '<S28>/EKF_RP'
  boolean_T doneDoubleBufferReInit_p;  // '<S19>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_el; // '<S26>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_ka; // '<S17>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_pq; // '<S17>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_nq; // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_cu; // '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_f3; // '<S1>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_a;  // '<S1>/MATLAB Function1'
  DW_MATLABFunction1_h2_control_T sf_MATLABFunction7;// '<S20>/MATLAB Function7' 
  DW_MATLABFunction1_h2_control_T sf_MATLABFunction1_i;// '<S4>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_h2_controller_pitch_T_ {
  real_T A_cond[16];                   // Variable: A_cond
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T B_cond[4];                    // Variable: B_cond
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T C[4];                         // Variable: C
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T D;                            // Variable: D
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T K[2];                         // Variable: K
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S28>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S31>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S28>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S28>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S17>/Gain'
                                          //    '<S17>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S28>/EKF_RP'
                                          //    '<S31>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S19>/Constant6'
                                          //    '<S28>/EKF_RP'
                                          //    '<S31>/EKF_Y'

  real_T param[10];                    // Variable: param
                                          //  Referenced by: '<Root>/allocation_logic'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S31>/EKF_Y'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S31>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S28>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S31>/Memory4'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S70>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S69>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S48>/Out1'

  px4_Bus_actuator_outputs Constant_Value_h;// Computed Parameter: Constant_Value_h
                                               //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_accel Out1_Y0_i;      // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S56>/Out1'

  px4_Bus_sensor_accel Constant_Value_p;// Computed Parameter: Constant_Value_p
                                           //  Referenced by: '<S55>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_b;       // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S58>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e;// Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S57>/Constant'

  px4_Bus_sensor_mag Out1_Y0_d;        // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S60>/Out1'

  px4_Bus_sensor_mag Constant_Value_hr;// Computed Parameter: Constant_Value_hr
                                          //  Referenced by: '<S59>/Constant'

  real_T Delay3_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S1>/Delay3'

  real_T Internal_A;                   // Computed Parameter: Internal_A
                                          //  Referenced by: '<S11>/Internal'

  real_T Internal_C;                   // Computed Parameter: Internal_C
                                          //  Referenced by: '<S11>/Internal'

  real_T Internal_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S11>/Internal'

  real_T Gain_Gain;                    // Expression: 65
                                          //  Referenced by: '<S1>/Gain'

  real_T Gain4_Gain;                   // Expression: 1
                                          //  Referenced by: '<Root>/Gain4'

  real_T Constant_Value_j;             // Expression: 2
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain_Gain_m;                  // Expression: -1
                                          //  Referenced by: '<Root>/Gain'

  real_T Gain2_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<Root>/Gain2'

  real_T Constant3_Value;              // Expression: -0.85
                                          //  Referenced by: '<S1>/Constant3'

  real_T Constant6_Value;              // Expression: 0.85
                                          //  Referenced by: '<S1>/Constant6'

  real_T Delay2_InitialCondition[4];   // Expression: zeros(4,1)
                                          //  Referenced by: '<S1>/Delay2'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value_m;            // Expression: 150
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_n;             // Expression: 1000
                                          //  Referenced by: '<S44>/Constant'

  real_T Constant_Value_jz;            // Expression: 1000
                                          //  Referenced by: '<S45>/Constant'

  real_T Constant_Value_pr;            // Expression: 1000
                                          //  Referenced by: '<S46>/Constant'

  real_T Constant_Value_d;             // Expression: 1000
                                          //  Referenced by: '<S47>/Constant'

  real_T Delay23_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay23'

  real_T Delay22_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay22'

  real_T Delay21_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay21'

  real_T Delay20_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay20'

  real_T Delay14_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay14'

  real_T Delay13_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay13'

  real_T Delay12_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay12'

  real_T Delay11_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay11'

  real_T Delay10_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay10'

  real_T Delay9_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay9'

  real_T Delay8_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay8'

  real_T Delay7_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay7'

  real_T Delay6_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay6'

  real_T Delay5_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay5'

  real_T Delay4_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay4'

  real_T Delay3_InitialCondition_d;    // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay3'

  real_T Delay2_InitialCondition_k;    // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T Delay_InitialCondition_h[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay'

  real_T Delay1_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay1'

  real_T Delay2_InitialCondition_p[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay2'

  real_T Delay3_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay3'

  real_T Delay4_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay4'

  real_T Delay5_InitialCondition_h[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay5'

  real_T Delay6_InitialCondition_n[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay6'

  real_T Delay7_InitialCondition_m[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay7'

  real_T Delay8_InitialCondition_j[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay8'

  real_T Delay9_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay9'

  real_T Delay10_InitialCondition_n[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay10'

  real_T Delay11_InitialCondition_a[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay11'

  real_T Delay12_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay12'

  real_T Delay13_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay13'

  real_T Delay14_InitialCondition_o[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay14'

  real_T Delay15_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay15'

  real_T Delay20_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay20'

  real_T Delay21_InitialCondition_d[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay21'

  real_T Delay22_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay22'

  real_T Delay23_InitialCondition_p[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay23'

  real_T Delay24_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay24'

  real_T Delay25_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay25'

  real_T Delay26_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay26'

  real_T Delay27_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay27'

  real_T Delay16_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay16'

  real_T Delay17_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay17'

  real_T Delay18_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay18'

  real_T Delay19_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S26>/Delay19'

  real_T Gain_Gain_b;                  // Expression: 1/20
                                          //  Referenced by: '<S30>/Gain'

  real_T Delay2_InitialCondition_kt;   // Expression: 0.0
                                          //  Referenced by: '<S28>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S28>/Memory2'

  real_T Delay2_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S31>/Delay2'

  real_T Memory2_InitialCondition_h;   // Expression: 0
                                          //  Referenced by: '<S31>/Memory2'

  real_T DiscreteTransferFcn_NumCoef_g;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_j[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_m;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_o[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_j;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_h;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_c;// Expression: 0
                                            //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S19>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S19>/Memory6'

  real_T Rref_Time;                    // Expression: 0
                                          //  Referenced by: '<Root>/R ref'

  real_T Rref_Y0;                      // Expression: 0
                                          //  Referenced by: '<Root>/R ref'

  real_T Rref_YFinal;                  // Expression: pi/180*(0)
                                          //  Referenced by: '<Root>/R ref'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant8'

  real_T Gain2_Gain_e;                 // Expression: 180/pi
                                          //  Referenced by: '<S20>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S20>/Gain1'

  real_T Gain_Gain_e;                  // Expression: 180/pi
                                          //  Referenced by: '<S4>/Gain'

  real_T DiscreteTransferFcn1_NumCoef_n;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_g[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_e;// Expression: 0
                                            //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn_NumCoef_gv;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_i;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_o;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_m[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_g;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_g;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_e[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_o;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S64>/Constant'

  real32_T Constant_Value_e5;          // Computed Parameter: Constant_Value_e5
                                          //  Referenced by: '<S65>/Constant'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<Root>/Gain1'

  int16_T Gain3_Gain;                  // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<Root>/Gain3'

  int16_T LookUpTable_tableData[33];// Computed Parameter: LookUpTable_tableData
                                       //  Referenced by: '<S71>/Look-Up Table'

  uint16_T Point50_Value;              // Computed Parameter: Point50_Value
                                          //  Referenced by: '<S72>/Point50'

  uint16_T Point25_Value;              // Computed Parameter: Point25_Value
                                          //  Referenced by: '<S72>/Point25'

  uint16_T LookUpTable_bp01Data[33]; // Computed Parameter: LookUpTable_bp01Data
                                        //  Referenced by: '<S71>/Look-Up Table'

  boolean_T Constant6_Value_f;         // Computed Parameter: Constant6_Value_f
                                          //  Referenced by: '<Root>/Constant6'

  boolean_T Constant2_Value;           // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T ARMPWM1_Value;             // Computed Parameter: ARMPWM1_Value
                                          //  Referenced by: '<Root>/ARM PWM1'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S5>/failsafe'

  uint8_T startingswitch_CurrentSetting;
                            // Computed Parameter: startingswitch_CurrentSetting
                               //  Referenced by: '<Root>/starting switch'

  uint8_T ManualSwitch2_CurrentSetting;
                             // Computed Parameter: ManualSwitch2_CurrentSetting
                                //  Referenced by: '<Root>/Manual Switch2'

};

// Real-time Model Data Structure
struct tag_RTM_h2_controller_pitch_T {
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

  extern P_h2_controller_pitch_T h2_controller_pitch_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_h2_controller_pitch_T h2_controller_pitch_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_h2_controller_pitch_T h2_controller_pitch_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void h2_controller_pitch_initialize(void);
  extern void h2_controller_pitch_step(void);
  extern void h2_controller_pitch_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_h2_controller_pitch_T *const h2_controller_pitch_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S55>/NOT' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S59>/NOT' : Unused code path elimination
//  Block '<S69>/NOT' : Unused code path elimination
//  Block '<S1>/Zero-Order Hold3' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'h2_controller_pitch'
//  '<S1>'   : 'h2_controller_pitch/H2 Controller Anna'
//  '<S2>'   : 'h2_controller_pitch/MATLAB Function2'
//  '<S3>'   : 'h2_controller_pitch/MATLAB Function3'
//  '<S4>'   : 'h2_controller_pitch/Observer'
//  '<S5>'   : 'h2_controller_pitch/PX4'
//  '<S6>'   : 'h2_controller_pitch/PX4 uORB Read'
//  '<S7>'   : 'h2_controller_pitch/Sensors'
//  '<S8>'   : 'h2_controller_pitch/Sine'
//  '<S9>'   : 'h2_controller_pitch/allocation_logic'
//  '<S10>'  : 'h2_controller_pitch/H2 Controller Anna/ prefilter'
//  '<S11>'  : 'h2_controller_pitch/H2 Controller Anna/LTI System'
//  '<S12>'  : 'h2_controller_pitch/H2 Controller Anna/MATLAB Function1'
//  '<S13>'  : 'h2_controller_pitch/H2 Controller Anna/MATLAB Function3'
//  '<S14>'  : 'h2_controller_pitch/H2 Controller Anna/LTI System/IO Delay'
//  '<S15>'  : 'h2_controller_pitch/H2 Controller Anna/LTI System/Input Delay'
//  '<S16>'  : 'h2_controller_pitch/H2 Controller Anna/LTI System/Output Delay'
//  '<S17>'  : 'h2_controller_pitch/Observer/IMU measurements & rotation'
//  '<S18>'  : 'h2_controller_pitch/Observer/MATLAB Function1'
//  '<S19>'  : 'h2_controller_pitch/Observer/Observer'
//  '<S20>'  : 'h2_controller_pitch/Observer/Subsystem'
//  '<S21>'  : 'h2_controller_pitch/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S22>'  : 'h2_controller_pitch/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S23>'  : 'h2_controller_pitch/Observer/Observer/ filter'
//  '<S24>'  : 'h2_controller_pitch/Observer/Observer/ filter1'
//  '<S25>'  : 'h2_controller_pitch/Observer/Observer/ filter2'
//  '<S26>'  : 'h2_controller_pitch/Observer/Observer/Median Filter'
//  '<S27>'  : 'h2_controller_pitch/Observer/Observer/RPY_dot_computation'
//  '<S28>'  : 'h2_controller_pitch/Observer/Observer/RP_EKF'
//  '<S29>'  : 'h2_controller_pitch/Observer/Observer/RP_computation'
//  '<S30>'  : 'h2_controller_pitch/Observer/Observer/Sliding Filter'
//  '<S31>'  : 'h2_controller_pitch/Observer/Observer/Y_EKF'
//  '<S32>'  : 'h2_controller_pitch/Observer/Observer/Y_computation'
//  '<S33>'  : 'h2_controller_pitch/Observer/Observer/Median Filter/MATLAB Function'
//  '<S34>'  : 'h2_controller_pitch/Observer/Observer/RP_EKF/EKF_RP'
//  '<S35>'  : 'h2_controller_pitch/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S36>'  : 'h2_controller_pitch/Observer/Observer/Y_EKF/EKF_Y'
//  '<S37>'  : 'h2_controller_pitch/Observer/Subsystem/MATLAB Function1'
//  '<S38>'  : 'h2_controller_pitch/Observer/Subsystem/MATLAB Function2'
//  '<S39>'  : 'h2_controller_pitch/Observer/Subsystem/MATLAB Function7'
//  '<S40>'  : 'h2_controller_pitch/PX4/Acquisition'
//  '<S41>'  : 'h2_controller_pitch/PX4/U + BIAS'
//  '<S42>'  : 'h2_controller_pitch/PX4/Acquisition/MATLAB Function'
//  '<S43>'  : 'h2_controller_pitch/PX4/Acquisition/MATLAB Function1'
//  '<S44>'  : 'h2_controller_pitch/PX4/U + BIAS/input1'
//  '<S45>'  : 'h2_controller_pitch/PX4/U + BIAS/input2'
//  '<S46>'  : 'h2_controller_pitch/PX4/U + BIAS/input3'
//  '<S47>'  : 'h2_controller_pitch/PX4/U + BIAS/input4'
//  '<S48>'  : 'h2_controller_pitch/PX4 uORB Read/Enabled Subsystem'
//  '<S49>'  : 'h2_controller_pitch/Sensors/Accelerometer'
//  '<S50>'  : 'h2_controller_pitch/Sensors/Gyroscope'
//  '<S51>'  : 'h2_controller_pitch/Sensors/Magnetometer'
//  '<S52>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles'
//  '<S53>'  : 'h2_controller_pitch/Sensors/Vehicle Attitude'
//  '<S54>'  : 'h2_controller_pitch/Sensors/correct sequence'
//  '<S55>'  : 'h2_controller_pitch/Sensors/Accelerometer/PX4 uORB Read'
//  '<S56>'  : 'h2_controller_pitch/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S57>'  : 'h2_controller_pitch/Sensors/Gyroscope/PX4 uORB Read'
//  '<S58>'  : 'h2_controller_pitch/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S59>'  : 'h2_controller_pitch/Sensors/Magnetometer/PX4 uORB Read'
//  '<S60>'  : 'h2_controller_pitch/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S61>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S62>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S63>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S64>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S65>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S66>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S67>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S68>'  : 'h2_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S69>'  : 'h2_controller_pitch/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S70>'  : 'h2_controller_pitch/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S71>'  : 'h2_controller_pitch/Sine/Sine'
//  '<S72>'  : 'h2_controller_pitch/Sine/Sine/Handle Quarter Symmetry Sine'

#endif                                 // RTW_HEADER_h2_controller_pitch_h_

//
// File trailer for generated code.
//
// [EOF]
//
