#ifndef _EASY_CARD_ENGINE_H_
#define _EASY_CARD_ENGINE_H_

#include "ec_core/core.h"
#include "game_factory_imp.h"
struct lua_State;
namespace EasyCard
{
    class CECCore : public ICore
    {
    public:
        CECCore();
        ~CECCore();
        static CECCore* GetInstace();
        bool Initalize();
        IGameFactory* GetGameFactory();
    private:
        bool InitLua();

        CGameFactory m_factory;
        lua_State* lua_;
        static CECCore* s_pInstance;

    };
}


#endif