/*
 * P1_ExpDemo_private.h
 *
 * Code generation for model "P1_ExpDemo".
 *
 * Model version              : 1.235
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Fri Jan 26 20:28:24 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_P1_ExpDemo_private_h_
#define RTW_HEADER_P1_ExpDemo_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void P1_Encoder(SimStruct *rts);
extern void P1_PWM(SimStruct *rts);
extern void P1_ResetEncoder(SimStruct *rts);
extern void P1_LimitFlag(SimStruct *rts);
extern void P1_SetLimit(SimStruct *rts);
extern void P1_Switch(SimStruct *rts);
extern void P1_PWMPrescaler(SimStruct *rts);
extern void P1_ResetSwitchFlag(SimStruct *rts);
extern void P1_ThermFlag(SimStruct *rts);

/* private model entry point functions */
extern void P1_ExpDemo_derivatives(void);

#endif                                 /* RTW_HEADER_P1_ExpDemo_private_h_ */
