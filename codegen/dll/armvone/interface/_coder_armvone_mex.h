/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: _coder_armvone_mex.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef _CODER_ARMVONE_MEX_H
#define _CODER_ARMVONE_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_armvone_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_armvone_mex.h
 *
 * [EOF]
 */