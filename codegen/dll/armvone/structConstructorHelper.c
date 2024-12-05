/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: structConstructorHelper.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "structConstructorHelper.h"
#include "armvone_internal_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const char varargin_2_f1[14]
 *                const char varargin_2_f2[6]
 *                const char varargin_2_f3[6]
 *                const char varargin_2_f4[10]
 *                const char varargin_2_f5[8]
 *                const char varargin_2_f6[10]
 *                const double varargin_4[6]
 *                struct_T s[6]
 * Return Type  : void
 */
void structConstructorHelper(const char varargin_2_f1[14],
                             const char varargin_2_f2[6],
                             const char varargin_2_f3[6],
                             const char varargin_2_f4[10],
                             const char varargin_2_f5[8],
                             const char varargin_2_f6[10],
                             const double varargin_4[6], struct_T s[6])
{
  int j;
  s[0].JointName.size[0] = 1;
  s[0].JointName.size[1] = 14;
  for (j = 0; j < 14; j++) {
    s[0].JointName.data[j] = varargin_2_f1[j];
  }
  s[1].JointName.size[0] = 1;
  s[1].JointName.size[1] = 6;
  s[2].JointName.size[0] = 1;
  s[2].JointName.size[1] = 6;
  for (j = 0; j < 6; j++) {
    s[1].JointName.data[j] = varargin_2_f2[j];
    s[2].JointName.data[j] = varargin_2_f3[j];
  }
  s[3].JointName.size[0] = 1;
  s[3].JointName.size[1] = 10;
  for (j = 0; j < 10; j++) {
    s[3].JointName.data[j] = varargin_2_f4[j];
  }
  s[4].JointName.size[0] = 1;
  s[4].JointName.size[1] = 8;
  for (j = 0; j < 8; j++) {
    s[4].JointName.data[j] = varargin_2_f5[j];
  }
  s[5].JointName.size[0] = 1;
  s[5].JointName.size[1] = 10;
  for (j = 0; j < 10; j++) {
    s[5].JointName.data[j] = varargin_2_f6[j];
  }
  for (j = 0; j < 6; j++) {
    s[j].JointPosition = varargin_4[j];
  }
}

/*
 * File trailer for structConstructorHelper.c
 *
 * [EOF]
 */
