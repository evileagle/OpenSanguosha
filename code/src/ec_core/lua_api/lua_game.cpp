#include "lua_game.h"
#include "lua/lua.hpp"

namespace EasyCard
{
    EasyCard::PLuaGame LoadGame( const char* name, const IGame* game )
    {
        lua_State* lua = luaL_newstate();
        lua_newuserdata(lua, sizeof(LuaGame));
        luaL_newmetatable(lua, "game_meta");
        lua_setmetatable(lua, -2);
        PLuaGame lua_game = (PLuaGame)lua_touserdata(lua, -1);
        lua_game->lua = lua;
        lua_game->game = game;
        lua_createtable(lua, );

    }

}
