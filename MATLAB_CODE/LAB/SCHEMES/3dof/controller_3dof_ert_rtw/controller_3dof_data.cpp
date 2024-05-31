//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_3dof_data.cpp
//
// Code generated for Simulink model 'controller_3dof'.
//
// Model version                  : 1.70
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr 16 17:37:26 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller_3dof.h"

// Block parameters (default storage)
P_controller_3dof_T controller_3dof_P = {
  // Variable: Kv
  //  Referenced by: '<S2>/Gain3'

  { -1.4116262364283178E-5, 6.3969840136535539E-7, 5.915577628502606E-6,
    3.1557503738721266E-7, -1.2950063575720663E-5, 4.2840197067821639E-6,
    3.7230038546229906E-6, 1.62624959992746E-6, -2.2828305210061616E-5 },

  // Variable: P0
  //  Referenced by: '<S3>/Constant3'

  { 0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025375684706611303, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0025414139809878345, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0028458679630077549 },

  // Variable: Q
  //  Referenced by: '<S3>/Constant4'

  { 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1 },

  // Variable: R
  //  Referenced by: '<S3>/Constant5'

  { 0.0005, 0.0, 0.0, 0.0, 0.0005, 0.0, 0.0, 0.0, 0.0005 },

  // Variable: Rbody_ned
  //  Referenced by: '<S5>/Gain2'

  { 0.70710678118654757, 0.70710678118654746, 0.0, 0.70710678118654746,
    -0.70710678118654757, 1.2246467991473532E-16, 8.6595605623549316E-17,
    -8.6595605623549341E-17, -1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by: '<S3>/Constant'

  0.01,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S3>/Constant1'
  //    '<S3>/Constant6'

  0.02,

  // Variable: mf
  //  Referenced by: '<Root>/Constant2'

  { 22602.0, 0.0, -42062.0 },

  // Variable: param
  //  Referenced by: '<Root>/Constant1'

  { 0.015, 0.015, 0.03, 0.25, 0.0022, 1.14E-7, 0.866 },

  // Variable: x0EKF
  //  Referenced by: '<S3>/Constant2'

  { 0.0, 0.0, -0.9, -0.0080925510955704213, -0.00422682228976928,
    0.0092810582594727072 },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S53>/Out1'

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
  //  Referenced by: '<S52>/Constant'

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
  //  Referenced by: '<S30>/Out1'

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

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S35>/Out1'

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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S27>/Constant'

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

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S11>/Constant'

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

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S19>/Out1'

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

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S18>/Constant'

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

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S23>/Out1'

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

  // Computed Parameter: Constant_Value_ou
  //  Referenced by: '<S22>/Constant'

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

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S25>/Out1'

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
  //  Referenced by: '<S24>/Constant'

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
  //  Referenced by: '<S3>/Memory2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Memory4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Memory3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S3>/Delay2'

  0.0,

  // Expression: Rbody_frd
  //  Referenced by: '<S5>/Gain'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Expression: 0
  //  Referenced by: '<S3>/Memory1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Memory'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S2>/Discrete-Time Integrator'

  0.01,

  // Expression: 0
  //  Referenced by: '<S2>/Discrete-Time Integrator'

  0.0,

  // Expression: 10
  //  Referenced by: '<Root>/Constant3'

  10.0,

  // Expression: 1500
  //  Referenced by: '<S31>/Constant'

  1500.0,

  // Expression: 1700
  //  Referenced by: '<S32>/Constant'

  1700.0,

  // Expression: 1000
  //  Referenced by: '<S33>/Constant'

  1000.0,

  // Expression: 1700
  //  Referenced by: '<S34>/Constant'

  1700.0,

  // Expression: 0
  //  Referenced by: '<S3>/Memory5'

  0.0,

  // Expression: Rbody_frd
  //  Referenced by: '<S5>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Expression: 0
  //  Referenced by: '<S3>/Memory6'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RPY angle_ref'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/RPY angle_ref'

  0.0,

  // Expression: zeros(3,1)
  //  Referenced by: '<Root>/RPY angle_ref'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: Constant_Value_ck
  //  Referenced by: '<S39>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_aa
  //  Referenced by: '<S40>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_h0
  //  Referenced by: '<S47>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S48>/Constant'

  1.0F,

  // Expression: Rbody_frd
  //  Referenced by: '<Root>/Gain'

  { 0.707106769F, 0.707106769F, 0.0F, -0.707106769F, 0.707106769F, 0.0F, 0.0F,
    0.0F, 1.0F },

  // Expression: Rbody_frd
  //  Referenced by: '<Root>/Gain1'

  { 0.707106769F, 0.707106769F, 0.0F, -0.707106769F, 0.707106769F, 0.0F, 0.0F,
    0.0F, 1.0F },

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S2>/Gain2'

  { -0.000507417542F, 1.92491552E-5F, 0.000125814011F, 1.50014494E-5F,
    -0.000473452295F, 9.06474161E-5F, 7.9956757E-5F, 3.6423553E-5F,
    -0.000869256677F, -0.00530810095F, 8.91401723E-5F, 0.000528309087F,
    8.0525635E-5F, -0.0050947289F, 0.00042874171F, 0.000352392875F,
    0.000198134221F, -0.00980745163F },

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<Root>/Constant5'

  false,

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<Root>/Constant'

  false,

  // Computed Parameter: ARMPWM_Value
  //  Referenced by: '<Root>/ARM PWM'

  true,

  // Computed Parameter: failsafe_Value
  //  Referenced by: '<S10>/failsafe'

  false,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  1U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
