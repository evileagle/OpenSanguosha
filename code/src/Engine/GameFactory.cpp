#include "GameFactory.h"
#include "GameDesc.h"

namespace EasyCard
{

	CGameFactory::CGameFactory(void)
	{
	}


	CGameFactory::~CGameFactory(void)
	{
	}

    bool CGameFactory::Initialize()
    {
        lua_State* state = luaL_newstate();
        if (state == nullptr)
        {
            return false;
        }
        luaL_openlibs(state);
        luaL_dofile(state, "./Games/Factory.cfg");
        lua_getglobal(state, "games");
        if (!lua_istable(state, -1))
        {
            return false;
        }
        lua_len(state, -1);
        int len = lua_tointeger(state, -1);
        lua_pop(state, 1);
        for (int i=1; i<= len; i++)
        {
            lua_pushinteger(state, i);
            lua_gettable(state, -1);
            if (!lua_istable(state, -1))
            {
                lua_pop(state, 1);
                continue;
            }
            CreateDescriptor(state);
            lua_pop(state, 1);
        }
        lua_close(state);
        return true;
    }

    uint CGameFactory::GetGameCount()
    {
        return m_descriptors.size();
    }

    const IGameDesc* CGameFactory::GetGameDesc( uint nIndex )
    {
        if (nIndex >= m_descriptors.size())
        {
            return NULL;
        }
        return (IGameDesc*)m_descriptors[nIndex];
    }

    IGame* CGameFactory::CreateGame( char* szName )
    {
        return NULL;
    }

    bool CGameFactory::CreateDescriptor( lua_State* state )
    {
        int nTop = lua_gettop(state);
        bool bSuccess = false;
        do 
        {
            lua_getfield(state, -1, "name");
            if (!lua_isstring(state, -1))
            {
                break;
            }
            const char* pName = lua_tostring(state, -1);

            lua_getfield(state, -2, "display_name");
            if (!lua_isstring(state, -1))
            {
                break;
            }
            const char* pDisPlayName = lua_tostring(state, -1);

            lua_getfield(state, -3, "display_name");
            if (!lua_isnumber(state, -1))
            {
                break;
            }
            int nPlayerNumber = lua_tointeger(state, -1);

            CGameDesc* pDesc = new CGameDesc(pName, pDisPlayName, nPlayerNumber);

            m_descriptors.push_back(pDesc);

            bSuccess = true;
        } while (false);

        lua_settop(state, nTop);
        return bSuccess;
    }


}
