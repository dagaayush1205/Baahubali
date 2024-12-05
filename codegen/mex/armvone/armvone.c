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
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "handle.h"
#include "importrobot.h"
#include "inverseKinematics.h"
#include "rt_nonfinite.h"
#include "structConstructorHelper.h"
#include "trvec2tform.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    10,                                        /* lineNo */
    "armvone",                                 /* fcnName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    19,                                        /* lineNo */
    "armvone",                                 /* fcnName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    25,                                        /* lineNo */
    "armvone",                                 /* fcnName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    3,                                         /* lineNo */
    "armvone",                                 /* fcnName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pathName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    1,                                         /* lineNo */
    17,                                        /* colNo */
    "armvone",                                 /* fName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    10,                                        /* lineNo */
    5,                                         /* colNo */
    "armvone",                                 /* fName */
    "/home/pritesh0/ayush/baahubali/armvone.m" /* pName */
};

/* Function Definitions */
void armvone(const emlrtStack *sp, const real_T q0[6], const real_T pos[3],
             emxArray_struct0_T *vone)
{
  static const char_T t4_f5[8] = {'y', 'a', 'w', 'j', 'o', 'i', 'n', 't'};
  static const char_T t4_f2[6] = {'j', 'o', 'i', 'n', 't', '1'};
  static const char_T t4_f3[6] = {'j', 'o', 'i', 'n', 't', '2'};
  b_rigidBodyTree arm;
  b_rigidBodyTree *r;
  d_robotics_manip_internal_Rigid lobj_2;
  emlrtStack b_st;
  emlrtStack st;
  inverseKinematics ik;
  struct_T rv[6];
  real_T C[6];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  c_emxInitStruct_robotics_manip_(sp, &lobj_2, &ac_emlrtRTEI);
  emxInitStruct_inverseKinematics(sp, &ik, &bc_emlrtRTEI);
  for (i = 0; i < 13; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2._pobj0[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 13; i++) {
    lobj_2._pobj0[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 7; i++) {
    emlrtPushHeapReferenceStackR2021a(
        (emlrtCTX)sp, true, &ik._pobj5._pobj1._pobj1[i],
        (void *)&h_handle_matlabCodegenDestructo, NULL, NULL, NULL);
  }
  for (i = 0; i < 7; i++) {
    ik._pobj5._pobj1._pobj1[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5._pobj0,
                                    (void *)&h_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5._pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 7; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4._pobj1[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 7; i++) {
    ik._pobj4._pobj1[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 13; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj3[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 13; i++) {
    ik._pobj3[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 12; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2._pobj2[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 12; i++) {
    lobj_2._pobj2[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  lobj_2.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    emlrtPushHeapReferenceStackR2021a(
        (emlrtCTX)sp, true, &ik._pobj5._pobj1._pobj0[i],
        (void *)&b_handle_matlabCodegenDestructo, NULL, NULL, NULL);
  }
  for (i = 0; i < 6; i++) {
    ik._pobj5._pobj1._pobj0[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5._pobj1.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4._pobj0[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 6; i++) {
    ik._pobj4._pobj0[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj4.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj2[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 6; i++) {
    ik._pobj2[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2,
                                    (void *)&handle_matlabCodegenDestructor,
                                    NULL, NULL, NULL);
  lobj_2.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &arm,
                                    (void *)&c_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  arm.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5._pobj1,
                                    (void *)&g_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5._pobj1.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4,
                                    (void *)&g_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj4.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj0,
                                    (void *)&i_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj0.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj6,
                                    (void *)&e_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj6.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik,
                                    (void *)&d_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik.matlabCodegenIsDeleted = true;
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5,
                                    (void *)&f_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5.matlabCodegenIsDeleted = true;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /*  Import the robot */
  r = &arm;
  st.site = &d_emlrtRSI;
  importrobot(&st, &lobj_2, &r);
  /*  Define the initial joint configuration (use names from your URDF) */
  for (i = 0; i < 6; i++) {
    C[i] = q0[i];
  }
  real_T dv[16];
  /*  Create the IK solver */
  st.site = &emlrtRSI;
  c_inverseKinematics_inverseKine(&st, &ik, &arm);
  /*  Define the end-effector name (use the name from your URDF) */
  /*  Define the weights for the IK solution */
  /*  Adjust as necessary for your DOF */
  /*  Solve the inverse kinematics */
  st.site = &b_emlrtRSI;
  structConstructorHelper(cv, t4_f2, t4_f3, cv1, t4_f5, cv2, C, rv);
  trvec2tform(pos, dv);
  b_st.site = &xb_emlrtRSI;
  SystemCore_step(&b_st, &ik, dv, rv, vone);
  /*  Extract the new joint positions */
  /* vone = struct(... */
  /*     'JointName', {'turntablejoint', 'joint1', 'joint2', 'pitchJoint',
   * 'yawjoint', 'roll joint'},'JointPosition', newConfig.JointPosition); */
  st.site = &c_emlrtRSI;
  f_handle_matlabCodegenDestructo(&st, &ik._pobj5);
  st.site = &c_emlrtRSI;
  d_handle_matlabCodegenDestructo(&st, &ik);
  st.site = &c_emlrtRSI;
  e_handle_matlabCodegenDestructo(&st, &ik._pobj6);
  st.site = &c_emlrtRSI;
  i_handle_matlabCodegenDestructo(&st, &ik._pobj0);
  st.site = &c_emlrtRSI;
  g_handle_matlabCodegenDestructo(&st, &ik._pobj4);
  st.site = &c_emlrtRSI;
  g_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1);
  st.site = &c_emlrtRSI;
  c_handle_matlabCodegenDestructo(&st, &arm);
  st.site = &c_emlrtRSI;
  handle_matlabCodegenDestructor(&st, &lobj_2);
  for (i = 0; i < 6; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj2[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &ik._pobj4.Base);
  for (i = 0; i < 6; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj4._pobj0[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1.Base);
  for (i = 0; i < 6; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1._pobj0[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &lobj_2.Base);
  for (i = 0; i < 12; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &lobj_2._pobj2[i]);
  }
  for (i = 0; i < 13; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj3[i]);
  }
  for (i = 0; i < 7; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj4._pobj1[i]);
  }
  st.site = &c_emlrtRSI;
  h_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj0);
  for (i = 0; i < 7; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1._pobj1[i]);
  }
  for (i = 0; i < 13; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &lobj_2._pobj0[i]);
  }
  emxFreeStruct_inverseKinematics(sp, &ik);
  d_emxFreeStruct_robotics_manip_(sp, &lobj_2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (armvone.c) */
