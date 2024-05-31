//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: manual_waveInput_data.cpp
//
// Code generated for Simulink model 'manual_waveInput'.
//
// Model version                  : 1.76
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue Apr 16 17:55:13 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "manual_waveInput.h"

// Block parameters (default storage)
P_manual_waveInput_T manual_waveInput_P = {
  // Variable: P0
  //  Referenced by: '<S2>/Constant3'

  { 0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0025375684706611303, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0025414139809878345, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0028458679630077549 },

  // Variable: Q
  //  Referenced by: '<S2>/Constant4'

  { 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.1 },

  // Variable: R
  //  Referenced by: '<S2>/Constant5'

  { 0.0005, 0.0, 0.0, 0.0, 0.0005, 0.0, 0.0, 0.0, 0.0005 },

  // Variable: Ts_EKF_integr
  //  Referenced by: '<S2>/Constant'

  0.01,

  // Variable: Ts_EKF_meas
  //  Referenced by:
  //    '<S2>/Constant1'
  //    '<S2>/Constant6'

  0.02,

  // Variable: mf
  //  Referenced by: '<Root>/Constant2'

  { 22602.0, 0.0, -42062.0 },

  // Variable: x0EKF
  //  Referenced by: '<S2>/Constant2'

  { 0.0, 0.0, -0.9, -0.0080925510955704213, -0.00422682228976928,
    0.0092810582594727072 },

  // Variable: Rbody_frd
  //  Referenced by:
  //    '<Root>/Gain'
  //    '<Root>/Gain1'

  { 0.707106769F, 0.707106769F, 0.0F, -0.707106769F, 0.707106769F, 0.0F, 0.0F,
    0.0F, 1.0F },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S74>/Out1'

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
  //  Referenced by: '<S73>/Constant'

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

  // Computed Parameter: Out1_Y0_b
  //  Referenced by: '<S36>/Out1'

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
  //  Referenced by: '<S33>/Constant'

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

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Constant_Value_f
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

    {
      0U, 0U, 0U }
    ,                                  // clip_counter
    0U,                                // samples

    {
      0U, 0U, 0U, 0U }
    // _padding0
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S29>/Out1'

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
  //  Referenced by: '<S28>/Constant'

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
  //  Referenced by: '<S31>/Out1'

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
  //  Referenced by: '<S30>/Constant'

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
  //  Referenced by: '<S2>/Memory2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory4'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory3'

  0.0,

  // Expression: 0.0
  //  Referenced by: '<S2>/Delay2'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory'

  0.0,

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
  //  Referenced by: '<S37>/Constant'

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
  //  Referenced by: '<S38>/Constant'

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
  //  Referenced by: '<S39>/Constant'

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
  //  Referenced by: '<S40>/Constant'

  1000.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory5'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Memory6'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S15>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S17>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S19>/Gain'

  57.295779513082323,

  // Computed Parameter: Constant_Value_ft
  //  Referenced by: '<S44>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S45>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_ha
  //  Referenced by: '<S52>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_oj
  //  Referenced by: '<S53>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S60>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S61>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_is
  //  Referenced by: '<S68>/Constant'

  1.0F,

  // Computed Parameter: Constant_Value_pl
  //  Referenced by: '<S69>/Constant'

  1.0F,

  // Computed Parameter: Gain_Gain_j
  //  Referenced by: '<S16>/Gain'

  57.2957802F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S18>/Gain'

  57.2957802F,

  // Computed Parameter: Gain_Gain_oj
  //  Referenced by: '<S20>/Gain'

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
  //  Referenced by: '<S9>/failsafe'

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
