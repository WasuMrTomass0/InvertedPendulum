/*
 * Wahadlo.c
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

#include "Wahadlo.h"
#include "Wahadlo_private.h"
#include "Wahadlo_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

/* Block signals (auto storage) */
B_Wahadlo_T Wahadlo_B;

/* Block states (auto storage) */
DW_Wahadlo_T Wahadlo_DW;

/* Real-time model */
RT_MODEL_Wahadlo_T Wahadlo_M_;
RT_MODEL_Wahadlo_T *const Wahadlo_M = &Wahadlo_M_;
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
void Wahadlo_output(void)
{
  real_T rtb_Memory1;
  real_T rtb_Encoder1024PPR[5];
  int32_T i;

  /* ManualSwitch: '<Root>/Reset Encoders1' incorporates:
   *  Constant: '<Root>/Ctrl'
   *  Constant: '<Root>/Ctrl1'
   *  Gain: '<S4>/Slider Gain'
   */
  if (Wahadlo_P.ResetEncoders1_CurrentSetting == 1) {
    Wahadlo_B.ResetEncoders1 = Wahadlo_P.SliderGain_gain * Wahadlo_P.Ctrl1_Value;
  } else {
    Wahadlo_B.ResetEncoders1 = Wahadlo_P.Ctrl_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders1' */

  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Gain: '<S2>/Encoder 1024 PPR' */
  for (i = 0; i < 5; i++) {
    rtb_Encoder1024PPR[i] = Wahadlo_P.Encoder1024PPR_Gain * Wahadlo_B.Encoder[i];
  }

  /* End of Gain: '<S2>/Encoder 1024 PPR' */

  /* Gain: '<S2>/Angle Scale' */
  Wahadlo_B.AngleScale = Wahadlo_P.AngleScale_Gain * rtb_Encoder1024PPR[3];

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/pi'
   *  Constant: '<S1>/pos'
   *  Gain: '<S3>/Gain1'
   *  Product: '<S1>/Product'
   */
  rtb_Memory1 = Wahadlo_P.pi_Value * Wahadlo_P.AlfaNormalization_pos +
    Wahadlo_P.Gain1_Gain * Wahadlo_B.AngleScale;

  /* Fcn: '<S1>/angle normalization' */
  Wahadlo_B.PendPosOut = rt_atan2d_snf(sin(rtb_Memory1), cos(rtb_Memory1));

  /* Gain: '<S3>/Gain2' incorporates:
   *  Memory: '<S3>/Memory'
   *  Sum: '<S3>/Sum'
   */
  Wahadlo_B.Pend_vel = 1.0 / Wahadlo_P.Sensors_T0 * (Wahadlo_B.AngleScale -
    Wahadlo_DW.Memory_PreviousInput);

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Cart Offset'
   *  Gain: '<S2>/PosCart Scale'
   */
  Wahadlo_B.Sum = Wahadlo_P.PosCartScale_Gain * rtb_Encoder1024PPR[4] +
    Wahadlo_P.CartOffset_Value;

  /* Gain: '<S3>/Gain3' */
  Wahadlo_B.Cart_pos = Wahadlo_P.Gain3_Gain * Wahadlo_B.Sum;

  /* Gain: '<S3>/Gain4' incorporates:
   *  Memory: '<S3>/Memory1'
   *  Sum: '<S3>/Sum1'
   */
  Wahadlo_B.Cart_vel = 1.0 / Wahadlo_P.Sensors_T0 * (Wahadlo_B.Sum -
    Wahadlo_DW.Memory1_PreviousInput);

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Saturate: '<S2>/Saturation' */
  if (0.0 > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[0] = Wahadlo_P.Saturation_UpperSat;
  } else if (0.0 < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[0] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[0] = 0.0;
  }

  if (Wahadlo_B.ResetEncoders1 > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[1] = Wahadlo_P.Saturation_UpperSat;
  } else if (Wahadlo_B.ResetEncoders1 < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[1] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[1] = Wahadlo_B.ResetEncoders1;
  }

  if (0.0 > Wahadlo_P.Saturation_UpperSat) {
    Wahadlo_B.Saturation[2] = Wahadlo_P.Saturation_UpperSat;
  } else if (0.0 < Wahadlo_P.Saturation_LowerSat) {
    Wahadlo_B.Saturation[2] = Wahadlo_P.Saturation_LowerSat;
  } else {
    Wahadlo_B.Saturation[2] = 0.0;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[2];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ResetSource' */
  Wahadlo_B.ResetSource[0] = Wahadlo_P.ResetSource_Value[0];
  Wahadlo_B.ResetSource[1] = Wahadlo_P.ResetSource_Value[1];
  Wahadlo_B.ResetSource[2] = Wahadlo_P.ResetSource_Value[2];

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[3];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/LimitFlagSource' */
  Wahadlo_B.LimitFlagSource[0] = Wahadlo_P.LimitFlagSource_Value[0];
  Wahadlo_B.LimitFlagSource[1] = Wahadlo_P.LimitFlagSource_Value[1];
  Wahadlo_B.LimitFlagSource[2] = Wahadlo_P.LimitFlagSource_Value[2];

  /* Constant: '<S2>/LimitSource' */
  Wahadlo_B.LimitSource[0] = Wahadlo_P.LimitSource_Value[0];
  Wahadlo_B.LimitSource[1] = Wahadlo_P.LimitSource_Value[1];
  Wahadlo_B.LimitSource[2] = Wahadlo_P.LimitSource_Value[2];

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[4];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[5];
    sfcnOutputs(rts, 0);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[6];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/PWMPrescalerSource' */
  Wahadlo_B.PWMPrescalerSource = Wahadlo_P.PWMPrescalerSource_Value;

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[7];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ResetSwitchFlagSource' */
  Wahadlo_B.ResetSwitchFlagSource[0] = Wahadlo_P.ResetSwitchFlagSource_Value[0];
  Wahadlo_B.ResetSwitchFlagSource[1] = Wahadlo_P.ResetSwitchFlagSource_Value[1];
  Wahadlo_B.ResetSwitchFlagSource[2] = Wahadlo_P.ResetSwitchFlagSource_Value[2];

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[8];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S2>/ThermFlagSource' */
  Wahadlo_B.ThermFlagSource[0] = Wahadlo_P.ThermFlagSource_Value[0];
  Wahadlo_B.ThermFlagSource[1] = Wahadlo_P.ThermFlagSource_Value[1];
  Wahadlo_B.ThermFlagSource[2] = Wahadlo_P.ThermFlagSource_Value[2];

  /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
   *  Constant: '<Root>/Normal'
   *  Constant: '<Root>/Reset'
   */
  if (Wahadlo_P.ResetEncoders_CurrentSetting == 1) {
    Wahadlo_B.ResetEncoders = Wahadlo_P.Reset_Value;
  } else {
    Wahadlo_B.ResetEncoders = Wahadlo_P.Normal_Value;
  }

  /* End of ManualSwitch: '<Root>/Reset Encoders' */
}

/* Model update function */
void Wahadlo_update(void)
{
  /* Update for Memory: '<S3>/Memory' */
  Wahadlo_DW.Memory_PreviousInput = Wahadlo_B.AngleScale;

  /* Update for Memory: '<S3>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput = Wahadlo_B.Sum;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Wahadlo_M->Timing.clockTick0)) {
    ++Wahadlo_M->Timing.clockTickH0;
  }

  Wahadlo_M->Timing.t[0] = Wahadlo_M->Timing.clockTick0 *
    Wahadlo_M->Timing.stepSize0 + Wahadlo_M->Timing.clockTickH0 *
    Wahadlo_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Wahadlo_initialize(void)
{
  /* Start for Constant: '<S2>/LimitFlagSource' */
  Wahadlo_B.LimitFlagSource[0] = Wahadlo_P.LimitFlagSource_Value[0];
  Wahadlo_B.LimitFlagSource[1] = Wahadlo_P.LimitFlagSource_Value[1];
  Wahadlo_B.LimitFlagSource[2] = Wahadlo_P.LimitFlagSource_Value[2];

  /* Start for Constant: '<S2>/LimitSource' */
  Wahadlo_B.LimitSource[0] = Wahadlo_P.LimitSource_Value[0];
  Wahadlo_B.LimitSource[1] = Wahadlo_P.LimitSource_Value[1];
  Wahadlo_B.LimitSource[2] = Wahadlo_P.LimitSource_Value[2];

  /* Start for Constant: '<S2>/PWMPrescalerSource' */
  Wahadlo_B.PWMPrescalerSource = Wahadlo_P.PWMPrescalerSource_Value;

  /* Start for Constant: '<S2>/ResetSwitchFlagSource' */
  Wahadlo_B.ResetSwitchFlagSource[0] = Wahadlo_P.ResetSwitchFlagSource_Value[0];
  Wahadlo_B.ResetSwitchFlagSource[1] = Wahadlo_P.ResetSwitchFlagSource_Value[1];
  Wahadlo_B.ResetSwitchFlagSource[2] = Wahadlo_P.ResetSwitchFlagSource_Value[2];

  /* Start for Constant: '<S2>/ThermFlagSource' */
  Wahadlo_B.ThermFlagSource[0] = Wahadlo_P.ThermFlagSource_Value[0];
  Wahadlo_B.ThermFlagSource[1] = Wahadlo_P.ThermFlagSource_Value[1];
  Wahadlo_B.ThermFlagSource[2] = Wahadlo_P.ThermFlagSource_Value[2];

  /* InitializeConditions for Memory: '<S3>/Memory' */
  Wahadlo_DW.Memory_PreviousInput = Wahadlo_P.Memory_X0;

  /* InitializeConditions for Memory: '<S3>/Memory1' */
  Wahadlo_DW.Memory1_PreviousInput = Wahadlo_P.Memory1_X0;
}

/* Model terminate function */
void Wahadlo_terminate(void)
{
  /* Level2 S-Function Block: '<S2>/Encoder' (P1_Encoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWM' (P1_PWM) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetEncoder' (P1_ResetEncoder) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitFlag' (P1_LimitFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/SetLimit' (P1_SetLimit) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/LimitSwitch' (P1_Switch) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/PWMPrescaler' (P1_PWMPrescaler) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ResetSwitchFlag ' (P1_ResetSwitchFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S2>/ThermFlag ' (P1_ThermFlag) */
  {
    SimStruct *rts = Wahadlo_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Wahadlo_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Wahadlo_update();
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
  Wahadlo_initialize();
}

void MdlTerminate(void)
{
  Wahadlo_terminate();
}

/* Registration function */
RT_MODEL_Wahadlo_T *Wahadlo(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Wahadlo_M, 0,
                sizeof(RT_MODEL_Wahadlo_T));
  rtsiSetSolverName(&Wahadlo_M->solverInfo,"FixedStepDiscrete");
  Wahadlo_M->solverInfoPtr = (&Wahadlo_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Wahadlo_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    Wahadlo_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Wahadlo_M->Timing.sampleTimes = (&Wahadlo_M->Timing.sampleTimesArray[0]);
    Wahadlo_M->Timing.offsetTimes = (&Wahadlo_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Wahadlo_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    Wahadlo_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(Wahadlo_M, &Wahadlo_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Wahadlo_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    Wahadlo_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Wahadlo_M, 9999.0);
  Wahadlo_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Wahadlo_M->Sizes.checksums[0] = (743102918U);
  Wahadlo_M->Sizes.checksums[1] = (3666379826U);
  Wahadlo_M->Sizes.checksums[2] = (182934237U);
  Wahadlo_M->Sizes.checksums[3] = (586102344U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    Wahadlo_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Wahadlo_M->extModeInfo,
      &Wahadlo_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Wahadlo_M->extModeInfo, Wahadlo_M->Sizes.checksums);
    rteiSetTPtr(Wahadlo_M->extModeInfo, rtmGetTPtr(Wahadlo_M));
  }

  Wahadlo_M->solverInfoPtr = (&Wahadlo_M->solverInfo);
  Wahadlo_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&Wahadlo_M->solverInfo, 0.01);
  rtsiSetSolverMode(&Wahadlo_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Wahadlo_M->ModelData.blockIO = ((void *) &Wahadlo_B);

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      Wahadlo_B.Encoder[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      Wahadlo_B.ResetEncoder[i] = 0.0;
    }

    Wahadlo_B.ResetEncoders1 = 0.0;
    Wahadlo_B.AngleScale = 0.0;
    Wahadlo_B.PendPosOut = 0.0;
    Wahadlo_B.Pend_vel = 0.0;
    Wahadlo_B.Sum = 0.0;
    Wahadlo_B.Cart_pos = 0.0;
    Wahadlo_B.Cart_vel = 0.0;
    Wahadlo_B.PWM[0] = 0.0;
    Wahadlo_B.PWM[1] = 0.0;
    Wahadlo_B.PWM[2] = 0.0;
    Wahadlo_B.Saturation[0] = 0.0;
    Wahadlo_B.Saturation[1] = 0.0;
    Wahadlo_B.Saturation[2] = 0.0;
    Wahadlo_B.ResetSource[0] = 0.0;
    Wahadlo_B.ResetSource[1] = 0.0;
    Wahadlo_B.ResetSource[2] = 0.0;
    Wahadlo_B.LimitFlag[0] = 0.0;
    Wahadlo_B.LimitFlag[1] = 0.0;
    Wahadlo_B.LimitFlag[2] = 0.0;
    Wahadlo_B.LimitFlagSource[0] = 0.0;
    Wahadlo_B.LimitFlagSource[1] = 0.0;
    Wahadlo_B.LimitFlagSource[2] = 0.0;
    Wahadlo_B.LimitSource[0] = 0.0;
    Wahadlo_B.LimitSource[1] = 0.0;
    Wahadlo_B.LimitSource[2] = 0.0;
    Wahadlo_B.SetLimit[0] = 0.0;
    Wahadlo_B.SetLimit[1] = 0.0;
    Wahadlo_B.SetLimit[2] = 0.0;
    Wahadlo_B.LimitSwitch[0] = 0.0;
    Wahadlo_B.LimitSwitch[1] = 0.0;
    Wahadlo_B.LimitSwitch[2] = 0.0;
    Wahadlo_B.PWMPrescaler = 0.0;
    Wahadlo_B.PWMPrescalerSource = 0.0;
    Wahadlo_B.ResetSwitchFlag[0] = 0.0;
    Wahadlo_B.ResetSwitchFlag[1] = 0.0;
    Wahadlo_B.ResetSwitchFlag[2] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[0] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[1] = 0.0;
    Wahadlo_B.ResetSwitchFlagSource[2] = 0.0;
    Wahadlo_B.ThermFlag[0] = 0.0;
    Wahadlo_B.ThermFlag[1] = 0.0;
    Wahadlo_B.ThermFlag[2] = 0.0;
    Wahadlo_B.ThermFlagSource[0] = 0.0;
    Wahadlo_B.ThermFlagSource[1] = 0.0;
    Wahadlo_B.ThermFlagSource[2] = 0.0;
    Wahadlo_B.ResetEncoders = 0.0;
  }

  /* parameters */
  Wahadlo_M->ModelData.defaultParam = ((real_T *)&Wahadlo_P);

  /* states (dwork) */
  Wahadlo_M->ModelData.dwork = ((void *) &Wahadlo_DW);
  (void) memset((void *)&Wahadlo_DW, 0,
                sizeof(DW_Wahadlo_T));
  Wahadlo_DW.Memory_PreviousInput = 0.0;
  Wahadlo_DW.Memory1_PreviousInput = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Wahadlo_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &Wahadlo_M->NonInlinedSFcns.sfcnInfo;
    Wahadlo_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(Wahadlo_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &Wahadlo_M->Sizes.numSampTimes);
    Wahadlo_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(Wahadlo_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,Wahadlo_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(Wahadlo_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(Wahadlo_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(Wahadlo_M));
    rtssSetStepSizePtr(sfcnInfo, &Wahadlo_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(Wahadlo_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Wahadlo_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Wahadlo_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &Wahadlo_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &Wahadlo_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &Wahadlo_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &Wahadlo_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &Wahadlo_M->solverInfoPtr);
  }

  Wahadlo_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)&Wahadlo_M->NonInlinedSFcns.childSFunctions[0], 0,
                  9*sizeof(SimStruct));
    Wahadlo_M->childSfunctions = (&Wahadlo_M->
      NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        Wahadlo_M->childSfunctions[i] =
          (&Wahadlo_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: Wahadlo/<S2>/Encoder (P1_Encoder) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/Encoder");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.Encoder_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/PWM (P1_PWM) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.Saturation;
          sfcnUPtrs[1] = &Wahadlo_B.Saturation[1];
          sfcnUPtrs[2] = &Wahadlo_B.Saturation[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/PWM");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.PWM_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/ResetEncoder (P1_ResetEncoder) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &Wahadlo_B.ResetSource[0];
          sfcnUPtrs[1] = &Wahadlo_B.ResetSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ResetSource[2];
          sfcnUPtrs[3] = &Wahadlo_B.ResetEncoders;
          sfcnUPtrs[4] = &Wahadlo_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 5);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 5);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ResetEncoder");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ResetEncoder_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/LimitFlag (P1_LimitFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.LimitFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.LimitFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.LimitFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.LimitFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitFlag");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/LimitFlag");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.LimitFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.LimitFlag_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/SetLimit (P1_SetLimit) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.LimitSource;
          sfcnUPtrs[1] = &Wahadlo_B.LimitSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.LimitSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.SetLimit));
        }
      }

      /* path info */
      ssSetModelName(rts, "SetLimit");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/SetLimit");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.SetLimit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.SetLimit_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/LimitSwitch (P1_Switch) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.LimitSwitch));
        }
      }

      /* path info */
      ssSetModelName(rts, "LimitSwitch");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/LimitSwitch");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.LimitSwitch_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.LimitSwitch_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/PWMPrescaler (P1_PWMPrescaler) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &Wahadlo_B.PWMPrescalerSource;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &Wahadlo_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/PWMPrescaler");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.PWMPrescaler_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/ResetSwitchFlag  (P1_ResetSwitchFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.ResetSwitchFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.ResetSwitchFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ResetSwitchFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ResetSwitchFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetSwitchFlag ");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ResetSwitchFlag ");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ResetSwitchFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ResetSwitchFlag_P2_Size);
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

    /* Level2 S-Function Block: Wahadlo/<S2>/ThermFlag  (P1_ThermFlag) */
    {
      SimStruct *rts = Wahadlo_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = Wahadlo_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &Wahadlo_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, Wahadlo_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &Wahadlo_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &Wahadlo_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &Wahadlo_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Wahadlo_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] = Wahadlo_B.ThermFlagSource;
          sfcnUPtrs[1] = &Wahadlo_B.ThermFlagSource[1];
          sfcnUPtrs[2] = &Wahadlo_B.ThermFlagSource[2];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *) Wahadlo_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "Wahadlo/Cart-Pendulum System/ThermFlag ");
      ssSetRTModel(rts,Wahadlo_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Wahadlo_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)Wahadlo_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)Wahadlo_P.ThermFlag_P2_Size);
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
  Wahadlo_M->Sizes.numContStates = (0);/* Number of continuous states */
  Wahadlo_M->Sizes.numY = (0);         /* Number of model outputs */
  Wahadlo_M->Sizes.numU = (0);         /* Number of model inputs */
  Wahadlo_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Wahadlo_M->Sizes.numSampTimes = (1); /* Number of sample times */
  Wahadlo_M->Sizes.numBlocks = (45);   /* Number of blocks */
  Wahadlo_M->Sizes.numBlockIO = (24);  /* Number of block outputs */
  Wahadlo_M->Sizes.numBlockPrms = (90);/* Sum of parameter "widths" */
  return Wahadlo_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
