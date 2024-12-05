/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: importrobot.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "importrobot.h"
#include "CollisionSet.h"
#include "RigidBody.h"
#include "armvone_data.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rand.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : d_robotics_manip_internal_Rigid *iobj_0
 *                b_rigidBodyTree **iobj_1
 * Return Type  : void
 */
void importrobot(d_robotics_manip_internal_Rigid *iobj_0,
                 b_rigidBodyTree **iobj_1)
{
  static const double dv1[36] = {0.00568540036480312,
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
  static const double dv2[16] = {1.0, 0.0, -0.0, 0.0, 0.0,     1.0, 0.0,   0.0,
                                 0.0, 0.0, 1.0,  0.0, 0.26945, 0.0, 0.216, 1.0};
  static const double dv[9] = {
      0.00568540036480312,    -1.6292124155158921E-5, 0.00010258985607075304,
      -1.6292124155158921E-5, 0.0079788268447147578,  0.00014277899029547592,
      0.00010258985607075304, 0.00014277899029547592, 0.0091598053364996337};
  static const char b_cv[9] = {'t', 'u', 'r', 'n', 't', 'a', 'b', 'l', 'e'};
  static const char b_cv5[9] = {'b', 'a', 's', 'e', '_', 'l', 'i', 'n', 'k'};
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const signed char iv3[6] = {0, 0, -1, 0, 0, 0};
  static const char b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  double msubspace_data[36];
  double poslim_data[14];
  double unusedExpr[5];
  int s_size[2];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  char s_data[204];
  signed char homepos_data[7];
  boolean_T result;
  b_rand(unusedExpr);
  iobj_0->NumBodies = 6.0;
  iobj_0->Bodies[0] = RigidBody_RigidBody(
      &iobj_0->_pobj2[0], cv4, &iobj_0->_pobj0[0], &iobj_0->_pobj1[0]);
  iobj_0->Bodies[1] = RigidBody_RigidBody(
      &iobj_0->_pobj2[1], cv5, &iobj_0->_pobj0[1], &iobj_0->_pobj1[1]);
  iobj_0->Bodies[2] = RigidBody_RigidBody(
      &iobj_0->_pobj2[2], cv6, &iobj_0->_pobj0[2], &iobj_0->_pobj1[2]);
  iobj_0->Bodies[3] = RigidBody_RigidBody(
      &iobj_0->_pobj2[3], cv7, &iobj_0->_pobj0[3], &iobj_0->_pobj1[3]);
  iobj_0->Bodies[4] = RigidBody_RigidBody(
      &iobj_0->_pobj2[4], cv8, &iobj_0->_pobj0[4], &iobj_0->_pobj1[4]);
  iobj_0->Bodies[5] = RigidBody_RigidBody(
      &iobj_0->_pobj2[5], cv9, &iobj_0->_pobj0[5], &iobj_0->_pobj1[5]);
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->_pobj2[6].NameInternal = s;
  s = iobj_0->_pobj2[6].NameInternal;
  s.Length = 9.0;
  for (i = 0; i < 9; i++) {
    s.Vector[i] = b_cv[i];
  }
  iobj_0->_pobj2[6].NameInternal = s;
  iobj_0->_pobj2[6].ParentIndex = 0.0;
  iobj_0->_pobj2[6].MassInternal = 2.3506402744061;
  iobj_0->_pobj2[6].CenterOfMassInternal[0] = -0.00267730480039297;
  iobj_0->_pobj2[6].CenterOfMassInternal[1] = -0.00258676298943122;
  iobj_0->_pobj2[6].CenterOfMassInternal[2] = 0.0234823964354525;
  for (i = 0; i < 9; i++) {
    iobj_0->_pobj2[6].InertiaInternal[i] = dv[i];
  }
  for (i = 0; i < 36; i++) {
    iobj_0->_pobj2[6].SpatialInertia[i] = dv1[i];
  }
  iobj_0->_pobj1[6].InTree = false;
  for (i = 0; i < 16; i++) {
    iobj_0->_pobj1[6].JointToParentTransform[i] = iv[i];
  }
  for (i = 0; i < 16; i++) {
    iobj_0->_pobj1[6].ChildToJointTransform[i] = iv[i];
  }
  for (i = 0; i < 14; i++) {
    iobj_0->_pobj1[6].PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_0->_pobj1[6].HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_0->_pobj1[6].MotionSubspaceInternal[i] = 0.0;
  }
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->_pobj1[6].NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->_pobj1[6].TypeInternal = s;
  s = iobj_0->_pobj1[6].NameInternal;
  s.Length = 14.0;
  for (i = 0; i < 14; i++) {
    s.Vector[i] = cv[i];
  }
  iobj_0->_pobj1[6].NameInternal = s;
  s = iobj_0->_pobj1[6].TypeInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv1[i];
  }
  iobj_0->_pobj1[6].TypeInternal = s;
  s = iobj_0->_pobj1[6].TypeInternal;
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
    iobj_0->_pobj1[6].VelocityNumber = 1.0;
    iobj_0->_pobj1[6].PositionNumber = 1.0;
    iobj_0->_pobj1[6].JointAxisInternal[0] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[1] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[2] = 1.0;
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
    iobj_0->_pobj1[6].VelocityNumber = 1.0;
    iobj_0->_pobj1[6].PositionNumber = 1.0;
    iobj_0->_pobj1[6].JointAxisInternal[0] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[1] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[2] = 1.0;
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
    iobj_0->_pobj1[6].VelocityNumber = 6.0;
    iobj_0->_pobj1[6].PositionNumber = 7.0;
    iobj_0->_pobj1[6].JointAxisInternal[0] = rtNaN;
    iobj_0->_pobj1[6].JointAxisInternal[1] = rtNaN;
    iobj_0->_pobj1[6].JointAxisInternal[2] = rtNaN;
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
    iobj_0->_pobj1[6].VelocityNumber = 0.0;
    iobj_0->_pobj1[6].PositionNumber = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[0] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[1] = 0.0;
    iobj_0->_pobj1[6].JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(&iobj_0->_pobj1[6], msubspace_data);
  s = iobj_0->_pobj1[6].TypeInternal;
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
    d = iobj_0->_pobj1[6].PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        iobj_0->_pobj1[6].PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_0->_pobj1[6].HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    iobj_0->_pobj1[6].PositionLimitsInternal[0] = poslim_data[0];
    iobj_0->_pobj1[6].PositionLimitsInternal[7] = poslim_data[1];
    iobj_0->_pobj1[6].HomePositionInternal[0] = homepos_data[0];
  }
  iobj_0->_pobj2[6].JointInternal = &iobj_0->_pobj1[6];
  for (i = 0; i < 16; i++) {
    iobj_0->_pobj2[6].JointInternal->JointToParentTransform[i] = dv2[i];
  }
  for (i = 0; i < 16; i++) {
    iobj_0->_pobj2[6].JointInternal->ChildToJointTransform[i] = iv[i];
  }
  c_rigidBodyJoint_get_MotionSubs(iobj_0->_pobj2[6].JointInternal,
                                  msubspace_data, s_size);
  for (i = 0; i < 6; i++) {
    msubspace_data[i] = iv3[i];
  }
  c_rigidBodyJoint_set_MotionSubs(iobj_0->_pobj2[6].JointInternal,
                                  msubspace_data);
  iobj_0->_pobj2[6].JointInternal->InTree = true;
  iobj_0->_pobj2[6].JointInternal->PositionLimitsInternal[0] = -2.0;
  iobj_0->_pobj2[6].JointInternal->PositionLimitsInternal[7] = 2.0;
  iobj_0->_pobj2[6].JointInternal->JointAxisInternal[0] = 0.0;
  iobj_0->_pobj2[6].JointInternal->JointAxisInternal[1] = 0.0;
  iobj_0->_pobj2[6].JointInternal->JointAxisInternal[2] = -1.0;
  iobj_0->_pobj2[6].JointInternal->HomePositionInternal[0] = 0.0;
  iobj_0->_pobj2[6].CollisionsInternal =
      CollisionSet_CollisionSet(&iobj_0->_pobj0[6], 0.0);
  iobj_0->_pobj2[6].matlabCodegenIsDeleted = false;
  iobj_0->Bodies[0] = &iobj_0->_pobj2[6];
  iobj_0->Bodies[0]->Index = 1.0;
  iobj_0->Bodies[1] = b_RigidBody_RigidBody(
      &iobj_0->_pobj2[7], &iobj_0->_pobj0[7], &iobj_0->_pobj1[7]);
  iobj_0->Bodies[1]->Index = 2.0;
  iobj_0->Bodies[2] = c_RigidBody_RigidBody(
      &iobj_0->_pobj2[8], &iobj_0->_pobj0[8], &iobj_0->_pobj1[8]);
  iobj_0->Bodies[2]->Index = 3.0;
  iobj_0->Bodies[3] = d_RigidBody_RigidBody(
      &iobj_0->_pobj2[9], &iobj_0->_pobj0[9], &iobj_0->_pobj1[9]);
  iobj_0->Bodies[3]->Index = 4.0;
  iobj_0->Bodies[4] = e_RigidBody_RigidBody(
      &iobj_0->_pobj2[10], &iobj_0->_pobj0[10], &iobj_0->_pobj1[10]);
  iobj_0->Bodies[4]->Index = 5.0;
  iobj_0->Bodies[5] = f_RigidBody_RigidBody(
      &iobj_0->_pobj2[11], &iobj_0->_pobj0[11], &iobj_0->_pobj1[11]);
  iobj_0->Bodies[5]->Index = 6.0;
  iobj_0->Gravity[0] = 0.0;
  iobj_0->Gravity[1] = 0.0;
  iobj_0->Gravity[2] = 0.0;
  iobj_0->NumNonFixedBodies = 6.0;
  iobj_0->PositionNumber = 6.0;
  iobj_0->VelocityNumber = 6.0;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->Base.NameInternal = s;
  s = iobj_0->Base.NameInternal;
  s.Length = 9.0;
  for (i = 0; i < 9; i++) {
    s.Vector[i] = b_cv5[i];
  }
  iobj_0->Base.NameInternal = s;
  iobj_0->Base.ParentIndex = -1.0;
  iobj_0->Base.MassInternal = 0.0;
  iobj_0->Base.CenterOfMassInternal[0] = 0.0;
  iobj_0->Base.CenterOfMassInternal[1] = 0.0;
  iobj_0->Base.CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    iobj_0->Base.InertiaInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_0->Base.SpatialInertia[i] = 0.0;
  }
  s = iobj_0->Base.NameInternal;
  if (s.Length < 1.0) {
    ibmat = 0;
  } else {
    ibmat = (int)s.Length;
  }
  s_size[0] = 1;
  s_size[1] = ibmat + 4;
  if (ibmat - 1 >= 0) {
    memcpy(&s_data[0], &s.Vector[0], (unsigned int)ibmat * sizeof(char));
  }
  s_data[ibmat] = '_';
  s_data[ibmat + 1] = 'j';
  s_data[ibmat + 2] = 'n';
  s_data[ibmat + 3] = 't';
  iobj_0->Base.JointInternal =
      rigidBodyJoint_rigidBodyJoint(&iobj_0->_pobj1[12], s_data, s_size);
  iobj_0->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&iobj_0->_pobj0[12], 0.0);
  iobj_0->Base.matlabCodegenIsDeleted = false;
  iobj_0->Base.Index = 0.0;
  iobj_0->matlabCodegenIsDeleted = false;
  (*iobj_1)->TreeInternal = iobj_0;
  (*iobj_1)->matlabCodegenIsDeleted = false;
}

/*
 * File trailer for importrobot.c
 *
 * [EOF]
 */
