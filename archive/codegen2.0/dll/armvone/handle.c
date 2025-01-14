/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * handle.c
 *
 * Code generation for function 'handle'
 *
 */

/* Include files */
#include "handle.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include "collisioncodegen_api.hpp"

/* Function Definitions */
void b_handle_matlabCodegenDestructo(d_robotics_manip_internal_Colli *obj)
{
  c_robotics_manip_internal_Colli b_obj;
  int b_i;
  if (!obj->matlabCodegenIsDeleted) {
    double d;
    int i;
    obj->matlabCodegenIsDeleted = true;
    d = obj->Size;
    i = (int)d;
    for (b_i = 0; b_i < i; b_i++) {
      b_obj = obj->CollisionGeometries->data[b_i];
      collisioncodegen_destructGeometry(&b_obj.CollisionPrimitive);
      obj->CollisionGeometries->data[b_i] = b_obj;
    }
  }
}

void handle_matlabCodegenDestructor(inverseKinematics *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }
}

/* End of code generation (handle.c) */
