#include "Engine.h"


namespace EasyCard
{
    CEngine::CEngine()
    {
    }


    CEngine::~CEngine()
    {
    }

    bool CEngine::Initalize()
    {
        return true;
    }

    IGameFactory* CEngine::GetGameFactory()
    {
        return &m_factory;
    }

}
