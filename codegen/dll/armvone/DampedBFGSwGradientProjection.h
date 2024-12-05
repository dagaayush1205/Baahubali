/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: DampedBFGSwGradientProjection.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef DAMPEDBFGSWGRADIENTPROJECTION_H
#define DAMPEDBFGSWGRADIENTPROJECTION_H

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
c_robotics_core_internal_NLPSol
c_DampedBFGSwGradientProjection(c_robotics_core_internal_Damped *obj,
                                emxArray_real_T *xSol, double *err,
                                double *iter);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for DampedBFGSwGradientProjection.h
 *
 * [EOF]
 */
