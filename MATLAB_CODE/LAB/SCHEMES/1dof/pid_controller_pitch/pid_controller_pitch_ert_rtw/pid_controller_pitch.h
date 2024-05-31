//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_controller_pitch.h
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
#ifndef RTW_HEADER_pid_controller_pitch_h_
#define RTW_HEADER_pid_controller_pitch_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "pid_controller_pitch_types.h"
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
struct DW_MATLABFunction1_pid_contro_T {
  int32_T sfEvent;                     // '<S4>/MATLAB Function1'
  uint8_T is_active_c9_pid_controller_pit;// '<S4>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S4>/MATLAB Function1'
};

// Block signals (default storage)
struct B_pid_controller_pitch_T {
  real_T TmpSignalConversionAtSFun_a[87];// '<S25>/MATLAB Function'
  real_T b_norm[58];
  px4_Bus_vehicle_odometry In1;        // '<S68>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T TmpSignalConversionAt_asyncqueu[29];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T dv1[12];
  px4_Bus_actuator_outputs In1_h;      // '<S46>/In1'
  px4_Bus_actuator_outputs b_varargout_2_c;
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  real_T dv2[9];
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro b_varargout_2_cx;
  px4_Bus_sensor_mag In1_k;            // '<S58>/In1'
  px4_Bus_sensor_gyro In1_d;           // '<S56>/In1'
  px4_Bus_sensor_accel In1_dn;         // '<S54>/In1'
  px4_Bus_sensor_mag b_varargout_2_b;
  real_T dv3[6];
  real_T dv4[6];
  real_T dv5[6];
  real_T xt[5];
  real_T u[4];                         // '<Root>/allocation_logic'
  real_T minval[4];
  real_T tau_allocated[3];             // '<Root>/allocation_logic'
  real_T u_vect[3];
  real_T TmpSignalConversionAtSFunct[3];// '<S18>/RPY_dot_computation'
  real_T Gain2[3];                     // '<S19>/Gain2'
  real_T Gain_e[3];                    // '<S4>/Gain'
  uint16_T pwmValue[8];
  real_T temp[2];
  real_T temp_p[2];
  real32_T Gain1_g[3];                 // '<Root>/Gain1'
  int8_T A_tmp_c[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T Internal;                     // '<S10>/Internal'
  real_T Product;                      // '<S1>/Product'
  real_T Sum23[3];                     // '<S29>/Sum23'
  real_T Sum24[3];                     // '<S29>/Sum24'
  real_T ManualSwitch2[28];            // '<Root>/Manual Switch2'
  real_T y1_k;                         // '<S19>/MATLAB Function7'
  real_T y2_b;                         // '<S19>/MATLAB Function7'
  real_T y3_j;                         // '<S19>/MATLAB Function7'
  real_T y1_l;                         // '<S4>/MATLAB Function1'
  real_T y2_k;                         // '<S4>/MATLAB Function1'
  real_T y3_a;                         // '<S4>/MATLAB Function1'
  real_T y_c[3];                       // '<S16>/MATLAB Function1'
  real_T y_i[3];                       // '<S16>/MATLAB Function'
  real_T u1;                           // '<Root>/MATLAB Function2'
  real_T u2;                           // '<Root>/MATLAB Function2'
  real_T u3;                           // '<Root>/MATLAB Function2'
  real_T u4;                           // '<Root>/MATLAB Function2'
  real_T tau_o[3];                     // '<S1>/MATLAB Function3'
  real_T u_sat;                        // '<S1>/MATLAB Function1'
  real32_T SignalConversion[4];        // '<Root>/Signal Conversion'
  real32_T y_f[3];                     // '<S7>/correct sequence'
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T Pt_f;
  real_T Sum23_g;
  real_T Delay_DSTATE_e;
  real_T Delay1_DSTATE_m;
  real_T Delay2_DSTATE_k;
  real_T Delay3_DSTATE_c;
  real_T Delay4_DSTATE_j;
  real_T Delay5_DSTATE_e;
  real_T Delay6_DSTATE_j;
  real_T Delay7_DSTATE_l;
  real_T Delay8_DSTATE_m;
  real_T Delay9_DSTATE_e;
  real_T Delay10_DSTATE_a;
  real_T Delay11_DSTATE_m;
  real_T Delay12_DSTATE_h;
  real_T Delay13_DSTATE_b;
  real_T Delay14_DSTATE_k;
  real_T Delay15_DSTATE;
  real_T Delay20_DSTATE_m;
  real_T Delay21_DSTATE_b;
  real_T Delay22_DSTATE_g;
  real_T Delay23_DSTATE_e;
  real_T Delay24_DSTATE;
  real_T Delay25_DSTATE;
  real_T Delay26_DSTATE;
  real_T Delay27_DSTATE;
  real_T Delay16_DSTATE;
  real_T Delay17_DSTATE;
  real_T Delay18_DSTATE;
  real_T x;
  real_T y_idx_0;
  real_T rtb_Delay_i_idx_0;
  real_T rtb_Delay1_g_idx_0;
  real_T rtb_Delay2_g_idx_0;
  real_T rtb_Delay3_f_idx_0;
  real_T rtb_Delay4_p_idx_0;
  real_T rtb_Delay5_l_idx_0;
  real_T rtb_Delay6_g_idx_0;
  real_T rtb_Delay7_l_idx_0;
  real_T rtb_Delay8_e_idx_0;
  real_T rtb_Delay9_c_idx_0;
  real_T rtb_Delay10_g_idx_0;
  real_T rtb_Delay11_g_idx_0;
  real_T rtb_Delay12_k_idx_0;
  real_T rtb_Delay13_o_idx_0;
  real_T rtb_Delay14_a_idx_0;
  real_T rtb_Delay15_idx_0;
  real_T rtb_Delay20_m_idx_0;
  real_T rtb_Delay21_j_idx_0;
  real_T rtb_Delay22_c_idx_0;
  real_T rtb_Delay23_a_idx_0;
  real_T rtb_Delay24_idx_0;
  real_T rtb_Delay25_idx_0;
  real_T rtb_Delay26_idx_0;
  real_T rtb_Delay27_idx_0;
  real_T rtb_Delay16_idx_0;
  real_T rtb_Delay17_idx_0;
  real_T rtb_Delay18_idx_0;
  real_T y_idx_1;
  real_T rtb_Delay_i_idx_1;
  real_T rtb_Delay1_g_idx_1;
  real_T rtb_Delay2_g_idx_1;
  real_T rtb_Delay3_f_idx_1;
  real_T rtb_Delay4_p_idx_1;
  real_T rtb_Delay5_l_idx_1;
  real_T rtb_Delay6_g_idx_1;
  real_T rtb_Delay7_l_idx_1;
  real_T rtb_Delay8_e_idx_1;
  real_T rtb_Delay9_c_idx_1;
  real_T rtb_Delay10_g_idx_1;
  real_T rtb_Delay11_g_idx_1;
  real_T rtb_Delay12_k_idx_1;
  real_T rtb_Delay13_o_idx_1;
  real_T rtb_Delay14_a_idx_1;
  real_T rtb_Delay15_idx_1;
  real_T rtb_Delay20_m_idx_1;
  real_T rtb_Delay21_j_idx_1;
  real_T rtb_Delay22_c_idx_1;
  real_T rtb_Delay23_a_idx_1;
  real_T rtb_Delay24_idx_1;
  real_T rtb_Delay25_idx_1;
  real_T rtb_Delay26_idx_1;
  real_T rtb_Delay27_idx_1;
  real_T rtb_Delay16_idx_1;
  real_T rtb_Delay17_idx_1;
  real_T rtb_Delay18_idx_1;
  real_T x_idx_0;
  real_T y;
  real_T y_g;
  real_T y_m;
  real_T y_n;
  real_T d;
  real_T d1;
  real_T At1_tmp;
  real_T Sum2_b;                       // '<S1>/Sum2'
  real32_T y1_p;                       // '<Root>/MATLAB Function3'
  real32_T y2_ew;                      // '<Root>/MATLAB Function3'
  real32_T y3_o;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S60>/Product3'
  int32_T b;
  int32_T r1;
  int32_T r2;
};

// Block states (default storage) for system '<Root>'
struct DW_pid_controller_pitch_T {
  px4_internal_block_PWM_pid_co_T obj; // '<S5>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_n;// '<S67>/SourceBlock'
  px4_internal_block_Subscriber_T obj_g;// '<S57>/SourceBlock'
  px4_internal_block_Subscriber_T obj_gg;// '<S55>/SourceBlock'
  px4_internal_block_Subscriber_T obj_k;// '<S53>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S6>/SourceBlock'
  real_T Delay3_DSTATE;                // '<S1>/Delay3'
  real_T Internal_DSTATE;              // '<S10>/Internal'
  real_T Delay2_DSTATE[2];             // '<S1>/Delay2'
  real_T Delay23_DSTATE[3];            // '<S29>/Delay23'
  real_T Delay22_DSTATE[3];            // '<S29>/Delay22'
  real_T Delay21_DSTATE[3];            // '<S29>/Delay21'
  real_T Delay20_DSTATE[3];            // '<S29>/Delay20'
  real_T Delay14_DSTATE[3];            // '<S29>/Delay14'
  real_T Delay13_DSTATE[3];            // '<S29>/Delay13'
  real_T Delay12_DSTATE[3];            // '<S29>/Delay12'
  real_T Delay11_DSTATE[3];            // '<S29>/Delay11'
  real_T Delay10_DSTATE[3];            // '<S29>/Delay10'
  real_T Delay9_DSTATE[3];             // '<S29>/Delay9'
  real_T Delay8_DSTATE[3];             // '<S29>/Delay8'
  real_T Delay7_DSTATE[3];             // '<S29>/Delay7'
  real_T Delay6_DSTATE[3];             // '<S29>/Delay6'
  real_T Delay5_DSTATE[3];             // '<S29>/Delay5'
  real_T Delay4_DSTATE[3];             // '<S29>/Delay4'
  real_T Delay3_DSTATE_j[3];           // '<S29>/Delay3'
  real_T Delay2_DSTATE_f[3];           // '<S29>/Delay2'
  real_T Delay1_DSTATE[3];             // '<S29>/Delay1'
  real_T Delay_DSTATE[3];              // '<S29>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S23>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S23>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S23>/Discrete Transfer Fcn2'
  real_T Delay_DSTATE_e[3];            // '<S25>/Delay'
  real_T Delay1_DSTATE_m[3];           // '<S25>/Delay1'
  real_T Delay2_DSTATE_k[3];           // '<S25>/Delay2'
  real_T Delay3_DSTATE_c[3];           // '<S25>/Delay3'
  real_T Delay4_DSTATE_j[3];           // '<S25>/Delay4'
  real_T Delay5_DSTATE_e[3];           // '<S25>/Delay5'
  real_T Delay6_DSTATE_j[3];           // '<S25>/Delay6'
  real_T Delay7_DSTATE_l[3];           // '<S25>/Delay7'
  real_T Delay8_DSTATE_m[3];           // '<S25>/Delay8'
  real_T Delay9_DSTATE_e[3];           // '<S25>/Delay9'
  real_T Delay10_DSTATE_a[3];          // '<S25>/Delay10'
  real_T Delay11_DSTATE_m[3];          // '<S25>/Delay11'
  real_T Delay12_DSTATE_h[3];          // '<S25>/Delay12'
  real_T Delay13_DSTATE_b[3];          // '<S25>/Delay13'
  real_T Delay14_DSTATE_k[3];          // '<S25>/Delay14'
  real_T Delay15_DSTATE[3];            // '<S25>/Delay15'
  real_T Delay20_DSTATE_m[3];          // '<S25>/Delay20'
  real_T Delay21_DSTATE_b[3];          // '<S25>/Delay21'
  real_T Delay22_DSTATE_g[3];          // '<S25>/Delay22'
  real_T Delay23_DSTATE_e[3];          // '<S25>/Delay23'
  real_T Delay24_DSTATE[3];            // '<S25>/Delay24'
  real_T Delay25_DSTATE[3];            // '<S25>/Delay25'
  real_T Delay26_DSTATE[3];            // '<S25>/Delay26'
  real_T Delay27_DSTATE[3];            // '<S25>/Delay27'
  real_T Delay16_DSTATE[3];            // '<S25>/Delay16'
  real_T Delay17_DSTATE[3];            // '<S25>/Delay17'
  real_T Delay18_DSTATE[3];            // '<S25>/Delay18'
  real_T Delay19_DSTATE[3];            // '<S25>/Delay19'
  real_T Delay2_DSTATE_l[3];           // '<S27>/Delay2'
  real_T Delay2_DSTATE_fv[3];          // '<S30>/Delay2'
  real_T DiscreteTransferFcn_states_i; // '<S24>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_p;// '<S24>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_o;// '<S24>/Discrete Transfer Fcn2'
  real_T DiscreteTransferFcn1_states_e;// '<S9>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn_states_p; // '<S22>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_l;// '<S22>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_g;// '<S22>/Discrete Transfer Fcn2'
  real_T Memory4_PreviousInput[5];     // '<S27>/Memory4'
  real_T Memory2_PreviousInput;        // '<S27>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S27>/Memory3'
  real_T Memory4_PreviousInput_d;      // '<S30>/Memory4'
  real_T Memory3_PreviousInput_g;      // '<S30>/Memory3'
  real_T Memory2_PreviousInput_f;      // '<S30>/Memory2'
  real_T Memory5_PreviousInput;        // '<S18>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S18>/Memory6'
  struct {
    void *LoggedData;
  } PWM_PWORK;                         // '<Root>/PWM'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<S29>/Scope'

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
  } TAU_ROLL_PWORK;                    // '<S1>/TAU_ROLL'

  struct {
    void *LoggedData;
  } ERROR1_PWORK;                      // '<S1>/ERROR1'

  struct {
    void *LoggedData;
  } ERROR_PWORK;                       // '<S1>/ERROR'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S67>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S61>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S61>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S61>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_h;// '<S57>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S55>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_g;// '<S53>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_kv;// '<S6>/Enabled Subsystem'
  uint8_T is_active_c17_pid_controller_pi;// '<Root>/allocation_logic'
  uint8_T is_active_c12_pid_controller_pi;// '<S7>/correct sequence'
  uint8_T is_active_c6_pid_controller_pit;// '<S39>/MATLAB Function'
  uint8_T is_active_c13_pid_controller_pi;// '<S19>/MATLAB Function2'
  uint8_T is_active_c24_pid_controller_pi;// '<S19>/MATLAB Function1'
  uint8_T is_active_c2_pid_controller_pit;// '<S18>/Y_computation'
  uint8_T is_active_c3_pid_controller_pit;// '<S30>/EKF_Y'
  uint8_T is_active_c4_pid_controller_pit;// '<S18>/RP_computation'
  uint8_T is_active_c8_pid_controller_pit;// '<S27>/MATLAB Function'
  uint8_T is_active_c5_pid_controller_pit;// '<S27>/EKF_RP'
  uint8_T is_active_c11_pid_controller_pi;// '<S18>/RPY_dot_computation'
  uint8_T is_active_c18_pid_controller_pi;// '<S25>/MATLAB Function'
  uint8_T is_active_c1_pid_controller_pit;// '<S16>/MATLAB Function1'
  uint8_T is_active_c10_pid_controller_pi;// '<S16>/MATLAB Function'
  uint8_T is_active_c7_pid_controller_pit;// '<Root>/MATLAB Function3'
  uint8_T is_active_c16_pid_controller_pi;// '<Root>/MATLAB Function2'
  uint8_T is_active_c19_pid_controller_pi;// '<S1>/MATLAB Function3'
  uint8_T is_active_c14_pid_controller_pi;// '<S1>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_i;  // '<S7>/correct sequence'
  boolean_T doneDoubleBufferReInit_g;  // '<S39>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_a;  // '<S19>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_o;  // '<S19>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_b;  // '<S18>/Y_computation'
  boolean_T doneDoubleBufferReInit_aw; // '<S30>/EKF_Y'
  boolean_T doneDoubleBufferReInit_a2; // '<S18>/RP_computation'
  boolean_T doneDoubleBufferReInit_f;  // '<S27>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_fb; // '<S27>/EKF_RP'
  boolean_T doneDoubleBufferReInit_h;  // '<S18>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_k;  // '<S25>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_c;  // '<S16>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_al; // '<S16>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_o1; // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_ib; // '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_n;  // '<S1>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_fv; // '<S1>/MATLAB Function1'
  DW_MATLABFunction1_pid_contro_T sf_MATLABFunction7;// '<S19>/MATLAB Function7' 
  DW_MATLABFunction1_pid_contro_T sf_MATLABFunction1_m;// '<S4>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_pid_controller_pitch_T_ {
  real_T A_cond[4];                    // Variable: A_cond
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T B_cond[2];                    // Variable: B_cond
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T C[2];                         // Variable: C
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T D;                            // Variable: D
                                          //  Referenced by: '<S1>/MATLAB Function1'

  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S27>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S30>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S27>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S27>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S16>/Gain'
                                          //    '<S16>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S27>/EKF_RP'
                                          //    '<S30>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S18>/Constant6'
                                          //    '<S27>/EKF_RP'
                                          //    '<S30>/EKF_Y'

  real_T param[10];                    // Variable: param
                                          //  Referenced by: '<Root>/allocation_logic'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S30>/EKF_Y'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S30>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S27>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S30>/Memory4'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S68>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S67>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_b;  // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S46>/Out1'

  px4_Bus_actuator_outputs Constant_Value_p;// Computed Parameter: Constant_Value_p
                                               //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_accel Out1_Y0_a;      // Computed Parameter: Out1_Y0_a
                                          //  Referenced by: '<S54>/Out1'

  px4_Bus_sensor_accel Constant_Value_m;// Computed Parameter: Constant_Value_m
                                           //  Referenced by: '<S53>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_k;       // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S56>/Out1'

  px4_Bus_sensor_gyro Constant_Value_b;// Computed Parameter: Constant_Value_b
                                          //  Referenced by: '<S55>/Constant'

  px4_Bus_sensor_mag Out1_Y0_l;        // Computed Parameter: Out1_Y0_l
                                          //  Referenced by: '<S58>/Out1'

  px4_Bus_sensor_mag Constant_Value_d; // Computed Parameter: Constant_Value_d
                                          //  Referenced by: '<S57>/Constant'

  real_T Constant_Value_db;            // Expression: 0
                                          //  Referenced by: '<S39>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S39>/Constant1'

  real_T Delay3_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S1>/Delay3'

  real_T Internal_A;                   // Computed Parameter: Internal_A
                                          //  Referenced by: '<S10>/Internal'

  real_T Internal_C;                   // Computed Parameter: Internal_C
                                          //  Referenced by: '<S10>/Internal'

  real_T Internal_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S10>/Internal'

  real_T Gain_Gain;                    // Expression: 35
                                          //  Referenced by: '<S1>/Gain'

  real_T Constant3_Value;              // Expression: -0.9
                                          //  Referenced by: '<S1>/Constant3'

  real_T Constant6_Value;              // Expression: 0.9
                                          //  Referenced by: '<S1>/Constant6'

  real_T Delay2_InitialCondition[2];   // Expression: zeros(2,1)
                                          //  Referenced by: '<S1>/Delay2'

  real_T Constant1_Value_j;            // Expression: 900
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value_n;            // Expression: 150
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_g;             // Expression: 1000
                                          //  Referenced by: '<S42>/Constant'

  real_T Constant_Value_e;             // Expression: 1000
                                          //  Referenced by: '<S43>/Constant'

  real_T Constant_Value_l;             // Expression: 1000
                                          //  Referenced by: '<S44>/Constant'

  real_T Constant_Value_eh;            // Expression: 1000
                                          //  Referenced by: '<S45>/Constant'

  real_T Delay23_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay23'

  real_T Delay22_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay22'

  real_T Delay21_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay21'

  real_T Delay20_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay20'

  real_T Delay14_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay14'

  real_T Delay13_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay13'

  real_T Delay12_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay12'

  real_T Delay11_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay11'

  real_T Delay10_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay10'

  real_T Delay9_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay9'

  real_T Delay8_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay8'

  real_T Delay7_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay7'

  real_T Delay6_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay6'

  real_T Delay5_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay5'

  real_T Delay4_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay4'

  real_T Delay3_InitialCondition_h;    // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay3'

  real_T Delay2_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  real_T Delay_InitialCondition_j[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay'

  real_T Delay1_InitialCondition_b[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay1'

  real_T Delay2_InitialCondition_f[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay2'

  real_T Delay3_InitialCondition_g[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay3'

  real_T Delay4_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay4'

  real_T Delay5_InitialCondition_a[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay5'

  real_T Delay6_InitialCondition_h[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay6'

  real_T Delay7_InitialCondition_a[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay7'

  real_T Delay8_InitialCondition_g[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay8'

  real_T Delay9_InitialCondition_a[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay9'

  real_T Delay10_InitialCondition_n[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay10'

  real_T Delay11_InitialCondition_e[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay11'

  real_T Delay12_InitialCondition_p[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay12'

  real_T Delay13_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay13'

  real_T Delay14_InitialCondition_m[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay14'

  real_T Delay15_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay15'

  real_T Delay20_InitialCondition_p[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay20'

  real_T Delay21_InitialCondition_l[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay21'

  real_T Delay22_InitialCondition_d[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay22'

  real_T Delay23_InitialCondition_n[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay23'

  real_T Delay24_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay24'

  real_T Delay25_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay25'

  real_T Delay26_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay26'

  real_T Delay27_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay27'

  real_T Delay16_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay16'

  real_T Delay17_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay17'

  real_T Delay18_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay18'

  real_T Delay19_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay19'

  real_T Gain_Gain_n;                  // Expression: 1/20
                                          //  Referenced by: '<S29>/Gain'

  real_T Delay2_InitialCondition_j;    // Expression: 0.0
                                          //  Referenced by: '<S27>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S27>/Memory2'

  real_T Delay2_InitialCondition_i;    // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay2'

  real_T Memory2_InitialCondition_c;   // Expression: 0
                                          //  Referenced by: '<S30>/Memory2'

  real_T DiscreteTransferFcn_NumCoef_h;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_p[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_d;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_k;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_k[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_m;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_b;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_p[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_i;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S18>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S18>/Memory6'

  real_T RPYref_Time;                  // Expression: 0
                                          //  Referenced by: '<Root>/RPY ref'

  real_T RPYref_Y0;                    // Expression: 0
                                          //  Referenced by: '<Root>/RPY ref'

  real_T RPYref_YFinal;                // Expression: pi/180*(10)
                                          //  Referenced by: '<Root>/RPY ref'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain1'

  real_T Gain_Gain_d;                  // Expression: 180/pi
                                          //  Referenced by: '<S4>/Gain'

  real_T Constant_Value_be;            // Expression: 1
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant5_Value;              // Expression: 0.6
                                          //  Referenced by: '<Root>/Constant5'

  real_T Gain2_Gain_b;                 // Expression: pi/180*-1
                                          //  Referenced by: '<Root>/Gain2'

  real_T DiscreteTransferFcn1_NumCoef_ks;// Expression: [Ts_slk*p]
                                            //  Referenced by: '<S9>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_p[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S9>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_e;// Expression: 0
                                            //  Referenced by: '<S9>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn_NumCoef_o;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_g[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_a;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_c;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_pa[2];// Expression: [1 (Ts_slk*p-1)]
                                               //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_a;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_l;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_o[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_Initial_iv;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real32_T Constant_Value_md;          // Computed Parameter: Constant_Value_md
                                          //  Referenced by: '<S62>/Constant'

  real32_T Constant_Value_f;           // Computed Parameter: Constant_Value_f
                                          //  Referenced by: '<S63>/Constant'

  real32_T Gain1_Gain_n;               // Computed Parameter: Gain1_Gain_n
                                          //  Referenced by: '<Root>/Gain1'

  boolean_T Constant6_Value_g;         // Computed Parameter: Constant6_Value_g
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

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_pid_controller_pitch_T {
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

  extern P_pid_controller_pitch_T pid_controller_pitch_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_pid_controller_pitch_T pid_controller_pitch_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_pid_controller_pitch_T pid_controller_pitch_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void pid_controller_pitch_initialize(void);
  extern void pid_controller_pitch_step(void);
  extern void pid_controller_pitch_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_pid_controller_pitch_T *const pid_controller_pitch_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S53>/NOT' : Unused code path elimination
//  Block '<S55>/NOT' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S67>/NOT' : Unused code path elimination
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
//  '<Root>' : 'pid_controller_pitch'
//  '<S1>'   : 'pid_controller_pitch/Controller Camilla'
//  '<S2>'   : 'pid_controller_pitch/MATLAB Function2'
//  '<S3>'   : 'pid_controller_pitch/MATLAB Function3'
//  '<S4>'   : 'pid_controller_pitch/Observer'
//  '<S5>'   : 'pid_controller_pitch/PX4'
//  '<S6>'   : 'pid_controller_pitch/PX4 uORB Read'
//  '<S7>'   : 'pid_controller_pitch/Sensors'
//  '<S8>'   : 'pid_controller_pitch/allocation_logic'
//  '<S9>'   : 'pid_controller_pitch/Controller Camilla/ prefilter'
//  '<S10>'  : 'pid_controller_pitch/Controller Camilla/LTI System'
//  '<S11>'  : 'pid_controller_pitch/Controller Camilla/MATLAB Function1'
//  '<S12>'  : 'pid_controller_pitch/Controller Camilla/MATLAB Function3'
//  '<S13>'  : 'pid_controller_pitch/Controller Camilla/LTI System/IO Delay'
//  '<S14>'  : 'pid_controller_pitch/Controller Camilla/LTI System/Input Delay'
//  '<S15>'  : 'pid_controller_pitch/Controller Camilla/LTI System/Output Delay'
//  '<S16>'  : 'pid_controller_pitch/Observer/IMU measurements & rotation'
//  '<S17>'  : 'pid_controller_pitch/Observer/MATLAB Function1'
//  '<S18>'  : 'pid_controller_pitch/Observer/Observer'
//  '<S19>'  : 'pid_controller_pitch/Observer/Subsystem'
//  '<S20>'  : 'pid_controller_pitch/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S21>'  : 'pid_controller_pitch/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S22>'  : 'pid_controller_pitch/Observer/Observer/ filter'
//  '<S23>'  : 'pid_controller_pitch/Observer/Observer/ filter1'
//  '<S24>'  : 'pid_controller_pitch/Observer/Observer/ filter2'
//  '<S25>'  : 'pid_controller_pitch/Observer/Observer/Median Filter'
//  '<S26>'  : 'pid_controller_pitch/Observer/Observer/RPY_dot_computation'
//  '<S27>'  : 'pid_controller_pitch/Observer/Observer/RP_EKF'
//  '<S28>'  : 'pid_controller_pitch/Observer/Observer/RP_computation'
//  '<S29>'  : 'pid_controller_pitch/Observer/Observer/Sliding Filter'
//  '<S30>'  : 'pid_controller_pitch/Observer/Observer/Y_EKF'
//  '<S31>'  : 'pid_controller_pitch/Observer/Observer/Y_computation'
//  '<S32>'  : 'pid_controller_pitch/Observer/Observer/Median Filter/MATLAB Function'
//  '<S33>'  : 'pid_controller_pitch/Observer/Observer/RP_EKF/EKF_RP'
//  '<S34>'  : 'pid_controller_pitch/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S35>'  : 'pid_controller_pitch/Observer/Observer/Y_EKF/EKF_Y'
//  '<S36>'  : 'pid_controller_pitch/Observer/Subsystem/MATLAB Function1'
//  '<S37>'  : 'pid_controller_pitch/Observer/Subsystem/MATLAB Function2'
//  '<S38>'  : 'pid_controller_pitch/Observer/Subsystem/MATLAB Function7'
//  '<S39>'  : 'pid_controller_pitch/PX4/Acquisition'
//  '<S40>'  : 'pid_controller_pitch/PX4/U + BIAS'
//  '<S41>'  : 'pid_controller_pitch/PX4/Acquisition/MATLAB Function'
//  '<S42>'  : 'pid_controller_pitch/PX4/U + BIAS/input1'
//  '<S43>'  : 'pid_controller_pitch/PX4/U + BIAS/input2'
//  '<S44>'  : 'pid_controller_pitch/PX4/U + BIAS/input3'
//  '<S45>'  : 'pid_controller_pitch/PX4/U + BIAS/input4'
//  '<S46>'  : 'pid_controller_pitch/PX4 uORB Read/Enabled Subsystem'
//  '<S47>'  : 'pid_controller_pitch/Sensors/Accelerometer'
//  '<S48>'  : 'pid_controller_pitch/Sensors/Gyroscope'
//  '<S49>'  : 'pid_controller_pitch/Sensors/Magnetometer'
//  '<S50>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles'
//  '<S51>'  : 'pid_controller_pitch/Sensors/Vehicle Attitude'
//  '<S52>'  : 'pid_controller_pitch/Sensors/correct sequence'
//  '<S53>'  : 'pid_controller_pitch/Sensors/Accelerometer/PX4 uORB Read'
//  '<S54>'  : 'pid_controller_pitch/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S55>'  : 'pid_controller_pitch/Sensors/Gyroscope/PX4 uORB Read'
//  '<S56>'  : 'pid_controller_pitch/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S57>'  : 'pid_controller_pitch/Sensors/Magnetometer/PX4 uORB Read'
//  '<S58>'  : 'pid_controller_pitch/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S59>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S60>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S61>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S62>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S63>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S64>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S65>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S66>'  : 'pid_controller_pitch/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S67>'  : 'pid_controller_pitch/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S68>'  : 'pid_controller_pitch/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_pid_controller_pitch_h_

//
// File trailer for generated code.
//
// [EOF]
//
