/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xorgqr.h
 *
 * Code generation for function 'xorgqr'
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
void xorgqr(const emlrtStack *sp, int32_T m, int32_T n, int32_T k,
            emxArray_real_T *A, int32_T lda, const emxArray_real_T *tau);

/* End of code generation (xorgqr.h) */
