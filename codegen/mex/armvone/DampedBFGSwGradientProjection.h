/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * DampedBFGSwGradientProjection.h
 *
 * Code generation for function 'DampedBFGSwGradientProjection'
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
c_robotics_core_internal_NLPSol c_DampedBFGSwGradientProjection(
    const emlrtStack *sp, c_robotics_core_internal_Damped *obj,
    emxArray_real_T *xSol, real_T *err, real_T *iter);

/* End of code generation (DampedBFGSwGradientProjection.h) */
