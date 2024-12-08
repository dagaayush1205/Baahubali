/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void b_xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  double *y_data;
  int k;
  y_data = y->data;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y_data[i] += a * y_data[(ix0 + k) - 1];
    }
  }
}

void c_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0)
{
  const double *x_data;
  double *y_data;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    int i;
    int scalarLB;
    int vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      i = (iy0 + k) - 1;
      r = _mm_loadu_pd(&y_data[i]);
      _mm_storeu_pd(
          &y_data[i],
          _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(a),
                                   _mm_loadu_pd(&x_data[(ix0 + k) - 1]))));
    }
    for (k = scalarLB; k < n; k++) {
      i = (iy0 + k) - 1;
      y_data[i] += a * x_data[(ix0 + k) - 1];
    }
  }
}

void d_xaxpy(double a, const double x[9], int ix0, double y[3])
{
  if (!(a == 0.0)) {
    __m128d r;
    r = _mm_loadu_pd(&y[1]);
    _mm_storeu_pd(&y[1], _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(a),
                                                  _mm_loadu_pd(&x[ix0 - 1]))));
  }
}

void e_xaxpy(double a, const double x[3], double y[9], int iy0)
{
  if (!(a == 0.0)) {
    __m128d r;
    __m128d r1;
    int i;
    i = iy0 - 1;
    r = _mm_loadu_pd(&x[1]);
    r = _mm_mul_pd(_mm_set1_pd(a), r);
    r1 = _mm_loadu_pd(&y[i]);
    r = _mm_add_pd(r1, r);
    _mm_storeu_pd(&y[i], r);
  }
}

void xaxpy(int n, double a, int ix0, double y[9], int iy0)
{
  int k;
  if (!(a == 0.0)) {
    for (k = 0; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y[i] += a * y[(ix0 + k) - 1];
    }
  }
}

/* End of code generation (xaxpy.c) */
