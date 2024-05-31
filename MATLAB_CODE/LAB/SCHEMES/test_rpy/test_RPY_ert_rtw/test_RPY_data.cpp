//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: test_RPY_data.cpp
//
// Code generated for Simulink model 'test_RPY'.
//
// Model version                  : 1.108
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Fri May 10 11:28:34 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "test_RPY.h"

// Block parameters (default storage)
P_test_RPY_T test_RPY_P = {
  // Variable: IMU_w_b_bias
  //  Referenced by: '<Root>/Constant2'

  { -0.0080925510955704213, -0.00422682228976928, 0.0092810582594727072 },

  // Variable: P0_phth
  //  Referenced by: '<S21>/Memory3'

  { 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    2.5375684706611302E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 2.5414139809878346E-6, 0.0,
    0.0, 0.0, 0.0, 0.0, 2.8458679630077551E-6 },

  // Variable: P0_ps
  //  Referenced by: '<S23>/Memory3'

  100.0,

  // Variable: Q_phth
  //  Referenced by: '<S21>/EKF_RP'

  { 90.0, 0.0, 0.0, 0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001 },

  // Variable: R_phth
  //  Referenced by: '<S21>/EKF_RP'

  { 80.0, 0.0, 0.0, 140.0 },

  // Variable: Rz
  //  Referenced by:
  //    '<S3>/Gain'
  //    '<S3>/Gain1'

  { 0.70710678118654757, 0.70710678118654746, 0.0, -0.70710678118654746,
    0.70710678118654757, 0.0, 0.0, 0.0, 1.0 },

  // Variable: Ts_EKF_integr
  //  Referenced by:
  //    '<S21>/EKF_RP'
  //    '<S23>/EKF_Y'

  0.0001,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S7>/Constant6'
  //    '<S21>/EKF_RP'
  //    '<S23>/EKF_Y'

  0.01,

  // Variable: q_ps
  //  Referenced by: '<S23>/EKF_Y'

  170.0,

  // Variable: r_ps
  //  Referenced by: '<S23>/EKF_Y'

  200.0,

  // Variable: x0_phth
  //  Referenced by: '<S21>/Memory4'

  { 0.0, 0.0, -0.0080925510955704213, -0.00422682228976928,
    0.0092810582594727072 },

  // Variable: x0_ps
  //  Referenced by: '<S23>/Memory4'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S33>/Out1'

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

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S30>/Constant'

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
  //  Referenced by: '<S13>/Out1'

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
  //  Referenced by: '<S12>/Constant'

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
  //  Referenced by: '<S15>/Out1'

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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S14>/Constant'

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
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_m
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
    false,                             // is_external

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U }
    // _padding0
  },

  // Expression: 1
  //  Referenced by: '<S41>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S42>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Sine Wave'

  1.0,

  // Computed Parameter: SineWave_Hsin
  //  Referenced by: '<Root>/Sine Wave'

  0.0099998333341666645,

  // Computed Parameter: SineWave_HCos
  //  Referenced by: '<Root>/Sine Wave'

  0.99995000041666526,

  // Computed Parameter: SineWave_PSin
  //  Referenced by: '<Root>/Sine Wave'

  -0.0099998333341666645,

  // Computed Parameter: SineWave_PCos
  //  Referenced by: '<Root>/Sine Wave'

  0.99995000041666526,

  // Expression: 1000
  //  Referenced by: '<S34>/Constant'

  1000.0,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave1'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave1'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Sine Wave1'

  1.0,

  // Computed Parameter: SineWave1_Hsin
  //  Referenced by: '<Root>/Sine Wave1'

  0.0099998333341666645,

  // Computed Parameter: SineWave1_HCos
  //  Referenced by: '<Root>/Sine Wave1'

  0.99995000041666526,

  // Computed Parameter: SineWave1_PSin
  //  Referenced by: '<Root>/Sine Wave1'

  0.99995000041666526,

  // Computed Parameter: SineWave1_PCos
  //  Referenced by: '<Root>/Sine Wave1'

  0.0099998333341667356,

  // Expression: 1000
  //  Referenced by: '<S35>/Constant'

  1000.0,

  // Expression: 200
  //  Referenced by: '<Root>/Sine Wave2'

  200.0,

  // Expression: 300
  //  Referenced by: '<Root>/Sine Wave2'

  300.0,

  // Expression: 1
  //  Referenced by: '<Root>/Sine Wave2'

  1.0,

  // Computed Parameter: SineWave2_Hsin
  //  Referenced by: '<Root>/Sine Wave2'

  0.0099998333341666645,

  // Computed Parameter: SineWave2_HCos
  //  Referenced by: '<Root>/Sine Wave2'

  0.99995000041666526,

  // Computed Parameter: SineWave2_PSin
  //  Referenced by: '<Root>/Sine Wave2'

  -0.0099998333341666645,

  // Computed Parameter: SineWave2_PCos
  //  Referenced by: '<Root>/Sine Wave2'

  0.99995000041666526,

  // Expression: 1200
  //  Referenced by: '<S36>/Constant'

  1200.0,

  // Expression: 200
  //  Referenced by: '<Root>/Sine Wave3'

  200.0,

  // Expression: 300
  //  Referenced by: '<Root>/Sine Wave3'

  300.0,

  // Expression: 1
  //  Referenced by: '<Root>/Sine Wave3'

  1.0,

  // Computed Parameter: SineWave3_Hsin
  //  Referenced by: '<Root>/Sine Wave3'

  0.0099998333341666645,

  // Computed Parameter: SineWave3_HCos
  //  Referenced by: '<Root>/Sine Wave3'

  0.99995000041666526,

  // Computed Parameter: SineWave3_PSin
  //  Referenced by: '<Root>/Sine Wave3'

  0.99995000041666526,

  // Computed Parameter: SineWave3_PCos
  //  Referenced by: '<Root>/Sine Wave3'

  0.0099998333341667356,

  // Expression: 1000
  //  Referenced by: '<S37>/Constant'

  1000.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn1'

  0.0,

  // Expression: [Ts_slk*p]
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  0.2,

  // Expression: [1 (Ts_slk*p-1)]
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  { 1.0, -0.8 },

  // Expression: 0
  //  Referenced by: '<S25>/Discrete Transfer Fcn2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S21>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S21>/Memory2'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S23>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S23>/Memory2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/Memory6'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S10>/Gain2'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S10>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain'

  57.295779513082323,

  // Computed Parameter: Gain1_Gain_m
  //  Referenced by: '<Root>/Gain1'

  57.2957802F,

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
  //  Referenced by: '<S8>/failsafe'

  false,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  1U,

  // Computed Parameter: startingswitch_CurrentSetting
  //  Referenced by: '<Root>/starting switch'

  1U
};

//
// File trailer for generated code.
//
// [EOF]
//
