/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * strcmp.c
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "strcmp.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T b_strcmp(const char_T a_data[], const int32_T a_size[2],
                   const char_T b_data[], const int32_T b_size[2])
{
  boolean_T b;
  boolean_T b_bool;
  b_bool = false;
  b = (a_size[1] == 0);
  if (b && (b_size[1] == 0)) {
    b_bool = true;
  } else if (a_size[1] == b_size[1]) {
    int32_T kstr;
    kstr = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (kstr <= b_size[1] - 1) {
        if (a_data[kstr] != b_data[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T c_strcmp(const emlrtStack *sp, const char_T a_data[],
                   const int32_T a_size[2], real_T cmpLen)
{
  static const char_T b_cv[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T i;
  int32_T minnanb;
  boolean_T b_bool;
  boolean_T guard1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = muDoubleScalarFloor(cmpLen);
  st.site = &ld_emlrtRSI;
  b_st.site = &md_emlrtRSI;
  b_bool = false;
  minnanb = muIntScalarMin_sint32(a_size[1], 8);
  guard1 = false;
  if ((int32_T)y <= minnanb) {
    i = (int32_T)y;
    minnanb = muIntScalarMin_sint32(minnanb, i);
    guard1 = true;
  } else if (a_size[1] == 8) {
    minnanb = 8;
    guard1 = true;
  }
  if (guard1) {
    i = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (i <= (uint8_T)minnanb - 1) {
        uint8_T u;
        c_st.site = &cf_emlrtRSI;
        u = (uint8_T)a_data[i];
        if (u > 127) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &l_emlrtRTEI, "Coder:toolbox:unsupportedString",
              "Coder:toolbox:unsupportedString", 2, 12, 127);
        }
        if (cv10[u] != cv10[(int32_T)b_cv[i]]) {
          exitg1 = 1;
        } else {
          i++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/* End of code generation (strcmp.c) */
