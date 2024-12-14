/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * structConstructorHelper.c
 *
 * Code generation for function 'structConstructorHelper'
 *
 */

/* Include files */
#include "structConstructorHelper.h"
#include "armvone_internal_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void structConstructorHelper(const char varargin_2_f1[15],
                             const char varargin_2_f2[12],
                             const char varargin_2_f3[12],
                             const char varargin_2_f4[10],
                             const char varargin_2_f5[9],
                             const double varargin_4[5], b_struct_T s[5])
{
  int j;
  s[0].JointName.size[0] = 1;
  s[0].JointName.size[1] = 15;
  for (j = 0; j < 15; j++) {
    s[0].JointName.data[j] = varargin_2_f1[j];
  }
  s[1].JointName.size[0] = 1;
  s[1].JointName.size[1] = 12;
  s[2].JointName.size[0] = 1;
  s[2].JointName.size[1] = 12;
  for (j = 0; j < 12; j++) {
    s[1].JointName.data[j] = varargin_2_f2[j];
    s[2].JointName.data[j] = varargin_2_f3[j];
  }
  s[3].JointName.size[0] = 1;
  s[3].JointName.size[1] = 10;
  for (j = 0; j < 10; j++) {
    s[3].JointName.data[j] = varargin_2_f4[j];
  }
  s[4].JointName.size[0] = 1;
  s[4].JointName.size[1] = 9;
  for (j = 0; j < 9; j++) {
    s[4].JointName.data[j] = varargin_2_f5[j];
  }
  for (j = 0; j < 5; j++) {
    s[j].JointPosition = varargin_4[j];
  }
}

/* End of code generation (structConstructorHelper.c) */
