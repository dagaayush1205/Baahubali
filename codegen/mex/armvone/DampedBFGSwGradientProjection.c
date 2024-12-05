/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * DampedBFGSwGradientProjection.c
 *
 * Code generation for function 'DampedBFGSwGradientProjection'
 *
 */

/* Include files */
#include "DampedBFGSwGradientProjection.h"
#include "IKHelpers.h"
#include "all.h"
#include "any.h"
#include "armvone_data.h"
#include "armvone_emxutil.h"
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "assertCompatibleDims.h"
#include "diag.h"
#include "div.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
#include "eml_qr.h"
#include "eye.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "inv.h"
#include "isPositiveDefinite.h"
#include "mldivide.h"
#include "mtimes.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "sqrt1.h"
#include "tic.h"
#include "toc.h"
#include "vAllOrAny.h"
#include "blas.h"
#include "emlrt.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo bi_emlrtRSI = {
    221,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ci_emlrtRSI = {
    227,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo di_emlrtRSI = {
    228,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ei_emlrtRSI = {
    232,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo fi_emlrtRSI = {
    233,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo gi_emlrtRSI = {
    240,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo hi_emlrtRSI = {
    241,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ii_emlrtRSI = {
    251,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ji_emlrtRSI = {
    254,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ki_emlrtRSI = {
    263,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo li_emlrtRSI = {
    266,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo mi_emlrtRSI = {
    267,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ni_emlrtRSI = {
    271,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo oi_emlrtRSI = {
    278,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo pi_emlrtRSI = {
    279,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo qi_emlrtRSI = {
    286,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ri_emlrtRSI = {
    294,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo si_emlrtRSI = {
    299,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ti_emlrtRSI = {
    314,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ui_emlrtRSI = {
    318,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo vi_emlrtRSI = {
    319,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo wi_emlrtRSI = {
    322,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo xi_emlrtRSI = {
    324,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo yi_emlrtRSI = {
    348,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo aj_emlrtRSI = {
    350,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo bj_emlrtRSI = {
    352,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo cj_emlrtRSI = {
    355,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo dj_emlrtRSI = {
    362,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ej_emlrtRSI = {
    365,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo fj_emlrtRSI = {
    376,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo gj_emlrtRSI = {
    383,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo hj_emlrtRSI = {
    392,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ij_emlrtRSI = {
    393,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo jj_emlrtRSI = {
    397,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo kj_emlrtRSI = {
    398,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo lj_emlrtRSI = {
    399,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo mj_emlrtRSI = {
    400,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo nj_emlrtRSI = {
    413,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo oj_emlrtRSI = {
    416,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo pj_emlrtRSI = {
    422,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo qj_emlrtRSI = {
    426,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo rj_emlrtRSI = {
    438,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo wm_emlrtRSI = {
    184,                                               /* lineNo */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo xm_emlrtRSI = {
    186,                                               /* lineNo */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo ym_emlrtRSI = {
    195,                                               /* lineNo */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo an_emlrtRSI = {
    206,                                               /* lineNo */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo bn_emlrtRSI = {
    11,                                                            /* lineNo */
    "rank",                                                        /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/rank.m" /* pathName
                                                                    */
};

static emlrtRSInfo cn_emlrtRSI = {
    20,                                                            /* lineNo */
    "local_rank",                                                  /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/rank.m" /* pathName
                                                                    */
};

static emlrtRSInfo dn_emlrtRSI = {
    31,                                                            /* lineNo */
    "local_rank",                                                  /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/rank.m" /* pathName
                                                                    */
};

static emlrtRSInfo en_emlrtRSI = {
    18,                                                           /* lineNo */
    "svd",                                                        /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName */
};

static emlrtRSInfo fn_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                      */
};

static emlrtRSInfo gn_emlrtRSI =
    {
        31,       /* lineNo */
        "xgesvd", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pathName */
};

static emlrtRSInfo hn_emlrtRSI =
    {
        205,            /* lineNo */
        "ceval_xgesvd", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pathName */
};

static emlrtRSInfo in_emlrtRSI = {
    17,                                                          /* lineNo */
    "qr",                                                        /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/qr.m" /* pathName */
};

static emlrtRSInfo uo_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/mldivide.m" /* pathName
                                                                     */
};

static emlrtRSInfo lq_emlrtRSI = {
    443,                                            /* lineNo */
    "DampedBFGSwGradientProjection/atLocalMinimum", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo xq_emlrtRSI =
    {
        34,               /* lineNo */
        "rdivide_helper", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
        "rdivide_helper.m" /* pathName */
};

static emlrtRSInfo yq_emlrtRSI = {
    53,    /* lineNo */
    "div", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                      */
};

static emlrtRSInfo ar_emlrtRSI = {
    17,                                                            /* lineNo */
    "max",                                                         /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                    */
};

static emlrtRSInfo br_emlrtRSI = {
    58,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                           */
};

static emlrtRSInfo cr_emlrtRSI = {
    97,        /* lineNo */
    "maximum", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                           */
};

static emlrtRSInfo dr_emlrtRSI =
    {
        238,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo er_emlrtRSI = {
    73,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo fr_emlrtRSI = {
    65,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo gr_emlrtRSI = {
    114,         /* lineNo */
    "findFirst", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo hr_emlrtRSI = {
    131,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo jr_emlrtRSI = {
    17,                                                            /* lineNo */
    "min",                                                         /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/datafun/min.m" /* pathName
                                                                    */
};

static emlrtRSInfo kr_emlrtRSI = {
    60,         /* lineNo */
    "minOrMax", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                           */
};

static emlrtRSInfo lr_emlrtRSI = {
    110,       /* lineNo */
    "minimum", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                           */
};

static emlrtRSInfo ur_emlrtRSI = {
    447,                                                    /* lineNo */
    "DampedBFGSwGradientProjection/searchDirectionInvalid", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    16,                                                             /* lineNo */
    19,                                                             /* colNo */
    "mldivide",                                                     /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/mldivide.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI =
    {
        198,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtECInfo s_emlrtECI = {
    2,                                             /* nDims */
    413,                                           /* lineNo */
    67,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo t_emlrtECI = {
    1,                                             /* nDims */
    413,                                           /* lineNo */
    67,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo u_emlrtECI = {
    2,                                             /* nDims */
    400,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo v_emlrtECI = {
    1,                                             /* nDims */
    400,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo w_emlrtECI = {
    2,                                             /* nDims */
    399,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo x_emlrtECI = {
    1,                                             /* nDims */
    399,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo y_emlrtECI = {
    1,                                             /* nDims */
    397,                                           /* lineNo */
    28,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo ab_emlrtECI = {
    1,                                             /* nDims */
    386,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo bb_emlrtECI = {
    2,                                             /* nDims */
    383,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo cb_emlrtECI = {
    1,                                             /* nDims */
    383,                                           /* lineNo */
    25,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    377,                                           /* lineNo */
    48,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtECInfo db_emlrtECI = {
    1,                                             /* nDims */
    364,                                           /* lineNo */
    24,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo eb_emlrtECI = {
    1,                                             /* nDims */
    362,                                           /* lineNo */
    64,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo fb_emlrtECI = {
    1,                                             /* nDims */
    348,                                           /* lineNo */
    60,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo gb_emlrtECI = {
    1,                                             /* nDims */
    319,                                           /* lineNo */
    32,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo hb_emlrtECI = {
    2,                                             /* nDims */
    299,                                           /* lineNo */
    30,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo ib_emlrtECI = {
    1,                                             /* nDims */
    299,                                           /* lineNo */
    30,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    298,                                           /* lineNo */
    55,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtECInfo jb_emlrtECI = {
    2,                                             /* nDims */
    294,                                           /* lineNo */
    30,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo kb_emlrtECI = {
    1,                                             /* nDims */
    294,                                           /* lineNo */
    30,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    287,                                           /* lineNo */
    57,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    248,                                           /* lineNo */
    21,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo lb_emlrtECI = {
    2,                                             /* nDims */
    241,                                           /* lineNo */
    21,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtECInfo mb_emlrtECI = {
    1,                                             /* nDims */
    241,                                           /* lineNo */
    21,                                            /* colNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    239,                                           /* lineNo */
    25,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    316,                                           /* lineNo */
    47,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    317,                                           /* lineNo */
    50,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    379,                                           /* lineNo */
    31,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    290,                                           /* lineNo */
    36,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    380,                                           /* lineNo */
    49,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    291,                                           /* lineNo */
    54,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    324,                                           /* lineNo */
    51,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    325,                                           /* lineNo */
    58,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,                                            /* iFirst */
    -1,                                            /* iLast */
    325,                                           /* lineNo */
    60,                                            /* colNo */
    "",                                            /* aName */
    "DampedBFGSwGradientProjection/solveInternal", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/svd.m" /* pName */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    205,                                               /* lineNo */
    30,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    205,                                               /* lineNo */
    28,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtECInfo pb_emlrtECI = {
    1,                                                 /* nDims */
    184,                                               /* lineNo */
    36,                                                /* colNo */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    185,                                               /* lineNo */
    43,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    208,                                               /* lineNo */
    42,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    209,                                               /* lineNo */
    27,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,                                                /* iFirst */
    -1,                                                /* iLast */
    206,                                               /* lineNo */
    49,                                                /* colNo */
    "",                                                /* aName */
    "DampedBFGSwGradientProjection/identifyActiveSet", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m", /* pName */
    0                                                  /* checkKind */
};

static emlrtECInfo qb_emlrtECI = {
    1,                                                      /* nDims */
    447,                                                    /* lineNo */
    45,                                                     /* colNo */
    "DampedBFGSwGradientProjection/searchDirectionInvalid", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo kd_emlrtRTEI = {
    218,                             /* lineNo */
    13,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ld_emlrtRTEI = {
    228,                             /* lineNo */
    13,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo md_emlrtRTEI = {
    244,                             /* lineNo */
    13,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo nd_emlrtRTEI = {
    239,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo
    od_emlrtRTEI =
        {
            76,                  /* lineNo */
            9,                   /* colNo */
            "eml_mtimes_helper", /* fName */
            "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/"
            "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    261,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo
    qd_emlrtRTEI =
        {
            86,                  /* lineNo */
            9,                   /* colNo */
            "eml_mtimes_helper", /* fName */
            "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/"
            "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    263,                             /* lineNo */
    36,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo sd_emlrtRTEI = {
    314,                             /* lineNo */
    32,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo td_emlrtRTEI = {
    316,                             /* lineNo */
    47,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ud_emlrtRTEI = {
    348,                             /* lineNo */
    62,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo vd_emlrtRTEI = {
    216,                             /* lineNo */
    48,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo wd_emlrtRTEI = {
    348,                             /* lineNo */
    60,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo xd_emlrtRTEI = {
    316,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo yd_emlrtRTEI = {
    317,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo
    ae_emlrtRTEI =
        {
            74,                  /* lineNo */
            9,                   /* colNo */
            "eml_mtimes_helper", /* fName */
            "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/ops/"
            "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo be_emlrtRTEI = {
    318,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ce_emlrtRTEI = {
    286,                             /* lineNo */
    26,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo de_emlrtRTEI = {
    364,                             /* lineNo */
    28,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ee_emlrtRTEI = {
    362,                             /* lineNo */
    68,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo fe_emlrtRTEI = {
    364,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ge_emlrtRTEI = {
    291,                             /* lineNo */
    26,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo he_emlrtRTEI = {
    365,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ie_emlrtRTEI = {
    362,                             /* lineNo */
    64,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo je_emlrtRTEI = {
    322,                             /* lineNo */
    30,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ke_emlrtRTEI = {
    322,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo le_emlrtRTEI = {
    386,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo me_emlrtRTEI = {
    294,                             /* lineNo */
    49,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ne_emlrtRTEI = {
    377,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo oe_emlrtRTEI = {
    298,                             /* lineNo */
    26,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo pe_emlrtRTEI = {
    380,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo qe_emlrtRTEI = {
    399,                             /* lineNo */
    33,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo re_emlrtRTEI = {
    431,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo se_emlrtRTEI = {
    424,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo te_emlrtRTEI = {
    432,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ue_emlrtRTEI = {
    400,                             /* lineNo */
    34,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ve_emlrtRTEI = {
    413,                             /* lineNo */
    67,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo we_emlrtRTEI = {
    232,                             /* lineNo */
    13,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo xe_emlrtRTEI = {
    233,                             /* lineNo */
    14,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ye_emlrtRTEI = {
    233,                             /* lineNo */
    24,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo af_emlrtRTEI = {
    266,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo bf_emlrtRTEI = {
    294,                             /* lineNo */
    26,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo cf_emlrtRTEI = {
    324,                             /* lineNo */
    51,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo df_emlrtRTEI = {
    240,                             /* lineNo */
    23,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    241,                             /* lineNo */
    25,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    392,                             /* lineNo */
    31,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    380,                             /* lineNo */
    49,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo hf_emlrtRTEI = {
    291,                             /* lineNo */
    54,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo xf_emlrtRTEI = {
    180,                             /* lineNo */
    13,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ag_emlrtRTEI = {
    184,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo bg_emlrtRTEI = {
    185,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo cg_emlrtRTEI = {
    208,                             /* lineNo */
    17,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo dg_emlrtRTEI = {
    20,                                                           /* lineNo */
    9,                                                            /* colNo */
    "svd",                                                        /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/svd.m" /* pName */
};

static emlrtRTEInfo eg_emlrtRTEI = {
    209,                             /* lineNo */
    27,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo fg_emlrtRTEI =
    {
        31,       /* lineNo */
        33,       /* colNo */
        "xgesvd", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pName */
};

static emlrtRTEInfo gg_emlrtRTEI = {
    206,                             /* lineNo */
    35,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo hg_emlrtRTEI = {
    206,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ig_emlrtRTEI =
    {
        98,       /* lineNo */
        20,       /* colNo */
        "xgesvd", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pName */
};

static emlrtRTEInfo jg_emlrtRTEI =
    {
        131,      /* lineNo */
        9,        /* colNo */
        "xgesvd", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pName */
};

static emlrtRTEInfo kg_emlrtRTEI =
    {
        129,      /* lineNo */
        33,       /* colNo */
        "xgesvd", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pName */
};

static emlrtRTEInfo lg_emlrtRTEI = {
    178,                             /* lineNo */
    32,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo mg_emlrtRTEI = {
    18,                                                           /* lineNo */
    9,                                                            /* colNo */
    "svd",                                                        /* fName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/matfun/svd.m" /* pName */
};

static emlrtRTEInfo ng_emlrtRTEI =
    {
        129,      /* lineNo */
        9,        /* colNo */
        "xgesvd", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pName */
};

static emlrtRTEInfo gh_emlrtRTEI = {
    443,                             /* lineNo */
    58,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo uh_emlrtRTEI = {
    447,                             /* lineNo */
    45,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo oi_emlrtRTEI = {
    241,                             /* lineNo */
    21,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo pi_emlrtRTEI = {
    299,                             /* lineNo */
    30,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo qi_emlrtRTEI = {
    397,                             /* lineNo */
    28,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ri_emlrtRTEI = {
    386,                             /* lineNo */
    25,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo si_emlrtRTEI = {
    364,                             /* lineNo */
    24,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRTEInfo ui_emlrtRTEI = {
    319,                             /* lineNo */
    32,                              /* colNo */
    "DampedBFGSwGradientProjection", /* fName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pName */
};

static emlrtRSInfo jt_emlrtRSI = {
    386,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo kt_emlrtRSI = {
    364,                                           /* lineNo */
    "DampedBFGSwGradientProjection/solveInternal", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/shared/robotics/robotutils/+robotics/"
    "+core/+internal/DampedBFGSwGradientProjection.m" /* pathName */
};

static emlrtRSInfo lt_emlrtRSI = {
    54,    /* lineNo */
    "div", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                      */
};

/* Function Declarations */
static void b_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2);

static void b_plus(const emlrtStack *sp, emxArray_real_T *in1,
                   const emxArray_real_T *in2);

static real_T binary_expand_op_2(const emlrtStack *sp, const emlrtRSInfo in1,
                                 const emxArray_real_T *in2,
                                 const emxArray_real_T *in3,
                                 c_robotics_core_internal_Damped *in4,
                                 real_T in5[36], emxArray_real_T *in6,
                                 c_robotics_manip_internal_IKExt **out2);

static void c_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2);

static void c_plus(const emlrtStack *sp, emxArray_real_T *in1,
                   const emxArray_real_T *in2);

static void d_DampedBFGSwGradientProjection(
    const emlrtStack *sp, const c_robotics_core_internal_Damped *obj,
    const emxArray_real_T *x, emxArray_boolean_T *activeSet,
    emxArray_real_T *A);

static boolean_T e_DampedBFGSwGradientProjection(
    const emlrtStack *sp, const c_robotics_core_internal_Damped *obj,
    const emxArray_real_T *Hg, const emxArray_real_T *alpha);

static boolean_T
f_DampedBFGSwGradientProjection(const emlrtStack *sp,
                                const c_robotics_core_internal_Damped *obj,
                                const emxArray_real_T *xNew);

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2);

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void b_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 1, &ri_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &ri_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] - in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ri_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void b_plus(const emlrtStack *sp, emxArray_real_T *in1,
                   const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 1, &qi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &qi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] + in2_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &qi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static real_T binary_expand_op_2(const emlrtStack *sp, const emlrtRSInfo in1,
                                 const emxArray_real_T *in2,
                                 const emxArray_real_T *in3,
                                 c_robotics_core_internal_Damped *in4,
                                 real_T in5[36], emxArray_real_T *in6,
                                 c_robotics_manip_internal_IKExt **out2)
{
  emlrtStack st;
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  const real_T *in3_data;
  real_T out1;
  real_T *b_in2_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  in3_data = in3->data;
  in2_data = in2->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 1, &ie_emlrtRTEI);
  if (in3->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &ie_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] + in3_data[i * stride_1_0];
  }
  st.site = (emlrtRSInfo *)&in1;
  out1 = IKHelpers_computeCost(&st, b_in2, in4->ExtraArgs, in5, in6, out2);
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return out1;
}

static void c_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 1, &ui_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &ui_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in2->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = in1_data[i * stride_0_0] - in2_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ui_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void c_plus(const emlrtStack *sp, emxArray_real_T *in1,
                   const emxArray_real_T *in2)
{
  emxArray_real_T *b_in2;
  const real_T *in2_data;
  real_T *b_in2_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in2, 1, &si_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in2->size[0];
  b_in2->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in2, i, &si_emlrtRTEI);
  b_in2_data = b_in2->data;
  stride_0_0 = (in2->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] + in1_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &si_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in2_data[i];
  }
  emxFree_real_T(sp, &b_in2);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void d_DampedBFGSwGradientProjection(
    const emlrtStack *sp, const c_robotics_core_internal_Damped *obj,
    const emxArray_real_T *x, emxArray_boolean_T *activeSet, emxArray_real_T *A)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'v', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *b_activeSetCols;
  emxArray_int32_T *b_p;
  emxArray_int32_T *ii;
  emxArray_real_T *A_;
  emxArray_real_T *Q;
  emxArray_real_T *R;
  emxArray_real_T *activeSetCols;
  emxArray_real_T *s;
  emxArray_real_T *superb;
  real_T *A__data;
  real_T *A_data;
  real_T *activeSetCols_data;
  real_T *s_data;
  int32_T exponent;
  int32_T i;
  int32_T irank;
  int32_T loop_ub;
  int32_T *ii_data;
  boolean_T *activeSet_data;
  boolean_T *b_activeSetCols_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  loop_ub = obj->ConstraintBound->size[0];
  i = activeSet->size[0];
  activeSet->size[0] = loop_ub;
  emxEnsureCapacity_boolean_T(sp, activeSet, i, &xf_emlrtRTEI);
  activeSet_data = activeSet->data;
  for (i = 0; i < loop_ub; i++) {
    activeSet_data[i] = false;
  }
  A->size[0] = x->size[0];
  A->size[1] = 0;
  if (obj->ConstraintsOn) {
    int32_T b_loop_ub;
    int32_T c_loop_ub;
    int32_T minnm;
    int32_T obj_tmp;
    st.site = &wm_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    if (obj->ConstraintMatrix->size[0] != x->size[0]) {
      if (((obj->ConstraintMatrix->size[0] == 1) &&
           (obj->ConstraintMatrix->size[1] == 1)) ||
          (x->size[0] == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &kb_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &jb_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    emxInit_real_T(&st, &activeSetCols, 1, &ag_emlrtRTEI);
    b_st.site = &dl_emlrtRSI;
    mtimes(&b_st, obj->ConstraintMatrix, x, activeSetCols);
    activeSetCols_data = activeSetCols->data;
    b_loop_ub = activeSetCols->size[0];
    if ((activeSetCols->size[0] != loop_ub) &&
        ((activeSetCols->size[0] != 1) && (loop_ub != 1))) {
      emlrtDimSizeImpxCheckR2021b(activeSetCols->size[0], loop_ub, &pb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    st.site = &wm_emlrtRSI;
    emxInit_int32_T(&st, &ii, 1, &hd_emlrtRTEI);
    if (activeSetCols->size[0] == obj->ConstraintBound->size[0]) {
      emxInit_boolean_T(&st, &b_activeSetCols, &yf_emlrtRTEI);
      i = b_activeSetCols->size[0];
      b_activeSetCols->size[0] = activeSetCols->size[0];
      emxEnsureCapacity_boolean_T(&st, b_activeSetCols, i, &yf_emlrtRTEI);
      b_activeSetCols_data = b_activeSetCols->data;
      for (i = 0; i < b_loop_ub; i++) {
        b_activeSetCols_data[i] =
            (activeSetCols_data[i] >= obj->ConstraintBound->data[i]);
      }
      b_st.site = &kh_emlrtRSI;
      eml_find(&b_st, b_activeSetCols, ii);
      ii_data = ii->data;
      emxFree_boolean_T(&st, &b_activeSetCols);
    } else {
      b_st.site = &kh_emlrtRSI;
      binary_expand_op_4(&b_st, ii, kh_emlrtRSI, activeSetCols, obj);
      ii_data = ii->data;
    }
    b_loop_ub = ii->size[0];
    i = activeSetCols->size[0];
    activeSetCols->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(&st, activeSetCols, i, &ag_emlrtRTEI);
    activeSetCols_data = activeSetCols->data;
    for (i = 0; i < b_loop_ub; i++) {
      activeSetCols_data[i] = ii_data[i];
    }
    obj_tmp = obj->ConstraintMatrix->size[1];
    emxInit_real_T(sp, &A_, 2, &bg_emlrtRTEI);
    c_loop_ub = obj->ConstraintMatrix->size[0];
    i = A_->size[0] * A_->size[1];
    A_->size[0] = c_loop_ub;
    A_->size[1] = ii->size[0];
    emxEnsureCapacity_real_T(sp, A_, i, &bg_emlrtRTEI);
    A__data = A_->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (irank = 0; irank < c_loop_ub; irank++) {
        minnm = (int32_T)activeSetCols_data[i];
        if ((minnm < 1) || (minnm > obj_tmp)) {
          emlrtDynamicBoundsCheckR2012b(minnm, 1, obj_tmp, &fe_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A__data[irank + A_->size[0] * i] =
            obj->ConstraintMatrix
                ->data[irank + obj->ConstraintMatrix->size[0] * (minnm - 1)];
      }
    }
    st.site = &xm_emlrtRSI;
    b_st.site = &bn_emlrtRSI;
    irank = 0;
    emxInit_real_T(&b_st, &s, 1, &mg_emlrtRTEI);
    s_data = s->data;
    if ((obj->ConstraintMatrix->size[0] != 0) &&
        (activeSetCols->size[0] != 0)) {
      real_T absx;
      boolean_T p;
      c_st.site = &cn_emlrtRSI;
      d_st.site = &jl_emlrtRSI;
      e_st.site = &ll_emlrtRSI;
      f_st.site = &ml_emlrtRSI;
      p = flatVectorAllOrAny(&f_st, A_);
      if (p) {
        d_st.site = &en_emlrtRSI;
        if (obj->ConstraintMatrix->size[0] == 0) {
          s->size[0] = 0;
        } else {
          e_st.site = &fn_emlrtRSI;
          f_st.site = &pl_emlrtRSI;
          g_st.site = &gn_emlrtRSI;
          i = A->size[0] * A->size[1];
          A->size[0] = A_->size[0];
          A->size[1] = A_->size[1];
          emxEnsureCapacity_real_T(&g_st, A, i, &fg_emlrtRTEI);
          A_data = A->data;
          minnm = A_->size[0] * A_->size[1];
          for (i = 0; i < minnm; i++) {
            A_data[i] = A__data[i];
          }
          minnm = muIntScalarMin_sint32(b_loop_ub, c_loop_ub);
          i = s->size[0];
          s->size[0] = minnm;
          emxEnsureCapacity_real_T(&g_st, s, i, &ig_emlrtRTEI);
          s_data = s->data;
          if (obj->ConstraintMatrix->size[0] != 0) {
            ptrdiff_t info_t;
            emxInit_real_T(&g_st, &superb, 1, &ng_emlrtRTEI);
            if (minnm > 1) {
              i = superb->size[0];
              superb->size[0] = minnm - 1;
              emxEnsureCapacity_real_T(&g_st, superb, i, &kg_emlrtRTEI);
              A__data = superb->data;
            } else {
              i = superb->size[0];
              superb->size[0] = 1;
              emxEnsureCapacity_real_T(&g_st, superb, i, &jg_emlrtRTEI);
              A__data = superb->data;
            }
            info_t =
                LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)c_loop_ub,
                               (ptrdiff_t)activeSetCols->size[0], &A_data[0],
                               (ptrdiff_t)c_loop_ub, &s_data[0], NULL,
                               (ptrdiff_t)1, NULL, (ptrdiff_t)1, &A__data[0]);
            emxFree_real_T(&g_st, &superb);
            minnm = (int32_T)info_t;
          } else {
            minnm = 0;
          }
          h_st.site = &hn_emlrtRSI;
          if (minnm < 0) {
            if (minnm == -1010) {
              emlrtErrorWithMessageIdR2018a(&h_st, &ob_emlrtRTEI,
                                            "MATLAB:nomem", "MATLAB:nomem", 0);
            } else {
              emlrtErrorWithMessageIdR2018a(&h_st, &nb_emlrtRTEI,
                                            "Coder:toolbox:LAPACKCallErrorInfo",
                                            "Coder:toolbox:LAPACKCallErrorInfo",
                                            5, 4, 14, &fname[0], 12, minnm);
            }
          }
          if (minnm > 0) {
            emlrtErrorWithMessageIdR2018a(&e_st, &pb_emlrtRTEI,
                                          "Coder:MATLAB:svd_NoConvergence",
                                          "Coder:MATLAB:svd_NoConvergence", 0);
          }
        }
      } else {
        minnm = (int32_T)muDoubleScalarMin(obj->ConstraintMatrix->size[0],
                                           activeSetCols->size[0]);
        i = s->size[0];
        s->size[0] = (int32_T)muDoubleScalarMin(obj->ConstraintMatrix->size[0],
                                                activeSetCols->size[0]);
        emxEnsureCapacity_real_T(&c_st, s, i, &dg_emlrtRTEI);
        s_data = s->data;
        for (i = 0; i < minnm; i++) {
          s_data[i] = rtNaN;
        }
      }
      if (obj->ConstraintMatrix->size[0] == 0) {
        minnm = 0;
      } else {
        minnm = muIntScalarMax_sint32(obj->ConstraintMatrix->size[0],
                                      activeSetCols->size[0]);
      }
      if (s->size[0] == 0) {
        absx = 0.0;
      } else {
        boolean_T exitg1;
        absx = muDoubleScalarAbs(s_data[0]);
        if (muDoubleScalarIsInf(absx) || muDoubleScalarIsNaN(absx)) {
          absx = rtNaN;
        } else if (absx < 4.4501477170144028E-308) {
          absx = 4.94065645841247E-324;
        } else {
          frexp(absx, &exponent);
          absx = ldexp(1.0, exponent - 53);
        }
        absx *= (real_T)minnm;
        minnm = 0;
        exitg1 = false;
        while ((!exitg1) && (minnm <= s->size[0] - 1)) {
          if (muDoubleScalarIsInf(s_data[minnm]) ||
              muDoubleScalarIsNaN(s_data[minnm])) {
            absx = 1.7976931348623157E+308;
            exitg1 = true;
          } else {
            minnm++;
          }
        }
      }
      c_st.site = &dn_emlrtRSI;
      if (s->size[0] > 2147483646) {
        d_st.site = &rb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      minnm = 0;
      while ((minnm <= s->size[0] - 1) && (s_data[minnm] > absx)) {
        irank++;
        minnm++;
      }
    }
    if (irank < activeSetCols->size[0]) {
      int32_T b_iv[2];
      st.site = &ym_emlrtRSI;
      emxInit_real_T(&st, &Q, 2, &lg_emlrtRTEI);
      emxInit_real_T(&st, &R, 2, &lg_emlrtRTEI);
      emxInit_int32_T(&st, &b_p, 2, &lg_emlrtRTEI);
      b_st.site = &in_emlrtRSI;
      eml_qr(&b_st, A_, Q, R, b_p);
      ii_data = b_p->data;
      emxFree_real_T(&st, &R);
      emxFree_real_T(&st, &Q);
      if (irank < 1) {
        irank = 0;
      } else {
        if (b_p->size[1] < 1) {
          emlrtDynamicBoundsCheckR2012b(1, 1, b_p->size[1], &ee_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (irank > b_p->size[1]) {
          emlrtDynamicBoundsCheckR2012b(irank, 1, b_p->size[1], &de_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
      }
      b_iv[0] = 1;
      b_iv[1] = irank;
      st.site = &an_emlrtRSI;
      indexShapeCheck(&st, activeSetCols->size[0], b_iv);
      i = s->size[0];
      s->size[0] = irank;
      emxEnsureCapacity_real_T(sp, s, i, &gg_emlrtRTEI);
      s_data = s->data;
      for (i = 0; i < irank; i++) {
        if ((ii_data[i] < 1) || (ii_data[i] > b_loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(ii_data[i], 1, b_loop_ub, &ie_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        s_data[i] = activeSetCols_data[ii_data[i] - 1];
      }
      emxFree_int32_T(sp, &b_p);
      b_loop_ub = s->size[0];
      i = activeSetCols->size[0];
      activeSetCols->size[0] = s->size[0];
      emxEnsureCapacity_real_T(sp, activeSetCols, i, &hg_emlrtRTEI);
      activeSetCols_data = activeSetCols->data;
      for (i = 0; i < b_loop_ub; i++) {
        activeSetCols_data[i] = s_data[i];
      }
    }
    emxFree_real_T(sp, &s);
    emxFree_real_T(sp, &A_);
    i = A->size[0] * A->size[1];
    A->size[0] = c_loop_ub;
    b_loop_ub = activeSetCols->size[0];
    A->size[1] = activeSetCols->size[0];
    emxEnsureCapacity_real_T(sp, A, i, &cg_emlrtRTEI);
    A_data = A->data;
    for (i = 0; i < b_loop_ub; i++) {
      for (irank = 0; irank < c_loop_ub; irank++) {
        minnm = (int32_T)activeSetCols_data[i];
        if ((minnm < 1) || (minnm > obj_tmp)) {
          emlrtDynamicBoundsCheckR2012b(minnm, 1, obj_tmp, &ge_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        A_data[irank + A->size[0] * i] =
            obj->ConstraintMatrix
                ->data[irank + obj->ConstraintMatrix->size[0] * (minnm - 1)];
      }
    }
    i = ii->size[0];
    ii->size[0] = activeSetCols->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &eg_emlrtRTEI);
    ii_data = ii->data;
    for (i = 0; i < b_loop_ub; i++) {
      irank = (int32_T)activeSetCols_data[i];
      if ((irank < 1) || (irank > loop_ub)) {
        emlrtDynamicBoundsCheckR2012b(irank, 1, loop_ub, &he_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      ii_data[i] = irank;
    }
    emxFree_real_T(sp, &activeSetCols);
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      activeSet_data[ii_data[i] - 1] = true;
    }
    emxFree_int32_T(sp, &ii);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static boolean_T e_DampedBFGSwGradientProjection(
    const emlrtStack *sp, const c_robotics_core_internal_Damped *obj,
    const emxArray_real_T *Hg, const emxArray_real_T *alpha)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack st;
  emxArray_boolean_T *b_alpha;
  const real_T *Hg_data;
  const real_T *alpha_data;
  real_T y;
  int32_T i;
  boolean_T flag;
  boolean_T *b_alpha_data;
  st.prev = sp;
  st.tls = sp->tls;
  alpha_data = alpha->data;
  Hg_data = Hg->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (Hg->size[0] == 0) {
    y = 0.0;
  } else {
    n_t = (ptrdiff_t)Hg->size[0];
    incx_t = (ptrdiff_t)1;
    y = dnrm2(&n_t, (real_T *)&Hg_data[0], &incx_t);
  }
  emxInit_boolean_T(sp, &b_alpha, &gh_emlrtRTEI);
  if (y < obj->GradientTolerance) {
    int32_T loop_ub;
    loop_ub = alpha->size[0];
    i = b_alpha->size[0];
    b_alpha->size[0] = alpha->size[0];
    emxEnsureCapacity_boolean_T(sp, b_alpha, i, &gh_emlrtRTEI);
    b_alpha_data = b_alpha->data;
    for (i = 0; i < loop_ub; i++) {
      b_alpha_data[i] = (alpha_data[i] <= 0.0);
    }
    st.site = &lq_emlrtRSI;
    if (all(&st, b_alpha)) {
      flag = true;
    } else {
      flag = false;
    }
  } else {
    flag = false;
  }
  emxFree_boolean_T(sp, &b_alpha);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return flag;
}

static boolean_T
f_DampedBFGSwGradientProjection(const emlrtStack *sp,
                                const c_robotics_core_internal_Damped *obj,
                                const emxArray_real_T *xNew)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_boolean_T *r1;
  emxArray_real_T *r;
  real_T *r2;
  int32_T i;
  boolean_T flag;
  boolean_T *r3;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &r, 1, &uh_emlrtRTEI);
  emxInit_boolean_T(sp, &r1, &uh_emlrtRTEI);
  if (obj->ConstraintsOn) {
    int32_T loop_ub;
    int32_T stride_0_0;
    int32_T stride_1_0;
    st.site = &ur_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    if (obj->ConstraintMatrix->size[0] != xNew->size[0]) {
      if (((obj->ConstraintMatrix->size[0] == 1) &&
           (obj->ConstraintMatrix->size[1] == 1)) ||
          (xNew->size[0] == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &kb_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &jb_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &dl_emlrtRSI;
    mtimes(&b_st, obj->ConstraintMatrix, xNew, r);
    r2 = r->data;
    i = obj->ConstraintBound->size[0];
    if ((r->size[0] != i) && ((r->size[0] != 1) && (i != 1))) {
      emlrtDimSizeImpxCheckR2021b(r->size[0], i, &qb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    st.site = &ur_emlrtRSI;
    if (obj->ConstraintBound->size[0] == 1) {
      loop_ub = r->size[0];
    } else {
      loop_ub = obj->ConstraintBound->size[0];
    }
    i = r1->size[0];
    r1->size[0] = loop_ub;
    emxEnsureCapacity_boolean_T(sp, r1, i, &uh_emlrtRTEI);
    r3 = r1->data;
    stride_0_0 = (r->size[0] != 1);
    stride_1_0 = (obj->ConstraintBound->size[0] != 1);
    for (i = 0; i < loop_ub; i++) {
      r3[i] = (r2[i * stride_0_0] - obj->ConstraintBound->data[i * stride_1_0] >
               1.4901161193847656E-8);
    }
    st.site = &ur_emlrtRSI;
    if (any(&st, r1)) {
      flag = true;
    } else {
      flag = false;
    }
  } else {
    flag = false;
  }
  emxFree_boolean_T(sp, &r1);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return flag;
}

static void minus(const emlrtStack *sp, emxArray_real_T *in1,
                  const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &oi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &oi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] -
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &oi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &pi_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &pi_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &pi_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

c_robotics_core_internal_NLPSol c_DampedBFGSwGradientProjection(
    const emlrtStack *sp, c_robotics_core_internal_Damped *obj,
    emxArray_real_T *xSol, real_T *err, real_T *iter)
{
  __m128d r5;
  __m128d r6;
  c_robotics_manip_internal_IKExt *args;
  c_robotics_manip_internal_IKExt *r;
  c_robotics_manip_internal_IKExt *r10;
  c_robotics_manip_internal_IKExt *r7;
  c_robotics_manip_internal_IKExt *r8;
  c_robotics_manip_internal_IKExt *r9;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *activeSet;
  emxArray_boolean_T *b_activeSet;
  emxArray_int32_T *ii;
  emxArray_int32_T *inactiveConstraintIndices;
  emxArray_int32_T *r1;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  emxArray_real_T *A;
  emxArray_real_T *AIn;
  emxArray_real_T *H;
  emxArray_real_T *Hg;
  emxArray_real_T *P;
  emxArray_real_T *a;
  emxArray_real_T *a__4;
  emxArray_real_T *bIn;
  emxArray_real_T *b_y;
  emxArray_real_T *c_y;
  emxArray_real_T *d_y;
  emxArray_real_T *grad;
  emxArray_real_T *gradNew;
  emxArray_real_T *x;
  emxArray_real_T *y;
  real_T a__3[36];
  real_T b_gamma;
  real_T beta;
  real_T cost;
  real_T costNew;
  real_T *AIn_data;
  real_T *A_data;
  real_T *H_data;
  real_T *Hg_data;
  real_T *a_data;
  real_T *gradNew_data;
  real_T *grad_data;
  real_T *xSol_data;
  real_T *x_data;
  real_T *y_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T n;
  int32_T scalarLB;
  int32_T scalarLB_tmp;
  int32_T vectorUB;
  int32_T vectorUB_tmp;
  int32_T *ii_data;
  int32_T *inactiveConstraintIndices_data;
  boolean_T *activeSet_data;
  boolean_T *b_activeSet_data;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &x, 1, &kd_emlrtRTEI);
  n = obj->SeedInternal->size[0];
  i = x->size[0];
  x->size[0] = n;
  emxEnsureCapacity_real_T(sp, x, i, &kd_emlrtRTEI);
  x_data = x->data;
  loop_ub = obj->SeedInternal->size[0];
  for (i = 0; i < loop_ub; i++) {
    x_data[i] = obj->SeedInternal->data[i];
  }
  st.site = &bi_emlrtRSI;
  b_st.site = &uh_emlrtRSI;
  obj->TimeObjInternal.StartTime = tic(&b_st);
  b_st.site = &vh_emlrtRSI;
  emxInit_real_T(sp, &a__4, 2, &vd_emlrtRTEI);
  st.site = &ci_emlrtRSI;
  cost = IKHelpers_computeCost(&st, x, obj->ExtraArgs, a__3, a__4, &r);
  obj->ExtraArgs = r;
  st.site = &di_emlrtRSI;
  args = obj->ExtraArgs;
  emxInit_real_T(&st, &grad, 1, &ld_emlrtRTEI);
  i = grad->size[0];
  grad->size[0] = args->GradTemp->size[0];
  emxEnsureCapacity_real_T(&st, grad, i, &ld_emlrtRTEI);
  grad_data = grad->data;
  loop_ub = args->GradTemp->size[0];
  for (i = 0; i < loop_ub; i++) {
    grad_data[i] = args->GradTemp->data[i];
  }
  emxInit_real_T(sp, &H, 2, &we_emlrtRTEI);
  st.site = &ei_emlrtRSI;
  eye(&st, x->size[0], H);
  H_data = H->data;
  emxInit_boolean_T(sp, &activeSet, &xe_emlrtRTEI);
  emxInit_real_T(sp, &A, 2, &ye_emlrtRTEI);
  st.site = &fi_emlrtRSI;
  d_DampedBFGSwGradientProjection(&st, obj, x, activeSet, A);
  A_data = A->data;
  activeSet_data = activeSet->data;
  i = A->size[1];
  emxInit_real_T(sp, &a, 1, &nd_emlrtRTEI);
  emxInit_real_T(sp, &AIn, 2, &yd_emlrtRTEI);
  emxInit_real_T(sp, &y, 2, &df_emlrtRTEI);
  emxInit_real_T(sp, &b_y, 2, &ef_emlrtRTEI);
  emxInit_real_T(sp, &c_y, 2, &ef_emlrtRTEI);
  for (k = 0; k < i; k++) {
    if (k + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &nc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub_tmp = A->size[0];
    i1 = a->size[0];
    a->size[0] = A->size[0];
    emxEnsureCapacity_real_T(sp, a, i1, &nd_emlrtRTEI);
    a_data = a->data;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      a_data[i1] = A_data[i1 + A->size[0] * k];
    }
    st.site = &gi_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    b_dynamic_size_checks(&b_st, a, H, A->size[0], H->size[0]);
    b_st.site = &dl_emlrtRSI;
    b_mtimes(&b_st, a, H, y);
    st.site = &gi_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    c_dynamic_size_checks(&b_st, y, a, y->size[1], A->size[0]);
    b_gamma = 1.0 / c_mtimes(y, a);
    i1 = b_y->size[0] * b_y->size[1];
    b_y->size[0] = H->size[0];
    b_y->size[1] = H->size[1];
    emxEnsureCapacity_real_T(sp, b_y, i1, &od_emlrtRTEI);
    y_data = b_y->data;
    last = H->size[0] * H->size[1];
    scalarLB_tmp = (last / 2) << 1;
    vectorUB_tmp = scalarLB_tmp - 2;
    for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
      r5 = _mm_loadu_pd(&H_data[i1]);
      _mm_storeu_pd(&y_data[i1], _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
    }
    for (i1 = scalarLB_tmp; i1 < last; i1++) {
      y_data[i1] = b_gamma * H_data[i1];
    }
    i1 = AIn->size[0] * AIn->size[1];
    AIn->size[0] = A->size[0];
    AIn->size[1] = A->size[0];
    emxEnsureCapacity_real_T(sp, AIn, i1, &qd_emlrtRTEI);
    AIn_data = AIn->data;
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      scalarLB = (A->size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (i2 = 0; i2 <= vectorUB; i2 += 2) {
        r5 = _mm_loadu_pd(&A_data[i2 + A->size[0] * k]);
        _mm_storeu_pd(&AIn_data[i2 + AIn->size[0] * i1],
                      _mm_mul_pd(r5, _mm_set1_pd(A_data[i1 + A->size[0] * k])));
      }
      for (i2 = scalarLB; i2 < loop_ub_tmp; i2++) {
        AIn_data[i2 + AIn->size[0] * i1] =
            A_data[i2 + A->size[0] * k] * A_data[i1 + A->size[0] * k];
      }
    }
    st.site = &hi_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    d_dynamic_size_checks(&b_st, b_y, AIn, b_y->size[1], AIn->size[0]);
    b_st.site = &dl_emlrtRSI;
    d_mtimes(&b_st, b_y, AIn, c_y);
    st.site = &hi_emlrtRSI;
    b_st.site = &wk_emlrtRSI;
    d_dynamic_size_checks(&b_st, c_y, H, c_y->size[1], H->size[0]);
    b_st.site = &dl_emlrtRSI;
    d_mtimes(&b_st, c_y, H, b_y);
    y_data = b_y->data;
    if ((H->size[0] != b_y->size[0]) &&
        ((H->size[0] != 1) && (b_y->size[0] != 1))) {
      emlrtDimSizeImpxCheckR2021b(H->size[0], b_y->size[0], &mb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((H->size[1] != b_y->size[1]) &&
        ((H->size[1] != 1) && (b_y->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(H->size[1], b_y->size[1], &lb_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((H->size[0] == b_y->size[0]) && (H->size[1] == b_y->size[1])) {
      for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
        r5 = _mm_loadu_pd(&H_data[i1]);
        r6 = _mm_loadu_pd(&y_data[i1]);
        _mm_storeu_pd(&H_data[i1], _mm_sub_pd(r5, r6));
      }
      for (i1 = scalarLB_tmp; i1 < last; i1++) {
        H_data[i1] -= y_data[i1];
      }
    } else {
      st.site = &hi_emlrtRSI;
      minus(&st, H, b_y);
      H_data = H->data;
    }
  }
  i = xSol->size[0];
  xSol->size[0] = n;
  emxEnsureCapacity_real_T(sp, xSol, i, &md_emlrtRTEI);
  xSol_data = xSol->data;
  for (i = 0; i < n; i++) {
    xSol_data[i] = x_data[i];
  }
  beta = obj->MaxNumIterationInternal;
  i = (int32_T)beta;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, beta, mxDOUBLE_CLASS, (int32_T)beta,
                                &gb_emlrtRTEI, (emlrtConstCTX)sp);
  b_i = 0;
  emxInit_real_T(sp, &Hg, 1, &af_emlrtRTEI);
  emxInit_real_T(sp, &P, 2, &bf_emlrtRTEI);
  emxInit_real_T(sp, &bIn, 1, &xd_emlrtRTEI);
  emxInit_int32_T(sp, &inactiveConstraintIndices, 1, &be_emlrtRTEI);
  emxInit_real_T(sp, &gradNew, 1, &he_emlrtRTEI);
  emxInit_int32_T(sp, &r1, 1, &cf_emlrtRTEI);
  emxInit_int32_T(sp, &r2, 1, &td_emlrtRTEI);
  emxInit_int32_T(sp, &ii, 1, &hd_emlrtRTEI);
  emxInit_real_T(sp, &d_y, 2, &ff_emlrtRTEI);
  emxInit_int32_T(sp, &r3, 1, &gf_emlrtRTEI);
  emxInit_int32_T(sp, &r4, 1, &hf_emlrtRTEI);
  emxInit_boolean_T(sp, &b_activeSet, &sd_emlrtRTEI);
  int32_T exitg2;
  do {
    exitg2 = 0;
    if (b_i <= i - 1) {
      boolean_T valid;
      *iter = (real_T)b_i + 1.0;
      st.site = &ii_emlrtRSI;
      b_st.site = &qo_emlrtRSI;
      valid = (obj->TimeObjInternal.StartTime.tv_sec > 0.0);
      if (!valid) {
        emlrtErrorWithMessageIdR2018a(&st, &t_emlrtRTEI,
                                      "shared_robotics:robotutils:timeprovider:"
                                      "TimeProviderNotInitialized",
                                      "shared_robotics:robotutils:timeprovider:"
                                      "TimeProviderNotInitialized",
                                      0);
      }
      b_st.site = &ro_emlrtRSI;
      b_gamma = toc(&b_st, obj->TimeObjInternal.StartTime.tv_sec,
                    obj->TimeObjInternal.StartTime.tv_nsec);
      st.site = &ii_emlrtRSI;
      valid = (b_gamma > obj->MaxTimeInternal);
      if (valid) {
        exitFlag = TimeLimitExceeded;
        st.site = &ji_emlrtRSI;
        *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
        exitg2 = 1;
      } else {
        if ((A->size[0] == 0) || (A->size[1] == 0)) {
          i1 = a->size[0];
          a->size[0] = 1;
          emxEnsureCapacity_real_T(sp, a, i1, &pd_emlrtRTEI);
          a_data = a->data;
          a_data[0] = 0.0;
        } else {
          st.site = &ki_emlrtRSI;
          b_st.site = &wk_emlrtRSI;
          d_dynamic_size_checks(&b_st, A, A, A->size[0], A->size[0]);
          b_st.site = &dl_emlrtRSI;
          e_mtimes(&b_st, A, A, b_y);
          st.site = &ki_emlrtRSI;
          b_st.site = &ki_emlrtRSI;
          loop_ub = A->size[1];
          i1 = c_y->size[0] * c_y->size[1];
          c_y->size[0] = A->size[1];
          k = A->size[0];
          c_y->size[1] = A->size[0];
          emxEnsureCapacity_real_T(&b_st, c_y, i1, &rd_emlrtRTEI);
          y_data = c_y->data;
          for (i1 = 0; i1 < k; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              y_data[i2 + c_y->size[0] * i1] = A_data[i1 + A->size[0] * i2];
            }
          }
          if (c_y->size[0] != b_y->size[0]) {
            emlrtErrorWithMessageIdR2018a(
                &b_st, &db_emlrtRTEI, "MATLAB:dimagree", "MATLAB:dimagree", 0);
          }
          c_st.site = &uo_emlrtRSI;
          mldiv(&c_st, b_y, c_y, AIn);
          b_st.site = &wk_emlrtRSI;
          dynamic_size_checks(&b_st, AIn, grad, AIn->size[1], grad->size[0]);
          b_st.site = &dl_emlrtRSI;
          f_mtimes(&b_st, AIn, grad, a);
          a_data = a->data;
        }
        st.site = &li_emlrtRSI;
        b_st.site = &wk_emlrtRSI;
        dynamic_size_checks(&b_st, H, grad, H->size[1], grad->size[0]);
        b_st.site = &dl_emlrtRSI;
        f_mtimes(&b_st, H, grad, Hg);
        Hg_data = Hg->data;
        st.site = &mi_emlrtRSI;
        if (e_DampedBFGSwGradientProjection(&st, obj, Hg, a)) {
          exitFlag = LocalMinimumFound;
          st.site = &ni_emlrtRSI;
          *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
          exitg2 = 1;
        } else {
          int32_T idxl;
          boolean_T exitg3;
          boolean_T guard1;
          boolean_T guard2;
          boolean_T guard3;
          guard1 = false;
          guard2 = false;
          guard3 = false;
          if (obj->ConstraintsOn && ((A->size[0] != 0) && (A->size[1] != 0))) {
            st.site = &oi_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            d_dynamic_size_checks(&b_st, A, A, A->size[0], A->size[0]);
            b_st.site = &dl_emlrtRSI;
            e_mtimes(&b_st, A, A, b_y);
            st.site = &oi_emlrtRSI;
            inv(&st, b_y, c_y);
            st.site = &pi_emlrtRSI;
            b_st.site = &pi_emlrtRSI;
            diag(&b_st, c_y, gradNew);
            b_st.site = &pi_emlrtRSI;
            c_sqrt(&b_st, gradNew);
            gradNew_data = gradNew->data;
            b_st.site = &xq_emlrtRSI;
            c_st.site = &yq_emlrtRSI;
            assertCompatibleDims(&c_st, a, gradNew);
            if (a->size[0] == gradNew->size[0]) {
              loop_ub = a->size[0];
              scalarLB = (a->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&a_data[i1]);
                r6 = _mm_loadu_pd(&gradNew_data[i1]);
                _mm_storeu_pd(&a_data[i1], _mm_div_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < loop_ub; i1++) {
                a_data[i1] /= gradNew_data[i1];
              }
            } else {
              c_st.site = &lt_emlrtRSI;
              rdivide(&c_st, a, gradNew);
              a_data = a->data;
            }
            st.site = &pi_emlrtRSI;
            b_st.site = &ar_emlrtRSI;
            c_st.site = &br_emlrtRSI;
            d_st.site = &cr_emlrtRSI;
            if (a->size[0] < 1) {
              emlrtErrorWithMessageIdR2018a(
                  &d_st, &eb_emlrtRTEI,
                  "Coder:toolbox:eml_min_or_max_varDimZero",
                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
            }
            e_st.site = &dr_emlrtRSI;
            last = a->size[0];
            if (a->size[0] <= 2) {
              if (a->size[0] == 1) {
                b_gamma = a_data[0];
                scalarLB = 1;
              } else if ((a_data[0] < a_data[1]) ||
                         (muDoubleScalarIsNaN(a_data[0]) &&
                          (!muDoubleScalarIsNaN(a_data[1])))) {
                b_gamma = a_data[1];
                scalarLB = 2;
              } else {
                b_gamma = a_data[0];
                scalarLB = 1;
              }
            } else {
              f_st.site = &fr_emlrtRSI;
              if (!muDoubleScalarIsNaN(a_data[0])) {
                scalarLB = 1;
              } else {
                scalarLB = 0;
                g_st.site = &gr_emlrtRSI;
                if (a->size[0] > 2147483646) {
                  h_st.site = &rb_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }
                k = 2;
                exitg3 = false;
                while ((!exitg3) && (k <= last)) {
                  if (!muDoubleScalarIsNaN(a_data[k - 1])) {
                    scalarLB = k;
                    exitg3 = true;
                  } else {
                    k++;
                  }
                }
              }
              if (scalarLB == 0) {
                b_gamma = a_data[0];
                scalarLB = 1;
              } else {
                f_st.site = &er_emlrtRSI;
                b_gamma = a_data[scalarLB - 1];
                idxl = scalarLB + 1;
                g_st.site = &hr_emlrtRSI;
                if ((scalarLB + 1 <= a->size[0]) && (a->size[0] > 2147483646)) {
                  h_st.site = &rb_emlrtRSI;
                  check_forloop_overflow_error(&h_st);
                }
                for (k = idxl; k <= last; k++) {
                  beta = a_data[k - 1];
                  if (b_gamma < beta) {
                    b_gamma = beta;
                    scalarLB = k;
                  }
                }
              }
            }
            if (c_norm(Hg) < 0.5 * b_gamma) {
              st.site = &qi_emlrtRSI;
              b_st.site = &kh_emlrtRSI;
              eml_find(&b_st, activeSet, ii);
              ii_data = ii->data;
              loop_ub = ii->size[0];
              i1 = a->size[0];
              a->size[0] = ii->size[0];
              emxEnsureCapacity_real_T(&st, a, i1, &ce_emlrtRTEI);
              a_data = a->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                a_data[i1] = ii_data[i1];
              }
              if ((scalarLB < 1) || (scalarLB > ii->size[0])) {
                emlrtDynamicBoundsCheckR2012b(scalarLB, 1, ii->size[0],
                                              &mc_emlrtBCI, (emlrtConstCTX)sp);
              }
              idxl = (int32_T)a_data[scalarLB - 1];
              if ((idxl < 1) || (idxl > activeSet->size[0])) {
                emlrtDynamicBoundsCheckR2012b(idxl, 1, activeSet->size[0],
                                              &rc_emlrtBCI, (emlrtConstCTX)sp);
              }
              activeSet_data[idxl - 1] = false;
              scalarLB = activeSet->size[0];
              last = 0;
              for (loop_ub_tmp = 0; loop_ub_tmp < scalarLB; loop_ub_tmp++) {
                if (activeSet_data[loop_ub_tmp]) {
                  last++;
                }
              }
              i1 = r4->size[0];
              r4->size[0] = last;
              emxEnsureCapacity_int32_T(sp, r4, i1, &vd_emlrtRTEI);
              ii_data = r4->data;
              last = 0;
              for (loop_ub_tmp = 0; loop_ub_tmp < scalarLB; loop_ub_tmp++) {
                if (activeSet_data[loop_ub_tmp]) {
                  ii_data[last] = loop_ub_tmp;
                  last++;
                }
              }
              last = obj->ConstraintMatrix->size[1];
              i1 = A->size[0] * A->size[1];
              A->size[0] = obj->ConstraintMatrix->size[0];
              loop_ub = r4->size[0];
              A->size[1] = r4->size[0];
              emxEnsureCapacity_real_T(sp, A, i1, &ge_emlrtRTEI);
              A_data = A->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                k = obj->ConstraintMatrix->size[0];
                for (i2 = 0; i2 < k; i2++) {
                  if ((ii_data[i1] < 0) || (ii_data[i1] > last - 1)) {
                    emlrtDynamicBoundsCheckR2012b(ii_data[i1], 0, last - 1,
                                                  &tc_emlrtBCI,
                                                  (emlrtConstCTX)sp);
                  }
                  A_data[i2 + A->size[0] * i1] =
                      obj->ConstraintMatrix
                          ->data[i2 +
                                 obj->ConstraintMatrix->size[0] * ii_data[i1]];
                }
              }
              st.site = &ri_emlrtRSI;
              eye(&st, n, P);
              xSol_data = P->data;
              st.site = &ri_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              d_dynamic_size_checks(&b_st, A, A, A->size[0], A->size[0]);
              b_st.site = &dl_emlrtRSI;
              e_mtimes(&b_st, A, A, b_y);
              st.site = &ri_emlrtRSI;
              b_st.site = &ri_emlrtRSI;
              loop_ub = A->size[1];
              i1 = c_y->size[0] * c_y->size[1];
              c_y->size[0] = A->size[1];
              k = A->size[0];
              c_y->size[1] = A->size[0];
              emxEnsureCapacity_real_T(&b_st, c_y, i1, &me_emlrtRTEI);
              y_data = c_y->data;
              for (i1 = 0; i1 < k; i1++) {
                for (i2 = 0; i2 < loop_ub; i2++) {
                  y_data[i2 + c_y->size[0] * i1] = A_data[i1 + A->size[0] * i2];
                }
              }
              if (c_y->size[0] != b_y->size[0]) {
                emlrtErrorWithMessageIdR2018a(&b_st, &db_emlrtRTEI,
                                              "MATLAB:dimagree",
                                              "MATLAB:dimagree", 0);
              }
              c_st.site = &uo_emlrtRSI;
              mldiv(&c_st, b_y, c_y, AIn);
              b_st.site = &wk_emlrtRSI;
              d_dynamic_size_checks(&b_st, A, AIn, A->size[1], AIn->size[0]);
              b_st.site = &dl_emlrtRSI;
              d_mtimes(&b_st, A, AIn, b_y);
              y_data = b_y->data;
              if ((P->size[0] != b_y->size[0]) &&
                  ((P->size[0] != 1) && (b_y->size[0] != 1))) {
                emlrtDimSizeImpxCheckR2021b(P->size[0], b_y->size[0],
                                            &kb_emlrtECI, (emlrtConstCTX)sp);
              }
              if ((P->size[1] != b_y->size[1]) &&
                  ((P->size[1] != 1) && (b_y->size[1] != 1))) {
                emlrtDimSizeImpxCheckR2021b(P->size[1], b_y->size[1],
                                            &jb_emlrtECI, (emlrtConstCTX)sp);
              }
              if ((P->size[0] == b_y->size[0]) &&
                  (P->size[1] == b_y->size[1])) {
                loop_ub_tmp = P->size[0] * P->size[1];
                scalarLB = (loop_ub_tmp / 2) << 1;
                vectorUB = scalarLB - 2;
                for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                  r5 = _mm_loadu_pd(&xSol_data[i1]);
                  r6 = _mm_loadu_pd(&y_data[i1]);
                  _mm_storeu_pd(&xSol_data[i1], _mm_sub_pd(r5, r6));
                }
                for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                  xSol_data[i1] -= y_data[i1];
                }
              } else {
                st.site = &ri_emlrtRSI;
                minus(&st, P, b_y);
                xSol_data = P->data;
              }
              i1 = obj->ConstraintMatrix->size[1];
              if (idxl > i1) {
                emlrtDynamicBoundsCheckR2012b(idxl, 1, i1, &lc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              loop_ub = obj->ConstraintMatrix->size[0];
              i1 = a->size[0];
              a->size[0] = loop_ub;
              emxEnsureCapacity_real_T(sp, a, i1, &oe_emlrtRTEI);
              a_data = a->data;
              k = obj->ConstraintMatrix->size[0];
              for (i1 = 0; i1 < k; i1++) {
                a_data[i1] = obj->ConstraintMatrix
                                 ->data[i1 + obj->ConstraintMatrix->size[0] *
                                                 (idxl - 1)];
              }
              st.site = &si_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              b_dynamic_size_checks(&b_st, a, P, a->size[0], P->size[0]);
              b_st.site = &dl_emlrtRSI;
              b_mtimes(&b_st, a, P, y);
              st.site = &si_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              c_dynamic_size_checks(&b_st, y, a, y->size[1], a->size[0]);
              b_gamma = 1.0 / c_mtimes(y, a);
              i1 = b_y->size[0] * b_y->size[1];
              b_y->size[0] = P->size[0];
              b_y->size[1] = P->size[1];
              emxEnsureCapacity_real_T(sp, b_y, i1, &od_emlrtRTEI);
              y_data = b_y->data;
              loop_ub_tmp = P->size[0] * P->size[1];
              scalarLB = (loop_ub_tmp / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&xSol_data[i1]);
                _mm_storeu_pd(&y_data[i1],
                              _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
              }
              for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                y_data[i1] = b_gamma * xSol_data[i1];
              }
              i1 = AIn->size[0] * AIn->size[1];
              AIn->size[0] = loop_ub;
              AIn->size[1] = loop_ub;
              emxEnsureCapacity_real_T(sp, AIn, i1, &qd_emlrtRTEI);
              AIn_data = AIn->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                scalarLB = (a->size[0] / 2) << 1;
                vectorUB = scalarLB - 2;
                for (i2 = 0; i2 <= vectorUB; i2 += 2) {
                  r5 = _mm_loadu_pd(&a_data[i2]);
                  _mm_storeu_pd(&AIn_data[i2 + AIn->size[0] * i1],
                                _mm_mul_pd(r5, _mm_set1_pd(a_data[i1])));
                }
                for (i2 = scalarLB; i2 < loop_ub; i2++) {
                  AIn_data[i2 + AIn->size[0] * i1] = a_data[i2] * a_data[i1];
                }
              }
              st.site = &si_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              d_dynamic_size_checks(&b_st, b_y, AIn, b_y->size[1],
                                    AIn->size[0]);
              b_st.site = &dl_emlrtRSI;
              d_mtimes(&b_st, b_y, AIn, c_y);
              st.site = &si_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              d_dynamic_size_checks(&b_st, c_y, P, c_y->size[1], P->size[0]);
              b_st.site = &dl_emlrtRSI;
              d_mtimes(&b_st, c_y, P, b_y);
              y_data = b_y->data;
              if ((H->size[0] != b_y->size[0]) &&
                  ((H->size[0] != 1) && (b_y->size[0] != 1))) {
                emlrtDimSizeImpxCheckR2021b(H->size[0], b_y->size[0],
                                            &ib_emlrtECI, (emlrtConstCTX)sp);
              }
              if ((H->size[1] != b_y->size[1]) &&
                  ((H->size[1] != 1) && (b_y->size[1] != 1))) {
                emlrtDimSizeImpxCheckR2021b(H->size[1], b_y->size[1],
                                            &hb_emlrtECI, (emlrtConstCTX)sp);
              }
              if ((H->size[0] == b_y->size[0]) &&
                  (H->size[1] == b_y->size[1])) {
                loop_ub_tmp = H->size[0] * H->size[1];
                scalarLB = (loop_ub_tmp / 2) << 1;
                vectorUB = scalarLB - 2;
                for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                  r5 = _mm_loadu_pd(&H_data[i1]);
                  r6 = _mm_loadu_pd(&y_data[i1]);
                  _mm_storeu_pd(&H_data[i1], _mm_add_pd(r5, r6));
                }
                for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                  H_data[i1] += y_data[i1];
                }
              } else {
                st.site = &si_emlrtRSI;
                plus(&st, H, b_y);
                H_data = H->data;
              }
              b_i++;
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }
          if (guard3) {
            real_T lambda;
            real_T m;
            real_T sigma;
            int32_T exitg1;
            loop_ub = Hg->size[0];
            scalarLB = (Hg->size[0] / 2) << 1;
            vectorUB = scalarLB - 2;
            for (i1 = 0; i1 <= vectorUB; i1 += 2) {
              r5 = _mm_loadu_pd(&Hg_data[i1]);
              _mm_storeu_pd(&Hg_data[i1], _mm_mul_pd(r5, _mm_set1_pd(-1.0)));
            }
            for (i1 = scalarLB; i1 < loop_ub; i1++) {
              Hg_data[i1] = -Hg_data[i1];
            }
            idxl = -1;
            if (obj->ConstraintsOn) {
              loop_ub = activeSet->size[0];
              i1 = b_activeSet->size[0];
              b_activeSet->size[0] = activeSet->size[0];
              emxEnsureCapacity_boolean_T(sp, b_activeSet, i1, &sd_emlrtRTEI);
              b_activeSet_data = b_activeSet->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                b_activeSet_data[i1] = !activeSet_data[i1];
              }
              st.site = &ti_emlrtRSI;
              if (any(&st, b_activeSet)) {
                i1 = b_activeSet->size[0];
                b_activeSet->size[0] = activeSet->size[0];
                emxEnsureCapacity_boolean_T(sp, b_activeSet, i1, &td_emlrtRTEI);
                b_activeSet_data = b_activeSet->data;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  b_activeSet_data[i1] = !activeSet_data[i1];
                }
                last = 0;
                for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
                  if (b_activeSet_data[loop_ub_tmp]) {
                    last++;
                  }
                }
                i1 = r2->size[0];
                r2->size[0] = last;
                emxEnsureCapacity_int32_T(sp, r2, i1, &vd_emlrtRTEI);
                ii_data = r2->data;
                last = 0;
                for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
                  if (b_activeSet_data[loop_ub_tmp]) {
                    ii_data[last] = loop_ub_tmp;
                    last++;
                  }
                }
                last = obj->ConstraintBound->size[0];
                loop_ub = r2->size[0];
                i1 = bIn->size[0];
                bIn->size[0] = r2->size[0];
                emxEnsureCapacity_real_T(sp, bIn, i1, &xd_emlrtRTEI);
                xSol_data = bIn->data;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  if ((ii_data[i1] < 0) || (ii_data[i1] > last - 1)) {
                    emlrtDynamicBoundsCheckR2012b(ii_data[i1], 0, last - 1,
                                                  &oc_emlrtBCI,
                                                  (emlrtConstCTX)sp);
                  }
                  xSol_data[i1] = obj->ConstraintBound->data[ii_data[i1]];
                }
                last = obj->ConstraintMatrix->size[1];
                i1 = AIn->size[0] * AIn->size[1];
                AIn->size[0] = obj->ConstraintMatrix->size[0];
                AIn->size[1] = r2->size[0];
                emxEnsureCapacity_real_T(sp, AIn, i1, &yd_emlrtRTEI);
                AIn_data = AIn->data;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  k = obj->ConstraintMatrix->size[0];
                  for (i2 = 0; i2 < k; i2++) {
                    if ((ii_data[i1] < 0) || (ii_data[i1] > last - 1)) {
                      emlrtDynamicBoundsCheckR2012b(ii_data[i1], 0, last - 1,
                                                    &pc_emlrtBCI,
                                                    (emlrtConstCTX)sp);
                    }
                    AIn_data[i2 + AIn->size[0] * i1] =
                        obj->ConstraintMatrix
                            ->data[i2 + obj->ConstraintMatrix->size[0] *
                                            ii_data[i1]];
                  }
                }
                st.site = &ui_emlrtRSI;
                b_st.site = &kh_emlrtRSI;
                eml_find(&b_st, b_activeSet, ii);
                ii_data = ii->data;
                loop_ub = ii->size[0];
                i1 = inactiveConstraintIndices->size[0];
                inactiveConstraintIndices->size[0] = ii->size[0];
                emxEnsureCapacity_int32_T(&st, inactiveConstraintIndices, i1,
                                          &be_emlrtRTEI);
                inactiveConstraintIndices_data =
                    inactiveConstraintIndices->data;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  inactiveConstraintIndices_data[i1] = ii_data[i1];
                }
                st.site = &vi_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                dynamic_size_checks(&b_st, AIn, x, AIn->size[0], x->size[0]);
                b_st.site = &dl_emlrtRSI;
                mtimes(&b_st, AIn, x, a);
                a_data = a->data;
                k = bIn->size[0];
                if ((bIn->size[0] != a->size[0]) &&
                    ((bIn->size[0] != 1) && (a->size[0] != 1))) {
                  emlrtDimSizeImpxCheckR2021b(bIn->size[0], a->size[0],
                                              &gb_emlrtECI, (emlrtConstCTX)sp);
                }
                st.site = &vi_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                dynamic_size_checks(&b_st, AIn, Hg, AIn->size[0], Hg->size[0]);
                b_st.site = &dl_emlrtRSI;
                mtimes(&b_st, AIn, Hg, gradNew);
                gradNew_data = gradNew->data;
                st.site = &vi_emlrtRSI;
                if (bIn->size[0] == a->size[0]) {
                  scalarLB = (bIn->size[0] / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                    r5 = _mm_loadu_pd(&xSol_data[i1]);
                    r6 = _mm_loadu_pd(&a_data[i1]);
                    _mm_storeu_pd(&xSol_data[i1], _mm_sub_pd(r5, r6));
                  }
                  for (i1 = scalarLB; i1 < k; i1++) {
                    xSol_data[i1] -= a_data[i1];
                  }
                } else {
                  b_st.site = &vi_emlrtRSI;
                  c_minus(&b_st, bIn, a);
                  xSol_data = bIn->data;
                }
                b_st.site = &xq_emlrtRSI;
                c_st.site = &yq_emlrtRSI;
                assertCompatibleDims(&c_st, bIn, gradNew);
                if (bIn->size[0] == gradNew->size[0]) {
                  k = bIn->size[0];
                  scalarLB = (bIn->size[0] / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                    r5 = _mm_loadu_pd(&xSol_data[i1]);
                    r6 = _mm_loadu_pd(&gradNew_data[i1]);
                    _mm_storeu_pd(&xSol_data[i1], _mm_div_pd(r5, r6));
                  }
                  for (i1 = scalarLB; i1 < k; i1++) {
                    xSol_data[i1] /= gradNew_data[i1];
                  }
                } else {
                  c_st.site = &lt_emlrtRSI;
                  rdivide(&c_st, bIn, gradNew);
                  xSol_data = bIn->data;
                }
                st.site = &wi_emlrtRSI;
                k = bIn->size[0];
                i1 = b_activeSet->size[0];
                b_activeSet->size[0] = bIn->size[0];
                emxEnsureCapacity_boolean_T(&st, b_activeSet, i1,
                                            &je_emlrtRTEI);
                b_activeSet_data = b_activeSet->data;
                for (i1 = 0; i1 < k; i1++) {
                  b_activeSet_data[i1] = (xSol_data[i1] > 0.0);
                }
                b_st.site = &kh_emlrtRSI;
                eml_find(&b_st, b_activeSet, ii);
                ii_data = ii->data;
                scalarLB = ii->size[0];
                i1 = a->size[0];
                a->size[0] = ii->size[0];
                emxEnsureCapacity_real_T(&st, a, i1, &ke_emlrtRTEI);
                a_data = a->data;
                for (i1 = 0; i1 < scalarLB; i1++) {
                  a_data[i1] = ii_data[i1];
                }
                if (a->size[0] != 0) {
                  last = 0;
                  for (loop_ub_tmp = 0; loop_ub_tmp < k; loop_ub_tmp++) {
                    if (b_activeSet_data[loop_ub_tmp]) {
                      last++;
                    }
                  }
                  i1 = r1->size[0];
                  r1->size[0] = last;
                  emxEnsureCapacity_int32_T(sp, r1, i1, &vd_emlrtRTEI);
                  ii_data = r1->data;
                  last = 0;
                  for (loop_ub_tmp = 0; loop_ub_tmp < k; loop_ub_tmp++) {
                    if (b_activeSet_data[loop_ub_tmp]) {
                      ii_data[last] = loop_ub_tmp;
                      last++;
                    }
                  }
                  st.site = &xi_emlrtRSI;
                  loop_ub_tmp = r1->size[0];
                  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
                    if ((ii_data[i1] < 0) || (ii_data[i1] > bIn->size[0] - 1)) {
                      emlrtDynamicBoundsCheckR2012b(
                          ii_data[i1], 0, bIn->size[0] - 1, &uc_emlrtBCI, &st);
                    }
                  }
                  b_st.site = &jr_emlrtRSI;
                  c_st.site = &kr_emlrtRSI;
                  d_st.site = &lr_emlrtRSI;
                  if (r1->size[0] < 1) {
                    emlrtErrorWithMessageIdR2018a(
                        &d_st, &eb_emlrtRTEI,
                        "Coder:toolbox:eml_min_or_max_varDimZero",
                        "Coder:toolbox:eml_min_or_max_varDimZero", 0);
                  }
                  e_st.site = &dr_emlrtRSI;
                  if (r1->size[0] <= 2) {
                    if (r1->size[0] == 1) {
                      lambda = xSol_data[ii_data[0]];
                      scalarLB = 1;
                    } else {
                      lambda = xSol_data[ii_data[0]];
                      beta = xSol_data[ii_data[1]];
                      if ((lambda > beta) || (muDoubleScalarIsNaN(lambda) &&
                                              (!muDoubleScalarIsNaN(beta)))) {
                        lambda = beta;
                        scalarLB = 2;
                      } else {
                        scalarLB = 1;
                      }
                    }
                  } else {
                    f_st.site = &fr_emlrtRSI;
                    lambda = xSol_data[ii_data[0]];
                    if (!muDoubleScalarIsNaN(lambda)) {
                      scalarLB = 1;
                    } else {
                      scalarLB = 0;
                      g_st.site = &gr_emlrtRSI;
                      if (r1->size[0] > 2147483646) {
                        h_st.site = &rb_emlrtRSI;
                        check_forloop_overflow_error(&h_st);
                      }
                      k = 2;
                      exitg3 = false;
                      while ((!exitg3) && (k <= loop_ub_tmp)) {
                        if (!muDoubleScalarIsNaN(xSol_data[ii_data[k - 1]])) {
                          scalarLB = k;
                          exitg3 = true;
                        } else {
                          k++;
                        }
                      }
                    }
                    if (scalarLB == 0) {
                      scalarLB = 1;
                    } else {
                      f_st.site = &er_emlrtRSI;
                      lambda = xSol_data[ii_data[scalarLB - 1]];
                      idxl = scalarLB + 1;
                      g_st.site = &hr_emlrtRSI;
                      if ((scalarLB + 1 <= r1->size[0]) &&
                          (r1->size[0] > 2147483646)) {
                        h_st.site = &rb_emlrtRSI;
                        check_forloop_overflow_error(&h_st);
                      }
                      for (k = idxl; k <= loop_ub_tmp; k++) {
                        beta = xSol_data[ii_data[k - 1]];
                        if (lambda > beta) {
                          lambda = beta;
                          scalarLB = k;
                        }
                      }
                    }
                  }
                  if ((scalarLB < 1) || (scalarLB > ii->size[0])) {
                    emlrtDynamicBoundsCheckR2012b(scalarLB, 1, ii->size[0],
                                                  &wc_emlrtBCI,
                                                  (emlrtConstCTX)sp);
                  }
                  i1 = (int32_T)a_data[scalarLB - 1];
                  if ((i1 < 1) || (i1 > loop_ub)) {
                    emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub, &vc_emlrtBCI,
                                                  (emlrtConstCTX)sp);
                  }
                  idxl = inactiveConstraintIndices_data[i1 - 1];
                } else {
                  lambda = 0.0;
                }
              } else {
                lambda = 0.0;
              }
            } else {
              lambda = 0.0;
            }
            if (lambda > 0.0) {
              b_gamma = muDoubleScalarMin(1.0, lambda);
            } else {
              b_gamma = 1.0;
            }
            beta = obj->ArmijoRuleBeta;
            sigma = obj->ArmijoRuleSigma;
            loop_ub = Hg->size[0];
            i1 = a->size[0];
            a->size[0] = Hg->size[0];
            emxEnsureCapacity_real_T(sp, a, i1, &ud_emlrtRTEI);
            a_data = a->data;
            scalarLB_tmp = (Hg->size[0] / 2) << 1;
            vectorUB_tmp = scalarLB_tmp - 2;
            for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
              r5 = _mm_loadu_pd(&Hg_data[i1]);
              _mm_storeu_pd(&a_data[i1], _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
            }
            for (i1 = scalarLB_tmp; i1 < loop_ub; i1++) {
              a_data[i1] = b_gamma * Hg_data[i1];
            }
            k = x->size[0];
            if ((x->size[0] != a->size[0]) &&
                ((x->size[0] != 1) && (a->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(x->size[0], a->size[0], &fb_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if (x->size[0] == a->size[0]) {
              i1 = a->size[0];
              a->size[0] = x->size[0];
              emxEnsureCapacity_real_T(sp, a, i1, &wd_emlrtRTEI);
              a_data = a->data;
              scalarLB = (x->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&x_data[i1]);
                r6 = _mm_loadu_pd(&a_data[i1]);
                _mm_storeu_pd(&a_data[i1], _mm_add_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < k; i1++) {
                a_data[i1] += x_data[i1];
              }
              st.site = &yi_emlrtRSI;
              costNew = IKHelpers_computeCost(&st, a, obj->ExtraArgs, a__3,
                                              a__4, &r8);
            } else {
              st.site = &yi_emlrtRSI;
              costNew = binary_expand_op_2(&st, yi_emlrtRSI, x, a, obj, a__3,
                                           a__4, &r7);
              r8 = r7;
            }
            obj->ExtraArgs = r8;
            m = 0.0;
            do {
              exitg1 = 0;
              i1 = y->size[0] * y->size[1];
              y->size[0] = 1;
              k = grad->size[0];
              y->size[1] = grad->size[0];
              emxEnsureCapacity_real_T(sp, y, i1, &ae_emlrtRTEI);
              y_data = y->data;
              scalarLB = (grad->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&grad_data[i1]);
                _mm_storeu_pd(&y_data[i1], _mm_mul_pd(_mm_set1_pd(-sigma), r5));
              }
              for (i1 = scalarLB; i1 < k; i1++) {
                y_data[i1] = -sigma * grad_data[i1];
              }
              i1 = gradNew->size[0];
              gradNew->size[0] = Hg->size[0];
              emxEnsureCapacity_real_T(sp, gradNew, i1, &od_emlrtRTEI);
              gradNew_data = gradNew->data;
              for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
                r5 = _mm_loadu_pd(&Hg_data[i1]);
                _mm_storeu_pd(&gradNew_data[i1],
                              _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
              }
              for (i1 = scalarLB_tmp; i1 < loop_ub; i1++) {
                gradNew_data[i1] = b_gamma * Hg_data[i1];
              }
              st.site = &aj_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              c_dynamic_size_checks(&b_st, y, gradNew, y->size[1],
                                    gradNew->size[0]);
              if (cost - costNew < c_mtimes(y, gradNew)) {
                st.site = &bj_emlrtRSI;
                valid = (b_gamma < obj->StepTolerance);
                if (valid) {
                  exitFlag = StepSizeBelowMinimum;
                  st.site = &cj_emlrtRSI;
                  *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
                  exitg1 = 1;
                } else {
                  b_gamma *= beta;
                  m++;
                  i1 = a->size[0];
                  a->size[0] = Hg->size[0];
                  emxEnsureCapacity_real_T(sp, a, i1, &ee_emlrtRTEI);
                  a_data = a->data;
                  for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
                    r5 = _mm_loadu_pd(&Hg_data[i1]);
                    _mm_storeu_pd(&a_data[i1],
                                  _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
                  }
                  for (i1 = scalarLB_tmp; i1 < loop_ub; i1++) {
                    a_data[i1] = b_gamma * Hg_data[i1];
                  }
                  k = x->size[0];
                  if ((x->size[0] != a->size[0]) &&
                      ((x->size[0] != 1) && (a->size[0] != 1))) {
                    emlrtDimSizeImpxCheckR2021b(x->size[0], a->size[0],
                                                &eb_emlrtECI,
                                                (emlrtConstCTX)sp);
                  }
                  if (x->size[0] == a->size[0]) {
                    i1 = a->size[0];
                    a->size[0] = x->size[0];
                    emxEnsureCapacity_real_T(sp, a, i1, &ie_emlrtRTEI);
                    a_data = a->data;
                    scalarLB = (x->size[0] / 2) << 1;
                    vectorUB = scalarLB - 2;
                    for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                      r5 = _mm_loadu_pd(&x_data[i1]);
                      r6 = _mm_loadu_pd(&a_data[i1]);
                      _mm_storeu_pd(&a_data[i1], _mm_add_pd(r5, r6));
                    }
                    for (i1 = scalarLB; i1 < k; i1++) {
                      a_data[i1] += x_data[i1];
                    }
                    st.site = &dj_emlrtRSI;
                    costNew = IKHelpers_computeCost(&st, a, obj->ExtraArgs,
                                                    a__3, a__4, &r10);
                  } else {
                    st.site = &dj_emlrtRSI;
                    costNew = binary_expand_op_2(&st, dj_emlrtRSI, x, a, obj,
                                                 a__3, a__4, &r9);
                    r10 = r9;
                  }
                  obj->ExtraArgs = r10;
                }
              } else {
                i1 = xSol->size[0];
                xSol->size[0] = Hg->size[0];
                emxEnsureCapacity_real_T(sp, xSol, i1, &de_emlrtRTEI);
                xSol_data = xSol->data;
                for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
                  r5 = _mm_loadu_pd(&Hg_data[i1]);
                  _mm_storeu_pd(&xSol_data[i1],
                                _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
                }
                for (i1 = scalarLB_tmp; i1 < loop_ub; i1++) {
                  xSol_data[i1] = b_gamma * Hg_data[i1];
                }
                k = x->size[0];
                if ((x->size[0] != xSol->size[0]) &&
                    ((x->size[0] != 1) && (xSol->size[0] != 1))) {
                  emlrtDimSizeImpxCheckR2021b(x->size[0], xSol->size[0],
                                              &db_emlrtECI, (emlrtConstCTX)sp);
                }
                if (x->size[0] == xSol->size[0]) {
                  i1 = xSol->size[0];
                  xSol->size[0] = x->size[0];
                  emxEnsureCapacity_real_T(sp, xSol, i1, &fe_emlrtRTEI);
                  xSol_data = xSol->data;
                  scalarLB = (x->size[0] / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                    r5 = _mm_loadu_pd(&x_data[i1]);
                    r6 = _mm_loadu_pd(&xSol_data[i1]);
                    _mm_storeu_pd(&xSol_data[i1], _mm_add_pd(r5, r6));
                  }
                  for (i1 = scalarLB; i1 < k; i1++) {
                    xSol_data[i1] += x_data[i1];
                  }
                } else {
                  st.site = &kt_emlrtRSI;
                  c_plus(&st, xSol, x);
                  xSol_data = xSol->data;
                }
                st.site = &ej_emlrtRSI;
                args = obj->ExtraArgs;
                k = args->GradTemp->size[0];
                i1 = gradNew->size[0];
                gradNew->size[0] = k;
                emxEnsureCapacity_real_T(&st, gradNew, i1, &he_emlrtRTEI);
                gradNew_data = gradNew->data;
                scalarLB = args->GradTemp->size[0];
                for (i1 = 0; i1 < scalarLB; i1++) {
                  gradNew_data[i1] = args->GradTemp->data[i1];
                }
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = 1;
            } else if (m == 0.0) {
              st.site = &fj_emlrtRSI;
              if (muDoubleScalarAbs(b_gamma - lambda) < 1.4901161193847656E-8) {
                i1 = obj->ConstraintMatrix->size[1];
                if ((idxl < 1) || (idxl > i1)) {
                  emlrtDynamicBoundsCheckR2012b(idxl, 1, i1, &kc_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                loop_ub = obj->ConstraintMatrix->size[0];
                i1 = a->size[0];
                a->size[0] = loop_ub;
                emxEnsureCapacity_real_T(sp, a, i1, &ne_emlrtRTEI);
                a_data = a->data;
                k = obj->ConstraintMatrix->size[0];
                for (i1 = 0; i1 < k; i1++) {
                  a_data[i1] = obj->ConstraintMatrix
                                   ->data[i1 + obj->ConstraintMatrix->size[0] *
                                                   (idxl - 1)];
                }
                if (idxl > activeSet->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(idxl, 1, activeSet->size[0],
                                                &qc_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                activeSet_data[idxl - 1] = true;
                scalarLB = activeSet->size[0];
                last = 0;
                for (loop_ub_tmp = 0; loop_ub_tmp < scalarLB; loop_ub_tmp++) {
                  if (activeSet_data[loop_ub_tmp]) {
                    last++;
                  }
                }
                i1 = r3->size[0];
                r3->size[0] = last;
                emxEnsureCapacity_int32_T(sp, r3, i1, &vd_emlrtRTEI);
                ii_data = r3->data;
                last = 0;
                for (loop_ub_tmp = 0; loop_ub_tmp < scalarLB; loop_ub_tmp++) {
                  if (activeSet_data[loop_ub_tmp]) {
                    ii_data[last] = loop_ub_tmp;
                    last++;
                  }
                }
                last = obj->ConstraintMatrix->size[1];
                i1 = A->size[0] * A->size[1];
                A->size[0] = obj->ConstraintMatrix->size[0];
                k = r3->size[0];
                A->size[1] = r3->size[0];
                emxEnsureCapacity_real_T(sp, A, i1, &pe_emlrtRTEI);
                A_data = A->data;
                for (i1 = 0; i1 < k; i1++) {
                  scalarLB = obj->ConstraintMatrix->size[0];
                  for (i2 = 0; i2 < scalarLB; i2++) {
                    if ((ii_data[i1] < 0) || (ii_data[i1] > last - 1)) {
                      emlrtDynamicBoundsCheckR2012b(ii_data[i1], 0, last - 1,
                                                    &sc_emlrtBCI,
                                                    (emlrtConstCTX)sp);
                    }
                    A_data[i2 + A->size[0] * i1] =
                        obj->ConstraintMatrix
                            ->data[i2 + obj->ConstraintMatrix->size[0] *
                                            ii_data[i1]];
                  }
                }
                st.site = &gj_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                b_dynamic_size_checks(&b_st, a, H, a->size[0], H->size[0]);
                b_st.site = &dl_emlrtRSI;
                b_mtimes(&b_st, a, H, y);
                st.site = &gj_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                c_dynamic_size_checks(&b_st, y, a, y->size[1], a->size[0]);
                i1 = b_y->size[0] * b_y->size[1];
                b_y->size[0] = loop_ub;
                b_y->size[1] = loop_ub;
                emxEnsureCapacity_real_T(sp, b_y, i1, &qd_emlrtRTEI);
                y_data = b_y->data;
                for (i1 = 0; i1 < loop_ub; i1++) {
                  scalarLB = (a->size[0] / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (i2 = 0; i2 <= vectorUB; i2 += 2) {
                    r5 = _mm_loadu_pd(&a_data[i2]);
                    _mm_storeu_pd(&y_data[i2 + b_y->size[0] * i1],
                                  _mm_mul_pd(r5, _mm_set1_pd(a_data[i1])));
                  }
                  for (i2 = scalarLB; i2 < loop_ub; i2++) {
                    y_data[i2 + b_y->size[0] * i1] = a_data[i2] * a_data[i1];
                  }
                }
                st.site = &gj_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                d_dynamic_size_checks(&b_st, b_y, H, b_y->size[1], H->size[0]);
                b_st.site = &dl_emlrtRSI;
                d_mtimes(&b_st, b_y, H, AIn);
                st.site = &gj_emlrtRSI;
                b_st.site = &wk_emlrtRSI;
                d_dynamic_size_checks(&b_st, H, AIn, H->size[1], AIn->size[0]);
                b_st.site = &dl_emlrtRSI;
                d_mtimes(&b_st, H, AIn, b_y);
                y_data = b_y->data;
                b_gamma = 1.0 / c_mtimes(y, a);
                loop_ub_tmp = b_y->size[0] * b_y->size[1];
                scalarLB = (loop_ub_tmp / 2) << 1;
                vectorUB = scalarLB - 2;
                for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                  r5 = _mm_loadu_pd(&y_data[i1]);
                  _mm_storeu_pd(&y_data[i1],
                                _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
                }
                for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                  y_data[i1] *= b_gamma;
                }
                if ((H->size[0] != b_y->size[0]) &&
                    ((H->size[0] != 1) && (b_y->size[0] != 1))) {
                  emlrtDimSizeImpxCheckR2021b(H->size[0], b_y->size[0],
                                              &cb_emlrtECI, (emlrtConstCTX)sp);
                }
                if ((H->size[1] != b_y->size[1]) &&
                    ((H->size[1] != 1) && (b_y->size[1] != 1))) {
                  emlrtDimSizeImpxCheckR2021b(H->size[1], b_y->size[1],
                                              &bb_emlrtECI, (emlrtConstCTX)sp);
                }
                if ((H->size[0] == b_y->size[0]) &&
                    (H->size[1] == b_y->size[1])) {
                  loop_ub_tmp = H->size[0] * H->size[1];
                  scalarLB = (loop_ub_tmp / 2) << 1;
                  vectorUB = scalarLB - 2;
                  for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                    r5 = _mm_loadu_pd(&H_data[i1]);
                    r6 = _mm_loadu_pd(&y_data[i1]);
                    _mm_storeu_pd(&H_data[i1], _mm_sub_pd(r5, r6));
                  }
                  for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                    H_data[i1] -= y_data[i1];
                  }
                } else {
                  st.site = &gj_emlrtRSI;
                  minus(&st, H, b_y);
                  H_data = H->data;
                }
                guard1 = true;
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }
          if (guard2) {
            real_T b_H[2];
            if ((k != grad->size[0]) && ((k != 1) && (grad->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(k, grad->size[0], &ab_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if (gradNew->size[0] == grad->size[0]) {
              i1 = grad->size[0];
              grad->size[0] = k;
              emxEnsureCapacity_real_T(sp, grad, i1, &le_emlrtRTEI);
              grad_data = grad->data;
              scalarLB = (gradNew->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&gradNew_data[i1]);
                r6 = _mm_loadu_pd(&grad_data[i1]);
                _mm_storeu_pd(&grad_data[i1], _mm_sub_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < k; i1++) {
                grad_data[i1] = gradNew_data[i1] - grad_data[i1];
              }
            } else {
              st.site = &jt_emlrtRSI;
              b_minus(&st, grad, gradNew);
              grad_data = grad->data;
            }
            st.site = &hj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            e_dynamic_size_checks(&b_st, Hg, grad, Hg->size[0], grad->size[0]);
            b_gamma = g_mtimes(Hg, grad);
            i1 = y->size[0] * y->size[1];
            y->size[0] = 1;
            k = grad->size[0];
            y->size[1] = grad->size[0];
            emxEnsureCapacity_real_T(sp, y, i1, &ae_emlrtRTEI);
            y_data = y->data;
            last = (grad->size[0] / 2) << 1;
            scalarLB = last - 2;
            for (i1 = 0; i1 <= scalarLB; i1 += 2) {
              r5 = _mm_loadu_pd(&grad_data[i1]);
              _mm_storeu_pd(&y_data[i1], _mm_mul_pd(_mm_set1_pd(0.2), r5));
            }
            for (i1 = last; i1 < k; i1++) {
              y_data[i1] = 0.2 * grad_data[i1];
            }
            st.site = &hj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            f_dynamic_size_checks(&b_st, y, H, y->size[1], H->size[0]);
            b_st.site = &dl_emlrtRSI;
            h_mtimes(&b_st, y, H, d_y);
            st.site = &hj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            c_dynamic_size_checks(&b_st, d_y, grad, d_y->size[1],
                                  grad->size[0]);
            if (b_gamma < c_mtimes(d_y, grad)) {
              i1 = y->size[0] * y->size[1];
              y->size[0] = 1;
              y->size[1] = grad->size[0];
              emxEnsureCapacity_real_T(sp, y, i1, &ae_emlrtRTEI);
              y_data = y->data;
              for (i1 = 0; i1 <= scalarLB; i1 += 2) {
                r5 = _mm_loadu_pd(&grad_data[i1]);
                _mm_storeu_pd(&y_data[i1], _mm_mul_pd(_mm_set1_pd(0.8), r5));
              }
              for (i1 = last; i1 < k; i1++) {
                y_data[i1] = 0.8 * grad_data[i1];
              }
              st.site = &ij_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              f_dynamic_size_checks(&b_st, y, H, y->size[1], H->size[0]);
              b_st.site = &dl_emlrtRSI;
              h_mtimes(&b_st, y, H, d_y);
              st.site = &ij_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              c_dynamic_size_checks(&b_st, d_y, grad, d_y->size[1],
                                    grad->size[0]);
              st.site = &ij_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              b_dynamic_size_checks(&b_st, grad, H, grad->size[0], H->size[0]);
              b_st.site = &dl_emlrtRSI;
              b_mtimes(&b_st, grad, H, y);
              st.site = &ij_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              c_dynamic_size_checks(&b_st, y, grad, y->size[1], grad->size[0]);
              st.site = &ij_emlrtRSI;
              b_st.site = &wk_emlrtRSI;
              e_dynamic_size_checks(&b_st, Hg, grad, Hg->size[0],
                                    grad->size[0]);
              b_gamma = c_mtimes(d_y, grad) / (c_mtimes(y, grad) - b_gamma);
            } else {
              b_gamma = 1.0;
            }
            for (i1 = 0; i1 <= vectorUB_tmp; i1 += 2) {
              r5 = _mm_loadu_pd(&Hg_data[i1]);
              _mm_storeu_pd(&Hg_data[i1], _mm_mul_pd(_mm_set1_pd(b_gamma), r5));
            }
            for (i1 = scalarLB_tmp; i1 < loop_ub; i1++) {
              Hg_data[i1] *= b_gamma;
            }
            i1 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = H->size[0];
            b_y->size[1] = H->size[1];
            emxEnsureCapacity_real_T(sp, b_y, i1, &od_emlrtRTEI);
            y_data = b_y->data;
            loop_ub_tmp = H->size[0] * H->size[1];
            scalarLB = (loop_ub_tmp / 2) << 1;
            vectorUB = scalarLB - 2;
            for (i1 = 0; i1 <= vectorUB; i1 += 2) {
              r5 = _mm_loadu_pd(&H_data[i1]);
              _mm_storeu_pd(&y_data[i1],
                            _mm_mul_pd(_mm_set1_pd(1.0 - b_gamma), r5));
            }
            for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
              y_data[i1] = (1.0 - b_gamma) * H_data[i1];
            }
            st.site = &jj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            dynamic_size_checks(&b_st, b_y, grad, b_y->size[1], grad->size[0]);
            b_st.site = &dl_emlrtRSI;
            f_mtimes(&b_st, b_y, grad, a);
            a_data = a->data;
            loop_ub = Hg->size[0];
            if ((Hg->size[0] != a->size[0]) &&
                ((Hg->size[0] != 1) && (a->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(Hg->size[0], a->size[0], &y_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if (Hg->size[0] == a->size[0]) {
              scalarLB = (Hg->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&Hg_data[i1]);
                r6 = _mm_loadu_pd(&a_data[i1]);
                _mm_storeu_pd(&Hg_data[i1], _mm_add_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < loop_ub; i1++) {
                Hg_data[i1] += a_data[i1];
              }
            } else {
              st.site = &jj_emlrtRSI;
              b_plus(&st, Hg, a);
              Hg_data = Hg->data;
            }
            st.site = &kj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            e_dynamic_size_checks(&b_st, Hg, grad, Hg->size[0], grad->size[0]);
            b_gamma = g_mtimes(Hg, grad);
            st.site = &lj_emlrtRSI;
            eye(&st, n, AIn);
            AIn_data = AIn->data;
            loop_ub = Hg->size[0];
            i1 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = Hg->size[0];
            b_y->size[1] = grad->size[0];
            emxEnsureCapacity_real_T(sp, b_y, i1, &qe_emlrtRTEI);
            y_data = b_y->data;
            for (i1 = 0; i1 < k; i1++) {
              scalarLB = (Hg->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i2 = 0; i2 <= vectorUB; i2 += 2) {
                r5 = _mm_loadu_pd(&Hg_data[i2]);
                _mm_storeu_pd(
                    &y_data[i2 + b_y->size[0] * i1],
                    _mm_div_pd(
                        _mm_add_pd(_mm_set1_pd(0.0),
                                   _mm_mul_pd(r5, _mm_set1_pd(grad_data[i1]))),
                        _mm_set1_pd(b_gamma)));
              }
              for (i2 = scalarLB; i2 < loop_ub; i2++) {
                y_data[i2 + b_y->size[0] * i1] =
                    Hg_data[i2] * grad_data[i1] / b_gamma;
              }
            }
            if ((AIn->size[0] != b_y->size[0]) &&
                ((AIn->size[0] != 1) && (b_y->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(AIn->size[0], b_y->size[0],
                                          &x_emlrtECI, (emlrtConstCTX)sp);
            }
            if ((AIn->size[1] != b_y->size[1]) &&
                ((AIn->size[1] != 1) && (b_y->size[1] != 1))) {
              emlrtDimSizeImpxCheckR2021b(AIn->size[1], b_y->size[1],
                                          &w_emlrtECI, (emlrtConstCTX)sp);
            }
            if ((AIn->size[0] == b_y->size[0]) &&
                (AIn->size[1] == b_y->size[1])) {
              loop_ub_tmp = AIn->size[0] * AIn->size[1];
              scalarLB = (loop_ub_tmp / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&AIn_data[i1]);
                r6 = _mm_loadu_pd(&y_data[i1]);
                _mm_storeu_pd(&AIn_data[i1], _mm_sub_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                AIn_data[i1] -= y_data[i1];
              }
            } else {
              st.site = &lj_emlrtRSI;
              minus(&st, AIn, b_y);
            }
            st.site = &mj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            d_dynamic_size_checks(&b_st, AIn, H, AIn->size[1], H->size[0]);
            b_st.site = &dl_emlrtRSI;
            d_mtimes(&b_st, AIn, H, b_y);
            st.site = &mj_emlrtRSI;
            b_st.site = &wk_emlrtRSI;
            d_dynamic_size_checks(&b_st, b_y, AIn, b_y->size[1], AIn->size[1]);
            b_st.site = &dl_emlrtRSI;
            i_mtimes(&b_st, b_y, AIn, H);
            H_data = H->data;
            i1 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = Hg->size[0];
            b_y->size[1] = Hg->size[0];
            emxEnsureCapacity_real_T(sp, b_y, i1, &ue_emlrtRTEI);
            y_data = b_y->data;
            for (i1 = 0; i1 < loop_ub; i1++) {
              scalarLB = (Hg->size[0] / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i2 = 0; i2 <= vectorUB; i2 += 2) {
                r5 = _mm_loadu_pd(&Hg_data[i2]);
                _mm_storeu_pd(
                    &y_data[i2 + b_y->size[0] * i1],
                    _mm_div_pd(
                        _mm_add_pd(_mm_set1_pd(0.0),
                                   _mm_mul_pd(r5, _mm_set1_pd(Hg_data[i1]))),
                        _mm_set1_pd(b_gamma)));
              }
              for (i2 = scalarLB; i2 < loop_ub; i2++) {
                y_data[i2 + b_y->size[0] * i1] =
                    Hg_data[i2] * Hg_data[i1] / b_gamma;
              }
            }
            if ((H->size[0] != b_y->size[0]) &&
                ((H->size[0] != 1) && (b_y->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(H->size[0], b_y->size[0], &v_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if ((H->size[1] != b_y->size[1]) &&
                ((H->size[1] != 1) && (b_y->size[1] != 1))) {
              emlrtDimSizeImpxCheckR2021b(H->size[1], b_y->size[1], &u_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if ((H->size[0] == b_y->size[0]) && (H->size[1] == b_y->size[1])) {
              loop_ub_tmp = H->size[0] * H->size[1];
              scalarLB = (loop_ub_tmp / 2) << 1;
              vectorUB = scalarLB - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                r5 = _mm_loadu_pd(&H_data[i1]);
                r6 = _mm_loadu_pd(&y_data[i1]);
                _mm_storeu_pd(&H_data[i1], _mm_add_pd(r5, r6));
              }
              for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
                H_data[i1] += y_data[i1];
              }
            } else {
              st.site = &mj_emlrtRSI;
              plus(&st, H, b_y);
              H_data = H->data;
            }
            b_H[0] = H->size[0];
            b_H[1] = H->size[1];
            st.site = &nj_emlrtRSI;
            b_eye(&st, b_H, AIn);
            AIn_data = AIn->data;
            loop_ub_tmp = AIn->size[0] * AIn->size[1];
            scalarLB = (loop_ub_tmp / 2) << 1;
            vectorUB = scalarLB - 2;
            for (i1 = 0; i1 <= vectorUB; i1 += 2) {
              r5 = _mm_loadu_pd(&AIn_data[i1]);
              _mm_storeu_pd(&AIn_data[i1],
                            _mm_mul_pd(_mm_set1_pd(1.4901161193847656E-8), r5));
            }
            for (i1 = scalarLB; i1 < loop_ub_tmp; i1++) {
              AIn_data[i1] *= 1.4901161193847656E-8;
            }
            if ((H->size[0] != AIn->size[0]) &&
                ((H->size[0] != 1) && (AIn->size[0] != 1))) {
              emlrtDimSizeImpxCheckR2021b(H->size[0], AIn->size[0], &t_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if ((H->size[1] != AIn->size[1]) &&
                ((H->size[1] != 1) && (AIn->size[1] != 1))) {
              emlrtDimSizeImpxCheckR2021b(H->size[1], AIn->size[1], &s_emlrtECI,
                                          (emlrtConstCTX)sp);
            }
            if (AIn->size[0] == 1) {
              loop_ub = H->size[0];
            } else {
              loop_ub = AIn->size[0];
            }
            i1 = b_y->size[0] * b_y->size[1];
            b_y->size[0] = loop_ub;
            if (AIn->size[1] == 1) {
              k = H->size[1];
            } else {
              k = AIn->size[1];
            }
            b_y->size[1] = k;
            emxEnsureCapacity_real_T(sp, b_y, i1, &ve_emlrtRTEI);
            y_data = b_y->data;
            last = (H->size[0] != 1);
            scalarLB = (H->size[1] != 1);
            loop_ub_tmp = (AIn->size[0] != 1);
            vectorUB = (AIn->size[1] != 1);
            idxl = 0;
            scalarLB_tmp = 0;
            for (i1 = 0; i1 < k; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                y_data[i2 + b_y->size[0] * i1] =
                    H_data[i2 * last + H->size[0] * idxl] +
                    AIn_data[i2 * loop_ub_tmp + AIn->size[0] * scalarLB_tmp];
              }
              scalarLB_tmp += vectorUB;
              idxl += scalarLB;
            }
            i1 = AIn->size[0] * AIn->size[1];
            AIn->size[0] = loop_ub;
            AIn->size[1] = k;
            emxEnsureCapacity_real_T(sp, AIn, i1, &ve_emlrtRTEI);
            AIn_data = AIn->data;
            for (i1 = 0; i1 < k; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                AIn_data[i2 + AIn->size[0] * i1] =
                    y_data[i2 + b_y->size[0] * i1];
              }
            }
            st.site = &nj_emlrtRSI;
            if (!isPositiveDefinite(&st, AIn)) {
              exitFlag = HessianNotPositiveSemidefinite;
              st.site = &oj_emlrtRSI;
              *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
              exitg2 = 1;
            } else {
              guard1 = true;
            }
          }
          if (guard1) {
            st.site = &pj_emlrtRSI;
            if (f_DampedBFGSwGradientProjection(&st, obj, xSol)) {
              loop_ub = x->size[0];
              i = xSol->size[0];
              xSol->size[0] = x->size[0];
              emxEnsureCapacity_real_T(sp, xSol, i, &se_emlrtRTEI);
              xSol_data = xSol->data;
              for (i = 0; i < loop_ub; i++) {
                xSol_data[i] = x_data[i];
              }
              exitFlag = SearchDirectionInvalid;
              st.site = &qj_emlrtRSI;
              *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
              exitg2 = 1;
            } else {
              loop_ub = xSol->size[0];
              i1 = x->size[0];
              x->size[0] = xSol->size[0];
              emxEnsureCapacity_real_T(sp, x, i1, &re_emlrtRTEI);
              x_data = x->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                x_data[i1] = xSol_data[i1];
              }
              loop_ub = gradNew->size[0];
              i1 = grad->size[0];
              grad->size[0] = gradNew->size[0];
              emxEnsureCapacity_real_T(sp, grad, i1, &te_emlrtRTEI);
              grad_data = grad->data;
              for (i1 = 0; i1 < loop_ub; i1++) {
                grad_data[i1] = gradNew_data[i1];
              }
              cost = costNew;
              b_i++;
            }
          }
        }
      }
    } else {
      exitFlag = IterationLimitExceeded;
      st.site = &rj_emlrtRSI;
      *err = IKHelpers_evaluateSolution(&st, obj->ExtraArgs);
      *iter = obj->MaxNumIterationInternal;
      exitg2 = 1;
    }
  } while (exitg2 == 0);
  emxFree_boolean_T(sp, &b_activeSet);
  emxFree_int32_T(sp, &r4);
  emxFree_int32_T(sp, &r3);
  emxFree_real_T(sp, &d_y);
  emxFree_int32_T(sp, &ii);
  emxFree_real_T(sp, &c_y);
  emxFree_real_T(sp, &b_y);
  emxFree_real_T(sp, &y);
  emxFree_int32_T(sp, &r2);
  emxFree_int32_T(sp, &r1);
  emxFree_real_T(sp, &gradNew);
  emxFree_int32_T(sp, &inactiveConstraintIndices);
  emxFree_real_T(sp, &AIn);
  emxFree_real_T(sp, &bIn);
  emxFree_real_T(sp, &P);
  emxFree_real_T(sp, &Hg);
  emxFree_real_T(sp, &a);
  emxFree_real_T(sp, &A);
  emxFree_boolean_T(sp, &activeSet);
  emxFree_real_T(sp, &H);
  emxFree_real_T(sp, &grad);
  emxFree_real_T(sp, &a__4);
  emxFree_real_T(sp, &x);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return exitFlag;
}

/* End of code generation (DampedBFGSwGradientProjection.c) */
