//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_3dof_private.h
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
#ifndef RTW_HEADER_controller_3dof_private_h_
#define RTW_HEADER_controller_3dof_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include <uORB/topics/actuator_outputs.h>
#include "controller_3dof.h"
#include "controller_3dof_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void controller_3do_SourceBlock_Init(DW_SourceBlock_controller_3do_T
  *localDW);
extern void controller_3dof_SourceBlock(B_SourceBlock_controller_3dof_T *localB,
  DW_SourceBlock_controller_3do_T *localDW);
extern void controller_3do_SourceBlock_Term(DW_SourceBlock_controller_3do_T
  *localDW);

#endif                                 // RTW_HEADER_controller_3dof_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
