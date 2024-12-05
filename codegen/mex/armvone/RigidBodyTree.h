/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * RigidBodyTree.h
 *
 * Code generation for function 'RigidBodyTree'
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
e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(const emlrtStack *sp,
                            e_robotics_manip_internal_Rigid *obj);

void RigidBodyTree_addBody(
    const emlrtStack *sp, e_robotics_manip_internal_Rigid *obj,
    c_robotics_manip_internal_Rigid *bodyin, const char_T parentName_data[],
    const int32_T parentName_size[2], d_robotics_manip_internal_Colli *iobj_0,
    rigidBodyJoint *iobj_1, c_robotics_manip_internal_Rigid *iobj_2);

void c_RigidBodyTree_bodyIndicesToPo(const emlrtStack *sp,
                                     const e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *bodyIndices,
                                     emxArray_real_T *posIndices);

void c_RigidBodyTree_efficientFKAndJ(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *qv, real_T bid1,
                                     real_T T_data[], int32_T T_size[2],
                                     emxArray_real_T *Jac);

real_T c_RigidBodyTree_findBodyIndexBy(const emlrtStack *sp,
                                       e_robotics_manip_internal_Rigid *obj,
                                       const char_T bodyname_data[],
                                       const int32_T bodyname_size[2]);

void c_RigidBodyTree_get_JointPositi(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     emxArray_real_T *limits);

void c_RigidBodyTree_validateConfigu(const emlrtStack *sp,
                                     e_robotics_manip_internal_Rigid *obj,
                                     const struct_T Q[6],
                                     emxArray_real_T *qvec);

/* End of code generation (RigidBodyTree.h) */
