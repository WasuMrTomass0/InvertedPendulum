/*
 * P1_ExpDemo.h
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

#ifndef RTW_HEADER_P1_ExpDemo_h_
#define RTW_HEADER_P1_ExpDemo_h_
#include <string.h>
#include <stddef.h>
#include <math.h>
#ifndef P1_ExpDemo_COMMON_INCLUDES_
# define P1_ExpDemo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* P1_ExpDemo_COMMON_INCLUDES_ */

#include "P1_ExpDemo_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
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

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define P1_ExpDemo_rtModel             RT_MODEL_P1_ExpDemo_T

/* Block signals (auto storage) */
typedef struct {
  real_T Encoder[5];                   /* '<S2>/Encoder' */
  real_T Sum;                          /* '<S2>/Sum' */
  real_T Cart_pos;                     /* '<S7>/Gain3' */
  real_T MatrixGain;                   /* '<Root>/Matrix Gain' */
  real_T AngleScale;                   /* '<S2>/Angle Scale' */
  real_T PendPosOut;                   /* '<S1>/angle normalization' */
  real_T Pend_vel;                     /* '<S7>/Gain2' */
  real_T Cart_vel;                     /* '<S7>/Gain4' */
  real_T Sum_k[4];                     /* '<Root>/Sum' */
  real_T umax;                         /* '<S15>/umax' */
  real_T Fcn;                          /* '<S12>/Fcn' */
  real_T CtrlMode;                     /* '<Root>/Algorithm Selector2' */
  real_T Gain1;                        /* '<S3>/Gain1' */
  real_T Memory;                       /* '<S10>/Memory' */
  real_T Gain3;                        /* '<S3>/Gain3' */
  real_T Memory_o;                     /* '<S9>/Memory' */
  real_T Fcn_k;                        /* '<S5>/Fcn' */
  real_T CtrlSat;                      /* '<S5>/CtrlSat' */
  real_T PWM[3];                       /* '<S2>/PWM' */
  real_T Saturation[3];                /* '<S2>/Saturation' */
  real_T ResetEncoder[5];              /* '<S2>/ResetEncoder' */
  real_T ResetSource[3];               /* '<S2>/ResetSource' */
  real_T LimitFlag[3];                 /* '<S2>/LimitFlag' */
  real_T LimitFlagSource[3];           /* '<S2>/LimitFlagSource' */
  real_T LimitSource[3];               /* '<S2>/LimitSource' */
  real_T SetLimit[3];                  /* '<S2>/SetLimit' */
  real_T LimitSwitch[3];               /* '<S2>/LimitSwitch' */
  real_T PWMPrescaler;                 /* '<S2>/PWMPrescaler' */
  real_T PWMPrescalerSource;           /* '<S2>/PWMPrescalerSource' */
  real_T ResetSwitchFlag[3];           /* '<S2>/ResetSwitchFlag ' */
  real_T ResetSwitchFlagSource[3];     /* '<S2>/ResetSwitchFlagSource' */
  real_T ThermFlag[3];                 /* '<S2>/ThermFlag ' */
  real_T ThermFlagSource[3];           /* '<S2>/ThermFlagSource' */
  real_T Fcn_kz;                       /* '<S4>/Fcn' */
  real_T IntegratorGain;               /* '<S12>/Integrator Gain' */
  real_T ResetEncoders;                /* '<Root>/Reset Encoders' */
} B_P1_ExpDemo_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S7>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S7>/Memory1' */
  real_T Memory_PreviousInput_a;       /* '<S10>/Memory' */
  real_T Memory_PreviousInput_o;       /* '<S9>/Memory' */
  struct {
    void *LoggedData;
  } CartRef_Pos_PWORK;                 /* '<Root>/CartRef_Pos' */

  struct {
    void *LoggedData;
  } PendulumControlandStatesExperiment_PWORK;/* '<Root>/Pendulum  Control and States (Experiment)' */

  struct {
    void *LoggedData;
  } SoftLandingMonitor_PWORK;          /* '<S4>/Soft Landing Monitor' */

  int32_T clockTickCounter;            /* '<Root>/Algorithm Selector2' */
  boolean_T swing_Mode;                /* '<S15>/swing' */
} DW_P1_ExpDemo_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S12>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S12>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S10>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S9>/Integrator' */
} X_P1_ExpDemo_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S12>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S12>/Integrator' */
  real_T Integrator_CSTATE_m;          /* '<S10>/Integrator' */
  real_T Integrator_CSTATE_p;          /* '<S9>/Integrator' */
} XDot_P1_ExpDemo_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S12>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S12>/Integrator' */
  boolean_T Integrator_CSTATE_m;       /* '<S10>/Integrator' */
  boolean_T Integrator_CSTATE_p;       /* '<S9>/Integrator' */
} XDis_P1_ExpDemo_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S12>/Integrator' */
} PrevZCX_P1_ExpDemo_T;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            P1_ExpDemo_B
#define BlockIO                        B_P1_ExpDemo_T
#define rtX                            P1_ExpDemo_X
#define ContinuousStates               X_P1_ExpDemo_T
#define rtXdot                         P1_ExpDemo_XDot
#define StateDerivatives               XDot_P1_ExpDemo_T
#define tXdis                          P1_ExpDemo_XDis
#define StateDisabled                  XDis_P1_ExpDemo_T
#define rtP                            P1_ExpDemo_P
#define Parameters                     P_P1_ExpDemo_T
#define rtDWork                        P1_ExpDemo_DW
#define D_Work                         DW_P1_ExpDemo_T
#define rtPrevZCSigState               P1_ExpDemo_PrevZCX
#define PrevZCSigStates                PrevZCX_P1_ExpDemo_T

/* Parameters (auto storage) */
struct P_P1_ExpDemo_T_ {
  real_T RefCartPos_Amplitude;         /* Mask Parameter: RefCartPos_Amplitude
                                        * Referenced by:
                                        *   '<S6>/sawtooth'
                                        *   '<S6>/sine'
                                        *   '<S6>/square'
                                        */
  real_T PIDPend_D;                    /* Mask Parameter: PIDPend_D
                                        * Referenced by: '<S10>/Kd1'
                                        */
  real_T PIDCart_D;                    /* Mask Parameter: PIDCart_D
                                        * Referenced by: '<S9>/Kd1'
                                        */
  real_T RefCartPos_Frequency;         /* Mask Parameter: RefCartPos_Frequency
                                        * Referenced by:
                                        *   '<S6>/sawtooth'
                                        *   '<S6>/sine'
                                        *   '<S6>/square'
                                        */
  real_T ControllerPID_Friction;       /* Mask Parameter: ControllerPID_Friction
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T PIDPend_I;                    /* Mask Parameter: PIDPend_I
                                        * Referenced by: '<S10>/Ki'
                                        */
  real_T PIDCart_I;                    /* Mask Parameter: PIDCart_I
                                        * Referenced by: '<S9>/Ki'
                                        */
  real_T PIDPend_P;                    /* Mask Parameter: PIDPend_P
                                        * Referenced by: '<S10>/Kp'
                                        */
  real_T PIDCart_P;                    /* Mask Parameter: PIDCart_P
                                        * Referenced by: '<S9>/Kp'
                                        */
  real_T Softlandingarbiter_R;         /* Mask Parameter: Softlandingarbiter_R
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T RefCartPos_Sawtooth;          /* Mask Parameter: RefCartPos_Sawtooth
                                        * Referenced by: '<S6>/SawToothGain'
                                        */
  real_T RefCartPos_Sine;              /* Mask Parameter: RefCartPos_Sine
                                        * Referenced by: '<S6>/SineGain'
                                        */
  real_T RefCartPos_Square;            /* Mask Parameter: RefCartPos_Square
                                        * Referenced by: '<S6>/SquareGain'
                                        */
  real_T Sensors_T0;                   /* Mask Parameter: Sensors_T0
                                        * Referenced by:
                                        *   '<S7>/Gain2'
                                        *   '<S7>/Gain4'
                                        */
  real_T ControllerPID_T0;             /* Mask Parameter: ControllerPID_T0
                                        * Referenced by:
                                        *   '<S9>/Kd1'
                                        *   '<S10>/Kd1'
                                        */
  real_T ControllerPID_Umax;           /* Mask Parameter: ControllerPID_Umax
                                        * Referenced by: '<S3>/CtrlSat1'
                                        */
  real_T CoulombViscousFriction_gain;  /* Mask Parameter: CoulombViscousFriction_gain
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T CoulombViscousFriction_gain_h;/* Mask Parameter: CoulombViscousFriction_gain_h
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Softlandingarbiter_k;         /* Mask Parameter: Softlandingarbiter_k
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T CoulombViscousFriction_offset;/* Mask Parameter: CoulombViscousFriction_offset
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T AlfaNormalization_pos;        /* Mask Parameter: AlfaNormalization_pos
                                        * Referenced by: '<S1>/pos'
                                        */
  real_T Swingingcontroller_umax;      /* Mask Parameter: Swingingcontroller_umax
                                        * Referenced by: '<S15>/umax'
                                        */
  real_T Linearcontroller1_umax1;      /* Mask Parameter: Linearcontroller1_umax1
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Nottoescapewatchdog_umax2;    /* Mask Parameter: Nottoescapewatchdog_umax2
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T CtrlSat_UpperSat;             /* Expression: 1
                                        * Referenced by: '<S4>/CtrlSat'
                                        */
  real_T CtrlSat_LowerSat;             /* Expression: -1
                                        * Referenced by: '<S4>/CtrlSat'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T _Threshold;                   /* Expression: 0
                                        * Referenced by: '<S4>/3'
                                        */
  real_T _Threshold_p;                 /* Expression: 0
                                        * Referenced by: '<S4>/2'
                                        */
  real_T Encoder_P1_Size[2];           /* Computed Parameter: Encoder_P1_Size
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T Encoder_P1;                   /* Expression: BaseAddress
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T Encoder_P2_Size[2];           /* Computed Parameter: Encoder_P2_Size
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T Encoder_P2;                   /* Expression: T0
                                        * Referenced by: '<S2>/Encoder'
                                        */
  real_T Encoder1024PPR_Gain;          /* Expression: 1
                                        * Referenced by: '<S2>/Encoder 1024 PPR'
                                        */
  real_T PosCartScale_Gain;            /* Expression: 5.7053e-005
                                        * Referenced by: '<S2>/PosCart Scale'
                                        */
  real_T CartOffset_Value;             /* Expression: -1.86/2
                                        * Referenced by: '<S2>/Cart Offset'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T Const1_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/Const1'
                                        */
  real_T Const2_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/Const2'
                                        */
  real_T Const3_Value;                 /* Expression: 0
                                        * Referenced by: '<S6>/Const3'
                                        */
  real_T MatrixGain_Gain[4];           /* Expression: [0 0 1 0]
                                        * Referenced by: '<Root>/Matrix Gain'
                                        */
  real_T pi_Value;                     /* Expression: pi
                                        * Referenced by: '<S1>/pi'
                                        */
  real_T AngleScale_Gain;              /* Expression: 2*pi/4096
                                        * Referenced by: '<S2>/Angle Scale'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S7>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T Control0_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Control = 0'
                                        */
  real_T one_Value;                    /* Expression: 1
                                        * Referenced by: '<S14>/one '
                                        */
  real_T swing_OnVal;                  /* Expression: eps
                                        * Referenced by: '<S15>/swing'
                                        */
  real_T swing_OffVal;                 /* Expression: eps
                                        * Referenced by: '<S15>/swing'
                                        */
  real_T swing_YOn;                    /* Expression: 1
                                        * Referenced by: '<S15>/swing'
                                        */
  real_T swing_YOff;                   /* Expression: -1
                                        * Referenced by: '<S15>/swing'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: K(1)
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  real_T Gain2_Gain;                   /* Expression: K(2)
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T SaturationCartError_UpperSat; /* Expression: 0.1
                                        * Referenced by: '<S12>/Saturation Cart Error'
                                        */
  real_T SaturationCartError_LowerSat; /* Expression: -0.1
                                        * Referenced by: '<S12>/Saturation Cart Error'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: K(3)
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: K(4)
                                        * Referenced by: '<S12>/Gain4'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: 0.2
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: -0.2
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T _Threshold_b;                 /* Expression: 0
                                        * Referenced by: '<S4>/4'
                                        */
  real_T AlgorithmSelector2_Amp;       /* Expression: 1
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  real_T AlgorithmSelector2_Period;    /* Computed Parameter: AlgorithmSelector2_Period
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  real_T AlgorithmSelector2_Duty;      /* Computed Parameter: AlgorithmSelector2_Duty
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  real_T AlgorithmSelector2_PhaseDelay;/* Expression: 0
                                        * Referenced by: '<Root>/Algorithm Selector2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Integrator_IC_a;              /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_UpperSat_l;        /* Expression: 1
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_LowerSat_k;        /* Expression: -1
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Memory_X0_p;                  /* Expression: 0
                                        * Referenced by: '<S10>/Memory'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Integrator_UpperSat_b;        /* Expression: 1
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Integrator_LowerSat_kg;       /* Expression: -1
                                        * Referenced by: '<S9>/Integrator'
                                        */
  real_T Memory_X0_m;                  /* Expression: 0
                                        * Referenced by: '<S9>/Memory'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T CtrlSat_UpperSat_o;           /* Expression: 0.4
                                        * Referenced by: '<S5>/CtrlSat'
                                        */
  real_T CtrlSat_LowerSat_l;           /* Expression: -0.4
                                        * Referenced by: '<S5>/CtrlSat'
                                        */
  real_T PWM_P1_Size[2];               /* Computed Parameter: PWM_P1_Size
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T PWM_P1;                       /* Expression: BaseAddress
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T PWM_P2_Size[2];               /* Computed Parameter: PWM_P2_Size
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T PWM_P2;                       /* Expression: T0
                                        * Referenced by: '<S2>/PWM'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T ResetEncoder_P1_Size[2];      /* Computed Parameter: ResetEncoder_P1_Size
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */
  real_T ResetEncoder_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2_Size[2];      /* Computed Parameter: ResetEncoder_P2_Size
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */
  real_T ResetEncoder_P2;              /* Expression: T0
                                        * Referenced by: '<S2>/ResetEncoder'
                                        */
  real_T ResetSource_Value[3];         /* Expression: [1 1 1 ]
                                        * Referenced by: '<S2>/ResetSource'
                                        */
  real_T LimitFlag_P1_Size[2];         /* Computed Parameter: LimitFlag_P1_Size
                                        * Referenced by: '<S2>/LimitFlag'
                                        */
  real_T LimitFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S2>/LimitFlag'
                                        */
  real_T LimitFlag_P2_Size[2];         /* Computed Parameter: LimitFlag_P2_Size
                                        * Referenced by: '<S2>/LimitFlag'
                                        */
  real_T LimitFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S2>/LimitFlag'
                                        */
  real_T LimitFlagSource_Value[3];     /* Expression: [0 0 0]
                                        * Referenced by: '<S2>/LimitFlagSource'
                                        */
  real_T LimitSource_Value[3];         /* Expression: [129 116 300]
                                        * Referenced by: '<S2>/LimitSource'
                                        */
  real_T SetLimit_P1_Size[2];          /* Computed Parameter: SetLimit_P1_Size
                                        * Referenced by: '<S2>/SetLimit'
                                        */
  real_T SetLimit_P1;                  /* Expression: BaseAddress
                                        * Referenced by: '<S2>/SetLimit'
                                        */
  real_T SetLimit_P2_Size[2];          /* Computed Parameter: SetLimit_P2_Size
                                        * Referenced by: '<S2>/SetLimit'
                                        */
  real_T SetLimit_P2;                  /* Expression: T0
                                        * Referenced by: '<S2>/SetLimit'
                                        */
  real_T LimitSwitch_P1_Size[2];       /* Computed Parameter: LimitSwitch_P1_Size
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */
  real_T LimitSwitch_P1;               /* Expression: BaseAddress
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2_Size[2];       /* Computed Parameter: LimitSwitch_P2_Size
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */
  real_T LimitSwitch_P2;               /* Expression: T0
                                        * Referenced by: '<S2>/LimitSwitch'
                                        */
  real_T PWMPrescaler_P1_Size[2];      /* Computed Parameter: PWMPrescaler_P1_Size
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P1;              /* Expression: BaseAddress
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2_Size[2];      /* Computed Parameter: PWMPrescaler_P2_Size
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */
  real_T PWMPrescaler_P2;              /* Expression: T0
                                        * Referenced by: '<S2>/PWMPrescaler'
                                        */
  real_T PWMPrescalerSource_Value;     /* Expression: 0
                                        * Referenced by: '<S2>/PWMPrescalerSource'
                                        */
  real_T ResetSwitchFlag_P1_Size[2];   /* Computed Parameter: ResetSwitchFlag_P1_Size
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P1;           /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2_Size[2];   /* Computed Parameter: ResetSwitchFlag_P2_Size
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlag_P2;           /* Expression: T0
                                        * Referenced by: '<S2>/ResetSwitchFlag '
                                        */
  real_T ResetSwitchFlagSource_Value[3];/* Expression: [ 0 0 0 ]
                                         * Referenced by: '<S2>/ResetSwitchFlagSource'
                                         */
  real_T ThermFlag_P1_Size[2];         /* Computed Parameter: ThermFlag_P1_Size
                                        * Referenced by: '<S2>/ThermFlag '
                                        */
  real_T ThermFlag_P1;                 /* Expression: BaseAddress
                                        * Referenced by: '<S2>/ThermFlag '
                                        */
  real_T ThermFlag_P2_Size[2];         /* Computed Parameter: ThermFlag_P2_Size
                                        * Referenced by: '<S2>/ThermFlag '
                                        */
  real_T ThermFlag_P2;                 /* Expression: T0
                                        * Referenced by: '<S2>/ThermFlag '
                                        */
  real_T ThermFlagSource_Value[3];     /* Expression: [1 1 1]
                                        * Referenced by: '<S2>/ThermFlagSource'
                                        */
  real_T IntegratorGain_Gain;          /* Expression: 0.0
                                        * Referenced by: '<S12>/Integrator Gain'
                                        */
  uint8_T ResetEncoders_CurrentSetting;/* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_P1_ExpDemo_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
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
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    real_T odeY[4];
    real_T odeF[6][4];
    ODE5_IntgData intgData;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
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
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

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
    void *timingData;
    real_T *varNextHitTimesList;
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
extern P_P1_ExpDemo_T P1_ExpDemo_P;

/* Block signals (auto storage) */
extern B_P1_ExpDemo_T P1_ExpDemo_B;

/* Continuous states (auto storage) */
extern X_P1_ExpDemo_T P1_ExpDemo_X;

/* Block states (auto storage) */
extern DW_P1_ExpDemo_T P1_ExpDemo_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_P1_ExpDemo_T P1_ExpDemo_PrevZCX;

/* Model entry point functions */
extern void P1_ExpDemo_initialize(void);
extern void P1_ExpDemo_output(void);
extern void P1_ExpDemo_update(void);
extern void P1_ExpDemo_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern P1_ExpDemo_rtModel *P1_ExpDemo(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_P1_ExpDemo_T *const P1_ExpDemo_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/LimitFlagGain' : Unused code path elimination
 * Block '<S2>/LimitSwitchGain' : Unused code path elimination
 * Block '<S2>/PWMGain' : Unused code path elimination
 * Block '<S2>/PWMPrescalerGain' : Unused code path elimination
 * Block '<S2>/ResetEncoderGain' : Unused code path elimination
 * Block '<S2>/ResetSwitchFlagGain' : Unused code path elimination
 * Block '<S2>/SetLimitGain' : Unused code path elimination
 * Block '<S2>/ThermFlagGain' : Unused code path elimination
 */

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
 * '<Root>' : 'P1_ExpDemo'
 * '<S1>'   : 'P1_ExpDemo/Alfa Normalization'
 * '<S2>'   : 'P1_ExpDemo/Cart-Pendulum System'
 * '<S3>'   : 'P1_ExpDemo/Controller PID'
 * '<S4>'   : 'P1_ExpDemo/Controller Swing-up'
 * '<S5>'   : 'P1_ExpDemo/Penalty'
 * '<S6>'   : 'P1_ExpDemo/Ref.Cart.Pos.'
 * '<S7>'   : 'P1_ExpDemo/Sensors'
 * '<S8>'   : 'P1_ExpDemo/Controller PID/Coulomb & Viscous Friction'
 * '<S9>'   : 'P1_ExpDemo/Controller PID/PIDCart'
 * '<S10>'  : 'P1_ExpDemo/Controller PID/PIDPend'
 * '<S11>'  : 'P1_ExpDemo/Controller Swing-up/Coulomb & Viscous Friction'
 * '<S12>'  : 'P1_ExpDemo/Controller Swing-up/Linear controller1'
 * '<S13>'  : 'P1_ExpDemo/Controller Swing-up/Not to escape watchdog'
 * '<S14>'  : 'P1_ExpDemo/Controller Swing-up/Soft landing arbiter'
 * '<S15>'  : 'P1_ExpDemo/Controller Swing-up/Swinging controller'
 */
#endif                                 /* RTW_HEADER_P1_ExpDemo_h_ */
