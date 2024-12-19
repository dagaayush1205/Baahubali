/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * eye.c
 *
 * Code generation for function 'eye'
 *
 */

/* Include files */
#include "eye.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gg_emlrtRSI = {
    50,    /* lineNo */
    "eye", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pathName
                                                                          */
};

static emlrtRSInfo hg_emlrtRSI = {
    96,    /* lineNo */
    "eye", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pathName
                                                                          */
};

static emlrtRSInfo ig_emlrtRSI = {
    21,                           /* lineNo */
    "checkAndSaturateExpandSize", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "checkAndSaturateExpandSize.m" /* pathName */
};

static emlrtRSInfo ur_emlrtRSI = {
    57,    /* lineNo */
    "eye", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pathName
                                                                          */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    94,    /* lineNo */
    5,     /* colNo */
    "eye", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/eye.m" /* pName
                                                                          */
};

/* Function Definitions */
void b_eye(const emlrtStack *sp, const real_T varargin_1[2],
           emxArray_real_T *b_I)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  real_T *I_data;
  int32_T b_d;
  int32_T i;
  int32_T m_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ur_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ig_emlrtRSI;
  if ((varargin_1[0] != muDoubleScalarFloor(varargin_1[0])) ||
      muDoubleScalarIsInf(varargin_1[0]) || (varargin_1[0] < -2.147483648E+9) ||
      (varargin_1[0] > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1[0] <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1[0];
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  m_tmp_tmp = (int32_T)varargin_1[0];
  b_st.site = &ig_emlrtRSI;
  if ((varargin_1[1] != muDoubleScalarFloor(varargin_1[1])) ||
      muDoubleScalarIsInf(varargin_1[1]) || (varargin_1[1] < -2.147483648E+9) ||
      (varargin_1[1] > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1[1] <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1[1];
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  b_d = (int32_T)varargin_1[1];
  b_d = muIntScalarMin_sint32(m_tmp_tmp, b_d);
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = (int32_T)varargin_1[0];
  b_I->size[1] = (int32_T)varargin_1[1];
  emxEnsureCapacity_real_T(sp, b_I, i, &mc_emlrtRTEI);
  I_data = b_I->data;
  m_tmp_tmp = (int32_T)varargin_1[0] * (int32_T)varargin_1[1];
  for (i = 0; i < m_tmp_tmp; i++) {
    I_data[i] = 0.0;
  }
  if (b_d > 0) {
    st.site = &hg_emlrtRSI;
    if (b_d > 2147483646) {
      b_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (m_tmp_tmp = 0; m_tmp_tmp < b_d; m_tmp_tmp++) {
      I_data[m_tmp_tmp + b_I->size[0] * m_tmp_tmp] = 1.0;
    }
  }
}

void eye(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *b_I)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T d;
  real_T t;
  real_T *I_data;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T m_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 < 0.0) {
    t = 0.0;
  } else {
    t = varargin_1;
  }
  b_st.site = &ig_emlrtRSI;
  if ((t != muDoubleScalarFloor(t)) || muDoubleScalarIsInf(t) ||
      (t < -2.147483648E+9) || (t > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (t <= 0.0) {
    d = 0.0;
  } else {
    d = t;
  }
  if (!(d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  m_tmp_tmp = (int32_T)t;
  i = b_I->size[0] * b_I->size[1];
  b_I->size[0] = (int32_T)t;
  b_I->size[1] = (int32_T)t;
  emxEnsureCapacity_real_T(sp, b_I, i, &mc_emlrtRTEI);
  I_data = b_I->data;
  loop_ub_tmp = (int32_T)t * (int32_T)t;
  for (i = 0; i < loop_ub_tmp; i++) {
    I_data[i] = 0.0;
  }
  if ((int32_T)t > 0) {
    st.site = &hg_emlrtRSI;
    if ((int32_T)t > 2147483646) {
      b_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (loop_ub_tmp = 0; loop_ub_tmp < m_tmp_tmp; loop_ub_tmp++) {
      I_data[loop_ub_tmp + b_I->size[0] * loop_ub_tmp] = 1.0;
    }
  }
}

/* End of code generation (eye.c) */
