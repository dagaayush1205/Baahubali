/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
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
void b_xaxpy(real_T a, const real_T x[9], int32_T ix0, real_T y[3]);

void c_xaxpy(real_T a, const real_T x[3], real_T y[9], int32_T iy0);

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0);

/* End of code generation (xaxpy.h) */
