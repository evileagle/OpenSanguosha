#ifndef _LUA_HELPER_AUTO_STACK_H_
#define _LUA_HELPER_AUTO_STACK_H_

#include "lua/lua.h"

namespace LuaHelper
{
    class CAutoStack
    {
    public:
        CAutoStack();
        CAutoStack(lua_State* l);
        void Attach(lua_State* l);
        lua_State* Detach();
        ~CAutoStack();
    private:
        lua_State* m_pState;
        int m_nTop;
    };
}

#endif