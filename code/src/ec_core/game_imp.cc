#include "game_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "ec_core.h"
#include "core_define.h"
#include "lua_api/lua_game.h"
#include "lua_loader/main_loader.h"

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
    lua_State* lua = core_->GetLua();
    assert(lua != NULL);
    if (!LuaApi::CreateLuaGame(lua, this))
    {
        return false;
    }
    if (!LuaLoader::LoadMain(lua))
    {
        return false;
    }
    return LuaLoader::CallInit(lua, config);
}

bool Game::Start()
{
    assert(core_ != NULL);
    return LuaLoader::CallStart(core_->GetLua());
}

}