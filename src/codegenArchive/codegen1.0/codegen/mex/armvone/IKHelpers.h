/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * IKHelpers.h
 *
 * Code generation for function 'IKHelpers'
 *
 */

#pragma once

/* Include files */
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
real_T IKHelpers_computeCost(const emlrtStack *sp, const emxArray_real_T *x,
                             c_robotics_manip_internal_IKExt *args,
                             real_T W[36], emxArray_real_T *Jac,
                             c_robotics_manip_internal_IKExt **b_args);

real_T IKHelpers_evaluateSolution(const emlrtStack *sp,
                                  const c_robotics_manip_internal_IKExt *args);

/* End of code generation (IKHelpers.h) */
