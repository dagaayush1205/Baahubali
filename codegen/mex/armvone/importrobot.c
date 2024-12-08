/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * importrobot.c
 *
 * Code generation for function 'importrobot'
 *
 */

/* Include files */
#include "importrobot.h"
#include "CollisionSet.h"
#include "RigidBody.h"
#include "armvone_data.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI =
    {
        87,            /* lineNo */
        "importrobot", /* fcnName */
        "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
        "importrobot.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    192,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    182,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    185,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    201,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    167,                   /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    168,                   /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBody.m" /* pathName */
};

/* Function Definitions */
void importrobot(const emlrtStack *sp, d_robotics_manip_internal_Rigid *iobj_0,
                 b_rigidBodyTree **iobj_1)
{
  static const char_T b_cv[9] = {'b', 'a', 's', 'e', '_', 'l', 'i', 'n', 'k'};
  __m128d r;
  __m128d r1;
  __m128d r2;
  c_robotics_manip_internal_Chara s;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T idx[5];
  real_T dv[2];
  real_T dv1[2];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T loop_ub;
  char_T s_data[204];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &l_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  b_st.site = &m_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  d_st.site = &h_emlrtRSI;
  emlrtRandu(&idx[0], 5);
  r = _mm_loadu_pd(&idx[0]);
  r1 = _mm_set1_pd(62.0);
  _mm_storeu_pd(&dv[0], _mm_mul_pd(r, r1));
  dv1[0] = muDoubleScalarFloor(dv[0]);
  dv1[1] = muDoubleScalarFloor(dv[1]);
  r = _mm_loadu_pd(&dv1[0]);
  r2 = _mm_set1_pd(1.0);
  _mm_storeu_pd(&idx[0], _mm_add_pd(r, r2));
  r = _mm_loadu_pd(&idx[2]);
  _mm_storeu_pd(&dv[0], _mm_mul_pd(r, r1));
  dv1[0] = muDoubleScalarFloor(dv[0]);
  dv1[1] = muDoubleScalarFloor(dv[1]);
  r = _mm_loadu_pd(&dv1[0]);
  _mm_storeu_pd(&idx[2], _mm_add_pd(r, r2));
  idx[4] = muDoubleScalarFloor(idx[4] * 62.0) + 1.0;
  for (loop_ub = 0; loop_ub < 5; loop_ub++) {
    real_T d;
    d = idx[loop_ub];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &xc_emlrtDCI, &d_st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 62)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 62, &ye_emlrtBCI, &d_st);
    }
  }
  iobj_0->NumBodies = 6.0;
  b_st.site = &o_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[0] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[0], cv4, &iobj_0->_pobj0[0], &iobj_0->_pobj1[0]);
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[1] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[1], cv5, &iobj_0->_pobj0[1], &iobj_0->_pobj1[1]);
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[2] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[2], cv6, &iobj_0->_pobj0[2], &iobj_0->_pobj1[2]);
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[3] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[3], cv7, &iobj_0->_pobj0[3], &iobj_0->_pobj1[3]);
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[4] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[4], cv8, &iobj_0->_pobj0[4], &iobj_0->_pobj1[4]);
  c_st.site = &r_emlrtRSI;
  iobj_0->Bodies[5] = RigidBody_RigidBody(
      &c_st, &iobj_0->_pobj2[5], cv9, &iobj_0->_pobj0[5], &iobj_0->_pobj1[5]);
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[0] = b_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[6], &iobj_0->_pobj0[6], &iobj_0->_pobj1[6]);
  iobj_0->Bodies[0]->Index = 1.0;
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[1] = c_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[7], &iobj_0->_pobj0[7], &iobj_0->_pobj1[7]);
  iobj_0->Bodies[1]->Index = 2.0;
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[2] = d_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[8], &iobj_0->_pobj0[8], &iobj_0->_pobj1[8]);
  iobj_0->Bodies[2]->Index = 3.0;
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[3] = e_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[9], &iobj_0->_pobj0[9], &iobj_0->_pobj1[9]);
  iobj_0->Bodies[3]->Index = 4.0;
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[4] = f_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[10], &iobj_0->_pobj0[10], &iobj_0->_pobj1[10]);
  iobj_0->Bodies[4]->Index = 5.0;
  b_st.site = &p_emlrtRSI;
  iobj_0->Bodies[5] = g_RigidBody_RigidBody(
      &b_st, &iobj_0->_pobj2[11], &iobj_0->_pobj0[11], &iobj_0->_pobj1[11]);
  iobj_0->Bodies[5]->Index = 6.0;
  b_st.site = &n_emlrtRSI;
  iobj_0->Gravity[0] = 0.0;
  iobj_0->Gravity[1] = 0.0;
  iobj_0->Gravity[2] = 0.0;
  iobj_0->NumNonFixedBodies = 6.0;
  iobj_0->PositionNumber = 6.0;
  iobj_0->VelocityNumber = 6.0;
  b_st.site = &q_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  s.Length = 200.0;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    s.Vector[loop_ub] = ' ';
  }
  iobj_0->Base.NameInternal = s;
  c_st.site = &gb_emlrtRSI;
  s = iobj_0->Base.NameInternal;
  s.Length = 9.0;
  for (loop_ub = 0; loop_ub < 9; loop_ub++) {
    s.Vector[loop_ub] = b_cv[loop_ub];
  }
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 9;
  iv1[1] = 9;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &c_st);
  iobj_0->Base.NameInternal = s;
  iobj_0->Base.ParentIndex = -1.0;
  iobj_0->Base.MassInternal = 0.0;
  iobj_0->Base.CenterOfMassInternal[0] = 0.0;
  iobj_0->Base.CenterOfMassInternal[1] = 0.0;
  iobj_0->Base.CenterOfMassInternal[2] = 0.0;
  for (loop_ub = 0; loop_ub < 9; loop_ub++) {
    iobj_0->Base.InertiaInternal[loop_ub] = 0.0;
  }
  for (loop_ub = 0; loop_ub < 36; loop_ub++) {
    iobj_0->Base.SpatialInertia[loop_ub] = 0.0;
  }
  c_st.site = &lb_emlrtRSI;
  s = iobj_0->Base.NameInternal;
  if (s.Length < 1.0) {
    loop_ub = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &i_emlrtBCI,
                                    &c_st);
    }
    loop_ub = (int32_T)s.Length;
  }
  b_iv[0] = 1;
  b_iv[1] = loop_ub + 4;
  if (loop_ub - 1 >= 0) {
    memcpy(&s_data[0], &s.Vector[0], (uint32_T)loop_ub * sizeof(char_T));
  }
  s_data[loop_ub] = '_';
  s_data[loop_ub + 1] = 'j';
  s_data[loop_ub + 2] = 'n';
  s_data[loop_ub + 3] = 't';
  c_st.site = &mb_emlrtRSI;
  iobj_0->Base.JointInternal =
      rigidBodyJoint_rigidBodyJoint(&c_st, &iobj_0->_pobj1[12], s_data, b_iv);
  c_st.site = &jb_emlrtRSI;
  iobj_0->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&c_st, &iobj_0->_pobj0[12], 0.0);
  iobj_0->Base.matlabCodegenIsDeleted = false;
  iobj_0->Base.Index = 0.0;
  iobj_0->matlabCodegenIsDeleted = false;
  st.site = &e_emlrtRSI;
  b_st.site = &qb_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  (*iobj_1)->TreeInternal = iobj_0;
  (*iobj_1)->matlabCodegenIsDeleted = false;
}

/* End of code generation (importrobot.c) */
