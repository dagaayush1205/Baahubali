/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_armvone_api.h
 *
 * Code generation for function 'armvone'
 *
 */

#ifndef _CODER_ARMVONE_API_H
#define _CODER_ARMVONE_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void armvone(real_T q0[6], real_T pos[3], real_T vone_data[],
             int32_T vone_size[2]);

void armvone_api(const mxArray *const prhs[2], const mxArray **plhs);

void armvone_atexit(void);

void armvone_initialize(void);

void armvone_terminate(void);

void armvone_xil_shutdown(void);

void armvone_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_armvone_api.h) */
