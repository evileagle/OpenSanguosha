#include "lua_game.h"
#include "lua/lua.hpp"
#include "lua_player_data.h"

namespace EasyCard{
namespace LuaApi{
namespace Game{

typedef struct LuaGame
{
    const IGame* game;
}*PLuaGame;

const char* METATABLE = "game_magic";
const char* NAME = "game";

// TODO 
// getuserdata

int GetPlayerData(lua_State* lua)
{
    if (!lua_isnumber(lua, -1))
    {
        return 0;
    }
    lua_Unsigned index = lua_tounsigned(lua, -1);
    return PlayerData::Get(lua, index);
}

luaL_Reg game_funcs = {
    "getplayer", GetPlayerData
};

bool CreateMetaTable(lua_State* lua)
{
    // new metatable +1
    luaL_newmetatable(lua, METATABLE);
    // game_meta.__index = metatable; 
    lua_pushvalue(lua, -1);
    lua_setfield(lua, -2, "__index");
    // metatable = {funcs};
    lua_pushvalue(lua, -1);
    luaL_setfuncs(lua, &game_funcs, 0);
    return true;
}

bool Create(lua_State* lua)
{
    // push userdata +1
    lua_newuserdata(lua, sizeof(LuaGame));

    // create meta table +1
    if (!CreateMetaTable(lua))
    {
        return false;
    }

    // setmetatable(userdata, metatable) -1
    lua_setmetatable(lua, -2);

    // set to global
    lua_pushvalue(lua, -1);
    lua_setglobal(lua, NAME);
    PLuaGame lua_game = (PLuaGame)lua_touserdata(lua, -1);
    lua_game->game = NULL;
    lua_pop(lua, 1);
    return true;
}

bool Set( lua_State* lua, const IGame* game )
{
    lua_getglobal(lua, NAME);
    PLuaGame lua_game = (PLuaGame)luaL_testudata(lua, -1, METATABLE);
    if (lua_game == NULL)
    {
        return false;
    }
    lua_game->game = game;
    return true;
}

void Destroy( lua_State* lua )
{
    lua_pushnil(lua);
    lua_setglobal(lua, NAME);
}

}
}
}
