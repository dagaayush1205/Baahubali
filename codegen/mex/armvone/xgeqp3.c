/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo fo_emlrtRSI = {
    63,       /* lineNo */
    "xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo go_emlrtRSI = {
    98,             /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo ho_emlrtRSI = {
    138,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo io_emlrtRSI = {
    141,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo jo_emlrtRSI = {
    143,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo ko_emlrtRSI = {
    148,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo lo_emlrtRSI = {
    151,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo mo_emlrtRSI = {
    154,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRSInfo no_emlrtRSI = {
    158,            /* lineNo */
    "ceval_xgeqp3", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pathName */
};

static emlrtRTEInfo ki_emlrtRTEI = {
    61,       /* lineNo */
    9,        /* colNo */
    "xgeqp3", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pName */
};

static emlrtRTEInfo li_emlrtRTEI = {
    92,       /* lineNo */
    22,       /* colNo */
    "xgeqp3", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pName */
};

static emlrtRTEInfo mi_emlrtRTEI = {
    105,      /* lineNo */
    1,        /* colNo */
    "xgeqp3", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pName */
};

static emlrtRTEInfo ni_emlrtRTEI = {
    97,       /* lineNo */
    5,        /* colNo */
    "xgeqp3", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgeqp3.m" /* pName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T *tau,
            emxArray_int32_T *jpvt)
{
  static const int32_T b_offsets[4] = {0, 1, 2, 3};
  static const int32_T offsets[4] = {0, 1, 2, 3};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 'q', 'p', '3'};
  ptrdiff_t *jpvt_t_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_ptrdiff_t *jpvt_t;
  real_T *A_data;
  real_T *tau_data;
  int32_T i;
  int32_T loop_ub;
  int32_T minmana;
  int32_T minmn;
  int32_T na;
  int32_T *jpvt_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  minmn = A->size[0];
  na = A->size[1] - 1;
  i = jpvt->size[0] * jpvt->size[1];
  jpvt->size[0] = 1;
  loop_ub = A->size[1];
  jpvt->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(sp, jpvt, i, &ki_emlrtRTEI);
  jpvt_data = jpvt->data;
  for (i = 0; i < loop_ub; i++) {
    jpvt_data[i] = 0;
  }
  st.site = &fo_emlrtRSI;
  minmana = muIntScalarMin_sint32(minmn, loop_ub);
  i = tau->size[0];
  tau->size[0] = minmana;
  emxEnsureCapacity_real_T(&st, tau, i, &li_emlrtRTEI);
  tau_data = tau->data;
  emxInit_ptrdiff_t(&st, &jpvt_t, &mi_emlrtRTEI);
  if ((A->size[0] == 0) || (A->size[1] == 0) || (A->size[0] < 1) ||
      (A->size[1] < 1)) {
    i = tau->size[0];
    tau->size[0] = minmana;
    emxEnsureCapacity_real_T(&st, tau, i, &ni_emlrtRTEI);
    tau_data = tau->data;
    for (i = 0; i < minmana; i++) {
      tau_data[i] = 0.0;
    }
    b_st.site = &go_emlrtRSI;
    if (A->size[1] > 2147483646) {
      c_st.site = &rb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    loop_ub = ((na + 1) / 4) << 2;
    minmn = loop_ub - 4;
    for (i = 0; i <= minmn; i += 4) {
      _mm_storeu_si128(
          (__m128i *)&jpvt_data[i],
          _mm_add_epi32(
              _mm_add_epi32(_mm_set1_epi32(i),
                            _mm_loadu_si128((const __m128i *)&offsets[0])),
              _mm_set1_epi32(1)));
    }
    for (i = loop_ub; i <= na; i++) {
      jpvt_data[i] = i + 1;
    }
  } else {
    ptrdiff_t info_t;
    boolean_T p;
    i = jpvt_t->size[0];
    jpvt_t->size[0] = loop_ub;
    emxEnsureCapacity_ptrdiff_t(&st, jpvt_t, i, &mi_emlrtRTEI);
    jpvt_t_data = jpvt_t->data;
    for (i = 0; i < loop_ub; i++) {
      jpvt_t_data[i] = (ptrdiff_t)0;
    }
    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)A->size[0], (ptrdiff_t)A->size[1],
                            &A_data[0], (ptrdiff_t)A->size[0], &jpvt_t_data[0],
                            &tau_data[0]);
    b_st.site = &ho_emlrtRSI;
    if ((int32_T)info_t != 0) {
      p = true;
      if ((int32_T)info_t != -4) {
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
      b_st.site = &io_emlrtRSI;
      if (A->size[1] > 2147483646) {
        c_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (loop_ub = 0; loop_ub <= na; loop_ub++) {
        b_st.site = &jo_emlrtRSI;
        if (minmn > 2147483646) {
          c_st.site = &rb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        for (i = 0; i < minmn; i++) {
          A_data[loop_ub * minmn + i] = rtNaN;
        }
      }
      i = na + 1;
      minmn = muIntScalarMin_sint32(minmn, i);
      b_st.site = &ko_emlrtRSI;
      if (minmn > 2147483646) {
        c_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < minmn; i++) {
        tau_data[i] = rtNaN;
      }
      loop_ub = minmn + 1;
      b_st.site = &lo_emlrtRSI;
      if ((minmn + 1 <= minmana) && (minmana > 2147483646)) {
        c_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = loop_ub; i <= minmana; i++) {
        tau_data[i - 1] = 0.0;
      }
      b_st.site = &mo_emlrtRSI;
      if (A->size[1] > 2147483646) {
        c_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      loop_ub = ((na + 1) / 4) << 2;
      minmn = loop_ub - 4;
      for (i = 0; i <= minmn; i += 4) {
        _mm_storeu_si128(
            (__m128i *)&jpvt_data[i],
            _mm_add_epi32(
                _mm_add_epi32(_mm_set1_epi32(i),
                              _mm_loadu_si128((const __m128i *)&b_offsets[0])),
                _mm_set1_epi32(1)));
      }
      for (i = loop_ub; i <= na; i++) {
        jpvt_data[i] = i + 1;
      }
    } else {
      b_st.site = &no_emlrtRSI;
      if (A->size[1] > 2147483646) {
        c_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i <= na; i++) {
        jpvt_data[i] = (int32_T)jpvt_t_data[i];
      }
    }
  }
  emxFree_ptrdiff_t(&st, &jpvt_t);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (xgeqp3.c) */
