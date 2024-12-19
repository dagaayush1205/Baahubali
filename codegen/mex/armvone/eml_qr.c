/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * eml_qr.c
 *
 * Code generation for function 'eml_qr'
 *
 */

/* Include files */
#include "eml_qr.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "xorgqr.h"

/* Variable Definitions */
static emlrtRSInfo rn_emlrtRSI = {
    21,       /* lineNo */
    "eml_qr", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo sn_emlrtRSI = {
    102,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo tn_emlrtRSI = {
    103,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo un_emlrtRSI = {
    107,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo vn_emlrtRSI = {
    108,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo wn_emlrtRSI = {
    113,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo xn_emlrtRSI = {
    115,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo yn_emlrtRSI = {
    121,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo ao_emlrtRSI = {
    122,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo bo_emlrtRSI = {
    125,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo co_emlrtRSI = {
    129,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo do_emlrtRSI = {
    132,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo eo_emlrtRSI = {
    136,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo fo_emlrtRSI = {
    137,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo go_emlrtRSI = {
    140,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo ho_emlrtRSI = {
    144,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo io_emlrtRSI = {
    145,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo jo_emlrtRSI = {
    149,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo ko_emlrtRSI = {
    150,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo lo_emlrtRSI = {
    151,       /* lineNo */
    "qr_full", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRSInfo wo_emlrtRSI = {
    202,        /* lineNo */
    "unpackQR", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pathName */
};

static emlrtRTEInfo qg_emlrtRTEI = {
    98,       /* lineNo */
    20,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

static emlrtRTEInfo rg_emlrtRTEI = {
    99,       /* lineNo */
    20,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

static emlrtRTEInfo sg_emlrtRTEI = {
    132,      /* lineNo */
    10,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

static emlrtRTEInfo tg_emlrtRTEI = {
    114,      /* lineNo */
    31,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

static emlrtRTEInfo ug_emlrtRTEI = {
    21,       /* lineNo */
    30,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

static emlrtRTEInfo vg_emlrtRTEI = {
    1,        /* lineNo */
    20,       /* colNo */
    "eml_qr", /* fName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/private/"
    "eml_qr.m" /* pName */
};

/* Function Definitions */
void eml_qr(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *Q,
            emxArray_real_T *R, emxArray_int32_T *E)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *jpvt1;
  emxArray_real_T *b_A;
  emxArray_real_T *tau;
  const real_T *A_data;
  real_T *Q_data;
  real_T *R_data;
  real_T *b_A_data;
  int32_T i;
  int32_T j;
  int32_T m_tmp;
  int32_T n;
  int32_T *E_data;
  int32_T *jpvt1_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &rn_emlrtRSI;
  m_tmp = A->size[0];
  n = A->size[1] - 1;
  j = Q->size[0] * Q->size[1];
  Q->size[0] = A->size[0];
  Q->size[1] = A->size[0];
  emxEnsureCapacity_real_T(&st, Q, j, &qg_emlrtRTEI);
  Q_data = Q->data;
  j = R->size[0] * R->size[1];
  R->size[0] = A->size[0];
  R->size[1] = A->size[1];
  emxEnsureCapacity_real_T(&st, R, j, &rg_emlrtRTEI);
  R_data = R->data;
  emxInit_real_T(&st, &tau, 1, &vg_emlrtRTEI);
  if (A->size[0] > A->size[1]) {
    int32_T loop_ub_tmp;
    b_st.site = &sn_emlrtRSI;
    for (j = 0; j <= n; j++) {
      b_st.site = &tn_emlrtRSI;
      if (m_tmp > 2147483646) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < m_tmp; i++) {
        Q_data[i + Q->size[0] * j] = A_data[i + A->size[0] * j];
      }
    }
    loop_ub_tmp = A->size[1] + 1;
    b_st.site = &un_emlrtRSI;
    if ((A->size[1] + 1 <= A->size[0]) && (A->size[0] > 2147483646)) {
      c_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (j = loop_ub_tmp; j <= m_tmp; j++) {
      b_st.site = &vn_emlrtRSI;
      if (m_tmp > 2147483646) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < m_tmp; i++) {
        Q_data[i + Q->size[0] * (j - 1)] = 0.0;
      }
    }
    emxInit_int32_T(&st, &jpvt1, 2, &vg_emlrtRTEI);
    b_st.site = &wn_emlrtRSI;
    xgeqp3(&b_st, Q, tau, jpvt1);
    jpvt1_data = jpvt1->data;
    Q_data = Q->data;
    j = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = A->size[1];
    emxEnsureCapacity_int32_T(&st, E, j, &tg_emlrtRTEI);
    E_data = E->data;
    b_st.site = &xn_emlrtRSI;
    for (j = 0; j <= n; j++) {
      E_data[j] = jpvt1_data[j];
    }
    emxFree_int32_T(&st, &jpvt1);
    b_st.site = &yn_emlrtRSI;
    for (j = 0; j <= n; j++) {
      b_st.site = &ao_emlrtRSI;
      for (i = 0; i <= j; i++) {
        R_data[i + R->size[0] * j] = Q_data[i + Q->size[0] * j];
      }
      loop_ub_tmp = j + 2;
      b_st.site = &bo_emlrtRSI;
      if ((j + 2 <= m_tmp) && (m_tmp > 2147483646)) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = loop_ub_tmp; i <= m_tmp; i++) {
        R_data[(i + R->size[0] * j) - 1] = 0.0;
      }
    }
    b_st.site = &co_emlrtRSI;
    c_st.site = &wo_emlrtRSI;
    xorgqr(&c_st, A->size[0], A->size[0], A->size[1], Q, A->size[0], tau);
  } else {
    int32_T loop_ub_tmp;
    emxInit_real_T(&st, &b_A, 2, &ug_emlrtRTEI);
    j = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&st, b_A, j, &sg_emlrtRTEI);
    b_A_data = b_A->data;
    loop_ub_tmp = A->size[0] * A->size[1];
    for (j = 0; j < loop_ub_tmp; j++) {
      b_A_data[j] = A_data[j];
    }
    b_st.site = &do_emlrtRSI;
    xgeqp3(&b_st, b_A, tau, E);
    b_A_data = b_A->data;
    b_st.site = &eo_emlrtRSI;
    if (A->size[0] > 2147483646) {
      c_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (j = 0; j < m_tmp; j++) {
      b_st.site = &fo_emlrtRSI;
      if (j + 1 > 2147483646) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i <= j; i++) {
        R_data[i + R->size[0] * j] = b_A_data[i + b_A->size[0] * j];
      }
      loop_ub_tmp = j + 2;
      b_st.site = &go_emlrtRSI;
      if ((j + 2 <= m_tmp) && (m_tmp > 2147483646)) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = loop_ub_tmp; i <= m_tmp; i++) {
        R_data[(i + R->size[0] * j) - 1] = 0.0;
      }
    }
    loop_ub_tmp = A->size[0] + 1;
    b_st.site = &ho_emlrtRSI;
    if ((A->size[0] + 1 <= A->size[1]) && (A->size[1] > 2147483646)) {
      c_st.site = &yb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (j = loop_ub_tmp; j <= n + 1; j++) {
      b_st.site = &io_emlrtRSI;
      if (m_tmp > 2147483646) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < m_tmp; i++) {
        R_data[i + R->size[0] * (j - 1)] = b_A_data[i + b_A->size[0] * (j - 1)];
      }
    }
    b_st.site = &jo_emlrtRSI;
    c_st.site = &wo_emlrtRSI;
    xorgqr(&c_st, A->size[0], A->size[0], A->size[0], b_A, A->size[0], tau);
    b_A_data = b_A->data;
    b_st.site = &ko_emlrtRSI;
    for (j = 0; j < m_tmp; j++) {
      b_st.site = &lo_emlrtRSI;
      if (m_tmp > 2147483646) {
        c_st.site = &yb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < m_tmp; i++) {
        Q_data[i + Q->size[0] * j] = b_A_data[i + b_A->size[0] * j];
      }
    }
    emxFree_real_T(&st, &b_A);
  }
  emxFree_real_T(&st, &tau);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (eml_qr.c) */
