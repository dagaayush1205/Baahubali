/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * vAllOrAny.c
 *
 * Code generation for function 'vAllOrAny'
 *
 */

/* Include files */
#include "vAllOrAny.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo nl_emlrtRSI = {
    103,                  /* lineNo */
    "flatVectorAllOrAny", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/vAllOrAny.m" /* pathName
                                                                            */
};

/* Function Definitions */
boolean_T flatVectorAllOrAny(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack st;
  const real_T *x_data;
  int32_T k;
  int32_T nx_tmp;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  nx_tmp = x->size[0] * x->size[1];
  p = true;
  st.site = &nl_emlrtRSI;
  if (nx_tmp > 2147483646) {
    b_st.site = &rb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < nx_tmp; k++) {
    if ((!p) ||
        (muDoubleScalarIsInf(x_data[k]) || muDoubleScalarIsNaN(x_data[k]))) {
      p = false;
    }
  }
  return p;
}

/* End of code generation (vAllOrAny.c) */
