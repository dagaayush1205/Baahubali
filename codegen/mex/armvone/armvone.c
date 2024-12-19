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
    11,                                              /* lineNo */
    "armvone",                                       /* fcnName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    21,                                              /* lineNo */
    "armvone",                                       /* fcnName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    26,                                              /* lineNo */
    "armvone",                                       /* fcnName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    3,                                               /* lineNo */
    "armvone",                                       /* fcnName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    25,                                               /* lineNo */
    17,                                               /* colNo */
    "new",                                            /* aName */
    "armvone",                                        /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    25,                                               /* lineNo */
    38,                                               /* colNo */
    "new",                                            /* aName */
    "armvone",                                        /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    25,                                               /* lineNo */
    59,                                               /* colNo */
    "new",                                            /* aName */
    "armvone",                                        /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    25,                                               /* lineNo */
    80,                                               /* colNo */
    "new",                                            /* aName */
    "armvone",                                        /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                               /* iFirst */
    -1,                                               /* iLast */
    25,                                               /* lineNo */
    101,                                              /* colNo */
    "new",                                            /* aName */
    "armvone",                                        /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m", /* pName */
    0                                                 /* checkKind */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    1,                                               /* lineNo */
    17,                                              /* colNo */
    "armvone",                                       /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    11,                                              /* lineNo */
    5,                                               /* colNo */
    "armvone",                                       /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    21,                                              /* lineNo */
    5,                                               /* colNo */
    "armvone",                                       /* fName */
    "/home/ayush/Vibranium/baahubali/urdf/armvone.m" /* pName */
};

/* Function Definitions */
void armvone(armvoneStackData *SD, const emlrtStack *sp, const real_T q0[5],
             const real_T pos[3], real_T vone_data[], int32_T vone_size[2])
{
  b_rigidBodyTree arm;
  b_rigidBodyTree *r;
  b_struct_T rv[5];
  d_robotics_manip_internal_Rigid lobj_2;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_struct_T *new;
  inverseKinematics ik;
  struct_T *new_data;
  real_T C[5];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  c_emxInitStruct_robotics_manip_(sp, &lobj_2, &ac_emlrtRTEI);
  emxInitStruct_inverseKinematics(sp, &ik, &bc_emlrtRTEI);
  emxInit_struct_T(sp, &new, &cc_emlrtRTEI);
  for (i = 0; i < 17; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2._pobj0[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 17; i++) {
    lobj_2._pobj0[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 6; i++) {
    emlrtPushHeapReferenceStackR2021a(
        (emlrtCTX)sp, true, &ik._pobj5._pobj1._pobj1[i],
        (void *)&h_handle_matlabCodegenDestructo, NULL, NULL, NULL);
  }
  for (i = 0; i < 6; i++) {
    ik._pobj5._pobj1._pobj1[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5._pobj0,
                                    (void *)&h_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5._pobj0.matlabCodegenIsDeleted = true;
  for (i = 0; i < 6; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4._pobj1[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 6; i++) {
    ik._pobj4._pobj1[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 11; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj3[i],
                                      (void *)&h_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 11; i++) {
    ik._pobj3[i].matlabCodegenIsDeleted = true;
  }
  for (i = 0; i < 10; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2._pobj2[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 10; i++) {
    lobj_2._pobj2[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &lobj_2.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  lobj_2.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    emlrtPushHeapReferenceStackR2021a(
        (emlrtCTX)sp, true, &ik._pobj5._pobj1._pobj0[i],
        (void *)&b_handle_matlabCodegenDestructo, NULL, NULL, NULL);
  }
  for (i = 0; i < 5; i++) {
    ik._pobj5._pobj1._pobj0[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj5._pobj1.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj5._pobj1.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4._pobj0[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 5; i++) {
    ik._pobj4._pobj0[i].matlabCodegenIsDeleted = true;
  }
  emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj4.Base,
                                    (void *)&b_handle_matlabCodegenDestructo,
                                    NULL, NULL, NULL);
  ik._pobj4.Base.matlabCodegenIsDeleted = true;
  for (i = 0; i < 5; i++) {
    emlrtPushHeapReferenceStackR2021a((emlrtCTX)sp, true, &ik._pobj2[i],
                                      (void *)&b_handle_matlabCodegenDestructo,
                                      NULL, NULL, NULL);
  }
  for (i = 0; i < 5; i++) {
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
  importrobot(SD, &st, &lobj_2, &r);
  /*  Define the initial joint configuration as an array */
  for (i = 0; i < 5; i++) {
    C[i] = q0[i];
  }
  real_T dv[16];
  /* qInitial = q0; % q0 is already an array of joint positions */
  /*  Create the IK solver */
  st.site = &emlrtRSI;
  c_inverseKinematics_inverseKine(&st, &ik, &arm);
  /*  Define the end-effector name (use the name from your URDF) */
  /*  Define the weights for the IK solution */
  /*  Adjust as necessary for your DOF */
  /*  Solve the inverse kinematics */
  /* [newConfig, ~] = ik(endEffector, trvec2tform(pos), weights, qInitial); */
  st.site = &b_emlrtRSI;
  structConstructorHelper(cv, cv1, cv2, cv3, cv4, C, rv);
  trvec2tform(pos, dv);
  b_st.site = &fc_emlrtRSI;
  SystemCore_step(&b_st, &ik, dv, rv, new);
  new_data = new->data;
  /*  Extract the new joint positions and return as an array */
  /* vone = [newConfig.JointPosition]; */
  if (new->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, new->size[1], &emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (new->size[1] < 2) {
    emlrtDynamicBoundsCheckR2012b(2, 1, new->size[1], &b_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (new->size[1] < 3) {
    emlrtDynamicBoundsCheckR2012b(3, 1, new->size[1], &c_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (new->size[1] < 4) {
    emlrtDynamicBoundsCheckR2012b(4, 1, new->size[1], &d_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (new->size[1] < 5) {
    emlrtDynamicBoundsCheckR2012b(5, 1, new->size[1], &e_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  vone_size[0] = 1;
  vone_size[1] = 5;
  vone_data[0] = new_data[0].JointPosition.data[0];
  vone_data[1] = new_data[1].JointPosition.data[0];
  vone_data[2] = new_data[2].JointPosition.data[0];
  vone_data[3] = new_data[3].JointPosition.data[0];
  vone_data[4] = new_data[4].JointPosition.data[0];
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
  for (i = 0; i < 5; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj2[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &ik._pobj4.Base);
  for (i = 0; i < 5; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj4._pobj0[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1.Base);
  for (i = 0; i < 5; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1._pobj0[i]);
  }
  st.site = &c_emlrtRSI;
  b_handle_matlabCodegenDestructo(&st, &lobj_2.Base);
  for (i = 0; i < 10; i++) {
    st.site = &c_emlrtRSI;
    b_handle_matlabCodegenDestructo(&st, &lobj_2._pobj2[i]);
  }
  for (i = 0; i < 11; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj3[i]);
  }
  for (i = 0; i < 6; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj4._pobj1[i]);
  }
  st.site = &c_emlrtRSI;
  h_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj0);
  for (i = 0; i < 6; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &ik._pobj5._pobj1._pobj1[i]);
  }
  for (i = 0; i < 17; i++) {
    st.site = &c_emlrtRSI;
    h_handle_matlabCodegenDestructo(&st, &lobj_2._pobj0[i]);
  }
  emxFree_struct_T(sp, &new);
  emxFreeStruct_inverseKinematics(sp, &ik);
  d_emxFreeStruct_robotics_manip_(sp, &lobj_2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (armvone.c) */
