/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * RigidBodyTree.c
 *
 * Code generation for function 'RigidBodyTree'
 *
 */

/* Include files */
#include "RigidBodyTree.h"
#include "CharacterVector.h"
#include "CollisionSet.h"
#include "RigidBody.h"
#include "all.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "cat.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "normalizeRows.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "warning.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = {
    165,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo wc_emlrtRSI = {
    160,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    167,                           /* lineNo */
    "RigidBodyTree/RigidBodyTree", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    47,                                                /* lineNo */
    "FastVisualizationHelper/FastVisualizationHelper", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/FastVisualizationHelper.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    1399,                           /* lineNo */
    "RigidBodyTree/clearAllBodies", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo bd_emlrtRSI = {
    1380,                           /* lineNo */
    "RigidBodyTree/clearAllBodies", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    1425,                                /* lineNo */
    "RigidBodyTree/findBodyIndexByName", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    230,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    234,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    238,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    241,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    243,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    283,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    285,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    286,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ce_emlrtRSI = {
    293,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    294,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    254,                     /* lineNo */
    "RigidBodyTree/addBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI = {
    1448,                                     /* lineNo */
    "RigidBodyTree/findBodyIndexByJointName", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    1452,                                     /* lineNo */
    "RigidBodyTree/findBodyIndexByJointName", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo le_emlrtRSI = {
    199,              /* lineNo */
    "RigidBody/copy", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo me_emlrtRSI = {
    200,              /* lineNo */
    "RigidBody/copy", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo ne_emlrtRSI = {
    210,              /* lineNo */
    "RigidBody/copy", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo oe_emlrtRSI = {
    96,                    /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    99,                    /* lineNo */
    "RigidBody/RigidBody", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBody.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    2333,                                    /* lineNo */
    "RigidBodyTree/get.JointPositionLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    2335,                                    /* lineNo */
    "RigidBodyTree/get.JointPositionLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    1696,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    1698,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    1701,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    1707,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ah_emlrtRSI = {
    1710,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo bh_emlrtRSI = {
    1712,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    1637,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    1646,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    1647,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    1651,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    1658,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo hh_emlrtRSI = {
    1662,                                  /* lineNo */
    "RigidBodyTree/validateConfiguration", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo vj_emlrtRSI = {
    1897,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo wj_emlrtRSI = {
    1929,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo xj_emlrtRSI = {
    1930,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo yj_emlrtRSI = {
    1933,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ak_emlrtRSI = {
    1956,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo bk_emlrtRSI = {
    1955,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ck_emlrtRSI = {
    1967,                                        /* lineNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo dk_emlrtRSI = {
    2007,                                  /* lineNo */
    "RigidBodyTree/kinematicPathInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ek_emlrtRSI = {
    2008,                                  /* lineNo */
    "RigidBodyTree/kinematicPathInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo vs_emlrtRSI = {
    765,                                          /* lineNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ws_emlrtRSI = {
    125,                                                         /* lineNo */
    "colon",                                                     /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtRSInfo xs_emlrtRSI = {
    319,                                                         /* lineNo */
    "eml_float_colon",                                           /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtDCInfo i_emlrtDCI = {
    264,                     /* lineNo */
    24,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    273,                     /* lineNo */
    36,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    1,                       /* iFirst */
    6,                       /* iLast */
    273,                     /* lineNo */
    36,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    285,                     /* lineNo */
    36,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    1,                       /* iFirst */
    6,                       /* iLast */
    285,                     /* lineNo */
    36,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    286,                     /* lineNo */
    36,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                       /* iFirst */
    6,                       /* iLast */
    286,                     /* lineNo */
    36,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    288,                     /* lineNo */
    36,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                       /* iFirst */
    6,                       /* iLast */
    288,                     /* lineNo */
    36,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    289,                     /* lineNo */
    36,                      /* colNo */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                       /* iFirst */
    6,                       /* iLast */
    289,                     /* lineNo */
    36,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    0,                       /* iFirst */
    5,                       /* iLast */
    264,                     /* lineNo */
    24,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    3                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    0,                       /* iFirst */
    5,                       /* iLast */
    269,                     /* lineNo */
    37,                      /* colNo */
    "",                      /* aName */
    "RigidBodyTree/addBody", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo i_emlrtRTEI = {
    1451,                                     /* lineNo */
    21,                                       /* colNo */
    "RigidBodyTree/findBodyIndexByJointName", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo s_emlrtBCI = {
    0,                                        /* iFirst */
    5,                                        /* iLast */
    1452,                                     /* lineNo */
    38,                                       /* colNo */
    "",                                       /* aName */
    "RigidBodyTree/findBodyIndexByJointName", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = {
    2329,                                    /* lineNo */
    28,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    4                            /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = {
    2329,                                    /* lineNo */
    28,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = {
    2331,                                    /* lineNo */
    21,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtDCInfo hb_emlrtDCI = {
    2335,                                    /* lineNo */
    28,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    2335,                                    /* lineNo */
    28,                                      /* colNo */
    "",                                      /* aName */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = {
    2335,                                    /* lineNo */
    30,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    2335,                                    /* lineNo */
    30,                                      /* colNo */
    "",                                      /* aName */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtECInfo j_emlrtECI = {
    -1,                                      /* nDims */
    2335,                                    /* lineNo */
    21,                                      /* colNo */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo kb_emlrtBCI = {
    0,                                       /* iFirst */
    5,                                       /* iLast */
    2332,                                    /* lineNo */
    35,                                      /* colNo */
    "",                                      /* aName */
    "RigidBodyTree/get.JointPositionLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtECInfo o_emlrtECI = {
    1,                                               /* nDims */
    1699,                                            /* lineNo */
    20,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtECInfo p_emlrtECI = {
    1,                                               /* nDims */
    1700,                                            /* lineNo */
    20,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtECInfo q_emlrtECI = {
    -1,                                              /* nDims */
    1708,                                            /* lineNo */
    21,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtECInfo r_emlrtECI = {
    -1,                                              /* nDims */
    1711,                                            /* lineNo */
    21,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    1644,                                  /* lineNo */
    25,                                    /* colNo */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo cc_emlrtBCI = {
    1,                                     /* iFirst */
    6,                                     /* iLast */
    1661,                                  /* lineNo */
    32,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = {
    1666,                                  /* lineNo */
    30,                                    /* colNo */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    1666,                                  /* lineNo */
    30,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = {
    1666,                                  /* lineNo */
    37,                                    /* colNo */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    1666,                                  /* lineNo */
    37,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI = {
    10,              /* lineNo */
    23,              /* colNo */
    "validatenumel", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenumel.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    18,              /* lineNo */
    23,              /* colNo */
    "validatenumel", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenumel.m" /* pName */
};

static emlrtDCInfo yb_emlrtDCI = {
    1696,                                            /* lineNo */
    13,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = {
    1696,                                            /* lineNo */
    13,                                              /* colNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    0,                                     /* iFirst */
    5,                                     /* iLast */
    1645,                                  /* lineNo */
    39,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/validateConfiguration", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    1708,                                            /* lineNo */
    26,                                              /* colNo */
    "",                                              /* aName */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    1708,                                            /* lineNo */
    63,                                              /* colNo */
    "",                                              /* aName */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    1711,                                            /* lineNo */
    26,                                              /* colNo */
    "",                                              /* aName */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    1711,                                            /* lineNo */
    63,                                              /* colNo */
    "",                                              /* aName */
    "RigidBodyTree/validateConfigurationWithLimits", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = {
    1900,                                        /* lineNo */
    32,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    4                            /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = {
    1900,                                        /* lineNo */
    32,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = {
    1932,                                        /* lineNo */
    51,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    1,                                           /* iFirst */
    6,                                           /* iLast */
    1932,                                        /* lineNo */
    51,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo ec_emlrtDCI = {
    1933,                                        /* lineNo */
    64,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1933,                                        /* lineNo */
    64,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = {
    1933,                                        /* lineNo */
    72,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1933,                                        /* lineNo */
    72,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = {
    1935,                                        /* lineNo */
    55,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    1,                                           /* iFirst */
    6,                                           /* iLast */
    1935,                                        /* lineNo */
    55,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = {
    1957,                                        /* lineNo */
    35,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1957,                                        /* lineNo */
    35,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo ic_emlrtDCI = {
    1957,                                        /* lineNo */
    43,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1957,                                        /* lineNo */
    43,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtECInfo ob_emlrtECI = {
    -1,                                          /* nDims */
    1957,                                        /* lineNo */
    29,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo hd_emlrtBCI = {
    0,                                           /* iFirst */
    5,                                           /* iLast */
    1890,                                        /* lineNo */
    40,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo jc_emlrtDCI = {
    1890,                                        /* lineNo */
    40,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1902,                                        /* lineNo */
    45,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1907,                                        /* lineNo */
    45,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    0,                                           /* iFirst */
    5,                                           /* iLast */
    1903,                                        /* lineNo */
    50,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo kc_emlrtDCI = {
    1903,                                        /* lineNo */
    50,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1903,                                        /* lineNo */
    71,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    0,                                           /* iFirst */
    5,                                           /* iLast */
    1908,                                        /* lineNo */
    47,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo lc_emlrtDCI = {
    1908,                                        /* lineNo */
    47,                                          /* colNo */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    1908,                                        /* lineNo */
    68,                                          /* colNo */
    "",                                          /* aName */
    "RigidBodyTree/efficientFKAndJacobianForIK", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo
    od_emlrtBCI =
        {
            1,                               /* iFirst */
            1,                               /* iLast */
            451,                             /* lineNo */
            55,                              /* colNo */
            "",                              /* aName */
            "rigidBodyJoint/jointTransform", /* fName */
            "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/"
            "rigidBodyJoint.m", /* pName */
            0                   /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    2018,                                  /* lineNo */
    43,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/kinematicPathInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    2020,                                  /* lineNo */
    41,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/kinematicPathInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    2012,                                  /* lineNo */
    37,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/kinematicPathInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    2012,                                  /* lineNo */
    64,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/kinematicPathInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    2017,                                  /* lineNo */
    52,                                    /* colNo */
    "",                                    /* aName */
    "RigidBodyTree/kinematicPathInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    2041,                            /* lineNo */
    33,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    2041,                            /* lineNo */
    31,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    2031,                            /* lineNo */
    21,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo mc_emlrtDCI = {
    2029,                            /* lineNo */
    31,                              /* colNo */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo nc_emlrtDCI = {
    2029,                            /* lineNo */
    31,                              /* colNo */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    0,                               /* iFirst */
    5,                               /* iLast */
    2033,                            /* lineNo */
    35,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo oc_emlrtDCI = {
    2033,                            /* lineNo */
    35,                              /* colNo */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    2038,                            /* lineNo */
    25,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,                              /* iFirst */
    -1,                              /* iLast */
    2034,                            /* lineNo */
    25,                              /* colNo */
    "",                              /* aName */
    "RigidBodyTree/ancestorIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    419,                                                         /* lineNo */
    15,                                                          /* colNo */
    "assert_pmaxsize",                                           /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtBCInfo me_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    769,                                          /* lineNo */
    39,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo sc_emlrtDCI = {
    769,                                          /* lineNo */
    39,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    769,                                          /* lineNo */
    37,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtECInfo wb_emlrtECI = {
    -1,                                           /* nDims */
    765,                                          /* lineNo */
    21,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtBCInfo oe_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    762,                                          /* lineNo */
    33,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo tc_emlrtDCI = {
    758,                                          /* lineNo */
    34,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo uc_emlrtDCI = {
    758,                                          /* lineNo */
    34,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = {
    1,                                            /* iFirst */
    6,                                            /* iLast */
    757,                                          /* lineNo */
    46,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo vc_emlrtDCI = {
    757,                                          /* lineNo */
    46,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    757,                                          /* lineNo */
    58,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo wc_emlrtDCI = {
    765,                                          /* lineNo */
    32,                                           /* colNo */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    765,                                          /* lineNo */
    32,                                           /* colNo */
    "",                                           /* aName */
    "RigidBodyTree/bodyIndicesToPositionIndices", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    2329,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    1696,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    1699,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    1700,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    1707,            /* lineNo */
    21,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    1708,            /* lineNo */
    26,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    1710,            /* lineNo */
    21,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    1711,            /* lineNo */
    26,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    1698,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    1900,            /* lineNo */
    17,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo of_emlrtRTEI =
    {
        178,      /* lineNo */
        65,       /* colNo */
        "mtimes", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

static emlrtRTEInfo pf_emlrtRTEI = {
    1933,            /* lineNo */
    60,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo qf_emlrtRTEI = {
    1897,            /* lineNo */
    17,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo rf_emlrtRTEI =
    {
        178,      /* lineNo */
        13,       /* colNo */
        "mtimes", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+blas/"
        "mtimes.m" /* pName */
};

static emlrtRTEInfo sf_emlrtRTEI = {
    2018,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo tf_emlrtRTEI = {
    2007,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo uf_emlrtRTEI = {
    2008,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo vf_emlrtRTEI = {
    2029,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo wf_emlrtRTEI = {
    2041,            /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = {
    746,             /* lineNo */
    31,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo wh_emlrtRTEI = {
    757,             /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo xh_emlrtRTEI = {
    758,             /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo yh_emlrtRTEI = {
    769,             /* lineNo */
    13,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo ai_emlrtRTEI = {
    28,                                                          /* lineNo */
    9,                                                           /* colNo */
    "colon",                                                     /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtRTEInfo bi_emlrtRTEI = {
    765,             /* lineNo */
    32,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo ci_emlrtRTEI = {
    765,             /* lineNo */
    63,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo di_emlrtRTEI = {
    320,                                                         /* lineNo */
    20,                                                          /* colNo */
    "colon",                                                     /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = {
    765,             /* lineNo */
    21,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = {
    757,             /* lineNo */
    58,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = {
    765,             /* lineNo */
    44,              /* colNo */
    "RigidBodyTree", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pName */
};

static emlrtRSInfo mt_emlrtRSI = {
    2018,                                  /* lineNo */
    "RigidBodyTree/kinematicPathInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo nt_emlrtRSI = {
    1699,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

static emlrtRSInfo ot_emlrtRSI = {
    1700,                                            /* lineNo */
    "RigidBodyTree/validateConfigurationWithLimits", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/RigidBodyTree.m" /* pathName */
};

/* Function Declarations */
static void RigidBodyTree_ancestorIndices(const emlrtStack *sp,
                                          e_robotics_manip_internal_Rigid *obj,
                                          c_robotics_manip_internal_Rigid *body,
                                          emxArray_real_T *indices);

static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3);

static void binary_expand_op_1(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3);

static void c_RigidBodyTree_initVisualizati(const emlrtStack *sp);

static void c_RigidBodyTree_kinematicPathIn(
    const emlrtStack *sp, e_robotics_manip_internal_Rigid *obj,
    c_robotics_manip_internal_Rigid *body1,
    c_robotics_manip_internal_Rigid *body2, emxArray_real_T *indices);

static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

/* Function Definitions */
static void RigidBodyTree_ancestorIndices(const emlrtStack *sp,
                                          e_robotics_manip_internal_Rigid *obj,
                                          c_robotics_manip_internal_Rigid *body,
                                          emxArray_real_T *indices)
{
  real_T d;
  real_T *indices_data;
  int32_T i;
  int32_T loop_ub_tmp;
  uint32_T b_i;
  d = obj->NumBodies + 1.0;
  if (!(d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d, &nc_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &mc_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = indices->size[0] * indices->size[1];
  indices->size[0] = 1;
  loop_ub_tmp = (int32_T)d;
  indices->size[1] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, indices, i, &vf_emlrtRTEI);
  indices_data = indices->data;
  for (i = 0; i < loop_ub_tmp; i++) {
    indices_data[i] = 0.0;
  }
  b_i = 2U;
  if ((int32_T)d < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)d, &wd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  indices_data[0] = body->Index;
  while (body->ParentIndex > 0.0) {
    if (body->ParentIndex != (int32_T)muDoubleScalarFloor(body->ParentIndex)) {
      emlrtIntegerCheckR2012b(body->ParentIndex, &oc_emlrtDCI,
                              (emlrtConstCTX)sp);
    }
    i = (int32_T)body->ParentIndex - 1;
    if ((i < 0) || (i > 5)) {
      emlrtDynamicBoundsCheckR2012b(i, 0, 5, &xd_emlrtBCI, (emlrtConstCTX)sp);
    }
    body = obj->Bodies[i];
    if (((int32_T)b_i < 1) || ((int32_T)b_i > indices->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, indices->size[1],
                                    &ae_emlrtBCI, (emlrtConstCTX)sp);
    }
    indices_data[(int32_T)b_i - 1] = body->Index;
    b_i++;
  }
  if (body->Index > 0.0) {
    if (((int32_T)b_i < 1) || ((int32_T)b_i > indices->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b_i, 1, indices->size[1],
                                    &yd_emlrtBCI, (emlrtConstCTX)sp);
    }
    indices_data[(int32_T)b_i - 1] = body->ParentIndex;
    b_i++;
  }
  if (indices->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, indices->size[1], &vd_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (((int32_T)(b_i - 1U) < 1) || ((int32_T)(b_i - 1U) > indices->size[1])) {
    emlrtDynamicBoundsCheckR2012b((int32_T)(b_i - 1U), 1, indices->size[1],
                                  &ud_emlrtBCI, (emlrtConstCTX)sp);
  }
  i = indices->size[0] * indices->size[1];
  indices->size[1] = (int32_T)(b_i - 1U);
  emxEnsureCapacity_real_T(sp, indices, i, &wf_emlrtRTEI);
}

static void binary_expand_op(const emlrtStack *sp, emxArray_boolean_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &bd_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[i * stride_0_0] >=
                   in3_data[i * stride_1_0] - 4.4408920985006262E-16);
  }
}

static void binary_expand_op_1(const emlrtStack *sp, emxArray_boolean_T *in1,
                               const emxArray_real_T *in2,
                               const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T *in1_data;
  in3_data = in3->data;
  in2_data = in2->data;
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, in1, i, &ad_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        (in2_data[i * stride_0_0] <=
         in3_data[i * stride_1_0 + in3->size[0]] + 4.4408920985006262E-16);
  }
}

static void c_RigidBodyTree_initVisualizati(const emlrtStack *sp)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  emlrtStack b_st;
  emlrtStack st;
  real_T idx[5];
  real_T dv[2];
  real_T dv1[2];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &h_emlrtRSI;
  emlrtRandu(&idx[0], 5);
  r = _mm_loadu_pd(&idx[0]);
  r1 = _mm_set1_pd(62.0);
  _mm_storeu_pd(&dv[0], _mm_mul_pd(r, r1));
  dv1[0] = muDoubleScalarFloor(dv[0]);
  dv1[1] = muDoubleScalarFloor(dv[1]);
  r = _mm_loadu_pd(&dv1[0]);
  r2 = _mm_set1_pd(1.0);
  _mm_storeu_pd(&idx[0], _mm_add_pd(r, r2));
  r = _mm_loadu_pd(&idx[2]);
  _mm_storeu_pd(&dv[0], _mm_mul_pd(r, r1));
  dv1[0] = muDoubleScalarFloor(dv[0]);
  dv1[1] = muDoubleScalarFloor(dv[1]);
  r = _mm_loadu_pd(&dv1[0]);
  _mm_storeu_pd(&idx[2], _mm_add_pd(r, r2));
  idx[4] = muDoubleScalarFloor(idx[4] * 62.0) + 1.0;
  for (i = 0; i < 5; i++) {
    real_T d;
    d = idx[i];
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &xc_emlrtDCI, &b_st);
    }
    if (((int32_T)d < 1) || ((int32_T)d > 62)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 62, &se_emlrtBCI, &b_st);
    }
  }
}

static void c_RigidBodyTree_kinematicPathIn(
    const emlrtStack *sp, e_robotics_manip_internal_Rigid *obj,
    c_robotics_manip_internal_Rigid *body1,
    c_robotics_manip_internal_Rigid *body2, emxArray_real_T *indices)
{
  emlrtStack st;
  emxArray_real_T *ancestorIndices1;
  emxArray_real_T *ancestorIndices2;
  real_T *ancestorIndices1_data;
  real_T *ancestorIndices2_data;
  real_T *indices_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T minPathLength;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &ancestorIndices1, 2, &tf_emlrtRTEI);
  st.site = &dk_emlrtRSI;
  RigidBodyTree_ancestorIndices(&st, obj, body1, ancestorIndices1);
  ancestorIndices1_data = ancestorIndices1->data;
  emxInit_real_T(sp, &ancestorIndices2, 2, &uf_emlrtRTEI);
  st.site = &ek_emlrtRSI;
  RigidBodyTree_ancestorIndices(&st, obj, body2, ancestorIndices2);
  ancestorIndices2_data = ancestorIndices2->data;
  minPathLength = (int32_T)muDoubleScalarMin(ancestorIndices1->size[1],
                                             ancestorIndices2->size[1]);
  i = 1;
  exitg1 = false;
  while ((!exitg1) && (i - 1 <= minPathLength - 2)) {
    b_i = ancestorIndices1->size[1] - i;
    if ((b_i < 1) || (b_i > ancestorIndices1->size[1])) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, ancestorIndices1->size[1],
                                    &rd_emlrtBCI, (emlrtConstCTX)sp);
    }
    i1 = ancestorIndices2->size[1] - i;
    if ((i1 < 1) || (i1 > ancestorIndices2->size[1])) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, ancestorIndices2->size[1],
                                    &sd_emlrtBCI, (emlrtConstCTX)sp);
    }
    if (ancestorIndices1_data[b_i - 1] != ancestorIndices2_data[i1 - 1]) {
      minPathLength = i;
      exitg1 = true;
    } else {
      i++;
    }
  }
  b_i = ancestorIndices1->size[1] - minPathLength;
  if ((b_i + 1 < 1) || (b_i + 1 > ancestorIndices1->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ancestorIndices1->size[1],
                                  &td_emlrtBCI, (emlrtConstCTX)sp);
  }
  if (b_i < 1) {
    loop_ub = 0;
  } else {
    if (b_i > ancestorIndices1->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, ancestorIndices1->size[1],
                                    &pd_emlrtBCI, (emlrtConstCTX)sp);
    }
    loop_ub = b_i;
  }
  i1 = ancestorIndices2->size[1] - minPathLength;
  if (i1 < 1) {
    i1 = 0;
    i = 1;
    i2 = -1;
  } else {
    if (i1 > ancestorIndices2->size[1]) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, ancestorIndices2->size[1],
                                    &qd_emlrtBCI, (emlrtConstCTX)sp);
    }
    i1--;
    i = -1;
    i2 = 0;
  }
  minPathLength = indices->size[0] * indices->size[1];
  indices->size[0] = 1;
  st.site = &mt_emlrtRSI;
  b_loop_ub = div_s32(&st, i2 - i1, i);
  indices->size[1] = (loop_ub + b_loop_ub) + 2;
  emxEnsureCapacity_real_T(sp, indices, minPathLength, &sf_emlrtRTEI);
  indices_data = indices->data;
  for (i2 = 0; i2 < loop_ub; i2++) {
    indices_data[i2] = ancestorIndices1_data[i2];
  }
  indices_data[loop_ub] = ancestorIndices1_data[b_i];
  emxFree_real_T(sp, &ancestorIndices1);
  for (b_i = 0; b_i <= b_loop_ub; b_i++) {
    indices_data[(b_i + loop_ub) + 1] = ancestorIndices2_data[i1 + i * b_i];
  }
  emxFree_real_T(sp, &ancestorIndices2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, (emlrtConstCTX)sp);
  } else {
    uint32_T u;
    uint32_T u1;
    if (numerator < 0) {
      u = ~(uint32_T)numerator + 1U;
    } else {
      u = (uint32_T)numerator;
    }
    if (denominator < 0) {
      u1 = ~(uint32_T)denominator + 1U;
    } else {
      u1 = (uint32_T)denominator;
    }
    u /= u1;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)u;
    } else {
      quotient = (int32_T)u;
    }
  }
  return quotient;
}

e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(const emlrtStack *sp,
                            e_robotics_manip_internal_Rigid *obj)
{
  static const char_T b_cv[8] = {'b', 'a', 's', 'e', '_', 'j', 'n', 't'};
  static const char_T b_cv2[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv3[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T b_cv4[5] = {'f', 'i', 'x', 'e', 'd'};
  static const int8_T iv3[12] = {0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1};
  static const int8_T iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const int8_T b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const int8_T iv1[6] = {0, 0, 0, 0, 0, 1};
  c_robotics_manip_internal_Chara s;
  e_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T msubspace_data[36];
  real_T poslim_data[14];
  int32_T msubspace_size[2];
  int32_T poslim_size[2];
  int32_T exitg1;
  int32_T homepos_size_idx_1;
  int32_T i;
  int32_T i1;
  int32_T ibmat;
  int8_T b_I[36];
  int8_T c_I[9];
  int8_T homepos_data[7];
  boolean_T result;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_obj = obj;
  st.site = &l_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &m_emlrtRSI;
  c_RigidBodyTree_initVisualizati(&st);
  st.site = &wc_emlrtRSI;
  b_st.site = &s_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->Base.NameInternal = s;
  s = b_obj->Base.NameInternal;
  s.Length = 4.0;
  s.Vector[0] = 'b';
  s.Vector[1] = 'a';
  s.Vector[2] = 's';
  s.Vector[3] = 'e';
  b_obj->Base.NameInternal = s;
  b_st.site = &t_emlrtRSI;
  b_obj->_pobj2[0].InTree = false;
  for (i = 0; i < 16; i++) {
    b_obj->_pobj2[0].JointToParentTransform[i] = iv[i];
  }
  for (i = 0; i < 16; i++) {
    b_obj->_pobj2[0].ChildToJointTransform[i] = iv[i];
  }
  for (i = 0; i < 14; i++) {
    b_obj->_pobj2[0].PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    b_obj->_pobj2[0].HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    b_obj->_pobj2[0].MotionSubspaceInternal[i] = 0.0;
  }
  c_st.site = &v_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->_pobj2[0].NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->_pobj2[0].TypeInternal = s;
  s = b_obj->_pobj2[0].NameInternal;
  s.Length = 8.0;
  for (i = 0; i < 8; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_obj->_pobj2[0].NameInternal = s;
  c_st.site = &w_emlrtRSI;
  s = b_obj->_pobj2[0].TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv1[i];
  }
  b_obj->_pobj2[0].TypeInternal = s;
  c_st.site = &x_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  s = b_obj->_pobj2[0].TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &d_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &d_st);
    }
    i = (int32_T)s.Length;
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
    b_obj->_pobj2[0].VelocityNumber = 1.0;
    b_obj->_pobj2[0].PositionNumber = 1.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 1.0;
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
    b_obj->_pobj2[0].VelocityNumber = 1.0;
    b_obj->_pobj2[0].PositionNumber = 1.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 1.0;
    break;
  case 2: {
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
    b_obj->_pobj2[0].VelocityNumber = 6.0;
    b_obj->_pobj2[0].PositionNumber = 7.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = rtNaN;
    b_obj->_pobj2[0].JointAxisInternal[1] = rtNaN;
    b_obj->_pobj2[0].JointAxisInternal[2] = rtNaN;
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
    b_obj->_pobj2[0].VelocityNumber = 0.0;
    b_obj->_pobj2[0].PositionNumber = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[0] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[1] = 0.0;
    b_obj->_pobj2[0].JointAxisInternal[2] = 0.0;
    break;
  }
  c_st.site = &y_emlrtRSI;
  c_rigidBodyJoint_set_MotionSubs(&c_st, &b_obj->_pobj2[0], msubspace_data,
                                  msubspace_size);
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  s = b_obj->_pobj2[0].TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    if (s.Length != (int32_T)muDoubleScalarFloor(s.Length)) {
      emlrtIntegerCheckR2012b(s.Length, &c_emlrtDCI, &d_st);
    }
    if (((int32_T)s.Length < 1) || ((int32_T)s.Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)s.Length, 1, 200, &c_emlrtBCI,
                                    &d_st);
    }
    i = (int32_T)s.Length;
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
    real_T d;
    d = b_obj->_pobj2[0].PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &emlrtDCI, &b_st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &emlrtBCI, &b_st);
      }
      ibmat = (int32_T)d;
    }
    msubspace_size[0] = ibmat;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &emlrtECI, &b_st);
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        b_obj->_pobj2[0].PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size[0] * i];
      }
    }
    d = b_obj->_pobj2[0].PositionNumber;
    if (d < 1.0) {
      i = 0;
    } else {
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &b_emlrtDCI, &b_st);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 7)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 7, &b_emlrtBCI, &b_st);
      }
      i = (int32_T)d;
    }
    if (i != homepos_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(i, homepos_size_idx_1, &b_emlrtECI,
                                      &b_st);
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      b_obj->_pobj2[0].HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    msubspace_size[0] = 1;
    msubspace_size[1] = 2;
    emlrtSubAssignSizeCheckR2012b(&msubspace_size[0], 2, &poslim_size[0], 2,
                                  &c_emlrtECI, &b_st);
    b_obj->_pobj2[0].PositionLimitsInternal[0] = poslim_data[0];
    b_obj->_pobj2[0].PositionLimitsInternal[7] = poslim_data[1];
    if (homepos_size_idx_1 != 1) {
      emlrtSubAssignSizeCheck1dR2017a(1, homepos_size_idx_1, &d_emlrtECI,
                                      &b_st);
    }
    b_obj->_pobj2[0].HomePositionInternal[0] = homepos_data[0];
  }
  b_obj->Base.JointInternal = &b_obj->_pobj2[0];
  b_obj->Base.Index = -1.0;
  b_obj->Base.ParentIndex = -1.0;
  b_obj->Base.MassInternal = 1.0;
  b_obj->Base.CenterOfMassInternal[0] = 0.0;
  b_obj->Base.CenterOfMassInternal[1] = 0.0;
  b_obj->Base.CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    c_I[i] = 0;
  }
  c_I[0] = 1;
  c_I[4] = 1;
  c_I[8] = 1;
  for (i = 0; i < 9; i++) {
    b_obj->Base.InertiaInternal[i] = c_I[i];
  }
  for (i = 0; i < 36; i++) {
    b_I[i] = 0;
  }
  for (ibmat = 0; ibmat < 6; ibmat++) {
    b_I[ibmat + 6 * ibmat] = 1;
  }
  for (i = 0; i < 36; i++) {
    b_obj->Base.SpatialInertia[i] = b_I[i];
  }
  b_st.site = &u_emlrtRSI;
  b_obj->Base.CollisionsInternal =
      CollisionSet_CollisionSet(&b_st, &b_obj->_pobj1[0], 0.0);
  b_obj->Base.matlabCodegenIsDeleted = false;
  b_obj->Base.Index = 0.0;
  st.site = &vc_emlrtRSI;
  b_st.site = &yc_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  st.site = &xc_emlrtRSI;
  b_st.site = &bd_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[0] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[0], cv4,
                                         &b_obj->_pobj1[1], &b_obj->_pobj2[1]);
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[1] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[1], cv5,
                                         &b_obj->_pobj1[2], &b_obj->_pobj2[2]);
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[2] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[2], cv6,
                                         &b_obj->_pobj1[3], &b_obj->_pobj2[3]);
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[3] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[3], cv7,
                                         &b_obj->_pobj1[4], &b_obj->_pobj2[4]);
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[4] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[4], cv8,
                                         &b_obj->_pobj1[5], &b_obj->_pobj2[5]);
  c_st.site = &r_emlrtRSI;
  b_obj->Bodies[5] = RigidBody_RigidBody(&c_st, &b_obj->_pobj0[5], cv9,
                                         &b_obj->_pobj1[6], &b_obj->_pobj2[6]);
  b_obj->NumBodies = 0.0;
  b_obj->NumNonFixedBodies = 0.0;
  b_obj->PositionNumber = 0.0;
  b_obj->VelocityNumber = 0.0;
  b_st.site = &ad_emlrtRSI;
  c_RigidBodyTree_initVisualizati(&b_st);
  for (i = 0; i < 12; i++) {
    b_obj->PositionDoFMap[i] = iv3[i];
  }
  for (i = 0; i < 12; i++) {
    b_obj->VelocityDoFMap[i] = iv3[i];
  }
  b_obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

void RigidBodyTree_addBody(
    const emlrtStack *sp, e_robotics_manip_internal_Rigid *obj,
    c_robotics_manip_internal_Rigid *bodyin, const char_T parentName_data[],
    const int32_T parentName_size[2], d_robotics_manip_internal_Colli *iobj_0,
    rigidBodyJoint *iobj_1, c_robotics_manip_internal_Rigid *iobj_2)
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T varargin_1[5] = {'J', 'o', 'i', 'n', 't'};
  c_robotics_manip_internal_Chara s;
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  rigidBodyJoint *jnt;
  real_T c_bodyin[36];
  real_T b_bodyin[9];
  real_T b_index;
  real_T bid;
  real_T obj_Length;
  real_T pid;
  int32_T bname_size[2];
  int32_T obj_Vector_size[2];
  int32_T b_i;
  int32_T bid2;
  int32_T i;
  int32_T loop_ub;
  char_T b_obj_Vector_data[204];
  char_T bname_data[200];
  char_T obj_Vector[200];
  char_T obj_Vector_data[200];
  int8_T c_I[36];
  int8_T b_I[9];
  boolean_T b_bool;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &td_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &dd_emlrtRSI;
  obj_Length = bodyin->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = bodyin->NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    loop_ub = (int32_T)obj_Length;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  st.site = &td_emlrtRSI;
  bid = c_RigidBodyTree_findBodyIndexBy(&st, obj, obj_Vector_data,
                                        obj_Vector_size);
  if (bid > -1.0) {
    st.site = &ud_emlrtRSI;
    b_st.site = &dd_emlrtRSI;
    obj_Length = bodyin->NameInternal.Length;
    for (i = 0; i < 200; i++) {
      obj_Vector[i] = bodyin->NameInternal.Vector[i];
    }
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
        emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
      }
      if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                      &b_st);
      }
      loop_ub = (int32_T)obj_Length;
    }
    if (loop_ub - 1 >= 0) {
      memcpy(&bname_data[0], &obj_Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    st.site = &ud_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbodytree:BodyNameCollision",
        "robotics:robotmanip:rigidbodytree:BodyNameCollision", 3, 4, loop_ub,
        &bname_data[0]);
  }
  st.site = &vd_emlrtRSI;
  b_st.site = &fe_emlrtRSI;
  pid = c_RigidBodyTree_findBodyIndexBy(&b_st, obj, parentName_data,
                                        parentName_size);
  if (pid == -1.0) {
    b_st.site = &ge_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "robotics:robotmanip:rigidbodytree:BodyNotFound",
        "robotics:robotmanip:rigidbodytree:BodyNotFound", 3, 4,
        parentName_size[1], &parentName_data[0]);
  }
  st.site = &wd_emlrtRSI;
  if (bodyin->Index == 0.0) {
    b_st.site = &he_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
        &varargin_1[0]);
  }
  jnt = bodyin->JointInternal;
  st.site = &wd_emlrtRSI;
  b_st.site = &ie_emlrtRSI;
  obj_Length = jnt->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    loop_ub = (int32_T)obj_Length;
  }
  bname_size[0] = 1;
  bname_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&bname_data[0], &obj_Vector[0], (uint32_T)loop_ub * sizeof(char_T));
  }
  st.site = &wd_emlrtRSI;
  bid2 = -1;
  b_st.site = &je_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  if (loop_ub == 0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:findBodyIndexByJointName:expectedNonempty", 3, 4, 9,
        "jointname");
  }
  bid = obj->NumBodies;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, bid, mxDOUBLE_CLASS, (int32_T)bid,
                                &i_emlrtRTEI, &st);
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= (int32_T)bid - 1)) {
    b_st.site = &ke_emlrtRSI;
    if (b_i > 5) {
      emlrtDynamicBoundsCheckR2012b(6, 0, 5, &s_emlrtBCI, &b_st);
    }
    b_obj = obj->Bodies[b_i];
    if (b_obj->Index == 0.0) {
      c_st.site = &he_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &c_st, &d_emlrtRTEI,
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
          &varargin_1[0]);
    }
    jnt = b_obj->JointInternal;
    b_st.site = &ke_emlrtRSI;
    c_st.site = &ie_emlrtRSI;
    obj_Length = jnt->NameInternal.Length;
    for (i = 0; i < 200; i++) {
      obj_Vector[i] = jnt->NameInternal.Vector[i];
    }
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
    obj_Vector_size[0] = 1;
    obj_Vector_size[1] = loop_ub;
    if (loop_ub - 1 >= 0) {
      memcpy(&obj_Vector_data[0], &obj_Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    b_st.site = &ke_emlrtRSI;
    if (b_strcmp(obj_Vector_data, obj_Vector_size, bname_data, bname_size)) {
      bid2 = b_i + 1;
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  if (bid2 > 0) {
    st.site = &xd_emlrtRSI;
    if (bodyin->Index == 0.0) {
      b_st.site = &he_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &b_st, &d_emlrtRTEI,
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
          &varargin_1[0]);
    }
    jnt = bodyin->JointInternal;
    st.site = &xd_emlrtRSI;
    b_st.site = &ie_emlrtRSI;
    obj_Length = jnt->NameInternal.Length;
    for (i = 0; i < 200; i++) {
      obj_Vector[i] = jnt->NameInternal.Vector[i];
    }
    if (obj_Length < 1.0) {
      loop_ub = 0;
    } else {
      if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
        emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
      }
      if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                      &b_st);
      }
      loop_ub = (int32_T)obj_Length;
    }
    if (loop_ub - 1 >= 0) {
      memcpy(&bname_data[0], &obj_Vector[0],
             (uint32_T)loop_ub * sizeof(char_T));
    }
    st.site = &xd_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbodytree:JointNameCollision",
        "robotics:robotmanip:rigidbodytree:JointNameCollision", 3, 4, loop_ub,
        &bname_data[0]);
  }
  b_index = obj->NumBodies + 1.0;
  st.site = &ee_emlrtRSI;
  b_st.site = &le_emlrtRSI;
  obj_Length = bodyin->NameInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = bodyin->NameInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    loop_ub = (int32_T)obj_Length;
  }
  b_st.site = &le_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  iobj_2->NameInternal = s;
  c_st.site = &oe_emlrtRSI;
  d_st.site = &pb_emlrtRSI;
  if (loop_ub == 0) {
    emlrtErrorWithMessageIdR2018a(
        &d_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:rigidBody:expectedNonempty", 3, 4, 5, "bname");
  }
  s = iobj_2->NameInternal;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  c_st.site = &pe_emlrtRSI;
  CharacterVector_setVector(&c_st, &s, obj_Vector_data, obj_Vector_size);
  iobj_2->NameInternal = s;
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub + 4;
  if (loop_ub - 1 >= 0) {
    memcpy(&b_obj_Vector_data[0], &obj_Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  b_obj_Vector_data[loop_ub] = '_';
  b_obj_Vector_data[loop_ub + 1] = 'j';
  b_obj_Vector_data[loop_ub + 2] = 'n';
  b_obj_Vector_data[loop_ub + 3] = 't';
  c_st.site = &t_emlrtRSI;
  iobj_2->JointInternal = rigidBodyJoint_rigidBodyJoint(
      &c_st, &iobj_1[0], b_obj_Vector_data, obj_Vector_size);
  iobj_2->Index = -1.0;
  iobj_2->ParentIndex = -1.0;
  iobj_2->MassInternal = 1.0;
  iobj_2->CenterOfMassInternal[0] = 0.0;
  iobj_2->CenterOfMassInternal[1] = 0.0;
  iobj_2->CenterOfMassInternal[2] = 0.0;
  for (i = 0; i < 9; i++) {
    b_I[i] = 0;
  }
  b_I[0] = 1;
  b_I[4] = 1;
  b_I[8] = 1;
  for (i = 0; i < 9; i++) {
    iobj_2->InertiaInternal[i] = b_I[i];
  }
  for (i = 0; i < 36; i++) {
    c_I[i] = 0;
  }
  for (loop_ub = 0; loop_ub < 6; loop_ub++) {
    c_I[loop_ub + 6 * loop_ub] = 1;
  }
  for (i = 0; i < 36; i++) {
    iobj_2->SpatialInertia[i] = c_I[i];
  }
  real_T bodyin_idx_2;
  c_st.site = &u_emlrtRSI;
  iobj_2->CollisionsInternal =
      CollisionSet_CollisionSet(&c_st, &iobj_0[0], 0.0);
  iobj_2->matlabCodegenIsDeleted = false;
  b_st.site = &me_emlrtRSI;
  iobj_2->JointInternal =
      rigidBodyJoint_copy(&b_st, bodyin->JointInternal, &iobj_1[1]);
  iobj_2->MassInternal = bodyin->MassInternal;
  bid = bodyin->CenterOfMassInternal[0];
  obj_Length = bodyin->CenterOfMassInternal[1];
  bodyin_idx_2 = bodyin->CenterOfMassInternal[2];
  iobj_2->CenterOfMassInternal[0] = bid;
  iobj_2->CenterOfMassInternal[1] = obj_Length;
  iobj_2->CenterOfMassInternal[2] = bodyin_idx_2;
  for (i = 0; i < 9; i++) {
    b_bodyin[i] = bodyin->InertiaInternal[i];
  }
  for (i = 0; i < 9; i++) {
    iobj_2->InertiaInternal[i] = b_bodyin[i];
  }
  for (i = 0; i < 36; i++) {
    c_bodyin[i] = bodyin->SpatialInertia[i];
  }
  for (i = 0; i < 36; i++) {
    iobj_2->SpatialInertia[i] = c_bodyin[i];
  }
  b_st.site = &ne_emlrtRSI;
  iobj_2->CollisionsInternal =
      CollisionSet_copy(&b_st, bodyin->CollisionsInternal, &iobj_0[1]);
  if (b_index != (int32_T)muDoubleScalarFloor(b_index)) {
    emlrtIntegerCheckR2012b(b_index, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (((int32_T)b_index - 1 < 0) || ((int32_T)b_index - 1 > 5)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)b_index - 1, 0, 5, &q_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  obj->Bodies[(int32_T)b_index - 1] = iobj_2;
  iobj_2->Index = b_index;
  iobj_2->ParentIndex = pid;
  if ((pid > 0.0) && (((int32_T)pid - 1 < 0) || ((int32_T)pid - 1 > 5))) {
    emlrtDynamicBoundsCheckR2012b((int32_T)pid - 1, 0, 5, &r_emlrtBCI,
                                  (emlrtConstCTX)sp);
  }
  if (iobj_2->Index != (int32_T)muDoubleScalarFloor(iobj_2->Index)) {
    emlrtIntegerCheckR2012b(iobj_2->Index, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)iobj_2->Index;
  if ((i < 1) || (i > 6)) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 6, &l_emlrtBCI, (emlrtConstCTX)sp);
  }
  iobj_2->JointInternal->InTree = true;
  obj->NumBodies++;
  st.site = &yd_emlrtRSI;
  if (iobj_2->Index == 0.0) {
    b_st.site = &he_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
        &varargin_1[0]);
  }
  jnt = iobj_2->JointInternal;
  st.site = &yd_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  obj_Length = jnt->TypeInternal.Length;
  for (i = 0; i < 200; i++) {
    obj_Vector[i] = jnt->TypeInternal.Vector[i];
  }
  if (obj_Length < 1.0) {
    i = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    i = (int32_T)obj_Length;
  }
  b_bool = false;
  if (i == 5) {
    loop_ub = 0;
    int32_T exitg2;
    do {
      exitg2 = 0;
      if (loop_ub < 5) {
        if (obj_Vector[loop_ub] != b_cv[loop_ub]) {
          exitg2 = 1;
        } else {
          loop_ub++;
        }
      } else {
        b_bool = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  if (!b_bool) {
    obj->NumNonFixedBodies++;
    st.site = &ae_emlrtRSI;
    if (iobj_2->Index == 0.0) {
      b_st.site = &he_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &b_st, &d_emlrtRTEI,
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
          &varargin_1[0]);
    }
    jnt = iobj_2->JointInternal;
    if (iobj_2->Index != (int32_T)muDoubleScalarFloor(iobj_2->Index)) {
      emlrtIntegerCheckR2012b(iobj_2->Index, &k_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)iobj_2->Index < 1) || ((int32_T)iobj_2->Index > 6)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)iobj_2->Index, 1, 6, &m_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)iobj_2->Index - 1;
    obj->PositionDoFMap[loop_ub] = obj->PositionNumber + 1.0;
    obj->PositionDoFMap[loop_ub + 6] =
        obj->PositionNumber + jnt->PositionNumber;
    st.site = &be_emlrtRSI;
    if (iobj_2->Index == 0.0) {
      b_st.site = &he_emlrtRSI;
      emlrtErrorWithMessageIdR2018a(
          &b_st, &d_emlrtRTEI,
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
          "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
          &varargin_1[0]);
    }
    jnt = iobj_2->JointInternal;
    if (iobj_2->Index != (int32_T)muDoubleScalarFloor(iobj_2->Index)) {
      emlrtIntegerCheckR2012b(iobj_2->Index, &l_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)iobj_2->Index < 1) || ((int32_T)iobj_2->Index > 6)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)iobj_2->Index, 1, 6, &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)iobj_2->Index - 1;
    obj->VelocityDoFMap[loop_ub] = obj->VelocityNumber + 1.0;
    obj->VelocityDoFMap[loop_ub + 6] =
        obj->VelocityNumber + jnt->VelocityNumber;
  } else {
    if (iobj_2->Index != (int32_T)muDoubleScalarFloor(iobj_2->Index)) {
      emlrtIntegerCheckR2012b(iobj_2->Index, &m_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)iobj_2->Index < 1) || ((int32_T)iobj_2->Index > 6)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)iobj_2->Index, 1, 6, &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)iobj_2->Index;
    obj->PositionDoFMap[loop_ub - 1] = 0.0;
    obj->PositionDoFMap[loop_ub + 5] = -1.0;
    if (iobj_2->Index != (int32_T)muDoubleScalarFloor(iobj_2->Index)) {
      emlrtIntegerCheckR2012b(iobj_2->Index, &n_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)iobj_2->Index < 1) || ((int32_T)iobj_2->Index > 6)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)iobj_2->Index, 1, 6, &p_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)iobj_2->Index;
    obj->VelocityDoFMap[loop_ub - 1] = 0.0;
    obj->VelocityDoFMap[loop_ub + 5] = -1.0;
  }
  st.site = &ce_emlrtRSI;
  if (iobj_2->Index == 0.0) {
    b_st.site = &he_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
        &varargin_1[0]);
  }
  jnt = iobj_2->JointInternal;
  obj->PositionNumber += jnt->PositionNumber;
  st.site = &de_emlrtRSI;
  if (iobj_2->Index == 0.0) {
    b_st.site = &he_emlrtRSI;
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI,
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
        "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
        &varargin_1[0]);
  }
  jnt = iobj_2->JointInternal;
  obj->VelocityNumber += jnt->VelocityNumber;
}

void c_RigidBodyTree_bodyIndicesToPo(const emlrtStack *sp,
                                     const e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *bodyIndices,
                                     emxArray_real_T *posIndices)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *r;
  emxArray_int32_T *r2;
  emxArray_real_T *positionMap;
  emxArray_real_T *y;
  const real_T *bodyIndices_data;
  real_T d;
  real_T idxCount;
  real_T *posIndices_data;
  real_T *positionMap_data;
  real_T *y_data;
  int32_T end;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T nm1d2;
  int32_T *r1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  bodyIndices_data = bodyIndices->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  end = bodyIndices->size[0];
  nm1d2 = 0;
  for (i = 0; i < end; i++) {
    if (bodyIndices_data[i] != 0.0) {
      nm1d2++;
    }
  }
  emxInit_int32_T(sp, &r, 1, &fi_emlrtRTEI);
  k = r->size[0];
  r->size[0] = nm1d2;
  emxEnsureCapacity_int32_T(sp, r, k, &vh_emlrtRTEI);
  r1 = r->data;
  nm1d2 = 0;
  for (i = 0; i < end; i++) {
    if (bodyIndices_data[i] != 0.0) {
      r1[nm1d2] = i;
      nm1d2++;
    }
  }
  emxInit_real_T(sp, &positionMap, 2, &wh_emlrtRTEI);
  loop_ub = r->size[0];
  k = positionMap->size[0] * positionMap->size[1];
  positionMap->size[0] = r->size[0];
  positionMap->size[1] = 2;
  emxEnsureCapacity_real_T(sp, positionMap, k, &wh_emlrtRTEI);
  positionMap_data = positionMap->data;
  for (k = 0; k < 2; k++) {
    for (end = 0; end < loop_ub; end++) {
      if (r1[end] > bodyIndices->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(r1[end], 0, bodyIndices->size[0] - 1,
                                      &qe_emlrtBCI, (emlrtConstCTX)sp);
      }
      d = bodyIndices_data[r1[end]];
      if (d != (int32_T)muDoubleScalarFloor(d)) {
        emlrtIntegerCheckR2012b(d, &vc_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d < 1) || ((int32_T)d > 6)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 6, &pe_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      positionMap_data[end + positionMap->size[0] * k] =
          obj->PositionDoFMap[((int32_T)d + 6 * k) - 1];
    }
  }
  emxFree_int32_T(sp, &r);
  if (!(obj->PositionNumber >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->PositionNumber, &uc_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  d = obj->PositionNumber;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &tc_emlrtDCI, (emlrtConstCTX)sp);
  }
  k = posIndices->size[0] * posIndices->size[1];
  posIndices->size[0] = 1;
  nm1d2 = (int32_T)d;
  posIndices->size[1] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, posIndices, k, &xh_emlrtRTEI);
  posIndices_data = posIndices->data;
  for (k = 0; k < nm1d2; k++) {
    posIndices_data[k] = 0.0;
  }
  idxCount = 0.0;
  emxInit_int32_T(sp, &r2, 2, &ei_emlrtRTEI);
  emxInit_real_T(sp, &y, 2, &gi_emlrtRTEI);
  y_data = y->data;
  for (i = 0; i < loop_ub; i++) {
    real_T numPositions_tmp;
    if (i + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, loop_ub, &oe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    numPositions_tmp =
        positionMap_data[i + positionMap->size[0]] - positionMap_data[i];
    if (numPositions_tmp + 1.0 > 0.0) {
      real_T a;
      real_T b;
      if (numPositions_tmp + 1.0 < 1.0) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = (int32_T)((numPositions_tmp + 1.0) - 1.0) + 1;
        emxEnsureCapacity_real_T(sp, y, k, &ai_emlrtRTEI);
        y_data = y->data;
        nm1d2 = (int32_T)((numPositions_tmp + 1.0) - 1.0);
        for (k = 0; k <= nm1d2; k++) {
          y_data[k] = (real_T)k + 1.0;
        }
      }
      k = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      nm1d2 = y->size[1];
      r2->size[1] = y->size[1];
      emxEnsureCapacity_int32_T(sp, r2, k, &bi_emlrtRTEI);
      r1 = r2->data;
      for (k = 0; k < nm1d2; k++) {
        a = idxCount + y_data[k];
        if (a != (int32_T)muDoubleScalarFloor(a)) {
          emlrtIntegerCheckR2012b(a, &wc_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)a < 1) || ((int32_T)a > (int32_T)d)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)a, 1, (int32_T)d, &re_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        r1[k] = (int32_T)a;
      }
      st.site = &vs_emlrtRSI;
      a = positionMap_data[i];
      b = positionMap_data[i + positionMap->size[0]];
      b_st.site = &jp_emlrtRSI;
      if (muDoubleScalarIsNaN(a) || muDoubleScalarIsNaN(b)) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, k, &ci_emlrtRTEI);
        y_data = y->data;
        y_data[0] = rtNaN;
      } else if (b < a) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else if ((muDoubleScalarIsInf(a) || muDoubleScalarIsInf(b)) &&
                 (a == b)) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = 1;
        emxEnsureCapacity_real_T(&b_st, y, k, &ci_emlrtRTEI);
        y_data = y->data;
        y_data[0] = rtNaN;
      } else if (muDoubleScalarFloor(a) == a) {
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        nm1d2 = (int32_T)numPositions_tmp;
        y->size[1] = (int32_T)numPositions_tmp + 1;
        emxEnsureCapacity_real_T(&b_st, y, k, &ci_emlrtRTEI);
        y_data = y->data;
        for (k = 0; k <= nm1d2; k++) {
          y_data[k] = a + (real_T)k;
        }
      } else {
        real_T apnd;
        real_T cdiff;
        real_T ndbl;
        c_st.site = &ws_emlrtRSI;
        ndbl = muDoubleScalarFloor(numPositions_tmp + 0.5);
        apnd = a + ndbl;
        cdiff = apnd - b;
        if (muDoubleScalarAbs(cdiff) <
            4.4408920985006262E-16 *
                muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
          ndbl++;
          apnd = b;
        } else if (cdiff > 0.0) {
          apnd = a + (ndbl - 1.0);
        } else {
          ndbl++;
        }
        if (ndbl >= 0.0) {
          end = (int32_T)ndbl;
        } else {
          end = 0;
        }
        d_st.site = &xs_emlrtRSI;
        if (ndbl > 2.147483647E+9) {
          emlrtErrorWithMessageIdR2018a(&d_st, &wb_emlrtRTEI,
                                        "Coder:MATLAB:pmaxsize",
                                        "Coder:MATLAB:pmaxsize", 0);
        }
        k = y->size[0] * y->size[1];
        y->size[0] = 1;
        y->size[1] = end;
        emxEnsureCapacity_real_T(&c_st, y, k, &di_emlrtRTEI);
        y_data = y->data;
        if (end > 0) {
          y_data[0] = a;
          if (end > 1) {
            y_data[end - 1] = apnd;
            nm1d2 = (end - 1) / 2;
            for (k = 0; k <= nm1d2 - 2; k++) {
              y_data[k + 1] = a + ((real_T)k + 1.0);
              y_data[(end - k) - 2] = apnd - ((real_T)k + 1.0);
            }
            if (nm1d2 << 1 == end - 1) {
              y_data[nm1d2] = (positionMap_data[i] + apnd) / 2.0;
            } else {
              y_data[nm1d2] = positionMap_data[i] + (real_T)nm1d2;
              y_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
            }
          }
        }
      }
      if (r2->size[1] != y->size[1]) {
        emlrtSubAssignSizeCheck1dR2017a(r2->size[1], y->size[1], &wb_emlrtECI,
                                        (emlrtConstCTX)sp);
      }
      nm1d2 = y->size[1] - 1;
      for (k = 0; k <= nm1d2; k++) {
        posIndices_data[r1[k] - 1] = y_data[k];
      }
      idxCount += numPositions_tmp + 1.0;
    }
  }
  emxFree_real_T(sp, &y);
  emxFree_int32_T(sp, &r2);
  emxFree_real_T(sp, &positionMap);
  if (idxCount < 1.0) {
    k = 0;
  } else {
    if ((int32_T)d < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)d, &ne_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (idxCount != (int32_T)muDoubleScalarFloor(idxCount)) {
      emlrtIntegerCheckR2012b(idxCount, &sc_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)idxCount < 1) || ((int32_T)idxCount > (int32_T)d)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)idxCount, 1, (int32_T)d,
                                    &me_emlrtBCI, (emlrtConstCTX)sp);
    }
    k = (int32_T)idxCount;
  }
  end = posIndices->size[0] * posIndices->size[1];
  posIndices->size[1] = k;
  emxEnsureCapacity_real_T(sp, posIndices, end, &yh_emlrtRTEI);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_RigidBodyTree_efficientFKAndJ(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *qv, real_T bid1,
                                     real_T T_data[], int32_T T_size[2],
                                     emxArray_real_T *Jac)
{
  static const char_T b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  c_robotics_manip_internal_Rigid *body1;
  c_robotics_manip_internal_Rigid *nextBody;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *C;
  emxArray_real_T *b_qv;
  emxArray_real_T *kinematicPathIndices;
  rigidBodyJoint *joint;
  real_T JacSlice_data[36];
  real_T X[36];
  real_T T1[16];
  real_T T1j[16];
  real_T Tj1[16];
  real_T b[16];
  real_T R[9];
  real_T tempR[9];
  const real_T *qv_data;
  real_T alpha1;
  real_T beta1;
  real_T *Jac_data;
  real_T *b_qv_data;
  real_T *kinematicPathIndices_data;
  int32_T JacSlice_size[2];
  int32_T b_iv[2];
  int32_T X_tmp;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T kstr;
  char_T TRANSA1;
  char_T TRANSB1;
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
  qv_data = qv->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (bid1 >= 0.0) {
    real_T d;
    int32_T loop_ub_tmp;
    if (bid1 == 0.0) {
      body1 = &obj->Base;
    } else {
      if (bid1 != (int32_T)muDoubleScalarFloor(bid1)) {
        emlrtIntegerCheckR2012b(bid1, &jc_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)bid1 - 1 < 0) || ((int32_T)bid1 - 1 > 5)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)bid1 - 1, 0, 5, &hd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      body1 = obj->Bodies[(int32_T)bid1 - 1];
    }
    emxInit_real_T(sp, &kinematicPathIndices, 2, &qf_emlrtRTEI);
    st.site = &vj_emlrtRSI;
    c_RigidBodyTree_kinematicPathIn(&st, obj, body1, &obj->Base,
                                    kinematicPathIndices);
    kinematicPathIndices_data = kinematicPathIndices->data;
    memset(&T1[0], 0, 16U * sizeof(real_T));
    T1[0] = 1.0;
    T1[5] = 1.0;
    T1[10] = 1.0;
    T1[15] = 1.0;
    if (!(obj->PositionNumber >= 0.0)) {
      emlrtNonNegativeCheckR2012b(obj->PositionNumber, &bc_emlrtDCI,
                                  (emlrtConstCTX)sp);
    }
    if (obj->PositionNumber !=
        (int32_T)muDoubleScalarFloor(obj->PositionNumber)) {
      emlrtIntegerCheckR2012b(obj->PositionNumber, &cc_emlrtDCI,
                              (emlrtConstCTX)sp);
    }
    d = obj->PositionNumber;
    i = Jac->size[0] * Jac->size[1];
    Jac->size[0] = 6;
    Jac->size[1] = (int32_T)d;
    emxEnsureCapacity_real_T(sp, Jac, i, &nf_emlrtRTEI);
    Jac_data = Jac->data;
    loop_ub_tmp = 6 * (int32_T)d;
    for (i = 0; i < loop_ub_tmp; i++) {
      Jac_data[i] = 0.0;
    }
    i = kinematicPathIndices->size[1];
    emxInit_real_T(sp, &C, 2, &rf_emlrtRTEI);
    emxInit_real_T(sp, &b_qv, 1, &pf_emlrtRTEI);
    for (b_i = 0; b_i <= i - 2; b_i++) {
      __m128d r;
      __m128d r1;
      real_T Tc2p[16];
      real_T b_tempR_tmp;
      real_T tempR_tmp;
      int32_T exitg1;
      int32_T jointSign;
      char_T obj_Vector[200];
      boolean_T b_bool;
      boolean_T nextBodyIsParent;
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &id_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      alpha1 = kinematicPathIndices_data[b_i];
      if (alpha1 != 0.0) {
        if (b_i + 1 > i) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &ld_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
          emlrtIntegerCheckR2012b(alpha1, &kc_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)alpha1 - 1 < 0) || ((int32_T)alpha1 - 1 > 5)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)alpha1 - 1, 0, 5, &kd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        body1 = obj->Bodies[(int32_T)alpha1 - 1];
      } else {
        body1 = &obj->Base;
      }
      if (b_i + 2 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, i, &jd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      alpha1 = kinematicPathIndices_data[b_i + 1];
      if (alpha1 != 0.0) {
        if (b_i + 2 > i) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, i, &nd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
          emlrtIntegerCheckR2012b(alpha1, &lc_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)alpha1 - 1 < 0) || ((int32_T)alpha1 - 1 > 5)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)alpha1 - 1, 0, 5, &md_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        nextBody = obj->Bodies[(int32_T)alpha1 - 1];
      } else {
        nextBody = &obj->Base;
      }
      nextBodyIsParent = (nextBody->Index == body1->ParentIndex);
      if (nextBodyIsParent) {
        nextBody = body1;
        jointSign = 1;
      } else {
        jointSign = -1;
      }
      joint = nextBody->JointInternal;
      st.site = &wj_emlrtRSI;
      b_st.site = &bb_emlrtRSI;
      alpha1 = joint->TypeInternal.Length;
      for (i1 = 0; i1 < 200; i1++) {
        obj_Vector[i1] = joint->TypeInternal.Vector[i1];
      }
      if (alpha1 < 1.0) {
        i1 = 0;
      } else {
        if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
          emlrtIntegerCheckR2012b(alpha1, &c_emlrtDCI, &b_st);
        }
        if (((int32_T)alpha1 < 1) || ((int32_T)alpha1 > 200)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)alpha1, 1, 200, &c_emlrtBCI,
                                        &b_st);
        }
        i1 = (int32_T)alpha1;
      }
      b_bool = false;
      if (i1 == 5) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 5) {
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
        real_T Tj[16];
        st.site = &xj_emlrtRSI;
        for (i1 = 0; i1 < 16; i1++) {
          Tj1[i1] = joint->JointToParentTransform[i1];
        }
        b_st.site = &fk_emlrtRSI;
        c_st.site = &gk_emlrtRSI;
        d_st.site = &bb_emlrtRSI;
        alpha1 = joint->TypeInternal.Length;
        for (i1 = 0; i1 < 200; i1++) {
          obj_Vector[i1] = joint->TypeInternal.Vector[i1];
        }
        if (alpha1 < 1.0) {
          i1 = 0;
        } else {
          if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
            emlrtIntegerCheckR2012b(alpha1, &c_emlrtDCI, &d_st);
          }
          if (((int32_T)alpha1 < 1) || ((int32_T)alpha1 > 200)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)alpha1, 1, 200, &c_emlrtBCI,
                                          &d_st);
          }
          i1 = (int32_T)alpha1;
        }
        b_bool = false;
        if (i1 == 8) {
          kstr = 0;
          do {
            exitg1 = 0;
            if (kstr < 8) {
              if (b_cv1[kstr] != obj_Vector[kstr]) {
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
          kstr = 0;
        } else {
          b_bool = false;
          if (i1 == 9) {
            kstr = 0;
            do {
              exitg1 = 0;
              if (kstr < 9) {
                if (cv3[kstr] != obj_Vector[kstr]) {
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
            kstr = 1;
          } else {
            b_bool = false;
            if (i1 == 8) {
              kstr = 0;
              do {
                exitg1 = 0;
                if (kstr < 8) {
                  if (b_cv2[kstr] != obj_Vector[kstr]) {
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
              kstr = 2;
            } else {
              kstr = -1;
            }
          }
        }
        switch (kstr) {
        case 0: {
          real_T b_v[3];
          real_T v[3];
          real_T c_tempR_tmp;
          real_T d_tempR_tmp;
          real_T e_tempR_tmp;
          real_T qidx_idx_0;
          real_T qidx_idx_1;
          c_st.site = &hk_emlrtRSI;
          rigidBodyJoint_get_JointAxis(&c_st, joint, v);
          c_st.site = &ik_emlrtRSI;
          d_st.site = &lk_emlrtRSI;
          e_st.site = &mk_emlrtRSI;
          f_st.site = &nk_emlrtRSI;
          normalizeRows(&f_st, v, b_v);
          alpha1 = b_v[0] * b_v[1] * 0.0;
          beta1 = b_v[0] * b_v[2] * 0.0;
          tempR_tmp = b_v[1] * b_v[2] * 0.0;
          b_tempR_tmp = b_v[0] * b_v[0] * 0.0 + 1.0;
          qidx_idx_0 = alpha1 - b_v[2] * 0.0;
          qidx_idx_1 = beta1 + b_v[1] * 0.0;
          alpha1 += b_v[2] * 0.0;
          c_tempR_tmp = b_v[1] * b_v[1] * 0.0 + 1.0;
          d_tempR_tmp = tempR_tmp - b_v[0] * 0.0;
          beta1 -= b_v[1] * 0.0;
          tempR_tmp += b_v[0] * 0.0;
          e_tempR_tmp = b_v[2] * b_v[2] * 0.0 + 1.0;
          cat(b_tempR_tmp, qidx_idx_0, qidx_idx_1, alpha1, c_tempR_tmp,
              d_tempR_tmp, beta1, tempR_tmp, e_tempR_tmp, tempR);
          cat(b_tempR_tmp, qidx_idx_0, qidx_idx_1, alpha1, c_tempR_tmp,
              d_tempR_tmp, beta1, tempR_tmp, e_tempR_tmp, R);
          for (kstr = 0; kstr < 3; kstr++) {
            R[kstr] = tempR[3 * kstr];
            R[kstr + 3] = tempR[3 * kstr + 1];
            R[kstr + 6] = tempR[3 * kstr + 2];
          }
          memset(&b[0], 0, 16U * sizeof(real_T));
          for (i1 = 0; i1 < 3; i1++) {
            kstr = i1 << 2;
            b[kstr] = R[3 * i1];
            b[kstr + 1] = R[3 * i1 + 1];
            b[kstr + 2] = R[3 * i1 + 2];
          }
          b[15] = 1.0;
        } break;
        case 1: {
          real_T v[3];
          c_st.site = &jk_emlrtRSI;
          rigidBodyJoint_get_JointAxis(&c_st, joint, v);
          memset(&R[0], 0, 9U * sizeof(real_T));
          R[0] = 1.0;
          R[4] = 1.0;
          R[8] = 1.0;
          for (i1 = 0; i1 < 3; i1++) {
            kstr = i1 << 2;
            b[kstr] = R[3 * i1];
            b[kstr + 1] = R[3 * i1 + 1];
            b[kstr + 2] = R[3 * i1 + 2];
            b[i1 + 12] = v[i1] * 0.0;
          }
          b[3] = 0.0;
          b[7] = 0.0;
          b[11] = 0.0;
          b[15] = 1.0;
        } break;
        case 2:
          emlrtDynamicBoundsCheckR2012b(5, 1, 1, &od_emlrtBCI, &b_st);
          break;
        default:
          memset(&b[0], 0, 16U * sizeof(real_T));
          b[0] = 1.0;
          b[5] = 1.0;
          b[10] = 1.0;
          b[15] = 1.0;
          break;
        }
        for (i1 = 0; i1 < 16; i1++) {
          Tj[i1] = joint->ChildToJointTransform[i1];
        }
        for (i1 = 0; i1 < 4; i1++) {
          alpha1 = Tj1[i1];
          beta1 = Tj1[i1 + 4];
          tempR_tmp = Tj1[i1 + 8];
          b_tempR_tmp = Tj1[i1 + 12];
          for (kstr = 0; kstr < 4; kstr++) {
            X_tmp = kstr << 2;
            T1j[i1 + X_tmp] = ((alpha1 * b[X_tmp] + beta1 * b[X_tmp + 1]) +
                               tempR_tmp * b[X_tmp + 2]) +
                              b_tempR_tmp * b[X_tmp + 3];
          }
          alpha1 = T1j[i1];
          beta1 = T1j[i1 + 4];
          tempR_tmp = T1j[i1 + 8];
          b_tempR_tmp = T1j[i1 + 12];
          for (kstr = 0; kstr < 4; kstr++) {
            X_tmp = kstr << 2;
            Tc2p[i1 + X_tmp] = ((alpha1 * Tj[X_tmp] + beta1 * Tj[X_tmp + 1]) +
                                tempR_tmp * Tj[X_tmp + 2]) +
                               b_tempR_tmp * Tj[X_tmp + 3];
          }
        }
      } else {
        real_T Tj[16];
        real_T qidx_idx_0;
        real_T qidx_idx_1;
        int32_T loop_ub;
        if (nextBody->Index != (int32_T)muDoubleScalarFloor(nextBody->Index)) {
          emlrtIntegerCheckR2012b(nextBody->Index, &dc_emlrtDCI,
                                  (emlrtConstCTX)sp);
        }
        if (((int32_T)nextBody->Index < 1) || ((int32_T)nextBody->Index > 6)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)nextBody->Index, 1, 6,
                                        &bd_emlrtBCI, (emlrtConstCTX)sp);
        }
        kstr = (int32_T)nextBody->Index;
        qidx_idx_0 = obj->PositionDoFMap[kstr - 1];
        qidx_idx_1 = obj->PositionDoFMap[kstr + 5];
        if (qidx_idx_0 > qidx_idx_1) {
          i1 = 0;
          kstr = 0;
        } else {
          if (qidx_idx_0 != (int32_T)muDoubleScalarFloor(qidx_idx_0)) {
            emlrtIntegerCheckR2012b(qidx_idx_0, &ec_emlrtDCI,
                                    (emlrtConstCTX)sp);
          }
          if (((int32_T)qidx_idx_0 < 1) ||
              ((int32_T)qidx_idx_0 > qv->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)qidx_idx_0, 1, qv->size[0],
                                          &cd_emlrtBCI, (emlrtConstCTX)sp);
          }
          i1 = (int32_T)qidx_idx_0 - 1;
          if (qidx_idx_1 != (int32_T)muDoubleScalarFloor(qidx_idx_1)) {
            emlrtIntegerCheckR2012b(qidx_idx_1, &fc_emlrtDCI,
                                    (emlrtConstCTX)sp);
          }
          if (((int32_T)qidx_idx_1 < 1) ||
              ((int32_T)qidx_idx_1 > qv->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)qidx_idx_1, 1, qv->size[0],
                                          &dd_emlrtBCI, (emlrtConstCTX)sp);
          }
          kstr = (int32_T)qidx_idx_1;
        }
        b_iv[0] = 1;
        loop_ub = kstr - i1;
        b_iv[1] = loop_ub;
        st.site = &yj_emlrtRSI;
        indexShapeCheck(&st, qv->size[0], b_iv);
        kstr = b_qv->size[0];
        b_qv->size[0] = loop_ub;
        emxEnsureCapacity_real_T(sp, b_qv, kstr, &pf_emlrtRTEI);
        b_qv_data = b_qv->data;
        for (kstr = 0; kstr < loop_ub; kstr++) {
          b_qv_data[kstr] = qv_data[i1 + kstr];
        }
        st.site = &yj_emlrtRSI;
        c_rigidBodyJoint_transformBodyT(&st, joint, b_qv, Tc2p);
        if (nextBody->Index != (int32_T)muDoubleScalarFloor(nextBody->Index)) {
          emlrtIntegerCheckR2012b(nextBody->Index, &gc_emlrtDCI,
                                  (emlrtConstCTX)sp);
        }
        if (((int32_T)nextBody->Index < 1) || ((int32_T)nextBody->Index > 6)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)nextBody->Index, 1, 6,
                                        &ed_emlrtBCI, (emlrtConstCTX)sp);
        }
        kstr = (int32_T)nextBody->Index;
        qidx_idx_0 = obj->VelocityDoFMap[kstr - 1];
        qidx_idx_1 = obj->VelocityDoFMap[kstr + 5];
        if (nextBodyIsParent) {
          for (i1 = 0; i1 < 16; i1++) {
            Tj[i1] = joint->ChildToJointTransform[i1];
          }
        } else {
          for (i1 = 0; i1 < 16; i1++) {
            Tj1[i1] = joint->JointToParentTransform[i1];
          }
          for (i1 = 0; i1 < 3; i1++) {
            R[3 * i1] = Tj1[i1];
            R[3 * i1 + 1] = Tj1[i1 + 4];
            R[3 * i1 + 2] = Tj1[i1 + 8];
          }
          r = _mm_loadu_pd(&R[0]);
          r1 = _mm_set1_pd(-1.0);
          _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[2]);
          _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[4]);
          _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
          r = _mm_loadu_pd(&R[6]);
          _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
          tempR[8] = -R[8];
          alpha1 = Tj1[12];
          beta1 = Tj1[13];
          tempR_tmp = Tj1[14];
          for (i1 = 0; i1 < 3; i1++) {
            kstr = i1 << 2;
            Tj[kstr] = R[3 * i1];
            Tj[kstr + 1] = R[3 * i1 + 1];
            Tj[kstr + 2] = R[3 * i1 + 2];
            Tj[i1 + 12] = (tempR[i1] * alpha1 + tempR[i1 + 3] * beta1) +
                          tempR[i1 + 6] * tempR_tmp;
          }
          Tj[3] = 0.0;
          Tj[7] = 0.0;
          Tj[11] = 0.0;
          Tj[15] = 1.0;
        }
        for (i1 = 0; i1 < 4; i1++) {
          alpha1 = Tj[i1];
          beta1 = Tj[i1 + 4];
          tempR_tmp = Tj[i1 + 8];
          b_tempR_tmp = Tj[i1 + 12];
          for (kstr = 0; kstr < 4; kstr++) {
            X_tmp = kstr << 2;
            T1j[i1 + X_tmp] = ((alpha1 * T1[X_tmp] + beta1 * T1[X_tmp + 1]) +
                               tempR_tmp * T1[X_tmp + 2]) +
                              b_tempR_tmp * T1[X_tmp + 3];
          }
        }
        for (i1 = 0; i1 < 3; i1++) {
          R[3 * i1] = T1j[i1];
          R[3 * i1 + 1] = T1j[i1 + 4];
          R[3 * i1 + 2] = T1j[i1 + 8];
        }
        r = _mm_loadu_pd(&R[0]);
        r1 = _mm_set1_pd(-1.0);
        _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[2]);
        _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[4]);
        _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[6]);
        _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
        tempR[8] = -R[8];
        alpha1 = T1j[12];
        beta1 = T1j[13];
        tempR_tmp = T1j[14];
        for (i1 = 0; i1 < 3; i1++) {
          kstr = i1 << 2;
          Tj1[kstr] = R[3 * i1];
          Tj1[kstr + 1] = R[3 * i1 + 1];
          Tj1[kstr + 2] = R[3 * i1 + 2];
          Tj1[i1 + 12] = (tempR[i1] * alpha1 + tempR[i1 + 3] * beta1) +
                         tempR[i1 + 6] * tempR_tmp;
        }
        Tj1[3] = 0.0;
        Tj1[7] = 0.0;
        Tj1[11] = 0.0;
        Tj1[15] = 1.0;
        st.site = &bk_emlrtRSI;
        R[0] = 0.0;
        R[3] = -Tj1[14];
        R[6] = Tj1[13];
        R[1] = Tj1[14];
        R[4] = 0.0;
        R[7] = -Tj1[12];
        R[2] = -Tj1[13];
        R[5] = Tj1[12];
        R[8] = 0.0;
        for (i1 = 0; i1 < 3; i1++) {
          alpha1 = R[i1];
          beta1 = R[i1 + 3];
          tempR_tmp = R[i1 + 6];
          for (kstr = 0; kstr < 3; kstr++) {
            X_tmp = kstr << 2;
            tempR[i1 + 3 * kstr] =
                (alpha1 * Tj1[X_tmp] + beta1 * Tj1[X_tmp + 1]) +
                tempR_tmp * Tj1[X_tmp + 2];
            X[kstr + 6 * i1] = Tj1[kstr + (i1 << 2)];
            X[kstr + 6 * (i1 + 3)] = 0.0;
          }
        }
        for (i1 = 0; i1 < 3; i1++) {
          X[6 * i1 + 3] = tempR[3 * i1];
          kstr = i1 << 2;
          X_tmp = 6 * (i1 + 3);
          X[X_tmp + 3] = Tj1[kstr];
          X[6 * i1 + 4] = tempR[3 * i1 + 1];
          X[X_tmp + 4] = Tj1[kstr + 1];
          X[6 * i1 + 5] = tempR[3 * i1 + 2];
          X[X_tmp + 5] = Tj1[kstr + 2];
        }
        b_st.site = &ak_emlrtRSI;
        c_rigidBodyJoint_get_MotionSubs(&b_st, joint, JacSlice_data,
                                        JacSlice_size);
        b_st.site = &dl_emlrtRSI;
        if (JacSlice_size[1] == 0) {
          JacSlice_size[1] = 0;
        } else {
          c_st.site = &el_emlrtRSI;
          d_st.site = &fl_emlrtRSI;
          TRANSB1 = 'N';
          TRANSA1 = 'N';
          alpha1 = 1.0;
          beta1 = 0.0;
          m_t = (ptrdiff_t)6;
          n_t = (ptrdiff_t)JacSlice_size[1];
          k_t = (ptrdiff_t)6;
          lda_t = (ptrdiff_t)6;
          ldb_t = (ptrdiff_t)6;
          ldc_t = (ptrdiff_t)6;
          i1 = C->size[0] * C->size[1];
          C->size[0] = 6;
          C->size[1] = JacSlice_size[1];
          emxEnsureCapacity_real_T(&d_st, C, i1, &lf_emlrtRTEI);
          b_qv_data = C->data;
          dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &X[0], &lda_t,
                &JacSlice_data[0], &ldb_t, &beta1, &b_qv_data[0], &ldc_t);
          i1 = C->size[1];
          JacSlice_size[1] = i1;
          kstr = 6 * C->size[1];
          for (i1 = 0; i1 < kstr; i1++) {
            JacSlice_data[i1] = b_qv_data[i1];
          }
        }
        loop_ub = 6 * JacSlice_size[1];
        JacSlice_size[0] = 6;
        kstr = (loop_ub / 2) << 1;
        X_tmp = kstr - 2;
        for (i1 = 0; i1 <= X_tmp; i1 += 2) {
          r = _mm_loadu_pd(&JacSlice_data[i1]);
          _mm_storeu_pd(&JacSlice_data[i1],
                        _mm_mul_pd(r, _mm_set1_pd(jointSign)));
        }
        for (i1 = kstr; i1 < loop_ub; i1++) {
          JacSlice_data[i1] *= (real_T)jointSign;
        }
        if (qidx_idx_0 > qidx_idx_1) {
          i1 = 0;
          kstr = 0;
        } else {
          if (qidx_idx_0 != (int32_T)muDoubleScalarFloor(qidx_idx_0)) {
            emlrtIntegerCheckR2012b(qidx_idx_0, &hc_emlrtDCI,
                                    (emlrtConstCTX)sp);
          }
          if (((int32_T)qidx_idx_0 < 1) || ((int32_T)qidx_idx_0 > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)qidx_idx_0, 1, (int32_T)d,
                                          &fd_emlrtBCI, (emlrtConstCTX)sp);
          }
          i1 = (int32_T)qidx_idx_0 - 1;
          if (qidx_idx_1 != (int32_T)muDoubleScalarFloor(qidx_idx_1)) {
            emlrtIntegerCheckR2012b(qidx_idx_1, &ic_emlrtDCI,
                                    (emlrtConstCTX)sp);
          }
          if (((int32_T)qidx_idx_1 < 1) || ((int32_T)qidx_idx_1 > (int32_T)d)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)qidx_idx_1, 1, (int32_T)d,
                                          &gd_emlrtBCI, (emlrtConstCTX)sp);
          }
          kstr = (int32_T)qidx_idx_1;
        }
        b_iv[0] = 6;
        loop_ub = kstr - i1;
        b_iv[1] = loop_ub;
        emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &JacSlice_size[0], 2,
                                      &ob_emlrtECI, (emlrtCTX)sp);
        for (kstr = 0; kstr < loop_ub; kstr++) {
          for (X_tmp = 0; X_tmp < 6; X_tmp++) {
            Jac_data[X_tmp + 6 * (i1 + kstr)] = JacSlice_data[X_tmp + 6 * kstr];
          }
        }
      }
      if (nextBodyIsParent) {
        for (i1 = 0; i1 < 4; i1++) {
          alpha1 = Tc2p[i1];
          beta1 = Tc2p[i1 + 4];
          tempR_tmp = Tc2p[i1 + 8];
          b_tempR_tmp = Tc2p[i1 + 12];
          for (kstr = 0; kstr < 4; kstr++) {
            X_tmp = kstr << 2;
            T1j[i1 + X_tmp] = ((alpha1 * T1[X_tmp] + beta1 * T1[X_tmp + 1]) +
                               tempR_tmp * T1[X_tmp + 2]) +
                              b_tempR_tmp * T1[X_tmp + 3];
          }
        }
        memcpy(&T1[0], &T1j[0], 16U * sizeof(real_T));
      } else {
        for (i1 = 0; i1 < 3; i1++) {
          R[3 * i1] = Tc2p[i1];
          R[3 * i1 + 1] = Tc2p[i1 + 4];
          R[3 * i1 + 2] = Tc2p[i1 + 8];
        }
        r = _mm_loadu_pd(&R[0]);
        r1 = _mm_set1_pd(-1.0);
        _mm_storeu_pd(&tempR[0], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[2]);
        _mm_storeu_pd(&tempR[2], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[4]);
        _mm_storeu_pd(&tempR[4], _mm_mul_pd(r, r1));
        r = _mm_loadu_pd(&R[6]);
        _mm_storeu_pd(&tempR[6], _mm_mul_pd(r, r1));
        tempR[8] = -R[8];
        alpha1 = Tc2p[12];
        beta1 = Tc2p[13];
        tempR_tmp = Tc2p[14];
        for (i1 = 0; i1 < 3; i1++) {
          kstr = i1 << 2;
          T1j[kstr] = R[3 * i1];
          T1j[kstr + 1] = R[3 * i1 + 1];
          T1j[kstr + 2] = R[3 * i1 + 2];
          T1j[i1 + 12] = (tempR[i1] * alpha1 + tempR[i1 + 3] * beta1) +
                         tempR[i1 + 6] * tempR_tmp;
        }
        T1j[3] = 0.0;
        T1j[7] = 0.0;
        T1j[11] = 0.0;
        T1j[15] = 1.0;
        for (i1 = 0; i1 < 4; i1++) {
          alpha1 = T1j[i1];
          beta1 = T1j[i1 + 4];
          tempR_tmp = T1j[i1 + 8];
          b_tempR_tmp = T1j[i1 + 12];
          for (kstr = 0; kstr < 4; kstr++) {
            X_tmp = kstr << 2;
            Tj1[i1 + X_tmp] = ((alpha1 * T1[X_tmp] + beta1 * T1[X_tmp + 1]) +
                               tempR_tmp * T1[X_tmp + 2]) +
                              b_tempR_tmp * T1[X_tmp + 3];
          }
        }
        memcpy(&T1[0], &Tj1[0], 16U * sizeof(real_T));
      }
    }
    emxFree_real_T(sp, &b_qv);
    emxFree_real_T(sp, &kinematicPathIndices);
    for (i = 0; i < 3; i++) {
      i1 = i << 2;
      alpha1 = T1[i1];
      X[6 * i] = alpha1;
      kstr = 6 * (i + 3);
      X[kstr] = 0.0;
      X[6 * i + 3] = 0.0;
      X[kstr + 3] = alpha1;
      alpha1 = T1[i1 + 1];
      X[6 * i + 1] = alpha1;
      X[kstr + 1] = 0.0;
      X[6 * i + 4] = 0.0;
      X[kstr + 4] = alpha1;
      alpha1 = T1[i1 + 2];
      X[6 * i + 2] = alpha1;
      X[kstr + 2] = 0.0;
      X[6 * i + 5] = 0.0;
      X[kstr + 5] = alpha1;
    }
    st.site = &ck_emlrtRSI;
    b_st.site = &dl_emlrtRSI;
    if (Jac->size[1] == 0) {
      Jac->size[0] = 6;
      Jac->size[1] = 0;
    } else {
      c_st.site = &el_emlrtRSI;
      d_st.site = &fl_emlrtRSI;
      i = C->size[0] * C->size[1];
      C->size[0] = 6;
      C->size[1] = (int32_T)d;
      emxEnsureCapacity_real_T(&d_st, C, i, &of_emlrtRTEI);
      b_qv_data = C->data;
      for (i = 0; i < loop_ub_tmp; i++) {
        b_qv_data[i] = Jac_data[i];
      }
      TRANSB1 = 'N';
      TRANSA1 = 'N';
      alpha1 = 1.0;
      beta1 = 0.0;
      m_t = (ptrdiff_t)6;
      n_t = (ptrdiff_t)Jac->size[1];
      k_t = (ptrdiff_t)6;
      lda_t = (ptrdiff_t)6;
      ldb_t = (ptrdiff_t)6;
      ldc_t = (ptrdiff_t)6;
      i = Jac->size[0] * Jac->size[1];
      Jac->size[0] = 6;
      Jac->size[1] = (int32_T)d;
      emxEnsureCapacity_real_T(&d_st, Jac, i, &lf_emlrtRTEI);
      Jac_data = Jac->data;
      dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, &X[0], &lda_t,
            &b_qv_data[0], &ldb_t, &beta1, &Jac_data[0], &ldc_t);
    }
    emxFree_real_T(&b_st, &C);
    T_size[0] = 4;
    T_size[1] = 4;
    memcpy(&T_data[0], &T1[0], 16U * sizeof(real_T));
  } else {
    T_size[0] = 0;
    T_size[1] = 0;
    Jac->size[0] = 6;
    Jac->size[1] = 0;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

real_T c_RigidBodyTree_findBodyIndexBy(const emlrtStack *sp,
                                       e_robotics_manip_internal_Rigid *obj,
                                       const char_T bodyname_data[],
                                       const int32_T bodyname_size[2])
{
  c_robotics_manip_internal_Rigid *b_obj;
  emlrtStack b_st;
  emlrtStack st;
  real_T bid;
  real_T obj_Length;
  int32_T obj_Vector_size[2];
  int32_T loop_ub;
  char_T obj_Vector[200];
  char_T obj_Vector_data[200];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  bid = -1.0;
  st.site = &id_emlrtRSI;
  b_st.site = &pb_emlrtRSI;
  if (bodyname_size[1] == 0) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:findBodyIndexByName:expectedNonempty", 3, 4, 8, "bodyname");
  }
  st.site = &jd_emlrtRSI;
  b_st.site = &dd_emlrtRSI;
  obj_Length = obj->Base.NameInternal.Length;
  for (loop_ub = 0; loop_ub < 200; loop_ub++) {
    obj_Vector[loop_ub] = obj->Base.NameInternal.Vector[loop_ub];
  }
  if (obj_Length < 1.0) {
    loop_ub = 0;
  } else {
    if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
      emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
    }
    if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200, &c_emlrtBCI,
                                    &b_st);
    }
    loop_ub = (int32_T)obj_Length;
  }
  obj_Vector_size[0] = 1;
  obj_Vector_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&obj_Vector_data[0], &obj_Vector[0],
           (uint32_T)loop_ub * sizeof(char_T));
  }
  st.site = &jd_emlrtRSI;
  if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
               bodyname_size)) {
    bid = 0.0;
  } else {
    real_T d;
    int32_T i;
    boolean_T exitg1;
    d = obj->NumBodies;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                  &g_emlrtRTEI, (emlrtConstCTX)sp);
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= (int32_T)d - 1)) {
      st.site = &kd_emlrtRSI;
      if (i > 5) {
        emlrtDynamicBoundsCheckR2012b(6, 0, 5, &i_emlrtBCI, &st);
      }
      b_obj = obj->Bodies[i];
      b_st.site = &dd_emlrtRSI;
      obj_Length = b_obj->NameInternal.Length;
      for (loop_ub = 0; loop_ub < 200; loop_ub++) {
        obj_Vector[loop_ub] = b_obj->NameInternal.Vector[loop_ub];
      }
      if (obj_Length < 1.0) {
        loop_ub = 0;
      } else {
        if (obj_Length != (int32_T)muDoubleScalarFloor(obj_Length)) {
          emlrtIntegerCheckR2012b(obj_Length, &c_emlrtDCI, &b_st);
        }
        if (((int32_T)obj_Length < 1) || ((int32_T)obj_Length > 200)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)obj_Length, 1, 200,
                                        &c_emlrtBCI, &b_st);
        }
        loop_ub = (int32_T)obj_Length;
      }
      obj_Vector_size[0] = 1;
      obj_Vector_size[1] = loop_ub;
      if (loop_ub - 1 >= 0) {
        memcpy(&obj_Vector_data[0], &obj_Vector[0],
               (uint32_T)loop_ub * sizeof(char_T));
      }
      st.site = &kd_emlrtRSI;
      if (b_strcmp(obj_Vector_data, obj_Vector_size, bodyname_data,
                   bodyname_size)) {
        bid = (real_T)i + 1.0;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }
  return bid;
}

void c_RigidBodyTree_get_JointPositi(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     emxArray_real_T *limits)
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Rigid *body;
  emlrtStack b_st;
  emlrtStack st;
  rigidBodyJoint *b_obj;
  real_T tmp_data[14];
  real_T d;
  real_T k;
  real_T pnum;
  real_T *limits_data;
  int32_T b_iv[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!(obj->PositionNumber >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->PositionNumber, &fb_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  if (obj->PositionNumber !=
      (int32_T)muDoubleScalarFloor(obj->PositionNumber)) {
    emlrtIntegerCheckR2012b(obj->PositionNumber, &gb_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  d = obj->PositionNumber;
  i = limits->size[0] * limits->size[1];
  limits->size[0] = (int32_T)d;
  limits->size[1] = 2;
  emxEnsureCapacity_real_T(sp, limits, i, &mc_emlrtRTEI);
  limits_data = limits->data;
  loop_ub_tmp = (int32_T)d << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    limits_data[i] = 0.0;
  }
  k = 1.0;
  pnum = obj->NumBodies;
  i = (int32_T)pnum;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, pnum, mxDOUBLE_CLASS, (int32_T)pnum,
                                &q_emlrtRTEI, (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    char_T obj_Vector[200];
    boolean_T b_bool;
    if (b_i > 5) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, 5, &kb_emlrtBCI, (emlrtConstCTX)sp);
    }
    body = obj->Bodies[b_i];
    st.site = &cg_emlrtRSI;
    b_obj = body->JointInternal;
    b_st.site = &bb_emlrtRSI;
    pnum = b_obj->TypeInternal.Length;
    for (i1 = 0; i1 < 200; i1++) {
      obj_Vector[i1] = b_obj->TypeInternal.Vector[i1];
    }
    if (pnum < 1.0) {
      i1 = 0;
    } else {
      if (pnum != (int32_T)muDoubleScalarFloor(pnum)) {
        emlrtIntegerCheckR2012b(pnum, &c_emlrtDCI, &b_st);
      }
      if (((int32_T)pnum < 1) || ((int32_T)pnum > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)pnum, 1, 200, &c_emlrtBCI,
                                      &b_st);
      }
      i1 = (int32_T)pnum;
    }
    b_bool = false;
    if (i1 == 5) {
      loop_ub_tmp = 0;
      int32_T exitg1;
      do {
        exitg1 = 0;
        if (loop_ub_tmp < 5) {
          if (obj_Vector[loop_ub_tmp] != b_cv[loop_ub_tmp]) {
            exitg1 = 1;
          } else {
            loop_ub_tmp++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (!b_bool) {
      pnum = body->JointInternal->PositionNumber;
      pnum += k;
      if (k > pnum - 1.0) {
        i1 = 0;
        i2 = 0;
      } else {
        if (k != (int32_T)muDoubleScalarFloor(k)) {
          emlrtIntegerCheckR2012b(k, &hb_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)k < 1) || ((int32_T)k > (int32_T)d)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)k, 1, (int32_T)d, &ib_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        i1 = (int32_T)k - 1;
        if (pnum - 1.0 != (int32_T)muDoubleScalarFloor(pnum - 1.0)) {
          emlrtIntegerCheckR2012b(pnum - 1.0, &ib_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)(pnum - 1.0) < 1) ||
            ((int32_T)(pnum - 1.0) > (int32_T)d)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(pnum - 1.0), 1, (int32_T)d,
                                        &jb_emlrtBCI, (emlrtConstCTX)sp);
        }
        i2 = (int32_T)(pnum - 1.0);
      }
      st.site = &dg_emlrtRSI;
      c_rigidBodyJoint_get_PositionLi(&st, body->JointInternal, tmp_data,
                                      tmp_size);
      loop_ub_tmp = i2 - i1;
      b_iv[0] = loop_ub_tmp;
      b_iv[1] = 2;
      emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &tmp_size[0], 2, &j_emlrtECI,
                                    (emlrtCTX)sp);
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < loop_ub_tmp; i3++) {
          limits_data[(i1 + i3) + limits->size[0] * i2] =
              tmp_data[i3 + tmp_size[0] * i2];
        }
      }
      k = pnum;
    }
  }
}

void c_RigidBodyTree_validateConfigu(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     const struct_T Q[6], emxArray_real_T *qvec)
{
  static const char_T b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T varargin_1[5] = {'J', 'o', 'i', 'n', 't'};
  c_robotics_manip_internal_Rigid *body;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *lbOK;
  emxArray_boolean_T *ubOK;
  emxArray_int32_T *ii;
  emxArray_int32_T *indicesUpperBoundViolation;
  emxArray_real_T *limits;
  rigidBodyJoint *jnt;
  real_T d;
  real_T idx_idx_0;
  real_T *limits_data;
  real_T *qvec_data;
  int32_T obj_Vector_size[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T loop_ub;
  int32_T *ii_data;
  int32_T *indicesUpperBoundViolation_data;
  char_T obj_Vector[200];
  char_T obj_Vector_data[200];
  boolean_T *lbOK_data;
  boolean_T *ubOK_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &vg_emlrtRSI;
  idx_idx_0 = obj->NumNonFixedBodies;
  b_st.site = &ch_emlrtRSI;
  c_st.site = &pb_emlrtRSI;
  if ((!(muDoubleScalarFloor(idx_idx_0) == idx_idx_0)) ||
      muDoubleScalarIsInf(idx_idx_0) || (!(idx_idx_0 >= 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &w_emlrtRTEI,
                                  "Coder:toolbox:ValidateattributesBadNumel",
                                  "MATLAB:validateattributes:badnumel", 0);
  }
  if (!(idx_idx_0 == 6.0)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &x_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectNumel",
        "MATLAB:validateConfiguration:incorrectNumel", 5, 4, 5, "input", 6,
        idx_idx_0);
  }
  if (!(obj->PositionNumber >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->PositionNumber, &ac_emlrtDCI, &st);
  }
  d = obj->PositionNumber;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &yb_emlrtDCI, &st);
  }
  i = qvec->size[0];
  qvec->size[0] = (int32_T)d;
  emxEnsureCapacity_real_T(&st, qvec, i, &yc_emlrtRTEI);
  qvec_data = qvec->data;
  if (!(obj->PositionNumber >= 0.0)) {
    emlrtNonNegativeCheckR2012b(obj->PositionNumber, &ac_emlrtDCI, &st);
  }
  d = obj->PositionNumber;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &yb_emlrtDCI, &st);
  }
  loop_ub = (int32_T)d;
  for (i = 0; i < loop_ub; i++) {
    qvec_data[i] = 0.0;
  }
  d = obj->NumBodies;
  i = (int32_T)d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                &v_emlrtRTEI, &st);
  for (b_i = 0; b_i < i; b_i++) {
    boolean_T b_bool;
    if (b_i > 5) {
      emlrtDynamicBoundsCheckR2012b(b_i, 0, 5, &fc_emlrtBCI, &st);
    }
    body = obj->Bodies[b_i];
    b_st.site = &dh_emlrtRSI;
    jnt = body->JointInternal;
    c_st.site = &bb_emlrtRSI;
    idx_idx_0 = jnt->TypeInternal.Length;
    for (i1 = 0; i1 < 200; i1++) {
      obj_Vector[i1] = jnt->TypeInternal.Vector[i1];
    }
    if (idx_idx_0 < 1.0) {
      i1 = 0;
    } else {
      if (idx_idx_0 != (int32_T)muDoubleScalarFloor(idx_idx_0)) {
        emlrtIntegerCheckR2012b(idx_idx_0, &c_emlrtDCI, &c_st);
      }
      if (((int32_T)idx_idx_0 < 1) || ((int32_T)idx_idx_0 > 200)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)idx_idx_0, 1, 200, &c_emlrtBCI,
                                      &c_st);
      }
      i1 = (int32_T)idx_idx_0;
    }
    b_bool = false;
    if (i1 == 5) {
      idx = 0;
      int32_T exitg1;
      do {
        exitg1 = 0;
        if (idx < 5) {
          if (obj_Vector[idx] != b_cv[idx]) {
            exitg1 = 1;
          } else {
            idx++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (!b_bool) {
      real_T idx_idx_1;
      int32_T j;
      boolean_T exitg2;
      b_st.site = &eh_emlrtRSI;
      if (body->Index == 0.0) {
        c_st.site = &he_emlrtRSI;
        emlrtErrorWithMessageIdR2018a(
            &c_st, &d_emlrtRTEI,
            "robotics:robotmanip:rigidbody:NoSuchPropertyForBase",
            "robotics:robotmanip:rigidbody:NoSuchPropertyForBase", 3, 4, 5,
            &varargin_1[0]);
      }
      jnt = body->JointInternal;
      idx = -2;
      j = 0;
      exitg2 = false;
      while ((!exitg2) && (j < 6)) {
        b_st.site = &fh_emlrtRSI;
        c_st.site = &ie_emlrtRSI;
        idx_idx_0 = jnt->NameInternal.Length;
        for (i1 = 0; i1 < 200; i1++) {
          obj_Vector[i1] = jnt->NameInternal.Vector[i1];
        }
        if (idx_idx_0 < 1.0) {
          loop_ub = 0;
        } else {
          if (idx_idx_0 != (int32_T)muDoubleScalarFloor(idx_idx_0)) {
            emlrtIntegerCheckR2012b(idx_idx_0, &c_emlrtDCI, &c_st);
          }
          if (((int32_T)idx_idx_0 < 1) || ((int32_T)idx_idx_0 > 200)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)idx_idx_0, 1, 200,
                                          &c_emlrtBCI, &c_st);
          }
          loop_ub = (int32_T)idx_idx_0;
        }
        obj_Vector_size[0] = 1;
        obj_Vector_size[1] = loop_ub;
        if (loop_ub - 1 >= 0) {
          memcpy(&obj_Vector_data[0], &obj_Vector[0],
                 (uint32_T)loop_ub * sizeof(char_T));
        }
        b_st.site = &fh_emlrtRSI;
        if (b_strcmp(Q[j].JointName.data, Q[j].JointName.size, obj_Vector_data,
                     obj_Vector_size)) {
          idx = j;
          exitg2 = true;
        } else {
          j++;
        }
      }
      if (idx + 1 == -1) {
        b_st.site = &gh_emlrtRSI;
        emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                      "robotics:robotmanip:rigidbodytree:"
                                      "ConfigStructArrayInvalidJointNames",
                                      "robotics:robotmanip:rigidbodytree:"
                                      "ConfigStructArrayInvalidJointNames",
                                      0);
      }
      if (idx + 1 < 1) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 6, &cc_emlrtBCI, &st);
      }
      idx_idx_0 = jnt->PositionNumber;
      b_st.site = &hh_emlrtRSI;
      c_st.site = &pb_emlrtRSI;
      d = Q[idx].JointPosition;
      if (muDoubleScalarIsNaN(d)) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &e_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedNonNaN",
            "MATLAB:validateConfiguration:expectedNonNaN", 3, 4, 5, "input");
      }
      c_st.site = &pb_emlrtRSI;
      if (muDoubleScalarIsInf(Q[idx].JointPosition)) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &f_emlrtRTEI,
            "Coder:toolbox:ValidateattributesexpectedFinite",
            "MATLAB:validateConfiguration:expectedFinite", 3, 4, 5, "input");
      }
      c_st.site = &pb_emlrtRSI;
      if ((!(muDoubleScalarFloor(idx_idx_0) == idx_idx_0)) ||
          muDoubleScalarIsInf(idx_idx_0) || (!(idx_idx_0 >= 0.0))) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &w_emlrtRTEI, "Coder:toolbox:ValidateattributesBadNumel",
            "MATLAB:validateattributes:badnumel", 0);
      }
      if (!(idx_idx_0 == 1.0)) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &x_emlrtRTEI,
            "Coder:toolbox:ValidateattributesincorrectNumel",
            "MATLAB:validateConfiguration:incorrectNumel", 5, 4, 5, "input", 6,
            idx_idx_0);
      }
      idx_idx_0 = obj->PositionDoFMap[b_i];
      idx_idx_1 = obj->PositionDoFMap[b_i + 6];
      if (idx_idx_0 > idx_idx_1) {
        i1 = 0;
        idx = 0;
      } else {
        if (idx_idx_0 != (int32_T)muDoubleScalarFloor(idx_idx_0)) {
          emlrtIntegerCheckR2012b(idx_idx_0, &wb_emlrtDCI, &st);
        }
        if (((int32_T)idx_idx_0 < 1) || ((int32_T)idx_idx_0 > qvec->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx_idx_0, 1, qvec->size[0],
                                        &dc_emlrtBCI, &st);
        }
        i1 = (int32_T)idx_idx_0 - 1;
        if (idx_idx_1 != (int32_T)muDoubleScalarFloor(idx_idx_1)) {
          emlrtIntegerCheckR2012b(idx_idx_1, &xb_emlrtDCI, &st);
        }
        if (((int32_T)idx_idx_1 < 1) || ((int32_T)idx_idx_1 > qvec->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)idx_idx_1, 1, qvec->size[0],
                                        &ec_emlrtBCI, &st);
        }
        idx = (int32_T)idx_idx_1;
      }
      loop_ub = idx - i1;
      for (idx = 0; idx < loop_ub; idx++) {
        qvec_data[i1 + idx] = d;
      }
    }
  }
  emxInit_real_T(sp, &limits, 2, &gd_emlrtRTEI);
  st.site = &wg_emlrtRSI;
  c_RigidBodyTree_get_JointPositi(&st, obj, limits);
  limits_data = limits->data;
  loop_ub = qvec->size[0];
  if ((qvec->size[0] != limits->size[0]) &&
      ((qvec->size[0] != 1) && (limits->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(qvec->size[0], limits->size[0], &o_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_boolean_T(sp, &ubOK, &ad_emlrtRTEI);
  if (qvec->size[0] == limits->size[0]) {
    i = ubOK->size[0];
    ubOK->size[0] = qvec->size[0];
    emxEnsureCapacity_boolean_T(sp, ubOK, i, &ad_emlrtRTEI);
    ubOK_data = ubOK->data;
    for (i = 0; i < loop_ub; i++) {
      ubOK_data[i] = (qvec_data[i] <= limits_data[i + limits->size[0]] +
                                          4.4408920985006262E-16);
    }
  } else {
    st.site = &nt_emlrtRSI;
    binary_expand_op_1(&st, ubOK, qvec, limits);
    ubOK_data = ubOK->data;
  }
  loop_ub = qvec->size[0];
  if ((qvec->size[0] != limits->size[0]) &&
      ((qvec->size[0] != 1) && (limits->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(qvec->size[0], limits->size[0], &p_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_boolean_T(sp, &lbOK, &bd_emlrtRTEI);
  if (qvec->size[0] == limits->size[0]) {
    i = lbOK->size[0];
    lbOK->size[0] = qvec->size[0];
    emxEnsureCapacity_boolean_T(sp, lbOK, i, &bd_emlrtRTEI);
    lbOK_data = lbOK->data;
    for (i = 0; i < loop_ub; i++) {
      lbOK_data[i] = (qvec_data[i] >= limits_data[i] - 4.4408920985006262E-16);
    }
  } else {
    st.site = &ot_emlrtRSI;
    binary_expand_op(&st, lbOK, qvec, limits);
    lbOK_data = lbOK->data;
  }
  emxInit_int32_T(sp, &indicesUpperBoundViolation, 1, &cd_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 1, &hd_emlrtRTEI);
  st.site = &xg_emlrtRSI;
  if ((!all(&st, ubOK)) || (!all(&st, lbOK))) {
    st.site = &yg_emlrtRSI;
    loop_ub = ubOK->size[0];
    for (i = 0; i < loop_ub; i++) {
      ubOK_data[i] = !ubOK_data[i];
    }
    b_st.site = &kh_emlrtRSI;
    eml_find(&b_st, ubOK, ii);
    ii_data = ii->data;
    loop_ub = ii->size[0];
    i = indicesUpperBoundViolation->size[0];
    indicesUpperBoundViolation->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, indicesUpperBoundViolation, i,
                              &cd_emlrtRTEI);
    indicesUpperBoundViolation_data = indicesUpperBoundViolation->data;
    for (i = 0; i < loop_ub; i++) {
      indicesUpperBoundViolation_data[i] = ii_data[i];
    }
    i = ii->size[0];
    ii->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(sp, ii, i, &dd_emlrtRTEI);
    ii_data = ii->data;
    for (i = 0; i < loop_ub; i++) {
      if ((indicesUpperBoundViolation_data[i] < 1) ||
          (indicesUpperBoundViolation_data[i] > qvec->size[0])) {
        emlrtDynamicBoundsCheckR2012b(indicesUpperBoundViolation_data[i], 1,
                                      qvec->size[0], &gc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      ii_data[i] = indicesUpperBoundViolation_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      i1 = indicesUpperBoundViolation_data[i];
      if ((i1 < 1) || (i1 > limits->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, limits->size[0], &hc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    if (ii->size[0] != loop_ub) {
      emlrtSubAssignSizeCheck1dR2017a(ii->size[0], loop_ub, &q_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    for (i = 0; i < loop_ub; i++) {
      qvec_data[ii_data[i] - 1] =
          limits_data[(indicesUpperBoundViolation_data[i] + limits->size[0]) -
                      1];
    }
    st.site = &ah_emlrtRSI;
    loop_ub = lbOK->size[0];
    for (i = 0; i < loop_ub; i++) {
      lbOK_data[i] = !lbOK_data[i];
    }
    b_st.site = &kh_emlrtRSI;
    eml_find(&b_st, lbOK, ii);
    ii_data = ii->data;
    loop_ub = ii->size[0];
    i = indicesUpperBoundViolation->size[0];
    indicesUpperBoundViolation->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, indicesUpperBoundViolation, i,
                              &ed_emlrtRTEI);
    indicesUpperBoundViolation_data = indicesUpperBoundViolation->data;
    for (i = 0; i < loop_ub; i++) {
      indicesUpperBoundViolation_data[i] = ii_data[i];
    }
    i = ii->size[0];
    ii->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(sp, ii, i, &fd_emlrtRTEI);
    ii_data = ii->data;
    for (i = 0; i < loop_ub; i++) {
      if ((indicesUpperBoundViolation_data[i] < 1) ||
          (indicesUpperBoundViolation_data[i] > qvec->size[0])) {
        emlrtDynamicBoundsCheckR2012b(indicesUpperBoundViolation_data[i], 1,
                                      qvec->size[0], &ic_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      ii_data[i] = indicesUpperBoundViolation_data[i];
    }
    for (i = 0; i < loop_ub; i++) {
      i1 = indicesUpperBoundViolation_data[i];
      if ((i1 < 1) || (i1 > limits->size[0])) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, limits->size[0], &jc_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    if (ii->size[0] != loop_ub) {
      emlrtSubAssignSizeCheck1dR2017a(ii->size[0], loop_ub, &r_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    for (i = 0; i < loop_ub; i++) {
      qvec_data[ii_data[i] - 1] =
          limits_data[indicesUpperBoundViolation_data[i] - 1];
    }
    st.site = &bh_emlrtRSI;
    b_st.site = &lf_emlrtRSI;
    e_warning(&b_st);
  }
  emxFree_int32_T(sp, &ii);
  emxFree_int32_T(sp, &indicesUpperBoundViolation);
  emxFree_boolean_T(sp, &lbOK);
  emxFree_boolean_T(sp, &ubOK);
  emxFree_real_T(sp, &limits);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (RigidBodyTree.c) */
