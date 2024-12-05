/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * isPositiveDefinite.c
 *
 * Code generation for function 'isPositiveDefinite'
 *
 */

/* Include files */
#include "isPositiveDefinite.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo nr_emlrtRSI = {
    11,                   /* lineNo */
    "isPositiveDefinite", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/isPositiveDefinite.m" /* pathName */
};

static emlrtRSInfo or_emlrtRSI = {
    15,                                                            /* lineNo */
    "chol",                                                        /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/chol.m" /* pathName
                                                                    */
};

static emlrtRSInfo pr_emlrtRSI = {
    84,     /* lineNo */
    "chol", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                       */
};

static emlrtRSInfo qr_emlrtRSI = {
    93,     /* lineNo */
    "chol", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                       */
};

static emlrtRSInfo rr_emlrtRSI = {
    94,     /* lineNo */
    "chol", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                       */
};

static emlrtRSInfo sr_emlrtRSI =
    {
        79,             /* lineNo */
        "ceval_xpotrf", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xpotrf.m" /* pathName */
};

static emlrtRSInfo tr_emlrtRSI =
    {
        13,       /* lineNo */
        "xpotrf", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xpotrf.m" /* pathName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    56,     /* lineNo */
    23,     /* colNo */
    "chol", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/chol.m" /* pName
                                                                       */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    16,                                                            /* lineNo */
    5,                                                             /* colNo */
    "chol",                                                        /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/chol.m" /* pName */
};

static emlrtRTEInfo sh_emlrtRTEI = {
    1,      /* lineNo */
    31,     /* colNo */
    "chol", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/chol.m" /* pName
                                                                       */
};

static emlrtRTEInfo th_emlrtRTEI = {
    1,                    /* lineNo */
    17,                   /* colNo */
    "isPositiveDefinite", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/isPositiveDefinite.m" /* pName */
};

/* Function Definitions */
boolean_T isPositiveDefinite(const emlrtStack *sp, const emxArray_real_T *B)
{
  static const char_T fname[19] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'p', 'o', 't', 'r', 'f',
                                   '_', 'w', 'o', 'r', 'k'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *A;
  const real_T *B_data;
  real_T *A_data;
  int32_T b_n;
  int32_T i;
  int32_T loop_ub_tmp;
  int32_T n;
  boolean_T flag;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  B_data = B->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &nr_emlrtRSI;
  b_st.site = &or_emlrtRSI;
  emxInit_real_T(&b_st, &A, 2, &th_emlrtRTEI);
  n = B->size[0];
  i = A->size[0] * A->size[1];
  A->size[0] = B->size[0];
  b_n = B->size[1];
  A->size[1] = B->size[1];
  emxEnsureCapacity_real_T(&b_st, A, i, &sh_emlrtRTEI);
  A_data = A->data;
  loop_ub_tmp = B->size[0] * B->size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    A_data[i] = B_data[i];
  }
  if (A->size[0] != A->size[1]) {
    emlrtErrorWithMessageIdR2018a(&b_st, &tb_emlrtRTEI, "MATLAB:square",
                                  "MATLAB:square", 0);
  }
  n = muIntScalarMin_sint32(n, b_n);
  b_n = 0;
  loop_ub_tmp = 0;
  if (n != 0) {
    ptrdiff_t info_t;
    c_st.site = &pr_emlrtRSI;
    d_st.site = &tr_emlrtRSI;
    info_t = LAPACKE_dpotrf_work(102, 'L', (ptrdiff_t)n, &A_data[0],
                                 (ptrdiff_t)A->size[0]);
    e_st.site = &sr_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&e_st, &ob_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&e_st, &nb_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &fname[0], 12, (int32_T)info_t);
      }
    }
    loop_ub_tmp = (int32_T)info_t;
    if ((int32_T)info_t == 0) {
      b_n = n;
    } else {
      b_n = (int32_T)info_t - 1;
    }
    c_st.site = &qr_emlrtRSI;
    if (b_n > 2147483646) {
      d_st.site = &rb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (n = 2; n <= b_n; n++) {
      c_st.site = &rr_emlrtRSI;
    }
  }
  if ((b_n > A->size[0]) || (b_n > A->size[1])) {
    emlrtErrorWithMessageIdR2018a(&st, &ub_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  emxFree_real_T(&st, &A);
  flag = (loop_ub_tmp == 0);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return flag;
}

/* End of code generation (isPositiveDefinite.c) */
