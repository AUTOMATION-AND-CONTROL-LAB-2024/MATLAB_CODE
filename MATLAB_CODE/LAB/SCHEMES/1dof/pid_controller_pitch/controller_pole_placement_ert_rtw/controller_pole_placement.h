//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_pole_placement.h
//
// Code generated for Simulink model 'controller_pole_placement'.
//
// Model version                  : 1.54
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 16:25:55 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_pole_placement_h_
#define RTW_HEADER_controller_pole_placement_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "controller_pole_placement_types.h"
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

// Block states (default storage) for system '<S3>/MATLAB Function1'
struct DW_MATLABFunction1_controller_T {
  int32_T sfEvent;                     // '<S3>/MATLAB Function1'
  uint8_T is_active_c9_controller_pole_pl;// '<S3>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S3>/MATLAB Function1'
};

// Block signals (default storage)
struct B_controller_pole_placement_T {
  real_T TmpSignalConversionAtSFun_e[87];// '<S18>/MATLAB Function'
  real_T b_norm[58];
  px4_Bus_vehicle_odometry In1;        // '<S69>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T ManualSwitch2[28];            // '<Root>/Manual Switch2'
  real_T TmpSignalConversionAt_asyncqueu[29];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T dv1[12];
  px4_Bus_actuator_outputs In1_h;      // '<S40>/In1'
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
  real_T tau_o[3];                     // '<S6>/MATLAB Function3'
  real_T u_vect[3];
  real_T TmpSignalConversionAtSFunct[3];// '<S11>/RPY_dot_computation'
  real_T Gain2[3];                     // '<S12>/Gain2'
  real_T Gain_e[3];                    // '<S3>/Gain'
  real_T x[3];
  uint16_T pwmValue[8];
  real_T temp[2];
  real_T temp_p[2];
  real32_T Gain1_d[3];                 // '<Root>/Gain1'
  int8_T A_tmp_c[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T Internal;                     // '<S42>/Internal'
  real_T Product;                      // '<S6>/Product'
  real_T Sum23[3];                     // '<S22>/Sum23'
  real_T Sum24[3];                     // '<S22>/Sum24'
  real_T u_sat;                        // '<S6>/MATLAB Function1'
  real_T y1_b;                         // '<S12>/MATLAB Function7'
  real_T y2_p;                         // '<S12>/MATLAB Function7'
  real_T y3_g;                         // '<S12>/MATLAB Function7'
  real_T y1_j;                         // '<S3>/MATLAB Function1'
  real_T y2_pc;                        // '<S3>/MATLAB Function1'
  real_T y3_l;                         // '<S3>/MATLAB Function1'
  real_T y_c[3];                       // '<S9>/MATLAB Function1'
  real_T y_p[3];                       // '<S9>/MATLAB Function'
  real_T u1;                           // '<Root>/MATLAB Function2'
  real_T u2;                           // '<Root>/MATLAB Function2'
  real_T u3;                           // '<Root>/MATLAB Function2'
  real_T u4;                           // '<Root>/MATLAB Function2'
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
  real_T Pt_f;
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
  real_T Delay2_DSTATE;
  real_T Delay2_DSTATE_m;
  real_T Delay2_DSTATE_n;
  real_T d;
  real_T d1;
  real_T Sum2_h;                       // '<S6>/Sum2'
  real32_T y1_e;                       // '<Root>/MATLAB Function3'
  real32_T y2_i;                       // '<Root>/MATLAB Function3'
  real32_T y3_c;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S61>/Product3'
  int32_T b;
  int32_T r1;
  int32_T r2;
};

// Block states (default storage) for system '<Root>'
struct DW_controller_pole_placement_T {
  px4_internal_block_PWM_contro_T obj; // '<S4>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_c;// '<S68>/SourceBlock'
  px4_internal_block_Subscriber_T obj_h;// '<S58>/SourceBlock'
  px4_internal_block_Subscriber_T obj_j;// '<S56>/SourceBlock'
  px4_internal_block_Subscriber_T obj_jj;// '<S54>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S5>/SourceBlock'
  real_T Delay3_DSTATE;                // '<S6>/Delay3'
  real_T Internal_DSTATE;              // '<S42>/Internal'
  real_T Delay2_DSTATE[3];             // '<S6>/Delay2'
  real_T Delay23_DSTATE[3];            // '<S22>/Delay23'
  real_T Delay22_DSTATE[3];            // '<S22>/Delay22'
  real_T Delay21_DSTATE[3];            // '<S22>/Delay21'
  real_T Delay20_DSTATE[3];            // '<S22>/Delay20'
  real_T Delay14_DSTATE[3];            // '<S22>/Delay14'
  real_T Delay13_DSTATE[3];            // '<S22>/Delay13'
  real_T Delay12_DSTATE[3];            // '<S22>/Delay12'
  real_T Delay11_DSTATE[3];            // '<S22>/Delay11'
  real_T Delay10_DSTATE[3];            // '<S22>/Delay10'
  real_T Delay9_DSTATE[3];             // '<S22>/Delay9'
  real_T Delay8_DSTATE[3];             // '<S22>/Delay8'
  real_T Delay7_DSTATE[3];             // '<S22>/Delay7'
  real_T Delay6_DSTATE[3];             // '<S22>/Delay6'
  real_T Delay5_DSTATE[3];             // '<S22>/Delay5'
  real_T Delay4_DSTATE[3];             // '<S22>/Delay4'
  real_T Delay3_DSTATE_d[3];           // '<S22>/Delay3'
  real_T Delay2_DSTATE_i[3];           // '<S22>/Delay2'
  real_T Delay1_DSTATE[3];             // '<S22>/Delay1'
  real_T Delay_DSTATE[3];              // '<S22>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S16>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S16>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S16>/Discrete Transfer Fcn2'
  real_T Delay_DSTATE_p[3];            // '<S18>/Delay'
  real_T Delay1_DSTATE_p[3];           // '<S18>/Delay1'
  real_T Delay2_DSTATE_p[3];           // '<S18>/Delay2'
  real_T Delay3_DSTATE_j[3];           // '<S18>/Delay3'
  real_T Delay4_DSTATE_e[3];           // '<S18>/Delay4'
  real_T Delay5_DSTATE_p[3];           // '<S18>/Delay5'
  real_T Delay6_DSTATE_p[3];           // '<S18>/Delay6'
  real_T Delay7_DSTATE_o[3];           // '<S18>/Delay7'
  real_T Delay8_DSTATE_n[3];           // '<S18>/Delay8'
  real_T Delay9_DSTATE_i[3];           // '<S18>/Delay9'
  real_T Delay10_DSTATE_f[3];          // '<S18>/Delay10'
  real_T Delay11_DSTATE_k[3];          // '<S18>/Delay11'
  real_T Delay12_DSTATE_n[3];          // '<S18>/Delay12'
  real_T Delay13_DSTATE_g[3];          // '<S18>/Delay13'
  real_T Delay14_DSTATE_g[3];          // '<S18>/Delay14'
  real_T Delay15_DSTATE[3];            // '<S18>/Delay15'
  real_T Delay20_DSTATE_h[3];          // '<S18>/Delay20'
  real_T Delay21_DSTATE_d[3];          // '<S18>/Delay21'
  real_T Delay22_DSTATE_h[3];          // '<S18>/Delay22'
  real_T Delay23_DSTATE_p[3];          // '<S18>/Delay23'
  real_T Delay24_DSTATE[3];            // '<S18>/Delay24'
  real_T Delay25_DSTATE[3];            // '<S18>/Delay25'
  real_T Delay26_DSTATE[3];            // '<S18>/Delay26'
  real_T Delay27_DSTATE[3];            // '<S18>/Delay27'
  real_T Delay16_DSTATE[3];            // '<S18>/Delay16'
  real_T Delay17_DSTATE[3];            // '<S18>/Delay17'
  real_T Delay18_DSTATE[3];            // '<S18>/Delay18'
  real_T Delay19_DSTATE[3];            // '<S18>/Delay19'
  real_T Delay2_DSTATE_l[3];           // '<S20>/Delay2'
  real_T Delay2_DSTATE_n[3];           // '<S23>/Delay2'
  real_T DiscreteTransferFcn_states_a; // '<S17>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_e;// '<S17>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p;// '<S17>/Discrete Transfer Fcn2'
  real_T DiscreteTransferFcn1_states_eg;// '<S41>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn_states_f; // '<S15>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states_d;// '<S15>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states_p2;// '<S15>/Discrete Transfer Fcn2'
  real_T Memory4_PreviousInput[5];     // '<S20>/Memory4'
  real_T Memory2_PreviousInput;        // '<S20>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S20>/Memory3'
  real_T Memory4_PreviousInput_k;      // '<S23>/Memory4'
  real_T Memory3_PreviousInput_f;      // '<S23>/Memory3'
  real_T Memory2_PreviousInput_b;      // '<S23>/Memory2'
  real_T Memory5_PreviousInput;        // '<S11>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S11>/Memory6'
  struct {
    void *LoggedData;
  } PWM_PWORK;                         // '<Root>/PWM'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<S22>/Scope'

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
  } TAU_ROLL_PWORK;                    // '<S6>/TAU_ROLL'

  struct {
    void *LoggedData;
  } ERROR1_PWORK;                      // '<S6>/ERROR1'

  struct {
    void *LoggedData;
  } ERROR_PWORK;                       // '<S6>/ERROR'

  int8_T EnabledSubsystem_SubsysRanBC; // '<S68>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S62>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S62>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S62>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_j;// '<S58>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_c;// '<S56>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_js;// '<S54>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_k;// '<S5>/Enabled Subsystem'
  uint8_T is_active_c17_controller_pole_p;// '<Root>/allocation_logic'
  uint8_T is_active_c12_controller_pole_p;// '<S7>/correct sequence'
  uint8_T is_active_c19_controller_pole_p;// '<S6>/MATLAB Function3'
  uint8_T is_active_c14_controller_pole_p;// '<S6>/MATLAB Function1'
  uint8_T is_active_c25_controller_pole_p;// '<S32>/MATLAB Function1'
  uint8_T is_active_c6_controller_pole_pl;// '<S32>/MATLAB Function'
  uint8_T is_active_c13_controller_pole_p;// '<S12>/MATLAB Function2'
  uint8_T is_active_c24_controller_pole_p;// '<S12>/MATLAB Function1'
  uint8_T is_active_c2_controller_pole_pl;// '<S11>/Y_computation'
  uint8_T is_active_c3_controller_pole_pl;// '<S23>/EKF_Y'
  uint8_T is_active_c4_controller_pole_pl;// '<S11>/RP_computation'
  uint8_T is_active_c8_controller_pole_pl;// '<S20>/MATLAB Function'
  uint8_T is_active_c5_controller_pole_pl;// '<S20>/EKF_RP'
  uint8_T is_active_c11_controller_pole_p;// '<S11>/RPY_dot_computation'
  uint8_T is_active_c18_controller_pole_p;// '<S18>/MATLAB Function'
  uint8_T is_active_c1_controller_pole_pl;// '<S9>/MATLAB Function1'
  uint8_T is_active_c10_controller_pole_p;// '<S9>/MATLAB Function'
  uint8_T is_active_c7_controller_pole_pl;// '<Root>/MATLAB Function3'
  uint8_T is_active_c16_controller_pole_p;// '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit;    // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_h;  // '<S7>/correct sequence'
  boolean_T doneDoubleBufferReInit_f;  // '<S6>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_a;  // '<S6>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_p;  // '<S32>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_fl; // '<S32>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_g;  // '<S12>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_n;  // '<S12>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_e;  // '<S11>/Y_computation'
  boolean_T doneDoubleBufferReInit_o;  // '<S23>/EKF_Y'
  boolean_T doneDoubleBufferReInit_c;  // '<S11>/RP_computation'
  boolean_T doneDoubleBufferReInit_f0; // '<S20>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_k;  // '<S20>/EKF_RP'
  boolean_T doneDoubleBufferReInit_p0; // '<S11>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_el; // '<S18>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_ka; // '<S9>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_pq; // '<S9>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_nq; // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_cu; // '<Root>/MATLAB Function2'
  DW_MATLABFunction1_controller_T sf_MATLABFunction7;// '<S12>/MATLAB Function7' 
  DW_MATLABFunction1_controller_T sf_MATLABFunction1_i;// '<S3>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_controller_pole_placement_T_ {
  real_T A_cond[9];                    // Variable: A_cond
                                          //  Referenced by: '<S6>/MATLAB Function1'

  real_T B_cond[3];                    // Variable: B_cond
                                          //  Referenced by: '<S6>/MATLAB Function1'

  real_T C[3];                         // Variable: C
                                          //  Referenced by: '<S6>/MATLAB Function1'

  real_T D;                            // Variable: D
                                          //  Referenced by: '<S6>/MATLAB Function1'

  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S20>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S23>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S20>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S20>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S9>/Gain'
                                          //    '<S9>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S20>/EKF_RP'
                                          //    '<S23>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S11>/Constant6'
                                          //    '<S20>/EKF_RP'
                                          //    '<S23>/EKF_Y'

  real_T param[10];                    // Variable: param
                                          //  Referenced by: '<Root>/allocation_logic'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S23>/EKF_Y'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S23>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S20>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S23>/Memory4'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S69>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S68>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S40>/Out1'

  px4_Bus_actuator_outputs Constant_Value_h;// Computed Parameter: Constant_Value_h
                                               //  Referenced by: '<S5>/Constant'

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

  real_T Gain_Gain;                    // Expression: -1
                                          //  Referenced by: '<Root>/Gain'

  real_T Delay3_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S6>/Delay3'

  real_T Internal_A;                   // Computed Parameter: Internal_A
                                          //  Referenced by: '<S42>/Internal'

  real_T Internal_C;                   // Computed Parameter: Internal_C
                                          //  Referenced by: '<S42>/Internal'

  real_T Internal_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S42>/Internal'

  real_T Gain_Gain_e;                  // Expression: 25
                                          //  Referenced by: '<S6>/Gain'

  real_T Constant3_Value;              // Expression: -0.85
                                          //  Referenced by: '<S6>/Constant3'

  real_T Constant6_Value;              // Expression: 0.85
                                          //  Referenced by: '<S6>/Constant6'

  real_T Delay2_InitialCondition[3];   // Expression: zeros(3,1)
                                          //  Referenced by: '<S6>/Delay2'

  real_T Constant1_Value;              // Expression: 1000
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value_m;            // Expression: 150
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_n;             // Expression: 1000
                                          //  Referenced by: '<S36>/Constant'

  real_T Constant_Value_j;             // Expression: 1000
                                          //  Referenced by: '<S37>/Constant'

  real_T Constant_Value_pr;            // Expression: 1000
                                          //  Referenced by: '<S38>/Constant'

  real_T Constant_Value_d;             // Expression: 1000
                                          //  Referenced by: '<S39>/Constant'

  real_T Delay23_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay23'

  real_T Delay22_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay22'

  real_T Delay21_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay21'

  real_T Delay20_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay20'

  real_T Delay14_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay14'

  real_T Delay13_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay13'

  real_T Delay12_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay12'

  real_T Delay11_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay11'

  real_T Delay10_InitialCondition;     // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay10'

  real_T Delay9_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay9'

  real_T Delay8_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay8'

  real_T Delay7_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay7'

  real_T Delay6_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay6'

  real_T Delay5_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay5'

  real_T Delay4_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay4'

  real_T Delay3_InitialCondition_d;    // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay3'

  real_T Delay2_InitialCondition_k;    // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay2'

  real_T Delay1_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S22>/Delay'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S16>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S16>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S16>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  real_T Delay_InitialCondition_h[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay'

  real_T Delay1_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay1'

  real_T Delay2_InitialCondition_p[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay2'

  real_T Delay3_InitialCondition_o[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay3'

  real_T Delay4_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay4'

  real_T Delay5_InitialCondition_h[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay5'

  real_T Delay6_InitialCondition_n[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay6'

  real_T Delay7_InitialCondition_m[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay7'

  real_T Delay8_InitialCondition_j[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay8'

  real_T Delay9_InitialCondition_i[3]; // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay9'

  real_T Delay10_InitialCondition_n[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay10'

  real_T Delay11_InitialCondition_a[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay11'

  real_T Delay12_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay12'

  real_T Delay13_InitialCondition_b[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay13'

  real_T Delay14_InitialCondition_o[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay14'

  real_T Delay15_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay15'

  real_T Delay20_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay20'

  real_T Delay21_InitialCondition_d[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay21'

  real_T Delay22_InitialCondition_f[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay22'

  real_T Delay23_InitialCondition_p[3];// Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay23'

  real_T Delay24_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay24'

  real_T Delay25_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay25'

  real_T Delay26_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay26'

  real_T Delay27_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay27'

  real_T Delay16_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay16'

  real_T Delay17_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay17'

  real_T Delay18_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay18'

  real_T Delay19_InitialCondition[3];  // Expression: zeros(1,3)
                                          //  Referenced by: '<S18>/Delay19'

  real_T Gain_Gain_b;                  // Expression: 1/20
                                          //  Referenced by: '<S22>/Gain'

  real_T Delay2_InitialCondition_kt;   // Expression: 0.0
                                          //  Referenced by: '<S20>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S20>/Memory2'

  real_T Delay2_InitialCondition_a;    // Expression: 0.0
                                          //  Referenced by: '<S23>/Delay2'

  real_T Memory2_InitialCondition_h;   // Expression: 0
                                          //  Referenced by: '<S23>/Memory2'

  real_T DiscreteTransferFcn_NumCoef_g;// Expression: [Ts_slk*p]
                                          //  Referenced by: '<S17>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_j[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S17>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_e;// Expression: 0
                                            //  Referenced by: '<S17>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_m;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_o[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_j;// Expression: 0
                                            //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_h;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_c;// Expression: 0
                                            //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S11>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S11>/Memory6'

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

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S12>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S12>/Gain1'

  real_T Gain_Gain_ex;                 // Expression: 180/pi
                                          //  Referenced by: '<S3>/Gain'

  real_T Constant_Value_jx;            // Expression: 3.9
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant5_Value;              // Expression: 2
                                          //  Referenced by: '<Root>/Constant5'

  real_T Gain2_Gain_o;                 // Expression: pi/180
                                          //  Referenced by: '<Root>/Gain2'

  real_T DiscreteTransferFcn1_NumCoef_d;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_a[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_h;// Expression: 0
                                            //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn_NumCoef_gv;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S15>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef_i[2];// Expression: [1 (Ts_slk*p-1)]
                                             //  Referenced by: '<S15>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialSt_i;// Expression: 0
                                            //  Referenced by: '<S15>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef_o;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef_m[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialS_g;// Expression: 0
                                            //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef_g;// Expression: [Ts_slk*p]
                                           //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef_e[2];// Expression: [1 (Ts_slk*p-1)]
                                              //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialS_o;// Expression: 0
                                            //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  real32_T Constant_Value_o;           // Computed Parameter: Constant_Value_o
                                          //  Referenced by: '<S63>/Constant'

  real32_T Constant_Value_e5;          // Computed Parameter: Constant_Value_e5
                                          //  Referenced by: '<S64>/Constant'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<Root>/Gain1'

  boolean_T Constant6_Value_f;         // Computed Parameter: Constant6_Value_f
                                          //  Referenced by: '<Root>/Constant6'

  boolean_T Constant2_Value;           // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

  boolean_T ARMPWM1_Value;             // Computed Parameter: ARMPWM1_Value
                                          //  Referenced by: '<Root>/ARM PWM1'

  boolean_T failsafe_Value;            // Computed Parameter: failsafe_Value
                                          //  Referenced by: '<S4>/failsafe'

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
struct tag_RTM_controller_pole_place_T {
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

  extern P_controller_pole_placement_T controller_pole_placement_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controller_pole_placement_T controller_pole_placement_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controller_pole_placement_T controller_pole_placement_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_pole_placement_initialize(void);
  extern void controller_pole_placement_step(void);
  extern void controller_pole_placement_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controller_pole_plac_T *const controller_pole_placement_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S5>/NOT' : Unused code path elimination
//  Block '<S54>/NOT' : Unused code path elimination
//  Block '<S56>/NOT' : Unused code path elimination
//  Block '<S58>/NOT' : Unused code path elimination
//  Block '<S68>/NOT' : Unused code path elimination
//  Block '<S6>/Zero-Order Hold3' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'controller_pole_placement'
//  '<S1>'   : 'controller_pole_placement/MATLAB Function2'
//  '<S2>'   : 'controller_pole_placement/MATLAB Function3'
//  '<S3>'   : 'controller_pole_placement/Observer'
//  '<S4>'   : 'controller_pole_placement/PX4'
//  '<S5>'   : 'controller_pole_placement/PX4 uORB Read'
//  '<S6>'   : 'controller_pole_placement/Pole Placement Controller Anna'
//  '<S7>'   : 'controller_pole_placement/Sensors'
//  '<S8>'   : 'controller_pole_placement/allocation_logic'
//  '<S9>'   : 'controller_pole_placement/Observer/IMU measurements & rotation'
//  '<S10>'  : 'controller_pole_placement/Observer/MATLAB Function1'
//  '<S11>'  : 'controller_pole_placement/Observer/Observer'
//  '<S12>'  : 'controller_pole_placement/Observer/Subsystem'
//  '<S13>'  : 'controller_pole_placement/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S14>'  : 'controller_pole_placement/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S15>'  : 'controller_pole_placement/Observer/Observer/ filter'
//  '<S16>'  : 'controller_pole_placement/Observer/Observer/ filter1'
//  '<S17>'  : 'controller_pole_placement/Observer/Observer/ filter2'
//  '<S18>'  : 'controller_pole_placement/Observer/Observer/Median Filter'
//  '<S19>'  : 'controller_pole_placement/Observer/Observer/RPY_dot_computation'
//  '<S20>'  : 'controller_pole_placement/Observer/Observer/RP_EKF'
//  '<S21>'  : 'controller_pole_placement/Observer/Observer/RP_computation'
//  '<S22>'  : 'controller_pole_placement/Observer/Observer/Sliding Filter'
//  '<S23>'  : 'controller_pole_placement/Observer/Observer/Y_EKF'
//  '<S24>'  : 'controller_pole_placement/Observer/Observer/Y_computation'
//  '<S25>'  : 'controller_pole_placement/Observer/Observer/Median Filter/MATLAB Function'
//  '<S26>'  : 'controller_pole_placement/Observer/Observer/RP_EKF/EKF_RP'
//  '<S27>'  : 'controller_pole_placement/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S28>'  : 'controller_pole_placement/Observer/Observer/Y_EKF/EKF_Y'
//  '<S29>'  : 'controller_pole_placement/Observer/Subsystem/MATLAB Function1'
//  '<S30>'  : 'controller_pole_placement/Observer/Subsystem/MATLAB Function2'
//  '<S31>'  : 'controller_pole_placement/Observer/Subsystem/MATLAB Function7'
//  '<S32>'  : 'controller_pole_placement/PX4/Acquisition'
//  '<S33>'  : 'controller_pole_placement/PX4/U + BIAS'
//  '<S34>'  : 'controller_pole_placement/PX4/Acquisition/MATLAB Function'
//  '<S35>'  : 'controller_pole_placement/PX4/Acquisition/MATLAB Function1'
//  '<S36>'  : 'controller_pole_placement/PX4/U + BIAS/input1'
//  '<S37>'  : 'controller_pole_placement/PX4/U + BIAS/input2'
//  '<S38>'  : 'controller_pole_placement/PX4/U + BIAS/input3'
//  '<S39>'  : 'controller_pole_placement/PX4/U + BIAS/input4'
//  '<S40>'  : 'controller_pole_placement/PX4 uORB Read/Enabled Subsystem'
//  '<S41>'  : 'controller_pole_placement/Pole Placement Controller Anna/ prefilter'
//  '<S42>'  : 'controller_pole_placement/Pole Placement Controller Anna/LTI System'
//  '<S43>'  : 'controller_pole_placement/Pole Placement Controller Anna/MATLAB Function1'
//  '<S44>'  : 'controller_pole_placement/Pole Placement Controller Anna/MATLAB Function3'
//  '<S45>'  : 'controller_pole_placement/Pole Placement Controller Anna/LTI System/IO Delay'
//  '<S46>'  : 'controller_pole_placement/Pole Placement Controller Anna/LTI System/Input Delay'
//  '<S47>'  : 'controller_pole_placement/Pole Placement Controller Anna/LTI System/Output Delay'
//  '<S48>'  : 'controller_pole_placement/Sensors/Accelerometer'
//  '<S49>'  : 'controller_pole_placement/Sensors/Gyroscope'
//  '<S50>'  : 'controller_pole_placement/Sensors/Magnetometer'
//  '<S51>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles'
//  '<S52>'  : 'controller_pole_placement/Sensors/Vehicle Attitude'
//  '<S53>'  : 'controller_pole_placement/Sensors/correct sequence'
//  '<S54>'  : 'controller_pole_placement/Sensors/Accelerometer/PX4 uORB Read'
//  '<S55>'  : 'controller_pole_placement/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S56>'  : 'controller_pole_placement/Sensors/Gyroscope/PX4 uORB Read'
//  '<S57>'  : 'controller_pole_placement/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S58>'  : 'controller_pole_placement/Sensors/Magnetometer/PX4 uORB Read'
//  '<S59>'  : 'controller_pole_placement/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S60>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S61>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S62>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S63>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S64>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S65>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S66>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S67>'  : 'controller_pole_placement/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S68>'  : 'controller_pole_placement/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S69>'  : 'controller_pole_placement/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                               // RTW_HEADER_controller_pole_placement_h_

//
// File trailer for generated code.
//
// [EOF]
//
