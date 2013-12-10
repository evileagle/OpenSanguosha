#include "lua_player_prop.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "lua_game.h"

namespace EasyCard{
namespace LuaApi{

const char* PROP_NAME = "player_prop";

bool InitPlayerProp(lua_State* lua, size_t number)
{
    assert(lua != NULL);
    GetLuaGame(lua);

    lua_newtable(lua);
    for (size_t i=1; i<number; ++i)
    {
        lua_pushunsigned(lua, i);
        lua_newtable(lua);
        lua_settable(lua, -3);
    }

    lua_setuservalue(lua, -2);
    return true;
}

size_t PlayerToPropIndex(size_t index)
{
    return index+1;
}

int GetPlayerProp( lua_State *lua)
{
    lua_Unsigned index = PlayerToPropIndex(lua_tounsigned(lua, 1));
    const char* key = lua_tostring(lua, 2);
    
    // prop = game.player_prop
    GetLuaGame(lua);
    lua_getuservalue(lua, -1);

    // player_prop = prop[index];
    lua_pushunsigned(lua, index);
    lua_gettable(lua, -2);

    // value = player_prop[key]
    lua_getfield(lua, -1, key);
    return 1;
}

int SetPlayerProp( lua_State *lua )
{
    lua_Unsigned index = PlayerToPropIndex(lua_tounsigned(lua, 1));
    const char* key = lua_tostring(lua, 2);

    GetLuaGame(lua);
    lua_getuservalue(lua, -1);

    lua_pushunsigned(lua, index);
    lua_gettable(lua, -2);

    lua_pushvalue(lua, 3);
    lua_setfield(lua, -2, key);

    return 0;
}

}
}