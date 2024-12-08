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
#include "CharacterVector.h"
#include "CollisionSet.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "validatestring.h"
#include "collisioncodegen_api.hpp"
#include <string.h>

/* Function Definitions */
c_robotics_manip_internal_Rigid *RigidBody_RigidBody(
    c_robotics_manip_internal_Rigid *obj, const char bodyInput[10],
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1)
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
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
  s = iobj_1->TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    double d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
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
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *
RigidBody_copy(c_robotics_manip_internal_Rigid *obj,
               d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1,
               c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  void *copyGeometryInternal;
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Colli expl_temp;
  c_robotics_manip_internal_Colli r;
  c_robotics_manip_internal_Rigid *newbody;
  d_robotics_manip_internal_Colli *f_obj;
  d_robotics_manip_internal_Colli *newObj;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double d_obj[16];
  double t22_WorldPose[16];
  double poslim_data[14];
  double e_obj[9];
  double c_obj[7];
  double obj_Length;
  double obj_idx_1;
  double obj_idx_2;
  int b_obj_Vector_size[2];
  int obj_Vector_size[2];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int loop_ub;
  int poslim_size_idx_0;
  char b_obj_Vector_data[204];
  char b_obj_Vector[200];
  char obj_Vector[200];
  char obj_Vector_data[200];
  signed char c_I[36];
  signed char b_I[9];
  char tmp_data[9];
  signed char homepos_data[7];
  boolean_T result;
  obj_Length = obj->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = obj->NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  newbody = iobj_2;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_2->NameInternal = s;
  s = iobj_2->NameInternal;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  CharacterVector_setVector(&s, obj_Vector_data, obj_Vector_size);
  iobj_2->NameInternal = s;
  b_obj_Vector_size[0] = 1;
  b_obj_Vector_size[1] = loop_ub + 4;
  if (loop_ub - 1 >= 0) {
    memcpy(&b_obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  b_obj_Vector_data[loop_ub] = '_';
  b_obj_Vector_data[loop_ub + 1] = 'j';
  b_obj_Vector_data[loop_ub + 2] = 'n';
  b_obj_Vector_data[loop_ub + 3] = 't';
  iobj_2->JointInternal = rigidBodyJoint_rigidBodyJoint(
      &iobj_1[0], b_obj_Vector_data, b_obj_Vector_size);
  iobj_2->Index = -1.0;
  iobj_2->ParentIndex = -1.0;
  iobj_2->MassInternal = 1.0;
  iobj_2->CenterOfMassInternal[0] = 0.0;
  iobj_2->CenterOfMassInternal[1] = 0.0;
  iobj_2->CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    iobj_2->InertiaInternal[i] = b_I[i];
  }
  for (i = 0; i < 36; i++) {
    c_I[i] = 0;
  }
  for (ibmat = 0; ibmat < 6; ibmat++) {
    c_I[ibmat + 6 * ibmat] = 1;
  }
  for (i = 0; i < 36; i++) {
    iobj_2->SpatialInertia[i] = c_I[i];
  }
  iobj_2->CollisionsInternal = CollisionSet_CollisionSet(&iobj_0[0], 0.0);
  iobj_2->matlabCodegenIsDeleted = false;
  b_obj = obj->JointInternal;
  obj_Length = b_obj->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = b_obj->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)obj_Length;
  }
  obj_Length = b_obj->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    b_obj_Vector[i] = b_obj->NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    ibmat = 0;
  } else {
    ibmat = (int)obj_Length;
  }
  iobj_1[1].InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_1[1].JointToParentTransform[i] = i1;
    iobj_1[1].ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_1[1].PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_1[1].HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_1[1].MotionSubspaceInternal[i] = 0.0;
  }
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1[1].NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_1[1].TypeInternal = s;
  s = iobj_1[1].NameInternal;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = ibmat;
  if (ibmat - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &b_obj_Vector[0],
           (unsigned int)ibmat * sizeof(char));
  }
  CharacterVector_setVector(&s, obj_Vector_data, obj_Vector_size);
  iobj_1[1].NameInternal = s;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  s = iobj_1[1].TypeInternal;
  validatestring(obj_Vector_data, obj_Vector_size, tmp_data, b_obj_Vector_size);
  CharacterVector_setVector(&s, tmp_data, b_obj_Vector_size);
  iobj_1[1].TypeInternal = s;
  obj_Length = iobj_1[1].TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = iobj_1[1].TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj_Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv[ibmat] != obj_Vector[ibmat]) {
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
          if (cv3[ibmat] != obj_Vector[ibmat]) {
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
            if (b_cv1[ibmat] != obj_Vector[ibmat]) {
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
    iobj_1[1].VelocityNumber = 1.0;
    iobj_1[1].PositionNumber = 1.0;
    iobj_1[1].JointAxisInternal[0] = 0.0;
    iobj_1[1].JointAxisInternal[1] = 0.0;
    iobj_1[1].JointAxisInternal[2] = 1.0;
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
    iobj_1[1].VelocityNumber = 1.0;
    iobj_1[1].PositionNumber = 1.0;
    iobj_1[1].JointAxisInternal[0] = 0.0;
    iobj_1[1].JointAxisInternal[1] = 0.0;
    iobj_1[1].JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b[6];
    for (i = 0; i < 36; i++) {
      c_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      c_I[ibmat + 6 * ibmat] = 1;
    }
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = c_I[i];
    }
    poslim_size_idx_0 = 7;
    for (loop_ub = 0; loop_ub < 2; loop_ub++) {
      signed char b_tmp;
      ibmat = loop_ub * 3;
      b_tmp = (signed char)(10 * loop_ub - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * loop_ub] = rtNaN;
      poslim_data[7 * loop_ub + 1] = rtNaN;
      poslim_data[7 * loop_ub + 2] = rtNaN;
      poslim_data[7 * loop_ub + 3] = rtNaN;
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
    iobj_1[1].VelocityNumber = 6.0;
    iobj_1[1].PositionNumber = 7.0;
    iobj_1[1].JointAxisInternal[0] = rtNaN;
    iobj_1[1].JointAxisInternal[1] = rtNaN;
    iobj_1[1].JointAxisInternal[2] = rtNaN;
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
    iobj_1[1].VelocityNumber = 0.0;
    iobj_1[1].PositionNumber = 0.0;
    iobj_1[1].JointAxisInternal[0] = 0.0;
    iobj_1[1].JointAxisInternal[1] = 0.0;
    iobj_1[1].JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(&iobj_1[1], msubspace_data);
  obj_Length = iobj_1[1].TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = iobj_1[1].TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj_Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (obj_Vector[ibmat] != b_cv2[ibmat]) {
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
    obj_Length = iobj_1[1].PositionNumber;
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)obj_Length;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        iobj_1[1].PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1[1].HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1[1].PositionLimitsInternal[0] = poslim_data[0];
    iobj_1[1].PositionLimitsInternal[7] = poslim_data[1];
    iobj_1[1].HomePositionInternal[0] = homepos_data[0];
  }
  obj_Length = b_obj->NameInternal.Length;
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj_Length;
  }
  if (i != 0) {
    obj_Length = b_obj->NameInternal.Length;
    for (i = 0; i < 200; i++) {
      obj_Vector[i] = b_obj->NameInternal.Vector[i];
    }
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)obj_Length;
    }
    if (!iobj_1[1].InTree) {
      s = iobj_1[1].NameInternal;
      obj_Vector_size[0] = 1;
      obj_Vector_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        memcpy(&obj_Vector_data[0], &obj_Vector[0],
               (unsigned int)loop_ub * sizeof(char));
      }
      CharacterVector_setVector(&s, obj_Vector_data, obj_Vector_size);
      iobj_1[1].NameInternal = s;
    }
  }
  for (i = 0; i < 14; i++) {
    poslim_data[i] = b_obj->PositionLimitsInternal[i];
  }
  for (i = 0; i < 14; i++) {
    iobj_1[1].PositionLimitsInternal[i] = poslim_data[i];
  }
  for (i = 0; i < 7; i++) {
    c_obj[i] = b_obj->HomePositionInternal[i];
  }
  for (i = 0; i < 7; i++) {
    iobj_1[1].HomePositionInternal[i] = c_obj[i];
  }
  obj_Length = b_obj->JointAxisInternal[0];
  obj_idx_1 = b_obj->JointAxisInternal[1];
  obj_idx_2 = b_obj->JointAxisInternal[2];
  iobj_1[1].JointAxisInternal[0] = obj_Length;
  iobj_1[1].JointAxisInternal[1] = obj_idx_1;
  iobj_1[1].JointAxisInternal[2] = obj_idx_2;
  c_rigidBodyJoint_get_MotionSubs(b_obj, msubspace_data, b_obj_Vector_size);
  c_rigidBodyJoint_set_MotionSubs(&iobj_1[1], msubspace_data);
  for (i = 0; i < 16; i++) {
    d_obj[i] = b_obj->JointToParentTransform[i];
  }
  for (i = 0; i < 16; i++) {
    iobj_1[1].JointToParentTransform[i] = d_obj[i];
  }
  for (i = 0; i < 16; i++) {
    d_obj[i] = b_obj->ChildToJointTransform[i];
  }
  for (i = 0; i < 16; i++) {
    iobj_1[1].ChildToJointTransform[i] = d_obj[i];
  }
  iobj_2->JointInternal = &iobj_1[1];
  iobj_2->MassInternal = obj->MassInternal;
  obj_Length = obj->CenterOfMassInternal[0];
  obj_idx_1 = obj->CenterOfMassInternal[1];
  obj_idx_2 = obj->CenterOfMassInternal[2];
  iobj_2->CenterOfMassInternal[0] = obj_Length;
  iobj_2->CenterOfMassInternal[1] = obj_idx_1;
  iobj_2->CenterOfMassInternal[2] = obj_idx_2;
  for (i = 0; i < 9; i++) {
    e_obj[i] = obj->InertiaInternal[i];
  }
  for (i = 0; i < 9; i++) {
    iobj_2->InertiaInternal[i] = e_obj[i];
  }
  for (i = 0; i < 36; i++) {
    msubspace_data[i] = obj->SpatialInertia[i];
  }
  for (i = 0; i < 36; i++) {
    iobj_2->SpatialInertia[i] = msubspace_data[i];
  }
  f_obj = obj->CollisionsInternal;
  newObj = CollisionSet_CollisionSet(&iobj_0[1], f_obj->MaxElements);
  newObj->Size = f_obj->Size;
  obj_Length = f_obj->Size;
  i = (int)obj_Length;
  for (ibmat = 0; ibmat < i; ibmat++) {
    r = f_obj->CollisionGeometries->data[ibmat];
    memcpy(&d_obj[0], &r.LocalPose[0], 16U * sizeof(double));
    memcpy(&t22_WorldPose[0], &r.WorldPose[0], 16U * sizeof(double));
    copyGeometryInternal = collisioncodegen_copyGeometry(r.CollisionPrimitive);
    expl_temp.CollisionPrimitive = copyGeometryInternal;
    memcpy(&expl_temp.LocalPose[0], &d_obj[0], 16U * sizeof(double));
    memcpy(&expl_temp.WorldPose[0], &t22_WorldPose[0], 16U * sizeof(double));
    expl_temp.MeshScale[0] = r.MeshScale[0];
    expl_temp.MeshScale[1] = r.MeshScale[1];
    expl_temp.MeshScale[2] = r.MeshScale[2];
    newObj->CollisionGeometries->data[ibmat] = expl_temp;
  }
  iobj_2->CollisionsInternal = newObj;
  return newbody;
}

c_robotics_manip_internal_Rigid *
b_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1)
{
  static const double dv1[36] = {0.079276964214759632,
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
  static const double dv2[16] = {1.0,     0.0, -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0, 0.0,     0.0, 1.0, 0.0,
                                 0.08505, 0.0, 0.15172, 1.0};
  static const double dv[9] = {
      0.079276964214759632,   0.00024792377218861784, -0.029130311935912909,
      0.00024792377218861784, 0.091392133702590139,   0.00066260610916762442,
      -0.029130311935912909,  0.00066260610916762442, 0.013373436344149846};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv1[6] = {'j', 'o', 'i', 'n', 't', '1'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const signed char iv3[6] = {0, -1, 0, 0, 0, 0};
  static const char b_cv[5] = {'l', 'i', 'n', 'k', '1'};
  static const char b_cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
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
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv2[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
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
    signed char b_I[36];
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    double d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  int msubspace_size[2];
  c_rigidBodyJoint_get_MotionSubs(b_obj->JointInternal, msubspace_data,
                                  msubspace_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj->JointInternal, msubspace_data);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = -1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *
c_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1)
{
  static const double dv1[36] = {0.0021473383658498421,
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
  static const double dv2[16] = {1.0,     0.0,     -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0,     0.0,     0.0, 1.0, 0.0,
                                 0.16161, -0.0165, 0.39308, 1.0};
  static const double dv[9] = {
      0.0021473383658498421,  0.00043478224643843394, -0.0021842452941198296,
      0.00043478224643843394, 0.0062275738404100429,  0.00024484744519511826,
      -0.0021842452941198296, 0.00024484744519511826, 0.0048643183067106268};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv4[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const char b_cv1[6] = {'j', 'o', 'i', 'n', 't', '2'};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const signed char iv3[6] = {0, -1, 0, 0, 0, 0};
  static const char b_cv[5] = {'l', 'i', 'n', 'k', '2'};
  static const char b_cv5[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
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
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv2[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
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
    signed char b_I[36];
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    double d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  int msubspace_size[2];
  c_rigidBodyJoint_get_MotionSubs(b_obj->JointInternal, msubspace_data,
                                  msubspace_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj->JointInternal, msubspace_data);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = -1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *
d_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1)
{
  static const double dv1[36] = {0.00038227670959680652,
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
  static const double dv2[16] = {1.0,     0.0,      -0.0,    0.0, 0.0, 1.0,
                                 0.0,     0.0,      0.0,     0.0, 1.0, 0.0,
                                 0.19676, 0.016444, 0.10409, 1.0};
  static const double dv[9] = {
      0.00038227670959680652,  9.9896089242309635E-5, -0.00049902544617585782,
      9.9896089242309635E-5,   0.00127147469255335,   5.2832875076398257E-5,
      -0.00049902544617585782, 5.2832875076398257E-5, 0.0010618886280044186};
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const signed char iv3[6] = {0, 1, 0, 0, 0, 0};
  static const char b_cv[5] = {'p', 'i', 't', 'c', 'h'};
  static const char b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
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
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
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
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  int msubspace_size[2];
  c_rigidBodyJoint_get_MotionSubs(b_obj->JointInternal, msubspace_data,
                                  msubspace_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj->JointInternal, msubspace_data);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = 0.0;
  b_obj->JointInternal->JointAxisInternal[1] = 1.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.0;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *
e_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1)
{
  static const double dv1[36] = {0.00030659306989070284,
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
  static const double dv2[16] = {1.0,      0.0,         -0.0,   0.0, 0.0, 1.0,
                                 0.0,      0.0,         0.0,    0.0, 1.0, 0.0,
                                 0.095579, -0.00064427, 0.0505, 1.0};
  static const double dv[9] = {
      0.00030659306989070284,  0.00016969514638915506, -0.00031624041430616291,
      0.00016969514638915506,  0.0010894878934764338,  6.80190897028461E-5,
      -0.00031624041430616291, 6.80190897028461E-5,    0.00097981186404543039};
  static const double dv3[6] = {
      -0.46761983415865516, 0.0, 0.88392968651439219, 0.0, 0.0, 0.0};
  static const char b_cv[8] = {'y', 'a', 'w', 'j', 'o', 'i', 'n', 't'};
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 3.0;
  s.Vector[0] = 'y';
  s.Vector[1] = 'a';
  s.Vector[2] = 'w';
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
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
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
    iobj_1->VelocityNumber = 1.0;
    iobj_1->PositionNumber = 1.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  int msubspace_size[2];
  c_rigidBodyJoint_get_MotionSubs(b_obj->JointInternal, msubspace_data,
                                  msubspace_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = dv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj->JointInternal, msubspace_data);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = -0.46761983415865516;
  b_obj->JointInternal->JointAxisInternal[1] = 0.0;
  b_obj->JointInternal->JointAxisInternal[2] = 0.88392968651439219;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

c_robotics_manip_internal_Rigid *
f_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1)
{
  static const double dv1[36] = {0.0021301676780353411,
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
  static const double dv2[16] = {1.0,     0.0,       -0.0,     0.0, 0.0, 1.0,
                                 0.0,     0.0,       0.0,      0.0, 1.0, 0.0,
                                 0.06953, -0.042517, 0.035491, 1.0};
  static const double dv[9] = {
      0.0021301676780353411,  0.0007417655137471849,  -0.0024409365294323776,
      0.0007417655137471849,  0.0061591580099290728,  0.00039146529877202873,
      -0.0024409365294323776, 0.00039146529877202873, 0.0054626710719641609};
  static const double dv3[6] = {
      -0.88392968651439219, 0.0, -0.46761983415865516, 0.0, 0.0, 0.0};
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s = b_obj->NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'r';
  s.Vector[1] = 'o';
  s.Vector[2] = 'l';
  s.Vector[3] = 'l';
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
  s = iobj_1->TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_1->TypeInternal = s;
  s = iobj_1->TypeInternal;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
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
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
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
    signed char b_I[36];
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
    iobj_1->VelocityNumber = 6.0;
    iobj_1->PositionNumber = 7.0;
    iobj_1->JointAxisInternal[0] = rtNaN;
    iobj_1->JointAxisInternal[1] = rtNaN;
    iobj_1->JointAxisInternal[2] = rtNaN;
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
    iobj_1->VelocityNumber = 0.0;
    iobj_1->PositionNumber = 0.0;
    iobj_1->JointAxisInternal[0] = 0.0;
    iobj_1->JointAxisInternal[1] = 0.0;
    iobj_1->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_1, msubspace_data);
  s = iobj_1->TypeInternal;
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
    double d;
    d = iobj_1->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_1->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_1->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_1->PositionLimitsInternal[0] = poslim_data[0];
    iobj_1->PositionLimitsInternal[7] = poslim_data[1];
    iobj_1->HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->JointInternal = iobj_1;
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->JointInternal->ChildToJointTransform[i] = iv[i];
  }
  int msubspace_size[2];
  c_rigidBodyJoint_get_MotionSubs(b_obj->JointInternal, msubspace_data,
                                  msubspace_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = dv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj->JointInternal, msubspace_data);
  b_obj->JointInternal->InTree = true;
  b_obj->JointInternal->PositionLimitsInternal[0] = -2.0;
  b_obj->JointInternal->PositionLimitsInternal[7] = 2.0;
  b_obj->JointInternal->JointAxisInternal[0] = -0.88392968651439219;
  b_obj->JointInternal->JointAxisInternal[1] = 0.0;
  b_obj->JointInternal->JointAxisInternal[2] = -0.46761983415865516;
  b_obj->JointInternal->HomePositionInternal[0] = 0.0;
  b_obj->CollisionsInternal = CollisionSet_CollisionSet(iobj_0, 0.0);
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/* End of code generation (RigidBody.c) */
