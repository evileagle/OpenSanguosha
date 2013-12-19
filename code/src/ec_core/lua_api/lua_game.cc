#include "lua_game.h"
#include "lua/lua.hpp"
#include "lua_player_prop.h"
#include "lua_round_loop.h"

namespace EasyCard{
namespace Core{
namespace LuaApi{

const char* METATABLE = "game_magic";
const char* GAME_NAME = "game";


luaL_Reg game_funcs[] = {
    {"get_prop", GetPlayerProp},
    {"set_prop", SetPlayerProp},
    {"add_round", AddRound},
    {"start_loop", StartLoop},
    {"current_player", GetCurrentPlayer},
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

bool CreateLuaGame(lua_State* lua, Game* game)
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
    lua_newtable(lua);
    lua_setuservalue(lua, -1);
    PLuaGame lua_game = (PLuaGame)lua_touserdata(lua, -1);
    lua_game->game = game;
    lua_pop(lua, 1);
    return true;
}

void DestroyLuaGame( lua_State* lua )
{
    lua_pushnil(lua);
    lua_setglobal(lua, GAME_NAME);
}

PLuaGame GetLuaGame( lua_State* lua )
{
    lua_getfield(lua, LUA_REGISTRYINDEX, GAME_NAME);
    if (!lua_isuserdata(lua, -1))
    {
        lua_pop(lua, 1);
        return NULL;
    }
    lua_getuservalue(lua, -1);
    if (!lua_istable(lua, -1))
    {
        lua_pop(lua, 1);
        return NULL;
    }
    return (PLuaGame)lua_touserdata(lua, -1);
}

bool GetGameTable( lua_State* lua )
{
    lua_getfield(lua, LUA_REGISTRYINDEX, GAME_NAME);
    if (!lua_isuserdata(lua, -1))
    {
        lua_pop(lua, 1);
        return false;
    }
    lua_getuservalue(lua, -1);
    lua_remove(lua, -2);
    return lua_istable(lua, -1);
}

}
}
}