/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: IKHelpers.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "IKHelpers.h"
#include "RigidBodyTree.h"
#include "armvone_emxutil.h"
#include "armvone_types.h"
#include "rand.h"
#include "randn.h"
#include "rigidBodyJoint.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "svd.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Definitions */
/*
 * Arguments    : const emxArray_real_T *x
 *                c_robotics_manip_internal_IKExt *args
 *                double W[36]
 *                emxArray_real_T *Jac
 *                c_robotics_manip_internal_IKExt **b_args
 * Return Type  : double
 */
double IKHelpers_computeCost(const emxArray_real_T *x,
                             c_robotics_manip_internal_IKExt *args,
                             double W[36], emxArray_real_T *Jac,
                             c_robotics_manip_internal_IKExt **b_args)
{
  __m128d r;
  e_robotics_manip_internal_Rigid *treeInternal;
  emxArray_real_T *c_y;
  creal_T u;
  creal_T v;
  double T_data[16];
  double Td[16];
  double T[9];
  double y[9];
  double b_y[6];
  double e[6];
  double c_v[4];
  double b_v[3];
  double s[3];
  double vspecial_data[3];
  double cost;
  double d;
  double q;
  double *Jac_data;
  double *y_data;
  int T_size[2];
  int boffset;
  int i;
  int scalarLB;
  int vectorUB;
  signed char R_tmp[3];
  boolean_T exitg1;
  boolean_T rEQ0;
  *b_args = args;
  treeInternal = (*b_args)->Robot;
  for (i = 0; i < 16; i++) {
    Td[i] = (*b_args)->Tform[i];
  }
  for (i = 0; i < 36; i++) {
    W[i] = (*b_args)->WeightMatrix[i];
  }
  cost = (*b_args)->BodyIndex;
  c_RigidBodyTree_efficientFKAndJ(treeInternal, x, cost, T_data, T_size, Jac);
  boffset = 6 * Jac->size[1];
  i = Jac->size[0] * Jac->size[1];
  Jac->size[0] = 6;
  emxEnsureCapacity_real_T(Jac, i);
  Jac_data = Jac->data;
  scalarLB = (boffset / 2) << 1;
  vectorUB = scalarLB - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&Jac_data[i]);
    _mm_storeu_pd(&Jac_data[i], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
  }
  for (i = scalarLB; i < boffset; i++) {
    Jac_data[i] = -Jac_data[i];
  }
  i = T_size[0];
  for (scalarLB = 0; scalarLB < 3; scalarLB++) {
    R_tmp[scalarLB] = (signed char)(scalarLB + 1);
    T[3 * scalarLB] = T_data[(signed char)(scalarLB + 1) - 1];
    T[3 * scalarLB + 1] = T_data[((signed char)(scalarLB + 1) + i) - 1];
    T[3 * scalarLB + 2] = T_data[((signed char)(scalarLB + 1) + i * 2) - 1];
  }
  for (i = 0; i < 3; i++) {
    d = Td[i];
    cost = Td[i + 4];
    q = Td[i + 8];
    for (scalarLB = 0; scalarLB < 3; scalarLB++) {
      y[i + 3 * scalarLB] = (d * T[3 * scalarLB] + cost * T[3 * scalarLB + 1]) +
                            q * T[3 * scalarLB + 2];
    }
  }
  cost = 0.5 * (((y[0] + y[4]) + y[8]) - 1.0);
  if (!(fabs(cost) > 1.0)) {
    u.re = acos(cost);
  } else {
    boolean_T b;
    v.re = cost + 1.0;
    v.im = 0.0;
    b_sqrt(&v);
    u.re = 1.0 - cost;
    u.im = 0.0;
    b_sqrt(&u);
    rEQ0 = rtIsNaN(v.re);
    b = rtIsNaN(u.re);
    if (b || rEQ0) {
      cost = rtNaN;
    } else if (rtIsInf(u.re) && rtIsInf(v.re)) {
      if (u.re > 0.0) {
        i = 1;
      } else {
        i = -1;
      }
      if (v.re > 0.0) {
        boffset = 1;
      } else {
        boffset = -1;
      }
      cost = atan2(i, boffset);
    } else if (v.re == 0.0) {
      if (u.re > 0.0) {
        cost = RT_PI / 2.0;
      } else if (u.re < 0.0) {
        cost = -(RT_PI / 2.0);
      } else {
        cost = 0.0;
      }
    } else {
      cost = atan2(u.re, v.re);
    }
    u.re = 2.0 * cost;
  }
  cost = 2.0 * sin(u.re);
  b_v[0] = (y[5] - y[7]) / cost;
  b_v[1] = (y[6] - y[2]) / cost;
  b_v[2] = (y[1] - y[3]) / cost;
  if (rtIsNaN(u.re) || rtIsInf(u.re)) {
    cost = rtNaN;
  } else if (u.re == 0.0) {
    cost = 0.0;
  } else {
    cost = fmod(u.re, 3.1415926535897931);
    rEQ0 = (cost == 0.0);
    if (!rEQ0) {
      q = fabs(u.re / 3.1415926535897931);
      rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
    }
    if (rEQ0) {
      cost = 0.0;
    } else if (cost < 0.0) {
      cost += 3.1415926535897931;
    }
  }
  rEQ0 = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 3)) {
    if (!(b_v[i] == 0.0)) {
      rEQ0 = false;
      exitg1 = true;
    } else {
      i++;
    }
  }
  if ((cost == 0.0) || rEQ0) {
    for (i = 0; i < 3; i++) {
      vspecial_data[i] = 0.0;
    }
    for (scalarLB = 0; scalarLB < 1; scalarLB++) {
      __m128d r1;
      double V[9];
      memset(&T[0], 0, 9U * sizeof(double));
      T[0] = 1.0;
      T[4] = 1.0;
      T[8] = 1.0;
      r = _mm_loadu_pd(&T[0]);
      r1 = _mm_loadu_pd(&y[0]);
      _mm_storeu_pd(&T[0], _mm_sub_pd(r, r1));
      r = _mm_loadu_pd(&T[2]);
      r1 = _mm_loadu_pd(&y[2]);
      _mm_storeu_pd(&T[2], _mm_sub_pd(r, r1));
      r = _mm_loadu_pd(&T[4]);
      r1 = _mm_loadu_pd(&y[4]);
      _mm_storeu_pd(&T[4], _mm_sub_pd(r, r1));
      r = _mm_loadu_pd(&T[6]);
      r1 = _mm_loadu_pd(&y[6]);
      _mm_storeu_pd(&T[6], _mm_sub_pd(r, r1));
      T[8] -= y[8];
      rEQ0 = true;
      for (i = 0; i < 9; i++) {
        if (rEQ0) {
          d = T[i];
          if (rtIsInf(d) || rtIsNaN(d)) {
            rEQ0 = false;
          }
        } else {
          rEQ0 = false;
        }
      }
      if (rEQ0) {
        double U[9];
        svd(T, U, s, V);
      } else {
        for (i = 0; i < 9; i++) {
          V[i] = rtNaN;
        }
      }
      vspecial_data[0] = V[6];
      vspecial_data[1] = V[7];
      vspecial_data[2] = V[8];
    }
    b_v[0] = vspecial_data[0];
    b_v[1] = vspecial_data[1];
    b_v[2] = vspecial_data[2];
  }
  r = _mm_loadu_pd(&b_v[0]);
  _mm_storeu_pd(&s[0], r);
  _mm_storeu_pd(&vspecial_data[0], _mm_mul_pd(r, r));
  s[2] = b_v[2];
  cost = 1.0 / sqrt((vspecial_data[0] + vspecial_data[1]) + b_v[2] * b_v[2]);
  r = _mm_loadu_pd(&s[0]);
  _mm_storeu_pd(&c_v[0], _mm_mul_pd(r, _mm_set1_pd(cost)));
  e[0] = u.re * c_v[0];
  e[3] = Td[12] - T_data[(R_tmp[0] + T_size[0] * 3) - 1];
  e[1] = u.re * c_v[1];
  e[4] = Td[13] - T_data[(R_tmp[1] + T_size[0] * 3) - 1];
  e[2] = u.re * (s[2] * cost);
  e[5] = Td[14] - T_data[(R_tmp[2] + T_size[0] * 3) - 1];
  i = (*b_args)->ErrTemp->size[0];
  (*b_args)->ErrTemp->size[0] = 6;
  emxEnsureCapacity_real_T((*b_args)->ErrTemp, i);
  for (i = 0; i < 6; i++) {
    (*b_args)->ErrTemp->data[i] = e[i];
  }
  cost = 0.0;
  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (scalarLB = 0; scalarLB < 6; scalarLB++) {
      d += 0.5 * e[scalarLB] * W[scalarLB + 6 * i];
    }
    cost += d * e[i];
  }
  (*b_args)->CostTemp = cost;
  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (scalarLB = 0; scalarLB < 6; scalarLB++) {
      d += e[scalarLB] * W[scalarLB + 6 * i];
    }
    b_y[i] = d;
  }
  scalarLB = Jac->size[1];
  emxInit_real_T(&c_y, 2);
  i = c_y->size[0] * c_y->size[1];
  c_y->size[0] = 1;
  c_y->size[1] = Jac->size[1];
  emxEnsureCapacity_real_T(c_y, i);
  y_data = c_y->data;
  for (vectorUB = 0; vectorUB < scalarLB; vectorUB++) {
    boffset = vectorUB * 6;
    cost = 0.0;
    for (i = 0; i < 6; i++) {
      cost += b_y[i] * Jac_data[boffset + i];
    }
    y_data[vectorUB] = cost;
  }
  i = (*b_args)->GradTemp->size[0];
  (*b_args)->GradTemp->size[0] = Jac->size[1];
  emxEnsureCapacity_real_T((*b_args)->GradTemp, i);
  for (i = 0; i < scalarLB; i++) {
    (*b_args)->GradTemp->data[i] = y_data[i];
  }
  emxFree_real_T(&c_y);
  return (*b_args)->CostTemp;
}

/*
 * Arguments    : const c_robotics_manip_internal_IKExt *args
 * Return Type  : double
 */
double IKHelpers_evaluateSolution(const c_robotics_manip_internal_IKExt *args)
{
  double en;
  double scale;
  int i;
  int k;
  en = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 6; k++) {
    double absxk;
    absxk = 0.0;
    for (i = 0; i < 6; i++) {
      absxk += args->WeightMatrix[k + 6 * i] * args->ErrTemp->data[i];
    }
    absxk = fabs(absxk);
    if (absxk > scale) {
      double t;
      t = scale / absxk;
      en = en * t * t + 1.0;
      scale = absxk;
    } else {
      double t;
      t = absxk / scale;
      en += t * t;
    }
  }
  return scale * sqrt(en);
}

/*
 * Arguments    : c_robotics_manip_internal_IKExt *args
 *                double rc_data[]
 * Return Type  : int
 */
int IKHelpers_randomConfig(c_robotics_manip_internal_IKExt *args,
                           double rc_data[])
{
  static const char b_cv[5] = {'f', 'i', 'x', 'e', 'd'};
  e_robotics_manip_internal_Rigid *obj;
  emxArray_boolean_T *x;
  rigidBodyJoint *b_obj;
  double qi_data[49];
  double bounds_data[14];
  double b_x_data[7];
  double rn_data[7];
  double translbounds[6];
  double rn[3];
  double dv[2];
  double posnum;
  int bounds_size[2];
  int b_i;
  int i;
  int i1;
  int kstr;
  int loop_ub_tmp;
  int rc_size;
  int vectorUB;
  int x_size;
  boolean_T *x_data;
  obj = args->Robot;
  posnum = obj->PositionNumber;
  loop_ub_tmp = (int)posnum;
  rc_size = (int)posnum;
  if (loop_ub_tmp - 1 >= 0) {
    memset(&rc_data[0], 0, (unsigned int)loop_ub_tmp * sizeof(double));
  }
  posnum = obj->NumBodies;
  i = (int)posnum;
  emxInit_boolean_T(&x);
  for (b_i = 0; b_i < i; b_i++) {
    double p_idx_0;
    double p_idx_1;
    p_idx_0 = obj->PositionDoFMap[b_i];
    p_idx_1 = obj->PositionDoFMap[b_i + 6];
    if (p_idx_0 <= p_idx_1) {
      char obj_Vector[200];
      signed char unnamed_idx_1;
      boolean_T b_bool;
      b_obj = obj->Bodies[b_i]->JointInternal;
      posnum = b_obj->TypeInternal.Length;
      for (i1 = 0; i1 < 200; i1++) {
        obj_Vector[i1] = b_obj->TypeInternal.Vector[i1];
      }
      if (posnum < 1.0) {
        i1 = 0;
      } else {
        i1 = (int)posnum;
      }
      b_bool = false;
      if (i1 == 5) {
        kstr = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (kstr < 5) {
            if (obj_Vector[kstr] != b_cv[kstr]) {
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
        posnum = b_obj->PositionNumber;
        if (posnum < 1.0) {
          unnamed_idx_1 = 0;
        } else {
          unnamed_idx_1 = (signed char)(int)posnum;
        }
      } else {
        unnamed_idx_1 = 1;
      }
      kstr = unnamed_idx_1;
      if (kstr - 1 >= 0) {
        memset(&qi_data[0], 0, (unsigned int)kstr * sizeof(double));
      }
      switch ((int)b_obj->PositionNumber) {
      case 0:
        qi_data[0] = rtNaN;
        break;
      case 7: {
        __m128d b_r;
        __m128d r1;
        double r[4];
        double b_x[3];
        boolean_T b_b[3];
        boolean_T bv[3];
        boolean_T c_b[3];
        boolean_T b;
        boolean_T exitg2;
        boolean_T guard1;
        boolean_T guard2;
        boolean_T guard3;
        randn(r);
        posnum =
            sqrt(((r[0] * r[0] + r[1] * r[1]) + r[2] * r[2]) + r[3] * r[3]);
        qi_data[0] = r[0] / posnum;
        qi_data[1] = r[1] / posnum;
        qi_data[2] = r[2] / posnum;
        qi_data[3] = r[3] / posnum;
        for (i1 = 0; i1 < 2; i1++) {
          translbounds[3 * i1] = b_obj->PositionLimitsInternal[7 * i1 + 4];
          translbounds[3 * i1 + 1] = b_obj->PositionLimitsInternal[7 * i1 + 5];
          translbounds[3 * i1 + 2] = b_obj->PositionLimitsInternal[7 * i1 + 6];
        }
        if (unnamed_idx_1 < 5) {
          i1 = 0;
          vectorUB = 0;
        } else {
          i1 = 4;
          vectorUB = unnamed_idx_1;
        }
        bv[0] = ((!rtIsInf(translbounds[0])) && (!rtIsNaN(translbounds[0])));
        bv[1] = ((!rtIsInf(translbounds[1])) && (!rtIsNaN(translbounds[1])));
        bv[2] = ((!rtIsInf(translbounds[2])) && (!rtIsNaN(translbounds[2])));
        b = true;
        kstr = 0;
        exitg2 = false;
        while ((!exitg2) && (kstr < 3)) {
          if (!bv[kstr]) {
            b = false;
            exitg2 = true;
          } else {
            kstr++;
          }
        }
        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (b) {
          b_b[0] = rtIsInf(translbounds[3]);
          c_b[0] = rtIsNaN(translbounds[3]);
          b_b[1] = rtIsInf(translbounds[4]);
          c_b[1] = rtIsNaN(translbounds[4]);
          b_b[2] = rtIsInf(translbounds[5]);
          c_b[2] = rtIsNaN(translbounds[5]);
          b_bool = true;
          kstr = 0;
          exitg2 = false;
          while ((!exitg2) && (kstr < 3)) {
            if (b_b[kstr] || c_b[kstr]) {
              b_bool = false;
              exitg2 = true;
            } else {
              kstr++;
            }
          }
          if (b_bool) {
            __m128d r2;
            c_rand(rn);
            b_r = _mm_loadu_pd(&translbounds[3]);
            r1 = _mm_loadu_pd(&translbounds[0]);
            r2 = _mm_loadu_pd(&rn[0]);
            _mm_storeu_pd(&rn[0],
                          _mm_add_pd(r1, _mm_mul_pd(r2, _mm_sub_pd(b_r, r1))));
            rn[2] =
                translbounds[2] + rn[2] * (translbounds[5] - translbounds[2]);
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
        if (guard3) {
          if (b) {
            b_b[0] = !rtIsInf(translbounds[3]);
            c_b[0] = !rtIsNaN(translbounds[3]);
            b_b[1] = !rtIsInf(translbounds[4]);
            c_b[1] = !rtIsNaN(translbounds[4]);
            b_b[2] = !rtIsInf(translbounds[5]);
            c_b[2] = !rtIsNaN(translbounds[5]);
            b_bool = false;
            kstr = 0;
            exitg2 = false;
            while ((!exitg2) && (kstr < 3)) {
              if ((!b_b[kstr]) || (!c_b[kstr])) {
                b_bool = true;
                exitg2 = true;
              } else {
                kstr++;
              }
            }
            if (b_bool) {
              b_randn(b_x);
              dv[0] = fabs(b_x[0]);
              dv[1] = fabs(b_x[1]);
              b_r = _mm_loadu_pd(&translbounds[0]);
              r1 = _mm_loadu_pd(&dv[0]);
              _mm_storeu_pd(&rn[0], _mm_add_pd(b_r, r1));
              rn[2] = translbounds[2] + fabs(b_x[2]);
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }
        if (guard2) {
          b_bool = false;
          kstr = 0;
          exitg2 = false;
          while ((!exitg2) && (kstr < 3)) {
            if (!bv[kstr]) {
              b_bool = true;
              exitg2 = true;
            } else {
              kstr++;
            }
          }
          if (b_bool) {
            b_b[0] = rtIsInf(translbounds[3]);
            c_b[0] = rtIsNaN(translbounds[3]);
            b_b[1] = rtIsInf(translbounds[4]);
            c_b[1] = rtIsNaN(translbounds[4]);
            b_b[2] = rtIsInf(translbounds[5]);
            c_b[2] = rtIsNaN(translbounds[5]);
            b_bool = true;
            kstr = 0;
            exitg2 = false;
            while ((!exitg2) && (kstr < 3)) {
              if (b_b[kstr] || c_b[kstr]) {
                b_bool = false;
                exitg2 = true;
              } else {
                kstr++;
              }
            }
            if (b_bool) {
              b_randn(b_x);
              dv[0] = fabs(b_x[0]);
              dv[1] = fabs(b_x[1]);
              b_r = _mm_loadu_pd(&translbounds[3]);
              r1 = _mm_loadu_pd(&dv[0]);
              _mm_storeu_pd(&rn[0], _mm_sub_pd(b_r, r1));
              rn[2] = translbounds[5] - fabs(b_x[2]);
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }
        if (guard1) {
          b_randn(rn);
        }
        kstr = vectorUB - i1;
        for (vectorUB = 0; vectorUB < kstr; vectorUB++) {
          qi_data[i1 + vectorUB] = rn[vectorUB];
        }
      } break;
      default: {
        __m128d b_r;
        __m128d r1;
        boolean_T exitg2;
        boolean_T guard1;
        boolean_T guard2;
        boolean_T guard3;
        posnum = b_obj->PositionNumber;
        if (posnum < 1.0) {
          loop_ub_tmp = 0;
        } else {
          loop_ub_tmp = (int)posnum;
        }
        bounds_size[0] = loop_ub_tmp;
        bounds_size[1] = 2;
        for (i1 = 0; i1 < 2; i1++) {
          for (vectorUB = 0; vectorUB < loop_ub_tmp; vectorUB++) {
            bounds_data[vectorUB + loop_ub_tmp * i1] =
                b_obj->PositionLimitsInternal[vectorUB + 7 * i1];
          }
        }
        i1 = x->size[0];
        x->size[0] = loop_ub_tmp;
        emxEnsureCapacity_boolean_T(x, i1);
        x_data = x->data;
        for (i1 = 0; i1 < loop_ub_tmp; i1++) {
          posnum = bounds_data[i1];
          x_data[i1] = ((!rtIsInf(posnum)) && (!rtIsNaN(posnum)));
        }
        b_bool = true;
        kstr = 1;
        exitg2 = false;
        while ((!exitg2) && (kstr <= x->size[0])) {
          if (!x_data[kstr - 1]) {
            b_bool = false;
            exitg2 = true;
          } else {
            kstr++;
          }
        }
        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (b_bool) {
          i1 = x->size[0];
          x->size[0] = loop_ub_tmp;
          emxEnsureCapacity_boolean_T(x, i1);
          x_data = x->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            posnum = bounds_data[i1 + loop_ub_tmp];
            x_data[i1] = ((!rtIsInf(posnum)) && (!rtIsNaN(posnum)));
          }
          b_bool = true;
          kstr = 1;
          exitg2 = false;
          while ((!exitg2) && (kstr <= x->size[0])) {
            if (!x_data[kstr - 1]) {
              b_bool = false;
              exitg2 = true;
            } else {
              kstr++;
            }
          }
          if (b_bool) {
            x_size = d_rand(loop_ub_tmp, rn_data);
            if (x_size == 1) {
              i1 = loop_ub_tmp;
            } else {
              i1 = x_size;
            }
            if ((x_size == loop_ub_tmp) && (loop_ub_tmp == i1)) {
              x_size = loop_ub_tmp;
              kstr = (loop_ub_tmp / 2) << 1;
              vectorUB = kstr - 2;
              for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                __m128d r2;
                b_r = _mm_loadu_pd(&bounds_data[i1 + loop_ub_tmp]);
                r1 = _mm_loadu_pd(&bounds_data[i1]);
                r2 = _mm_loadu_pd(&rn_data[i1]);
                _mm_storeu_pd(
                    &rn_data[i1],
                    _mm_add_pd(r1, _mm_mul_pd(r2, _mm_sub_pd(b_r, r1))));
              }
              for (i1 = kstr; i1 < loop_ub_tmp; i1++) {
                posnum = bounds_data[i1];
                rn_data[i1] =
                    posnum +
                    rn_data[i1] * (bounds_data[i1 + loop_ub_tmp] - posnum);
              }
            } else {
              binary_expand_op_13(rn_data, &x_size, bounds_data, bounds_size);
            }
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
        if (guard3) {
          i1 = x->size[0];
          x->size[0] = loop_ub_tmp;
          emxEnsureCapacity_boolean_T(x, i1);
          x_data = x->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            posnum = bounds_data[i1];
            x_data[i1] = ((!rtIsInf(posnum)) && (!rtIsNaN(posnum)));
          }
          b_bool = true;
          kstr = 1;
          exitg2 = false;
          while ((!exitg2) && (kstr <= x->size[0])) {
            if (!x_data[kstr - 1]) {
              b_bool = false;
              exitg2 = true;
            } else {
              kstr++;
            }
          }
          if (b_bool) {
            i1 = x->size[0];
            x->size[0] = loop_ub_tmp;
            emxEnsureCapacity_boolean_T(x, i1);
            x_data = x->data;
            for (i1 = 0; i1 < loop_ub_tmp; i1++) {
              posnum = bounds_data[i1 + loop_ub_tmp];
              x_data[i1] = (rtIsInf(posnum) || rtIsNaN(posnum));
            }
            b_bool = false;
            kstr = 1;
            exitg2 = false;
            while ((!exitg2) && (kstr <= x->size[0])) {
              if (x_data[kstr - 1]) {
                b_bool = true;
                exitg2 = true;
              } else {
                kstr++;
              }
            }
            if (b_bool) {
              dv[0] = loop_ub_tmp;
              dv[1] = 1.0;
              x_size = c_randn(dv, b_x_data);
              for (kstr = 0; kstr < x_size; kstr++) {
                rn_data[kstr] = fabs(b_x_data[kstr]);
              }
              if (loop_ub_tmp == x_size) {
                x_size = loop_ub_tmp;
                kstr = (loop_ub_tmp / 2) << 1;
                vectorUB = kstr - 2;
                for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                  b_r = _mm_loadu_pd(&bounds_data[i1]);
                  r1 = _mm_loadu_pd(&rn_data[i1]);
                  _mm_storeu_pd(&rn_data[i1], _mm_add_pd(b_r, r1));
                }
                for (i1 = kstr; i1 < loop_ub_tmp; i1++) {
                  rn_data[i1] += bounds_data[i1];
                }
              } else {
                binary_expand_op_14(rn_data, &x_size, bounds_data, bounds_size);
              }
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }
        }
        if (guard2) {
          i1 = x->size[0];
          x->size[0] = loop_ub_tmp;
          emxEnsureCapacity_boolean_T(x, i1);
          x_data = x->data;
          for (i1 = 0; i1 < loop_ub_tmp; i1++) {
            posnum = bounds_data[i1];
            x_data[i1] = (rtIsInf(posnum) || rtIsNaN(posnum));
          }
          b_bool = false;
          kstr = 1;
          exitg2 = false;
          while ((!exitg2) && (kstr <= x->size[0])) {
            if (x_data[kstr - 1]) {
              b_bool = true;
              exitg2 = true;
            } else {
              kstr++;
            }
          }
          if (b_bool) {
            i1 = x->size[0];
            x->size[0] = loop_ub_tmp;
            emxEnsureCapacity_boolean_T(x, i1);
            x_data = x->data;
            for (i1 = 0; i1 < loop_ub_tmp; i1++) {
              posnum = bounds_data[i1 + loop_ub_tmp];
              x_data[i1] = ((!rtIsInf(posnum)) && (!rtIsNaN(posnum)));
            }
            b_bool = true;
            kstr = 1;
            exitg2 = false;
            while ((!exitg2) && (kstr <= x->size[0])) {
              if (!x_data[kstr - 1]) {
                b_bool = false;
                exitg2 = true;
              } else {
                kstr++;
              }
            }
            if (b_bool) {
              dv[0] = loop_ub_tmp;
              dv[1] = 1.0;
              x_size = c_randn(dv, b_x_data);
              for (kstr = 0; kstr < x_size; kstr++) {
                rn_data[kstr] = fabs(b_x_data[kstr]);
              }
              if (loop_ub_tmp == x_size) {
                x_size = loop_ub_tmp;
                kstr = (loop_ub_tmp / 2) << 1;
                vectorUB = kstr - 2;
                for (i1 = 0; i1 <= vectorUB; i1 += 2) {
                  b_r = _mm_loadu_pd(&bounds_data[i1 + loop_ub_tmp]);
                  r1 = _mm_loadu_pd(&rn_data[i1]);
                  _mm_storeu_pd(&rn_data[i1], _mm_sub_pd(b_r, r1));
                }
                for (i1 = kstr; i1 < loop_ub_tmp; i1++) {
                  rn_data[i1] = bounds_data[i1 + loop_ub_tmp] - rn_data[i1];
                }
              } else {
                binary_expand_op_15(rn_data, &x_size, bounds_data, bounds_size);
              }
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }
        }
        if (guard1) {
          dv[0] = loop_ub_tmp;
          dv[1] = 1.0;
          x_size = c_randn(dv, rn_data);
        }
        if (x_size - 1 >= 0) {
          memcpy(&qi_data[0], &rn_data[0],
                 (unsigned int)x_size * sizeof(double));
        }
      } break;
      }
      if (p_idx_0 > p_idx_1) {
        i1 = 0;
        vectorUB = 0;
      } else {
        i1 = (int)p_idx_0 - 1;
        vectorUB = (int)p_idx_1;
      }
      kstr = vectorUB - i1;
      for (vectorUB = 0; vectorUB < kstr; vectorUB++) {
        rc_data[i1 + vectorUB] = qi_data[vectorUB];
      }
    }
  }
  emxFree_boolean_T(&x);
  return rc_size;
}

/*
 * File trailer for IKHelpers.c
 *
 * [EOF]
 */
