/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * eml_qr.h
 *
 * Code generation for function 'eml_qr'
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
void eml_qr(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *Q,
            emxArray_real_T *R, emxArray_int32_T *E);

/* End of code generation (eml_qr.h) */
