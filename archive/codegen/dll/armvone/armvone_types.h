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

#ifndef ARMVONE_TYPES_H
#define ARMVONE_TYPES_H

/* Include files */
#include "rtwtypes.h"
#include "coder_posix_time.h"

/* Type Definitions */
#ifndef d_typedef_c_robotics_core_inter
#define d_typedef_c_robotics_core_inter
typedef struct {
  coderTimespec StartTime;
} c_robotics_core_internal_System;
#endif /* d_typedef_c_robotics_core_inter */

#ifndef c_typedef_c_robotics_manip_inte
#define c_typedef_c_robotics_manip_inte
typedef struct {
  double Length;
  char Vector[200];
} c_robotics_manip_internal_Chara;
#endif /* c_typedef_c_robotics_manip_inte */

#ifndef typedef_rigidBodyJoint
#define typedef_rigidBodyJoint
typedef struct {
  double VelocityNumber;
  double PositionNumber;
  boolean_T InTree;
  double JointToParentTransform[16];
  double ChildToJointTransform[16];
  c_robotics_manip_internal_Chara NameInternal;
  double PositionLimitsInternal[14];
  double HomePositionInternal[7];
  double JointAxisInternal[3];
  double MotionSubspaceInternal[36];
  c_robotics_manip_internal_Chara TypeInternal;
} rigidBodyJoint;
#endif /* typedef_rigidBodyJoint */

#ifndef d_typedef_c_robotics_manip_inte
#define d_typedef_c_robotics_manip_inte
typedef struct {
  void *CollisionPrimitive;
  double LocalPose[16];
  double WorldPose[16];
  double MeshScale[3];
} c_robotics_manip_internal_Colli;
#endif /* d_typedef_c_robotics_manip_inte */

#ifndef c_typedef_c_emxArray_robotics_m
#define c_typedef_c_emxArray_robotics_m
typedef struct {
  c_robotics_manip_internal_Colli *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_robotics_manip_inter;
#endif /* c_typedef_c_emxArray_robotics_m */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  char data[200];
  int size[2];
};
#endif /* struct_emxArray_char_T_1x200 */
#ifndef typedef_emxArray_char_T_1x200
#define typedef_emxArray_char_T_1x200
typedef struct emxArray_char_T_1x200 emxArray_char_T_1x200;
#endif /* typedef_emxArray_char_T_1x200 */

#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1 {
  double data[1];
  int size[2];
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
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_struct_T;
#endif /* typedef_emxArray_struct_T */

#ifndef struct_emxArray_int8_T
#define struct_emxArray_int8_T
struct emxArray_int8_T {
  signed char *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int8_T */
#ifndef typedef_emxArray_int8_T
#define typedef_emxArray_int8_T
typedef struct emxArray_int8_T emxArray_int8_T;
#endif /* typedef_emxArray_int8_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
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
  double data[7];
  int size[2];
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
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} b_emxArray_struct_T;
#endif /* typedef_b_emxArray_struct_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef c_typedef_d_robotics_manip_inte
#define c_typedef_d_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  c_emxArray_robotics_manip_inter *CollisionGeometries;
  double MaxElements;
  double Size;
} d_robotics_manip_internal_Colli;
#endif /* c_typedef_d_robotics_manip_inte */

#ifndef e_typedef_c_robotics_manip_inte
#define e_typedef_c_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  c_robotics_manip_internal_Chara NameInternal;
  double Index;
  rigidBodyJoint *JointInternal;
  double ParentIndex;
  double MassInternal;
  double CenterOfMassInternal[3];
  double InertiaInternal[9];
  double SpatialInertia[36];
  d_robotics_manip_internal_Colli *CollisionsInternal;
} c_robotics_manip_internal_Rigid;
#endif /* e_typedef_c_robotics_manip_inte */

#ifndef d_typedef_d_robotics_manip_inte
#define d_typedef_d_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  double NumBodies;
  c_robotics_manip_internal_Rigid Base;
  double Gravity[3];
  c_robotics_manip_internal_Rigid *Bodies[6];
  double NumNonFixedBodies;
  double PositionNumber;
  double VelocityNumber;
  d_robotics_manip_internal_Colli _pobj0[13];
  rigidBodyJoint _pobj1[13];
  c_robotics_manip_internal_Rigid _pobj2[12];
} d_robotics_manip_internal_Rigid;
#endif /* d_typedef_d_robotics_manip_inte */

#ifndef c_typedef_e_robotics_manip_inte
#define c_typedef_e_robotics_manip_inte
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  double NumBodies;
  c_robotics_manip_internal_Rigid Base;
  c_robotics_manip_internal_Rigid *Bodies[6];
  double NumNonFixedBodies;
  double PositionNumber;
  double VelocityNumber;
  double PositionDoFMap[12];
  double VelocityDoFMap[12];
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
  double WeightMatrix[36];
  double Tform[16];
  emxArray_real_T *ErrTemp;
  double CostTemp;
  emxArray_real_T *GradTemp;
  double BodyIndex;
  double KinematicModel;
} c_robotics_manip_internal_IKExt;
#endif /* f_typedef_c_robotics_manip_inte */

#ifndef e_typedef_c_robotics_core_inter
#define e_typedef_c_robotics_core_inter
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  emxArray_real_T *ConstraintMatrix;
  emxArray_real_T *ConstraintBound;
  boolean_T ConstraintsOn;
  double SolutionTolerance;
  boolean_T RandomRestart;
  c_robotics_manip_internal_IKExt *ExtraArgs;
  double MaxNumIteration;
  double MaxTime;
  emxArray_real_T *SeedInternal;
  double MaxTimeInternal;
  double MaxNumIterationInternal;
  double StepTolerance;
  c_robotics_core_internal_System TimeObj;
  double GradientTolerance;
  double ArmijoRuleBeta;
  double ArmijoRuleSigma;
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
  int isInitialized;
  boolean_T isSetupComplete;
  double RigidBodyTreeKinematicModel;
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
  double JointPosition;
} d_struct_T;
#endif /* typedef_d_struct_T */

#ifndef typedef_c_emxArray_struct_T
#define typedef_c_emxArray_struct_T
typedef struct {
  d_struct_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} c_emxArray_struct_T;
#endif /* typedef_c_emxArray_struct_T */

#endif
/* End of code generation (armvone_types.h) */
