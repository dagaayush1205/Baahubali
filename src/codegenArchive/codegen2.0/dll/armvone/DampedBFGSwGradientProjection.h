/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * DampedBFGSwGradientProjection.h
 *
 * Code generation for function 'DampedBFGSwGradientProjection'
 *
 */

#ifndef DAMPEDBFGSWGRADIENTPROJECTION_H
#define DAMPEDBFGSWGRADIENTPROJECTION_H

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
c_robotics_core_internal_NLPSol
c_DampedBFGSwGradientProjection(c_robotics_core_internal_Damped *obj,
                                emxArray_real_T *xSol, double *err,
                                double *iter);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (DampedBFGSwGradientProjection.h) */
