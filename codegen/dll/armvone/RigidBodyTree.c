/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * RigidBodyTree.c
 *
 * Code generation for function 'RigidBodyTree'
 *
 */

/* Include files */
#include "RigidBodyTree.h"
#include "CollisionSet.h"
#include "RigidBody.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "find.h"
#include "rand.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Declarations */
static void RigidBodyTree_ancestorIndices(e_robotics_manip_internal_Rigid *obj,
                                          c_robotics_manip_internal_Rigid *body,
                                          emxArray_real_T *indices);

static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3);

static void binary_expand_op_1(emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static int div_s32(int numerator, int denominator);

/* Function Definitions */
static void RigidBodyTree_ancestorIndices(e_robotics_manip_internal_Rigid *obj,
                                          c_robotics_manip_internal_Rigid *body,
                                          emxArray_real_T *indices)
{
  double *indices_data;
  unsigned int b_i;
  int i;
  int loop_ub;
  i = indices->size[0] * indices->size[1];
  indices->size[0] = 1;
  indices->size[1] = (int)(obj->NumBodies + 1.0);
  emxEnsureCapacity_real_T(indices, i);
  indices_data = indices->data;
  loop_ub = (int)(obj->NumBodies + 1.0);
  for (i = 0; i < loop_ub; i++) {
    indices_data[i] = 0.0;
  }
  b_i = 2U;
  indices_data[0] = body->Index;
  while (body->ParentIndex > 0.0) {
    body = obj->Bodies[(int)body->ParentIndex - 1];
    indices_data[(int)b_i - 1] = body->Index;
    b_i++;
  }
  if (body->Index > 0.0) {
    indices_data[(int)b_i - 1] = body->ParentIndex;
    b_i++;
  }
  i = indices->size[0] * indices->size[1];
  indices->size[1] = (int)(b_i - 1U);
  emxEnsureCapacity_real_T(indices, i);
}

static void binary_expand_op(emxArray_boolean_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] >=
                   in3_data[i * stride_1_0] - 4.4408920985006262E-16);
  }
}

static void binary_expand_op_1(emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  const double *in2_data;
  const double *in3_data;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(in1, i);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        (in2_data[i * stride_0_0] <=
         in3_data[i * stride_1_0 + in3->size[0]] + 4.4408920985006262E-16);
  }
}

static int div_s32(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int u;
    unsigned int u1;
    if (numerator < 0) {
      u = ~(unsigned int)numerator + 1U;
    } else {
      u = (unsigned int)numerator;
    }
    if (denominator < 0) {
      u1 = ~(unsigned int)denominator + 1U;
    } else {
      u1 = (unsigned int)denominator;
    }
    u /= u1;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int)u;
    } else {
      quotient = (int)u;
    }
  }
  return quotient;
}

e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(e_robotics_manip_internal_Rigid *obj)
{
  static const signed char iv3[12] = {0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1};
  static const char b_cv[8] = {'b', 'a', 's', 'e', '_', 'j', 'n', 't'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  e_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  double unusedExpr[5];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char b_I[36];
  signed char c_I[9];
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  b_rand(unusedExpr);
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->Base.NameInternal = s;
  s = b_obj->Base.NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'b';
  s.Vector[1] = 'a';
  s.Vector[2] = 's';
  s.Vector[3] = 'e';
  b_obj->Base.NameInternal = s;
  b_obj->_pobj2[0].InTree = false;
  for (i = 0; i < 16; i++) {
    b_obj->_pobj2[0].JointToParentTransform[i] = iv[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->_pobj2[0].ChildToJointTransform[i] = iv[i];
  }
  for (i = 0; i < 14; i++) {
    b_obj->_pobj2[0].PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    b_obj->_pobj2[0].HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    b_obj->_pobj2[0].MotionSubspaceInternal[i] = 0.0;
  }
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->_pobj2[0].NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->_pobj2[0].TypeInternal = s;
  s = b_obj->_pobj2[0].NameInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_obj->_pobj2[0].NameInternal = s;
  s = b_obj->_pobj2[0].TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv1[i];
  }
  b_obj->_pobj2[0].TypeInternal = s;
  s = b_obj->_pobj2[0].TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    i = (int)s.Length;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->_pobj2[0].VelocityNumber = 1.0;
    b_obj->_pobj2[0].PositionNumber = 1.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->_pobj2[0].VelocityNumber = 1.0;
    b_obj->_pobj2[0].PositionNumber = 1.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size_idx_0 = 7;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      signed char b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (signed char)(10 * homepos_size_idx_1 - 5);
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
    b_obj->_pobj2[0].VelocityNumber = 6.0;
    b_obj->_pobj2[0].PositionNumber = 7.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = rtNaN;
    b_obj->_pobj2[0].JointAxisInternal[1] = rtNaN;
    b_obj->_pobj2[0].JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->_pobj2[0].VelocityNumber = 0.0;
    b_obj->_pobj2[0].PositionNumber = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(&b_obj->_pobj2[0], msubspace_data);
  s = b_obj->_pobj2[0].TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    i = (int)s.Length;
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
    double d;
    d = b_obj->_pobj2[0].PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        b_obj->_pobj2[0].PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      b_obj->_pobj2[0].HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_obj->_pobj2[0].PositionLimitsInternal[0] = poslim_data[0];
    b_obj->_pobj2[0].PositionLimitsInternal[7] = poslim_data[1];
    b_obj->_pobj2[0].HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->Base.JointInternal = &b_obj->_pobj2[0];
  b_obj->Base.Index = -1.0;
  b_obj->Base.ParentIndex = -1.0;
  b_obj->Base.MassInternal = 1.0;
  b_obj->Base.CenterOfMassInternal[0] = 0.0;
  b_obj->Base.CenterOfMassInternal[1] = 0.0;
  b_obj->Base.CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    c_I[i] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (i = 0; i < 9; i++) {
    b_obj->Base.InertiaInternal[i] = c_I[i];
  }
  for (i = 0; i < 36; i++) {
    b_I[i] = 0;
  }
  for (ibmat = 0; ibmat < 6; ibmat++) {
    b_I[ibmat + 6 * ibmat] = 1;
  }
  for (i = 0; i < 36; i++) {
    b_obj->Base.SpatialInertia[i] = b_I[i];
  }
  b_obj->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&b_obj->_pobj1[0], 0.0);
  b_obj->Base.matlabCodegenIsDeleted = false;
  b_obj->Base.Index = 0.0;
  b_obj->Bodies[0] = RigidBody_RigidBody(&b_obj->_pobj0[0], cv4,
                                         &b_obj->_pobj1[1], &b_obj->_pobj2[1]);
  b_obj->Bodies[1] = RigidBody_RigidBody(&b_obj->_pobj0[1], cv5,
                                         &b_obj->_pobj1[2], &b_obj->_pobj2[2]);
  b_obj->Bodies[2] = RigidBody_RigidBody(&b_obj->_pobj0[2], cv6,
                                         &b_obj->_pobj1[3], &b_obj->_pobj2[3]);
  b_obj->Bodies[3] = RigidBody_RigidBody(&b_obj->_pobj0[3], cv7,
                                         &b_obj->_pobj1[4], &b_obj->_pobj2[4]);
  b_obj->Bodies[4] = RigidBody_RigidBody(&b_obj->_pobj0[4], cv8,
                                         &b_obj->_pobj1[5], &b_obj->_pobj2[5]);
  b_obj->Bodies[5] = RigidBody_RigidBody(&b_obj->_pobj0[5], cv9,
                                         &b_obj->_pobj1[6], &b_obj->_pobj2[6]);
  b_obj->NumBodies = 0.0;
  b_obj->NumNonFixedBodies = 0.0;
  b_obj->PositionNumber = 0.0;
  b_obj->VelocityNumber = 0.0;
  b_rand(unusedExpr);
  for (i = 0; i < 12; i++) {
    b_obj->PositionDoFMap[i] = iv3[i];
  }
  for (i = 0; i < 12; i++) {
    b_obj->VelocityDoFMap[i] = iv3[i];
  }
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void RigidBodyTree_addBody(e_robotics_manip_internal_Rigid *obj,
                           c_robotics_manip_internal_Rigid *bodyin,
                           const char parentName_data[],
                           const int parentName_size[2],
                           d_robotics_manip_internal_Colli *iobj_0,
                           rigidBodyJoint *iobj_1,
                           c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *jnt;
  double b_index;
  double pid;
  int obj_Vector_size[2];
  int loop_ub;
  char obj_Vector[200];
  char obj_Vector_data[200];
  boolean_T b_bool;
  pid = bodyin->NameInternal.Length;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    obj_Vector[loop_ub] = bodyin->NameInternal.Vector[loop_ub];
  }
  if (pid < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)pid;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  c_RigidBodyTree_findBodyIndexBy(obj, obj_Vector_data, obj_Vector_size);
  pid = c_RigidBodyTree_findBodyIndexBy(obj, parentName_data, parentName_size);
  b_index = obj->NumBodies + 1.0;
  body = RigidBody_copy(bodyin, &iobj_0[0], &iobj_1[0], iobj_2);
  obj->Bodies[(int)b_index - 1] = body;
  body->Index = b_index;
  body->ParentIndex = pid;
  body->JointInternal->InTree = true;
  obj->NumBodies++;
  jnt = body->JointInternal;
  pid = jnt->TypeInternal.Length;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    obj_Vector[loop_ub] = jnt->TypeInternal.Vector[loop_ub];
  }
  if (pid < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)pid;
  }
  b_bool = false;
  if (loop_ub == 5) {
    loop_ub = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
          exitg1 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    obj->NumNonFixedBodies++;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->PositionDoFMap[loop_ub] = obj->PositionNumber + 1.0;
    obj->PositionDoFMap[loop_ub + 6] =
        obj->PositionNumber + jnt->PositionNumber;
    jnt = body->JointInternal;
    loop_ub = (int)body->Index - 1;
    obj->VelocityDoFMap[loop_ub] = obj->VelocityNumber + 1.0;
    obj->VelocityDoFMap[loop_ub + 6] =
        obj->VelocityNumber + jnt->VelocityNumber;
  } else {
    loop_ub = (int)body->Index;
    obj->PositionDoFMap[loop_ub - 1] = 0.0;
    obj->PositionDoFMap[loop_ub + 5] = -1.0;
    loop_ub = (int)body->Index;
    obj->VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->VelocityDoFMap[loop_ub + 5] = -1.0;
  }
  jnt = body->JointInternal;
  obj->PositionNumber += jnt->PositionNumber;
  jnt = body->JointInternal;
  obj->VelocityNumber += jnt->VelocityNumber;
}

void c_RigidBodyTree_efficientFKAndJ(e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *qv, double bid1,
                                     double T_data[], int T_size[2],
                                     emxArray_real_T *Jac)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Rigid *body1;
  c_robotics_manip_internal_Rigid *nextBody;
  emxArray_real_T *B;
  emxArray_real_T *ancestorIndices1;
  emxArray_real_T *ancestorIndices2;
  emxArray_real_T *b_qv;
  emxArray_real_T *kinematicPathIndices;
  rigidBodyJoint *joint;
  double b_data[36];
  double y_data[36];
  double T1[16];
  double T1j[16];
  double Tj1[16];
  double b[16];
  double R[9];
  double tempR[9];
  double b_v[3];
  double v[3];
  const double *qv_data;
  double *ancestorIndices1_data;
  double *ancestorIndices2_data;
  double *kinematicPathIndices_data;
  int b_i;
  int i;
  int jointSign;
  int k;
  int loop_ub;
  qv_data = qv->data;
  if (bid1 >= 0.0) {
    double X[36];
    double s;
    int X_tmp;
    int c_i;
    int minPathLength;
    boolean_T exitg1;
    if (bid1 == 0.0) {
      body1 = &obj->Base;
    } else {
      body1 = obj->Bodies[(int)bid1 - 1];
    }
    emxInit_real_T(&ancestorIndices1, 2);
    RigidBodyTree_ancestorIndices(obj, body1, ancestorIndices1);
    ancestorIndices1_data = ancestorIndices1->data;
    emxInit_real_T(&ancestorIndices2, 2);
    RigidBodyTree_ancestorIndices(obj, &obj->Base, ancestorIndices2);
    ancestorIndices2_data = ancestorIndices2->data;
    minPathLength =
        (int)fmin(ancestorIndices1->size[1], ancestorIndices2->size[1]);
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i - 2 <= minPathLength - 2)) {
      if (ancestorIndices1_data[ancestorIndices1->size[1] - i] !=
          ancestorIndices2_data[ancestorIndices2->size[1] - i]) {
        minPathLength = i - 1;
        exitg1 = true;
      } else {
        i++;
      }
    }
    k = ancestorIndices1->size[1] - minPathLength;
    if (k < 1) {
      loop_ub = 0;
    } else {
      loop_ub = k;
    }
    b_i = ancestorIndices2->size[1] - minPathLength;
    if (b_i < 1) {
      b_i = 0;
      X_tmp = 1;
      c_i = -1;
    } else {
      b_i--;
      X_tmp = -1;
      c_i = 0;
    }
    emxInit_real_T(&kinematicPathIndices, 2);
    jointSign = kinematicPathIndices->size[0] * kinematicPathIndices->size[1];
    kinematicPathIndices->size[0] = 1;
    minPathLength = div_s32(c_i - b_i, X_tmp);
    c_i = (loop_ub + minPathLength) + 2;
    kinematicPathIndices->size[1] = c_i;
    emxEnsureCapacity_real_T(kinematicPathIndices, jointSign);
    kinematicPathIndices_data = kinematicPathIndices->data;
    for (jointSign = 0; jointSign < loop_ub; jointSign++) {
      kinematicPathIndices_data[jointSign] = ancestorIndices1_data[jointSign];
    }
    kinematicPathIndices_data[loop_ub] = ancestorIndices1_data[k];
    emxFree_real_T(&ancestorIndices1);
    for (k = 0; k <= minPathLength; k++) {
      kinematicPathIndices_data[(k + loop_ub) + 1] =
          ancestorIndices2_data[b_i + X_tmp * k];
    }
    emxFree_real_T(&ancestorIndices2);
    memset(&T1[0], 0, 16U * sizeof(double));
    T1[0] = 1.0;
    T1[5] = 1.0;
    T1[10] = 1.0;
    T1[15] = 1.0;
    k = Jac->size[0] * Jac->size[1];
    Jac->size[0] = 6;
    Jac->size[1] = (int)obj->PositionNumber;
    emxEnsureCapacity_real_T(Jac, k);
    ancestorIndices2_data = Jac->data;
    loop_ub = 6 * (int)obj->PositionNumber;
    for (k = 0; k < loop_ub; k++) {
      ancestorIndices2_data[k] = 0.0;
    }
    emxInit_real_T(&b_qv, 1);
    for (i = 0; i <= c_i - 2; i++) {
      __m128d r;
      __m128d r1;
      double Tc2p[16];
      double b_tempR_tmp;
      double c_tempR_tmp;
      double tempR_tmp;
      int exitg2;
      char obj_Vector[200];
      boolean_T b_bool;
      boolean_T nextBodyIsParent;
      s = kinematicPathIndices_data[i];
      if (s != 0.0) {
        body1 = obj->Bodies[(int)s - 1];
      } else {
        body1 = &obj->Base;
      }
      s = kinematicPathIndices_data[i + 1];
      if (s != 0.0) {
        nextBody = obj->Bodies[(int)s - 1];
      } else {
        nextBody = &obj->Base;
      }
      nextBodyIsParent = (nextBody->Index == body1->ParentIndex);
      if (nextBodyIsParent) {
        nextBody = body1;
        jointSign = 1;
      } else {
        jointSign = -1;
      }
      joint = nextBody->JointInternal;
      s = joint->TypeInternal.Length;
      for (k = 0; k < 200; k++) {
        obj_Vector[k] = joint->TypeInternal.Vector[k];
      }
      if (s < 1.0) {
        k = 0;
      } else {
        k = (int)s;
      }
      b_bool = false;
      if (k == 5) {
        minPathLength = 0;
        do {
          exitg2 = 0;
          if (minPathLength < 5) {
            if (obj_Vector[minPathLength] != b_cv[minPathLength]) {
              exitg2 = 1;
            } else {
              minPathLength++;
            }
          } else {
            b_bool = true;
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }
      if (b_bool) {
        double Tj[16];
        for (k = 0; k < 16; k++) {
          Tj1[k] = joint->JointToParentTransform[k];
        }
        s = joint->TypeInternal.Length;
        for (k = 0; k < 200; k++) {
          obj_Vector[k] = joint->TypeInternal.Vector[k];
        }
        if (s < 1.0) {
          k = 0;
        } else {
          k = (int)s;
        }
        b_bool = false;
        if (k == 8) {
          minPathLength = 0;
          do {
            exitg2 = 0;
            if (minPathLength < 8) {
              if (b_cv1[minPathLength] != obj_Vector[minPathLength]) {
                exitg2 = 1;
              } else {
                minPathLength++;
              }
            } else {
              b_bool = true;
              exitg2 = 1;
            }
          } while (exitg2 == 0);
        }
        if (b_bool) {
          minPathLength = 0;
        } else {
          b_bool = false;
          if (k == 9) {
            minPathLength = 0;
            do {
              exitg2 = 0;
              if (minPathLength < 9) {
                if (cv3[minPathLength] != obj_Vector[minPathLength]) {
                  exitg2 = 1;
                } else {
                  minPathLength++;
                }
              } else {
                b_bool = true;
                exitg2 = 1;
              }
            } while (exitg2 == 0);
          }
          if (b_bool) {
            minPathLength = 1;
          } else {
            b_bool = false;
            if (k == 8) {
              minPathLength = 0;
              do {
                exitg2 = 0;
                if (minPathLength < 8) {
                  if (b_cv2[minPathLength] != obj_Vector[minPathLength]) {
                    exitg2 = 1;
                  } else {
                    minPathLength++;
                  }
                } else {
                  b_bool = true;
                  exitg2 = 1;
                }
              } while (exitg2 == 0);
            }
            if (b_bool) {
              minPathLength = 2;
            } else {
              minPathLength = -1;
            }
          }
        }
        switch (minPathLength) {
        case 0: {
          double d_tempR_tmp;
          double e_tempR_tmp;
          double f_tempR_tmp;
          double qidx_idx_0;
          double qidx_idx_1;
          rigidBodyJoint_get_JointAxis(joint, v);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&b_v[0], _mm_mul_pd(r, r));
          s = 1.0 / sqrt((b_v[0] + b_v[1]) + v[2] * v[2]);
          r = _mm_loadu_pd(&v[0]);
          _mm_storeu_pd(&b_v[0], _mm_mul_pd(r, _mm_set1_pd(s)));
          b_v[2] = v[2] * s;
          s = b_v[0] * b_v[0] * 0.0 + 1.0;
          tempR[0] = s;
          tempR_tmp = b_v[0] * b_v[1] * 0.0;
          b_tempR_tmp = tempR_tmp - b_v[2] * 0.0;
          tempR[1] = b_tempR_tmp;
          c_tempR_tmp = b_v[0] * b_v[2] * 0.0;
          qidx_idx_0 = c_tempR_tmp + b_v[1] * 0.0;
          tempR[2] = qidx_idx_0;
          tempR_tmp += b_v[2] * 0.0;
          tempR[3] = tempR_tmp;
          qidx_idx_1 = b_v[1] * b_v[1] * 0.0 + 1.0;
          tempR[4] = qidx_idx_1;
          d_tempR_tmp = b_v[1] * b_v[2] * 0.0;
          e_tempR_tmp = d_tempR_tmp - b_v[0] * 0.0;
          tempR[5] = e_tempR_tmp;
          c_tempR_tmp -= b_v[1] * 0.0;
          tempR[6] = c_tempR_tmp;
          d_tempR_tmp += b_v[0] * 0.0;
          tempR[7] = d_tempR_tmp;
          f_tempR_tmp = b_v[2] * b_v[2] * 0.0 + 1.0;
          tempR[8] = f_tempR_tmp;
          R[0] = s;
          R[1] = b_tempR_tmp;
          R[2] = qidx_idx_0;
          R[3] = tempR_tmp;
          R[4] = qidx_idx_1;
          R[5] = e_tempR_tmp;
          R[6] = c_tempR_tmp;
          R[7] = d_tempR_tmp;
          R[8] = f_tempR_tmp;
          for (k = 0; k < 3; k++) {
            R[k] = tempR[3 * k];
            R[k + 3] = tempR[3 * k + 1];
            R[k + 6] = tempR[3 * k + 2];
          }
          memset(&b[0], 0, 16U * sizeof(double));
          for (k = 0; k < 3; k++) {
            minPathLength = k << 2;
            b[minPathLength] = R[3 * k];
            b[minPathLength + 1] = R[3 * k + 1];
            b[minPathLength + 2] = R[3 * k + 2];
          }
          b[15] = 1.0;
        } break;
        case 1:
          rigidBodyJoint_get_JointAxis(joint, v);
          memset(&R[0], 0, 9U * sizeof(double));
          R[0] = 1.0;
          R[4] = 1.0;
          R[8] = 1.0;
          for (k = 0; k < 3; k++) {
            minPathLength = k << 2;
            b[minPathLength] = R[3 * k];
            b[minPathLength + 1] = R[3 * k + 1];
            b[minPathLength + 2] = R[3 * k + 2];
            b[k + 12] = v[k] * 0.0;
          }
          b[3] = 0.0;
          b[7] = 0.0;
          b[11] = 0.0;
          b[15] = 1.0;
          break;
        case 2:
          /* A check that is always false is detected at compile-time.
           * Eliminating code that follows. */
          break;
        default:
          memset(&b[0], 0, 16U * sizeof(double));
          b[0] = 1.0;
          b[5] = 1.0;
          b[10] = 1.0;
          b[15] = 1.0;
          break;
        }
        for (k = 0; k < 16; k++) {
          Tj[k] = joint->ChildToJointTransform[k];
        }
        for (k = 0; k < 4; k++) {
          s = Tj1[k];
          tempR_tmp = Tj1[k + 4];
          b_tempR_tmp = Tj1[k + 8];
          c_tempR_tmp = Tj1[k + 12];
          for (b_i = 0; b_i < 4; b_i++) {
            X_tmp = b_i << 2;
            T1j[k + X_tmp] = ((s * b[X_tmp] + tempR_tmp * b[X_tmp + 1]) +
                              b_tempR_tmp * b[X_tmp + 2]) +
                             c_tempR_tmp * b[X_tmp + 3];
          }
          s = T1j[k];
          tempR_tmp = T1j[k + 4];
          b_tempR_tmp = T1j[k + 8];
          c_tempR_tmp = T1j[k + 12];
          for (b_i = 0; b_i < 4; b_i++) {
            X_tmp = b_i << 2;
            Tc2p[k + X_tmp] = ((s * Tj[X_tmp] + tempR_tmp * Tj[X_tmp + 1]) +
                               b_tempR_tmp * Tj[X_tmp + 2]) +
                              c_tempR_tmp * Tj[X_tmp + 3];
          }
        }
      } else {
        double Tj[16];
        double qidx_idx_0;
        double qidx_idx_1;
        minPathLength = (int)nextBody->Index;
        qidx_idx_0 = obj->PositionDoFMap[minPathLength - 1];
        qidx_idx_1 = obj->PositionDoFMap[minPathLength + 5];
        if (qidx_idx_0 > qidx_idx_1) {
          k = 0;
          b_i = 0;
        } else {
          k = (int)qidx_idx_0 - 1;
          b_i = (int)qidx_idx_1;
        }
        loop_ub = b_i - k;
        b_i = b_qv->size[0];
        b_qv->size[0] = loop_ub;
        emxEnsureCapacity_real_T(b_qv, b_i);
        ancestorIndices1_data = b_qv->data;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          ancestorIndices1_data[b_i] = qv_data[k + b_i];
        }
        c_rigidBodyJoint_transformBodyT(joint, b_qv, Tc2p);
        minPathLength = (int)nextBody->Index;
        qidx_idx_0 = obj->VelocityDoFMap[minPathLength - 1];
        qidx_idx_1 = obj->VelocityDoFMap[minPathLength + 5];
        if (nextBodyIsParent) {
          for (k = 0; k < 16; k++) {
            Tj[k] = joint->ChildToJointTransform[k];
          }
        } else {
          for (k = 0; k < 16; k++) {
            Tj1[k] = joint->JointToParentTransform[k];
          }
          for (k = 0; k < 3; k++) {
            R[3 * k] = Tj1[k];
            R[3 * k + 1] = Tj1[k + 4];
            R[3 * k + 2] = Tj1[k + 8];
          }
          r = _mm_loadu_pd(&R[0]);
          r1 = _mm_set1_pd(-1.0);
          _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[2]);
          _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[4]);
          _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[6]);
          _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
          tempR[8] = -R[8];
          s = Tj1[12];
          tempR_tmp = Tj1[13];
          b_tempR_tmp = Tj1[14];
          for (k = 0; k < 3; k++) {
            minPathLength = k << 2;
            Tj[minPathLength] = R[3 * k];
            Tj[minPathLength + 1] = R[3 * k + 1];
            Tj[minPathLength + 2] = R[3 * k + 2];
            Tj[k + 12] = (tempR[k] * s + tempR[k + 3] * tempR_tmp) +
                         tempR[k + 6] * b_tempR_tmp;
          }
          Tj[3] = 0.0;
          Tj[7] = 0.0;
          Tj[11] = 0.0;
          Tj[15] = 1.0;
        }
        for (k = 0; k < 4; k++) {
          s = Tj[k];
          tempR_tmp = Tj[k + 4];
          b_tempR_tmp = Tj[k + 8];
          c_tempR_tmp = Tj[k + 12];
          for (b_i = 0; b_i < 4; b_i++) {
            X_tmp = b_i << 2;
            T1j[k + X_tmp] = ((s * T1[X_tmp] + tempR_tmp * T1[X_tmp + 1]) +
                              b_tempR_tmp * T1[X_tmp + 2]) +
                             c_tempR_tmp * T1[X_tmp + 3];
          }
        }
        for (k = 0; k < 3; k++) {
          R[3 * k] = T1j[k];
          R[3 * k + 1] = T1j[k + 4];
          R[3 * k + 2] = T1j[k + 8];
        }
        r = _mm_loadu_pd(&R[0]);
        r1 = _mm_set1_pd(-1.0);
        _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[2]);
        _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[4]);
        _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[6]);
        _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
        tempR[8] = -R[8];
        s = T1j[12];
        tempR_tmp = T1j[13];
        b_tempR_tmp = T1j[14];
        for (k = 0; k < 3; k++) {
          minPathLength = k << 2;
          Tj1[minPathLength] = R[3 * k];
          Tj1[minPathLength + 1] = R[3 * k + 1];
          Tj1[minPathLength + 2] = R[3 * k + 2];
          Tj1[k + 12] = (tempR[k] * s + tempR[k + 3] * tempR_tmp) +
                        tempR[k + 6] * b_tempR_tmp;
        }
        Tj1[3] = 0.0;
        Tj1[7] = 0.0;
        Tj1[11] = 0.0;
        Tj1[15] = 1.0;
        R[0] = 0.0;
        R[3] = -Tj1[14];
        R[6] = Tj1[13];
        R[1] = Tj1[14];
        R[4] = 0.0;
        R[7] = -Tj1[12];
        R[2] = -Tj1[13];
        R[5] = Tj1[12];
        R[8] = 0.0;
        for (k = 0; k < 3; k++) {
          s = R[k];
          tempR_tmp = R[k + 3];
          b_tempR_tmp = R[k + 6];
          for (b_i = 0; b_i < 3; b_i++) {
            X_tmp = b_i << 2;
            tempR[k + 3 * b_i] = (s * Tj1[X_tmp] + tempR_tmp * Tj1[X_tmp + 1]) +
                                 b_tempR_tmp * Tj1[X_tmp + 2];
            X[b_i + 6 * k] = Tj1[b_i + (k << 2)];
            X[b_i + 6 * (k + 3)] = 0.0;
          }
        }
        for (k = 0; k < 3; k++) {
          X[6 * k + 3] = tempR[3 * k];
          X_tmp = k << 2;
          minPathLength = 6 * (k + 3);
          X[minPathLength + 3] = Tj1[X_tmp];
          X[6 * k + 4] = tempR[3 * k + 1];
          X[minPathLength + 4] = Tj1[X_tmp + 1];
          X[6 * k + 5] = tempR[3 * k + 2];
          X[minPathLength + 5] = Tj1[X_tmp + 2];
        }
        int b_size[2];
        c_rigidBodyJoint_get_MotionSubs(joint, b_data, b_size);
        X_tmp = b_size[1];
        for (loop_ub = 0; loop_ub < X_tmp; loop_ub++) {
          minPathLength = loop_ub * 6;
          for (b_i = 0; b_i < 6; b_i++) {
            s = 0.0;
            for (k = 0; k < 6; k++) {
              s += X[k * 6 + b_i] * b_data[minPathLength + k];
            }
            y_data[minPathLength + b_i] = s;
          }
        }
        if (qidx_idx_0 > qidx_idx_1) {
          k = 0;
          b_i = 0;
        } else {
          k = (int)qidx_idx_0 - 1;
          b_i = (int)qidx_idx_1;
        }
        loop_ub = b_i - k;
        for (b_i = 0; b_i < loop_ub; b_i++) {
          r = _mm_loadu_pd(&y_data[6 * b_i]);
          X_tmp = k + b_i;
          r1 = _mm_set1_pd(jointSign);
          _mm_storeu_pd(&ancestorIndices2_data[6 * X_tmp], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&y_data[6 * b_i + 2]);
          _mm_storeu_pd(&ancestorIndices2_data[6 * X_tmp + 2],
                        _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&y_data[6 * b_i + 4]);
          _mm_storeu_pd(&ancestorIndices2_data[6 * X_tmp + 4],
                        _mm_mul_pd(r, r1));
        }
      }
      if (nextBodyIsParent) {
        for (k = 0; k < 4; k++) {
          s = Tc2p[k];
          tempR_tmp = Tc2p[k + 4];
          b_tempR_tmp = Tc2p[k + 8];
          c_tempR_tmp = Tc2p[k + 12];
          for (b_i = 0; b_i < 4; b_i++) {
            X_tmp = b_i << 2;
            T1j[k + X_tmp] = ((s * T1[X_tmp] + tempR_tmp * T1[X_tmp + 1]) +
                              b_tempR_tmp * T1[X_tmp + 2]) +
                             c_tempR_tmp * T1[X_tmp + 3];
          }
        }
        memcpy(&T1[0], &T1j[0], 16U * sizeof(double));
      } else {
        for (k = 0; k < 3; k++) {
          R[3 * k] = Tc2p[k];
          R[3 * k + 1] = Tc2p[k + 4];
          R[3 * k + 2] = Tc2p[k + 8];
        }
        r = _mm_loadu_pd(&R[0]);
        r1 = _mm_set1_pd(-1.0);
        _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[2]);
        _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[4]);
        _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[6]);
        _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
        tempR[8] = -R[8];
        s = Tc2p[12];
        tempR_tmp = Tc2p[13];
        b_tempR_tmp = Tc2p[14];
        for (k = 0; k < 3; k++) {
          minPathLength = k << 2;
          T1j[minPathLength] = R[3 * k];
          T1j[minPathLength + 1] = R[3 * k + 1];
          T1j[minPathLength + 2] = R[3 * k + 2];
          T1j[k + 12] = (tempR[k] * s + tempR[k + 3] * tempR_tmp) +
                        tempR[k + 6] * b_tempR_tmp;
        }
        T1j[3] = 0.0;
        T1j[7] = 0.0;
        T1j[11] = 0.0;
        T1j[15] = 1.0;
        for (k = 0; k < 4; k++) {
          s = T1j[k];
          tempR_tmp = T1j[k + 4];
          b_tempR_tmp = T1j[k + 8];
          c_tempR_tmp = T1j[k + 12];
          for (b_i = 0; b_i < 4; b_i++) {
            X_tmp = b_i << 2;
            Tj1[k + X_tmp] = ((s * T1[X_tmp] + tempR_tmp * T1[X_tmp + 1]) +
                              b_tempR_tmp * T1[X_tmp + 2]) +
                             c_tempR_tmp * T1[X_tmp + 3];
          }
        }
        memcpy(&T1[0], &Tj1[0], 16U * sizeof(double));
      }
    }
    emxFree_real_T(&b_qv);
    emxFree_real_T(&kinematicPathIndices);
    for (k = 0; k < 3; k++) {
      b_i = k << 2;
      s = T1[b_i];
      X[6 * k] = s;
      X_tmp = 6 * (k + 3);
      X[X_tmp] = 0.0;
      X[6 * k + 3] = 0.0;
      X[X_tmp + 3] = s;
      s = T1[b_i + 1];
      X[6 * k + 1] = s;
      X[X_tmp + 1] = 0.0;
      X[6 * k + 4] = 0.0;
      X[X_tmp + 4] = s;
      s = T1[b_i + 2];
      X[6 * k + 2] = s;
      X[X_tmp + 2] = 0.0;
      X[6 * k + 5] = 0.0;
      X[X_tmp + 5] = s;
    }
    X_tmp = Jac->size[1];
    emxInit_real_T(&B, 2);
    k = B->size[0] * B->size[1];
    B->size[0] = 6;
    B->size[1] = Jac->size[1];
    emxEnsureCapacity_real_T(B, k);
    ancestorIndices1_data = B->data;
    minPathLength = 6 * Jac->size[1];
    for (k = 0; k < minPathLength; k++) {
      ancestorIndices1_data[k] = ancestorIndices2_data[k];
    }
    k = Jac->size[0] * Jac->size[1];
    Jac->size[0] = 6;
    Jac->size[1] = X_tmp;
    emxEnsureCapacity_real_T(Jac, k);
    ancestorIndices2_data = Jac->data;
    for (loop_ub = 0; loop_ub < X_tmp; loop_ub++) {
      minPathLength = loop_ub * 6;
      for (i = 0; i < 6; i++) {
        s = 0.0;
        for (k = 0; k < 6; k++) {
          s += X[k * 6 + i] * ancestorIndices1_data[minPathLength + k];
        }
        ancestorIndices2_data[minPathLength + i] = s;
      }
    }
    emxFree_real_T(&B);
    T_size[0] = 4;
    T_size[1] = 4;
    memcpy(&T_data[0], &T1[0], 16U * sizeof(double));
  } else {
    T_size[0] = 0;
    T_size[1] = 0;
    Jac->size[0] = 6;
    Jac->size[1] = 0;
  }
}

double c_RigidBodyTree_findBodyIndexBy(e_robotics_manip_internal_Rigid *obj,
                                       const char bodyname_data[],
                                       const int bodyname_size[2])
{
  c_robotics_manip_internal_Rigid *b_obj;
  double bid;
  double obj_Length;
  int obj_Vector_size[2];
  int loop_ub;
  char obj_Vector[200];
  char obj_Vector_data[200];
  bid = -1.0;
  obj_Length = obj->Base.NameInternal.Length;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    obj_Vector[loop_ub] = obj->Base.NameInternal.Vector[loop_ub];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
               bodyname_size)) {
    bid = 0.0;
  } else {
    double d;
    int i;
    boolean_T exitg1;
    d = obj->NumBodies;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= (int)d - 1)) {
      b_obj = obj->Bodies[i];
      obj_Length = b_obj->NameInternal.Length;
      for (loop_ub = 0; loop_ub < 200; loop_ub++) {
        obj_Vector[loop_ub] = b_obj->NameInternal.Vector[loop_ub];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)obj_Length;
      }
      obj_Vector_size[0] = 1;
      obj_Vector_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        memcpy(&obj_Vector_data[0], &obj_Vector[0],
               (unsigned int)loop_ub * sizeof(char));
      }
      if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
                   bodyname_size)) {
        bid = (double)i + 1.0;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }
  return bid;
}

void c_RigidBodyTree_get_JointPositi(e_robotics_manip_internal_Rigid *obj,
                                     emxArray_real_T *limits)
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Rigid *body;
  rigidBodyJoint *b_obj;
  double tmp_data[14];
  double k;
  double pnum;
  double *limits_data;
  int b_i;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  i = limits->size[0] * limits->size[1];
  limits->size[0] = (int)obj->PositionNumber;
  limits->size[1] = 2;
  emxEnsureCapacity_real_T(limits, i);
  limits_data = limits->data;
  loop_ub = (int)obj->PositionNumber << 1;
  for (i = 0; i < loop_ub; i++) {
    limits_data[i] = 0.0;
  }
  k = 1.0;
  pnum = obj->NumBodies;
  i = (int)pnum;
  for (b_i = 0; b_i < i; b_i++) {
    char obj_Vector[200];
    boolean_T b_bool;
    body = obj->Bodies[b_i];
    b_obj = body->JointInternal;
    pnum = b_obj->TypeInternal.Length;
    for (i1 = 0; i1 < 200; i1++) {
      obj_Vector[i1] = b_obj->TypeInternal.Vector[i1];
    }
    if (pnum < 1.0) {
      i1 = 0;
    } else {
      i1 = (int)pnum;
    }
    b_bool = false;
    if (i1 == 5) {
      loop_ub = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub < 5) {
          if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
            exitg1 = 1;
          } else {
            loop_ub++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (!b_bool) {
      int tmp_size[2];
      pnum = body->JointInternal->PositionNumber;
      pnum += k;
      if (k > pnum - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)k - 1;
        i2 = (int)(pnum - 1.0);
      }
      c_rigidBodyJoint_get_PositionLi(body->JointInternal, tmp_data, tmp_size);
      loop_ub = i2 - i1;
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          limits_data[(i1 + i3) + limits->size[0] * i2] =
              tmp_data[i3 + tmp_size[0] * i2];
        }
      }
      k = pnum;
    }
  }
}

void c_RigidBodyTree_validateConfigu(e_robotics_manip_internal_Rigid *obj,
                                     const b_struct_T Q[6],
                                     emxArray_real_T *qvec)
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Rigid *body;
  emxArray_boolean_T *lbOK;
  emxArray_boolean_T *ubOK;
  emxArray_int32_T *indicesUpperBoundViolation;
  emxArray_real_T *limits;
  rigidBodyJoint *jnt;
  double idx_idx_0;
  double *limits_data;
  double *qvec_data;
  int obj_Vector_size[2];
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
  int kstr;
  int loop_ub;
  int *indicesUpperBoundViolation_data;
  char obj_Vector[200];
  char obj_Vector_data[200];
  boolean_T b_bool;
  boolean_T exitg2;
  boolean_T guard1;
  boolean_T *lbOK_data;
  boolean_T *ubOK_data;
  loop_ub = (int)obj->PositionNumber;
  i = qvec->size[0];
  qvec->size[0] = loop_ub;
  emxEnsureCapacity_real_T(qvec, i);
  qvec_data = qvec->data;
  b_loop_ub = (int)obj->PositionNumber;
  for (i = 0; i < b_loop_ub; i++) {
    qvec_data[i] = 0.0;
  }
  idx_idx_0 = obj->NumBodies;
  i = (int)idx_idx_0;
  for (b_i = 0; b_i < i; b_i++) {
    body = obj->Bodies[b_i];
    jnt = body->JointInternal;
    idx_idx_0 = jnt->TypeInternal.Length;
    for (i1 = 0; i1 < 200; i1++) {
      obj_Vector[i1] = jnt->TypeInternal.Vector[i1];
    }
    if (idx_idx_0 < 1.0) {
      i1 = 0;
    } else {
      i1 = (int)idx_idx_0;
    }
    b_bool = false;
    if (i1 == 5) {
      kstr = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (kstr < 5) {
          if (obj_Vector[kstr] != b_cv[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (!b_bool) {
      double idx_idx_1;
      int idx;
      jnt = body->JointInternal;
      idx = -2;
      kstr = 0;
      exitg2 = false;
      while ((!exitg2) && (kstr < 6)) {
        idx_idx_0 = jnt->NameInternal.Length;
        for (i1 = 0; i1 < 200; i1++) {
          obj_Vector[i1] = jnt->NameInternal.Vector[i1];
        }
        if (idx_idx_0 < 1.0) {
          b_loop_ub = 0;
        } else {
          b_loop_ub = (int)idx_idx_0;
        }
        obj_Vector_size[0] = 1;
        obj_Vector_size[1] = b_loop_ub;
        if (b_loop_ub - 1 >= 0) {
          memcpy(&obj_Vector_data[0], &obj_Vector[0],
                 (unsigned int)b_loop_ub * sizeof(char));
        }
        if (b_strcmp(Q[kstr].JointName.data, Q[kstr].JointName.size,
                     obj_Vector_data, obj_Vector_size)) {
          idx = kstr;
          exitg2 = true;
        } else {
          kstr++;
        }
      }
      idx_idx_0 = obj->PositionDoFMap[b_i];
      idx_idx_1 = obj->PositionDoFMap[b_i + 6];
      if (idx_idx_0 > idx_idx_1) {
        i1 = 0;
        kstr = 0;
      } else {
        i1 = (int)idx_idx_0 - 1;
        kstr = (int)idx_idx_1;
      }
      b_loop_ub = kstr - i1;
      for (kstr = 0; kstr < b_loop_ub; kstr++) {
        qvec_data[i1 + kstr] = Q[idx].JointPosition;
      }
    }
  }
  emxInit_real_T(&limits, 2);
  c_RigidBodyTree_get_JointPositi(obj, limits);
  limits_data = limits->data;
  emxInit_boolean_T(&ubOK);
  if (qvec->size[0] == limits->size[0]) {
    i = ubOK->size[0];
    ubOK->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(ubOK, i);
    ubOK_data = ubOK->data;
    for (i = 0; i < loop_ub; i++) {
      ubOK_data[i] = (qvec_data[i] <= limits_data[i + limits->size[0]] +
                                          4.4408920985006262E-16);
    }
  } else {
    binary_expand_op_1(ubOK, qvec, limits);
    ubOK_data = ubOK->data;
  }
  emxInit_boolean_T(&lbOK);
  if (qvec->size[0] == limits->size[0]) {
    loop_ub = qvec->size[0];
    i = lbOK->size[0];
    lbOK->size[0] = qvec->size[0];
    emxEnsureCapacity_boolean_T(lbOK, i);
    lbOK_data = lbOK->data;
    for (i = 0; i < loop_ub; i++) {
      lbOK_data[i] = (qvec_data[i] >= limits_data[i] - 4.4408920985006262E-16);
    }
  } else {
    binary_expand_op(lbOK, qvec, limits);
    lbOK_data = lbOK->data;
  }
  b_bool = true;
  kstr = 1;
  exitg2 = false;
  while ((!exitg2) && (kstr <= ubOK->size[0])) {
    if (!ubOK_data[kstr - 1]) {
      b_bool = false;
      exitg2 = true;
    } else {
      kstr++;
    }
  }
  emxInit_int32_T(&indicesUpperBoundViolation, 1);
  guard1 = false;
  if (b_bool) {
    b_bool = true;
    kstr = 1;
    exitg2 = false;
    while ((!exitg2) && (kstr <= lbOK->size[0])) {
      if (!lbOK_data[kstr - 1]) {
        b_bool = false;
        exitg2 = true;
      } else {
        kstr++;
      }
    }
    if (!b_bool) {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    loop_ub = ubOK->size[0];
    for (i = 0; i < loop_ub; i++) {
      ubOK_data[i] = !ubOK_data[i];
    }
    eml_find(ubOK, indicesUpperBoundViolation);
    indicesUpperBoundViolation_data = indicesUpperBoundViolation->data;
    loop_ub = indicesUpperBoundViolation->size[0];
    for (i = 0; i < loop_ub; i++) {
      qvec_data[indicesUpperBoundViolation_data[i] - 1] =
          limits_data[(indicesUpperBoundViolation_data[i] + limits->size[0]) -
                      1];
    }
    loop_ub = lbOK->size[0];
    for (i = 0; i < loop_ub; i++) {
      lbOK_data[i] = !lbOK_data[i];
    }
    eml_find(lbOK, indicesUpperBoundViolation);
    indicesUpperBoundViolation_data = indicesUpperBoundViolation->data;
    loop_ub = indicesUpperBoundViolation->size[0];
    for (i = 0; i < loop_ub; i++) {
      qvec_data[indicesUpperBoundViolation_data[i] - 1] =
          limits_data[indicesUpperBoundViolation_data[i] - 1];
    }
  }
  emxFree_int32_T(&indicesUpperBoundViolation);
  emxFree_boolean_T(&lbOK);
  emxFree_boolean_T(&ubOK);
  emxFree_real_T(&limits);
}

/* End of code generation (RigidBodyTree.c) */
