/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "armvone.h"
#include "armvone_terminate.h"
#include "rt_nonfinite.h"
#include <stdio.h>

/* Function Declarations */
static void argInit_1x3_real_T(double result[3]);

static void argInit_1x5_real_T(double result[5]);

static double argInit_real_T(void);

/* Function Definitions */
static void argInit_1x3_real_T(double result[3])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x5_real_T(double result[5])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static double argInit_real_T(void)
{
  return 0.0;
}

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_armvone();
  /* Terminate the application.
You do not need to do this more than one time. */
  armvone_terminate();
  return 0;
}

void main_armvone(void)
{
  double dv[5];
  double vone_data[5];
  double dv1[3];
  int vone_size[2];
  /* Initialize function 'armvone' input arguments. */
  /* Initialize function input argument 'q0'. */
  /* Initialize function input argument 'pos'. */
  /* Call the entry-point 'armvone'. */
  for (int i = 0; i < 5; i++) scanf("%lf", dv+i);
  for (int i = 0; i < 3; i++) scanf("%lf", dv1+i);
  armvone(dv, dv1, vone_data, vone_size);
  for(int i=0 ; i<5 ; i++)
  printf("%f\n", vone_data[i]);
}

/* End of code generation (main.c) */
