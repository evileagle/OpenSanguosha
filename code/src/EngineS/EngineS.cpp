#include "Engine.h"


namespace EasyCard
{
    CEngineS::CEngineS()
    {
    }


    CEngineS::~CEngineS()
    {
    }

    bool CEngineS::Initalize()
    {
        if (!m_factory.Initialize())
        {
            return false;
        }
        return true;
    }

    IGameFactory* CEngineS::GetGameFactory()
    {
        return &m_factory;
    }

    CEngineS* CEngineS::GetInstace()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new CEngineS;
            if (s_pInstance == nullptr)
            {
                return nullptr;
            }
            s_pInstance->Initalize();
        }
        return s_pInstance;

    }

}
