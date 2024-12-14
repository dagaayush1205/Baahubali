/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * CollisionSet.h
 *
 * Code generation for function 'CollisionSet'
 *
 */

#pragma once

/* Include files */
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
d_robotics_manip_internal_Colli *
CollisionSet_CollisionSet(const emlrtStack *sp,
                          d_robotics_manip_internal_Colli *obj,
                          real_T maxElements);

d_robotics_manip_internal_Colli *
CollisionSet_copy(const emlrtStack *sp, d_robotics_manip_internal_Colli *obj,
                  d_robotics_manip_internal_Colli *iobj_0);

/* End of code generation (CollisionSet.h) */
