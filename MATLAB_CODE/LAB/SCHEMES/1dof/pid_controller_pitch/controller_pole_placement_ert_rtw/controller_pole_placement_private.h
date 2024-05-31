//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_pole_placement_private.h
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
#ifndef RTW_HEADER_controller_pole_placement_private_h_
#define RTW_HEADER_controller_pole_placement_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "controller_pole_placement.h"
#include "controller_pole_placement_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void controller_MATLABFunction1_Init(DW_MATLABFunction1_controller_T
  *localDW);
extern void controller_pole_MATLABFunction1(const real_T rtu_u[3], real_T
  *rty_y1, real_T *rty_y2, real_T *rty_y3, DW_MATLABFunction1_controller_T
  *localDW);

#endif                       // RTW_HEADER_controller_pole_placement_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
