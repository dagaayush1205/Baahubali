/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void svd(const double A[9], double U[9], double s[3], double V[9])
{
  __m128d r;
  double b_A[9];
  double e[3];
  double work[3];
  double anrm;
  double cscale;
  double nrm;
  double rt;
  double snorm;
  double sqds;
  int i;
  int ii;
  int k;
  int kase;
  int m;
  int q;
  int qjj;
  int qp1;
  int qq;
  int qq_tmp;
  int scalarLB;
  boolean_T doscale;
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (i = 0; i < 9; i++) {
    b_A[i] = A[i];
    U[i] = 0.0;
    V[i] = 0.0;
  }
  doscale = false;
  anrm = xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    xzlascl(anrm, cscale, b_A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    xzlascl(anrm, cscale, b_A);
  }
  for (q = 0; q < 2; q++) {
    boolean_T apply_transform;
    qp1 = q + 2;
    qq_tmp = q + 3 * q;
    qq = qq_tmp + 1;
    apply_transform = false;
    nrm = xnrm2(3 - q, b_A, qq_tmp + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq_tmp] < 0.0) {
        nrm = -nrm;
      }
      s[q] = nrm;
      if (fabs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        i = (qq_tmp - q) + 3;
        scalarLB = ((((i - qq_tmp) / 2) << 1) + qq_tmp) + 1;
        qjj = scalarLB - 2;
        for (k = qq; k <= qjj; k += 2) {
          r = _mm_loadu_pd(&b_A[k - 1]);
          _mm_storeu_pd(&b_A[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
        }
        for (k = scalarLB; k <= i; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        i = (qq_tmp - q) + 3;
        scalarLB = ((((i - qq_tmp) / 2) << 1) + qq_tmp) + 1;
        qjj = scalarLB - 2;
        for (k = qq; k <= qjj; k += 2) {
          r = _mm_loadu_pd(&b_A[k - 1]);
          _mm_storeu_pd(&b_A[k - 1], _mm_div_pd(r, _mm_set1_pd(s[q])));
        }
        for (k = scalarLB; k <= i; k++) {
          b_A[k - 1] /= s[q];
        }
      }
      b_A[qq_tmp]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + 3 * (kase - 1);
      if (apply_transform) {
        xaxpy(3 - q,
              -(xdotc(3 - q, b_A, qq_tmp + 1, b_A, qjj + 1) / b_A[qq_tmp]),
              qq_tmp + 1, b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 4; ii++) {
      kase = (ii + 3 * q) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 1) {
      nrm = c_xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          scalarLB = ((((2 - q) / 2) << 1) + q) + 2;
          qjj = scalarLB - 2;
          for (k = qp1; k <= qjj; k += 2) {
            r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
          }
          for (k = scalarLB; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          scalarLB = ((((2 - q) / 2) << 1) + q) + 2;
          qjj = scalarLB - 2;
          for (k = qp1; k <= qjj; k += 2) {
            r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_div_pd(r, _mm_set1_pd(nrm)));
          }
          for (k = scalarLB; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 4; ii++) {
          work[ii - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          d_xaxpy(e[kase - 1], b_A, 3 * (kase - 1) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          e_xaxpy(-e[kase - 1] / e[1], work, b_A, 3 * (kase - 1) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        V[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (q = 1; q >= 0; q--) {
    qp1 = q + 2;
    qq = q + 3 * q;
    if (s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + 3 * (kase - 1)) + 1;
        xaxpy(3 - q, -(xdotc(3 - q, U, qq + 1, U, qjj) / U[qq]), qq + 1, U,
              qjj);
      }
      scalarLB = q + 3;
      qjj = q + 1;
      for (ii = q + 1; ii <= qjj; ii += 2) {
        i = (ii + 3 * q) - 1;
        r = _mm_loadu_pd(&U[i]);
        _mm_storeu_pd(&U[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
      }
      for (ii = scalarLB; ii < 4; ii++) {
        kase = 3 * q + 2;
        U[kase] = -U[kase];
      }
      U[qq]++;
      if (q - 1 >= 0) {
        U[3 * q] = 0.0;
      }
    } else {
      U[3 * q] = 0.0;
      U[3 * q + 1] = 0.0;
      U[3 * q + 2] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (q = 2; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      xaxpy(2, -(xdotc(2, V, 2, V, 5) / V[1]), 2, V, 5);
      xaxpy(2, -(xdotc(2, V, 2, V, 8) / V[1]), 2, V, 8);
    }
    V[3 * q] = 0.0;
    V[3 * q + 1] = 0.0;
    V[3 * q + 2] = 0.0;
    V[q + 3 * q] = 1.0;
  }
  qq = 0;
  snorm = 0.0;
  for (q = 0; q < 3; q++) {
    nrm = s[q];
    if (nrm != 0.0) {
      rt = fabs(nrm);
      nrm /= rt;
      s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }
      kase = 3 * q;
      scalarLB = kase + 3;
      qjj = kase + 1;
      for (k = kase + 1; k <= qjj; k += 2) {
        r = _mm_loadu_pd(&U[k - 1]);
        _mm_storeu_pd(&U[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
      }
      for (k = scalarLB; k <= scalarLB; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 3) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = fabs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        scalarLB = kase + 3;
        qjj = kase + 1;
        for (k = kase + 1; k <= qjj; k += 2) {
          r = _mm_loadu_pd(&V[k - 1]);
          _mm_storeu_pd(&V[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
        }
        for (k = scalarLB; k <= scalarLB; k++) {
          V[k - 1] *= nrm;
        }
      }
    }
    snorm = fmax(snorm, fmax(fabs(s[q]), fabs(e[q])));
  }
  while ((m + 2 > 0) && (qq < 75)) {
    boolean_T exitg1;
    qq_tmp = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = fabs(e[ii - 1]);
      if ((nrm <= 2.2204460492503131E-16 * (fabs(s[ii - 1]) + fabs(s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= ii)) {
        qjj = kase;
        if (kase == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = fabs(e[kase - 1]);
          }
          if (kase > ii + 1) {
            nrm += fabs(e[kase - 2]);
          }
          rt = fabs(s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == ii) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        ii = qjj;
      }
    }
    switch (kase) {
    case 1: {
      rt = e[m];
      e[m] = 0.0;
      for (k = qq_tmp; k >= ii + 1; k--) {
        double sm;
        sm = xrotg(&s[k - 1], &rt, &sqds);
        if (k > ii + 1) {
          rt = -sqds * e[0];
          e[0] *= sm;
        }
        xrot(V, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
      }
    } break;
    case 2: {
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (k = ii + 1; k <= m + 2; k++) {
        double b;
        double sm;
        sm = xrotg(&s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        xrot(U, 3 * (k - 1) + 1, 3 * (ii - 1) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      double sm;
      nrm = s[m + 1];
      scale =
          fmax(fmax(fmax(fmax(fabs(nrm), fabs(s[m])), fabs(e[m])), fabs(s[ii])),
               fabs(e[ii]));
      sm = nrm / scale;
      nrm = s[m] / scale;
      rt = e[m] / scale;
      sqds = s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (k = ii + 1; k <= qq_tmp; k++) {
        sm = xrotg(&rt, &nrm, &sqds);
        if (k > ii + 1) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * s[k];
        s[k] *= sm;
        i = 3 * (k - 1) + 1;
        kase = 3 * k + 1;
        xrot(V, i, kase, sm, sqds);
        s[k - 1] = sm * b + sqds * nrm;
        sm = xrotg(&s[k - 1], &rt, &sqds);
        b = e[k - 1];
        rt = sm * b + sqds * s[k];
        s[k] = -sqds * b + sm * s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        xrot(U, i, kase, sm, sqds);
      }
      e[m] = rt;
      qq++;
    } break;
    default:
      if (s[ii] < 0.0) {
        s[ii] = -s[ii];
        kase = 3 * ii;
        scalarLB = kase + 3;
        qjj = kase + 1;
        for (k = kase + 1; k <= qjj; k += 2) {
          r = _mm_loadu_pd(&V[k - 1]);
          _mm_storeu_pd(&V[k - 1], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        }
        for (k = scalarLB; k <= scalarLB; k++) {
          V[k - 1] = -V[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (s[ii] < s[qp1])) {
        rt = s[ii];
        s[ii] = s[qp1];
        s[qp1] = rt;
        i = 3 * ii + 1;
        kase = 3 * (ii + 1) + 1;
        xswap(V, i, kase);
        xswap(U, i, kase);
        ii = qp1;
        qp1++;
      }
      qq = 0;
      m--;
      break;
    }
  }
  if (doscale) {
    b_xzlascl(cscale, anrm, s);
  }
}

/* End of code generation (svd.c) */
