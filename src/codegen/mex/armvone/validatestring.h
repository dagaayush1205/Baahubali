/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * validatestring.h
 *
 * Code generation for function 'validatestring'
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
int32_T get_match(const emlrtStack *sp, const char_T str_data[],
                  const int32_T str_size[2], char_T match_data[],
                  int32_T match_size[2]);

/* End of code generation (validatestring.h) */
