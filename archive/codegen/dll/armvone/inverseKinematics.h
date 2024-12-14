/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * inverseKinematics.h
 *
 * Code generation for function 'inverseKinematics'
 *
 */

#ifndef INVERSEKINEMATICS_H
#define INVERSEKINEMATICS_H

/* Include files */
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
    inverseKinematics *obj, const b_struct_T initialGuess[6],
    emxArray_struct_T *QSol, char solutionInfo_Status_data[],
    int solutionInfo_Status_size[2], double *solutionInfo_NumRandomRestarts,
    double *solutionInfo_PoseErrorNorm, double *solutionInfo_ExitFlag);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (inverseKinematics.h) */
