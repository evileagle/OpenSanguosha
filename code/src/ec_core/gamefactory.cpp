#include "GameFactory.h"
#include "GameDesc.h"
#include "LuaPlus/stack_frame.h"

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
        if (state == NULL)
        {
            return false;
        }
        luaL_openlibs(state);
        luaL_dofile(state, "./Games/Factory.cfg");
        lua_getglobal(state, "games");
        table games(state, -1);
        bool bResult = CreateDescriptors(state, games);
        lua_close(state);
        return bResult;
    }

    size_t CGameFactory::GetGameCount()
    {
        return m_descriptors.size();
    }

    const IGameDesc* CGameFactory::GetGameDesc( size_t nIndex )
    {
        if (nIndex >= m_descriptors.size())
        {
            return NULL;
        }
        return (IGameDesc*)m_descriptors[nIndex];
    }

    const IGame* CGameFactory::CreateGame( const char* szName )
    {
        return NULL;
    }

    bool CGameFactory::CreateDescriptor( lua_State* state, table& desc )
    {
        stack_frame sf(state);
        if (!desc.is_valid())
        {
            return false;
        }
        string name;
        if (desc.get_value("name", name))
        {
            return false;
        }

        string displayname;
        if (desc.get_value("display_name", displayname))
        {
            return false;
        }

        lua_Unsigned nPlayerNumber;
        if (desc.get_value("player_number", nPlayerNumber))
        {
            return false;
        }

        CGameDesc* pDesc = new CGameDesc(name.c_str(), displayname.c_str(), nPlayerNumber);

        m_descriptors.push_back(pDesc);

        return true;
    }

    bool CGameFactory::CreateDescriptors( lua_State* state, table& games )
    {
        stack_frame sf(state);
        if (!games.is_valid())
        {
            return false;
        }
        int len = games.get_len();
        for (int i=1; i<= len; i++)
        {
            stack_frame sf(state);
            table gamedesc;
            if (games.get_value(i, gamedesc))
            {
                CreateDescriptor(state, gamedesc);
            }
        }
        return true;
    }


}
