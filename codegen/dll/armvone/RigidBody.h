/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: RigidBody.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef RIGIDBODY_H
#define RIGIDBODY_H

/* Include Files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
c_robotics_manip_internal_Rigid *RigidBody_RigidBody(
    c_robotics_manip_internal_Rigid *obj, const char bodyInput[10],
    d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1);

c_robotics_manip_internal_Rigid *
RigidBody_copy(c_robotics_manip_internal_Rigid *obj,
               d_robotics_manip_internal_Colli *iobj_0, rigidBodyJoint *iobj_1,
               c_robotics_manip_internal_Rigid *iobj_2);

c_robotics_manip_internal_Rigid *
b_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1);

c_robotics_manip_internal_Rigid *
c_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1);

c_robotics_manip_internal_Rigid *
d_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1);

c_robotics_manip_internal_Rigid *
e_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1);

c_robotics_manip_internal_Rigid *
f_RigidBody_RigidBody(c_robotics_manip_internal_Rigid *obj,
                      d_robotics_manip_internal_Colli *iobj_0,
                      rigidBodyJoint *iobj_1);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for RigidBody.h
 *
 * [EOF]
 */