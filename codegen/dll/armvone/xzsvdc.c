/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: xzsvdc.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "xzsvdc.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xnrm2.h"
#include "xrotg.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *A
 *                emxArray_real_T *S
 * Return Type  : void
 */
void xzsvdc(emxArray_real_T *A, emxArray_real_T *S)
{
  emxArray_real_T *e;
  emxArray_real_T *s;
  emxArray_real_T *work;
  double anrm;
  double cscale;
  double nrm;
  double rt;
  double sm;
  double *A_data;
  double *e_data;
  double *s_data;
  double *work_data;
  int i;
  int ii;
  int k;
  int m;
  int minnp;
  int ns;
  int p_tmp;
  int q;
  int qs;
  boolean_T doscale;
  A_data = A->data;
  m = A->size[0];
  p_tmp = A->size[1];
  if (A->size[0] + 1 <= A->size[1]) {
    ns = A->size[0];
  } else {
    ns = A->size[1] - 1;
  }
  qs = A->size[0];
  minnp = A->size[1];
  if (qs <= minnp) {
    minnp = qs;
  }
  emxInit_real_T(&s, 1);
  i = s->size[0];
  s->size[0] = ns + 1;
  emxEnsureCapacity_real_T(s, i);
  s_data = s->data;
  for (i = 0; i <= ns; i++) {
    s_data[i] = 0.0;
  }
  emxInit_real_T(&e, 1);
  i = e->size[0];
  e->size[0] = A->size[1];
  emxEnsureCapacity_real_T(e, i);
  e_data = e->data;
  for (i = 0; i < p_tmp; i++) {
    e_data[i] = 0.0;
  }
  emxInit_real_T(&work, 1);
  i = work->size[0];
  work->size[0] = A->size[0];
  emxEnsureCapacity_real_T(work, i);
  work_data = work->data;
  for (i = 0; i < m; i++) {
    work_data[i] = 0.0;
  }
  doscale = false;
  cscale = 0.0;
  anrm = b_xzlangeM(A);
  if ((A->size[0] != 0) && (A->size[1] != 0)) {
    double b_r;
    double snorm;
    int nct;
    int nmq;
    int nrt;
    int qp1;
    int qq;
    int vectorUB;
    boolean_T guard1;
    cscale = anrm;
    guard1 = false;
    if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
      doscale = true;
      cscale = 6.7178761075670888E-139;
      guard1 = true;
    } else if (anrm > 1.4885657073574029E+138) {
      doscale = true;
      cscale = 1.4885657073574029E+138;
      guard1 = true;
    }
    if (guard1) {
      c_xzlascl(anrm, cscale, A->size[0], A->size[1], A, A->size[0]);
      A_data = A->data;
    }
    if (A->size[1] >= 2) {
      qs = A->size[1] - 2;
    } else {
      qs = 0;
    }
    nrt = A->size[0];
    if (qs <= nrt) {
      nrt = qs;
    }
    if (A->size[0] >= 1) {
      qs = A->size[0] - 1;
    } else {
      qs = 0;
    }
    nct = A->size[1];
    if (qs <= nct) {
      nct = qs;
    }
    if (nct >= nrt) {
      i = nct;
    } else {
      i = nrt;
    }
    for (q = 0; q < i; q++) {
      __m128d r;
      boolean_T apply_transform;
      qp1 = q + 2;
      qq = (q + m * q) + 1;
      nmq = (m - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = b_xnrm2(nmq + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            ns = qq + nmq;
            qs = ((((ns - qq) + 1) / 2) << 1) + qq;
            vectorUB = qs - 2;
            for (k = qq; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&A_data[k - 1]);
              _mm_storeu_pd(&A_data[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
            }
            for (k = qs; k <= ns; k++) {
              A_data[k - 1] *= nrm;
            }
          } else {
            ns = qq + nmq;
            qs = ((((ns - qq) + 1) / 2) << 1) + qq;
            vectorUB = qs - 2;
            for (k = qq; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&A_data[k - 1]);
              _mm_storeu_pd(&A_data[k - 1],
                            _mm_div_pd(r, _mm_set1_pd(s_data[q])));
            }
            for (k = qs; k <= ns; k++) {
              A_data[k - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (qs = qp1; qs <= p_tmp; qs++) {
        ns = q + m * (qs - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (nmq + 1 >= 1) {
            for (k = 0; k <= nmq; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[ns + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          b_xaxpy(nmq + 1, nrm, qq, A, ns + 1);
          A_data = A->data;
        }
        e_data[qs - 1] = A_data[ns];
      }
      if (q + 1 <= nrt) {
        ns = p_tmp - q;
        nrm = b_xnrm2(ns - 1, e, q + 2);
        if (nrm == 0.0) {
          e_data[q] = 0.0;
        } else {
          if (e_data[q + 1] < 0.0) {
            e_data[q] = -nrm;
          } else {
            e_data[q] = nrm;
          }
          nrm = e_data[q];
          if (fabs(e_data[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e_data[q];
            ns += q;
            qs = (((((ns - q) - 1) / 2) << 1) + q) + 2;
            vectorUB = qs - 2;
            for (k = qp1; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&e_data[k - 1]);
              _mm_storeu_pd(&e_data[k - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
            }
            for (k = qs; k <= ns; k++) {
              e_data[k - 1] *= nrm;
            }
          } else {
            ns += q;
            qs = (((((ns - q) - 1) / 2) << 1) + q) + 2;
            vectorUB = qs - 2;
            for (k = qp1; k <= vectorUB; k += 2) {
              r = _mm_loadu_pd(&e_data[k - 1]);
              _mm_storeu_pd(&e_data[k - 1], _mm_div_pd(r, _mm_set1_pd(nrm)));
            }
            for (k = qs; k <= ns; k++) {
              e_data[k - 1] /= nrm;
            }
          }
          e_data[q + 1]++;
          e_data[q] = -e_data[q];
          if (q + 2 <= m) {
            for (ii = qp1; ii <= m; ii++) {
              work_data[ii - 1] = 0.0;
            }
            for (qs = qp1; qs <= p_tmp; qs++) {
              c_xaxpy(nmq, e_data[qs - 1], A, (q + m * (qs - 1)) + 2, work,
                      q + 2);
              work_data = work->data;
            }
            for (qs = qp1; qs <= p_tmp; qs++) {
              c_xaxpy(nmq, -e_data[qs - 1] / e_data[q + 1], work, q + 2, A,
                      (q + m * (qs - 1)) + 2);
              A_data = A->data;
            }
          }
        }
      }
    }
    qs = A->size[1];
    m = A->size[0] + 1;
    if (qs <= m) {
      m = qs;
    }
    if (nct < A->size[1]) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (A->size[0] < m) {
      s_data[m - 1] = 0.0;
    }
    if (nrt + 1 < m) {
      e_data[nrt] = A_data[nrt + A->size[0] * (m - 1)];
    }
    e_data[m - 1] = 0.0;
    nmq = m;
    qq = 0;
    snorm = 0.0;
    for (q = 0; q < m; q++) {
      nrm = s_data[q];
      if (s_data[q] != 0.0) {
        rt = fabs(s_data[q]);
        b_r = s_data[q] / rt;
        nrm = rt;
        s_data[q] = rt;
        if (q + 1 < m) {
          e_data[q] /= b_r;
        }
      }
      if ((q + 1 < m) && (e_data[q] != 0.0)) {
        rt = fabs(e_data[q]);
        b_r = rt / e_data[q];
        e_data[q] = rt;
        s_data[q + 1] *= b_r;
      }
      snorm = fmax(snorm, fmax(fabs(nrm), fabs(e_data[q])));
    }
    while ((m > 0) && (qq < 75)) {
      boolean_T exitg1;
      vectorUB = m - 1;
      ii = m - 1;
      exitg1 = false;
      while (!(exitg1 || (ii == 0))) {
        nrm = fabs(e_data[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[ii - 1]) + fabs(s_data[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e_data[ii - 1] = 0.0;
          exitg1 = true;
        } else {
          ii--;
        }
      }
      if (ii == m - 1) {
        ns = 4;
      } else {
        qs = m;
        ns = m;
        exitg1 = false;
        while ((!exitg1) && (ns >= ii)) {
          qs = ns;
          if (ns == ii) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m) {
              nrm = fabs(e_data[ns - 1]);
            }
            if (ns > ii + 1) {
              nrm += fabs(e_data[ns - 2]);
            }
            rt = fabs(s_data[ns - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (qs == ii) {
          ns = 3;
        } else if (qs == m) {
          ns = 1;
        } else {
          ns = 2;
          ii = qs;
        }
      }
      switch (ns) {
      case 1: {
        rt = e_data[m - 2];
        e_data[m - 2] = 0.0;
        for (k = vectorUB; k >= ii + 1; k--) {
          double sqds;
          sqds = xrotg(&s_data[k - 1], &rt, &sm);
          if (k > ii + 1) {
            b_r = e_data[k - 2];
            rt = -sm * b_r;
            e_data[k - 2] = b_r * sqds;
          }
        }
      } break;
      case 2: {
        rt = e_data[ii - 1];
        e_data[ii - 1] = 0.0;
        for (k = ii + 1; k <= m; k++) {
          double sqds;
          sqds = xrotg(&s_data[k - 1], &rt, &sm);
          b_r = e_data[k - 1];
          rt = -sm * b_r;
          e_data[k - 1] = b_r * sqds;
        }
      } break;
      case 3: {
        double scale;
        double sqds;
        nrm = s_data[m - 1];
        rt = s_data[m - 2];
        b_r = e_data[m - 2];
        scale = fmax(
            fmax(fmax(fmax(fabs(nrm), fabs(rt)), fabs(b_r)), fabs(s_data[ii])),
            fabs(e_data[ii]));
        sm = nrm / scale;
        nrm = rt / scale;
        rt = b_r / scale;
        sqds = s_data[ii] / scale;
        b_r = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b_r != 0.0) || (nrm != 0.0)) {
          rt = sqrt(b_r * b_r + nrm);
          if (b_r < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b_r + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e_data[ii] / scale);
        for (k = ii + 1; k < m; k++) {
          sqds = xrotg(&rt, &nrm, &sm);
          if (k > ii + 1) {
            e_data[k - 2] = rt;
          }
          b_r = e_data[k - 1];
          nrm = s_data[k - 1];
          e_data[k - 1] = sqds * b_r - sm * nrm;
          rt = sm * s_data[k];
          s_data[k] *= sqds;
          s_data[k - 1] = sqds * nrm + sm * b_r;
          sqds = xrotg(&s_data[k - 1], &rt, &sm);
          b_r = e_data[k - 1];
          rt = sqds * b_r + sm * s_data[k];
          s_data[k] = -sm * b_r + sqds * s_data[k];
          nrm = sm * e_data[k];
          e_data[k] *= sqds;
        }
        e_data[m - 2] = rt;
        qq++;
      } break;
      default:
        if (s_data[ii] < 0.0) {
          s_data[ii] = -s_data[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < nmq) && (s_data[ii] < s_data[qp1])) {
          rt = s_data[ii];
          s_data[ii] = s_data[qp1];
          s_data[qp1] = rt;
          ii = qp1;
          qp1++;
        }
        qq = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  emxFree_real_T(&e);
  i = S->size[0];
  S->size[0] = minnp;
  emxEnsureCapacity_real_T(S, i);
  A_data = S->data;
  for (k = 0; k < minnp; k++) {
    A_data[k] = s_data[k];
  }
  emxFree_real_T(&s);
  if (doscale) {
    d_xzlascl(cscale, anrm, minnp, S);
  }
}

/*
 * File trailer for xzsvdc.c
 *
 * [EOF]
 */
