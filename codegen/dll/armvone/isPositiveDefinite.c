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
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
boolean_T isPositiveDefinite(const emxArray_real_T *B)
{
  emxArray_real_T *A;
  const double *B_data;
  double *A_data;
  int i;
  int i1;
  int ia;
  int iac;
  int info;
  int ix;
  int n;
  int nmj;
  B_data = B->data;
  emxInit_real_T(&A, 2);
  i = B->size[0];
  i1 = A->size[0] * A->size[1];
  A->size[0] = B->size[0];
  A->size[1] = B->size[1];
  emxEnsureCapacity_real_T(A, i1);
  A_data = A->data;
  nmj = B->size[0] * B->size[1];
  for (i1 = 0; i1 < nmj; i1++) {
    A_data[i1] = B_data[i1];
  }
  nmj = B->size[0];
  n = B->size[1];
  if (nmj <= n) {
    n = nmj;
  }
  info = 0;
  if (n != 0) {
    int j;
    boolean_T exitg1;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= n - 1)) {
      double c;
      double ssq;
      int idxAjj;
      idxAjj = j + j * i;
      ssq = 0.0;
      if (j >= 1) {
        for (ix = 0; ix < j; ix++) {
          c = A_data[j + ix * i];
          ssq += c * c;
        }
      }
      ssq = A_data[idxAjj] - ssq;
      if (ssq > 0.0) {
        ssq = sqrt(ssq);
        A_data[idxAjj] = ssq;
        if (j + 1 < n) {
          int ia0;
          int idxAjp1j;
          nmj = (n - j) - 1;
          ia0 = j + 2;
          idxAjp1j = idxAjj + 2;
          if ((nmj != 0) && (j != 0)) {
            ix = j;
            i1 = (j + i * (j - 1)) + 2;
            for (iac = ia0; i < 0 ? iac >= i1 : iac <= i1; iac += i) {
              int i2;
              c = -A_data[ix];
              i2 = iac + nmj;
              for (ia = iac; ia < i2; ia++) {
                int i3;
                i3 = ((idxAjj + ia) - iac) + 1;
                A_data[i3] += A_data[ia - 1] * c;
              }
              ix += i;
            }
          }
          ssq = 1.0 / ssq;
          i1 = idxAjj + nmj;
          nmj = ((((i1 - idxAjj) / 2) << 1) + idxAjj) + 2;
          ia0 = nmj - 2;
          for (ix = idxAjp1j; ix <= ia0; ix += 2) {
            __m128d r;
            r = _mm_loadu_pd(&A_data[ix - 1]);
            _mm_storeu_pd(&A_data[ix - 1], _mm_mul_pd(_mm_set1_pd(ssq), r));
          }
          for (ix = nmj; ix <= i1 + 1; ix++) {
            A_data[ix - 1] *= ssq;
          }
        }
        j++;
      } else {
        info = j + 1;
        exitg1 = true;
      }
    }
  }
  emxFree_real_T(&A);
  return info == 0;
}

/* End of code generation (isPositiveDefinite.c) */
