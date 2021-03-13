/*
 * pendulim_exp_demoDemo_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pendulim_exp_demoDemo".
 *
 * Model version              : 1.241
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Mar 09 12:57:00 2021
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pendulim_exp_demoDemo.h"
#include "pendulim_exp_demoDemo_private.h"

/* Block parameters (auto storage) */
P_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_P = {
  0.0,                                 /* Mask Parameter: RefCartPos_Amplitude
                                        * Referenced by:
                                        *   '<S6>/sawtooth'
                                        *   '<S6>/sine'
                                        *   '<S6>/square'
                                        */
  -0.01,                               /* Mask Parameter: PIDPend_D
                                        * Referenced by: '<S10>/Kd1'
                                        */
  -0.5,                                /* Mask Parameter: PIDCart_D
                                        * Referenced by: '<S9>/Kd1'
                                        */
  0.05,                                /* Mask Parameter: RefCartPos_Frequency
                                        * Referenced by:
                                        *   '<S6>/sawtooth'
                                        *   '<S6>/sine'
                                        *   '<S6>/square'
                                        */
  0.05,                                /* Mask Parameter: ControllerPID_Friction
                                        * Referenced by: '<S8>/Gain1'
                                        */
  0.0,                                 /* Mask Parameter: PIDPend_I
                                        * Referenced by: '<S10>/Ki'
                                        */
  -0.0,                                /* Mask Parameter: PIDCart_I
                                        * Referenced by: '<S9>/Ki'
                                        */
  -1.0,                                /* Mask Parameter: PIDPend_P
                                        * Referenced by: '<S10>/Kp'
                                        */
  -0.8,                                /* Mask Parameter: PIDCart_P
                                        * Referenced by: '<S9>/Kp'
                                        */
  0.3,                                 /* Mask Parameter: Softlandingarbiter_R
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.0,                                 /* Mask Parameter: RefCartPos_Sawtooth
                                        * Referenced by: '<S6>/SawToothGain'
                                        */
  1.0,                                 /* Mask Parameter: RefCartPos_Sine
                                        * Referenced by: '<S6>/SineGain'
                                        */
  0.0,                                 /* Mask Parameter: RefCartPos_Square
                                        * Referenced by: '<S6>/SquareGain'
                                        */
  0.01,                                /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S7>/Gain2'
                                        *   '<S7>/Gain4'
                                        */
  0.01,                                /* Mask Parameter: ControllerPID_T0
                                        * Referenced by:
                                        *   '<S9>/Kd1'
                                        *   '<S10>/Kd1'
                                        */
  0.5,                                 /* Mask Parameter: ControllerPID_Umax
                                        * Referenced by: '<S3>/CtrlSat1'
                                        */
  1.0,                                 /* Mask Parameter: CoulombViscousFriction_gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  1.0,                                 /* Mask Parameter: CoulombViscousFriction_gain_h
                                        * Referenced by: '<S8>/Gain'
                                        */
  8.5,                                 /* Mask Parameter: Softlandingarbiter_k
                                        * Referenced by: '<S14>/Gain'
                                        */
  0.09,                                /* Mask Parameter: CoulombViscousFriction_offset
                                        * Referenced by: '<S11>/Gain1'
                                        */
  1.0,                                 /* Mask Parameter: AlfaNormalization_pos
                                        * Referenced by: '<S1>/pos'
                                        */
  0.5,                                 /* Mask Parameter: Swingingcontroller_umax
                                        * Referenced by: '<S15>/umax'
                                        */
  0.4,                                 /* Mask Parameter: Linearcontroller1_umax1
                                        * Referenced by: '<S12>/Saturation'
                                        */
  1.0,                                 /* Mask Parameter: Nottoescapewatchdog_umax2
                                        * Referenced by: '<S13>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/CtrlSat'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S4>/CtrlSat'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/2'
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
  5.7053E-5,                           /* Expression: 5.7053e-005
                                        * Referenced by: '<S2>/PosCart Scale'
                                        */
  -0.93,                               /* Expression: -1.86/2
                                        * Referenced by: '<S2>/Cart Offset'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Const1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Const2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Const3'
                                        */

  /*  Expression: [0 0 1 0]
   * Referenced by: '<Root>/Matrix Gain'
   */
  { 0.0, 0.0, 1.0, 0.0 },
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/pi'
                                        */
  0.0015339807878856412,               /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/Angle Scale'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Control = 0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S14>/one '
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S15>/swing'
                                        */
  2.2204460492503131E-16,              /* Expression: eps
                                        * Referenced by: '<S15>/swing'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S15>/swing'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S15>/swing'
                                        */
  8.0,                                 /* Expression: K(1)
                                        * Referenced by: '<S12>/Gain1'
                                        */
  -83.333333333333329,                 /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  83.333333333333329,                  /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  0.6,                                 /* Expression: K(2)
                                        * Referenced by: '<S12>/Gain2'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S12>/Saturation Cart Error'
                                        */
  -0.1,                                /* Expression: -0.1
                                        * Referenced by: '<S12>/Saturation Cart Error'
                                        */
  3.8,                                 /* Expression: K(3)
                                        * Referenced by: '<S12>/Gain3'
                                        */
  1.0,                                 /* Expression: K(4)
                                        * Referenced by: '<S12>/Gain4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S12>/Integrator'
                                        */
  -0.2,                                /* Expression: -0.2
                                        * Referenced by: '<S12>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  6000.0,                              /* Computed Parameter: AlgorithmSelector2_Period
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  5100.0,                              /* Computed Parameter: AlgorithmSelector2_Duty
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S10>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S10>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S9>/Integrator'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S9>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch'
                                        */
  0.4,                                 /* Expression: 0.4
                                        * Referenced by: '<S5>/CtrlSat'
                                        */
  -0.4,                                /* Expression: -0.4
                                        * Referenced by: '<S5>/CtrlSat'
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
  0.0,                                 /* Expression: 0.0
                                        * Referenced by: '<S12>/Integrator Gain'
                                        */
  1U,                                  /* Computed Parameter: ResetEncoders1_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders1'
                                        */
  0U                                   /* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};
