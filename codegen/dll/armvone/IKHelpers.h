/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * IKHelpers.h
 *
 * Code generation for function 'IKHelpers'
 *
 */

#ifndef IKHELPERS_H
#define IKHELPERS_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double IKHelpers_computeCost(const emxArray_real_T *x,
                             c_robotics_manip_internal_IKExt *args,
                             double W[36], emxArray_real_T *Jac,
                             c_robotics_manip_internal_IKExt **b_args);

double IKHelpers_evaluateSolution(const c_robotics_manip_internal_IKExt *args);

int IKHelpers_randomConfig(c_robotics_manip_internal_IKExt *args,
                           double rc_data[]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (IKHelpers.h) */
