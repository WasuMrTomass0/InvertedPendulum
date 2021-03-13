/*
 * P1_ExpDemo_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&P1_ExpDemo_B.Encoder[0]), 0, 0, 71 }
  ,

  { (char_T *)(&P1_ExpDemo_DW.Memory_PreviousInput), 0, 0, 4 },

  { (char_T *)(&P1_ExpDemo_DW.CartRef_Pos_PWORK.LoggedData), 11, 0, 3 },

  { (char_T *)(&P1_ExpDemo_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&P1_ExpDemo_DW.swing_Mode), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&P1_ExpDemo_P.RefCartPos_Amplitude), 0, 0, 154 },

  { (char_T *)(&P1_ExpDemo_P.ResetEncoders_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] P1_ExpDemo_dt.h */
