#ifndef _EASY_CARD_LUAENGINE_H_
#define _EASY_CARD_LUAENGINE_H_

#include "Engine.h"

namespace EasyCard
{
    typedef struct LuaEngine
    {
        IEngine* pEngine;
    }*PLuaEngine;

    int  getgame(lua_State *L);
}


#endif

