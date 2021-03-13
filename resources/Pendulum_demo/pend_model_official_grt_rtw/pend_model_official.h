/*
 * pend_model_official.h
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

#ifndef RTW_HEADER_pend_model_official_h_
#define RTW_HEADER_pend_model_official_h_
#include <string.h>
#include <stddef.h>
#include <float.h>
#ifndef pend_model_official_COMMON_INCLUDES_
# define pend_model_official_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* pend_model_official_COMMON_INCLUDES_ */

#include "pend_model_official_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Encoder[5];                   /* '<S1>/Encoder' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T CartVel;                      /* '<Root>/Derivative' */
  real_T AngleScale;                   /* '<S1>/Angle Scale' */
  real_T PendVel;                      /* '<Root>/Derivative1' */
  real_T Step;                         /* '<Root>/Step' */
  real_T Step1;                        /* '<Root>/Step1' */
  real_T PWM[3];                       /* '<S1>/PWM' */
  real_T Saturation[3];                /* '<S1>/Saturation' */
  real_T ResetEncoder[5];              /* '<S1>/ResetEncoder' */
  real_T ResetSource[3];               /* '<S1>/ResetSource' */
  real_T LimitFlag[3];                 /* '<S1>/LimitFlag' */
  real_T LimitFlagSource[3];           /* '<S1>/LimitFlagSource' */
  real_T LimitSource[3];               /* '<S1>/LimitSource' */
  real_T SetLimit[3];                  /* '<S1>/SetLimit' */
  real_T LimitSwitch[3];               /* '<S1>/LimitSwitch' */
  real_T PWMPrescaler;                 /* '<S1>/PWMPrescaler' */
  real_T PWMPrescalerSource;           /* '<S1>/PWMPrescalerSource' */
  real_T ResetSwitchFlag[3];           /* '<S1>/ResetSwitchFlag ' */
  real_T ResetSwitchFlagSource[3];     /* '<S1>/ResetSwitchFlagSource' */
  real_T ThermFlag[3];                 /* '<S1>/ThermFlag ' */
  real_T ThermFlagSource[3];           /* '<S1>/ThermFlagSource' */
} B_pend_model_official_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  real_T TimeStampA_c;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeA_h;               /* '<Root>/Derivative1' */
  real_T TimeStampB_d;                 /* '<Root>/Derivative1' */
  real_T LastUAtTimeB_p;               /* '<Root>/Derivative1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */
} DW_pend_model_official_T;

/* Parameters (auto storage) */
struct P_pend_model_official_T_ {
  real_T Encoder_P1_Size[2];           /* Computed Parameter: Encoder_P1_Size
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Encoder_P1;                   /* Expression: BaseAddress
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Encoder_P2_Size[2];           /* Computed Parameter: Encoder_P2_Size
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Encoder_P2;                   /* Expression: T0
                                        * Referenced by: '<S1>/Encoder'
                                        */
  real_T Encoder500PPR_Gain;           /* Expression: 1
                                        * Referenced by: '<S1>/Encoder 500PPR'
                                        */
  real_T PosCartScale_Gain;            /* Expression: 5.7053e-005
                                        * Referenced by: '<S1>/PosCart Scale'
                                        */
  real_T CartOffset_Value;             /* Expression: -0.55
                                        * Referenced by: '<S1>/Cart Offset'
                                        */
  real_T AngleScale_Gain;              /* Expression: 2*pi/4096
                                        * Referenced by: '<S1>/Angle Scale'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0.1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 0.01
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 1
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T PWM_P1_Size[2];               /* Computed Parameter: PWM_P1_Size
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T PWM_P1;                       /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T PWM_P2_Size[2];               /* Computed Parameter: PWM_P2_Size
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T PWM_P2;                       /* Expression: T0
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T ResetEncoder_P1_Size[2];      /* Computed Parameter: ResetEncoder_P1_Size
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */
  real_T ResetEncoder_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2_Size[2];      /* Computed Parameter: ResetEncoder_P2_Size
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2;              /* Expression: T0
                                        * Referenced by: '<S1>/ResetEncoder'
                                        */
  real_T ResetSource_Value[3];         /* Expression: [0 0 0 ]
                                        * Referenced by: '<S1>/ResetSource'
                                        */
  real_T LimitFlag_P1_Size[2];         /* Computed Parameter: LimitFlag_P1_Size
                                        * Referenced by: '<S1>/LimitFlag'
                                        */
  real_T LimitFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitFlag'
                                        */
  real_T LimitFlag_P2_Size[2];         /* Computed Parameter: LimitFlag_P2_Size
                                        * Referenced by: '<S1>/LimitFlag'
                                        */
  real_T LimitFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S1>/LimitFlag'
                                        */
  real_T LimitFlagSource_Value[3];     /* Expression: [0 0 0]
                                        * Referenced by: '<S1>/LimitFlagSource'
                                        */
  real_T LimitSource_Value[3];         /* Expression: [129 116 300]
                                        * Referenced by: '<S1>/LimitSource'
                                        */
  real_T SetLimit_P1_Size[2];          /* Computed Parameter: SetLimit_P1_Size
                                        * Referenced by: '<S1>/SetLimit'
                                        */
  real_T SetLimit_P1;                  /* Expression: BaseAddress
                                        * Referenced by: '<S1>/SetLimit'
                                        */
  real_T SetLimit_P2_Size[2];          /* Computed Parameter: SetLimit_P2_Size
                                        * Referenced by: '<S1>/SetLimit'
                                        */
  real_T SetLimit_P2;                  /* Expression: T0
                                        * Referenced by: '<S1>/SetLimit'
                                        */
  real_T LimitSwitch_P1_Size[2];       /* Computed Parameter: LimitSwitch_P1_Size
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */
  real_T LimitSwitch_P1;               /* Expression: BaseAddress
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2_Size[2];       /* Computed Parameter: LimitSwitch_P2_Size
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2;               /* Expression: T0
                                        * Referenced by: '<S1>/LimitSwitch'
                                        */
  real_T PWMPrescaler_P1_Size[2];      /* Computed Parameter: PWMPrescaler_P1_Size
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2_Size[2];      /* Computed Parameter: PWMPrescaler_P2_Size
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2;              /* Expression: T0
                                        * Referenced by: '<S1>/PWMPrescaler'
                                        */
  real_T PWMPrescalerSource_Value;     /* Expression: 0
                                        * Referenced by: '<S1>/PWMPrescalerSource'
                                        */
  real_T ResetSwitchFlag_P1_Size[2];   /* Computed Parameter: ResetSwitchFlag_P1_Size
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P1;           /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2_Size[2];   /* Computed Parameter: ResetSwitchFlag_P2_Size
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2;           /* Expression: T0
                                        * Referenced by: '<S1>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlagSource_Value[3];/* Expression: [ 0 0 0 ]
                                         * Referenced by: '<S1>/ResetSwitchFlagSource'
                                         */
  real_T ThermFlag_P1_Size[2];         /* Computed Parameter: ThermFlag_P1_Size
                                        * Referenced by: '<S1>/ThermFlag '
                                        */
  real_T ThermFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S1>/ThermFlag '
                                        */
  real_T ThermFlag_P2_Size[2];         /* Computed Parameter: ThermFlag_P2_Size
                                        * Referenced by: '<S1>/ThermFlag '
                                        */
  real_T ThermFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S1>/ThermFlag '
                                        */
  real_T ThermFlagSource_Value[3];     /* Expression: [1 1 1]
                                        * Referenced by: '<S1>/ThermFlagSource'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pend_model_official_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[9];
    SimStruct *childSFunctionPtrs[9];
    struct _ssBlkInfo2 blkInfo2[9];
    struct _ssSFcnModelMethods2 methods2[9];
    struct _ssSFcnModelMethods3 methods3[9];
    struct _ssStatesInfo2 statesInfo2[9];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[5];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[3];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn8;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_pend_model_official_T pend_model_official_P;

/* Block signals (auto storage) */
extern B_pend_model_official_T pend_model_official_B;

/* Block states (auto storage) */
extern DW_pend_model_official_T pend_model_official_DW;

/* Model entry point functions */
extern void pend_model_official_initialize(void);
extern void pend_model_official_step(void);
extern void pend_model_official_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pend_model_official_T *const pend_model_official_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'pend_model_official'
 * '<S1>'   : 'pend_model_official/Cart-Pendulum System'
 */
#endif                                 /* RTW_HEADER_pend_model_official_h_ */
