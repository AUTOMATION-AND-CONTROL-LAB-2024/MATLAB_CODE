//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_1dof_VSC.h
//
// Code generated for Simulink model 'controller_1dof_VSC'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri May 24 12:31:24 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_1dof_VSC_h_
#define RTW_HEADER_controller_1dof_VSC_h_
#include <poll.h>
#include <uORB/uORB.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_PX4_PWM.h"
#include "MW_uORB_Read.h"
#include "controller_1dof_VSC_types.h"
#include <uORB/topics/vehicle_odometry.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/sensor_accel.h>
#include <uORB/topics/sensor_gyro.h>
#include <uORB/topics/sensor_mag.h>
#include <string.h>

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
  uint8_T is_active_c9_controller_1dof_VS;// '<S4>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit;    // '<S4>/MATLAB Function1'
};

// Block signals (default storage)
struct B_controller_1dof_VSC_T {
  px4_Bus_vehicle_odometry In1;        // '<S72>/In1'
  px4_Bus_vehicle_odometry b_varargout_2;
  real_T dv[30];
  real_T TmpSignalConversionAt_asyncqueu[29];
  // '<Root>/TmpSignal ConversionAt_asyncqueue_inserted_for_To Workspace1Inport1' 
  real_T Pt1[25];
  real_T Pt[25];
  real_T At1[25];
  real_T Pt1_m[25];
  real_T dv1[12];
  px4_Bus_actuator_outputs In1_p;      // '<S50>/In1'
  px4_Bus_actuator_outputs b_varargout_2_c;
  real_T Lk[10];
  real_T B[10];
  real_T A_tmp[10];
  real_T dv2[9];
  px4_Bus_sensor_accel b_varargout_2_k;
  px4_Bus_sensor_gyro In1_f;           // '<S60>/In1'
  px4_Bus_sensor_accel In1_c;          // '<S58>/In1'
  px4_Bus_sensor_gyro b_varargout_2_cx;
  px4_Bus_sensor_mag In1_m;            // '<S62>/In1'
  px4_Bus_sensor_mag b_varargout_2_b;
  real_T dv3[6];
  real_T dv4[6];
  real_T dv5[6];
  real_T xt[5];
  real_T minval[4];
  real_T DataTypeConversion3[3];       // '<S25>/Data Type Conversion3'
  real_T Gain[3];                      // '<S4>/Gain'
  real_T Gain_p[3];
  uint16_T pwmValue[8];
  real_T RP_meas[2];
  real_T RP_meas_c[2];
  real32_T Gain1_j[3];                 // '<Root>/Gain1'
  int8_T A_tmp_f[10];
  real_T DigitalClock1;                // '<Root>/Digital Clock1'
  real_T ManualSwitch2[28];            // '<Root>/Manual Switch2'
  real_T v;                            // '<S1>/Sum4'
  real_T Sum7;                         // '<S1>/Sum7'
  real_T u[4];                         // '<Root>/allocation_logic'
  real_T tau_allocated[3];             // '<Root>/allocation_logic'
  real_T y1_l;                         // '<S28>/MATLAB Function7'
  real_T y2_b;                         // '<S28>/MATLAB Function7'
  real_T y3_f;                         // '<S28>/MATLAB Function7'
  real_T y1_f;                         // '<S4>/MATLAB Function1'
  real_T y2_l;                         // '<S4>/MATLAB Function1'
  real_T y3_i;                         // '<S4>/MATLAB Function1'
  real_T y[3];                         // '<S25>/MATLAB Function1'
  real_T y_g[3];                       // '<S25>/MATLAB Function'
  real_T u1;                           // '<Root>/MATLAB Function2'
  real_T u2;                           // '<Root>/MATLAB Function2'
  real_T u3;                           // '<Root>/MATLAB Function2'
  real_T u4;                           // '<Root>/MATLAB Function2'
  real_T tau_o[3];                     // '<S1>/MATLAB Function3'
  real_T u_d;                          // '<S9>/Integrator'
  real32_T SignalConversion[4];        // '<Root>/Signal Conversion'
  real32_T y_l[3];                     // '<S7>/correct sequence'
  real_T ph_meas;
  real_T wq1;
  real_T wr1;
  real_T cph;
  real_T cth;
  real_T sph;
  real_T tth;
  real_T Pt_g;
  real_T Gain9;                        // '<S1>/Gain9'
  real_T d;
  real_T d1;
  real_T Gain6;                        // '<S1>/Gain6'
  real_T Internal;                     // '<S17>/Internal'
  real_T Product;                      // '<S1>/Product'
  real_T RPYref;                       // '<Root>/RPY ref'
  real_T DataTypeConversion;           // '<Root>/Data Type Conversion'
  real_T Gain2_b;                      // '<Root>/Gain2'
  real32_T y1_i;                       // '<Root>/MATLAB Function3'
  real32_T y2_k;                       // '<Root>/MATLAB Function3'
  real32_T y3_d;                       // '<Root>/MATLAB Function3'
  real32_T Product3;                   // '<S64>/Product3'
  real32_T Product2;                   // '<S64>/Product2'
  int32_T b;
  int32_T r1;
};

// Block states (default storage) for system '<Root>'
struct DW_controller_1dof_VSC_T {
  px4_internal_block_PWM_contro_T obj; // '<S5>/PX4 PWM Output'
  px4_internal_block_Subscriber_T obj_m;// '<S71>/SourceBlock'
  px4_internal_block_Subscriber_T obj_c;// '<S61>/SourceBlock'
  px4_internal_block_Subscriber_T obj_d;// '<S59>/SourceBlock'
  px4_internal_block_Subscriber_T obj_f;// '<S57>/SourceBlock'
  px4_internal_block_Subscriber_T obj_dc;// '<S6>/SourceBlock'
  real_T Delay_DSTATE;                 // '<S9>/Delay'
  real_T DiscreteTransferFcn_states;   // '<S36>/Discrete Transfer Fcn'
  real_T DiscreteTransferFcn1_states;  // '<S36>/Discrete Transfer Fcn1'
  real_T DiscreteTransferFcn2_states;  // '<S36>/Discrete Transfer Fcn2'
  real_T Delay2_DSTATE[3];             // '<S32>/Delay2'
  real_T Delay2_DSTATE_b[3];           // '<S34>/Delay2'
  real_T Internal_DSTATE;              // '<S17>/Internal'
  real_T Internal_DSTATE_h;            // '<S18>/Internal'
  real_T Internal_DSTATE_f;            // '<S10>/Internal'
  real_T DiscreteTimeIntegrator1_DSTATE;// '<S1>/Discrete-Time Integrator1'
  real_T Memory_PreviousInput;         // '<S9>/Memory'
  real_T Memory4_PreviousInput[5];     // '<S32>/Memory4'
  real_T Memory2_PreviousInput;        // '<S32>/Memory2'
  real_T Memory3_PreviousInput[25];    // '<S32>/Memory3'
  real_T Memory4_PreviousInput_e;      // '<S34>/Memory4'
  real_T Memory3_PreviousInput_h;      // '<S34>/Memory3'
  real_T Memory2_PreviousInput_p;      // '<S34>/Memory2'
  real_T Memory5_PreviousInput;        // '<S27>/Memory5'
  real_T Memory6_PreviousInput[3];     // '<S27>/Memory6'
  struct {
    void *LoggedData;
  } PWM_PWORK;                         // '<Root>/PWM'

  struct {
    void *LoggedData[2];
  } TAU_PWORK;                         // '<Root>/TAU'

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      // '<S1>/Scope8'

  struct {
    void *LoggedData;
  } ERROR1_PWORK;                      // '<S1>/ERROR1'

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

  int8_T EnabledSubsystem_SubsysRanBC; // '<S71>/Enabled Subsystem'
  int8_T IfActionSubsystem2_SubsysRanBC;// '<S65>/If Action Subsystem2'
  int8_T IfActionSubsystem1_SubsysRanBC;// '<S65>/If Action Subsystem1'
  int8_T IfActionSubsystem_SubsysRanBC;// '<S65>/If Action Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_a;// '<S61>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_i;// '<S59>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_iw;// '<S57>/Enabled Subsystem'
  int8_T EnabledSubsystem_SubsysRanBC_p;// '<S6>/Enabled Subsystem'
  uint8_T is_active_c17_controller_1dof_V;// '<Root>/allocation_logic'
  uint8_T is_active_c12_controller_1dof_V;// '<S7>/correct sequence'
  uint8_T is_active_c6_controller_1dof_VS;// '<S43>/MATLAB Function'
  uint8_T is_active_c13_controller_1dof_V;// '<S28>/MATLAB Function2'
  uint8_T is_active_c24_controller_1dof_V;// '<S28>/MATLAB Function1'
  uint8_T is_active_c2_controller_1dof_VS;// '<S27>/Y_computation'
  uint8_T is_active_c3_controller_1dof_VS;// '<S34>/EKF_Y'
  uint8_T is_active_c4_controller_1dof_VS;// '<S27>/RP_computation'
  uint8_T is_active_c8_controller_1dof_VS;// '<S32>/MATLAB Function'
  uint8_T is_active_c5_controller_1dof_VS;// '<S32>/EKF_RP'
  uint8_T is_active_c11_controller_1dof_V;// '<S27>/RPY_dot_computation'
  uint8_T is_active_c1_controller_1dof_VS;// '<S25>/MATLAB Function1'
  uint8_T is_active_c10_controller_1dof_V;// '<S25>/MATLAB Function'
  uint8_T is_active_c7_controller_1dof_VS;// '<Root>/MATLAB Function3'
  uint8_T is_active_c16_controller_1dof_V;// '<Root>/MATLAB Function2'
  uint8_T is_active_c19_controller_1dof_V;// '<S1>/MATLAB Function3'
  uint8_T is_active_c14_controller_1dof_V;// '<S9>/Integrator'
  boolean_T Relay1_Mode;               // '<S1>/Relay1'
  boolean_T doneDoubleBufferReInit;    // '<Root>/allocation_logic'
  boolean_T doneDoubleBufferReInit_n;  // '<S7>/correct sequence'
  boolean_T doneDoubleBufferReInit_d;  // '<S43>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_dr; // '<S28>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_p;  // '<S28>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_g;  // '<S27>/Y_computation'
  boolean_T doneDoubleBufferReInit_c;  // '<S34>/EKF_Y'
  boolean_T doneDoubleBufferReInit_g2; // '<S27>/RP_computation'
  boolean_T doneDoubleBufferReInit_df; // '<S32>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_l;  // '<S32>/EKF_RP'
  boolean_T doneDoubleBufferReInit_l2; // '<S27>/RPY_dot_computation'
  boolean_T doneDoubleBufferReInit_a;  // '<S25>/MATLAB Function1'
  boolean_T doneDoubleBufferReInit_da; // '<S25>/MATLAB Function'
  boolean_T doneDoubleBufferReInit_i;  // '<Root>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_m;  // '<Root>/MATLAB Function2'
  boolean_T doneDoubleBufferReInit_f;  // '<S1>/MATLAB Function3'
  boolean_T doneDoubleBufferReInit_ds; // '<S9>/Integrator'
  DW_MATLABFunction1_controller_T sf_MATLABFunction7;// '<S28>/MATLAB Function7' 
  DW_MATLABFunction1_controller_T sf_MATLABFunction1_p;// '<S4>/MATLAB Function1' 
};

// Parameters (default storage)
struct P_controller_1dof_VSC_T_ {
  real_T P0_phth[25];                  // Variable: P0_phth
                                          //  Referenced by: '<S32>/Memory3'

  real_T P0_ps;                        // Variable: P0_ps
                                          //  Referenced by: '<S34>/Memory3'

  real_T Q_phth[25];                   // Variable: Q_phth
                                          //  Referenced by: '<S32>/EKF_RP'

  real_T R_phth[4];                    // Variable: R_phth
                                          //  Referenced by: '<S32>/EKF_RP'

  real_T Rz[9];                        // Variable: Rz
                                          //  Referenced by:
                                          //    '<S25>/Gain'
                                          //    '<S25>/Gain1'

  real_T Ts_EKF_integr;                // Variable: Ts_EKF_integr
                                          //  Referenced by:
                                          //    '<S32>/EKF_RP'
                                          //    '<S34>/EKF_Y'

  real_T Ts_EKF_meas;                  // Variable: Ts_EKF_meas
                                          //  Referenced by:
                                          //    '<S27>/Constant6'
                                          //    '<S32>/EKF_RP'
                                          //    '<S34>/EKF_Y'

  real_T Ts_slk;                       // Variable: Ts_slk
                                          //  Referenced by: '<S9>/Integrator'

  real_T alpha_t_en[3];                // Variable: alpha_t_en
                                          //  Referenced by: '<S1>/Gain6'

  real_T beta_t_en[3];                 // Variable: beta_t_en
                                          //  Referenced by: '<S1>/Gain7'

  real_T epsilon;                      // Variable: epsilon
                                          //  Referenced by: '<S1>/Gain11'

  real_T param[10];                    // Variable: param
                                          //  Referenced by: '<Root>/allocation_logic'

  real_T q_en;                         // Variable: q_en
                                          //  Referenced by: '<S1>/Gain9'

  real_T q_ps;                         // Variable: q_ps
                                          //  Referenced by: '<S34>/EKF_Y'

  real_T r;                            // Variable: r
                                          //  Referenced by: '<S1>/Gain8'

  real_T r_ps;                         // Variable: r_ps
                                          //  Referenced by: '<S34>/EKF_Y'

  real_T x0_phth[5];                   // Variable: x0_phth
                                          //  Referenced by: '<S32>/Memory4'

  real_T x0_ps;                        // Variable: x0_ps
                                          //  Referenced by: '<S34>/Memory4'

  px4_Bus_vehicle_odometry Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S72>/Out1'

  px4_Bus_vehicle_odometry Constant_Value;// Computed Parameter: Constant_Value
                                             //  Referenced by: '<S71>/Constant'

  px4_Bus_actuator_outputs Out1_Y0_k;  // Computed Parameter: Out1_Y0_k
                                          //  Referenced by: '<S50>/Out1'

  px4_Bus_actuator_outputs Constant_Value_b;// Computed Parameter: Constant_Value_b
                                               //  Referenced by: '<S6>/Constant'

  px4_Bus_sensor_accel Out1_Y0_h;      // Computed Parameter: Out1_Y0_h
                                          //  Referenced by: '<S58>/Out1'

  px4_Bus_sensor_accel Constant_Value_n;// Computed Parameter: Constant_Value_n
                                           //  Referenced by: '<S57>/Constant'

  px4_Bus_sensor_gyro Out1_Y0_hr;      // Computed Parameter: Out1_Y0_hr
                                          //  Referenced by: '<S60>/Out1'

  px4_Bus_sensor_gyro Constant_Value_l;// Computed Parameter: Constant_Value_l
                                          //  Referenced by: '<S59>/Constant'

  px4_Bus_sensor_mag Out1_Y0_kk;       // Computed Parameter: Out1_Y0_kk
                                          //  Referenced by: '<S62>/Out1'

  px4_Bus_sensor_mag Constant_Value_m; // Computed Parameter: Constant_Value_m
                                          //  Referenced by: '<S61>/Constant'

  real_T Constant_Value_d;             // Expression: 0
                                          //  Referenced by: '<S43>/Constant'

  real_T Constant1_Value;              // Expression: 0
                                          //  Referenced by: '<S43>/Constant1'

  real_T Delay_InitialCondition;       // Expression: 0.0
                                          //  Referenced by: '<S9>/Delay'

  real_T Memory_InitialCondition;      // Expression: 0
                                          //  Referenced by: '<S9>/Memory'

  real_T Constant_Value_c;             // Expression: 0.9
                                          //  Referenced by: '<S9>/Constant'

  real_T Constant1_Value_d;            // Expression: -0.9
                                          //  Referenced by: '<S9>/Constant1'

  real_T Constant1_Value_j;            // Expression: 1000
                                          //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value;              // Expression: 150
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value_n0;            // Expression: 1000
                                          //  Referenced by: '<S46>/Constant'

  real_T Constant_Value_ln;            // Expression: 1000
                                          //  Referenced by: '<S47>/Constant'

  real_T Constant_Value_bn;            // Expression: 1000
                                          //  Referenced by: '<S48>/Constant'

  real_T Constant_Value_ch;            // Expression: 1000
                                          //  Referenced by: '<S49>/Constant'

  real_T DiscreteTransferFcn_NumCoef;  // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S36>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                           //  Referenced by: '<S36>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn_InitialStat;// Expression: 0
                                            //  Referenced by: '<S36>/Discrete Transfer Fcn'

  real_T DiscreteTransferFcn1_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn1_InitialSta;// Expression: 0
                                            //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  real_T DiscreteTransferFcn2_NumCoef; // Expression: [Ts_slk*p]
                                          //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_DenCoef[2];// Expression: [1 (Ts_slk*p-1)]
                                            //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  real_T DiscreteTransferFcn2_InitialSta;// Expression: 0
                                            //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  real_T Delay2_InitialCondition;      // Expression: 0.0
                                          //  Referenced by: '<S32>/Delay2'

  real_T Memory2_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S32>/Memory2'

  real_T Delay2_InitialCondition_l;    // Expression: 0.0
                                          //  Referenced by: '<S34>/Delay2'

  real_T Memory2_InitialCondition_g;   // Expression: 0
                                          //  Referenced by: '<S34>/Memory2'

  real_T Memory5_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S27>/Memory5'

  real_T Memory6_InitialCondition;     // Expression: 0
                                          //  Referenced by: '<S27>/Memory6'

  real_T RPYref_Time;                  // Expression: 0
                                          //  Referenced by: '<Root>/RPY ref'

  real_T RPYref_Y0;                    // Expression: 0
                                          //  Referenced by: '<Root>/RPY ref'

  real_T RPYref_YFinal;                // Expression: pi/180*(0)
                                          //  Referenced by: '<Root>/RPY ref'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S28>/Gain2'

  real_T Gain1_Gain;                   // Expression: 180/pi
                                          //  Referenced by: '<S28>/Gain1'

  real_T Gain_Gain;                    // Expression: 180/pi
                                          //  Referenced by: '<S4>/Gain'

  real_T Internal_A;                   // Computed Parameter: Internal_A
                                          //  Referenced by: '<S17>/Internal'

  real_T Internal_B;                   // Computed Parameter: Internal_B
                                          //  Referenced by: '<S17>/Internal'

  real_T Internal_C;                   // Computed Parameter: Internal_C
                                          //  Referenced by: '<S17>/Internal'

  real_T Internal_InitialCondition;    // Expression: 0
                                          //  Referenced by: '<S17>/Internal'

  real_T Internal_A_d;                 // Computed Parameter: Internal_A_d
                                          //  Referenced by: '<S18>/Internal'

  real_T Internal_B_f;                 // Computed Parameter: Internal_B_f
                                          //  Referenced by: '<S18>/Internal'

  real_T Internal_C_a;                 // Computed Parameter: Internal_C_a
                                          //  Referenced by: '<S18>/Internal'

  real_T Internal_InitialCondition_p;  // Expression: 0
                                          //  Referenced by: '<S18>/Internal'

  real_T Internal_A_n;                 // Computed Parameter: Internal_A_n
                                          //  Referenced by: '<S10>/Internal'

  real_T Internal_B_p;                 // Computed Parameter: Internal_B_p
                                          //  Referenced by: '<S10>/Internal'

  real_T Internal_C_g;                 // Computed Parameter: Internal_C_g
                                          //  Referenced by: '<S10>/Internal'

  real_T Internal_InitialCondition_k;  // Expression: 0
                                          //  Referenced by: '<S10>/Internal'

  real_T DiscreteTimeIntegrator1_gainval;
                          // Computed Parameter: DiscreteTimeIntegrator1_gainval
                             //  Referenced by: '<S1>/Discrete-Time Integrator1'

  real_T DiscreteTimeIntegrator1_IC;   // Expression: 0
                                          //  Referenced by: '<S1>/Discrete-Time Integrator1'

  real_T Gain3_Gain;                   // Expression: 1000
                                          //  Referenced by: '<S1>/Gain3'

  real_T Gain_Gain_o;                  // Expression: 60
                                          //  Referenced by: '<S1>/Gain'

  real_T Relay1_OnVal;                 // Expression: 0.001
                                          //  Referenced by: '<S1>/Relay1'

  real_T Relay1_OffVal;                // Expression: -0.001
                                          //  Referenced by: '<S1>/Relay1'

  real_T Relay1_YOn;                   // Expression: 1
                                          //  Referenced by: '<S1>/Relay1'

  real_T Relay1_YOff;                  // Expression: -1
                                          //  Referenced by: '<S1>/Relay1'

  real_T Gain1_Gain_k;                 // Expression: 10
                                          //  Referenced by: '<S1>/Gain1'

  real_T Gain2_Gain_a;                 // Expression: 1
                                          //  Referenced by: '<S1>/Gain2'

  real_T Constant_Value_be;            // Expression: 3.9
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain2_Gain_n;                 // Expression: pi/180
                                          //  Referenced by: '<Root>/Gain2'

  real32_T Constant_Value_g;           // Computed Parameter: Constant_Value_g
                                          //  Referenced by: '<S66>/Constant'

  real32_T Constant_Value_k;           // Computed Parameter: Constant_Value_k
                                          //  Referenced by: '<S67>/Constant'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<Root>/Gain1'

  boolean_T Constant6_Value;           // Computed Parameter: Constant6_Value
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
struct tag_RTM_controller_1dof_VSC_T {
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

  extern P_controller_1dof_VSC_T controller_1dof_VSC_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_controller_1dof_VSC_T controller_1dof_VSC_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_controller_1dof_VSC_T controller_1dof_VSC_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void controller_1dof_VSC_initialize(void);
  extern void controller_1dof_VSC_step(void);
  extern void controller_1dof_VSC_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_controller_1dof_VSC_T *const controller_1dof_VSC_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S6>/NOT' : Unused code path elimination
//  Block '<S57>/NOT' : Unused code path elimination
//  Block '<S59>/NOT' : Unused code path elimination
//  Block '<S61>/NOT' : Unused code path elimination
//  Block '<S71>/NOT' : Unused code path elimination
//  Block '<S1>/Zero-Order Hold4' : Eliminated since input and output rates are identical


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
//  '<Root>' : 'controller_1dof_VSC'
//  '<S1>'   : 'controller_1dof_VSC/Controller Anna'
//  '<S2>'   : 'controller_1dof_VSC/MATLAB Function2'
//  '<S3>'   : 'controller_1dof_VSC/MATLAB Function3'
//  '<S4>'   : 'controller_1dof_VSC/Observer'
//  '<S5>'   : 'controller_1dof_VSC/PX4'
//  '<S6>'   : 'controller_1dof_VSC/PX4 uORB Read'
//  '<S7>'   : 'controller_1dof_VSC/Sensors'
//  '<S8>'   : 'controller_1dof_VSC/allocation_logic'
//  '<S9>'   : 'controller_1dof_VSC/Controller Anna/Integrator'
//  '<S10>'  : 'controller_1dof_VSC/Controller Anna/LTI System'
//  '<S11>'  : 'controller_1dof_VSC/Controller Anna/MATLAB Function3'
//  '<S12>'  : 'controller_1dof_VSC/Controller Anna/Subsystem'
//  '<S13>'  : 'controller_1dof_VSC/Controller Anna/Integrator/Integrator'
//  '<S14>'  : 'controller_1dof_VSC/Controller Anna/LTI System/IO Delay'
//  '<S15>'  : 'controller_1dof_VSC/Controller Anna/LTI System/Input Delay'
//  '<S16>'  : 'controller_1dof_VSC/Controller Anna/LTI System/Output Delay'
//  '<S17>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System1'
//  '<S18>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System2'
//  '<S19>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System1/IO Delay'
//  '<S20>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System1/Input Delay'
//  '<S21>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System1/Output Delay'
//  '<S22>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System2/IO Delay'
//  '<S23>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System2/Input Delay'
//  '<S24>'  : 'controller_1dof_VSC/Controller Anna/Subsystem/LTI System2/Output Delay'
//  '<S25>'  : 'controller_1dof_VSC/Observer/IMU measurements & rotation'
//  '<S26>'  : 'controller_1dof_VSC/Observer/MATLAB Function1'
//  '<S27>'  : 'controller_1dof_VSC/Observer/Observer'
//  '<S28>'  : 'controller_1dof_VSC/Observer/Subsystem'
//  '<S29>'  : 'controller_1dof_VSC/Observer/IMU measurements & rotation/MATLAB Function'
//  '<S30>'  : 'controller_1dof_VSC/Observer/IMU measurements & rotation/MATLAB Function1'
//  '<S31>'  : 'controller_1dof_VSC/Observer/Observer/RPY_dot_computation'
//  '<S32>'  : 'controller_1dof_VSC/Observer/Observer/RP_EKF'
//  '<S33>'  : 'controller_1dof_VSC/Observer/Observer/RP_computation'
//  '<S34>'  : 'controller_1dof_VSC/Observer/Observer/Y_EKF'
//  '<S35>'  : 'controller_1dof_VSC/Observer/Observer/Y_computation'
//  '<S36>'  : 'controller_1dof_VSC/Observer/Observer/acceleration filter'
//  '<S37>'  : 'controller_1dof_VSC/Observer/Observer/RP_EKF/EKF_RP'
//  '<S38>'  : 'controller_1dof_VSC/Observer/Observer/RP_EKF/MATLAB Function'
//  '<S39>'  : 'controller_1dof_VSC/Observer/Observer/Y_EKF/EKF_Y'
//  '<S40>'  : 'controller_1dof_VSC/Observer/Subsystem/MATLAB Function1'
//  '<S41>'  : 'controller_1dof_VSC/Observer/Subsystem/MATLAB Function2'
//  '<S42>'  : 'controller_1dof_VSC/Observer/Subsystem/MATLAB Function7'
//  '<S43>'  : 'controller_1dof_VSC/PX4/Acquisition'
//  '<S44>'  : 'controller_1dof_VSC/PX4/U + BIAS'
//  '<S45>'  : 'controller_1dof_VSC/PX4/Acquisition/MATLAB Function'
//  '<S46>'  : 'controller_1dof_VSC/PX4/U + BIAS/input1'
//  '<S47>'  : 'controller_1dof_VSC/PX4/U + BIAS/input2'
//  '<S48>'  : 'controller_1dof_VSC/PX4/U + BIAS/input3'
//  '<S49>'  : 'controller_1dof_VSC/PX4/U + BIAS/input4'
//  '<S50>'  : 'controller_1dof_VSC/PX4 uORB Read/Enabled Subsystem'
//  '<S51>'  : 'controller_1dof_VSC/Sensors/Accelerometer'
//  '<S52>'  : 'controller_1dof_VSC/Sensors/Gyroscope'
//  '<S53>'  : 'controller_1dof_VSC/Sensors/Magnetometer'
//  '<S54>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles'
//  '<S55>'  : 'controller_1dof_VSC/Sensors/Vehicle Attitude'
//  '<S56>'  : 'controller_1dof_VSC/Sensors/correct sequence'
//  '<S57>'  : 'controller_1dof_VSC/Sensors/Accelerometer/PX4 uORB Read'
//  '<S58>'  : 'controller_1dof_VSC/Sensors/Accelerometer/PX4 uORB Read/Enabled Subsystem'
//  '<S59>'  : 'controller_1dof_VSC/Sensors/Gyroscope/PX4 uORB Read'
//  '<S60>'  : 'controller_1dof_VSC/Sensors/Gyroscope/PX4 uORB Read/Enabled Subsystem'
//  '<S61>'  : 'controller_1dof_VSC/Sensors/Magnetometer/PX4 uORB Read'
//  '<S62>'  : 'controller_1dof_VSC/Sensors/Magnetometer/PX4 uORB Read/Enabled Subsystem'
//  '<S63>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Angle Calculation'
//  '<S64>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Quaternion Normalize'
//  '<S65>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input'
//  '<S66>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem'
//  '<S67>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem1'
//  '<S68>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Angle Calculation/Protect asincos input/If Action Subsystem2'
//  '<S69>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus'
//  '<S70>'  : 'controller_1dof_VSC/Sensors/Quaternions to Rotation Angles/Quaternion Normalize/Quaternion Modulus/Quaternion Norm'
//  '<S71>'  : 'controller_1dof_VSC/Sensors/Vehicle Attitude/PX4 uORB Read'
//  '<S72>'  : 'controller_1dof_VSC/Sensors/Vehicle Attitude/PX4 uORB Read/Enabled Subsystem'

#endif                                 // RTW_HEADER_controller_1dof_VSC_h_

//
// File trailer for generated code.
//
// [EOF]
//
