/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_mexutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgeqp3.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo
    wo_emlrtRSI =
        {
            42,      /* lineNo */
            "mldiv", /* fcnName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pathName */
};

static emlrtRSInfo
    xo_emlrtRSI =
        {
            44,      /* lineNo */
            "mldiv", /* fcnName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pathName */
};

static emlrtRSInfo yo_emlrtRSI =
    {
        67,        /* lineNo */
        "lusolve", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "lusolve.m" /* pathName */
};

static emlrtRSInfo ap_emlrtRSI =
    {
        109,          /* lineNo */
        "lusolveNxN", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "lusolve.m" /* pathName */
};

static emlrtRSInfo bp_emlrtRSI =
    {
        112,          /* lineNo */
        "lusolveNxN", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "lusolve.m" /* pathName */
};

static emlrtRSInfo cp_emlrtRSI =
    {
        124,          /* lineNo */
        "InvAtimesX", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "lusolve.m" /* pathName */
};

static emlrtRSInfo dp_emlrtRSI = {
    19,        /* lineNo */
    "xgetrfs", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pathName */
};

static emlrtRSInfo ep_emlrtRSI = {
    108,      /* lineNo */
    "cmldiv", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pathName */
};

static emlrtRSInfo fp_emlrtRSI = {
    70,       /* lineNo */
    "cmldiv", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pathName */
};

static emlrtRSInfo tp_emlrtRSI =
    {
        90,              /* lineNo */
        "warn_singular", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "lusolve.m" /* pathName */
};

static emlrtRSInfo up_emlrtRSI =
    {
        61,        /* lineNo */
        "qrsolve", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo vp_emlrtRSI =
    {
        72,        /* lineNo */
        "qrsolve", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo wp_emlrtRSI =
    {
        85,        /* lineNo */
        "qrsolve", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo xp_emlrtRSI =
    {
        173,          /* lineNo */
        "rankFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo yp_emlrtRSI =
    {
        172,          /* lineNo */
        "rankFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo aq_emlrtRSI =
    {
        119,         /* lineNo */
        "LSQFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo bq_emlrtRSI =
    {
        126,         /* lineNo */
        "LSQFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo cq_emlrtRSI =
    {
        128,         /* lineNo */
        "LSQFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo dq_emlrtRSI =
    {
        138,         /* lineNo */
        "LSQFromQR", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pathName */
};

static emlrtRSInfo eq_emlrtRSI = {
    40,         /* lineNo */
    "xunormqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xunormqr.m" /* pathName */
};

static emlrtRSInfo fq_emlrtRSI = {
    106,              /* lineNo */
    "ceval_xunormqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xunormqr.m" /* pathName */
};

static emlrtRSInfo gq_emlrtRSI = {
    112,              /* lineNo */
    "ceval_xunormqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xunormqr.m" /* pathName */
};

static emlrtRSInfo hq_emlrtRSI = {
    21,          /* lineNo */
    "xzunormqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzunormqr.m" /* pathName */
};

static emlrtRSInfo iq_emlrtRSI = {
    23,          /* lineNo */
    "xzunormqr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzunormqr.m" /* pathName */
};

static emlrtRSInfo jq_emlrtRSI = {
    38,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzunormqr.m" /* pathName */
};

static emlrtRSInfo kq_emlrtRSI = {
    40,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzunormqr.m" /* pathName */
};

static emlrtRSInfo lq_emlrtRSI = {
    46,                    /* lineNo */
    "applyJthHouseHolder", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "+reflapack/xzunormqr.m" /* pathName */
};

static emlrtRTEInfo
    wg_emlrtRTEI =
        {
            31,         /* lineNo */
            5,          /* colNo */
            "mldivide", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pName */
};

static emlrtRTEInfo xg_emlrtRTEI =
    {
        61,        /* lineNo */
        2,         /* colNo */
        "qrsolve", /* fName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pName */
};

static emlrtRTEInfo
    yg_emlrtRTEI =
        {
            42,         /* lineNo */
            5,          /* colNo */
            "mldivide", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pName */
};

static emlrtRTEInfo ah_emlrtRTEI = {
    48,        /* lineNo */
    37,        /* colNo */
    "xgetrfs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pName */
};

static emlrtRTEInfo bh_emlrtRTEI =
    {
        85,        /* lineNo */
        26,        /* colNo */
        "qrsolve", /* fName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pName */
};

static emlrtRTEInfo ch_emlrtRTEI = {
    70,        /* lineNo */
    23,        /* colNo */
    "xgetrfs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pName */
};

static emlrtRTEInfo
    dh_emlrtRTEI =
        {
            44,         /* lineNo */
            5,          /* colNo */
            "mldivide", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pName */
};

static emlrtRTEInfo eh_emlrtRTEI =
    {
        119,       /* lineNo */
        5,         /* colNo */
        "qrsolve", /* fName */
        "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
        "qrsolve.m" /* pName */
};

static emlrtRTEInfo
    fh_emlrtRTEI =
        {
            25,         /* lineNo */
            14,         /* colNo */
            "mldivide", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/ops/"
            "mldivide.m" /* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = {
    70,        /* lineNo */
    1,         /* colNo */
    "xgetrfs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgetrfs.m" /* pName */
};

/* Function Definitions */
void mldiv(const emlrtStack *sp, const emxArray_real_T *A,
           const emxArray_real_T *B, emxArray_real_T *Y)
{
  static const int32_T b_iv[2] = {1, 6};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'o', 'r', 'm', 'q', 'r'};
  static const char_T rfmt[6] = {'%', '1', '4', '.', '6', 'e'};
  ptrdiff_t *IPIV_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_int32_T *jpvt;
  emxArray_ptrdiff_t *IPIV;
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  emxArray_real_T *tau;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  const real_T *A_data;
  const real_T *B_data;
  real_T *Y_data;
  real_T *b_A_data;
  real_T *b_B_data;
  real_T *tau_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T *jpvt_data;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  B_data = B->data;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_A, 2, &fh_emlrtRTEI);
  emxInit_real_T(sp, &tau, 1, &fh_emlrtRTEI);
  emxInit_int32_T(sp, &jpvt, 2, &fh_emlrtRTEI);
  emxInit_real_T(sp, &b_B, 2, &bh_emlrtRTEI);
  emxInit_ptrdiff_t(sp, &IPIV, &gh_emlrtRTEI);
  if ((A->size[0] == 0) || (A->size[1] == 0) ||
      ((B->size[0] == 0) || (B->size[1] == 0))) {
    int32_T maxmn;
    i = Y->size[0] * Y->size[1];
    Y->size[0] = A->size[1];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(sp, Y, i, &wg_emlrtRTEI);
    Y_data = Y->data;
    maxmn = A->size[1] * B->size[1];
    for (i = 0; i < maxmn; i++) {
      Y_data[i] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    ptrdiff_t INFO;
    ptrdiff_t LDA;
    ptrdiff_t nrc_t;
    int32_T maxmn;
    int32_T minmn;
    st.site = &wo_emlrtRSI;
    b_st.site = &yo_emlrtRSI;
    i = B->size[0];
    i1 = Y->size[0] * Y->size[1];
    Y->size[0] = B->size[0];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, Y, i1, &yg_emlrtRTEI);
    Y_data = Y->data;
    maxmn = B->size[0] * B->size[1];
    for (i1 = 0; i1 < maxmn; i1++) {
      Y_data[i1] = B_data[i1];
    }
    c_st.site = &ap_emlrtRSI;
    d_st.site = &cp_emlrtRSI;
    minmn = A->size[0];
    maxmn = A->size[1];
    maxmn = muIntScalarMin_sint32(minmn, maxmn);
    minmn = muIntScalarMin_sint32(i, maxmn);
    e_st.site = &dp_emlrtRSI;
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&e_st, b_A, i, &ah_emlrtRTEI);
    b_A_data = b_A->data;
    maxmn = A->size[0] * A->size[1];
    for (i = 0; i < maxmn; i++) {
      b_A_data[i] = A_data[i];
    }
    f_st.site = &fp_emlrtRSI;
    g_st.site = &gp_emlrtRSI;
    i = IPIV->size[0];
    IPIV->size[0] = minmn;
    emxEnsureCapacity_ptrdiff_t(&e_st, IPIV, i, &ch_emlrtRTEI);
    IPIV_data = IPIV->data;
    nrc_t = (ptrdiff_t)minmn;
    LDA = (ptrdiff_t)b_A->size[0];
    INFO = LAPACKE_dgetrf_work(102, nrc_t, nrc_t, &b_A_data[0], LDA,
                               &IPIV_data[0]);
    f_st.site = &ep_emlrtRSI;
    if ((int32_T)INFO < 0) {
      if ((int32_T)INFO == -1010) {
        emlrtErrorWithMessageIdR2018a(&f_st, &ob_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&f_st, &nb_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      19, &cv12[0], 12, (int32_T)INFO);
      }
    }
    LAPACKE_dgetrs_work(102, 'N', nrc_t, (ptrdiff_t)B->size[1], &b_A_data[0],
                        LDA, &IPIV_data[0], &Y_data[0], (ptrdiff_t)B->size[0]);
    if (((A->size[0] != 1) || (A->size[1] != 1)) && ((int32_T)INFO > 0)) {
      c_st.site = &bp_emlrtRSI;
      d_st.site = &tp_emlrtRSI;
      b_warning(&d_st);
    }
  } else {
    real_T tol;
    int32_T maxmn;
    int32_T minmn;
    int32_T rankA;
    boolean_T overflow;
    st.site = &xo_emlrtRSI;
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&st, b_A, i, &xg_emlrtRTEI);
    b_A_data = b_A->data;
    maxmn = A->size[0] * A->size[1];
    for (i = 0; i < maxmn; i++) {
      b_A_data[i] = A_data[i];
    }
    b_st.site = &up_emlrtRSI;
    xgeqp3(&b_st, b_A, tau, jpvt);
    jpvt_data = jpvt->data;
    tau_data = tau->data;
    b_A_data = b_A->data;
    b_st.site = &vp_emlrtRSI;
    rankA = 0;
    tol = 0.0;
    if (b_A->size[0] < b_A->size[1]) {
      minmn = b_A->size[0];
      maxmn = b_A->size[1];
    } else {
      minmn = b_A->size[1];
      maxmn = b_A->size[0];
    }
    if (minmn > 0) {
      tol = muDoubleScalarMin(1.4901161193847656E-8,
                              2.2204460492503131E-15 * (real_T)maxmn) *
            muDoubleScalarAbs(b_A_data[0]);
      while ((rankA < minmn) &&
             (!(muDoubleScalarAbs(b_A_data[rankA + b_A->size[0] * rankA]) <=
                tol))) {
        rankA++;
      }
    }
    if (rankA < minmn) {
      char_T str[14];
      c_st.site = &xp_emlrtRSI;
      y = NULL;
      m = emlrtCreateCharArray(2, &b_iv[0]);
      emlrtInitCharArrayR2013a(&c_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateDoubleScalar(tol);
      emlrtAssign(&b_y, m);
      d_st.site = &jt_emlrtRSI;
      emlrt_marshallIn(&d_st, b_sprintf(&d_st, y, b_y, &c_emlrtMCI),
                       "<output of sprintf>", str);
      c_st.site = &yp_emlrtRSI;
      f_warning(&c_st, rankA, str);
    }
    b_st.site = &wp_emlrtRSI;
    i = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[0];
    i1 = B->size[1];
    b_B->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, b_B, i, &bh_emlrtRTEI);
    b_B_data = b_B->data;
    maxmn = B->size[0] * B->size[1];
    for (i = 0; i < maxmn; i++) {
      b_B_data[i] = B_data[i];
    }
    i = Y->size[0] * Y->size[1];
    Y->size[0] = b_A->size[1];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, Y, i, &dh_emlrtRTEI);
    Y_data = Y->data;
    maxmn = b_A->size[1] * b_B->size[1];
    for (i = 0; i < maxmn; i++) {
      Y_data[i] = 0.0;
    }
    c_st.site = &aq_emlrtRSI;
    d_st.site = &eq_emlrtRSI;
    if ((b_A->size[0] != 0) && (b_A->size[1] != 0)) {
      ptrdiff_t nrc_t;
      nrc_t = (ptrdiff_t)b_B->size[0];
      nrc_t = LAPACKE_dormqr(
          102, 'L', 'T', nrc_t, (ptrdiff_t)b_B->size[1],
          (ptrdiff_t)muIntScalarMin_sint32(b_A->size[0], b_A->size[1]),
          &b_A_data[0], (ptrdiff_t)b_A->size[0], &tau_data[0], &b_B_data[0],
          nrc_t);
      e_st.site = &fq_emlrtRSI;
      if ((int32_T)nrc_t != 0) {
        boolean_T p;
        overflow = true;
        p = false;
        if ((int32_T)nrc_t == -7) {
          p = true;
        } else if ((int32_T)nrc_t == -9) {
          p = true;
        } else if ((int32_T)nrc_t == -10) {
          p = true;
        }
        if (!p) {
          if ((int32_T)nrc_t == -1010) {
            emlrtErrorWithMessageIdR2018a(&e_st, &ob_emlrtRTEI, "MATLAB:nomem",
                                          "MATLAB:nomem", 0);
          } else {
            emlrtErrorWithMessageIdR2018a(
                &e_st, &nb_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
                "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &fname[0], 12,
                (int32_T)nrc_t);
          }
        }
      } else {
        overflow = false;
      }
      if (overflow) {
        if (((int32_T)nrc_t == -10) && (b_B->size[1] > 1)) {
          e_st.site = &gq_emlrtRSI;
          minmn = muIntScalarMin_sint32(b_A->size[0], b_A->size[1]);
          f_st.site = &hq_emlrtRSI;
          if (minmn > 2147483646) {
            g_st.site = &rb_emlrtRSI;
            check_forloop_overflow_error(&g_st);
          }
          maxmn = b_A->size[0];
          for (j = 0; j < minmn; j++) {
            f_st.site = &iq_emlrtRSI;
            i = b_B->size[1];
            if (tau_data[j] != 0.0) {
              int32_T a_tmp;
              g_st.site = &jq_emlrtRSI;
              if (b_B->size[1] > 2147483646) {
                h_st.site = &rb_emlrtRSI;
                check_forloop_overflow_error(&h_st);
              }
              a_tmp = j + 2;
              overflow = ((j + 2 <= maxmn) && (maxmn > 2147483646));
              for (k = 0; k < i; k++) {
                tol = b_B_data[j + b_B->size[0] * k];
                g_st.site = &kq_emlrtRSI;
                if (overflow) {
                  h_st.site = &rb_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }
                for (b_i = a_tmp; b_i <= maxmn; b_i++) {
                  tol += b_A_data[(b_i + b_A->size[0] * j) - 1] *
                         b_B_data[(b_i + b_B->size[0] * k) - 1];
                }
                tol *= tau_data[j];
                if (tol != 0.0) {
                  int32_T scalarLB;
                  int32_T vectorUB;
                  b_B_data[j + b_B->size[0] * k] -= tol;
                  g_st.site = &lq_emlrtRSI;
                  scalarLB = (((((maxmn - j) - 1) / 2) << 1) + j) + 2;
                  vectorUB = scalarLB - 2;
                  for (b_i = a_tmp; b_i <= vectorUB; b_i += 2) {
                    __m128d r;
                    __m128d r1;
                    r = _mm_loadu_pd(&b_A_data[(b_i + b_A->size[0] * j) - 1]);
                    r1 = _mm_loadu_pd(&b_B_data[(b_i + b_B->size[0] * k) - 1]);
                    _mm_storeu_pd(
                        &b_B_data[(b_i + b_B->size[0] * k) - 1],
                        _mm_sub_pd(r1, _mm_mul_pd(r, _mm_set1_pd(tol))));
                  }
                  for (b_i = scalarLB; b_i <= maxmn; b_i++) {
                    b_B_data[(b_i + b_B->size[0] * k) - 1] -=
                        b_A_data[(b_i + b_A->size[0] * j) - 1] * tol;
                  }
                }
              }
            }
          }
        } else {
          minmn = b_B->size[0];
          maxmn = b_B->size[1];
          i = b_B->size[0] * b_B->size[1];
          b_B->size[0] = minmn;
          b_B->size[1] = maxmn;
          emxEnsureCapacity_real_T(&d_st, b_B, i, &eh_emlrtRTEI);
          b_B_data = b_B->data;
          maxmn *= minmn;
          for (i = 0; i < maxmn; i++) {
            b_B_data[i] = rtNaN;
          }
        }
      }
    }
    c_st.site = &bq_emlrtRSI;
    if (B->size[1] > 2147483646) {
      d_st.site = &rb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    overflow = (rankA > 2147483646);
    for (k = 0; k < i1; k++) {
      c_st.site = &cq_emlrtRSI;
      if (overflow) {
        d_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (b_i = 0; b_i < rankA; b_i++) {
        Y_data[(jpvt_data[b_i] + Y->size[0] * k) - 1] =
            b_B_data[b_i + b_B->size[0] * k];
      }
      for (j = rankA; j >= 1; j--) {
        i = jpvt_data[j - 1];
        Y_data[(i + Y->size[0] * k) - 1] /=
            b_A_data[(j + b_A->size[0] * (j - 1)) - 1];
        c_st.site = &dq_emlrtRSI;
        for (b_i = 0; b_i <= j - 2; b_i++) {
          Y_data[(jpvt_data[b_i] + Y->size[0] * k) - 1] -=
              Y_data[(i + Y->size[0] * k) - 1] *
              b_A_data[b_i + b_A->size[0] * (j - 1)];
        }
      }
    }
  }
  emxFree_ptrdiff_t(sp, &IPIV);
  emxFree_real_T(sp, &b_B);
  emxFree_int32_T(sp, &jpvt);
  emxFree_real_T(sp, &tau);
  emxFree_real_T(sp, &b_A);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (mldivide.c) */
