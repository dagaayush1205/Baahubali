/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: _coder_armvone_api.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef _CODER_ARMVONE_API_H
#define _CODER_ARMVONE_API_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x200
#define struct_emxArray_char_T_1x200
struct emxArray_char_T_1x200 {
  char_T data[200];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x200 */
#ifndef typedef_emxArray_char_T_1x200
#define typedef_emxArray_char_T_1x200
typedef struct emxArray_char_T_1x200 emxArray_char_T_1x200;
#endif /* typedef_emxArray_char_T_1x200 */

#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1 {
  real_T data[1];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_1x1 */
#ifndef typedef_emxArray_real_T_1x1
#define typedef_emxArray_real_T_1x1
typedef struct emxArray_real_T_1x1 emxArray_real_T_1x1;
#endif /* typedef_emxArray_real_T_1x1 */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  emxArray_char_T_1x200 JointName;
  emxArray_real_T_1x1 JointPosition;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T
typedef struct {
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct0_T;
#endif /* typedef_emxArray_struct0_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void armvone(real_T q0[6], real_T pos[3], emxArray_struct0_T *vone);

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
/*
 * File trailer for _coder_armvone_api.h
 *
 * [EOF]
 */
