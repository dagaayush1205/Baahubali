/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * SystemCore.c
 *
 * Code generation for function 'SystemCore'
 *
 */

/* Include files */
#include "SystemCore.h"
#include "RigidBodyTree.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "eye.h"
#include "inverseKinematics.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo vf_emlrtRSI = {
    1,                 /* lineNo */
    "SystemCore/step", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" /* pathName */
};

static emlrtRSInfo wf_emlrtRSI = {
    123,                           /* lineNo */
    "inverseKinematics/setupImpl", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    126,                           /* lineNo */
    "inverseKinematics/setupImpl", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    129,                           /* lineNo */
    "inverseKinematics/setupImpl", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    528,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    530,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    531,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    532,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo eg_emlrtRSI = {
    533,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    534,                                 /* lineNo */
    "inverseKinematics/assembleProblem", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    135,                                /* lineNo */
    "inverseKinematics/setupExtraArgs", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    1,                 /* lineNo */
    1,                 /* colNo */
    "SystemCore/step", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" /* pName */
};

static emlrtDCInfo p_emlrtDCI = {
    522,                                 /* lineNo */
    23,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    4                      /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    522,                                 /* lineNo */
    23,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    522,                                 /* lineNo */
    26,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    527,                                 /* lineNo */
    21,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    533,                                 /* lineNo */
    49,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    534,                                 /* lineNo */
    52,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    531,                                 /* lineNo */
    23,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    531,                                 /* lineNo */
    23,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    531,                                 /* lineNo */
    25,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    531,                                 /* lineNo */
    25,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    531,                                 /* lineNo */
    35,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    531,                                 /* lineNo */
    35,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = {
    531,                                 /* lineNo */
    37,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    531,                                 /* lineNo */
    37,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtECInfo g_emlrtECI = {
    -1,                                  /* nDims */
    531,                                 /* lineNo */
    21,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtDCInfo w_emlrtDCI = {
    532,                                 /* lineNo */
    23,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    532,                                 /* lineNo */
    23,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    532,                                 /* lineNo */
    25,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    532,                                 /* lineNo */
    25,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = {
    532,                                 /* lineNo */
    35,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    532,                                 /* lineNo */
    35,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    532,                                 /* lineNo */
    42,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    532,                                 /* lineNo */
    42,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtECInfo h_emlrtECI = {
    -1,                                  /* nDims */
    532,                                 /* lineNo */
    21,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    1,                                  /* nDims */
    150,                                /* lineNo */
    13,                                 /* colNo */
    "inverseKinematics/setupExtraArgs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtDCInfo bb_emlrtDCI = {
    523,                                 /* lineNo */
    13,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    0,                                   /* iFirst */
    4,                                   /* iLast */
    528,                                 /* lineNo */
    58,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = {
    150,                                /* lineNo */
    23,                                 /* colNo */
    "inverseKinematics/setupExtraArgs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = {
    150,                                /* lineNo */
    23,                                 /* colNo */
    "inverseKinematics/setupExtraArgs", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    4                      /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    533,                                 /* lineNo */
    23,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = {
    533,                                 /* lineNo */
    23,                                  /* colNo */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    534,                                 /* lineNo */
    23,                                  /* colNo */
    "",                                  /* aName */
    "inverseKinematics/assembleProblem", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    522,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    523,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    540,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    541,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    146,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    150,                 /* lineNo */
    23,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    151,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    531,                 /* lineNo */
    21,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

/* Function Definitions */
void SystemCore_step(const emlrtStack *sp, inverseKinematics *obj,
                     const real_T varargin_2[16],
                     const b_struct_T varargin_4[5],
                     emxArray_struct_T *varargout_1)
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T varargin_1[5] = {'J', 'o', 'i', 'n', 't'};
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *A;
  emxArray_real_T *b;
  emxArray_real_T *r;
  rigidBodyJoint *joint;
  real_T tmp_data[14];
  real_T *A_data;
  real_T *b_data;
  real_T *r1;
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T i5;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (obj->isInitialized == 2) {
    emlrtErrorWithMessageIdR2018a(
        sp, &m_emlrtRTEI, "MATLAB:system:methodCalledWhenReleasedCodegen",
        "MATLAB:system:methodCalledWhenReleasedCodegen", 3, 4, 4, "step");
  }
  if (obj->isInitialized != 1) {
    real_T d;
    real_T k;
    real_T m;
    real_T n;
    real_T obj_Length;
    int32_T loop_ub;
    int32_T loop_ub_tmp;
    int8_T b_I[16];
    st.site = &vf_emlrtRSI;
    b_st.site = &fc_emlrtRSI;
    obj->isSetupComplete = false;
    if (obj->isInitialized != 0) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &m_emlrtRTEI,
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen",
          "MATLAB:system:methodCalledWhenLockedReleasedCodegen", 3, 4, 5,
          "setup");
    }
    obj->isInitialized = 1;
    c_st.site = &vf_emlrtRSI;
    d_st.site = &wf_emlrtRSI;
    n = obj->RigidBodyTreeInternal->PositionNumber;
    if (!(n >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n, &p_emlrtDCI, &d_st);
    }
    if (n != (int32_T)muDoubleScalarFloor(n)) {
      emlrtIntegerCheckR2012b(n, &q_emlrtDCI, &d_st);
    }
    d = 2.0 * n;
    i = (int32_T)muDoubleScalarFloor(d);
    if (d != i) {
      emlrtIntegerCheckR2012b(d, &r_emlrtDCI, &d_st);
    }
    emxInit_real_T(&d_st, &A, 2, &ec_emlrtRTEI);
    i1 = A->size[0] * A->size[1];
    A->size[0] = (int32_T)n;
    A->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(&d_st, A, i1, &ec_emlrtRTEI);
    A_data = A->data;
    loop_ub_tmp = (int32_T)n * (int32_T)d;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      A_data[i1] = 0.0;
    }
    emxInit_real_T(&d_st, &b, 1, &fc_emlrtRTEI);
    if (d != i) {
      emlrtIntegerCheckR2012b(d, &bb_emlrtDCI, &d_st);
    }
    loop_ub = (int32_T)d;
    i1 = b->size[0];
    b->size[0] = (int32_T)d;
    emxEnsureCapacity_real_T(&d_st, b, i1, &fc_emlrtRTEI);
    b_data = b->data;
    if ((int32_T)d != i) {
      emlrtIntegerCheckR2012b(d, &bb_emlrtDCI, &d_st);
    }
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = 0.0;
    }
    k = 1.0;
    m = 1.0;
    obj_Length = obj->RigidBodyTreeInternal->NumBodies;
    i = (int32_T)obj_Length;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, obj_Length, mxDOUBLE_CLASS,
                                  (int32_T)obj_Length, &n_emlrtRTEI, &d_st);
    emxInit_real_T(&d_st, &r, 2, &lc_emlrtRTEI);
    for (b_i = 0; b_i < i; b_i++) {
      real_T pnum;
      char_T obj_Vector[200];
      boolean_T b_bool;
      e_st.site = &ag_emlrtRSI;
      if (b_i > 4) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, 4, &kb_emlrtBCI, &e_st);
      }
      b_obj = obj->RigidBodyTreeInternal->Bodies[b_i];
      if (b_obj->Index == 0.0) {
        f_st.site = &oe_emlrtRSI;
        emlrtErrorWithMessageIdR2018a(
            &f_st, &b_emlrtRTEI,
            "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
            "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
            &varargin_1[0]);
      }
      joint = b_obj->JointInternal;
      pnum = joint->PositionNumber;
      e_st.site = &bg_emlrtRSI;
      f_st.site = &bb_emlrtRSI;
      obj_Length = joint->TypeInternal.Length;
      for (i1 = 0; i1 < 200; i1++) {
        obj_Vector[i1] = joint->TypeInternal.Vector[i1];
      }
      if (obj_Length < 1.0) {
        i1 = 0;
      } else {
        if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
          emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &f_st);
        }
        if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200,
                                        &h_emlrtBCI, &f_st);
        }
        i1 = (int32_T)obj_Length;
      }
      b_bool = false;
      if (i1 == 5) {
        loop_ub = 0;
        int32_T exitg1;
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
        real_T d1;
        int32_T b_loop_ub;
        int32_T i3;
        int32_T vectorUB;
        obj_Length = (k + pnum) - 1.0;
        if (k > obj_Length) {
          i1 = 0;
          i2 = 0;
        } else {
          if (k != (int32_T)muDoubleScalarFloor(k)) {
            emlrtIntegerCheckR2012b(k, &s_emlrtDCI, &d_st);
          }
          if (((int32_T)k < 1) || ((int32_T)k > (int32_T)n)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)k, 1, (int32_T)n,
                                          &cb_emlrtBCI, &d_st);
          }
          i1 = (int32_T)k - 1;
          if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
            emlrtIntegerCheckR2012b(obj_Length, &t_emlrtDCI, &d_st);
          }
          if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > (int32_T)n)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, (int32_T)n,
                                          &db_emlrtBCI, &d_st);
          }
          i2 = (int32_T)obj_Length;
        }
        d1 = m + pnum;
        if (m > d1 - 1.0) {
          i3 = 0;
          i4 = 0;
        } else {
          if (m != (int32_T)muDoubleScalarFloor(m)) {
            emlrtIntegerCheckR2012b(m, &u_emlrtDCI, &d_st);
          }
          if (((int32_T)m < 1) || ((int32_T)m > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)m, 1, (int32_T)d,
                                          &eb_emlrtBCI, &d_st);
          }
          i3 = (int32_T)m - 1;
          if (d1 - 1.0 != (int32_T)muDoubleScalarFloor(d1 - 1.0)) {
            emlrtIntegerCheckR2012b(d1 - 1.0, &v_emlrtDCI, &d_st);
          }
          if (((int32_T)(d1 - 1.0) < 1) || ((int32_T)(d1 - 1.0) > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(d1 - 1.0), 1, (int32_T)d,
                                          &fb_emlrtBCI, &d_st);
          }
          i4 = (int32_T)(d1 - 1.0);
        }
        e_st.site = &cg_emlrtRSI;
        eye(&e_st, pnum, r);
        r1 = r->data;
        loop_ub = i2 - i1;
        tmp_size[0] = loop_ub;
        b_loop_ub = i4 - i3;
        tmp_size[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&tmp_size[0], 2, &r->size[0], 2,
                                      &g_emlrtECI, &d_st);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (i4 = 0; i4 < loop_ub; i4++) {
            A_data[(i1 + i4) + A->size[0] * (i3 + i2)] = r1[i4 + loop_ub * i2];
          }
        }
        if (k > obj_Length) {
          i1 = 0;
          i2 = 0;
        } else {
          if (k != (int32_T)muDoubleScalarFloor(k)) {
            emlrtIntegerCheckR2012b(k, &w_emlrtDCI, &d_st);
          }
          if (((int32_T)k < 1) || ((int32_T)k > (int32_T)n)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)k, 1, (int32_T)n,
                                          &gb_emlrtBCI, &d_st);
          }
          i1 = (int32_T)k - 1;
          if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
            emlrtIntegerCheckR2012b(obj_Length, &x_emlrtDCI, &d_st);
          }
          if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > (int32_T)n)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, (int32_T)n,
                                          &hb_emlrtBCI, &d_st);
          }
          i2 = (int32_T)obj_Length;
        }
        obj_Length = m + 2.0 * pnum;
        if (d1 > obj_Length - 1.0) {
          i3 = 0;
          i4 = 0;
        } else {
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &y_emlrtDCI, &d_st);
          }
          if (((int32_T)d1 < 1) || ((int32_T)d1 > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, (int32_T)d,
                                          &ib_emlrtBCI, &d_st);
          }
          i3 = (int32_T)d1 - 1;
          if (obj_Length - 1.0 !=
              (int32_T)muDoubleScalarFloor(obj_Length - 1.0)) {
            emlrtIntegerCheckR2012b(obj_Length - 1.0, &ab_emlrtDCI, &d_st);
          }
          if (((int32_T)(obj_Length - 1.0) < 1) ||
              ((int32_T)(obj_Length - 1.0) > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(obj_Length - 1.0), 1,
                                          (int32_T)d, &jb_emlrtBCI, &d_st);
          }
          i4 = (int32_T)(obj_Length - 1.0);
        }
        e_st.site = &dg_emlrtRSI;
        eye(&e_st, pnum, r);
        r1 = r->data;
        loop_ub = r->size[0] * r->size[1];
        b_loop_ub = (loop_ub / 2) << 1;
        vectorUB = b_loop_ub - 2;
        for (i5 = 0; i5 <= vectorUB; i5 += 2) {
          __m128d r2;
          r2 = _mm_loadu_pd(&r1[i5]);
          _mm_storeu_pd(&r1[i5], _mm_mul_pd(r2, _mm_set1_pd(-1.0)));
        }
        for (i5 = b_loop_ub; i5 < loop_ub; i5++) {
          r1[i5] = -r1[i5];
        }
        loop_ub = i2 - i1;
        tmp_size[0] = loop_ub;
        b_loop_ub = i4 - i3;
        tmp_size[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&tmp_size[0], 2, &r->size[0], 2,
                                      &h_emlrtECI, &d_st);
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          for (i4 = 0; i4 < loop_ub; i4++) {
            A_data[(i1 + i4) + A->size[0] * (i3 + i2)] = r1[i4 + loop_ub * i2];
          }
        }
        e_st.site = &eg_emlrtRSI;
        c_rigidBodyJoint_get_PositionLi(&e_st, joint, tmp_data, tmp_size);
        i1 = tmp_size[0] << 1;
        if (i1 < 2) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i1, &ab_emlrtBCI, &d_st);
        }
        if (m != (int32_T)muDoubleScalarFloor(m)) {
          emlrtIntegerCheckR2012b(m, &eb_emlrtDCI, &d_st);
        }
        if (((int32_T)m < 1) || ((int32_T)m > b->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)m, 1, b->size[0], &lb_emlrtBCI,
                                        &d_st);
        }
        b_data[(int32_T)m - 1] = tmp_data[1];
        e_st.site = &fg_emlrtRSI;
        c_rigidBodyJoint_get_PositionLi(&e_st, joint, tmp_data, tmp_size);
        i1 = tmp_size[0] << 1;
        if (i1 < 1) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i1, &bb_emlrtBCI, &d_st);
        }
        if (((int32_T)((uint32_T)m + 1U) < 1) ||
            ((int32_T)((uint32_T)m + 1U) > b->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)m + 1U), 1,
                                        b->size[0], &mb_emlrtBCI, &d_st);
        }
        b_data[(int32_T)(uint32_T)m] = -tmp_data[0];
        m = obj_Length;
      }
      k += pnum;
    }
    emxFree_real_T(&d_st, &r);
    i = obj->Solver->ConstraintMatrix->size[0] *
        obj->Solver->ConstraintMatrix->size[1];
    obj->Solver->ConstraintMatrix->size[0] = (int32_T)n;
    obj->Solver->ConstraintMatrix->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(&d_st, obj->Solver->ConstraintMatrix, i,
                             &gc_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      obj->Solver->ConstraintMatrix->data[i] = A_data[i];
    }
    emxFree_real_T(&d_st, &A);
    loop_ub = b->size[0];
    i = obj->Solver->ConstraintBound->size[0];
    obj->Solver->ConstraintBound->size[0] = b->size[0];
    emxEnsureCapacity_real_T(&d_st, obj->Solver->ConstraintBound, i,
                             &hc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      obj->Solver->ConstraintBound->data[i] = b_data[i];
    }
    d_st.site = &xf_emlrtRSI;
    c_RigidBodyTree_get_JointPositi(&d_st, obj->RigidBodyTreeInternal,
                                    obj->Limits);
    d_st.site = &yf_emlrtRSI;
    e_st.site = &mg_emlrtRSI;
    obj->_pobj0.matlabCodegenIsDeleted = false;
    obj->Solver->ExtraArgs = &obj->_pobj0;
    for (i = 0; i < 36; i++) {
      obj->Solver->ExtraArgs->WeightMatrix[i] = 0.0;
    }
    obj->Solver->ExtraArgs->Robot = obj->RigidBodyTreeInternal;
    obj->Solver->ExtraArgs->KinematicModel = obj->RigidBodyTreeKinematicModel;
    for (i = 0; i < 16; i++) {
      b_I[i] = 0;
    }
    b_I[0] = 1;
    b_I[5] = 1;
    b_I[10] = 1;
    b_I[15] = 1;
    for (i = 0; i < 16; i++) {
      obj->Solver->ExtraArgs->Tform[i] = b_I[i];
    }
    obj->Solver->ExtraArgs->BodyIndex = -1.0;
    i = obj->Solver->ExtraArgs->ErrTemp->size[0];
    obj->Solver->ExtraArgs->ErrTemp->size[0] = 6;
    emxEnsureCapacity_real_T(&d_st, obj->Solver->ExtraArgs->ErrTemp, i,
                             &ic_emlrtRTEI);
    for (i = 0; i < 6; i++) {
      obj->Solver->ExtraArgs->ErrTemp->data[i] = 0.0;
    }
    obj->Solver->ExtraArgs->CostTemp = 0.0;
    d = obj->RigidBodyTreeInternal->PositionNumber;
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &db_emlrtDCI, &d_st);
    }
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &cb_emlrtDCI, &d_st);
    }
    i = b->size[0];
    b->size[0] = (int32_T)d;
    emxEnsureCapacity_real_T(&d_st, b, i, &jc_emlrtRTEI);
    b_data = b->data;
    d = obj->RigidBodyTreeInternal->PositionNumber;
    if (!(d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(d, &db_emlrtDCI, &d_st);
    }
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &cb_emlrtDCI, &d_st);
    }
    loop_ub = (int32_T)d;
    for (i = 0; i < loop_ub; i++) {
      b_data[i] = 0.0;
    }
    loop_ub = b->size[0];
    if (b->size[0] > 35) {
      emlrtDimSizeGeqCheckR2012b(35, b->size[0], &i_emlrtECI, &d_st);
    }
    i = obj->Solver->ExtraArgs->GradTemp->size[0];
    obj->Solver->ExtraArgs->GradTemp->size[0] = b->size[0];
    emxFree_real_T(&d_st, &b);
    emxEnsureCapacity_real_T(&d_st, obj->Solver->ExtraArgs->GradTemp, i,
                             &kc_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      obj->Solver->ExtraArgs->GradTemp->data[i] = 0.0;
    }
    obj->isSetupComplete = true;
  }
  st.site = &vf_emlrtRSI;
  inverseKinematics_stepImpl(&st, obj, varargin_2, varargin_4, varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (SystemCore.c) */
