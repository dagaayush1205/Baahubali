/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "indexShapeCheck.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo oh_emlrtRSI =
    {
        42,                /* lineNo */
        "indexShapeCheck", /* fcnName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
        "indexShapeCheck.m" /* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI =
    {
        122,           /* lineNo */
        5,             /* colNo */
        "errOrWarnIf", /* fName */
        "/home/pritesh0/matlab24/toolbox/eml/eml/+coder/+internal/"
        "indexShapeCheck.m" /* pName */
};

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, int32_T matrixSize,
                     const int32_T indexSize[2])
{
  emlrtStack st;
  boolean_T c;
  st.prev = sp;
  st.tls = sp->tls;
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    c = true;
  } else {
    c = false;
  }
  st.site = &oh_emlrtRSI;
  if (c) {
    emlrtErrorWithMessageIdR2018a(&st, &bb_emlrtRTEI,
                                  "Coder:FE:PotentialVectorVector",
                                  "Coder:FE:PotentialVectorVector", 0);
  }
}

/* End of code generation (indexShapeCheck.c) */
