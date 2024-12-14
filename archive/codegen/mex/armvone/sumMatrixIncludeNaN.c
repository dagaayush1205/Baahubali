/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T b_sumColumnB(const real_T x[4])
{
  return ((x[0] + x[1]) + x[2]) + x[3];
}

real_T sumColumnB(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

/* End of code generation (sumMatrixIncludeNaN.c) */
