#include "game_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "ec_core.h"
#include "core_define.h"

namespace EasyCard{

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
    luaL_dofile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "game.lua");
}

}