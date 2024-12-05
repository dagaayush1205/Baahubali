/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: inverseKinematics.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "inverseKinematics.h"
#include "CollisionSet.h"
#include "DampedBFGSwGradientProjection.h"
#include "IKHelpers.h"
#include "RigidBodyTree.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "coder_posix_time.h"
#include "collisioncodegen_api.hpp"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static void b_cast(const emxArray_struct_T *r2, emxArray_struct0_T *r3);

static void cast(const b_emxArray_struct_T *r2, emxArray_struct_T *r3);

/* Function Definitions */
/*
 * Arguments    : const emxArray_struct_T *r2
 *                emxArray_struct0_T *r3
 * Return Type  : void
 */
static void b_cast(const emxArray_struct_T *r2, emxArray_struct0_T *r3)
{
  const b_struct_T *r;
  struct0_T *r1;
  int i;
  int i1;
  int i2;
  r = r2->data;
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  i1 = r2->size[1];
  r3->size[1] = r2->size[1];
  emxEnsureCapacity_struct0_T(r3, i);
  r1 = r3->data;
  for (i = 0; i < i1; i++) {
    int loop_ub;
    r1[i].JointName.size[0] = 1;
    loop_ub = r[i].JointName.size[1];
    r1[i].JointName.size[1] = loop_ub;
    for (i2 = 0; i2 < loop_ub; i2++) {
      r1[i].JointName.data[i2] = r[i].JointName.data[i2];
    }
    r1[i].JointPosition.size[0] = 1;
    i2 = r[i].JointPosition.size[1];
    r1[i].JointPosition.size[1] = i2;
    r1[i].JointPosition.data[0] = r[i].JointPosition.data[0];
  }
}

/*
 * Arguments    : const b_emxArray_struct_T *r2
 *                emxArray_struct_T *r3
 * Return Type  : void
 */
static void cast(const b_emxArray_struct_T *r2, emxArray_struct_T *r3)
{
  b_struct_T *r1;
  const c_struct_T *r;
  int i;
  int i1;
  r = r2->data;
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  i1 = r2->size[1];
  r3->size[1] = r2->size[1];
  emxEnsureCapacity_struct_T1(r3, i);
  r1 = r3->data;
  for (i = 0; i < i1; i++) {
    r1[i].JointName.size[0] = 1;
    r1[i].JointName.size[1] = 0;
    r1[i].JointPosition.size[0] = 1;
    r1[i].JointPosition.size[1] = 1;
    r1[i].JointPosition.data[0] = r[i].JointPosition;
  }
}

/*
 * Arguments    : inverseKinematics *obj
 *                b_rigidBodyTree *varargin_2
 * Return Type  : inverseKinematics *
 */
inverseKinematics *c_inverseKinematics_inverseKine(inverseKinematics *obj,
                                                   b_rigidBodyTree *varargin_2)
{
  void *copyGeometryInternal;
  c_robotics_manip_internal_Colli expl_temp;
  c_robotics_manip_internal_Colli r;
  c_robotics_manip_internal_Rigid *body;
  c_robotics_manip_internal_Rigid *parent;
  d_robotics_manip_internal_Colli *e_obj;
  d_robotics_manip_internal_Colli *newObj;
  d_robotics_manip_internal_Rigid *c_obj;
  e_robotics_manip_internal_Rigid *newRobotInternal;
  inverseKinematics *b_obj;
  double t23_LocalPose[16];
  double t23_WorldPose[16];
  double bid;
  int obj_Vector_size[2];
  int i;
  int loop_ub;
  char obj_Vector[200];
  char obj_Vector_data[200];
  b_obj = obj;
  b_obj->isInitialized = 0;
  b_obj->_pobj6.MaxNumIteration = 1500.0;
  b_obj->_pobj6.MaxTime = 10.0;
  b_obj->_pobj6.GradientTolerance = 1.0E-7;
  b_obj->_pobj6.SolutionTolerance = 1.0E-6;
  b_obj->_pobj6.ArmijoRuleBeta = 0.4;
  b_obj->_pobj6.ArmijoRuleSigma = 1.0E-5;
  b_obj->_pobj6.ConstraintsOn = true;
  b_obj->_pobj6.RandomRestart = true;
  b_obj->_pobj6.StepTolerance = 1.0E-14;
  b_obj->_pobj6.ConstraintMatrix->size[0] = 0;
  b_obj->_pobj6.ConstraintMatrix->size[1] = 0;
  b_obj->_pobj6.ConstraintBound->size[0] = 0;
  b_obj->_pobj6.TimeObj.StartTime.tv_sec = 0.0;
  b_obj->_pobj6.TimeObj.StartTime.tv_nsec = 0.0;
  b_obj->_pobj6.TimeObjInternal.StartTime.tv_sec = 0.0;
  b_obj->_pobj6.TimeObjInternal.StartTime.tv_nsec = 0.0;
  b_obj->_pobj6.matlabCodegenIsDeleted = false;
  b_obj->Solver = &b_obj->_pobj6;
  c_obj = varargin_2->TreeInternal;
  newRobotInternal = RigidBodyTree_RigidBodyTree(&b_obj->_pobj4);
  bid = c_obj->Base.NameInternal.Length;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    obj_Vector[loop_ub] = c_obj->Base.NameInternal.Vector[loop_ub];
  }
  if (bid < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)bid;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (unsigned int)loop_ub * sizeof(char));
  }
  bid = c_RigidBodyTree_findBodyIndexBy(newRobotInternal, obj_Vector_data,
                                        obj_Vector_size);
  if ((!(bid == 0.0)) && (bid < 0.0)) {
    c_robotics_manip_internal_Chara d_obj;
    d_obj = newRobotInternal->Base.NameInternal;
    d_obj.Length = loop_ub;
    if (loop_ub < 1) {
      loop_ub = 0;
    }
    if (loop_ub - 1 >= 0) {
      memcpy(&d_obj.Vector[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    newRobotInternal->Base.NameInternal = d_obj;
  }
  e_obj = c_obj->Base.CollisionsInternal;
  newObj = CollisionSet_CollisionSet(&b_obj->_pobj3[0], e_obj->MaxElements);
  newObj->Size = e_obj->Size;
  bid = e_obj->Size;
  loop_ub = (int)bid;
  for (i = 0; i < loop_ub; i++) {
    r = e_obj->CollisionGeometries->data[i];
    memcpy(&t23_LocalPose[0], &r.LocalPose[0], 16U * sizeof(double));
    memcpy(&t23_WorldPose[0], &r.WorldPose[0], 16U * sizeof(double));
    copyGeometryInternal = collisioncodegen_copyGeometry(r.CollisionPrimitive);
    expl_temp.CollisionPrimitive = copyGeometryInternal;
    memcpy(&expl_temp.LocalPose[0], &t23_LocalPose[0], 16U * sizeof(double));
    memcpy(&expl_temp.WorldPose[0], &t23_WorldPose[0], 16U * sizeof(double));
    expl_temp.MeshScale[0] = r.MeshScale[0];
    expl_temp.MeshScale[1] = r.MeshScale[1];
    expl_temp.MeshScale[2] = r.MeshScale[2];
    newObj->CollisionGeometries->data[i] = expl_temp;
  }
  newRobotInternal->Base.CollisionsInternal = newObj;
  if (c_obj->NumBodies >= 1.0) {
    body = c_obj->Bodies[0];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[1], &b_obj->_pobj1[0],
                          &b_obj->_pobj2[0]);
  }
  if (c_obj->NumBodies >= 2.0) {
    body = c_obj->Bodies[1];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[3], &b_obj->_pobj1[2],
                          &b_obj->_pobj2[1]);
  }
  if (c_obj->NumBodies >= 3.0) {
    body = c_obj->Bodies[2];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[5], &b_obj->_pobj1[4],
                          &b_obj->_pobj2[2]);
  }
  if (c_obj->NumBodies >= 4.0) {
    body = c_obj->Bodies[3];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[7], &b_obj->_pobj1[6],
                          &b_obj->_pobj2[3]);
  }
  if (c_obj->NumBodies >= 5.0) {
    body = c_obj->Bodies[4];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[9], &b_obj->_pobj1[8],
                          &b_obj->_pobj2[4]);
  }
  if (c_obj->NumBodies >= 6.0) {
    body = c_obj->Bodies[5];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      parent = c_obj->Bodies[(int)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    bid = parent->NameInternal.Length;
    for (loop_ub = 0; loop_ub < 200; loop_ub++) {
      obj_Vector[loop_ub] = parent->NameInternal.Vector[loop_ub];
    }
    if (bid < 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = (int)bid;
    }
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (unsigned int)loop_ub * sizeof(char));
    }
    RigidBodyTree_addBody(newRobotInternal, body, obj_Vector_data,
                          obj_Vector_size, &b_obj->_pobj3[11],
                          &b_obj->_pobj1[10], &b_obj->_pobj2[5]);
  }
  b_obj->_pobj5.TreeInternal =
      RigidBodyTree_RigidBodyTree(&b_obj->_pobj5._pobj1);
  b_obj->_pobj5.TreeInternal->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&b_obj->_pobj5._pobj0, 10.0);
  b_obj->_pobj5.matlabCodegenIsDeleted = false;
  b_obj->_pobj5.TreeInternal = newRobotInternal;
  b_obj->RigidBodyTreeInternal = b_obj->_pobj5.TreeInternal;
  b_obj->RigidBodyTreeKinematicModel = 0.0;
  b_obj->RigidBodyTreeKinematicModel = 0.0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

/*
 * Arguments    : inverseKinematics *obj
 *                const struct_T initialGuess[6]
 *                emxArray_struct0_T *QSol
 *                char solutionInfo_Status_data[]
 *                int solutionInfo_Status_size[2]
 *                double *solutionInfo_NumRandomRestarts
 *                double *solutionInfo_PoseErrorNorm
 *                double *solutionInfo_ExitFlag
 * Return Type  : double
 */
double inverseKinematics_solve(
    inverseKinematics *obj, const struct_T initialGuess[6],
    emxArray_struct0_T *QSol, char solutionInfo_Status_data[],
    int solutionInfo_Status_size[2], double *solutionInfo_NumRandomRestarts,
    double *solutionInfo_PoseErrorNorm, double *solutionInfo_ExitFlag)
{
  static const c_struct_T r5 = {
      0.0 /* JointPosition */
  };
  static const char b_cv[14] = {'b', 'e', 's', 't', ' ', 'a', 'v',
                                'a', 'i', 'l', 'a', 'b', 'l', 'e'};
  static const char b_cv1[7] = {'s', 'u', 'c', 'c', 'e', 's', 's'};
  static const char b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  b_emxArray_struct_T *r3;
  b_struct_T *Q_data;
  c_robotics_core_internal_Damped *b_obj;
  c_robotics_manip_internal_Rigid *body;
  c_struct_T *r4;
  e_robotics_manip_internal_Rigid *c_obj;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_real_T *bodyIndices;
  emxArray_real_T *iniGuessVec;
  emxArray_real_T *positionIndices;
  emxArray_real_T *positionMap;
  emxArray_real_T *xSolPrev;
  emxArray_real_T *y;
  emxArray_struct_T *Q;
  rigidBodyJoint *d_obj;
  double newseed_data[42];
  double err;
  double iter;
  double solutionInfo_Iterations;
  double tol;
  double *bodyIndices_data;
  double *iniGuessVec_data;
  double *positionMap_data;
  double *xSolPrev_data;
  double *y_data;
  int b_i;
  int end;
  unsigned int i;
  int k;
  int loop_ub;
  int nm1d2;
  int *r1;
  boolean_T exitg1;
  c_robotics_core_internal_NLPSol exitFlag;
  c_robotics_core_internal_NLPSol exitFlagPrev;
  emxInit_real_T(&iniGuessVec, 1);
  c_RigidBodyTree_validateConfigu(obj->RigidBodyTreeInternal, initialGuess,
                                  iniGuessVec);
  iniGuessVec_data = iniGuessVec->data;
  b_obj = obj->Solver;
  b_obj->MaxNumIterationInternal = b_obj->MaxNumIteration;
  b_obj->MaxTimeInternal = b_obj->MaxTime;
  loop_ub = iniGuessVec->size[0];
  k = b_obj->SeedInternal->size[0];
  b_obj->SeedInternal->size[0] = iniGuessVec->size[0];
  emxEnsureCapacity_real_T(b_obj->SeedInternal, k);
  for (k = 0; k < loop_ub; k++) {
    b_obj->SeedInternal->data[k] = iniGuessVec_data[k];
  }
  tol = b_obj->SolutionTolerance;
  b_obj->TimeObj.StartTime.tv_sec = tic(&b_obj->TimeObj.StartTime.tv_nsec);
  emxInit_real_T(&xSolPrev, 1);
  exitFlag = c_DampedBFGSwGradientProjection(b_obj, xSolPrev, &err, &iter);
  xSolPrev_data = xSolPrev->data;
  *solutionInfo_NumRandomRestarts = 0.0;
  solutionInfo_Iterations = iter;
  *solutionInfo_PoseErrorNorm = err;
  exitFlagPrev = exitFlag;
  emxInit_real_T(&bodyIndices, 1);
  exitg1 = false;
  while ((!exitg1) && (b_obj->RandomRestart && (err > tol))) {
    b_obj->MaxNumIterationInternal -= iter;
    err =
        toc(b_obj->TimeObj.StartTime.tv_sec, b_obj->TimeObj.StartTime.tv_nsec);
    b_obj->MaxTimeInternal = b_obj->MaxTime - err;
    if (b_obj->MaxNumIterationInternal <= 0.0) {
      exitFlag = IterationLimitExceeded;
    }
    if ((exitFlag == IterationLimitExceeded) ||
        (exitFlag == TimeLimitExceeded)) {
      exitFlagPrev = exitFlag;
      exitg1 = true;
    } else {
      nm1d2 = IKHelpers_randomConfig(b_obj->ExtraArgs, newseed_data);
      k = b_obj->SeedInternal->size[0];
      b_obj->SeedInternal->size[0] = nm1d2;
      emxEnsureCapacity_real_T(b_obj->SeedInternal, k);
      for (k = 0; k < nm1d2; k++) {
        b_obj->SeedInternal->data[k] = newseed_data[k];
      }
      exitFlag =
          c_DampedBFGSwGradientProjection(b_obj, bodyIndices, &err, &iter);
      bodyIndices_data = bodyIndices->data;
      if (err < *solutionInfo_PoseErrorNorm) {
        loop_ub = bodyIndices->size[0];
        k = xSolPrev->size[0];
        xSolPrev->size[0] = bodyIndices->size[0];
        emxEnsureCapacity_real_T(xSolPrev, k);
        xSolPrev_data = xSolPrev->data;
        for (k = 0; k < loop_ub; k++) {
          xSolPrev_data[k] = bodyIndices_data[k];
        }
        *solutionInfo_PoseErrorNorm = err;
        exitFlagPrev = exitFlag;
      }
      (*solutionInfo_NumRandomRestarts)++;
      solutionInfo_Iterations += iter;
    }
  }
  if (*solutionInfo_PoseErrorNorm < tol) {
    solutionInfo_Status_size[0] = 1;
    solutionInfo_Status_size[1] = 7;
    for (k = 0; k < 7; k++) {
      solutionInfo_Status_data[k] = b_cv1[k];
    }
  } else {
    solutionInfo_Status_size[0] = 1;
    solutionInfo_Status_size[1] = 14;
    for (k = 0; k < 14; k++) {
      solutionInfo_Status_data[k] = b_cv[k];
    }
  }
  c_obj = obj->RigidBodyTreeInternal;
  err = obj->Solver->ExtraArgs->BodyIndex;
  k = bodyIndices->size[0];
  bodyIndices->size[0] = (int)c_obj->NumBodies;
  emxEnsureCapacity_real_T(bodyIndices, k);
  bodyIndices_data = bodyIndices->data;
  loop_ub = (int)c_obj->NumBodies;
  for (k = 0; k < loop_ub; k++) {
    bodyIndices_data[k] = 0.0;
  }
  if (err == 0.0) {
    k = bodyIndices->size[0];
    bodyIndices->size[0] = 1;
    emxEnsureCapacity_real_T(bodyIndices, k);
    bodyIndices_data = bodyIndices->data;
    bodyIndices_data[0] = 0.0;
  } else {
    body = c_obj->Bodies[(int)err - 1];
    i = 1U;
    while (body->ParentIndex != 0.0) {
      bodyIndices_data[(int)i - 1] = body->Index;
      body = c_obj->Bodies[(int)body->ParentIndex - 1];
      i++;
    }
    if ((int)(i - 1U) < 1) {
      k = 0;
    } else {
      k = (int)i - 1;
    }
    end = bodyIndices->size[0];
    bodyIndices->size[0] = k + 2;
    emxEnsureCapacity_real_T(bodyIndices, end);
    bodyIndices_data = bodyIndices->data;
    bodyIndices_data[k] = body->Index;
    bodyIndices_data[k + 1] = 0.0;
  }
  c_obj = obj->RigidBodyTreeInternal;
  end = bodyIndices->size[0];
  nm1d2 = 0;
  for (b_i = 0; b_i < end; b_i++) {
    if (bodyIndices_data[b_i] != 0.0) {
      nm1d2++;
    }
  }
  emxInit_int32_T(&r, 1);
  k = r->size[0];
  r->size[0] = nm1d2;
  emxEnsureCapacity_int32_T(r, k);
  r1 = r->data;
  nm1d2 = 0;
  for (b_i = 0; b_i < end; b_i++) {
    if (bodyIndices_data[b_i] != 0.0) {
      r1[nm1d2] = b_i;
      nm1d2++;
    }
  }
  emxInit_real_T(&positionMap, 2);
  loop_ub = r->size[0];
  k = positionMap->size[0] * positionMap->size[1];
  positionMap->size[0] = r->size[0];
  positionMap->size[1] = 2;
  emxEnsureCapacity_real_T(positionMap, k);
  positionMap_data = positionMap->data;
  for (k = 0; k < 2; k++) {
    for (end = 0; end < loop_ub; end++) {
      positionMap_data[end + positionMap->size[0] * k] =
          c_obj->PositionDoFMap[((int)bodyIndices_data[r1[end]] + 6 * k) - 1];
    }
  }
  emxFree_int32_T(&r);
  emxFree_real_T(&bodyIndices);
  emxInit_real_T(&positionIndices, 2);
  k = positionIndices->size[0] * positionIndices->size[1];
  positionIndices->size[0] = 1;
  positionIndices->size[1] = (int)c_obj->PositionNumber;
  emxEnsureCapacity_real_T(positionIndices, k);
  bodyIndices_data = positionIndices->data;
  nm1d2 = (int)c_obj->PositionNumber;
  for (k = 0; k < nm1d2; k++) {
    bodyIndices_data[k] = 0.0;
  }
  err = 0.0;
  emxInit_int32_T(&r2, 2);
  emxInit_real_T(&y, 2);
  y_data = y->data;
  for (b_i = 0; b_i < loop_ub; b_i++) {
    iter = positionMap_data[b_i + positionMap->size[0]] - positionMap_data[b_i];
    if (iter + 1.0 > 0.0) {
      double b;
      if (iter + 1.0 < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int)((iter + 1.0) - 1.0) + 1;
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        nm1d2 = (int)((iter + 1.0) - 1.0);
        for (k = 0; k <= nm1d2; k++) {
          y_data[k] = (double)k + 1.0;
        }
      }
      k = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      nm1d2 = y->size[1];
      r2->size[1] = y->size[1];
      emxEnsureCapacity_int32_T(r2, k);
      r1 = r2->data;
      for (k = 0; k < nm1d2; k++) {
        r1[k] = (int)(err + y_data[k]);
      }
      tol = positionMap_data[b_i];
      b = positionMap_data[b_i + positionMap->size[0]];
      if (rtIsNaN(tol) || rtIsNaN(b)) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        y_data[0] = rtNaN;
      } else if (b < tol) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((rtIsInf(tol) || rtIsInf(b)) && (tol == b)) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        y_data[0] = rtNaN;
      } else if (floor(tol) == tol) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        nm1d2 = (int)iter;
        y->size[1] = (int)iter + 1;
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        for (k = 0; k <= nm1d2; k++) {
          y_data[k] = tol + (double)k;
        }
      } else {
        double apnd;
        double cdiff;
        double ndbl;
        ndbl = floor(iter + 0.5);
        apnd = tol + ndbl;
        cdiff = apnd - b;
        if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(tol), fabs(b))) {
          ndbl++;
          apnd = b;
        } else if (cdiff > 0.0) {
          apnd = tol + (ndbl - 1.0);
        } else {
          ndbl++;
        }
        if (ndbl >= 0.0) {
          end = (int)ndbl;
        } else {
          end = 0;
        }
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = end;
        emxEnsureCapacity_real_T(y, k);
        y_data = y->data;
        if (end > 0) {
          y_data[0] = tol;
          if (end > 1) {
            y_data[end - 1] = apnd;
            nm1d2 = (end - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              y_data[k + 1] = tol + ((double)k + 1.0);
              y_data[(end - k) - 2] = apnd - ((double)k + 1.0);
            }
            if (nm1d2 << 1 == end - 1) {
              y_data[nm1d2] = (positionMap_data[b_i] + apnd) / 2.0;
            } else {
              y_data[nm1d2] = positionMap_data[b_i] + (double)nm1d2;
              y_data[nm1d2 + 1] = apnd - (double)nm1d2;
            }
          }
        }
      }
      nm1d2 = y->size[1] - 1;
      for (k = 0; k <= nm1d2; k++) {
        bodyIndices_data[r1[k] - 1] = y_data[k];
      }
      err += iter + 1.0;
    }
  }
  emxFree_real_T(&y);
  emxFree_int32_T(&r2);
  emxFree_real_T(&positionMap);
  if (err < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)err;
  }
  k = positionIndices->size[0] * positionIndices->size[1];
  positionIndices->size[1] = loop_ub;
  emxEnsureCapacity_real_T(positionIndices, k);
  bodyIndices_data = positionIndices->data;
  for (k = 0; k < loop_ub; k++) {
    err = bodyIndices_data[k];
    iniGuessVec_data[(int)err - 1] = xSolPrev_data[(int)err - 1];
  }
  emxFree_real_T(&xSolPrev);
  emxFree_real_T(&positionIndices);
  c_obj = obj->RigidBodyTreeInternal;
  err = c_obj->NumNonFixedBodies;
  emxInit_struct_T1(&r3);
  k = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  nm1d2 = (int)err;
  r3->size[1] = (int)err;
  emxEnsureCapacity_struct_T(r3, k);
  r4 = r3->data;
  for (k = 0; k < nm1d2; k++) {
    r4[k] = r5;
  }
  emxInit_struct_T(&Q);
  cast(r3, Q);
  Q_data = Q->data;
  emxFree_struct_T1(&r3);
  i = 1U;
  err = c_obj->NumBodies;
  k = (int)err;
  for (b_i = 0; b_i < k; b_i++) {
    char obj_Vector[200];
    boolean_T b_bool;
    body = c_obj->Bodies[b_i];
    d_obj = body->JointInternal;
    err = d_obj->TypeInternal.Length;
    for (end = 0; end < 200; end++) {
      obj_Vector[end] = d_obj->TypeInternal.Vector[end];
    }
    if (err < 1.0) {
      end = 0;
    } else {
      end = (int)err;
    }
    b_bool = false;
    if (end == 5) {
      nm1d2 = 0;
      int exitg2;
      do {
        exitg2 = 0;
        if (nm1d2 < 5) {
          if (obj_Vector[nm1d2] != b_cv2[nm1d2]) {
            exitg2 = 1;
          } else {
            nm1d2++;
          }
        } else {
          b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    if (!b_bool) {
      nm1d2 = (int)body->Index;
      iter = c_obj->PositionDoFMap[nm1d2 - 1];
      tol = c_obj->PositionDoFMap[nm1d2 + 5];
      d_obj = body->JointInternal;
      err = d_obj->NameInternal.Length;
      for (end = 0; end < 200; end++) {
        obj_Vector[end] = d_obj->NameInternal.Vector[end];
      }
      if (err < 1.0) {
        loop_ub = 0;
      } else {
        loop_ub = (int)err;
      }
      Q_data[(int)i - 1].JointName.size[0] = 1;
      Q_data[(int)i - 1].JointName.size[1] = loop_ub;
      for (end = 0; end < loop_ub; end++) {
        Q_data[(int)i - 1].JointName.data[end] = obj_Vector[end];
      }
      if (iter > tol) {
        end = 0;
        nm1d2 = 0;
      } else {
        end = (int)iter - 1;
        nm1d2 = (int)tol;
      }
      Q_data[(int)i - 1].JointPosition.size[0] = 1;
      Q_data[(int)i - 1].JointPosition.size[1] = 1;
      loop_ub = nm1d2 - end;
      for (nm1d2 = 0; nm1d2 < loop_ub; nm1d2++) {
        Q_data[(int)i - 1].JointPosition.data[nm1d2] =
            iniGuessVec_data[end + nm1d2];
      }
      i++;
    }
  }
  emxFree_real_T(&iniGuessVec);
  b_cast(Q, QSol);
  emxFree_struct_T(&Q);
  *solutionInfo_ExitFlag = (int)exitFlagPrev;
  return solutionInfo_Iterations;
}

/*
 * File trailer for inverseKinematics.c
 *
 * [EOF]
 */
