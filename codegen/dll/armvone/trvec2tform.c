/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: trvec2tform.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "trvec2tform.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const double t[3]
 *                double H[16]
 * Return Type  : void
 */
void trvec2tform(const double t[3], double H[16])
{
  memset(&H[0], 0, 16U * sizeof(double));
  H[0] = 1.0;
  H[5] = 1.0;
  H[10] = 1.0;
  H[15] = 1.0;
  H[12] = t[0];
  H[13] = t[1];
  H[14] = t[2];
}

/*
 * File trailer for trvec2tform.c
 *
 * [EOF]
 */
