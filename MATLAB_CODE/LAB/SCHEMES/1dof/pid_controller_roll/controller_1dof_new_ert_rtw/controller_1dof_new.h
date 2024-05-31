//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_1dof_new.h
//
// Code generated for Simulink model 'controller_1dof_new'.
//
// Model version                  : 1.50
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed May 29 11:27:42 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_1dof_new_h_
#define RTW_HEADER_controller_1dof_new_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "controller_1dof_new_types.h"
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
struct DW_MATLABFunction1_controller_T {
  int32_T sfEvent;                     // '<S4>/MATLAB Function1'
  uint8_T is_active_c9_controller_1dof_ne;// '<S4>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S4>/MATLAB Function1'
};

// Block signals (default storage)
struct B_controller_1dof_new_T {
  real_T TmpSignalConversionAtSFun_e[87];// '<S25>/MATLAB Function'
  real_T b_norm[58];
  px4_Bus_vehicle_odometry In1;        // '<S69>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T dv1[12];
  px4_Bus_actuator_outputs In1_h;      // '<S47>/In1'
  px4_Bus_actuator_outputs b_varargout_2_c;
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  real_T dv2[9];
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro b_varargout_2_cx;
  px4_Bus_sensor_mag In1_f;            // '<S59>/In1'
  px4_Bus_sensor_gyro In1_n;           // '<S57>/In1'
  px4_Bus_sensor_accel In1_i;          // '<S55>/In1'
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
  real32_T Gain1_d[3];                 // '<Root>/Gain1'
  int8_T A_tmp_c[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T Internal;                     // '<S10>/Internal'
  real_T Product;                      // '<S1>/Product'
  real_T Sum23[3];                     // '<S29>/Sum23'
  real_T Sum24[3];                     // '<S29>/Sum24'
  real_T ManualSwitch2[28];            // '<Root>/Manual Switch2'
  real_T TmpSignalConversionAt_asyncqueu[29];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T y1_b;                         // '<S19>/MATLAB Function7'
  real_T y2_p;                         // '<S19>/MATLAB Function7'
  real_T y3_g;                         // '<S19>/MATLAB Function7'
  real_T y1_j;                         // '<S4>/MATLAB Function1'
  real_T y2_pc;                        // '<S4>/MATLAB Function1'
  real_T y3_l;                         // '<S4>/MATLAB Function1'
  real_T y_c[3];                       // '<S16>/MATLAB Function1'
  real_T y_p[3];                       // '<S16>/MATLAB Function'
  real_T u1;                           // '<Root>/MATLAB Function2'
  real_T u2;                           // '<Root>/MATLAB Function2'
  real_T u3;                           // '<Root>/MATLAB Function2'
  real_T u4;                           // '<Root>/MATLAB Function2'
  real_T tau_o[3];                     // '<S1>/MATLAB Function3'
  real_T u_sat;                        // '<S1>/MATLAB Function1'
  real32_T SignalConversion[4];        // '<Root>/Signal Conversion'
  real32_T y_k[3];                     // '<S7>/correct sequence'
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T a21;
  real_T Sum23_f;
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
  real_T x;
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
  real_T x_idx_0;
  real_T y;
  real_T y_g;
  real_T y_g1;
  real_T y_m;
  real_T d;
  real_T cph_tmp;
  real_T ps_meas_tmp_tmp;
  real_T Sum2_h;                       // '<S1>/Sum2'
  uint64_T frac;
  real32_T y1_e;                       // '<Root>/MATLAB Function3'
  real32_T y2_i;                       // '<Root>/MATLAB Function3'
  real32_T y3_c;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S61>/Product3'
  real32_T Product2;                   // '<S61>/Product2'
  int32_T b;
  int32_T r1;
  int32_T r2;
  uint32_T bpIdx;
};

// Block states (default storage) for system '<Root>'
struct DW_controller_1dof_new_T {
  px4_internal_block_PWM_contro_T obj; // '<S5>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_c;// '<S68>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S58>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S56>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jj;// '<S54>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S6>/SourceBlock'
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
  real_T Delay3_DSTATE_d[3];           // '<S29>/Delay3'
  real_T Delay2_DSTATE_i[3];           // '<S29>/Delay2'
  real_T Delay1_DSTATE[3];             // '<S29>/Delay1'
  real_T Delay_DSTATE[3];              // '<S29>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S23>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S23>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S23>/Discrete Transfer Fcn2'
  real_T Delay_DSTATE_p[3];            // '<S25>/Delay'
  real_T Delay1_DSTATE_p[3];           // '<S25>/Delay1'
  real_T Delay2_DSTATE_p[3];           // '<S25>/Delay2'
  real_T Delay3_DSTATE_j[3];           // '<S25>/Delay3'
  real_T Delay4_DSTATE_e[3];           // '<S25>/Delay4'
  real_T Delay5_DSTATE_p[3];           // '<S25>/Delay5'
  real_T Delay6_DSTATE_p[3];           // '<S25>/Delay6'
  real_T Delay7_DSTATE_o[3];           // '<S25>/Delay7'
  real_T Delay8_DSTATE_n[3];           // '<S25>/Delay8'
  real_T Delay9_DSTATE_i[3];           // '<S25>/Delay9'
  real_T Delay10_DSTATE_f[3];          // '<S25>/Delay10'
  real_T Delay11_DSTATE_k[3];          // '<S25>/Delay11'
  real_T Delay12_DSTATE_n[3];          // '<S25>/Delay12'
  real_T Delay13_DSTATE_g[3];          // '<S25>/Delay13'
  real_T Delay14_DSTATE_g[3];          // '<S25>/Delay14'
  real_T Delay15_DSTATE[3];            // '<S25>/Delay15'
  real_T Delay20_DSTATE_h[3];          // '<S25>/Delay20'
  real_T Delay21_DSTATE_d[3];          // '<S25>/Delay21'
  real_T Delay22_DSTATE_h[3];          // '<S25>/Delay22'
  real_T Delay23_DSTATE_p[3];          // '<S25>/Delay23'
  real_T Delay24_DSTATE[3];            // '<S25>/Delay24'
  real_T Delay25_DSTATE[3];            // '<S25>/Delay25'
  real_T Delay26_DSTATE[3];            // '<S25>/Delay26'
  real_T Delay27_DSTATE[3];            // '<S25>/Delay27'
  real_T Delay16_DSTATE[3];            // '<S25>/Delay16'
  real_T Delay17_DSTATE[3];            // '<S25>/Delay17'
  real_T Delay18_DSTATE[3];            // '<S25>/Delay18'
  real_T Delay19_DSTATE[3];            // '<S25>/Delay19'
  real_T Delay2_DSTATE_l[3];           // '<S27>/Delay2'
  real_T Delay2_DSTATE_n[3];           // '<S30>/Delay2'
  real_T DiscreteTransferFcn_states_a; // '<S24>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_e;// '<S24>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p;// '<S24>/Discrete Transfer Fcn2'
  real_T DiscreteTransferFcn_states_f; // '<S22>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_d;// '<S22>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p2;// '<S22>/Discrete Transfer Fcn2'
  real_T Memory4_PreviousInput[5];     // '<S27>/Memory4'
  real_T Memory2_PreviousInput;        // '<S27>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S27>/Memory3'
  real_T Memory4_PreviousInput_k;      // '<S30>/Memory4'
  real_T Memory3_PreviousInput_f;      // '<S30>/Memory3'
  real_T Memory2_PreviousInput_b;      // '<S30>/Memory2'
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

  int8_T EnabledSubsystem_SubsysRanBC; // '<S68>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S62>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S62>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S62>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S58>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S56>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_js;// '<S54>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S6>/Enabled Subsystem'
  uint8_T is_active_c17_controller_1dof_n;// '<Root>/allocation_logic'
  uint8_T is_active_c12_controller_1dof_n;// '<S7>/correct sequence'
  uint8_T is_active_c25_controller_1dof_n;// '<S39>/MATLAB Function1'
  uint8_T is_active_c6_controller_1dof_ne;// '<S39>/MATLAB Function'
  uint8_T is_active_c13_controller_1dof_n;// '<S19>/MATLAB Function2'
  uint8_T is_active_c24_controller_1dof_n;// '<S19>/MATLAB Function1'
  uint8_T is_active_c2_controller_1dof_ne;// '<S18>/Y_computation'
  uint8_T is_active_c3_controller_1dof_ne;// '<S30>/EKF_Y'
  uint8_T is_active_c4_controller_1dof_ne;// '<S18>/RP_computation'
  uint8_T is_active_c8_controller_1dof_ne;// '<S27>/MATLAB Function'
  uint8_T is_active_c5_controller_1dof_ne;// '<S27>/EKF_RP'
  uint8_T is_active_c11_controller_1dof_n;// '<S18>/RPY_dot_computation'
  uint8_T is_active_c18_controller_1dof_n;// '<S25>/MATLAB Function'
  uint8_T is_active_c1_controller_1dof_ne;// '<S16>/MATLAB Function1'
  uint8_T is_active_c10_controller_1dof_n;// '<S16>/MATLAB Function'
  uint8_T is_active_c7_controller_1dof_ne;// '<Root>/MATLAB Function3'
  uint8_T is_active_c16_controller_1dof_n;// '<Root>/MATLAB Function2'
  uint8_T is_active_c19_controller_1dof_n;// '<S1>/MATLAB Function3'
  uint8_T is_active_c14_controller_1dof_n;// '<S1>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_h;  // '<S7>/correct sequence'
  boolean_T doneDoubleBufferReInit_b;  // '<S39>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_f;  // '<S39>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_g;  // '<S19>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_n;  // '<S19>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_e;  // '<S18>/Y_computation'
  boolean_T doneDoubleBufferReInit_o;  // '<S30>/EKF_Y'
  boolean_T doneDoubleBufferReInit_c;  // '<S18>/RP_computation'
  boolean_T doneDoubleBufferReInit_f0; // '<S27>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_k;  // '<S27>/EKF_RP'
  boolean_T doneDoubleBufferReInit_p;  // '<S18>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_el; // '<S25>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_ka; // '<S16>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_pq; // '<S16>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_nq; // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_cu; // '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_f3; // '<S1>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_a;  // '<S1>/MATLAB Function1'
  DW_MATLABFunction1_controller_T sf_MATLABFunction7;// '<S19>/MATLAB Function7' 
  DW_MATLABFunction1_controller_T sf_MATLABFunction1_i;// '<S4>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_controller_1dof_new_T_ {
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
                                          //  Referenced by: '<S69>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S68>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S47>/Out1'

  px4_Bus_actuator_outputs Constant_Value_h;// Computed Parameter: Constant_Value_h
                                               //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_accel Out1_Y0_i;      // Computed Parameter: Out1_Y0_i
                                          //  Referenced by: '<S55>/Out1'

  px4_Bus_sensor_accel Constant_Value_p;// Computed Parameter: Constant_Value_p
                                           //  Referenced by: '<S54>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_b;       // Computed Parameter: Out1_Y0_b
                                          //  Referenced by: '<S57>/Out1'

  px4_Bus_sensor_gyro Constant_Value_e;// Computed Parameter: Constant_Value_e
                                          //  Referenced by: '<S56>/Constant'

  px4_Bus_sensor_mag Out1_Y0_d;        // Computed Parameter: Out1_Y0_d
                                          //  Referenced by: '<S59>/Out1'

  px4_Bus_sensor_mag Constant_Value_hr;// Computed Parameter: Constant_Value_hr
                                          //  Referenced by: '<S58>/Constant'

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

  real_T Constant3_Value;              // Expression: -0.85
                                          //  Referenced by: '<S1>/Constant3'

  real_T Constant6_Value;              // Expression: 0.85
                                          //  Referenced by: '<S1>/Constant6'

  real_T Delay2_InitialCondition[2];   // Expression: zeros(2,1)
                                          //  Referenced by: '<S1>/Delay2'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value_m;            // Expression: 150
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_n;             // Expression: 1000
                                          //  Referenced by: '<S43>/Constant'

  real_T Constant_Value_j;             // Expression: 1000
                                          //  Referenced by: '<S44>/Constant'

  real_T Constant_Value_pr;            // Expression: 1000
                                          //  Referenced by: '<S45>/Constant'

  real_T Constant_Value_d;             // Expression: 1000
                                          //  Referenced by: '<S46>/Constant'

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

  real_T Delay3_InitialCondition_d;    // Expression: 0.0
                                          //  Referenced by: '<S29>/Delay3'

  real_T Delay2_InitialCondition_k;    // Expression: 0.0
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

  real_T Delay_InitialCondition_h[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay'

  real_T Delay1_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay1'

  real_T Delay2_InitialCondition_p[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay2'

  real_T Delay3_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay3'

  real_T Delay4_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay4'

  real_T Delay5_InitialCondition_h[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay5'

  real_T Delay6_InitialCondition_n[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay6'

  real_T Delay7_InitialCondition_m[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay7'

  real_T Delay8_InitialCondition_j[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay8'

  real_T Delay9_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay9'

  real_T Delay10_InitialCondition_n[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay10'

  real_T Delay11_InitialCondition_a[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay11'

  real_T Delay12_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay12'

  real_T Delay13_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay13'

  real_T Delay14_InitialCondition_o[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay14'

  real_T Delay15_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay15'

  real_T Delay20_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay20'

  real_T Delay21_InitialCondition_d[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay21'

  real_T Delay22_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S25>/Delay22'

  real_T Delay23_InitialCondition_p[3];// Expression: zeros(1,3)
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

  real_T Gain_Gain_b;                  // Expression: 1/20
                                          //  Referenced by: '<S29>/Gain'

  real_T Delay2_InitialCondition_kt;   // Expression: 0.0
                                          //  Referenced by: '<S27>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S27>/Memory2'

  real_T Delay2_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S30>/Delay2'

  real_T Memory2_InitialCondition_h;   // Expression: 0
                                          //  Referenced by: '<S30>/Memory2'

  real_T DiscreteTransferFcn_NumCoef_g;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_j[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_m;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_o[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_j;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_h;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_c;// Expression: 0
                                            //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S18>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S18>/Memory6'

  real_T Rref_Time;                    // Expression: 0
                                          //  Referenced by: '<Root>/R ref'

  real_T Rref_Y0;                      // Expression: 0
                                          //  Referenced by: '<Root>/R ref'

  real_T Rref_YFinal;                  // Expression: 0
                                          //  Referenced by: '<Root>/R ref'

  real_T Gain4_Gain;                   // Expression: 0.2
                                          //  Referenced by: '<Root>/Gain4'

  real_T Gain3_Gain;                   // Expression: 2
                                          //  Referenced by: '<Root>/Gain3'

  real_T Gain5_Gain;                   // Expression: pi/180
                                          //  Referenced by: '<Root>/Gain5'

  real_T Constant7_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant8'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S19>/Gain1'

  real_T Gain_Gain_e;                  // Expression: 180/pi
                                          //  Referenced by: '<S4>/Gain'

  real_T Constant5_Value;              // Expression: 0.6
                                          //  Referenced by: '<Root>/Constant5'

  real_T Constant_Value_jx;            // Expression: 1
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain2_Gain_o;                 // Expression: pi/180
                                          //  Referenced by: '<Root>/Gain2'

  real_T DiscreteTransferFcn_NumCoef_gv;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_i;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_o;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_m[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_g;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_g;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_e[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_o;// Expression: 0
                                            //  Referenced by: '<S22>/Discrete Transfer Fcn2'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S63>/Constant'

  real32_T Constant_Value_e5;          // Computed Parameter: Constant_Value_e5
                                          //  Referenced by: '<S64>/Constant'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<Root>/Gain1'

  int16_T LookUpTable_tableData[33];// Computed Parameter: LookUpTable_tableData
                                       //  Referenced by: '<S70>/Look-Up Table'

  uint16_T Point50_Value;              // Computed Parameter: Point50_Value
                                          //  Referenced by: '<S71>/Point50'

  uint16_T Point25_Value;              // Computed Parameter: Point25_Value
                                          //  Referenced by: '<S71>/Point25'

  uint16_T LookUpTable_bp01Data[33]; // Computed Parameter: LookUpTable_bp01Data
                                        //  Referenced by: '<S70>/Look-Up Table'

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

  uint8_T ManualSwitch_CurrentSetting;
                              // Computed Parameter: ManualSwitch_CurrentSetting
                                 //  Referenced by: '<Root>/Manual Switch'

};

// Real-time Model Data Structure
struct tag_RTM_controller_1dof_new_T {
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

  extern P_controller_1dof_new_T controller_1dof_new_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controller_1dof_new_T controller_1dof_new_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controller_1dof_new_T controller_1dof_new_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_1dof_new_initialize(void);
  extern void controller_1dof_new_step(void);
  extern void controller_1dof_new_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controller_1dof_new_T *const controller_1dof_new_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S54>/NOT' : Unused code path elimination
//  Block '<S56>/NOT' : Unused code path elimination
//  Block '<S58>/NOT' : Unused code path elimination
//  Block '<S68>/NOT' : Unused code path elimination
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
//  '<Root>' : 'controller_1dof_new'
//  '<S1>'   : 'controller_1dof_new/Controller Camilla'
//  '<S2>'   : 'controller_1dof_new/MATLAB Function2'
//  '<S3>'   : 'controller_1dof_new/MATLAB Function3'
//  '<S4>'   : 'controller_1dof_new/Observer'
//  '<S5>'   : 'controller_1dof_new/PX4'
//  '<S6>'   : 'controller_1dof_new/PX4 uORB Read'
//  '<S7>'   : 'controller_1dof_new/Sensors'
//  '<S8>'   : 'controller_1dof_new/Sine'
//  '<S9>'   : 'controller_1dof_new/allocation_logic'
//  '<S10>'  : 'controller_1dof_new/Controller Camilla/LTI System'
//  '<S11>'  : 'controller_1dof_new/Controller Camilla/MATLAB Function1'
//  '<S12>'  : 'controller_1dof_new/Controller Camilla/MATLAB Function3'
//  '<S13>'  : 'controller_1dof_new/Controller Camilla/LTI System/IO Delay'
//  '<S14>'  : 'controller_1dof_new/Controller Camilla/LTI System/Input Delay'
//  '<S15>'  : 'controller_1dof_new/Controller Camilla/LTI System/Output Delay'
//  '<S16>'  : 'controller_1dof_new/Observer/IMU measurements & rotation'
//  '<S17>'  : 'controller_1dof_new/Observer/MATLAB Function1'
//  '<S18>'  : 'controller_1dof_new/Observer/Observer'
//  '<S19>'  : 'controller_1dof_new/Observer/Subsystem'
//  '<S20>'  : 'controller_1dof_new/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S21>'  : 'controller_1dof_new/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S22>'  : 'controller_1dof_new/Observer/Observer/ filter'
//  '<S23>'  : 'controller_1dof_new/Observer/Observer/ filter1'
//  '<S24>'  : 'controller_1dof_new/Observer/Observer/ filter2'
//  '<S25>'  : 'controller_1dof_new/Observer/Observer/Median Filter'
//  '<S26>'  : 'controller_1dof_new/Observer/Observer/RPY_dot_computation'
//  '<S27>'  : 'controller_1dof_new/Observer/Observer/RP_EKF'
//  '<S28>'  : 'controller_1dof_new/Observer/Observer/RP_computation'
//  '<S29>'  : 'controller_1dof_new/Observer/Observer/Sliding Filter'
//  '<S30>'  : 'controller_1dof_new/Observer/Observer/Y_EKF'
//  '<S31>'  : 'controller_1dof_new/Observer/Observer/Y_computation'
//  '<S32>'  : 'controller_1dof_new/Observer/Observer/Median Filter/MATLAB Function'
//  '<S33>'  : 'controller_1dof_new/Observer/Observer/RP_EKF/EKF_RP'
//  '<S34>'  : 'controller_1dof_new/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S35>'  : 'controller_1dof_new/Observer/Observer/Y_EKF/EKF_Y'
//  '<S36>'  : 'controller_1dof_new/Observer/Subsystem/MATLAB Function1'
//  '<S37>'  : 'controller_1dof_new/Observer/Subsystem/MATLAB Function2'
//  '<S38>'  : 'controller_1dof_new/Observer/Subsystem/MATLAB Function7'
//  '<S39>'  : 'controller_1dof_new/PX4/Acquisition'
//  '<S40>'  : 'controller_1dof_new/PX4/U + BIAS'
//  '<S41>'  : 'controller_1dof_new/PX4/Acquisition/MATLAB Function'
//  '<S42>'  : 'controller_1dof_new/PX4/Acquisition/MATLAB Function1'
//  '<S43>'  : 'controller_1dof_new/PX4/U + BIAS/input1'
//  '<S44>'  : 'controller_1dof_new/PX4/U + BIAS/input2'
//  '<S45>'  : 'controller_1dof_new/PX4/U + BIAS/input3'
//  '<S46>'  : 'controller_1dof_new/PX4/U + BIAS/input4'
//  '<S47>'  : 'controller_1dof_new/PX4 uORB Read/Enabled Subsystem'
//  '<S48>'  : 'controller_1dof_new/Sensors/Accelerometer'
//  '<S49>'  : 'controller_1dof_new/Sensors/Gyroscope'
//  '<S50>'  : 'controller_1dof_new/Sensors/Magnetometer'
//  '<S51>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles'
//  '<S52>'  : 'controller_1dof_new/Sensors/Vehicle Attitude'
//  '<S53>'  : 'controller_1dof_new/Sensors/correct sequence'
//  '<S54>'  : 'controller_1dof_new/Sensors/Accelerometer/PX4 uORB Read'
//  '<S55>'  : 'controller_1dof_new/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S56>'  : 'controller_1dof_new/Sensors/Gyroscope/PX4 uORB Read'
//  '<S57>'  : 'controller_1dof_new/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S58>'  : 'controller_1dof_new/Sensors/Magnetometer/PX4 uORB Read'
//  '<S59>'  : 'controller_1dof_new/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S60>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S61>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S62>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S63>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S64>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S65>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S66>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S67>'  : 'controller_1dof_new/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S68>'  : 'controller_1dof_new/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S69>'  : 'controller_1dof_new/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'
//  '<S70>'  : 'controller_1dof_new/Sine/Sine'
//  '<S71>'  : 'controller_1dof_new/Sine/Sine/Handle Quarter Symmetry Sine'

#endif                                 // RTW_HEADER_controller_1dof_new_h_

//
// File trailer for generated code.
//
// [EOF]
//
