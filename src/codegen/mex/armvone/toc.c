/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * toc.c
 *
 * Code generation for function 'toc'
 *
 */

/* Include files */
#include "toc.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "emlrt.h"

/* Variable Definitions */
static emlrtRSInfo bp_emlrtRSI = {
    37,    /* lineNo */
    "toc", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/timefun/toc.m" /* pathName
                                                                            */
};

/* Function Definitions */
real_T toc(const emlrtStack *sp, real_T tstart_tv_sec, real_T tstart_tv_nsec)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emlrtTimespec tnow;
  int32_T status;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bp_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &gi_emlrtRSI;
  c_st.site = &hi_emlrtRSI;
  status = emlrtClockGettimeMonotonic(&tnow);
  d_st.site = &ii_emlrtRSI;
  if (status != 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &cb_emlrtRTEI, "Coder:toolbox:CoderTimeCallFailed",
        "Coder:toolbox:CoderTimeCallFailed", 5, 4, 26, &cv12[0], 12, status);
  }
  return (tnow.tv_sec - tstart_tv_sec) +
         (tnow.tv_nsec - tstart_tv_nsec) / 1.0E+9;
}

/* End of code generation (toc.c) */
