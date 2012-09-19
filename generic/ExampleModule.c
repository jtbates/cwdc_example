#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/ExampleModule.c"
#else

static int nn_(ExampleModule_updateOutput)(lua_State *L)
{
  THTensor *input = luaT_checkudata(L, 2, torch_Tensor);
  THTensor *output = luaT_getfieldcheckudata(L, 1, "output", torch_Tensor);

  THTensor_(resizeAs)(output, input);

  TH_TENSOR_APPLY2(real, output, real, input, \
                   *output_data = fabs(*input_data);)
  return 1;
}

static int nn_(ExampleModule_updateGradInput)(lua_State *L)
{
  THTensor *input = luaT_checkudata(L, 2, torch_Tensor);
  THTensor *gradOutput = luaT_checkudata(L, 3, torch_Tensor);
  THTensor *gradInput = luaT_getfieldcheckudata(L, 1, "gradInput", torch_Tensor);

  THTensor_(resizeAs)(gradInput, input);
  TH_TENSOR_APPLY3(real, gradInput, real, gradOutput, real, input, \
                   real z = *input_data;                              \
                   *gradInput_data = *gradOutput_data * (z >= 0 ? 1 : -1);)
  return 1;
}

static const struct luaL_Reg nn_(ExampleModule__) [] = {
  {"ExampleModule_updateOutput", nn_(ExampleModule_updateOutput)},
  {"ExampleModule_updateGradInput", nn_(ExampleModule_updateGradInput)},
  {NULL, NULL}
};

static void nn_(ExampleModule_init)(lua_State *L)
{
  luaT_pushmetatable(L, torch_Tensor);
  luaT_registeratname(L, nn_(ExampleModule__), "nn");
  lua_pop(L,1);
}

#endif
