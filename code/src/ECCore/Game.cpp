#include "Game.h"
#include <assert.h>
#include "lua/lua.h"
#include "lua/lauxlib.h"

namespace EasyCard
{
    CGame::CGame()
    {

    }

    CGame::CGame( const char* szName )
    {
        SetName(szName);
    }

    CGame::~CGame()
    {

    }

    const char* CGame::GetName()
    {
        return m_name.c_str();
    }

    void CGame::SetName( const char* szName )
    {
        assert(szName);
        if (szName != nullptr)
        {
            m_name = szName;
        }
    }

    EasyCard::ecode CGame::Load()
    {
        lua_State* state = luaL_newstate();
    }

}