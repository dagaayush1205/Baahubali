/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xzlascl.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "xzlascl.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : double cfrom
 *                double cto
 *                double A[3]
 * Return Type  : void
 */
void b_xzlascl(double cfrom, double cto, double A[3])
{
  double cfromc;
  double ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    __m128d r;
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    r = _mm_loadu_pd(&A[0]);
    _mm_storeu_pd(&A[0], _mm_mul_pd(r, _mm_set1_pd(mul)));
    A[2] *= mul;
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                int n
 *                emxArray_real_T *A
 *                int lda
 * Return Type  : void
 */
void c_xzlascl(double cfrom, double cto, int m, int n, emxArray_real_T *A,
               int lda)
{
  double cfromc;
  double ctoc;
  double *A_data;
  int i;
  int j;
  boolean_T notdone;
  A_data = A->data;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (j = 0; j < n; j++) {
      int offset;
      offset = j * lda - 1;
      for (i = 0; i < m; i++) {
        int b_i;
        b_i = (offset + i) + 1;
        A_data[b_i] *= mul;
      }
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                int m
 *                emxArray_real_T *A
 * Return Type  : void
 */
void d_xzlascl(double cfrom, double cto, int m, emxArray_real_T *A)
{
  double cfromc;
  double ctoc;
  double *A_data;
  int i;
  boolean_T notdone;
  A_data = A->data;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    int scalarLB;
    int vectorUB;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    scalarLB = (m / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&A_data[i]);
      _mm_storeu_pd(&A_data[i], _mm_mul_pd(r, _mm_set1_pd(mul)));
    }
    for (i = scalarLB; i < m; i++) {
      A_data[i] *= mul;
    }
  }
}

/*
 * Arguments    : double cfrom
 *                double cto
 *                double A[9]
 * Return Type  : void
 */
void xzlascl(double cfrom, double cto, double A[9])
{
  double cfromc;
  double ctoc;
  int j;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    double cfrom1;
    double cto1;
    double mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((fabs(cfrom1) > fabs(ctoc)) && (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (fabs(cto1) > fabs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (j = 0; j < 3; j++) {
      int offset;
      offset = j * 3 - 1;
      A[offset + 1] *= mul;
      A[offset + 2] *= mul;
      A[offset + 3] *= mul;
    }
  }
}

/*
 * File trailer for xzlascl.c
 *
 * [EOF]
 */
