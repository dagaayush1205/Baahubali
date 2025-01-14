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

#pragma once

/* Include files */
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void SystemCore_step(const emlrtStack *sp, inverseKinematics *obj,
                     const real_T varargin_2[16],
                     const b_struct_T varargin_4[5],
                     emxArray_struct_T *varargout_1);

/* End of code generation (SystemCore.h) */
