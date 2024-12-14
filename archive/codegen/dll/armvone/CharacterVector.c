/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * CharacterVector.c
 *
 * Code generation for function 'CharacterVector'
 *
 */

/* Include files */
#include "CharacterVector.h"
#include "armvone_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void CharacterVector_setVector(c_robotics_manip_internal_Chara *obj,
                               const char vec_data[], const int vec_size[2])
{
  int loop_ub;
  obj->Length = vec_size[1];
  loop_ub = vec_size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&obj->Vector[0], &vec_data[0], (unsigned int)loop_ub * sizeof(char));
  }
}

/* End of code generation (CharacterVector.c) */
