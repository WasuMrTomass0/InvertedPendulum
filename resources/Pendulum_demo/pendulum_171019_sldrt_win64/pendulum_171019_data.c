/*
 * pendulum_171019_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pendulum_171019".
 *
 * Model version              : 1.158
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Thu Oct 17 15:45:51 2019
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pendulum_171019.h"
#include "pendulum_171019_private.h"

/* Block parameters (auto storage) */
P_pendulum_171019_T pendulum_171019_P = {
  0.01,                                /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S3>/Gain2'
                                        *   '<S3>/Gain4'
                                        */
  2.0,                                 /* Mask Parameter: AlfaNormalization_pos
                                        * Referenced by: '<S1>/pos'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Control'
                                        */

  /*  Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/Encoder'
                                        */

  /*  Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S2>/Encoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/Encoder'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Encoder 500PPR'
                                        */
  5.7053E-5,                           /* Expression: 5.7053e-005
                                        * Referenced by: '<S2>/PosCart Scale'
                                        */
  -0.55,                               /* Expression: -0.55
                                        * Referenced by: '<S2>/Cart Offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/pi'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/Angle Scale'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Memory'
                                        */

  /*  Computed Parameter: PWM_P1_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/PWM'
                                        */

  /*  Computed Parameter: PWM_P2_Size
   * Referenced by: '<S2>/PWM'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/PWM'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -0.5,                                /* Expression: -0.5
                                        * Referenced by: '<S2>/Saturation'
                                        */

  /*  Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */

  /*  Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S2>/ResetEncoder'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */

  /*  Expression: [0 0 0 ]
   * Referenced by: '<S2>/ResetSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: LimitFlag_P1_Size
   * Referenced by: '<S2>/LimitFlag'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/LimitFlag'
                                        */

  /*  Computed Parameter: LimitFlag_P2_Size
   * Referenced by: '<S2>/LimitFlag'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/LimitFlag'
                                        */

  /*  Expression: [0 0 0]
   * Referenced by: '<S2>/LimitFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Expression: [129 116 300]
   * Referenced by: '<S2>/LimitSource'
   */
  { 129.0, 116.0, 300.0 },

  /*  Computed Parameter: SetLimit_P1_Size
   * Referenced by: '<S2>/SetLimit'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/SetLimit'
                                        */

  /*  Computed Parameter: SetLimit_P2_Size
   * Referenced by: '<S2>/SetLimit'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/SetLimit'
                                        */

  /*  Computed Parameter: LimitSwitch_P1_Size
   * Referenced by: '<S2>/LimitSwitch'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */

  /*  Computed Parameter: LimitSwitch_P2_Size
   * Referenced by: '<S2>/LimitSwitch'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */

  /*  Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */

  /*  Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S2>/PWMPrescaler'
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/PWMPrescalerSource'
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P1_Size
   * Referenced by: '<S2>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */

  /*  Computed Parameter: ResetSwitchFlag_P2_Size
   * Referenced by: '<S2>/ResetSwitchFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */

  /*  Expression: [ 0 0 0 ]
   * Referenced by: '<S2>/ResetSwitchFlagSource'
   */
  { 0.0, 0.0, 0.0 },

  /*  Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },
  57088.0,                             /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ThermFlag '
                                        */

  /*  Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S2>/ThermFlag '
   */
  { 1.0, 1.0 },
  0.01,                                /* Expression: T0
                                        * Referenced by: '<S2>/ThermFlag '
                                        */

  /*  Expression: [1 1 1]
   * Referenced by: '<S2>/ThermFlagSource'
   */
  { 1.0, 1.0, 1.0 },
  0U                                   /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};
