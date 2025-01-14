/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xnrm2.h
 *
 * Code generation for function 'xnrm2'
 *
 */

#ifndef XNRM2_H
#define XNRM2_H

/* Include files */
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
/* End of code generation (xnrm2.h) */
