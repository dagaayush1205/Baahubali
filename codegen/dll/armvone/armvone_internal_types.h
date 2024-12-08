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

#ifndef ARMVONE_INTERNAL_TYPES_H
#define ARMVONE_INTERNAL_TYPES_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"

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

#ifndef struct_emxArray_char_T_1x14
#define struct_emxArray_char_T_1x14
struct emxArray_char_T_1x14 {
  char data[14];
  int size[2];
};
#endif /* struct_emxArray_char_T_1x14 */
#ifndef typedef_emxArray_char_T_1x14
#define typedef_emxArray_char_T_1x14
typedef struct emxArray_char_T_1x14 emxArray_char_T_1x14;
#endif /* typedef_emxArray_char_T_1x14 */

#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct {
  emxArray_char_T_1x14 JointName;
  double JointPosition;
} b_struct_T;
#endif /* typedef_b_struct_T */

#ifndef typedef_b_rigidBodyTree
#define typedef_b_rigidBodyTree
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  d_robotics_manip_internal_Rigid *TreeInternal;
} b_rigidBodyTree;
#endif /* typedef_b_rigidBodyTree */

#endif
/* End of code generation (armvone_internal_types.h) */
