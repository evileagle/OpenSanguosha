#include "round_loader.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "lua_plus/stack_frame.h"
#include "ec_common/type_def.h"
#include "core_define.h"

namespace EasyCard{
namespace LuaLoader{
using namespace LuaPlus;

const char* ROUND_NAME = "round";

bool LoadRound( lua_State* lua )
{
    assert(lua != NULL);
    stack_frame sf(lua);
    luaL_loadfile(lua, CURRENT_DIR PATH_DELIMITER "round.lua");
    lua_pcall(lua, 0, 1, 0);
    if (!lua_istable(lua, -1))
    {
        return false;
    }
    lua_setfield(lua, LUA_REGISTRYINDEX, ROUND_NAME);
    return true;
}

bool CallRound( lua_State* lua )
{
    assert(lua != NULL);
    stack_frame sf(lua);
    if (!GetRound(lua))
    {
        return false;
    }
    lua_getfield(lua, -1, "do");
    if (!lua_isfunction(lua, -1))
    {
        return false;
    }
    lua_pcall(lua, 0, 0, 0);
    return true;
}

bool GetRound( lua_State* lua )
{
    assert(lua != NULL);
    lua_getfield(lua, LUA_REGISTRYINDEX, ROUND_NAME);
    return lua_istable(lua, -1);
}

void DisposeRound( lua_State* lua )
{
    assert(lua != NULL);
    lua_pushnil(lua);
    lua_setfield(lua, LUA_REGISTRYINDEX, ROUND_NAME);
}

}
}
