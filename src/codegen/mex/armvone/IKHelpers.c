/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * IKHelpers.c
 *
 * Code generation for function 'IKHelpers'
 *
 */

/* Include files */
#include "IKHelpers.h"
#include "RigidBodyTree.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "complexTimes.h"
#include "normalizeRows.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "vAllOrAny.h"
#include "xzsvdc.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo bk_emlrtRSI = {
    26,                      /* lineNo */
    "IKHelpers/computeCost", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtRSInfo ck_emlrtRSI = {
    32,                      /* lineNo */
    "IKHelpers/computeCost", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtRSInfo dk_emlrtRSI = {
    35,                      /* lineNo */
    "IKHelpers/computeCost", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtRSInfo ol_emlrtRSI = {
    69,                    /* lineNo */
    "IKHelpers/poseError", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtRSInfo pl_emlrtRSI = {
    51,           /* lineNo */
    "rotm2axang", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutilsint/"
    "+robotics/+internal/rotm2axang.m" /* pathName */
};

static emlrtRSInfo ql_emlrtRSI = {
    42,           /* lineNo */
    "rotm2axang", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutilsint/"
    "+robotics/+internal/rotm2axang.m" /* pathName */
};

static emlrtRSInfo sl_emlrtRSI = {
    36,    /* lineNo */
    "svd", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    wl_emlrtRSI =
        {
            52,    /* lineNo */
            "svd", /* fcnName */
            "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
            "svd.m" /* pathName */
};

static emlrtRSInfo yl_emlrtRSI = {
    34,       /* lineNo */
    "xgesvd", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/+lapack/"
    "xgesvd.m" /* pathName */
};

static emlrtRSInfo cp_emlrtRSI = {
    47,                           /* lineNo */
    "IKHelpers/evaluateSolution", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    66,                    /* lineNo */
    23,                    /* colNo */
    "",                    /* aName */
    "IKHelpers/poseError", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m", /* pName */
    0                               /* checkKind */
};

static emlrtECInfo nb_emlrtECI = {
    -1,           /* nDims */
    45,           /* lineNo */
    9,            /* colNo */
    "rotm2axang", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutilsint/"
    "+robotics/+internal/rotm2axang.m" /* pName */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    64,                    /* lineNo */
    23,                    /* colNo */
    "",                    /* aName */
    "IKHelpers/poseError", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m", /* pName */
    0                               /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    64,                    /* lineNo */
    19,                    /* colNo */
    "",                    /* aName */
    "IKHelpers/poseError", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m", /* pName */
    0                               /* checkKind */
};

static emlrtRTEInfo jf_emlrtRTEI = {
    31,          /* lineNo */
    13,          /* colNo */
    "IKHelpers", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pName */
};

static emlrtRTEInfo kf_emlrtRTEI = {
    33,          /* lineNo */
    13,          /* colNo */
    "IKHelpers", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pName */
};

static emlrtRTEInfo lf_emlrtRTEI = {
    35,          /* lineNo */
    13,          /* colNo */
    "IKHelpers", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    35,          /* lineNo */
    30,          /* colNo */
    "IKHelpers", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pName */
};

/* Function Definitions */
real_T IKHelpers_computeCost(const emlrtStack *sp, const emxArray_real_T *x,
                             c_robotics_manip_internal_IKExt *args,
                             real_T W[36], emxArray_real_T *Jac,
                             c_robotics_manip_internal_IKExt **b_args)
{
  __m128d r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  e_robotics_manip_internal_Rigid *treeInternal;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  emxArray_real_T b_T;
  emxArray_real_T *c_y;
  creal_T u;
  creal_T v;
  real_T T_data[16];
  real_T Td[16];
  real_T T[9];
  real_T c_T[9];
  real_T y[9];
  real_T b_y[6];
  real_T e[6];
  real_T b_v[3];
  real_T c_v[3];
  real_T br_tmp_tmp;
  real_T cost;
  real_T q;
  real_T *Jac_data;
  real_T *y_data;
  int32_T iv1[3];
  int32_T T_size[2];
  int32_T b_iv[2];
  int32_T vspecial_size[2];
  int32_T i;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  char_T TRANSA1;
  char_T TRANSB1;
  int8_T R_tmp[3];
  boolean_T exitg1;
  boolean_T rEQ0;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  *b_args = args;
  treeInternal = (*b_args)->Robot;
  for (i = 0; i < 16; i++) {
    Td[i] = (*b_args)->Tform[i];
  }
  for (i = 0; i < 36; i++) {
    W[i] = (*b_args)->WeightMatrix[i];
  }
  cost = (*b_args)->BodyIndex;
  st.site = &bk_emlrtRSI;
  c_RigidBodyTree_efficientFKAndJ(&st, treeInternal, x, cost, T_data, T_size,
                                  Jac);
  loop_ub = 6 * Jac->size[1];
  i = Jac->size[0] * Jac->size[1];
  Jac->size[0] = 6;
  emxEnsureCapacity_real_T(sp, Jac, i, &jf_emlrtRTEI);
  Jac_data = Jac->data;
  scalarLB = (loop_ub / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&Jac_data[i]);
    _mm_storeu_pd(&Jac_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  }
  for (i = scalarLB; i < loop_ub; i++) {
    Jac_data[i] = -Jac_data[i];
  }
  st.site = &ck_emlrtRSI;
  if (T_size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, T_size[0], &gd_emlrtBCI, &st);
  }
  R_tmp[0] = 1;
  if (T_size[0] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &gd_emlrtBCI, &st);
  }
  R_tmp[1] = 2;
  if (T_size[0] < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &gd_emlrtBCI, &st);
  }
  R_tmp[2] = 3;
  if (T_size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, T_size[1], &fd_emlrtBCI, &st);
  }
  if (T_size[1] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &fd_emlrtBCI, &st);
  }
  if (T_size[1] < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, 2, &fd_emlrtBCI, &st);
  }
  if (T_size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, 3, &ed_emlrtBCI, &st);
  }
  i = T_size[0];
  for (scalarLB = 0; scalarLB < 3; scalarLB++) {
    loop_ub = R_tmp[scalarLB] - 1;
    T[3 * scalarLB] = T_data[loop_ub];
    T[3 * scalarLB + 1] = T_data[loop_ub + i];
    T[3 * scalarLB + 2] = T_data[loop_ub + i * 2];
  }
  for (i = 0; i < 3; i++) {
    br_tmp_tmp = Td[i];
    cost = Td[i + 4];
    q = Td[i + 8];
    for (scalarLB = 0; scalarLB < 3; scalarLB++) {
      y[i + 3 * scalarLB] =
          (br_tmp_tmp * T[3 * scalarLB] + cost * T[3 * scalarLB + 1]) +
          q * T[3 * scalarLB + 2];
    }
  }
  b_st.site = &ol_emlrtRSI;
  cost = 0.5 * (((y[0] + y[4]) + y[8]) - 1.0);
  if (!(muDoubleScalarAbs(cost) > 1.0)) {
    u.re = muDoubleScalarAcos(cost);
  } else {
    v.re = cost + 1.0;
    v.im = 0.0;
    b_sqrt(&v);
    u.re = 1.0 - cost;
    u.im = 0.0;
    b_sqrt(&u);
    br_tmp_tmp = u.re;
    if ((!(-v.im == 0.0)) || (!(u.im == 0.0))) {
      cost = v.re * u.im + -v.im * u.re;
      if ((muDoubleScalarIsInf(cost) || muDoubleScalarIsNaN(cost)) &&
          (!muDoubleScalarIsNaN(v.re)) && (!muDoubleScalarIsNaN(-v.im)) &&
          (!muDoubleScalarIsNaN(u.re)) && (!muDoubleScalarIsNaN(u.im))) {
        cost = v.re;
        q = -v.im;
        rescale(&cost, &q);
        cost = u.re;
        q = u.im;
        rescale(&cost, &q);
      }
    }
    u.re = 2.0 * muDoubleScalarAtan2(br_tmp_tmp, v.re);
  }
  cost = 2.0 * muDoubleScalarSin(u.re);
  b_v[0] = (y[5] - y[7]) / cost;
  b_v[1] = (y[6] - y[2]) / cost;
  b_v[2] = (y[1] - y[3]) / cost;
  if (muDoubleScalarIsNaN(u.re) || muDoubleScalarIsInf(u.re)) {
    cost = rtNaN;
  } else if (u.re == 0.0) {
    cost = 0.0;
  } else {
    cost = muDoubleScalarRem(u.re, 3.1415926535897931);
    rEQ0 = (cost == 0.0);
    if (!rEQ0) {
      q = muDoubleScalarAbs(u.re / 3.1415926535897931);
      rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
               2.2204460492503131E-16 * q);
    }
    if (rEQ0) {
      cost = 0.0;
    } else if (cost < 0.0) {
      cost += 3.1415926535897931;
    }
  }
  rEQ0 = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 3)) {
    if (!(b_v[loop_ub] == 0.0)) {
      rEQ0 = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if ((cost == 0.0) || rEQ0) {
    __m128d r1;
    vspecial_size[0] = 3;
    vspecial_size[1] = 1;
    memset(&T[0], 0, 9U * sizeof(real_T));
    T[0] = 1.0;
    T[4] = 1.0;
    T[8] = 1.0;
    c_st.site = &ql_emlrtRSI;
    r = _mm_loadu_pd(&T[0]);
    r1 = _mm_loadu_pd(&y[0]);
    _mm_storeu_pd(&T[0], _mm_sub_pd(r, r1));
    r = _mm_loadu_pd(&T[2]);
    r1 = _mm_loadu_pd(&y[2]);
    _mm_storeu_pd(&T[2], _mm_sub_pd(r, r1));
    r = _mm_loadu_pd(&T[4]);
    r1 = _mm_loadu_pd(&y[4]);
    _mm_storeu_pd(&T[4], _mm_sub_pd(r, r1));
    r = _mm_loadu_pd(&T[6]);
    r1 = _mm_loadu_pd(&y[6]);
    _mm_storeu_pd(&T[6], _mm_sub_pd(r, r1));
    T[8] -= y[8];
    d_st.site = &rl_emlrtRSI;
    e_st.site = &tl_emlrtRSI;
    b_T.data = &T[0];
    b_iv[0] = 3;
    b_iv[1] = 3;
    b_T.size = &b_iv[0];
    b_T.allocatedSize = 9;
    b_T.numDimensions = 2;
    b_T.canFreeData = false;
    f_st.site = &ul_emlrtRSI;
    rEQ0 = flatVectorAllOrAny(&f_st, &b_T);
    if (rEQ0) {
      real_T U[9];
      d_st.site = &sl_emlrtRSI;
      e_st.site = &wl_emlrtRSI;
      f_st.site = &xl_emlrtRSI;
      memcpy(&c_T[0], &T[0], 9U * sizeof(real_T));
      g_st.site = &yl_emlrtRSI;
      xzsvdc(&g_st, c_T, U, b_v, y);
    } else {
      for (i = 0; i < 9; i++) {
        y[i] = rtNaN;
      }
    }
    iv1[0] = 1;
    iv1[1] = 3;
    iv1[2] = 1;
    emlrtSubAssignSizeCheckR2012b(&iv1[0], 3, &vspecial_size[0], 2,
                                  &nb_emlrtECI, &b_st);
    b_v[0] = y[6];
    b_v[1] = y[7];
    b_v[2] = y[8];
  }
  for (i = 0; i < 3; i++) {
    c_v[i] = b_v[i];
  }
  c_st.site = &pl_emlrtRSI;
  normalizeRows(&c_st, c_v, b_v);
  e[0] = u.re * b_v[0];
  e[3] = Td[12] - T_data[T_size[0] * 3];
  e[1] = u.re * b_v[1];
  e[4] = Td[13] - T_data[T_size[0] * 3 + 1];
  e[2] = u.re * b_v[2];
  e[5] = Td[14] - T_data[T_size[0] * 3 + 2];
  i = (*b_args)->ErrTemp->size[0];
  (*b_args)->ErrTemp->size[0] = 6;
  emxEnsureCapacity_real_T(sp, (*b_args)->ErrTemp, i, &kf_emlrtRTEI);
  for (i = 0; i < 6; i++) {
    (*b_args)->ErrTemp->data[i] = e[i];
  }
  cost = 0.0;
  for (i = 0; i < 6; i++) {
    br_tmp_tmp = 0.0;
    for (scalarLB = 0; scalarLB < 6; scalarLB++) {
      br_tmp_tmp += 0.5 * e[scalarLB] * W[scalarLB + 6 * i];
    }
    cost += br_tmp_tmp * e[i];
  }
  (*b_args)->CostTemp = cost;
  for (i = 0; i < 6; i++) {
    br_tmp_tmp = 0.0;
    for (scalarLB = 0; scalarLB < 6; scalarLB++) {
      br_tmp_tmp += e[scalarLB] * W[scalarLB + 6 * i];
    }
    b_y[i] = br_tmp_tmp;
  }
  emxInit_real_T(sp, &c_y, 2, &nf_emlrtRTEI);
  y_data = c_y->data;
  st.site = &dk_emlrtRSI;
  b_st.site = &ll_emlrtRSI;
  if (Jac->size[1] == 0) {
    c_y->size[0] = 1;
    c_y->size[1] = 0;
  } else {
    c_st.site = &ml_emlrtRSI;
    d_st.site = &nl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    cost = 1.0;
    q = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)Jac->size[1];
    k_t = (ptrdiff_t)6;
    lda_t = (ptrdiff_t)1;
    ldb_t = (ptrdiff_t)6;
    ldc_t = (ptrdiff_t)1;
    i = c_y->size[0] * c_y->size[1];
    c_y->size[0] = 1;
    c_y->size[1] = Jac->size[1];
    emxEnsureCapacity_real_T(&d_st, c_y, i, &mf_emlrtRTEI);
    y_data = c_y->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &cost, &b_y[0], &lda_t,
          &Jac_data[0], &ldb_t, &q, &y_data[0], &ldc_t);
  }
  loop_ub = c_y->size[1];
  i = (*b_args)->GradTemp->size[0];
  (*b_args)->GradTemp->size[0] = c_y->size[1];
  emxEnsureCapacity_real_T(sp, (*b_args)->GradTemp, i, &lf_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    (*b_args)->GradTemp->data[i] = y_data[i];
  }
  emxFree_real_T(sp, &c_y);
  cost = (*b_args)->CostTemp;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return cost;
}

real_T IKHelpers_evaluateSolution(const emlrtStack *sp,
                                  const c_robotics_manip_internal_IKExt *args)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T y[6];
  real_T en;
  real_T scale;
  int32_T i;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  st.site = &cp_emlrtRSI;
  b_st.site = &fl_emlrtRSI;
  if (args->ErrTemp->size[0] != 6) {
    if (args->ErrTemp->size[0] == 1) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &kb_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &jb_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  for (k = 0; k < 6; k++) {
    scale = 0.0;
    for (i = 0; i < 6; i++) {
      scale += args->WeightMatrix[k + 6 * i] * args->ErrTemp->data[i];
    }
    y[k] = scale;
  }
  en = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 6; k++) {
    real_T absxk;
    absxk = muDoubleScalarAbs(y[k]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      en = en * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      en += t * t;
    }
  }
  return scale * muDoubleScalarSqrt(en);
}

/* End of code generation (IKHelpers.c) */
