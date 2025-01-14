/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xzlangeM.c
 *
 * Code generation for function 'xzlangeM'
 *
 */

/* Include files */
#include "xzlangeM.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double b_xzlangeM(const emxArray_real_T *x)
{
  const double *x_data;
  double y;
  boolean_T b;
  boolean_T b1;
  x_data = x->data;
  y = 0.0;
  b = (x->size[0] == 0);
  b1 = (x->size[1] == 0);
  if ((!b) && (!b1)) {
    int k;
    k = 0;
    int exitg1;
    int i;
    do {
      exitg1 = 0;
      i = x->size[0] * x->size[1];
      if (k <= i - 1) {
        double absxk;
        absxk = fabs(x_data[k]);
        if (rtIsNaN(absxk)) {
          y = rtNaN;
          exitg1 = 1;
        } else {
          if (absxk > y) {
            y = absxk;
          }
          k++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return y;
}

double xzlangeM(const double x[9])
{
  double y;
  int k;
  boolean_T exitg1;
  y = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 9)) {
    double absxk;
    absxk = fabs(x[k]);
    if (rtIsNaN(absxk)) {
      y = rtNaN;
      exitg1 = true;
    } else {
      if (absxk > y) {
        y = absxk;
      }
      k++;
    }
  }
  return y;
}

/* End of code generation (xzlangeM.c) */
