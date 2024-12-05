/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: armvone.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
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
/*
 * Import the robot
 *
 * Arguments    : const double q0[6]
 *                const double pos[3]
 *                emxArray_struct0_T *vone
 * Return Type  : void
 */
void armvone(const double q0[6], const double pos[3], emxArray_struct0_T *vone)
{
  static const char t2_f5[8] = {'y', 'a', 'w', 'j', 'o', 'i', 'n', 't'};
  static const char t2_f2[6] = {'j', 'o', 'i', 'n', 't', '1'};
  static const char t2_f3[6] = {'j', 'o', 'i', 'n', 't', '2'};
  b_rigidBodyTree arm;
  b_rigidBodyTree *r;
  c_robotics_manip_internal_Rigid *obj;
  d_robotics_manip_internal_Rigid lobj_2;
  inverseKinematics ik;
  struct_T rv[6];
  double C[6];
  int i;
  if (!isInitialized_armvone) {
    armvone_initialize();
  }
  c_emxInitStruct_robotics_manip_(&lobj_2);
  emxInitStruct_inverseKinematics(&ik);
  for (i = 0; i < 13; i++) {
    lobj_2._pobj0[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 7; i++) {
    ik._pobj5._pobj1._pobj1[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj5._pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 7; i++) {
    ik._pobj4._pobj1[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 13; i++) {
    ik._pobj3[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 12; i++) {
    lobj_2._pobj2[i].matlabCodegenIsDeleted = true;
  }
  lobj_2.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    ik._pobj5._pobj1._pobj0[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    ik._pobj4._pobj0[i].matlabCodegenIsDeleted = true;
  }
  ik._pobj4.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
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
  r = &arm;
  importrobot(&lobj_2, &r);
  /*  Define the initial joint configuration (use names from your URDF) */
  for (i = 0; i < 6; i++) {
    C[i] = q0[i];
  }
  double dv[16];
  /*  Create the IK solver */
  c_inverseKinematics_inverseKine(&ik, &arm);
  /*  Define the end-effector name (use the name from your URDF) */
  /*  Define the weights for the IK solution */
  /*  Adjust as necessary for your DOF */
  /*  Solve the inverse kinematics */
  structConstructorHelper(cv, t2_f2, t2_f3, cv1, t2_f5, cv2, C, rv);
  trvec2tform(pos, dv);
  SystemCore_step(&ik, dv, rv, vone);
  /*  Extract the new joint positions */
  /* vone = struct(... */
  /*     'JointName', {'turntablejoint', 'joint1', 'joint2', 'pitchJoint',
   * 'yawjoint', 'roll joint'},'JointPosition', newConfig.JointPosition); */
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
  for (i = 0; i < 6; i++) {
    obj = &ik._pobj2[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!ik._pobj4.Base.matlabCodegenIsDeleted) {
    ik._pobj4.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 6; i++) {
    obj = &ik._pobj4._pobj0[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!ik._pobj5._pobj1.Base.matlabCodegenIsDeleted) {
    ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 6; i++) {
    obj = &ik._pobj5._pobj1._pobj0[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  if (!lobj_2.Base.matlabCodegenIsDeleted) {
    lobj_2.Base.matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 12; i++) {
    obj = &lobj_2._pobj2[i];
    if (!obj->matlabCodegenIsDeleted) {
      obj->matlabCodegenIsDeleted = true;
    }
  }
  for (i = 0; i < 13; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj3[i]);
  }
  for (i = 0; i < 7; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj4._pobj1[i]);
  }
  b_handle_matlabCodegenDestructo(&ik._pobj5._pobj0);
  for (i = 0; i < 7; i++) {
    b_handle_matlabCodegenDestructo(&ik._pobj5._pobj1._pobj1[i]);
  }
  for (i = 0; i < 13; i++) {
    b_handle_matlabCodegenDestructo(&lobj_2._pobj0[i]);
  }
  emxFreeStruct_inverseKinematics(&ik);
  d_emxFreeStruct_robotics_manip_(&lobj_2);
}

/*
 * File trailer for armvone.c
 *
 * [EOF]
 */
