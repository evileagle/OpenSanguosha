#include "lua_player_prop.h"
#include <assert.h>
#include "lua/lua.hpp"

namespace EasyCard{
namespace LuaApi{

const char* PROP_NAME = "player_prop";

bool InitPlayerProp(lua_State* lua, size_t number)
{
    assert(lua != NULL);
    lua_newtable(lua);
    lua_pushvalue(lua, -1);
    lua_setfield(lua, LUA_REGISTRYINDEX, PROP_NAME);
    for (size_t i=1; i<number; ++i)
    {
        lua_pushunsigned(lua, i);
        lua_newtable(lua);
        lua_settable(lua, -3);
    }
    return true;
}

bool DisposePlayerProp( lua_State* lua )
{
    lua_pushnil(lua);
    lua_setfield(lua, LUA_REGISTRYINDEX, PROP_NAME);
    return true;
}

int GetPlayerProp( lua_State *lua)
{
    lua_Unsigned index = luaL_checkunsigned(lua, 1);
    const char* key = luaL_checkstring(lua, 2);
    
    // prop = registry.player_prop
    lua_getfield(lua, LUA_REGISTRYINDEX, PROP_NAME);

    // player_prop = prop[index];
    lua_pushunsigned(lua, index);
    lua_gettable(lua, -2);

    // value = player_prop[key]
    lua_getfield(lua, -1, key);
    return 1;
}

}
}