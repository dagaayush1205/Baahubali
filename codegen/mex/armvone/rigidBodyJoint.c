/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rigidBodyJoint.c
 *
 * Code generation for function 'rigidBodyJoint'
 *
 */

/* Include files */
#include "rigidBodyJoint.h"
#include "CharacterVector.h"
#include "all.h"
#include "any.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "cat.h"
#include "normalizeRows.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "validatestring.h"
#include "warning.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = {
    279,                                 /* lineNo */
    "rigidBodyJoint/set.MotionSubspace", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo kb_emlrtRSI = {
    304,                                 /* lineNo */
    "rigidBodyJoint/get.MotionSubspace", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo nb_emlrtRSI = {
    166,                             /* lineNo */
    "rigidBodyJoint/rigidBodyJoint", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ob_emlrtRSI = {
    170,                             /* lineNo */
    "rigidBodyJoint/rigidBodyJoint", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo qe_emlrtRSI = {
    240,                   /* lineNo */
    "rigidBodyJoint/copy", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo re_emlrtRSI = {
    409,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo se_emlrtRSI = {
    410,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo te_emlrtRSI = {
    412,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ue_emlrtRSI = {
    414,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ve_emlrtRSI = {
    415,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo we_emlrtRSI = {
    421,                           /* lineNo */
    "rigidBodyJoint/copyInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo xe_emlrtRSI = {
    173,                             /* lineNo */
    "rigidBodyJoint/rigidBodyJoint", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ye_emlrtRSI = {
    74,               /* lineNo */
    "validatestring", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/lang/validatestring.m" /* pathName
                                                                            */
};

static emlrtRSInfo af_emlrtRSI = {
    111,                  /* lineNo */
    "fullValidatestring", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/lang/validatestring.m" /* pathName
                                                                            */
};

static emlrtRSInfo hf_emlrtRSI = {
    151,                       /* lineNo */
    "rigidBodyJoint/set.Type", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo if_emlrtRSI = {
    252,                       /* lineNo */
    "rigidBodyJoint/set.Name", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo jf_emlrtRSI = {
    254,                       /* lineNo */
    "rigidBodyJoint/set.Name", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo kf_emlrtRSI = {
    256,                       /* lineNo */
    "rigidBodyJoint/set.Name", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo bg_emlrtRSI = {
    296,                                 /* lineNo */
    "rigidBodyJoint/get.PositionLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo kk_emlrtRSI = {
    312,                            /* lineNo */
    "rigidBodyJoint/get.JointAxis", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo qk_emlrtRSI = {
    448,                             /* lineNo */
    "rigidBodyJoint/jointTransform", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo rk_emlrtRSI = {
    451,                             /* lineNo */
    "rigidBodyJoint/jointTransform", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo sk_emlrtRSI = {
    41,    /* lineNo */
    "cat", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                      */
};

static emlrtRSInfo tk_emlrtRSI = {
    65,         /* lineNo */
    "cat_impl", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/cat.m" /* pathName
                                                                      */
};

static emlrtRSInfo uk_emlrtRSI =
    {
        21,            /* lineNo */
        "axang2tform", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/"
        "axang2tform.m" /* pathName */
};

static emlrtRSInfo vk_emlrtRSI = {
    21,                      /* lineNo */
    "validateNumericMatrix", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/+validation/validateNumericMatrix.m" /* pathName */
};

static emlrtRSInfo xk_emlrtRSI = {
    23,           /* lineNo */
    "quat2tform", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/quat2tform.m" /* pathName */
};

static emlrtRSInfo yk_emlrtRSI = {
    22,          /* lineNo */
    "quat2rotm", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/quat2rotm.m" /* pathName */
};

static emlrtRSInfo al_emlrtRSI = {
    33,          /* lineNo */
    "quat2rotm", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/quat2rotm.m" /* pathName */
};

static emlrtRSInfo bl_emlrtRSI = {
    34,          /* lineNo */
    "quat2rotm", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/quat2rotm.m" /* pathName */
};

static emlrtRSInfo cl_emlrtRSI = {
    35,          /* lineNo */
    "quat2rotm", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutilsint/+robotics/"
    "+internal/quat2rotm.m" /* pathName */
};

static emlrtRSInfo yr_emlrtRSI = {
    620,                             /* lineNo */
    "rigidBodyJoint/randomPosition", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo as_emlrtRSI = {
    627,                             /* lineNo */
    "rigidBodyJoint/randomPosition", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo bs_emlrtRSI = {
    631,                             /* lineNo */
    "rigidBodyJoint/randomPosition", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo cs_emlrtRSI = {
    634,                             /* lineNo */
    "rigidBodyJoint/randomPosition", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ds_emlrtRSI = {
    288,                               /* lineNo */
    "rigidBodyJoint/get.HomePosition", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo es_emlrtRSI =
    {
        64,        /* lineNo */
        "randrot", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/shared/rotations/rotationslib/"
        "randrot.m" /* pathName */
};

static emlrtRSInfo fs_emlrtRSI =
    {
        68,        /* lineNo */
        "randrot", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/shared/rotations/rotationslib/"
        "randrot.m" /* pathName */
};

static emlrtRSInfo hs_emlrtRSI = {
    10,                         /* lineNo */
    "quaternionBase/normalize", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/rotations/rotationslib/"
    "+matlabshared/+rotations/+internal/@quaternionBase/normalize.m" /* pathName
                                                                      */
};

static emlrtRSInfo is_emlrtRSI = {
    597,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo js_emlrtRSI = {
    600,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ks_emlrtRSI = {
    602,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ls_emlrtRSI = {
    604,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ms_emlrtRSI = {
    596,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo ns_emlrtRSI = {
    599,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtRSInfo os_emlrtRSI = {
    601,                                             /* lineNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pathName
                                                                            */
};

static emlrtDCInfo
    d_emlrtDCI =
        {
            280,                                 /* lineNo */
            48,                                  /* colNo */
            "rigidBodyJoint/set.MotionSubspace", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtBCInfo
    d_emlrtBCI =
        {
            1,                                   /* iFirst */
            6,                                   /* iLast */
            280,                                 /* lineNo */
            48,                                  /* colNo */
            "",                                  /* aName */
            "rigidBodyJoint/set.MotionSubspace", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtECInfo e_emlrtECI = {
    -1,                                  /* nDims */
    280,                                 /* lineNo */
    17,                                  /* colNo */
    "rigidBodyJoint/set.MotionSubspace", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtDCInfo
    g_emlrtDCI =
        {
            305,                                 /* lineNo */
            60,                                  /* colNo */
            "rigidBodyJoint/get.MotionSubspace", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtBCInfo
    g_emlrtBCI =
        {
            1,                                   /* iFirst */
            6,                                   /* iLast */
            305,                                 /* lineNo */
            60,                                  /* colNo */
            "",                                  /* aName */
            "rigidBodyJoint/get.MotionSubspace", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    139,                  /* lineNo */
    9,                    /* colNo */
    "fullValidatestring", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/lang/validatestring.m" /* pName
                                                                            */
};

static emlrtRTEInfo k_emlrtRTEI = {
    131,                  /* lineNo */
    9,                    /* colNo */
    "fullValidatestring", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/lang/validatestring.m" /* pName
                                                                            */
};

static emlrtDCInfo
    eb_emlrtDCI =
        {
            297,                                 /* lineNo */
            53,                                  /* colNo */
            "rigidBodyJoint/get.PositionLimits", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtBCInfo
    hb_emlrtBCI =
        {
            1,                                   /* iFirst */
            7,                                   /* iLast */
            297,                                 /* lineNo */
            53,                                  /* colNo */
            "",                                  /* aName */
            "rigidBodyJoint/get.PositionLimits", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    225,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/cat.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    18,              /* lineNo */
    23,              /* colNo */
    "validatencols", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatencols.m" /* pName */
};

static emlrtBCInfo
    be_emlrtBCI =
        {
            -1,                              /* iFirst */
            -1,                              /* iLast */
            451,                             /* lineNo */
            93,                              /* colNo */
            "",                              /* aName */
            "rigidBodyJoint/jointTransform", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtBCInfo
    ce_emlrtBCI =
        {
            -1,                              /* iFirst */
            -1,                              /* iLast */
            451,                             /* lineNo */
            55,                              /* colNo */
            "",                              /* aName */
            "rigidBodyJoint/jointTransform", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtDCInfo
    pc_emlrtDCI =
        {
            621,                             /* lineNo */
            20,                              /* colNo */
            "rigidBodyJoint/randomPosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtDCInfo
    qc_emlrtDCI =
        {
            633,                             /* lineNo */
            53,                              /* colNo */
            "rigidBodyJoint/randomPosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtBCInfo
    je_emlrtBCI =
        {
            1,                               /* iFirst */
            7,                               /* iLast */
            633,                             /* lineNo */
            53,                              /* colNo */
            "",                              /* aName */
            "rigidBodyJoint/randomPosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtECInfo rb_emlrtECI = {
    -1,                              /* nDims */
    631,                             /* lineNo */
    17,                              /* colNo */
    "rigidBodyJoint/randomPosition", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtDCInfo
    rc_emlrtDCI =
        {
            289,                               /* lineNo */
            51,                                /* colNo */
            "rigidBodyJoint/get.HomePosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            1                   /* checkKind */
};

static emlrtBCInfo
    ke_emlrtBCI =
        {
            1,                                 /* iFirst */
            7,                                 /* iLast */
            289,                               /* lineNo */
            51,                                /* colNo */
            "",                                /* aName */
            "rigidBodyJoint/get.HomePosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtECInfo sb_emlrtECI = {
    1,                                               /* nDims */
    598,                                             /* lineNo */
    27,                                              /* colNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtECInfo tb_emlrtECI = {
    1,                                               /* nDims */
    598,                                             /* lineNo */
    22,                                              /* colNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtECInfo ub_emlrtECI = {
    1,                                               /* nDims */
    600,                                             /* lineNo */
    22,                                              /* colNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtECInfo vb_emlrtECI = {
    1,                                               /* nDims */
    602,                                             /* lineNo */
    22,                                              /* colNo */
    "rigidBodyJoint/naiveRandomPositionGivenBounds", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/rigidBodyJoint.m" /* pName
                                                                            */
};

static emlrtBCInfo
    le_emlrtBCI =
        {
            -1,                              /* iFirst */
            -1,                              /* iLast */
            627,                             /* lineNo */
            17,                              /* colNo */
            "",                              /* aName */
            "rigidBodyJoint/randomPosition", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

/* Function Declarations */
static void binary_expand_op_5(real_T in1_data[], int32_T *in1_size,
                               const rigidBodyJoint *in2, int32_T in3);

static void binary_expand_op_7(real_T in1_data[], int32_T *in1_size,
                               const rigidBodyJoint *in2, int32_T in3);

static void times(real_T in1_data[], int32_T *in1_size, const real_T in2_data[],
                  const int32_T *in2_size);

/* Function Definitions */
static void binary_expand_op_5(real_T in1_data[], int32_T *in1_size,
                               const rigidBodyJoint *in2, int32_T in3)
{
  real_T in2_data[7];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in1_size == 1) {
    loop_ub = in3 + 1;
  } else {
    loop_ub = *in1_size;
  }
  stride_0_0 = (in3 + 1 != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] =
        in2->PositionLimitsInternal[i * stride_0_0] + in1_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &in2_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

static void binary_expand_op_7(real_T in1_data[], int32_T *in1_size,
                               const rigidBodyJoint *in2, int32_T in3)
{
  real_T in2_data[7];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in1_size == 1) {
    loop_ub = in3 + 1;
  } else {
    loop_ub = *in1_size;
  }
  stride_0_0 = (in3 + 1 != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = in2->PositionLimitsInternal[i * stride_0_0 + 7] -
                  in1_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &in2_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

static void times(real_T in1_data[], int32_T *in1_size, const real_T in2_data[],
                  const int32_T *in2_size)
{
  real_T b_in1_data[7];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in2_size == 1) {
    loop_ub = *in1_size;
  } else {
    loop_ub = *in2_size;
  }
  stride_0_0 = (*in1_size != 1);
  stride_1_0 = (*in2_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] * in2_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in1_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

void c_rigidBodyJoint_get_MotionSubs(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     real_T msubspace_data[],
                                     int32_T msubspace_size[2])
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T kstr;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &b_st);
    }
    i = (int32_T)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
    real_T d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 6)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 6, &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      kstr = (int32_T)d;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = kstr;
    for (i = 0; i < kstr; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int32_T msubspace_data_tmp;
        msubspace_data_tmp = i1 + 6 * i;
        msubspace_data[msubspace_data_tmp] =
            obj->MotionSubspaceInternal[msubspace_data_tmp];
      }
    }
  } else {
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
  }
}

void c_rigidBodyJoint_get_PositionLi(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     real_T lims_data[], int32_T lims_size[2])
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T kstr;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &b_st);
    }
    i = (int32_T)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
    real_T d;
    d = obj->PositionNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &eb_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &hb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      kstr = (int32_T)d;
    }
    lims_size[0] = kstr;
    lims_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        lims_data[i1 + kstr * i] = obj->PositionLimitsInternal[i1 + 7 * i];
      }
    }
  } else {
    lims_size[0] = 1;
    lims_size[1] = 2;
    lims_data[0] = 0.0;
    lims_data[1] = 0.0;
  }
}

void c_rigidBodyJoint_set_MotionSubs(const emlrtStack *sp, rigidBodyJoint *obj,
                                     const real_T msubspace_data[],
                                     const int32_T msubspace_size[2])
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_iv[2];
  int32_T i;
  int32_T i1;
  int32_T kstr;
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &b_st);
    }
    i = (int32_T)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
    real_T d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &d_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 6)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 6, &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      kstr = (int32_T)d;
    }
    b_iv[0] = 6;
    b_iv[1] = kstr;
    emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &msubspace_size[0], 2,
                                  &e_emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < kstr; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int32_T i2;
        i2 = i1 + 6 * i;
        obj->MotionSubspaceInternal[i2] = msubspace_data[i2];
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      obj->MotionSubspaceInternal[i] = 0.0;
    }
  }
}

void c_rigidBodyJoint_transformBodyT(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     const emxArray_real_T *q, real_T T[16])
{
  static const char_T b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b[16];
  real_T b_I[16];
  real_T b_b[16];
  real_T tempR[9];
  real_T result_data[4];
  const real_T *q_data;
  real_T b_tempR_tmp;
  real_T cth;
  real_T sth;
  real_T tempR_tmp;
  int32_T exitg1;
  int32_T i;
  int32_T i1;
  int32_T kstr;
  boolean_T result;
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
  q_data = q->data;
  st.site = &fk_emlrtRSI;
  b_st.site = &gk_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &c_st);
    }
    i = (int32_T)obj->TypeInternal.Length;
  }
  result = false;
  if (i == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != obj->TypeInternal.Vector[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    kstr = 0;
  } else {
    result = false;
    if (i == 9) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 9) {
          if (cv3[kstr] != obj->TypeInternal.Vector[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      kstr = 1;
    } else {
      result = false;
      if (i == 8) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 8) {
            if (b_cv1[kstr] != obj->TypeInternal.Vector[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }
  switch (kstr) {
  case 0: {
    real_T R[9];
    real_T v[3];
    real_T c_tempR_tmp;
    real_T d_tempR_tmp;
    real_T e_tempR_tmp;
    real_T f_tempR_tmp;
    real_T g_tempR_tmp;
    real_T h_tempR_tmp;
    real_T i_tempR_tmp;
    real_T j_tempR_tmp;
    real_T k_tempR_tmp;
    int8_T input_sizes_idx_1;
    b_st.site = &hk_emlrtRSI;
    rigidBodyJoint_get_JointAxis(&b_st, obj, v);
    b_st.site = &ik_emlrtRSI;
    c_st.site = &sk_emlrtRSI;
    d_st.site = &tk_emlrtRSI;
    if ((q->size[0] != 1) && (q->size[0] != 0)) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &ib_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
          "MATLAB:catenate:matrixDimensionMismatch", 0);
    }
    input_sizes_idx_1 = (int8_T)(q->size[0] != 0);
    result_data[0] = v[0];
    result_data[1] = v[1];
    result_data[2] = v[2];
    kstr = input_sizes_idx_1;
    for (i = 0; i < kstr; i++) {
      result_data[3] = q_data[0];
    }
    b_st.site = &ik_emlrtRSI;
    c_st.site = &uk_emlrtRSI;
    d_st.site = &vk_emlrtRSI;
    e_st.site = &pb_emlrtRSI;
    if (input_sizes_idx_1 + 3 != 4) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &lb_emlrtRTEI,
          "Coder:toolbox:ValidateattributesincorrectNumcols",
          "MATLAB:axang2tform:incorrectNumcols", 5, 4, 5, "axang", 6, 4.0);
    }
    c_st.site = &lk_emlrtRSI;
    d_st.site = &mk_emlrtRSI;
    e_st.site = &nk_emlrtRSI;
    normalizeRows(&e_st, &result_data[0], v);
    cth = muDoubleScalarCos(result_data[3]);
    sth = muDoubleScalarSin(result_data[3]);
    c_tempR_tmp = v[0] * v[1] * (1.0 - cth);
    d_tempR_tmp = v[2] * sth;
    e_tempR_tmp = v[0] * v[2] * (1.0 - cth);
    f_tempR_tmp = v[1] * sth;
    g_tempR_tmp = v[1] * v[2] * (1.0 - cth);
    sth *= v[0];
    h_tempR_tmp = v[0] * v[0] * (1.0 - cth) + cth;
    i_tempR_tmp = c_tempR_tmp - d_tempR_tmp;
    j_tempR_tmp = e_tempR_tmp + f_tempR_tmp;
    c_tempR_tmp += d_tempR_tmp;
    d_tempR_tmp = v[1] * v[1] * (1.0 - cth) + cth;
    k_tempR_tmp = g_tempR_tmp - sth;
    e_tempR_tmp -= f_tempR_tmp;
    f_tempR_tmp = g_tempR_tmp + sth;
    g_tempR_tmp = v[2] * v[2] * (1.0 - cth) + cth;
    cat(h_tempR_tmp, i_tempR_tmp, j_tempR_tmp, c_tempR_tmp, d_tempR_tmp,
        k_tempR_tmp, e_tempR_tmp, f_tempR_tmp, g_tempR_tmp, tempR);
    cat(h_tempR_tmp, i_tempR_tmp, j_tempR_tmp, c_tempR_tmp, d_tempR_tmp,
        k_tempR_tmp, e_tempR_tmp, f_tempR_tmp, g_tempR_tmp, R);
    for (kstr = 0; kstr < 3; kstr++) {
      R[kstr] = tempR[3 * kstr];
      R[kstr + 3] = tempR[3 * kstr + 1];
      R[kstr + 6] = tempR[3 * kstr + 2];
    }
    memset(&b[0], 0, 16U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b[kstr] = R[3 * i];
      b[kstr + 1] = R[3 * i + 1];
      b[kstr + 2] = R[3 * i + 2];
    }
    b[15] = 1.0;
  } break;
  case 1: {
    real_T v[3];
    b_st.site = &jk_emlrtRSI;
    rigidBodyJoint_get_JointAxis(&b_st, obj, v);
    b_st.site = &qk_emlrtRSI;
    c_st.site = &wk_emlrtRSI;
    if (q->size[0] != 1) {
      if (q->size[0] == 1) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &kb_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&c_st, &jb_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    memset(&tempR[0], 0, 9U * sizeof(real_T));
    tempR[0] = 1.0;
    tempR[4] = 1.0;
    tempR[8] = 1.0;
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b[kstr] = tempR[3 * i];
      b[kstr + 1] = tempR[3 * i + 1];
      b[kstr + 2] = tempR[3 * i + 2];
      b[i + 12] = v[i] * q_data[0];
    }
    b[3] = 0.0;
    b[7] = 0.0;
    b[11] = 0.0;
    b[15] = 1.0;
  } break;
  case 2: {
    __m128d r;
    real_T R[9];
    real_T c_tempR_tmp;
    real_T d_tempR_tmp;
    real_T e_tempR_tmp;
    real_T f_tempR_tmp;
    real_T g_tempR_tmp;
    real_T h_tempR_tmp;
    real_T i_tempR_tmp;
    real_T j_tempR_tmp;
    real_T k_tempR_tmp;
    if (q->size[0] < 5) {
      emlrtDynamicBoundsCheckR2012b(5, 1, q->size[0], &ce_emlrtBCI, &st);
    }
    if (q->size[0] < 6) {
      emlrtDynamicBoundsCheckR2012b(6, 1, q->size[0], &ce_emlrtBCI, &st);
    }
    if (q->size[0] < 7) {
      emlrtDynamicBoundsCheckR2012b(7, 1, q->size[0], &ce_emlrtBCI, &st);
    }
    memset(&b_I[0], 0, 16U * sizeof(real_T));
    b_I[0] = 1.0;
    b_I[5] = 1.0;
    b_I[10] = 1.0;
    b_I[15] = 1.0;
    b_I[12] = q_data[4];
    b_I[13] = q_data[5];
    b_I[14] = q_data[6];
    b_st.site = &rk_emlrtRSI;
    if (q->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, q->size[0], &be_emlrtBCI, &b_st);
    }
    if (q->size[0] < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, q->size[0], &be_emlrtBCI, &b_st);
    }
    if (q->size[0] < 3) {
      emlrtDynamicBoundsCheckR2012b(3, 1, q->size[0], &be_emlrtBCI, &b_st);
    }
    if (q->size[0] < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, q->size[0], &be_emlrtBCI, &b_st);
    }
    c_st.site = &xk_emlrtRSI;
    d_st.site = &yk_emlrtRSI;
    r = _mm_loadu_pd(&q_data[0]);
    _mm_storeu_pd(&result_data[0], _mm_mul_pd(r, r));
    r = _mm_loadu_pd(&q_data[2]);
    _mm_storeu_pd(&result_data[2], _mm_mul_pd(r, r));
    sth = b_sumColumnB(result_data);
    e_st.site = &ok_emlrtRSI;
    if (sth < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    sth = muDoubleScalarSqrt(sth);
    r = _mm_set1_pd(1.0 / sth);
    _mm_storeu_pd(&result_data[0], _mm_mul_pd(_mm_loadu_pd(&q_data[0]), r));
    _mm_storeu_pd(&result_data[2], _mm_mul_pd(_mm_loadu_pd(&q_data[2]), r));
    d_st.site = &al_emlrtRSI;
    d_st.site = &al_emlrtRSI;
    d_st.site = &bl_emlrtRSI;
    d_st.site = &bl_emlrtRSI;
    d_st.site = &cl_emlrtRSI;
    d_st.site = &cl_emlrtRSI;
    c_tempR_tmp = result_data[1] * result_data[2];
    d_tempR_tmp = result_data[0] * result_data[3];
    e_tempR_tmp = result_data[3] * result_data[3];
    f_tempR_tmp = result_data[1] * result_data[3];
    g_tempR_tmp = result_data[0] * result_data[2];
    sth = result_data[2] * result_data[3];
    h_tempR_tmp = result_data[0] * result_data[1];
    i_tempR_tmp = result_data[1] * result_data[1];
    j_tempR_tmp = result_data[2] * result_data[2];
    k_tempR_tmp = 1.0 - 2.0 * (j_tempR_tmp + e_tempR_tmp);
    tempR_tmp = 2.0 * (c_tempR_tmp - d_tempR_tmp);
    b_tempR_tmp = 2.0 * (f_tempR_tmp + g_tempR_tmp);
    c_tempR_tmp = 2.0 * (c_tempR_tmp + d_tempR_tmp);
    d_tempR_tmp = 1.0 - 2.0 * (i_tempR_tmp + e_tempR_tmp);
    e_tempR_tmp = 2.0 * (sth - h_tempR_tmp);
    f_tempR_tmp = 2.0 * (f_tempR_tmp - g_tempR_tmp);
    g_tempR_tmp = 2.0 * (sth + h_tempR_tmp);
    sth = 1.0 - 2.0 * (i_tempR_tmp + j_tempR_tmp);
    cat(k_tempR_tmp, tempR_tmp, b_tempR_tmp, c_tempR_tmp, d_tempR_tmp,
        e_tempR_tmp, f_tempR_tmp, g_tempR_tmp, sth, tempR);
    cat(k_tempR_tmp, tempR_tmp, b_tempR_tmp, c_tempR_tmp, d_tempR_tmp,
        e_tempR_tmp, f_tempR_tmp, g_tempR_tmp, sth, R);
    for (kstr = 0; kstr < 3; kstr++) {
      R[kstr] = tempR[3 * kstr];
      R[kstr + 3] = tempR[3 * kstr + 1];
      R[kstr + 6] = tempR[3 * kstr + 2];
    }
    memset(&b_b[0], 0, 16U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b_b[kstr] = R[3 * i];
      b_b[kstr + 1] = R[3 * i + 1];
      b_b[kstr + 2] = R[3 * i + 2];
    }
    b_b[15] = 1.0;
    for (i = 0; i < 4; i++) {
      sth = b_I[i];
      cth = b_I[i + 4];
      tempR_tmp = b_I[i + 8];
      b_tempR_tmp = b_I[i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        kstr = i1 << 2;
        b[i + kstr] = ((sth * b_b[kstr] + cth * b_b[kstr + 1]) +
                       tempR_tmp * b_b[kstr + 2]) +
                      b_tempR_tmp * b_b[kstr + 3];
      }
    }
  } break;
  default:
    memset(&b[0], 0, 16U * sizeof(real_T));
    b[0] = 1.0;
    b[5] = 1.0;
    b[10] = 1.0;
    b[15] = 1.0;
    break;
  }
  for (i = 0; i < 4; i++) {
    sth = obj->JointToParentTransform[i];
    cth = obj->JointToParentTransform[i + 4];
    tempR_tmp = obj->JointToParentTransform[i + 8];
    b_tempR_tmp = obj->JointToParentTransform[i + 12];
    for (i1 = 0; i1 < 4; i1++) {
      kstr = i1 << 2;
      b_I[i + kstr] =
          ((sth * b[kstr] + cth * b[kstr + 1]) + tempR_tmp * b[kstr + 2]) +
          b_tempR_tmp * b[kstr + 3];
    }
    sth = b_I[i];
    cth = b_I[i + 4];
    tempR_tmp = b_I[i + 8];
    b_tempR_tmp = b_I[i + 12];
    for (i1 = 0; i1 < 4; i1++) {
      kstr = i1 << 2;
      T[i + kstr] = ((sth * obj->ChildToJointTransform[kstr] +
                      cth * obj->ChildToJointTransform[kstr + 1]) +
                     tempR_tmp * obj->ChildToJointTransform[kstr + 2]) +
                    b_tempR_tmp * obj->ChildToJointTransform[kstr + 3];
    }
  }
}

rigidBodyJoint *rigidBodyJoint_copy(const emlrtStack *sp,
                                    const rigidBodyJoint *obj,
                                    rigidBodyJoint *iobj_0)
{
  static const char_T b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv2[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv1[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  rigidBodyJoint *newjoint;
  real_T msubspace_data[36];
  real_T c_obj[16];
  real_T poslim_data[14];
  real_T b_obj[7];
  real_T obj_Length;
  real_T obj_Length_tmp;
  int32_T msubspace_size[2];
  int32_T partial_match_size[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int32_T loop_ub;
  char_T tmp_data[205];
  char_T b_obj_Vector[200];
  char_T obj_Vector[200];
  char_T obj_Vector_data[200];
  char_T jointtype_data[9];
  char_T partial_match_data[9];
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &re_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  obj_Length = obj->TypeInternal.Length;
  memcpy(&obj_Vector[0], &obj->TypeInternal.Vector[0], 200U * sizeof(char_T));
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &c_st);
    }
    loop_ub = (int32_T)obj_Length;
  }
  b_st.site = &se_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  obj_Length_tmp = obj->NameInternal.Length;
  memcpy(&b_obj_Vector[0], &obj->NameInternal.Vector[0], 200U * sizeof(char_T));
  if (obj_Length_tmp < 1.0) {
    ibmat = 0;
  } else {
    if (obj_Length_tmp != (int32_T)muDoubleScalarFloor(obj_Length_tmp)) {
      emlrtIntegerCheckR2012b(obj_Length_tmp, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)obj_Length_tmp < 1) || ((int32_T)obj_Length_tmp > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length_tmp, 1, 200,
                                    &c_emlrtBCI, &c_st);
    }
    ibmat = (int32_T)obj_Length_tmp;
  }
  b_st.site = &te_emlrtRSI;
  iobj_0->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    iobj_0->JointToParentTransform[i] = i1;
    iobj_0->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    iobj_0->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    iobj_0->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    iobj_0->MotionSubspaceInternal[i] = 0.0;
  }
  c_st.site = &nb_emlrtRSI;
  d_st.site = &pb_emlrtRSI;
  if (ibmat == 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rigidBodyJoint:expectedNonempty", 3, 4, 5, "jname");
  }
  c_st.site = &v_emlrtRSI;
  newjoint = iobj_0;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_0->TypeInternal = s;
  s = iobj_0->NameInternal;
  msubspace_size[0] = 1;
  msubspace_size[1] = ibmat;
  if (ibmat - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &b_obj_Vector[0],
           (uint32_T)ibmat * sizeof(char_T));
  }
  c_st.site = &ob_emlrtRSI;
  CharacterVector_setVector(&c_st, &s, obj_Vector_data, msubspace_size);
  iobj_0->NameInternal = s;
  c_st.site = &xe_emlrtRSI;
  d_st.site = &ye_emlrtRSI;
  msubspace_size[0] = 1;
  msubspace_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  e_st.site = &af_emlrtRSI;
  ibmat = get_match(&e_st, obj_Vector_data, msubspace_size, partial_match_data,
                    partial_match_size);
  if ((ibmat == 0) || (loop_ub == 0)) {
    poslim_size[0] = 1;
    poslim_size[1] = 8;
    for (i = 0; i < 8; i++) {
      jointtype_data[i] = ' ';
    }
    if ((ibmat == 0) || (loop_ub == 0)) {
      tmp_data[0] = ',';
      tmp_data[1] = ' ';
      tmp_data[2] = '\'';
      if (loop_ub - 1 >= 0) {
        memcpy(&tmp_data[3], &obj_Vector[0],
               (uint32_T)loop_ub * sizeof(char_T));
      }
      tmp_data[loop_ub + 3] = '\'';
      tmp_data[loop_ub + 4] = ',';
      emlrtErrorWithMessageIdR2018a(
          &d_st, &k_emlrtRTEI,
          "Coder:toolbox:ValidatestringUnrecognizedStringChoice",
          "MATLAB:rigidBodyJoint:unrecognizedStringChoice", 9, 4, 5, "jtype", 4,
          44, "\'revolute\', \'prismatic\', \'fixed\', \'floating\'", 4,
          loop_ub + 5, &tmp_data[0]);
    }
  } else if (ibmat > 1) {
    tmp_data[0] = ',';
    tmp_data[1] = ' ';
    tmp_data[2] = '\'';
    if (loop_ub - 1 >= 0) {
      memcpy(&tmp_data[3], &obj_Vector[0], (uint32_T)loop_ub * sizeof(char_T));
    }
    tmp_data[loop_ub + 3] = '\'';
    tmp_data[loop_ub + 4] = ',';
    emlrtErrorWithMessageIdR2018a(
        &d_st, &j_emlrtRTEI,
        "Coder:toolbox:ValidatestringAmbiguousStringChoice",
        "MATLAB:rigidBodyJoint:ambiguousStringChoice", 9, 4, 5, "jtype", 4, 44,
        "\'revolute\', \'prismatic\', \'fixed\', \'floating\'", 4, loop_ub + 5,
        &tmp_data[0]);
  } else {
    poslim_size[0] = 1;
    loop_ub = partial_match_size[1];
    poslim_size[1] = partial_match_size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&jointtype_data[0], &partial_match_data[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
  }
  c_st.site = &w_emlrtRSI;
  s = iobj_0->TypeInternal;
  d_st.site = &hf_emlrtRSI;
  CharacterVector_setVector(&d_st, &s, jointtype_data, poslim_size);
  iobj_0->TypeInternal = s;
  c_st.site = &x_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  obj_Length = iobj_0->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = iobj_0->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &d_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &d_st);
    }
    i = (int32_T)obj_Length;
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
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 1.0;
    iobj_0->PositionNumber = 1.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 1.0;
    iobj_0->PositionNumber = 1.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
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
    iobj_0->VelocityNumber = 6.0;
    iobj_0->PositionNumber = 7.0;
    iobj_0->JointAxisInternal[0] = rtNaN;
    iobj_0->JointAxisInternal[1] = rtNaN;
    iobj_0->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    iobj_0->VelocityNumber = 0.0;
    iobj_0->PositionNumber = 0.0;
    iobj_0->JointAxisInternal[0] = 0.0;
    iobj_0->JointAxisInternal[1] = 0.0;
    iobj_0->JointAxisInternal[2] = 0.0;
    break;
  }
  c_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&c_st, iobj_0, msubspace_data,
                                  msubspace_size);
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  obj_Length = iobj_0->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = iobj_0->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &d_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &d_st);
    }
    i = (int32_T)obj_Length;
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
    obj_Length = iobj_0->PositionNumber;
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
        emlrtIntegerCheckR2012b(obj_Length, &emlrtDCI, &b_st);
      }
      if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 7, &emlrtBCI,
                                      &b_st);
      }
      loop_ub = (int32_T)obj_Length;
    }
    partial_match_size[0] = loop_ub;
    partial_match_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&partial_match_size[0], 2, &poslim_size[0], 2,
                                  &emlrtECI, &b_st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        iobj_0->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    obj_Length = iobj_0->PositionNumber;
    if (obj_Length < 1.0) {
      i = 0;
    } else {
      if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
        emlrtIntegerCheckR2012b(obj_Length, &b_emlrtDCI, &b_st);
      }
      if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 7, &b_emlrtBCI,
                                      &b_st);
      }
      i = (int32_T)obj_Length;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI,
                                      &b_st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      iobj_0->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    partial_match_size[0] = 1;
    partial_match_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&partial_match_size[0], 2, &poslim_size[0], 2,
                                  &c_emlrtECI, &b_st);
    iobj_0->PositionLimitsInternal[0] = poslim_data[0];
    iobj_0->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI,
                                      &b_st);
    }
    iobj_0->HomePositionInternal[0] = homepos_data[0];
  }
  b_st.site = &ue_emlrtRSI;
  c_st.site = &ie_emlrtRSI;
  if (obj_Length_tmp < 1.0) {
    i = 0;
  } else {
    if (obj_Length_tmp != (int32_T)muDoubleScalarFloor(obj_Length_tmp)) {
      emlrtIntegerCheckR2012b(obj_Length_tmp, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)obj_Length_tmp < 1) || ((int32_T)obj_Length_tmp > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length_tmp, 1, 200,
                                    &c_emlrtBCI, &c_st);
    }
    i = (int32_T)obj_Length_tmp;
  }
  if (i != 0) {
    b_st.site = &ve_emlrtRSI;
    c_st.site = &ie_emlrtRSI;
    memcpy(&obj_Vector[0], &obj->NameInternal.Vector[0], 200U * sizeof(char_T));
    if (obj_Length_tmp < 1.0) {
      loop_ub = 0;
    } else {
      if (obj_Length_tmp != (int32_T)muDoubleScalarFloor(obj_Length_tmp)) {
        emlrtIntegerCheckR2012b(obj_Length_tmp, &c_emlrtDCI, &c_st);
      }
      if (((int32_T)obj_Length_tmp < 1) || ((int32_T)obj_Length_tmp > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length_tmp, 1, 200,
                                      &c_emlrtBCI, &c_st);
      }
      loop_ub = (int32_T)obj_Length_tmp;
    }
    b_st.site = &ve_emlrtRSI;
    c_st.site = &if_emlrtRSI;
    d_st.site = &pb_emlrtRSI;
    if (loop_ub == 0) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &b_emlrtRTEI,
          "Coder:toolbox:ValidateattributesexpectedNonempty",
          "MATLAB:rigidBodyJoint:expectedNonempty", 3, 4, 4, "Name");
    }
    if (!iobj_0->InTree) {
      s = iobj_0->NameInternal;
      msubspace_size[0] = 1;
      msubspace_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        memcpy(&obj_Vector_data[0], &obj_Vector[0],
               (uint32_T)loop_ub * sizeof(char_T));
      }
      c_st.site = &jf_emlrtRSI;
      CharacterVector_setVector(&c_st, &s, obj_Vector_data, msubspace_size);
      iobj_0->NameInternal = s;
    } else {
      c_st.site = &kf_emlrtRSI;
      d_st.site = &lf_emlrtRSI;
      warning(&d_st);
    }
  }
  memcpy(&poslim_data[0], &obj->PositionLimitsInternal[0],
         14U * sizeof(real_T));
  for (i = 0; i < 14; i++) {
    iobj_0->PositionLimitsInternal[i] = poslim_data[i];
  }
  for (i = 0; i < 7; i++) {
    b_obj[i] = obj->HomePositionInternal[i];
  }
  for (i = 0; i < 7; i++) {
    iobj_0->HomePositionInternal[i] = b_obj[i];
  }
  iobj_0->JointAxisInternal[0] = obj->JointAxisInternal[0];
  iobj_0->JointAxisInternal[1] = obj->JointAxisInternal[1];
  iobj_0->JointAxisInternal[2] = obj->JointAxisInternal[2];
  b_st.site = &we_emlrtRSI;
  c_rigidBodyJoint_get_MotionSubs(&b_st, obj, msubspace_data, msubspace_size);
  b_st.site = &we_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&b_st, iobj_0, msubspace_data,
                                  msubspace_size);
  memcpy(&c_obj[0], &obj->JointToParentTransform[0], 16U * sizeof(real_T));
  for (i = 0; i < 16; i++) {
    iobj_0->JointToParentTransform[i] = c_obj[i];
  }
  memcpy(&c_obj[0], &obj->ChildToJointTransform[0], 16U * sizeof(real_T));
  for (i = 0; i < 16; i++) {
    iobj_0->ChildToJointTransform[i] = c_obj[i];
  }
  return newjoint;
}

void rigidBodyJoint_get_JointAxis(const emlrtStack *sp,
                                  const rigidBodyJoint *obj, real_T ax[3])
{
  static const char_T b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  int32_T exitg1;
  int32_T kstr;
  boolean_T b_bool;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kk_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    kstr = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &b_st);
    }
    kstr = (int32_T)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (kstr == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
  guard1 = false;
  if (b_bool) {
    guard1 = true;
  } else {
    st.site = &kk_emlrtRSI;
    b_st.site = &bb_emlrtRSI;
    if (obj->TypeInternal.Length < 1.0) {
      kstr = 0;
    } else {
      if (obj->TypeInternal.Length !=
          (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
        emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &b_st);
      }
      if (((int32_T)obj->TypeInternal.Length < 1) ||
          ((int32_T)obj->TypeInternal.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                      &c_emlrtBCI, &b_st);
      }
      kstr = (int32_T)obj->TypeInternal.Length;
    }
    b_bool = false;
    if (kstr == 9) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 9) {
          if (obj->TypeInternal.Vector[kstr] != cv3[kstr]) {
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
      guard1 = true;
    } else {
      ax[0] = rtNaN;
      ax[1] = rtNaN;
      ax[2] = rtNaN;
    }
  }
  if (guard1) {
    ax[0] = obj->JointAxisInternal[0];
    ax[1] = obj->JointAxisInternal[1];
    ax[2] = obj->JointAxisInternal[2];
  }
}

void rigidBodyJoint_randomPosition(const emlrtStack *sp,
                                   const rigidBodyJoint *obj, real_T qv_data[],
                                   int32_T qv_size[2])
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T b_tmp_data;
  emxArray_boolean_T c_tmp_data;
  emxArray_boolean_T d_tmp_data;
  emxArray_boolean_T e_tmp_data;
  emxArray_boolean_T f_tmp_data;
  emxArray_boolean_T g_tmp_data;
  real_T rn_data[7];
  real_T x_data[7];
  real_T r[4];
  real_T c_r[3];
  real_T rn[3];
  real_T dv[2];
  real_T n;
  int32_T i;
  int32_T loop_ub;
  int32_T tmp_size;
  int32_T x_size;
  int8_T unnamed_idx_1;
  boolean_T tmp_data[7];
  boolean_T b_bool;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yr_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &ds_emlrtRSI;
  c_st.site = &bb_emlrtRSI;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    if (obj->TypeInternal.Length !=
        (int32_T)muDoubleScalarFloor(obj->TypeInternal.Length)) {
      emlrtIntegerCheckR2012b(obj->TypeInternal.Length, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)obj->TypeInternal.Length < 1) ||
        ((int32_T)obj->TypeInternal.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj->TypeInternal.Length, 1, 200,
                                    &c_emlrtBCI, &c_st);
    }
    i = (int32_T)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    tmp_size = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (tmp_size < 5) {
        if (obj->TypeInternal.Vector[tmp_size] != b_cv[tmp_size]) {
          exitg1 = 1;
        } else {
          tmp_size++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!b_bool) {
    n = obj->PositionNumber;
    if (n < 1.0) {
      i = 0;
    } else {
      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &rc_emlrtDCI, &st);
      }
      if (((int32_T)n < 1) || ((int32_T)n > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, 7, &ke_emlrtBCI, &st);
      }
      i = (int32_T)n;
    }
    unnamed_idx_1 = (int8_T)i;
  } else {
    unnamed_idx_1 = 1;
  }
  qv_size[0] = 1;
  qv_size[1] = unnamed_idx_1;
  loop_ub = unnamed_idx_1;
  if (loop_ub - 1 >= 0) {
    memset(&qv_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }
  if (obj->PositionNumber !=
      (int32_T)muDoubleScalarFloor(obj->PositionNumber)) {
    emlrtIntegerCheckR2012b(obj->PositionNumber, &pc_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  switch ((int32_T)obj->PositionNumber) {
  case 0:
    qv_size[0] = 1;
    qv_size[1] = 1;
    qv_data[0] = rtNaN;
    break;
  case 7: {
    __m128d b_r;
    __m128d r1;
    boolean_T b[3];
    boolean_T b_b[3];
    boolean_T bv[3];
    boolean_T exitg2;
    boolean_T guard1;
    boolean_T guard2;
    boolean_T guard3;
    boolean_T y;
    st.site = &as_emlrtRSI;
    b_st.site = &es_emlrtRSI;
    emlrtRandn(&r[0], 4);
    b_st.site = &fs_emlrtRSI;
    c_st.site = &hs_emlrtRSI;
    n = ((r[0] * r[0] + r[1] * r[1]) + r[2] * r[2]) + r[3] * r[3];
    if (n < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    n = muDoubleScalarSqrt(n);
    if (unnamed_idx_1 < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, unnamed_idx_1, &le_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    qv_data[0] = r[0] / n;
    if (unnamed_idx_1 < 2) {
      emlrtDynamicBoundsCheckR2012b(2, 1, 1, &le_emlrtBCI, (emlrtConstCTX)sp);
    }
    qv_data[1] = r[1] / n;
    if (unnamed_idx_1 < 3) {
      emlrtDynamicBoundsCheckR2012b(3, 1, 2, &le_emlrtBCI, (emlrtConstCTX)sp);
    }
    qv_data[2] = r[2] / n;
    if (unnamed_idx_1 < 4) {
      emlrtDynamicBoundsCheckR2012b(4, 1, 3, &le_emlrtBCI, (emlrtConstCTX)sp);
    }
    qv_data[3] = r[3] / n;
    if (unnamed_idx_1 < 5) {
      i = 0;
      tmp_size = 0;
    } else {
      i = 4;
      tmp_size = unnamed_idx_1;
    }
    loop_ub = tmp_size - i;
    if (loop_ub != 3) {
      emlrtSubAssignSizeCheck1dR2017a(loop_ub, 3, &rb_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    st.site = &bs_emlrtRSI;
    n = obj->PositionLimitsInternal[4];
    bv[0] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
    n = obj->PositionLimitsInternal[5];
    bv[1] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
    n = obj->PositionLimitsInternal[6];
    bv[2] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
    b_bool = true;
    tmp_size = 0;
    exitg2 = false;
    while ((!exitg2) && (tmp_size < 3)) {
      if (!bv[tmp_size]) {
        b_bool = false;
        exitg2 = true;
      } else {
        tmp_size++;
      }
    }
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (b_bool) {
      n = obj->PositionLimitsInternal[11];
      b[0] = muDoubleScalarIsInf(n);
      b_b[0] = muDoubleScalarIsNaN(n);
      n = obj->PositionLimitsInternal[12];
      b[1] = muDoubleScalarIsInf(n);
      b_b[1] = muDoubleScalarIsNaN(n);
      n = obj->PositionLimitsInternal[13];
      b[2] = muDoubleScalarIsInf(n);
      b_b[2] = muDoubleScalarIsNaN(n);
      y = true;
      tmp_size = 0;
      exitg2 = false;
      while ((!exitg2) && (tmp_size < 3)) {
        if (b[tmp_size] || b_b[tmp_size]) {
          y = false;
          exitg2 = true;
        } else {
          tmp_size++;
        }
      }
      if (y) {
        __m128d r2;
        b_st.site = &is_emlrtRSI;
        emlrtRandu(&rn[0], 3);
        b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[11]);
        r1 = _mm_loadu_pd(&obj->PositionLimitsInternal[4]);
        r2 = _mm_loadu_pd(&rn[0]);
        _mm_storeu_pd(&rn[0],
                      _mm_add_pd(r1, _mm_mul_pd(r2, _mm_sub_pd(b_r, r1))));
        n = obj->PositionLimitsInternal[6];
        rn[2] = n + rn[2] * (obj->PositionLimitsInternal[13] - n);
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
    if (guard3) {
      if (b_bool) {
        n = obj->PositionLimitsInternal[11];
        b[0] = !muDoubleScalarIsInf(n);
        b_b[0] = !muDoubleScalarIsNaN(n);
        n = obj->PositionLimitsInternal[12];
        b[1] = !muDoubleScalarIsInf(n);
        b_b[1] = !muDoubleScalarIsNaN(n);
        n = obj->PositionLimitsInternal[13];
        b[2] = !muDoubleScalarIsInf(n);
        b_b[2] = !muDoubleScalarIsNaN(n);
        y = false;
        tmp_size = 0;
        exitg2 = false;
        while ((!exitg2) && (tmp_size < 3)) {
          if ((!b[tmp_size]) || (!b_b[tmp_size])) {
            y = true;
            exitg2 = true;
          } else {
            tmp_size++;
          }
        }
        if (y) {
          b_st.site = &js_emlrtRSI;
          emlrtRandn(&c_r[0], 3);
          dv[0] = muDoubleScalarAbs(c_r[0]);
          dv[1] = muDoubleScalarAbs(c_r[1]);
          b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[4]);
          r1 = _mm_loadu_pd(&dv[0]);
          _mm_storeu_pd(&rn[0], _mm_add_pd(b_r, r1));
          rn[2] = obj->PositionLimitsInternal[6] + muDoubleScalarAbs(c_r[2]);
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }
    if (guard2) {
      y = false;
      tmp_size = 0;
      exitg2 = false;
      while ((!exitg2) && (tmp_size < 3)) {
        if (!bv[tmp_size]) {
          y = true;
          exitg2 = true;
        } else {
          tmp_size++;
        }
      }
      if (y) {
        n = obj->PositionLimitsInternal[11];
        b[0] = muDoubleScalarIsInf(n);
        b_b[0] = muDoubleScalarIsNaN(n);
        n = obj->PositionLimitsInternal[12];
        b[1] = muDoubleScalarIsInf(n);
        b_b[1] = muDoubleScalarIsNaN(n);
        n = obj->PositionLimitsInternal[13];
        b[2] = muDoubleScalarIsInf(n);
        b_b[2] = muDoubleScalarIsNaN(n);
        y = true;
        tmp_size = 0;
        exitg2 = false;
        while ((!exitg2) && (tmp_size < 3)) {
          if (b[tmp_size] || b_b[tmp_size]) {
            y = false;
            exitg2 = true;
          } else {
            tmp_size++;
          }
        }
        if (y) {
          b_st.site = &ks_emlrtRSI;
          emlrtRandn(&c_r[0], 3);
          dv[0] = muDoubleScalarAbs(c_r[0]);
          dv[1] = muDoubleScalarAbs(c_r[1]);
          b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[11]);
          r1 = _mm_loadu_pd(&dv[0]);
          _mm_storeu_pd(&rn[0], _mm_sub_pd(b_r, r1));
          rn[2] = obj->PositionLimitsInternal[13] - muDoubleScalarAbs(c_r[2]);
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if (guard1) {
      b_st.site = &ls_emlrtRSI;
      emlrtRandn(&rn[0], 3);
    }
    for (tmp_size = 0; tmp_size < 3; tmp_size++) {
      qv_data[i + tmp_size] = rn[tmp_size];
    }
  } break;
  default: {
    __m128d b_r;
    __m128d r1;
    int32_T vectorUB;
    boolean_T guard1;
    boolean_T guard2;
    boolean_T guard3;
    n = obj->PositionNumber;
    if (n < 1.0) {
      loop_ub = 0;
    } else {
      if (n != (int32_T)muDoubleScalarFloor(n)) {
        emlrtIntegerCheckR2012b(n, &qc_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)n < 1) || ((int32_T)n > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)n, 1, 7, &je_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      loop_ub = (int32_T)n;
    }
    st.site = &cs_emlrtRSI;
    tmp_size = loop_ub;
    for (i = 0; i < loop_ub; i++) {
      n = obj->PositionLimitsInternal[i];
      tmp_data[i] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
    }
    b_tmp_data.data = &tmp_data[0];
    b_tmp_data.size = &tmp_size;
    b_tmp_data.allocatedSize = 7;
    b_tmp_data.numDimensions = 1;
    b_tmp_data.canFreeData = false;
    guard1 = false;
    guard2 = false;
    guard3 = false;
    b_st.site = &ms_emlrtRSI;
    if (all(&b_st, &b_tmp_data)) {
      tmp_size = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        n = obj->PositionLimitsInternal[i + 7];
        tmp_data[i] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
      }
      c_tmp_data.data = &tmp_data[0];
      c_tmp_data.size = &tmp_size;
      c_tmp_data.allocatedSize = 7;
      c_tmp_data.numDimensions = 1;
      c_tmp_data.canFreeData = false;
      b_st.site = &ms_emlrtRSI;
      if (all(&b_st, &c_tmp_data)) {
        int32_T scalarLB_tmp;
        int32_T vectorUB_tmp;
        b_st.site = &is_emlrtRSI;
        x_size = (int8_T)loop_ub;
        if (loop_ub != 0) {
          emlrtRandu(&rn_data[0], loop_ub);
        }
        scalarLB_tmp = (loop_ub / 2) << 1;
        vectorUB_tmp = scalarLB_tmp - 2;
        for (i = 0; i <= vectorUB_tmp; i += 2) {
          b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[i + 7]);
          r1 = _mm_loadu_pd(&obj->PositionLimitsInternal[i]);
          _mm_storeu_pd(&x_data[i], _mm_sub_pd(b_r, r1));
        }
        for (i = scalarLB_tmp; i < loop_ub; i++) {
          x_data[i] = obj->PositionLimitsInternal[i + 7] -
                      obj->PositionLimitsInternal[i];
        }
        if (((int8_T)loop_ub != loop_ub) &&
            (((int8_T)loop_ub != 1) && (loop_ub != 1))) {
          emlrtDimSizeImpxCheckR2021b((int8_T)loop_ub, loop_ub, &sb_emlrtECI,
                                      &st);
        }
        if ((int8_T)loop_ub == loop_ub) {
          tmp_size = ((int8_T)loop_ub / 2) << 1;
          vectorUB = tmp_size - 2;
          for (i = 0; i <= vectorUB; i += 2) {
            b_r = _mm_loadu_pd(&rn_data[i]);
            r1 = _mm_loadu_pd(&x_data[i]);
            _mm_storeu_pd(&rn_data[i], _mm_mul_pd(b_r, r1));
          }
          for (i = tmp_size; i < x_size; i++) {
            rn_data[i] *= x_data[i];
          }
        } else {
          times(rn_data, &x_size, x_data, &loop_ub);
        }
        if ((loop_ub != x_size) && ((loop_ub != 1) && (x_size != 1))) {
          emlrtDimSizeImpxCheckR2021b(loop_ub, x_size, &tb_emlrtECI, &st);
        }
        if (loop_ub == x_size) {
          x_size = loop_ub;
          for (i = 0; i <= vectorUB_tmp; i += 2) {
            b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[i]);
            r1 = _mm_loadu_pd(&rn_data[i]);
            _mm_storeu_pd(&rn_data[i], _mm_add_pd(b_r, r1));
          }
          for (i = scalarLB_tmp; i < loop_ub; i++) {
            rn_data[i] += obj->PositionLimitsInternal[i];
          }
        } else {
          binary_expand_op_5(rn_data, &x_size, obj, loop_ub - 1);
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
    if (guard3) {
      tmp_size = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        n = obj->PositionLimitsInternal[i];
        tmp_data[i] = ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
      }
      d_tmp_data.data = &tmp_data[0];
      d_tmp_data.size = &tmp_size;
      d_tmp_data.allocatedSize = 7;
      d_tmp_data.numDimensions = 1;
      d_tmp_data.canFreeData = false;
      b_st.site = &ns_emlrtRSI;
      if (all(&b_st, &d_tmp_data)) {
        tmp_size = loop_ub;
        for (i = 0; i < loop_ub; i++) {
          n = obj->PositionLimitsInternal[i + 7];
          tmp_data[i] = (muDoubleScalarIsInf(n) || muDoubleScalarIsNaN(n));
        }
        f_tmp_data.data = &tmp_data[0];
        f_tmp_data.size = &tmp_size;
        f_tmp_data.allocatedSize = 7;
        f_tmp_data.numDimensions = 1;
        f_tmp_data.canFreeData = false;
        b_st.site = &ns_emlrtRSI;
        if (any(&b_st, &f_tmp_data)) {
          b_st.site = &js_emlrtRSI;
          dv[0] = loop_ub;
          dv[1] = 1.0;
          c_st.site = &js_emlrtRSI;
          x_size = randn(&c_st, dv, x_data);
          for (tmp_size = 0; tmp_size < x_size; tmp_size++) {
            rn_data[tmp_size] = muDoubleScalarAbs(x_data[tmp_size]);
          }
          if ((loop_ub != x_size) && ((loop_ub != 1) && (x_size != 1))) {
            emlrtDimSizeImpxCheckR2021b(loop_ub, x_size, &ub_emlrtECI, &st);
          }
          if (loop_ub == x_size) {
            x_size = loop_ub;
            tmp_size = (loop_ub / 2) << 1;
            vectorUB = tmp_size - 2;
            for (i = 0; i <= vectorUB; i += 2) {
              b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[i]);
              r1 = _mm_loadu_pd(&rn_data[i]);
              _mm_storeu_pd(&rn_data[i], _mm_add_pd(b_r, r1));
            }
            for (i = tmp_size; i < loop_ub; i++) {
              rn_data[i] += obj->PositionLimitsInternal[i];
            }
          } else {
            binary_expand_op_5(rn_data, &x_size, obj, loop_ub - 1);
          }
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    }
    if (guard2) {
      tmp_size = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        n = obj->PositionLimitsInternal[i];
        tmp_data[i] = (muDoubleScalarIsInf(n) || muDoubleScalarIsNaN(n));
      }
      e_tmp_data.data = &tmp_data[0];
      e_tmp_data.size = &tmp_size;
      e_tmp_data.allocatedSize = 7;
      e_tmp_data.numDimensions = 1;
      e_tmp_data.canFreeData = false;
      b_st.site = &os_emlrtRSI;
      if (any(&b_st, &e_tmp_data)) {
        tmp_size = loop_ub;
        for (i = 0; i < loop_ub; i++) {
          n = obj->PositionLimitsInternal[i + 7];
          tmp_data[i] =
              ((!muDoubleScalarIsInf(n)) && (!muDoubleScalarIsNaN(n)));
        }
        g_tmp_data.data = &tmp_data[0];
        g_tmp_data.size = &tmp_size;
        g_tmp_data.allocatedSize = 7;
        g_tmp_data.numDimensions = 1;
        g_tmp_data.canFreeData = false;
        b_st.site = &os_emlrtRSI;
        if (all(&b_st, &g_tmp_data)) {
          b_st.site = &ks_emlrtRSI;
          dv[0] = loop_ub;
          dv[1] = 1.0;
          c_st.site = &ks_emlrtRSI;
          x_size = randn(&c_st, dv, x_data);
          for (tmp_size = 0; tmp_size < x_size; tmp_size++) {
            rn_data[tmp_size] = muDoubleScalarAbs(x_data[tmp_size]);
          }
          if ((loop_ub != x_size) && ((loop_ub != 1) && (x_size != 1))) {
            emlrtDimSizeImpxCheckR2021b(loop_ub, x_size, &vb_emlrtECI, &st);
          }
          if (loop_ub == x_size) {
            x_size = loop_ub;
            tmp_size = (loop_ub / 2) << 1;
            vectorUB = tmp_size - 2;
            for (i = 0; i <= vectorUB; i += 2) {
              b_r = _mm_loadu_pd(&obj->PositionLimitsInternal[i + 7]);
              r1 = _mm_loadu_pd(&rn_data[i]);
              _mm_storeu_pd(&rn_data[i], _mm_sub_pd(b_r, r1));
            }
            for (i = tmp_size; i < loop_ub; i++) {
              rn_data[i] = obj->PositionLimitsInternal[i + 7] - rn_data[i];
            }
          } else {
            binary_expand_op_7(rn_data, &x_size, obj, loop_ub - 1);
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
    }
    if (guard1) {
      dv[0] = loop_ub;
      dv[1] = 1.0;
      b_st.site = &ls_emlrtRSI;
      x_size = randn(&b_st, dv, rn_data);
    }
    qv_size[0] = x_size;
    qv_size[1] = 1;
    if (x_size - 1 >= 0) {
      memcpy(&qv_data[0], &rn_data[0], (uint32_T)x_size * sizeof(real_T));
    }
  } break;
  }
}

rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(const emlrtStack *sp,
                                              rigidBodyJoint *obj,
                                              const char_T jname_data[],
                                              const int32_T jname_size[2])
{
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv1[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  emlrtStack b_st;
  emlrtStack st;
  rigidBodyJoint *b_obj;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T msubspace_size[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_obj = obj;
  b_obj->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    b_obj->JointToParentTransform[i] = i1;
    b_obj->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    b_obj->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    b_obj->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    b_obj->MotionSubspaceInternal[i] = 0.0;
  }
  st.site = &nb_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  if (jname_size[1] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rigidBodyJoint:expectedNonempty", 3, 4, 5, "jname");
  }
  st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  st.site = &ob_emlrtRSI;
  CharacterVector_setVector(&st, &s, jname_data, jname_size);
  b_obj->NameInternal = s;
  st.site = &w_emlrtRSI;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_obj->TypeInternal = s;
  st.site = &x_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    i = (int32_T)s.Length;
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
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    int8_T b_I[36];
    int8_T b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = 6;
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size[0] = 7;
    poslim_size[1] = 2;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      int8_T b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (int8_T)(10 * homepos_size_idx_1 - 5);
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
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size[0] = 1;
    poslim_size[1] = 2;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&st, b_obj, msubspace_data, msubspace_size);
  st.site = &ab_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    i = (int32_T)s.Length;
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
    real_T d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      ibmat = (int32_T)d;
    }
    msubspace_size[0] = ibmat;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &emlrtECI, (emlrtCTX)sp);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        b_obj->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      b_obj->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    msubspace_size[0] = 1;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &c_emlrtECI, (emlrtCTX)sp);
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/* End of code generation (rigidBodyJoint.c) */
