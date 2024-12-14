/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * inverseKinematics.c
 *
 * Code generation for function 'inverseKinematics'
 *
 */

/* Include files */
#include "inverseKinematics.h"
#include "CharacterVector.h"
#include "CollisionSet.h"
#include "DampedBFGSwGradientProjection.h"
#include "RigidBodyTree.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_mexutil.h"
#include "armvone_types.h"
#include "indexShapeCheck.h"
#include "norm.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "warning.h"
#include "emlrt.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sb_emlrtRSI = {
    216,                                   /* lineNo */
    "inverseKinematics/inverseKinematics", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    247,                                   /* lineNo */
    "inverseKinematics/inverseKinematics", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    259,                                   /* lineNo */
    "inverseKinematics/inverseKinematics", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    1,               /* lineNo */
    "System/System", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/System.p" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    1,                          /* lineNo */
    "SystemProp/setProperties", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemProp.p" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    462,                                     /* lineNo */
    "inverseKinematics/set.SolverAlgorithm", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    1,                                       /* lineNo */
    "NLPSolverInterface/NLPSolverInterface", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    70,                                                            /* lineNo */
    "DampedBFGSwGradientProjection/DampedBFGSwGradientProjection", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    112,                                                           /* lineNo */
    "DampedBFGSwGradientProjection/DampedBFGSwGradientProjection", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    113,                                                           /* lineNo */
    "DampedBFGSwGradientProjection/DampedBFGSwGradientProjection", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    42,                                      /* lineNo */
    "SystemTimeProvider/SystemTimeProvider", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/SystemTimeProvider.m" /* pathName */
};

static emlrtRSInfo fc_emlrtRSI = {
    1,                           /* lineNo */
    "TimeProvider/TimeProvider", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/TimeProvider.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    1,                                /* lineNo */
    "ProcessConstructorArguments/do", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/ProcessConstructorArguments.p" /* pathName */
};

static emlrtRSInfo hc_emlrtRSI = {
    485,                                   /* lineNo */
    "inverseKinematics/set.RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ic_emlrtRSI = {
    486,                                   /* lineNo */
    "inverseKinematics/set.RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    490,                                   /* lineNo */
    "inverseKinematics/set.RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    492,                                   /* lineNo */
    "inverseKinematics/set.RigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    10,                                   /* lineNo */
    "errorIfUnsupportedForFloatingJoint", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/errorIfUnsupportedForFloatingJoint.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    11,                                   /* lineNo */
    "errorIfUnsupportedForFloatingJoint", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/errorIfUnsupportedForFloatingJoint.m" /* pathName */
};

static emlrtRSInfo nc_emlrtRSI = {
    364,                  /* lineNo */
    "rigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "rigidBodyTree.m" /* pathName */
};

static emlrtRSInfo oc_emlrtRSI = {
    1455,                               /* lineNo */
    "rigidBodyTree/copyIntoDataFormat", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "rigidBodyTree.m" /* pathName */
};

static emlrtRSInfo pc_emlrtRSI = {
    1454,                               /* lineNo */
    "rigidBodyTree/copyIntoDataFormat", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "rigidBodyTree.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    566,                  /* lineNo */
    "RigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    567,                  /* lineNo */
    "RigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    572,                  /* lineNo */
    "RigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    585,                  /* lineNo */
    "RigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    571,                  /* lineNo */
    "RigidBodyTree/copy", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo cd_emlrtRSI = {
    2307,                         /* lineNo */
    "RigidBodyTree/get.BaseName", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ed_emlrtRSI = {
    2312,                         /* lineNo */
    "RigidBodyTree/set.BaseName", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo fd_emlrtRSI = {
    2315,                         /* lineNo */
    "RigidBodyTree/set.BaseName", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    2321,                         /* lineNo */
    "RigidBodyTree/set.BaseName", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo hd_emlrtRSI = {
    2323,                         /* lineNo */
    "RigidBodyTree/set.BaseName", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    2374,                        /* lineNo */
    "RigidBodyTree/set.Gravity", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo mf_emlrtRSI = {
    172,                           /* lineNo */
    "rigidBodyTree/rigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "rigidBodyTree.m" /* pathName */
};

static emlrtRSInfo nf_emlrtRSI = {
    182,                           /* lineNo */
    "rigidBodyTree/rigidBodyTree", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "rigidBodyTree.m" /* pathName */
};

static emlrtRSInfo hg_emlrtRSI = {
    162,                          /* lineNo */
    "inverseKinematics/stepImpl", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ig_emlrtRSI = {
    163,                          /* lineNo */
    "inverseKinematics/stepImpl", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo jg_emlrtRSI = {
    268,                             /* lineNo */
    "inverseKinematics/setPoseGoal", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo kg_emlrtRSI = {
    269,                             /* lineNo */
    "inverseKinematics/setPoseGoal", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo lg_emlrtRSI = {
    271,                             /* lineNo */
    "inverseKinematics/setPoseGoal", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    280,                             /* lineNo */
    "inverseKinematics/setPoseGoal", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    281,                             /* lineNo */
    "inverseKinematics/setPoseGoal", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    31,    /* lineNo */
    "inv", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/matfun/inv.m" /* pathName
                                                                           */
};

static emlrtRSInfo rg_emlrtRSI = {
    318,                       /* lineNo */
    "inverseKinematics/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo sg_emlrtRSI = {
    320,                       /* lineNo */
    "inverseKinematics/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    326,                       /* lineNo */
    "inverseKinematics/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    327,                       /* lineNo */
    "inverseKinematics/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    331,                       /* lineNo */
    "inverseKinematics/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pathName */
};

static emlrtRSInfo qh_emlrtRSI = {
    108,                        /* lineNo */
    "NLPSolverInterface/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    111,                        /* lineNo */
    "NLPSolverInterface/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    123,                        /* lineNo */
    "NLPSolverInterface/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    142,                        /* lineNo */
    "NLPSolverInterface/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo uh_emlrtRSI = {
    144,                        /* lineNo */
    "NLPSolverInterface/solve", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pathName */
};

static emlrtRSInfo wr_emlrtRSI = {
    53,                       /* lineNo */
    "IKHelpers/randomConfig", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/IKHelpers.m" /* pathName */
};

static emlrtRSInfo xr_emlrtRSI = {
    664,                                  /* lineNo */
    "RigidBodyTree/randomJointPositions", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo yr_emlrtRSI = {
    670,                                  /* lineNo */
    "RigidBodyTree/randomJointPositions", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo vs_emlrtRSI = {
    2060,                                /* lineNo */
    "RigidBodyTree/kinematicPathToBase", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo bt_emlrtRSI = {
    727,                                 /* lineNo */
    "RigidBodyTree/formatConfiguration", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ct_emlrtRSI = {
    734,                                 /* lineNo */
    "RigidBodyTree/formatConfiguration", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo dt_emlrtRSI = {
    736,                                 /* lineNo */
    "RigidBodyTree/formatConfiguration", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo et_emlrtRSI = {
    737,                                 /* lineNo */
    "RigidBodyTree/formatConfiguration", /* fcnName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pathName */
};

static emlrtBCInfo n_emlrtBCI = {
    0,                    /* iFirst */
    5,                    /* iLast */
    581,                  /* lineNo */
    45,                   /* colNo */
    "",                   /* aName */
    "RigidBodyTree/copy", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    581,                  /* lineNo */
    45,                   /* colNo */
    "RigidBodyTree/copy", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtDCInfo
    jb_emlrtDCI =
        {
            37,       /* lineNo */
            14,       /* colNo */
            "repmat", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/"
            "repmat.m", /* pName */
            4           /* checkKind */
};

static emlrtRTEInfo r_emlrtRTEI = {
    2425,                                             /* lineNo */
    13,                                               /* colNo */
    "RigidBodyTree/assertUpperBoundOnPositionNumber", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    -1,                                   /* nDims */
    671,                                  /* lineNo */
    21,                                   /* colNo */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    671,                                  /* lineNo */
    28,                                   /* colNo */
    "",                                   /* aName */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = {
    671,                                  /* lineNo */
    28,                                   /* colNo */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                                   /* iFirst */
    -1,                                   /* iLast */
    671,                                  /* lineNo */
    23,                                   /* colNo */
    "",                                   /* aName */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = {
    671,                                  /* lineNo */
    23,                                   /* colNo */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    1,                                    /* iFirst */
    6,                                    /* iLast */
    668,                                  /* lineNo */
    40,                                   /* colNo */
    "",                                   /* aName */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo s_emlrtRTEI = {
    667,                                  /* lineNo */
    21,                                   /* colNo */
    "RigidBodyTree/randomJointPositions", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtECInfo l_emlrtECI = {
    1,                                   /* nDims */
    737,                                 /* lineNo */
    25,                                  /* colNo */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    737,                                 /* lineNo */
    27,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    737,                                 /* lineNo */
    58,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = {
    737,                                 /* lineNo */
    58,                                  /* colNo */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    737,                                 /* lineNo */
    48,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = {
    737,                                 /* lineNo */
    48,                                  /* colNo */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    1,                                   /* iFirst */
    6,                                   /* iLast */
    735,                                 /* lineNo */
    53,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = {
    735,                                 /* lineNo */
    53,                                  /* colNo */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = {
    732,                                 /* lineNo */
    25,                                  /* colNo */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    2060,                                /* lineNo */
    38,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    2060,                                /* lineNo */
    36,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtECInfo m_emlrtECI = {
    -1,                         /* nDims */
    143,                        /* lineNo */
    17,                         /* colNo */
    "NLPSolverInterface/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pName */
};

static emlrtECInfo n_emlrtECI = {
    -1,                        /* nDims */
    329,                       /* lineNo */
    13,                        /* colNo */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtDCInfo pb_emlrtDCI = {
    326,                       /* lineNo */
    13,                        /* colNo */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = {
    326,                       /* lineNo */
    13,                        /* colNo */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    4                      /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    0,                                   /* iFirst */
    5,                                   /* iLast */
    2052,                                /* lineNo */
    35,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = {
    2052,                                /* lineNo */
    35,                                  /* colNo */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    2056,                                /* lineNo */
    29,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    0,                                   /* iFirst */
    5,                                   /* iLast */
    2057,                                /* lineNo */
    39,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtDCInfo sb_emlrtDCI = {
    2057,                                /* lineNo */
    39,                                  /* colNo */
    "RigidBodyTree/kinematicPathToBase", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    1                                   /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = {
    329,                       /* lineNo */
    19,                        /* colNo */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    1                      /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    329,                       /* lineNo */
    19,                        /* colNo */
    "",                        /* aName */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    329,                       /* lineNo */
    47,                        /* colNo */
    "",                        /* aName */
    "inverseKinematics/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m", /* pName */
    0                      /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = {
    142,                        /* lineNo */
    17,                         /* colNo */
    "NLPSolverInterface/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m", /* pName */
    1                                                 /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = {
    142,                        /* lineNo */
    17,                         /* colNo */
    "NLPSolverInterface/solve", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m", /* pName */
    4                                                 /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    0,                                   /* iFirst */
    5,                                   /* iLast */
    733,                                 /* lineNo */
    39,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    736,                                 /* lineNo */
    25,                                  /* colNo */
    "",                                  /* aName */
    "RigidBodyTree/formatConfiguration", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m", /* pName */
    0                                   /* checkKind */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    104,                  /* lineNo */
    13,                   /* colNo */
    "NLPSolverInterface", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    326,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    329,                 /* lineNo */
    19,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    143,                  /* lineNo */
    17,                   /* colNo */
    "NLPSolverInterface", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    148,                  /* lineNo */
    21,                   /* colNo */
    "NLPSolverInterface", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pName */
};

static emlrtRTEInfo
    tc_emlrtRTEI =
        {
            59,       /* lineNo */
            13,       /* colNo */
            "repmat", /* fName */
            "/home/ayush/Applications/matlab/toolbox/eml/lib/matlab/elmat/"
            "repmat.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    318,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    327,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    329,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    115,                  /* lineNo */
    13,                   /* colNo */
    "NLPSolverInterface", /* fName */
    "/home/ayush/Applications/matlab/toolbox/shared/robotics/robotutils/"
    "+robotics/+core/+internal/NLPSolverInterface.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    331,                 /* lineNo */
    20,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

static emlrtRTEInfo ii_emlrtRTEI = {
    727,             /* lineNo */
    17,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/+robotics/"
    "+manip/+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = {
    331,                 /* lineNo */
    13,                  /* colNo */
    "inverseKinematics", /* fName */
    "/home/ayush/Applications/matlab/toolbox/robotics/robotmanip/"
    "inverseKinematics.m" /* pName */
};

/* Function Declarations */
static void b_cast(const emlrtStack *sp, const b_emxArray_struct_T *r2,
                   emxArray_struct_T *r3);

static void cast(const emlrtStack *sp, const c_emxArray_struct_T *r2,
                 b_emxArray_struct_T *r3);

static void inverseKinematics_setPoseGoal(const emlrtStack *sp,
                                          inverseKinematics *obj,
                                          const real_T tform[16]);

/* Function Definitions */
static void b_cast(const emlrtStack *sp, const b_emxArray_struct_T *r2,
                   emxArray_struct_T *r3)
{
  const c_struct_T *r;
  struct_T *r1;
  int32_T i;
  int32_T i1;
  int32_T i2;
  r = r2->data;
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  i1 = r2->size[1];
  r3->size[1] = r2->size[1];
  emxEnsureCapacity_struct_T2(sp, r3, i, &ji_emlrtRTEI);
  r1 = r3->data;
  for (i = 0; i < i1; i++) {
    int32_T loop_ub;
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
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

static void cast(const emlrtStack *sp, const c_emxArray_struct_T *r2,
                 b_emxArray_struct_T *r3)
{
  c_struct_T *r1;
  const d_struct_T *r;
  int32_T i;
  int32_T i1;
  r = r2->data;
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  i1 = r2->size[1];
  r3->size[1] = r2->size[1];
  emxEnsureCapacity_struct_T1(sp, r3, i, &ii_emlrtRTEI);
  r1 = r3->data;
  for (i = 0; i < i1; i++) {
    r1[i].JointName.size[0] = 1;
    r1[i].JointName.size[1] = 0;
    r1[i].JointPosition.size[0] = 1;
    r1[i].JointPosition.size[1] = 1;
    r1[i].JointPosition.data[0] = r[i].JointPosition;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

static void inverseKinematics_setPoseGoal(const emlrtStack *sp,
                                          inverseKinematics *obj,
                                          const real_T tform[16])
{
  static const int32_T b_iv[2] = {1, 6};
  static const char_T rfmt[6] = {'%', '1', '4', '.', '6', 'e'};
  static const char_T b[5] = {'p', 'i', 't', 'c', 'h'};
  static const char_T b_cv[5] = {'p', 'i', 't', 'c', 'h'};
  static const int8_T iv1[6] = {0, 0, 0, 1, 1, 0};
  c_robotics_manip_internal_IKExt *args;
  c_robotics_manip_internal_Rigid *c_obj;
  e_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  real_T x[9];
  real_T y[9];
  real_T maxval[3];
  real_T absx11;
  real_T absx21;
  real_T absx31;
  int32_T bidx;
  int32_T exitg1;
  int32_T p1;
  int32_T p2;
  int32_T p3;
  char_T obj_Vector[200];
  int8_T weightMatrix[36];
  boolean_T b_bool;
  boolean_T exitg2;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_obj = obj->RigidBodyTreeInternal;
  b_st.site = &cd_emlrtRSI;
  c_st.site = &dd_emlrtRSI;
  absx11 = b_obj->Base.NameInternal.Length;
  for (p3 = 0; p3 < 200; p3++) {
    obj_Vector[p3] = b_obj->Base.NameInternal.Vector[p3];
  }
  if (absx11 < 1.0) {
    p3 = 0;
  } else {
    if (absx11 != (int32_T)muDoubleScalarFloor(absx11)) {
      emlrtIntegerCheckR2012b(absx11, &c_emlrtDCI, &c_st);
    }
    if (((int32_T)absx11 < 1) || ((int32_T)absx11 > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)absx11, 1, 200, &i_emlrtBCI,
                                    &c_st);
    }
    p3 = (int32_T)absx11;
  }
  b_bool = false;
  if (p3 == 5) {
    p1 = 0;
    do {
      exitg1 = 0;
      if (p1 < 5) {
        if (obj_Vector[p1] != b_cv[p1]) {
          exitg1 = 1;
        } else {
          p1++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (b_bool) {
    st.site = &kg_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI,
        "robotics:robotmanip:inversekinematics:EndEffectorIsBase",
        "robotics:robotmanip:inversekinematics:EndEffectorIsBase", 0);
  }
  st.site = &lg_emlrtRSI;
  b_obj = obj->RigidBodyTreeInternal;
  b_st.site = &fe_emlrtRSI;
  bidx = -1;
  c_st.site = &jd_emlrtRSI;
  d_st.site = &dd_emlrtRSI;
  absx11 = b_obj->Base.NameInternal.Length;
  for (p3 = 0; p3 < 200; p3++) {
    obj_Vector[p3] = b_obj->Base.NameInternal.Vector[p3];
  }
  if (absx11 < 1.0) {
    p3 = 0;
  } else {
    if (absx11 != (int32_T)muDoubleScalarFloor(absx11)) {
      emlrtIntegerCheckR2012b(absx11, &c_emlrtDCI, &d_st);
    }
    if (((int32_T)absx11 < 1) || ((int32_T)absx11 > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)absx11, 1, 200, &i_emlrtBCI,
                                    &d_st);
    }
    p3 = (int32_T)absx11;
  }
  b_bool = false;
  if (p3 == 5) {
    p1 = 0;
    do {
      exitg1 = 0;
      if (p1 < 5) {
        if (obj_Vector[p1] != b_cv[p1]) {
          exitg1 = 1;
        } else {
          p1++;
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
    absx21 = b_obj->NumBodies;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, absx21, mxDOUBLE_CLASS,
                                  (int32_T)absx21, &g_emlrtRTEI, &b_st);
    p2 = 0;
    exitg2 = false;
    while ((!exitg2) && (p2 <= (int32_T)absx21 - 1)) {
      c_st.site = &kd_emlrtRSI;
      if (p2 > 5) {
        emlrtDynamicBoundsCheckR2012b(6, 0, 5, &o_emlrtBCI, &c_st);
      }
      c_obj = b_obj->Bodies[p2];
      d_st.site = &dd_emlrtRSI;
      absx11 = c_obj->NameInternal.Length;
      for (p3 = 0; p3 < 200; p3++) {
        obj_Vector[p3] = c_obj->NameInternal.Vector[p3];
      }
      if (absx11 < 1.0) {
        p3 = 0;
      } else {
        if (absx11 != (int32_T)muDoubleScalarFloor(absx11)) {
          emlrtIntegerCheckR2012b(absx11, &c_emlrtDCI, &d_st);
        }
        if (((int32_T)absx11 < 1) || ((int32_T)absx11 > 200)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)absx11, 1, 200, &i_emlrtBCI,
                                        &d_st);
        }
        p3 = (int32_T)absx11;
      }
      b_bool = false;
      if (p3 == 5) {
        p1 = 0;
        do {
          exitg1 = 0;
          if (p1 < 5) {
            if (obj_Vector[p1] != b_cv[p1]) {
              exitg1 = 1;
            } else {
              p1++;
            }
          } else {
            b_bool = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (b_bool) {
        bidx = p2 + 1;
        exitg2 = true;
      } else {
        p2++;
      }
    }
  }
  if (bidx == -1) {
    b_st.site = &ge_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "robotics:robotmanip:rigidbodytree:BodyNotFound",
        "robotics:robotmanip:rigidbodytree:BodyNotFound", 3, 4, 5, &b[0]);
  }
  st.site = &mg_emlrtRSI;
  for (p3 = 0; p3 < 3; p3++) {
    p1 = p3 << 2;
    x[3 * p3] = tform[p1];
    x[3 * p3 + 1] = tform[p1 + 1];
    x[3 * p3 + 2] = tform[p1 + 2];
  }
  p1 = 0;
  p2 = 3;
  p3 = 6;
  absx11 = muDoubleScalarAbs(tform[0]);
  absx21 = muDoubleScalarAbs(tform[1]);
  absx31 = muDoubleScalarAbs(tform[2]);
  if ((absx21 > absx11) && (absx21 > absx31)) {
    p1 = 3;
    p2 = 0;
    x[0] = tform[1];
    x[1] = tform[0];
    x[3] = tform[5];
    x[4] = tform[4];
    x[6] = tform[9];
    x[7] = tform[8];
  } else if (absx31 > absx11) {
    p1 = 6;
    p3 = 0;
    x[0] = tform[2];
    x[2] = tform[0];
    x[3] = tform[6];
    x[5] = tform[4];
    x[6] = tform[10];
    x[8] = tform[8];
  }
  x[1] /= x[0];
  x[2] /= x[0];
  x[4] -= x[1] * x[3];
  x[5] -= x[2] * x[3];
  x[7] -= x[1] * x[6];
  x[8] -= x[2] * x[6];
  if (muDoubleScalarAbs(x[5]) > muDoubleScalarAbs(x[4])) {
    int32_T itmp;
    itmp = p2;
    p2 = p3;
    p3 = itmp;
    absx11 = x[1];
    x[1] = x[2];
    x[2] = absx11;
    absx11 = x[4];
    x[4] = x[5];
    x[5] = absx11;
    absx11 = x[7];
    x[7] = x[8];
    x[8] = absx11;
  }
  x[5] /= x[4];
  x[8] -= x[5] * x[7];
  absx11 = (x[1] * x[5] - x[2]) / x[8];
  absx21 = -(x[1] + x[7] * absx11) / x[4];
  y[p1] = ((1.0 - x[3] * absx21) - x[6] * absx11) / x[0];
  y[p1 + 1] = absx21;
  y[p1 + 2] = absx11;
  absx11 = -x[5] / x[8];
  absx21 = (1.0 - x[7] * absx11) / x[4];
  y[p2] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p2 + 1] = absx21;
  y[p2 + 2] = absx11;
  absx11 = 1.0 / x[8];
  absx21 = -x[7] * absx11 / x[4];
  y[p3] = -(x[3] * absx21 + x[6] * absx11) / x[0];
  y[p3 + 1] = absx21;
  y[p3 + 2] = absx11;
  b_st.site = &og_emlrtRSI;
  for (p3 = 0; p3 < 3; p3++) {
    p1 = p3 << 2;
    x[3 * p3] = tform[p1];
    x[3 * p3 + 1] = tform[p1 + 1];
    x[3 * p3 + 2] = tform[p1 + 2];
  }
  absx11 = b_norm(x);
  absx21 = b_norm(y);
  absx31 = 1.0 / (absx11 * absx21);
  if ((absx11 == 0.0) || (absx21 == 0.0) || (absx31 == 0.0)) {
    c_st.site = &pg_emlrtRSI;
    b_warning(&c_st);
  } else if (muDoubleScalarIsNaN(absx31) || (absx31 < 2.2204460492503131E-16)) {
    char_T str[14];
    c_st.site = &qg_emlrtRSI;
    b_y = NULL;
    m = emlrtCreateCharArray(2, &b_iv[0]);
    emlrtInitCharArrayR2013a(&c_st, 6, m, &rfmt[0]);
    emlrtAssign(&b_y, m);
    c_y = NULL;
    m = emlrtCreateDoubleScalar(absx31);
    emlrtAssign(&c_y, m);
    d_st.site = &jt_emlrtRSI;
    emlrt_marshallIn(&d_st, b_sprintf(&d_st, b_y, c_y, &c_emlrtMCI),
                     "<output of sprintf>", str);
    c_st.site = &qg_emlrtRSI;
    c_warning(&c_st, str);
  }
  for (p3 = 0; p3 < 3; p3++) {
    x[3 * p3] = y[3 * p3] - tform[p3];
    p1 = 3 * p3 + 1;
    x[p1] = y[p1] - tform[p3 + 4];
    p1 = 3 * p3 + 2;
    x[p1] = y[p1] - tform[p3 + 8];
  }
  for (p2 = 0; p2 < 9; p2++) {
    y[p2] = muDoubleScalarAbs(x[p2]);
  }
  for (p1 = 0; p1 < 3; p1++) {
    maxval[p1] = y[3 * p1];
    for (p2 = 0; p2 < 2; p2++) {
      absx21 = y[(p2 + 3 * p1) + 1];
      if (muDoubleScalarIsNaN(absx21)) {
        b_bool = false;
      } else {
        absx11 = maxval[p1];
        if (muDoubleScalarIsNaN(absx11)) {
          b_bool = true;
        } else {
          b_bool = (absx11 < absx21);
        }
      }
      if (b_bool) {
        maxval[p1] = absx21;
      }
    }
  }
  if (!muDoubleScalarIsNaN(maxval[0])) {
    p1 = 1;
  } else {
    p1 = 0;
    p2 = 2;
    exitg2 = false;
    while ((!exitg2) && (p2 < 4)) {
      if (!muDoubleScalarIsNaN(maxval[p2 - 1])) {
        p1 = p2;
        exitg2 = true;
      } else {
        p2++;
      }
    }
  }
  if (p1 == 0) {
    absx11 = maxval[0];
  } else {
    absx11 = maxval[p1 - 1];
    p3 = p1 + 1;
    for (p2 = p3; p2 < 4; p2++) {
      absx21 = maxval[p2 - 1];
      if (absx11 < absx21) {
        absx11 = absx21;
      }
    }
  }
  guard1 = false;
  if (absx11 > 0.0001) {
    guard1 = true;
  } else {
    real_T d_y;
    absx11 = 3.3121686421112381E-170;
    absx21 = muDoubleScalarAbs(tform[3]);
    if (absx21 > 3.3121686421112381E-170) {
      d_y = 1.0;
      absx11 = absx21;
    } else {
      absx31 = absx21 / 3.3121686421112381E-170;
      d_y = absx31 * absx31;
    }
    absx21 = muDoubleScalarAbs(tform[7]);
    if (absx21 > absx11) {
      absx31 = absx11 / absx21;
      d_y = d_y * absx31 * absx31 + 1.0;
      absx11 = absx21;
    } else {
      absx31 = absx21 / absx11;
      d_y += absx31 * absx31;
    }
    absx21 = muDoubleScalarAbs(tform[11]);
    if (absx21 > absx11) {
      absx31 = absx11 / absx21;
      d_y = d_y * absx31 * absx31 + 1.0;
      absx11 = absx21;
    } else {
      absx31 = absx21 / absx11;
      d_y += absx31 * absx31;
    }
    absx21 = muDoubleScalarAbs(tform[15] - 1.0);
    if (absx21 > absx11) {
      absx31 = absx11 / absx21;
      d_y = d_y * absx31 * absx31 + 1.0;
      absx11 = absx21;
    } else {
      absx31 = absx21 / absx11;
      d_y += absx31 * absx31;
    }
    d_y = absx11 * muDoubleScalarSqrt(d_y);
    if (d_y > 1.0E-7) {
      guard1 = true;
    }
  }
  if (guard1) {
    st.site = &ng_emlrtRSI;
    b_st.site = &lf_emlrtRSI;
    d_warning(&b_st);
  }
  for (p3 = 0; p3 < 36; p3++) {
    weightMatrix[p3] = 0;
  }
  for (p1 = 0; p1 < 6; p1++) {
    weightMatrix[p1 + 6 * p1] = iv1[p1];
  }
  args = obj->Solver->ExtraArgs;
  for (p3 = 0; p3 < 36; p3++) {
    args->WeightMatrix[p3] = weightMatrix[p3];
  }
  args->BodyIndex = bidx;
  args->KinematicModel = obj->RigidBodyTreeKinematicModel;
  for (p3 = 0; p3 < 16; p3++) {
    args->Tform[p3] = tform[p3];
  }
}

inverseKinematics *c_inverseKinematics_inverseKine(const emlrtStack *sp,
                                                   inverseKinematics *obj,
                                                   b_rigidBodyTree *varargin_2)
{
  static const char_T varargin_1[17] = {'i', 'n', 'v', 'e', 'r', 's',
                                        'e', 'K', 'i', 'n', 'e', 'm',
                                        'a', 't', 'i', 'c', 's'};
  c_robotics_manip_internal_Chara d_obj;
  c_robotics_manip_internal_Rigid *body;
  c_robotics_manip_internal_Rigid *parent;
  d_robotics_manip_internal_Rigid *c_obj;
  e_robotics_manip_internal_Rigid *newRobotInternal;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  inverseKinematics *b_obj;
  real_T g[3];
  real_T bid;
  int32_T basename_size[2];
  int32_T loop_ub;
  char_T basename_data[200];
  boolean_T exitg1;
  boolean_T hasjoint;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  b_obj = obj;
  st.site = &sb_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  c_st.site = &wb_emlrtRSI;
  b_st.site = &vb_emlrtRSI;
  c_st.site = &xb_emlrtRSI;
  b_obj->isInitialized = 0;
  st.site = &sb_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &tb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  c_st.site = &bc_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
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
  c_st.site = &cc_emlrtRSI;
  d_st.site = &ec_emlrtRSI;
  e_st.site = &fc_emlrtRSI;
  b_obj->_pobj6.TimeObj.StartTime.tv_sec = 0.0;
  b_obj->_pobj6.TimeObj.StartTime.tv_nsec = 0.0;
  c_st.site = &dc_emlrtRSI;
  d_st.site = &ec_emlrtRSI;
  e_st.site = &fc_emlrtRSI;
  b_obj->_pobj6.TimeObjInternal.StartTime.tv_sec = 0.0;
  b_obj->_pobj6.TimeObjInternal.StartTime.tv_nsec = 0.0;
  b_obj->_pobj6.matlabCodegenIsDeleted = false;
  b_obj->Solver = &b_obj->_pobj6;
  st.site = &ub_emlrtRSI;
  b_st.site = &wb_emlrtRSI;
  c_st.site = &gc_emlrtRSI;
  d_st.site = &gc_emlrtRSI;
  e_st.site = &hc_emlrtRSI;
  bid = varargin_2->TreeInternal->NumNonFixedBodies;
  if (bid == 0.0) {
    e_st.site = &ic_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &e_st, &c_emlrtRTEI,
        "robotics:robotmanip:inversekinematics:RigidBodyTreeFixed",
        "robotics:robotmanip:inversekinematics:RigidBodyTreeFixed", 0);
  }
  e_st.site = &jc_emlrtRSI;
  f_st.site = &lc_emlrtRSI;
  hasjoint = (varargin_2->TreeInternal->VelocityNumber !=
              varargin_2->TreeInternal->PositionNumber);
  if (hasjoint) {
    f_st.site = &mc_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI,
                                  "robotics:robotmanip:rigidbodytree:"
                                  "FunctionNotSupportedForFloatingJoint",
                                  "robotics:robotmanip:rigidbodytree:"
                                  "FunctionNotSupportedForFloatingJoint",
                                  3, 4, 17, &varargin_1[0]);
  }
  e_st.site = &kc_emlrtRSI;
  f_st.site = &nc_emlrtRSI;
  g_st.site = &pc_emlrtRSI;
  c_obj = varargin_2->TreeInternal;
  h_st.site = &qc_emlrtRSI;
  newRobotInternal = RigidBodyTree_RigidBodyTree(&h_st, &b_obj->_pobj4);
  h_st.site = &rc_emlrtRSI;
  i_st.site = &cd_emlrtRSI;
  j_st.site = &dd_emlrtRSI;
  d_obj = c_obj->Base.NameInternal;
  if (d_obj.Length < 1.0) {
    loop_ub = 0;
  } else {
    if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
      emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &j_st);
    }
    if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200, &i_emlrtBCI,
                                    &j_st);
    }
    loop_ub = (int32_T)d_obj.Length;
  }
  basename_size[0] = 1;
  basename_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&basename_data[0], &d_obj.Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  h_st.site = &rc_emlrtRSI;
  i_st.site = &ed_emlrtRSI;
  j_st.site = &pb_emlrtRSI;
  if (loop_ub == 0) {
    emlrtErrorWithMessageIdR2018a(
        &j_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rigidBodyTree:expectedNonempty", 3, 4, 8, "baseName");
  }
  i_st.site = &fd_emlrtRSI;
  bid = c_RigidBodyTree_findBodyIndexBy(&i_st, newRobotInternal, basename_data,
                                        basename_size);
  if (!(bid == 0.0)) {
    if (bid < 0.0) {
      d_obj = newRobotInternal->Base.NameInternal;
      i_st.site = &gd_emlrtRSI;
      CharacterVector_setVector(&i_st, &d_obj, basename_data, basename_size);
      newRobotInternal->Base.NameInternal = d_obj;
    } else {
      i_st.site = &hd_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &i_st, &d_emlrtRTEI,
          "robotics:robotmanip:rigidbodytree:BaseNameCollision",
          "robotics:robotmanip:rigidbodytree:BaseNameCollision", 3, 4, loop_ub,
          &basename_data[0]);
    }
  }
  h_st.site = &uc_emlrtRSI;
  newRobotInternal->Base.CollisionsInternal = CollisionSet_copy(
      &h_st, c_obj->Base.CollisionsInternal, &b_obj->_pobj3[0]);
  h_st.site = &sc_emlrtRSI;
  g[0] = c_obj->Gravity[0];
  g[1] = c_obj->Gravity[1];
  g[2] = c_obj->Gravity[2];
  i_st.site = &sd_emlrtRSI;
  j_st.site = &pb_emlrtRSI;
  hasjoint = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 3)) {
    if (!muDoubleScalarIsNaN(g[loop_ub])) {
      loop_ub++;
    } else {
      hasjoint = false;
      exitg1 = true;
    }
  }
  if (!hasjoint) {
    emlrtErrorWithMessageIdR2018a(
        &j_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:rigidBodyTree:expectedNonNaN", 3, 4, 7, "Gravity");
  }
  j_st.site = &pb_emlrtRSI;
  hasjoint = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 3)) {
    if ((!muDoubleScalarIsInf(g[loop_ub])) &&
        (!muDoubleScalarIsNaN(g[loop_ub]))) {
      loop_ub++;
    } else {
      hasjoint = false;
      exitg1 = true;
    }
  }
  if (!hasjoint) {
    emlrtErrorWithMessageIdR2018a(
        &j_st, &f_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:rigidBodyTree:expectedFinite", 3, 4, 7, "Gravity");
  }
  if (c_obj->NumBodies >= 1.0) {
    body = c_obj->Bodies[0];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[1], &b_obj->_pobj1[0],
                          &b_obj->_pobj2[0]);
  }
  if (c_obj->NumBodies >= 2.0) {
    body = c_obj->Bodies[1];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[3], &b_obj->_pobj1[2],
                          &b_obj->_pobj2[1]);
  }
  if (c_obj->NumBodies >= 3.0) {
    body = c_obj->Bodies[2];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[5], &b_obj->_pobj1[4],
                          &b_obj->_pobj2[2]);
  }
  if (c_obj->NumBodies >= 4.0) {
    body = c_obj->Bodies[3];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[7], &b_obj->_pobj1[6],
                          &b_obj->_pobj2[3]);
  }
  if (c_obj->NumBodies >= 5.0) {
    body = c_obj->Bodies[4];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[9], &b_obj->_pobj1[8],
                          &b_obj->_pobj2[4]);
  }
  if (c_obj->NumBodies >= 6.0) {
    body = c_obj->Bodies[5];
    bid = body->ParentIndex;
    if (bid > 0.0) {
      if (bid != (int32_T)muDoubleScalarFloor(bid)) {
        emlrtIntegerCheckR2012b(bid, &h_emlrtDCI, &g_st);
      }
      if (((int32_T)bid - 1 < 0) || ((int32_T)bid - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid - 1, 0, 5, &n_emlrtBCI,
                                      &g_st);
      }
      parent = c_obj->Bodies[(int32_T)bid - 1];
    } else {
      parent = &c_obj->Base;
    }
    h_st.site = &tc_emlrtRSI;
    i_st.site = &dd_emlrtRSI;
    d_obj = parent->NameInternal;
    if (d_obj.Length < 1.0) {
      loop_ub = 0;
    } else {
      if (d_obj.Length != (int32_T)muDoubleScalarFloor(d_obj.Length)) {
        emlrtIntegerCheckR2012b(d_obj.Length, &c_emlrtDCI, &i_st);
      }
      if (((int32_T)d_obj.Length < 1) || ((int32_T)d_obj.Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_obj.Length, 1, 200,
                                      &i_emlrtBCI, &i_st);
      }
      loop_ub = (int32_T)d_obj.Length;
    }
    basename_size[0] = 1;
    basename_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&basename_data[0], &d_obj.Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    h_st.site = &tc_emlrtRSI;
    RigidBodyTree_addBody(&h_st, newRobotInternal, body, basename_data,
                          basename_size, &b_obj->_pobj3[11], &b_obj->_pobj1[10],
                          &b_obj->_pobj2[5]);
  }
  g_st.site = &oc_emlrtRSI;
  h_st.site = &qb_emlrtRSI;
  i_st.site = &f_emlrtRSI;
  h_st.site = &mf_emlrtRSI;
  b_obj->_pobj5.TreeInternal =
      RigidBodyTree_RigidBodyTree(&h_st, &b_obj->_pobj5._pobj1);
  h_st.site = &nf_emlrtRSI;
  b_obj->_pobj5.TreeInternal->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&h_st, &b_obj->_pobj5._pobj0, 10.0);
  b_obj->_pobj5.matlabCodegenIsDeleted = false;
  b_obj->_pobj5.TreeInternal = newRobotInternal;
  b_obj->RigidBodyTreeInternal = b_obj->_pobj5.TreeInternal;
  b_obj->RigidBodyTreeKinematicModel = 0.0;
  b_obj->RigidBodyTreeKinematicModel = 0.0;
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void inverseKinematics_stepImpl(const emlrtStack *sp, inverseKinematics *obj,
                                const real_T tform[16],
                                const b_struct_T initialGuess[6],
                                emxArray_struct_T *QSol)
{
  static const d_struct_T r4 = {
      0.0 /* JointPosition */
  };
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  b_emxArray_struct_T *Q;
  c_emxArray_struct_T *r2;
  c_robotics_core_internal_Damped *c_obj;
  c_robotics_manip_internal_IKExt *args;
  c_robotics_manip_internal_Rigid *body;
  c_struct_T *Q_data;
  d_struct_T *r3;
  e_robotics_manip_internal_Rigid *d_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_int32_T *r;
  emxArray_real_T *bodyIndices;
  emxArray_real_T *iniGuessVec;
  emxArray_real_T *positionIndices;
  emxArray_real_T *xSolPrev;
  inverseKinematics *b_obj;
  rigidBodyJoint *e_obj;
  real_T qi_data[49];
  real_T newseed_data[42];
  real_T err;
  real_T errPrev;
  real_T iter;
  real_T p_idx_1;
  real_T tol;
  real_T *bodyIndices_data;
  real_T *iniGuessVec_data;
  real_T *xSolPrev_data;
  int32_T qi_size[2];
  int32_T b_loop_ub;
  int32_T c_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T newseed_size_tmp;
  int32_T *r1;
  uint32_T b_i;
  boolean_T exitg1;
  boolean_T valid;
  c_robotics_core_internal_NLPSol exitFlag;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &hg_emlrtRSI;
  inverseKinematics_setPoseGoal(&st, obj, tform);
  st.site = &ig_emlrtRSI;
  b_obj = obj;
  emxInit_real_T(&st, &iniGuessVec, 1, &uc_emlrtRTEI);
  b_st.site = &rg_emlrtRSI;
  c_RigidBodyTree_validateConfigu(&b_st, obj->RigidBodyTreeInternal,
                                  initialGuess, iniGuessVec);
  iniGuessVec_data = iniGuessVec->data;
  b_st.site = &sg_emlrtRSI;
  c_obj = obj->Solver;
  c_obj->MaxNumIterationInternal = c_obj->MaxNumIteration;
  c_obj->MaxTimeInternal = c_obj->MaxTime;
  loop_ub = iniGuessVec->size[0];
  i = c_obj->SeedInternal->size[0];
  c_obj->SeedInternal->size[0] = iniGuessVec->size[0];
  emxEnsureCapacity_real_T(&b_st, c_obj->SeedInternal, i, &oc_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_obj->SeedInternal->data[i] = iniGuessVec_data[i];
  }
  tol = c_obj->SolutionTolerance;
  c_st.site = &qh_emlrtRSI;
  d_st.site = &vh_emlrtRSI;
  c_obj->TimeObj.StartTime = tic(&d_st);
  d_st.site = &wh_emlrtRSI;
  emxInit_real_T(&b_st, &xSolPrev, 1, &xc_emlrtRTEI);
  c_st.site = &rh_emlrtRSI;
  exitFlag =
      c_DampedBFGSwGradientProjection(&c_st, c_obj, xSolPrev, &err, &iter);
  xSolPrev_data = xSolPrev->data;
  errPrev = err;
  emxInit_real_T(&b_st, &bodyIndices, 1, &pc_emlrtRTEI);
  exitg1 = false;
  while ((!exitg1) && (c_obj->RandomRestart && (err > tol))) {
    c_obj->MaxNumIterationInternal -= iter;
    c_st.site = &sh_emlrtRSI;
    d_st.site = &ro_emlrtRSI;
    valid = (c_obj->TimeObj.StartTime.tv_sec > 0.0);
    if (!valid) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &t_emlrtRTEI,
          "shared_robotics:robotutils:timeprovider:TimeProviderNotInitialized",
          "shared_robotics:robotutils:timeprovider:TimeProviderNotInitialized",
          0);
    }
    d_st.site = &so_emlrtRSI;
    iter = toc(&d_st, c_obj->TimeObj.StartTime.tv_sec,
               c_obj->TimeObj.StartTime.tv_nsec);
    c_obj->MaxTimeInternal = c_obj->MaxTime - iter;
    if (c_obj->MaxNumIterationInternal <= 0.0) {
      exitFlag = IterationLimitExceeded;
    }
    if ((exitFlag == IterationLimitExceeded) ||
        (exitFlag == TimeLimitExceeded)) {
      exitg1 = true;
    } else {
      c_st.site = &th_emlrtRSI;
      args = c_obj->ExtraArgs;
      d_st.site = &wr_emlrtRSI;
      d_obj = args->Robot;
      e_st.site = &xr_emlrtRSI;
      iter = d_obj->PositionNumber;
      if (!(iter <= 42.0)) {
        emlrtErrorWithMessageIdR2018a(&e_st, &r_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      if (!(iter >= 0.0)) {
        emlrtNonNegativeCheckR2012b(iter, &vb_emlrtDCI, &d_st);
      }
      err = muDoubleScalarFloor(iter);
      if (iter != err) {
        emlrtIntegerCheckR2012b(iter, &ub_emlrtDCI, &d_st);
      }
      newseed_size_tmp = (int32_T)iter;
      if (iter != err) {
        emlrtIntegerCheckR2012b(iter, &ub_emlrtDCI, &d_st);
      }
      if (newseed_size_tmp - 1 >= 0) {
        memset(&newseed_data[0], 0,
               (uint32_T)newseed_size_tmp * sizeof(real_T));
      }
      err = d_obj->NumBodies;
      i = (int32_T)err;
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, err, mxDOUBLE_CLASS, (int32_T)err,
                                    &s_emlrtRTEI, &d_st);
      for (c_i = 0; c_i < i; c_i++) {
        if (((int32_T)((uint32_T)c_i + 1U) < 1) ||
            ((int32_T)((uint32_T)c_i + 1U) > 6)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1, 6,
                                        &tb_emlrtBCI, &d_st);
        }
        err = d_obj->PositionDoFMap[c_i];
        p_idx_1 = d_obj->PositionDoFMap[c_i + 6];
        if (err <= p_idx_1) {
          e_st.site = &yr_emlrtRSI;
          rigidBodyJoint_randomPosition(
              &e_st, d_obj->Bodies[c_i]->JointInternal, qi_data, qi_size);
          if (err > p_idx_1) {
            i1 = 0;
            i2 = 0;
          } else {
            if (err != (int32_T)muDoubleScalarFloor(err)) {
              emlrtIntegerCheckR2012b(err, &lb_emlrtDCI, &d_st);
            }
            if (((int32_T)err < 1) || ((int32_T)err > (int32_T)iter)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)err, 1, (int32_T)iter,
                                            &sb_emlrtBCI, &d_st);
            }
            i1 = (int32_T)err - 1;
            if (p_idx_1 != (int32_T)muDoubleScalarFloor(p_idx_1)) {
              emlrtIntegerCheckR2012b(p_idx_1, &kb_emlrtDCI, &d_st);
            }
            if (((int32_T)p_idx_1 < 1) || ((int32_T)p_idx_1 > (int32_T)iter)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)p_idx_1, 1, (int32_T)iter,
                                            &rb_emlrtBCI, &d_st);
            }
            i2 = (int32_T)p_idx_1;
          }
          b_loop_ub = i2 - i1;
          i2 = qi_size[0] * qi_size[1];
          if (b_loop_ub != i2) {
            emlrtSubAssignSizeCheck1dR2017a(b_loop_ub, i2, &k_emlrtECI, &d_st);
          }
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            newseed_data[i1 + i2] = qi_data[i2];
          }
        }
      }
      i = c_obj->SeedInternal->size[0];
      if (i != (int32_T)iter) {
        emlrtSubAssignSizeCheck1dR2017a(i, (int32_T)iter, &m_emlrtECI, &b_st);
      }
      i = c_obj->SeedInternal->size[0];
      c_obj->SeedInternal->size[0] = (int32_T)iter;
      emxEnsureCapacity_real_T(&b_st, c_obj->SeedInternal, i, &rc_emlrtRTEI);
      for (i = 0; i < newseed_size_tmp; i++) {
        c_obj->SeedInternal->data[i] = newseed_data[i];
      }
      c_st.site = &uh_emlrtRSI;
      exitFlag = c_DampedBFGSwGradientProjection(&c_st, c_obj, bodyIndices,
                                                 &err, &iter);
      bodyIndices_data = bodyIndices->data;
      if (err < errPrev) {
        b_loop_ub = bodyIndices->size[0];
        i = xSolPrev->size[0];
        xSolPrev->size[0] = bodyIndices->size[0];
        emxEnsureCapacity_real_T(&b_st, xSolPrev, i, &sc_emlrtRTEI);
        xSolPrev_data = xSolPrev->data;
        for (i = 0; i < b_loop_ub; i++) {
          xSolPrev_data[i] = bodyIndices_data[i];
        }
        errPrev = err;
      }
    }
  }
  b_st.site = &tg_emlrtRSI;
  d_obj = b_obj->RigidBodyTreeInternal;
  iter = b_obj->Solver->ExtraArgs->BodyIndex;
  if (!(d_obj->NumBodies >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d_obj->NumBodies, &qb_emlrtDCI, &b_st);
  }
  err = d_obj->NumBodies;
  if (err != (int32_T)muDoubleScalarFloor(err)) {
    emlrtIntegerCheckR2012b(err, &pb_emlrtDCI, &b_st);
  }
  i = bodyIndices->size[0];
  bodyIndices->size[0] = (int32_T)err;
  emxEnsureCapacity_real_T(&b_st, bodyIndices, i, &pc_emlrtRTEI);
  bodyIndices_data = bodyIndices->data;
  if (!(d_obj->NumBodies >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d_obj->NumBodies, &qb_emlrtDCI, &b_st);
  }
  err = d_obj->NumBodies;
  if (err != (int32_T)muDoubleScalarFloor(err)) {
    emlrtIntegerCheckR2012b(err, &pb_emlrtDCI, &b_st);
  }
  b_loop_ub = (int32_T)err;
  for (i = 0; i < b_loop_ub; i++) {
    bodyIndices_data[i] = 0.0;
  }
  if (iter == 0.0) {
    i = bodyIndices->size[0];
    bodyIndices->size[0] = 1;
    emxEnsureCapacity_real_T(&b_st, bodyIndices, i, &pc_emlrtRTEI);
    bodyIndices_data = bodyIndices->data;
    bodyIndices_data[0] = 0.0;
  } else {
    if (iter != (int32_T)muDoubleScalarFloor(iter)) {
      emlrtIntegerCheckR2012b(iter, &rb_emlrtDCI, &b_st);
    }
    if (((int32_T)iter - 1 < 0) || ((int32_T)iter - 1 > 5)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)iter - 1, 0, 5, &bc_emlrtBCI,
                                    &b_st);
    }
    body = d_obj->Bodies[(int32_T)iter - 1];
    b_i = 1U;
    while (body->ParentIndex != 0.0) {
      if (((int32_T)b_i < 1) || ((int32_T)b_i > bodyIndices->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, bodyIndices->size[0],
                                      &cc_emlrtBCI, &b_st);
      }
      bodyIndices_data[(int32_T)b_i - 1] = body->Index;
      if (body->ParentIndex !=
          (int32_T)muDoubleScalarFloor(body->ParentIndex)) {
        emlrtIntegerCheckR2012b(body->ParentIndex, &sb_emlrtDCI, &b_st);
      }
      i = (int32_T)body->ParentIndex - 1;
      if ((i < 0) || (i > 5)) {
        emlrtDynamicBoundsCheckR2012b(i, 0, 5, &dc_emlrtBCI, &b_st);
      }
      body = d_obj->Bodies[i];
      b_i++;
    }
    if ((int32_T)(b_i - 1U) < 1) {
      i = 0;
    } else {
      if (bodyIndices->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, bodyIndices->size[0], &ac_emlrtBCI,
                                      &b_st);
      }
      if (((int32_T)(b_i - 1U) < 1) ||
          ((int32_T)(b_i - 1U) > bodyIndices->size[0])) {
        emlrtDynamicBoundsCheckR2012b(
            (int32_T)(b_i - 1U), 1, bodyIndices->size[0], &yb_emlrtBCI, &b_st);
      }
      i = (int32_T)(b_i - 1U);
    }
    qi_size[0] = 1;
    qi_size[1] = i;
    c_st.site = &vs_emlrtRSI;
    indexShapeCheck(&c_st, bodyIndices->size[0], qi_size);
    i1 = bodyIndices->size[0];
    bodyIndices->size[0] = i + 2;
    emxEnsureCapacity_real_T(&b_st, bodyIndices, i1, &pc_emlrtRTEI);
    bodyIndices_data = bodyIndices->data;
    bodyIndices_data[i] = body->Index;
    bodyIndices_data[i + 1] = 0.0;
  }
  emxInit_real_T(&st, &positionIndices, 2, &vc_emlrtRTEI);
  b_st.site = &ug_emlrtRSI;
  c_RigidBodyTree_bodyIndicesToPo(&b_st, b_obj->RigidBodyTreeInternal,
                                  bodyIndices, positionIndices);
  bodyIndices_data = positionIndices->data;
  emxFree_real_T(&st, &bodyIndices);
  emxInit_int32_T(&st, &r, 2, &wc_emlrtRTEI);
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  b_loop_ub = positionIndices->size[1];
  r->size[1] = positionIndices->size[1];
  emxEnsureCapacity_int32_T(&st, r, i, &qc_emlrtRTEI);
  r1 = r->data;
  for (i = 0; i < b_loop_ub; i++) {
    if (bodyIndices_data[i] !=
        (int32_T)muDoubleScalarFloor(bodyIndices_data[i])) {
      emlrtIntegerCheckR2012b(bodyIndices_data[i], &tb_emlrtDCI, &st);
    }
    i1 = (int32_T)bodyIndices_data[i];
    if ((i1 < 1) || (i1 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub, &ec_emlrtBCI, &st);
    }
    r1[i] = i1;
  }
  for (i = 0; i < b_loop_ub; i++) {
    i1 = (int32_T)bodyIndices_data[i];
    if ((i1 < 1) || (i1 > xSolPrev->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, xSolPrev->size[0], &fc_emlrtBCI,
                                    &st);
    }
  }
  if (r->size[1] != positionIndices->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(r->size[1], positionIndices->size[1],
                                    &n_emlrtECI, &st);
  }
  for (i = 0; i < b_loop_ub; i++) {
    iniGuessVec_data[r1[i] - 1] =
        xSolPrev_data[(int32_T)bodyIndices_data[i] - 1];
  }
  emxFree_real_T(&st, &xSolPrev);
  emxFree_int32_T(&st, &r);
  emxFree_real_T(&st, &positionIndices);
  emxInit_struct_T1(&st, &Q, &yc_emlrtRTEI);
  b_st.site = &vg_emlrtRSI;
  d_obj = b_obj->RigidBodyTreeInternal;
  c_st.site = &bt_emlrtRSI;
  iter = d_obj->NumNonFixedBodies;
  d_st.site = &gp_emlrtRSI;
  if ((iter != muDoubleScalarFloor(iter)) || muDoubleScalarIsInf(iter) ||
      (iter < -2.147483648E+9) || (iter > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &o_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (iter <= 0.0) {
    tol = 0.0;
  } else {
    tol = iter;
  }
  if (!(tol <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&d_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (!(iter >= 0.0)) {
    emlrtNonNegativeCheckR2012b(iter, &jb_emlrtDCI, &c_st);
  }
  emxInit_struct_T2(&b_st, &r2, &tc_emlrtRTEI);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  newseed_size_tmp = (int32_T)iter;
  r2->size[1] = (int32_T)iter;
  emxEnsureCapacity_struct_T(&b_st, r2, i, &tc_emlrtRTEI);
  r3 = r2->data;
  for (i = 0; i < newseed_size_tmp; i++) {
    r3[i] = r4;
  }
  c_st.site = &bt_emlrtRSI;
  cast(&c_st, r2, Q);
  Q_data = Q->data;
  emxFree_struct_T2(&b_st, &r2);
  b_i = 1U;
  err = d_obj->NumBodies;
  i = (int32_T)err;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, err, mxDOUBLE_CLASS, (int32_T)err,
                                &u_emlrtRTEI, &b_st);
  for (c_i = 0; c_i < i; c_i++) {
    char_T obj_Vector[200];
    if (c_i > 5) {
      emlrtDynamicBoundsCheckR2012b(c_i, 0, 5, &gc_emlrtBCI, &b_st);
    }
    body = d_obj->Bodies[c_i];
    c_st.site = &ct_emlrtRSI;
    e_obj = body->JointInternal;
    d_st.site = &bb_emlrtRSI;
    iter = e_obj->TypeInternal.Length;
    for (i1 = 0; i1 < 200; i1++) {
      obj_Vector[i1] = e_obj->TypeInternal.Vector[i1];
    }
    if (iter < 1.0) {
      i1 = 0;
    } else {
      if (iter != (int32_T)muDoubleScalarFloor(iter)) {
        emlrtIntegerCheckR2012b(iter, &c_emlrtDCI, &d_st);
      }
      if (((int32_T)iter < 1) || ((int32_T)iter > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)iter, 1, 200, &i_emlrtBCI,
                                      &d_st);
      }
      i1 = (int32_T)iter;
    }
    valid = false;
    if (i1 == 5) {
      newseed_size_tmp = 0;
      int32_T exitg2;
      do {
        exitg2 = 0;
        if (newseed_size_tmp < 5) {
          if (obj_Vector[newseed_size_tmp] != b_cv[newseed_size_tmp]) {
            exitg2 = 1;
          } else {
            newseed_size_tmp++;
          }
        } else {
          valid = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    if (!valid) {
      if (body->Index != (int32_T)muDoubleScalarFloor(body->Index)) {
        emlrtIntegerCheckR2012b(body->Index, &ob_emlrtDCI, &b_st);
      }
      newseed_size_tmp = (int32_T)body->Index;
      if ((newseed_size_tmp < 1) || (newseed_size_tmp > 6)) {
        emlrtDynamicBoundsCheckR2012b(newseed_size_tmp, 1, 6, &xb_emlrtBCI,
                                      &b_st);
      }
      err = d_obj->PositionDoFMap[newseed_size_tmp - 1];
      p_idx_1 = d_obj->PositionDoFMap[newseed_size_tmp + 5];
      c_st.site = &dt_emlrtRSI;
      e_obj = body->JointInternal;
      d_st.site = &ie_emlrtRSI;
      iter = e_obj->NameInternal.Length;
      for (i1 = 0; i1 < 200; i1++) {
        obj_Vector[i1] = e_obj->NameInternal.Vector[i1];
      }
      if (iter < 1.0) {
        b_loop_ub = 0;
      } else {
        if (iter != (int32_T)muDoubleScalarFloor(iter)) {
          emlrtIntegerCheckR2012b(iter, &c_emlrtDCI, &d_st);
        }
        if (((int32_T)iter < 1) || ((int32_T)iter > 200)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)iter, 1, 200, &i_emlrtBCI,
                                        &d_st);
        }
        b_loop_ub = (int32_T)iter;
      }
      valid = (((int32_T)b_i < 1) || ((int32_T)b_i > Q->size[1]));
      if (valid) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, Q->size[1], &hc_emlrtBCI,
                                      &b_st);
      }
      Q_data[(int32_T)b_i - 1].JointName.size[0] = 1;
      Q_data[(int32_T)b_i - 1].JointName.size[1] = b_loop_ub;
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        Q_data[(int32_T)b_i - 1].JointName.data[i1] = obj_Vector[i1];
      }
      if (err > p_idx_1) {
        i1 = 0;
        i2 = 0;
      } else {
        if (err != (int32_T)muDoubleScalarFloor(err)) {
          emlrtIntegerCheckR2012b(err, &nb_emlrtDCI, &b_st);
        }
        if (((int32_T)err < 1) || ((int32_T)err > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)err, 1, loop_ub, &wb_emlrtBCI,
                                        &b_st);
        }
        i1 = (int32_T)err - 1;
        if (p_idx_1 != (int32_T)muDoubleScalarFloor(p_idx_1)) {
          emlrtIntegerCheckR2012b(p_idx_1, &mb_emlrtDCI, &b_st);
        }
        if (((int32_T)p_idx_1 < 1) || ((int32_T)p_idx_1 > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)p_idx_1, 1, loop_ub,
                                        &vb_emlrtBCI, &b_st);
        }
        i2 = (int32_T)p_idx_1;
      }
      qi_size[0] = 1;
      b_loop_ub = i2 - i1;
      qi_size[1] = b_loop_ub;
      c_st.site = &et_emlrtRSI;
      indexShapeCheck(&c_st, iniGuessVec->size[0], qi_size);
      if (b_loop_ub != 1) {
        emlrtDimSizeEqCheckR2012b(1, b_loop_ub, &l_emlrtECI, &b_st);
      }
      if (((int32_T)b_i < 1) || ((int32_T)b_i > Q->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, Q->size[1], &ub_emlrtBCI,
                                      &b_st);
      }
      Q_data[(int32_T)b_i - 1].JointPosition.size[0] = 1;
      Q_data[(int32_T)b_i - 1].JointPosition.size[1] = 1;
      Q_data[(int32_T)b_i - 1].JointPosition.data[0] = iniGuessVec_data[i1];
      b_i++;
    }
  }
  emxFree_real_T(&b_st, &iniGuessVec);
  b_st.site = &vg_emlrtRSI;
  b_cast(&b_st, Q, QSol);
  emxFree_struct_T1(&st, &Q);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (inverseKinematics.c) */
