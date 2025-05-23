/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * any.c
 *
 * Code generation for function 'any'
 *
 */

/* Include files */
#include "any.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T any(const emxArray_boolean_T *x)
{
  int ix;
  const boolean_T *x_data;
  boolean_T exitg1;
  boolean_T y;
  x_data = x->data;
  y = false;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    if (x_data[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

/* End of code generation (any.c) */
