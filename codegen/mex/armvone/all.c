/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * all.c
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "all.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo qh_emlrtRSI = {
    13,    /* lineNo */
    "all", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/all.m" /* pathName
                                                                        */
};

/* Function Definitions */
boolean_T all(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ix;
  const boolean_T *x_data;
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &qh_emlrtRSI;
  y = true;
  b_st.site = &rh_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &yb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    if (!x_data[ix - 1]) {
      y = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

/* End of code generation (all.c) */
