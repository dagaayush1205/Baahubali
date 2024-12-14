/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * inv.c
 *
 * Code generation for function 'inv'
 *
 */

/* Include files */
#include "inv.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "xzgetrf.h"

/* Function Definitions */
void inv(const emxArray_real_T *x, emxArray_real_T *y)
{
  emxArray_int32_T *ipiv;
  emxArray_int32_T *p;
  emxArray_real_T *b_x;
  const double *x_data;
  double *b_x_data;
  double *y_data;
  int b_i;
  int i;
  int j;
  int k;
  int *ipiv_data;
  int *p_data;
  x_data = x->data;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    int yk;
    i = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    yk = x->size[0] * x->size[1];
    for (i = 0; i < yk; i++) {
      y_data[i] = x_data[i];
    }
  } else {
    int i1;
    int n_tmp;
    int yk;
    n_tmp = x->size[0];
    i = y->size[0] * y->size[1];
    y->size[0] = x->size[0];
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, i);
    y_data = y->data;
    yk = x->size[0] * x->size[1];
    for (i = 0; i < yk; i++) {
      y_data[i] = 0.0;
    }
    emxInit_real_T(&b_x, 2);
    i = b_x->size[0] * b_x->size[1];
    b_x->size[0] = x->size[0];
    b_x->size[1] = x->size[1];
    emxEnsureCapacity_real_T(b_x, i);
    b_x_data = b_x->data;
    for (i = 0; i < yk; i++) {
      b_x_data[i] = x_data[i];
    }
    emxInit_int32_T(&ipiv, 2);
    xzgetrf(x->size[0], x->size[0], b_x, x->size[0], ipiv);
    ipiv_data = ipiv->data;
    b_x_data = b_x->data;
    emxInit_int32_T(&p, 2);
    i = p->size[0] * p->size[1];
    p->size[0] = 1;
    p->size[1] = x->size[0];
    emxEnsureCapacity_int32_T(p, i);
    p_data = p->data;
    p_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n_tmp; k++) {
      yk++;
      p_data[k - 1] = yk;
    }
    i = ipiv->size[1];
    for (k = 0; k < i; k++) {
      i1 = ipiv_data[k];
      if (i1 > k + 1) {
        yk = p_data[i1 - 1];
        p_data[i1 - 1] = p_data[k];
        p_data[k] = yk;
      }
    }
    emxFree_int32_T(&ipiv);
    for (k = 0; k < n_tmp; k++) {
      i = p_data[k];
      y_data[k + y->size[0] * (i - 1)] = 1.0;
      for (j = k + 1; j <= n_tmp; j++) {
        if (y_data[(j + y->size[0] * (i - 1)) - 1] != 0.0) {
          i1 = j + 1;
          for (b_i = i1; b_i <= n_tmp; b_i++) {
            y_data[(b_i + y->size[0] * (i - 1)) - 1] -=
                y_data[(j + y->size[0] * (i - 1)) - 1] *
                b_x_data[(b_i + b_x->size[0] * (j - 1)) - 1];
          }
        }
      }
    }
    emxFree_int32_T(&p);
    for (j = 0; j < n_tmp; j++) {
      yk = x->size[0] * j - 1;
      for (k = n_tmp; k >= 1; k--) {
        double d;
        int kAcol;
        kAcol = x->size[0] * (k - 1) - 1;
        i = k + yk;
        d = y_data[i];
        if (d != 0.0) {
          y_data[i] = d / b_x_data[k + kAcol];
          for (b_i = 0; b_i <= k - 2; b_i++) {
            i1 = (b_i + yk) + 1;
            y_data[i1] -= y_data[i] * b_x_data[(b_i + kAcol) + 1];
          }
        }
      }
    }
    emxFree_real_T(&b_x);
  }
}

/* End of code generation (inv.c) */
