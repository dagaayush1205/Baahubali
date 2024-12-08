/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void xgeqp3(emxArray_real_T *A, emxArray_real_T *tau, emxArray_int32_T *jpvt)
{
  static const int offsets[4] = {0, 1, 2, 3};
  emxArray_real_T *vn1;
  emxArray_real_T *vn2;
  emxArray_real_T *work;
  double *A_data;
  double *tau_data;
  double *vn1_data;
  double *vn2_data;
  double *work_data;
  int b_i;
  int i;
  int ia;
  int k;
  int lastc;
  int m_tmp;
  int minmana;
  int n_tmp;
  int nmi;
  int *jpvt_data;
  boolean_T guard1;
  A_data = A->data;
  m_tmp = A->size[0];
  n_tmp = A->size[1];
  lastc = A->size[0];
  minmana = A->size[1];
  if (lastc <= minmana) {
    minmana = lastc;
  }
  i = tau->size[0];
  tau->size[0] = minmana;
  emxEnsureCapacity_real_T(tau, i);
  tau_data = tau->data;
  for (i = 0; i < minmana; i++) {
    tau_data[i] = 0.0;
  }
  emxInit_real_T(&work, 1);
  emxInit_real_T(&vn1, 1);
  emxInit_real_T(&vn2, 1);
  guard1 = false;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    guard1 = true;
  } else {
    lastc = A->size[0];
    minmana = A->size[1];
    if (lastc <= minmana) {
      minmana = lastc;
    }
    if (minmana < 1) {
      guard1 = true;
    } else {
      double smax;
      int minmn;
      i = jpvt->size[0] * jpvt->size[1];
      jpvt->size[0] = 1;
      jpvt->size[1] = n_tmp;
      emxEnsureCapacity_int32_T(jpvt, i);
      jpvt_data = jpvt->data;
      lastc = A->size[0];
      minmn = A->size[1];
      if (lastc <= minmn) {
        minmn = lastc;
      }
      i = work->size[0];
      work->size[0] = n_tmp;
      emxEnsureCapacity_real_T(work, i);
      work_data = work->data;
      i = vn1->size[0];
      vn1->size[0] = n_tmp;
      emxEnsureCapacity_real_T(vn1, i);
      vn1_data = vn1->data;
      i = vn2->size[0];
      vn2->size[0] = n_tmp;
      emxEnsureCapacity_real_T(vn2, i);
      vn2_data = vn2->data;
      for (k = 0; k < n_tmp; k++) {
        jpvt_data[k] = k + 1;
        work_data[k] = 0.0;
        smax = b_xnrm2(m_tmp, A, k * m_tmp + 1);
        vn1_data[k] = smax;
        vn2_data[k] = smax;
      }
      for (b_i = 0; b_i < minmn; b_i++) {
        double s;
        double temp2;
        int ii;
        int ip1;
        int lastv;
        int mmi;
        int pvt;
        ip1 = b_i + 2;
        lastv = b_i * m_tmp;
        ii = lastv + b_i;
        nmi = n_tmp - b_i;
        mmi = m_tmp - b_i;
        if (nmi < 1) {
          minmana = -1;
        } else {
          minmana = 0;
          if (nmi > 1) {
            smax = fabs(vn1_data[b_i]);
            for (k = 2; k <= nmi; k++) {
              s = fabs(vn1_data[(b_i + k) - 1]);
              if (s > smax) {
                minmana = k - 1;
                smax = s;
              }
            }
          }
        }
        pvt = b_i + minmana;
        if (pvt + 1 != b_i + 1) {
          minmana = pvt * m_tmp;
          for (k = 0; k < m_tmp; k++) {
            lastc = minmana + k;
            smax = A_data[lastc];
            i = lastv + k;
            A_data[lastc] = A_data[i];
            A_data[i] = smax;
          }
          minmana = jpvt_data[pvt];
          jpvt_data[pvt] = jpvt_data[b_i];
          jpvt_data[b_i] = minmana;
          vn1_data[pvt] = vn1_data[b_i];
          vn2_data[pvt] = vn2_data[b_i];
        }
        if (b_i + 1 < m_tmp) {
          temp2 = A_data[ii];
          pvt = ii + 2;
          tau_data[b_i] = 0.0;
          if (mmi > 0) {
            smax = b_xnrm2(mmi - 1, A, ii + 2);
            if (smax != 0.0) {
              s = fabs(A_data[ii]);
              smax = fabs(smax);
              if (s < smax) {
                s /= smax;
                smax *= sqrt(s * s + 1.0);
              } else if (s > smax) {
                smax /= s;
                smax = s * sqrt(smax * smax + 1.0);
              } else if (rtIsNaN(smax)) {
                smax = rtNaN;
              } else {
                smax = s * 1.4142135623730951;
              }
              if (A_data[ii] >= 0.0) {
                smax = -smax;
              }
              if (fabs(smax) < 1.0020841800044864E-292) {
                __m128d r;
                minmana = 0;
                i = ii + mmi;
                do {
                  minmana++;
                  lastc = (((((i - ii) - 1) / 2) << 1) + ii) + 2;
                  lastv = lastc - 2;
                  for (k = pvt; k <= lastv; k += 2) {
                    r = _mm_loadu_pd(&A_data[k - 1]);
                    _mm_storeu_pd(
                        &A_data[k - 1],
                        _mm_mul_pd(_mm_set1_pd(9.9792015476736E+291), r));
                  }
                  for (k = lastc; k <= i; k++) {
                    A_data[k - 1] *= 9.9792015476736E+291;
                  }
                  smax *= 9.9792015476736E+291;
                  temp2 *= 9.9792015476736E+291;
                } while ((fabs(smax) < 1.0020841800044864E-292) &&
                         (minmana < 20));
                s = fabs(temp2);
                smax = fabs(b_xnrm2(mmi - 1, A, ii + 2));
                if (s < smax) {
                  s /= smax;
                  smax *= sqrt(s * s + 1.0);
                } else if (s > smax) {
                  smax /= s;
                  smax = s * sqrt(smax * smax + 1.0);
                } else if (rtIsNaN(smax)) {
                  smax = rtNaN;
                } else {
                  smax = s * 1.4142135623730951;
                }
                if (temp2 >= 0.0) {
                  smax = -smax;
                }
                tau_data[b_i] = (smax - temp2) / smax;
                s = 1.0 / (temp2 - smax);
                for (k = pvt; k <= lastv; k += 2) {
                  r = _mm_loadu_pd(&A_data[k - 1]);
                  _mm_storeu_pd(&A_data[k - 1], _mm_mul_pd(_mm_set1_pd(s), r));
                }
                for (k = lastc; k <= i; k++) {
                  A_data[k - 1] *= s;
                }
                for (k = 0; k < minmana; k++) {
                  smax *= 1.0020841800044864E-292;
                }
                temp2 = smax;
              } else {
                tau_data[b_i] = (smax - A_data[ii]) / smax;
                s = 1.0 / (A_data[ii] - smax);
                i = ii + mmi;
                minmana = (((((i - ii) - 1) / 2) << 1) + ii) + 2;
                lastc = minmana - 2;
                for (k = pvt; k <= lastc; k += 2) {
                  __m128d r;
                  r = _mm_loadu_pd(&A_data[k - 1]);
                  _mm_storeu_pd(&A_data[k - 1], _mm_mul_pd(_mm_set1_pd(s), r));
                }
                for (k = minmana; k <= i; k++) {
                  A_data[k - 1] *= s;
                }
                temp2 = smax;
              }
            }
          }
          A_data[ii] = temp2;
        } else {
          tau_data[b_i] = 0.0;
        }
        if (b_i + 1 < n_tmp) {
          temp2 = A_data[ii];
          A_data[ii] = 1.0;
          pvt = (ii + m_tmp) + 1;
          if (tau_data[b_i] != 0.0) {
            boolean_T exitg2;
            lastv = mmi - 1;
            minmana = (ii + mmi) - 1;
            while ((lastv + 1 > 0) && (A_data[minmana] == 0.0)) {
              lastv--;
              minmana--;
            }
            lastc = nmi - 2;
            exitg2 = false;
            while ((!exitg2) && (lastc + 1 > 0)) {
              int exitg1;
              minmana = pvt + lastc * m_tmp;
              ia = minmana;
              do {
                exitg1 = 0;
                if (ia <= minmana + lastv) {
                  if (A_data[ia - 1] != 0.0) {
                    exitg1 = 1;
                  } else {
                    ia++;
                  }
                } else {
                  lastc--;
                  exitg1 = 2;
                }
              } while (exitg1 == 0);
              if (exitg1 == 1) {
                exitg2 = true;
              }
            }
          } else {
            lastv = -1;
            lastc = -1;
          }
          if (lastv + 1 > 0) {
            if (lastc + 1 != 0) {
              for (nmi = 0; nmi <= lastc; nmi++) {
                work_data[nmi] = 0.0;
              }
              nmi = 0;
              i = pvt + m_tmp * lastc;
              for (k = pvt; m_tmp < 0 ? k >= i : k <= i; k += m_tmp) {
                smax = 0.0;
                minmana = k + lastv;
                for (ia = k; ia <= minmana; ia++) {
                  smax += A_data[ia - 1] * A_data[(ii + ia) - k];
                }
                work_data[nmi] += smax;
                nmi++;
              }
            }
            if (!(-tau_data[b_i] == 0.0)) {
              for (nmi = 0; nmi <= lastc; nmi++) {
                if (work_data[nmi] != 0.0) {
                  smax = work_data[nmi] * -tau_data[b_i];
                  i = lastv + pvt;
                  for (minmana = pvt; minmana <= i; minmana++) {
                    A_data[minmana - 1] += A_data[(ii + minmana) - pvt] * smax;
                  }
                }
                pvt += m_tmp;
              }
            }
          }
          A_data[ii] = temp2;
        }
        for (nmi = ip1; nmi <= n_tmp; nmi++) {
          minmana = b_i + (nmi - 1) * m_tmp;
          smax = vn1_data[nmi - 1];
          if (smax != 0.0) {
            s = fabs(A_data[minmana]) / smax;
            s = 1.0 - s * s;
            if (s < 0.0) {
              s = 0.0;
            }
            temp2 = smax / vn2_data[nmi - 1];
            temp2 = s * (temp2 * temp2);
            if (temp2 <= 1.4901161193847656E-8) {
              if (b_i + 1 < m_tmp) {
                smax = b_xnrm2(mmi - 1, A, minmana + 2);
                vn1_data[nmi - 1] = smax;
                vn2_data[nmi - 1] = smax;
              } else {
                vn1_data[nmi - 1] = 0.0;
                vn2_data[nmi - 1] = 0.0;
              }
            } else {
              vn1_data[nmi - 1] = smax * sqrt(s);
            }
          }
        }
      }
    }
  }
  if (guard1) {
    i = jpvt->size[0] * jpvt->size[1];
    jpvt->size[0] = 1;
    jpvt->size[1] = n_tmp;
    emxEnsureCapacity_int32_T(jpvt, i);
    jpvt_data = jpvt->data;
    minmana = (n_tmp / 4) << 2;
    lastc = minmana - 4;
    for (nmi = 0; nmi <= lastc; nmi += 4) {
      _mm_storeu_si128(
          (__m128i *)&jpvt_data[nmi],
          _mm_add_epi32(
              _mm_add_epi32(_mm_set1_epi32(nmi),
                            _mm_loadu_si128((const __m128i *)&offsets[0])),
              _mm_set1_epi32(1)));
    }
    for (nmi = minmana; nmi < n_tmp; nmi++) {
      jpvt_data[nmi] = nmi + 1;
    }
  }
  emxFree_real_T(&vn2);
  emxFree_real_T(&vn1);
  emxFree_real_T(&work);
}

/* End of code generation (xgeqp3.c) */
