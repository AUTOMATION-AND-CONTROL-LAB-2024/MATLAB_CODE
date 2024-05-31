//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_2dof_pid_private.h
//
// Code generated for Simulink model 'controller_2dof_pid'.
//
// Model version                  : 1.10
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Tue May 28 18:20:00 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_2dof_pid_private_h_
#define RTW_HEADER_controller_2dof_pid_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "controller_2dof_pid.h"
#include "controller_2dof_pid_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T
  *localDW);
extern void controller_2dof_MATLABFunction1(const real_T rtu_x1[2], real_T
  rtu_u_sat1, real_T rtu_e, real_T rtu_u_min, real_T rtu_u_max, boolean_T
  rtu_on_off, real_T rty_x[2], real_T *rty_u_sat,
  DW_MATLABFunction1_controller_T *localDW);
extern void controll_MATLABFunction1_f_Init(DW_MATLABFunction1_controll_b_T
  *localDW);
extern void controller_2d_MATLABFunction1_m(const real_T rtu_u[3], real_T
  *rty_y1, real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controll_b_T
  *localDW);

#endif                             // RTW_HEADER_controller_2dof_pid_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
