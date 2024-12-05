/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: _coder_armvone_info.c
 *
 * MATLAB Coder version            : 24.2
 * C/C++ source code generated on  : 05-Dec-2024 16:36:04
 */

/* Include Files */
#include "_coder_armvone_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789ced54cd4ec240105e0c261efce1e203987031246df4403c8b82358a6831261212b6ed"
      "220bbb5db35db49e7c043dfa481e7d23b5942d6db5290182073b97e9"
      "ecb73bdf37b3dd0139ed3c0700d804bebdadfb7e631c17c67e05442d8ee762fb72d1ed60"
      "15e423e724fe32f626b30572851fd890a2e0a4c528b6a12d9a4ff708",
      "70e430f280ac11d2c5043531457a38a87b11ad86a020f020efbbd243e6401f52c07bce44"
      "210907413f3e12eacd4fd90f9ad08f420c6f699576914241a0c11913"
      "455530460ce6aa4e0f7264a99c194c60d3f13f860213472d058b259371a496f0770fb90d"
      "897a04e93db20eab35fdb1c6a185912d1a9cf5912930b3151aaaef75",
      "cefa7653ea93b894aa784a152954a99f3574ef42f9b18b4595c03b7907525f67467d714b"
      "d2274df2bdcfc827f31b297c126f69f505def7cf362a345a572741f7"
      "d69475c5fd64ffdac8ef3c7fb697c927edbff0b909f9a6fd2fb713f80a317cbf4f7aba8b"
      "6e0765fdf4a07c7d79b377757211d2d148e149d30112e265e55fdefb",
      "5ee43c0fdeb7e6ad74a189e2ef3b9be351be6c8eff5e5736c7ff962f9be3f3e5ff0211fe"
      "057e",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3248U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("armvone"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString("/home/pritesh0/ayush/baahubali/armvone.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739591.68368055555));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2712019 (R2024b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("cDyQ9h2gHGGb51VSioa4MF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_armvone_info.c
 *
 * [EOF]
 */
