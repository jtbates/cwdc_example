/* Example C functions */

static int l_add(lua_State *L) {
  int x = lua_tonumber(L, 1);
  int y = lua_tonumber(L, 2);
  lua_pushnumber(L, x+y);
  return 1;
}

static int l_mul(lua_State *L) {
  int x = lua_tonumber(L, 1);
  int y = lua_tonumber(L, 2);
  lua_pushnumber(L, x*y);
  return 1;
}

static const struct luaL_reg example_functions__  [] = {
  {"add",l_add},
  {"mul",l_mul},
  {NULL, NULL}
};

static void cwdc_ExampleFunctions_init(lua_State *L)
{
  luaL_openlib(L,"cwdc",example_functions__,0);
  return 1;
}
