//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: h2_controller_pitch_data.cpp
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
#include "h2_controller_pitch.h"

// Block parameters (default storage)
P_h2_controller_pitch_T h2_controller_pitch_P = {
  // Variable: A_cond
  //  Referenced by: '<S1>/MATLAB Function1'

  { 3.9585755221906189, 2.0, 0.0, 0.0, -2.9384400774184076, 0.0, 1.0, 0.0,
    1.9390095503674996, 0.0, 0.0, 0.5, -0.95971453996266, 0.0, 0.0, 0.0 },

  // Variable: B_cond
  //  Referenced by: '<S1>/MATLAB Function1'

  { 2.0, 0.0, 0.0, 0.0 },

  // Variable: C
  //  Referenced by: '<S1>/MATLAB Function1'

  { -0.34302186457830319, 0.51482119393369419, -0.51510593040824015,
    0.34359137346432361 },

  // Variable: D
  //  Referenced by: '<S1>/MATLAB Function1'

  1.0,

  // Variable: K
  //  Referenced by: '<S1>/MATLAB Function1'

  { -0.1765895940704163, -0.1803639314174334 },

  // Variable: P0_phth
  //  Referenced by: '<S28>/Memory3'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 400.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.6580861306901564E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 2.6465823711880742E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 2.8584624305447393E-6 },

  // Variable: P0_ps
  //  Referenced by: '<S31>/Memory3'

  100.0,

  // Variable: Q_phth
  //  Referenced by: '<S28>/EKF_RP'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: R_phth
  //  Referenced by: '<S28>/EKF_RP'

  { 400.0, 0.0, 0.0, 400.0 },

  // Variable: Rz
  //  Referenced by:
  //    '<S17>/Gain'
  //    '<S17>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by:
  //    '<S28>/EKF_RP'
  //    '<S31>/EKF_Y'

  0.001,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S19>/Constant6'
  //    '<S28>/EKF_RP'
  //    '<S31>/EKF_Y'

  0.01,

  // Variable: param
  //  Referenced by: '<Root>/allocation_logic'

  { 0.015, 0.015, 0.03, 0.25, 0.00684324, 0.00703859, 0.00814964, 0.00746697,
    1.14E-7, 0.866 },

  // Variable: q_ps
  //  Referenced by: '<S31>/EKF_Y'

  170.0,

  // Variable: r_ps
  //  Referenced by: '<S31>/EKF_Y'

  200.0,

  // Variable: x0_phth
  //  Referenced by: '<S28>/Memory4'

  { 0.0, 0.0, -0.0079201206542285421, -0.0045187680595803869,
    0.0092138500822308879 },

  // Variable: x0_ps
  //  Referenced by: '<S31>/Memory4'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S70>/Out1'

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
  //  Referenced by: '<S69>/Constant'

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
  //  Referenced by: '<S48>/Out1'

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

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S56>/Out1'

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
  //  Referenced by: '<S55>/Constant'

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
    0U,                                // samples

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_e
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
    0U,                                // samples

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_d
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
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_hr
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
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: 0
  //  Referenced by: '<S1>/Delay3'

  0.0,

  // Computed Parameter: Internal_A
  //  Referenced by: '<S11>/Internal'

  0.30119421191220208,

  // Computed Parameter: Internal_C
  //  Referenced by: '<S11>/Internal'

  0.698805788087798,

  // Expression: 0
  //  Referenced by: '<S11>/Internal'

  0.0,

  // Expression: 65
  //  Referenced by: '<S1>/Gain'

  65.0,

  // Expression: 1
  //  Referenced by: '<Root>/Gain4'

  1.0,

  // Expression: 2
  //  Referenced by: '<Root>/Constant'

  2.0,

  // Expression: -1
  //  Referenced by: '<Root>/Gain'

  -1.0,

  // Expression: pi/180
  //  Referenced by: '<Root>/Gain2'

  0.017453292519943295,

  // Expression: -0.85
  //  Referenced by: '<S1>/Constant3'

  -0.85,

  // Expression: 0.85
  //  Referenced by: '<S1>/Constant6'

  0.85,

  // Expression: zeros(4,1)
  //  Referenced by: '<S1>/Delay2'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1000
  //  Referenced by: '<Root>/Constant1'

  1000.0,

  // Expression: 150
  //  Referenced by: '<Root>/Constant3'

  150.0,

  // Expression: 1000
  //  Referenced by: '<S44>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S45>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S46>/Constant'

  1000.0,

  // Expression: 1000
  //  Referenced by: '<S47>/Constant'

  1000.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay23'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay22'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay21'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay20'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay14'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay13'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay12'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay11'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay10'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay9'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay8'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay7'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay6'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay5'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay4'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay1'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S30>/Delay'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S24>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S24>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S24>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S24>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S24>/Discrete Transfer Fcn2'

  0.0,

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay1'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay2'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay3'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay4'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay5'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay6'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay7'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay8'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay9'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay10'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay11'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay12'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay13'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay14'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay15'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay20'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay21'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay22'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay23'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay24'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay25'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay26'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay27'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay16'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay17'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay18'

  { 0.0, 0.0, 0.0 },

  // Expression: zeros(1,3)
  //  Referenced by: '<S26>/Delay19'

  { 0.0, 0.0, 0.0 },

  // Expression: 1/20
  //  Referenced by: '<S30>/Gain'

  0.05,

  // Expression: 0.0
  //  Referenced by: '<S28>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S28>/Memory2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S31>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S31>/Memory2'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  0.15,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  { 1.0, -0.85 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/Memory6'

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
  //  Referenced by: '<S20>/Gain2'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S20>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S4>/Gain'

  57.295779513082323,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  0.0069999999999999993,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  { 1.0, -0.993 },

  // Expression: 0
  //  Referenced by: '<S10>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S23>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S23>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  0.05,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  { 1.0, -0.95 },

  // Expression: 0
  //  Referenced by: '<S23>/Discrete Transfer Fcn2'

  0.0,

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S64>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_e5
  //  Referenced by: '<S65>/Constant'

  1.0F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: '<Root>/Gain1'

  57.2957802F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<Root>/Gain3'

  0,

  // Computed Parameter: LookUpTable_tableData
  //  Referenced by: '<S71>/Look-Up Table'

  { 0, 804, 1606, 2404, 3196, 3981, 4756, 5520, 6270, 7005, 7723, 8423, 9102,
    9760, 10394, 11003, 11585, 12140, 12665, 13160, 13623, 14053, 14449, 14811,
    15137, 15426, 15679, 15893, 16069, 16207, 16305, 16364, 16384 },

  // Computed Parameter: Point50_Value
  //  Referenced by: '<S72>/Point50'

  32768U,

  // Computed Parameter: Point25_Value
  //  Referenced by: '<S72>/Point25'

  16384U,

  // Computed Parameter: LookUpTable_bp01Data
  //  Referenced by: '<S71>/Look-Up Table'

  { 0U, 512U, 1024U, 1536U, 2048U, 2560U, 3072U, 3584U, 4096U, 4608U, 5120U,
    5632U, 6144U, 6656U, 7168U, 7680U, 8192U, 8704U, 9216U, 9728U, 10240U,
    10752U, 11264U, 11776U, 12288U, 12800U, 13312U, 13824U, 14336U, 14848U,
    15360U, 15872U, 16384U },

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
  //  Referenced by: '<S5>/failsafe'

  false,

  // Computed Parameter: startingswitch_CurrentSetting
  //  Referenced by: '<Root>/starting switch'

  1U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
