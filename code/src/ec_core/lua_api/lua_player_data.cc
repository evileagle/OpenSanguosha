#include "lua_player_data.h"
#include <assert.h>
#include "lua/lua.hpp"

namespace EasyCard{
namespace LuaApi{
namespace PlayerData{

const char* DATA_NAME = "player_data";

bool Init(lua_State* lua, size_t number)
{
    assert(lua != NULL);
    lua_newtable(lua);
    lua_pushvalue(lua, -1);
    lua_setfield(lua, LUA_REGISTRYINDEX, DATA_NAME);
    for (size_t i=1; i<number; ++i)
    {
        lua_pushunsigned(lua, i);
        lua_newtable(lua);
        lua_settable(lua, -3);
    }
    return true;
}

int Get( lua_State *lua, size_t index )
{
    lua_getfield(lua, LUA_REGISTRYINDEX, DATA_NAME);
    lua_pushunsigned(lua, index);
    lua_gettable(lua, -2);
    return 1;
}

bool Dispose( lua_State* lua )
{
    lua_pushnil(lua);
    lua_setfield(lua, LUA_REGISTRYINDEX, DATA_NAME);
    return true;
}

}
}
}