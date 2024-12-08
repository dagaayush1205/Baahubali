/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void diag(const emxArray_real_T *v, emxArray_real_T *d)
{
  const double *v_data;
  double *d_data;
  int u0;
  v_data = v->data;
  if ((v->size[0] == 1) && (v->size[1] == 1)) {
    u0 = d->size[0];
    d->size[0] = 1;
    emxEnsureCapacity_real_T(d, u0);
    d_data = d->data;
    d_data[0] = v_data[0];
  } else {
    int u1;
    u0 = v->size[0];
    u1 = v->size[1];
    if (u0 <= u1) {
      u1 = u0;
    }
    if (v->size[1] <= 0) {
      u1 = 0;
    }
    u0 = d->size[0];
    d->size[0] = u1;
    emxEnsureCapacity_real_T(d, u0);
    d_data = d->data;
    for (u0 = 0; u0 < u1; u0++) {
      d_data[u0] = v_data[u0 + v->size[0] * u0];
    }
  }
}

/* End of code generation (diag.c) */
