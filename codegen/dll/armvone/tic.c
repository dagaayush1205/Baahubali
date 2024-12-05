/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: tic.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "tic.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "coder_posix_time.h"

/* Function Definitions */
/*
 * Arguments    : double *tstart_tv_nsec
 * Return Type  : double
 */
double tic(double *tstart_tv_nsec)
{
  coderTimespec b_timespec;
  double tstart_tv_sec;
  if (!freq_not_empty) {
    freq_not_empty = true;
    coderInitTimeFunctions(&freq);
  }
  coderTimeClockGettimeMonotonic(&b_timespec, freq);
  tstart_tv_sec = b_timespec.tv_sec;
  *tstart_tv_nsec = b_timespec.tv_nsec;
  return tstart_tv_sec;
}

/*
 * File trailer for tic.c
 *
 * [EOF]
 */
