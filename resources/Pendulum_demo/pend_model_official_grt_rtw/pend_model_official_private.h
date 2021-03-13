/*
 * pend_model_official_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pend_model_official".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Mon Oct 14 11:47:37 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pend_model_official_private_h_
#define RTW_HEADER_pend_model_official_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void P1_Encoder(SimStruct *rts);
extern void P1_PWM(SimStruct *rts);
extern void P1_ResetEncoder(SimStruct *rts);
extern void P1_LimitFlag(SimStruct *rts);
extern void P1_SetLimit(SimStruct *rts);
extern void P1_Switch(SimStruct *rts);
extern void P1_PWMPrescaler(SimStruct *rts);
extern void P1_ResetSwitchFlag(SimStruct *rts);
extern void P1_ThermFlag(SimStruct *rts);

#endif                                 /* RTW_HEADER_pend_model_official_private_h_ */
