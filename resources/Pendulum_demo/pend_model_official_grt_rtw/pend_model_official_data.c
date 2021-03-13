/*
 * pend_model_official_data.c
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

#include "pend_model_official.h"
#include "pend_model_official_private.h"

/* Block parameters (auto storage) */
P_pend_model_official_T pend_model_official_P = {
  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S1>/Encoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S1>/Encoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Encoder 500PPR'
                                        */
  5.7053E-5,                           /* Expression: 5.7053e-005
                                        * Referenced by: '<S1>/PosCart Scale'
                                        */
  -0.55,                               /* Expression: -0.55
                                        * Referenced by: '<S1>/Cart Offset'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S1>/Angle Scale'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<Root>/Step1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S1>/PWM'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S1>/PWM'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/PWM'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S1>/ResetEncoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S1>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */

  /*  Expression: [0 0 0 ]
   * Referenced by: '<S1>/ResetSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S1>/LimitFlag'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitFlag'
                                        */

  /*  Computed Parameter: LimitFlag_P2_Size
   * Referenced by: '<S1>/LimitFlag'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/LimitFlag'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S1>/LimitFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [129 116 300]
   * Referenced by: '<S1>/LimitSource'
   */
  { 129.0, 116.0, 300.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S1>/SetLimit'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/SetLimit'
                                        */

  /*  Computed Parameter: SetLimit_P2_Size
   * Referenced by: '<S1>/SetLimit'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/SetLimit'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S1>/LimitSwitch'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */

  /*  Computed Parameter: LimitSwitch_P2_Size
   * Referenced by: '<S1>/LimitSwitch'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S1>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S1>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S1>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P2_Size
   * Referenced by: '<S1>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S1>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S1>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S1>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S1>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 }
};
