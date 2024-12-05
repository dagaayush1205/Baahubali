/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * CharacterVector.c
 *
 * Code generation for function 'CharacterVector'
 *
 */

/* Include files */
#include "CharacterVector.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo ve_emlrtBCI = {
    1,                           /* iFirst */
    200,                         /* iLast */
    26,                          /* lineNo */
    28,                          /* colNo */
    "",                          /* aName */
    "CharacterVector/setVector", /* fName */
    "/home/pritesh0/matlab24/toolbox/robotics/robotmanip/+robotics/+manip/"
    "+internal/CharacterVector.m", /* pName */
    0                              /* checkKind */
};

/* Function Definitions */
void CharacterVector_setVector(const emlrtStack *sp,
                               c_robotics_manip_internal_Chara *obj,
                               const char_T vec_data[],
                               const int32_T vec_size[2])
{
  int32_T b_iv[2];
  int32_T iv1[2];
  int32_T i;
  int32_T loop_ub;
  obj->Length = vec_size[1];
  if (vec_size[1] < 1) {
    i = 0;
    loop_ub = 0;
  } else {
    i = vec_size[1];
    if (vec_size[1] > 200) {
      emlrtDynamicBoundsCheckR2012b(vec_size[1], 1, 200, &ve_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = vec_size[1];
  }
  b_iv[0] = 1;
  b_iv[1] = loop_ub;
  iv1[0] = 1;
  iv1[1] = i;
  emlrtSubAssignSizeCheckR2012b(&b_iv[0], 2, &iv1[0], 2, &f_emlrtECI,
                                (emlrtCTX)sp);
  if (loop_ub - 1 >= 0) {
    memcpy(&obj->Vector[0], &vec_data[0], (uint32_T)loop_ub * sizeof(char_T));
  }
}

/* End of code generation (CharacterVector.c) */
