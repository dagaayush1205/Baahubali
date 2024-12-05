/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: minOrMax.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "minOrMax.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                int *out2
 * Return Type  : double
 */
double binary_expand_op_10(const emxArray_real_T *in1,
                           const emxArray_real_T *in2, int *out2)
{
  emxArray_real_T *b_in1;
  const double *in1_data;
  const double *in2_data;
  double out1;
  double *b_in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 1);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] / in2_data[i * stride_1_0];
  }
  out1 = maximum(b_in1, out2);
  emxFree_real_T(&b_in1);
  return out1;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int *idx
 * Return Type  : double
 */
double maximum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double ex;
  int k;
  int last_tmp;
  x_data = x->data;
  last_tmp = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if ((x_data[0] < ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last_tmp)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      int i;
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last_tmp; k++) {
        double d;
        d = x_data[k - 1];
        if (ex < d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                int *idx
 * Return Type  : double
 */
double minimum(const emxArray_real_T *x, int *idx)
{
  const double *x_data;
  double ex;
  int k;
  int last_tmp;
  x_data = x->data;
  last_tmp = x->size[0];
  if (x->size[0] <= 2) {
    if (x->size[0] == 1) {
      ex = x_data[0];
      *idx = 1;
    } else {
      ex = x_data[x->size[0] - 1];
      if ((x_data[0] > ex) || (rtIsNaN(x_data[0]) && (!rtIsNaN(ex)))) {
        *idx = x->size[0];
      } else {
        ex = x_data[0];
        *idx = 1;
      }
    }
  } else {
    if (!rtIsNaN(x_data[0])) {
      *idx = 1;
    } else {
      boolean_T exitg1;
      *idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last_tmp)) {
        if (!rtIsNaN(x_data[k - 1])) {
          *idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (*idx == 0) {
      ex = x_data[0];
      *idx = 1;
    } else {
      int i;
      ex = x_data[*idx - 1];
      i = *idx + 1;
      for (k = i; k <= last_tmp; k++) {
        double d;
        d = x_data[k - 1];
        if (ex > d) {
          ex = d;
          *idx = k;
        }
      }
    }
  }
  return ex;
}

/*
 * File trailer for minOrMax.c
 *
 * [EOF]
 */
