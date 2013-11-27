#ifndef _EASY_CARD_ENGINE_H_
#define _EASY_CARD_ENGINE_H_

#include "EC_Core/ICore.h"
#include "GameFactory.h"

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
        CGameFactory m_factory;
        static CECCore* s_pInstance;

    };
}


#endif