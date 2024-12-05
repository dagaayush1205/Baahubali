/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: SystemCore.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

/* Include Files */
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
                     const struct_T varargin_4[6],
                     emxArray_struct0_T *varargout_1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for SystemCore.h
 *
 * [EOF]
 */
