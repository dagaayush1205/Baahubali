/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xaxpy.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef XAXPY_H
#define XAXPY_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0);

void c_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0);

void d_xaxpy(double a, const double x[9], int ix0, double y[3]);

void e_xaxpy(double a, const double x[3], double y[9], int iy0);

void xaxpy(int n, double a, int ix0, double y[9], int iy0);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xaxpy.h
 *
 * [EOF]
 */
