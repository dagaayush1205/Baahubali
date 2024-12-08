/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * tic.c
 *
 * Code generation for function 'tic'
 *
 */

/* Include files */
#include "tic.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "emlrt.h"

/* Variable Definitions */
static emlrtRSInfo xh_emlrtRSI = {
    32,    /* lineNo */
    "tic", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/timefun/tic.m" /* pathName
                                                                            */
};

/* Function Definitions */
emlrtTimespec tic(const emlrtStack *sp)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emlrtTimespec tstart;
  int32_T status;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xh_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &yh_emlrtRSI;
  c_st.site = &ai_emlrtRSI;
  status = emlrtClockGettimeMonotonic(&tstart);
  d_st.site = &bi_emlrtRSI;
  if (status != 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &cb_emlrtRTEI, "Coder:toolbox:CoderTimeCallFailed",
        "Coder:toolbox:CoderTimeCallFailed", 5, 4, 26, &cv11[0], 12, status);
  }
  return tstart;
}

/* End of code generation (tic.c) */
