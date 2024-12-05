/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * RigidBody.c
 *
 * Code generation for function 'RigidBody'
 *
 */

/* Include files */
#include "RigidBody.h"
#include "CollisionSet.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = {
    153,                   /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    158,                   /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    158,                   /* lineNo */
    56,                    /* colNo */
    "",                    /* aName */
    "RigidBody/RigidBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m", /* pName */
    0                        /* checkKind */
};

/* Function Definitions */
c_robotics_manip_internal_Rigid *
RigidBody_RigidBody(const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
                    const char_T bodyInput[10],
                    d_robotics_manip_internal_Colli *iobj_0,
                    rigidBodyJoint *iobj_1)
{
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv1[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T msubspace_size[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T b_I[36];
  int8_T c_I[9];
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 10.0;
  for (i = 0; i < 10; i++) {
    s.Vector[i] = bodyInput[i];
  }
  b_obj->NameInternal = s;
  st.site = &t_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 14.0;
  for (i = 0; i < 10; i++) {
    s.Vector[i] = bodyInput[i];
  }
  s.Vector[10] = '_';
  s.Vector[11] = 'j';
  s.Vector[12] = 'n';
  s.Vector[13] = 't';
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv1[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv2[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv2[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data,
                                  msubspace_size);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv3[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    msubspace_size[0] = ibmat;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &emlrtECI, &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    msubspace_size[0] = 1;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &c_emlrtECI, &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  b_obj->Index = -1.0;
  b_obj->ParentIndex = -1.0;
  b_obj->MassInternal = 1.0;
  b_obj->CenterOfMassInternal[0] = 0.0;
  b_obj->CenterOfMassInternal[1] = 0.0;
  b_obj->CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    c_I[i] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = c_I[i];
  }
  for (i = 0; i < 36; i++) {
    b_I[i] = 0;
  }
  for (ibmat = 0; ibmat < 6; ibmat++) {
    b_I[ibmat + 6 * ibmat] = 1;
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = b_I[i];
  }
  st.site = &u_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *b_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.00568540036480312,
                                 -1.6292124155158921E-5,
                                 0.00010258985607075304,
                                 0.0,
                                 -0.055198666800744887,
                                 -0.0060805492633001458,
                                 -1.6292124155158921E-5,
                                 0.0079788268447147578,
                                 0.00014277899029547592,
                                 0.055198666800744887,
                                 0.0,
                                 0.0062933804906644989,
                                 0.00010258985607075304,
                                 0.00014277899029547592,
                                 0.0091598053364996337,
                                 0.0060805492633001458,
                                 -0.0062933804906644989,
                                 0.0,
                                 0.0,
                                 0.055198666800744887,
                                 0.0060805492633001458,
                                 2.3506402744061,
                                 0.0,
                                 0.0,
                                 -0.055198666800744887,
                                 0.0,
                                 -0.0062933804906644989,
                                 0.0,
                                 2.3506402744061,
                                 0.0,
                                 -0.0060805492633001458,
                                 0.0062933804906644989,
                                 0.0,
                                 0.0,
                                 0.0,
                                 2.3506402744061};
  static const real_T dv2[16] = {1.0, 0.0, -0.0, 0.0, 0.0,     1.0, 0.0,   0.0,
                                 0.0, 0.0, 1.0,  0.0, 0.26945, 0.0, 0.216, 1.0};
  static const real_T dv[9] = {
      0.00568540036480312,    -1.6292124155158921E-5, 0.00010258985607075304,
      -1.6292124155158921E-5, 0.0079788268447147578,  0.00014277899029547592,
      0.00010258985607075304, 0.00014277899029547592, 0.0091598053364996337};
  static const char_T b_cv[9] = {'t', 'u', 'r', 'n', 't', 'a', 'b', 'l', 'e'};
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  static const int8_T iv5[6] = {0, 0, -1, 0, 0, 0};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 9.0;
  for (i = 0; i < 9; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 9;
  iv1[1] = 9;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 0.0;
  b_obj->MassInternal = 2.3506402744061;
  b_obj->CenterOfMassInternal[0] = -0.00267730480039297;
  b_obj->CenterOfMassInternal[1] = -0.00258676298943122;
  b_obj->CenterOfMassInternal[2] = 0.0234823964354525;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 14.0;
  for (i = 0; i < 14; i++) {
    s.Vector[i] = cv[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv4[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv5[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = 0.0;
  b_obj->JointInternal->JointAxisInternal[2] = -1.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *c_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.079276964214759632,
                                 0.00024792377218861784,
                                 -0.029130311935912909,
                                 0.0,
                                 -0.400671557772473,
                                 -0.004743933466168841,
                                 0.00024792377218861784,
                                 0.091392133702590139,
                                 0.00066260610916762442,
                                 0.400671557772473,
                                 0.0,
                                 -0.14955006945043345,
                                 -0.029130311935912909,
                                 0.00066260610916762442,
                                 0.013373436344149846,
                                 0.004743933466168841,
                                 0.14955006945043345,
                                 0.0,
                                 0.0,
                                 0.400671557772473,
                                 0.004743933466168841,
                                 2.86881846288643,
                                 0.0,
                                 0.0,
                                 -0.400671557772473,
                                 0.0,
                                 0.14955006945043345,
                                 0.0,
                                 2.86881846288643,
                                 0.0,
                                 -0.004743933466168841,
                                 -0.14955006945043345,
                                 0.0,
                                 0.0,
                                 0.0,
                                 2.86881846288643};
  static const real_T dv2[16] = {1.0,     0.0, -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0, 0.0,     0.0, 1.0, 0.0,
                                 0.08505, 0.0, 0.15172, 1.0};
  static const real_T dv[9] = {
      0.079276964214759632,   0.00024792377218861784, -0.029130311935912909,
      0.00024792377218861784, 0.091392133702590139,   0.00066260610916762442,
      -0.029130311935912909,  0.00066260610916762442, 0.013373436344149846};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv1[6] = {'j', 'o', 'i', 'n', 't', '1'};
  static const char_T b_cv[5] = {'l', 'i', 'n', 'k', '1'};
  static const char_T b_cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  static const int8_T iv5[6] = {0, -1, 0, 0, 0, 0};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 5;
  iv1[1] = 5;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 1.0;
  b_obj->MassInternal = 2.86881846288643;
  b_obj->CenterOfMassInternal[0] = 0.052129499090007;
  b_obj->CenterOfMassInternal[1] = -0.00165361926087013;
  b_obj->CenterOfMassInternal[2] = 0.139664312313907;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 6.0;
  for (i = 0; i < 6; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv2[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv3[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv4[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv5[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv5[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = -1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *d_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.0021473383658498421,
                                 0.00043478224643843394,
                                 -0.0021842452941198296,
                                 0.0,
                                 -0.03726523351742575,
                                 -0.00929906236719845,
                                 0.00043478224643843394,
                                 0.0062275738404100429,
                                 0.00024484744519511826,
                                 0.03726523351742575,
                                 0.0,
                                 -0.0661758423038866,
                                 -0.0021842452941198296,
                                 0.00024484744519511826,
                                 0.0048643183067106268,
                                 0.00929906236719845,
                                 0.0661758423038866,
                                 0.0,
                                 0.0,
                                 0.03726523351742575,
                                 0.00929906236719845,
                                 1.4157165117551,
                                 0.0,
                                 0.0,
                                 -0.03726523351742575,
                                 0.0,
                                 0.0661758423038866,
                                 0.0,
                                 1.4157165117551,
                                 0.0,
                                 -0.00929906236719845,
                                 -0.0661758423038866,
                                 0.0,
                                 0.0,
                                 0.0,
                                 1.4157165117551};
  static const real_T dv2[16] = {1.0,     0.0,     -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0,     0.0,     0.0, 1.0, 0.0,
                                 0.16161, -0.0165, 0.39308, 1.0};
  static const real_T dv[9] = {
      0.0021473383658498421,  0.00043478224643843394, -0.0021842452941198296,
      0.00043478224643843394, 0.0062275738404100429,  0.00024484744519511826,
      -0.0021842452941198296, 0.00024484744519511826, 0.0048643183067106268};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv1[6] = {'j', 'o', 'i', 'n', 't', '2'};
  static const char_T b_cv[5] = {'l', 'i', 'n', 'k', '2'};
  static const char_T b_cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  static const int8_T iv5[6] = {0, -1, 0, 0, 0, 0};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 5;
  iv1[1] = 5;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 2.0;
  b_obj->MassInternal = 1.4157165117551;
  b_obj->CenterOfMassInternal[0] = 0.0467437101668375;
  b_obj->CenterOfMassInternal[1] = -0.00656844946709717;
  b_obj->CenterOfMassInternal[2] = 0.0263225251722374;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 6.0;
  for (i = 0; i < 6; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv2[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv3[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv4[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv5[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv5[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = -1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *e_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.00038227670959680652,
                                 9.9896089242309635E-5,
                                 -0.00049902544617585782,
                                 0.0,
                                 -0.010384381111011677,
                                 -0.0021581837304646525,
                                 9.9896089242309635E-5,
                                 0.00127147469255335,
                                 5.2832875076398257E-5,
                                 0.010384381111011677,
                                 0.0,
                                 -0.019629263853319971,
                                 -0.00049902544617585782,
                                 5.2832875076398257E-5,
                                 0.0010618886280044186,
                                 0.0021581837304646525,
                                 0.019629263853319971,
                                 0.0,
                                 0.0,
                                 0.010384381111011677,
                                 0.0021581837304646525,
                                 0.424370516791685,
                                 0.0,
                                 0.0,
                                 -0.010384381111011677,
                                 0.0,
                                 0.019629263853319971,
                                 0.0,
                                 0.424370516791685,
                                 0.0,
                                 -0.0021581837304646525,
                                 -0.019629263853319971,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.424370516791685};
  static const real_T dv2[16] = {1.0,     0.0,      -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0,      0.0,     0.0, 1.0, 0.0,
                                 0.19676, 0.016444, 0.10409, 1.0};
  static const real_T dv[9] = {
      0.00038227670959680652,  9.9896089242309635E-5, -0.00049902544617585782,
      9.9896089242309635E-5,   0.00127147469255335,   5.2832875076398257E-5,
      -0.00049902544617585782, 5.2832875076398257E-5, 0.0010618886280044186};
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv[5] = {'p', 'i', 't', 'c', 'h'};
  static const char_T b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  static const int8_T iv5[6] = {0, 1, 0, 0, 0, 0};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 5;
  iv1[1] = 5;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 3.0;
  b_obj->MassInternal = 0.424370516791685;
  b_obj->CenterOfMassInternal[0] = 0.0462550131939434;
  b_obj->CenterOfMassInternal[1] = -0.00508561185348336;
  b_obj->CenterOfMassInternal[2] = 0.0244700814503312;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 10.0;
  for (i = 0; i < 10; i++) {
    s.Vector[i] = cv1[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv4[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv5[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = 1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *f_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.00030659306989070284,
                                 0.00016969514638915506,
                                 -0.00031624041430616291,
                                 0.0,
                                 -0.0074839601072747078,
                                 -0.003789792124147047,
                                 0.00016969514638915506,
                                 0.0010894878934764338,
                                 6.80190897028461E-5,
                                 0.0074839601072747078,
                                 0.0,
                                 -0.018621989745768289,
                                 -0.00031624041430616291,
                                 6.80190897028461E-5,
                                 0.00097981186404543039,
                                 0.003789792124147047,
                                 0.018621989745768289,
                                 0.0,
                                 0.0,
                                 0.0074839601072747078,
                                 0.003789792124147047,
                                 0.416375076239649,
                                 0.0,
                                 0.0,
                                 -0.0074839601072747078,
                                 0.0,
                                 0.018621989745768289,
                                 0.0,
                                 0.416375076239649,
                                 0.0,
                                 -0.003789792124147047,
                                 -0.018621989745768289,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.416375076239649};
  static const real_T dv2[16] = {1.0,      0.0,         -0.0,   0.0, 0.0, 1.0,
                                 0.0,      0.0,         0.0,    0.0, 1.0, 0.0,
                                 0.095579, -0.00064427, 0.0505, 1.0};
  static const real_T dv[9] = {
      0.00030659306989070284,  0.00016969514638915506, -0.00031624041430616291,
      0.00016969514638915506,  0.0010894878934764338,  6.80190897028461E-5,
      -0.00031624041430616291, 6.80190897028461E-5,    0.00097981186404543039};
  static const real_T dv3[6] = {
      -0.46761983415865516, 0.0, 0.88392968651439219, 0.0, 0.0, 0.0};
  static const char_T b_cv[8] = {'y', 'a', 'w', 'j', 'o', 'i', 'n', 't'};
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 3.0;
  s.Vector[0] = 'y';
  s.Vector[1] = 'a';
  s.Vector[2] = 'w';
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 3;
  iv1[1] = 3;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 4.0;
  b_obj->MassInternal = 0.416375076239649;
  b_obj->CenterOfMassInternal[0] = 0.0447240740582902;
  b_obj->CenterOfMassInternal[1] = -0.00910187074205612;
  b_obj->CenterOfMassInternal[2] = 0.0179740828266273;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv2[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv3[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv4[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = dv3[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = -0.46761983415865516;
  b_obj->JointInternal->JointAxisInternal[1] = 0.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.88392968651439219;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *g_RigidBody_RigidBody(
    const emlrtStack *sp, c_robotics_manip_internal_Rigid *obj,
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const real_T dv1[36] = {0.0021301676780353411,
                                 0.0007417655137471849,
                                 -0.0024409365294323776,
                                 0.0,
                                 -0.02878787783958377,
                                 -0.010096218146654944,
                                 0.0007417655137471849,
                                 0.0061591580099290728,
                                 0.00039146529877202873,
                                 0.02878787783958377,
                                 0.0,
                                 -0.054526389837966378,
                                 -0.0024409365294323776,
                                 0.00039146529877202873,
                                 0.0054626710719641609,
                                 0.010096218146654944,
                                 0.054526389837966378,
                                 0.0,
                                 0.0,
                                 0.02878787783958377,
                                 0.010096218146654944,
                                 0.695670819953184,
                                 0.0,
                                 0.0,
                                 -0.02878787783958377,
                                 0.0,
                                 0.054526389837966378,
                                 0.0,
                                 0.695670819953184,
                                 0.0,
                                 -0.010096218146654944,
                                 -0.054526389837966378,
                                 0.0,
                                 0.0,
                                 0.0,
                                 0.695670819953184};
  static const real_T dv2[16] = {1.0,     0.0,       -0.0,     0.0, 0.0, 1.0,
                                 0.0,     0.0,       0.0,      0.0, 1.0, 0.0,
                                 0.06953, -0.042517, 0.035491, 1.0};
  static const real_T dv[9] = {
      0.0021301676780353411,  0.0007417655137471849,  -0.0024409365294323776,
      0.0007417655137471849,  0.0061591580099290728,  0.00039146529877202873,
      -0.0024409365294323776, 0.00039146529877202873, 0.0054626710719641609};
  static const real_T dv3[6] = {
      -0.88392968651439219, 0.0, -0.46761983415865516, 0.0, 0.0, 0.0};
  static const char_T b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv4[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T iv2[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv3[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_obj = obj;
  st.site = &s_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  st.site = &gb_emlrtRSI;
  s = b_obj->NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'r';
  s.Vector[1] = 'o';
  s.Vector[2] = 'l';
  s.Vector[3] = 'l';
  b_iv[0] = 1;
  iv1[0] = 1;
  b_iv[1] = 4;
  iv1[1] = 4;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI, &st);
  b_obj->NameInternal = s;
  b_obj->ParentIndex = 5.0;
  b_obj->MassInternal = 0.695670819953184;
  b_obj->CenterOfMassInternal[0] = 0.0783795845305626;
  b_obj->CenterOfMassInternal[1] = -0.0145129245859908;
  b_obj->CenterOfMassInternal[2] = 0.0413814652187382;
  for (i = 0; i < 9; i++) {
    b_obj->InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    b_obj->SpatialInertia[i] = dv1[i];
  }
  st.site = &hb_emlrtRSI;
  iobj_1->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1->JointToParentTransform[i] = i1;
    iobj_1->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1->MotionSubspaceInternal[i] = 0.0;
  }
  b_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->NameInternal;
  s.Length = 10.0;
  for (i = 0; i < 10; i++) {
    s.Vector[i] = cv2[i];
  }
  iobj_1->NameInternal = s;
  b_st.site = &w_emlrtRSI;
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_1->TypeInternal = s;
  b_st.site = &x_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv1[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv2[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv2[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv3[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    iv1[0] = 6;
    iv1[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv4[i];
    }
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    iv1[0] = 6;
    iv1[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  b_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_1, msubspace_data, iv1);
  b_st.site = &ab_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  s = iobj_1->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    i = (int32_T)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv3[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    real_T d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &st);
      }
      ibmat = (int32_T)d;
    }
    b_iv[0] = ibmat;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &emlrtECI,
                                  &st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI, &st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_iv[0] = 1;
    b_iv[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &poslim_size[0], 2, &c_emlrtECI,
                                  &st);
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI, &st);
    }
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  if (iv1[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, iv1[1], &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = dv3[i];
  }
  st.site = &ib_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj->JointInternal, msubspace_data,
                                  iv1);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = -0.88392968651439219;
  b_obj->JointInternal->JointAxisInternal[1] = 0.0;
  b_obj->JointInternal->JointAxisInternal[2] = -0.46761983415865516;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  st.site = &jb_emlrtRSI;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(&st, iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* End of code generation (RigidBody.c) */
