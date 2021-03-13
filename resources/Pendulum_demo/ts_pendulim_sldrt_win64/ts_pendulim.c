/*
 * ts_pendulim.c
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
#include "ts_pendulim_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_ts_pendulim_T ts_pendulim_B;

/* Continuous states */
X_ts_pendulim_T ts_pendulim_X;

/* Block states (auto storage) */
DW_ts_pendulim_T ts_pendulim_DW;

/* Real-time model */
RT_MODEL_ts_pendulim_T ts_pendulim_M_;
RT_MODEL_ts_pendulim_T *const ts_pendulim_M = &ts_pendulim_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ts_pendulim_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  ts_pendulim_output();
  ts_pendulim_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  ts_pendulim_output();
  ts_pendulim_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  ts_pendulim_output();
  ts_pendulim_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  ts_pendulim_output();
  ts_pendulim_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  ts_pendulim_output();
  ts_pendulim_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void ts_pendulim_output(void)
{
  real_T temp;
  real_T rtb_Encoder1024PPR[5];
  real_T rtb_Memory1;
  int32_T i;
  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* set solver stop time */
    if (!(ts_pendulim_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ts_pendulim_M->solverInfo,
                            ((ts_pendulim_M->Timing.clockTickH0 + 1) *
        ts_pendulim_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ts_pendulim_M->solverInfo,
                            ((ts_pendulim_M->Timing.clockTick0 + 1) *
        ts_pendulim_M->Timing.stepSize0 + ts_pendulim_M->Timing.clockTickH0 *
        ts_pendulim_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ts_pendulim_M)) {
    ts_pendulim_M->Timing.t[0] = rtsiGetT(&ts_pendulim_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S2>/Encoder 1024 PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder1024PPR[i] = ts_pendulim_P.Encoder1024PPR_Gain *
        ts_pendulim_B.Encoder[i];
    }

    /* End of Gain: '<S2>/Encoder 1024 PPR' */

    /* Gain: '<S2>/Angle Scale' */
    ts_pendulim_B.AngleScale = ts_pendulim_P.AngleScale_Gain *
      rtb_Encoder1024PPR[3];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/pi'
     *  Constant: '<S1>/pos'
     *  Gain: '<S5>/Gain1'
     *  Product: '<S1>/Product'
     */
    rtb_Memory1 = ts_pendulim_P.pi_Value * ts_pendulim_P.AlfaNormalization_pos +
      ts_pendulim_P.Gain1_Gain * ts_pendulim_B.AngleScale;

    /* Fcn: '<S1>/angle normalization' */
    ts_pendulim_B.PendPosOut = rt_atan2d_snf(sin(rtb_Memory1), cos(rtb_Memory1));

    /* Gain: '<S5>/Gain2' incorporates:
     *  Memory: '<S5>/Memory'
     *  Sum: '<S5>/Sum'
     */
    ts_pendulim_B.Pend_vel = 1.0 / ts_pendulim_P.Sensors_T0 *
      (ts_pendulim_B.AngleScale - ts_pendulim_DW.Memory_PreviousInput);
  }

  /* SignalGenerator: '<S4>/square' */
  rtb_Memory1 = ts_pendulim_P.RefCartPos_Frequency * ts_pendulim_M->Timing.t[0];

  /* SignalGenerator: '<S4>/sawtooth' */
  temp = ts_pendulim_P.RefCartPos_Frequency * ts_pendulim_M->Timing.t[0];

  /* SignalGenerator: '<S4>/square' */
  if (rtb_Memory1 - floor(rtb_Memory1) >= 0.5) {
    rtb_Memory1 = ts_pendulim_P.RefCartPos_Amplitude;
  } else {
    rtb_Memory1 = -ts_pendulim_P.RefCartPos_Amplitude;
  }

  /* Sum: '<S4>/Sum' incorporates:
   *  Gain: '<S4>/SawToothGain'
   *  Gain: '<S4>/SineGain'
   *  Gain: '<S4>/SquareGain'
   *  SignalGenerator: '<S4>/sawtooth'
   *  SignalGenerator: '<S4>/sine'
   */
  ts_pendulim_B.Sum = (sin(6.2831853071795862 * ts_pendulim_M->Timing.t[0] *
    ts_pendulim_P.RefCartPos_Frequency) * ts_pendulim_P.RefCartPos_Amplitude *
                       ts_pendulim_P.RefCartPos_Sine +
                       ts_pendulim_P.RefCartPos_Square * rtb_Memory1) + (1.0 -
    (temp - floor(temp)) * 2.0) * ts_pendulim_P.RefCartPos_Amplitude *
    ts_pendulim_P.RefCartPos_Sawtooth;
  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Cart Offset'
     *  Gain: '<S2>/PosCart Scale'
     */
    ts_pendulim_B.Sum_f = ts_pendulim_P.PosCartScale_Gain * rtb_Encoder1024PPR[4]
      + ts_pendulim_P.CartOffset_Value;

    /* Gain: '<S5>/Gain3' */
    ts_pendulim_B.Cart_pos = ts_pendulim_P.Gain3_Gain * ts_pendulim_B.Sum_f;

    /* Gain: '<S5>/Gain4' incorporates:
     *  Memory: '<S5>/Memory1'
     *  Sum: '<S5>/Sum1'
     */
    ts_pendulim_B.Cart_vel = 1.0 / ts_pendulim_P.Sensors_T0 *
      (ts_pendulim_B.Sum_f - ts_pendulim_DW.Memory1_PreviousInput);
  }

  /* Sum: '<Root>/Add' */
  ts_pendulim_B.Add = ts_pendulim_B.Sum - ts_pendulim_B.Cart_pos;
  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Memory: '<Root>/Memory' */
    ts_pendulim_B.Memory = ts_pendulim_DW.Memory_PreviousInput_b;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain1'
   *  Sum: '<Root>/Sum1'
   */
  ts_pendulim_B.Sum_h = (ts_pendulim_B.Add - ts_pendulim_B.Memory) *
    ts_pendulim_P.Gain1_Gain_f + ts_pendulim_P.Gain_Gain * ts_pendulim_B.Add;
  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Saturate: '<S2>/Saturation' */
  if (0.0 > ts_pendulim_P.Saturation_UpperSat) {
    ts_pendulim_B.Saturation[0] = ts_pendulim_P.Saturation_UpperSat;
  } else if (0.0 < ts_pendulim_P.Saturation_LowerSat) {
    ts_pendulim_B.Saturation[0] = ts_pendulim_P.Saturation_LowerSat;
  } else {
    ts_pendulim_B.Saturation[0] = 0.0;
  }

  /* ManualSwitch: '<Root>/Reset Encoders1' incorporates:
   *  Constant: '<Root>/Normal1'
   */
  if (ts_pendulim_P.ResetEncoders1_CurrentSetting == 1) {
    rtb_Memory1 = ts_pendulim_B.Sum_h;
  } else {
    rtb_Memory1 = ts_pendulim_P.Normal1_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders1' */

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Memory1 > ts_pendulim_P.Saturation_UpperSat) {
    ts_pendulim_B.Saturation[1] = ts_pendulim_P.Saturation_UpperSat;
  } else if (rtb_Memory1 < ts_pendulim_P.Saturation_LowerSat) {
    ts_pendulim_B.Saturation[1] = ts_pendulim_P.Saturation_LowerSat;
  } else {
    ts_pendulim_B.Saturation[1] = rtb_Memory1;
  }

  if (0.0 > ts_pendulim_P.Saturation_UpperSat) {
    ts_pendulim_B.Saturation[2] = ts_pendulim_P.Saturation_UpperSat;
  } else if (0.0 < ts_pendulim_P.Saturation_LowerSat) {
    ts_pendulim_B.Saturation[2] = ts_pendulim_P.Saturation_LowerSat;
  } else {
    ts_pendulim_B.Saturation[2] = 0.0;
  }

  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSource' */
    ts_pendulim_B.ResetSource[0] = ts_pendulim_P.ResetSource_Value[0];
    ts_pendulim_B.ResetSource[1] = ts_pendulim_P.ResetSource_Value[1];
    ts_pendulim_B.ResetSource[2] = ts_pendulim_P.ResetSource_Value[2];

    /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/LimitFlagSource' */
    ts_pendulim_B.LimitFlagSource[0] = ts_pendulim_P.LimitFlagSource_Value[0];
    ts_pendulim_B.LimitFlagSource[1] = ts_pendulim_P.LimitFlagSource_Value[1];
    ts_pendulim_B.LimitFlagSource[2] = ts_pendulim_P.LimitFlagSource_Value[2];

    /* Constant: '<S2>/LimitSource' */
    ts_pendulim_B.LimitSource[0] = ts_pendulim_P.LimitSource_Value[0];
    ts_pendulim_B.LimitSource[1] = ts_pendulim_P.LimitSource_Value[1];
    ts_pendulim_B.LimitSource[2] = ts_pendulim_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/PWMPrescalerSource' */
    ts_pendulim_B.PWMPrescalerSource = ts_pendulim_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSwitchFlagSource' */
    ts_pendulim_B.ResetSwitchFlagSource[0] =
      ts_pendulim_P.ResetSwitchFlagSource_Value[0];
    ts_pendulim_B.ResetSwitchFlagSource[1] =
      ts_pendulim_P.ResetSwitchFlagSource_Value[1];
    ts_pendulim_B.ResetSwitchFlagSource[2] =
      ts_pendulim_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ThermFlagSource' */
    ts_pendulim_B.ThermFlagSource[0] = ts_pendulim_P.ThermFlagSource_Value[0];
    ts_pendulim_B.ThermFlagSource[1] = ts_pendulim_P.ThermFlagSource_Value[1];
    ts_pendulim_B.ThermFlagSource[2] = ts_pendulim_P.ThermFlagSource_Value[2];

    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (ts_pendulim_P.ResetEncoders_CurrentSetting == 1) {
      ts_pendulim_B.ResetEncoders = ts_pendulim_P.Reset_Value;
    } else {
      ts_pendulim_B.ResetEncoders = ts_pendulim_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */
  }

  /* Gain: '<S3>/Filter Coefficient' incorporates:
   *  Gain: '<S3>/Derivative Gain'
   *  Integrator: '<S3>/Filter'
   *  Sum: '<S3>/SumD'
   */
  ts_pendulim_B.FilterCoefficient = (ts_pendulim_P.PIDController_D * 0.0 -
    ts_pendulim_X.Filter_CSTATE) * ts_pendulim_P.PIDController_N;

  /* Gain: '<S3>/Integral Gain' */
  ts_pendulim_B.IntegralGain = ts_pendulim_P.PIDController_I * 0.0;
}

/* Model update function */
void ts_pendulim_update(void)
{
  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    /* Update for Memory: '<S5>/Memory' */
    ts_pendulim_DW.Memory_PreviousInput = ts_pendulim_B.AngleScale;

    /* Update for Memory: '<S5>/Memory1' */
    ts_pendulim_DW.Memory1_PreviousInput = ts_pendulim_B.Sum_f;

    /* Update for Memory: '<Root>/Memory' */
    ts_pendulim_DW.Memory_PreviousInput_b = ts_pendulim_B.Add;
  }

  if (rtmIsMajorTimeStep(ts_pendulim_M)) {
    rt_ertODEUpdateContinuousStates(&ts_pendulim_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ts_pendulim_M->Timing.clockTick0)) {
    ++ts_pendulim_M->Timing.clockTickH0;
  }

  ts_pendulim_M->Timing.t[0] = rtsiGetSolverStopTime(&ts_pendulim_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ts_pendulim_M->Timing.clockTick1)) {
      ++ts_pendulim_M->Timing.clockTickH1;
    }

    ts_pendulim_M->Timing.t[1] = ts_pendulim_M->Timing.clockTick1 *
      ts_pendulim_M->Timing.stepSize1 + ts_pendulim_M->Timing.clockTickH1 *
      ts_pendulim_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ts_pendulim_derivatives(void)
{
  XDot_ts_pendulim_T *_rtXdot;
  _rtXdot = ((XDot_ts_pendulim_T *) ts_pendulim_M->ModelData.derivs);

  /* Derivatives for Integrator: '<S3>/Filter' */
  _rtXdot->Filter_CSTATE = ts_pendulim_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE = ts_pendulim_B.IntegralGain;
}

/* Model initialize function */
void ts_pendulim_initialize(void)
{
  /* Start for Constant: '<S2>/LimitFlagSource' */
  ts_pendulim_B.LimitFlagSource[0] = ts_pendulim_P.LimitFlagSource_Value[0];
  ts_pendulim_B.LimitFlagSource[1] = ts_pendulim_P.LimitFlagSource_Value[1];
  ts_pendulim_B.LimitFlagSource[2] = ts_pendulim_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S2>/LimitSource' */
  ts_pendulim_B.LimitSource[0] = ts_pendulim_P.LimitSource_Value[0];
  ts_pendulim_B.LimitSource[1] = ts_pendulim_P.LimitSource_Value[1];
  ts_pendulim_B.LimitSource[2] = ts_pendulim_P.LimitSource_Value[2];

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  ts_pendulim_B.PWMPrescalerSource = ts_pendulim_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S2>/ResetSwitchFlagSource' */
  ts_pendulim_B.ResetSwitchFlagSource[0] =
    ts_pendulim_P.ResetSwitchFlagSource_Value[0];
  ts_pendulim_B.ResetSwitchFlagSource[1] =
    ts_pendulim_P.ResetSwitchFlagSource_Value[1];
  ts_pendulim_B.ResetSwitchFlagSource[2] =
    ts_pendulim_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  ts_pendulim_B.ThermFlagSource[0] = ts_pendulim_P.ThermFlagSource_Value[0];
  ts_pendulim_B.ThermFlagSource[1] = ts_pendulim_P.ThermFlagSource_Value[1];
  ts_pendulim_B.ThermFlagSource[2] = ts_pendulim_P.ThermFlagSource_Value[2];

  /* InitializeConditions for Memory: '<S5>/Memory' */
  ts_pendulim_DW.Memory_PreviousInput = ts_pendulim_P.Memory_X0;

  /* InitializeConditions for Memory: '<S5>/Memory1' */
  ts_pendulim_DW.Memory1_PreviousInput = ts_pendulim_P.Memory1_X0;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  ts_pendulim_DW.Memory_PreviousInput_b = ts_pendulim_P.Memory_X0_o;

  /* InitializeConditions for Integrator: '<S3>/Filter' */
  ts_pendulim_X.Filter_CSTATE = ts_pendulim_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  ts_pendulim_X.Integrator_CSTATE = ts_pendulim_P.Integrator_IC;
}

/* Model terminate function */
void ts_pendulim_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = ts_pendulim_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ts_pendulim_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ts_pendulim_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ts_pendulim_initialize();
}

void MdlTerminate(void)
{
  ts_pendulim_terminate();
}

/* Registration function */
RT_MODEL_ts_pendulim_T *ts_pendulim(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ts_pendulim_M, 0,
                sizeof(RT_MODEL_ts_pendulim_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ts_pendulim_M->solverInfo,
                          &ts_pendulim_M->Timing.simTimeStep);
    rtsiSetTPtr(&ts_pendulim_M->solverInfo, &rtmGetTPtr(ts_pendulim_M));
    rtsiSetStepSizePtr(&ts_pendulim_M->solverInfo,
                       &ts_pendulim_M->Timing.stepSize0);
    rtsiSetdXPtr(&ts_pendulim_M->solverInfo, &ts_pendulim_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ts_pendulim_M->solverInfo, (real_T **)
                         &ts_pendulim_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ts_pendulim_M->solverInfo,
      &ts_pendulim_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ts_pendulim_M->solverInfo, (&rtmGetErrorStatus
      (ts_pendulim_M)));
    rtsiSetRTModelPtr(&ts_pendulim_M->solverInfo, ts_pendulim_M);
  }

  rtsiSetSimTimeStep(&ts_pendulim_M->solverInfo, MAJOR_TIME_STEP);
  ts_pendulim_M->ModelData.intgData.y = ts_pendulim_M->ModelData.odeY;
  ts_pendulim_M->ModelData.intgData.f[0] = ts_pendulim_M->ModelData.odeF[0];
  ts_pendulim_M->ModelData.intgData.f[1] = ts_pendulim_M->ModelData.odeF[1];
  ts_pendulim_M->ModelData.intgData.f[2] = ts_pendulim_M->ModelData.odeF[2];
  ts_pendulim_M->ModelData.intgData.f[3] = ts_pendulim_M->ModelData.odeF[3];
  ts_pendulim_M->ModelData.intgData.f[4] = ts_pendulim_M->ModelData.odeF[4];
  ts_pendulim_M->ModelData.intgData.f[5] = ts_pendulim_M->ModelData.odeF[5];
  ts_pendulim_M->ModelData.contStates = ((real_T *) &ts_pendulim_X);
  rtsiSetSolverData(&ts_pendulim_M->solverInfo, (void *)
                    &ts_pendulim_M->ModelData.intgData);
  rtsiSetSolverName(&ts_pendulim_M->solverInfo,"ode5");
  ts_pendulim_M->solverInfoPtr = (&ts_pendulim_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = ts_pendulim_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ts_pendulim_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ts_pendulim_M->Timing.sampleTimes = (&ts_pendulim_M->
      Timing.sampleTimesArray[0]);
    ts_pendulim_M->Timing.offsetTimes = (&ts_pendulim_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    ts_pendulim_M->Timing.sampleTimes[0] = (0.0);
    ts_pendulim_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    ts_pendulim_M->Timing.offsetTimes[0] = (0.0);
    ts_pendulim_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ts_pendulim_M, &ts_pendulim_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = ts_pendulim_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ts_pendulim_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ts_pendulim_M, 9999.0);
  ts_pendulim_M->Timing.stepSize0 = 0.01;
  ts_pendulim_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  ts_pendulim_M->Sizes.checksums[0] = (2037341661U);
  ts_pendulim_M->Sizes.checksums[1] = (3015900732U);
  ts_pendulim_M->Sizes.checksums[2] = (3569414441U);
  ts_pendulim_M->Sizes.checksums[3] = (3029458700U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    ts_pendulim_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ts_pendulim_M->extModeInfo,
      &ts_pendulim_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ts_pendulim_M->extModeInfo,
                        ts_pendulim_M->Sizes.checksums);
    rteiSetTPtr(ts_pendulim_M->extModeInfo, rtmGetTPtr(ts_pendulim_M));
  }

  ts_pendulim_M->solverInfoPtr = (&ts_pendulim_M->solverInfo);
  ts_pendulim_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&ts_pendulim_M->solverInfo, 0.01);
  rtsiSetSolverMode(&ts_pendulim_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ts_pendulim_M->ModelData.blockIO = ((void *) &ts_pendulim_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      ts_pendulim_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      ts_pendulim_B.ResetEncoder[i] = 0.0;
    }

    ts_pendulim_B.AngleScale = 0.0;
    ts_pendulim_B.PendPosOut = 0.0;
    ts_pendulim_B.Pend_vel = 0.0;
    ts_pendulim_B.Sum = 0.0;
    ts_pendulim_B.Sum_f = 0.0;
    ts_pendulim_B.Cart_pos = 0.0;
    ts_pendulim_B.Cart_vel = 0.0;
    ts_pendulim_B.Add = 0.0;
    ts_pendulim_B.Memory = 0.0;
    ts_pendulim_B.Sum_h = 0.0;
    ts_pendulim_B.PWM[0] = 0.0;
    ts_pendulim_B.PWM[1] = 0.0;
    ts_pendulim_B.PWM[2] = 0.0;
    ts_pendulim_B.Saturation[0] = 0.0;
    ts_pendulim_B.Saturation[1] = 0.0;
    ts_pendulim_B.Saturation[2] = 0.0;
    ts_pendulim_B.ResetSource[0] = 0.0;
    ts_pendulim_B.ResetSource[1] = 0.0;
    ts_pendulim_B.ResetSource[2] = 0.0;
    ts_pendulim_B.LimitFlag[0] = 0.0;
    ts_pendulim_B.LimitFlag[1] = 0.0;
    ts_pendulim_B.LimitFlag[2] = 0.0;
    ts_pendulim_B.LimitFlagSource[0] = 0.0;
    ts_pendulim_B.LimitFlagSource[1] = 0.0;
    ts_pendulim_B.LimitFlagSource[2] = 0.0;
    ts_pendulim_B.LimitSource[0] = 0.0;
    ts_pendulim_B.LimitSource[1] = 0.0;
    ts_pendulim_B.LimitSource[2] = 0.0;
    ts_pendulim_B.SetLimit[0] = 0.0;
    ts_pendulim_B.SetLimit[1] = 0.0;
    ts_pendulim_B.SetLimit[2] = 0.0;
    ts_pendulim_B.LimitSwitch[0] = 0.0;
    ts_pendulim_B.LimitSwitch[1] = 0.0;
    ts_pendulim_B.LimitSwitch[2] = 0.0;
    ts_pendulim_B.PWMPrescaler = 0.0;
    ts_pendulim_B.PWMPrescalerSource = 0.0;
    ts_pendulim_B.ResetSwitchFlag[0] = 0.0;
    ts_pendulim_B.ResetSwitchFlag[1] = 0.0;
    ts_pendulim_B.ResetSwitchFlag[2] = 0.0;
    ts_pendulim_B.ResetSwitchFlagSource[0] = 0.0;
    ts_pendulim_B.ResetSwitchFlagSource[1] = 0.0;
    ts_pendulim_B.ResetSwitchFlagSource[2] = 0.0;
    ts_pendulim_B.ThermFlag[0] = 0.0;
    ts_pendulim_B.ThermFlag[1] = 0.0;
    ts_pendulim_B.ThermFlag[2] = 0.0;
    ts_pendulim_B.ThermFlagSource[0] = 0.0;
    ts_pendulim_B.ThermFlagSource[1] = 0.0;
    ts_pendulim_B.ThermFlagSource[2] = 0.0;
    ts_pendulim_B.ResetEncoders = 0.0;
    ts_pendulim_B.FilterCoefficient = 0.0;
    ts_pendulim_B.IntegralGain = 0.0;
  }

  /* parameters */
  ts_pendulim_M->ModelData.defaultParam = ((real_T *)&ts_pendulim_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ts_pendulim_X;
    ts_pendulim_M->ModelData.contStates = (x);
    (void) memset((void *)&ts_pendulim_X, 0,
                  sizeof(X_ts_pendulim_T));
  }

  /* states (dwork) */
  ts_pendulim_M->ModelData.dwork = ((void *) &ts_pendulim_DW);
  (void) memset((void *)&ts_pendulim_DW, 0,
                sizeof(DW_ts_pendulim_T));
  ts_pendulim_DW.Memory_PreviousInput = 0.0;
  ts_pendulim_DW.Memory1_PreviousInput = 0.0;
  ts_pendulim_DW.Memory_PreviousInput_b = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ts_pendulim_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &ts_pendulim_M->NonInlinedSFcns.sfcnInfo;
    ts_pendulim_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(ts_pendulim_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &ts_pendulim_M->Sizes.numSampTimes);
    ts_pendulim_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(ts_pendulim_M)
      [0]);
    ts_pendulim_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(ts_pendulim_M)
      [1]);
    rtssSetTPtrPtr(sfcnInfo,ts_pendulim_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(ts_pendulim_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(ts_pendulim_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(ts_pendulim_M));
    rtssSetStepSizePtr(sfcnInfo, &ts_pendulim_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(ts_pendulim_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &ts_pendulim_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &ts_pendulim_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &ts_pendulim_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &ts_pendulim_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &ts_pendulim_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &ts_pendulim_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &ts_pendulim_M->solverInfoPtr);
  }

  ts_pendulim_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&ts_pendulim_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    ts_pendulim_M->childSfunctions =
      (&ts_pendulim_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        ts_pendulim_M->childSfunctions[i] =
          (&ts_pendulim_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.Encoder_P2_Size);
      }

      /* registration */
      P1_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/PWM (P1_PWM) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = ts_pendulim_B.Saturation;
          sfcnUPtrs[1] = &ts_pendulim_B.Saturation[1];
          sfcnUPtrs[2] = &ts_pendulim_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.PWM_P2_Size);
      }

      /* registration */
      P1_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &ts_pendulim_B.ResetSource[0];
          sfcnUPtrs[1] = &ts_pendulim_B.ResetSource[1];
          sfcnUPtrs[2] = &ts_pendulim_B.ResetSource[2];
          sfcnUPtrs[3] = &ts_pendulim_B.ResetEncoders;
          sfcnUPtrs[4] = &ts_pendulim_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.ResetEncoder_P2_Size);
      }

      /* registration */
      P1_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = ts_pendulim_B.LimitFlagSource;
          sfcnUPtrs[1] = &ts_pendulim_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &ts_pendulim_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.LimitFlag_P2_Size);
      }

      /* registration */
      P1_LimitFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = ts_pendulim_B.LimitSource;
          sfcnUPtrs[1] = &ts_pendulim_B.LimitSource[1];
          sfcnUPtrs[2] = &ts_pendulim_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.SetLimit_P2_Size);
      }

      /* registration */
      P1_SetLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.LimitSwitch_P2_Size);
      }

      /* registration */
      P1_Switch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &ts_pendulim_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &ts_pendulim_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      P1_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = ts_pendulim_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &ts_pendulim_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &ts_pendulim_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            ts_pendulim_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.ResetSwitchFlag_P2_Size);
      }

      /* registration */
      P1_ResetSwitchFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: ts_pendulim/<S2>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = ts_pendulim_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = ts_pendulim_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = ts_pendulim_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = ts_pendulim_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &ts_pendulim_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, ts_pendulim_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &ts_pendulim_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &ts_pendulim_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &ts_pendulim_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &ts_pendulim_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = ts_pendulim_B.ThermFlagSource;
          sfcnUPtrs[1] = &ts_pendulim_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &ts_pendulim_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &ts_pendulim_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) ts_pendulim_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "ts_pendulim/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,ts_pendulim_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &ts_pendulim_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)ts_pendulim_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)ts_pendulim_P.ThermFlag_P2_Size);
      }

      /* registration */
      P1_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  ts_pendulim_M->Sizes.numContStates = (2);/* Number of continuous states */
  ts_pendulim_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  ts_pendulim_M->Sizes.numY = (0);     /* Number of model outputs */
  ts_pendulim_M->Sizes.numU = (0);     /* Number of model inputs */
  ts_pendulim_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ts_pendulim_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ts_pendulim_M->Sizes.numBlocks = (61);/* Number of blocks */
  ts_pendulim_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  ts_pendulim_M->Sizes.numBlockPrms = (101);/* Sum of parameter "widths" */
  return ts_pendulim_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
