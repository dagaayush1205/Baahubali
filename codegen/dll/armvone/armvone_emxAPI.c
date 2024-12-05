/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: armvone_emxAPI.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "armvone_emxAPI.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>

/* Function Definitions */
/*
 * Arguments    : int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions, const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = (struct0_T *)malloc((unsigned int)numEl * sizeof(struct0_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

/*
 * Arguments    : struct0_T *data
 *                int numDimensions
 *                const int *size
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data,
                                                 int numDimensions,
                                                 const int *size)
{
  emxArray_struct0_T *emx;
  int i;
  int numEl;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : struct0_T *data
 *                int rows
 *                int cols
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
                                               int cols)
{
  emxArray_struct0_T *emx;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

/*
 * Arguments    : int rows
 *                int cols
 * Return Type  : emxArray_struct0_T *
 */
emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols)
{
  emxArray_struct0_T *emx;
  emxInit_struct0_T(&emx, 2);
  emx->size[0] = rows;
  rows *= cols;
  emx->size[1] = cols;
  emx->data = (struct0_T *)malloc((unsigned int)rows * sizeof(struct0_T));
  emx->numDimensions = 2;
  emx->allocatedSize = rows;
  return emx;
}

/*
 * Arguments    : emxArray_struct0_T *emxArray
 * Return Type  : void
 */
void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray)
{
  emxFree_struct0_T(&emxArray);
}

/*
 * Arguments    : emxArray_struct0_T **pEmxArray
 *                int numDimensions
 * Return Type  : void
 */
void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxInit_struct0_T(pEmxArray, numDimensions);
}

/*
 * File trailer for armvone_emxAPI.c
 *
 * [EOF]
 */
