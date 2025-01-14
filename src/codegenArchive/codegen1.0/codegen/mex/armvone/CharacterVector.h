/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * CharacterVector.h
 *
 * Code generation for function 'CharacterVector'
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
void CharacterVector_setVector(const emlrtStack *sp,
                               c_robotics_manip_internal_Chara *obj,
                               const char_T vec_data[],
                               const int32_T vec_size[2]);

/* End of code generation (CharacterVector.h) */
