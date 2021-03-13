/*
 * Wahadlo_private.h
 *
 * Code generation for model "Wahadlo".
 *
 * Model version              : 1.244
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Mon Oct 09 10:33:19 2017
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Wahadlo_private_h_
#define RTW_HEADER_Wahadlo_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void P1_Encoder(SimStruct *rts);
extern void P1_PWM(SimStruct *rts);
extern void P1_ResetEncoder(SimStruct *rts);
extern void P1_LimitFlag(SimStruct *rts);
extern void P1_SetLimit(SimStruct *rts);
extern void P1_Switch(SimStruct *rts);
extern void P1_PWMPrescaler(SimStruct *rts);
extern void P1_ResetSwitchFlag(SimStruct *rts);
extern void P1_ThermFlag(SimStruct *rts);

#endif                                 /* RTW_HEADER_Wahadlo_private_h_ */
