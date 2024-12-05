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
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo rb_emlrtRTEI = {
    102,                                                          /* lineNo */
    19,                                                           /* colNo */
    "diag",                                                       /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

static emlrtRTEInfo qh_emlrtRTEI = {
    100,                                                          /* lineNo */
    5,                                                            /* colNo */
    "diag",                                                       /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

static emlrtRTEInfo rh_emlrtRTEI = {
    109,                                                          /* lineNo */
    24,                                                           /* colNo */
    "diag",                                                       /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/diag.m" /* pName */
};

/* Function Definitions */
void diag(const emlrtStack *sp, const emxArray_real_T *v, emxArray_real_T *d)
{
  const real_T *v_data;
  real_T *d_data;
  int32_T m;
  v_data = v->data;
  if ((v->size[0] == 1) && (v->size[1] == 1)) {
    m = d->size[0];
    d->size[0] = 1;
    emxEnsureCapacity_real_T(sp, d, m, &qh_emlrtRTEI);
    d_data = d->data;
    d_data[0] = v_data[0];
  } else {
    int32_T n;
    if ((v->size[0] == 1) || (v->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &rb_emlrtRTEI, "Coder:toolbox:diag_varsizedMatrixVector",
          "Coder:toolbox:diag_varsizedMatrixVector", 0);
    }
    m = v->size[0];
    n = v->size[1];
    if (v->size[1] > 0) {
      n = muIntScalarMin_sint32(m, n);
    } else {
      n = 0;
    }
    m = d->size[0];
    d->size[0] = n;
    emxEnsureCapacity_real_T(sp, d, m, &rh_emlrtRTEI);
    d_data = d->data;
    for (m = 0; m < n; m++) {
      d_data[m] = v_data[m + v->size[0] * m];
    }
  }
}

/* End of code generation (diag.c) */
