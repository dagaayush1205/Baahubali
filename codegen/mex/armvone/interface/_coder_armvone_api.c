/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_armvone_api.c
 *
 * Code generation for function '_coder_armvone_api'
 *
 */

/* Include files */
#include "_coder_armvone_api.h"
#include "armvone.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ji_emlrtRTEI = {
    1,                    /* lineNo */
    1,                    /* colNo */
    "_coder_armvone_api", /* fName */
    ""                    /* pName */
};

/* Function Declarations */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[6];

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6];

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_struct0_T *u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6];

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[6]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[6];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[6]
{
  real_T(*y)[6];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const emxArray_struct0_T *u)
{
  static const char_T *sv[2] = {"JointName", "JointPosition"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  const struct0_T *u_data;
  real_T *pData;
  int32_T b_iv[2];
  int32_T b_j1;
  int32_T i;
  u_data = u->data;
  y = NULL;
  b_iv[0] = 1;
  b_iv[1] = u->size[1];
  emlrtAssign(&y,
              emlrtCreateStructArray(2, &b_iv[0], 2, (const char_T **)&sv[0]));
  emlrtCreateField(y, "JointName");
  emlrtCreateField(y, "JointPosition");
  i = 0;
  for (b_j1 = 0; b_j1 < u->size[1U]; b_j1++) {
    int32_T b_i;
    b_y = NULL;
    b_iv[0] = 1;
    b_i = u_data[b_j1].JointName.size[1];
    b_iv[1] = b_i;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, b_i, m,
                             &u_data[b_j1].JointName.data[0]);
    emlrtAssign(&b_y, m);
    emlrtSetFieldR2017b(y, i, "JointName", b_y, 0);
    c_y = NULL;
    b_iv[0] = 1;
    b_iv[1] = 1;
    m = emlrtCreateNumericArray(2, &b_iv[0], mxDOUBLE_CLASS, mxREAL);
    pData = emlrtMxGetPr(m);
    pData[0] = u_data[b_j1].JointPosition.data[0];
    emlrtAssign(&c_y, m);
    emlrtSetFieldR2017b(y, i, "JointPosition", c_y, 1);
    i++;
  }
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[6]
{
  static const int32_T dims[2] = {1, 6};
  real_T(*ret)[6];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2] = {1, 3};
  real_T(*ret)[3];
  int32_T b_iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &b_iv[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void armvone_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_struct0_T *vone;
  real_T(*q0)[6];
  real_T(*pos)[3];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  /* Marshall function inputs */
  q0 = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "q0");
  pos = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "pos");
  /* Invoke the target function */
  emxInit_struct0_T(&st, &vone, &ji_emlrtRTEI);
  armvone(&st, *q0, *pos, vone);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, vone);
  emxFree_struct0_T(&st, &vone);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_armvone_api.c) */
