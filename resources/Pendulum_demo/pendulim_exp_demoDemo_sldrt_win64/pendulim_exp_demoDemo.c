/*
 * pendulim_exp_demoDemo.c
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
#include "pendulim_exp_demoDemo_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_B;

/* Continuous states */
X_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_X;

/* Block states (auto storage) */
DW_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_PrevZCX;

/* Real-time model */
RT_MODEL_pendulim_exp_demoDemo_T pendulim_exp_demoDemo_M_;
RT_MODEL_pendulim_exp_demoDemo_T *const pendulim_exp_demoDemo_M =
  &pendulim_exp_demoDemo_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  pendulim_exp_demoDemo_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  pendulim_exp_demoDemo_output();
  pendulim_exp_demoDemo_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  pendulim_exp_demoDemo_output();
  pendulim_exp_demoDemo_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  pendulim_exp_demoDemo_output();
  pendulim_exp_demoDemo_derivatives();

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
  pendulim_exp_demoDemo_output();
  pendulim_exp_demoDemo_derivatives();

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
  pendulim_exp_demoDemo_output();
  pendulim_exp_demoDemo_derivatives();

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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void pendulim_exp_demoDemo_output(void)
{
  /* local block i/o variables */
  real_T rtb_ResetEncoders1;
  real_T rtb_Encoder1024PPR[5];
  real_T rtb_SineGain;
  real_T rtb_SquareGain;
  real_T rtb_Gain1;
  real_T rtb_Gain2;
  real_T rtb_Gain3;
  real_T rtb_Gain4;
  real_T rtb_s2;
  int32_T i;
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* set solver stop time */
    if (!(pendulim_exp_demoDemo_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&pendulim_exp_demoDemo_M->solverInfo,
                            ((pendulim_exp_demoDemo_M->Timing.clockTickH0 + 1) *
        pendulim_exp_demoDemo_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&pendulim_exp_demoDemo_M->solverInfo,
                            ((pendulim_exp_demoDemo_M->Timing.clockTick0 + 1) *
        pendulim_exp_demoDemo_M->Timing.stepSize0 +
        pendulim_exp_demoDemo_M->Timing.clockTickH0 *
        pendulim_exp_demoDemo_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pendulim_exp_demoDemo_M)) {
    pendulim_exp_demoDemo_M->Timing.t[0] = rtsiGetT
      (&pendulim_exp_demoDemo_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S2>/Encoder 1024 PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder1024PPR[i] = pendulim_exp_demoDemo_P.Encoder1024PPR_Gain *
        pendulim_exp_demoDemo_B.Encoder[i];
    }

    /* End of Gain: '<S2>/Encoder 1024 PPR' */

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Cart Offset'
     *  Gain: '<S2>/PosCart Scale'
     */
    pendulim_exp_demoDemo_B.Sum = pendulim_exp_demoDemo_P.PosCartScale_Gain *
      rtb_Encoder1024PPR[4] + pendulim_exp_demoDemo_P.CartOffset_Value;

    /* Gain: '<S7>/Gain3' */
    pendulim_exp_demoDemo_B.Cart_pos = pendulim_exp_demoDemo_P.Gain3_Gain *
      pendulim_exp_demoDemo_B.Sum;
  }

  /* SignalGenerator: '<S6>/sine' */
  rtb_ResetEncoders1 = sin(6.2831853071795862 *
    pendulim_exp_demoDemo_M->Timing.t[0] *
    pendulim_exp_demoDemo_P.RefCartPos_Frequency) *
    pendulim_exp_demoDemo_P.RefCartPos_Amplitude;

  /* Gain: '<S6>/SineGain' */
  rtb_SineGain = pendulim_exp_demoDemo_P.RefCartPos_Sine * rtb_ResetEncoders1;

  /* SignalGenerator: '<S6>/square' */
  rtb_Gain1 = pendulim_exp_demoDemo_P.RefCartPos_Frequency *
    pendulim_exp_demoDemo_M->Timing.t[0];
  if (rtb_Gain1 - floor(rtb_Gain1) >= 0.5) {
    rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.RefCartPos_Amplitude;
  } else {
    rtb_ResetEncoders1 = -pendulim_exp_demoDemo_P.RefCartPos_Amplitude;
  }

  /* End of SignalGenerator: '<S6>/square' */

  /* Gain: '<S6>/SquareGain' */
  rtb_SquareGain = pendulim_exp_demoDemo_P.RefCartPos_Square *
    rtb_ResetEncoders1;

  /* SignalGenerator: '<S6>/sawtooth' */
  rtb_Gain1 = pendulim_exp_demoDemo_P.RefCartPos_Frequency *
    pendulim_exp_demoDemo_M->Timing.t[0];
  rtb_ResetEncoders1 = (1.0 - (rtb_Gain1 - floor(rtb_Gain1)) * 2.0) *
    pendulim_exp_demoDemo_P.RefCartPos_Amplitude;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/SawToothGain'
   */
  rtb_ResetEncoders1 = (rtb_SineGain + rtb_SquareGain) +
    pendulim_exp_demoDemo_P.RefCartPos_Sawtooth * rtb_ResetEncoders1;

  /* Gain: '<Root>/Matrix Gain' incorporates:
   *  Constant: '<S6>/Const1'
   *  Constant: '<S6>/Const2'
   *  Constant: '<S6>/Const3'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtMatrix GainInport1'
   */
  pendulim_exp_demoDemo_B.MatrixGain =
    ((pendulim_exp_demoDemo_P.MatrixGain_Gain[0] *
      pendulim_exp_demoDemo_P.Const1_Value +
      pendulim_exp_demoDemo_P.MatrixGain_Gain[1] *
      pendulim_exp_demoDemo_P.Const2_Value) +
     pendulim_exp_demoDemo_P.MatrixGain_Gain[2] * rtb_ResetEncoders1) +
    pendulim_exp_demoDemo_P.MatrixGain_Gain[3] *
    pendulim_exp_demoDemo_P.Const3_Value;
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Gain: '<S2>/Angle Scale' */
    pendulim_exp_demoDemo_B.AngleScale = pendulim_exp_demoDemo_P.AngleScale_Gain
      * rtb_Encoder1024PPR[3];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/pi'
     *  Constant: '<S1>/pos'
     *  Gain: '<S7>/Gain1'
     *  Product: '<S1>/Product'
     */
    rtb_SineGain = pendulim_exp_demoDemo_P.pi_Value *
      pendulim_exp_demoDemo_P.AlfaNormalization_pos +
      pendulim_exp_demoDemo_P.Gain1_Gain * pendulim_exp_demoDemo_B.AngleScale;

    /* Fcn: '<S1>/angle normalization' */
    pendulim_exp_demoDemo_B.PendPosOut = rt_atan2d_snf(sin(rtb_SineGain), cos
      (rtb_SineGain));

    /* Gain: '<S7>/Gain2' incorporates:
     *  Memory: '<S7>/Memory'
     *  Sum: '<S7>/Sum'
     */
    pendulim_exp_demoDemo_B.Pend_vel = 1.0 / pendulim_exp_demoDemo_P.Sensors_T0 *
      (pendulim_exp_demoDemo_B.AngleScale -
       pendulim_exp_demoDemo_DW.Memory_PreviousInput);

    /* Gain: '<S7>/Gain4' incorporates:
     *  Memory: '<S7>/Memory1'
     *  Sum: '<S7>/Sum1'
     */
    pendulim_exp_demoDemo_B.Cart_vel = 1.0 / pendulim_exp_demoDemo_P.Sensors_T0 *
      (pendulim_exp_demoDemo_B.Sum -
       pendulim_exp_demoDemo_DW.Memory1_PreviousInput);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S6>/Const1'
   *  Constant: '<S6>/Const2'
   *  Constant: '<S6>/Const3'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtMatrix GainInport1'
   */
  pendulim_exp_demoDemo_B.Sum_k[0] = pendulim_exp_demoDemo_P.Const1_Value -
    pendulim_exp_demoDemo_B.PendPosOut;
  pendulim_exp_demoDemo_B.Sum_k[1] = pendulim_exp_demoDemo_P.Const2_Value -
    pendulim_exp_demoDemo_B.Pend_vel;
  pendulim_exp_demoDemo_B.Sum_k[2] = rtb_ResetEncoders1 -
    pendulim_exp_demoDemo_B.Cart_pos;
  pendulim_exp_demoDemo_B.Sum_k[3] = pendulim_exp_demoDemo_P.Const3_Value -
    pendulim_exp_demoDemo_B.Cart_vel;

  /* Fcn: '<S13>/Fcn' */
  rtb_ResetEncoders1 = -pendulim_exp_demoDemo_B.Sum_k[2];

  /* Signum: '<S13>/Sign' */
  if (rtb_ResetEncoders1 < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_ResetEncoders1 > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_ResetEncoders1 == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_ResetEncoders1;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  Signum: '<S13>/Sign'
   */
  rtb_SineGain = pendulim_exp_demoDemo_P.Nottoescapewatchdog_umax2 * rtb_Gain3;

  /* Fcn: '<S4>/limiter' */
  rtb_SquareGain = fabs(pendulim_exp_demoDemo_B.Sum_k[2]) - 0.5;

  /* Sum: '<S14>/s2' incorporates:
   *  Constant: '<S14>/one '
   *  Fcn: '<S14>/Kinetic Energy'
   *  Fcn: '<S14>/Potential Energy'
   *  Gain: '<S14>/Gain'
   *  Sum: '<S14>/s3'
   */
  rtb_s2 = 9.81 * pendulim_exp_demoDemo_P.Softlandingarbiter_k *
    pendulim_exp_demoDemo_P.Softlandingarbiter_R * (cos
    (pendulim_exp_demoDemo_B.Sum_k[0]) - pendulim_exp_demoDemo_P.one_Value) +
    pendulim_exp_demoDemo_B.Sum_k[1] * pendulim_exp_demoDemo_B.Sum_k[1] * 0.5;

  /* Fcn: '<S15>/abs(x1)' */
  rtb_ResetEncoders1 = (fabs(pendulim_exp_demoDemo_B.Sum_k[0]) -
                        1.5707963267948966) * pendulim_exp_demoDemo_B.Sum_k[1];

  /* Relay: '<S15>/swing' */
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    if (rtb_ResetEncoders1 >= pendulim_exp_demoDemo_P.swing_OnVal) {
      pendulim_exp_demoDemo_DW.swing_Mode = true;
    } else {
      if (rtb_ResetEncoders1 <= pendulim_exp_demoDemo_P.swing_OffVal) {
        pendulim_exp_demoDemo_DW.swing_Mode = false;
      }
    }
  }

  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Relay: '<S15>/swing' */
    if (pendulim_exp_demoDemo_DW.swing_Mode) {
      rtb_Gain3 = pendulim_exp_demoDemo_P.swing_YOn;
    } else {
      rtb_Gain3 = pendulim_exp_demoDemo_P.swing_YOff;
    }

    /* Gain: '<S15>/umax' */
    pendulim_exp_demoDemo_B.umax =
      pendulim_exp_demoDemo_P.Swingingcontroller_umax * rtb_Gain3;
  }

  /* Gain: '<S12>/Gain1' */
  rtb_Gain1 = pendulim_exp_demoDemo_P.Gain1_Gain_f *
    pendulim_exp_demoDemo_B.Sum_k[0];

  /* TransferFcn: '<S12>/Transfer Fcn' */
  rtb_ResetEncoders1 = 0.0;
  rtb_ResetEncoders1 += pendulim_exp_demoDemo_P.TransferFcn_C *
    pendulim_exp_demoDemo_X.TransferFcn_CSTATE;

  /* Gain: '<S12>/Gain2' */
  rtb_Gain2 = pendulim_exp_demoDemo_P.Gain2_Gain * rtb_ResetEncoders1;

  /* Saturate: '<S12>/Saturation Cart Error' */
  if (pendulim_exp_demoDemo_B.Sum_k[2] >
      pendulim_exp_demoDemo_P.SaturationCartError_UpperSat) {
    rtb_Gain3 = pendulim_exp_demoDemo_P.SaturationCartError_UpperSat;
  } else if (pendulim_exp_demoDemo_B.Sum_k[2] <
             pendulim_exp_demoDemo_P.SaturationCartError_LowerSat) {
    rtb_Gain3 = pendulim_exp_demoDemo_P.SaturationCartError_LowerSat;
  } else {
    rtb_Gain3 = pendulim_exp_demoDemo_B.Sum_k[2];
  }

  /* Gain: '<S12>/Gain3' incorporates:
   *  Saturate: '<S12>/Saturation Cart Error'
   */
  rtb_Gain3 *= pendulim_exp_demoDemo_P.Gain3_Gain_e;

  /* Gain: '<S12>/Gain4' */
  rtb_Gain4 = pendulim_exp_demoDemo_P.Gain4_Gain *
    pendulim_exp_demoDemo_B.Sum_k[3];

  /* Fcn: '<S12>/Fcn' */
  pendulim_exp_demoDemo_B.Fcn = (fabs(pendulim_exp_demoDemo_B.Sum_k[0]) < 0.1);

  /* Integrator: '<S12>/Integrator'
   *
   * Regarding '<S12>/Integrator':
   *  Limited Integrator
   */
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &pendulim_exp_demoDemo_PrevZCX.Integrator_Reset_ZCE,
                       pendulim_exp_demoDemo_B.Fcn);

    /* evaluate zero-crossings */
    if (zcEvent) {
      pendulim_exp_demoDemo_X.Integrator_CSTATE =
        pendulim_exp_demoDemo_P.Integrator_IC;
    }
  }

  if (pendulim_exp_demoDemo_X.Integrator_CSTATE >=
      pendulim_exp_demoDemo_P.Integrator_UpperSat ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE =
      pendulim_exp_demoDemo_P.Integrator_UpperSat;
  } else if (pendulim_exp_demoDemo_X.Integrator_CSTATE <=
             (pendulim_exp_demoDemo_P.Integrator_LowerSat) ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE =
      (pendulim_exp_demoDemo_P.Integrator_LowerSat);
  }

  rtb_ResetEncoders1 = pendulim_exp_demoDemo_X.Integrator_CSTATE;

  /* Sum: '<S12>/Sum' */
  rtb_ResetEncoders1 += ((rtb_Gain1 + rtb_Gain2) + rtb_Gain3) + rtb_Gain4;

  /* Switch: '<S4>/4' incorporates:
   *  Fcn: '<S4>/Upper zone arbiter'
   *  Saturate: '<S12>/Saturation'
   *  Switch: '<S4>/2'
   */
  if (rtb_SquareGain >= pendulim_exp_demoDemo_P._Threshold_b) {
    rtb_ResetEncoders1 = rtb_SineGain;
  } else if (fabs(pendulim_exp_demoDemo_B.Sum_k[0]) - 0.2 >=
             pendulim_exp_demoDemo_P._Threshold_p) {
    /* Switch: '<S4>/3' incorporates:
     *  Constant: '<S4>/Control = 0'
     *  Switch: '<S4>/2'
     */
    if (rtb_s2 >= pendulim_exp_demoDemo_P._Threshold) {
      rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.Control0_Value;
    } else {
      rtb_ResetEncoders1 = pendulim_exp_demoDemo_B.umax;
    }

    /* End of Switch: '<S4>/3' */
  } else if (rtb_ResetEncoders1 >
             pendulim_exp_demoDemo_P.Linearcontroller1_umax1) {
    /* Saturate: '<S12>/Saturation' incorporates:
     *  Switch: '<S4>/2'
     */
    rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.Linearcontroller1_umax1;
  } else {
    if (rtb_ResetEncoders1 < -pendulim_exp_demoDemo_P.Linearcontroller1_umax1) {
      /* Saturate: '<S12>/Saturation' incorporates:
       *  Switch: '<S4>/2'
       */
      rtb_ResetEncoders1 = -pendulim_exp_demoDemo_P.Linearcontroller1_umax1;
    }
  }

  /* End of Switch: '<S4>/4' */

  /* Signum: '<S11>/Sign' */
  if (rtb_ResetEncoders1 < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_ResetEncoders1 > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_ResetEncoders1 == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_ResetEncoders1;
  }

  /* Gain: '<S11>/Gain1' incorporates:
   *  Signum: '<S11>/Sign'
   */
  rtb_SineGain = pendulim_exp_demoDemo_P.CoulombViscousFriction_offset *
    rtb_Gain3;

  /* Gain: '<S11>/Gain' */
  rtb_SquareGain = pendulim_exp_demoDemo_P.CoulombViscousFriction_gain *
    rtb_ResetEncoders1;
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
    pendulim_exp_demoDemo_B.CtrlMode =
      (pendulim_exp_demoDemo_DW.clockTickCounter <
       pendulim_exp_demoDemo_P.AlgorithmSelector2_Duty) &&
      (pendulim_exp_demoDemo_DW.clockTickCounter >= 0) ?
      pendulim_exp_demoDemo_P.AlgorithmSelector2_Amp : 0.0;
    if (pendulim_exp_demoDemo_DW.clockTickCounter >=
        pendulim_exp_demoDemo_P.AlgorithmSelector2_Period - 1.0) {
      pendulim_exp_demoDemo_DW.clockTickCounter = 0;
    } else {
      pendulim_exp_demoDemo_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Fcn: '<S3>/angle normalization'
   */
  pendulim_exp_demoDemo_B.Gain1 = rt_atan2d_snf(sin
    (pendulim_exp_demoDemo_B.Sum_k[0] + 3.1415926535897931), cos
    (pendulim_exp_demoDemo_B.Sum_k[0] + 3.1415926535897931)) *
    pendulim_exp_demoDemo_P.Gain1_Gain_g;

  /* Gain: '<S10>/Kp' */
  rtb_Gain1 = pendulim_exp_demoDemo_P.PIDPend_P * pendulim_exp_demoDemo_B.Gain1;

  /* Integrator: '<S10>/Integrator'
   *
   * Regarding '<S10>/Integrator':
   *  Limited Integrator
   */
  if (pendulim_exp_demoDemo_X.Integrator_CSTATE_m >=
      pendulim_exp_demoDemo_P.Integrator_UpperSat_l ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE_m =
      pendulim_exp_demoDemo_P.Integrator_UpperSat_l;
  } else if (pendulim_exp_demoDemo_X.Integrator_CSTATE_m <=
             (pendulim_exp_demoDemo_P.Integrator_LowerSat_k) ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE_m =
      (pendulim_exp_demoDemo_P.Integrator_LowerSat_k);
  }

  rtb_ResetEncoders1 = pendulim_exp_demoDemo_X.Integrator_CSTATE_m;

  /* Gain: '<S10>/Ki' */
  rtb_Gain2 = pendulim_exp_demoDemo_P.PIDPend_I * rtb_ResetEncoders1;
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Memory: '<S10>/Memory' */
    pendulim_exp_demoDemo_B.Memory =
      pendulim_exp_demoDemo_DW.Memory_PreviousInput_a;
  }

  /* Gain: '<S10>/Kd1' incorporates:
   *  Sum: '<S10>/Sum1'
   */
  rtb_Gain3 = pendulim_exp_demoDemo_P.PIDPend_D /
    pendulim_exp_demoDemo_P.ControllerPID_T0 * (pendulim_exp_demoDemo_B.Gain1 -
    pendulim_exp_demoDemo_B.Memory);

  /* Gain: '<S3>/Gain3' */
  pendulim_exp_demoDemo_B.Gain3 = pendulim_exp_demoDemo_P.Gain3_Gain_b *
    pendulim_exp_demoDemo_B.Sum_k[2];

  /* Gain: '<S9>/Kp' */
  rtb_Gain4 = pendulim_exp_demoDemo_P.PIDCart_P * pendulim_exp_demoDemo_B.Gain3;

  /* Integrator: '<S9>/Integrator'
   *
   * Regarding '<S9>/Integrator':
   *  Limited Integrator
   */
  if (pendulim_exp_demoDemo_X.Integrator_CSTATE_p >=
      pendulim_exp_demoDemo_P.Integrator_UpperSat_b ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE_p =
      pendulim_exp_demoDemo_P.Integrator_UpperSat_b;
  } else if (pendulim_exp_demoDemo_X.Integrator_CSTATE_p <=
             (pendulim_exp_demoDemo_P.Integrator_LowerSat_kg) ) {
    pendulim_exp_demoDemo_X.Integrator_CSTATE_p =
      (pendulim_exp_demoDemo_P.Integrator_LowerSat_kg);
  }

  rtb_ResetEncoders1 = pendulim_exp_demoDemo_X.Integrator_CSTATE_p;
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Memory: '<S9>/Memory' */
    pendulim_exp_demoDemo_B.Memory_o =
      pendulim_exp_demoDemo_DW.Memory_PreviousInput_o;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S9>/Kd1'
   *  Gain: '<S9>/Ki'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  rtb_ResetEncoders1 = ((pendulim_exp_demoDemo_P.PIDCart_I * rtb_ResetEncoders1
    + rtb_Gain4) + pendulim_exp_demoDemo_P.PIDCart_D /
                        pendulim_exp_demoDemo_P.ControllerPID_T0 *
                        (pendulim_exp_demoDemo_B.Gain3 -
    pendulim_exp_demoDemo_B.Memory_o)) + ((rtb_Gain1 + rtb_Gain2) + rtb_Gain3);

  /* Signum: '<S8>/Sign' */
  if (rtb_ResetEncoders1 < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_ResetEncoders1 > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_ResetEncoders1 == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_ResetEncoders1;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Signum: '<S8>/Sign'
   */
  rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.ControllerPID_Friction *
    rtb_Gain3 + pendulim_exp_demoDemo_P.CoulombViscousFriction_gain_h *
    rtb_ResetEncoders1;

  /* Switch: '<Root>/Switch' incorporates:
   *  Fcn: '<S3>/Fcn'
   *  Product: '<S3>/Product1'
   *  Saturate: '<S3>/CtrlSat1'
   */
  if (pendulim_exp_demoDemo_B.CtrlMode >=
      pendulim_exp_demoDemo_P.Switch_Threshold) {
    /* Sum: '<S11>/Sum' */
    rtb_Gain3 = rtb_SineGain + rtb_SquareGain;

    /* Saturate: '<S4>/CtrlSat' */
    if (rtb_Gain3 > pendulim_exp_demoDemo_P.CtrlSat_UpperSat) {
      rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.CtrlSat_UpperSat;
    } else if (rtb_Gain3 < pendulim_exp_demoDemo_P.CtrlSat_LowerSat) {
      rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.CtrlSat_LowerSat;
    } else {
      rtb_ResetEncoders1 = rtb_Gain3;
    }

    /* End of Saturate: '<S4>/CtrlSat' */
  } else {
    if (rtb_ResetEncoders1 > pendulim_exp_demoDemo_P.ControllerPID_Umax) {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = pendulim_exp_demoDemo_P.ControllerPID_Umax;
    } else if (rtb_ResetEncoders1 < -pendulim_exp_demoDemo_P.ControllerPID_Umax)
    {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = -pendulim_exp_demoDemo_P.ControllerPID_Umax;
    } else {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = rtb_ResetEncoders1;
    }

    rtb_ResetEncoders1 = (real_T)(fabs(pendulim_exp_demoDemo_B.Gain1) < 1.3) *
      rtb_Gain3;
  }

  /* End of Switch: '<Root>/Switch' */
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Fcn: '<S5>/Fcn' */
    pendulim_exp_demoDemo_B.Fcn_k = rt_powd_snf
      ((pendulim_exp_demoDemo_B.Cart_pos - 0.8) * 10.0, 3.0) * (real_T)
      (pendulim_exp_demoDemo_B.Cart_pos >= 0.8) + rt_powd_snf
      ((pendulim_exp_demoDemo_B.Cart_pos + 0.8) * 10.0, 3.0) * (real_T)
      (pendulim_exp_demoDemo_B.Cart_pos <= -0.8);
  }

  /* Sum: '<S5>/Sum' */
  rtb_ResetEncoders1 += pendulim_exp_demoDemo_B.Fcn_k;

  /* Saturate: '<S5>/CtrlSat' */
  if (rtb_ResetEncoders1 > pendulim_exp_demoDemo_P.CtrlSat_UpperSat_o) {
    pendulim_exp_demoDemo_B.CtrlSat = pendulim_exp_demoDemo_P.CtrlSat_UpperSat_o;
  } else if (rtb_ResetEncoders1 < pendulim_exp_demoDemo_P.CtrlSat_LowerSat_l) {
    pendulim_exp_demoDemo_B.CtrlSat = pendulim_exp_demoDemo_P.CtrlSat_LowerSat_l;
  } else {
    pendulim_exp_demoDemo_B.CtrlSat = rtb_ResetEncoders1;
  }

  /* End of Saturate: '<S5>/CtrlSat' */
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* ManualSwitch: '<Root>/Reset Encoders1' incorporates:
   *  Constant: '<Root>/Normal1'
   */
  if (pendulim_exp_demoDemo_P.ResetEncoders1_CurrentSetting == 1) {
    rtb_ResetEncoders1 = pendulim_exp_demoDemo_B.CtrlSat;
  } else {
    rtb_ResetEncoders1 = pendulim_exp_demoDemo_P.Normal1_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders1' */

  /* Saturate: '<S2>/Saturation' */
  if (0.0 > pendulim_exp_demoDemo_P.Saturation_UpperSat) {
    pendulim_exp_demoDemo_B.Saturation[0] =
      pendulim_exp_demoDemo_P.Saturation_UpperSat;
  } else if (0.0 < pendulim_exp_demoDemo_P.Saturation_LowerSat) {
    pendulim_exp_demoDemo_B.Saturation[0] =
      pendulim_exp_demoDemo_P.Saturation_LowerSat;
  } else {
    pendulim_exp_demoDemo_B.Saturation[0] = 0.0;
  }

  if (rtb_ResetEncoders1 > pendulim_exp_demoDemo_P.Saturation_UpperSat) {
    pendulim_exp_demoDemo_B.Saturation[1] =
      pendulim_exp_demoDemo_P.Saturation_UpperSat;
  } else if (rtb_ResetEncoders1 < pendulim_exp_demoDemo_P.Saturation_LowerSat) {
    pendulim_exp_demoDemo_B.Saturation[1] =
      pendulim_exp_demoDemo_P.Saturation_LowerSat;
  } else {
    pendulim_exp_demoDemo_B.Saturation[1] = rtb_ResetEncoders1;
  }

  if (0.0 > pendulim_exp_demoDemo_P.Saturation_UpperSat) {
    pendulim_exp_demoDemo_B.Saturation[2] =
      pendulim_exp_demoDemo_P.Saturation_UpperSat;
  } else if (0.0 < pendulim_exp_demoDemo_P.Saturation_LowerSat) {
    pendulim_exp_demoDemo_B.Saturation[2] =
      pendulim_exp_demoDemo_P.Saturation_LowerSat;
  } else {
    pendulim_exp_demoDemo_B.Saturation[2] = 0.0;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSource' */
    pendulim_exp_demoDemo_B.ResetSource[0] =
      pendulim_exp_demoDemo_P.ResetSource_Value[0];
    pendulim_exp_demoDemo_B.ResetSource[1] =
      pendulim_exp_demoDemo_P.ResetSource_Value[1];
    pendulim_exp_demoDemo_B.ResetSource[2] =
      pendulim_exp_demoDemo_P.ResetSource_Value[2];

    /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/LimitFlagSource' */
    pendulim_exp_demoDemo_B.LimitFlagSource[0] =
      pendulim_exp_demoDemo_P.LimitFlagSource_Value[0];
    pendulim_exp_demoDemo_B.LimitFlagSource[1] =
      pendulim_exp_demoDemo_P.LimitFlagSource_Value[1];
    pendulim_exp_demoDemo_B.LimitFlagSource[2] =
      pendulim_exp_demoDemo_P.LimitFlagSource_Value[2];

    /* Constant: '<S2>/LimitSource' */
    pendulim_exp_demoDemo_B.LimitSource[0] =
      pendulim_exp_demoDemo_P.LimitSource_Value[0];
    pendulim_exp_demoDemo_B.LimitSource[1] =
      pendulim_exp_demoDemo_P.LimitSource_Value[1];
    pendulim_exp_demoDemo_B.LimitSource[2] =
      pendulim_exp_demoDemo_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/PWMPrescalerSource' */
    pendulim_exp_demoDemo_B.PWMPrescalerSource =
      pendulim_exp_demoDemo_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSwitchFlagSource' */
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[0] =
      pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[0];
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[1] =
      pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[1];
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[2] =
      pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ThermFlagSource' */
    pendulim_exp_demoDemo_B.ThermFlagSource[0] =
      pendulim_exp_demoDemo_P.ThermFlagSource_Value[0];
    pendulim_exp_demoDemo_B.ThermFlagSource[1] =
      pendulim_exp_demoDemo_P.ThermFlagSource_Value[1];
    pendulim_exp_demoDemo_B.ThermFlagSource[2] =
      pendulim_exp_demoDemo_P.ThermFlagSource_Value[2];
  }

  /* Fcn: '<S4>/Fcn' */
  pendulim_exp_demoDemo_B.Fcn_kz = (rtb_s2 > 0.0);
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
  }

  /* Gain: '<S12>/Integrator Gain' */
  pendulim_exp_demoDemo_B.IntegratorGain =
    pendulim_exp_demoDemo_P.IntegratorGain_Gain * pendulim_exp_demoDemo_B.Sum_k
    [2];
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (pendulim_exp_demoDemo_P.ResetEncoders_CurrentSetting == 1) {
      pendulim_exp_demoDemo_B.ResetEncoders =
        pendulim_exp_demoDemo_P.Reset_Value;
    } else {
      pendulim_exp_demoDemo_B.ResetEncoders =
        pendulim_exp_demoDemo_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */
  }
}

/* Model update function */
void pendulim_exp_demoDemo_update(void)
{
  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Update for Memory: '<S7>/Memory' */
    pendulim_exp_demoDemo_DW.Memory_PreviousInput =
      pendulim_exp_demoDemo_B.AngleScale;

    /* Update for Memory: '<S7>/Memory1' */
    pendulim_exp_demoDemo_DW.Memory1_PreviousInput = pendulim_exp_demoDemo_B.Sum;
  }

  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Update for Memory: '<S10>/Memory' */
    pendulim_exp_demoDemo_DW.Memory_PreviousInput_a =
      pendulim_exp_demoDemo_B.Gain1;
  }

  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    /* Update for Memory: '<S9>/Memory' */
    pendulim_exp_demoDemo_DW.Memory_PreviousInput_o =
      pendulim_exp_demoDemo_B.Gain3;
  }

  if (rtmIsMajorTimeStep(pendulim_exp_demoDemo_M)) {
    rt_ertODEUpdateContinuousStates(&pendulim_exp_demoDemo_M->solverInfo);
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
  if (!(++pendulim_exp_demoDemo_M->Timing.clockTick0)) {
    ++pendulim_exp_demoDemo_M->Timing.clockTickH0;
  }

  pendulim_exp_demoDemo_M->Timing.t[0] = rtsiGetSolverStopTime
    (&pendulim_exp_demoDemo_M->solverInfo);

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
    if (!(++pendulim_exp_demoDemo_M->Timing.clockTick1)) {
      ++pendulim_exp_demoDemo_M->Timing.clockTickH1;
    }

    pendulim_exp_demoDemo_M->Timing.t[1] =
      pendulim_exp_demoDemo_M->Timing.clockTick1 *
      pendulim_exp_demoDemo_M->Timing.stepSize1 +
      pendulim_exp_demoDemo_M->Timing.clockTickH1 *
      pendulim_exp_demoDemo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void pendulim_exp_demoDemo_derivatives(void)
{
  XDot_pendulim_exp_demoDemo_T *_rtXdot;
  _rtXdot = ((XDot_pendulim_exp_demoDemo_T *)
             pendulim_exp_demoDemo_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += pendulim_exp_demoDemo_P.TransferFcn_A *
    pendulim_exp_demoDemo_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += pendulim_exp_demoDemo_B.Sum_k[1];

  /* Derivatives for Integrator: '<S12>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE <=
            (pendulim_exp_demoDemo_P.Integrator_LowerSat) );
    usat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE >=
            pendulim_exp_demoDemo_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (pendulim_exp_demoDemo_B.IntegratorGain > 0)) ||
        (usat && (pendulim_exp_demoDemo_B.IntegratorGain < 0)) ) {
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE =
        pendulim_exp_demoDemo_B.IntegratorGain;
    } else {
      /* in saturation */
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE_m <=
            (pendulim_exp_demoDemo_P.Integrator_LowerSat_k) );
    usat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE_m >=
            pendulim_exp_demoDemo_P.Integrator_UpperSat_l );
    if ((!lsat && !usat) ||
        (lsat && (pendulim_exp_demoDemo_B.Gain1 > 0)) ||
        (usat && (pendulim_exp_demoDemo_B.Gain1 < 0)) ) {
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE_m =
        pendulim_exp_demoDemo_B.Gain1;
    } else {
      /* in saturation */
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE_m = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S9>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE_p <=
            (pendulim_exp_demoDemo_P.Integrator_LowerSat_kg) );
    usat = ( pendulim_exp_demoDemo_X.Integrator_CSTATE_p >=
            pendulim_exp_demoDemo_P.Integrator_UpperSat_b );
    if ((!lsat && !usat) ||
        (lsat && (pendulim_exp_demoDemo_B.Gain3 > 0)) ||
        (usat && (pendulim_exp_demoDemo_B.Gain3 < 0)) ) {
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE_p =
        pendulim_exp_demoDemo_B.Gain3;
    } else {
      /* in saturation */
      ((XDot_pendulim_exp_demoDemo_T *)
        pendulim_exp_demoDemo_M->ModelData.derivs)->Integrator_CSTATE_p = 0.0;
    }
  }
}

/* Model initialize function */
void pendulim_exp_demoDemo_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
  pendulim_exp_demoDemo_DW.clockTickCounter = 0;

  /* Start for Constant: '<S2>/LimitFlagSource' */
  pendulim_exp_demoDemo_B.LimitFlagSource[0] =
    pendulim_exp_demoDemo_P.LimitFlagSource_Value[0];
  pendulim_exp_demoDemo_B.LimitFlagSource[1] =
    pendulim_exp_demoDemo_P.LimitFlagSource_Value[1];
  pendulim_exp_demoDemo_B.LimitFlagSource[2] =
    pendulim_exp_demoDemo_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S2>/LimitSource' */
  pendulim_exp_demoDemo_B.LimitSource[0] =
    pendulim_exp_demoDemo_P.LimitSource_Value[0];
  pendulim_exp_demoDemo_B.LimitSource[1] =
    pendulim_exp_demoDemo_P.LimitSource_Value[1];
  pendulim_exp_demoDemo_B.LimitSource[2] =
    pendulim_exp_demoDemo_P.LimitSource_Value[2];

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  pendulim_exp_demoDemo_B.PWMPrescalerSource =
    pendulim_exp_demoDemo_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S2>/ResetSwitchFlagSource' */
  pendulim_exp_demoDemo_B.ResetSwitchFlagSource[0] =
    pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[0];
  pendulim_exp_demoDemo_B.ResetSwitchFlagSource[1] =
    pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[1];
  pendulim_exp_demoDemo_B.ResetSwitchFlagSource[2] =
    pendulim_exp_demoDemo_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  pendulim_exp_demoDemo_B.ThermFlagSource[0] =
    pendulim_exp_demoDemo_P.ThermFlagSource_Value[0];
  pendulim_exp_demoDemo_B.ThermFlagSource[1] =
    pendulim_exp_demoDemo_P.ThermFlagSource_Value[1];
  pendulim_exp_demoDemo_B.ThermFlagSource[2] =
    pendulim_exp_demoDemo_P.ThermFlagSource_Value[2];
  pendulim_exp_demoDemo_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  pendulim_exp_demoDemo_DW.Memory_PreviousInput =
    pendulim_exp_demoDemo_P.Memory_X0;

  /* InitializeConditions for Memory: '<S7>/Memory1' */
  pendulim_exp_demoDemo_DW.Memory1_PreviousInput =
    pendulim_exp_demoDemo_P.Memory1_X0;

  /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn' */
  pendulim_exp_demoDemo_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S12>/Integrator' */
  pendulim_exp_demoDemo_X.Integrator_CSTATE =
    pendulim_exp_demoDemo_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  pendulim_exp_demoDemo_X.Integrator_CSTATE_m =
    pendulim_exp_demoDemo_P.Integrator_IC_a;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  pendulim_exp_demoDemo_DW.Memory_PreviousInput_a =
    pendulim_exp_demoDemo_P.Memory_X0_p;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  pendulim_exp_demoDemo_X.Integrator_CSTATE_p =
    pendulim_exp_demoDemo_P.Integrator_IC_h;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  pendulim_exp_demoDemo_DW.Memory_PreviousInput_o =
    pendulim_exp_demoDemo_P.Memory_X0_m;
}

/* Model terminate function */
void pendulim_exp_demoDemo_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[8];
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
  pendulim_exp_demoDemo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pendulim_exp_demoDemo_update();
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
  pendulim_exp_demoDemo_initialize();
}

void MdlTerminate(void)
{
  pendulim_exp_demoDemo_terminate();
}

/* Registration function */
RT_MODEL_pendulim_exp_demoDemo_T *pendulim_exp_demoDemo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pendulim_exp_demoDemo_M, 0,
                sizeof(RT_MODEL_pendulim_exp_demoDemo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pendulim_exp_demoDemo_M->solverInfo,
                          &pendulim_exp_demoDemo_M->Timing.simTimeStep);
    rtsiSetTPtr(&pendulim_exp_demoDemo_M->solverInfo, &rtmGetTPtr
                (pendulim_exp_demoDemo_M));
    rtsiSetStepSizePtr(&pendulim_exp_demoDemo_M->solverInfo,
                       &pendulim_exp_demoDemo_M->Timing.stepSize0);
    rtsiSetdXPtr(&pendulim_exp_demoDemo_M->solverInfo,
                 &pendulim_exp_demoDemo_M->ModelData.derivs);
    rtsiSetContStatesPtr(&pendulim_exp_demoDemo_M->solverInfo, (real_T **)
                         &pendulim_exp_demoDemo_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&pendulim_exp_demoDemo_M->solverInfo,
      &pendulim_exp_demoDemo_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&pendulim_exp_demoDemo_M->solverInfo,
                          (&rtmGetErrorStatus(pendulim_exp_demoDemo_M)));
    rtsiSetRTModelPtr(&pendulim_exp_demoDemo_M->solverInfo,
                      pendulim_exp_demoDemo_M);
  }

  rtsiSetSimTimeStep(&pendulim_exp_demoDemo_M->solverInfo, MAJOR_TIME_STEP);
  pendulim_exp_demoDemo_M->ModelData.intgData.y =
    pendulim_exp_demoDemo_M->ModelData.odeY;
  pendulim_exp_demoDemo_M->ModelData.intgData.f[0] =
    pendulim_exp_demoDemo_M->ModelData.odeF[0];
  pendulim_exp_demoDemo_M->ModelData.intgData.f[1] =
    pendulim_exp_demoDemo_M->ModelData.odeF[1];
  pendulim_exp_demoDemo_M->ModelData.intgData.f[2] =
    pendulim_exp_demoDemo_M->ModelData.odeF[2];
  pendulim_exp_demoDemo_M->ModelData.intgData.f[3] =
    pendulim_exp_demoDemo_M->ModelData.odeF[3];
  pendulim_exp_demoDemo_M->ModelData.intgData.f[4] =
    pendulim_exp_demoDemo_M->ModelData.odeF[4];
  pendulim_exp_demoDemo_M->ModelData.intgData.f[5] =
    pendulim_exp_demoDemo_M->ModelData.odeF[5];
  pendulim_exp_demoDemo_M->ModelData.contStates = ((real_T *)
    &pendulim_exp_demoDemo_X);
  rtsiSetSolverData(&pendulim_exp_demoDemo_M->solverInfo, (void *)
                    &pendulim_exp_demoDemo_M->ModelData.intgData);
  rtsiSetSolverName(&pendulim_exp_demoDemo_M->solverInfo,"ode5");
  pendulim_exp_demoDemo_M->solverInfoPtr = (&pendulim_exp_demoDemo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pendulim_exp_demoDemo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    pendulim_exp_demoDemo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pendulim_exp_demoDemo_M->Timing.sampleTimes =
      (&pendulim_exp_demoDemo_M->Timing.sampleTimesArray[0]);
    pendulim_exp_demoDemo_M->Timing.offsetTimes =
      (&pendulim_exp_demoDemo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pendulim_exp_demoDemo_M->Timing.sampleTimes[0] = (0.0);
    pendulim_exp_demoDemo_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    pendulim_exp_demoDemo_M->Timing.offsetTimes[0] = (0.0);
    pendulim_exp_demoDemo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(pendulim_exp_demoDemo_M, &pendulim_exp_demoDemo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pendulim_exp_demoDemo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    pendulim_exp_demoDemo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pendulim_exp_demoDemo_M, 9999.0);
  pendulim_exp_demoDemo_M->Timing.stepSize0 = 0.01;
  pendulim_exp_demoDemo_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  pendulim_exp_demoDemo_M->Sizes.checksums[0] = (1021300407U);
  pendulim_exp_demoDemo_M->Sizes.checksums[1] = (2571267051U);
  pendulim_exp_demoDemo_M->Sizes.checksums[2] = (886309248U);
  pendulim_exp_demoDemo_M->Sizes.checksums[3] = (4057273003U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    pendulim_exp_demoDemo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pendulim_exp_demoDemo_M->extModeInfo,
      &pendulim_exp_demoDemo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pendulim_exp_demoDemo_M->extModeInfo,
                        pendulim_exp_demoDemo_M->Sizes.checksums);
    rteiSetTPtr(pendulim_exp_demoDemo_M->extModeInfo, rtmGetTPtr
                (pendulim_exp_demoDemo_M));
  }

  pendulim_exp_demoDemo_M->solverInfoPtr = (&pendulim_exp_demoDemo_M->solverInfo);
  pendulim_exp_demoDemo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&pendulim_exp_demoDemo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&pendulim_exp_demoDemo_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pendulim_exp_demoDemo_M->ModelData.blockIO = ((void *)
    &pendulim_exp_demoDemo_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      pendulim_exp_demoDemo_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      pendulim_exp_demoDemo_B.ResetEncoder[i] = 0.0;
    }

    pendulim_exp_demoDemo_B.Sum = 0.0;
    pendulim_exp_demoDemo_B.Cart_pos = 0.0;
    pendulim_exp_demoDemo_B.MatrixGain = 0.0;
    pendulim_exp_demoDemo_B.AngleScale = 0.0;
    pendulim_exp_demoDemo_B.PendPosOut = 0.0;
    pendulim_exp_demoDemo_B.Pend_vel = 0.0;
    pendulim_exp_demoDemo_B.Cart_vel = 0.0;
    pendulim_exp_demoDemo_B.Sum_k[0] = 0.0;
    pendulim_exp_demoDemo_B.Sum_k[1] = 0.0;
    pendulim_exp_demoDemo_B.Sum_k[2] = 0.0;
    pendulim_exp_demoDemo_B.Sum_k[3] = 0.0;
    pendulim_exp_demoDemo_B.umax = 0.0;
    pendulim_exp_demoDemo_B.Fcn = 0.0;
    pendulim_exp_demoDemo_B.CtrlMode = 0.0;
    pendulim_exp_demoDemo_B.Gain1 = 0.0;
    pendulim_exp_demoDemo_B.Memory = 0.0;
    pendulim_exp_demoDemo_B.Gain3 = 0.0;
    pendulim_exp_demoDemo_B.Memory_o = 0.0;
    pendulim_exp_demoDemo_B.Fcn_k = 0.0;
    pendulim_exp_demoDemo_B.CtrlSat = 0.0;
    pendulim_exp_demoDemo_B.PWM[0] = 0.0;
    pendulim_exp_demoDemo_B.PWM[1] = 0.0;
    pendulim_exp_demoDemo_B.PWM[2] = 0.0;
    pendulim_exp_demoDemo_B.Saturation[0] = 0.0;
    pendulim_exp_demoDemo_B.Saturation[1] = 0.0;
    pendulim_exp_demoDemo_B.Saturation[2] = 0.0;
    pendulim_exp_demoDemo_B.ResetSource[0] = 0.0;
    pendulim_exp_demoDemo_B.ResetSource[1] = 0.0;
    pendulim_exp_demoDemo_B.ResetSource[2] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlag[0] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlag[1] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlag[2] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlagSource[0] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlagSource[1] = 0.0;
    pendulim_exp_demoDemo_B.LimitFlagSource[2] = 0.0;
    pendulim_exp_demoDemo_B.LimitSource[0] = 0.0;
    pendulim_exp_demoDemo_B.LimitSource[1] = 0.0;
    pendulim_exp_demoDemo_B.LimitSource[2] = 0.0;
    pendulim_exp_demoDemo_B.SetLimit[0] = 0.0;
    pendulim_exp_demoDemo_B.SetLimit[1] = 0.0;
    pendulim_exp_demoDemo_B.SetLimit[2] = 0.0;
    pendulim_exp_demoDemo_B.LimitSwitch[0] = 0.0;
    pendulim_exp_demoDemo_B.LimitSwitch[1] = 0.0;
    pendulim_exp_demoDemo_B.LimitSwitch[2] = 0.0;
    pendulim_exp_demoDemo_B.PWMPrescaler = 0.0;
    pendulim_exp_demoDemo_B.PWMPrescalerSource = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlag[0] = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlag[1] = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlag[2] = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[0] = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[1] = 0.0;
    pendulim_exp_demoDemo_B.ResetSwitchFlagSource[2] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlag[0] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlag[1] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlag[2] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlagSource[0] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlagSource[1] = 0.0;
    pendulim_exp_demoDemo_B.ThermFlagSource[2] = 0.0;
    pendulim_exp_demoDemo_B.Fcn_kz = 0.0;
    pendulim_exp_demoDemo_B.IntegratorGain = 0.0;
    pendulim_exp_demoDemo_B.ResetEncoders = 0.0;
  }

  /* parameters */
  pendulim_exp_demoDemo_M->ModelData.defaultParam = ((real_T *)
    &pendulim_exp_demoDemo_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &pendulim_exp_demoDemo_X;
    pendulim_exp_demoDemo_M->ModelData.contStates = (x);
    (void) memset((void *)&pendulim_exp_demoDemo_X, 0,
                  sizeof(X_pendulim_exp_demoDemo_T));
  }

  /* states (dwork) */
  pendulim_exp_demoDemo_M->ModelData.dwork = ((void *) &pendulim_exp_demoDemo_DW);
  (void) memset((void *)&pendulim_exp_demoDemo_DW, 0,
                sizeof(DW_pendulim_exp_demoDemo_T));
  pendulim_exp_demoDemo_DW.Memory_PreviousInput = 0.0;
  pendulim_exp_demoDemo_DW.Memory1_PreviousInput = 0.0;
  pendulim_exp_demoDemo_DW.Memory_PreviousInput_a = 0.0;
  pendulim_exp_demoDemo_DW.Memory_PreviousInput_o = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pendulim_exp_demoDemo_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &pendulim_exp_demoDemo_M->NonInlinedSFcns.sfcnInfo;
    pendulim_exp_demoDemo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(pendulim_exp_demoDemo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &pendulim_exp_demoDemo_M->Sizes.numSampTimes);
    pendulim_exp_demoDemo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (pendulim_exp_demoDemo_M)[0]);
    pendulim_exp_demoDemo_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (pendulim_exp_demoDemo_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   pendulim_exp_demoDemo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(pendulim_exp_demoDemo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(pendulim_exp_demoDemo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (pendulim_exp_demoDemo_M));
    rtssSetStepSizePtr(sfcnInfo, &pendulim_exp_demoDemo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (pendulim_exp_demoDemo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &pendulim_exp_demoDemo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &pendulim_exp_demoDemo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &pendulim_exp_demoDemo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &pendulim_exp_demoDemo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &pendulim_exp_demoDemo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &pendulim_exp_demoDemo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &pendulim_exp_demoDemo_M->solverInfoPtr);
  }

  pendulim_exp_demoDemo_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)
                  &pendulim_exp_demoDemo_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    pendulim_exp_demoDemo_M->childSfunctions =
      (&pendulim_exp_demoDemo_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        pendulim_exp_demoDemo_M->childSfunctions[i] =
          (&pendulim_exp_demoDemo_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulim_exp_demoDemo_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulim_exp_demoDemo_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/PWM (P1_PWM) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = pendulim_exp_demoDemo_B.Saturation;
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.Saturation[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulim_exp_demoDemo_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulim_exp_demoDemo_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulim_exp_demoDemo_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &pendulim_exp_demoDemo_B.ResetSource[0];
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.ResetSource[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.ResetSource[2];
          sfcnUPtrs[3] = &pendulim_exp_demoDemo_B.ResetEncoders;
          sfcnUPtrs[4] = &pendulim_exp_demoDemo_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = pendulim_exp_demoDemo_B.LimitFlagSource;
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = pendulim_exp_demoDemo_B.LimitSource;
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.LimitSource[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &pendulim_exp_demoDemo_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &pendulim_exp_demoDemo_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = pendulim_exp_demoDemo_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts,
                "pendulim_exp_demoDemo/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: pendulim_exp_demoDemo/<S2>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = pendulim_exp_demoDemo_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulim_exp_demoDemo_M->
                         NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, pendulim_exp_demoDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &pendulim_exp_demoDemo_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pendulim_exp_demoDemo_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = pendulim_exp_demoDemo_B.ThermFlagSource;
          sfcnUPtrs[1] = &pendulim_exp_demoDemo_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &pendulim_exp_demoDemo_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulim_exp_demoDemo_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "pendulim_exp_demoDemo/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,pendulim_exp_demoDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulim_exp_demoDemo_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulim_exp_demoDemo_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulim_exp_demoDemo_P.ThermFlag_P2_Size);
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
  pendulim_exp_demoDemo_M->Sizes.numContStates = (4);/* Number of continuous states */
  pendulim_exp_demoDemo_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  pendulim_exp_demoDemo_M->Sizes.numY = (0);/* Number of model outputs */
  pendulim_exp_demoDemo_M->Sizes.numU = (0);/* Number of model inputs */
  pendulim_exp_demoDemo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pendulim_exp_demoDemo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  pendulim_exp_demoDemo_M->Sizes.numBlocks = (126);/* Number of blocks */
  pendulim_exp_demoDemo_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  pendulim_exp_demoDemo_M->Sizes.numBlockPrms = (157);/* Sum of parameter "widths" */
  return pendulim_exp_demoDemo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
