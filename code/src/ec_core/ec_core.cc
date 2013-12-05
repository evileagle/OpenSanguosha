#include "ec_core.h"
#include "core_define.h"
#include "lua/lua.hpp"


namespace EasyCard
{
    CECCore::CECCore()
    {
    }


    CECCore::~CECCore()
    {
    }

    bool CECCore::Initalize()
    {
        if (!InitLua())
        {
            return false;
        }
        if (!m_factory.Initialize(this))
        {
            return false;
        }
        return true;
    }

    IGameFactory* CECCore::GetGameFactory()
    {
        return &m_factory;
    }

    CECCore* CECCore::GetInstace()
    {
        if (s_pInstance == NULL)
        {
            s_pInstance = new CECCore;
            if (s_pInstance == NULL)
            {
                return NULL;
            }
            s_pInstance->Initalize();
        }
        return s_pInstance;
    }

    bool CECCore::InitLua()
    {
        lua_ = luaL_newstate();
        if (lua_ == NULL)
        {
            return false;
        }
        luaL_openlibs(lua_);
        return true;
    }

    lua_State* CECCore::GetLua()
    {
        return lua_;
    }

}
