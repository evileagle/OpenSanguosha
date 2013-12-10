#include "main_loader.h"
#include <string>
#include "lua/lua.hpp"
#include "lua_plus/stack_frame.h"
#include "core_define.h"

using namespace std;

namespace EasyCard{

using namespace LuaPlus;

#define EASY_CARD_GAME_NAME "game"
#define EASY_CARD_PLAYER_DATA "player_data"
namespace LuaLoader{
bool LoadMain( lua_State* lua)
{
    stack_frame sf(lua);
    luaL_dofile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "main.lua");
    if (!lua_istable(lua, -1))
    {
        return false;
    }
    lua_pushvalue(lua , -1);
    lua_setfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
    return true;
}

bool CallInit( lua_State* lua, GameConfig& config )
{
    GetMain(lua);
    lua_getfield(lua, -1, "init");
    if (!lua_isfunction(lua, -1))
    {
        return false;
    }
    // TODO pass config to main.lua
    lua_newtable(lua);
    lua_call(lua, 1, 1);
    if (!lua_isboolean(lua, -1))
    {
        return false;
    }
    return lua_toboolean(lua, -1);
}

bool GetMain( lua_State* lua )
{
    lua_getfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
    return lua_istable(lua, -1);
}

}
}