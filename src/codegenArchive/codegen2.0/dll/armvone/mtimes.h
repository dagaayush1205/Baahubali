/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
 *
 */

#ifndef MTIMES_H
#define MTIMES_H

/* Include files */
#include "armvone_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C);

void c_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C);

void d_mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
              emxArray_real_T *C);

void mtimes(const emxArray_real_T *A, const emxArray_real_T *B,
            emxArray_real_T *C);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (mtimes.h) */
