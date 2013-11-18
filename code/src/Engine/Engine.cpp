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

    }

    IGameFactory* CEngine::GetGameFactory()
    {
        return &m_factory;
    }

}
