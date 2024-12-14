/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_emxutil.c
 *
 * Code generation for function 'armvone_emxutil'
 *
 */

/* Include files */
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <string.h>

/* Function Definitions */
void c_emxEnsureCapacity_robotics_ma(c_emxArray_robotics_manip_inter *emxArray,
                                     int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(c_robotics_manip_internal_Colli));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_robotics_manip_internal_Colli) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_robotics_manip_internal_Colli *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void c_emxFreeMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[17])
{
  int i;
  for (i = 0; i < 17; i++) {
    c_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

void c_emxFreeStruct_robotics_core_i(c_robotics_core_internal_Damped *pStruct)
{
  emxFree_real_T(&pStruct->ConstraintMatrix);
  emxFree_real_T(&pStruct->ConstraintBound);
  emxFree_real_T(&pStruct->SeedInternal);
}

void c_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct)
{
  c_emxFree_robotics_manip_intern(&pStruct->CollisionGeometries);
}

void c_emxFree_robotics_manip_intern(
    c_emxArray_robotics_manip_inter **pEmxArray)
{
  if (*pEmxArray != (c_emxArray_robotics_manip_inter *)NULL) {
    if (((*pEmxArray)->data != (c_robotics_manip_internal_Colli *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_robotics_manip_inter *)NULL;
  }
}

void c_emxInitMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[17])
{
  int i;
  for (i = 0; i < 17; i++) {
    d_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

void c_emxInitStruct_robotics_core_i(c_robotics_core_internal_Damped *pStruct)
{
  emxInit_real_T(&pStruct->ConstraintMatrix, 2);
  emxInit_real_T(&pStruct->ConstraintBound, 1);
  emxInit_real_T(&pStruct->SeedInternal, 1);
}

void c_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct)
{
  c_emxInitMatrix_robotics_manip_(pStruct->_pobj0);
}

void c_emxInit_robotics_manip_intern(
    c_emxArray_robotics_manip_inter **pEmxArray)
{
  c_emxArray_robotics_manip_inter *emxArray;
  int i;
  *pEmxArray = (c_emxArray_robotics_manip_inter *)malloc(
      sizeof(c_emxArray_robotics_manip_inter));
  emxArray = *pEmxArray;
  emxArray->data = (c_robotics_manip_internal_Colli *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void d_emxFreeMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[11])
{
  int i;
  for (i = 0; i < 11; i++) {
    c_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

void d_emxFreeStruct_robotics_manip_(d_robotics_manip_internal_Rigid *pStruct)
{
  c_emxFreeMatrix_robotics_manip_(pStruct->_pobj0);
}

void d_emxInitMatrix_robotics_manip_(
    d_robotics_manip_internal_Colli pMatrix[11])
{
  int i;
  for (i = 0; i < 11; i++) {
    d_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

void d_emxInitStruct_robotics_manip_(d_robotics_manip_internal_Colli *pStruct)
{
  c_emxInit_robotics_manip_intern(&pStruct->CollisionGeometries);
}

void e_emxFreeMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[6])
{
  int i;
  for (i = 0; i < 6; i++) {
    c_emxFreeStruct_robotics_manip_(&pMatrix[i]);
  }
}

void e_emxFreeStruct_robotics_manip_(c_robotics_manip_internal_IKExt *pStruct)
{
  emxFree_real_T(&pStruct->ErrTemp);
  emxFree_real_T(&pStruct->GradTemp);
}

void e_emxInitMatrix_robotics_manip_(d_robotics_manip_internal_Colli pMatrix[6])
{
  int i;
  for (i = 0; i < 6; i++) {
    d_emxInitStruct_robotics_manip_(&pMatrix[i]);
  }
}

void e_emxInitStruct_robotics_manip_(c_robotics_manip_internal_IKExt *pStruct)
{
  emxInit_real_T(&pStruct->ErrTemp, 1);
  emxInit_real_T(&pStruct->GradTemp, 1);
}

void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(boolean_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(int));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (int *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int8_T(emxArray_int8_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(signed char));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(signed char) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (signed char *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(double));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(double) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (double *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_struct_T(c_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(d_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(d_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (d_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_struct_T1(b_emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(c_struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(c_struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (c_struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxExpand_struct_T(emxArray, oldNumel, newNumel);
  }
}

void emxEnsureCapacity_struct_T2(emxArray_struct_T *emxArray, int oldNumel)
{
  int i;
  int newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = malloc((unsigned int)i * sizeof(struct_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data,
             sizeof(struct_T) * (unsigned int)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }
    emxArray->data = (struct_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxExpand_struct_T1(emxArray, oldNumel, newNumel);
  }
}

void emxExpand_struct_T(b_emxArray_struct_T *emxArray, int fromIndex,
                        int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T(&emxArray->data[i]);
  }
}

void emxExpand_struct_T1(emxArray_struct_T *emxArray, int fromIndex,
                         int toIndex)
{
  int i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct_T1(&emxArray->data[i]);
  }
}

void emxFreeStruct_inverseKinematics(inverseKinematics *pStruct)
{
  emxFree_real_T(&pStruct->Limits);
  e_emxFreeStruct_robotics_manip_(&pStruct->_pobj0);
  d_emxFreeMatrix_robotics_manip_(pStruct->_pobj3);
  f_emxFreeStruct_robotics_manip_(&pStruct->_pobj4);
  emxFreeStruct_rigidBodyTree(&pStruct->_pobj5);
  c_emxFreeStruct_robotics_core_i(&pStruct->_pobj6);
}

void emxFreeStruct_rigidBodyTree(rigidBodyTree *pStruct)
{
  c_emxFreeStruct_robotics_manip_(&pStruct->_pobj0);
  f_emxFreeStruct_robotics_manip_(&pStruct->_pobj1);
}

void emxFree_boolean_T(emxArray_boolean_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T *)NULL;
  }
}

void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_int8_T(emxArray_int8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int8_T *)NULL) {
    if (((*pEmxArray)->data != (signed char *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int8_T *)NULL;
  }
}

void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (double *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxFree_struct_T(emxArray_struct_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_struct_T *)NULL) {
    if (((*pEmxArray)->data != (struct_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_struct_T *)NULL;
  }
}

void emxFree_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  if (*pEmxArray != (b_emxArray_struct_T *)NULL) {
    if (((*pEmxArray)->data != (c_struct_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (b_emxArray_struct_T *)NULL;
  }
}

void emxFree_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  if (*pEmxArray != (c_emxArray_struct_T *)NULL) {
    if (((*pEmxArray)->data != (d_struct_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }
    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (c_emxArray_struct_T *)NULL;
  }
}

void emxInitStruct_inverseKinematics(inverseKinematics *pStruct)
{
  emxInit_real_T(&pStruct->Limits, 2);
  e_emxInitStruct_robotics_manip_(&pStruct->_pobj0);
  d_emxInitMatrix_robotics_manip_(pStruct->_pobj3);
  f_emxInitStruct_robotics_manip_(&pStruct->_pobj4);
  emxInitStruct_rigidBodyTree(&pStruct->_pobj5);
  c_emxInitStruct_robotics_core_i(&pStruct->_pobj6);
}

void emxInitStruct_rigidBodyTree(rigidBodyTree *pStruct)
{
  d_emxInitStruct_robotics_manip_(&pStruct->_pobj0);
  f_emxInitStruct_robotics_manip_(&pStruct->_pobj1);
}

void emxInitStruct_struct_T(c_struct_T *pStruct)
{
  pStruct->JointName.size[0] = 0;
  pStruct->JointName.size[1] = 0;
  pStruct->JointPosition.size[0] = 0;
  pStruct->JointPosition.size[1] = 0;
}

void emxInitStruct_struct_T1(struct_T *pStruct)
{
  pStruct->JointName.size[0] = 0;
  pStruct->JointName.size[1] = 0;
  pStruct->JointPosition.size[0] = 0;
  pStruct->JointPosition.size[1] = 0;
}

void emxInit_boolean_T(emxArray_boolean_T **pEmxArray)
{
  emxArray_boolean_T *emxArray;
  *pEmxArray = (emxArray_boolean_T *)malloc(sizeof(emxArray_boolean_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int *)malloc(sizeof(int));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions)
{
  emxArray_int32_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int32_T *)malloc(sizeof(emxArray_int32_T));
  emxArray = *pEmxArray;
  emxArray->data = (int *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int8_T(emxArray_int8_T **pEmxArray)
{
  emxArray_int8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_int8_T *)malloc(sizeof(emxArray_int8_T));
  emxArray = *pEmxArray;
  emxArray->data = (signed char *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  emxArray_real_T *emxArray;
  int i;
  *pEmxArray = (emxArray_real_T *)malloc(sizeof(emxArray_real_T));
  emxArray = *pEmxArray;
  emxArray->data = (double *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * (unsigned int)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_struct_T(emxArray_struct_T **pEmxArray)
{
  emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (emxArray_struct_T *)malloc(sizeof(emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_struct_T1(b_emxArray_struct_T **pEmxArray)
{
  b_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (b_emxArray_struct_T *)malloc(sizeof(b_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_struct_T2(c_emxArray_struct_T **pEmxArray)
{
  c_emxArray_struct_T *emxArray;
  int i;
  *pEmxArray = (c_emxArray_struct_T *)malloc(sizeof(c_emxArray_struct_T));
  emxArray = *pEmxArray;
  emxArray->data = (d_struct_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int *)malloc(sizeof(int) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void f_emxFreeStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct)
{
  e_emxFreeMatrix_robotics_manip_(pStruct->_pobj1);
}

void f_emxInitStruct_robotics_manip_(e_robotics_manip_internal_Rigid *pStruct)
{
  e_emxInitMatrix_robotics_manip_(pStruct->_pobj1);
}

/* End of code generation (armvone_emxutil.c) */
