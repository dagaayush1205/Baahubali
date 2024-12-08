/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void binary_expand_op_11(emxArray_int32_T *in1, const emxArray_real_T *in2,
                         const c_robotics_core_internal_Damped *in3);

void eml_find(const emxArray_boolean_T *x, emxArray_int32_T *i);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (find.h) */
