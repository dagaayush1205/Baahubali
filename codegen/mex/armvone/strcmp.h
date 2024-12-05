/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * strcmp.h
 *
 * Code generation for function 'strcmp'
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
boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2],
                   const char_T b_data[], const int32_T b_size[2]);

boolean_T c_strcmp(const emlrtStack *sp, const char_T a_data[],
                   const int32_T a_size[2], real_T cmpLen);

/* End of code generation (strcmp.h) */
