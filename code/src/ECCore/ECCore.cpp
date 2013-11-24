#include "ECCore.h"


namespace EasyCard
{
    CECCore::CECCore()
    {
    }


    CECCore::~CECCore()
    {
    }

    bool CECCore::Initalize()
    {
        if (!m_factory.Initialize())
        {
            return false;
        }
        return true;
    }

    IGameFactory* CECCore::GetGameFactory()
    {
        return &m_factory;
    }

    CECCore* CECCore::GetInstace()
    {
        if (s_pInstance == nullptr)
        {
            s_pInstance = new CECCore;
            if (s_pInstance == nullptr)
            {
                return nullptr;
            }
            s_pInstance->Initalize();
        }
        return s_pInstance;

    }

}
