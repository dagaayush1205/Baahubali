/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_armvone_info.c
 *
 * Code generation for function 'armvone'
 *
 */

/* Include files */
#include "_coder_armvone_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5] = {
      "789ced54cd4ec24010de1a4c3cf8c3c50730e16248dae881781605318a6831261212b7ed"
      "621776bb66bb683df9087af4913cfa469a52b6b4d5a604081eec5ca6"
      "b3dfee7cdfcc7607288d730500b009027b5f0ffcc6382e8efd0a885b125712fb94c4fe55"
      "50889d93f8ebd89bcc11c81341e0408ac29316a3d8818e683f3f20c0",
      "91cbc823b246480f13d4c614e9d1a0e947b41681c2c087fcefaa8dcc813ea480dbee4421"
      "8906613f3e53ea2d4cd90f9ad28f6202ef34aadd128582408333264a"
      "9a608c18ccd35c1b7264699c194c60d30d3e860213572b878b659371a495b123107720d1"
      "8e207d40d661adae3fd539b43072448bb33e3205668e4a23f5bdcd59",
      "df6e467d129752555fa92a85aacdb396ee5f283ff6b0a811782fef40eabb9b515fd2d2f4"
      "49937c1f33f2c9fc46069fc43b8de602effb671b551aaf2bad8f5b53"
      "d695f493fd6b23bff3f2d55d269fb4ffc2e7a5e49bf6bfdc4ee12b26f0fd3eb1750fdd0e"
      "2afae941e5faf266efeae422a2a395c193a503a4c4cbcabfbcf7bdc8",
      "791ebeef86bfd283264abeef7c8ec7f9f239fe7b5df91cff5bbe7c8ecf97ff1b11fe057"
      "e",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3248U, &nameCaptureInfo);
  return nameCaptureInfo;
}

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
      emlrtMxCreateString("/home/ayush/Vibranium/baahubali/urdf/armvone.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739600.87582175923));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2773142 (R2024b) Update 2"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("cDyQ9h2gHGGb51VSioa4MF"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_armvone_info.c) */
