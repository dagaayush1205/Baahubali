/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_types.h
 *
 * Code generation for function 'armvone'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include <stddef.h>

/* Type Definitions */
#ifndef d_typedef_c_robotics_core_inter
#define d_typedef_c_robotics_core_inter
typedef struct {
  emlrtTimespec StartTime;
} c_robotics_core_internal_System;
#endif /* d_typedef_c_robotics_core_inter */

#ifndef c_typedef_c_robotics_manip_inte
#define c_typedef_c_robotics_manip_inte
typedef struct {
  real_T Length;
  char_T Vector[200];
} c_robotics_manip_internal_Chara;
#endif /* c_typedef_c_robotics_manip_inte */

#ifndef typedef_rigidBodyJoint
#define typedef_rigidBodyJoint
typedef struct {
  real_T VelocityNumber;
  real_T PositionNumber;
  boolean_T InTree;
  real_T JointToParentTransform[16];
  real_T ChildToJointTransform[16];
  c_robotics_manip_internal_Chara NameInternal;
  real_T PositionLimitsInternal[14];
  real_T HomePositionInternal[7];
  real_T JointAxisInternal[3];
  real_T MotionSubspaceInternal[36];
  c_robotics_manip_internal_Chara TypeInternal;
} rigidBodyJoint;
#endif /* typedef_rigidBodyJoint */

#ifndef d_typedef_c_robotics_manip_inte
#define d_typedef_c_robotics_manip_inte
typedef struct {
  void *CollisionPrimitive;
  real_T LocalPose[16];
  real_T WorldPose[16];
  real_T MeshScale[3];
} c_robotics_manip_internal_Colli;
#endif /* d_typedef_c_robotics_manip_inte */

#ifndef c_typedef_c_emxArray_robotics_m
#define c_typedef_c_emxArray_robotics_m
typedef struct {
  c_robotics_manip_internal_Colli *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c_emxArray_robotics_manip_inter;
#endif /* c_typedef_c_emxArray_robotics_m */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_char_T_1x200
#define struct_emxArray_char_T_1x200
struct emxArray_char_T_1x200 {
  char_T data[200];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x200 */
#ifndef typedef_emxArray_char_T_1x200
#define typedef_emxArray_char_T_1x200
typedef struct emxArray_char_T_1x200 emxArray_char_T_1x200;
#endif /* typedef_emxArray_char_T_1x200 */

#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1 {
  real_T data[1];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_1x1 */
#ifndef typedef_emxArray_real_T_1x1
#define typedef_emxArray_real_T_1x1
typedef struct emxArray_real_T_1x1 emxArray_real_T_1x1;
#endif /* typedef_emxArray_real_T_1x1 */

#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct {
  emxArray_char_T_1x200 JointName;
  emxArray_real_T_1x1 JointPosition;
} struct_T;
#endif /* typedef_struct_T */

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T
typedef struct {
  struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef struct_emxArray_real_T_1x7
#define struct_emxArray_real_T_1x7
struct emxArray_real_T_1x7 {
  real_T data[7];
  int32_T size[2];
};
#endif /* struct_emxArray_real_T_1x7 */
#ifndef typedef_emxArray_real_T_1x7
#define typedef_emxArray_real_T_1x7
typedef struct emxArray_real_T_1x7 emxArray_real_T_1x7;
#endif /* typedef_emxArray_real_T_1x7 */

#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct {
  emxArray_char_T_1x200 JointName;
  emxArray_real_T_1x7 JointPosition;
} c_struct_T;
#endif /* typedef_c_struct_T */

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T
typedef struct {
  c_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;
#endif /* typedef_b_emxArray_struct_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef struct_emxArray_ptrdiff_t
#define struct_emxArray_ptrdiff_t
struct emxArray_ptrdiff_t {
  ptrdiff_t *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_ptrdiff_t */
#ifndef typedef_emxArray_ptrdiff_t
#define typedef_emxArray_ptrdiff_t
typedef struct emxArray_ptrdiff_t emxArray_ptrdiff_t;
#endif /* typedef_emxArray_ptrdiff_t */

#ifndef c_typedef_d_robotics_manip_inte
#define c_typedef_d_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  c_emxArray_robotics_manip_inter *CollisionGeometries;
  real_T MaxElements;
  real_T Size;
} d_robotics_manip_internal_Colli;
#endif /* c_typedef_d_robotics_manip_inte */

#ifndef e_typedef_c_robotics_manip_inte
#define e_typedef_c_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  c_robotics_manip_internal_Chara NameInternal;
  real_T Index;
  rigidBodyJoint *JointInternal;
  real_T ParentIndex;
  real_T MassInternal;
  real_T CenterOfMassInternal[3];
  real_T InertiaInternal[9];
  real_T SpatialInertia[36];
  d_robotics_manip_internal_Colli *CollisionsInternal;
} c_robotics_manip_internal_Rigid;
#endif /* e_typedef_c_robotics_manip_inte */

#ifndef d_typedef_d_robotics_manip_inte
#define d_typedef_d_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  real_T NumBodies;
  c_robotics_manip_internal_Rigid Base;
  real_T Gravity[3];
  c_robotics_manip_internal_Rigid *Bodies[6];
  real_T NumNonFixedBodies;
  real_T PositionNumber;
  real_T VelocityNumber;
  d_robotics_manip_internal_Colli _pobj0[13];
  rigidBodyJoint _pobj1[13];
  c_robotics_manip_internal_Rigid _pobj2[12];
} d_robotics_manip_internal_Rigid;
#endif /* d_typedef_d_robotics_manip_inte */

#ifndef c_typedef_e_robotics_manip_inte
#define c_typedef_e_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  real_T NumBodies;
  c_robotics_manip_internal_Rigid Base;
  c_robotics_manip_internal_Rigid *Bodies[6];
  real_T NumNonFixedBodies;
  real_T PositionNumber;
  real_T VelocityNumber;
  real_T PositionDoFMap[12];
  real_T VelocityDoFMap[12];
  c_robotics_manip_internal_Rigid _pobj0[6];
  d_robotics_manip_internal_Colli _pobj1[7];
  rigidBodyJoint _pobj2[7];
} e_robotics_manip_internal_Rigid;
#endif /* c_typedef_e_robotics_manip_inte */

#ifndef f_typedef_c_robotics_manip_inte
#define f_typedef_c_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  e_robotics_manip_internal_Rigid *Robot;
  real_T WeightMatrix[36];
  real_T Tform[16];
  emxArray_real_T *ErrTemp;
  real_T CostTemp;
  emxArray_real_T *GradTemp;
  real_T BodyIndex;
  real_T KinematicModel;
} c_robotics_manip_internal_IKExt;
#endif /* f_typedef_c_robotics_manip_inte */

#ifndef e_typedef_c_robotics_core_inter
#define e_typedef_c_robotics_core_inter
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  emxArray_real_T *ConstraintMatrix;
  emxArray_real_T *ConstraintBound;
  boolean_T ConstraintsOn;
  real_T SolutionTolerance;
  boolean_T RandomRestart;
  c_robotics_manip_internal_IKExt *ExtraArgs;
  real_T MaxNumIteration;
  real_T MaxTime;
  emxArray_real_T *SeedInternal;
  real_T MaxTimeInternal;
  real_T MaxNumIterationInternal;
  real_T StepTolerance;
  c_robotics_core_internal_System TimeObj;
  real_T GradientTolerance;
  real_T ArmijoRuleBeta;
  real_T ArmijoRuleSigma;
  c_robotics_core_internal_System TimeObjInternal;
} c_robotics_core_internal_Damped;
#endif /* e_typedef_c_robotics_core_inter */

#ifndef typedef_rigidBodyTree
#define typedef_rigidBodyTree
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  e_robotics_manip_internal_Rigid *TreeInternal;
  d_robotics_manip_internal_Colli _pobj0;
  e_robotics_manip_internal_Rigid _pobj1;
} rigidBodyTree;
#endif /* typedef_rigidBodyTree */

#ifndef typedef_inverseKinematics
#define typedef_inverseKinematics
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T RigidBodyTreeKinematicModel;
  c_robotics_core_internal_Damped *Solver;
  emxArray_real_T *Limits;
  e_robotics_manip_internal_Rigid *RigidBodyTreeInternal;
  c_robotics_manip_internal_IKExt _pobj0;
  rigidBodyJoint _pobj1[12];
  c_robotics_manip_internal_Rigid _pobj2[6];
  d_robotics_manip_internal_Colli _pobj3[13];
  e_robotics_manip_internal_Rigid _pobj4;
  rigidBodyTree _pobj5;
  c_robotics_core_internal_Damped _pobj6;
} inverseKinematics;
#endif /* typedef_inverseKinematics */

#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct {
  real_T JointPosition;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T
typedef struct {
  d_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;
#endif /* typedef_c_emxArray_struct_T */

/* End of code generation (armvone_types.h) */
