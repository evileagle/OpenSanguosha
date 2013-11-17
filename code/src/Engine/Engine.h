#ifndef _EASY_CARD_ENGINE_H_
#define _EASY_CARD_ENGINE_H_

#include "Engine/IEngine.h"
#include "lua/lua.h"

namespace EasyCard
{

    class CEngine : public IEngine
    {
    public:
        CEngine();
        ~CEngine();
        virtual bool Initalize();
    private:
        lua_State* m_luaState;
    };
}


#endif