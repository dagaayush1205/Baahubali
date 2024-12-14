/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * armvone_initialize.c
 *
 * Code generation for function 'armvone_initialize'
 *
 */

/* Include files */
#include "armvone_initialize.h"
#include "CoderTimeAPI.h"
#include "armvone_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void armvone_initialize(void)
{
  c_eml_rand_mt19937ar_stateful_i();
  c_CoderTimeAPI_callCoderClockGe();
  isInitialized_armvone = true;
}

/* End of code generation (armvone_initialize.c) */
