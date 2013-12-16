#include "main_loader.h"
#include <assert.h>
#include <string>
#include "lua/lua.hpp"
#include "lua_plus/stack_frame.h"
#include "core_define.h"

using namespace std;

namespace EasyCard{

using namespace LuaPlus;

#define EASY_CARD_GAME_NAME "main"
#define EASY_CARD_PLAYER_DATA "player_data"

namespace LuaLoader{

bool LoadMain( lua_State* lua)
{
    assert(lua != NULL);
    stack_frame sf(lua);
    luaL_loadfile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "main.lua");
    lua_pcall(lua, 0, 1, 0);
    if (!lua_istable(lua, -1))
    {
        return false;
    }
    lua_setfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
    return true;
}

bool CallInit( lua_State* lua, GameConfig& config )
{
    assert(lua != NULL);
    stack_frame sf(lua);
    GetMain(lua);
    table game_main(lua, -1);
    if (!game_main.get_function("init"))
    {
        return false;
    }
    // TODO pass config to main.lua
    lua_newtable(lua);
    lua_call(lua, 1, 1);
    bool success = false;
    if (lua_isboolean(lua, -1))
    {
        success = lua_toboolean(lua, -1);
    }
    lua_pop(lua, 1);
    return success;
}

bool GetMain( lua_State* lua )
{
    assert(lua != NULL);
    lua_getfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
    bool success = lua_istable(lua, -1);
    if (!success)
    {
        lua_pop(lua, 1);
    }
    return success;
}

bool CallStart( lua_State* lua )
{
    assert(lua != NULL);
    stack_frame sf(lua);
    if (!GetMain(lua))
    {
        return false;
    }
    table game_main(lua, -1);
    if (!game_main.get_function("start"))
    {
        return false;
    }
    lua_pcall(lua, 0, 0, 0);
    return true;
}

bool CallOnEvent( lua_State* lua )
{
    assert(lua != NULL);
    stack_frame sf(lua);
    if (!GetMain(lua))
    {
        return false;
    }
    table game_main(lua, -1);
    if (!game_main.get_function("on"))
    {
        return false;
    }
    lua_pushvalue(lua, -3);
    lua_pcall(lua, 1, 0, 0);
    return true;
}

}
}