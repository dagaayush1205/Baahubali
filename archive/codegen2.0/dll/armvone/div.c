/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void binary_expand_op_9(emxArray_real_T *in1, const emxArray_real_T *in2,
                        const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  const double *in3_data;
  double *b_in1_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  in3_data = in3->data;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 1);
  if (in3->size[0] == 1) {
    if (in2->size[0] == 1) {
      loop_ub = in1->size[0];
    } else {
      loop_ub = in2->size[0];
    }
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_2_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] - in2_data[i * stride_1_0]) /
                    in3_data[i * stride_2_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(&b_in1);
}

/* End of code generation (div.c) */
