/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRTEInfo og_emlrtRTEI =
    {
        140,      /* lineNo */
        5,        /* colNo */
        "mtimes", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

/* Function Definitions */
void b_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (B->size[0] == 0) || (B->size[1] == 0)) {
    int32_T loop_ub;
    i = C->size[0] * C->size[1];
    C->size[0] = 1;
    loop_ub = B->size[1];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < loop_ub; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)B->size[1];
    k_t = (ptrdiff_t)A->size[0];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)1;
    i = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

real_T c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  const real_T *B_data;
  real_T C;
  B_data = B->data;
  A_data = A->data;
  if (A->size[1] < 1) {
    C = 0.0;
  } else {
    n_t = (ptrdiff_t)A->size[1];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    C = ddot(&n_t, (real_T *)&A_data[0], &incx_t, (real_T *)&B_data[0],
             &incy_t);
  }
  return C;
}

void d_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0) ||
      (B->size[1] == 0)) {
    int32_T loop_ub_tmp;
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    loop_ub_tmp = A->size[0] * B->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)B->size[1];
    k_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[0];
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void e_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0) ||
      (B->size[1] == 0)) {
    int32_T loop_ub_tmp;
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[1];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    loop_ub_tmp = A->size[1] * B->size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)B->size[1];
    k_t = (ptrdiff_t)A->size[0];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[1];
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[1];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void f_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    int32_T loop_ub;
    loop_ub = A->size[0];
    i = C->size[0];
    C->size[0] = A->size[0];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < loop_ub; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[0];
    i = C->size[0];
    C->size[0] = A->size[0];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

real_T g_mtimes(const emxArray_real_T *A, const emxArray_real_T *B)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  const real_T *A_data;
  const real_T *B_data;
  real_T C;
  B_data = B->data;
  A_data = A->data;
  if (A->size[0] < 1) {
    C = 0.0;
  } else {
    n_t = (ptrdiff_t)A->size[0];
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    C = ddot(&n_t, (real_T *)&A_data[0], &incx_t, (real_T *)&B_data[0],
             &incy_t);
  }
  return C;
}

void h_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[1] == 0) || (B->size[0] == 0) || (B->size[1] == 0)) {
    int32_T loop_ub;
    i = C->size[0] * C->size[1];
    C->size[0] = 1;
    loop_ub = B->size[1];
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < loop_ub; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)1;
    n_t = (ptrdiff_t)B->size[1];
    k_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)1;
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)1;
    i = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = B->size[1];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void i_mtimes(const emlrtStack *sp, const emxArray_real_T *A,
              const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0) ||
      (B->size[1] == 0)) {
    int32_T loop_ub_tmp;
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[0];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    loop_ub_tmp = A->size[0] * B->size[0];
    for (i = 0; i < loop_ub_tmp; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[0];
    n_t = (ptrdiff_t)B->size[0];
    k_t = (ptrdiff_t)A->size[1];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[0];
    i = C->size[0] * C->size[1];
    C->size[0] = A->size[0];
    C->size[1] = B->size[0];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

void mtimes(const emlrtStack *sp, const emxArray_real_T *A,
            const emxArray_real_T *B, emxArray_real_T *C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  const real_T *A_data;
  const real_T *B_data;
  real_T alpha1;
  real_T beta1;
  real_T *C_data;
  int32_T i;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  B_data = B->data;
  A_data = A->data;
  if ((A->size[0] == 0) || (A->size[1] == 0) || (B->size[0] == 0)) {
    int32_T loop_ub;
    loop_ub = A->size[1];
    i = C->size[0];
    C->size[0] = A->size[1];
    emxEnsureCapacity_real_T(sp, C, i, &og_emlrtRTEI);
    C_data = C->data;
    for (i = 0; i < loop_ub; i++) {
      C_data[i] = 0.0;
    }
  } else {
    st.site = &el_emlrtRSI;
    b_st.site = &fl_emlrtRSI;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A->size[1];
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)A->size[0];
    lda_t = (ptrdiff_t)A->size[0];
    ldb_t = (ptrdiff_t)B->size[0];
    ldc_t = (ptrdiff_t)A->size[1];
    i = C->size[0];
    C->size[0] = A->size[1];
    emxEnsureCapacity_real_T(&b_st, C, i, &lf_emlrtRTEI);
    C_data = C->data;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A_data[0],
          &lda_t, (real_T *)&B_data[0], &ldb_t, &beta1, &C_data[0], &ldc_t);
  }
}

/* End of code generation (mtimes.c) */
