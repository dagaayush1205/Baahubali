/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xzlascl.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef XZLASCL_H
#define XZLASCL_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_xzlascl(double cfrom, double cto, double A[3]);

void c_xzlascl(double cfrom, double cto, int m, int n, emxArray_real_T *A,
               int lda);

void d_xzlascl(double cfrom, double cto, int m, emxArray_real_T *A);

void xzlascl(double cfrom, double cto, double A[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for xzlascl.h
 *
 * [EOF]
 */
