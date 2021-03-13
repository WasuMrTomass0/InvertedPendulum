/*
 * ts_pendulim_data.c
 *
 * Code generation for model "ts_pendulim".
 *
 * Model version              : 1.243
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Wed Jun 06 08:32:46 2018
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ts_pendulim.h"
#include "ts_pendulim_private.h"

/* Block parameters (auto storage) */
P_ts_pendulim_T ts_pendulim_P = {
  0.3,                                 /* Mask Parameter: RefCartPos_Amplitude
                                        * Referenced by:
                                        *   '<S4>/sawtooth'
                                        *   '<S4>/sine'
                                        *   '<S4>/square'
                                        */
  0.0,                                 /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S3>/Derivative Gain'
                                        */
  0.1,                                 /* Mask Parameter: RefCartPos_Frequency
                                        * Referenced by:
                                        *   '<S4>/sawtooth'
                                        *   '<S4>/sine'
                                        *   '<S4>/square'
                                        */
  1.0,                                 /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S3>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S3>/Filter Coefficient'
                                        */
  0.0,                                 /* Mask Parameter: RefCartPos_Sawtooth
                                        * Referenced by: '<S4>/SawToothGain'
                                        */
  0.0,                                 /* Mask Parameter: RefCartPos_Sine
                                        * Referenced by: '<S4>/SineGain'
                                        */
  1.0,                                 /* Mask Parameter: RefCartPos_Square
                                        * Referenced by: '<S4>/SquareGain'
                                        */
  0.01,                                /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S5>/Gain2'
                                        *   '<S5>/Gain4'
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
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/pi'
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
                                        * Referenced by: '<S2>/Encoder 1024 PPR'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/Angle Scale'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory'
                                        */
  5.7053E-5,                           /* Expression: 5.7053e-005
                                        * Referenced by: '<S2>/PosCart Scale'
                                        */
  -0.93,                               /* Expression: -1.86/2
                                        * Referenced by: '<S2>/Cart Offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S5>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S5>/Memory1'
                                        */
  -0.8,                                /* Expression: -0.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<Root>/Gain1'
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
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal1'
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

  /*  Expression: [1 1 1 ]
   * Referenced by: '<S2>/ResetSource'
   */
  { 1.0, 1.0, 1.0 },

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
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S3>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S3>/Integrator'
                                        */
  1U,                                  /* Computed Parameter: ResetEncoders1_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders1'
                                        */
  0U                                   /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};
