/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone.h
 *
 * Code generation for function 'armvone'
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
void armvone(const emlrtStack *sp, const real_T q0[6], const real_T pos[3],
             real_T vone_data[], int32_T vone_size[2]);

/* End of code generation (armvone.h) */
