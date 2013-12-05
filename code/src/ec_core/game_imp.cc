#include "game_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "ec_core.h"

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
    luaL_dofile(lua, "./game.lua");
}

}