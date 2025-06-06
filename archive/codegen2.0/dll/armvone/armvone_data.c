/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_data.c
 *
 * Code generation for function 'armvone_data'
 *
 */

/* Include files */
#include "armvone_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
unsigned int state[625];

double freq;

boolean_T freq_not_empty;

const char cv[15] = {'t', 'u', 'r', 'n', 't', 'a', 'b', 'l',
                     'e', '_', 'j', 'o', 'i', 'n', 't'};

const char cv1[12] = {'l', 'i', 'n', 'k', 'O', 'n',
                      'e', 'J', 'o', 'i', 'n', 't'};

const char cv2[12] = {'l', 'i', 'n', 'k', 'T', 'w',
                      'o', 'J', 'o', 'i', 'n', 't'};

const char cv3[10] = {'p', 'i', 't', 'c', 'h', 'J', 'o', 'i', 'n', 't'};

const char cv4[9] = {'r', 'o', 'l', 'l', 'J', 'o', 'i', 'n', 't'};

const signed char iv[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

const char cv5[9] = {'p', 'r', 'i', 's', 'm', 'a', 't', 'i', 'c'};

const char cv6[10] = {'d', 'u', 'm', 'm', 'y', 'b', 'o', 'd', 'y', '1'};

const char cv7[10] = {'d', 'u', 'm', 'm', 'y', 'b', 'o', 'd', 'y', '2'};

const char cv8[10] = {'d', 'u', 'm', 'm', 'y', 'b', 'o', 'd', 'y', '3'};

const char cv9[10] = {'d', 'u', 'm', 'm', 'y', 'b', 'o', 'd', 'y', '4'};

const char cv10[10] = {'d', 'u', 'm', 'm', 'y', 'b', 'o', 'd', 'y', '5'};

boolean_T isInitialized_armvone = false;

/* End of code generation (armvone_data.c) */
