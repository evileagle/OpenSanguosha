#include "game_factory_imp.h"
#include <assert.h>
#include "lua/lua.hpp"
#include "lua_plus/stack_frame.h"
#include "lua_plus/table.h"
#include "ec_core.h"
#include "core_define.h"
#include "game_imp.h"

namespace EasyCard
{
    const char* PREDEFINE_CONFIG_NAME = "predefine";
    using namespace LuaPlus;
    GameFactory::GameFactory(void)
    {
    }


    GameFactory::~GameFactory(void)
    {
    }

    bool GameFactory::Initialize(CECCore* core)
    {
        assert(core != NULL);
        core_ = core;
        return true;
    }

    bool GameFactory::LoadPredefine()
    {
        assert(core_ != NULL);
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return false;
        }
        stack_frame sf(lua);
        luaL_dofile(lua, CURRENT_DIR PATH_DELIMITER GAME_DIR PATH_DELIMITER "predefine.cfg");
        if (!lua_istable(lua, -1))
        {
            return false;
        }
        lua_setfield(lua, LUA_REGISTRYINDEX, PREDEFINE_CONFIG_NAME);
        return true;
    }

    size_t GameFactory::GetPredefineCount()
    {
        assert(core_ != NULL);
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return 0;
        }
        stack_frame sf(lua);
        lua_getfield(lua, LUA_REGISTRYINDEX, PREDEFINE_CONFIG_NAME);
        if (!lua_istable(lua, -1))
        {
            return 0;
        }
        lua_len(lua, -1);
        return lua_tounsigned(lua, -1);
    }

    const IGame* GameFactory::CreatePredefineGame( size_t index )
    {
        assert(core_ != NULL);
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return NULL;
        }
        stack_frame sf(lua);

        lua_getfield(lua, LUA_REGISTRYINDEX, PREDEFINE_CONFIG_NAME);
        if (!lua_istable(lua, -1))
        {
            return NULL;
        }
        lua_len(lua, -1);
        if (luaL_checkunsigned(lua, -1) < index)
        {
            return NULL;
        }
        lua_gettable(lua, index);
        return CreateFromeLua();
    }

    const IGame* GameFactory::CreateFromeLua()
    {
        assert(core_ != NULL);
        lua_State* lua = core_->GetLua();
        if (lua == NULL)
        {
            return NULL;
        }
        stack_frame sf(lua);
        if (!lua_istable(lua, -1))
        {
            return NULL;
        }
        
        GameConfig config;
        lua_pushnil(lua);
        while (lua_next(lua, -1))
        {
            const char* name = lua_tostring(lua, -2);
            if (lua_isboolean(lua, -1))
            {
                bool value = lua_toboolean(lua, -1) != 0;
            }
            lua_pop(lua, 1);
        }

        return CreateGame(config);
    }

    const IGame* GameFactory::CreateGame( GameConfig& config )
    {
        Game* game = new Game(core_, config);
        return game;
    }

}
