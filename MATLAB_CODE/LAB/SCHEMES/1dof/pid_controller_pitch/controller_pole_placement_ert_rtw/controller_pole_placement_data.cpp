//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_pole_placement_data.cpp
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
#include "controller_pole_placement.h"

// Block parameters (default storage)
P_controller_pole_placement_T controller_pole_placement_P = {
  // Variable: A_cond
  //  Referenced by: '<S6>/MATLAB Function1'

  { 2.278675064291229, 1.0, 0.0, -1.5733104756541718, 0.0, 0.25,
    1.1779159728441675, 0.0, 0.0 },

  // Variable: B_cond
  //  Referenced by: '<S6>/MATLAB Function1'

  { 0.87912087912087911, 0.0, 0.0 },

  // Variable: C
  //  Referenced by: '<S6>/MATLAB Function1'

  { -0.80187955500495423, 1.0436556494956166, -0.96639267537150175 },

  // Variable: D
  //  Referenced by: '<S6>/MATLAB Function1'

  2.275,

  // Variable: P0_phth
  //  Referenced by: '<S20>/Memory3'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 400.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.6580861306901564E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6465823711880742E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 2.8584624305447393E-6 },

  // Variable: P0_ps
  //  Referenced by: '<S23>/Memory3'

  100.0,

  // Variable: Q_phth
  //  Referenced by: '<S20>/EKF_RP'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: R_phth
  //  Referenced by: '<S20>/EKF_RP'

  { 400.0, 0.0, 0.0, 400.0 },

  // Variable: Rz
  //  Referenced by:
  //    '<S9>/Gain'
  //    '<S9>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by:
  //    '<S20>/EKF_RP'
  //    '<S23>/EKF_Y'

  0.001,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S11>/Constant6'
  //    '<S20>/EKF_RP'
  //    '<S23>/EKF_Y'

  0.01,

  // Variable: param
  //  Referenced by: '<Root>/allocation_logic'

  { 0.015, 0.015, 0.03, 0.25, 0.00684324, 0.00703859, 0.00814964, 0.00746697,
    1.14E-7, 0.866 },

  // Variable: q_ps
  //  Referenced by: '<S23>/EKF_Y'

  170.0,

  // Variable: r_ps
  //  Referenced by: '<S23>/EKF_Y'

  200.0,

  // Variable: x0_phth
  //  Referenced by: '<S20>/Memory4'

  { 0.0, 0.0, -0.0079201206542285421, -0.0045187680595803869,
    0.0092138500822308879 },

  // Variable: x0_ps
  //  Referenced by: '<S23>/Memory4'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S69>/Out1'

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
  //  Referenced by: '<S68>/Constant'

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
  //  Referenced by: '<S40>/Out1'

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

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S5>/Constant'

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

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S55>/Out1'

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

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S54>/Constant'

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

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S57>/Out1'

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

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S56>/Constant'

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

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S59>/Out1'

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

  // Computed Parameter: Constant_Value_hr
  //  Referenced by: '<S58>/Constant'

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

  // Expression: -1
  //  Referenced by: '<Root>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S6>/Delay3'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S42>/Internal'

  0.30119421191220208,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S42>/Internal'

  0.698805788087798,

  // Expression: 0
  //  Referenced by: '<S42>/Internal'

  0.0,

  // Expression: 25
  //  Referenced by: '<S6>/Gain'

  25.0,

  // Expression: -0.85
  //  Referenced by: '<S6>/Constant3'

  -0.85,

  // Expression: 0.85
  //  Referenced by: '<S6>/Constant6'

  0.85,

  // Expression: zeros(3,1)
  //  Referenced by: '<S6>/Delay2'

  { 0.0, 0.0, 0.0 },

  // Expression: 1000
  //  Referenced by: '<Root>/Constant1'

  1000.0,

  // Expression: 150
  //  Referenced by: '<Root>/Constant3'

  150.0,

  // Expression: 1000
  //  Referenced by: '<S36>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S37>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S38>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S39>/Constant'

  1000.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay23'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay22'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay21'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay20'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay14'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay13'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay12'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay11'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay10'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay9'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay8'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay7'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay6'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay5'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay4'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S22>/Delay'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S16>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S16>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S16>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S16>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S16>/Discrete Transfer Fcn2'

  0.0,

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay2'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay3'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay4'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay5'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay6'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay7'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay8'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay9'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay10'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay11'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay12'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay13'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay14'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay15'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay20'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay21'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay22'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay23'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay24'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay25'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay26'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay27'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay16'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay17'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay18'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S18>/Delay19'

  { 0.0, 0.0, 0.0 },

  // Expression: 1/20
  //  Referenced by: '<S22>/Gain'

  0.05,

  // Expression: 0.0
  //  Referenced by: '<S20>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S20>/Memory2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S23>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S23>/Memory2'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S17>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S17>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S17>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S17>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S17>/Discrete Transfer Fcn2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S11>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S11>/Memory6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/R ref'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/R ref'

  0.0,

  // Expression: pi/180*(0)
  //  Referenced by: '<Root>/R ref'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant7'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant8'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S12>/Gain2'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S12>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S3>/Gain'

  57.295779513082323,

  // Expression: 3.9
  //  Referenced by: '<Root>/Constant'

  3.9,

  // Expression: 2
  //  Referenced by: '<Root>/Constant5'

  2.0,

  // Expression: pi/180
  //  Referenced by: '<Root>/Gain2'

  0.017453292519943295,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  0.0069999999999999993,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  { 1.0, -0.993 },

  // Expression: 0
  //  Referenced by: '<S41>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S15>/Discrete Transfer Fcn'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S15>/Discrete Transfer Fcn'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S15>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S15>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S15>/Discrete Transfer Fcn2'

  0.0,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S63>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_e5
  //  Referenced by: '<S64>/Constant'

  1.0F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: '<Root>/Gain1'

  57.2957802F,

  // Computed Parameter: Constant6_Value_f
  //  Referenced by: '<Root>/Constant6'

  false,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  false,

  // Computed Parameter: ARMPWM1_Value
  //  Referenced by: '<Root>/ARM PWM1'

  true,

  // Computed Parameter: failsafe_Value
  //  Referenced by: '<S4>/failsafe'

  false,

  // Computed Parameter: startingswitch_CurrentSetting
  //  Referenced by: '<Root>/starting switch'

  0U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
