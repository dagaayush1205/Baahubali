/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_mexutil.h
 *
 * Code generation for function 'armvone_mexutil'
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
void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId, char_T y[14]);

const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *m1,
                         const mxArray *m2, emlrtMCInfo *location);

void emlrt_marshallIn(const emlrtStack *sp,
                      const mxArray *a__output_of_sprintf_,
                      const char_T *identifier, char_T y[14]);

void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                        const emlrtMsgIdentifier *msgId, char_T ret[14]);

/* End of code generation (armvone_mexutil.h) */
