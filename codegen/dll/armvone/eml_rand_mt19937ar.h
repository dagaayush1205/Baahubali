/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: eml_rand_mt19937ar.h
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

#ifndef EML_RAND_MT19937AR_H
#define EML_RAND_MT19937AR_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
double b_eml_rand_mt19937ar(unsigned int b_state[625]);

void eml_rand_mt19937ar(unsigned int b_state[625]);

void genrand_uint32_vector(unsigned int mt[625], unsigned int u[2]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for eml_rand_mt19937ar.h
 *
 * [EOF]
 */
