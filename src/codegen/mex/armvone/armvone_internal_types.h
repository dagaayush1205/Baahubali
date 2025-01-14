/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_internal_types.h
 *
 * Code generation for function 'armvone'
 *
 */

#pragma once

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef c_enum_c_robotics_core_internal
#define c_enum_c_robotics_core_internal
enum c_robotics_core_internal_NLPSol
{
  LocalMinimumFound = 1, /* Default value */
  IterationLimitExceeded,
  TimeLimitExceeded,
  StepSizeBelowMinimum,
  ChangeInErrorBelowMinimum,
  SearchDirectionInvalid,
  HessianNotPositiveSemidefinite,
  TrustRegionRadiusBelowMinimum
};
#endif /* c_enum_c_robotics_core_internal */
#ifndef c_typedef_c_robotics_core_inter
#define c_typedef_c_robotics_core_inter
typedef enum c_robotics_core_internal_NLPSol c_robotics_core_internal_NLPSol;
#endif /* c_typedef_c_robotics_core_inter */

#ifndef struct_emxArray_char_T_1x15
#define struct_emxArray_char_T_1x15
struct emxArray_char_T_1x15 {
  char_T data[15];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x15 */
#ifndef typedef_emxArray_char_T_1x15
#define typedef_emxArray_char_T_1x15
typedef struct emxArray_char_T_1x15 emxArray_char_T_1x15;
#endif /* typedef_emxArray_char_T_1x15 */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  emxArray_char_T_1x15 JointName;
  real_T JointPosition;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_b_rigidBodyTree
#define typedef_b_rigidBodyTree
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  d_robotics_manip_internal_Rigid *TreeInternal;
} b_rigidBodyTree;
#endif /* typedef_b_rigidBodyTree */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (armvone_internal_types.h) */
