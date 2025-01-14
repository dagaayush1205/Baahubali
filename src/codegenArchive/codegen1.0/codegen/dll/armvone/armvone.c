/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone.c
 *
 * Code generation for function 'armvone'
 *
 */

/* Include files */
#include "armvone.h"
#include "SystemCore.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_initialize.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "handle.h"
#include "importrobot.h"
#include "inverseKinematics.h"
#include "rt_nonfinite.h"
#include "structConstructorHelper.h"
#include "trvec2tform.h"

/* Function Definitions */
void armvone(const double q0[5], const double pos[3], double vone_data[],
             int vone_size[2])
{
  b_rigidBodyTree arm;
  b_rigidBodyTree *r;
  b_struct_T rv[5];
  c_robotics_manip_internal_Rigid *obj;
  d_robotics_manip_internal_Rigid lobj_2;
  emxArray_struct_T *new;
  inverseKinematics ik;
  struct_T *new_data;
  double C[5];
  int i;
  if (!isInitialized_armvone) {
    armvone_initialize();
  }
  c_emxInitStruct_robotics_manip_(&lobj_2);
  emxInitStruct_inverseKinematics(&ik);
  for (i = 0; i < 17; i++) {
    lobj_2._pobj0[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 6; i++) {
    ik._pobj5._pobj1._pobj1[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj5._pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    ik._pobj4._pobj1[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 11; i++) {
    ik._pobj3[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 10; i++) {
    lobj_2._pobj2[i].matlabCodegenIsDeleted = true;
  }
  lobj_2.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    ik._pobj5._pobj1._pobj0[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    ik._pobj4._pobj0[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj4.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    ik._pobj2[i].matlabCodegenIsDeleted = true;
  }
  lobj_2.matlabCodegenIsDeleted = true;
  arm.matlabCodegenIsDeleted = true;
  ik._pobj5._pobj1.matlabCodegenIsDeleted = true;
  ik._pobj4.matlabCodegenIsDeleted = true;
  ik._pobj0.matlabCodegenIsDeleted = true;
  ik._pobj6.matlabCodegenIsDeleted = true;
  ik.matlabCodegenIsDeleted = true;
  ik._pobj5.matlabCodegenIsDeleted = true;
  /*  Import the robot */
  r = &arm;
  importrobot(&lobj_2, &r);
  /*  Define the initial joint configuration as an array */
  for (i = 0; i < 5; i++) {
    C[i] = q0[i];
  }
  double dv[16];
  /* qInitial = q0; % q0 is already an array of joint positions */
  /*  Create the IK solver */
  c_inverseKinematics_inverseKine(&ik, &arm);
  /*  Define the end-effector name (use the name from your URDF) */
  /*  Define the weights for the IK solution */
  /*  Adjust as necessary for your DOF */
  /*  Solve the inverse kinematics */
  /* [newConfig, ~] = ik(endEffector, trvec2tform(pos), weights, qInitial); */
  structConstructorHelper(cv, cv1, cv2, cv3, cv4, C, rv);
  emxInit_struct_T(&new);
  trvec2tform(pos, dv);
  SystemCore_step(&ik, dv, rv, new);
  new_data = new->data;
  /*  Extract the new joint positions and return as an array */
  /* vone = [newConfig.JointPosition]; */
  vone_size[0] = 1;
  vone_size[1] = 5;
  vone_data[0] = new_data[0].JointPosition.data[0];
  vone_data[1] = new_data[1].JointPosition.data[0];
  vone_data[2] = new_data[2].JointPosition.data[0];
  vone_data[3] = new_data[3].JointPosition.data[0];
  vone_data[4] = new_data[4].JointPosition.data[0];
  emxFree_struct_T(&new);
  if (!ik._pobj5.matlabCodegenIsDeleted) {
    ik._pobj5.matlabCodegenIsDeleted = true;
  }
  handle_matlabCodegenDestructor(&ik);
  if (!ik._pobj6.matlabCodegenIsDeleted) {
    ik._pobj6.matlabCodegenIsDeleted = true;
  }
  if (!ik._pobj0.matlabCodegenIsDeleted) {
    ik._pobj0.matlabCodegenIsDeleted = true;
  }
  if (!ik._pobj4.matlabCodegenIsDeleted) {
    ik._pobj4.matlabCodegenIsDeleted = true;
  }
  if (!ik._pobj5._pobj1.matlabCodegenIsDeleted) {
    ik._pobj5._pobj1.matlabCodegenIsDeleted = true;
  }
  if (!arm.matlabCodegenIsDeleted) {
    arm.matlabCodegenIsDeleted = true;
  }
  if (!lobj_2.matlabCodegenIsDeleted) {
    lobj_2.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 5; i++) {
    obj = &ik._pobj2[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!ik._pobj4.Base.matlabCodegenIsDeleted) {
    ik._pobj4.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 5; i++) {
    obj = &ik._pobj4._pobj0[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!ik._pobj5._pobj1.Base.matlabCodegenIsDeleted) {
    ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 5; i++) {
    obj = &ik._pobj5._pobj1._pobj0[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!lobj_2.Base.matlabCodegenIsDeleted) {
    lobj_2.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 10; i++) {
    obj = &lobj_2._pobj2[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  for (i = 0; i < 11; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj3[i]);
  }
  for (i = 0; i < 6; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj4._pobj1[i]);
  }
  b_handle_matlabCodegenDestructo(&ik._pobj5._pobj0);
  for (i = 0; i < 6; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj5._pobj1._pobj1[i]);
  }
  for (i = 0; i < 17; i++) {
    b_handle_matlabCodegenDestructo(&lobj_2._pobj0[i]);
  }
  emxFreeStruct_inverseKinematics(&ik);
  d_emxFreeStruct_robotics_manip_(&lobj_2);
}

/* End of code generation (armvone.c) */
