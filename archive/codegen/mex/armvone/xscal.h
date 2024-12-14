/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xscal.h
 *
 * Code generation for function 'xscal'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_xscal(const emlrtStack *sp, real_T a, real_T x[9], int32_T ix0);

void c_xscal(const emlrtStack *sp, real_T x[9], int32_T ix0);

void d_xscal(real_T a, real_T x[3]);

void xscal(const emlrtStack *sp, int32_T n, real_T a, real_T x[9], int32_T ix0);

/* End of code generation (xscal.h) */
