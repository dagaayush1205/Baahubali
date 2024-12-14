/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * complexTimes.c
 *
 * Code generation for function 'complexTimes'
 *
 */

/* Include files */
#include "complexTimes.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
real_T rescale(real_T *re, real_T *im)
{
  real_T absim;
  real_T scale;
  scale = muDoubleScalarAbs(*re);
  absim = muDoubleScalarAbs(*im);
  if (scale > absim) {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }
    *im /= scale;
  } else if (absim > scale) {
    *re /= absim;
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
    scale = absim;
  } else {
    if (*re < 0.0) {
      *re = -1.0;
    } else {
      *re = 1.0;
    }
    if (*im < 0.0) {
      *im = -1.0;
    } else {
      *im = 1.0;
    }
  }
  return scale;
}

/* End of code generation (complexTimes.c) */
