/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xnrm2.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef XNRM2_H
#define XNRM2_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_xnrm2(int n, const emxArray_real_T *x, int ix0);

double c_xnrm2(const double x[3]);

double xnrm2(int n, const double x[9], int ix0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xnrm2.h
 *
 * [EOF]
 */
