#include "lua_game.h"
#include "lua/lua.hpp"

namespace EasyCard
{
    luaL_Reg game_funcs = {};
    EasyCard::PLuaGame LoadGame( const char* name, const IGame* game )
    {
        lua_State* lua = luaL_newstate();
        luaL_openlibs(lua);
        // push _G +1
        lua_pushglobaltable(lua);
        // push userdata +1
        lua_newuserdata(lua, sizeof(LuaGame));
        // push metatable +1
        luaL_newmetatable(lua, "game_meta");
        // push table +1
        lua_newtable(lua);

        // newtable = {funcs};
        lua_pushvalue(lua, -1);
        luaL_setfuncs(lua, &game_funcs, 0);

        // game_meta.__index = newtable; -1
        lua_setfield(lua, -2, "__index");
        // userdata.metatable = table -1
        lua_setmetatable(lua, -2);

        PLuaGame lua_game = (PLuaGame)lua_touserdata(lua, -1);
        lua_game->lua = lua;
        lua_game->game = game;

        // _G.game = userdata; -1
        lua_setfield(lua, -2, "game");
        // pop _G -1
        lua_pop(lua, -1);
        return lua_game;
    }

}
