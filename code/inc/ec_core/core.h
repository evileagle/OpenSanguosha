#ifndef _EASY_CARD_CORE_H_
#define _EASY_CARD_CORE_H_

#ifdef WIN32

#if defined(EC_CORE)
#define EC_API __declspec(dllexport)
#else						/* }{ */
#define EC_API __declspec(dllimport)
#endif //EC_CORE

#else

#define  EC_API 

#endif // WIN32

namespace EasyCard
{
    class IGameFactory;
    class ICore
    {
    public:
        virtual IGameFactory* GetGameFactory() = 0;
        virtual void Dispose() = 0;
    };

    EC_API ICore* GetCore();
}
#endif