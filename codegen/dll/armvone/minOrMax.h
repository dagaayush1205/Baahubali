/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: minOrMax.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef MINORMAX_H
#define MINORMAX_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double binary_expand_op_10(const emxArray_real_T *in1,
                           const emxArray_real_T *in2, int *out2);

double maximum(const emxArray_real_T *x, int *idx);

double minimum(const emxArray_real_T *x, int *idx);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for minOrMax.h
 *
 * [EOF]
 */
