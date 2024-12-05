/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: SystemCore.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "SystemCore.h"
#include "RigidBodyTree.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "inverseKinematics.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : inverseKinematics *obj
 *                const double varargin_2[16]
 *                const struct_T varargin_4[6]
 *                emxArray_struct0_T *varargout_1
 * Return Type  : void
 */
void SystemCore_step(inverseKinematics *obj, const double varargin_2[16],
                     const struct_T varargin_4[6],
                     emxArray_struct0_T *varargout_1)
{
  static const signed char b_iv[6] = {0, 0, 0, 1, 1, 1};
  static const char b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char b_cv[4] = {'r', 'o', 'l', 'l'};
  c_robotics_manip_internal_IKExt *args;
  c_robotics_manip_internal_Rigid *c_obj;
  e_robotics_manip_internal_Rigid *b_obj;
  emxArray_int8_T *A;
  emxArray_int8_T *b_I;
  emxArray_int8_T *c_I;
  emxArray_real_T *b;
  rigidBodyJoint *joint;
  double tmp_data[14];
  double d;
  double expl_temp;
  double n;
  double t_tmp;
  double *b_data;
  int tmp_size[2];
  int b_i;
  int bidx;
  int exitg1;
  int i;
  int i1;
  int i2;
  int i4;
  int kstr;
  char obj_Vector[200];
  signed char weightMatrix[36];
  char expl_temp_data[14];
  signed char *A_data;
  signed char *I_data;
  signed char *b_I_data;
  boolean_T b_bool;
  if (obj->isInitialized != 1) {
    double k;
    double m;
    int loop_ub;
    int loop_ub_tmp;
    signed char d_I[16];
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    n = obj->RigidBodyTreeInternal->PositionNumber;
    emxInit_int8_T(&A);
    i = A->size[0] * A->size[1];
    A->size[0] = (int)n;
    loop_ub = (int)(2.0 * n);
    A->size[1] = loop_ub;
    emxEnsureCapacity_int8_T(A, i);
    A_data = A->data;
    loop_ub_tmp = (int)n * loop_ub;
    for (i = 0; i < loop_ub_tmp; i++) {
      A_data[i] = 0;
    }
    emxInit_real_T(&b, 1);
    i = b->size[0];
    b->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b, i);
    b_data = b->data;
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = 0.0;
    }
    k = 1.0;
    m = 1.0;
    d = obj->RigidBodyTreeInternal->NumBodies;
    i = (int)d;
    emxInit_int8_T(&b_I);
    emxInit_int8_T(&c_I);
    for (b_i = 0; b_i < i; b_i++) {
      double pnum;
      c_obj = obj->RigidBodyTreeInternal->Bodies[b_i];
      joint = c_obj->JointInternal;
      pnum = joint->PositionNumber;
      expl_temp = joint->TypeInternal.Length;
      for (i1 = 0; i1 < 200; i1++) {
        obj_Vector[i1] = joint->TypeInternal.Vector[i1];
      }
      if (expl_temp < 1.0) {
        i1 = 0;
      } else {
        i1 = (int)expl_temp;
      }
      b_bool = false;
      if (i1 == 5) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 5) {
            if (obj_Vector[kstr] != b_cv1[kstr]) {
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
        int b_loop_ub_tmp;
        int i3;
        int m_tmp_tmp;
        d = (k + pnum) - 1.0;
        if (k > d) {
          i1 = 0;
          i2 = 0;
        } else {
          i1 = (int)k - 1;
          i2 = (int)d;
        }
        expl_temp = m + pnum;
        if (m > expl_temp - 1.0) {
          i3 = 0;
          i4 = 0;
        } else {
          i3 = (int)m - 1;
          i4 = (int)(expl_temp - 1.0);
        }
        if (pnum < 0.0) {
          t_tmp = 0.0;
          m_tmp_tmp = 0;
        } else {
          t_tmp = pnum;
          m_tmp_tmp = (int)pnum;
        }
        bidx = b_I->size[0] * b_I->size[1];
        b_I->size[0] = (int)t_tmp;
        b_I->size[1] = (int)t_tmp;
        emxEnsureCapacity_int8_T(b_I, bidx);
        I_data = b_I->data;
        b_loop_ub_tmp = (int)t_tmp * (int)t_tmp;
        for (bidx = 0; bidx < b_loop_ub_tmp; bidx++) {
          I_data[bidx] = 0;
        }
        if ((int)t_tmp > 0) {
          for (bidx = 0; bidx < m_tmp_tmp; bidx++) {
            I_data[bidx + b_I->size[0] * bidx] = 1;
          }
        }
        bidx = i2 - i1;
        kstr = i4 - i3;
        for (i2 = 0; i2 < kstr; i2++) {
          for (i4 = 0; i4 < bidx; i4++) {
            A_data[(i1 + i4) + A->size[0] * (i3 + i2)] = I_data[i4 + bidx * i2];
          }
        }
        if (k > d) {
          i1 = 0;
          i2 = 0;
        } else {
          i1 = (int)k - 1;
          i2 = (int)d;
        }
        d = m + 2.0 * pnum;
        if (expl_temp > d - 1.0) {
          i3 = 0;
          i4 = 0;
        } else {
          i3 = (int)expl_temp - 1;
          i4 = (int)(d - 1.0);
        }
        bidx = b_I->size[0] * b_I->size[1];
        b_I->size[0] = (int)t_tmp;
        b_I->size[1] = (int)t_tmp;
        emxEnsureCapacity_int8_T(b_I, bidx);
        I_data = b_I->data;
        for (bidx = 0; bidx < b_loop_ub_tmp; bidx++) {
          I_data[bidx] = 0;
        }
        if ((int)t_tmp > 0) {
          for (bidx = 0; bidx < m_tmp_tmp; bidx++) {
            I_data[bidx + b_I->size[0] * bidx] = 1;
          }
        }
        bidx = c_I->size[0] * c_I->size[1];
        c_I->size[0] = (int)t_tmp;
        c_I->size[1] = (int)t_tmp;
        emxEnsureCapacity_int8_T(c_I, bidx);
        b_I_data = c_I->data;
        for (bidx = 0; bidx < b_loop_ub_tmp; bidx++) {
          b_I_data[bidx] = (signed char)-I_data[bidx];
        }
        bidx = i2 - i1;
        kstr = i4 - i3;
        for (i2 = 0; i2 < kstr; i2++) {
          for (i4 = 0; i4 < bidx; i4++) {
            A_data[(i1 + i4) + A->size[0] * (i3 + i2)] =
                b_I_data[i4 + bidx * i2];
          }
        }
        c_rigidBodyJoint_get_PositionLi(joint, tmp_data, tmp_size);
        b_data[(int)m - 1] = tmp_data[1];
        c_rigidBodyJoint_get_PositionLi(joint, tmp_data, tmp_size);
        b_data[(int)(unsigned int)m] = -tmp_data[0];
        m = d;
      }
      k += pnum;
    }
    emxFree_int8_T(&c_I);
    emxFree_int8_T(&b_I);
    i = obj->Solver->ConstraintMatrix->size[0] *
        obj->Solver->ConstraintMatrix->size[1];
    obj->Solver->ConstraintMatrix->size[0] = (int)n;
    obj->Solver->ConstraintMatrix->size[1] = loop_ub;
    emxEnsureCapacity_real_T(obj->Solver->ConstraintMatrix, i);
    for (i = 0; i < loop_ub_tmp; i++) {
      obj->Solver->ConstraintMatrix->data[i] = A_data[i];
    }
    emxFree_int8_T(&A);
    i = obj->Solver->ConstraintBound->size[0];
    obj->Solver->ConstraintBound->size[0] = loop_ub;
    emxEnsureCapacity_real_T(obj->Solver->ConstraintBound, i);
    for (i = 0; i < loop_ub; i++) {
      obj->Solver->ConstraintBound->data[i] = b_data[i];
    }
    c_RigidBodyTree_get_JointPositi(obj->RigidBodyTreeInternal, obj->Limits);
    obj->_pobj0.matlabCodegenIsDeleted = false;
    obj->Solver->ExtraArgs = &obj->_pobj0;
    for (i = 0; i < 36; i++) {
      obj->Solver->ExtraArgs->WeightMatrix[i] = 0.0;
    }
    obj->Solver->ExtraArgs->Robot = obj->RigidBodyTreeInternal;
    obj->Solver->ExtraArgs->KinematicModel = obj->RigidBodyTreeKinematicModel;
    for (i = 0; i < 16; i++) {
      d_I[i] = 0;
    }
    d_I[0] = 1;
    d_I[5] = 1;
    d_I[10] = 1;
    d_I[15] = 1;
    for (i = 0; i < 16; i++) {
      obj->Solver->ExtraArgs->Tform[i] = d_I[i];
    }
    obj->Solver->ExtraArgs->BodyIndex = -1.0;
    i = obj->Solver->ExtraArgs->ErrTemp->size[0];
    obj->Solver->ExtraArgs->ErrTemp->size[0] = 6;
    emxEnsureCapacity_real_T(obj->Solver->ExtraArgs->ErrTemp, i);
    for (i = 0; i < 6; i++) {
      obj->Solver->ExtraArgs->ErrTemp->data[i] = 0.0;
    }
    obj->Solver->ExtraArgs->CostTemp = 0.0;
    emxFree_real_T(&b);
    loop_ub = (int)obj->RigidBodyTreeInternal->PositionNumber;
    i = obj->Solver->ExtraArgs->GradTemp->size[0];
    obj->Solver->ExtraArgs->GradTemp->size[0] = loop_ub;
    emxEnsureCapacity_real_T(obj->Solver->ExtraArgs->GradTemp, i);
    for (i = 0; i < loop_ub; i++) {
      obj->Solver->ExtraArgs->GradTemp->data[i] = 0.0;
    }
    obj->isSetupComplete = true;
  }
  b_obj = obj->RigidBodyTreeInternal;
  bidx = -1;
  expl_temp = b_obj->Base.NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = b_obj->Base.NameInternal.Vector[i];
  }
  if (expl_temp < 1.0) {
    i = 0;
  } else {
    i = (int)expl_temp;
  }
  b_bool = false;
  if (i == 4) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 4) {
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
  if (b_bool) {
    bidx = 0;
  } else {
    boolean_T exitg2;
    d = b_obj->NumBodies;
    b_i = 0;
    exitg2 = false;
    while ((!exitg2) && (b_i <= (int)d - 1)) {
      c_obj = b_obj->Bodies[b_i];
      expl_temp = c_obj->NameInternal.Length;
      for (i = 0; i < 200; i++) {
        obj_Vector[i] = c_obj->NameInternal.Vector[i];
      }
      if (expl_temp < 1.0) {
        i = 0;
      } else {
        i = (int)expl_temp;
      }
      b_bool = false;
      if (i == 4) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 4) {
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
      if (b_bool) {
        bidx = b_i + 1;
        exitg2 = true;
      } else {
        b_i++;
      }
    }
  }
  for (i = 0; i < 36; i++) {
    weightMatrix[i] = 0;
  }
  for (kstr = 0; kstr < 6; kstr++) {
    weightMatrix[kstr + 6 * kstr] = b_iv[kstr];
  }
  args = obj->Solver->ExtraArgs;
  for (i = 0; i < 36; i++) {
    args->WeightMatrix[i] = weightMatrix[i];
  }
  args->BodyIndex = bidx;
  args->KinematicModel = obj->RigidBodyTreeKinematicModel;
  for (i = 0; i < 16; i++) {
    args->Tform[i] = varargin_2[i];
  }
  inverseKinematics_solve(obj, varargin_4, varargout_1, expl_temp_data,
                          tmp_size, &expl_temp, &t_tmp, &n);
}

/*
 * File trailer for SystemCore.c
 *
 * [EOF]
 */
