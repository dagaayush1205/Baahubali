/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * handle.c
 *
 * Code generation for function 'handle'
 *
 */

/* Include files */
#include "handle.h"
#include "armvone_data.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "collisioncodegen_api.hpp"

/* Variable Definitions */
static emlrtRSInfo ft_emlrtRSI = {
    22,                                            /* lineNo */
    "matlabCodegenHandle/matlabCodegenDestructor", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/eml/+coder/+internal/"
    "matlabCodegenHandle.m" /* pathName */
};

static emlrtRSInfo gt_emlrtRSI = {
    296,                   /* lineNo */
    "CollisionSet/delete", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pathName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    295,                   /* lineNo */
    25,                    /* colNo */
    "CollisionSet/delete", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m" /* pName */
};

static emlrtBCInfo af_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    296,                   /* lineNo */
    79,                    /* colNo */
    "",                    /* aName */
    "CollisionSet/delete", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    0                                  /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    296,                   /* lineNo */
    45,                    /* colNo */
    "",                    /* aName */
    "CollisionSet/delete", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/CollisionSet.m", /* pName */
    0                                  /* checkKind */
};

/* Function Definitions */
void b_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     c_robotics_manip_internal_Rigid *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void c_handle_matlabCodegenDestructo(const emlrtStack *sp, b_rigidBodyTree *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void d_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     inverseKinematics *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

void e_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     c_robotics_core_internal_Damped *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void f_handle_matlabCodegenDestructo(const emlrtStack *sp, rigidBodyTree *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void g_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void h_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     d_robotics_manip_internal_Colli *obj)
{
  c_robotics_manip_internal_Colli b_obj;
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!obj->matlabCodegenIsDeleted) {
    real_T d;
    int32_T i;
    obj->matlabCodegenIsDeleted = true;
    st.site = &ft_emlrtRSI;
    d = obj->Size;
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                  &xb_emlrtRTEI, &st);
    for (b_i = 0; b_i < i; b_i++) {
      int32_T i1;
      b_st.site = &gt_emlrtRSI;
      i1 = obj->CollisionGeometries->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &af_emlrtBCI, &b_st);
      }
      b_obj = obj->CollisionGeometries->data[b_i];
      collisioncodegen_destructGeometry(&b_obj.CollisionPrimitive);
      i1 = obj->CollisionGeometries->size[1] - 1;
      if (b_i > i1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, i1, &bf_emlrtBCI, &st);
      }
      obj->CollisionGeometries->data[b_i] = b_obj;
    }
  }
}

void handle_matlabCodegenDestructor(const emlrtStack *sp,
                                    d_robotics_manip_internal_Rigid *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

void i_handle_matlabCodegenDestructo(const emlrtStack *sp,
                                     c_robotics_manip_internal_IKExt *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* End of code generation (handle.c) */
