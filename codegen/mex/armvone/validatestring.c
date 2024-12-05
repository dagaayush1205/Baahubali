/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * validatestring.c
 *
 * Code generation for function 'validatestring'
 *
 */

/* Include files */
#include "validatestring.h"
#include "armvone_data.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo bf_emlrtRSI = {
    164,         /* lineNo */
    "get_match", /* fcnName */
    "/home/pritesh0/matlab24/toolbox/eml/lib/matlab/lang/validatestring.m" /* pathName
                                                                            */
};

/* Function Definitions */
int32_T get_match(const emlrtStack *sp, const char_T str_data[],
                  const int32_T str_size[2], char_T match_data[],
                  int32_T match_size[2])
{
  static const char_T b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T b_vstr[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char_T vstr[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const char_T b_cv1[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char_T c_vstr[5] = {'f', 'i', 'x', 'e', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T exitg1;
  int32_T i;
  int32_T kstr;
  int32_T nmatched;
  uint8_T u;
  boolean_T b_bool;
  boolean_T guard1;
  boolean_T guard2;
  boolean_T guard3;
  boolean_T guard4;
  boolean_T matched;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  match_size[0] = 1;
  match_size[1] = 8;
  for (i = 0; i < 8; i++) {
    match_data[i] = ' ';
  }
  nmatched = 0;
  matched = false;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  if (str_size[1] <= 8) {
    st.site = &bf_emlrtRSI;
    b_st.site = &ld_emlrtRSI;
    c_st.site = &md_emlrtRSI;
    b_bool = false;
    i = muIntScalarMin_sint32(str_size[1], str_size[1]);
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr <= i - 1) {
        d_st.site = &cf_emlrtRSI;
        u = (uint8_T)str_data[kstr];
        if (u > 127) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &l_emlrtRTEI, "Coder:toolbox:unsupportedString",
              "Coder:toolbox:unsupportedString", 2, 12, 127);
        }
        if (cv10[u] != cv10[(int32_T)b_cv[kstr]]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
    if (b_bool) {
      if (str_size[1] == 8) {
        nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 8;
        for (i = 0; i < 8; i++) {
          match_data[i] = b_vstr[i];
        }
      } else {
        match_size[0] = 1;
        match_size[1] = 8;
        for (i = 0; i < 8; i++) {
          match_data[i] = b_vstr[i];
        }
        matched = true;
        nmatched = 1;
        guard4 = true;
      }
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }
  if (guard4) {
    if (str_size[1] <= 9) {
      st.site = &bf_emlrtRSI;
      b_st.site = &ld_emlrtRSI;
      c_st.site = &md_emlrtRSI;
      b_bool = false;
      i = muIntScalarMin_sint32(str_size[1], str_size[1]);
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr <= i - 1) {
          d_st.site = &cf_emlrtRSI;
          u = (uint8_T)str_data[kstr];
          if (u > 127) {
            emlrtErrorWithMessageIdR2018a(
                &d_st, &l_emlrtRTEI, "Coder:toolbox:unsupportedString",
                "Coder:toolbox:unsupportedString", 2, 12, 127);
          }
          if (cv10[u] != cv10[(int32_T)cv3[kstr]]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool) {
        if (str_size[1] == 9) {
          nmatched = 1;
          match_size[0] = 1;
          match_size[1] = 9;
          for (i = 0; i < 9; i++) {
            match_data[i] = cv3[i];
          }
        } else {
          if (!matched) {
            match_size[0] = 1;
            match_size[1] = 9;
            for (i = 0; i < 9; i++) {
              match_data[i] = cv3[i];
            }
          }
          matched = true;
          nmatched++;
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }
  }
  if (guard3) {
    if (str_size[1] <= 5) {
      st.site = &bf_emlrtRSI;
      b_st.site = &ld_emlrtRSI;
      c_st.site = &md_emlrtRSI;
      b_bool = false;
      i = muIntScalarMin_sint32(str_size[1], str_size[1]);
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr <= i - 1) {
          d_st.site = &cf_emlrtRSI;
          u = (uint8_T)str_data[kstr];
          if (u > 127) {
            emlrtErrorWithMessageIdR2018a(
                &d_st, &l_emlrtRTEI, "Coder:toolbox:unsupportedString",
                "Coder:toolbox:unsupportedString", 2, 12, 127);
          }
          if (cv10[u] != cv10[(int32_T)b_cv1[kstr]]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          b_bool = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      if (b_bool) {
        if (str_size[1] == 5) {
          nmatched = 1;
          match_size[0] = 1;
          match_size[1] = 5;
          for (i = 0; i < 5; i++) {
            match_data[i] = c_vstr[i];
          }
        } else {
          if (!matched) {
            match_size[0] = 1;
            match_size[1] = 5;
            for (i = 0; i < 5; i++) {
              match_data[i] = c_vstr[i];
            }
          }
          matched = true;
          nmatched++;
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }
  }
  if (guard2) {
    st.site = &bf_emlrtRSI;
    if ((str_size[1] <= 8) && c_strcmp(&st, str_data, str_size, str_size[1])) {
      if (str_size[1] == 8) {
        nmatched = 1;
        match_size[0] = 1;
        match_size[1] = 8;
        for (i = 0; i < 8; i++) {
          match_data[i] = vstr[i];
        }
      } else {
        if (!matched) {
          match_size[0] = 1;
          match_size[1] = 8;
          for (i = 0; i < 8; i++) {
            match_data[i] = vstr[i];
          }
        }
        nmatched++;
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1 && (nmatched == 0)) {
    match_size[0] = 1;
    match_size[1] = 8;
    for (i = 0; i < 8; i++) {
      match_data[i] = ' ';
    }
  }
  return nmatched;
}

/* End of code generation (validatestring.c) */
