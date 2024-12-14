/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_emxutil.h
 *
 * Code generation for function 'armvone_emxutil'
 *
 */

#ifndef ARMVONE_EMXUTIL_H
#define ARMVONE_EMXUTIL_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
c_emxEnsureCapacity_robotics_ma(c_emxArray_robotics_manip_inter *emxArray,
                                int oldNumel);

extern void
c_emxFreeMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[13]);

extern void
c_emxFreeStruct_robotics_core_i(c_robotics_core_internal_Damped *pStruct);

extern void
c_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct);

extern void
c_emxFree_robotics_manip_intern(c_emxArray_robotics_manip_inter **pEmxArray);

extern void
c_emxInitMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[13]);

extern void
c_emxInitStruct_robotics_core_i(c_robotics_core_internal_Damped *pStruct);

extern void
c_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct);

extern void
c_emxInit_robotics_manip_intern(c_emxArray_robotics_manip_inter **pEmxArray);

extern void
d_emxFreeMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[7]);

extern void
d_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct);

extern void
d_emxInitMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[7]);

extern void
d_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct);

extern void
e_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_IKExt *pStruct);

extern void
e_emxInitStruct_robotics_manip_(c_robotics_manip_internal_IKExt *pStruct);

extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_struct_T(c_emxArray_struct_T *emxArray,
                                       int oldNumel);

extern void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_struct_T2(emxArray_struct_T *emxArray,
                                        int oldNumel);

extern void emxExpand_struct_T(b_emxArray_struct_T *emxArray, int fromIndex,
                               int toIndex);

extern void emxExpand_struct_T1(emxArray_struct_T *emxArray, int fromIndex,
                                int toIndex);

extern void emxFreeStruct_inverseKinematics(inverseKinematics *pStruct);

extern void emxFreeStruct_rigidBodyTree(rigidBodyTree *pStruct);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_int8_T(emxArray_int8_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_struct_T(emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray);

extern void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray);

extern void emxInitStruct_inverseKinematics(inverseKinematics *pStruct);

extern void emxInitStruct_rigidBodyTree(rigidBodyTree *pStruct);

extern void emxInitStruct_struct_T(c_struct_T *pStruct);

extern void emxInitStruct_struct_T1(struct_T *pStruct);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);

extern void emxInit_int8_T(emxArray_int8_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_struct_T(emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray);

extern void emxInit_struct_T2(c_emxArray_struct_T **pEmxArray);

extern void
f_emxFreeStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct);

extern void
f_emxInitStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (armvone_emxutil.h) */
