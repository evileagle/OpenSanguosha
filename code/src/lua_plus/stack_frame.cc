#include "lua_plus/stack_frame.h"
#include <assert.h>

namespace LuaPlus
{
    stack_frame::stack_frame()
        : m_nTop(0)
        , m_pState(NULL)
    {

    }

    stack_frame::stack_frame( lua_State* l )
    {
        attach(l);
    }

    void stack_frame::attach( lua_State* l )
    {
        assert(l != NULL);
        m_pState = l;
        m_nTop = lua_gettop(l);
    }

    stack_frame::~stack_frame()
    {
        if (m_pState != NULL)
        {
            lua_settop(m_pState, m_nTop);
            m_pState = NULL;
        }
    }

    lua_State* stack_frame::detach()
    {
        lua_State* pRet = m_pState;
        m_pState = NULL;
        m_nTop = 0;
        return pRet;
    }

}
