/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * trvec2tform.c
 *
 * Code generation for function 'trvec2tform'
 *
 */

/* Include files */
#include "trvec2tform.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void trvec2tform(const real_T t[3], real_T H[16])
{
  memset(&H[0], 0, 16U * sizeof(real_T));
  H[0] = 1.0;
  H[5] = 1.0;
  H[10] = 1.0;
  H[15] = 1.0;
  H[12] = t[0];
  H[13] = t[1];
  H[14] = t[2];
}

/* End of code generation (trvec2tform.c) */
