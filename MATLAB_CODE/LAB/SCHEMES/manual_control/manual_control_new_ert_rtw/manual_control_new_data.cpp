//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_control_new_data.cpp
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
#include "manual_control_new.h"

// Block parameters (default storage)
P_manual_control_new_T manual_control_new_P = {
  // Variable: P0_phth
  //  Referenced by: '<S16>/Memory3'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 400.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.6580861306901564E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6465823711880742E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 2.8584624305447393E-6 },

  // Variable: P0_ps
  //  Referenced by: '<S19>/Memory3'

  100.0,

  // Variable: Q_phth
  //  Referenced by: '<S16>/EKF_RP'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: R_phth
  //  Referenced by: '<S16>/EKF_RP'

  { 400.0, 0.0, 0.0, 400.0 },

  // Variable: Rz
  //  Referenced by:
  //    '<S5>/Gain'
  //    '<S5>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by:
  //    '<S16>/EKF_RP'
  //    '<S19>/EKF_Y'

  0.001,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S7>/Constant6'
  //    '<S16>/EKF_RP'
  //    '<S19>/EKF_Y'

  0.01,

  // Variable: q_ps
  //  Referenced by: '<S19>/EKF_Y'

  170.0,

  // Variable: r_ps
  //  Referenced by: '<S19>/EKF_Y'

  200.0,

  // Variable: x0_phth
  //  Referenced by: '<S16>/Memory4'

  { 0.0, 0.0, -0.0079201206542285421, -0.0045187680595803869,
    0.0092138500822308879 },

  // Variable: x0_ps
  //  Referenced by: '<S19>/Memory4'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S56>/Out1'

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
  //  Referenced by: '<S55>/Constant'

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

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S42>/Out1'

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
  //  Referenced by: '<S41>/Constant'

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
  //  Referenced by: '<S44>/Out1'

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
  //  Referenced by: '<S43>/Constant'

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
  //  Referenced by: '<S46>/Out1'

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

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S45>/Constant'

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

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Motor1'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S31>/Constant'

  1000.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant3'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Motor2'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S32>/Constant'

  1000.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant5'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Motor3'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S33>/Constant'

  1000.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant1'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Motor4'

  0.0,

  // Expression: 1000
  //  Referenced by: '<S34>/Constant'

  1000.0,

  // Expression: 0.0
  //  Referenced by: '<S16>/Delay2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay23'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay22'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay21'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay20'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay14'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay13'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay12'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay11'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay10'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay9'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay8'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay7'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay6'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay5'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay4'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S18>/Delay'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S12>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S12>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S12>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S12>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S12>/Discrete Transfer Fcn2'

  0.0,

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay2'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay3'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay4'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay5'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay6'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay7'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay8'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay9'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay10'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay11'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay12'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay13'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay14'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay15'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay20'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay21'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay22'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay23'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay24'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay25'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay26'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay27'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay16'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay17'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay18'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S14>/Delay19'

  { 0.0, 0.0, 0.0 },

  // Expression: 1/20
  //  Referenced by: '<S18>/Gain'

  0.05,

  // Expression: 0
  //  Referenced by: '<S16>/Memory2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S19>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/Memory2'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S13>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S13>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S13>/Discrete Transfer Fcn2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Memory6'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S8>/Gain2'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S8>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S2>/Gain'

  57.295779513082323,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S11>/Discrete Transfer Fcn'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S11>/Discrete Transfer Fcn'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S11>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S11>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S11>/Discrete Transfer Fcn2'

  0.0,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S50>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_e5
  //  Referenced by: '<S51>/Constant'

  1.0F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: '<Root>/Gain1'

  57.2957802F,

  // Computed Parameter: Constant6_Value
  //  Referenced by: '<Root>/Constant6'

  { false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false },

  // Computed Parameter: ARMPWM1_Value
  //  Referenced by: '<Root>/ARM PWM1'

  true,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  false,

  // Computed Parameter: failsafe_Value
  //  Referenced by: '<S3>/failsafe'

  false,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  1U,

  // Computed Parameter: startingswitch_CurrentSetting
  //  Referenced by: '<Root>/starting switch'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
