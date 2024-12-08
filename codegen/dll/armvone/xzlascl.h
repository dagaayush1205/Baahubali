/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xzlascl.h
 *
 * Code generation for function 'xzlascl'
 *
 */

#ifndef XZLASCL_H
#define XZLASCL_H

/* Include files */
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
/* End of code generation (xzlascl.h) */
