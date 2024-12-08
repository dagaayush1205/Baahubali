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
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void b_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C)
{
  const double *A_data;
  const double *B_data;
  double *C_data;
  int b_i;
  int i;
  int inner;
  int j;
  int k;
  int mc_tmp;
  int nc_tmp;
  B_data = B->data;
  A_data = A->data;
  mc_tmp = A->size[1];
  inner = A->size[0];
  nc_tmp = B->size[1];
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[1];
  C->size[1] = B->size[1];
  emxEnsureCapacity_real_T(C, i);
  C_data = C->data;
  for (j = 0; j < nc_tmp; j++) {
    int boffset;
    int coffset;
    coffset = j * mc_tmp;
    boffset = j * B->size[0];
    for (b_i = 0; b_i < mc_tmp; b_i++) {
      C_data[coffset + b_i] = 0.0;
    }
    for (k = 0; k < inner; k++) {
      double bkj;
      bkj = B_data[boffset + k];
      for (b_i = 0; b_i < mc_tmp; b_i++) {
        i = coffset + b_i;
        C_data[i] += A_data[b_i * A->size[0] + k] * bkj;
      }
    }
  }
}

void c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C)
{
  const double *A_data;
  const double *B_data;
  double *C_data;
  int aoffset;
  int i;
  int inner;
  int k;
  int mc_tmp;
  B_data = B->data;
  A_data = A->data;
  mc_tmp = A->size[0];
  inner = A->size[1];
  aoffset = C->size[0];
  C->size[0] = A->size[0];
  emxEnsureCapacity_real_T(C, aoffset);
  C_data = C->data;
  for (i = 0; i < mc_tmp; i++) {
    C_data[i] = 0.0;
  }
  for (k = 0; k < inner; k++) {
    int scalarLB;
    int vectorUB;
    aoffset = k * A->size[0];
    scalarLB = (mc_tmp / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&C_data[i]);
      _mm_storeu_pd(&C_data[i],
                    _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&A_data[aoffset + i]),
                                             _mm_set1_pd(B_data[k]))));
    }
    for (i = scalarLB; i < mc_tmp; i++) {
      C_data[i] += A_data[aoffset + i] * B_data[k];
    }
  }
}

void d_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C)
{
  const double *A_data;
  const double *B_data;
  double *C_data;
  int b_i;
  int i;
  int inner;
  int j;
  int k;
  int mc_tmp;
  int nc_tmp;
  B_data = B->data;
  A_data = A->data;
  mc_tmp = A->size[0];
  inner = A->size[1];
  nc_tmp = B->size[0];
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = B->size[0];
  emxEnsureCapacity_real_T(C, i);
  C_data = C->data;
  for (j = 0; j < nc_tmp; j++) {
    int coffset;
    coffset = j * mc_tmp;
    for (b_i = 0; b_i < mc_tmp; b_i++) {
      C_data[coffset + b_i] = 0.0;
    }
    for (k = 0; k < inner; k++) {
      double bkj;
      int aoffset;
      int scalarLB;
      int vectorUB;
      aoffset = k * A->size[0];
      bkj = B_data[k * B->size[0] + j];
      scalarLB = (mc_tmp / 2) << 1;
      vectorUB = scalarLB - 2;
      for (b_i = 0; b_i <= vectorUB; b_i += 2) {
        __m128d r;
        i = coffset + b_i;
        r = _mm_loadu_pd(&C_data[i]);
        _mm_storeu_pd(
            &C_data[i],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&A_data[aoffset + b_i]),
                                     _mm_set1_pd(bkj))));
      }
      for (b_i = scalarLB; b_i < mc_tmp; b_i++) {
        i = coffset + b_i;
        C_data[i] += A_data[aoffset + b_i] * bkj;
      }
    }
  }
}

void mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
            emxArray_real_T *C)
{
  const double *A_data;
  const double *B_data;
  double *C_data;
  int b_i;
  int i;
  int inner;
  int j;
  int k;
  int mc_tmp;
  int nc_tmp;
  B_data = B->data;
  A_data = A->data;
  mc_tmp = A->size[0];
  inner = A->size[1];
  nc_tmp = B->size[1];
  i = C->size[0] * C->size[1];
  C->size[0] = A->size[0];
  C->size[1] = B->size[1];
  emxEnsureCapacity_real_T(C, i);
  C_data = C->data;
  for (j = 0; j < nc_tmp; j++) {
    int boffset;
    int coffset;
    coffset = j * mc_tmp;
    boffset = j * B->size[0];
    for (b_i = 0; b_i < mc_tmp; b_i++) {
      C_data[coffset + b_i] = 0.0;
    }
    for (k = 0; k < inner; k++) {
      double bkj;
      int aoffset;
      int scalarLB;
      int vectorUB;
      aoffset = k * A->size[0];
      bkj = B_data[boffset + k];
      scalarLB = (mc_tmp / 2) << 1;
      vectorUB = scalarLB - 2;
      for (b_i = 0; b_i <= vectorUB; b_i += 2) {
        __m128d r;
        i = coffset + b_i;
        r = _mm_loadu_pd(&C_data[i]);
        _mm_storeu_pd(
            &C_data[i],
            _mm_add_pd(r, _mm_mul_pd(_mm_loadu_pd(&A_data[aoffset + b_i]),
                                     _mm_set1_pd(bkj))));
      }
      for (b_i = scalarLB; b_i < mc_tmp; b_i++) {
        i = coffset + b_i;
        C_data[i] += A_data[aoffset + b_i] * bkj;
      }
    }
  }
}

/* End of code generation (mtimes.c) */
