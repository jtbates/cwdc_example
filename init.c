#include "TH.h"
#include "luaT.h"
#include "omp.h"

#define torch_(NAME) TH_CONCAT_3(torch_, Real, NAME)
#define torch_Tensor TH_CONCAT_STRING_3(torch., Real, Tensor)
#define nn_(NAME) TH_CONCAT_3(nn_, Real, NAME)

#include "generic/ExampleModule.c"
#include "THGenerateFloatTypes.h"

#include "example_functions.c"

DLL_EXPORT int luaopen_libcwdc(lua_State *L)
{
  nn_FloatExampleModule_init(L);

  nn_DoubleExampleModule_init(L);

  cwdc_ExampleFunctions_init(L);
  return 1;
}
