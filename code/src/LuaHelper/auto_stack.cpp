#include "LuaHelper/auto_stack.h"
#include <assert.h>

namespace LuaHelper
{
    CAutoStack::CAutoStack()
        : m_nTop(0)
        , m_pState(NULL)
    {

    }

    CAutoStack::CAutoStack( lua_State* l )
    {
        Attach(l);
    }

    void CAutoStack::Attach( lua_State* l )
    {
        assert(l != nullptr);
        m_pState = l;
        m_nTop = lua_gettop(l);
    }

    CAutoStack::~CAutoStack()
    {
        if (m_pState != nullptr)
        {
            lua_settop(m_pState, m_nTop);
            m_pState = nullptr;
        }
    }

    lua_State* CAutoStack::Detach()
    {
        lua_State* pRet = m_pState;
        m_pState = nullptr;
        m_nTop = 0;
        return pRet;
    }

}
