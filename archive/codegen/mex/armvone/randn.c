/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * randn.c
 *
 * Code generation for function 'randn'
 *
 */

/* Include files */
#include "randn.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo
    hs_emlrtRSI =
        {
            114,     /* lineNo */
            "randn", /* fcnName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/randfun/"
            "randn.m" /* pathName */
};

static emlrtRSInfo rs_emlrtRSI = {
    20,                /* lineNo */
    "zerosWithChecks", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "zerosWithChecks.m" /* pathName */
};

static emlrtRSInfo
    ss_emlrtRSI =
        {
            139,                 /* lineNo */
            "extrinsicRandnGen", /* fcnName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/randfun/"
            "randn.m" /* pathName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    13,              /* lineNo */
    27,              /* colNo */
    "mustBeInteger", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/validators/"
    "mustBeInteger.m" /* pName */
};

/* Function Definitions */
int32_T randn(const emlrtStack *sp, const real_T varargin_1[2], real_T r_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T r_size;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &hs_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ss_emlrtRSI;
  c_st.site = &rs_emlrtRSI;
  p = true;
  for (k = 0; k < 2; k++) {
    if (p) {
      real_T d;
      d = varargin_1[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d) ||
          (!(d == muDoubleScalarFloor(d)))) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&c_st, &vb_emlrtRTEI,
                                  "MATLAB:validators:mustBeInteger",
                                  "MATLAB:validators:mustBeInteger", 0);
  }
  r_size = (int32_T)varargin_1[0];
  if ((int32_T)varargin_1[0] != 0) {
    emlrtRandn(&r_data[0], (int32_T)varargin_1[0]);
  }
  return r_size;
}

/* End of code generation (randn.c) */
