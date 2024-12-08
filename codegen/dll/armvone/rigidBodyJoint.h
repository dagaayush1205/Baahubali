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

#ifndef RIGIDBODYJOINT_H
#define RIGIDBODYJOINT_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op_13(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2]);

void binary_expand_op_14(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2]);

void binary_expand_op_15(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2]);

void c_rigidBodyJoint_get_MotionSubs(const rigidBodyJoint *obj,
                                     double msubspace_data[],
                                     int msubspace_size[2]);

void c_rigidBodyJoint_get_PositionLi(const rigidBodyJoint *obj,
                                     double lims_data[], int lims_size[2]);

void c_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                     const double msubspace_data[]);

void c_rigidBodyJoint_transformBodyT(const rigidBodyJoint *obj,
                                     const emxArray_real_T *q, double T[16]);

void rigidBodyJoint_get_JointAxis(const rigidBodyJoint *obj, double ax[3]);

rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj,
                                              const char jname_data[],
                                              const int jname_size[2]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (rigidBodyJoint.h) */
