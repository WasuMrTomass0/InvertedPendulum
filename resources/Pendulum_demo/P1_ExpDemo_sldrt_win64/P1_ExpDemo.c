/*
 * P1_ExpDemo.c
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

#include "P1_ExpDemo.h"
#include "P1_ExpDemo_private.h"
#include "P1_ExpDemo_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_P1_ExpDemo_T P1_ExpDemo_B;

/* Continuous states */
X_P1_ExpDemo_T P1_ExpDemo_X;

/* Block states (auto storage) */
DW_P1_ExpDemo_T P1_ExpDemo_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_P1_ExpDemo_T P1_ExpDemo_PrevZCX;

/* Real-time model */
RT_MODEL_P1_ExpDemo_T P1_ExpDemo_M_;
RT_MODEL_P1_ExpDemo_T *const P1_ExpDemo_M = &P1_ExpDemo_M_;

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
  P1_ExpDemo_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  P1_ExpDemo_output();
  P1_ExpDemo_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  P1_ExpDemo_output();
  P1_ExpDemo_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  P1_ExpDemo_output();
  P1_ExpDemo_derivatives();

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
  P1_ExpDemo_output();
  P1_ExpDemo_derivatives();

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
  P1_ExpDemo_output();
  P1_ExpDemo_derivatives();

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
void P1_ExpDemo_output(void)
{
  /* local block i/o variables */
  real_T rtb_Sum_l;
  real_T rtb_Encoder1024PPR[5];
  real_T rtb_SineGain;
  real_T rtb_SquareGain;
  real_T rtb_Gain1;
  real_T rtb_Gain2;
  real_T rtb_Gain3;
  real_T rtb_Gain4;
  real_T rtb_s2;
  int32_T i;
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* set solver stop time */
    if (!(P1_ExpDemo_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&P1_ExpDemo_M->solverInfo,
                            ((P1_ExpDemo_M->Timing.clockTickH0 + 1) *
        P1_ExpDemo_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&P1_ExpDemo_M->solverInfo,
                            ((P1_ExpDemo_M->Timing.clockTick0 + 1) *
        P1_ExpDemo_M->Timing.stepSize0 + P1_ExpDemo_M->Timing.clockTickH0 *
        P1_ExpDemo_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(P1_ExpDemo_M)) {
    P1_ExpDemo_M->Timing.t[0] = rtsiGetT(&P1_ExpDemo_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S2>/Encoder 1024 PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder1024PPR[i] = P1_ExpDemo_P.Encoder1024PPR_Gain *
        P1_ExpDemo_B.Encoder[i];
    }

    /* End of Gain: '<S2>/Encoder 1024 PPR' */

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<S2>/Cart Offset'
     *  Gain: '<S2>/PosCart Scale'
     */
    P1_ExpDemo_B.Sum = P1_ExpDemo_P.PosCartScale_Gain * rtb_Encoder1024PPR[4] +
      P1_ExpDemo_P.CartOffset_Value;

    /* Gain: '<S7>/Gain3' */
    P1_ExpDemo_B.Cart_pos = P1_ExpDemo_P.Gain3_Gain * P1_ExpDemo_B.Sum;
  }

  /* SignalGenerator: '<S6>/sine' */
  rtb_Sum_l = sin(6.2831853071795862 * P1_ExpDemo_M->Timing.t[0] *
                  P1_ExpDemo_P.RefCartPos_Frequency) *
    P1_ExpDemo_P.RefCartPos_Amplitude;

  /* Gain: '<S6>/SineGain' */
  rtb_SineGain = P1_ExpDemo_P.RefCartPos_Sine * rtb_Sum_l;

  /* SignalGenerator: '<S6>/square' */
  rtb_Gain1 = P1_ExpDemo_P.RefCartPos_Frequency * P1_ExpDemo_M->Timing.t[0];
  if (rtb_Gain1 - floor(rtb_Gain1) >= 0.5) {
    rtb_Sum_l = P1_ExpDemo_P.RefCartPos_Amplitude;
  } else {
    rtb_Sum_l = -P1_ExpDemo_P.RefCartPos_Amplitude;
  }

  /* End of SignalGenerator: '<S6>/square' */

  /* Gain: '<S6>/SquareGain' */
  rtb_SquareGain = P1_ExpDemo_P.RefCartPos_Square * rtb_Sum_l;

  /* SignalGenerator: '<S6>/sawtooth' */
  rtb_Gain1 = P1_ExpDemo_P.RefCartPos_Frequency * P1_ExpDemo_M->Timing.t[0];
  rtb_Sum_l = (1.0 - (rtb_Gain1 - floor(rtb_Gain1)) * 2.0) *
    P1_ExpDemo_P.RefCartPos_Amplitude;

  /* Sum: '<S6>/Sum' incorporates:
   *  Gain: '<S6>/SawToothGain'
   */
  rtb_Sum_l = (rtb_SineGain + rtb_SquareGain) + P1_ExpDemo_P.RefCartPos_Sawtooth
    * rtb_Sum_l;

  /* Gain: '<Root>/Matrix Gain' incorporates:
   *  Constant: '<S6>/Const1'
   *  Constant: '<S6>/Const2'
   *  Constant: '<S6>/Const3'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtMatrix GainInport1'
   */
  P1_ExpDemo_B.MatrixGain = ((P1_ExpDemo_P.MatrixGain_Gain[0] *
    P1_ExpDemo_P.Const1_Value + P1_ExpDemo_P.MatrixGain_Gain[1] *
    P1_ExpDemo_P.Const2_Value) + P1_ExpDemo_P.MatrixGain_Gain[2] * rtb_Sum_l) +
    P1_ExpDemo_P.MatrixGain_Gain[3] * P1_ExpDemo_P.Const3_Value;
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Gain: '<S2>/Angle Scale' */
    P1_ExpDemo_B.AngleScale = P1_ExpDemo_P.AngleScale_Gain * rtb_Encoder1024PPR
      [3];

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/pi'
     *  Constant: '<S1>/pos'
     *  Gain: '<S7>/Gain1'
     *  Product: '<S1>/Product'
     */
    rtb_SineGain = P1_ExpDemo_P.pi_Value * P1_ExpDemo_P.AlfaNormalization_pos +
      P1_ExpDemo_P.Gain1_Gain * P1_ExpDemo_B.AngleScale;

    /* Fcn: '<S1>/angle normalization' */
    P1_ExpDemo_B.PendPosOut = rt_atan2d_snf(sin(rtb_SineGain), cos(rtb_SineGain));

    /* Gain: '<S7>/Gain2' incorporates:
     *  Memory: '<S7>/Memory'
     *  Sum: '<S7>/Sum'
     */
    P1_ExpDemo_B.Pend_vel = 1.0 / P1_ExpDemo_P.Sensors_T0 *
      (P1_ExpDemo_B.AngleScale - P1_ExpDemo_DW.Memory_PreviousInput);

    /* Gain: '<S7>/Gain4' incorporates:
     *  Memory: '<S7>/Memory1'
     *  Sum: '<S7>/Sum1'
     */
    P1_ExpDemo_B.Cart_vel = 1.0 / P1_ExpDemo_P.Sensors_T0 * (P1_ExpDemo_B.Sum -
      P1_ExpDemo_DW.Memory1_PreviousInput);
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S6>/Const1'
   *  Constant: '<S6>/Const2'
   *  Constant: '<S6>/Const3'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtMatrix GainInport1'
   */
  P1_ExpDemo_B.Sum_k[0] = P1_ExpDemo_P.Const1_Value - P1_ExpDemo_B.PendPosOut;
  P1_ExpDemo_B.Sum_k[1] = P1_ExpDemo_P.Const2_Value - P1_ExpDemo_B.Pend_vel;
  P1_ExpDemo_B.Sum_k[2] = rtb_Sum_l - P1_ExpDemo_B.Cart_pos;
  P1_ExpDemo_B.Sum_k[3] = P1_ExpDemo_P.Const3_Value - P1_ExpDemo_B.Cart_vel;

  /* Fcn: '<S13>/Fcn' */
  rtb_Sum_l = -P1_ExpDemo_B.Sum_k[2];

  /* Signum: '<S13>/Sign' */
  if (rtb_Sum_l < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_Sum_l > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_Sum_l == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_Sum_l;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  Signum: '<S13>/Sign'
   */
  rtb_SineGain = P1_ExpDemo_P.Nottoescapewatchdog_umax2 * rtb_Gain3;

  /* Fcn: '<S4>/limiter' */
  rtb_SquareGain = fabs(P1_ExpDemo_B.Sum_k[2]) - 0.5;

  /* Sum: '<S14>/s2' incorporates:
   *  Constant: '<S14>/one '
   *  Fcn: '<S14>/Kinetic Energy'
   *  Fcn: '<S14>/Potential Energy'
   *  Gain: '<S14>/Gain'
   *  Sum: '<S14>/s3'
   */
  rtb_s2 = 9.81 * P1_ExpDemo_P.Softlandingarbiter_k *
    P1_ExpDemo_P.Softlandingarbiter_R * (cos(P1_ExpDemo_B.Sum_k[0]) -
    P1_ExpDemo_P.one_Value) + P1_ExpDemo_B.Sum_k[1] * P1_ExpDemo_B.Sum_k[1] *
    0.5;

  /* Fcn: '<S15>/abs(x1)' */
  rtb_Sum_l = (fabs(P1_ExpDemo_B.Sum_k[0]) - 1.5707963267948966) *
    P1_ExpDemo_B.Sum_k[1];

  /* Relay: '<S15>/swing' */
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    if (rtb_Sum_l >= P1_ExpDemo_P.swing_OnVal) {
      P1_ExpDemo_DW.swing_Mode = true;
    } else {
      if (rtb_Sum_l <= P1_ExpDemo_P.swing_OffVal) {
        P1_ExpDemo_DW.swing_Mode = false;
      }
    }
  }

  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Relay: '<S15>/swing' */
    if (P1_ExpDemo_DW.swing_Mode) {
      rtb_Gain3 = P1_ExpDemo_P.swing_YOn;
    } else {
      rtb_Gain3 = P1_ExpDemo_P.swing_YOff;
    }

    /* Gain: '<S15>/umax' */
    P1_ExpDemo_B.umax = P1_ExpDemo_P.Swingingcontroller_umax * rtb_Gain3;
  }

  /* Gain: '<S12>/Gain1' */
  rtb_Gain1 = P1_ExpDemo_P.Gain1_Gain_f * P1_ExpDemo_B.Sum_k[0];

  /* TransferFcn: '<S12>/Transfer Fcn' */
  rtb_Sum_l = 0.0;
  rtb_Sum_l += P1_ExpDemo_P.TransferFcn_C * P1_ExpDemo_X.TransferFcn_CSTATE;

  /* Gain: '<S12>/Gain2' */
  rtb_Gain2 = P1_ExpDemo_P.Gain2_Gain * rtb_Sum_l;

  /* Saturate: '<S12>/Saturation Cart Error' */
  if (P1_ExpDemo_B.Sum_k[2] > P1_ExpDemo_P.SaturationCartError_UpperSat) {
    rtb_Gain3 = P1_ExpDemo_P.SaturationCartError_UpperSat;
  } else if (P1_ExpDemo_B.Sum_k[2] < P1_ExpDemo_P.SaturationCartError_LowerSat)
  {
    rtb_Gain3 = P1_ExpDemo_P.SaturationCartError_LowerSat;
  } else {
    rtb_Gain3 = P1_ExpDemo_B.Sum_k[2];
  }

  /* Gain: '<S12>/Gain3' incorporates:
   *  Saturate: '<S12>/Saturation Cart Error'
   */
  rtb_Gain3 *= P1_ExpDemo_P.Gain3_Gain_e;

  /* Gain: '<S12>/Gain4' */
  rtb_Gain4 = P1_ExpDemo_P.Gain4_Gain * P1_ExpDemo_B.Sum_k[3];

  /* Fcn: '<S12>/Fcn' */
  P1_ExpDemo_B.Fcn = (fabs(P1_ExpDemo_B.Sum_k[0]) < 0.1);

  /* Integrator: '<S12>/Integrator'
   *
   * Regarding '<S12>/Integrator':
   *  Limited Integrator
   */
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &P1_ExpDemo_PrevZCX.Integrator_Reset_ZCE,
                       P1_ExpDemo_B.Fcn);

    /* evaluate zero-crossings */
    if (zcEvent) {
      P1_ExpDemo_X.Integrator_CSTATE = P1_ExpDemo_P.Integrator_IC;
    }
  }

  if (P1_ExpDemo_X.Integrator_CSTATE >= P1_ExpDemo_P.Integrator_UpperSat ) {
    P1_ExpDemo_X.Integrator_CSTATE = P1_ExpDemo_P.Integrator_UpperSat;
  } else if (P1_ExpDemo_X.Integrator_CSTATE <= (P1_ExpDemo_P.Integrator_LowerSat)
             ) {
    P1_ExpDemo_X.Integrator_CSTATE = (P1_ExpDemo_P.Integrator_LowerSat);
  }

  rtb_Sum_l = P1_ExpDemo_X.Integrator_CSTATE;

  /* Sum: '<S12>/Sum' */
  rtb_Sum_l += ((rtb_Gain1 + rtb_Gain2) + rtb_Gain3) + rtb_Gain4;

  /* Switch: '<S4>/4' incorporates:
   *  Fcn: '<S4>/Upper zone arbiter'
   *  Saturate: '<S12>/Saturation'
   *  Switch: '<S4>/2'
   */
  if (rtb_SquareGain >= P1_ExpDemo_P._Threshold_b) {
    rtb_Sum_l = rtb_SineGain;
  } else if (fabs(P1_ExpDemo_B.Sum_k[0]) - 0.2 >= P1_ExpDemo_P._Threshold_p) {
    /* Switch: '<S4>/3' incorporates:
     *  Constant: '<S4>/Control = 0'
     *  Switch: '<S4>/2'
     */
    if (rtb_s2 >= P1_ExpDemo_P._Threshold) {
      rtb_Sum_l = P1_ExpDemo_P.Control0_Value;
    } else {
      rtb_Sum_l = P1_ExpDemo_B.umax;
    }

    /* End of Switch: '<S4>/3' */
  } else if (rtb_Sum_l > P1_ExpDemo_P.Linearcontroller1_umax1) {
    /* Saturate: '<S12>/Saturation' incorporates:
     *  Switch: '<S4>/2'
     */
    rtb_Sum_l = P1_ExpDemo_P.Linearcontroller1_umax1;
  } else {
    if (rtb_Sum_l < -P1_ExpDemo_P.Linearcontroller1_umax1) {
      /* Saturate: '<S12>/Saturation' incorporates:
       *  Switch: '<S4>/2'
       */
      rtb_Sum_l = -P1_ExpDemo_P.Linearcontroller1_umax1;
    }
  }

  /* End of Switch: '<S4>/4' */

  /* Signum: '<S11>/Sign' */
  if (rtb_Sum_l < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_Sum_l > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_Sum_l == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_Sum_l;
  }

  /* Gain: '<S11>/Gain1' incorporates:
   *  Signum: '<S11>/Sign'
   */
  rtb_SineGain = P1_ExpDemo_P.CoulombViscousFriction_offset * rtb_Gain3;

  /* Gain: '<S11>/Gain' */
  rtb_SquareGain = P1_ExpDemo_P.CoulombViscousFriction_gain * rtb_Sum_l;
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
    P1_ExpDemo_B.CtrlMode = (P1_ExpDemo_DW.clockTickCounter <
      P1_ExpDemo_P.AlgorithmSelector2_Duty) && (P1_ExpDemo_DW.clockTickCounter >=
      0) ? P1_ExpDemo_P.AlgorithmSelector2_Amp : 0.0;
    if (P1_ExpDemo_DW.clockTickCounter >= P1_ExpDemo_P.AlgorithmSelector2_Period
        - 1.0) {
      P1_ExpDemo_DW.clockTickCounter = 0;
    } else {
      P1_ExpDemo_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Fcn: '<S3>/angle normalization'
   */
  P1_ExpDemo_B.Gain1 = rt_atan2d_snf(sin(P1_ExpDemo_B.Sum_k[0] +
    3.1415926535897931), cos(P1_ExpDemo_B.Sum_k[0] + 3.1415926535897931)) *
    P1_ExpDemo_P.Gain1_Gain_g;

  /* Gain: '<S10>/Kp' */
  rtb_Gain1 = P1_ExpDemo_P.PIDPend_P * P1_ExpDemo_B.Gain1;

  /* Integrator: '<S10>/Integrator'
   *
   * Regarding '<S10>/Integrator':
   *  Limited Integrator
   */
  if (P1_ExpDemo_X.Integrator_CSTATE_m >= P1_ExpDemo_P.Integrator_UpperSat_l ) {
    P1_ExpDemo_X.Integrator_CSTATE_m = P1_ExpDemo_P.Integrator_UpperSat_l;
  } else if (P1_ExpDemo_X.Integrator_CSTATE_m <=
             (P1_ExpDemo_P.Integrator_LowerSat_k) ) {
    P1_ExpDemo_X.Integrator_CSTATE_m = (P1_ExpDemo_P.Integrator_LowerSat_k);
  }

  rtb_Sum_l = P1_ExpDemo_X.Integrator_CSTATE_m;

  /* Gain: '<S10>/Ki' */
  rtb_Gain2 = P1_ExpDemo_P.PIDPend_I * rtb_Sum_l;
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Memory: '<S10>/Memory' */
    P1_ExpDemo_B.Memory = P1_ExpDemo_DW.Memory_PreviousInput_a;
  }

  /* Gain: '<S10>/Kd1' incorporates:
   *  Sum: '<S10>/Sum1'
   */
  rtb_Gain3 = P1_ExpDemo_P.PIDPend_D / P1_ExpDemo_P.ControllerPID_T0 *
    (P1_ExpDemo_B.Gain1 - P1_ExpDemo_B.Memory);

  /* Gain: '<S3>/Gain3' */
  P1_ExpDemo_B.Gain3 = P1_ExpDemo_P.Gain3_Gain_b * P1_ExpDemo_B.Sum_k[2];

  /* Gain: '<S9>/Kp' */
  rtb_Gain4 = P1_ExpDemo_P.PIDCart_P * P1_ExpDemo_B.Gain3;

  /* Integrator: '<S9>/Integrator'
   *
   * Regarding '<S9>/Integrator':
   *  Limited Integrator
   */
  if (P1_ExpDemo_X.Integrator_CSTATE_p >= P1_ExpDemo_P.Integrator_UpperSat_b ) {
    P1_ExpDemo_X.Integrator_CSTATE_p = P1_ExpDemo_P.Integrator_UpperSat_b;
  } else if (P1_ExpDemo_X.Integrator_CSTATE_p <=
             (P1_ExpDemo_P.Integrator_LowerSat_kg) ) {
    P1_ExpDemo_X.Integrator_CSTATE_p = (P1_ExpDemo_P.Integrator_LowerSat_kg);
  }

  rtb_Sum_l = P1_ExpDemo_X.Integrator_CSTATE_p;
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Memory: '<S9>/Memory' */
    P1_ExpDemo_B.Memory_o = P1_ExpDemo_DW.Memory_PreviousInput_o;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Gain: '<S9>/Kd1'
   *  Gain: '<S9>/Ki'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  rtb_Sum_l = ((P1_ExpDemo_P.PIDCart_I * rtb_Sum_l + rtb_Gain4) +
               P1_ExpDemo_P.PIDCart_D / P1_ExpDemo_P.ControllerPID_T0 *
               (P1_ExpDemo_B.Gain3 - P1_ExpDemo_B.Memory_o)) + ((rtb_Gain1 +
    rtb_Gain2) + rtb_Gain3);

  /* Signum: '<S8>/Sign' */
  if (rtb_Sum_l < 0.0) {
    rtb_Gain3 = -1.0;
  } else if (rtb_Sum_l > 0.0) {
    rtb_Gain3 = 1.0;
  } else if (rtb_Sum_l == 0.0) {
    rtb_Gain3 = 0.0;
  } else {
    rtb_Gain3 = rtb_Sum_l;
  }

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Gain'
   *  Gain: '<S8>/Gain1'
   *  Signum: '<S8>/Sign'
   */
  rtb_Sum_l = P1_ExpDemo_P.ControllerPID_Friction * rtb_Gain3 +
    P1_ExpDemo_P.CoulombViscousFriction_gain_h * rtb_Sum_l;

  /* Switch: '<Root>/Switch' incorporates:
   *  Fcn: '<S3>/Fcn'
   *  Product: '<S3>/Product1'
   *  Saturate: '<S3>/CtrlSat1'
   */
  if (P1_ExpDemo_B.CtrlMode >= P1_ExpDemo_P.Switch_Threshold) {
    /* Sum: '<S11>/Sum' */
    rtb_Gain3 = rtb_SineGain + rtb_SquareGain;

    /* Saturate: '<S4>/CtrlSat' */
    if (rtb_Gain3 > P1_ExpDemo_P.CtrlSat_UpperSat) {
      rtb_Sum_l = P1_ExpDemo_P.CtrlSat_UpperSat;
    } else if (rtb_Gain3 < P1_ExpDemo_P.CtrlSat_LowerSat) {
      rtb_Sum_l = P1_ExpDemo_P.CtrlSat_LowerSat;
    } else {
      rtb_Sum_l = rtb_Gain3;
    }

    /* End of Saturate: '<S4>/CtrlSat' */
  } else {
    if (rtb_Sum_l > P1_ExpDemo_P.ControllerPID_Umax) {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = P1_ExpDemo_P.ControllerPID_Umax;
    } else if (rtb_Sum_l < -P1_ExpDemo_P.ControllerPID_Umax) {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = -P1_ExpDemo_P.ControllerPID_Umax;
    } else {
      /* Saturate: '<S3>/CtrlSat1' */
      rtb_Gain3 = rtb_Sum_l;
    }

    rtb_Sum_l = (real_T)(fabs(P1_ExpDemo_B.Gain1) < 1.3) * rtb_Gain3;
  }

  /* End of Switch: '<Root>/Switch' */
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Fcn: '<S5>/Fcn' */
    P1_ExpDemo_B.Fcn_k = rt_powd_snf((P1_ExpDemo_B.Cart_pos - 0.8) * 10.0, 3.0) *
      (real_T)(P1_ExpDemo_B.Cart_pos >= 0.8) + rt_powd_snf
      ((P1_ExpDemo_B.Cart_pos + 0.8) * 10.0, 3.0) * (real_T)
      (P1_ExpDemo_B.Cart_pos <= -0.8);
  }

  /* Sum: '<S5>/Sum' */
  rtb_Sum_l += P1_ExpDemo_B.Fcn_k;

  /* Saturate: '<S5>/CtrlSat' */
  if (rtb_Sum_l > P1_ExpDemo_P.CtrlSat_UpperSat_o) {
    P1_ExpDemo_B.CtrlSat = P1_ExpDemo_P.CtrlSat_UpperSat_o;
  } else if (rtb_Sum_l < P1_ExpDemo_P.CtrlSat_LowerSat_l) {
    P1_ExpDemo_B.CtrlSat = P1_ExpDemo_P.CtrlSat_LowerSat_l;
  } else {
    P1_ExpDemo_B.CtrlSat = rtb_Sum_l;
  }

  /* End of Saturate: '<S5>/CtrlSat' */
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }
  }

  /* Saturate: '<S2>/Saturation' */
  if (0.0 > P1_ExpDemo_P.Saturation_UpperSat) {
    P1_ExpDemo_B.Saturation[0] = P1_ExpDemo_P.Saturation_UpperSat;
  } else if (0.0 < P1_ExpDemo_P.Saturation_LowerSat) {
    P1_ExpDemo_B.Saturation[0] = P1_ExpDemo_P.Saturation_LowerSat;
  } else {
    P1_ExpDemo_B.Saturation[0] = 0.0;
  }

  if (P1_ExpDemo_B.CtrlSat > P1_ExpDemo_P.Saturation_UpperSat) {
    P1_ExpDemo_B.Saturation[1] = P1_ExpDemo_P.Saturation_UpperSat;
  } else if (P1_ExpDemo_B.CtrlSat < P1_ExpDemo_P.Saturation_LowerSat) {
    P1_ExpDemo_B.Saturation[1] = P1_ExpDemo_P.Saturation_LowerSat;
  } else {
    P1_ExpDemo_B.Saturation[1] = P1_ExpDemo_B.CtrlSat;
  }

  if (0.0 > P1_ExpDemo_P.Saturation_UpperSat) {
    P1_ExpDemo_B.Saturation[2] = P1_ExpDemo_P.Saturation_UpperSat;
  } else if (0.0 < P1_ExpDemo_P.Saturation_LowerSat) {
    P1_ExpDemo_B.Saturation[2] = P1_ExpDemo_P.Saturation_LowerSat;
  } else {
    P1_ExpDemo_B.Saturation[2] = 0.0;
  }

  /* End of Saturate: '<S2>/Saturation' */
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSource' */
    P1_ExpDemo_B.ResetSource[0] = P1_ExpDemo_P.ResetSource_Value[0];
    P1_ExpDemo_B.ResetSource[1] = P1_ExpDemo_P.ResetSource_Value[1];
    P1_ExpDemo_B.ResetSource[2] = P1_ExpDemo_P.ResetSource_Value[2];

    /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/LimitFlagSource' */
    P1_ExpDemo_B.LimitFlagSource[0] = P1_ExpDemo_P.LimitFlagSource_Value[0];
    P1_ExpDemo_B.LimitFlagSource[1] = P1_ExpDemo_P.LimitFlagSource_Value[1];
    P1_ExpDemo_B.LimitFlagSource[2] = P1_ExpDemo_P.LimitFlagSource_Value[2];

    /* Constant: '<S2>/LimitSource' */
    P1_ExpDemo_B.LimitSource[0] = P1_ExpDemo_P.LimitSource_Value[0];
    P1_ExpDemo_B.LimitSource[1] = P1_ExpDemo_P.LimitSource_Value[1];
    P1_ExpDemo_B.LimitSource[2] = P1_ExpDemo_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/PWMPrescalerSource' */
    P1_ExpDemo_B.PWMPrescalerSource = P1_ExpDemo_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ResetSwitchFlagSource' */
    P1_ExpDemo_B.ResetSwitchFlagSource[0] =
      P1_ExpDemo_P.ResetSwitchFlagSource_Value[0];
    P1_ExpDemo_B.ResetSwitchFlagSource[1] =
      P1_ExpDemo_P.ResetSwitchFlagSource_Value[1];
    P1_ExpDemo_B.ResetSwitchFlagSource[2] =
      P1_ExpDemo_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S2>/ThermFlagSource' */
    P1_ExpDemo_B.ThermFlagSource[0] = P1_ExpDemo_P.ThermFlagSource_Value[0];
    P1_ExpDemo_B.ThermFlagSource[1] = P1_ExpDemo_P.ThermFlagSource_Value[1];
    P1_ExpDemo_B.ThermFlagSource[2] = P1_ExpDemo_P.ThermFlagSource_Value[2];
  }

  /* Fcn: '<S4>/Fcn' */
  P1_ExpDemo_B.Fcn_kz = (rtb_s2 > 0.0);
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
  }

  /* Gain: '<S12>/Integrator Gain' */
  P1_ExpDemo_B.IntegratorGain = P1_ExpDemo_P.IntegratorGain_Gain *
    P1_ExpDemo_B.Sum_k[2];
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Normal'
     *  Constant: '<Root>/Reset'
     */
    if (P1_ExpDemo_P.ResetEncoders_CurrentSetting == 1) {
      P1_ExpDemo_B.ResetEncoders = P1_ExpDemo_P.Reset_Value;
    } else {
      P1_ExpDemo_B.ResetEncoders = P1_ExpDemo_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */
  }
}

/* Model update function */
void P1_ExpDemo_update(void)
{
  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Update for Memory: '<S7>/Memory' */
    P1_ExpDemo_DW.Memory_PreviousInput = P1_ExpDemo_B.AngleScale;

    /* Update for Memory: '<S7>/Memory1' */
    P1_ExpDemo_DW.Memory1_PreviousInput = P1_ExpDemo_B.Sum;
  }

  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Update for Memory: '<S10>/Memory' */
    P1_ExpDemo_DW.Memory_PreviousInput_a = P1_ExpDemo_B.Gain1;
  }

  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    /* Update for Memory: '<S9>/Memory' */
    P1_ExpDemo_DW.Memory_PreviousInput_o = P1_ExpDemo_B.Gain3;
  }

  if (rtmIsMajorTimeStep(P1_ExpDemo_M)) {
    rt_ertODEUpdateContinuousStates(&P1_ExpDemo_M->solverInfo);
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
  if (!(++P1_ExpDemo_M->Timing.clockTick0)) {
    ++P1_ExpDemo_M->Timing.clockTickH0;
  }

  P1_ExpDemo_M->Timing.t[0] = rtsiGetSolverStopTime(&P1_ExpDemo_M->solverInfo);

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
    if (!(++P1_ExpDemo_M->Timing.clockTick1)) {
      ++P1_ExpDemo_M->Timing.clockTickH1;
    }

    P1_ExpDemo_M->Timing.t[1] = P1_ExpDemo_M->Timing.clockTick1 *
      P1_ExpDemo_M->Timing.stepSize1 + P1_ExpDemo_M->Timing.clockTickH1 *
      P1_ExpDemo_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void P1_ExpDemo_derivatives(void)
{
  XDot_P1_ExpDemo_T *_rtXdot;
  _rtXdot = ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += P1_ExpDemo_P.TransferFcn_A *
    P1_ExpDemo_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += P1_ExpDemo_B.Sum_k[1];

  /* Derivatives for Integrator: '<S12>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( P1_ExpDemo_X.Integrator_CSTATE <= (P1_ExpDemo_P.Integrator_LowerSat)
            );
    usat = ( P1_ExpDemo_X.Integrator_CSTATE >= P1_ExpDemo_P.Integrator_UpperSat );
    if ((!lsat && !usat) ||
        (lsat && (P1_ExpDemo_B.IntegratorGain > 0)) ||
        (usat && (P1_ExpDemo_B.IntegratorGain < 0)) ) {
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)->Integrator_CSTATE =
        P1_ExpDemo_B.IntegratorGain;
    } else {
      /* in saturation */
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)->Integrator_CSTATE =
        0.0;
    }
  }

  /* Derivatives for Integrator: '<S10>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( P1_ExpDemo_X.Integrator_CSTATE_m <=
            (P1_ExpDemo_P.Integrator_LowerSat_k) );
    usat = ( P1_ExpDemo_X.Integrator_CSTATE_m >=
            P1_ExpDemo_P.Integrator_UpperSat_l );
    if ((!lsat && !usat) ||
        (lsat && (P1_ExpDemo_B.Gain1 > 0)) ||
        (usat && (P1_ExpDemo_B.Gain1 < 0)) ) {
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)
        ->Integrator_CSTATE_m = P1_ExpDemo_B.Gain1;
    } else {
      /* in saturation */
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)
        ->Integrator_CSTATE_m = 0.0;
    }
  }

  /* Derivatives for Integrator: '<S9>/Integrator' */
  {
    boolean_T lsat;
    boolean_T usat;
    lsat = ( P1_ExpDemo_X.Integrator_CSTATE_p <=
            (P1_ExpDemo_P.Integrator_LowerSat_kg) );
    usat = ( P1_ExpDemo_X.Integrator_CSTATE_p >=
            P1_ExpDemo_P.Integrator_UpperSat_b );
    if ((!lsat && !usat) ||
        (lsat && (P1_ExpDemo_B.Gain3 > 0)) ||
        (usat && (P1_ExpDemo_B.Gain3 < 0)) ) {
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)
        ->Integrator_CSTATE_p = P1_ExpDemo_B.Gain3;
    } else {
      /* in saturation */
      ((XDot_P1_ExpDemo_T *) P1_ExpDemo_M->ModelData.derivs)
        ->Integrator_CSTATE_p = 0.0;
    }
  }
}

/* Model initialize function */
void P1_ExpDemo_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<Root>/Algorithm Selector2' */
  P1_ExpDemo_DW.clockTickCounter = 0;

  /* Start for Constant: '<S2>/LimitFlagSource' */
  P1_ExpDemo_B.LimitFlagSource[0] = P1_ExpDemo_P.LimitFlagSource_Value[0];
  P1_ExpDemo_B.LimitFlagSource[1] = P1_ExpDemo_P.LimitFlagSource_Value[1];
  P1_ExpDemo_B.LimitFlagSource[2] = P1_ExpDemo_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S2>/LimitSource' */
  P1_ExpDemo_B.LimitSource[0] = P1_ExpDemo_P.LimitSource_Value[0];
  P1_ExpDemo_B.LimitSource[1] = P1_ExpDemo_P.LimitSource_Value[1];
  P1_ExpDemo_B.LimitSource[2] = P1_ExpDemo_P.LimitSource_Value[2];

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  P1_ExpDemo_B.PWMPrescalerSource = P1_ExpDemo_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S2>/ResetSwitchFlagSource' */
  P1_ExpDemo_B.ResetSwitchFlagSource[0] =
    P1_ExpDemo_P.ResetSwitchFlagSource_Value[0];
  P1_ExpDemo_B.ResetSwitchFlagSource[1] =
    P1_ExpDemo_P.ResetSwitchFlagSource_Value[1];
  P1_ExpDemo_B.ResetSwitchFlagSource[2] =
    P1_ExpDemo_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  P1_ExpDemo_B.ThermFlagSource[0] = P1_ExpDemo_P.ThermFlagSource_Value[0];
  P1_ExpDemo_B.ThermFlagSource[1] = P1_ExpDemo_P.ThermFlagSource_Value[1];
  P1_ExpDemo_B.ThermFlagSource[2] = P1_ExpDemo_P.ThermFlagSource_Value[2];
  P1_ExpDemo_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Memory: '<S7>/Memory' */
  P1_ExpDemo_DW.Memory_PreviousInput = P1_ExpDemo_P.Memory_X0;

  /* InitializeConditions for Memory: '<S7>/Memory1' */
  P1_ExpDemo_DW.Memory1_PreviousInput = P1_ExpDemo_P.Memory1_X0;

  /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn' */
  P1_ExpDemo_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S12>/Integrator' */
  P1_ExpDemo_X.Integrator_CSTATE = P1_ExpDemo_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S10>/Integrator' */
  P1_ExpDemo_X.Integrator_CSTATE_m = P1_ExpDemo_P.Integrator_IC_a;

  /* InitializeConditions for Memory: '<S10>/Memory' */
  P1_ExpDemo_DW.Memory_PreviousInput_a = P1_ExpDemo_P.Memory_X0_p;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  P1_ExpDemo_X.Integrator_CSTATE_p = P1_ExpDemo_P.Integrator_IC_h;

  /* InitializeConditions for Memory: '<S9>/Memory' */
  P1_ExpDemo_DW.Memory_PreviousInput_o = P1_ExpDemo_P.Memory_X0_m;
}

/* Model terminate function */
void P1_ExpDemo_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = P1_ExpDemo_M->childSfunctions[8];
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
  P1_ExpDemo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  P1_ExpDemo_update();
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
  P1_ExpDemo_initialize();
}

void MdlTerminate(void)
{
  P1_ExpDemo_terminate();
}

/* Registration function */
RT_MODEL_P1_ExpDemo_T *P1_ExpDemo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)P1_ExpDemo_M, 0,
                sizeof(RT_MODEL_P1_ExpDemo_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&P1_ExpDemo_M->solverInfo,
                          &P1_ExpDemo_M->Timing.simTimeStep);
    rtsiSetTPtr(&P1_ExpDemo_M->solverInfo, &rtmGetTPtr(P1_ExpDemo_M));
    rtsiSetStepSizePtr(&P1_ExpDemo_M->solverInfo,
                       &P1_ExpDemo_M->Timing.stepSize0);
    rtsiSetdXPtr(&P1_ExpDemo_M->solverInfo, &P1_ExpDemo_M->ModelData.derivs);
    rtsiSetContStatesPtr(&P1_ExpDemo_M->solverInfo, (real_T **)
                         &P1_ExpDemo_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&P1_ExpDemo_M->solverInfo,
      &P1_ExpDemo_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&P1_ExpDemo_M->solverInfo, (&rtmGetErrorStatus
      (P1_ExpDemo_M)));
    rtsiSetRTModelPtr(&P1_ExpDemo_M->solverInfo, P1_ExpDemo_M);
  }

  rtsiSetSimTimeStep(&P1_ExpDemo_M->solverInfo, MAJOR_TIME_STEP);
  P1_ExpDemo_M->ModelData.intgData.y = P1_ExpDemo_M->ModelData.odeY;
  P1_ExpDemo_M->ModelData.intgData.f[0] = P1_ExpDemo_M->ModelData.odeF[0];
  P1_ExpDemo_M->ModelData.intgData.f[1] = P1_ExpDemo_M->ModelData.odeF[1];
  P1_ExpDemo_M->ModelData.intgData.f[2] = P1_ExpDemo_M->ModelData.odeF[2];
  P1_ExpDemo_M->ModelData.intgData.f[3] = P1_ExpDemo_M->ModelData.odeF[3];
  P1_ExpDemo_M->ModelData.intgData.f[4] = P1_ExpDemo_M->ModelData.odeF[4];
  P1_ExpDemo_M->ModelData.intgData.f[5] = P1_ExpDemo_M->ModelData.odeF[5];
  P1_ExpDemo_M->ModelData.contStates = ((real_T *) &P1_ExpDemo_X);
  rtsiSetSolverData(&P1_ExpDemo_M->solverInfo, (void *)
                    &P1_ExpDemo_M->ModelData.intgData);
  rtsiSetSolverName(&P1_ExpDemo_M->solverInfo,"ode5");
  P1_ExpDemo_M->solverInfoPtr = (&P1_ExpDemo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = P1_ExpDemo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    P1_ExpDemo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    P1_ExpDemo_M->Timing.sampleTimes = (&P1_ExpDemo_M->Timing.sampleTimesArray[0]);
    P1_ExpDemo_M->Timing.offsetTimes = (&P1_ExpDemo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    P1_ExpDemo_M->Timing.sampleTimes[0] = (0.0);
    P1_ExpDemo_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    P1_ExpDemo_M->Timing.offsetTimes[0] = (0.0);
    P1_ExpDemo_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(P1_ExpDemo_M, &P1_ExpDemo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = P1_ExpDemo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    P1_ExpDemo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(P1_ExpDemo_M, 9999.0);
  P1_ExpDemo_M->Timing.stepSize0 = 0.01;
  P1_ExpDemo_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  P1_ExpDemo_M->Sizes.checksums[0] = (881090505U);
  P1_ExpDemo_M->Sizes.checksums[1] = (87551531U);
  P1_ExpDemo_M->Sizes.checksums[2] = (1747452531U);
  P1_ExpDemo_M->Sizes.checksums[3] = (1592601213U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    P1_ExpDemo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(P1_ExpDemo_M->extModeInfo,
      &P1_ExpDemo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(P1_ExpDemo_M->extModeInfo, P1_ExpDemo_M->Sizes.checksums);
    rteiSetTPtr(P1_ExpDemo_M->extModeInfo, rtmGetTPtr(P1_ExpDemo_M));
  }

  P1_ExpDemo_M->solverInfoPtr = (&P1_ExpDemo_M->solverInfo);
  P1_ExpDemo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&P1_ExpDemo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&P1_ExpDemo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  P1_ExpDemo_M->ModelData.blockIO = ((void *) &P1_ExpDemo_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      P1_ExpDemo_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      P1_ExpDemo_B.ResetEncoder[i] = 0.0;
    }

    P1_ExpDemo_B.Sum = 0.0;
    P1_ExpDemo_B.Cart_pos = 0.0;
    P1_ExpDemo_B.MatrixGain = 0.0;
    P1_ExpDemo_B.AngleScale = 0.0;
    P1_ExpDemo_B.PendPosOut = 0.0;
    P1_ExpDemo_B.Pend_vel = 0.0;
    P1_ExpDemo_B.Cart_vel = 0.0;
    P1_ExpDemo_B.Sum_k[0] = 0.0;
    P1_ExpDemo_B.Sum_k[1] = 0.0;
    P1_ExpDemo_B.Sum_k[2] = 0.0;
    P1_ExpDemo_B.Sum_k[3] = 0.0;
    P1_ExpDemo_B.umax = 0.0;
    P1_ExpDemo_B.Fcn = 0.0;
    P1_ExpDemo_B.CtrlMode = 0.0;
    P1_ExpDemo_B.Gain1 = 0.0;
    P1_ExpDemo_B.Memory = 0.0;
    P1_ExpDemo_B.Gain3 = 0.0;
    P1_ExpDemo_B.Memory_o = 0.0;
    P1_ExpDemo_B.Fcn_k = 0.0;
    P1_ExpDemo_B.CtrlSat = 0.0;
    P1_ExpDemo_B.PWM[0] = 0.0;
    P1_ExpDemo_B.PWM[1] = 0.0;
    P1_ExpDemo_B.PWM[2] = 0.0;
    P1_ExpDemo_B.Saturation[0] = 0.0;
    P1_ExpDemo_B.Saturation[1] = 0.0;
    P1_ExpDemo_B.Saturation[2] = 0.0;
    P1_ExpDemo_B.ResetSource[0] = 0.0;
    P1_ExpDemo_B.ResetSource[1] = 0.0;
    P1_ExpDemo_B.ResetSource[2] = 0.0;
    P1_ExpDemo_B.LimitFlag[0] = 0.0;
    P1_ExpDemo_B.LimitFlag[1] = 0.0;
    P1_ExpDemo_B.LimitFlag[2] = 0.0;
    P1_ExpDemo_B.LimitFlagSource[0] = 0.0;
    P1_ExpDemo_B.LimitFlagSource[1] = 0.0;
    P1_ExpDemo_B.LimitFlagSource[2] = 0.0;
    P1_ExpDemo_B.LimitSource[0] = 0.0;
    P1_ExpDemo_B.LimitSource[1] = 0.0;
    P1_ExpDemo_B.LimitSource[2] = 0.0;
    P1_ExpDemo_B.SetLimit[0] = 0.0;
    P1_ExpDemo_B.SetLimit[1] = 0.0;
    P1_ExpDemo_B.SetLimit[2] = 0.0;
    P1_ExpDemo_B.LimitSwitch[0] = 0.0;
    P1_ExpDemo_B.LimitSwitch[1] = 0.0;
    P1_ExpDemo_B.LimitSwitch[2] = 0.0;
    P1_ExpDemo_B.PWMPrescaler = 0.0;
    P1_ExpDemo_B.PWMPrescalerSource = 0.0;
    P1_ExpDemo_B.ResetSwitchFlag[0] = 0.0;
    P1_ExpDemo_B.ResetSwitchFlag[1] = 0.0;
    P1_ExpDemo_B.ResetSwitchFlag[2] = 0.0;
    P1_ExpDemo_B.ResetSwitchFlagSource[0] = 0.0;
    P1_ExpDemo_B.ResetSwitchFlagSource[1] = 0.0;
    P1_ExpDemo_B.ResetSwitchFlagSource[2] = 0.0;
    P1_ExpDemo_B.ThermFlag[0] = 0.0;
    P1_ExpDemo_B.ThermFlag[1] = 0.0;
    P1_ExpDemo_B.ThermFlag[2] = 0.0;
    P1_ExpDemo_B.ThermFlagSource[0] = 0.0;
    P1_ExpDemo_B.ThermFlagSource[1] = 0.0;
    P1_ExpDemo_B.ThermFlagSource[2] = 0.0;
    P1_ExpDemo_B.Fcn_kz = 0.0;
    P1_ExpDemo_B.IntegratorGain = 0.0;
    P1_ExpDemo_B.ResetEncoders = 0.0;
  }

  /* parameters */
  P1_ExpDemo_M->ModelData.defaultParam = ((real_T *)&P1_ExpDemo_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &P1_ExpDemo_X;
    P1_ExpDemo_M->ModelData.contStates = (x);
    (void) memset((void *)&P1_ExpDemo_X, 0,
                  sizeof(X_P1_ExpDemo_T));
  }

  /* states (dwork) */
  P1_ExpDemo_M->ModelData.dwork = ((void *) &P1_ExpDemo_DW);
  (void) memset((void *)&P1_ExpDemo_DW, 0,
                sizeof(DW_P1_ExpDemo_T));
  P1_ExpDemo_DW.Memory_PreviousInput = 0.0;
  P1_ExpDemo_DW.Memory1_PreviousInput = 0.0;
  P1_ExpDemo_DW.Memory_PreviousInput_a = 0.0;
  P1_ExpDemo_DW.Memory_PreviousInput_o = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    P1_ExpDemo_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &P1_ExpDemo_M->NonInlinedSFcns.sfcnInfo;
    P1_ExpDemo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(P1_ExpDemo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &P1_ExpDemo_M->Sizes.numSampTimes);
    P1_ExpDemo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(P1_ExpDemo_M)[0]);
    P1_ExpDemo_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(P1_ExpDemo_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,P1_ExpDemo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(P1_ExpDemo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(P1_ExpDemo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(P1_ExpDemo_M));
    rtssSetStepSizePtr(sfcnInfo, &P1_ExpDemo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(P1_ExpDemo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &P1_ExpDemo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &P1_ExpDemo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &P1_ExpDemo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &P1_ExpDemo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &P1_ExpDemo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &P1_ExpDemo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &P1_ExpDemo_M->solverInfoPtr);
  }

  P1_ExpDemo_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&P1_ExpDemo_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    P1_ExpDemo_M->childSfunctions =
      (&P1_ExpDemo_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        P1_ExpDemo_M->childSfunctions[i] =
          (&P1_ExpDemo_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/PWM (P1_PWM) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = P1_ExpDemo_B.Saturation;
          sfcnUPtrs[1] = &P1_ExpDemo_B.Saturation[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &P1_ExpDemo_B.ResetSource[0];
          sfcnUPtrs[1] = &P1_ExpDemo_B.ResetSource[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.ResetSource[2];
          sfcnUPtrs[3] = &P1_ExpDemo_B.ResetEncoders;
          sfcnUPtrs[4] = &P1_ExpDemo_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = P1_ExpDemo_B.LimitFlagSource;
          sfcnUPtrs[1] = &P1_ExpDemo_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = P1_ExpDemo_B.LimitSource;
          sfcnUPtrs[1] = &P1_ExpDemo_B.LimitSource[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &P1_ExpDemo_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &P1_ExpDemo_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = P1_ExpDemo_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &P1_ExpDemo_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: P1_ExpDemo/<S2>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = P1_ExpDemo_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &P1_ExpDemo_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, P1_ExpDemo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &P1_ExpDemo_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &P1_ExpDemo_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = P1_ExpDemo_B.ThermFlagSource;
          sfcnUPtrs[1] = &P1_ExpDemo_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &P1_ExpDemo_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) P1_ExpDemo_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "P1_ExpDemo/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,P1_ExpDemo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &P1_ExpDemo_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)P1_ExpDemo_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)P1_ExpDemo_P.ThermFlag_P2_Size);
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
  P1_ExpDemo_M->Sizes.numContStates = (4);/* Number of continuous states */
  P1_ExpDemo_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  P1_ExpDemo_M->Sizes.numY = (0);      /* Number of model outputs */
  P1_ExpDemo_M->Sizes.numU = (0);      /* Number of model inputs */
  P1_ExpDemo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  P1_ExpDemo_M->Sizes.numSampTimes = (2);/* Number of sample times */
  P1_ExpDemo_M->Sizes.numBlocks = (124);/* Number of blocks */
  P1_ExpDemo_M->Sizes.numBlockIO = (36);/* Number of block outputs */
  P1_ExpDemo_M->Sizes.numBlockPrms = (155);/* Sum of parameter "widths" */
  return P1_ExpDemo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
