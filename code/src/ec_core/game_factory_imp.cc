#include "game_factory_imp.h"
#include "lua/lua.hpp"
#include "lua_plus/stack_frame.h"
#include "ec_core.h"
#include "core_define.h"

namespace EasyCard
{
    using namespace LuaPlus;
    CGameFactory::CGameFactory(void)
    {
    }


    CGameFactory::~CGameFactory(void)
    {
    }

    bool CGameFactory::Initialize(CECCore* core)
    {
        core_ = core;
        return true;
    }

    bool CGameFactory::LoadPredefine()
    {
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return false;
        }
        stack_frame sf(lua);
        luaL_loadfile(lua, "./games/predefine.cfg");
        lua_getfield(lua, LUA_REGISTRYINDEX, EC_LUA_GLOBAL_NAME);
        lua_setupvalue(lua, -2, 1);
        lua_pcall(lua, 1, LUA_MULTRET, 0);
        return true;
    }

    size_t CGameFactory::GetPredefineCount()
    {
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return 0;
        }
        stack_frame sf(lua);
        lua_getfield(lua, LUA_REGISTRYINDEX, EC_LUA_GLOBAL_NAME);
        lua_getfield(lua, -1, "games");
        lua_len(lua, -1);
        return lua_tounsigned(lua, -1);
    }

    const IGame* CGameFactory::CreatePredefineGame( size_t index )
    {
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return NULL;
        }

    }

}
