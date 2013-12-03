#include "game_factory_imp.h"
#include "game_desc_imp.h"
#include "lua_plus/stack_frame.h"

namespace EasyCard
{

    CGameFactory::CGameFactory(void)
    {
    }


    CGameFactory::~CGameFactory(void)
    {
    }

    bool CGameFactory::Initialize(lua_State* lua)
    {
        if (lua == NULL)
        {
            return false;
        }
        lua_newtable(lua);
        lua_pushvalue(lua, -1);
        lua_setfield(lua, LUA_REGISTRYINDEX, "predefine");
        luaL_dofile(lua, "./games/predefine.cfg");
        table games(lua, -1);
        bool bResult = CreateDescriptors(lua, games);
        lua_close(lua);
        return bResult;
    }


    const IGame* CGameFactory::CreateGame(size_t index)
    {
        return NULL;
    }

}
