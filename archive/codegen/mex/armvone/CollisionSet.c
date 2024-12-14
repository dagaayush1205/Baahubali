/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * CollisionSet.c
 *
 * Code generation for function 'CollisionSet'
 *
 */

/* Include files */
#include "CollisionSet.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "collisioncodegen_api.hpp"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo od_emlrtRSI = {
    283,                 /* lineNo */
    "CollisionSet/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    287,                 /* lineNo */
    "CollisionSet/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    62,                          /* lineNo */
    25,                          /* colNo */
    "CollisionSet/CollisionSet", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                          /* iFirst */
    -1,                          /* iLast */
    63,                          /* lineNo */
    45,                          /* colNo */
    "",                          /* aName */
    "CollisionSet/CollisionSet", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    0                                  /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    38,                          /* lineNo */
    65,                          /* colNo */
    "CollisionSet/CollisionSet", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    1                                  /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    38,                          /* lineNo */
    65,                          /* colNo */
    "CollisionSet/CollisionSet", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    4                                  /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    286,                 /* lineNo */
    21,                  /* colNo */
    "CollisionSet/copy", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pName */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    287,                 /* lineNo */
    44,                  /* colNo */
    "",                  /* aName */
    "CollisionSet/copy", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    287,                 /* lineNo */
    78,                  /* colNo */
    "",                  /* aName */
    "CollisionSet/copy", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    0                                  /* checkKind */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    38,             /* lineNo */
    65,             /* colNo */
    "CollisionSet", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pName */
};

/* Function Definitions */
d_robotics_manip_internal_Colli *
CollisionSet_CollisionSet(const emlrtStack *sp,
                          d_robotics_manip_internal_Colli *obj,
                          real_T maxElements)
{
  static const void *t0_GeometryInternal = NULL;
  c_robotics_manip_internal_Colli expl_temp;
  d_robotics_manip_internal_Colli *b_obj;
  real_T d;
  int32_T b_i;
  int32_T i;
  int32_T i2;
  b_obj = obj;
  b_obj->Size = 0.0;
  b_obj->MaxElements = maxElements;
  if (!(b_obj->MaxElements >= 0.0)) {
    emlrtNonNegativeCheckR2012b(b_obj->MaxElements, &f_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  d = b_obj->MaxElements;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = b_obj->CollisionGeometries->size[0] * b_obj->CollisionGeometries->size[1];
  b_obj->CollisionGeometries->size[0] = 1;
  b_obj->CollisionGeometries->size[1] = (int32_T)d;
  c_emxEnsureCapacity_robotics_ma(sp, b_obj->CollisionGeometries, i,
                                  &dc_emlrtRTEI);
  d = b_obj->MaxElements;
  i = (int32_T)d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                &emlrtRTEI, (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    i1 = b_obj->CollisionGeometries->size[1];
    expl_temp.CollisionPrimitive = (void *)t0_GeometryInternal;
    for (i2 = 0; i2 < 16; i2++) {
      expl_temp.LocalPose[i2] = iv[i2];
    }
    for (i2 = 0; i2 < 16; i2++) {
      expl_temp.WorldPose[i2] = iv[i2];
    }
    expl_temp.MeshScale[0] = 1.0;
    expl_temp.MeshScale[1] = 1.0;
    expl_temp.MeshScale[2] = 1.0;
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    b_obj->CollisionGeometries->data[b_i] = expl_temp;
  }
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

d_robotics_manip_internal_Colli *
CollisionSet_copy(const emlrtStack *sp, d_robotics_manip_internal_Colli *obj,
                  d_robotics_manip_internal_Colli *iobj_0)
{
  void *copyGeometryInternal;
  c_robotics_manip_internal_Colli expl_temp;
  c_robotics_manip_internal_Colli r;
  d_robotics_manip_internal_Colli *newObj;
  emlrtStack st;
  real_T t15_LocalPose[16];
  real_T t15_WorldPose[16];
  real_T d;
  int32_T b_i;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &od_emlrtRSI;
  newObj = CollisionSet_CollisionSet(&st, iobj_0, obj->MaxElements);
  newObj->Size = obj->Size;
  d = obj->Size;
  i = (int32_T)d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                &h_emlrtRTEI, (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    int32_T i1;
    st.site = &pd_emlrtRSI;
    i1 = obj->CollisionGeometries->size[1];
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &q_emlrtBCI, &st);
    }
    r = obj->CollisionGeometries->data[b_i];
    memcpy(&t15_LocalPose[0], &r.LocalPose[0], 16U * sizeof(real_T));
    memcpy(&t15_WorldPose[0], &r.WorldPose[0], 16U * sizeof(real_T));
    copyGeometryInternal = collisioncodegen_copyGeometry(r.CollisionPrimitive);
    i1 = newObj->CollisionGeometries->size[1];
    expl_temp.CollisionPrimitive = copyGeometryInternal;
    memcpy(&expl_temp.LocalPose[0], &t15_LocalPose[0], 16U * sizeof(real_T));
    memcpy(&expl_temp.WorldPose[0], &t15_WorldPose[0], 16U * sizeof(real_T));
    expl_temp.MeshScale[0] = r.MeshScale[0];
    expl_temp.MeshScale[1] = r.MeshScale[1];
    expl_temp.MeshScale[2] = r.MeshScale[2];
    if (b_i > i1 - 1) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    newObj->CollisionGeometries->data[b_i] = expl_temp;
  }
  return newObj;
}

/* End of code generation (CollisionSet.c) */
