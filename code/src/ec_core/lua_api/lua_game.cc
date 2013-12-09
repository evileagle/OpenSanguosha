#include "lua_game.h"
#include "lua/lua.hpp"
#include "lua_player_prop.h"

namespace EasyCard{
namespace LuaApi{

typedef struct LuaGame
{
    const Game* game;
}*PLuaGame;

const char* METATABLE = "game_magic";
const char* GAME_NAME = "game";


luaL_Reg game_funcs[] = {
    {"get_prop", GetPlayerProp},
    {"set_prop", SetPlayerProp}
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
    luaL_setfuncs(lua, game_funcs, 0);
    return true;
}

bool CreateLuaGame(lua_State* lua, const Game* game)
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
    lua_setglobal(lua, GAME_NAME);
    PLuaGame lua_game = (PLuaGame)lua_touserdata(lua, -1);
    lua_game->game = game;
    lua_pop(lua, 1);
    return true;
}

void DestroyLuaGame( lua_State* lua )
{
    DisposePlayerProp(lua);
    lua_pushnil(lua);
    lua_setglobal(lua, GAME_NAME);
}

void GetLuaGame( lua_State* lua )
{
    lua_getfield(lua, LUA_REGISTRYINDEX, GAME_NAME);
}

}
}
