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

#ifndef RIGIDBODYTREE_H
#define RIGIDBODYTREE_H

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
e_robotics_manip_internal_Rigid *
RigidBodyTree_RigidBodyTree(e_robotics_manip_internal_Rigid *obj);

void RigidBodyTree_addBody(e_robotics_manip_internal_Rigid *obj,
                           c_robotics_manip_internal_Rigid *bodyin,
                           const char parentName_data[],
                           const int parentName_size[2],
                           d_robotics_manip_internal_Colli *iobj_0,
                           rigidBodyJoint *iobj_1,
                           c_robotics_manip_internal_Rigid *iobj_2);

void c_RigidBodyTree_efficientFKAndJ(e_robotics_manip_internal_Rigid *obj,
                                     const emxArray_real_T *qv, double bid1,
                                     double T_data[], int T_size[2],
                                     emxArray_real_T *Jac);

double c_RigidBodyTree_findBodyIndexBy(e_robotics_manip_internal_Rigid *obj,
                                       const char bodyname_data[],
                                       const int bodyname_size[2]);

void c_RigidBodyTree_get_JointPositi(e_robotics_manip_internal_Rigid *obj,
                                     emxArray_real_T *limits);

void c_RigidBodyTree_validateConfigu(e_robotics_manip_internal_Rigid *obj,
                                     const b_struct_T Q[6],
                                     emxArray_real_T *qvec);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (RigidBodyTree.h) */
