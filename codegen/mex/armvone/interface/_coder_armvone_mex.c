/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_armvone_mex.c
 *
 * Code generation for function '_coder_armvone_mex'
 *
 */

/* Include files */
#include "_coder_armvone_mex.h"
#include "_coder_armvone_api.h"
#include "armvone_data.h"
#include "armvone_initialize.h"
#include "armvone_terminate.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void armvone_mexFunction(armvoneStackData *SD, int32_T nlhs, mxArray *plhs[1],
                         int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        7, "armvone");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "armvone");
  }
  /* Call the function. */
  armvone_api(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  armvoneStackData *armvoneStackDataGlobal = NULL;
  armvoneStackDataGlobal = (armvoneStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(armvoneStackData));
  mexAtExit(&armvone_atexit);
  armvone_initialize();
  armvone_mexFunction(armvoneStackDataGlobal, nlhs, plhs, nrhs, prhs);
  armvone_terminate();
  emlrtMxFree(armvoneStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "UTF-8", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_armvone_mex.c) */
