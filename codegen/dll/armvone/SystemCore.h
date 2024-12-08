/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

/* Include files */
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void SystemCore_step(inverseKinematics *obj, const double varargin_2[16],
                     const b_struct_T varargin_4[6],
                     emxArray_struct_T *varargout_1);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (SystemCore.h) */
