/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: armvone_emxAPI.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef ARMVONE_EMXAPI_H
#define ARMVONE_EMXAPI_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions,
                                                 const int *size);

extern emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                        int numDimensions,
                                                        const int *size);

extern emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                                      int cols);

extern emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols);

extern void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray);

extern void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray,
                                   int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for armvone_emxAPI.h
 *
 * [EOF]
 */
