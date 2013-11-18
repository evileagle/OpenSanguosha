#include "GameFactory.h"
#include "lua/lua.h"

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

    }

    uint CGameFactory::GetGameCount()
    {
        return m_descriptors.size();
    }

    IGameDesc* CGameFactory::GetGameDesc( uint nIndex )
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


}
