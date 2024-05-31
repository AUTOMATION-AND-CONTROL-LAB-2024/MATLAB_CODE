//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pid_controller_pitch_private.h
//
// Code generated for Simulink model 'pid_controller_pitch'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 15:38:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_pid_controller_pitch_private_h_
#define RTW_HEADER_pid_controller_pitch_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "pid_controller_pitch.h"
#include "pid_controller_pitch_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void pid_contro_MATLABFunction1_Init(DW_MATLABFunction1_pid_contro_T
  *localDW);
extern void pid_controller__MATLABFunction1(const real_T rtu_u[3], real_T
  *rty_y1, real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_pid_contro_T
  *localDW);

#endif                            // RTW_HEADER_pid_controller_pitch_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
