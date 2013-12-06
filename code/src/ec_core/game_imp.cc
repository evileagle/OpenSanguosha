#include "game_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "ec_core.h"
#include "core_define.h"

namespace EasyCard
{

#define EASY_CARD_GAME_NAME "game"
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
    luaL_dofile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "main.lua");
    if (!lua_istable(lua, -1))
    {
        return false;
    }
    lua_setfield(lua, LUA_REGISTRYINDEX, EASY_CARD_GAME_NAME);
    // TODO pass config to main.lua
    return true;
}

}