#include "lua_player_prop.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "lua_plus/table.h"
#include "lua_game.h"

namespace EasyCard{
namespace LuaApi{

using namespace LuaPlus;
const char* PROP_NAME = "player_prop";

bool InitPlayerProp(lua_State* lua, size_t number)
{
    assert(lua != NULL);
    if (!GetGameTable(lua))
    {
        return false;
    }

    lua_newtable(lua);
    for (size_t i=1; i<number; ++i)
    {
        lua_pushunsigned(lua, i);
        lua_newtable(lua);
        lua_settable(lua, -3);
    }

    lua_setfield(lua, -2, PROP_NAME);
    lua_pop(lua, 1);
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
    if (!GetGameTable(lua))
    {
        lua_pushnil(lua);
        return 1;
    }
    table game(lua, -1);
    if (!game.get_table(PROP_NAME))
    {
        lua_pushnil(lua);
        return 1;
    }
    // player_prop = prop[index];
    table prop(lua, -1);
    if (!prop.get_table(index))
    {
        lua_pushnil(lua);
        return 1;
    }

    // value = player_prop[key]
    table player(lua, -1);
    player.get_any(key);
    return 1;
}

int SetPlayerProp( lua_State *lua )
{
    lua_Unsigned index = PlayerToPropIndex(lua_tounsigned(lua, 1));
    const char* key = lua_tostring(lua, 2);

    if (!GetGameTable(lua))
    {
        return false;
    }
    lua_getfield(lua, -1, PROP_NAME);
    lua_pushunsigned(lua, index);
    lua_gettable(lua, -2);

    lua_pushvalue(lua, 3);
    lua_setfield(lua, -2, key);

    return 0;
}

}
}