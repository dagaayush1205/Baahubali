/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: armvone_initialize.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "armvone_initialize.h"
#include "CoderTimeAPI.h"
#include "armvone_data.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void armvone_initialize(void)
{
  c_eml_rand_mt19937ar_stateful_i();
  c_CoderTimeAPI_callCoderClockGe();
  isInitialized_armvone = true;
}

/*
 * File trailer for armvone_initialize.c
 *
 * [EOF]
 */
