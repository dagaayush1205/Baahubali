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

#pragma once

/* Include files */
#include "armvone_internal_types.h"
#include "armvone_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
inverseKinematics *c_inverseKinematics_inverseKine(const emlrtStack *sp,
                                                   inverseKinematics *obj,
                                                   b_rigidBodyTree *varargin_2);

real_T inverseKinematics_stepImpl(
    const emlrtStack *sp, inverseKinematics *obj, const real_T tform[16],
    const struct_T initialGuess[6], emxArray_struct0_T *QSol,
    char_T solutionInfo_Status_data[], int32_T solutionInfo_Status_size[2],
    real_T *solutionInfo_NumRandomRestarts, real_T *solutionInfo_PoseErrorNorm,
    real_T *solutionInfo_ExitFlag);

/* End of code generation (inverseKinematics.h) */
