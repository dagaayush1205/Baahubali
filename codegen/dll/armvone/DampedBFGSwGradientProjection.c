/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: DampedBFGSwGradientProjection.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "DampedBFGSwGradientProjection.h"
#include "IKHelpers.h"
#include "any.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "diag.h"
#include "div.h"
#include "find.h"
#include "inv.h"
#include "isPositiveDefinite.h"
#include "minOrMax.h"
#include "mldivide.h"
#include "mtimes.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "xgeqp3.h"
#include "xzsvdc.h"
#include "coder_posix_time.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>

/* Function Declarations */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2);

static void binary_expand_op_12(emxArray_boolean_T *in1,
                                const emxArray_real_T *in2,
                                const c_robotics_core_internal_Damped *in3);

static double binary_expand_op_2(const emxArray_real_T *in1, double in2,
                                 const emxArray_real_T *in3,
                                 c_robotics_core_internal_Damped *in4,
                                 double in5[36], emxArray_real_T *in6,
                                 c_robotics_manip_internal_IKExt **out2);

static void binary_expand_op_3(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3);

static void binary_expand_op_4(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3, double in4);

static void binary_expand_op_5(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4, double in5);

static void binary_expand_op_6(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3);

static void binary_expand_op_7(emxArray_real_T *in1, const emxArray_real_T *in2,
                               double in3, const emxArray_real_T *in4);

static void d_DampedBFGSwGradientProjection(
    const c_robotics_core_internal_Damped *obj, const emxArray_real_T *x,
    emxArray_boolean_T *activeSet, emxArray_real_T *A);

static boolean_T
e_DampedBFGSwGradientProjection(const c_robotics_core_internal_Damped *obj,
                                const emxArray_real_T *xNew);

static void minus(emxArray_real_T *in1, const emxArray_real_T *in2);

static void plus(emxArray_real_T *in1, const emxArray_real_T *in2);

/* Function Definitions */
/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void b_minus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  double *b_in2_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in2, 1);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] - in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_boolean_T *in1
 *                const emxArray_real_T *in2
 *                const c_robotics_core_internal_Damped *in3
 * Return Type  : void
 */
static void binary_expand_op_12(emxArray_boolean_T *in1,
                                const emxArray_real_T *in2,
                                const c_robotics_core_internal_Damped *in3)
{
  const double *in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  boolean_T *in1_data;
  in2_data = in2->data;
  if (in3->ConstraintBound->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->ConstraintBound->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->ConstraintBound->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        (in2_data[i * stride_0_0] - in3->ConstraintBound->data[i * stride_1_0] >
         1.4901161193847656E-8);
  }
}

/*
 * Arguments    : const emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 *                c_robotics_core_internal_Damped *in4
 *                double in5[36]
 *                emxArray_real_T *in6
 *                c_robotics_manip_internal_IKExt **out2
 * Return Type  : double
 */
static double binary_expand_op_2(const emxArray_real_T *in1, double in2,
                                 const emxArray_real_T *in3,
                                 c_robotics_core_internal_Damped *in4,
                                 double in5[36], emxArray_real_T *in6,
                                 c_robotics_manip_internal_IKExt **out2)
{
  emxArray_real_T *b_in1;
  const double *in1_data;
  const double *in3_data;
  double out1;
  double *b_in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 1);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] + in2 * in3_data[i * stride_1_0];
  }
  out1 = IKHelpers_computeCost(b_in1, in4->ExtraArgs, in5, in6, out2);
  emxFree_real_T(&b_in1);
  return out1;
}

/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void binary_expand_op_3(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const double *in3_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in3->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in3->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in3->size[0] != 1);
  stride_1_1 = (in3->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
          in2 * in3_data[i1 * stride_1_0 + in3->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                double in4
 * Return Type  : void
 */
static void binary_expand_op_4(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3, double in4)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  double *b_in2_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int loop_ub;
  int scalarLB;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int vectorUB;
  in3_data = in3->data;
  in2_data = in2->data;
  loop_ub = in3->size[0];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&in3_data[i1]);
      _mm_storeu_pd(
          &in1_data[i1 + in1->size[0] * i],
          _mm_div_pd(_mm_add_pd(_mm_set1_pd(0.0),
                                _mm_mul_pd(r, _mm_set1_pd(in3_data[i]))),
                     _mm_set1_pd(in4)));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = in3_data[i1] * in3_data[i] / in4;
    }
  }
  emxInit_real_T(&b_in2, 2);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    scalarLB = in2->size[1];
  } else {
    scalarLB = in1->size[1];
  }
  b_in2->size[1] = scalarLB;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  vectorUB = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < scalarLB; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + b_in2->size[0] * i] =
          in2_data[i1 * vectorUB + in2->size[0] * aux_0_1] +
          in1_data[i1 * stride_1_0 + in1->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = scalarLB;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < scalarLB; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in2_data[i1 + b_in2->size[0] * i];
    }
  }
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                const emxArray_real_T *in3
 *                const emxArray_real_T *in4
 *                double in5
 * Return Type  : void
 */
static void binary_expand_op_5(emxArray_real_T *in1, const emxArray_real_T *in2,
                               const emxArray_real_T *in3,
                               const emxArray_real_T *in4, double in5)
{
  emxArray_real_T *b_in2;
  const double *in2_data;
  const double *in3_data;
  const double *in4_data;
  double *b_in2_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int scalarLB;
  int stride_1_0;
  int stride_1_1;
  int vectorUB;
  in4_data = in4->data;
  in3_data = in3->data;
  in2_data = in2->data;
  loop_ub = in3->size[0];
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  b_loop_ub = in4->size[0];
  i = in1->size[0] * in1->size[1];
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
      __m128d r;
      r = _mm_loadu_pd(&in3_data[i1]);
      _mm_storeu_pd(
          &in1_data[i1 + in1->size[0] * i],
          _mm_div_pd(_mm_add_pd(_mm_set1_pd(0.0),
                                _mm_mul_pd(r, _mm_set1_pd(in4_data[i]))),
                     _mm_set1_pd(in5)));
    }
    for (i1 = scalarLB; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = in3_data[i1] * in4_data[i] / in5;
    }
  }
  emxInit_real_T(&b_in2, 2);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0] * b_in2->size[1];
  b_in2->size[0] = loop_ub;
  if (in1->size[1] == 1) {
    b_loop_ub = in2->size[1];
  } else {
    b_loop_ub = in1->size[1];
  }
  b_in2->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  b_in2_data = b_in2->data;
  scalarLB = (in2->size[0] != 1);
  vectorUB = (in2->size[1] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_1 = (in1->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in2_data[i1 + b_in2->size[0] * i] =
          in2_data[i1 * scalarLB + in2->size[0] * aux_0_1] -
          in1_data[i1 * stride_1_0 + in1->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += vectorUB;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in2_data[i1 + b_in2->size[0] * i];
    }
  }
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                double in2
 *                const emxArray_real_T *in3
 * Return Type  : void
 */
static void binary_expand_op_6(emxArray_real_T *in1, double in2,
                               const emxArray_real_T *in3)
{
  emxArray_real_T *b_in2;
  const double *in3_data;
  double *in1_data;
  double *in2_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in2, 1);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(b_in2, i);
  in2_data = b_in2->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = in2 * in1_data[i * stride_0_0] + in3_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i];
  }
  emxFree_real_T(&b_in2);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 *                double in3
 *                const emxArray_real_T *in4
 * Return Type  : void
 */
static void binary_expand_op_7(emxArray_real_T *in1, const emxArray_real_T *in2,
                               double in3, const emxArray_real_T *in4)
{
  const double *in2_data;
  const double *in4_data;
  double *in1_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in4_data = in4->data;
  in2_data = in2->data;
  if (in4->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[i * stride_0_0] + in3 * in4_data[i * stride_1_0];
  }
}

/*
 * Arguments    : const c_robotics_core_internal_Damped *obj
 *                const emxArray_real_T *x
 *                emxArray_boolean_T *activeSet
 *                emxArray_real_T *A
 * Return Type  : void
 */
static void d_DampedBFGSwGradientProjection(
    const c_robotics_core_internal_Damped *obj, const emxArray_real_T *x,
    emxArray_boolean_T *activeSet, emxArray_real_T *A)
{
  emxArray_boolean_T *b_s;
  emxArray_int32_T *activeSetCols;
  emxArray_int32_T *b_activeSetCols;
  emxArray_int32_T *jpvt;
  emxArray_int32_T *jpvt1;
  emxArray_real_T *A_;
  emxArray_real_T *b_A_;
  emxArray_real_T *s;
  const double *x_data;
  double *A__data;
  double *s_data;
  int exponent;
  int i;
  int k;
  int loop_ub;
  int mc_tmp;
  int *activeSetCols_data;
  int *jpvt1_data;
  int *jpvt_data;
  boolean_T *activeSet_data;
  boolean_T *b_s_data;
  x_data = x->data;
  loop_ub = obj->ConstraintBound->size[0];
  k = activeSet->size[0];
  activeSet->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(activeSet, k);
  activeSet_data = activeSet->data;
  for (k = 0; k < loop_ub; k++) {
    activeSet_data[k] = false;
  }
  A->size[0] = x->size[0];
  A->size[1] = 0;
  if (obj->ConstraintsOn) {
    int inner_tmp;
    int irank;
    mc_tmp = obj->ConstraintMatrix->size[1];
    inner_tmp = obj->ConstraintMatrix->size[0];
    emxInit_real_T(&s, 1);
    k = s->size[0];
    s->size[0] = mc_tmp;
    emxEnsureCapacity_real_T(s, k);
    s_data = s->data;
    for (i = 0; i < mc_tmp; i++) {
      s_data[i] = 0.0;
    }
    for (k = 0; k < inner_tmp; k++) {
      for (i = 0; i < mc_tmp; i++) {
        s_data[i] += obj->ConstraintMatrix
                         ->data[i * obj->ConstraintMatrix->size[0] + k] *
                     x_data[k];
      }
    }
    emxInit_int32_T(&activeSetCols, 1);
    if (s->size[0] == obj->ConstraintBound->size[0]) {
      emxInit_boolean_T(&b_s);
      k = b_s->size[0];
      b_s->size[0] = mc_tmp;
      emxEnsureCapacity_boolean_T(b_s, k);
      b_s_data = b_s->data;
      for (k = 0; k < mc_tmp; k++) {
        b_s_data[k] = (s_data[k] >= obj->ConstraintBound->data[k]);
      }
      eml_find(b_s, activeSetCols);
      activeSetCols_data = activeSetCols->data;
      emxFree_boolean_T(&b_s);
    } else {
      binary_expand_op_11(activeSetCols, s, obj);
      activeSetCols_data = activeSetCols->data;
    }
    emxInit_real_T(&A_, 2);
    k = A_->size[0] * A_->size[1];
    A_->size[0] = inner_tmp;
    loop_ub = activeSetCols->size[0];
    A_->size[1] = activeSetCols->size[0];
    emxEnsureCapacity_real_T(A_, k);
    A__data = A_->data;
    for (k = 0; k < loop_ub; k++) {
      for (mc_tmp = 0; mc_tmp < inner_tmp; mc_tmp++) {
        A__data[mc_tmp + A_->size[0] * k] =
            obj->ConstraintMatrix
                ->data[mc_tmp + obj->ConstraintMatrix->size[0] *
                                    (activeSetCols_data[k] - 1)];
      }
    }
    irank = 0;
    emxInit_real_T(&b_A_, 2);
    if ((obj->ConstraintMatrix->size[0] != 0) &&
        (activeSetCols->size[0] != 0)) {
      double absx;
      boolean_T p;
      mc_tmp = obj->ConstraintMatrix->size[0] * activeSetCols->size[0];
      p = true;
      for (k = 0; k < mc_tmp; k++) {
        if ((!p) || (rtIsInf(A__data[k]) || rtIsNaN(A__data[k]))) {
          p = false;
        }
      }
      if (p) {
        if (obj->ConstraintMatrix->size[0] == 0) {
          s->size[0] = 0;
        } else {
          k = b_A_->size[0] * b_A_->size[1];
          b_A_->size[0] = A_->size[0];
          b_A_->size[1] = A_->size[1];
          emxEnsureCapacity_real_T(b_A_, k);
          s_data = b_A_->data;
          mc_tmp = A_->size[0] * A_->size[1] - 1;
          for (k = 0; k <= mc_tmp; k++) {
            s_data[k] = A__data[k];
          }
          xzsvdc(b_A_, s);
          s_data = s->data;
        }
      } else {
        mc_tmp =
            (int)fmin(obj->ConstraintMatrix->size[0], activeSetCols->size[0]);
        k = s->size[0];
        s->size[0] =
            (int)fmin(obj->ConstraintMatrix->size[0], activeSetCols->size[0]);
        emxEnsureCapacity_real_T(s, k);
        s_data = s->data;
        for (k = 0; k < mc_tmp; k++) {
          s_data[k] = rtNaN;
        }
      }
      mc_tmp = obj->ConstraintMatrix->size[0];
      k = activeSetCols->size[0];
      if (mc_tmp >= k) {
        k = mc_tmp;
      }
      if (obj->ConstraintMatrix->size[0] == 0) {
        mc_tmp = 0;
      } else {
        mc_tmp = k;
      }
      if (s->size[0] == 0) {
        absx = 0.0;
      } else {
        boolean_T exitg1;
        absx = fabs(s_data[0]);
        if (rtIsInf(absx) || rtIsNaN(absx)) {
          absx = rtNaN;
        } else if (absx < 4.4501477170144028E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &exponent);
          absx = ldexp(1.0, exponent - 53);
        }
        absx *= (double)mc_tmp;
        i = 0;
        exitg1 = false;
        while ((!exitg1) && (i <= s->size[0] - 1)) {
          if (rtIsInf(s_data[i]) || rtIsNaN(s_data[i])) {
            absx = 1.7976931348623157E+308;
            exitg1 = true;
          } else {
            i++;
          }
        }
      }
      k = 0;
      while ((k <= s->size[0] - 1) && (s_data[k] > absx)) {
        irank++;
        k++;
      }
    }
    if (irank < activeSetCols->size[0]) {
      k = b_A_->size[0] * b_A_->size[1];
      b_A_->size[0] = inner_tmp;
      b_A_->size[1] = inner_tmp;
      emxEnsureCapacity_real_T(b_A_, k);
      s_data = b_A_->data;
      emxInit_int32_T(&jpvt, 2);
      if (obj->ConstraintMatrix->size[0] > activeSetCols->size[0]) {
        for (mc_tmp = 0; mc_tmp < loop_ub; mc_tmp++) {
          for (i = 0; i < inner_tmp; i++) {
            s_data[i + b_A_->size[0] * mc_tmp] =
                obj->ConstraintMatrix
                    ->data[i + obj->ConstraintMatrix->size[0] *
                                   (activeSetCols_data[mc_tmp] - 1)];
          }
        }
        k = activeSetCols->size[0] + 1;
        for (mc_tmp = k; mc_tmp <= inner_tmp; mc_tmp++) {
          for (i = 0; i < inner_tmp; i++) {
            s_data[i + b_A_->size[0] * (mc_tmp - 1)] = 0.0;
          }
        }
        emxInit_int32_T(&jpvt1, 2);
        xgeqp3(b_A_, s, jpvt1);
        jpvt1_data = jpvt1->data;
        k = jpvt->size[0] * jpvt->size[1];
        jpvt->size[0] = 1;
        jpvt->size[1] = activeSetCols->size[0];
        emxEnsureCapacity_int32_T(jpvt, k);
        jpvt_data = jpvt->data;
        for (mc_tmp = 0; mc_tmp < loop_ub; mc_tmp++) {
          jpvt_data[mc_tmp] = jpvt1_data[mc_tmp];
        }
        emxFree_int32_T(&jpvt1);
      } else {
        xgeqp3(A_, s, jpvt);
        jpvt_data = jpvt->data;
      }
      if (irank < 1) {
        mc_tmp = 0;
      } else {
        mc_tmp = irank;
      }
      emxInit_int32_T(&b_activeSetCols, 1);
      k = b_activeSetCols->size[0];
      b_activeSetCols->size[0] = mc_tmp;
      emxEnsureCapacity_int32_T(b_activeSetCols, k);
      jpvt1_data = b_activeSetCols->data;
      for (k = 0; k < mc_tmp; k++) {
        jpvt1_data[k] = activeSetCols_data[jpvt_data[k] - 1];
      }
      emxFree_int32_T(&jpvt);
      k = activeSetCols->size[0];
      activeSetCols->size[0] = mc_tmp;
      emxEnsureCapacity_int32_T(activeSetCols, k);
      activeSetCols_data = activeSetCols->data;
      for (k = 0; k < mc_tmp; k++) {
        activeSetCols_data[k] = jpvt1_data[k];
      }
      emxFree_int32_T(&b_activeSetCols);
    }
    emxFree_real_T(&b_A_);
    emxFree_real_T(&s);
    emxFree_real_T(&A_);
    k = A->size[0] * A->size[1];
    A->size[0] = inner_tmp;
    loop_ub = activeSetCols->size[0];
    A->size[1] = activeSetCols->size[0];
    emxEnsureCapacity_real_T(A, k);
    s_data = A->data;
    for (k = 0; k < loop_ub; k++) {
      for (mc_tmp = 0; mc_tmp < inner_tmp; mc_tmp++) {
        s_data[mc_tmp + A->size[0] * k] =
            obj->ConstraintMatrix
                ->data[mc_tmp + obj->ConstraintMatrix->size[0] *
                                    (activeSetCols_data[k] - 1)];
      }
      activeSet_data[activeSetCols_data[k] - 1] = true;
    }
    emxFree_int32_T(&activeSetCols);
  }
}

/*
 * Arguments    : const c_robotics_core_internal_Damped *obj
 *                const emxArray_real_T *xNew
 * Return Type  : boolean_T
 */
static boolean_T
e_DampedBFGSwGradientProjection(const c_robotics_core_internal_Damped *obj,
                                const emxArray_real_T *xNew)
{
  emxArray_boolean_T *x;
  emxArray_real_T *C;
  const double *xNew_data;
  double *C_data;
  int i;
  int k;
  boolean_T flag;
  boolean_T *x_data;
  xNew_data = xNew->data;
  emxInit_real_T(&C, 1);
  emxInit_boolean_T(&x);
  if (obj->ConstraintsOn) {
    int inner;
    int mc_tmp;
    boolean_T exitg1;
    mc_tmp = obj->ConstraintMatrix->size[1];
    inner = obj->ConstraintMatrix->size[0];
    i = C->size[0];
    C->size[0] = mc_tmp;
    emxEnsureCapacity_real_T(C, i);
    C_data = C->data;
    for (i = 0; i < mc_tmp; i++) {
      C_data[i] = 0.0;
    }
    for (k = 0; k < inner; k++) {
      for (i = 0; i < mc_tmp; i++) {
        C_data[i] += obj->ConstraintMatrix
                         ->data[i * obj->ConstraintMatrix->size[0] + k] *
                     xNew_data[k];
      }
    }
    if (C->size[0] == obj->ConstraintBound->size[0]) {
      i = x->size[0];
      x->size[0] = mc_tmp;
      emxEnsureCapacity_boolean_T(x, i);
      x_data = x->data;
      for (i = 0; i < mc_tmp; i++) {
        x_data[i] =
            (C_data[i] - obj->ConstraintBound->data[i] > 1.4901161193847656E-8);
      }
    } else {
      binary_expand_op_12(x, C, obj);
      x_data = x->data;
    }
    flag = false;
    mc_tmp = 1;
    exitg1 = false;
    while ((!exitg1) && (mc_tmp <= x->size[0])) {
      if (x_data[mc_tmp - 1]) {
        flag = true;
        exitg1 = true;
      } else {
        mc_tmp++;
      }
    }
    if (flag) {
      flag = true;
    } else {
      flag = false;
    }
  } else {
    flag = false;
  }
  emxFree_boolean_T(&x);
  emxFree_real_T(&C);
  return flag;
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void minus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : emxArray_real_T *in1
 *                const emxArray_real_T *in2
 * Return Type  : void
 */
static void plus(emxArray_real_T *in1, const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const double *in2_data;
  double *b_in1_data;
  double *in1_data;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emxInit_real_T(&b_in1, 2);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(b_in1, i);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(in1, i);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(&b_in1);
}

/*
 * Arguments    : c_robotics_core_internal_Damped *obj
 *                emxArray_real_T *xSol
 *                double *err
 *                double *iter
 * Return Type  : c_robotics_core_internal_NLPSol
 */
c_robotics_core_internal_NLPSol
c_DampedBFGSwGradientProjection(c_robotics_core_internal_Damped *obj,
                                emxArray_real_T *xSol, double *err,
                                double *iter)
{
  __m128d r7;
  __m128d r8;
  c_robotics_manip_internal_IKExt *args;
  c_robotics_manip_internal_IKExt *r;
  c_robotics_manip_internal_IKExt *r10;
  c_robotics_manip_internal_IKExt *r11;
  c_robotics_manip_internal_IKExt *r12;
  c_robotics_manip_internal_IKExt *r13;
  emxArray_boolean_T *activeSet;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *inactiveConstraintIndices;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_real_T *A;
  emxArray_real_T *AIn;
  emxArray_real_T *C;
  emxArray_real_T *H;
  emxArray_real_T *Hg;
  emxArray_real_T *V;
  emxArray_real_T *a;
  emxArray_real_T *a__4;
  emxArray_real_T *alpha;
  emxArray_real_T *bIn;
  emxArray_real_T *b_A;
  emxArray_real_T *b_alpha;
  emxArray_real_T *c_A;
  emxArray_real_T *grad;
  emxArray_real_T *gradNew;
  emxArray_real_T *r1;
  emxArray_real_T *x;
  double a__3[36];
  double beta;
  double cost;
  double costNew;
  double lambda;
  double *AIn_data;
  double *A_data;
  double *C_data;
  double *H_data;
  double *Hg_data;
  double *alpha_data;
  double *bIn_data;
  double *gradNew_data;
  double *grad_data;
  double *xSol_data;
  double *x_data;
  int b_i;
  int b_loop_ub_tmp;
  int boffset;
  int i;
  int i1;
  int i2;
  int i3;
  int idxl;
  int j;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int n;
  int nc_tmp;
  int vectorUB_tmp;
  int *inactiveConstraintIndices_data;
  int *r9;
  boolean_T *activeSet_data;
  boolean_T *b_x_data;
  c_robotics_core_internal_NLPSol exitFlag;
  emxInit_real_T(&x, 1);
  n = obj->SeedInternal->size[0];
  i = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(x, i);
  x_data = x->data;
  loop_ub = obj->SeedInternal->size[0];
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = obj->SeedInternal->data[i];
  }
  obj->TimeObjInternal.StartTime.tv_sec =
      tic(&obj->TimeObjInternal.StartTime.tv_nsec);
  emxInit_real_T(&a__4, 2);
  cost = IKHelpers_computeCost(x, obj->ExtraArgs, a__3, a__4, &r);
  obj->ExtraArgs = r;
  args = obj->ExtraArgs;
  emxInit_real_T(&grad, 1);
  i = grad->size[0];
  grad->size[0] = args->GradTemp->size[0];
  emxEnsureCapacity_real_T(grad, i);
  grad_data = grad->data;
  loop_ub = args->GradTemp->size[0];
  for (i = 0; i < loop_ub; i++) {
    grad_data[i] = args->GradTemp->data[i];
  }
  emxInit_real_T(&H, 2);
  i = H->size[0] * H->size[1];
  H->size[0] = n;
  H->size[1] = n;
  emxEnsureCapacity_real_T(H, i);
  H_data = H->data;
  loop_ub_tmp = x->size[0] * x->size[0];
  for (i = 0; i < loop_ub_tmp; i++) {
    H_data[i] = 0.0;
  }
  if (x->size[0] > 0) {
    for (i1 = 0; i1 < n; i1++) {
      H_data[i1 + H->size[0] * i1] = 1.0;
    }
  }
  emxInit_boolean_T(&activeSet);
  emxInit_real_T(&A, 2);
  d_DampedBFGSwGradientProjection(obj, x, activeSet, A);
  A_data = A->data;
  activeSet_data = activeSet->data;
  i = A->size[1];
  emxInit_real_T(&C, 2);
  emxInit_real_T(&a, 2);
  emxInit_real_T(&b_A, 2);
  emxInit_real_T(&alpha, 2);
  emxInit_real_T(&r1, 2);
  for (i1 = 0; i1 < i; i1++) {
    idxl = A->size[0];
    nc_tmp = H->size[1];
    i2 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = H->size[1];
    emxEnsureCapacity_real_T(C, i2);
    C_data = C->data;
    for (j = 0; j < nc_tmp; j++) {
      boffset = j * H->size[0];
      C_data[j] = 0.0;
      for (k = 0; k < idxl; k++) {
        C_data[j] += A_data[k + A->size[0] * i1] * H_data[boffset + k];
      }
    }
    beta = 0.0;
    for (i2 = 0; i2 < nc_tmp; i2++) {
      beta += C_data[i2] * A_data[i2 + A->size[0] * i1];
    }
    lambda = 1.0 / beta;
    i2 = a->size[0] * a->size[1];
    a->size[0] = H->size[0];
    a->size[1] = H->size[1];
    emxEnsureCapacity_real_T(a, i2);
    bIn_data = a->data;
    b_loop_ub_tmp = H->size[0] * H->size[1];
    k = (b_loop_ub_tmp / 2) << 1;
    vectorUB_tmp = k - 2;
    for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
      r7 = _mm_loadu_pd(&H_data[i2]);
      _mm_storeu_pd(&bIn_data[i2], _mm_mul_pd(_mm_set1_pd(lambda), r7));
    }
    for (i2 = k; i2 < b_loop_ub_tmp; i2++) {
      bIn_data[i2] = lambda * H_data[i2];
    }
    i2 = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[0];
    emxEnsureCapacity_real_T(b_A, i2);
    bIn_data = b_A->data;
    for (i2 = 0; i2 < idxl; i2++) {
      nc_tmp = (A->size[0] / 2) << 1;
      j = nc_tmp - 2;
      for (i3 = 0; i3 <= j; i3 += 2) {
        r7 = _mm_loadu_pd(&A_data[i3 + A->size[0] * i1]);
        _mm_storeu_pd(
            &bIn_data[i3 + b_A->size[0] * i2],
            _mm_mul_pd(r7, _mm_set1_pd(A_data[i2 + A->size[0] * i1])));
      }
      for (i3 = nc_tmp; i3 < idxl; i3++) {
        bIn_data[i3 + b_A->size[0] * i2] =
            A_data[i3 + A->size[0] * i1] * A_data[i2 + A->size[0] * i1];
      }
    }
    mtimes(a, b_A, r1);
    mtimes(r1, H, alpha);
    bIn_data = alpha->data;
    if ((H->size[0] == alpha->size[0]) && (H->size[1] == alpha->size[1])) {
      for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
        r7 = _mm_loadu_pd(&H_data[i2]);
        r8 = _mm_loadu_pd(&bIn_data[i2]);
        _mm_storeu_pd(&H_data[i2], _mm_sub_pd(r7, r8));
      }
      for (i2 = k; i2 < b_loop_ub_tmp; i2++) {
        H_data[i2] -= bIn_data[i2];
      }
    } else {
      minus(H, alpha);
      H_data = H->data;
    }
  }
  i = xSol->size[0];
  xSol->size[0] = n;
  emxEnsureCapacity_real_T(xSol, i);
  xSol_data = xSol->data;
  for (i = 0; i < n; i++) {
    xSol_data[i] = x_data[i];
  }
  lambda = obj->MaxNumIterationInternal;
  i = (int)lambda;
  b_i = 0;
  emxInit_real_T(&b_alpha, 1);
  emxInit_real_T(&Hg, 1);
  emxInit_real_T(&bIn, 1);
  emxInit_real_T(&AIn, 2);
  emxInit_int32_T(&inactiveConstraintIndices, 1);
  emxInit_real_T(&gradNew, 1);
  emxInit_real_T(&V, 2);
  emxInit_int32_T(&r2, 1);
  emxInit_boolean_T(&b_x);
  emxInit_real_T(&c_A, 2);
  emxInit_int32_T(&r3, 1);
  emxInit_int32_T(&r4, 1);
  emxInit_int32_T(&r5, 1);
  emxInit_int32_T(&r6, 1);
  int exitg2;
  do {
    exitg2 = 0;
    if (b_i <= i - 1) {
      boolean_T flag;
      *iter = (double)b_i + 1.0;
      lambda = toc(obj->TimeObjInternal.StartTime.tv_sec,
                   obj->TimeObjInternal.StartTime.tv_nsec);
      flag = (lambda > obj->MaxTimeInternal);
      if (flag) {
        exitFlag = TimeLimitExceeded;
        *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
        exitg2 = 1;
      } else {
        double b_gamma;
        int inner;
        boolean_T guard1;
        boolean_T guard2;
        boolean_T guard3;
        if ((A->size[0] == 0) || (A->size[1] == 0)) {
          i2 = b_alpha->size[0];
          b_alpha->size[0] = 1;
          emxEnsureCapacity_real_T(b_alpha, i2);
          alpha_data = b_alpha->data;
          alpha_data[0] = 0.0;
        } else {
          loop_ub = A->size[1];
          i2 = b_A->size[0] * b_A->size[1];
          b_A->size[0] = A->size[1];
          j = A->size[0];
          b_A->size[1] = A->size[0];
          emxEnsureCapacity_real_T(b_A, i2);
          bIn_data = b_A->data;
          for (i2 = 0; i2 < j; i2++) {
            for (i3 = 0; i3 < loop_ub; i3++) {
              bIn_data[i3 + b_A->size[0] * i2] = A_data[i2 + A->size[0] * i3];
            }
          }
          b_mtimes(A, A, r1);
          mldivide(r1, b_A, alpha);
          c_mtimes(alpha, grad, b_alpha);
          alpha_data = b_alpha->data;
        }
        c_mtimes(H, grad, Hg);
        Hg_data = Hg->data;
        lambda = b_norm(Hg);
        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (lambda < obj->GradientTolerance) {
          boolean_T exitg3;
          loop_ub = b_alpha->size[0];
          i2 = b_x->size[0];
          b_x->size[0] = b_alpha->size[0];
          emxEnsureCapacity_boolean_T(b_x, i2);
          b_x_data = b_x->data;
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_x_data[i2] = (alpha_data[i2] <= 0.0);
          }
          flag = true;
          boffset = 1;
          exitg3 = false;
          while ((!exitg3) && (boffset <= b_x->size[0])) {
            if (!b_x_data[boffset - 1]) {
              flag = false;
              exitg3 = true;
            } else {
              boffset++;
            }
          }
          if (flag) {
            exitFlag = LocalMinimumFound;
            *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
            exitg2 = 1;
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
        if (guard3) {
          if (obj->ConstraintsOn && ((A->size[0] != 0) && (A->size[1] != 0))) {
            b_mtimes(A, A, r1);
            inv(r1, alpha);
            diag(alpha, gradNew);
            gradNew_data = gradNew->data;
            boffset = gradNew->size[0];
            nc_tmp = (gradNew->size[0] / 2) << 1;
            j = nc_tmp - 2;
            for (i1 = 0; i1 <= j; i1 += 2) {
              r7 = _mm_loadu_pd(&gradNew_data[i1]);
              _mm_storeu_pd(&gradNew_data[i1], _mm_sqrt_pd(r7));
            }
            for (i1 = nc_tmp; i1 < boffset; i1++) {
              gradNew_data[i1] = sqrt(gradNew_data[i1]);
            }
            if (b_alpha->size[0] == gradNew->size[0]) {
              loop_ub = b_alpha->size[0];
              nc_tmp = (b_alpha->size[0] / 2) << 1;
              j = nc_tmp - 2;
              for (i2 = 0; i2 <= j; i2 += 2) {
                r7 = _mm_loadu_pd(&alpha_data[i2]);
                r8 = _mm_loadu_pd(&gradNew_data[i2]);
                _mm_storeu_pd(&alpha_data[i2], _mm_div_pd(r7, r8));
              }
              for (i2 = nc_tmp; i2 < loop_ub; i2++) {
                alpha_data[i2] /= gradNew_data[i2];
              }
              b_gamma = maximum(b_alpha, &boffset);
            } else {
              b_gamma = binary_expand_op_10(b_alpha, gradNew, &boffset);
            }
            if (lambda < 0.5 * b_gamma) {
              eml_find(activeSet, r3);
              r9 = r3->data;
              loop_ub = r3->size[0];
              i2 = b_alpha->size[0];
              b_alpha->size[0] = r3->size[0];
              emxEnsureCapacity_real_T(b_alpha, i2);
              alpha_data = b_alpha->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                alpha_data[i2] = r9[i2];
              }
              b_loop_ub_tmp = (int)alpha_data[boffset - 1] - 1;
              activeSet_data[b_loop_ub_tmp] = false;
              idxl = activeSet->size[0];
              boffset = 0;
              for (nc_tmp = 0; nc_tmp < idxl; nc_tmp++) {
                if (activeSet_data[nc_tmp]) {
                  boffset++;
                }
              }
              i2 = r4->size[0];
              r4->size[0] = boffset;
              emxEnsureCapacity_int32_T(r4, i2);
              r9 = r4->data;
              boffset = 0;
              for (nc_tmp = 0; nc_tmp < idxl; nc_tmp++) {
                if (activeSet_data[nc_tmp]) {
                  r9[boffset] = nc_tmp;
                  boffset++;
                }
              }
              loop_ub = obj->ConstraintMatrix->size[0];
              i2 = A->size[0] * A->size[1];
              A->size[0] = loop_ub;
              j = r4->size[0];
              A->size[1] = r4->size[0];
              emxEnsureCapacity_real_T(A, i2);
              A_data = A->data;
              for (i2 = 0; i2 < j; i2++) {
                boffset = obj->ConstraintMatrix->size[0];
                for (i3 = 0; i3 < boffset; i3++) {
                  A_data[i3 + A->size[0] * i2] =
                      obj->ConstraintMatrix
                          ->data[i3 + obj->ConstraintMatrix->size[0] * r9[i2]];
                }
              }
              i2 = AIn->size[0] * AIn->size[1];
              AIn->size[0] = n;
              AIn->size[1] = n;
              emxEnsureCapacity_real_T(AIn, i2);
              AIn_data = AIn->data;
              for (i2 = 0; i2 < loop_ub_tmp; i2++) {
                AIn_data[i2] = 0.0;
              }
              if (n > 0) {
                for (i1 = 0; i1 < n; i1++) {
                  AIn_data[i1 + AIn->size[0] * i1] = 1.0;
                }
              }
              i2 = b_A->size[0] * b_A->size[1];
              b_A->size[0] = r4->size[0];
              b_A->size[1] = loop_ub;
              emxEnsureCapacity_real_T(b_A, i2);
              bIn_data = b_A->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                for (i3 = 0; i3 < j; i3++) {
                  bIn_data[i3 + b_A->size[0] * i2] =
                      A_data[i2 + A->size[0] * i3];
                }
              }
              b_mtimes(A, A, r1);
              mldivide(r1, b_A, alpha);
              mtimes(A, alpha, r1);
              bIn_data = r1->data;
              if ((AIn->size[0] == r1->size[0]) &&
                  (AIn->size[1] == r1->size[1])) {
                nc_tmp = (loop_ub_tmp / 2) << 1;
                j = nc_tmp - 2;
                for (i2 = 0; i2 <= j; i2 += 2) {
                  r7 = _mm_loadu_pd(&AIn_data[i2]);
                  r8 = _mm_loadu_pd(&bIn_data[i2]);
                  _mm_storeu_pd(&AIn_data[i2], _mm_sub_pd(r7, r8));
                }
                for (i2 = nc_tmp; i2 < loop_ub_tmp; i2++) {
                  AIn_data[i2] -= bIn_data[i2];
                }
              } else {
                minus(AIn, r1);
                AIn_data = AIn->data;
              }
              inner = obj->ConstraintMatrix->size[0];
              i2 = b_alpha->size[0];
              b_alpha->size[0] = inner;
              emxEnsureCapacity_real_T(b_alpha, i2);
              alpha_data = b_alpha->data;
              loop_ub = obj->ConstraintMatrix->size[0];
              for (i2 = 0; i2 < loop_ub; i2++) {
                alpha_data[i2] =
                    obj->ConstraintMatrix
                        ->data[i2 +
                               obj->ConstraintMatrix->size[0] * b_loop_ub_tmp];
              }
              nc_tmp = AIn->size[1];
              i2 = C->size[0] * C->size[1];
              C->size[0] = 1;
              C->size[1] = AIn->size[1];
              emxEnsureCapacity_real_T(C, i2);
              C_data = C->data;
              for (j = 0; j < nc_tmp; j++) {
                boffset = j * AIn->size[0];
                C_data[j] = 0.0;
                for (i1 = 0; i1 < inner; i1++) {
                  C_data[j] += alpha_data[i1] * AIn_data[boffset + i1];
                }
              }
              beta = 0.0;
              for (i2 = 0; i2 < nc_tmp; i2++) {
                beta += C_data[i2] * alpha_data[i2];
              }
              lambda = 1.0 / beta;
              i2 = a->size[0] * a->size[1];
              a->size[0] = AIn->size[0];
              a->size[1] = AIn->size[1];
              emxEnsureCapacity_real_T(a, i2);
              bIn_data = a->data;
              b_loop_ub_tmp = AIn->size[0] * AIn->size[1];
              nc_tmp = (b_loop_ub_tmp / 2) << 1;
              j = nc_tmp - 2;
              for (i2 = 0; i2 <= j; i2 += 2) {
                r7 = _mm_loadu_pd(&AIn_data[i2]);
                _mm_storeu_pd(&bIn_data[i2],
                              _mm_mul_pd(_mm_set1_pd(lambda), r7));
              }
              for (i2 = nc_tmp; i2 < b_loop_ub_tmp; i2++) {
                bIn_data[i2] = lambda * AIn_data[i2];
              }
              i2 = alpha->size[0] * alpha->size[1];
              alpha->size[0] = inner;
              alpha->size[1] = inner;
              emxEnsureCapacity_real_T(alpha, i2);
              bIn_data = alpha->data;
              for (i2 = 0; i2 < inner; i2++) {
                nc_tmp = (b_alpha->size[0] / 2) << 1;
                j = nc_tmp - 2;
                for (i3 = 0; i3 <= j; i3 += 2) {
                  r7 = _mm_loadu_pd(&alpha_data[i3]);
                  _mm_storeu_pd(&bIn_data[i3 + alpha->size[0] * i2],
                                _mm_mul_pd(r7, _mm_set1_pd(alpha_data[i2])));
                }
                for (i3 = nc_tmp; i3 < inner; i3++) {
                  bIn_data[i3 + alpha->size[0] * i2] =
                      alpha_data[i3] * alpha_data[i2];
                }
              }
              mtimes(a, alpha, r1);
              mtimes(r1, AIn, alpha);
              bIn_data = alpha->data;
              if ((H->size[0] == alpha->size[0]) &&
                  (H->size[1] == alpha->size[1])) {
                b_loop_ub_tmp = H->size[0] * H->size[1];
                nc_tmp = (b_loop_ub_tmp / 2) << 1;
                j = nc_tmp - 2;
                for (i2 = 0; i2 <= j; i2 += 2) {
                  r7 = _mm_loadu_pd(&H_data[i2]);
                  r8 = _mm_loadu_pd(&bIn_data[i2]);
                  _mm_storeu_pd(&H_data[i2], _mm_add_pd(r7, r8));
                }
                for (i2 = nc_tmp; i2 < b_loop_ub_tmp; i2++) {
                  H_data[i2] += bIn_data[i2];
                }
              } else {
                plus(H, alpha);
                H_data = H->data;
              }
              b_i++;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }
        if (guard2) {
          double m;
          double sigma;
          int exitg1;
          loop_ub = Hg->size[0];
          nc_tmp = (Hg->size[0] / 2) << 1;
          j = nc_tmp - 2;
          for (i2 = 0; i2 <= j; i2 += 2) {
            r7 = _mm_loadu_pd(&Hg_data[i2]);
            _mm_storeu_pd(&Hg_data[i2], _mm_mul_pd(r7, _mm_set1_pd(-1.0)));
          }
          for (i2 = nc_tmp; i2 < loop_ub; i2++) {
            Hg_data[i2] = -Hg_data[i2];
          }
          idxl = -2;
          if (obj->ConstraintsOn) {
            loop_ub = activeSet->size[0];
            i2 = b_x->size[0];
            b_x->size[0] = activeSet->size[0];
            emxEnsureCapacity_boolean_T(b_x, i2);
            b_x_data = b_x->data;
            for (i2 = 0; i2 < loop_ub; i2++) {
              b_x_data[i2] = !activeSet_data[i2];
            }
            if (any(b_x)) {
              boffset = 0;
              for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                if (b_x_data[nc_tmp]) {
                  boffset++;
                }
              }
              i2 = r2->size[0];
              r2->size[0] = boffset;
              emxEnsureCapacity_int32_T(r2, i2);
              r9 = r2->data;
              boffset = 0;
              for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                if (b_x_data[nc_tmp]) {
                  r9[boffset] = nc_tmp;
                  boffset++;
                }
              }
              loop_ub = r2->size[0];
              i2 = bIn->size[0];
              bIn->size[0] = r2->size[0];
              emxEnsureCapacity_real_T(bIn, i2);
              bIn_data = bIn->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                bIn_data[i2] = obj->ConstraintBound->data[r9[i2]];
              }
              inner = obj->ConstraintMatrix->size[0];
              i2 = AIn->size[0] * AIn->size[1];
              AIn->size[0] = inner;
              AIn->size[1] = r2->size[0];
              emxEnsureCapacity_real_T(AIn, i2);
              AIn_data = AIn->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                j = obj->ConstraintMatrix->size[0];
                for (i3 = 0; i3 < j; i3++) {
                  AIn_data[i3 + AIn->size[0] * i2] =
                      obj->ConstraintMatrix
                          ->data[i3 + obj->ConstraintMatrix->size[0] * r9[i2]];
                }
              }
              eml_find(b_x, r3);
              r9 = r3->data;
              j = r3->size[0];
              i2 = inactiveConstraintIndices->size[0];
              inactiveConstraintIndices->size[0] = r3->size[0];
              emxEnsureCapacity_int32_T(inactiveConstraintIndices, i2);
              inactiveConstraintIndices_data = inactiveConstraintIndices->data;
              for (i2 = 0; i2 < j; i2++) {
                inactiveConstraintIndices_data[i2] = r9[i2];
              }
              i2 = b_alpha->size[0];
              b_alpha->size[0] = r2->size[0];
              emxEnsureCapacity_real_T(b_alpha, i2);
              alpha_data = b_alpha->data;
              for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                alpha_data[nc_tmp] = 0.0;
              }
              for (i1 = 0; i1 < inner; i1++) {
                for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                  alpha_data[nc_tmp] +=
                      AIn_data[nc_tmp * AIn->size[0] + i1] * x_data[i1];
                }
              }
              i2 = gradNew->size[0];
              gradNew->size[0] = r2->size[0];
              emxEnsureCapacity_real_T(gradNew, i2);
              gradNew_data = gradNew->data;
              for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                gradNew_data[nc_tmp] = 0.0;
              }
              for (i1 = 0; i1 < inner; i1++) {
                for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                  gradNew_data[nc_tmp] +=
                      AIn_data[nc_tmp * AIn->size[0] + i1] * Hg_data[i1];
                }
              }
              if (bIn->size[0] == 1) {
                i1 = b_alpha->size[0];
              } else {
                i1 = bIn->size[0];
              }
              if ((bIn->size[0] == b_alpha->size[0]) &&
                  (i1 == gradNew->size[0])) {
                nc_tmp = (bIn->size[0] / 2) << 1;
                j = nc_tmp - 2;
                for (i2 = 0; i2 <= j; i2 += 2) {
                  __m128d r14;
                  r7 = _mm_loadu_pd(&bIn_data[i2]);
                  r8 = _mm_loadu_pd(&alpha_data[i2]);
                  r14 = _mm_loadu_pd(&gradNew_data[i2]);
                  _mm_storeu_pd(&bIn_data[i2],
                                _mm_div_pd(_mm_sub_pd(r7, r8), r14));
                }
                for (i2 = nc_tmp; i2 < loop_ub; i2++) {
                  bIn_data[i2] =
                      (bIn_data[i2] - alpha_data[i2]) / gradNew_data[i2];
                }
              } else {
                binary_expand_op_9(bIn, b_alpha, gradNew);
                bIn_data = bIn->data;
              }
              loop_ub = bIn->size[0];
              i2 = b_x->size[0];
              b_x->size[0] = bIn->size[0];
              emxEnsureCapacity_boolean_T(b_x, i2);
              b_x_data = b_x->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                b_x_data[i2] = (bIn_data[i2] > 0.0);
              }
              eml_find(b_x, r3);
              r9 = r3->data;
              j = r3->size[0];
              i2 = b_alpha->size[0];
              b_alpha->size[0] = r3->size[0];
              emxEnsureCapacity_real_T(b_alpha, i2);
              alpha_data = b_alpha->data;
              for (i2 = 0; i2 < j; i2++) {
                alpha_data[i2] = r9[i2];
              }
              if (b_alpha->size[0] != 0) {
                boffset = 0;
                for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                  if (b_x_data[nc_tmp]) {
                    boffset++;
                  }
                }
                i2 = r6->size[0];
                r6->size[0] = boffset;
                emxEnsureCapacity_int32_T(r6, i2);
                r9 = r6->data;
                boffset = 0;
                for (nc_tmp = 0; nc_tmp < loop_ub; nc_tmp++) {
                  if (b_x_data[nc_tmp]) {
                    r9[boffset] = nc_tmp;
                    boffset++;
                  }
                }
                loop_ub = r6->size[0];
                i2 = gradNew->size[0];
                gradNew->size[0] = r6->size[0];
                emxEnsureCapacity_real_T(gradNew, i2);
                gradNew_data = gradNew->data;
                for (i2 = 0; i2 < loop_ub; i2++) {
                  gradNew_data[i2] = bIn_data[r9[i2]];
                }
                lambda = minimum(gradNew, &boffset);
                idxl = inactiveConstraintIndices_data
                           [(int)alpha_data[boffset - 1] - 1] -
                       1;
              } else {
                lambda = 0.0;
              }
            } else {
              lambda = 0.0;
            }
          } else {
            lambda = 0.0;
          }
          if (lambda > 0.0) {
            b_gamma = fmin(1.0, lambda);
          } else {
            b_gamma = 1.0;
          }
          beta = obj->ArmijoRuleBeta;
          sigma = obj->ArmijoRuleSigma;
          if (x->size[0] == Hg->size[0]) {
            loop_ub = x->size[0];
            i2 = gradNew->size[0];
            gradNew->size[0] = x->size[0];
            emxEnsureCapacity_real_T(gradNew, i2);
            gradNew_data = gradNew->data;
            nc_tmp = (x->size[0] / 2) << 1;
            j = nc_tmp - 2;
            for (i2 = 0; i2 <= j; i2 += 2) {
              r7 = _mm_loadu_pd(&Hg_data[i2]);
              r8 = _mm_loadu_pd(&x_data[i2]);
              _mm_storeu_pd(
                  &gradNew_data[i2],
                  _mm_add_pd(r8, _mm_mul_pd(_mm_set1_pd(b_gamma), r7)));
            }
            for (i2 = nc_tmp; i2 < loop_ub; i2++) {
              gradNew_data[i2] = x_data[i2] + b_gamma * Hg_data[i2];
            }
            costNew = IKHelpers_computeCost(gradNew, obj->ExtraArgs, a__3, a__4,
                                            &r11);
          } else {
            costNew = binary_expand_op_2(x, b_gamma, Hg, obj, a__3, a__4, &r10);
            r11 = r10;
          }
          obj->ExtraArgs = r11;
          m = 0.0;
          double b_sigma;
          do {
            exitg1 = 0;
            b_sigma = 0.0;
            loop_ub = grad->size[0];
            for (i2 = 0; i2 < loop_ub; i2++) {
              b_sigma += -sigma * grad_data[i2] * (b_gamma * Hg_data[i2]);
            }
            if (cost - costNew < b_sigma) {
              flag = (b_gamma < obj->StepTolerance);
              if (flag) {
                exitFlag = StepSizeBelowMinimum;
                *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
                exitg1 = 1;
              } else {
                b_gamma *= beta;
                m++;
                if (x->size[0] == Hg->size[0]) {
                  loop_ub = x->size[0];
                  i2 = gradNew->size[0];
                  gradNew->size[0] = x->size[0];
                  emxEnsureCapacity_real_T(gradNew, i2);
                  gradNew_data = gradNew->data;
                  nc_tmp = (x->size[0] / 2) << 1;
                  j = nc_tmp - 2;
                  for (i2 = 0; i2 <= j; i2 += 2) {
                    r7 = _mm_loadu_pd(&Hg_data[i2]);
                    r8 = _mm_loadu_pd(&x_data[i2]);
                    _mm_storeu_pd(
                        &gradNew_data[i2],
                        _mm_add_pd(r8, _mm_mul_pd(_mm_set1_pd(b_gamma), r7)));
                  }
                  for (i2 = nc_tmp; i2 < loop_ub; i2++) {
                    gradNew_data[i2] = x_data[i2] + b_gamma * Hg_data[i2];
                  }
                  costNew = IKHelpers_computeCost(gradNew, obj->ExtraArgs, a__3,
                                                  a__4, &r13);
                } else {
                  costNew =
                      binary_expand_op_2(x, b_gamma, Hg, obj, a__3, a__4, &r12);
                  r13 = r12;
                }
                obj->ExtraArgs = r13;
              }
            } else {
              if (x->size[0] == Hg->size[0]) {
                loop_ub = x->size[0];
                i2 = xSol->size[0];
                xSol->size[0] = x->size[0];
                emxEnsureCapacity_real_T(xSol, i2);
                xSol_data = xSol->data;
                nc_tmp = (x->size[0] / 2) << 1;
                j = nc_tmp - 2;
                for (i2 = 0; i2 <= j; i2 += 2) {
                  r7 = _mm_loadu_pd(&Hg_data[i2]);
                  r8 = _mm_loadu_pd(&x_data[i2]);
                  _mm_storeu_pd(
                      &xSol_data[i2],
                      _mm_add_pd(r8, _mm_mul_pd(_mm_set1_pd(b_gamma), r7)));
                }
                for (i2 = nc_tmp; i2 < loop_ub; i2++) {
                  xSol_data[i2] = x_data[i2] + b_gamma * Hg_data[i2];
                }
              } else {
                binary_expand_op_7(xSol, x, b_gamma, Hg);
                xSol_data = xSol->data;
              }
              args = obj->ExtraArgs;
              loop_ub = args->GradTemp->size[0];
              i2 = gradNew->size[0];
              gradNew->size[0] = loop_ub;
              emxEnsureCapacity_real_T(gradNew, i2);
              gradNew_data = gradNew->data;
              j = args->GradTemp->size[0];
              for (i2 = 0; i2 < j; i2++) {
                gradNew_data[i2] = args->GradTemp->data[i2];
              }
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = 1;
          } else if ((m == 0.0) &&
                     (fabs(b_gamma - lambda) < 1.4901161193847656E-8)) {
            inner = obj->ConstraintMatrix->size[0];
            i2 = b_alpha->size[0];
            b_alpha->size[0] = inner;
            emxEnsureCapacity_real_T(b_alpha, i2);
            alpha_data = b_alpha->data;
            loop_ub = obj->ConstraintMatrix->size[0];
            for (i2 = 0; i2 < loop_ub; i2++) {
              alpha_data[i2] =
                  obj->ConstraintMatrix
                      ->data[i2 + obj->ConstraintMatrix->size[0] * idxl];
            }
            activeSet_data[idxl] = true;
            idxl = activeSet->size[0];
            boffset = 0;
            for (nc_tmp = 0; nc_tmp < idxl; nc_tmp++) {
              if (activeSet_data[nc_tmp]) {
                boffset++;
              }
            }
            i2 = r5->size[0];
            r5->size[0] = boffset;
            emxEnsureCapacity_int32_T(r5, i2);
            r9 = r5->data;
            boffset = 0;
            for (nc_tmp = 0; nc_tmp < idxl; nc_tmp++) {
              if (activeSet_data[nc_tmp]) {
                r9[boffset] = nc_tmp;
                boffset++;
              }
            }
            i2 = A->size[0] * A->size[1];
            A->size[0] = obj->ConstraintMatrix->size[0];
            loop_ub = r5->size[0];
            A->size[1] = r5->size[0];
            emxEnsureCapacity_real_T(A, i2);
            A_data = A->data;
            for (i2 = 0; i2 < loop_ub; i2++) {
              j = obj->ConstraintMatrix->size[0];
              for (i3 = 0; i3 < j; i3++) {
                A_data[i3 + A->size[0] * i2] =
                    obj->ConstraintMatrix
                        ->data[i3 + obj->ConstraintMatrix->size[0] * r9[i2]];
              }
            }
            nc_tmp = H->size[1];
            i2 = C->size[0] * C->size[1];
            C->size[0] = 1;
            C->size[1] = H->size[1];
            emxEnsureCapacity_real_T(C, i2);
            C_data = C->data;
            for (j = 0; j < nc_tmp; j++) {
              boffset = j * H->size[0];
              C_data[j] = 0.0;
              for (i1 = 0; i1 < inner; i1++) {
                C_data[j] += alpha_data[i1] * H_data[boffset + i1];
              }
            }
            beta = 0.0;
            for (i2 = 0; i2 < nc_tmp; i2++) {
              beta += C_data[i2] * alpha_data[i2];
            }
            lambda = 1.0 / beta;
            i2 = alpha->size[0] * alpha->size[1];
            alpha->size[0] = inner;
            alpha->size[1] = inner;
            emxEnsureCapacity_real_T(alpha, i2);
            bIn_data = alpha->data;
            for (i2 = 0; i2 < inner; i2++) {
              nc_tmp = (b_alpha->size[0] / 2) << 1;
              j = nc_tmp - 2;
              for (i3 = 0; i3 <= j; i3 += 2) {
                r7 = _mm_loadu_pd(&alpha_data[i3]);
                _mm_storeu_pd(&bIn_data[i3 + alpha->size[0] * i2],
                              _mm_mul_pd(r7, _mm_set1_pd(alpha_data[i2])));
              }
              for (i3 = nc_tmp; i3 < inner; i3++) {
                bIn_data[i3 + alpha->size[0] * i2] =
                    alpha_data[i3] * alpha_data[i2];
              }
            }
            mtimes(alpha, H, r1);
            mtimes(H, r1, alpha);
            bIn_data = alpha->data;
            if ((H->size[0] == alpha->size[0]) &&
                (H->size[1] == alpha->size[1])) {
              b_loop_ub_tmp = H->size[0] * H->size[1];
              nc_tmp = (b_loop_ub_tmp / 2) << 1;
              j = nc_tmp - 2;
              for (i2 = 0; i2 <= j; i2 += 2) {
                r7 = _mm_loadu_pd(&bIn_data[i2]);
                r8 = _mm_loadu_pd(&H_data[i2]);
                _mm_storeu_pd(
                    &H_data[i2],
                    _mm_sub_pd(r8, _mm_mul_pd(_mm_set1_pd(lambda), r7)));
              }
              for (i2 = nc_tmp; i2 < b_loop_ub_tmp; i2++) {
                H_data[i2] -= lambda * bIn_data[i2];
              }
            } else {
              binary_expand_op_3(H, lambda, alpha);
              H_data = H->data;
            }
            guard1 = true;
          } else {
            if (gradNew->size[0] == grad->size[0]) {
              i2 = grad->size[0];
              grad->size[0] = loop_ub;
              emxEnsureCapacity_real_T(grad, i2);
              grad_data = grad->data;
              nc_tmp = (gradNew->size[0] / 2) << 1;
              j = nc_tmp - 2;
              for (i2 = 0; i2 <= j; i2 += 2) {
                r7 = _mm_loadu_pd(&gradNew_data[i2]);
                r8 = _mm_loadu_pd(&grad_data[i2]);
                _mm_storeu_pd(&grad_data[i2], _mm_sub_pd(r7, r8));
              }
              for (i2 = nc_tmp; i2 < loop_ub; i2++) {
                grad_data[i2] = gradNew_data[i2] - grad_data[i2];
              }
            } else {
              b_minus(grad, gradNew);
              grad_data = grad->data;
            }
            i2 = c_A->size[0] * c_A->size[1];
            c_A->size[0] = 1;
            loop_ub = grad->size[0];
            c_A->size[1] = grad->size[0];
            emxEnsureCapacity_real_T(c_A, i2);
            bIn_data = c_A->data;
            k = (grad->size[0] / 2) << 1;
            vectorUB_tmp = k - 2;
            for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
              r7 = _mm_loadu_pd(&grad_data[i2]);
              _mm_storeu_pd(&bIn_data[i2], _mm_mul_pd(_mm_set1_pd(0.2), r7));
            }
            for (i2 = k; i2 < loop_ub; i2++) {
              bIn_data[i2] = 0.2 * grad_data[i2];
            }
            inner = c_A->size[1];
            nc_tmp = H->size[1];
            i2 = C->size[0] * C->size[1];
            C->size[0] = 1;
            C->size[1] = H->size[1];
            emxEnsureCapacity_real_T(C, i2);
            C_data = C->data;
            for (j = 0; j < nc_tmp; j++) {
              boffset = j * H->size[0];
              C_data[j] = 0.0;
              for (i1 = 0; i1 < inner; i1++) {
                C_data[j] += bIn_data[i1] * H_data[boffset + i1];
              }
            }
            lambda = 0.0;
            b_loop_ub_tmp = Hg->size[0];
            for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
              lambda += Hg_data[i2] * grad_data[i2];
            }
            beta = 0.0;
            for (i2 = 0; i2 < nc_tmp; i2++) {
              beta += C_data[i2] * grad_data[i2];
            }
            if (lambda < beta) {
              i2 = c_A->size[0] * c_A->size[1];
              c_A->size[0] = 1;
              c_A->size[1] = grad->size[0];
              emxEnsureCapacity_real_T(c_A, i2);
              bIn_data = c_A->data;
              for (i2 = 0; i2 <= vectorUB_tmp; i2 += 2) {
                r7 = _mm_loadu_pd(&grad_data[i2]);
                _mm_storeu_pd(&bIn_data[i2], _mm_mul_pd(_mm_set1_pd(0.8), r7));
              }
              for (i2 = k; i2 < loop_ub; i2++) {
                bIn_data[i2] = 0.8 * grad_data[i2];
              }
              inner = c_A->size[1];
              i2 = C->size[0] * C->size[1];
              C->size[0] = 1;
              C->size[1] = H->size[1];
              emxEnsureCapacity_real_T(C, i2);
              C_data = C->data;
              for (j = 0; j < nc_tmp; j++) {
                boffset = j * H->size[0];
                C_data[j] = 0.0;
                for (i1 = 0; i1 < inner; i1++) {
                  C_data[j] += bIn_data[i1] * H_data[boffset + i1];
                }
              }
              i2 = c_A->size[0] * c_A->size[1];
              c_A->size[0] = 1;
              c_A->size[1] = H->size[1];
              emxEnsureCapacity_real_T(c_A, i2);
              bIn_data = c_A->data;
              beta = 0.0;
              for (j = 0; j < nc_tmp; j++) {
                boffset = j * H->size[0];
                bIn_data[j] = 0.0;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  bIn_data[j] += grad_data[i1] * H_data[boffset + i1];
                }
                beta += C_data[j] * grad_data[j];
              }
              b_gamma = 0.0;
              for (i2 = 0; i2 < nc_tmp; i2++) {
                b_gamma += bIn_data[i2] * grad_data[i2];
              }
              lambda = 0.0;
              for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
                lambda += Hg_data[i2] * grad_data[i2];
              }
              lambda = beta / (b_gamma - lambda);
            } else {
              lambda = 1.0;
            }
            i2 = r1->size[0] * r1->size[1];
            r1->size[0] = H->size[0];
            r1->size[1] = H->size[1];
            emxEnsureCapacity_real_T(r1, i2);
            bIn_data = r1->data;
            boffset = H->size[0] * H->size[1];
            nc_tmp = (boffset / 2) << 1;
            j = nc_tmp - 2;
            for (i2 = 0; i2 <= j; i2 += 2) {
              r7 = _mm_loadu_pd(&H_data[i2]);
              _mm_storeu_pd(&bIn_data[i2],
                            _mm_mul_pd(_mm_set1_pd(1.0 - lambda), r7));
            }
            for (i2 = nc_tmp; i2 < boffset; i2++) {
              bIn_data[i2] = (1.0 - lambda) * H_data[i2];
            }
            c_mtimes(r1, grad, b_alpha);
            alpha_data = b_alpha->data;
            if (Hg->size[0] == b_alpha->size[0]) {
              nc_tmp = (Hg->size[0] / 2) << 1;
              j = nc_tmp - 2;
              for (i2 = 0; i2 <= j; i2 += 2) {
                r7 = _mm_loadu_pd(&Hg_data[i2]);
                r8 = _mm_loadu_pd(&alpha_data[i2]);
                _mm_storeu_pd(
                    &Hg_data[i2],
                    _mm_add_pd(_mm_mul_pd(_mm_set1_pd(lambda), r7), r8));
              }
              for (i2 = nc_tmp; i2 < b_loop_ub_tmp; i2++) {
                Hg_data[i2] = lambda * Hg_data[i2] + alpha_data[i2];
              }
            } else {
              binary_expand_op_6(Hg, lambda, b_alpha);
              Hg_data = Hg->data;
            }
            lambda = 0.0;
            b_loop_ub_tmp = Hg->size[0];
            for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
              lambda += Hg_data[i2] * grad_data[i2];
            }
            i2 = AIn->size[0] * AIn->size[1];
            AIn->size[0] = n;
            AIn->size[1] = n;
            emxEnsureCapacity_real_T(AIn, i2);
            AIn_data = AIn->data;
            for (i2 = 0; i2 < loop_ub_tmp; i2++) {
              AIn_data[i2] = 0.0;
            }
            if (n > 0) {
              for (i1 = 0; i1 < n; i1++) {
                AIn_data[i1 + AIn->size[0] * i1] = 1.0;
              }
            }
            if ((AIn->size[0] == Hg->size[0]) &&
                (grad->size[0] == AIn->size[1])) {
              i2 = V->size[0] * V->size[1];
              V->size[0] = Hg->size[0];
              V->size[1] = grad->size[0];
              emxEnsureCapacity_real_T(V, i2);
              bIn_data = V->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                nc_tmp = (Hg->size[0] / 2) << 1;
                j = nc_tmp - 2;
                for (i3 = 0; i3 <= j; i3 += 2) {
                  r7 = _mm_loadu_pd(&Hg_data[i3]);
                  r8 = _mm_loadu_pd(&AIn_data[i3 + AIn->size[0] * i2]);
                  _mm_storeu_pd(
                      &bIn_data[i3 + V->size[0] * i2],
                      _mm_sub_pd(
                          r8,
                          _mm_div_pd(
                              _mm_add_pd(
                                  _mm_set1_pd(0.0),
                                  _mm_mul_pd(r7, _mm_set1_pd(grad_data[i2]))),
                              _mm_set1_pd(lambda))));
                }
                for (i3 = nc_tmp; i3 < b_loop_ub_tmp; i3++) {
                  bIn_data[i3 + V->size[0] * i2] =
                      AIn_data[i3 + AIn->size[0] * i2] -
                      Hg_data[i3] * grad_data[i2] / lambda;
                }
              }
            } else {
              binary_expand_op_5(V, AIn, Hg, grad, lambda);
            }
            mtimes(V, H, r1);
            d_mtimes(r1, V, alpha);
            bIn_data = alpha->data;
            if ((alpha->size[0] == Hg->size[0]) &&
                (Hg->size[0] == alpha->size[1])) {
              loop_ub = Hg->size[0];
              i2 = H->size[0] * H->size[1];
              H->size[0] = Hg->size[0];
              H->size[1] = Hg->size[0];
              emxEnsureCapacity_real_T(H, i2);
              H_data = H->data;
              for (i2 = 0; i2 < loop_ub; i2++) {
                nc_tmp = (Hg->size[0] / 2) << 1;
                j = nc_tmp - 2;
                for (i3 = 0; i3 <= j; i3 += 2) {
                  r7 = _mm_loadu_pd(&Hg_data[i3]);
                  r8 = _mm_loadu_pd(&bIn_data[i3 + alpha->size[0] * i2]);
                  _mm_storeu_pd(
                      &H_data[i3 + H->size[0] * i2],
                      _mm_add_pd(
                          r8, _mm_div_pd(
                                  _mm_add_pd(
                                      _mm_set1_pd(0.0),
                                      _mm_mul_pd(r7, _mm_set1_pd(Hg_data[i2]))),
                                  _mm_set1_pd(lambda))));
                }
                for (i3 = nc_tmp; i3 < loop_ub; i3++) {
                  H_data[i3 + H->size[0] * i2] =
                      bIn_data[i3 + alpha->size[0] * i2] +
                      Hg_data[i3] * Hg_data[i2] / lambda;
                }
              }
            } else {
              binary_expand_op_4(H, alpha, Hg, lambda);
              H_data = H->data;
            }
            boffset = H->size[0];
            idxl = H->size[1];
            if (boffset <= idxl) {
              idxl = boffset;
            }
            i2 = AIn->size[0] * AIn->size[1];
            AIn->size[0] = H->size[0];
            AIn->size[1] = H->size[1];
            emxEnsureCapacity_real_T(AIn, i2);
            AIn_data = AIn->data;
            b_loop_ub_tmp = H->size[0] * H->size[1];
            for (i2 = 0; i2 < b_loop_ub_tmp; i2++) {
              AIn_data[i2] = 0.0;
            }
            if (idxl > 0) {
              for (i1 = 0; i1 < idxl; i1++) {
                AIn_data[i1 + AIn->size[0] * i1] = 1.0;
              }
            }
            if (AIn->size[0] == 1) {
              loop_ub = H->size[0];
            } else {
              loop_ub = AIn->size[0];
            }
            i2 = alpha->size[0] * alpha->size[1];
            alpha->size[0] = loop_ub;
            if (AIn->size[1] == 1) {
              j = H->size[1];
            } else {
              j = AIn->size[1];
            }
            alpha->size[1] = j;
            emxEnsureCapacity_real_T(alpha, i2);
            bIn_data = alpha->data;
            boffset = (H->size[0] != 1);
            idxl = (H->size[1] != 1);
            nc_tmp = (AIn->size[0] != 1);
            k = (AIn->size[1] != 1);
            vectorUB_tmp = 0;
            b_loop_ub_tmp = 0;
            for (i2 = 0; i2 < j; i2++) {
              for (i3 = 0; i3 < loop_ub; i3++) {
                bIn_data[i3 + alpha->size[0] * i2] =
                    H_data[i3 * boffset + H->size[0] * vectorUB_tmp] +
                    1.4901161193847656E-8 *
                        AIn_data[i3 * nc_tmp + AIn->size[0] * b_loop_ub_tmp];
              }
              b_loop_ub_tmp += k;
              vectorUB_tmp += idxl;
            }
            i2 = AIn->size[0] * AIn->size[1];
            AIn->size[0] = loop_ub;
            AIn->size[1] = j;
            emxEnsureCapacity_real_T(AIn, i2);
            AIn_data = AIn->data;
            for (i2 = 0; i2 < j; i2++) {
              for (i3 = 0; i3 < loop_ub; i3++) {
                AIn_data[i3 + AIn->size[0] * i2] =
                    bIn_data[i3 + alpha->size[0] * i2];
              }
            }
            if (!isPositiveDefinite(AIn)) {
              exitFlag = HessianNotPositiveSemidefinite;
              *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
              exitg2 = 1;
            } else {
              guard1 = true;
            }
          }
        }
        if (guard1) {
          if (e_DampedBFGSwGradientProjection(obj, xSol)) {
            loop_ub = x->size[0];
            i = xSol->size[0];
            xSol->size[0] = x->size[0];
            emxEnsureCapacity_real_T(xSol, i);
            xSol_data = xSol->data;
            for (i = 0; i < loop_ub; i++) {
              xSol_data[i] = x_data[i];
            }
            exitFlag = SearchDirectionInvalid;
            *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
            exitg2 = 1;
          } else {
            loop_ub = xSol->size[0];
            i2 = x->size[0];
            x->size[0] = xSol->size[0];
            emxEnsureCapacity_real_T(x, i2);
            x_data = x->data;
            for (i2 = 0; i2 < loop_ub; i2++) {
              x_data[i2] = xSol_data[i2];
            }
            loop_ub = gradNew->size[0];
            i2 = grad->size[0];
            grad->size[0] = gradNew->size[0];
            emxEnsureCapacity_real_T(grad, i2);
            grad_data = grad->data;
            for (i2 = 0; i2 < loop_ub; i2++) {
              grad_data[i2] = gradNew_data[i2];
            }
            cost = costNew;
            b_i++;
          }
        }
      }
    } else {
      exitFlag = IterationLimitExceeded;
      *err = IKHelpers_evaluateSolution(obj->ExtraArgs);
      *iter = obj->MaxNumIterationInternal;
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  emxFree_real_T(&r1);
  emxFree_real_T(&alpha);
  emxFree_real_T(&b_A);
  emxFree_real_T(&a);
  emxFree_int32_T(&r6);
  emxFree_int32_T(&r5);
  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_real_T(&c_A);
  emxFree_boolean_T(&b_x);
  emxFree_real_T(&C);
  emxFree_int32_T(&r2);
  emxFree_real_T(&V);
  emxFree_real_T(&gradNew);
  emxFree_int32_T(&inactiveConstraintIndices);
  emxFree_real_T(&AIn);
  emxFree_real_T(&bIn);
  emxFree_real_T(&Hg);
  emxFree_real_T(&b_alpha);
  emxFree_real_T(&A);
  emxFree_boolean_T(&activeSet);
  emxFree_real_T(&H);
  emxFree_real_T(&grad);
  emxFree_real_T(&a__4);
  emxFree_real_T(&x);
  return exitFlag;
}

/*
 * File trailer for DampedBFGSwGradientProjection.c
 *
 * [EOF]
 */
