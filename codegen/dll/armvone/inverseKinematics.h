/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: inverseKinematics.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef INVERSEKINEMATICS_H
#define INVERSEKINEMATICS_H

/* Include Files */
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
inverseKinematics *c_inverseKinematics_inverseKine(inverseKinematics *obj,
                                                   b_rigidBodyTree *varargin_2);

double inverseKinematics_solve(
    inverseKinematics *obj, const struct_T initialGuess[6],
    emxArray_struct0_T *QSol, char solutionInfo_Status_data[],
    int solutionInfo_Status_size[2], double *solutionInfo_NumRandomRestarts,
    double *solutionInfo_PoseErrorNorm, double *solutionInfo_ExitFlag);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for inverseKinematics.h
 *
 * [EOF]
 */
