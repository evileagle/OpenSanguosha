#ifndef _EASY_CARD_ENGINE_H_
#define _EASY_CARD_ENGINE_H_

#include "Engine/IEngine.h"
#include "GameFactory.h"

namespace EasyCard
{

    class CEngine : public IEngine
    {
    public:
        CEngine();
        ~CEngine();
        bool Initalize();
        IGameFactory* GetGameFactory();
    private:
        CGameFactory m_factory;

    };
}


#endif