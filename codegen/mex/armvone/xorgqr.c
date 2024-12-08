/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xorgqr.c
 *
 * Code generation for function 'xorgqr'
 *
 */

/* Include files */
#include "xorgqr.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo oo_emlrtRSI = {
    60,             /* lineNo */
    "ceval_xorgqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xorgqr.m" /* pathName */
};

static emlrtRSInfo qo_emlrtRSI = {
    14,       /* lineNo */
    "xorgqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xorgqr.m" /* pathName */
};

/* Function Definitions */
void xorgqr(const emlrtStack *sp, int32_T m, int32_T n, int32_T k,
            emxArray_real_T *A, int32_T lda, const emxArray_real_T *tau)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'o', 'r', 'g', 'q', 'r'};
  emlrtStack b_st;
  emlrtStack st;
  const real_T *tau_data;
  real_T *A_data;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tau_data = tau->data;
  A_data = A->data;
  st.site = &qo_emlrtRSI;
  if ((A->size[0] != 0) && (A->size[1] != 0)) {
    ptrdiff_t info_t;
    boolean_T p;
    info_t = LAPACKE_dorgqr(102, (ptrdiff_t)m, (ptrdiff_t)n, (ptrdiff_t)k,
                            &A_data[0], (ptrdiff_t)lda, (real_T *)&tau_data[0]);
    b_st.site = &oo_emlrtRSI;
    if ((int32_T)info_t != 0) {
      boolean_T b_p;
      p = true;
      b_p = false;
      if ((int32_T)info_t == -7) {
        b_p = true;
      } else if ((int32_T)info_t == -5) {
        b_p = true;
      }
      if (!b_p) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &ob_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &nb_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)info_t);
        }
      }
    } else {
      p = false;
    }
    if (p) {
      int32_T A_idx_0;
      int32_T A_idx_1;
      A_idx_0 = A->size[0];
      A_idx_1 = A->size[1];
      for (i = 0; i < A_idx_1; i++) {
        for (i1 = 0; i1 < A_idx_0; i1++) {
          A_data[i1 + A->size[0] * i] = rtNaN;
        }
      }
    }
  }
}

/* End of code generation (xorgqr.c) */
