/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * assertCompatibleDims.c
 *
 * Code generation for function 'assertCompatibleDims'
 *
 */

/* Include files */
#include "assertCompatibleDims.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo sb_emlrtRTEI = {
    13,                     /* lineNo */
    27,                     /* colNo */
    "assertCompatibleDims", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/coder/coder/lib/+coder/+internal/"
    "assertCompatibleDims.m" /* pName */
};

/* Function Definitions */
void assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                          const emxArray_real_T *y)
{
  if ((x->size[0] != 1) && (y->size[0] != 1) && (x->size[0] != y->size[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &sb_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
}

/* End of code generation (assertCompatibleDims.c) */
