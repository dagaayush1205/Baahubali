/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rigidBodyJoint.h
 *
 * Code generation for function 'rigidBodyJoint'
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
void c_rigidBodyJoint_get_MotionSubs(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     real_T msubspace_data[],
                                     int32_T msubspace_size[2]);

void c_rigidBodyJoint_get_PositionLi(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     real_T lims_data[], int32_T lims_size[2]);

void c_rigidBodyJoint_set_MotionSubs(const emlrtStack *sp, rigidBodyJoint *obj,
                                     const real_T msubspace_data[],
                                     const int32_T msubspace_size[2]);

void c_rigidBodyJoint_transformBodyT(const emlrtStack *sp,
                                     const rigidBodyJoint *obj,
                                     const emxArray_real_T *q, real_T T[16]);

rigidBodyJoint *rigidBodyJoint_copy(const emlrtStack *sp,
                                    const rigidBodyJoint *obj,
                                    rigidBodyJoint *iobj_0);

void rigidBodyJoint_get_JointAxis(const emlrtStack *sp,
                                  const rigidBodyJoint *obj, real_T ax[3]);

void rigidBodyJoint_randomPosition(const emlrtStack *sp,
                                   const rigidBodyJoint *obj, real_T qv_data[],
                                   int32_T qv_size[2]);

rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(const emlrtStack *sp,
                                              rigidBodyJoint *obj,
                                              const char_T jname_data[],
                                              const int32_T jname_size[2]);

/* End of code generation (rigidBodyJoint.h) */
