#ifndef _LUA_PLUS_STACK_FRAME_H_
#define _LUA_PLUS_STACK_FRAME_H_

#include "lua/lua.h"

namespace LuaPlus
{
    class stack_frame
    {
    public:
        stack_frame();
        stack_frame(lua_State* l);
        void attach(lua_State* l);
        lua_State* detach();
        ~stack_frame();
    private:
        lua_State* m_pState;
        int m_nTop;
    };
}

#endif