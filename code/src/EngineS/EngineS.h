#ifndef _EASY_CARD_ENGINE_H_
#define _EASY_CARD_ENGINE_H_

#include "Engine/IEngine.h"
#include "GameFactory.h"

namespace EasyCard
{

    class CEngineS : public IEngine
    {
    public:
        CEngineS();
        ~CEngineS();
        static CEngineS* GetInstace();
        bool Initalize();
        IGameFactory* GetGameFactory();
    private:
        CGameFactory m_factory;
        static CEngineS* s_pInstance;

    };
}


#endif