/*
 * pendulum_171019.c
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
#include "pendulum_171019_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_pendulum_171019_T pendulum_171019_B;

/* Block states (auto storage) */
DW_pendulum_171019_T pendulum_171019_DW;

/* Real-time model */
RT_MODEL_pendulum_171019_T pendulum_171019_M_;
RT_MODEL_pendulum_171019_T *const pendulum_171019_M = &pendulum_171019_M_;
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
void pendulum_171019_output(void)
{
  real_T rtb_Encoder500PPR[5];
  real_T rtb_Memory;
  int32_T i;

  /* Constant: '<Root>/Control' */
  pendulum_171019_B.Control = pendulum_171019_P.Control_Value;

  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S2>/Encoder 500PPR' */
  for (i = 0; i < 5; i++) {
    rtb_Encoder500PPR[i] = pendulum_171019_P.Encoder500PPR_Gain *
      pendulum_171019_B.Encoder[i];
  }

  /* End of Gain: '<S2>/Encoder 500PPR' */

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Cart Offset'
   *  Gain: '<S2>/PosCart Scale'
   */
  pendulum_171019_B.Sum = pendulum_171019_P.PosCartScale_Gain *
    rtb_Encoder500PPR[4] + pendulum_171019_P.CartOffset_Value;

  /* Gain: '<S3>/Gain3' */
  pendulum_171019_B.Cart_pos = pendulum_171019_P.Gain3_Gain *
    pendulum_171019_B.Sum;

  /* Gain: '<S3>/Gain4' incorporates:
   *  Memory: '<S3>/Memory1'
   *  Sum: '<S3>/Sum1'
   */
  pendulum_171019_B.Cart_vel = 1.0 / pendulum_171019_P.Sensors_T0 *
    (pendulum_171019_B.Sum - pendulum_171019_DW.Memory1_PreviousInput);

  /* Gain: '<S2>/Angle Scale' */
  pendulum_171019_B.AngleScale = pendulum_171019_P.AngleScale_Gain *
    rtb_Encoder500PPR[3];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/pi'
   *  Constant: '<S1>/pos'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S1>/Product'
   */
  rtb_Memory = pendulum_171019_P.pi_Value *
    pendulum_171019_P.AlfaNormalization_pos + pendulum_171019_P.Gain1_Gain *
    pendulum_171019_B.AngleScale;

  /* Fcn: '<S1>/angle normalization' */
  pendulum_171019_B.PendPosOut = rt_atan2d_snf(sin(rtb_Memory), cos(rtb_Memory));

  /* Gain: '<S3>/Gain2' incorporates:
   *  Memory: '<S3>/Memory'
   *  Sum: '<S3>/Sum'
   */
  pendulum_171019_B.Pend_vel = 1.0 / pendulum_171019_P.Sensors_T0 *
    (pendulum_171019_B.AngleScale - pendulum_171019_DW.Memory_PreviousInput);

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Saturate: '<S2>/Saturation' */
  if (0.0 > pendulum_171019_P.Saturation_UpperSat) {
    pendulum_171019_B.Saturation[0] = pendulum_171019_P.Saturation_UpperSat;
  } else if (0.0 < pendulum_171019_P.Saturation_LowerSat) {
    pendulum_171019_B.Saturation[0] = pendulum_171019_P.Saturation_LowerSat;
  } else {
    pendulum_171019_B.Saturation[0] = 0.0;
  }

  if (pendulum_171019_B.Control > pendulum_171019_P.Saturation_UpperSat) {
    pendulum_171019_B.Saturation[1] = pendulum_171019_P.Saturation_UpperSat;
  } else if (pendulum_171019_B.Control < pendulum_171019_P.Saturation_LowerSat)
  {
    pendulum_171019_B.Saturation[1] = pendulum_171019_P.Saturation_LowerSat;
  } else {
    pendulum_171019_B.Saturation[1] = pendulum_171019_B.Control;
  }

  if (0.0 > pendulum_171019_P.Saturation_UpperSat) {
    pendulum_171019_B.Saturation[2] = pendulum_171019_P.Saturation_UpperSat;
  } else if (0.0 < pendulum_171019_P.Saturation_LowerSat) {
    pendulum_171019_B.Saturation[2] = pendulum_171019_P.Saturation_LowerSat;
  } else {
    pendulum_171019_B.Saturation[2] = 0.0;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ResetSource' */
  pendulum_171019_B.ResetSource[0] = pendulum_171019_P.ResetSource_Value[0];
  pendulum_171019_B.ResetSource[1] = pendulum_171019_P.ResetSource_Value[1];
  pendulum_171019_B.ResetSource[2] = pendulum_171019_P.ResetSource_Value[2];

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/LimitFlagSource' */
  pendulum_171019_B.LimitFlagSource[0] =
    pendulum_171019_P.LimitFlagSource_Value[0];
  pendulum_171019_B.LimitFlagSource[1] =
    pendulum_171019_P.LimitFlagSource_Value[1];
  pendulum_171019_B.LimitFlagSource[2] =
    pendulum_171019_P.LimitFlagSource_Value[2];

  /* Constant: '<S2>/LimitSource' */
  pendulum_171019_B.LimitSource[0] = pendulum_171019_P.LimitSource_Value[0];
  pendulum_171019_B.LimitSource[1] = pendulum_171019_P.LimitSource_Value[1];
  pendulum_171019_B.LimitSource[2] = pendulum_171019_P.LimitSource_Value[2];

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/PWMPrescalerSource' */
  pendulum_171019_B.PWMPrescalerSource =
    pendulum_171019_P.PWMPrescalerSource_Value;

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ResetSwitchFlagSource' */
  pendulum_171019_B.ResetSwitchFlagSource[0] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[0];
  pendulum_171019_B.ResetSwitchFlagSource[1] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[1];
  pendulum_171019_B.ResetSwitchFlagSource[2] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[2];

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ThermFlagSource' */
  pendulum_171019_B.ThermFlagSource[0] =
    pendulum_171019_P.ThermFlagSource_Value[0];
  pendulum_171019_B.ThermFlagSource[1] =
    pendulum_171019_P.ThermFlagSource_Value[1];
  pendulum_171019_B.ThermFlagSource[2] =
    pendulum_171019_P.ThermFlagSource_Value[2];

  /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
   *  Constant: '<Root>/Normal'
   *  Constant: '<Root>/Reset'
   */
  if (pendulum_171019_P.ResetEncoders_CurrentSetting == 1) {
    pendulum_171019_B.ResetEncoders = pendulum_171019_P.Reset_Value;
  } else {
    pendulum_171019_B.ResetEncoders = pendulum_171019_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */
}

/* Model update function */
void pendulum_171019_update(void)
{
  /* Update for Memory: '<S3>/Memory1' */
  pendulum_171019_DW.Memory1_PreviousInput = pendulum_171019_B.Sum;

  /* Update for Memory: '<S3>/Memory' */
  pendulum_171019_DW.Memory_PreviousInput = pendulum_171019_B.AngleScale;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pendulum_171019_M->Timing.clockTick0)) {
    ++pendulum_171019_M->Timing.clockTickH0;
  }

  pendulum_171019_M->Timing.t[0] = pendulum_171019_M->Timing.clockTick0 *
    pendulum_171019_M->Timing.stepSize0 + pendulum_171019_M->Timing.clockTickH0 *
    pendulum_171019_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void pendulum_171019_initialize(void)
{
  /* Start for Constant: '<S2>/LimitFlagSource' */
  pendulum_171019_B.LimitFlagSource[0] =
    pendulum_171019_P.LimitFlagSource_Value[0];
  pendulum_171019_B.LimitFlagSource[1] =
    pendulum_171019_P.LimitFlagSource_Value[1];
  pendulum_171019_B.LimitFlagSource[2] =
    pendulum_171019_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S2>/LimitSource' */
  pendulum_171019_B.LimitSource[0] = pendulum_171019_P.LimitSource_Value[0];
  pendulum_171019_B.LimitSource[1] = pendulum_171019_P.LimitSource_Value[1];
  pendulum_171019_B.LimitSource[2] = pendulum_171019_P.LimitSource_Value[2];

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  pendulum_171019_B.PWMPrescalerSource =
    pendulum_171019_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S2>/ResetSwitchFlagSource' */
  pendulum_171019_B.ResetSwitchFlagSource[0] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[0];
  pendulum_171019_B.ResetSwitchFlagSource[1] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[1];
  pendulum_171019_B.ResetSwitchFlagSource[2] =
    pendulum_171019_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  pendulum_171019_B.ThermFlagSource[0] =
    pendulum_171019_P.ThermFlagSource_Value[0];
  pendulum_171019_B.ThermFlagSource[1] =
    pendulum_171019_P.ThermFlagSource_Value[1];
  pendulum_171019_B.ThermFlagSource[2] =
    pendulum_171019_P.ThermFlagSource_Value[2];

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  pendulum_171019_DW.Memory1_PreviousInput = pendulum_171019_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S3>/Memory' */
  pendulum_171019_DW.Memory_PreviousInput = pendulum_171019_P.Memory_X0;
}

/* Model terminate function */
void pendulum_171019_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = pendulum_171019_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pendulum_171019_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pendulum_171019_update();
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
  pendulum_171019_initialize();
}

void MdlTerminate(void)
{
  pendulum_171019_terminate();
}

/* Registration function */
RT_MODEL_pendulum_171019_T *pendulum_171019(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pendulum_171019_M, 0,
                sizeof(RT_MODEL_pendulum_171019_T));
  rtsiSetSolverName(&pendulum_171019_M->solverInfo,"FixedStepDiscrete");
  pendulum_171019_M->solverInfoPtr = (&pendulum_171019_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pendulum_171019_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    pendulum_171019_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pendulum_171019_M->Timing.sampleTimes =
      (&pendulum_171019_M->Timing.sampleTimesArray[0]);
    pendulum_171019_M->Timing.offsetTimes =
      (&pendulum_171019_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pendulum_171019_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    pendulum_171019_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(pendulum_171019_M, &pendulum_171019_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pendulum_171019_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    pendulum_171019_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pendulum_171019_M, 9999.0);
  pendulum_171019_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  pendulum_171019_M->Sizes.checksums[0] = (1797003332U);
  pendulum_171019_M->Sizes.checksums[1] = (2179790002U);
  pendulum_171019_M->Sizes.checksums[2] = (3767939128U);
  pendulum_171019_M->Sizes.checksums[3] = (1434986208U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    pendulum_171019_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pendulum_171019_M->extModeInfo,
      &pendulum_171019_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pendulum_171019_M->extModeInfo,
                        pendulum_171019_M->Sizes.checksums);
    rteiSetTPtr(pendulum_171019_M->extModeInfo, rtmGetTPtr(pendulum_171019_M));
  }

  pendulum_171019_M->solverInfoPtr = (&pendulum_171019_M->solverInfo);
  pendulum_171019_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&pendulum_171019_M->solverInfo, 0.01);
  rtsiSetSolverMode(&pendulum_171019_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pendulum_171019_M->ModelData.blockIO = ((void *) &pendulum_171019_B);
  (void) memset(((void *) &pendulum_171019_B), 0,
                sizeof(B_pendulum_171019_T));

  /* parameters */
  pendulum_171019_M->ModelData.defaultParam = ((real_T *)&pendulum_171019_P);

  /* states (dwork) */
  pendulum_171019_M->ModelData.dwork = ((void *) &pendulum_171019_DW);
  (void) memset((void *)&pendulum_171019_DW, 0,
                sizeof(DW_pendulum_171019_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pendulum_171019_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &pendulum_171019_M->NonInlinedSFcns.sfcnInfo;
    pendulum_171019_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(pendulum_171019_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &pendulum_171019_M->Sizes.numSampTimes);
    pendulum_171019_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (pendulum_171019_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,pendulum_171019_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(pendulum_171019_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(pendulum_171019_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (pendulum_171019_M));
    rtssSetStepSizePtr(sfcnInfo, &pendulum_171019_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(pendulum_171019_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &pendulum_171019_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &pendulum_171019_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &pendulum_171019_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &pendulum_171019_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &pendulum_171019_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &pendulum_171019_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &pendulum_171019_M->solverInfoPtr);
  }

  pendulum_171019_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&pendulum_171019_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  9*sizeof(SimStruct));
    pendulum_171019_M->childSfunctions =
      (&pendulum_171019_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        pendulum_171019_M->childSfunctions[i] =
          (&pendulum_171019_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulum_171019_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.Encoder_P2_Size);
      }

      /* registration */
      P1_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/PWM (P1_PWM) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = pendulum_171019_B.Saturation;
          sfcnUPtrs[1] = &pendulum_171019_B.Saturation[1];
          sfcnUPtrs[2] = &pendulum_171019_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulum_171019_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.PWM_P2_Size);
      }

      /* registration */
      P1_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &pendulum_171019_B.ResetSource[0];
          sfcnUPtrs[1] = &pendulum_171019_B.ResetSource[1];
          sfcnUPtrs[2] = &pendulum_171019_B.ResetSource[2];
          sfcnUPtrs[3] = &pendulum_171019_B.ResetEncoders;
          sfcnUPtrs[4] = &pendulum_171019_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulum_171019_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.ResetEncoder_P2_Size);
      }

      /* registration */
      P1_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = pendulum_171019_B.LimitFlagSource;
          sfcnUPtrs[1] = &pendulum_171019_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &pendulum_171019_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulum_171019_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.LimitFlag_P2_Size);
      }

      /* registration */
      P1_LimitFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = pendulum_171019_B.LimitSource;
          sfcnUPtrs[1] = &pendulum_171019_B.LimitSource[1];
          sfcnUPtrs[2] = &pendulum_171019_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulum_171019_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.SetLimit_P2_Size);
      }

      /* registration */
      P1_SetLimit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulum_171019_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.LimitSwitch_P2_Size);
      }

      /* registration */
      P1_Switch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &pendulum_171019_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &pendulum_171019_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      P1_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = pendulum_171019_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &pendulum_171019_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &pendulum_171019_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            pendulum_171019_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       pendulum_171019_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       pendulum_171019_P.ResetSwitchFlag_P2_Size);
      }

      /* registration */
      P1_ResetSwitchFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: pendulum_171019/<S2>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = pendulum_171019_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = pendulum_171019_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = pendulum_171019_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = pendulum_171019_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &pendulum_171019_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, pendulum_171019_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &pendulum_171019_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &pendulum_171019_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &pendulum_171019_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &pendulum_171019_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = pendulum_171019_B.ThermFlagSource;
          sfcnUPtrs[1] = &pendulum_171019_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &pendulum_171019_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &pendulum_171019_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) pendulum_171019_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "pendulum_171019/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,pendulum_171019_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &pendulum_171019_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)pendulum_171019_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)pendulum_171019_P.ThermFlag_P2_Size);
      }

      /* registration */
      P1_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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
  pendulum_171019_M->Sizes.numContStates = (0);/* Number of continuous states */
  pendulum_171019_M->Sizes.numY = (0); /* Number of model outputs */
  pendulum_171019_M->Sizes.numU = (0); /* Number of model inputs */
  pendulum_171019_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pendulum_171019_M->Sizes.numSampTimes = (1);/* Number of sample times */
  pendulum_171019_M->Sizes.numBlocks = (41);/* Number of blocks */
  pendulum_171019_M->Sizes.numBlockIO = (24);/* Number of block outputs */
  pendulum_171019_M->Sizes.numBlockPrms = (87);/* Sum of parameter "widths" */
  return pendulum_171019_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
