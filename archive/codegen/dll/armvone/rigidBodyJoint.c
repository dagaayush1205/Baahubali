/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rigidBodyJoint.c
 *
 * Code generation for function 'rigidBodyJoint'
 *
 */

/* Include files */
#include "rigidBodyJoint.h"
#include "armvone_data.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
void binary_expand_op_13(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2])
{
  double b_in2_data[7];
  int i;
  int loop_ub;
  int stride_0_0_tmp;
  int stride_1_0;
  if (in2_size[0] == 1) {
    i = *in1_size;
  } else {
    i = in2_size[0];
  }
  if (i == 1) {
    loop_ub = in2_size[0];
  } else {
    loop_ub = i;
  }
  stride_0_0_tmp = (in2_size[0] != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    double b_in2_tmp;
    int in2_tmp;
    in2_tmp = i * stride_0_0_tmp;
    b_in2_tmp = in2_data[in2_tmp];
    b_in2_data[i] =
        b_in2_tmp + in1_data[i * stride_1_0] *
                        (in2_data[in2_tmp + in2_size[0]] - b_in2_tmp);
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in2_data[0],
           (unsigned int)loop_ub * sizeof(double));
  }
}

void binary_expand_op_14(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2])
{
  double b_in2_data[7];
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (*in1_size == 1) {
    loop_ub = in2_size[0];
  } else {
    loop_ub = *in1_size;
  }
  stride_0_0 = (in2_size[0] != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] = in2_data[i * stride_0_0] + in1_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in2_data[0],
           (unsigned int)loop_ub * sizeof(double));
  }
}

void binary_expand_op_15(double in1_data[], int *in1_size,
                         const double in2_data[], const int in2_size[2])
{
  double b_in2_data[7];
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (*in1_size == 1) {
    loop_ub = in2_size[0];
  } else {
    loop_ub = *in1_size;
  }
  stride_0_0 = (in2_size[0] != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2_data[i] =
        in2_data[i * stride_0_0 + in2_size[0]] - in1_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &b_in2_data[0],
           (unsigned int)loop_ub * sizeof(double));
  }
}

void c_rigidBodyJoint_get_MotionSubs(const rigidBodyJoint *obj,
                                     double msubspace_data[],
                                     int msubspace_size[2])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int kstr;
  boolean_T b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
  if (!b_bool) {
    double d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      kstr = (int)d;
    }
    msubspace_size[0] = 6;
    msubspace_size[1] = kstr;
    for (i = 0; i < kstr; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int msubspace_data_tmp;
        msubspace_data_tmp = i1 + 6 * i;
        msubspace_data[msubspace_data_tmp] =
            obj->MotionSubspaceInternal[msubspace_data_tmp];
      }
    }
  } else {
    msubspace_size[0] = 6;
    msubspace_size[1] = 1;
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
  }
}

void c_rigidBodyJoint_get_PositionLi(const rigidBodyJoint *obj,
                                     double lims_data[], int lims_size[2])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int kstr;
  boolean_T b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
  if (!b_bool) {
    double d;
    d = obj->PositionNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      kstr = (int)d;
    }
    lims_size[0] = kstr;
    lims_size[1] = 2;
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < kstr; i1++) {
        lims_data[i1 + kstr * i] = obj->PositionLimitsInternal[i1 + 7 * i];
      }
    }
  } else {
    lims_size[0] = 1;
    lims_size[1] = 2;
    lims_data[0] = 0.0;
    lims_data[1] = 0.0;
  }
}

void c_rigidBodyJoint_set_MotionSubs(rigidBodyJoint *obj,
                                     const double msubspace_data[])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  int i;
  int i1;
  int kstr;
  boolean_T b_bool;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 5) {
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
  if (!b_bool) {
    double d;
    d = obj->VelocityNumber;
    if (d < 1.0) {
      kstr = 0;
    } else {
      kstr = (int)d;
    }
    for (i = 0; i < kstr; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        int i2;
        i2 = i1 + 6 * i;
        obj->MotionSubspaceInternal[i2] = msubspace_data[i2];
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      obj->MotionSubspaceInternal[i] = 0.0;
    }
  }
}

void c_rigidBodyJoint_transformBodyT(const rigidBodyJoint *obj,
                                     const emxArray_real_T *q, double T[16])
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv1[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  double b[16];
  double b_I[16];
  double b_b[16];
  double tempR[9];
  double result_data[4];
  double v[3];
  const double *q_data;
  double b_tempR_tmp;
  double cth;
  double sth;
  double tempR_tmp;
  int exitg1;
  int i;
  int i1;
  int kstr;
  boolean_T result;
  q_data = q->data;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj->TypeInternal.Length;
  }
  result = false;
  if (i == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (b_cv[kstr] != obj->TypeInternal.Vector[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    kstr = 0;
  } else {
    result = false;
    if (i == 9) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 9) {
          if (cv3[kstr] != obj->TypeInternal.Vector[kstr]) {
            exitg1 = 1;
          } else {
            kstr++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      kstr = 1;
    } else {
      result = false;
      if (i == 8) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 8) {
            if (b_cv1[kstr] != obj->TypeInternal.Vector[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        kstr = 2;
      } else {
        kstr = -1;
      }
    }
  }
  switch (kstr) {
  case 0: {
    double R[9];
    signed char input_sizes_idx_1;
    rigidBodyJoint_get_JointAxis(obj, v);
    input_sizes_idx_1 = (signed char)(q->size[0] != 0);
    result_data[0] = v[0];
    result_data[1] = v[1];
    result_data[2] = v[2];
    kstr = input_sizes_idx_1;
    for (i = 0; i < kstr; i++) {
      result_data[3] = q_data[0];
    }
    __m128d r;
    double c_tempR_tmp;
    double d_tempR_tmp;
    double e_tempR_tmp;
    double f_tempR_tmp;
    double g_tempR_tmp;
    double h_tempR_tmp;
    double i_tempR_tmp;
    double j_tempR_tmp;
    double k_tempR_tmp;
    r = _mm_loadu_pd(&result_data[0]);
    _mm_storeu_pd(&v[0], _mm_mul_pd(r, r));
    sth = 1.0 / sqrt((v[0] + v[1]) + result_data[2] * result_data[2]);
    r = _mm_loadu_pd(&result_data[0]);
    _mm_storeu_pd(&v[0], _mm_mul_pd(r, _mm_set1_pd(sth)));
    v[2] = result_data[2] * sth;
    cth = cos(result_data[3]);
    sth = sin(result_data[3]);
    c_tempR_tmp = v[0] * v[0] * (1.0 - cth) + cth;
    tempR[0] = c_tempR_tmp;
    d_tempR_tmp = v[0] * v[1] * (1.0 - cth);
    e_tempR_tmp = v[2] * sth;
    f_tempR_tmp = d_tempR_tmp - e_tempR_tmp;
    tempR[1] = f_tempR_tmp;
    g_tempR_tmp = v[0] * v[2] * (1.0 - cth);
    h_tempR_tmp = v[1] * sth;
    i_tempR_tmp = g_tempR_tmp + h_tempR_tmp;
    tempR[2] = i_tempR_tmp;
    d_tempR_tmp += e_tempR_tmp;
    tempR[3] = d_tempR_tmp;
    e_tempR_tmp = v[1] * v[1] * (1.0 - cth) + cth;
    tempR[4] = e_tempR_tmp;
    j_tempR_tmp = v[1] * v[2] * (1.0 - cth);
    sth *= v[0];
    k_tempR_tmp = j_tempR_tmp - sth;
    tempR[5] = k_tempR_tmp;
    g_tempR_tmp -= h_tempR_tmp;
    tempR[6] = g_tempR_tmp;
    h_tempR_tmp = j_tempR_tmp + sth;
    tempR[7] = h_tempR_tmp;
    j_tempR_tmp = v[2] * v[2] * (1.0 - cth) + cth;
    tempR[8] = j_tempR_tmp;
    R[0] = c_tempR_tmp;
    R[1] = f_tempR_tmp;
    R[2] = i_tempR_tmp;
    R[3] = d_tempR_tmp;
    R[4] = e_tempR_tmp;
    R[5] = k_tempR_tmp;
    R[6] = g_tempR_tmp;
    R[7] = h_tempR_tmp;
    R[8] = j_tempR_tmp;
    for (kstr = 0; kstr < 3; kstr++) {
      R[kstr] = tempR[3 * kstr];
      R[kstr + 3] = tempR[3 * kstr + 1];
      R[kstr + 6] = tempR[3 * kstr + 2];
    }
    memset(&b[0], 0, 16U * sizeof(double));
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b[kstr] = R[3 * i];
      b[kstr + 1] = R[3 * i + 1];
      b[kstr + 2] = R[3 * i + 2];
    }
    b[15] = 1.0;
  } break;
  case 1:
    rigidBodyJoint_get_JointAxis(obj, v);
    memset(&tempR[0], 0, 9U * sizeof(double));
    tempR[0] = 1.0;
    tempR[4] = 1.0;
    tempR[8] = 1.0;
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b[kstr] = tempR[3 * i];
      b[kstr + 1] = tempR[3 * i + 1];
      b[kstr + 2] = tempR[3 * i + 2];
      b[i + 12] = v[i] * q_data[0];
    }
    b[3] = 0.0;
    b[7] = 0.0;
    b[11] = 0.0;
    b[15] = 1.0;
    break;
  case 2: {
    __m128d r;
    double R[9];
    double c_tempR_tmp;
    double d_tempR_tmp;
    double e_tempR_tmp;
    double f_tempR_tmp;
    double g_tempR_tmp;
    double h_tempR_tmp;
    double i_tempR_tmp;
    double j_tempR_tmp;
    double k_tempR_tmp;
    memset(&b_I[0], 0, 16U * sizeof(double));
    b_I[0] = 1.0;
    b_I[5] = 1.0;
    b_I[10] = 1.0;
    b_I[15] = 1.0;
    b_I[12] = q_data[4];
    b_I[13] = q_data[5];
    b_I[14] = q_data[6];
    r = _mm_loadu_pd(&q_data[0]);
    _mm_storeu_pd(&result_data[0], _mm_mul_pd(r, r));
    r = _mm_loadu_pd(&q_data[2]);
    _mm_storeu_pd(&result_data[2], _mm_mul_pd(r, r));
    sth = ((result_data[0] + result_data[1]) + result_data[2]) + result_data[3];
    r = _mm_set1_pd(1.0 / sqrt(sth));
    _mm_storeu_pd(&result_data[0], _mm_mul_pd(_mm_loadu_pd(&q_data[0]), r));
    _mm_storeu_pd(&result_data[2], _mm_mul_pd(_mm_loadu_pd(&q_data[2]), r));
    c_tempR_tmp = result_data[3] * result_data[3];
    d_tempR_tmp = result_data[2] * result_data[2];
    e_tempR_tmp = 1.0 - 2.0 * (d_tempR_tmp + c_tempR_tmp);
    tempR[0] = e_tempR_tmp;
    f_tempR_tmp = result_data[1] * result_data[2];
    g_tempR_tmp = result_data[0] * result_data[3];
    h_tempR_tmp = 2.0 * (f_tempR_tmp - g_tempR_tmp);
    tempR[1] = h_tempR_tmp;
    i_tempR_tmp = result_data[1] * result_data[3];
    j_tempR_tmp = result_data[0] * result_data[2];
    sth = 2.0 * (i_tempR_tmp + j_tempR_tmp);
    tempR[2] = sth;
    f_tempR_tmp = 2.0 * (f_tempR_tmp + g_tempR_tmp);
    tempR[3] = f_tempR_tmp;
    g_tempR_tmp = result_data[1] * result_data[1];
    c_tempR_tmp = 1.0 - 2.0 * (g_tempR_tmp + c_tempR_tmp);
    tempR[4] = c_tempR_tmp;
    k_tempR_tmp = result_data[2] * result_data[3];
    tempR_tmp = result_data[0] * result_data[1];
    b_tempR_tmp = 2.0 * (k_tempR_tmp - tempR_tmp);
    tempR[5] = b_tempR_tmp;
    i_tempR_tmp = 2.0 * (i_tempR_tmp - j_tempR_tmp);
    tempR[6] = i_tempR_tmp;
    j_tempR_tmp = 2.0 * (k_tempR_tmp + tempR_tmp);
    tempR[7] = j_tempR_tmp;
    d_tempR_tmp = 1.0 - 2.0 * (g_tempR_tmp + d_tempR_tmp);
    tempR[8] = d_tempR_tmp;
    R[0] = e_tempR_tmp;
    R[1] = h_tempR_tmp;
    R[2] = sth;
    R[3] = f_tempR_tmp;
    R[4] = c_tempR_tmp;
    R[5] = b_tempR_tmp;
    R[6] = i_tempR_tmp;
    R[7] = j_tempR_tmp;
    R[8] = d_tempR_tmp;
    for (kstr = 0; kstr < 3; kstr++) {
      R[kstr] = tempR[3 * kstr];
      R[kstr + 3] = tempR[3 * kstr + 1];
      R[kstr + 6] = tempR[3 * kstr + 2];
    }
    memset(&b_b[0], 0, 16U * sizeof(double));
    for (i = 0; i < 3; i++) {
      kstr = i << 2;
      b_b[kstr] = R[3 * i];
      b_b[kstr + 1] = R[3 * i + 1];
      b_b[kstr + 2] = R[3 * i + 2];
    }
    b_b[15] = 1.0;
    for (i = 0; i < 4; i++) {
      sth = b_I[i];
      cth = b_I[i + 4];
      tempR_tmp = b_I[i + 8];
      b_tempR_tmp = b_I[i + 12];
      for (i1 = 0; i1 < 4; i1++) {
        kstr = i1 << 2;
        b[i + kstr] = ((sth * b_b[kstr] + cth * b_b[kstr + 1]) +
                       tempR_tmp * b_b[kstr + 2]) +
                      b_tempR_tmp * b_b[kstr + 3];
      }
    }
  } break;
  default:
    memset(&b[0], 0, 16U * sizeof(double));
    b[0] = 1.0;
    b[5] = 1.0;
    b[10] = 1.0;
    b[15] = 1.0;
    break;
  }
  for (i = 0; i < 4; i++) {
    sth = obj->JointToParentTransform[i];
    cth = obj->JointToParentTransform[i + 4];
    tempR_tmp = obj->JointToParentTransform[i + 8];
    b_tempR_tmp = obj->JointToParentTransform[i + 12];
    for (i1 = 0; i1 < 4; i1++) {
      kstr = i1 << 2;
      b_I[i + kstr] =
          ((sth * b[kstr] + cth * b[kstr + 1]) + tempR_tmp * b[kstr + 2]) +
          b_tempR_tmp * b[kstr + 3];
    }
    sth = b_I[i];
    cth = b_I[i + 4];
    tempR_tmp = b_I[i + 8];
    b_tempR_tmp = b_I[i + 12];
    for (i1 = 0; i1 < 4; i1++) {
      kstr = i1 << 2;
      T[i + kstr] = ((sth * obj->ChildToJointTransform[kstr] +
                      cth * obj->ChildToJointTransform[kstr + 1]) +
                     tempR_tmp * obj->ChildToJointTransform[kstr + 2]) +
                    b_tempR_tmp * obj->ChildToJointTransform[kstr + 3];
    }
  }
}

void rigidBodyJoint_get_JointAxis(const rigidBodyJoint *obj, double ax[3])
{
  static const char b_cv[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  int exitg1;
  int i;
  int kstr;
  boolean_T b_bool;
  boolean_T guard1;
  if (obj->TypeInternal.Length < 1.0) {
    i = 0;
  } else {
    i = (int)obj->TypeInternal.Length;
  }
  b_bool = false;
  if (i == 8) {
    kstr = 0;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (obj->TypeInternal.Vector[kstr] != b_cv[kstr]) {
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
  guard1 = false;
  if (b_bool) {
    guard1 = true;
  } else {
    b_bool = false;
    if (i == 9) {
      kstr = 0;
      do {
        exitg1 = 0;
        if (kstr < 9) {
          if (obj->TypeInternal.Vector[kstr] != cv3[kstr]) {
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
    if (b_bool) {
      guard1 = true;
    } else {
      ax[0] = rtNaN;
      ax[1] = rtNaN;
      ax[2] = rtNaN;
    }
  }
  if (guard1) {
    ax[0] = obj->JointAxisInternal[0];
    ax[1] = obj->JointAxisInternal[1];
    ax[2] = obj->JointAxisInternal[2];
  }
}

rigidBodyJoint *rigidBodyJoint_rigidBodyJoint(rigidBodyJoint *obj,
                                              const char jname_data[],
                                              const int jname_size[2])
{
  static const char b_cv1[8] = {'r', 'e', 'v', 'o', 'l', 'u', 't', 'e'};
  static const char b_cv2[8] = {'f', 'l', 'o', 'a', 't', 'i', 'n', 'g'};
  static const signed char iv2[7] = {1, 0, 0, 0, 0, 0, 0};
  static const signed char b_iv[6] = {0, 0, 1, 0, 0, 0};
  static const signed char iv1[6] = {0, 0, 0, 0, 0, 1};
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  static const char b_cv3[5] = {'f', 'i', 'x', 'e', 'd'};
  c_robotics_manip_internal_Chara s;
  rigidBodyJoint *b_obj;
  double msubspace_data[36];
  double poslim_data[14];
  int exitg1;
  int homepos_size_idx_1;
  int i;
  int i1;
  int ibmat;
  int poslim_size_idx_0;
  signed char homepos_data[7];
  boolean_T result;
  b_obj = obj;
  b_obj->InTree = false;
  for (i = 0; i < 16; i++) {
    i1 = iv[i];
    b_obj->JointToParentTransform[i] = i1;
    b_obj->ChildToJointTransform[i] = i1;
  }
  for (i = 0; i < 14; i++) {
    b_obj->PositionLimitsInternal[i] = 0.0;
  }
  for (i = 0; i < 7; i++) {
    b_obj->HomePositionInternal[i] = 0.0;
  }
  for (i = 0; i < 36; i++) {
    b_obj->MotionSubspaceInternal[i] = 0.0;
  }
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->NameInternal = s;
  s.Length = 200.0;
  for (i = 0; i < 200; i++) {
    s.Vector[i] = ' ';
  }
  b_obj->TypeInternal = s;
  s = b_obj->NameInternal;
  s.Length = jname_size[1];
  ibmat = jname_size[1];
  if (ibmat - 1 >= 0) {
    memcpy(&s.Vector[0], &jname_data[0], (unsigned int)ibmat * sizeof(char));
  }
  b_obj->NameInternal = s;
  s = b_obj->TypeInternal;
  s.Length = 5.0;
  for (i = 0; i < 5; i++) {
    s.Vector[i] = b_cv[i];
  }
  b_obj->TypeInternal = s;
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    i = (int)s.Length;
  }
  result = false;
  if (i == 8) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 8) {
        if (b_cv1[ibmat] != s.Vector[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (result) {
    ibmat = 0;
  } else {
    result = false;
    if (i == 9) {
      ibmat = 0;
      do {
        exitg1 = 0;
        if (ibmat < 9) {
          if (cv3[ibmat] != s.Vector[ibmat]) {
            exitg1 = 1;
          } else {
            ibmat++;
          }
        } else {
          result = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (result) {
      ibmat = 1;
    } else {
      result = false;
      if (i == 8) {
        ibmat = 0;
        do {
          exitg1 = 0;
          if (ibmat < 8) {
            if (b_cv2[ibmat] != s.Vector[ibmat]) {
              exitg1 = 1;
            } else {
              ibmat++;
            }
          } else {
            result = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      if (result) {
        ibmat = 2;
      } else {
        ibmat = -1;
      }
    }
  }
  switch (ibmat) {
  case 0:
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = b_iv[i];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -3.1415926535897931;
    poslim_data[1] = 3.1415926535897931;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 1:
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = iv1[i];
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = -0.5;
    poslim_data[1] = 0.5;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 1.0;
    b_obj->PositionNumber = 1.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 1.0;
    break;
  case 2: {
    signed char b_I[36];
    signed char b[6];
    for (i = 0; i < 36; i++) {
      b_I[i] = 0;
    }
    for (ibmat = 0; ibmat < 6; ibmat++) {
      b_I[ibmat + 6 * ibmat] = 1;
    }
    for (i = 0; i < 36; i++) {
      msubspace_data[i] = b_I[i];
    }
    poslim_size_idx_0 = 7;
    for (homepos_size_idx_1 = 0; homepos_size_idx_1 < 2; homepos_size_idx_1++) {
      signed char b_tmp;
      ibmat = homepos_size_idx_1 * 3;
      b_tmp = (signed char)(10 * homepos_size_idx_1 - 5);
      b[ibmat] = b_tmp;
      b[ibmat + 1] = b_tmp;
      b[ibmat + 2] = b_tmp;
      poslim_data[7 * homepos_size_idx_1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 1] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 2] = rtNaN;
      poslim_data[7 * homepos_size_idx_1 + 3] = rtNaN;
    }
    for (i = 0; i < 2; i++) {
      poslim_data[7 * i + 4] = b[3 * i];
      poslim_data[7 * i + 5] = b[3 * i + 1];
      poslim_data[7 * i + 6] = b[3 * i + 2];
    }
    homepos_size_idx_1 = 7;
    for (i = 0; i < 7; i++) {
      homepos_data[i] = iv2[i];
    }
    b_obj->VelocityNumber = 6.0;
    b_obj->PositionNumber = 7.0;
    b_obj->JointAxisInternal[0] = rtNaN;
    b_obj->JointAxisInternal[1] = rtNaN;
    b_obj->JointAxisInternal[2] = rtNaN;
  } break;
  default:
    for (i = 0; i < 6; i++) {
      msubspace_data[i] = 0.0;
    }
    poslim_size_idx_0 = 1;
    poslim_data[0] = 0.0;
    poslim_data[1] = 0.0;
    homepos_size_idx_1 = 1;
    homepos_data[0] = 0;
    b_obj->VelocityNumber = 0.0;
    b_obj->PositionNumber = 0.0;
    b_obj->JointAxisInternal[0] = 0.0;
    b_obj->JointAxisInternal[1] = 0.0;
    b_obj->JointAxisInternal[2] = 0.0;
    break;
  }
  c_rigidBodyJoint_set_MotionSubs(b_obj, msubspace_data);
  s = b_obj->TypeInternal;
  if (s.Length < 1.0) {
    i = 0;
  } else {
    i = (int)s.Length;
  }
  result = false;
  if (i == 5) {
    ibmat = 0;
    do {
      exitg1 = 0;
      if (ibmat < 5) {
        if (s.Vector[ibmat] != b_cv3[ibmat]) {
          exitg1 = 1;
        } else {
          ibmat++;
        }
      } else {
        result = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (!result) {
    double d;
    d = b_obj->PositionNumber;
    if (d < 1.0) {
      ibmat = 0;
    } else {
      ibmat = (int)d;
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < ibmat; i1++) {
        b_obj->PositionLimitsInternal[i1 + 7 * i] =
            poslim_data[i1 + poslim_size_idx_0 * i];
      }
    }
    for (i = 0; i < homepos_size_idx_1; i++) {
      b_obj->HomePositionInternal[i] = homepos_data[i];
    }
  } else {
    b_obj->PositionLimitsInternal[0] = poslim_data[0];
    b_obj->PositionLimitsInternal[7] = poslim_data[1];
    b_obj->HomePositionInternal[0] = homepos_data[0];
  }
  return b_obj;
}

/* End of code generation (rigidBodyJoint.c) */
