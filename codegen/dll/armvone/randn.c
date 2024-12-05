/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: randn.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "randn.h"
#include "armvone_data.h"
#include "eml_rand_mt19937ar.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : double r[3]
 * Return Type  : void
 */
void b_randn(double r[3])
{
  r[0] = b_eml_rand_mt19937ar(state);
  r[1] = b_eml_rand_mt19937ar(state);
  r[2] = b_eml_rand_mt19937ar(state);
}

/*
 * Arguments    : const double varargin_1[2]
 *                double r_data[]
 * Return Type  : int
 */
int c_randn(const double varargin_1[2], double r_data[])
{
  int i;
  int k;
  int r_size;
  i = (int)varargin_1[0];
  r_size = (int)varargin_1[0];
  for (k = 0; k < i; k++) {
    r_data[k] = b_eml_rand_mt19937ar(state);
  }
  return r_size;
}

/*
 * Arguments    : double r[4]
 * Return Type  : void
 */
void randn(double r[4])
{
  r[0] = b_eml_rand_mt19937ar(state);
  r[1] = b_eml_rand_mt19937ar(state);
  r[2] = b_eml_rand_mt19937ar(state);
  r[3] = b_eml_rand_mt19937ar(state);
}

/*
 * File trailer for randn.c
 *
 * [EOF]
 */
