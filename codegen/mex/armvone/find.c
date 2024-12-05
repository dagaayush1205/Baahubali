/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo lh_emlrtRSI = {
    138,                                                          /* lineNo */
    "eml_find",                                                   /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    376,                                                          /* lineNo */
    "find_first_indices",                                         /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    396,                                                          /* lineNo */
    "find_first_indices",                                         /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pathName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    386,                                                          /* lineNo */
    1,                                                            /* colNo */
    "find_first_indices",                                         /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo id_emlrtRTEI = {
    363,                                                          /* lineNo */
    24,                                                           /* colNo */
    "find",                                                       /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo jd_emlrtRTEI = {
    138,                                                          /* lineNo */
    9,                                                            /* colNo */
    "find",                                                       /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

/* Function Definitions */
void binary_expand_op_4(const emlrtStack *sp, emxArray_int32_T *in1,
                        const emlrtRSInfo in2, const emxArray_real_T *in3,
                        const c_robotics_core_internal_Damped *in4)
{
  emlrtStack st;
  emxArray_boolean_T *b_in3;
  const real_T *in3_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *b_in3_data;
  st.prev = sp;
  st.tls = sp->tls;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_boolean_T(sp, &b_in3, &yf_emlrtRTEI);
  if (in4->ConstraintBound->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->ConstraintBound->size[0];
  }
  i = b_in3->size[0];
  b_in3->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, b_in3, i, &yf_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->ConstraintBound->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] = (in3_data[i * stride_0_0] >=
                     in4->ConstraintBound->data[i * stride_1_0]);
  }
  st.site = (emlrtRSInfo *)&in2;
  eml_find(&st, b_in3, in1);
  emxFree_boolean_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_i;
  int32_T idx;
  int32_T ii;
  int32_T nx_tmp;
  int32_T *i_data;
  const boolean_T *x_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  nx_tmp = x->size[0];
  st.site = &lh_emlrtRSI;
  idx = 0;
  b_i = i->size[0];
  i->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&st, i, b_i, &id_emlrtRTEI);
  i_data = i->data;
  b_st.site = &mh_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &rb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx_tmp - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= nx_tmp) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x->size[0]) {
    emlrtErrorWithMessageIdR2018a(&st, &ab_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x->size[0] == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    int32_T b_iv[2];
    if (idx < 1) {
      b_i = 0;
    } else {
      b_i = idx;
    }
    b_iv[0] = 1;
    b_iv[1] = b_i;
    b_st.site = &nh_emlrtRSI;
    indexShapeCheck(&b_st, i->size[0], b_iv);
    ii = i->size[0];
    i->size[0] = b_i;
    emxEnsureCapacity_int32_T(&st, i, ii, &jd_emlrtRTEI);
  }
}

/* End of code generation (find.c) */
