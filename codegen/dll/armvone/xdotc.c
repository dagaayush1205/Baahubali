/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xdotc.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "xdotc.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : int n
 *                const double x[9]
 *                int ix0
 *                const double y[9]
 *                int iy0
 * Return Type  : double
 */
double xdotc(int n, const double x[9], int ix0, const double y[9], int iy0)
{
  double d;
  int i;
  int k;
  d = 0.0;
  i = (unsigned char)n;
  for (k = 0; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

/*
 * File trailer for xdotc.c
 *
 * [EOF]
 */
