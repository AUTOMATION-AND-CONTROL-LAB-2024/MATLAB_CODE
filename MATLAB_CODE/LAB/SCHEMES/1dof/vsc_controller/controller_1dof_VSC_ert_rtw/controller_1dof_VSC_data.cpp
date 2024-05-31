//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_1dof_VSC_data.cpp
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
#include "controller_1dof_VSC.h"

// Block parameters (default storage)
P_controller_1dof_VSC_T controller_1dof_VSC_P = {
  // Variable: P0_phth
  //  Referenced by: '<S32>/Memory3'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.6580861306901564E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6465823711880742E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 2.8584624305447393E-6 },

  // Variable: P0_ps
  //  Referenced by: '<S34>/Memory3'

  100.0,

  // Variable: Q_phth
  //  Referenced by: '<S32>/EKF_RP'

  { 90.0, 0.0, 0.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: R_phth
  //  Referenced by: '<S32>/EKF_RP'

  { 80.0, 0.0, 0.0, 140.0 },

  // Variable: Rz
  //  Referenced by:
  //    '<S25>/Gain'
  //    '<S25>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by:
  //    '<S32>/EKF_RP'
  //    '<S34>/EKF_Y'

  0.0001,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S27>/Constant6'
  //    '<S32>/EKF_RP'
  //    '<S34>/EKF_Y'

  0.01,

  // Variable: Ts_slk
  //  Referenced by: '<S9>/Integrator'

  0.01,

  // Variable: alpha_t_en
  //  Referenced by: '<S1>/Gain6'

  { 0.0, 1.0, 2.0 },

  // Variable: beta_t_en
  //  Referenced by: '<S1>/Gain7'

  { 1.0, 2.0, 1.0 },

  // Variable: epsilon
  //  Referenced by: '<S1>/Gain11'

  13.0,

  // Variable: param
  //  Referenced by: '<Root>/allocation_logic'

  { 0.015, 0.015, 0.03, 0.25, 0.00684324, 0.00703859, 0.00814964, 0.00746697,
    1.14E-7, 0.866 },

  // Variable: q_en
  //  Referenced by: '<S1>/Gain9'

  0.23500000000000001,

  // Variable: q_ps
  //  Referenced by: '<S34>/EKF_Y'

  170.0,

  // Variable: r
  //  Referenced by: '<S1>/Gain8'

  1.0,

  // Variable: r_ps
  //  Referenced by: '<S34>/EKF_Y'

  200.0,

  // Variable: x0_phth
  //  Referenced by: '<S32>/Memory4'

  { 0.0, 0.0, -0.0079201206542285421, -0.0045187680595803869,
    0.0092138500822308879 },

  // Variable: x0_ps
  //  Referenced by: '<S34>/Memory4'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S72>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S71>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q

    {
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // q_offset

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // pose_covariance
    0.0F,                              // vx
    0.0F,                              // vy
    0.0F,                              // vz
    0.0F,                              // rollspeed
    0.0F,                              // pitchspeed
    0.0F,                              // yawspeed

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // velocity_covariance
    0U,                                // local_frame
    0U,                                // velocity_frame

    {
      0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S50>/Out1'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S6>/Constant'

  {
    (0ULL),                            // timestamp
    0U,                                // noutputs

    {
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // output

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S58>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S57>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_hr
  //  Referenced by: '<S60>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count
    0U,                                // samples

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S59>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count
    0U,                                // samples

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_kk
  //  Referenced by: '<S62>/Out1'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S61>/Constant'

  {
    (0ULL),                            // timestamp
    (0ULL),                            // timestamp_sample
    0U,                                // device_id
    0.0F,                              // x
    0.0F,                              // y
    0.0F,                              // z
    0.0F,                              // temperature
    0U,                                // error_count
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0
  //  Referenced by: '<S43>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S43>/Constant1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S9>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Memory'

  0.0,

  // Expression: 0.9
  //  Referenced by: '<S9>/Constant'

  0.9,

  // Expression: -0.9
  //  Referenced by: '<S9>/Constant1'

  -0.9,

  // Expression: 1000
  //  Referenced by: '<Root>/Constant1'

  1000.0,

  // Expression: 150
  //  Referenced by: '<Root>/Constant3'

  150.0,

  // Expression: 1000
  //  Referenced by: '<S46>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S47>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S48>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S49>/Constant'

  1000.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S36>/Discrete Transfer Fcn2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S32>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S32>/Memory2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S34>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S34>/Memory2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S27>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S27>/Memory6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RPY ref'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RPY ref'

  0.0,

  // Expression: pi/180*(0)
  //  Referenced by: '<Root>/RPY ref'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S28>/Gain2'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S28>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S4>/Gain'

  57.295779513082323,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S17>/Internal'

  0.81873075307798182,

  // Computed Parameter: Internal_B
  //  Referenced by: '<S17>/Internal'

  0.5,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S17>/Internal'

  0.36253849384403625,

  // Expression: 0
  //  Referenced by: '<S17>/Internal'

  0.0,

  // Computed Parameter: Internal_A_d
  //  Referenced by: '<S18>/Internal'

  0.81873075307798182,

  // Computed Parameter: Internal_B_f
  //  Referenced by: '<S18>/Internal'

  0.5,

  // Computed Parameter: Internal_C_a
  //  Referenced by: '<S18>/Internal'

  0.36253849384403625,

  // Expression: 0
  //  Referenced by: '<S18>/Internal'

  0.0,

  // Computed Parameter: Internal_A_n
  //  Referenced by: '<S10>/Internal'

  0.81873075307798182,

  // Computed Parameter: Internal_B_p
  //  Referenced by: '<S10>/Internal'

  0.5,

  // Computed Parameter: Internal_C_g
  //  Referenced by: '<S10>/Internal'

  0.36253849384403625,

  // Expression: 0
  //  Referenced by: '<S10>/Internal'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S1>/Discrete-Time Integrator1'

  0.01,

  // Expression: 0
  //  Referenced by: '<S1>/Discrete-Time Integrator1'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S1>/Gain3'

  1000.0,

  // Expression: 60
  //  Referenced by: '<S1>/Gain'

  60.0,

  // Expression: 0.001
  //  Referenced by: '<S1>/Relay1'

  0.001,

  // Expression: -0.001
  //  Referenced by: '<S1>/Relay1'

  -0.001,

  // Expression: 1
  //  Referenced by: '<S1>/Relay1'

  1.0,

  // Expression: -1
  //  Referenced by: '<S1>/Relay1'

  -1.0,

  // Expression: 10
  //  Referenced by: '<S1>/Gain1'

  10.0,

  // Expression: 1
  //  Referenced by: '<S1>/Gain2'

  1.0,

  // Expression: 3.9
  //  Referenced by: '<Root>/Constant'

  3.9,

  // Expression: pi/180
  //  Referenced by: '<Root>/Gain2'

  0.017453292519943295,

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S66>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S67>/Constant'

  1.0F,

  // Computed Parameter: Gain1_Gain_d
  //  Referenced by: '<Root>/Gain1'

  57.2957802F,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<Root>/Constant6'

  false,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  false,

  // Computed Parameter: ARMPWM1_Value
  //  Referenced by: '<Root>/ARM PWM1'

  true,

  // Computed Parameter: failsafe_Value
  //  Referenced by: '<S5>/failsafe'

  false,

  // Computed Parameter: startingswitch_CurrentSetting
  //  Referenced by: '<Root>/starting switch'

  0U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
