#include "game_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "ec_core.h"
#include "core_define.h"
#include "lua_api/lua_game.h"
#include "lua_plus/stack_frame.h"

namespace EasyCard{
using namespace LuaPlus;

#define EASY_CARD_GAME_NAME "game"
#define EASY_CARD_PLAYER_DATA "player_data"

Game::Game()
    : core_(NULL)
{
        
}

Game::Game( CECCore* core )
    : core_(NULL)
{
    Init(core_);
}

Game::Game(CECCore* core, GameConfig& config)
{
    Init(core);
}

Game::~Game()
{

}

bool Game::Init( CECCore* core )
{
    assert(core != NULL);
    core_ = core;
    return true;
}

bool Game::Load( GameConfig& config )
{
    assert(core_ != NULL);
    if (core_ == NULL)
    {
        return false;
    }
    lua_State* lua = core_->GetLua();
    if (lua == NULL)
    {
        return false;
    }
    LuaApi::CreateLuaGame(lua, this);
    stack_frame sf(lua);
    luaL_dofile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "main.lua");
    if (!lua_istable(lua, -1))
    {
        return false;
    }
    lua_pushvalue(lua , -1);
    lua_setfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
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

bool Game::Start()
{
    assert(core_ != NULL);
    if (core_ == NULL)
    {
        return false;
    }
    return true;
}

bool Game::GetMain()
{
    return true;
}

}