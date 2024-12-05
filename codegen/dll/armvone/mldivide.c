/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: mldivide.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "mldivide.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "xgeqp3.h"
#include "xzgetrf.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *A
 *                const emxArray_real_T *B
 *                emxArray_real_T *Y
 * Return Type  : void
 */
void mldivide(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *Y)
{
  emxArray_int32_T *jpvt;
  emxArray_real_T *b_A;
  emxArray_real_T *b_B;
  emxArray_real_T *tau;
  const double *A_data;
  const double *B_data;
  double *Y_data;
  double *b_A_data;
  double *b_B_data;
  double *tau_data;
  int b_i;
  int i;
  int j;
  int k;
  int *jpvt_data;
  B_data = B->data;
  A_data = A->data;
  emxInit_real_T(&b_A, 2);
  emxInit_real_T(&tau, 1);
  emxInit_int32_T(&jpvt, 2);
  emxInit_real_T(&b_B, 2);
  if ((A->size[0] == 0) || (A->size[1] == 0) ||
      ((B->size[0] == 0) || (B->size[1] == 0))) {
    int minmn;
    i = Y->size[0] * Y->size[1];
    Y->size[0] = A->size[1];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(Y, i);
    Y_data = Y->data;
    minmn = A->size[1] * B->size[1];
    for (i = 0; i < minmn; i++) {
      Y_data[i] = 0.0;
    }
  } else if (A->size[0] == A->size[1]) {
    double tol;
    int i1;
    int maxmn;
    int minmn;
    int mn;
    int vectorUB;
    i = Y->size[0] * Y->size[1];
    Y->size[0] = B->size[0];
    vectorUB = B->size[1];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(Y, i);
    Y_data = Y->data;
    minmn = B->size[0] * B->size[1];
    for (i = 0; i < minmn; i++) {
      Y_data[i] = B_data[i];
    }
    minmn = A->size[0];
    mn = A->size[1];
    if (minmn <= mn) {
      mn = minmn;
    }
    minmn = B->size[0];
    if (minmn <= mn) {
      mn = minmn;
    }
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(b_A, i);
    b_A_data = b_A->data;
    minmn = A->size[0] * A->size[1];
    for (i = 0; i < minmn; i++) {
      b_A_data[i] = A_data[i];
    }
    xzgetrf(mn, mn, b_A, A->size[0], jpvt);
    jpvt_data = jpvt->data;
    b_A_data = b_A->data;
    for (b_i = 0; b_i <= mn - 2; b_i++) {
      i = jpvt_data[b_i];
      if (i != b_i + 1) {
        for (j = 0; j < vectorUB; j++) {
          tol = Y_data[b_i + Y->size[0] * j];
          Y_data[b_i + Y->size[0] * j] = Y_data[(i + Y->size[0] * j) - 1];
          Y_data[(i + Y->size[0] * j) - 1] = tol;
        }
      }
    }
    for (j = 0; j < vectorUB; j++) {
      minmn = B->size[0] * j;
      for (k = 0; k < mn; k++) {
        maxmn = b_A->size[0] * k;
        i = k + minmn;
        if (Y_data[i] != 0.0) {
          i1 = k + 2;
          for (b_i = i1; b_i <= mn; b_i++) {
            int scalarLB;
            scalarLB = (b_i + minmn) - 1;
            Y_data[scalarLB] -= Y_data[i] * b_A_data[(b_i + maxmn) - 1];
          }
        }
      }
    }
    for (j = 0; j < vectorUB; j++) {
      minmn = B->size[0] * j - 1;
      for (k = mn; k >= 1; k--) {
        maxmn = b_A->size[0] * (k - 1) - 1;
        i = k + minmn;
        tol = Y_data[i];
        if (tol != 0.0) {
          Y_data[i] = tol / b_A_data[k + maxmn];
          for (b_i = 0; b_i <= k - 2; b_i++) {
            i1 = (b_i + minmn) + 1;
            Y_data[i1] -= Y_data[i] * b_A_data[(b_i + maxmn) + 1];
          }
        }
      }
    }
  } else {
    double tol;
    int i1;
    int maxmn;
    int minmn;
    int mn;
    int rankA;
    i = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(b_A, i);
    b_A_data = b_A->data;
    minmn = A->size[0] * A->size[1];
    for (i = 0; i < minmn; i++) {
      b_A_data[i] = A_data[i];
    }
    xgeqp3(b_A, tau, jpvt);
    jpvt_data = jpvt->data;
    tau_data = tau->data;
    b_A_data = b_A->data;
    rankA = 0;
    if (b_A->size[0] < b_A->size[1]) {
      minmn = b_A->size[0];
      maxmn = b_A->size[1];
    } else {
      minmn = b_A->size[1];
      maxmn = b_A->size[0];
    }
    if (minmn > 0) {
      tol =
          fmin(1.4901161193847656E-8, 2.2204460492503131E-15 * (double)maxmn) *
          fabs(b_A_data[0]);
      while ((rankA < minmn) &&
             (!(fabs(b_A_data[rankA + b_A->size[0] * rankA]) <= tol))) {
        rankA++;
      }
    }
    i = b_B->size[0] * b_B->size[1];
    b_B->size[0] = B->size[0];
    i1 = B->size[1];
    b_B->size[1] = B->size[1];
    emxEnsureCapacity_real_T(b_B, i);
    b_B_data = b_B->data;
    minmn = B->size[0] * B->size[1];
    for (i = 0; i < minmn; i++) {
      b_B_data[i] = B_data[i];
    }
    i = Y->size[0] * Y->size[1];
    Y->size[0] = b_A->size[1];
    Y->size[1] = B->size[1];
    emxEnsureCapacity_real_T(Y, i);
    Y_data = Y->data;
    minmn = b_A->size[1] * B->size[1];
    for (i = 0; i < minmn; i++) {
      Y_data[i] = 0.0;
    }
    minmn = b_A->size[0];
    mn = b_A->size[1];
    if (minmn <= mn) {
      mn = minmn;
    }
    for (j = 0; j < mn; j++) {
      minmn = b_B->size[1];
      maxmn = b_A->size[0];
      if (tau_data[j] != 0.0) {
        i = j + 2;
        for (k = 0; k < minmn; k++) {
          tol = b_B_data[j + b_B->size[0] * k];
          for (b_i = i; b_i <= maxmn; b_i++) {
            tol += b_A_data[(b_i + b_A->size[0] * j) - 1] *
                   b_B_data[(b_i + b_B->size[0] * k) - 1];
          }
          tol *= tau_data[j];
          if (tol != 0.0) {
            int scalarLB;
            int vectorUB;
            b_B_data[j + b_B->size[0] * k] -= tol;
            scalarLB = (((((maxmn - j) - 1) / 2) << 1) + j) + 2;
            vectorUB = scalarLB - 2;
            for (b_i = i; b_i <= vectorUB; b_i += 2) {
              __m128d r;
              __m128d r1;
              r = _mm_loadu_pd(&b_A_data[(b_i + b_A->size[0] * j) - 1]);
              r1 = _mm_loadu_pd(&b_B_data[(b_i + b_B->size[0] * k) - 1]);
              _mm_storeu_pd(&b_B_data[(b_i + b_B->size[0] * k) - 1],
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
    for (k = 0; k < i1; k++) {
      for (b_i = 0; b_i < rankA; b_i++) {
        Y_data[(jpvt_data[b_i] + Y->size[0] * k) - 1] =
            b_B_data[b_i + b_B->size[0] * k];
      }
      for (j = rankA; j >= 1; j--) {
        i = jpvt_data[j - 1];
        Y_data[(i + Y->size[0] * k) - 1] /=
            b_A_data[(j + b_A->size[0] * (j - 1)) - 1];
        for (b_i = 0; b_i <= j - 2; b_i++) {
          Y_data[(jpvt_data[b_i] + Y->size[0] * k) - 1] -=
              Y_data[(i + Y->size[0] * k) - 1] *
              b_A_data[b_i + b_A->size[0] * (j - 1)];
        }
      }
    }
  }
  emxFree_real_T(&b_B);
  emxFree_int32_T(&jpvt);
  emxFree_real_T(&tau);
  emxFree_real_T(&b_A);
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
