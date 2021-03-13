/*
 * pend_model_official.c
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

/* Block signals (auto storage) */
B_pend_model_official_T pend_model_official_B;

/* Block states (auto storage) */
DW_pend_model_official_T pend_model_official_DW;

/* Real-time model */
RT_MODEL_pend_model_official_T pend_model_official_M_;
RT_MODEL_pend_model_official_T *const pend_model_official_M =
  &pend_model_official_M_;

/* Model step function */
void pend_model_official_step(void)
{
  {
    real_T *lastU;
    real_T lastTime;
    real_T rtb_Encoder500PPR[5];
    int32_T i;

    /* Level2 S-Function Block: '<S1>/Encoder' (P1_Encoder) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[0];
      sfcnOutputs(rts, 1);
    }

    /* Gain: '<S1>/Encoder 500PPR' */
    for (i = 0; i < 5; i++) {
      rtb_Encoder500PPR[i] = pend_model_official_P.Encoder500PPR_Gain *
        pend_model_official_B.Encoder[i];
    }

    /* End of Gain: '<S1>/Encoder 500PPR' */

    /* Sum: '<S1>/Sum' incorporates:
     *  Constant: '<S1>/Cart Offset'
     *  Gain: '<S1>/PosCart Scale'
     */
    pend_model_official_B.Sum = pend_model_official_P.PosCartScale_Gain *
      rtb_Encoder500PPR[4] + pend_model_official_P.CartOffset_Value;

    /* Derivative: '<Root>/Derivative' */
    if ((pend_model_official_DW.TimeStampA >= pend_model_official_M->Timing.t[0])
        && (pend_model_official_DW.TimeStampB >= pend_model_official_M->
            Timing.t[0])) {
      pend_model_official_B.CartVel = 0.0;
    } else {
      lastTime = pend_model_official_DW.TimeStampA;
      lastU = &pend_model_official_DW.LastUAtTimeA;
      if (pend_model_official_DW.TimeStampA < pend_model_official_DW.TimeStampB)
      {
        if (pend_model_official_DW.TimeStampB < pend_model_official_M->Timing.t
            [0]) {
          lastTime = pend_model_official_DW.TimeStampB;
          lastU = &pend_model_official_DW.LastUAtTimeB;
        }
      } else {
        if (pend_model_official_DW.TimeStampA >= pend_model_official_M->
            Timing.t[0]) {
          lastTime = pend_model_official_DW.TimeStampB;
          lastU = &pend_model_official_DW.LastUAtTimeB;
        }
      }

      pend_model_official_B.CartVel = (pend_model_official_B.Sum - *lastU) /
        (pend_model_official_M->Timing.t[0] - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Gain: '<S1>/Angle Scale' */
    pend_model_official_B.AngleScale = pend_model_official_P.AngleScale_Gain *
      rtb_Encoder500PPR[3];

    /* Derivative: '<Root>/Derivative1' */
    if ((pend_model_official_DW.TimeStampA_c >= pend_model_official_M->Timing.t
         [0]) && (pend_model_official_DW.TimeStampB_d >=
                  pend_model_official_M->Timing.t[0])) {
      pend_model_official_B.PendVel = 0.0;
    } else {
      lastTime = pend_model_official_DW.TimeStampA_c;
      lastU = &pend_model_official_DW.LastUAtTimeA_h;
      if (pend_model_official_DW.TimeStampA_c <
          pend_model_official_DW.TimeStampB_d) {
        if (pend_model_official_DW.TimeStampB_d <
            pend_model_official_M->Timing.t[0]) {
          lastTime = pend_model_official_DW.TimeStampB_d;
          lastU = &pend_model_official_DW.LastUAtTimeB_p;
        }
      } else {
        if (pend_model_official_DW.TimeStampA_c >=
            pend_model_official_M->Timing.t[0]) {
          lastTime = pend_model_official_DW.TimeStampB_d;
          lastU = &pend_model_official_DW.LastUAtTimeB_p;
        }
      }

      pend_model_official_B.PendVel = (pend_model_official_B.AngleScale - *lastU)
        / (pend_model_official_M->Timing.t[0] - lastTime);
    }

    /* End of Derivative: '<Root>/Derivative1' */

    /* Step: '<Root>/Step' */
    if (pend_model_official_M->Timing.t[0] < pend_model_official_P.Step_Time) {
      pend_model_official_B.Step = pend_model_official_P.Step_Y0;
    } else {
      pend_model_official_B.Step = pend_model_official_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */

    /* Step: '<Root>/Step1' */
    if (pend_model_official_M->Timing.t[0] < pend_model_official_P.Step1_Time) {
      pend_model_official_B.Step1 = pend_model_official_P.Step1_Y0;
    } else {
      pend_model_official_B.Step1 = pend_model_official_P.Step1_YFinal;
    }

    /* End of Step: '<Root>/Step1' */

    /* Level2 S-Function Block: '<S1>/PWM' (P1_PWM) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[1];
      sfcnOutputs(rts, 1);
    }

    /* Saturate: '<S1>/Saturation' */
    if (0.0 > pend_model_official_P.Saturation_UpperSat) {
      pend_model_official_B.Saturation[0] =
        pend_model_official_P.Saturation_UpperSat;
    } else if (0.0 < pend_model_official_P.Saturation_LowerSat) {
      pend_model_official_B.Saturation[0] =
        pend_model_official_P.Saturation_LowerSat;
    } else {
      pend_model_official_B.Saturation[0] = 0.0;
    }

    if (pend_model_official_B.Step > pend_model_official_P.Saturation_UpperSat)
    {
      pend_model_official_B.Saturation[1] =
        pend_model_official_P.Saturation_UpperSat;
    } else if (pend_model_official_B.Step <
               pend_model_official_P.Saturation_LowerSat) {
      pend_model_official_B.Saturation[1] =
        pend_model_official_P.Saturation_LowerSat;
    } else {
      pend_model_official_B.Saturation[1] = pend_model_official_B.Step;
    }

    if (0.0 > pend_model_official_P.Saturation_UpperSat) {
      pend_model_official_B.Saturation[2] =
        pend_model_official_P.Saturation_UpperSat;
    } else if (0.0 < pend_model_official_P.Saturation_LowerSat) {
      pend_model_official_B.Saturation[2] =
        pend_model_official_P.Saturation_LowerSat;
    } else {
      pend_model_official_B.Saturation[2] = 0.0;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Level2 S-Function Block: '<S1>/ResetEncoder' (P1_ResetEncoder) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[2];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S1>/ResetSource' */
    pend_model_official_B.ResetSource[0] =
      pend_model_official_P.ResetSource_Value[0];
    pend_model_official_B.ResetSource[1] =
      pend_model_official_P.ResetSource_Value[1];
    pend_model_official_B.ResetSource[2] =
      pend_model_official_P.ResetSource_Value[2];

    /* Level2 S-Function Block: '<S1>/LimitFlag' (P1_LimitFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[3];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S1>/LimitFlagSource' */
    pend_model_official_B.LimitFlagSource[0] =
      pend_model_official_P.LimitFlagSource_Value[0];
    pend_model_official_B.LimitFlagSource[1] =
      pend_model_official_P.LimitFlagSource_Value[1];
    pend_model_official_B.LimitFlagSource[2] =
      pend_model_official_P.LimitFlagSource_Value[2];

    /* Constant: '<S1>/LimitSource' */
    pend_model_official_B.LimitSource[0] =
      pend_model_official_P.LimitSource_Value[0];
    pend_model_official_B.LimitSource[1] =
      pend_model_official_P.LimitSource_Value[1];
    pend_model_official_B.LimitSource[2] =
      pend_model_official_P.LimitSource_Value[2];

    /* Level2 S-Function Block: '<S1>/SetLimit' (P1_SetLimit) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S1>/LimitSwitch' (P1_Switch) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S1>/PWMPrescaler' (P1_PWMPrescaler) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[6];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S1>/PWMPrescalerSource' */
    pend_model_official_B.PWMPrescalerSource =
      pend_model_official_P.PWMPrescalerSource_Value;

    /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[7];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S1>/ResetSwitchFlagSource' */
    pend_model_official_B.ResetSwitchFlagSource[0] =
      pend_model_official_P.ResetSwitchFlagSource_Value[0];
    pend_model_official_B.ResetSwitchFlagSource[1] =
      pend_model_official_P.ResetSwitchFlagSource_Value[1];
    pend_model_official_B.ResetSwitchFlagSource[2] =
      pend_model_official_P.ResetSwitchFlagSource_Value[2];

    /* Level2 S-Function Block: '<S1>/ThermFlag ' (P1_ThermFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[8];
      sfcnOutputs(rts, 1);
    }

    /* Constant: '<S1>/ThermFlagSource' */
    pend_model_official_B.ThermFlagSource[0] =
      pend_model_official_P.ThermFlagSource_Value[0];
    pend_model_official_B.ThermFlagSource[1] =
      pend_model_official_P.ThermFlagSource_Value[1];
    pend_model_official_B.ThermFlagSource[2] =
      pend_model_official_P.ThermFlagSource_Value[2];
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(pend_model_official_M->rtwLogInfo,
                      (pend_model_official_M->Timing.t));

  {
    real_T *lastU;

    /* Update for Derivative: '<Root>/Derivative' */
    if (pend_model_official_DW.TimeStampA == (rtInf)) {
      pend_model_official_DW.TimeStampA = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeA;
    } else if (pend_model_official_DW.TimeStampB == (rtInf)) {
      pend_model_official_DW.TimeStampB = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeB;
    } else if (pend_model_official_DW.TimeStampA <
               pend_model_official_DW.TimeStampB) {
      pend_model_official_DW.TimeStampA = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeA;
    } else {
      pend_model_official_DW.TimeStampB = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeB;
    }

    *lastU = pend_model_official_B.Sum;

    /* End of Update for Derivative: '<Root>/Derivative' */

    /* Update for Derivative: '<Root>/Derivative1' */
    if (pend_model_official_DW.TimeStampA_c == (rtInf)) {
      pend_model_official_DW.TimeStampA_c = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeA_h;
    } else if (pend_model_official_DW.TimeStampB_d == (rtInf)) {
      pend_model_official_DW.TimeStampB_d = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeB_p;
    } else if (pend_model_official_DW.TimeStampA_c <
               pend_model_official_DW.TimeStampB_d) {
      pend_model_official_DW.TimeStampA_c = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeA_h;
    } else {
      pend_model_official_DW.TimeStampB_d = pend_model_official_M->Timing.t[0];
      lastU = &pend_model_official_DW.LastUAtTimeB_p;
    }

    *lastU = pend_model_official_B.AngleScale;

    /* End of Update for Derivative: '<Root>/Derivative1' */
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(pend_model_official_M)!=-1) &&
        !((rtmGetTFinal(pend_model_official_M)-pend_model_official_M->Timing.t[0])
          > pend_model_official_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(pend_model_official_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pend_model_official_M)) {
      rtmSetErrorStatus(pend_model_official_M, "Simulation finished");
    }
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
  if (!(++pend_model_official_M->Timing.clockTick0)) {
    ++pend_model_official_M->Timing.clockTickH0;
  }

  pend_model_official_M->Timing.t[0] = pend_model_official_M->Timing.clockTick0 *
    pend_model_official_M->Timing.stepSize0 +
    pend_model_official_M->Timing.clockTickH0 *
    pend_model_official_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++pend_model_official_M->Timing.clockTick1)) {
      ++pend_model_official_M->Timing.clockTickH1;
    }

    pend_model_official_M->Timing.t[1] =
      pend_model_official_M->Timing.clockTick1 *
      pend_model_official_M->Timing.stepSize1 +
      pend_model_official_M->Timing.clockTickH1 *
      pend_model_official_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void pend_model_official_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pend_model_official_M, 0,
                sizeof(RT_MODEL_pend_model_official_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pend_model_official_M->solverInfo,
                          &pend_model_official_M->Timing.simTimeStep);
    rtsiSetTPtr(&pend_model_official_M->solverInfo, &rtmGetTPtr
                (pend_model_official_M));
    rtsiSetStepSizePtr(&pend_model_official_M->solverInfo,
                       &pend_model_official_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pend_model_official_M->solverInfo,
                          (&rtmGetErrorStatus(pend_model_official_M)));
    rtsiSetRTModelPtr(&pend_model_official_M->solverInfo, pend_model_official_M);
  }

  rtsiSetSimTimeStep(&pend_model_official_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&pend_model_official_M->solverInfo,"FixedStepDiscrete");
  pend_model_official_M->solverInfoPtr = (&pend_model_official_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pend_model_official_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    pend_model_official_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pend_model_official_M->Timing.sampleTimes =
      (&pend_model_official_M->Timing.sampleTimesArray[0]);
    pend_model_official_M->Timing.offsetTimes =
      (&pend_model_official_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pend_model_official_M->Timing.sampleTimes[0] = (0.0);
    pend_model_official_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    pend_model_official_M->Timing.offsetTimes[0] = (0.0);
    pend_model_official_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(pend_model_official_M, &pend_model_official_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pend_model_official_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    pend_model_official_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pend_model_official_M, 10.0);
  pend_model_official_M->Timing.stepSize0 = 0.01;
  pend_model_official_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    pend_model_official_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(pend_model_official_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(pend_model_official_M->rtwLogInfo, (NULL));
    rtliSetLogT(pend_model_official_M->rtwLogInfo, "tout");
    rtliSetLogX(pend_model_official_M->rtwLogInfo, "");
    rtliSetLogXFinal(pend_model_official_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(pend_model_official_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(pend_model_official_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(pend_model_official_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(pend_model_official_M->rtwLogInfo, 1);
    rtliSetLogY(pend_model_official_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(pend_model_official_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(pend_model_official_M->rtwLogInfo, (NULL));
  }

  pend_model_official_M->solverInfoPtr = (&pend_model_official_M->solverInfo);
  pend_model_official_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&pend_model_official_M->solverInfo, 0.01);
  rtsiSetSolverMode(&pend_model_official_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &pend_model_official_B), 0,
                sizeof(B_pend_model_official_T));

  /* states (dwork) */
  (void) memset((void *)&pend_model_official_DW, 0,
                sizeof(DW_pend_model_official_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &pend_model_official_M->NonInlinedSFcns.sfcnInfo;
    pend_model_official_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(pend_model_official_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &pend_model_official_M->Sizes.numSampTimes);
    pend_model_official_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (pend_model_official_M)[0]);
    pend_model_official_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (pend_model_official_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,pend_model_official_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(pend_model_official_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(pend_model_official_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (pend_model_official_M));
    rtssSetStepSizePtr(sfcnInfo, &pend_model_official_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(pend_model_official_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &pend_model_official_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &pend_model_official_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &pend_model_official_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &pend_model_official_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &pend_model_official_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &pend_model_official_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &pend_model_official_M->solverInfoPtr);
  }

  pend_model_official_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)
                  &pend_model_official_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    pend_model_official_M->childSfunctions =
      (&pend_model_official_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        pend_model_official_M->childSfunctions[i] =
          (&pend_model_official_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: pend_model_official/<S1>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pend_model_official_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pend_model_official_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/PWM (P1_PWM) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = pend_model_official_B.Saturation;
          sfcnUPtrs[1] = &pend_model_official_B.Saturation[1];
          sfcnUPtrs[2] = &pend_model_official_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pend_model_official_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pend_model_official_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pend_model_official_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &pend_model_official_B.ResetSource[0];
          sfcnUPtrs[1] = &pend_model_official_B.ResetSource[1];
          sfcnUPtrs[2] = &pend_model_official_B.ResetSource[2];
          sfcnUPtrs[3] = &pend_model_official_B.Step1;
          sfcnUPtrs[4] = &pend_model_official_B.Step1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pend_model_official_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pend_model_official_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = pend_model_official_B.LimitFlagSource;
          sfcnUPtrs[1] = &pend_model_official_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &pend_model_official_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pend_model_official_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pend_model_official_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = pend_model_official_B.LimitSource;
          sfcnUPtrs[1] = &pend_model_official_B.LimitSource[1];
          sfcnUPtrs[2] = &pend_model_official_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pend_model_official_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pend_model_official_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pend_model_official_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pend_model_official_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &pend_model_official_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &pend_model_official_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pend_model_official_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pend_model_official_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = pend_model_official_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &pend_model_official_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &pend_model_official_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pend_model_official_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pend_model_official_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: pend_model_official/<S1>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = pend_model_official_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        pend_model_official_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        pend_model_official_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = pend_model_official_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pend_model_official_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, pend_model_official_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pend_model_official_M->
                           NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &pend_model_official_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pend_model_official_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = pend_model_official_B.ThermFlagSource;
          sfcnUPtrs[1] = &pend_model_official_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &pend_model_official_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pend_model_official_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pend_model_official_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "pend_model_official/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,pend_model_official_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pend_model_official_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pend_model_official_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pend_model_official_P.ThermFlag_P2_Size);
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

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(pend_model_official_M->rtwLogInfo, 0.0,
    rtmGetTFinal(pend_model_official_M), pend_model_official_M->Timing.stepSize0,
    (&rtmGetErrorStatus(pend_model_official_M)));

  /* Start for Constant: '<S1>/LimitFlagSource' */
  pend_model_official_B.LimitFlagSource[0] =
    pend_model_official_P.LimitFlagSource_Value[0];
  pend_model_official_B.LimitFlagSource[1] =
    pend_model_official_P.LimitFlagSource_Value[1];
  pend_model_official_B.LimitFlagSource[2] =
    pend_model_official_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S1>/LimitSource' */
  pend_model_official_B.LimitSource[0] =
    pend_model_official_P.LimitSource_Value[0];
  pend_model_official_B.LimitSource[1] =
    pend_model_official_P.LimitSource_Value[1];
  pend_model_official_B.LimitSource[2] =
    pend_model_official_P.LimitSource_Value[2];

  /* Start for Constant: '<S1>/PWMPrescalerSource' */
  pend_model_official_B.PWMPrescalerSource =
    pend_model_official_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S1>/ResetSwitchFlagSource' */
  pend_model_official_B.ResetSwitchFlagSource[0] =
    pend_model_official_P.ResetSwitchFlagSource_Value[0];
  pend_model_official_B.ResetSwitchFlagSource[1] =
    pend_model_official_P.ResetSwitchFlagSource_Value[1];
  pend_model_official_B.ResetSwitchFlagSource[2] =
    pend_model_official_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S1>/ThermFlagSource' */
  pend_model_official_B.ThermFlagSource[0] =
    pend_model_official_P.ThermFlagSource_Value[0];
  pend_model_official_B.ThermFlagSource[1] =
    pend_model_official_P.ThermFlagSource_Value[1];
  pend_model_official_B.ThermFlagSource[2] =
    pend_model_official_P.ThermFlagSource_Value[2];

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  pend_model_official_DW.TimeStampA = (rtInf);
  pend_model_official_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<Root>/Derivative1' */
  pend_model_official_DW.TimeStampA_c = (rtInf);
  pend_model_official_DW.TimeStampB_d = (rtInf);
}

/* Model terminate function */
void pend_model_official_terminate(void)
{
  /* Level2 S-Function Block: '<S1>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/PWM' (P1_PWM) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S1>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = pend_model_official_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}
